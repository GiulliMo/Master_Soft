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
#include "omp.h"
#include "test_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
CODEGEN_EXPORT_SYM void test(const emlrtStack *sp, real_T in3, real32_T out[12]);
void test_init();

// End of code generation (test.h)
