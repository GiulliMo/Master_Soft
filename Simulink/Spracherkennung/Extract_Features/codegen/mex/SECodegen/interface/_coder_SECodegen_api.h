//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_SECodegen_api.h
//
//  Code generation for function '_coder_SECodegen_api'
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
void SECodegen_api(SECodegenStackData *SD, const mxArray * const prhs[1],
                   int32_T nlhs, const mxArray *plhs[1]);

// End of code generation (_coder_SECodegen_api.h)
