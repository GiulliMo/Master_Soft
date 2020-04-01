//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: sdf_target.h
//
// Code generated for Simulink model 'sdf_target'.
//
// Model version                  : 1.22
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Wed Apr  1 19:10:30 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_sdf_target_h_
#define RTW_HEADER_sdf_target_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#include "slros_initialize.h"
#include "sdf_target_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

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

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

// Block signals (default storage)
typedef struct {
  real_T A_d[9];
  real_T Pp[9];
  real_T K[9];
  real_T A_d_tmp[9];
  real_T Pp_m[9];
  real_T Pp_c[4];
  real_T dv[4];
  SL_Bus_sdf_target_geometry_msgs_Point BusAssignment2;// '<Root>/Bus Assignment2' 
  SL_Bus_sdf_target_geometry_msgs_Point BusAssignment1;// '<Root>/Bus Assignment1' 
  SL_Bus_sdf_target_geometry_msgs_Point BusAssignment;// '<Root>/Bus Assignment' 
  SL_Bus_sdf_target_geometry_msgs_Point BusAssignment3;// '<Root>/Bus Assignment3' 
  real_T LSM9DS1IMUSensor_o3[3];       // '<Root>/LSM9DS1 IMU Sensor'
  real_T LSM9DS1IMUSensor_o2[3];       // '<Root>/LSM9DS1 IMU Sensor'
  real_T xp1[3];
  real_T dv1[3];
  real_T dv2[3];
  real_T K_k[3];
  char_T cv[16];
  real_T xp[2];
  char_T cv1[15];
  real_T psikf;                        // '<S3>/KF_target'
  real_T LSM9DS1IMUSensor_o1[3];       // '<Root>/LSM9DS1 IMU Sensor'
  real_T absx11;
  real_T absx31;
  real_T q;
  real_T psi;                          // '<S2>/EKF'
  real_T A_d_tmp_c;
  real_T A_d_tmp_b;
  real_T A_d_tmp_p;
} B_sdf_target_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  raspi_internal_lsm9ds1Block_s_T obj; // '<Root>/LSM9DS1 IMU Sensor'
  ros_slros_internal_block_Publ_T obj_p;// '<S8>/SinkBlock'
  ros_slros_internal_block_Publ_T obj_o;// '<S7>/SinkBlock'
  ros_slros_internal_block_Publ_T obj_h;// '<S6>/SinkBlock'
  ros_slros_internal_block_Publ_T obj_j;// '<S5>/SinkBlock'
  ros_slros_internal_block_Publ_T obj_l;// '<S4>/SinkBlock'
  real_T x_dach[2];                    // '<S3>/KF_target'
  real_T P[4];                         // '<S3>/KF_target'
  real_T Q[4];                         // '<S3>/KF_target'
  real_T R;                            // '<S3>/KF_target'
  real_T C[2];                         // '<S3>/KF_target'
  real_T A_d[4];                       // '<S3>/KF_target'
  real_T x_dach_m[3];                  // '<S2>/EKF'
  real_T P_m[9];                       // '<S2>/EKF'
  real_T Q_i[9];                       // '<S2>/EKF'
  real_T R_i[9];                       // '<S2>/EKF'
  real_T C_j[9];                       // '<S2>/EKF'
  real_T I[9];                         // '<S2>/EKF'
  boolean_T firstRun_not_empty;        // '<S3>/KF_target'
} DW_sdf_target_T;

// Continuous states (default storage)
typedef struct {
  real_T Integrator_CSTATE;            // '<S3>/Integrator'
} X_sdf_target_T;

// State derivatives (default storage)
typedef struct {
  real_T Integrator_CSTATE;            // '<S3>/Integrator'
} XDot_sdf_target_T;

// State disabled
typedef struct {
  boolean_T Integrator_CSTATE;         // '<S3>/Integrator'
} XDis_sdf_target_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (default storage)
struct P_sdf_target_T_ {
  SL_Bus_sdf_target_geometry_msgs_Point Constant_Value;// Computed Parameter: Constant_Value
                                                          //  Referenced by: '<S1>/Constant'

  real_T ToAccel_Gain;                 // Expression: 9.81
                                          //  Referenced by: '<S2>/ToAccel'

  real_T degToRad_Gain;                // Expression: pi/180
                                          //  Referenced by: '<S2>/degToRad'

  real_T Samplezeit_Value;             // Expression: 0.01
                                          //  Referenced by: '<Root>/Samplezeit'

  real_T Gain5_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S2>/Gain5'

  real_T Gain3_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S2>/Gain3'

  real_T Integrator_IC;                // Expression: 0
                                          //  Referenced by: '<S3>/Integrator'

  real_T Gain6_Gain;                   // Expression: -1
                                          //  Referenced by: '<S3>/Gain6'

};

// Real-time Model Data Structure
struct tag_RTM_sdf_target_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_sdf_target_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_sdf_target_T sdf_target_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_sdf_target_T sdf_target_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_sdf_target_T sdf_target_X;

// Block states (default storage)
extern DW_sdf_target_T sdf_target_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void sdf_target_initialize(void);
  extern void sdf_target_step(void);
  extern void sdf_target_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_sdf_target_T *const sdf_target_M;

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
//  '<Root>' : 'sdf_target'
//  '<S1>'   : 'sdf_target/Blank Message'
//  '<S2>'   : 'sdf_target/Extended Kalman FIlter'
//  '<S3>'   : 'sdf_target/Kalman FIlter'
//  '<S4>'   : 'sdf_target/Publish'
//  '<S5>'   : 'sdf_target/Publish1'
//  '<S6>'   : 'sdf_target/Publish2'
//  '<S7>'   : 'sdf_target/Publish3'
//  '<S8>'   : 'sdf_target/Publish4'
//  '<S9>'   : 'sdf_target/switch_x_z'
//  '<S10>'  : 'sdf_target/switch_x_z1'
//  '<S11>'  : 'sdf_target/switch_x_z2'
//  '<S12>'  : 'sdf_target/Extended Kalman FIlter/EKF'
//  '<S13>'  : 'sdf_target/Kalman FIlter/KF_target'

#endif                                 // RTW_HEADER_sdf_target_h_

//
// File trailer for generated code.
//
// [EOF]
//
