#!/usr/bin/env python3
#coding:utf-8

import rospy
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge,CvBridgeError

def callback(data):
	bridge = CvBridge()
	cv_image = bridge.imgmsg_to_cv2(data,"bgr8")
	cv2.imshow("receive",cv_image)
	cv2.waitKey(0)

def showImage():
	rospy.init_node('showImage',anonymous = True)
	rospy.Subscriber('ShowImage', Image, callback)
	rospy.spin()

if __name__ == '__main__':
	showImage()
