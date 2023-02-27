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

		ReadSettings();
		setWindowIcon(QIcon(":/images/icon.png"));
		//	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
		QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

		/*********************
		** Logging
		**********************/
		//	ui.view_logging->setModel(qnode.loggingModel());
		QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

		/*********************
		** Auto Start
		**********************/
		//	if ( ui.checkbox_remember_settings->isChecked() ) {
		//		on_button_connect_clicked(true);
		//	}

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
		// 绘制波形
		connect(m_qNetStreaming, SIGNAL(SendData(float *, int, long)), this, SLOT(RecvAndDraw(float *, int, long)));
		// 通过节点发送采样频率
		connect(m_qNetStreaming, SIGNAL(SendRate(int)), &qnode, SLOT(QNodePub1(int)));
		// 通过节点发送数据包
		connect(m_qNetStreaming, SIGNAL(SendData(float *, int, long)), &qnode, SLOT(QNodePub2(float *, int, long)));
		// 初始化线条数量
		connect(m_qNetStreaming, SIGNAL(SendChan(int)), this, SLOT(InitLines(int)));
		// 消息框滚动
		connect(m_qNetStreaming, SIGNAL(LoggingConfigUpdated()), this, SLOT(UpdateLogConfig()));
		connect(m_qNetStreaming, SIGNAL(LoggingComUpdated()), this, SLOT(UpdateLogCom()));
		connect(m_qNetStreaming, SIGNAL(LoggingEveUpdated()), this, SLOT(UpdateLogEve()));

		ui.gridLayout->setColumnStretch(0, 1);
		ui.gridLayout->setColumnStretch(1, 2);
		ui.gridLayout->setColumnStretch(2, 5);
		ui.gridLayout->setRowStretch(0, 1);
		ui.gridLayout->setRowStretch(1, 2);
		ui.gridLayout->setRowStretch(2, 3);
		ui.gridLayout->setRowStretch(3, 3);
		// 初始化画布
		InitDraw();

		notch_check = ui.checkBox_notch->isChecked();
		lp_check = ui.checkBox_low->isChecked();
		hp_check = ui.checkBox_high->isChecked();
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

	/*
	 * These triggers whenever the button is clicked, regardless of whether it
	 * is already checked or not.
	 */

	// void MainWindow::on_button_connect_clicked(bool check ) {
	//	if ( ui.checkbox_use_environment->isChecked() ) {
	//		if ( !qnode.init() ) {
	//			showNoMasterMessage();
	//		} else {
	//			ui.button_connect->setEnabled(false);
	//		}
	//	} else {
	//		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
	//						  ui.line_edit_host->text().toStdString()) ) {
	//			showNoMasterMessage();
	//		} else {
	//			ui.button_connect->setEnabled(false);
	//			ui.line_edit_master->setReadOnly(true);
	//			ui.line_edit_host->setReadOnly(true);
	//			ui.line_edit_topic->setReadOnly(true);
	//		}
	//	}
	// }

	void MainWindow::on_checkbox_use_environment_stateChanged(int state)
	{
		//	bool enabled;
		//	if ( state == 0 ) {
		//		enabled = true;
		//	} else {
		//		enabled = false;
		//	}
		//	ui.line_edit_master->setEnabled(enabled);
		//	ui.line_edit_host->setEnabled(enabled);
		//	ui.line_edit_topic->setEnabled(enabled);
	}

	/*****************************************************************************
	** Implemenation [Slots][manually connected]
	*****************************************************************************/

	/**
	 * This function is signalled by the underlying model. When the model changes,
	 * this will drop the cursor down to the last line in the QListview to ensure
	 * the user can always see the latest log message.
	 */
	void MainWindow::updateLoggingView()
	{
		//	ui.view_logging->scrollToBottom();
	}
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

	void MainWindow::ReadSettings()
	{
		//	QSettings settings("Qt-Ros Package", "qt_ros");
		//	restoreGeometry(settings.value("geometry").toByteArray());
		//	restoreState(settings.value("windowState").toByteArray());
		//	QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
		//	QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
		//	//QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
		//	ui.line_edit_master->setText(master_url);
		//	ui.line_edit_host->setText(host_url);
		//	//ui.line_edit_topic->setText(topic_name);
		//	bool remember = settings.value("remember_settings", false).toBool();
		//	ui.checkbox_remember_settings->setChecked(remember);
		//	bool checked = settings.value("use_environment_variables", false).toBool();
		//	ui.checkbox_use_environment->setChecked(checked);
		//	if ( checked ) {
		//		ui.line_edit_master->setEnabled(false);
		//		ui.line_edit_host->setEnabled(false);
		//		//ui.line_edit_topic->setEnabled(false);
		//	}
	}

	void MainWindow::WriteSettings()
	{
		//	QSettings settings("Qt-Ros Package", "qt_ros");
		//	settings.setValue("master_url",ui.line_edit_master->text());
		//	settings.setValue("host_url",ui.line_edit_host->text());
		//	//settings.setValue("topic_name",ui.line_edit_topic->text());
		//	settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
		//	settings.setValue("geometry", saveGeometry());
		//	settings.setValue("windowState", saveState());
		//	settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));
	}

	void MainWindow::closeEvent(QCloseEvent *event)
	{
		WriteSettings();
		QMainWindow::closeEvent(event);
	}
	// 初始化画布
	void MainWindow::InitDraw()
	{
		// 初始化坐标轴与画布，并将画布设置到widget上
		m_axisX = new QValueAxis();
		m_axisY = new QValueAxis();
		m_chart = new QChart();
		ui.chartwidget->setChart(m_chart);

		//	m_chartView = new QChartView(m_chart, this);// 将chart实例添加到chartview上
		//	ui.gridLayout->addWidget(m_chartView, 0, 1, 5, 1);// 在网格布局中添加chartview

		m_chart->setTitleBrush(QBrush(QColor(0, 0, 0))); // 设置标题Brush
		m_chart->setTitleFont(QFont("微软雅黑"));		 // 设置标题字体
		m_chart->setTitle("曲线图");					 // 设置标题
		m_chart->legend()->hide();						 //隐藏图例
		m_chart->addAxis(m_axisX, Qt::AlignBottom);		 //设置坐标轴位于chart中的位置
		m_chart->addAxis(m_axisY, Qt::AlignLeft);

		m_axisX->setTitleText("x");
		m_axisX->setRange(0, 1);
		m_axisX->setGridLineVisible(false);
		//	m_axisX->setLabelFormat("%s");

		m_axisY->setTitleText("y");
		m_axisY->setRange(0, 1);
		m_axisY->setGridLineVisible(false);
	}

	void MainWindow::RecvAndDraw(float *pfData, int nEegChan, long nNumSamples)
	{
		/*
		QString path = "/home/wuyou/out_new.txt";
		QFile file(path);
		file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
		QTextStream out(&file);
		for (int i = 0; i < nEegChan; ++i)
		{
			for (int j = 0; j < nNumSamples; ++j)
			{
				out << pfData[i * nEegChan + j] << '\t';
			}
			out << '\n';
		}
		file.close();
		*/

		// 存放数据
		QVector<QVector<double>> packet(nEegChan, QVector<double>(nNumSamples));
		// 基线校准，并计算最大最小值
		float fSample;
		QVector<float> aMin;
		QVector<float> aMax;
		QVector<float> aAvg;

		aMin.resize(nEegChan);
		aMax.resize(nEegChan);
		aAvg.resize(nEegChan);

		for (int i = 0; i < nEegChan; ++i)
		{
			aAvg[i] = 0.0f;
			for (int j = 0; j < nNumSamples; ++j)
			{
				fSample = pfData[j * nEegChan + i];

				if (j == 0)
				{
					aMin[i] = fSample;
					aMax[i] = fSample;
				}
				else
				{
					if (fSample < aMin[i])
						aMin[i] = fSample;
					if (fSample > aMax[i])
						aMax[i] = fSample;
				}

				aAvg[i] += fSample;
			}
			aAvg[i] /= nNumSamples;
		}
		for (int i = 0; i < nEegChan; ++i)
		{
			for (int j = 0; j < nNumSamples; ++j)
			{
				packet[i][j] = pfData[j * nEegChan + i] - aAvg[i];
			}
		}

		// 50Hz陷波滤波
		if (notch_check)
		{
			spuce::notch_allpass<double, double> Notch(0.05);
			for (int i = 0; i < nEegChan; ++i)
			{
				for (int j = 0; j < nNumSamples; ++j)
				{
					packet[i][j] = Notch.clock(packet[i][j]);
				}
			}
		}

		// 低通滤波
		if (lp_check && ~hp_check)
		{
			// 滤波器阶数
			long O = 6;
			// 截止频率，单位为kHz
			spuce::float_type f_cutoff = ui.doubleSpinBox_low->value() / 1000;
			// 通带波纹
			spuce::float_type ripple = 0.5;

			spuce::iir_coeff BPF(O);
			chebyshev_iir(BPF, f_cutoff, ripple);

			spuce::iir_df<spuce::float_type> LPF(BPF);

			for (int i = 0; i < nEegChan; ++i)
			{
				for (int j = 0; j < nNumSamples; ++j)
				{
					packet[i][j] = LPF.clock(packet[i][j]);
				}
			}
		}

		// 高通滤波
		if (hp_check && ~lp_check)
		{
			// 滤波器阶数
			long O = 6;
			// 截止频率，单位为kHz
			spuce::float_type f_cutoff = ui.doubleSpinBox_high->value() / 1000;
			// 通带波纹
			spuce::float_type ripple = 0.5;

			spuce::iir_coeff BPF(O, spuce::filter_type::high);
			chebyshev_iir(BPF, f_cutoff, ripple);

			spuce::iir_df<spuce::float_type> HPF(BPF);

			for (int i = 0; i < nEegChan; ++i)
			{
				for (int j = 0; j < nNumSamples; ++j)
				{
					packet[i][j] = HPF.clock(packet[i][j]);
				}
			}
		}

		// 曲线绘制
		for (int i = 0; i < nEegChan; ++i)
		{
			double dAutoScale = dDeltaY / ((aMax[i] - aMin[i]) * 1.25);
			double nYOffset = (i + 0.5) * dDeltaY;

			QVector<QPointF> aPoints;
			aPoints.resize(nNumSamples);
			for (int j = 0; j < nNumSamples; ++j)
			{
				aPoints[j].setX(j);
				aPoints[j].setY(nYOffset + packet[i][j] * dAutoScale);
			}
			m_spSeries[i]->replace(aPoints);
		}
		// 设置x轴刻度范围
		m_axisX->setRange(0, nNumSamples);
	}

	void MainWindow::InitLines(int lineNums)
	{
		nNumChannels = lineNums;
		dDeltaY = 1.0 / nNumChannels;
		//	qDebug() << "I receive chans:" << nNumChannels;
		//	qDebug() << dDeltaY;
		//	m_axisY->setRange(-1, 2 * nNumChannels - 1);                              //设置Y轴范围
		// 添加了19个坐标轴上的点
		//	m_axisY->setTickCount(2 * nNumChannels + 1);

		for (int i = 0; i < nNumChannels; ++i)
		{
			QSplineSeries *series = new QSplineSeries();
			m_spSeries.append(series);
			// 把曲线添加到画布上
			m_chart->addSeries(m_spSeries[i]);
			// 把坐标轴绑定到曲线上
			m_spSeries[i]->attachAxis(m_axisX);
			m_spSeries[i]->attachAxis(m_axisY);
			// 设置曲线颜色
			m_spSeries[i]->setColor(QColor(0, 0, 0));
		}
	}
} // namespace qt_ros

void qt_ros::MainWindow::on_button_connect_clicked()
{
	qnode.init();
	QThread::sleep(2);
	qDebug() << "Main wait 1 2s";
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

void qt_ros::MainWindow::on_checkBox_notch_stateChanged(int arg1)
{
	notch_check = arg1;
	//	notch_check = ui.checkBox_notch->isChecked();
	//	qDebug() << arg1;
}

void qt_ros::MainWindow::on_checkBox_low_stateChanged(int arg1)
{
	lp_check = arg1;
	//	lp_check = ui.checkBox_low->isChecked();
	//	qDebug() << arg1;
}

void qt_ros::MainWindow::on_checkBox_high_stateChanged(int arg1)
{
	hp_check = arg1;
	//	hp_check = ui.checkBox_high->isChecked();
	//	qDebug() << arg1;
}
