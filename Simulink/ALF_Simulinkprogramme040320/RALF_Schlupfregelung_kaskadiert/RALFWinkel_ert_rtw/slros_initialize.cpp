#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "RALFWinkel";

// For Block RALFWinkel/Publish
SimulinkPublisher<geometry_msgs::Point, SL_Bus_RALFWinkel_geometry_msgs_Point> Pub_RALFWinkel_96;

// For Block RALFWinkel/Publish1
SimulinkPublisher<geometry_msgs::Point, SL_Bus_RALFWinkel_geometry_msgs_Point> Pub_RALFWinkel_100;

// For Block RALFWinkel/Publish2
SimulinkPublisher<geometry_msgs::Point, SL_Bus_RALFWinkel_geometry_msgs_Point> Pub_RALFWinkel_103;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

