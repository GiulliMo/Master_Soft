//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imresize.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Apr-2020 11:33:32
//

// Include Files
#include "imresize.h"
#include "DeepLearningNetwork.h"
#include "test.h"
#include <cmath>
#include <cstring>

// Function Definitions

//
// Arguments    : const double in_[4900]
//                const double weights[50]
//                const int indices[50]
//                double out_[4900]
// Return Type  : void
//
void b_resizeAlongDim(const double in_[4900], const double weights[50], const
                      int indices[50], double out_[4900])
{
  double in[4900];
  int pixelIndex;
  double sumVal1;
  int outCInd;
  std::memcpy(&in[0], &in_[0], 4900U * sizeof(double));

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(pixelIndex,sumVal1,outCInd)

  for (int inRInd = 0; inRInd < 98; inRInd++) {
    for (outCInd = 0; outCInd < 50; outCInd++) {
      //  Core - second dimension
      pixelIndex = (inRInd + (indices[outCInd] - 1) * 98) + 1;
      sumVal1 = weights[outCInd] * in[pixelIndex - 1];
      out_[inRInd + 98 * outCInd] = sumVal1;
    }
  }
}

//
// Arguments    : int indices[98]
// Return Type  : void
//
void contributions(int indices[98])
{
  int i;
  int b_indices[588];
  static const signed char iv[588] = { -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
    69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
    88, 89, 90, 91, 92, 93, 94, 95, 96, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
    89, 90, 91, 92, 93, 94, 95, 96, 97, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
    89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
    89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
    89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 4, 5, 6, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
    69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
    88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101 };

  int aux[196];
  int k;

  //  Contributions, using pixel indices
  for (i = 0; i < 588; i++) {
    b_indices[i] = iv[i];
  }

  //  Create the auxiliary matrix:
  aux[0] = 1;
  aux[98] = 98;
  for (i = 0; i < 97; i++) {
    aux[i + 1] = aux[i] + 1;
    aux[i + 99] = aux[i + 98] - 1;
  }

  //  Mirror the out-of-bounds indices using mod:
  for (i = 0; i < 588; i++) {
    if (static_cast<double>(b_indices[i]) - 1.0 == 0.0) {
      k = 0;
    } else {
      k = static_cast<int>(std::fmod(static_cast<double>(b_indices[i]) - 1.0,
        196.0));
      if (k == 0) {
        k = 0;
      } else {
        if (static_cast<double>(b_indices[i]) - 1.0 < 0.0) {
          k += 196;
        }
      }
    }

    b_indices[i] = aux[k];
  }

  std::memcpy(&indices[0], &b_indices[196], 98U * sizeof(int));
}

//
// Arguments    : const double in_[4900]
//                const double weights[98]
//                const int indices[98]
//                double out_[4900]
// Return Type  : void
//
void resizeAlongDim(const double in_[4900], const double weights[98], const int
                    indices[98], double out_[4900])
{
  double in[4900];
  double sumVal1;
  int outRInd;
  std::memcpy(&in[0], &in_[0], 4900U * sizeof(double));

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(sumVal1,outRInd)

  for (int inCInd = 0; inCInd < 50; inCInd++) {
    for (outRInd = 0; outRInd < 98; outRInd++) {
      //  Core - first dimension
      sumVal1 = weights[outRInd] * in[(indices[outRInd] + 98 * inCInd) - 1];
      out_[outRInd + 98 * inCInd] = sumVal1;
    }
  }
}

//
// File trailer for imresize.cpp
//
// [EOF]
//
