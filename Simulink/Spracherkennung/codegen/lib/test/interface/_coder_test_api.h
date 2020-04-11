/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_test_api.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 11-Apr-2020 11:33:32
 */

#ifndef _CODER_TEST_API_H
#define _CODER_TEST_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#define MAX_THREADS                    omp_get_max_threads()

/* Function Declarations */
extern void test(real_T in3, real32_T out[12]);
extern void test_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray *
                     plhs[1]);
extern void test_atexit(void);
extern void test_initialize(void);
extern void test_terminate(void);
extern void test_xil_shutdown(void);
extern void test_xil_terminate(void);

#endif

/*
 * File trailer for _coder_test_api.h
 *
 * [EOF]
 */
