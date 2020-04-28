#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block RALFMain_SLAM/Joystickdaten/Subscribe
extern SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_RALFMain_SLAM_sensor_msgs_Joy> Sub_RALFMain_SLAM_869;

// For Block RALFMain_SLAM/RALFNavi/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_RALFMain_SLAM_geometry_msgs_Twist> Sub_RALFMain_SLAM_963;

// For Block RALFMain_SLAM/RALFWinkel/Subscribe1
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_RALFMain_SLAM_geometry_msgs_PoseStamped> Sub_RALFMain_SLAM_876;

void slros_node_init(int argc, char** argv);

#endif
