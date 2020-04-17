//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  iseven.cpp
//
//  Code generation for function 'iseven'
//


// Include files
#include "iseven.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo gd_emlrtRSI = { 9,  // lineNo
  "iseven",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/iseven.m"// pathName
};

static emlrtRTEInfo l_emlrtRTEI = { 12,// lineNo
  1,                                   // colNo
  "iseven",                            // fName
  "/usr/local/MATLAB/R2020a/toolbox/shared/signalwavelet/signalwavelet/+signalwavelet/+internal/iseven.m"// pName 
};

// Function Definitions
boolean_T iseven(const emlrtStack *sp, real_T x)
{
  int32_T n;
  real_T r;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gd_emlrtRSI;
  n = 0;
  if (x - x != 0.0) {
    n = 1;
  }

  if (n != 0) {
    emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
      "shared_signalwavelet:util:integer:ArgumentMustBeIntegerValued",
      "shared_signalwavelet:util:integer:ArgumentMustBeIntegerValued", 0);
  }

  if (muDoubleScalarIsNaN(x) || muDoubleScalarIsInf(x)) {
    r = rtNaN;
  } else {
    r = muDoubleScalarRem(x, 2.0);
    if (r == 0.0) {
      r = 0.0;
    }
  }

  return r == 0.0;
}

// End of code generation (iseven.cpp)
