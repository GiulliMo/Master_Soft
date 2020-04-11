//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imresize.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Apr-2020 11:33:32
//
#ifndef IMRESIZE_H
#define IMRESIZE_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "test_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void b_resizeAlongDim(const double in_[4900], const double weights[50],
  const int indices[50], double out_[4900]);
extern void contributions(int indices[98]);
extern void resizeAlongDim(const double in_[4900], const double weights[98],
  const int indices[98], double out_[4900]);

#endif

//
// File trailer for imresize.h
//
// [EOF]
//
