//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  test_types.h
//
//  Code generation for function 'test_types'
//


#pragma once

// Include files
#include "rtwtypes.h"

// Type Definitions
#include "cnn_api.hpp"
#include "MWTargetNetworkImpl.hpp"

// Type Definitions
class b_commandNet_0
{
 public:
  void allocate();
  void postsetup();
  b_commandNet_0();
  void deallocate();
  void setSize();
  void setup();
  void predict();
  void cleanup();
  real32_T *getLayerOutput(int32_T layerIndex, int32_T portIndex);
  real32_T *getInputDataPointer();
  real32_T *getOutputDataPointer();
  ~b_commandNet_0();
  int32_T batchSize;
  int32_T numLayers;
  MWTensor *inputTensor;
  MWTensor *outputTensor;
  MWCNNLayer *layers[15];
  real32_T *inputData;
  real32_T *outputData;
 private:
  MWTargetNetworkImpl *targetImpl;
};

#define MAX_THREADS                    omp_get_max_threads()

// End of code generation (test_types.h)
