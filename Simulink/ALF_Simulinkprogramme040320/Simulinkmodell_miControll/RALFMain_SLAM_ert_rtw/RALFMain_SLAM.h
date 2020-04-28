//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: RALFMain_SLAM.h
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
#ifndef RTW_HEADER_RALFMain_SLAM_h_
#define RTW_HEADER_RALFMain_SLAM_h_
#include <stddef.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "slros_initialize.h"
#include "RALFMain_SLAM_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
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

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
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

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

// Block signals for system '<S6>/Coordinate Transformation Conversion1'
typedef struct {
  real32_T soll_quat[4];        // '<S6>/Coordinate Transformation Conversion1'
} B_CoordinateTransformationCon_T;

// Block states (default storage) for system '<S6>/Coordinate Transformation Conversion1' 
typedef struct {
  robotics_slcore_internal_bloc_T obj;
                                // '<S6>/Coordinate Transformation Conversion1'
  boolean_T objisempty;         // '<S6>/Coordinate Transformation Conversion1'
} DW_CoordinateTransformationCo_T;

// Block signals (default storage)
typedef struct {
  SL_Bus_RALFMain_SLAM_sensor_msgs_Joy In1;// '<S27>/In1'
  SL_Bus_RALFMain_SLAM_sensor_msgs_Joy b_varargout_2;
  SL_Bus_RALFMain_SLAM_geometry_msgs_PoseStamped In1_i;// '<S39>/In1'
  SL_Bus_RALFMain_SLAM_geometry_msgs_PoseStamped b_varargout_2_m;
  SL_Bus_RALFMain_SLAM_geometry_msgs_Twist In1_m;// '<S36>/In1'
  SL_Bus_RALFMain_SLAM_geometry_msgs_Twist b_varargout_2_c;
  real32_T Product2_m[4];              // '<S51>/Product2'
  real32_T Gain_f[3];                  // '<S6>/Gain'
  real32_T Gain2_f[3];                 // '<S6>/Gain2'
  real_T rtb_istquat_idx_0;
  real_T rtb_istquat_idx_1;
  real_T rtb_istquat_idx_2;
  real_T rtb_Divide_idx_0;
  real_T rtb_Divide_idx_1;
  real32_T In1_e;                      // '<S46>/In1'
  int16_T Conversion[4];               // '<S1>/Conversion '
  real32_T Product1_d;                 // '<S16>/Product1'
  real32_T Product2_i;                 // '<S58>/Product2'
  real32_T Product2_b;                 // '<S16>/Product2'
  real32_T rtb_Switch_idx_0;
  real32_T rtb_Switch_idx_2;
  real32_T rtb_Switch_idx_3;
  int32_T DataTypeConversion_p;        // '<S49>/Data Type Conversion'
  int32_T rtb_Switch_idx_4;
  int16_T DataTypeConversion;          // '<Root>/Data Type Conversion'
  uint8_T BytePack[2];                 // '<Root>/Byte Pack'
  uint8_T BytePack_e[8];               // '<S1>/Byte Pack'
  B_CoordinateTransformationCon_T CoordinateTransformationCo_pnae;
                                // '<S6>/Coordinate Transformation Conversion1'
  B_CoordinateTransformationCon_T CoordinateTransformationCon_pna;
                                // '<S6>/Coordinate Transformation Conversion1'
} B_RALFMain_SLAM_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Subs_T obj; // '<S38>/SourceBlock'
  ros_slros_internal_block_Subs_T obj_d;// '<S30>/SourceBlock'
  ros_slros_internal_block_Subs_T obj_p;// '<S15>/SourceBlock'
  real_T CANsendbackleft_DSTATE;       // '<S1>/CAN send back left'
  real_T CANsendbackright_DSTATE;      // '<S1>/CAN send back right'
  real_T CANsendfrontleft_DSTATE;      // '<S1>/CAN send front left'
  real_T CANsendfrontright_DSTATE;     // '<S1>/CAN send front right'
  uint32_T Counter_ClkEphState;        // '<S2>/Counter'
  uint32_T Counter1_ClkEphState;       // '<S2>/Counter1'
  uint32_T Counter_ClkEphState_a;      // '<S18>/Counter'
  boolean_T Delay_DSTATE;              // '<S19>/Delay'
  uint8_T Counter_Count;               // '<S2>/Counter'
  uint8_T Counter1_Count;              // '<S2>/Counter1'
  uint8_T Counter_Count_i;             // '<S18>/Counter'
  DW_CoordinateTransformationCo_T CoordinateTransformationCo_pnae;
                                // '<S6>/Coordinate Transformation Conversion1'
  DW_CoordinateTransformationCo_T CoordinateTransformationCon_pna;
                                // '<S6>/Coordinate Transformation Conversion1'
} DW_RALFMain_SLAM_T;

