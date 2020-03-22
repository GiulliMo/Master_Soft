#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block MecanumPose/Subscribe
extern SimulinkSubscriber<std_msgs::Int16MultiArray, SL_Bus_MecanumPose_std_msgs_Int16MultiArray> Sub_MecanumPose_55;

void slros_node_init(int argc, char** argv);

#endif
