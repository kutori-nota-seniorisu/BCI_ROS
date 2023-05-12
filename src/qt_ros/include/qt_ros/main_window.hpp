/**
 * @file /include/qt_ros/main_window.hpp
 *
 * @brief Qt based gui for qt_ros.
 *
 * @date November 2010
 **/
#ifndef qt_ros_MAIN_WINDOW_H
#define qt_ros_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include <QtNetwork>
#include <QtCharts/QtCharts>
#include <atomic>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "qt_ros/Packets.h"
#include "qnetstreamingreceiver.hpp"
#include "spuce/filters/notch_allpass.h"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace qt_ros {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();

private slots:
    // 连接Qt与仿真器
	void on_button_connect_clicked();
    // 更新日志消息
    void UpdateLogConfig();
	void UpdateLogCom();
	void UpdateLogEve();

private:
	Ui::MainWindowDesign ui;
	QNode qnode;

	QNetStreamingReceiver* m_qNetStreaming;
	BasicInfoAcq m_basicInfo;

	QThread* m_thread;
};

}  // namespace qt_ros

#endif // qt_ros_MAIN_WINDOW_H
