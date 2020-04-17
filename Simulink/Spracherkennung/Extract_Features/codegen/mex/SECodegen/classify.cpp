//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  classify.cpp
//
//  Code generation for function 'classify'
//


// Include files
#include "classify.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "mwmathutil.h"
#include "predict.h"
#include "rt_nonfinite.h"
#include <string.h>

// Type Definitions
struct emxArray_cell_wrap_0_1
{
  cell_wrap_0 data[1];
  int32_T size[1];
};

// Variable Definitions
static emlrtRSInfo fe_emlrtRSI = { 1,  // lineNo
  "DeepLearningNetwork/classify",      // fcnName
  "/home/alf/Documents/MATLAB/SupportPackages/R2020a/toolbox/shared/dlcoder_base/supportpackages/shared_dl_targets/+coder/@DeepLear"
  "ningNetwork/classify.p"             // pathName
};

static emlrtRSInfo he_emlrtRSI = { 301,// lineNo
  "categorical/categorical",           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/matlab/datatypes/codegen/categorical/+matlab/+internal/+coder/@categorical/categorical.m"// pathName 
};

static emlrtRSInfo ie_emlrtRSI = { 659,// lineNo
  "categorical/initData",              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/matlab/datatypes/codegen/categorical/+matlab/+internal/+coder/@categorical/categorical.m"// pathName 
};

static emlrtRTEInfo m_emlrtRTEI = { 115,// lineNo
  35,                                  // colNo
  "categorical/getCategoryNames",      // fName
  "/usr/local/MATLAB/R2020a/toolbox/matlab/datatypes/codegen/categorical/+matlab/+internal/+coder/@categorical/getCategoryNames.m"// pName 
};

static emlrtRTEInfo n_emlrtRTEI = { 114,// lineNo
  80,                                  // colNo
  "categorical/getCategoryNames",      // fName
  "/usr/local/MATLAB/R2020a/toolbox/matlab/datatypes/codegen/categorical/+matlab/+internal/+coder/@categorical/getCategoryNames.m"// pName 
};

static emlrtRTEInfo o_emlrtRTEI = { 20,// lineNo
  9,                                   // colNo
  "nonzeros",                          // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/sparfun/nonzeros.m"// pName
};

static emlrtRTEInfo p_emlrtRTEI = { 14,// lineNo
  1,                                   // colNo
  "nonzeros",                          // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/sparfun/nonzeros.m"// pName
};

static emlrtDCInfo b_emlrtDCI = { 15,  // lineNo
  58,                                  // colNo
  "nonzeros",                          // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/sparfun/nonzeros.m",// pName
  4                                    // checkKind
};

