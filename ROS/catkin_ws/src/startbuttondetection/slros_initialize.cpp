#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "StartButtonDetection";

// For Block StartButtonDetection/Subscribe
SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_StartButtonDetection_sensor_msgs_Joy> Sub_StartButtonDetection_1;

// For Block StartButtonDetection/Publish
SimulinkPublisher<std_msgs::Int16, SL_Bus_StartButtonDetection_std_msgs_Int16> Pub_StartButtonDetection_29;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

