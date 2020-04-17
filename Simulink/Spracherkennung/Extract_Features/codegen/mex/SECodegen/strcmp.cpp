//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  strcmp.cpp
//
//  Code generation for function 'strcmp'
//


// Include files
#include "strcmp.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "SECodegen_data.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
void b_strcmp(const char_T a_data[], const int32_T a_size[2], boolean_T b_bool[3])
{
  static const char_T b_cv[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd' };

  b_bool[0] = false;
  b_bool[1] = false;
  b_bool[2] = false;
  if (a_size[1] == 8) {
    int32_T kstr;
    kstr = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (cv[static_cast<uint8_T>(a_data[kstr])] != cv[static_cast<int32_T>
            (b_cv[kstr])]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[2] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

boolean_T c_strcmp(const char_T a[8])
{
  static const char_T b[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd' };

  return memcmp((char_T *)&a[0], (char_T *)&b[0], 8) == 0;
}

// End of code generation (strcmp.cpp)