// Function Definitions
void DeepLearningNetwork_classify(const emlrtStack *sp, b_commandNet_0 *obj,
  const real_T indata[4900], real32_T scores[12])
{
  int32_T i;
  int32_T k;
  int32_T v_size_idx_0;
  int32_T b_j1;
  static const char_T classNames[120] = { 'd', 'g', 'l', 'n', 'o', 'o', 'r', 's',
    'u', 'y', 'u', 'b', 'o', 'o', 'e', 'o', 'f', 'n', 'i', 't', 'p', 'e', 'n',
    'a', 'w', '\x00', 'f', '\x00', 'f', '\x00', 'g', 'o', '\x00', 's', 'k', 'c',
    'n', '\x00', 't', '\x00', '\x00', '\x00', 'h', 'p', '\x00', '\x00', 'n', 'k',
    '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', 't', '\x00', '\x00', '\x00',
    'o', 'g', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',
    '\x00', '\x00', 'w', 'r', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',
    '\x00', '\x00', '\x00', '\x00', 'n', 'o', '\x00', '\x00', '\x00', '\x00',
    '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', 'u', '\x00', '\x00',
    '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', 'n',
    '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',
    '\x00', '\x00', 'd' };

  char_T s[10];
  static const boolean_T bv[128] = { false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  char_T v_data[10];
  emxArray_cell_wrap_0_1 tempValueSet;
  emxArray_cell_wrap_0_1 valueSet;
  static const char_T b_cv[9] = { '<', 'm', 'i', 's', 's', 'i', 'n', 'g', '>' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  DeepLearningNetwork_predict(obj, indata, scores);
  st.site = &fe_emlrtRSI;
  if (!muSingleScalarIsNaN(scores[0])) {
    i = 1;
  } else {
    boolean_T exitg1;
    i = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!muSingleScalarIsNaN(scores[k - 1])) {
        i = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (i == 0) {
    i = 1;
  } else {
    real32_T ex;
    ex = scores[i - 1];
    v_size_idx_0 = i + 1;
    for (k = v_size_idx_0; k < 13; k++) {
      real32_T f;
      f = scores[k - 1];
      if (ex < f) {
        ex = f;
        i = k;
      }
    }
  }

  b_st.site = &fe_emlrtRSI;
  b_j1 = 0;
  for (k = 0; k < 10; k++) {
    char_T c;
    c = classNames[(i + 12 * k) - 1];
    s[k] = c;
    if (c != 0) {
      b_j1++;
    }
  }

  if (b_j1 > 10) {
    emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  v_size_idx_0 = static_cast<int8_T>(b_j1);
  if (v_size_idx_0 < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(v_size_idx_0), &b_emlrtDCI,
      &b_st);
  }

  v_size_idx_0 = static_cast<int8_T>(b_j1);
  i = 0;
  for (k = 0; k < 10; k++) {
    if (s[k] != 0) {
      i++;
      if (i > b_j1) {
        emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
          "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
      }

      v_data[i - 1] = s[k];
    }
  }

  b_st.site = &fe_emlrtRSI;
  b_j1 = 0;
  while ((b_j1 + 1 <= v_size_idx_0) && bv[static_cast<int32_T>(v_data[b_j1])]) {
    b_j1++;
  }

  i = v_size_idx_0 - 1;
  while ((i + 1 > 0) && bv[static_cast<int32_T>(v_data[i])]) {
    i--;
  }

  if (b_j1 + 1 > i + 1) {
    b_j1 = 0;
    i = -1;
  }

  c_st.site = &he_emlrtRSI;
  tempValueSet.data[0].f1.size[0] = 1;
  i -= b_j1;
  tempValueSet.data[0].f1.size[1] = i + 1;
  for (v_size_idx_0 = 0; v_size_idx_0 <= i; v_size_idx_0++) {
    tempValueSet.data[0].f1.data[v_size_idx_0] = v_data[b_j1 + v_size_idx_0];
  }

  if (tempValueSet.data[0].f1.size[1] == 0) {
    valueSet.size[0] = 0;
  } else {
    valueSet.size[0] = 1;
    valueSet.data[0] = tempValueSet.data[0];
  }

  d_st.site = &ie_emlrtRSI;
  if (valueSet.size[0] != 0) {
    boolean_T bool_data_idx_0;
    boolean_T x;
    bool_data_idx_0 = false;
    if (9 == valueSet.data[0].f1.size[1]) {
      i = 0;
      int32_T exitg2;
      do {
        exitg2 = 0;
        if (i < 9) {
          if (b_cv[i] != valueSet.data[0].f1.data[i]) {
            exitg2 = 1;
          } else {
            i++;
          }
        } else {
          bool_data_idx_0 = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    x = bool_data_idx_0;
    if (x) {
      emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
        "MATLAB:categorical:UndefinedLabelCategoryName",
        "MATLAB:categorical:UndefinedLabelCategoryName", 3, 4, 9, "<missing>");
    }

    bool_data_idx_0 = (0 == valueSet.data[0].f1.size[1]);
    x = bool_data_idx_0;
    if (x) {
      emlrtErrorWithMessageIdR2018a(&d_st, &m_emlrtRTEI,
        "MATLAB:categorical:EmptyCategoryName",
        "MATLAB:categorical:EmptyCategoryName", 0);
    }
  }
}

// End of code generation (classify.cpp)
