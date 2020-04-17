//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  spectrogram.h
//
//  Code generation for function 'spectrogram'
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
void spectrogram(SECodegenStackData *SD, const emlrtStack *sp, const real_T x
                 [16000], coder::array<creal_T, 2U> &varargout_1, real_T
                 varargout_2_data[], int32_T varargout_2_size[1], real_T
                 varargout_3[98], coder::array<real_T, 2U> &varargout_4);

// End of code generation (spectrogram.h)
