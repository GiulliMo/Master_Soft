#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "RALFMain_SLAM";

// For Block RALFMain_SLAM/Joystickdaten/Subscribe
SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_RALFMain_SLAM_sensor_msgs_Joy> Sub_RALFMain_SLAM_869;

// For Block RALFMain_SLAM/RALFNavi/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_RALFMain_SLAM_geometry_msgs_Twist> Sub_RALFMain_SLAM_963;

// For Block RALFMain_SLAM/RALFWinkel/Subscribe
SimulinkSubscriber<geometry_msgs::PoseWithCovarianceStamped, SL_Bus_RALFMain_SLAM_PoseWithCovarianceStamped_l4ivcs> Sub_RALFMain_SLAM_1247;

// For Block RALFMain_SLAM/RALFWinkel/Subscribe1
SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_RALFMain_SLAM_geometry_msgs_PoseStamped> Sub_RALFMain_SLAM_876;

// For Block RALFMain_SLAM/Modusumschaltung/Get Parameter
SimulinkParameterArrayGetter<char_T, std::string> ParamGet_RALFMain_SLAM_1266;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

