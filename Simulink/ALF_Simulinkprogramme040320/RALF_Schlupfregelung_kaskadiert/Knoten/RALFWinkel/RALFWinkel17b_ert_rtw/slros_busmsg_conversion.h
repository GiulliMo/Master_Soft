#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include "RALFWinkel17b_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_RALFWinkel17b_geometry_msgs_Point const* busPtr);
void convertToBus(SL_Bus_RALFWinkel17b_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr);


#endif
