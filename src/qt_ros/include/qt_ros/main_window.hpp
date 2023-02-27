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

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();
	// 初始化画布
	void InitDraw();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_checkbox_use_environment_stateChanged(int state);

	/******************************************
	** Manual connections
	*******************************************/
	void updateLoggingView(); // no idea why this can't connect automatically

private slots:
	void on_button_connect_clicked();
	void InitLines(int lineNums);
	void RecvAndDraw(float* pfData, int nEegChan, long nNumSamples);
	void UpdateLogConfig();
	void UpdateLogCom();
	void UpdateLogEve();

	void on_checkBox_notch_stateChanged(int arg1);

	void on_checkBox_low_stateChanged(int arg1);

	void on_checkBox_high_stateChanged(int arg1);

private:
	Ui::MainWindowDesign ui;
	QNode qnode;

	QNetStreamingReceiver* m_qNetStreaming;
	BasicInfoAcq m_basicInfo;

	QChart* m_chart;
	QList<QSplineSeries*> m_spSeries;
	QValueAxis* m_axisX;
	QValueAxis* m_axisY;
	int nNumChannels;
	double dDeltaY;
	QThread* m_thread;

	bool notch_check;
	bool hp_check;
	bool lp_check;
};

}  // namespace qt_ros

#endif // qt_ros_MAIN_WINDOW_H
