//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  bark2hz.cpp
//
//  Code generation for function 'bark2hz'
//


// Include files
#include "bark2hz.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
static emlrtECInfo emlrtECI = { -1,    // nDims
  26,                                  // lineNo
  1,                                   // colNo
  "bark2hz",                           // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/bark2hz.m"// pName
};

// Function Definitions
void bark2hz(const emlrtStack *sp, real_T hz[52])
{
  int32_T trueCount;
  static const real_T b_dv[6] = { -0.53, -0.037415303659852808,
    0.45516939268029433, 0.94775408902044134, 1.4403387853605887,
    1.9329234817007361 };

  int32_T partialTrueCount;
  int32_T b_trueCount;
  int32_T i;
  real_T tmp_data[52];
  for (trueCount = 0; trueCount < 52; trueCount++) {
    hz[trueCount] = 0.41869699188912513 * static_cast<real_T>(trueCount) +
      -0.15050000000000002;
  }

  for (trueCount = 0; trueCount < 6; trueCount++) {
    hz[trueCount] = b_dv[trueCount];
  }

  trueCount = 0;
  partialTrueCount = 0;
  b_trueCount = 0;
  for (i = 0; i < 52; i++) {
    if (hz[i] > 20.1) {
      trueCount++;
      tmp_data[partialTrueCount] = (hz[i] + 4.4220000000000006) / 1.22;
      partialTrueCount++;
      b_trueCount++;
    }
  }

  if (b_trueCount != trueCount) {
    emlrtSubAssignSizeCheck1dR2017a(b_trueCount, trueCount, &emlrtECI, sp);
  }

  partialTrueCount = 0;
  for (i = 0; i < 52; i++) {
    real_T d;
    d = hz[i];
    if (hz[i] > 20.1) {
      d = tmp_data[partialTrueCount];
      partialTrueCount++;
    }

    d = 1960.0 * (d + 0.53) / (26.28 - d);
    hz[i] = d;
  }
}

// End of code generation (bark2hz.cpp)
