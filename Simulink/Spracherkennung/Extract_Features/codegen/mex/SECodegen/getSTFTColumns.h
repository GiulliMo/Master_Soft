//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  getSTFTColumns.h
//
//  Code generation for function 'getSTFTColumns'
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
void getSTFTColumns(SECodegenStackData *SD, const real_T x[16000], real_T xin
                    [39200], real_T t[98]);

// End of code generation (getSTFTColumns.h)
