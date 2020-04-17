//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  getSTFTColumns.cpp
//
//  Code generation for function 'getSTFTColumns'
//


// Include files
#include "getSTFTColumns.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
void getSTFTColumns(SECodegenStackData *SD, const real_T x[16000], real_T xin
                    [39200], real_T t[98])
{
  int32_T k;
  static const real_T b_dv[98] = { 0.0125, 0.0225, 0.0325, 0.0425, 0.0525,
    0.0625, 0.0725, 0.0825, 0.0925, 0.1025, 0.1125, 0.1225, 0.1325, 0.1425,
    0.1525, 0.1625, 0.1725, 0.1825, 0.1925, 0.2025, 0.2125, 0.2225, 0.2325,
    0.2425, 0.2525, 0.2625, 0.2725, 0.2825, 0.2925, 0.3025, 0.3125, 0.3225,
    0.3325, 0.3425, 0.3525, 0.3625, 0.3725, 0.3825, 0.3925, 0.4025, 0.4125,
    0.4225, 0.4325, 0.4425, 0.4525, 0.4625, 0.4725, 0.4825, 0.4925, 0.5025,
    0.5125, 0.5225, 0.5325, 0.5425, 0.5525, 0.5625, 0.5725, 0.5825, 0.5925,
    0.6025, 0.6125, 0.6225, 0.6325, 0.6425, 0.6525, 0.6625, 0.6725, 0.6825,
    0.6925, 0.7025, 0.7125, 0.7225, 0.7325, 0.7425, 0.7525, 0.7625, 0.7725,
    0.7825, 0.7925, 0.8025, 0.8125, 0.8225, 0.8325, 0.8425, 0.8525, 0.8625,
    0.8725, 0.8825, 0.8925, 0.9025, 0.9125, 0.9225, 0.9325, 0.9425, 0.9525,
    0.9625, 0.9725, 0.9825 };

  for (k = 0; k < 98; k++) {
    t[k] = b_dv[k];
    for (int32_T b_k = 0; b_k < 400; b_k++) {
      SD->f0.winPerCh[b_k + 400 * k] = static_cast<int16_T>((b_k + 160 * k) + 1);
    }
  }

  for (k = 0; k < 39200; k++) {
    xin[k] = x[SD->f0.winPerCh[k] - 1];
  }
}

// End of code generation (getSTFTColumns.cpp)
