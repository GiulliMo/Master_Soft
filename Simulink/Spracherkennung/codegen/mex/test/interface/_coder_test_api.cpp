//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_test_api.cpp
//
//  Code generation for function '_coder_test_api'
//


// Include files
#include "_coder_test_api.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"
#include "test.h"
#include "test_data.h"

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static const mxArray *d_emlrt_marshallOut(const coder::array<real_T, 1U> &u);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *in3, const
  char_T *identifier);

// Function Definitions
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static const mxArray *d_emlrt_marshallOut(const coder::array<real_T, 1U> &u)
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[1] = { 0 };

  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 1U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 1U> *)&u)->size(), 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *in3, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(in3), &thisId);
  emlrtDestroyArray(&in3);
  return y;
}

void test_api(testStackData *SD, const mxArray * const prhs[1], int32_T, const
              mxArray *plhs[1])
{
  real_T in3;
  coder::array<real_T, 1U> out;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  // Marshall function inputs
  in3 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "in3");

  // Invoke the target function
  test(SD, &st, in3, out);

  // Marshall function outputs
  out.no_free();
  plhs[0] = d_emlrt_marshallOut(out);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_test_api.cpp)
