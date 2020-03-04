//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: RALFWinkel.h
//
// Code generated for Simulink model 'RALFWinkel'.
//
// Model version                  : 1.5
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Thu Nov 15 17:12:57 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_RALFWinkel_h_
#define RTW_HEADER_RALFWinkel_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef RALFWinkel_COMMON_INCLUDES_
# define RALFWinkel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_I2C.h"
#include "slros_initialize.h"
#endif                                 // RALFWinkel_COMMON_INCLUDES_

#include "RALFWinkel_types.h"

// Shared type includes
#include "multiword_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_RALFWinkel_geometry_msgs_Point Constant;// '<S1>/Constant'
  real_T phi;                          // '<Root>/Integrator1'
  real_T omega;                        // '<Root>/Sum1'
  real_T sum1;                         // '<Root>/Product1'
  real_T sum2;                         // '<Root>/Product2'
  real_T phi_ohneF;                    // '<Root>/Integrator'
  real_T omega_filter;                 // '<Root>/Transfer Fcn'
  real_T sumergebnis;                  // '<Root>/Sum'
  real_T LSM9DS1IMUSensor_o1[3];       // '<Root>/LSM9DS1 IMU Sensor'
} B_RALFWinkel_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  raspi_internal_lsm9ds1Block_R_T obj; // '<Root>/LSM9DS1 IMU Sensor'
  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<Root>/Scope'

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<Root>/Scope1'

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      // '<Root>/Scope2'

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      // '<Root>/Scope3'

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      // '<Root>/Scope4'

  robotics_slros_internal_block_T obj_j;// '<S4>/SinkBlock'
} DW_RALFWinkel_T;

// Continuous states (auto storage)
typedef struct {
  real_T Integrator1_CSTATE;           // '<Root>/Integrator1'
  real_T Integrator_CSTATE;            // '<Root>/Integrator'
  real_T TransferFcn_CSTATE;           // '<Root>/Transfer Fcn'
} X_RALFWinkel_T;

// State derivatives (auto storage)
typedef struct {
  real_T Integrator1_CSTATE;           // '<Root>/Integrator1'
  real_T Integrator_CSTATE;            // '<Root>/Integrator'
  real_T TransferFcn_CSTATE;           // '<Root>/Transfer Fcn'
} XDot_RALFWinkel_T;

// State disabled
typedef struct {
  boolean_T Integrator1_CSTATE;        // '<Root>/Integrator1'
  boolean_T Integrator_CSTATE;         // '<Root>/Integrator'
  boolean_T TransferFcn_CSTATE;        // '<Root>/Transfer Fcn'
} XDis_RALFWinkel_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (auto storage)
struct P_RALFWinkel_T_ {
  real_T CompareToConstant1_const;     // Mask Parameter: CompareToConstant1_const
                                       //  Referenced by: '<S2>/Constant'

  real_T CompareToConstant2_const;     // Mask Parameter: CompareToConstant2_const
                                       //  Referenced by: '<S3>/Constant'

  SL_Bus_RALFWinkel_geometry_msgs_Point Constant_Value;// Computed Parameter: Constant_Value
                                                       //  Referenced by: '<S1>/Constant'

  real_T Integrator1_IC;               // Expression: 0
                                       //  Referenced by: '<Root>/Integrator1'

  real_T Constant_Value_h;             // Expression: 0.65
                                       //  Referenced by: '<Root>/Constant'

  real_T Integrator_IC;                // Expression: 0
                                       //  Referenced by: '<Root>/Integrator'

  real_T TransferFcn_A;                // Computed Parameter: TransferFcn_A
                                       //  Referenced by: '<Root>/Transfer Fcn'

  real_T TransferFcn_C;                // Computed Parameter: TransferFcn_C
                                       //  Referenced by: '<Root>/Transfer Fcn'

};

// Real-time Model Data Structure
struct tag_RTM_RALFWinkel_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_RALFWinkel_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[3][3];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_RALFWinkel_T RALFWinkel_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_RALFWinkel_T RALFWinkel_B;

// Continuous states (auto storage)
extern X_RALFWinkel_T RALFWinkel_X;

// Block states (auto storage)
extern DW_RALFWinkel_T RALFWinkel_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void RALFWinkel_initialize(void);
  extern void RALFWinkel_step(void);
  extern void RALFWinkel_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_RALFWinkel_T *const RALFWinkel_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion


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
//  '<Root>' : 'RALFWinkel'
//  '<S1>'   : 'RALFWinkel/Blank Message'
//  '<S2>'   : 'RALFWinkel/Compare To Constant1'
//  '<S3>'   : 'RALFWinkel/Compare To Constant2'
//  '<S4>'   : 'RALFWinkel/Publish'

#endif                                 // RTW_HEADER_RALFWinkel_h_

//
// File trailer for generated code.
//
// [EOF]
//
