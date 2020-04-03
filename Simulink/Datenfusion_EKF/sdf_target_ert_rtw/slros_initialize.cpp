#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "sdf_target";

// For Block sdf_target/Publish
SimulinkPublisher<geometry_msgs::Point, SL_Bus_sdf_target_geometry_msgs_Point> Pub_sdf_target_92;

// For Block sdf_target/Publish1
SimulinkPublisher<geometry_msgs::Point, SL_Bus_sdf_target_geometry_msgs_Point> Pub_sdf_target_96;

// For Block sdf_target/Publish2
SimulinkPublisher<geometry_msgs::Point, SL_Bus_sdf_target_geometry_msgs_Point> Pub_sdf_target_98;

// For Block sdf_target/Publish3
SimulinkPublisher<geometry_msgs::Point, SL_Bus_sdf_target_geometry_msgs_Point> Pub_sdf_target_102;

// For Block sdf_target/Publish4
SimulinkPublisher<geometry_msgs::Point, SL_Bus_sdf_target_geometry_msgs_Point> Pub_sdf_target_104;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

