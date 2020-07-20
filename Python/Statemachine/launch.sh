#! /bin/sh
export LD_LIBRARY_PATH="/home/alf/catkin_ws2/devel/lib:/opt/ros/kinetic/lib:/opt/ros/kinetic/lib/x86_64-linux-gnu";
roslaunch speechrecognition_alfons speechrecognition_alfons.launch.xml & echo $!
cd /home/alf/catkin_ws2/devel/lib/speechrecognition_alfons
python3 main_ros_alf.py

