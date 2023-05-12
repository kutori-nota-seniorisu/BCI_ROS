/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <QThread>
#include <iostream>
#include "../include/qt_ros/main_window.hpp"

// 添加信号处理文件
#include "spuce/filters/iir_coeff.h"
#include "spuce/filters/chebyshev_iir.h"
#include "spuce/filters/iir_df.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qt_ros
{

	using namespace Qt;

    /*****************************************************************************
	** Implementation [MainWindow]
	*****************************************************************************/

	MainWindow::MainWindow(int argc, char **argv, QWidget *parent)
		: QMainWindow(parent), qnode(argc, argv)
	{
		ui.setupUi(this);																	 // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
		QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

		setWindowIcon(QIcon(":/images/icon.png"));
        QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

        /*********************
        ** Logging
        **********************/
//		QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

		// 构造新线程
		m_thread = new QThread();
		m_qNetStreaming = new QNetStreamingReceiver();
		m_qNetStreaming->moveToThread(m_thread);

		// 设置三个消息框
		ui.listView_config->setModel(m_qNetStreaming->LoggingConfigModel());
		ui.listView_com->setModel(m_qNetStreaming->LoggingComModel());
		ui.listView_eve->setModel(m_qNetStreaming->LoggingEveModel());

		// 启动线程
		connect(m_thread, SIGNAL(started()), m_qNetStreaming, SLOT(Run()));
		// 通过节点发送采样频率
        connect(m_qNetStreaming, SIGNAL(SendRate(int)), &qnode, SLOT(QNode_Pub_Rate(int)));
		// 通过节点发送数据包
        connect(m_qNetStreaming, SIGNAL(SendData(float *, int, long)), &qnode, SLOT(QNode_Pub_Packet(float *, int, long)));
		// 初始化线条数量
		connect(m_qNetStreaming, SIGNAL(SendChan(int)), this, SLOT(InitLines(int)));
		// 消息框滚动
		connect(m_qNetStreaming, SIGNAL(LoggingConfigUpdated()), this, SLOT(UpdateLogConfig()));
		connect(m_qNetStreaming, SIGNAL(LoggingComUpdated()), this, SLOT(UpdateLogCom()));
		connect(m_qNetStreaming, SIGNAL(LoggingEveUpdated()), this, SLOT(UpdateLogEve()));
	}

	MainWindow::~MainWindow() {}

	/*****************************************************************************
	** Implementation [Slots]
	*****************************************************************************/

	void MainWindow::showNoMasterMessage()
	{
		QMessageBox msgBox;
		msgBox.setText("Couldn't find the ros master.");
		msgBox.exec();
		close();
	}

	/*****************************************************************************
	** Implemenation [Slots][manually connected]
	*****************************************************************************/

	/**
	 * This function is signalled by the underlying model. When the model changes,
	 * this will drop the cursor down to the last line in the QListview to ensure
	 * the user can always see the latest log message.
	 */
    // 更新日志消息
	void MainWindow::UpdateLogConfig()
	{
		ui.listView_config->scrollToBottom();
	}
	void MainWindow::UpdateLogCom()
	{
		ui.listView_com->scrollToBottom();
	}
	void MainWindow::UpdateLogEve()
	{
		ui.listView_eve->scrollToBottom();
	}

	/*****************************************************************************
	** Implementation [Menu]
	*****************************************************************************/

	void MainWindow::on_actionAbout_triggered()
	{
		QMessageBox::about(this, tr("About ..."), tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
	}

	/*****************************************************************************
	** Implementation [Configuration]
	*****************************************************************************/

	void MainWindow::closeEvent(QCloseEvent *event)
	{
		QMainWindow::closeEvent(event);
	}

} // namespace qt_ros

// 连接Qt与仿真器
void qt_ros::MainWindow::on_button_connect_clicked()
{
	qnode.init();
//	QThread::sleep(2);
//	qDebug() << "Main wait 1 2s";
	QString sIP = ui.lineEdit_ip->text();
	QString sPort = ui.lineEdit_port->text();
	qDebug() << "Get connect" << sIP << "  " << sPort;

	if (m_qNetStreaming->IsConnected())
	{
		// stop netstreaming client
		m_qNetStreaming->SetClient(false);
		m_qNetStreaming->ClientRequestStreamData(false);
		m_qNetStreaming->CloseClient();
		m_thread->quit();
		ui.button_connect->setText("Connect");
	}
	else
	{
		// change some UI elements
		ui.button_connect->setText("Disconnect");

		// start netstreaming client
		m_qNetStreaming->SetClient(true, sIP, sPort.toInt());
		m_thread->start();
	}
}
