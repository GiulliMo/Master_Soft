//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  test_data.h
//
//  Code generation for function 'test_data'
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
#include "test_types.h"

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t emlrtNestLockGlobal;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo b_emlrtRSI;
extern emlrtRSInfo c_emlrtRSI;
extern emlrtRSInfo f_emlrtRSI;
extern emlrtRSInfo g_emlrtRSI;
extern emlrtRSInfo h_emlrtRSI;
extern emlrtRSInfo i_emlrtRSI;
extern emlrtRSInfo j_emlrtRSI;
extern emlrtRSInfo k_emlrtRSI;
extern emlrtRSInfo l_emlrtRSI;
extern emlrtRSInfo m_emlrtRSI;

#define MAX_THREADS                    omp_get_max_threads()

// End of code generation (test_data.h)
