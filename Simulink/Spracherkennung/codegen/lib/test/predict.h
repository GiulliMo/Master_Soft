//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: predict.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Apr-2020 11:33:32
//
#ifndef PREDICT_H
#define PREDICT_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "test_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void DeepLearningNetwork_predict(b_commandNet_0 *obj, const double in
  [4900], float varargout_1[12]);

#endif

//
// File trailer for predict.h
//
// [EOF]
//
