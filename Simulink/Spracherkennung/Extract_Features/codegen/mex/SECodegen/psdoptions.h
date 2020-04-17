//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  psdoptions.h
//
//  Code generation for function 'psdoptions'
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
void checkUniqueOpts(const emlrtStack *sp, const real_T arg_data[], const
                     int32_T arg_size[2], boolean_T *err, real_T visitedOpts[16],
                     real_T *b_index);

// End of code generation (psdoptions.h)
