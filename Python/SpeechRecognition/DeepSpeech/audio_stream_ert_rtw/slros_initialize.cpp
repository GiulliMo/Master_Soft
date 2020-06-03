#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "audio_stream";

// For Block audio_stream/Publish
SimulinkPublisher<std_msgs::Int16MultiArray, SL_Bus_audio_stream_std_msgs_Int16MultiArray> Pub_audio_stream_6;

// For Block audio_stream/Publish1
SimulinkPublisher<geometry_msgs::Point, SL_Bus_audio_stream_geometry_msgs_Point> Pub_audio_stream_10;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

