#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import rospy
from std_msgs.msg import String
from std_msgs.msg import Float32MultiArray

from PySide2.QtWidgets import QApplication
from PySide2.QtUiTools import QUiLoader
from PySide2.QtCore import Signal, QObject
import pyqtgraph as pg
import numpy as np
count = 0
# t 为时间刻度
t = np.arange(0,512)

# 需要手动创建信号的类，然后才可将信号与槽相互连接
class MySignal(QObject):
	signal = Signal(Float32MultiArray)

# 定义了一个槽函数，绘制波形
def test_func1(val):
	print("I get rawdata",val.shape)
	nEegChan = val.shape[0]
	aAvg = np.mean(val, -1)
	aMax = np.max(val, -1)
	aMin = np.min(val, -1)
	
	## 曲线绘制
	# 自适应范围
	dAutoScale = 1.0 / ((aMax[0] - aMin[0]) * 1.25)
	# 偏移量
	
	pw.clear()
	pw.plot(t, val[0] * dAutoScale) 
	pw.plot(t, val[1] * dAutoScale + 2)

# 实例化信号类的对象，然后将该对象的信号与对应的槽函数连接，此处槽函数为 test_func1
mysi = MySignal()
mysi.signal.connect(test_func1)

# 定义了 ros 接收节点的回调函数，接收到数据包后发送信号，由槽函数进行绘制
def callback_get_packet(data):
	global mysi
	# 把一维数组转换成二维数组
	rawdata = np.array(data.data[:]).reshape(512, 35).T
	print(rawdata.shape)
	# wave1 = rawdata[0]
	# print("wave1:", wave1.shape[0])
	mysi.signal.emit(rawdata)
	print("I send rawdata")

rospy.init_node('listener', anonymous=True)
rospy.Subscriber("packet", Float32MultiArray, callback_get_packet)


app = QApplication([])
loader = QUiLoader()
# pyside2 一定要使用registerCustomWidget 
# 来注册 ui 文件中的第三方控件，这样加载的时候
# loader才知道第三方控件对应的类，才能实例化对象
loader.registerCustomWidget(pg.PlotWidget)
ui = loader.load('/home/wuyou/BCI_ROS/src/wave_show/scripts/ui_waveshow.ui')
# widget 是控件名称，需要注意
pw = ui.widget
pw.setBackground('w')
pw.setLabel('left', '幅值')
pw.setLabel('bottom', '弧度')
pw.setYRange(-1, 3)


ui.show()
app.exec_()


