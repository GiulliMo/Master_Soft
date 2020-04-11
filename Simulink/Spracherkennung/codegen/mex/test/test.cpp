//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  test.cpp
//
//  Code generation for function 'test'
//


// Include files
#include "test.h"
#include "DeepLearningNetwork.h"
#include "imresize.h"
#include "predict.h"
#include "rt_nonfinite.h"

// Variable Definitions
static b_commandNet_0 mynet;
static boolean_T mynet_not_empty;
static emlrtRSInfo emlrtRSI = { 4,     // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

// Function Definitions
void test(const emlrtStack *sp, real_T, real32_T out[12])
{
  real_T in2[4900];
  b_commandNet_0 *iobj_0;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  imresize(&st, in2);
  if (!mynet_not_empty) {
    iobj_0 = &mynet;
    DeepLearningNetwork_setup(iobj_0);
    mynet_not_empty = true;
  }

  DeepLearningNetwork_predict(&mynet, in2, out);
}

void test_init()
{
  mynet_not_empty = false;
}

// End of code generation (test.cpp)
