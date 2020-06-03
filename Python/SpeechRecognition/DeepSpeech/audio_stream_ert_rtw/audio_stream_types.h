//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: audio_stream_types.h
//
// Code generated for Simulink model 'audio_stream'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Wed Jun  3 10:55:28 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_audio_stream_types_h_
#define RTW_HEADER_audio_stream_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_audio_stream_std_msgs_MultiArrayDimension_
#define DEFINED_TYPEDEF_FOR_SL_Bus_audio_stream_std_msgs_MultiArrayDimension_

// MsgType=std_msgs/MultiArrayDimension
typedef struct {
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=Label_SL_Info:TruncateAction=warn 
  uint8_T Label[2048];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Label
  SL_Bus_ROSVariableLengthArrayInfo Label_SL_Info;
  uint32_T Size;
  uint32_T Stride;
} SL_Bus_audio_stream_std_msgs_MultiArrayDimension;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_audio_stream_std_msgs_MultiArrayLayout_
#define DEFINED_TYPEDEF_FOR_SL_Bus_audio_stream_std_msgs_MultiArrayLayout_

// MsgType=std_msgs/MultiArrayLayout
typedef struct {
  uint32_T DataOffset;

  // MsgType=std_msgs/MultiArrayDimension:IsVarLen=1:VarLenCategory=data:VarLenElem=Dim_SL_Info:TruncateAction=warn 
  SL_Bus_audio_stream_std_msgs_MultiArrayDimension Dim;

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Dim
  SL_Bus_ROSVariableLengthArrayInfo Dim_SL_Info;
} SL_Bus_audio_stream_std_msgs_MultiArrayLayout;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_audio_stream_std_msgs_Int16MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_audio_stream_std_msgs_Int16MultiArray_

// MsgType=std_msgs/Int16MultiArray
typedef struct {
  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  int16_T Data[2048];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;

  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_audio_stream_std_msgs_MultiArrayLayout Layout;
} SL_Bus_audio_stream_std_msgs_Int16MultiArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_audio_stream_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_audio_stream_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_audio_stream_geometry_msgs_Point;

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

// Parameters (default storage)
typedef struct P_audio_stream_T_ P_audio_stream_T;

// Forward declaration for rtModel
typedef struct tag_RTM_audio_stream_T RT_MODEL_audio_stream_T;

#endif                                 // RTW_HEADER_audio_stream_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
