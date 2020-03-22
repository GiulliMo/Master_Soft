//
//  MecanumPose_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "MecanumPose".
//
//  Model version              : 1.5
//  Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
//  C++ source code generated on : Sun Mar 22 11:28:49 2020
//
//  Target selection: ert.tlc
//  Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "ext_types.h"

// data type size table
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(SL_Bus_ROSVariableLengthArrayInfo),
  sizeof(SL_Bus_MecanumPose_std_msgs_MultiArrayDimension),
  sizeof(SL_Bus_MecanumPose_std_msgs_MultiArrayLayout),
  sizeof(SL_Bus_MecanumPose_std_msgs_Int16MultiArray),
  sizeof(ros_slros_internal_block_Subs_T)
};

// data type name table
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "SL_Bus_ROSVariableLengthArrayInfo",
  "SL_Bus_MecanumPose_std_msgs_MultiArrayDimension",
  "SL_Bus_MecanumPose_std_msgs_MultiArrayLayout",
  "SL_Bus_MecanumPose_std_msgs_Int16MultiArray",
  "ros_slros_internal_block_Subs_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&MecanumPose_B.In1), 17, 0, 1 },

  { (char_T *)(&MecanumPose_B.Product[0]), 0, 0, 8 },

  { (char_T *)(&MecanumPose_B.Data[0]), 4, 0, 128 }
  ,

  { (char_T *)(&MecanumPose_DW.obj), 18, 0, 1 },

  { (char_T *)(&MecanumPose_DW.EnabledSubsystem_SubsysRanBC), 2, 0, 1 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&MecanumPose_P.J[0]), 0, 0, 12 },

  { (char_T *)(&MecanumPose_P.Out1_Y0), 17, 0, 1 },

  { (char_T *)(&MecanumPose_P.Constant_Value), 17, 0, 1 },

  { (char_T *)(&MecanumPose_P.XVel_Value), 0, 0, 8 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

// [EOF] MecanumPose_dt.h
