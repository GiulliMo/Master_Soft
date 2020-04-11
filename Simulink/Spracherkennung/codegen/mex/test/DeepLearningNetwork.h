//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  DeepLearningNetwork.h
//
//  Code generation for function 'DeepLearningNetwork'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
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
void DeepLearningNetwork_setup(b_commandNet_0 *obj);

// End of code generation (DeepLearningNetwork.h)
