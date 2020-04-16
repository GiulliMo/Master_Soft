//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  matlabCodegenHandle.h
//
//  Code generation for function 'matlabCodegenHandle'
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
void c_matlabCodegenHandle_matlabCod(const emlrtStack *sp, audioDeviceReader
  *obj);
void d_matlabCodegenHandle_matlabCod(const emlrtStack *sp,
  dsp_private_AsyncBuffercg *obj);
void e_matlabCodegenHandle_matlabCod(const emlrtStack *sp,
  dsp_private_AsyncBuffercgHelper *obj);

// End of code generation (matlabCodegenHandle.h)
