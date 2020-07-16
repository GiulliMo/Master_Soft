//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: StartButtonDetection.h
//
// Code generated for Simulink model 'StartButtonDetection'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Tue Jul  7 13:27:15 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_StartButtonDetection_h_
#define RTW_HEADER_StartButtonDetection_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "StartButtonDetection_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_StartButtonDetection_sensor_msgs_Joy In1;// '<S5>/In1'
  SL_Bus_StartButtonDetection_sensor_msgs_Joy b_varargout_2;
} B_StartButtonDetection_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Publ_T obj; // '<S3>/SinkBlock'
  ros_slros_internal_block_Subs_T obj_n;// '<S4>/SourceBlock'
} DW_StartButtonDetection_T;

// Parameters (default storage)
struct P_StartButtonDetection_T_ {
  SL_Bus_StartButtonDetection_sensor_msgs_Joy Out1_Y0;// Computed Parameter: Out1_Y0
                                                         //  Referenced by: '<S5>/Out1'

  SL_Bus_StartButtonDetection_sensor_msgs_Joy Constant_Value;// Computed Parameter: Constant_Value
                                                                //  Referenced by: '<S4>/Constant'

  SL_Bus_StartButtonDetection_std_msgs_Int16 Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                                 //  Referenced by: '<S1>/Constant'

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
struct tag_RTM_StartButtonDetection_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_StartButtonDetection_T StartButtonDetection_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_StartButtonDetection_T StartButtonDetection_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_StartButtonDetection_T StartButtonDetection_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void StartButtonDetection_initialize(void);
  extern void StartButtonDetection_step(void);
  extern void StartButtonDetection_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_StartButtonDetection_T *const StartButtonDetection_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Display1' : Unused code path elimination


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
//  '<Root>' : 'StartButtonDetection'
//  '<S1>'   : 'StartButtonDetection/Blank Message'
//  '<S2>'   : 'StartButtonDetection/MATLAB Function'
//  '<S3>'   : 'StartButtonDetection/Publish'
//  '<S4>'   : 'StartButtonDetection/Subscribe'
//  '<S5>'   : 'StartButtonDetection/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_StartButtonDetection_h_

//
// File trailer for generated code.
//
// [EOF]
//
