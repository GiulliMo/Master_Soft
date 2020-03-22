#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/MultiArrayLayout.h>
#include "MecanumPose_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(std_msgs::Int16MultiArray* msgPtr, SL_Bus_MecanumPose_std_msgs_Int16MultiArray const* busPtr);
void convertToBus(SL_Bus_MecanumPose_std_msgs_Int16MultiArray* busPtr, std_msgs::Int16MultiArray const* msgPtr);

void convertFromBus(std_msgs::MultiArrayDimension* msgPtr, SL_Bus_MecanumPose_std_msgs_MultiArrayDimension const* busPtr);
void convertToBus(SL_Bus_MecanumPose_std_msgs_MultiArrayDimension* busPtr, std_msgs::MultiArrayDimension const* msgPtr);

void convertFromBus(std_msgs::MultiArrayLayout* msgPtr, SL_Bus_MecanumPose_std_msgs_MultiArrayLayout const* busPtr);
void convertToBus(SL_Bus_MecanumPose_std_msgs_MultiArrayLayout* busPtr, std_msgs::MultiArrayLayout const* msgPtr);


#endif
