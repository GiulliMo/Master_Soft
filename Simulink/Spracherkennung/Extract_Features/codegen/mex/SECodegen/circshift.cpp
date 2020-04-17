//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  circshift.cpp
//
//  Code generation for function 'circshift'
//


// Include files
#include "circshift.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "eml_int_forloop_overflow_check.h"
#include "mtimes.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo p_emlrtRSI = { 21,  // lineNo
  "eml_int_forloop_overflow_check",    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"// pathName 
};

static emlrtRSInfo id_emlrtRSI = { 42, // lineNo
  "circshift",                         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pathName 
};

static emlrtRSInfo jd_emlrtRSI = { 69, // lineNo
  "circshift_single_dim",              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pathName 
};

static emlrtRSInfo kd_emlrtRSI = { 66, // lineNo
  "circshift_single_dim",              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pathName 
};

static emlrtRSInfo ld_emlrtRSI = { 53, // lineNo
  "circshift_single_dim",              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pathName 
};

static emlrtRSInfo md_emlrtRSI = { 50, // lineNo
  "prodsize",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/coder/coder/+coder/+internal/prodsize.m"// pathName 
};

static emlrtRSInfo nd_emlrtRSI = { 133,// lineNo
  "circshift_core",                    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pathName 
};

static emlrtRSInfo od_emlrtRSI = { 129,// lineNo
  "circshift_core",                    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pathName 
};

static emlrtRSInfo pd_emlrtRSI = { 125,// lineNo
  "circshift_core",                    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pathName 
};

static emlrtRSInfo qd_emlrtRSI = { 120,// lineNo
  "circshift_core",                    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pathName 
};

static emlrtRSInfo rd_emlrtRSI = { 112,// lineNo
  "circshift_core",                    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pathName 
};

static emlrtRSInfo sd_emlrtRSI = { 108,// lineNo
  "circshift_core",                    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pathName 
};

static emlrtRSInfo td_emlrtRSI = { 106,// lineNo
  "circshift_core",                    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pathName 
};

static emlrtRTEInfo q_emlrtRTEI = { 31,// lineNo
  48,                                  // colNo
  "circshift",                         // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/circshift.m"// pName
};

static emlrtRSInfo te_emlrtRSI = { 133,// lineNo
  "eml_scalar_rdivide",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/idivide.m"// pathName
};

// Function Declarations
static int32_T _s32_u32_(const emlrtStack *sp, uint32_T b);
static int32_T divv_s32_sat(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);

// Function Definitions
static int32_T _s32_u32_(const emlrtStack *sp, uint32_T b)
{
  int32_T a;
  a = static_cast<int32_T>(b);
  if (a < 0) {
    emlrtIntegerOverflowErrorR2012b(NULL, sp);
  }

  return a;
}

static int32_T divv_s32_sat(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T b_numerator;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
    boolean_T quotientNeedsNegation;
    uint32_T b_denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    if (numerator < 0) {
      b_numerator = ~static_cast<uint32_T>(numerator) + 1U;
    } else {
      b_numerator = static_cast<uint32_T>(numerator);
    }

    if (denominator < 0) {
      b_denominator = ~static_cast<uint32_T>(denominator) + 1U;
    } else {
      b_denominator = static_cast<uint32_T>(denominator);
    }

    b_numerator /= b_denominator;
    if ((!quotientNeedsNegation) && (b_numerator >= 2147483647U)) {
      quotient = MAX_int32_T;
    } else if (quotientNeedsNegation && (b_numerator > 2147483647U)) {
      quotient = MIN_int32_T;
    } else if (quotientNeedsNegation) {
      quotient = -static_cast<int32_T>(b_numerator);
    } else {
      quotient = _s32_u32_(sp, b_numerator);
    }
  }

  return quotient;
}

