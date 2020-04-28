//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: RALFMain_SLAM_types.h
//
// Code generated for Simulink model 'RALFMain_SLAM'.
//
// Model version                  : 1.189
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Tue Apr 28 13:32:56 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_RALFMain_SLAM_types_h_
#define RTW_HEADER_RALFMain_SLAM_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_RALFMain_SLAM_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_RALFMain_SLAM_ros_time_Time Stamp;
} SL_Bus_RALFMain_SLAM_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_sensor_msgs_Joy_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_sensor_msgs_Joy_

// MsgType=sensor_msgs/Joy
typedef struct {
  // IsVarLen=1:VarLenCategory=data:VarLenElem=Axes_SL_Info:TruncateAction=warn
  real32_T Axes[8];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Axes
  SL_Bus_ROSVariableLengthArrayInfo Axes_SL_Info;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Buttons_SL_Info:TruncateAction=warn 
  int32_T Buttons[15];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Buttons
  SL_Bus_ROSVariableLengthArrayInfo Buttons_SL_Info;

  // MsgType=std_msgs/Header
  SL_Bus_RALFMain_SLAM_std_msgs_Header Header;
} SL_Bus_RALFMain_SLAM_sensor_msgs_Joy;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_RALFMain_SLAM_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_RALFMain_SLAM_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_RALFMain_SLAM_geometry_msgs_Vector3 Angular;
} SL_Bus_RALFMain_SLAM_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_RALFMain_SLAM_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_RALFMain_SLAM_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
typedef struct {
  // MsgType=geometry_msgs/Point
  SL_Bus_RALFMain_SLAM_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_RALFMain_SLAM_geometry_msgs_Quaternion Orientation;
} SL_Bus_RALFMain_SLAM_geometry_msgs_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_PoseStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RALFMain_SLAM_geometry_msgs_PoseStamped_

// MsgType=geometry_msgs/PoseStamped
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_RALFMain_SLAM_std_msgs_Header Header;

  // MsgType=geometry_msgs/Pose
  SL_Bus_RALFMain_SLAM_geometry_msgs_Pose Pose;
} SL_Bus_RALFMain_SLAM_geometry_msgs_PoseStamped;

#endif

#ifndef struct_tag_vxHWSOYrO9xtYchIOe7EKG
#define struct_tag_vxHWSOYrO9xtYchIOe7EKG

struct tag_vxHWSOYrO9xtYchIOe7EKG
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_vxHWSOYrO9xtYchIOe7EKG

#ifndef typedef_robotics_slcore_internal_bloc_T
#define typedef_robotics_slcore_internal_bloc_T

typedef struct tag_vxHWSOYrO9xtYchIOe7EKG robotics_slcore_internal_bloc_T;

#endif                                 //typedef_robotics_slcore_internal_bloc_T

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
typedef struct P_RALFMain_SLAM_T_ P_RALFMain_SLAM_T;

// Forward declaration for rtModel
typedef struct tag_RTM_RALFMain_SLAM_T RT_MODEL_RALFMain_SLAM_T;

#endif                                 // RTW_HEADER_RALFMain_SLAM_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
