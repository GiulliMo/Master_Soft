//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  SECodegen_types.h
//
//  Code generation for function 'SECodegen_types'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#ifdef _MSC_VER

#pragma warning(push)
#pragma warning(disable : 4251)

#endif

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

struct emxArray_char_T_1x10
{
  char_T data[10];
  int32_T size[2];
};

struct cell_wrap_0
{
  emxArray_char_T_1x10 f1;
};

struct cell_wrap_17
{
  real_T f1[16000];
};

struct SECodegenStackData
{
  struct {
    int16_T winPerCh[39200];
  } f0;

  struct {
    real_T fbank[25600];
  } f1;

  struct {
    real_T xin[39200];
    real_T c[39200];
    cell_wrap_17 r;
  } f2;

  struct {
    real_T filterBank2[12850];
  } f3;
};

#define MAX_THREADS                    omp_get_max_threads()
#ifdef _MSC_VER

#pragma warning(pop)

#endif

// End of code generation (SECodegen_types.h)
