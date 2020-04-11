//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test_types.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Apr-2020 11:33:32
//
#ifndef TEST_TYPES_H
#define TEST_TYPES_H

// Include Files
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
  float *getLayerOutput(int layerIndex, int portIndex);
  float *getInputDataPointer();
  float *getOutputDataPointer();
  ~b_commandNet_0();
  int batchSize;
  int numLayers;
  MWTensor *inputTensor;
  MWTensor *outputTensor;
  MWCNNLayer *layers[15];
  float *inputData;
  float *outputData;
 private:
  MWTargetNetworkImpl *targetImpl;
};

#define MAX_THREADS                    omp_get_max_threads()
#endif

//
// File trailer for test_types.h
//
// [EOF]
//
