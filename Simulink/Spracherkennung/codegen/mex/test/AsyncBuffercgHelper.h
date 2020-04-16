//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  AsyncBuffercgHelper.h
//
//  Code generation for function 'AsyncBuffercgHelper'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "test_types.h"

// Function Declarations
int32_T AsyncBuffercgHelper_stepImpl(const emlrtStack *sp,
  dsp_private_AsyncBuffercgHelper *obj, const real_T in_data[], const int32_T
  in_size[1]);
void c_AsyncBuffercgHelper_ReadSampl(const emlrtStack *sp, const
  dsp_private_AsyncBuffercgHelper *obj, coder::array<real_T, 1U> &out, int32_T
  *underrun, int32_T *overlapUnderrun, int32_T *c);

// End of code generation (AsyncBuffercgHelper.h)
