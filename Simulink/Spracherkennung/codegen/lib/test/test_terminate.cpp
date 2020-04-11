//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test_terminate.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Apr-2020 11:33:32
//

// Include Files
#include "test_terminate.h"
#include "DeepLearningNetwork.h"
#include "test.h"
#include "test_data.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void test_terminate()
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
  isInitialized_test = false;
}

//
// File trailer for test_terminate.cpp
//
// [EOF]
//
