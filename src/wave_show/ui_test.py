#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

from PySide2.QtWidgets import QApplication, QMainWindow
from test1 import Ui_MainWindow

class Stats:
    def __init__(self):
        self.window = QMainWindow()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self.window)
        self.window.show()
        
if __name__=='__main__':
    
    app = QApplication([])
    stats = Stats()
    stats.ui.pushButton.setText("hello world")
# window = QMainWindow()
# ui = Ui_MainWindow()
# ui.setupUi(window)
# window.show()
    app.exec_()