void b_circshift(const emlrtStack *sp, coder::array<real_T, 2U> &a, real_T p)
{
  int32_T ns;
  boolean_T shiftright;
  int32_T i;
  int32_T loop_ub;
  real_T buffer_data[256];
  int32_T nv;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  ns = static_cast<int32_T>(p);
  if (ns != p) {
    emlrtErrorWithMessageIdR2018a(sp, &q_emlrtRTEI,
      "Coder:toolbox:circshift_InvalidShiftType",
      "Coder:toolbox:circshift_InvalidShiftType", 6, 4, 5, "int32", 4, 5,
      "int32");
  }

  st.site = &id_emlrtRSI;
  shiftright = true;
  if (ns > a.size(0)) {
    b_st.site = &te_emlrtRSI;
    ns -= divv_s32_sat(&b_st, ns, a.size(0)) * a.size(0);
  }

  if (ns > (a.size(0) >> 1)) {
    ns = a.size(0) - ns;
    shiftright = false;
  }

  if (a.size(0) == 0) {
    i = 0;
  } else {
    i = a.size(0);
    i = muIntScalarMax_sint32(i, 98);
  }

  loop_ub = static_cast<int16_T>(muDoubleScalarFloor(static_cast<real_T>(i) /
    2.0));
  if (0 <= loop_ub - 1) {
    memset(&buffer_data[0], 0, loop_ub * sizeof(real_T));
  }

  i = a.size(0) + 1;
  nv = a.size(0);
  if (ns > 0) {
    for (int32_T b_i = 0; b_i < 98; b_i++) {
      int32_T pageroot;
      pageroot = b_i * (i - 1) - 1;
      if (shiftright) {
        int32_T k;
        int32_T i1;
        for (k = 0; k < ns; k++) {
          buffer_data[k] = a[((pageroot + k) + i) - ns];
        }

        i1 = ns + 1;
        for (k = nv; k >= i1; k--) {
          loop_ub = pageroot + k;
          a[loop_ub] = a[loop_ub - ns];
        }

        for (k = 0; k < ns; k++) {
          a[(pageroot + k) + 1] = buffer_data[k];
        }
      } else {
        int32_T k;
        for (k = 0; k < ns; k++) {
          buffer_data[k] = a[(pageroot + k) + 1];
        }

        loop_ub = i - ns;
        for (k = 0; k <= loop_ub - 2; k++) {
          int32_T i1;
          i1 = pageroot + k;
          a[i1 + 1] = a[(i1 + ns) + 1];
        }

        for (k = 0; k < ns; k++) {
          a[((pageroot + k) + i) - ns] = buffer_data[k];
        }
      }
    }
  }
}

void circshift(const emlrtStack *sp, coder::array<creal_T, 2U> &a, real_T p)
{
  int32_T ns;
  boolean_T shiftright;
  int32_T i;
  int32_T loop_ub;
  creal_T buffer_data[256];
  int32_T nv;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  ns = static_cast<int32_T>(p);
  if (ns != p) {
    emlrtErrorWithMessageIdR2018a(sp, &q_emlrtRTEI,
      "Coder:toolbox:circshift_InvalidShiftType",
      "Coder:toolbox:circshift_InvalidShiftType", 6, 4, 5, "int32", 4, 5,
      "int32");
  }

  st.site = &id_emlrtRSI;
  b_st.site = &ld_emlrtRSI;
  shiftright = true;
  if (ns > (a.size(0) >> 1)) {
    ns = a.size(0) - ns;
    shiftright = false;
  }

  if (a.size(0) == 0) {
    i = 0;
  } else {
    i = a.size(0);
    i = muIntScalarMax_sint32(i, 98);
  }

  loop_ub = static_cast<int16_T>(muDoubleScalarFloor(static_cast<real_T>(i) /
    2.0));
  if (0 <= loop_ub - 1) {
    memset(&buffer_data[0], 0, loop_ub * sizeof(creal_T));
  }

  i = a.size(0);
  nv = a.size(0);
  b_st.site = &kd_emlrtRSI;
  c_st.site = &md_emlrtRSI;
  b_st.site = &jd_emlrtRSI;
  c_st.site = &td_emlrtRSI;
  for (int32_T b_i = 0; b_i < 98; b_i++) {
    int32_T pageroot;
    pageroot = b_i * i;
    c_st.site = &sd_emlrtRSI;
    if (shiftright) {
      int32_T k;
      int32_T i1;
      c_st.site = &rd_emlrtRSI;
      if ((1 <= ns) && (ns > 2147483646)) {
        d_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 0; k < ns; k++) {
        buffer_data[k] = a[((pageroot + k) + i) - ns];
      }

      i1 = ns + 1;
      for (k = nv; k >= i1; k--) {
        loop_ub = pageroot + k;
        a[loop_ub - 1] = a[(loop_ub - ns) - 1];
      }

      c_st.site = &qd_emlrtRSI;
      for (k = 0; k < ns; k++) {
        a[pageroot + k] = buffer_data[k];
      }
    } else {
      int32_T k;
      c_st.site = &pd_emlrtRSI;
      if ((1 <= ns) && (ns > 2147483646)) {
        d_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 0; k < ns; k++) {
        buffer_data[k] = a[pageroot + k];
      }

      loop_ub = i - ns;
      c_st.site = &od_emlrtRSI;
      if ((1 <= loop_ub) && (loop_ub > 2147483646)) {
        d_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 0; k < loop_ub; k++) {
        int32_T i1;
        i1 = (pageroot + k) + 1;
        a[i1 - 1] = a[(i1 + ns) - 1];
      }

      c_st.site = &nd_emlrtRSI;
      for (k = 0; k < ns; k++) {
        a[((pageroot + k) + i) - ns] = buffer_data[k];
      }
    }
  }
}

// End of code generation (circshift.cpp)
