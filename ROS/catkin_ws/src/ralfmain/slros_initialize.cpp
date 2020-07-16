#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "RALFMain";

// For Block RALFMain/Joystickdaten/Subscribe
SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_RALFMain_sensor_msgs_Joy> Sub_RALFMain_869;

// For Block RALFMain/RALFNavi/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_RALFMain_geometry_msgs_Twist> Sub_RALFMain_963;

// For Block RALFMain/Subscribe
SimulinkSubscriber<geometry_msgs::PoseWithCovarianceStamped, SL_Bus_RALFMain_geometry_msgs_PoseWithCovarianceStamped> Sub_RALFMain_1223;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

