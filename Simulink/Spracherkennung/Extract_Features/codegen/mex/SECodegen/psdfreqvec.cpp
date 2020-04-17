//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  psdfreqvec.cpp
//
//  Code generation for function 'psdfreqvec'
//


// Include files
#include "psdfreqvec.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
void b_psdfreqvec(real_T w_data[], int32_T w_size[1])
{
  real_T w1_data[512];
  for (int32_T i = 0; i < 512; i++) {
    w1_data[i] = 31.25 * static_cast<real_T>(i);
  }

  w1_data[256] = 8000.0;
  w1_data[511] = 15968.75;
  w_size[0] = 257;
  memcpy(&w_data[0], &w1_data[0], 257U * sizeof(real_T));
}

void psdfreqvec(real_T w_data[], int32_T w_size[1])
{
  real_T w1_data[512];
  for (int32_T i = 0; i < 512; i++) {
    w1_data[i] = 31.25 * static_cast<real_T>(i);
  }

  w1_data[256] = 8000.0;
  w1_data[511] = 15968.75;
  w_size[0] = 512;
  memcpy(&w_data[0], &w1_data[0], 512U * sizeof(real_T));
}

// End of code generation (psdfreqvec.cpp)
