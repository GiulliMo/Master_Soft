//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_SECodegen_api.cpp
//
//  Code generation for function '_coder_SECodegen_api'
//


// Include files
#include "_coder_SECodegen_api.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "SECodegen_data.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Declarations
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[16000];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[16000];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *y, const
  char_T *identifier))[16000];
static const mxArray *emlrt_marshallOut(const real32_T u[12]);

// Function Definitions
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[16000]
{
  real_T (*y)[16000];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[16000]
{
  real_T (*ret)[16000];
  static const int32_T dims[1] = { 16000 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[16000])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *y, const
  char_T *identifier))[16000]
{
  real_T (*b_y)[16000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_y = b_emlrt_marshallIn(sp, emlrtAlias(y), &thisId);
  emlrtDestroyArray(&y);
  return b_y;
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

void SECodegen_api(SECodegenStackData *SD, const mxArray * const prhs[1],
                   int32_T, const mxArray *plhs[1])
{
  real32_T (*out)[12];
  real_T (*y)[16000];
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  out = (real32_T (*)[12])mxMalloc(sizeof(real32_T [12]));

  // Marshall function inputs
  y = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "y");

  // Invoke the target function
  SECodegen(SD, &st, *y, *out);

  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(*out);
}

// End of code generation (_coder_SECodegen_api.cpp)
