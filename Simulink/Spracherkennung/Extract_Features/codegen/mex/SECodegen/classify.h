//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  classify.h
//
//  Code generation for function 'classify'
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
void DeepLearningNetwork_classify(const emlrtStack *sp, b_commandNet_0 *obj,
  const real_T indata[4900], real32_T scores[12]);

// End of code generation (classify.h)
