//
//  RALFWinkel_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "RALFWinkel".
//
//  Model version              : 1.5
//  Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
//  C++ source code generated on : Thu Nov 15 17:12:57 2018
//
//  Target selection: ert.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex
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
  sizeof(SL_Bus_RALFWinkel_geometry_msgs_Point),
  sizeof(raspi_internal_lsm9ds1Block_R_T),
  sizeof(robotics_slros_internal_block_T)
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
  "SL_Bus_RALFWinkel_geometry_msgs_Point",
  "raspi_internal_lsm9ds1Block_R_T",
  "robotics_slros_internal_block_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&RALFWinkel_B.Constant), 14, 0, 1 },

  { (char_T *)(&RALFWinkel_B.phi), 0, 0, 10 }
  ,

  { (char_T *)(&RALFWinkel_DW.obj), 15, 0, 1 },

  { (char_T *)(&RALFWinkel_DW.Scope_PWORK.LoggedData), 11, 0, 5 },

  { (char_T *)(&RALFWinkel_DW.obj_j), 16, 0, 1 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&RALFWinkel_P.CompareToConstant1_const), 0, 0, 2 },

  { (char_T *)(&RALFWinkel_P.Constant_Value), 14, 0, 1 },

  { (char_T *)(&RALFWinkel_P.Integrator1_IC), 0, 0, 5 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

// [EOF] RALFWinkel_dt.h
