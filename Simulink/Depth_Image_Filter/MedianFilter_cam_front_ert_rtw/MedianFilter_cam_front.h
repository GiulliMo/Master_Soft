//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MedianFilter_cam_front.h
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
#ifndef RTW_HEADER_MedianFilter_cam_front_h_
#define RTW_HEADER_MedianFilter_cam_front_h_
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "slros_initialize.h"
#include "MedianFilter_cam_front_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_MedianFilter_cam_front_sensor_msgs_Image BusAssignment1;// '<S3>/Bus Assignment1' 
  SL_Bus_MedianFilter_cam_front_sensor_msgs_Image In1;// '<S4>/In1'
  SL_Bus_MedianFilter_cam_front_sensor_msgs_Image b_varargout_2;
  uint8_T b_varargout_2_Encoding[1036800];
  uint8_T b_varargout_2_Data[1036800];
  uint16_T ByteUnpack[518400];         // '<S3>/Byte Unpack'
  uint16_T PermuteDimensions1[518400]; // '<S3>/Permute Dimensions1'
  uint8_T BytePack1[1036800];          // '<S3>/Byte Pack1'
  uint16_T MedianFilter[518400];       // '<S3>/Median Filter'
  uint16_T PermuteDimensions[518400];  // '<S3>/Permute Dimensions'
  uint8_T b_varargout_2_Header_FrameId[128];
  uint16_T uW[25];
  int32_T mLoc[10];
  int32_T mWidth[10];
  char_T cv[34];
  SL_Bus_MedianFilter_cam_front_ros_time_Time b_varargout_2_Header_Stamp;
  int32_T h1Dims[2];
  int32_T uDims[2];
  int32_T yDims[2];
  int32_T hLoc[2];
  int32_T yOrigin[2];
  int32_T uOrigin[2];
  int32_T uEnd[2];
  int32_T uStride[2];
  int32_T sPreEdges[2];
  int32_T sPostEdges[2];
  int32_T c[2];
  int32_T hIdxB[2];
  int8_T o[5];
  int32_T ntIdx1;
  int32_T uElOffset1;
  int32_T ntIdx0;
  int32_T uElOffset0;
  int32_T yElIdx;
  int32_T yPre;
  int32_T yPost;
  int32_T hPost;
  int32_T preMinus;
  int32_T postMinus;
  int32_T postPlus;
  int32_T bPreEnd;
  int32_T bPostEnd;
  int32_T idxHLin;
  uint32_T b_varargout_2_Height;
  uint32_T b_varargout_2_Width;
  uint32_T b_varargout_2_Encoding_SL_Info_;
  uint32_T b_varargout_2_Encoding_SL_Inf_c;
  uint32_T b_varargout_2_Step;
  uint32_T b_varargout_2_Data_SL_Info_Curr;
  uint32_T b_varargout_2_Data_SL_Info_Rece;
  uint32_T b_varargout_2_Header_Seq;
  uint32_T b_varargout_2_Header_FrameId_SL;
  uint32_T b_varargout_2_Header_FrameId__p;
} B_MedianFilter_cam_front_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Publ_T obj; // '<S1>/SinkBlock'
  ros_slros_internal_block_Subs_T obj_f;// '<S2>/SourceBlock'
  int32_T MedianFilter_bSEnd[2];       // '<S3>/Median Filter'
  int32_T MedianFilter_bSPreEdg[2];    // '<S3>/Median Filter'
  int32_T MedianFilter_bSPstEdg[2];    // '<S3>/Median Filter'
  int32_T MedianFilter_bSStart[2];     // '<S3>/Median Filter'
  int32_T MedianFilter_inSEnd[2];      // '<S3>/Median Filter'
  int32_T MedianFilter_inSStart[2];    // '<S3>/Median Filter'
  int32_T MedianFilter_mLoc[10];       // '<S3>/Median Filter'
  int32_T MedianFilter_mWidth[10];     // '<S3>/Median Filter'
  int32_T MedianFilter_oSPreEdg[2];    // '<S3>/Median Filter'
  int32_T MedianFilter_oSPstEdg[2];    // '<S3>/Median Filter'
  int32_T MedianFilter_oSStart[2];     // '<S3>/Median Filter'
  int32_T MedianFilter_oSecEnd[2];     // '<S3>/Median Filter'
  int32_T MedianFilter_sCnt[2];        // '<S3>/Median Filter'
  boolean_T MedianFilter_isHgtUpd[2];  // '<S3>/Median Filter'
} DW_MedianFilter_cam_front_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState Subsystem_Trig_ZCE;       // '<Root>/Subsystem'
} PrevZCX_MedianFilter_cam_fron_T;

// Parameters (default storage)
struct P_MedianFilter_cam_front_T_ {
  SL_Bus_MedianFilter_cam_front_sensor_msgs_Image Out1_Y0;// Computed Parameter: Out1_Y0
                                                             //  Referenced by: '<S4>/Out1'

  SL_Bus_MedianFilter_cam_front_sensor_msgs_Image Constant_Value;// Computed Parameter: Constant_Value
                                                                    //  Referenced by: '<S2>/Constant'

  SL_Bus_MedianFilter_cam_front_sensor_msgs_Image Out1_Y0_n;// Computed Parameter: Out1_Y0_n
                                                               //  Referenced by: '<S3>/Out1'

  SL_Bus_MedianFilter_cam_front_sensor_msgs_Image Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                                      //  Referenced by: '<S5>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_MedianFilter_cam_fron_T {
  const char_T *errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_MedianFilter_cam_front_T MedianFilter_cam_front_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_MedianFilter_cam_front_T MedianFilter_cam_front_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_MedianFilter_cam_front_T MedianFilter_cam_front_DW;

// Zero-crossing (trigger) state
extern PrevZCX_MedianFilter_cam_fron_T MedianFilter_cam_front_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void MedianFilter_cam_front_initialize(void);
  extern void MedianFilter_cam_front_step(void);
  extern void MedianFilter_cam_front_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_MedianFilter_cam_fro_T *const MedianFilter_cam_front_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/Reshape' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'MedianFilter_cam_front'
//  '<S1>'   : 'MedianFilter_cam_front/Publish'
//  '<S2>'   : 'MedianFilter_cam_front/Subscribe'
//  '<S3>'   : 'MedianFilter_cam_front/Subsystem'
//  '<S4>'   : 'MedianFilter_cam_front/Subscribe/Enabled Subsystem'
//  '<S5>'   : 'MedianFilter_cam_front/Subsystem/Blank Message'

#endif                                 // RTW_HEADER_MedianFilter_cam_front_h_

//
// File trailer for generated code.
//
// [EOF]
//
