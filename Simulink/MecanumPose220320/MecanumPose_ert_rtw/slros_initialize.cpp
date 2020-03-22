#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "MecanumPose";

// For Block MecanumPose/Subscribe
SimulinkSubscriber<std_msgs::Int16MultiArray, SL_Bus_MecanumPose_std_msgs_Int16MultiArray> Sub_MecanumPose_55;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

