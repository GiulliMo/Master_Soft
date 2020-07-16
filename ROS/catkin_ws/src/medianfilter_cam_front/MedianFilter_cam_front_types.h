//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MedianFilter_cam_front_types.h
//
// Code generated for Simulink model 'MedianFilter_cam_front'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Wed Apr 29 10:17:35 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_MedianFilter_cam_front_types_h_
#define RTW_HEADER_MedianFilter_cam_front_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_MedianFilter_cam_front_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_MedianFilter_cam_front_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_MedianFilter_cam_front_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_MedianFilter_cam_front_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_MedianFilter_cam_front_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_MedianFilter_cam_front_ros_time_Time Stamp;
} SL_Bus_MedianFilter_cam_front_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_MedianFilter_cam_front_sensor_msgs_Image_
#define DEFINED_TYPEDEF_FOR_SL_Bus_MedianFilter_cam_front_sensor_msgs_Image_

// MsgType=sensor_msgs/Image
typedef struct {
  uint32_T Height;
  uint32_T Width;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=Encoding_SL_Info:TruncateAction=warn 
  uint8_T Encoding[1036800];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Encoding
  SL_Bus_ROSVariableLengthArrayInfo Encoding_SL_Info;
  uint8_T IsBigendian;
  uint32_T Step;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  uint8_T Data[1036800];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;

  // MsgType=std_msgs/Header
  SL_Bus_MedianFilter_cam_front_std_msgs_Header Header;
} SL_Bus_MedianFilter_cam_front_sensor_msgs_Image;

#endif

#ifndef struct_tag_rkSooZHJZnr3Dpfu1LNqfH
#define struct_tag_rkSooZHJZnr3Dpfu1LNqfH

struct tag_rkSooZHJZnr3Dpfu1LNqfH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_rkSooZHJZnr3Dpfu1LNqfH

#ifndef typedef_ros_slros_internal_block_Publ_T
#define typedef_ros_slros_internal_block_Publ_T

typedef struct tag_rkSooZHJZnr3Dpfu1LNqfH ros_slros_internal_block_Publ_T;

#endif                                 //typedef_ros_slros_internal_block_Publ_T

#ifndef struct_tag_9SewJ4y3IXNs5GrZti8qkG
#define struct_tag_9SewJ4y3IXNs5GrZti8qkG

struct tag_9SewJ4y3IXNs5GrZti8qkG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_9SewJ4y3IXNs5GrZti8qkG

#ifndef typedef_ros_slros_internal_block_Subs_T
#define typedef_ros_slros_internal_block_Subs_T

typedef struct tag_9SewJ4y3IXNs5GrZti8qkG ros_slros_internal_block_Subs_T;

#endif                                 //typedef_ros_slros_internal_block_Subs_T

// Parameters (default storage)
typedef struct P_MedianFilter_cam_front_T_ P_MedianFilter_cam_front_T;

// Forward declaration for rtModel
typedef struct tag_RTM_MedianFilter_cam_fron_T RT_MODEL_MedianFilter_cam_fro_T;

#endif                            // RTW_HEADER_MedianFilter_cam_front_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
