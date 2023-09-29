# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'ui_waveshow.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *

from plotgraph import GraphicsLayoutWidget


class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(1023, 844)
        self.gridLayout = QGridLayout(Form)
        self.gridLayout.setObjectName(u"gridLayout")
        self.tabWidget = QTabWidget(Form)
        self.tabWidget.setObjectName(u"tabWidget")
        sizePolicy = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.tabWidget.sizePolicy().hasHeightForWidth())
        self.tabWidget.setSizePolicy(sizePolicy)
        self.tab = QWidget()
        self.tab.setObjectName(u"tab")
        self.gridLayout_2 = QGridLayout(self.tab)
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.checkBox_notch = QCheckBox(self.tab)
        self.checkBox_notch.setObjectName(u"checkBox_notch")

        self.gridLayout_2.addWidget(self.checkBox_notch, 1, 0, 1, 1)

        self.spinBox_high = QSpinBox(self.tab)
        self.spinBox_high.setObjectName(u"spinBox_high")
        self.spinBox_high.setEnabled(False)
        self.spinBox_high.setValue(5)

        self.gridLayout_2.addWidget(self.spinBox_high, 3, 0, 1, 1)

        self.comboBox = QComboBox(self.tab)
        self.comboBox.setObjectName(u"comboBox")
        self.comboBox.setEditable(False)

        self.gridLayout_2.addWidget(self.comboBox, 7, 0, 1, 1)

        self.spinBox_low = QSpinBox(self.tab)
        self.spinBox_low.setObjectName(u"spinBox_low")
        self.spinBox_low.setEnabled(False)
        self.spinBox_low.setValue(30)

        self.gridLayout_2.addWidget(self.spinBox_low, 5, 0, 1, 1)

        self.checkBox_base = QCheckBox(self.tab)
        self.checkBox_base.setObjectName(u"checkBox_base")

        self.gridLayout_2.addWidget(self.checkBox_base, 0, 0, 1, 1)

        self.checkBox_low = QCheckBox(self.tab)
        self.checkBox_low.setObjectName(u"checkBox_low")

        self.gridLayout_2.addWidget(self.checkBox_low, 4, 0, 1, 1)

        self.checkBox_high = QCheckBox(self.tab)
        self.checkBox_high.setObjectName(u"checkBox_high")

        self.gridLayout_2.addWidget(self.checkBox_high, 2, 0, 1, 1)

        self.verticalSpacer_3 = QSpacerItem(20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.gridLayout_2.addItem(self.verticalSpacer_3, 8, 0, 1, 1)

        self.label = QLabel(self.tab)
        self.label.setObjectName(u"label")

        self.gridLayout_2.addWidget(self.label, 6, 0, 1, 1)

        self.tabWidget.addTab(self.tab, "")
        self.tab_2 = QWidget()
        self.tab_2.setObjectName(u"tab_2")
        self.gridLayout_3 = QGridLayout(self.tab_2)
        self.gridLayout_3.setObjectName(u"gridLayout_3")
        self.checkBox_base_2 = QCheckBox(self.tab_2)
        self.checkBox_base_2.setObjectName(u"checkBox_base_2")

        self.gridLayout_3.addWidget(self.checkBox_base_2, 0, 0, 1, 1)

        self.checkBox_notch_2 = QCheckBox(self.tab_2)
        self.checkBox_notch_2.setObjectName(u"checkBox_notch_2")

        self.gridLayout_3.addWidget(self.checkBox_notch_2, 1, 0, 1, 1)

        self.checkBox_high_2 = QCheckBox(self.tab_2)
        self.checkBox_high_2.setObjectName(u"checkBox_high_2")

        self.gridLayout_3.addWidget(self.checkBox_high_2, 2, 0, 1, 1)

        self.spinBox_high_2 = QSpinBox(self.tab_2)
        self.spinBox_high_2.setObjectName(u"spinBox_high_2")
        self.spinBox_high_2.setEnabled(False)
        self.spinBox_high_2.setValue(5)

        self.gridLayout_3.addWidget(self.spinBox_high_2, 3, 0, 1, 1)

        self.checkBox_low_2 = QCheckBox(self.tab_2)
        self.checkBox_low_2.setObjectName(u"checkBox_low_2")

        self.gridLayout_3.addWidget(self.checkBox_low_2, 4, 0, 1, 1)

        self.spinBox_low_2 = QSpinBox(self.tab_2)
        self.spinBox_low_2.setObjectName(u"spinBox_low_2")
        self.spinBox_low_2.setEnabled(False)
        self.spinBox_low_2.setValue(30)

        self.gridLayout_3.addWidget(self.spinBox_low_2, 5, 0, 1, 1)

        self.label_2 = QLabel(self.tab_2)
        self.label_2.setObjectName(u"label_2")

        self.gridLayout_3.addWidget(self.label_2, 6, 0, 1, 1)

        self.comboBox_2 = QComboBox(self.tab_2)
        self.comboBox_2.setObjectName(u"comboBox_2")
        self.comboBox_2.setEditable(False)

        self.gridLayout_3.addWidget(self.comboBox_2, 7, 0, 1, 1)

        self.verticalSpacer_4 = QSpacerItem(20, 540, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.gridLayout_3.addItem(self.verticalSpacer_4, 8, 0, 1, 1)

        self.tabWidget.addTab(self.tab_2, "")

        self.gridLayout.addWidget(self.tabWidget, 0, 0, 1, 1)

        self.verticalLayout = QVBoxLayout()
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.widget = GraphicsLayoutWidget(Form)
        self.widget.setObjectName(u"widget")
        sizePolicy.setHeightForWidth(self.widget.sizePolicy().hasHeightForWidth())
        self.widget.setSizePolicy(sizePolicy)

        self.verticalLayout.addWidget(self.widget)


        self.gridLayout.addLayout(self.verticalLayout, 0, 1, 1, 1)

        self.gridLayout.setColumnStretch(0, 1)
        self.gridLayout.setColumnStretch(1, 6)

        self.retranslateUi(Form)

        self.tabWidget.setCurrentIndex(0)


        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.checkBox_notch.setText(QCoreApplication.translate("Form", u"50 Hz Notch Filter", None))
        self.checkBox_base.setText(QCoreApplication.translate("Form", u"Baseline Correctioin", None))
        self.checkBox_low.setText(QCoreApplication.translate("Form", u"Low Pass Filter", None))
        self.checkBox_high.setText(QCoreApplication.translate("Form", u"High Pass Filter", None))
        self.label.setText(QCoreApplication.translate("Form", u"Select Channel", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), QCoreApplication.translate("Form", u"Tab 1", None))
        self.checkBox_base_2.setText(QCoreApplication.translate("Form", u"Baseline Correctioin", None))
        self.checkBox_notch_2.setText(QCoreApplication.translate("Form", u"50 Hz Notch Filter", None))
        self.checkBox_high_2.setText(QCoreApplication.translate("Form", u"High Pass Filter", None))
        self.checkBox_low_2.setText(QCoreApplication.translate("Form", u"Low Pass Filter", None))
        self.label_2.setText(QCoreApplication.translate("Form", u"Select Channel", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), QCoreApplication.translate("Form", u"Tab 2", None))
    # retranslateUi

