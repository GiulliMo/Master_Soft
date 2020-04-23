#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block RALFMain/Joystickdaten/Subscribe
extern SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_RALFMain_sensor_msgs_Joy> Sub_RALFMain_869;

// For Block RALFMain/RALFNavi/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_RALFMain_geometry_msgs_Twist> Sub_RALFMain_963;

// For Block RALFMain/RALFWinkel/Subscribe1
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_RALFMain_geometry_msgs_PoseStamped> Sub_RALFMain_876;

void slros_node_init(int argc, char** argv);

#endif
