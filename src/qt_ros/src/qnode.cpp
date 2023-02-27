/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/UInt16.h>
#include <sstream>
#include <QDebug>
#include <QFile>
#include "../include/qt_ros/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qt_ros
{

	/*****************************************************************************
	** Implementation
	*****************************************************************************/

	QNode::QNode(int argc, char **argv) : init_argc(argc),
										  init_argv(argv)
	{
	}

	QNode::~QNode()
	{
		if (ros::isStarted())
		{
			ros::shutdown(); // explicitly needed since we use ros::start();
			ros::waitForShutdown();
		}
		wait();
	}

	bool QNode::init()
	{
		ros::init(init_argc, init_argv, "qt_ros");
		if (!ros::master::check())
		{
			return false;
		}
		ros::start(); // explicitly needed since our nodehandle is going out of scope.
		ros::NodeHandle n;
		// 发布者，发布采样频率
		chat_pub1 = n.advertise<std_msgs::UInt16>("/samplerate", 10);
		// 发布者，发布数据包
		chat_pub2 = n.advertise<std_msgs::Float32MultiArray>("/packet", 1000);
		//	start();
		return true;
	}

	bool QNode::init(const std::string &master_url, const std::string &host_url)
	{
		//	std::map<std::string,std::string> remappings;
		//	remappings["__master"] = master_url;
		//	remappings["__hostname"] = host_url;
		//	ros::init(remappings,"qt_ros");
		//	if ( ! ros::master::check() ) {
		//		return false;
		//	}
		//	ros::start(); // explicitly needed since our nodehandle is going out of scope.
		//	ros::NodeHandle n;
		//	// Add your ros communications here.
		//	chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
		//	start();
		//	return true;
	}

	void QNode::run()
	{
		//	ros::Rate loop_rate(1);
		//	int count = 0;
		//	while ( ros::ok() ) {

		//		std_msgs::String msg;
		////		std_msgs::Float32MultiArray msg;
		////		float* dd;
		////		QVector<float> da;
		////		std::vector<float> dv;
		////		msg.data = dv;
		//		std::stringstream ss;
		//		ss << "hello world " << count;
		//		msg.data = ss.str();
		//		chatter_publisher.publish(msg);
		//		log(Info,std::string("I sent: ")+msg.data);
		//		ros::spinOnce();
		//		loop_rate.sleep();
		//		++count;
		//	}
		//	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
		//	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
	}

	void QNode::log(const LogLevel &level, const std::string &msg)
	{
		logging_model.insertRows(logging_model.rowCount(), 1);
		std::stringstream logging_model_msg;
		switch (level)
		{
		case (Debug):
		{
			ROS_DEBUG_STREAM(msg);
			logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
			break;
		}
		case (Info):
		{
			ROS_INFO_STREAM(msg);
			logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
			break;
		}
		case (Warn):
		{
			ROS_WARN_STREAM(msg);
			logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
			break;
		}
		case (Error):
		{
			ROS_ERROR_STREAM(msg);
			logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
			break;
		}
		case (Fatal):
		{
			ROS_FATAL_STREAM(msg);
			logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
			break;
		}
		}
		QVariant new_row(QString(logging_model_msg.str().c_str()));
		logging_model.setData(logging_model.index(logging_model.rowCount() - 1), new_row);
		Q_EMIT loggingUpdated(); // used to readjust the scrollbar
	}

	// 发布者，发布采样频率
	void QNode::QNodePub1(int nSampleRate)
	{
		std_msgs::UInt16 msg;
		msg.data = nSampleRate;
		ROS_INFO("I pub rate uint16 data: %u", msg.data);
		chat_pub1.publish(msg);
	}

	// 发布者，发布数据包
	void QNode::QNodePub2(float *pfData, int nChannels, long nSamples)
	{
		std::vector<float> vEegData(pfData, pfData + nChannels * nSamples);

		/*
		QString path = "/home/wuyou/out_ros.txt";
		QFile file(path);
		file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
		QTextStream out(&file);
		for (int i = 0; i < nChannels; ++i)
		{
			for (int j = 0; j < nSamples; ++j)
			{
				out << vEegData[i * nChannels + j] << '\t';
			}
			out << '\n';
		}
		file.close();
		*/

		std_msgs::Float32MultiArray msg;
		msg.data = vEegData;
		// ROS_INFO("I send data[0] %f", msg.data[0]);
		chat_pub2.publish(msg);
	}
} // namespace qt_ros
