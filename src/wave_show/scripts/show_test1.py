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
t = np.arange(0,512)

class MySignal(QObject):
	signal = Signal(Float32MultiArray)

def test_func1(val):
	print("I get signal",val)
	pw.clear()
	pw.plot(t,val)

mysi = MySignal()
mysi.signal.connect(test_func1)

def callback_get_packet(data):
	global mysi
	# 把一维数组转换成二维数组
	rawdata = np.array(data.data[:]).reshape(512, 35).T
	print(rawdata.shape)
	wave1 = rawdata[0]
	print("wave1:", wave1.shape[0])
	mysi.signal.emit(wave1)
	print("I send wave1")
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


ui.show()
app.exec_()


