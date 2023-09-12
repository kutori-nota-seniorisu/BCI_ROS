#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import rospy
import sys
sys.path.append('.')
import cv2
import os
import numpy as np
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

def pubImage():
	rospy.init_node('pubImage',anonymous = True)
	pub = rospy.Publisher('ShowImage', Image, queue_size = 10)
	rate = rospy.Rate(1)
	bridge = CvBridge()
	gt_imdb = []
	#path是我存放图片的文件夹
	path = "/home/sd/BCI_ROS/src/ptb_show/test"
	for item in os.listdir(path):
		gt_imdb.append(os.path.join(path,item))
		
	while not rospy.is_shutdown():
		for imagepath in gt_imdb:
			image = cv2.imread(imagepath)
			image = cv2.resize(image,(900,450))
			pub.publish(bridge.cv2_to_imgmsg(image,"bgr8"))
			#cv2.imshow("lala",image)
			print("I publish")
			# cv2.waitKey(0)
			rate.sleep()

if __name__ == '__main__':
	try:
		pubImage()
	except rospy.ROSInterruptException:
		pass
