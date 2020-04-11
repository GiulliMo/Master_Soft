//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_test_mex.cpp
//
//  Code generation for function '_coder_test_mex'
//


// Include files
#include "_coder_test_mex.h"
#include "DeepLearningNetwork.h"
#include "_coder_test_api.h"
#include "test.h"
#include "test_data.h"
#include "test_initialize.h"
#include "test_mexutil.h"
#include "test_terminate.h"

// Function Declarations
MEXFUNCTION_LINKAGE void test_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1]);

// Function Definitions
void test_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
                      mxArray *prhs[1])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;

  // Check for proper number of arguments.
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4, 4,
                        "test");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 4,
                        "test");
  }

  // Call the function.
  test_api(prhs, nlhs, outputs);

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

  mexAtExit(&test_atexit);
  emlrtLoadMATLABLibrary("sys/os/glnxa64/libiomp5.so");

  // Initialize the memory manager.
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);

  // Module initialization.
  test_initialize();
  st.tls = emlrtRootTLSGlobal;
  try {
    // Dispatch the entry-point.
    test_mexFunction(nlhs, plhs, nrhs, prhs);

    // Module termination.
    test_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  } catch (...) {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                     &emlrtLockerFunction, omp_get_num_procs());
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_test_mex.cpp)
