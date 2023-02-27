#!/usr/bin/env python
# -*- coding: UTF-8 -*-
import rospy
import numpy as np
import scipy.io as scio
from std_msgs.msg import Float32MultiArray

packetSize = 512

def talker():
    pub = rospy.Publisher('packet', Float32MultiArray, queue_size=10)
    rospy.init_node('pub_packet', anonymous=True)
    rate = rospy.Rate(10)

    eegdata = np.array(scio.loadmat('eegdata.mat')['eegdata'])
    print("数组形状：", eegdata.shape)
    print("数组第二维：", eegdata.shape[1])

    for exper_i in range(0, eegdata.shape[3]):
        for target_i in range(0, eegdata.shape[2]):
            for packet_i in range(0, 36):
                packet = eegdata[:, packet_i * packetSize : (packet_i + 1) * packetSize, target_i, exper_i]
                str = "exper: %s target: %s packet: %s" % exper_i % target_i % packet_i
                rospy.loginfo(str)
                pub.publish(packet)
                rate.sleep()
		
if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass