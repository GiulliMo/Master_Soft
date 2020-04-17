//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  circshift.h
//
//  Code generation for function 'circshift'
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
#include "SECodegen_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
void b_circshift(const emlrtStack *sp, coder::array<real_T, 2U> &a, real_T p);
void circshift(const emlrtStack *sp, coder::array<creal_T, 2U> &a, real_T p);

// End of code generation (circshift.h)
