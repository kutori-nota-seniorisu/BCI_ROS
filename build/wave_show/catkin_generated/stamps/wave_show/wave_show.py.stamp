#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import rospy
from std_msgs.msg import String
from std_msgs.msg import UInt16
from std_msgs.msg import Float32MultiArray
from scipy import signal

from PySide2.QtWidgets import QApplication
from PySide2.QtUiTools import QUiLoader
from PySide2.QtCore import Signal, QObject

import pyqtgraph as pg
import numpy as np

# check box 是否勾选的标志变量
base_check = False
notch_check = False
low_check = False
high_check = False

# 采样频率，默认为1000Hz
sampleRate = 1000

# 参数：50Hz陷波滤波器
# 将要被移除的频率 (Hz)
f_notch = 50
Ts = 1.0 / sampleRate
alpha = -2 * np.cos(2 * np.pi * f_notch * Ts)
beta = 0.95
# 构造滤波器
notch_b = [1, alpha, 1]
notch_a = [1, alpha * beta, beta**2]

# t 为时间刻度
t = np.arange(0,500)

# 需要手动创建信号的类，然后才可将信号与槽相互连接
class MySignal(QObject):
	signal = Signal(Float32MultiArray)

# 定义了一个槽函数，绘制波形
def test_func1(val):
	global base_check
	nEegChan = val.shape[0]
	dDeltaY = 1.0 / nEegChan

	aAvg = np.mean(val, -1)
	aMax = np.max(val, -1)
	aMin = np.min(val, -1)
	
	wave_data = val
	# 基线移动
	if base_check:
		print("in base check")
		for i in range(0, nEegChan):
			wave_data[i] = wave_data[i] - aAvg[i]
	# 50Hz陷波滤波
	if notch_check:
		print("in notch check")
		wave_data = signal.filtfilt(notch_b, notch_a, wave_data)
	# 低通滤波
	if low_check:
		N = 8
		Wn = ui.spinBox_low.value() / (sampleRate / 2)
		B, A = signal.cheby1(N, 0.5, Wn, "low")
		wave_data = signal.filtfilt(B, A, wave_data)
	# 高通滤波
	if high_check:
		N = 8
		Wn = ui.spinBox_high.value() / (sampleRate / 2)
		B, A = signal.cheby1(N, 0.5, Wn, "high")
		wave_data = signal.filtfilt(B, A, wave_data)

	p1.clear()
	# 曲线绘制
	for i in range(0, nEegChan):
		# 自适应范围
		dAutoScale = dDeltaY / ((aMax[0] - aMin[0]) * 1.25)
		# 偏移量
		nYOffset = (i + 0.5) * dDeltaY
		# 绘制
		p1.plot(t, wave_data[i] * dAutoScale + nYOffset)

# 实例化信号类的对象，然后将该对象的信号与对应的槽函数连接，此处槽函数为 test_func1
mysi = MySignal()
mysi.signal.connect(test_func1)

# 定义了 ros 接收节点的回调函数，接收到数据包后发送信号，由槽函数进行绘制
def callback_get_packet(data):
	global mysi
	# 把一维数组转换成二维数组
	rawdata = np.array(data.data[:]).reshape(500, 10).T
	print(rawdata.shape)
	mysi.signal.emit(rawdata)

# 获取采样频率
def callback_get_rate(rate):
	global sampleRate
	sampleRate = rate.data
	print("采样频率为：", sampleRate)

# 获取通道标签
def callback_get_chan(chan):
	print("收到标签：", chan.data)
	ui.comboBox.addItem(chan.data)

rospy.init_node('listener', anonymous=True)
rospy.Subscriber("packet", Float32MultiArray, callback_get_packet)
rospy.Subscriber("samplerate", UInt16, callback_get_rate)
rospy.Subscriber("chanlabel", String, callback_get_chan)

def on_checkBox_base_stateChanged(state):
	global base_check
	base_check = state

def	on_checkBox_notch_stateChanged(state):
	global notch_check
	notch_check = state

def on_checkBox_low_stateChanged(state):
	global low_check
	low_check = state
	ui.spinBox_low.setEnabled(state)

def	on_checkBox_high_stateChanged(state):
	global high_check
	high_check = state
	ui.spinBox_high.setEnabled(state)

app = QApplication([])
loader = QUiLoader()
# pyside2 一定要使用registerCustomWidget 
# 来注册 ui 文件中的第三方控件，这样加载的时候
# loader才知道第三方控件对应的类，才能实例化对象
loader.registerCustomWidget(pg.GraphicsLayoutWidget)
ui = loader.load('/home/wuyou/BCI_ROS/src/wave_show/scripts/ui_waveshow.ui')
# widget 是控件名称，需要注意
pw = ui.widget
pw.setBackground('w')
p1 = pw.addPlot(left = "labels", bottom = "time", title = "all channels", row = 0, col = 0, colspan = 2)
p1.showGrid(x = True, y = True)
p1.getAxis('left').setPen('#000000') # 坐标轴上色
p1.getAxis('bottom').setPen('#000000') # 坐标轴上色
p2 = pw.addPlot(left = "label", bottom = "time", title = "single channel", row = 1, col = 0)
p2.showGrid(x = True, y = True)
p2.getAxis('left').setPen('#000000') # 坐标轴上色
p2.getAxis('bottom').setPen('#000000') # 坐标轴上色
p3 = pw.addPlot(left = "label", bottom = "time", title = "fft", row = 1, col = 1)
p3.showGrid(x = True, y = True)
p3.getAxis('left').setPen('#000000') # 坐标轴上色
p3.getAxis('bottom').setPen('#000000') # 坐标轴上色
# pw.setLabel('left', 'label')
# pw.setLabel('bottom', 'time')
# pw.setYRange(0, 1)

ui.checkBox_base.stateChanged.connect(on_checkBox_base_stateChanged)
ui.checkBox_notch.stateChanged.connect(on_checkBox_notch_stateChanged)
ui.checkBox_low.stateChanged.connect(on_checkBox_low_stateChanged)
ui.checkBox_high.stateChanged.connect(on_checkBox_high_stateChanged)

ui.show()
app.exec_()
