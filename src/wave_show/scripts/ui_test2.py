#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

from PySide2.QtWidgets import QApplication, QMainWindow
from PySide2.QtUiTools import QUiLoader
app = QApplication([])
loader = QUiLoader()
ui = loader.load("/home/wuyou/BCI_ROS/src/wave_show/scripts/test1.ui")
ui.show()
app.exec_()
