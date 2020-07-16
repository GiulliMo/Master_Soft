#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "MedianFilter_cam_front";

// For Block MedianFilter_cam_front/Subscribe
SimulinkSubscriber<sensor_msgs::Image, SL_Bus_MedianFilter_cam_front_sensor_msgs_Image> Sub_MedianFilter_cam_front_46;

// For Block MedianFilter_cam_front/Publish
SimulinkPublisher<sensor_msgs::Image, SL_Bus_MedianFilter_cam_front_sensor_msgs_Image> Pub_MedianFilter_cam_front_47;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

