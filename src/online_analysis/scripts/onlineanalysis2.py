#!/usr/bin/env python
# -*- coding: UTF-8 -*-
import numpy as np
import h5py as h5
from sklearn.cross_decomposition import CCA
from scipy import signal
from statistics import median

# 相关变量及参数设置
# 数组缓存区大小
BUFFSIZE = 8192
# 采样频率
sampleRate = 2048
# 频率序列
freqList = [9, 10, 11, 12, 13, 14, 15, 16, 17]
# 每个数据包大小
packetSize = 512

# 参数：降采样
downSamplingNum = 8
downSampleRate = sampleRate / downSamplingNum
downBuffSize = int(BUFFSIZE / downSamplingNum)

# 参数：50Hz陷波滤波器
# 将要被移除的频率 (Hz)
f_notch = 50
Ts = 1 / downSampleRate
alpha = -2 * np.cos(2 * np.pi * f_notch * Ts)
beta = 0.95
# 构造滤波器
notch_b = [1, alpha, 1]
notch_a = [1, alpha * beta, beta**2]

# 参数：带通滤波器
# 通带阻带截止频率
Wp = [7 / (downSampleRate / 2), 70 / (downSampleRate / 2)]
Ws = [5 / (downSampleRate / 2), 80 / (downSampleRate / 2)]
# 通带最大衰减 [dB]
Rp = 3
# 阻带最小衰减 [dB]
Rs = 60
N, Wn = signal.cheb1ord(Wp, Ws, Rp, Rs)
# peak-to-peak ripple with R dB in the passband
bp_R = 0.5
B, A = signal.cheby1(N, bp_R, Wn, "bandpass")

# 生成参考信号
num_harms = 4
w_sincos = 0
num_freqs = len(freqList)
y_ref = np.zeros((num_freqs, 2 * num_harms, downBuffSize))
t = np.array([i / downSampleRate for i in range(1, downBuffSize + 1)])
# 对每个参考频率都生成参考波形
for freq_i in range(0, num_freqs):
	tmp = np.zeros((2 * num_harms, downBuffSize))
	# harm:harmonic wave 谐波
	for harm_i in range(0, num_harms):
		stim_freq = freqList[freq_i]
		# Frequencies other than the reference frequency
		d_sin = np.zeros((num_freqs, downBuffSize))
		d_cos = np.zeros((num_freqs, downBuffSize))
		for freq_j in range(0, num_freqs):
			if freq_j != freq_i:
				d_freq = freqList[freq_j]
				d_sin[freq_j, :] = np.sin(2 * np.pi * (harm_i + 1) * d_freq * t)
				d_cos[freq_j, :] = np.cos(2 * np.pi * (harm_i + 1) * d_freq * t)
		temp_d_sin = np.sum(d_sin, 0)
		temp_d_cos = np.sum(d_cos, 0)
		# superposition of the reference frequency with other frequencies
		tmp[2 * harm_i] = (np.sin(2 * np.pi * (harm_i + 1) *stim_freq * t) + w_sincos * temp_d_sin)
		tmp[2 * harm_i + 1] = (np.cos(2 * np.pi * (harm_i + 1) *stim_freq * t) + w_sincos * temp_d_cos)
	y_ref[freq_i] = tmp

# 标志相机启动与否的变量，为 false 时未启动，为 true 时启动
camera_on = False

# 用于分析的数据数组
data_used = np.array([])

# 从 mat 文件中读取数据
eegdata = np.array(h5.File('/home/wuyou/eegdata.mat', 'r')['eegdata']).T
print("数组形状：", eegdata.shape)
print("数组第二维：", eegdata.shape[1])

# 存储结果
ana_count = int((eegdata.shape[1] - BUFFSIZE) / (2 * packetSize) + 1)
res = np.zeros((eegdata.shape[3], eegdata.shape[2], ana_count))

for exper_i in range(0, eegdata.shape[3]):
	for target_i in range(0, eegdata.shape[2]):
		# 把原数组降至二维
		data = eegdata[:, :, target_i, exper_i]
		# print("data_used形状：", data_used.shape)

		# 每次读取一个 packet 的数据并拼接
		for packet_i in range(0, 36):
			packet = data[:, packet_i * packetSize : (packet_i + 1) * packetSize]
			if data_used.size == 0:
				data_used = packet
			else:
				data_used = np.hstack((data_used, packet))
				delta = data_used.shape[1] - BUFFSIZE
				if delta >= 0:
					if (delta / packetSize) % 2 == 0:
						data_used = data_used[:, -BUFFSIZE : ]
			if data_used.shape[1] == BUFFSIZE:
				# 当数组长度超过缓存长度，则进行处理
				# 选择导联
				ch_used = [20, 24, 25, 26, 27, 28, 29, 30, 31]
				# data used
				data_chused = data_used[ch_used, :]
				# the number of channels usd
				channel_usedNum = len(ch_used)

				# 构造数组，存储处理的数据
				data_downSample = np.zeros((channel_usedNum, downBuffSize))
				data_50hz = np.zeros((channel_usedNum, downBuffSize))
				data_removeBaseline = np.zeros((channel_usedNum, downBuffSize))
				data_bandpass = np.zeros((channel_usedNum, downBuffSize))

				# data pre-processing
				for chan_th in range(0, channel_usedNum):
					# downsampling
					data_downSample[chan_th, :] = signal.decimate(data_chused[chan_th, :], downSamplingNum, ftype='fir')
					# 50Hz notch filter
					data_50hz[chan_th, :] = signal.filtfilt(notch_b, notch_a, data_downSample[chan_th, :])
					# remove baseline
					data_removeBaseline[chan_th, :] = data_50hz[chan_th,:] - median(data_50hz[chan_th, :])
					# bandpass filter
					data_bandpass[chan_th, :] = signal.filtfilt(B, A, data_removeBaseline[chan_th, :])

				ref_data = y_ref
				test_data = data_bandpass.T
				# CCA
				num_class_cca = len(freqList)
				# 用于存储数据与参考信号的相关系数
				r_cca = np.zeros((num_class_cca))
				for class_i in range(0, num_class_cca):
					refdata_cca = ref_data[class_i].T
					cca = CCA(n_components=1)
					cca.fit(test_data, refdata_cca)
					U, V = cca.transform(test_data, refdata_cca)
					r_cca[class_i] = np.corrcoef(U[:, 0], V[:, 0])[0, 1]
				# 获取相关系数值最大的序号
				index_class_cca = np.argmax(r_cca)
				result = freqList[index_class_cca]

				ana_i = int((packet_i - 15) / 2)
				res[exper_i, target_i, ana_i] = result

				# 根据分析结果发布指令，每次分析结束后都执行一次
				if result == 20:
					# do something
					print("the frequency to start camera is", result)
					camera_on = True
			# if camera_on == True:
			# 	match result:
			# 		case 9:
			# 			print(9)
			# 		case 10:
			# 			print(10)
			# 		case 11:
			# 			print(11)
			# 		case 12:
			# 			print(12)
			# 		case 13:
			# 			print(13)
			# 		case 14:
			# 			print(14)
			# 		case 15:
			# 			print(15)
			# 		case 16:
			# 			print(16)
			# 		case 17:
			# 			print(17)
			# 		case _:
			# 			print("I am everything~")

	print("target x analysis:", res[exper_i])
print(res)
