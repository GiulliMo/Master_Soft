//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Apr-2020 11:33:32
//
#ifndef TEST_H
#define TEST_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "test_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void test(double in3, float out[12]);
extern void test_init();

#endif

//
// File trailer for test.h
//
// [EOF]
//
