//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: StartButtonDetection_types.h
//
// Code generated for Simulink model 'StartButtonDetection'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Thu Jul  2 13:57:30 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_StartButtonDetection_types_h_
#define RTW_HEADER_StartButtonDetection_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_StartButtonDetection_std_msgs_Int16_
#define DEFINED_TYPEDEF_FOR_SL_Bus_StartButtonDetection_std_msgs_Int16_

// MsgType=std_msgs/Int16
typedef struct {
  int16_T Data;
} SL_Bus_StartButtonDetection_std_msgs_Int16;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_StartButtonDetection_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_StartButtonDetection_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_StartButtonDetection_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_StartButtonDetection_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_StartButtonDetection_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_StartButtonDetection_ros_time_Time Stamp;
} SL_Bus_StartButtonDetection_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_StartButtonDetection_sensor_msgs_Joy_
#define DEFINED_TYPEDEF_FOR_SL_Bus_StartButtonDetection_sensor_msgs_Joy_

// MsgType=sensor_msgs/Joy
typedef struct {
  // IsVarLen=1:VarLenCategory=data:VarLenElem=Axes_SL_Info:TruncateAction=warn
  real32_T Axes[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Axes
  SL_Bus_ROSVariableLengthArrayInfo Axes_SL_Info;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Buttons_SL_Info:TruncateAction=warn 
  int32_T Buttons[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Buttons
  SL_Bus_ROSVariableLengthArrayInfo Buttons_SL_Info;

  // MsgType=std_msgs/Header
  SL_Bus_StartButtonDetection_std_msgs_Header Header;
} SL_Bus_StartButtonDetection_sensor_msgs_Joy;

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
typedef struct P_StartButtonDetection_T_ P_StartButtonDetection_T;

// Forward declaration for rtModel
typedef struct tag_RTM_StartButtonDetection_T RT_MODEL_StartButtonDetection_T;

#endif                              // RTW_HEADER_StartButtonDetection_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
