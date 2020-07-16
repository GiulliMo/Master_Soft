#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block MedianFilter_cam_front/Subscribe
extern SimulinkSubscriber<sensor_msgs::Image, SL_Bus_MedianFilter_cam_front_sensor_msgs_Image> Sub_MedianFilter_cam_front_46;

// For Block MedianFilter_cam_front/Publish
extern SimulinkPublisher<sensor_msgs::Image, SL_Bus_MedianFilter_cam_front_sensor_msgs_Image> Pub_MedianFilter_cam_front_47;

void slros_node_init(int argc, char** argv);

#endif
