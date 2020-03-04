//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: RALFWinkel_data.cpp
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
#include "RALFWinkel.h"
#include "RALFWinkel_private.h"

// Block parameters (auto storage)
P_RALFWinkel_T RALFWinkel_P = {
  // Mask Parameter: CompareToConstant1_const
  //  Referenced by: '<S2>/Constant'

  2.0,

  // Mask Parameter: CompareToConstant2_const
  //  Referenced by: '<S3>/Constant'

  -2.0,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Expression: 0
  //  Referenced by: '<Root>/Integrator1'

  0.0,

  // Expression: 0.65
  //  Referenced by: '<Root>/Constant'

  0.65,

  // Expression: 0
  //  Referenced by: '<Root>/Integrator'

  0.0,

  // Computed Parameter: TransferFcn_A
  //  Referenced by: '<Root>/Transfer Fcn'

  -3.3333333333333335,

  // Computed Parameter: TransferFcn_C
  //  Referenced by: '<Root>/Transfer Fcn'

  3.3333333333333335
};

//
// File trailer for generated code.
//
// [EOF]
//
