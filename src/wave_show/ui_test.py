#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

from PySide2.QtWidgets import QApplication, QMainWindow
from test1 import Ui_MainWindow

app = QApplication([])
window = QMainWindow()
ui = Ui_MainWindow()
ui.setupUi(window)
ui.pushButton.setText("hello world")
window.show()

app.exec_()