// Parameters (default storage)
struct P_RALFMain_SLAM_T_ {
  real32_T nmax;                       // Variable: nmax
                                          //  Referenced by:
                                          //    '<S41>/Gain'
                                          //    '<S41>/Gain1'

  real32_T pwinkel;                    // Variable: pwinkel
                                          //  Referenced by: '<S51>/Gain4'

  real32_T pwinkel_vel;                // Variable: pwinkel_vel
                                          //  Referenced by: '<S52>/Gain4'

  real_T CompareToConstant1_const;   // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S17>/Constant'

  real32_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S53>/Constant'

  real32_T CompareToConstant_const_m;
                                    // Mask Parameter: CompareToConstant_const_m
                                       //  Referenced by: '<S28>/Constant'

  real32_T CompareToConstant_const_o;
                                    // Mask Parameter: CompareToConstant_const_o
                                       //  Referenced by: '<S22>/Constant'

  real32_T CompareToConstant1_const_p;
                                   // Mask Parameter: CompareToConstant1_const_p
                                      //  Referenced by: '<S23>/Constant'

  real32_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S25>/Constant'

  real32_T CompareToConstant2_const; // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S24>/Constant'

  real32_T CompareToConstant_const_j;
                                    // Mask Parameter: CompareToConstant_const_j
                                       //  Referenced by: '<S32>/Constant'

  real32_T CompareToConstant1_const_l;
                                   // Mask Parameter: CompareToConstant1_const_l
                                      //  Referenced by: '<S33>/Constant'

  real32_T CompareToConstant3_const_f;
                                   // Mask Parameter: CompareToConstant3_const_f
                                      //  Referenced by: '<S35>/Constant'

  real32_T CompareToConstant2_const_i;
                                   // Mask Parameter: CompareToConstant2_const_i
                                      //  Referenced by: '<S34>/Constant'

  real32_T CompareToConstant_const_l;
                                    // Mask Parameter: CompareToConstant_const_l
                                       //  Referenced by: '<S48>/Constant'

  real32_T CompareToConstant_const_g;
                                    // Mask Parameter: CompareToConstant_const_g
                                       //  Referenced by: '<S8>/Constant'

  uint8_T Counter_HitValue;            // Mask Parameter: Counter_HitValue
                                          //  Referenced by: '<S2>/Counter'

  uint8_T Counter1_HitValue;           // Mask Parameter: Counter1_HitValue
                                          //  Referenced by: '<S2>/Counter1'

  uint8_T Counter_HitValue_f;          // Mask Parameter: Counter_HitValue_f
                                          //  Referenced by: '<S18>/Counter'

  uint8_T Counter_InitialCount;        // Mask Parameter: Counter_InitialCount
                                          //  Referenced by: '<S2>/Counter'

  uint8_T Counter1_InitialCount;       // Mask Parameter: Counter1_InitialCount
                                          //  Referenced by: '<S2>/Counter1'

  uint8_T Counter_InitialCount_n;      // Mask Parameter: Counter_InitialCount_n
                                          //  Referenced by: '<S18>/Counter'

  SL_Bus_RALFMain_SLAM_sensor_msgs_Joy Out1_Y0;// Computed Parameter: Out1_Y0
                                                  //  Referenced by: '<S27>/Out1'

  SL_Bus_RALFMain_SLAM_sensor_msgs_Joy Constant_Value;// Computed Parameter: Constant_Value
                                                         //  Referenced by: '<S15>/Constant'

  SL_Bus_RALFMain_SLAM_sensor_msgs_Joy Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                           //  Referenced by: '<S11>/Constant'

  SL_Bus_RALFMain_SLAM_geometry_msgs_PoseStamped Out1_Y0_i;// Computed Parameter: Out1_Y0_i
                                                              //  Referenced by: '<S39>/Out1'

