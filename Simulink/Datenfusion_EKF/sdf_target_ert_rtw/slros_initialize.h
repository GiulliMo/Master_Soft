#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block sdf_target/Publish
extern SimulinkPublisher<geometry_msgs::Point, SL_Bus_sdf_target_geometry_msgs_Point> Pub_sdf_target_92;

// For Block sdf_target/Publish1
extern SimulinkPublisher<geometry_msgs::Point, SL_Bus_sdf_target_geometry_msgs_Point> Pub_sdf_target_96;

// For Block sdf_target/Publish2
extern SimulinkPublisher<geometry_msgs::Point, SL_Bus_sdf_target_geometry_msgs_Point> Pub_sdf_target_98;

// For Block sdf_target/Publish3
extern SimulinkPublisher<geometry_msgs::Point, SL_Bus_sdf_target_geometry_msgs_Point> Pub_sdf_target_102;

// For Block sdf_target/Publish4
extern SimulinkPublisher<geometry_msgs::Point, SL_Bus_sdf_target_geometry_msgs_Point> Pub_sdf_target_104;

void slros_node_init(int argc, char** argv);

#endif
