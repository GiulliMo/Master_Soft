//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  ifWhileCond.cpp
//
//  Code generation for function 'ifWhileCond'
//


// Include files
#include "ifWhileCond.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
boolean_T ifWhileCond(const boolean_T x_data[], const int32_T x_size[2])
{
  boolean_T y;
  y = (x_size[1] != 0);
  if (y) {
    int32_T k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x_size[1] - 1)) {
      if (!x_data[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return y;
}

// End of code generation (ifWhileCond.cpp)