  SL_Bus_RALFMain_SLAM_geometry_msgs_PoseStamped Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                                     //  Referenced by: '<S38>/Constant'

  SL_Bus_RALFMain_SLAM_geometry_msgs_Twist Out1_Y0_j;// Computed Parameter: Out1_Y0_j
                                                        //  Referenced by: '<S36>/Out1'

  SL_Bus_RALFMain_SLAM_geometry_msgs_Twist Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                               //  Referenced by: '<S30>/Constant'

  real_T Gain1_Gain;                   // Expression: -5
                                          //  Referenced by: '<S2>/Gain1'

  real_T Gain_Gain;                    // Expression: 5
                                          //  Referenced by: '<S2>/Gain'

  real_T Gain_Gain_n;                  // Expression: 180/pi
                                          //  Referenced by: '<S5>/Gain'

  real_T Constant_Value_e;             // Expression: 1
                                          //  Referenced by: '<S62>/Constant'

  real_T Constant_Value_o;             // Expression: 1
                                          //  Referenced by: '<S63>/Constant'

  real_T Constant1_Value;              // Expression: -2
                                          //  Referenced by: '<S10>/Constant1'

  real_T Constant_Value_gx;            // Expression: 1
                                          //  Referenced by: '<S10>/Constant'

  real_T Constant2_Value;              // Expression: 8
                                          //  Referenced by: '<S2>/Constant2'

  real_T Constant3_Value;              // Expression: 11
                                          //  Referenced by: '<S2>/Constant3'

  real_T Constant_Value_d;             // Expression: 0
                                          //  Referenced by: '<Root>/Constant'

  real_T Constant_Value_j;             // Expression: 0
                                          //  Referenced by: '<S6>/Constant'

  real_T Gain3_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S6>/Gain3'

  real_T Constant_Value_f;             // Expression: -1
                                          //  Referenced by: '<S47>/Constant'

  real_T Constant_Value_b[4];          // Expression: [-1;1;-1;1]
                                          //  Referenced by: '<S1>/Constant'

  real_T CANsendbackleft_P1_Size[2];
                                  // Computed Parameter: CANsendbackleft_P1_Size
                                     //  Referenced by: '<S1>/CAN send back left'

  real_T CANsendbackleft_P1;           // Expression: Port
                                          //  Referenced by: '<S1>/CAN send back left'

  real_T CANsendbackleft_P2_Size[2];
                                  // Computed Parameter: CANsendbackleft_P2_Size
                                     //  Referenced by: '<S1>/CAN send back left'

  real_T CANsendbackleft_P2;           // Expression: Identifier
                                          //  Referenced by: '<S1>/CAN send back left'

  real_T CANsendbackright_P1_Size[2];
                                 // Computed Parameter: CANsendbackright_P1_Size
                                    //  Referenced by: '<S1>/CAN send back right'

  real_T CANsendbackright_P1;          // Expression: Port
                                          //  Referenced by: '<S1>/CAN send back right'

  real_T CANsendbackright_P2_Size[2];
                                 // Computed Parameter: CANsendbackright_P2_Size
                                    //  Referenced by: '<S1>/CAN send back right'

  real_T CANsendbackright_P2;          // Expression: Identifier
                                          //  Referenced by: '<S1>/CAN send back right'

  real_T CANsendfrontleft_P1_Size[2];
                                 // Computed Parameter: CANsendfrontleft_P1_Size
                                    //  Referenced by: '<S1>/CAN send front left'

  real_T CANsendfrontleft_P1;          // Expression: Port
                                          //  Referenced by: '<S1>/CAN send front left'

  real_T CANsendfrontleft_P2_Size[2];
                                 // Computed Parameter: CANsendfrontleft_P2_Size
                                    //  Referenced by: '<S1>/CAN send front left'

  real_T CANsendfrontleft_P2;          // Expression: Identifier
                                          //  Referenced by: '<S1>/CAN send front left'

  real_T CANsendfrontright_P1_Size[2];
                                // Computed Parameter: CANsendfrontright_P1_Size
                                   //  Referenced by: '<S1>/CAN send front right'

  real_T CANsendfrontright_P1;         // Expression: Port
                                          //  Referenced by: '<S1>/CAN send front right'

