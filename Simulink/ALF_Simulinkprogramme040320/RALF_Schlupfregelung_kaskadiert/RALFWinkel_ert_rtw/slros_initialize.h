#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block RALFWinkel/Publish
extern SimulinkPublisher<geometry_msgs::Point, SL_Bus_RALFWinkel_geometry_msgs_Point> Pub_RALFWinkel_96;

// For Block RALFWinkel/Publish1
extern SimulinkPublisher<geometry_msgs::Point, SL_Bus_RALFWinkel_geometry_msgs_Point> Pub_RALFWinkel_100;

// For Block RALFWinkel/Publish2
extern SimulinkPublisher<geometry_msgs::Point, SL_Bus_RALFWinkel_geometry_msgs_Point> Pub_RALFWinkel_103;

void slros_node_init(int argc, char** argv);

#endif
