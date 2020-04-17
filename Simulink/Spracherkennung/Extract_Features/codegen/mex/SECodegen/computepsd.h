//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  computepsd.h
//
//  Code generation for function 'computepsd'
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
void computepsd(const emlrtStack *sp, const coder::array<real_T, 2U> &Sxx1,
                const real_T w2_data[], const int32_T w2_size[1], const char_T
                range[8], coder::array<real_T, 2U> &varargout_1, real_T
                varargout_2_data[], int32_T varargout_2_size[1]);

// End of code generation (computepsd.h)