  real_T CANsendfrontright_P2_Size[2];
                                // Computed Parameter: CANsendfrontright_P2_Size
                                   //  Referenced by: '<S1>/CAN send front right'

  real_T CANsendfrontright_P2;         // Expression: Identifier
                                          //  Referenced by: '<S1>/CAN send front right'

  real_T SimulationPace_P1;            // Expression: SimulationPace
                                          //  Referenced by: '<Root>/Simulation Pace'

  real_T SimulationPace_P2;            // Expression: 1
                                          //  Referenced by: '<Root>/Simulation Pace'

  real_T SimulationPace_P3;            // Expression: OutputPaceError
                                          //  Referenced by: '<Root>/Simulation Pace'

  real_T SimulationPace_P4;            // Expression: SampleTime
                                          //  Referenced by: '<Root>/Simulation Pace'

  real32_T Constant_Value_gi;          // Computed Parameter: Constant_Value_gi
                                          //  Referenced by: '<S4>/Constant'

  real32_T MagnitudeAngletoComplex_Constan;
                          // Computed Parameter: MagnitudeAngletoComplex_Constan
                             //  Referenced by: '<S16>/Magnitude-Angle to Complex'

  real32_T Out1_Y0_p;                  // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S46>/Out1'

  real32_T Constant_Value_h[8];        // Computed Parameter: Constant_Value_h
                                          //  Referenced by: '<S50>/Constant'

  real32_T Gain_Gain_c;                // Computed Parameter: Gain_Gain_c
                                          //  Referenced by: '<S10>/Gain'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S10>/Gain1'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S10>/Gain2'

  real32_T Constant_Value_la;          // Computed Parameter: Constant_Value_la
                                          //  Referenced by: '<S3>/Constant'

  real32_T Constant_Value_p;           // Computed Parameter: Constant_Value_p
                                          //  Referenced by: '<S18>/Constant'

  real32_T Switch_Threshold;           // Computed Parameter: Switch_Threshold
                                          //  Referenced by: '<S3>/Switch'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S50>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S50>/Saturation3'

  real32_T Gain2_Gain_l;               // Computed Parameter: Gain2_Gain_l
                                          //  Referenced by: '<S6>/Gain2'

  real32_T Gain_Gain_f;                // Computed Parameter: Gain_Gain_f
                                          //  Referenced by: '<S6>/Gain'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S6>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S6>/Saturation'

  real32_T Constant1_Value_d[4];       // Computed Parameter: Constant1_Value_d
                                          //  Referenced by: '<S51>/Constant1'

  real32_T Constant1_Value_i[4];       // Computed Parameter: Constant1_Value_i
                                          //  Referenced by: '<S52>/Constant1'

  real32_T Gain3_Gain_i;               // Computed Parameter: Gain3_Gain_i
                                          //  Referenced by: '<S41>/Gain3'

  real32_T Gain2_Gain_d;               // Computed Parameter: Gain2_Gain_d
                                          //  Referenced by: '<S41>/Gain2'

  boolean_T Delay_InitialCondition;// Computed Parameter: Delay_InitialCondition
                                      //  Referenced by: '<S19>/Delay'

};

// Real-time Model Data Structure
struct tag_RTM_RALFMain_SLAM_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  //
  //  NonInlinedSFcns:
  //  The following substructure contains information regarding
  //  non-inlined s-functions used in the model.

  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[4];
    SimStruct *childSFunctionPtrs[4];
    struct _ssBlkInfo2 blkInfo2[4];
    struct _ssSFcnModelMethods2 methods2[4];
    struct _ssSFcnModelMethods3 methods3[4];
    struct _ssSFcnModelMethods4 methods4[4];
    struct _ssStatesInfo2 statesInfo2[4];
    ssPeriodicStatesInfo periodicStatesInfo[4];
    struct _ssPortInfo2 inputOutputPortInfo2[4];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T stepSize;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_RALFMain_SLAM_T RALFMain_SLAM_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_RALFMain_SLAM_T RALFMain_SLAM_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_RALFMain_SLAM_T RALFMain_SLAM_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void RALFMain_SLAM_initialize(void);
  extern void RALFMain_SLAM_step(void);
  extern void RALFMain_SLAM_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_RALFMain_SLAM_T *const RALFMain_SLAM_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S20>/Check Signal Attributes' : Unused code path elimination
