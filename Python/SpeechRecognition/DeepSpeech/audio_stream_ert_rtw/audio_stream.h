//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: audio_stream.h
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
#ifndef RTW_HEADER_audio_stream_h_
#define RTW_HEADER_audio_stream_h_
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "HostLib_Audio.h"
#include "audio_stream_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_audio_stream_std_msgs_Int16MultiArray BusAssignment;// '<Root>/Bus Assignment' 
  int16_T AudioDeviceReader[2048];     // '<Root>/Audio Device Reader'
} B_audio_stream_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Publ_T obj; // '<S4>/SinkBlock'
  ros_slros_internal_block_Publ_T obj_e;// '<S3>/SinkBlock'
  uint8_T AudioDeviceReader_AudioDeviceLi[1096];// '<Root>/Audio Device Reader'
} DW_audio_stream_T;

// Parameters (default storage)
struct P_audio_stream_T_ {
  SL_Bus_audio_stream_std_msgs_Int16MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                                 //  Referenced by: '<S1>/Constant'

  SL_Bus_audio_stream_geometry_msgs_Point Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                              //  Referenced by: '<S2>/Constant'

  real_T AudioDeviceReader_P1;         // Expression: SampleRate
                                          //  Referenced by: '<Root>/Audio Device Reader'

  real_T Constant_Value_c;             // Expression: 1
                                          //  Referenced by: '<Root>/Constant'

  uint32_T Constant1_Value;            // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<Root>/Constant1'

};

// Real-time Model Data Structure
struct tag_RTM_audio_stream_T {
  const char_T *errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_audio_stream_T audio_stream_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_audio_stream_T audio_stream_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_audio_stream_T audio_stream_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void audio_stream_initialize(void);
  extern void audio_stream_step(void);
  extern void audio_stream_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_audio_stream_T *const audio_stream_M;

#ifdef __cplusplus

}
#endif

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
//  '<Root>' : 'audio_stream'
//  '<S1>'   : 'audio_stream/Blank Message'
//  '<S2>'   : 'audio_stream/Blank Message1'
//  '<S3>'   : 'audio_stream/Publish'
//  '<S4>'   : 'audio_stream/Publish1'

#endif                                 // RTW_HEADER_audio_stream_h_

//
// File trailer for generated code.
//
// [EOF]
//
