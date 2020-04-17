//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  SECodegen_terminate.cpp
//
//  Code generation for function 'SECodegen_terminate'
//


// Include files
#include "SECodegen_terminate.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "SECodegen_data.h"
#include "_coder_SECodegen_mex.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
void SECodegen_atexit()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  SECodegen_init();
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void SECodegen_terminate()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (SECodegen_terminate.cpp)
