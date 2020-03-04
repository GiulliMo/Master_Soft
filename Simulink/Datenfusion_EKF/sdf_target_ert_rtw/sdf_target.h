/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sdf_target.h
 *
 * Code generated for Simulink model 'sdf_target'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar  4 20:49:03 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sdf_target_h_
#define RTW_HEADER_sdf_target_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef sdf_target_COMMON_INCLUDES_
# define sdf_target_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_I2C.h"
#endif                                 /* sdf_target_COMMON_INCLUDES_ */

#include "sdf_target_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
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

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T A_d[9];
  real_T Pp[9];
  real_T K[9];
  real_T A_d_tmp[9];
  real_T Pp_m[9];
  real_T Pp_c[4];
  real_T K_k[4];
  real_T ToAccel[3];                   /* '<Root>/ToAccel' */
  real_T degToRad[3];                  /* '<Root>/degToRad' */
  real_T LSM9DS1IMUSensor_o3[3];       /* '<Root>/LSM9DS1 IMU Sensor' */
  real_T dv0[3];
  real_T xp[2];
  real_T K_c[2];
  real_T psi_magnetometer;             /* '<Root>/Gain5' */
  real_T omega_integriert;             /* '<Root>/Gain6' */
  real_T psi_predict;                  /* '<Root>/Gain3' */
  real_T psikf;                        /* '<Root>/KF_target' */
  real_T psi;                          /* '<Root>/EKF' */
  real_T LSM9DS1IMUSensor_o1[3];       /* '<Root>/LSM9DS1 IMU Sensor' */
  real_T q;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  real_T xp3;                          /* '<Root>/EKF' */
  real_T rtb_LSM9DS1IMUSensor_o3_b;
  real_T A_d_tmp_p;
} B_sdf_target_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  raspi_internal_lsm9ds1Block_s_T obj; /* '<Root>/LSM9DS1 IMU Sensor' */
  real_T x_dach[2];                    /* '<Root>/KF_target' */
  real_T P[4];                         /* '<Root>/KF_target' */
  real_T Q[4];                         /* '<Root>/KF_target' */
  real_T R;                            /* '<Root>/KF_target' */
  real_T C[2];                         /* '<Root>/KF_target' */
  real_T A_d[4];                       /* '<Root>/KF_target' */
  real_T x_dach_g[3];                  /* '<Root>/EKF' */
  real_T P_f[9];                       /* '<Root>/EKF' */
  real_T Q_c[9];                       /* '<Root>/EKF' */
  real_T R_b[9];                       /* '<Root>/EKF' */
  real_T C_j[9];                       /* '<Root>/EKF' */
  real_T I[9];                         /* '<Root>/EKF' */
  struct {
    void *LoggedData[5];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  boolean_T firstRun_not_empty;        /* '<Root>/KF_target' */
} DW_sdf_target_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} X_sdf_target_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} XDot_sdf_target_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
} XDis_sdf_target_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_sdf_target_T_ {
  real_T ToAccel_Gain;                 /* Expression: 9.81
                                        * Referenced by: '<Root>/ToAccel'
                                        */
  real_T degToRad_Gain;                /* Expression: pi/180
                                        * Referenced by: '<Root>/degToRad'
                                        */
  real_T Samplezeit_Value;             /* Expression: 0.01
                                        * Referenced by: '<Root>/Samplezeit'
                                        */
  real_T Gain5_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Gain6_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Gain3_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_sdf_target_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
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

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
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

/* Block parameters (default storage) */
extern P_sdf_target_T sdf_target_P;

/* Block signals (default storage) */
extern B_sdf_target_T sdf_target_B;

/* Continuous states (default storage) */
extern X_sdf_target_T sdf_target_X;

/* Block states (default storage) */
extern DW_sdf_target_T sdf_target_DW;

/* Model entry point functions */
extern void sdf_target_initialize(void);
extern void sdf_target_step(void);
extern void sdf_target_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sdf_target_T *const sdf_target_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'sdf_target'
 * '<S1>'   : 'sdf_target/EKF'
 * '<S2>'   : 'sdf_target/KF_target'
 */
#endif                                 /* RTW_HEADER_sdf_target_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