//  Block '<S21>/Check Signal Attributes' : Unused code path elimination
//  Block '<S26>/x->r' : Unused code path elimination
//  Block '<S4>/Data Type Conversion3' : Unused code path elimination
//  Block '<S37>/x->r' : Unused code path elimination
//  Block '<S6>/Display' : Unused code path elimination
//  Block '<S6>/Display1' : Unused code path elimination
//  Block '<S6>/Gain1' : Unused code path elimination
//  Block '<S2>/Cast To Double1' : Eliminate redundant data type conversion
//  Block '<S2>/Cast To Double2' : Eliminate redundant data type conversion


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
//  '<Root>' : 'RALFMain_SLAM'
//  '<S1>'   : 'RALFMain_SLAM/Drehzahl Conversion und CAN send'
//  '<S2>'   : 'RALFMain_SLAM/Joystickdaten'
//  '<S3>'   : 'RALFMain_SLAM/Modusumschaltung'
//  '<S4>'   : 'RALFMain_SLAM/RALFNavi'
//  '<S5>'   : 'RALFMain_SLAM/RALFWinkel'
//  '<S6>'   : 'RALFMain_SLAM/Winkelregelung'
//  '<S7>'   : 'RALFMain_SLAM/Drehzahl Conversion und CAN send/Abfrage DMS-Betaetigung'
//  '<S8>'   : 'RALFMain_SLAM/Drehzahl Conversion und CAN send/Abfrage DMS-Betaetigung/Compare To Constant'
//  '<S9>'   : 'RALFMain_SLAM/Joystickdaten/AxesToBus'
//  '<S10>'  : 'RALFMain_SLAM/Joystickdaten/AxesToMatrix'
//  '<S11>'  : 'RALFMain_SLAM/Joystickdaten/Blank Message'
//  '<S12>'  : 'RALFMain_SLAM/Joystickdaten/ButtonsToBus'
//  '<S13>'  : 'RALFMain_SLAM/Joystickdaten/Cursorabfrage'
//  '<S14>'  : 'RALFMain_SLAM/Joystickdaten/Joystick_in_Winkel'
//  '<S15>'  : 'RALFMain_SLAM/Joystickdaten/Subscribe'
//  '<S16>'  : 'RALFMain_SLAM/Joystickdaten/scale_to_absolut'
//  '<S17>'  : 'RALFMain_SLAM/Joystickdaten/AxesToMatrix/Compare To Constant1'
//  '<S18>'  : 'RALFMain_SLAM/Joystickdaten/ButtonsToBus/Modusumschaltung'
//  '<S19>'  : 'RALFMain_SLAM/Joystickdaten/ButtonsToBus/Modusumschaltung/Edge Detector'
//  '<S20>'  : 'RALFMain_SLAM/Joystickdaten/ButtonsToBus/Modusumschaltung/Edge Detector/Check Signal Attributes'
//  '<S21>'  : 'RALFMain_SLAM/Joystickdaten/ButtonsToBus/Modusumschaltung/Edge Detector/Check Signal Attributes1'
//  '<S22>'  : 'RALFMain_SLAM/Joystickdaten/Cursorabfrage/Compare To Constant'
//  '<S23>'  : 'RALFMain_SLAM/Joystickdaten/Cursorabfrage/Compare To Constant1'
//  '<S24>'  : 'RALFMain_SLAM/Joystickdaten/Cursorabfrage/Compare To Constant2'
//  '<S25>'  : 'RALFMain_SLAM/Joystickdaten/Cursorabfrage/Compare To Constant3'
//  '<S26>'  : 'RALFMain_SLAM/Joystickdaten/Joystick_in_Winkel/Cartesian to Polar'
//  '<S27>'  : 'RALFMain_SLAM/Joystickdaten/Subscribe/Enabled Subsystem'
//  '<S28>'  : 'RALFMain_SLAM/Joystickdaten/scale_to_absolut/Compare To Constant'
//  '<S29>'  : 'RALFMain_SLAM/RALFNavi/Geschwindigkeitsabfrage'
//  '<S30>'  : 'RALFMain_SLAM/RALFNavi/Subscribe'
//  '<S31>'  : 'RALFMain_SLAM/RALFNavi/XY_in_Winkel'
//  '<S32>'  : 'RALFMain_SLAM/RALFNavi/Geschwindigkeitsabfrage/Compare To Constant'
//  '<S33>'  : 'RALFMain_SLAM/RALFNavi/Geschwindigkeitsabfrage/Compare To Constant1'
//  '<S34>'  : 'RALFMain_SLAM/RALFNavi/Geschwindigkeitsabfrage/Compare To Constant2'
//  '<S35>'  : 'RALFMain_SLAM/RALFNavi/Geschwindigkeitsabfrage/Compare To Constant3'
//  '<S36>'  : 'RALFMain_SLAM/RALFNavi/Subscribe/Enabled Subsystem'
//  '<S37>'  : 'RALFMain_SLAM/RALFNavi/XY_in_Winkel/Cartesian to Polar'
//  '<S38>'  : 'RALFMain_SLAM/RALFWinkel/Subscribe1'
//  '<S39>'  : 'RALFMain_SLAM/RALFWinkel/Subscribe1/Enabled Subsystem'
//  '<S40>'  : 'RALFMain_SLAM/Winkelregelung/DMS Safety'
//  '<S41>'  : 'RALFMain_SLAM/Winkelregelung/Mecanum_control'
//  '<S42>'  : 'RALFMain_SLAM/Winkelregelung/Quaternion Conjugate2'
//  '<S43>'  : 'RALFMain_SLAM/Winkelregelung/Quaternion Multiplication'
//  '<S44>'  : 'RALFMain_SLAM/Winkelregelung/Quaternions to Rotation Angles'
//  '<S45>'  : 'RALFMain_SLAM/Winkelregelung/DMS Safety/Abfrage DMS-Betaetigung'
//  '<S46>'  : 'RALFMain_SLAM/Winkelregelung/DMS Safety/If Action Subsystem'
//  '<S47>'  : 'RALFMain_SLAM/Winkelregelung/DMS Safety/Negation DMS'
//  '<S48>'  : 'RALFMain_SLAM/Winkelregelung/DMS Safety/Abfrage DMS-Betaetigung/Compare To Constant'
//  '<S49>'  : 'RALFMain_SLAM/Winkelregelung/Mecanum_control/Abfrage DMS-Betaetigung'
//  '<S50>'  : 'RALFMain_SLAM/Winkelregelung/Mecanum_control/Fahrtwinkelbewegungsvektor'
//  '<S51>'  : 'RALFMain_SLAM/Winkelregelung/Mecanum_control/Posenwinkelbewegungsvektor'
//  '<S52>'  : 'RALFMain_SLAM/Winkelregelung/Mecanum_control/WInkelgeschwindigkeitsbewegungsvektor'
//  '<S53>'  : 'RALFMain_SLAM/Winkelregelung/Mecanum_control/Abfrage DMS-Betaetigung/Compare To Constant'
//  '<S54>'  : 'RALFMain_SLAM/Winkelregelung/Mecanum_control/Fahrtwinkelbewegungsvektor/Polar to Cartesian'
//  '<S55>'  : 'RALFMain_SLAM/Winkelregelung/Quaternion Multiplication/q0'
//  '<S56>'  : 'RALFMain_SLAM/Winkelregelung/Quaternion Multiplication/q1'
//  '<S57>'  : 'RALFMain_SLAM/Winkelregelung/Quaternion Multiplication/q2'
//  '<S58>'  : 'RALFMain_SLAM/Winkelregelung/Quaternion Multiplication/q3'
//  '<S59>'  : 'RALFMain_SLAM/Winkelregelung/Quaternions to Rotation Angles/Angle Calculation'
//  '<S60>'  : 'RALFMain_SLAM/Winkelregelung/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S61>'  : 'RALFMain_SLAM/Winkelregelung/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S62>'  : 'RALFMain_SLAM/Winkelregelung/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S63>'  : 'RALFMain_SLAM/Winkelregelung/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S64>'  : 'RALFMain_SLAM/Winkelregelung/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S65>'  : 'RALFMain_SLAM/Winkelregelung/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S66>'  : 'RALFMain_SLAM/Winkelregelung/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // RTW_HEADER_RALFMain_SLAM_h_

//
// File trailer for generated code.
//
// [EOF]
//
