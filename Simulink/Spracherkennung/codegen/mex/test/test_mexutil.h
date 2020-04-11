//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  test_mexutil.h
//
//  Code generation for function 'test_mexutil'
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
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
CODEGEN_EXPORT_SYM void checkRunTimeError(const char * errMsg, const char * file,
  uint32_T line);
CODEGEN_EXPORT_SYM emlrtRTEInfo createEmlrtInfoStruct(const char * file,
  uint32_T line);
CODEGEN_EXPORT_SYM emlrtCTX emlrtGetRootTLSGlobal();
CODEGEN_EXPORT_SYM void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const
  emlrtConstCTX aTLS, void *aData);

// End of code generation (test_mexutil.h)
