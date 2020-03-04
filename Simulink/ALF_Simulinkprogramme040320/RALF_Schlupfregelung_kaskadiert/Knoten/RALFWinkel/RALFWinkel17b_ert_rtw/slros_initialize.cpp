#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "RALFWinkel17b";

// For Block RALFWinkel17b/Publish
SimulinkPublisher<geometry_msgs::Point, SL_Bus_RALFWinkel17b_geometry_msgs_Point> Pub_RALFWinkel17b_101;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

