//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MecanumPose.h
//
// Code generated for Simulink model 'MecanumPose'.
//
// Model version                  : 1.5
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sun Mar 22 11:28:49 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_MecanumPose_h_
#define RTW_HEADER_MecanumPose_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef MecanumPose_COMMON_INCLUDES_
# define MecanumPose_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "slros_initialize.h"
#endif                                 // MecanumPose_COMMON_INCLUDES_

#include "MecanumPose_types.h"

// Shared type includes
#include "multiword_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

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

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_MecanumPose_std_msgs_Int16MultiArray In1;// '<S2>/In1'
  SL_Bus_MecanumPose_std_msgs_Int16MultiArray b_varargout_2;
  SL_Bus_MecanumPose_std_msgs_MultiArrayDimension b_varargout_2_Layout_Dim[16];
  real_T Product[4];                   // '<Root>/Product'
  real_T Gain[4];                      // '<Root>/Gain'
  int16_T Data[128];
  int16_T b_varargout_2_Data[128];
} B_MecanumPose_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Subs_T obj; // '<S1>/SourceBlock'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S1>/Enabled Subsystem'
} DW_MecanumPose_T;

// Parameters (default storage)
struct P_MecanumPose_T_ {
  real_T J[12];                        // Variable: J
                                          //  Referenced by: '<Root>/Constant'

  SL_Bus_MecanumPose_std_msgs_Int16MultiArray Out1_Y0;// Computed Parameter: Out1_Y0
                                                         //  Referenced by: '<S2>/Out1'

  SL_Bus_MecanumPose_std_msgs_Int16MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                                //  Referenced by: '<S1>/Constant'

  real_T XVel_Value;                   // Expression: 2
                                          //  Referenced by: '<Root>/X-Vel'

  real_T YVel_Value;                   // Expression: 0
                                          //  Referenced by: '<Root>/Y-Vel'

  real_T Omega_DotVel_Value;           // Expression: 0.01865808823529413
                                          //  Referenced by: '<Root>/Omega_Dot-Vel'

  real_T Gain_Gain;                    // Expression: 1/25
                                          //  Referenced by: '<Root>/Gain'

  real_T SimulationPace_P1;            // Expression: SimulationPace
                                          //  Referenced by: '<Root>/Simulation Pace'

  real_T SimulationPace_P2;            // Expression: 2
                                          //  Referenced by: '<Root>/Simulation Pace'

  real_T SimulationPace_P3;            // Expression: OutputPaceError
                                          //  Referenced by: '<Root>/Simulation Pace'

  real_T SimulationPace_P4;            // Expression: SampleTime
                                          //  Referenced by: '<Root>/Simulation Pace'

};

// Real-time Model Data Structure
struct tag_RTM_MecanumPose_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_MecanumPose_T MecanumPose_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_MecanumPose_T MecanumPose_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_MecanumPose_T MecanumPose_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void MecanumPose_initialize(void);
  extern void MecanumPose_step(void);
  extern void MecanumPose_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_MecanumPose_T *const MecanumPose_M;

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
//  '<Root>' : 'MecanumPose'
//  '<S1>'   : 'MecanumPose/Subscribe'
//  '<S2>'   : 'MecanumPose/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_MecanumPose_h_

//
// File trailer for generated code.
//
// [EOF]
//
