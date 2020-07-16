#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block StartButtonDetection/Subscribe
extern SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_StartButtonDetection_sensor_msgs_Joy> Sub_StartButtonDetection_1;

// For Block StartButtonDetection/Publish
extern SimulinkPublisher<std_msgs::Int16, SL_Bus_StartButtonDetection_std_msgs_Int16> Pub_StartButtonDetection_29;

void slros_node_init(int argc, char** argv);

#endif
