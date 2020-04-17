//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  SECodegen_initialize.cpp
//
//  Code generation for function 'SECodegen_initialize'
//


// Include files
#include "SECodegen_initialize.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "SECodegen_data.h"
#include "_coder_SECodegen_mex.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Declarations
static void SECodegen_once();

// Function Definitions
static void SECodegen_once()
{
  mex_InitInfAndNan();
  SECodegen_init();
}

void SECodegen_initialize()
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
  emlrtLicenseCheckR2012b(&st, "Signal_Toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    SECodegen_once();
  }
}

// End of code generation (SECodegen_initialize.cpp)
