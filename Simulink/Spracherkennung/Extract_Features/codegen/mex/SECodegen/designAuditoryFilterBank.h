//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  designAuditoryFilterBank.h
//
//  Code generation for function 'designAuditoryFilterBank'
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
void designAuditoryFilterBank(SECodegenStackData *SD, const emlrtStack *sp,
  real_T filterBank[12850], real_T Fc[50]);

// End of code generation (designAuditoryFilterBank.h)
