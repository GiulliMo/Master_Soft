#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block RALFWinkel17b/Publish
extern SimulinkPublisher<geometry_msgs::Point, SL_Bus_RALFWinkel17b_geometry_msgs_Point> Pub_RALFWinkel17b_101;

void slros_node_init(int argc, char** argv);

#endif
