//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  pspectrogram.h
//
//  Code generation for function 'pspectrogram'
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
void centerOutputs(const emlrtStack *sp, coder::array<creal_T, 2U> &y, real_T
                   f_data[], const int32_T f_size[1], coder::array<real_T, 2U>
                   &Pxx);
void compute_PSD(const emlrtStack *sp, const coder::array<creal_T, 2U> &y,
                 real_T f_data[], int32_T f_size[1], const char_T options_range
                 [8], coder::array<real_T, 2U> &Pxx);

// End of code generation (pspectrogram.h)
