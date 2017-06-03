#!/bin/bash
source ~/AggreGator3.1/devel/setup.bash
export ROS_IP=192.168.0.103
export ROS_MASTER_URI="http://192.168.0.103:11311"
export | grep ROS
roslaunch ~/AggreGator3.1/src/GoGators.launch
