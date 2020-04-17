//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  computeDFT.h
//
//  Code generation for function 'computeDFT'
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
void computeDFT(const emlrtStack *sp, const real_T xin[39200], coder::array<
                creal_T, 2U> &Xx, real_T f_data[], int32_T f_size[1]);

// End of code generation (computeDFT.h)
