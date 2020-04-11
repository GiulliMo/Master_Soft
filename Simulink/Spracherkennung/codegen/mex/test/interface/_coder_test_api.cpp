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
#include "DeepLearningNetwork.h"
#include "rt_nonfinite.h"
#include "test.h"
#include "test_data.h"

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *in3, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const real32_T u[12]);

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

static const mxArray *emlrt_marshallOut(const real32_T u[12])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 0, 0 };

  static const int32_T iv1[2] = { 1, 12 };

  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxSINGLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, *(int32_T (*)[2])&iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

void test_api(const mxArray * const prhs[1], int32_T, const mxArray *plhs[1])
{
  real32_T (*out)[12];
  real_T in3;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  out = (real32_T (*)[12])mxMalloc(sizeof(real32_T [12]));

  // Marshall function inputs
  in3 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "in3");

  // Invoke the target function
  test(&st, in3, *out);

  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(*out);
}

// End of code generation (_coder_test_api.cpp)
