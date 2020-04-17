//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  designMelFilterBank.h
//
//  Code generation for function 'designMelFilterBank'
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
void designMelFilterBank(const emlrtStack *sp, const real_T bandEdges[52],
  real_T filterBank[25600], real_T centerFrequencies[50], boolean_T
  *FFTLengthTooSmall);

// End of code generation (designMelFilterBank.h)
