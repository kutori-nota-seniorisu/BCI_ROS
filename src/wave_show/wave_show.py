#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

from PySide2.QtWidgets import QApplication
from PySide2.QtUiTools import QUiLoader
import pyqtgraph as pg
import numpy as np

class WaveShow:
    def __init__(self):
        # 从文件中加载UI定义
        loader = QUiLoader()
		# pyside2 一定要使用registerCustomWidget 
        # 来注册 ui 文件中的第三方控件，这样加载的时候
        # loader才知道第三方控件对应的类，才能实例化对象
        loader.registerCustomWidget(pg.PlotWidget)
        
        self.ui = loader.load('/home/wuyou/BCI_ROS/src/wave_show/ui_waveshow.ui')
		# widget 是控件名称，需要注意
        self.pw = self.ui.widget

        self.pw.setBackground('w')

        self.pw.setLabel('left', '幅值')
        self.pw.setLabel('bottom', '弧度')

        self.ui.pushButton.clicked.connect(self.sin_curv)

    def sin_curv(self):
        t = np.arange(-5, 5, 0.01)
        y = np.sin(t)
        self.pw.clear()
        self.pw.setTitle('正弦函数曲线', size='12pt')
        self.pw.plot(t, y, pen=pg.mkPen('b'))

if __name__ == '__main__':

    app = QApplication([])
    stats = WaveShow()
    stats.ui.show()
    app.exec_()


