#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import rospy
from std_msgs.msg import Float32MultiArray
import numpy as np
import scipy.io as scio

data = scio.loadmat('/home/wuyou/BCI_ROS/src/online_analysis/scripts/save_eeg.mat')
data1 = np.array(data['SaveEegData'])
print(data1.shape)