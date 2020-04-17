//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  psdoptions.cpp
//
//  Code generation for function 'psdoptions'
//


// Include files
#include "psdoptions.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "ifWhileCond.h"
#include "ismember.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo xb_emlrtRSI = { 394,// lineNo
  "checkUniqueOpts",                   // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo yb_emlrtRSI = { 399,// lineNo
  "checkUniqueOpts",                   // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo ac_emlrtRSI = { 409,// lineNo
  "checkUniqueOpts",                   // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo bc_emlrtRSI = { 38, // lineNo
  "ismember",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/ismember.m"// pathName
};

static emlrtECInfo d_emlrtECI = { -1,  // nDims
  420,                                 // lineNo
  9,                                   // colNo
  "checkUniqueOpts",                   // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pName
};

// Function Definitions
void checkUniqueOpts(const emlrtStack *sp, const real_T arg_data[], const
                     int32_T arg_size[2], boolean_T *err, real_T visitedOpts[16],
                     real_T *b_index)
{
  boolean_T tf_data[19];
  int32_T tf_size[2];
  int32_T b_tf_size[2];
  boolean_T b_tf_data[19];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  *b_index = 1.0;
  memset(&visitedOpts[0], 0, 16U * sizeof(real_T));
  st.site = &xb_emlrtRSI;
  b_st.site = &bc_emlrtRSI;
  local_ismember(&b_st, arg_data, arg_size, tf_data, tf_size);
  st.site = &xb_emlrtRSI;
  if (ifWhileCond(tf_data, tf_size)) {
    *err = true;
  } else {
    int32_T loop_ub_tmp;
    int32_T i;
    boolean_T guard1 = false;
    boolean_T guard2 = false;
    tf_size[0] = 1;
    tf_size[1] = arg_size[1];
    loop_ub_tmp = arg_size[0] * arg_size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      tf_data[i] = (arg_data[i] == 1.0);
    }

    guard1 = false;
    guard2 = false;
    st.site = &yb_emlrtRSI;
    if (ifWhileCond(tf_data, tf_size)) {
      guard2 = true;
    } else {
      int32_T loop_ub;
      b_tf_size[0] = 1;
      b_tf_size[1] = arg_size[1];
      loop_ub = arg_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_tf_data[i] = (tf_data[i] || (arg_data[i] == 2.0));
      }

      st.site = &yb_emlrtRSI;
      if (ifWhileCond(b_tf_data, b_tf_size)) {
        guard2 = true;
      } else {
        tf_size[0] = 1;
        tf_size[1] = arg_size[1];
        for (i = 0; i < loop_ub_tmp; i++) {
          tf_data[i] = (arg_data[i] == 3.0);
        }

        st.site = &yb_emlrtRSI;
        if (ifWhileCond(tf_data, tf_size)) {
          guard2 = true;
        } else {
          tf_size[0] = 1;
          tf_size[1] = arg_size[1];
          for (i = 0; i < loop_ub_tmp; i++) {
            tf_data[i] = (arg_data[i] == 4.0);
          }

          st.site = &yb_emlrtRSI;
          if (ifWhileCond(tf_data, tf_size)) {
            guard2 = true;
          } else {
            tf_size[0] = 1;
            tf_size[1] = arg_size[1];
            for (i = 0; i < loop_ub_tmp; i++) {
              tf_data[i] = (arg_data[i] == 5.0);
            }

            st.site = &ac_emlrtRSI;
            if (ifWhileCond(tf_data, tf_size)) {
              guard1 = true;
            } else {
              b_tf_size[0] = 1;
              b_tf_size[1] = arg_size[1];
              loop_ub = arg_size[1];
              for (i = 0; i < loop_ub; i++) {
                b_tf_data[i] = (tf_data[i] || (arg_data[i] == 6.0));
              }

              st.site = &ac_emlrtRSI;
              if (ifWhileCond(b_tf_data, b_tf_size)) {
                guard1 = true;
              } else {
                tf_size[0] = 1;
                tf_size[1] = arg_size[1];
                for (i = 0; i < loop_ub_tmp; i++) {
                  tf_data[i] = (arg_data[i] == 7.0);
                }

                st.site = &ac_emlrtRSI;
                if (ifWhileCond(tf_data, tf_size)) {
                  guard1 = true;
                } else {
                  if (1 != arg_size[1]) {
                    emlrtSubAssignSizeCheck1dR2017a(1, arg_size[1], &d_emlrtECI,
                      sp);
                  }

                  visitedOpts[0] = arg_data[0];
                  *b_index = 2.0;
                }
              }
            }
          }
        }
      }
    }

    if (guard2) {
      visitedOpts[0] = 1.0;
      visitedOpts[1] = 2.0;
      visitedOpts[2] = 3.0;
      visitedOpts[3] = 4.0;
      *b_index = 4.0;
    }

    if (guard1) {
      visitedOpts[0] = 5.0;
      visitedOpts[1] = 6.0;
      visitedOpts[2] = 7.0;
      *b_index = 3.0;
    }

    *err = false;
  }
}

// End of code generation (psdoptions.cpp)
