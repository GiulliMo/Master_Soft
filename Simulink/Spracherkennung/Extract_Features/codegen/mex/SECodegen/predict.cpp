//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  predict.cpp
//
//  Code generation for function 'predict'
//


// Include files
#include "predict.h"
#include "DeepLearningNetwork.h"
#include "MWDeepLearningUtils.hpp"
#include "SECodegen.h"
#include "SECodegen_mexutil.h"
#include "rt_nonfinite.h"
#include <cstring>
#include <string.h>

// Type Definitions
struct cell_wrap_35
{
  real32_T f1[12];
};

// Function Definitions
void DeepLearningNetwork_predict(b_commandNet_0 *obj, const real_T in[4900],
  real32_T varargout_1[12])
{
  int32_T i;
  real32_T miniBatchT[4900];
  cell_wrap_35 outputsMiniBatch[1];
  for (i = 0; i < 98; i++) {
    for (int32_T i1 = 0; i1 < 50; i1++) {
      miniBatchT[i1 + 50 * i] = static_cast<real32_T>(in[i + 98 * i1]);
    }
  }

  memcpy(obj->getInputDataPointer(), miniBatchT, obj->layers[1]->getOutputTensor
         (0)->getNumElements() * sizeof(real32_T));
  TRY_DL_ERROR_CHECK();
  obj->predict();
  CATCH_DL_ERROR_CHECK();
  checkRunTimeError(err.what(), __FILE__, __LINE__);
  LEAVE_DL_ERROR_CHECK();
  memcpy(outputsMiniBatch[0].f1, obj->getLayerOutput(14, 0), obj->layers[14]
         ->getOutputTensor(0)->getNumElements() * sizeof(real32_T));
  for (i = 0; i < 12; i++) {
    varargout_1[i] = outputsMiniBatch[0].f1[i];
  }
}

// End of code generation (predict.cpp)
