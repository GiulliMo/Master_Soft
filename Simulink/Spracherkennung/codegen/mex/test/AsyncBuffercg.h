//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  AsyncBuffercg.h
//
//  Code generation for function 'AsyncBuffercg'
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
dsp_private_AsyncBuffercg *AsyncBuffercg_AsyncBuffercg(dsp_private_AsyncBuffercg
  *obj);
void AsyncBuffercg_read(const emlrtStack *sp, dsp_private_AsyncBuffercg *obj,
  coder::array<real_T, 1U> &out);
void AsyncBuffercg_write(const emlrtStack *sp, dsp_private_AsyncBuffercg *obj,
  const real_T in_data[], const int32_T in_size[1]);

// End of code generation (AsyncBuffercg.h)
