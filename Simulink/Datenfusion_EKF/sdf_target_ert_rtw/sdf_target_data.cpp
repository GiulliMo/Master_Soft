//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: sdf_target_data.cpp
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
#include "sdf_target.h"
#include "sdf_target_private.h"

// Block parameters (default storage)
P_sdf_target_T sdf_target_P = {
  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Expression: 9.81
  //  Referenced by: '<S2>/ToAccel'

  9.81,

  // Expression: pi/180
  //  Referenced by: '<S2>/degToRad'

  0.017453292519943295,

  // Expression: 0.01
  //  Referenced by: '<Root>/Samplezeit'

  0.01,

  // Expression: 180/pi
  //  Referenced by: '<S2>/Gain5'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S2>/Gain3'

  57.295779513082323,

  // Expression: 0
  //  Referenced by: '<S3>/Integrator'

  0.0,

  // Expression: -1
  //  Referenced by: '<S3>/Gain6'

  -1.0
};

//
// File trailer for generated code.
//
// [EOF]
//
