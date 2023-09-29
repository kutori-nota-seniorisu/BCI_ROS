# BCI_ROS

本手册旨在详细解释本工作空间，并介绍各功能包的功能与使用。此工作空间内包含三个功能包: online_analysis, ptb_show, wave_show。其中 online_analysis 功能包用于分析脑电信号数据，并发布机械臂控制指令； ptb_show 功能包用于显示刺激界面； wave_show 功能包用于显示脑电信号的可视化。

## 2023.06.12

不再使用qt采集脑电信号，将C++ demo代码写成纯ROS C++类

本机ubuntu版本 20.04

pip更新: `python3 -m pip install --upgrade pip`

## 工控机配置指南

ubuntu版本 18.04

ros版本 melodic

Qt版本 5.9.9

## 节点运行方式

### 离线数据手动发布并分析

效果：通过键盘输入0~9来控制离线数据的发布，并将数据发送给分析节点。

1. 运行数据分析的节点：`rosrun online_analysis onlineanalysis.py`
2. 运行离线数据发布的节点：`rosrun online_analysis eeg_pub_manual.py`
3. 运行获取键盘输入的节点：`rosrun online_analysis key_read.py`

### 在线数据获取并分析

效果：采集在线数据（Curry8或仿真器），并将数据发送给分析节点。

1. 运行 Curry8 仿真器/ Curry8
2. 运行连接 Curry8 的数据采集节点：`rosrun online_analysis datareceive`
3. 运行数据分析的节点：`rosrun online_analysis onlineanalysis.py`

### 脑电信号可视化

效果：采集数据后，将数据发送给可视化界面，在界面上绘制波形图，并具有信号滤波功能。

1. 运行可视化界面节点：`rosrun wave_show wave_show.py`
2. 运行 Curry8 仿真器/ Curry8
3. 运行连接 Curry8 的数据采集节点：`rosrun online_analysis datareceive`

## 相机相关

1. 首先运行相机配置launch文件：`roslaunch realsense2_camera rs_aligned_depth.launch`
2. 接着运行数据发送与分析节点：`roslaunch online_analysis ana_simu.launch`
3. 最后运行相机节点：`rosrun bci_grip col_align_depth.cpp`

## online_analysis

此功能包内包含 python 文件与 cpp 文件。

### src/rnetstreaming.cpp

src/rnetstreaming.cpp 定义了一个数据接收的类: RNetStreamingReceiver, include/online_analysis/rnetstreaming.h 是其声明。在该类中，定义了两个发布者，在通过 tcp/ip 通信接收到 Curry8 发送的数据后，对外发出。

### src/datareceive.cpp

该文件定义了一个节点，用于创建 RNetStreamingReceiver 类的实例化对象。该文件是需要执行的文件。

### scripts/key_read.py

该文件定义了一个发布节点。运行该节点后，程序将会读取键盘的输入，并将输入作为消息发布给接收节点。

### scripts/eeg_pub_man.py

该文件定义了一个发布离线数据的节点。在读取本地数据后，默认发布的数据包为高斯分布的噪声信号，当该节点收到 key_read.py 发布的键盘输入消息后，根据该消息选择发布何种数据。输入消息为1-9时，对应发布的数据为9Hz-17Hz的实验数据；输入消息为0时，发布高斯噪声信号。

### scripts/onlineanalysis.py

该文件定义了一个数据接收节点，并在获取数据后对其进行在线分析，最后将分析的结果发布出去。

### scripts/eeg_pub_auto.py

该文件定义了一个发布离线数据的节点，在读取本地的 .mat 文件数据后，将512组数据，每组35导，作为一个数据包，发送给数据分析节点(onlineanalysis.py)

### scripts/key_control.py

该文件定义了一个接受节点。该节点是与 key_read.py 所定义的节点匹配的测试节点，能够接受 key_read.py 发布的键盘输入消息，并以输出到命令框。
