/**
 * @file /include/qt_ros/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef qt_ros_QNODE_HPP_
#define qt_ros_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <vector>
#include <QThread>
#include <QStringListModel>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qt_ros
{

	/*****************************************************************************
	** Class
	*****************************************************************************/

	class QNode : public QThread
	{
		Q_OBJECT
	public:
		QNode(int argc, char **argv);
		virtual ~QNode();
		bool init();
		bool init(const std::string &master_url, const std::string &host_url);
		void run();

		/*********************
		** Logging
		**********************/
		enum LogLevel
		{
			Debug,
			Info,
			Warn,
			Error,
			Fatal
		};

		QStringListModel *loggingModel() { return &logging_model; }
		void log(const LogLevel &level, const std::string &msg);

	Q_SIGNALS:
		void loggingUpdated();
		void rosShutdown();

	private slots:
		// 发布采样频率
		void QNodePub1(int);
		// 发布数据包
		void QNodePub2(float *pfData, int nChannels, long nSamples);

	private:
		int init_argc;
		char **init_argv;
		// 发布者，发布采样频率
		ros::Publisher chat_pub1;
		// 发布者，发布数据包
		ros::Publisher chat_pub2;
		QStringListModel logging_model;
	};

} // namespace qt_ros

#endif /* qt_ros_QNODE_HPP_ */
