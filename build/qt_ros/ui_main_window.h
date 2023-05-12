/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_config;
    QGridLayout *gridLayout_3;
    QListView *listView_config;
    QGroupBox *groupBox_com;
    QGridLayout *gridLayout_4;
    QListView *listView_com;
    QGroupBox *groupBox_eve;
    QGridLayout *gridLayout_5;
    QListView *listView_eve;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_port;
    QPushButton *button_connect;
    QLineEdit *lineEdit_ip;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QStringLiteral("MainWindowDesign"));
        MainWindowDesign->resize(1076, 615);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QStringLiteral("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_config = new QGroupBox(centralwidget);
        groupBox_config->setObjectName(QStringLiteral("groupBox_config"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_config->sizePolicy().hasHeightForWidth());
        groupBox_config->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(groupBox_config);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(6);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        listView_config = new QListView(groupBox_config);
        listView_config->setObjectName(QStringLiteral("listView_config"));
        sizePolicy.setHeightForWidth(listView_config->sizePolicy().hasHeightForWidth());
        listView_config->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(listView_config, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_config, 1, 0, 1, 1);

        groupBox_com = new QGroupBox(centralwidget);
        groupBox_com->setObjectName(QStringLiteral("groupBox_com"));
        gridLayout_4 = new QGridLayout(groupBox_com);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        listView_com = new QListView(groupBox_com);
        listView_com->setObjectName(QStringLiteral("listView_com"));
        sizePolicy.setHeightForWidth(listView_com->sizePolicy().hasHeightForWidth());
        listView_com->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(listView_com, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_com, 2, 0, 1, 1);

        groupBox_eve = new QGroupBox(centralwidget);
        groupBox_eve->setObjectName(QStringLiteral("groupBox_eve"));
        gridLayout_5 = new QGridLayout(groupBox_eve);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        listView_eve = new QListView(groupBox_eve);
        listView_eve->setObjectName(QStringLiteral("listView_eve"));
        sizePolicy.setHeightForWidth(listView_eve->sizePolicy().hasHeightForWidth());
        listView_eve->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(listView_eve, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_eve, 3, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_port = new QLineEdit(centralwidget);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));
        sizePolicy.setHeightForWidth(lineEdit_port->sizePolicy().hasHeightForWidth());
        lineEdit_port->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit_port, 1, 1, 1, 1);

        button_connect = new QPushButton(centralwidget);
        button_connect->setObjectName(QStringLiteral("button_connect"));
        sizePolicy.setHeightForWidth(button_connect->sizePolicy().hasHeightForWidth());
        button_connect->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(button_connect, 2, 0, 1, 2);

        lineEdit_ip = new QLineEdit(centralwidget);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));
        sizePolicy.setHeightForWidth(lineEdit_ip->sizePolicy().hasHeightForWidth());
        lineEdit_ip->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit_ip, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 2);

        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setColumnStretch(0, 1);

        gridLayout_7->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1076, 28));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Preferences);
        menu_File->addSeparator();
        menu_File->addAction(actionAbout);
        menu_File->addAction(actionAbout_Qt);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", Q_NULLPTR));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", Q_NULLPTR));
        groupBox_config->setTitle(QApplication::translate("MainWindowDesign", "Configuration Log", Q_NULLPTR));
        groupBox_com->setTitle(QApplication::translate("MainWindowDesign", "Communication Log", Q_NULLPTR));
        groupBox_eve->setTitle(QApplication::translate("MainWindowDesign", "Events Log", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindowDesign", "IP", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindowDesign", "Port", Q_NULLPTR));
        lineEdit_port->setText(QApplication::translate("MainWindowDesign", "4455", Q_NULLPTR));
        button_connect->setText(QApplication::translate("MainWindowDesign", "Connect", Q_NULLPTR));
        lineEdit_ip->setText(QApplication::translate("MainWindowDesign", "127.0.0.1", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "&App", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
