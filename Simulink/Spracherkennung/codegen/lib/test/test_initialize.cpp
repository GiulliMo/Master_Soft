//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test_initialize.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Apr-2020 11:33:32
//

// Include Files
#include "test_initialize.h"
#include "DeepLearningNetwork.h"
#include "test.h"
#include "test_data.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void test_initialize()
{
  omp_init_nest_lock(&emlrtNestLockGlobal);
  test_init();
  isInitialized_test = true;
}

//
// File trailer for test_initialize.cpp
//
// [EOF]
//
