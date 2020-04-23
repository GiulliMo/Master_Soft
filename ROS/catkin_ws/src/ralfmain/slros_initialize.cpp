#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "RALFMain";

// For Block RALFMain/Joystickdaten/Subscribe
SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_RALFMain_sensor_msgs_Joy> Sub_RALFMain_869;

// For Block RALFMain/RALFNavi/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_RALFMain_geometry_msgs_Twist> Sub_RALFMain_963;

// For Block RALFMain/RALFWinkel/Subscribe1
SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_RALFMain_geometry_msgs_PoseStamped> Sub_RALFMain_876;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

