//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: DeepLearningNetwork.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Apr-2020 11:33:32
//
#ifndef DEEPLEARNINGNETWORK_H
#define DEEPLEARNINGNETWORK_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "test_types.h"

// Type Definitions
#include "MWElementwiseAffineLayer.hpp"
#include "cnn_api.hpp"
#include "MWFusedConvReLULayer.hpp"
#include "MWTargetNetworkImpl.hpp"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void DeepLearningNetwork_setup(b_commandNet_0 *obj);

#endif

//
// File trailer for DeepLearningNetwork.h
//
// [EOF]
//
