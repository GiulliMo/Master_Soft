//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  ismember.h
//
//  Code generation for function 'ismember'
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
void local_ismember(const emlrtStack *sp, const real_T a_data[], const int32_T
                    a_size[2], boolean_T tf_data[], int32_T tf_size[2]);

// End of code generation (ismember.h)
