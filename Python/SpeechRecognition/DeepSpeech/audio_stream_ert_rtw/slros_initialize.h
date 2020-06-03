#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block audio_stream/Publish
extern SimulinkPublisher<std_msgs::Int16MultiArray, SL_Bus_audio_stream_std_msgs_Int16MultiArray> Pub_audio_stream_6;

// For Block audio_stream/Publish1
extern SimulinkPublisher<geometry_msgs::Point, SL_Bus_audio_stream_geometry_msgs_Point> Pub_audio_stream_10;

void slros_node_init(int argc, char** argv);

#endif
