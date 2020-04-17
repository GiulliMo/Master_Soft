//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_SECodegen_mex.cpp
//
//  Code generation for function '_coder_SECodegen_mex'
//


// Include files
#include "_coder_SECodegen_mex.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "SECodegen_data.h"
#include "SECodegen_initialize.h"
#include "SECodegen_mexutil.h"
#include "SECodegen_terminate.h"
#include "_coder_SECodegen_api.h"
#include <string.h>

// Function Declarations
MEXFUNCTION_LINKAGE void SECodegen_mexFunction(SECodegenStackData *SD, int32_T
  nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[1]);

// Function Definitions
void SECodegen_mexFunction(SECodegenStackData *SD, int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;

  // Check for proper number of arguments.
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4, 9,
                        "SECodegen");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "SECodegen");
  }

  // Call the function.
  SECodegen_api(SD, prhs, nlhs, outputs);

  // Copy over outputs to the caller.
  emlrtReturnArrays(1, plhs, &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  SECodegenStackData *SECodegenStackDataGlobal = NULL;
  SECodegenStackDataGlobal = new SECodegenStackData;
  mexAtExit(&SECodegen_atexit);
  emlrtLoadMATLABLibrary("sys/os/glnxa64/libiomp5.so");

  // Initialize the memory manager.
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);

  // Module initialization.
  SECodegen_initialize();
  st.tls = emlrtRootTLSGlobal;
  try {
    // Dispatch the entry-point.
    SECodegen_mexFunction(SECodegenStackDataGlobal, nlhs, plhs, nrhs, prhs);

    // Module termination.
    SECodegen_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  } catch (...) {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }

  delete SECodegenStackDataGlobal;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                     &emlrtLockerFunction, omp_get_num_procs());
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_SECodegen_mex.cpp)
