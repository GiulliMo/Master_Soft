//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  test_initialize.cpp
//
//  Code generation for function 'test_initialize'
//


// Include files
#include "test_initialize.h"
#include "DeepLearningNetwork.h"
#include "_coder_test_mex.h"
#include "rt_nonfinite.h"
#include "test.h"
#include "test_data.h"

// Variable Definitions
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

// Function Declarations
static void test_once();

// Function Definitions
static void test_once()
{
  mex_InitInfAndNan();
  test_init();
}

void test_initialize()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Neural_Network_Toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    test_once();
  }
}

// End of code generation (test_initialize.cpp)
