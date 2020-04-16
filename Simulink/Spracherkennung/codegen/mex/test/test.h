//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  test.h
//
//  Code generation for function 'test'
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
CODEGEN_EXPORT_SYM void test(testStackData *SD, const emlrtStack *sp, real_T in3,
  coder::array<real_T, 1U> &out);

// End of code generation (test.h)
