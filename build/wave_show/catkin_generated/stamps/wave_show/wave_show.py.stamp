#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import rospy
from std_msgs.msg import String

from PySide2.QtWidgets import QApplication
from PySide2.QtUiTools import QUiLoader
import pyqtgraph as pg
import numpy as np
count = 0
class WaveShow:
    def __init__(self):
        # 从文件中加载UI定义
        loader = QUiLoader()
		# pyside2 一定要使用registerCustomWidget 
        # 来注册 ui 文件中的第三方控件，这样加载的时候
        # loader才知道第三方控件对应的类，才能实例化对象
        loader.registerCustomWidget(pg.PlotWidget)
        self.ui = loader.load('/home/wuyou/BCI_ROS/src/wave_show/scripts/ui_waveshow.ui')
		# widget 是控件名称，需要注意
        self.pw = self.ui.widget
        self.pw.setBackground('w')
        self.pw.setLabel('left', '幅值')
        self.pw.setLabel('bottom', '弧度')
        self.ui.pushButton.clicked.connect(self.sin_curv)

    def sin_curv(self):
        global count
        t = np.arange(-5, 5, 0.01)
        y = np.sin(t+count*0.01)
        count = count + 1
        self.pw.clear()
        self.pw.setTitle('正弦函数曲线', size='12pt')
        self.pw.plot(t, y, pen=pg.mkPen('b'))

def callback(data):
     rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)

def listener():
    	# In ROS, nodes are uniquely named. If two nodes with the same
	# name are launched, the previous one is kicked off. The
	# anonymous=True flag means that rospy will choose a unique
	# name for our 'listener' node so that multiple listeners can
	# run simultaneously.
	rospy.init_node('listener', anonymous=True)
	rospy.Subscriber("chatter", String, callback)
	# spin() simply keeps python from exiting until this node is stopped
	rospy.spin()
     
if __name__ == '__main__':
    listener()
    app = QApplication([])
    stats = WaveShow()
    stats.ui.show()
    app.exec_()


