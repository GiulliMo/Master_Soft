#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "RALFWinkel";

// For Block RALFWinkel/Publish
SimulinkPublisher<geometry_msgs::Point, SL_Bus_RALFWinkel_geometry_msgs_Point> Pub_RALFWinkel_96;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

