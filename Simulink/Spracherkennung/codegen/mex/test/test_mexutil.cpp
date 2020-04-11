//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  test_mexutil.cpp
//
//  Code generation for function 'test_mexutil'
//


// Include files
#include "test_mexutil.h"
#include "DeepLearningNetwork.h"
#include "rt_nonfinite.h"
#include "test.h"
#include "test_data.h"
#include <cstdlib>
#include <cstring>

// Function Definitions
void checkRunTimeError(const char * errMsg, const char * file, uint32_T line)
{
  emlrtRTEInfo rtInfo;
  uint32_T errMsgLen;
  rtInfo = createEmlrtInfoStruct(file, line);
  errMsgLen = (uint32_T)strlen(errMsg);
  emlrtErrorWithMessageIdR2018a(emlrtRootTLSGlobal, &rtInfo,
    "dnn_core:cnncodegen:RunTimeError", "dnn_core:cnncodegen:RunTimeError", 3,
    mxCHAR_CLASS, errMsgLen, errMsg);
}

emlrtRTEInfo createEmlrtInfoStruct(const char * file, uint32_T line)
{
  emlrtRTEInfo rtInfo;
  char_T *pn;
  char_T *fn;
  char_T *brk;
  uint32_T len;
  len = (uint32_T)strlen(file);
  pn = (char_T *)calloc(len + 1U, 1U);
  fn = (char_T *)calloc(len + 1U, 1U);
  memcpy(pn, file, len);
  memcpy(fn, file, len);
  brk = strrchr(fn, '.');
  *brk = '\x00';
  brk = strrchr(fn, '/');
  if (brk == NULL) {
    brk = strrchr(fn, '\\');
  }

  if (brk == NULL) {
    brk = fn;
  } else {
    brk++;
  }

  rtInfo.lineNo = static_cast<int32_T>(line);
  rtInfo.colNo = 0;
  rtInfo.fName = brk;
  rtInfo.pName = pn;
  return rtInfo;
}

emlrtCTX emlrtGetRootTLSGlobal()
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const emlrtConstCTX aTLS,
  void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

// End of code generation (test_mexutil.cpp)
