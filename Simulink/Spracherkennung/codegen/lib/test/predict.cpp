//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: predict.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Apr-2020 11:33:32
//

// Include Files
#include "predict.h"
#include "DeepLearningNetwork.h"
#include "test.h"
#include "test_rtwutil.h"
#include <cstring>

// Type Definitions
struct cell_wrap_6
{
  float f1[12];
};

// Function Definitions

//
// Arguments    : void
// Return Type  : int *
//

//
// Arguments    : b_commandNet_0 *obj
//                const double in[4900]
//                float varargout_1[12]
// Return Type  : void
//
void DeepLearningNetwork_predict(b_commandNet_0 *obj, const double in[4900],
  float varargout_1[12])
{
  int i;
  float miniBatchT[4900];
  cell_wrap_6 outputsMiniBatch[1];
  for (i = 0; i < 98; i++) {
    for (int i1 = 0; i1 < 50; i1++) {
      miniBatchT[i1 + 50 * i] = static_cast<float>(in[i + 98 * i1]);
    }
  }

  memcpy(obj->getInputDataPointer(), miniBatchT, obj->layers[1]->getOutputTensor
         (0)->getNumElements() * sizeof(float));
  obj->predict();
  memcpy(outputsMiniBatch[0].f1, obj->getLayerOutput(14, 0), obj->layers[14]
         ->getOutputTensor(0)->getNumElements() * sizeof(float));
  for (i = 0; i < 12; i++) {
    varargout_1[i] = outputsMiniBatch[0].f1[i];
  }
}

//
// File trailer for predict.cpp
//
// [EOF]
//
