#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import rospy
from std_msgs.msg import Bool
from  sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge

def TestPub():
	rospy.init_node('test_pub', anonymous=True)
	state_pub = rospy.Publisher('/StateResultNode', Bool, queue_size = 10)
	rate = rospy.Rate(1)

	msg = Bool()
	msg.data = True
	for i in range(2):
		state_pub.publish(msg)
		print("I publish state")
		rate.sleep()

	pic_pub = rospy.Publisher('/PictureNode', Image, queue_size=10)
	path = "/home/sd/BCI_ROS/src/ptb_show/test/0.png"
	image = cv2.imread(path)
	bridge = CvBridge()
	for i in range(2):
		pic_pub.publish(bridge.cv2_to_imgmsg(image, "bgr8"))
		print("I publish pic")
		rate.sleep()

if __name__ == '__main__':
	try:
		TestPub()
	except rospy.ROSInterruptException:
		pass