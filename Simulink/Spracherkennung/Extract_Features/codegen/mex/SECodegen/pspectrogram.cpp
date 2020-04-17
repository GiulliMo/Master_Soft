//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  pspectrogram.cpp
//
//  Code generation for function 'pspectrogram'
//


// Include files
#include "pspectrogram.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "SECodegen_data.h"
#include "circshift.h"
#include "computepsd.h"
#include "iseven.h"
#include "mtimes.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo tc_emlrtRSI = { 218,// lineNo
  "compute_PSD",                       // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pathName 
};

static emlrtRSInfo ad_emlrtRSI = { 231,// lineNo
  "centerOutputs",                     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pathName 
};

static emlrtRSInfo bd_emlrtRSI = { 235,// lineNo
  "centerOutputs",                     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pathName 
};

static emlrtRSInfo cd_emlrtRSI = { 239,// lineNo
  "centerOutputs",                     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pathName 
};

static emlrtRSInfo dd_emlrtRSI = { 11, // lineNo
  "centerest",                         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/centerest.m"// pathName 
};

static emlrtRSInfo ed_emlrtRSI = { 13, // lineNo
  "centerest",                         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/centerest.m"// pathName 
};

static emlrtRSInfo xd_emlrtRSI = { 11, // lineNo
  "centerfreq",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/centerfreq.m"// pathName 
};

static emlrtECInfo e_emlrtECI = { 2,   // nDims
  207,                                 // lineNo
  12,                                  // colNo
  "compute_PSD",                       // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pName 
};

static emlrtDCInfo c_emlrtDCI = { 13,  // lineNo
  11,                                  // colNo
  "centerfreq",                        // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/centerfreq.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo s_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  13,                                  // lineNo
  11,                                  // colNo
  "",                                  // aName
  "centerfreq",                        // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/centerfreq.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo d_emlrtDCI = { 16,  // lineNo
  11,                                  // colNo
  "centerfreq",                        // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/centerfreq.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo t_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  16,                                  // lineNo
  11,                                  // colNo
  "",                                  // aName
  "centerfreq",                        // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/centerfreq.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo ab_emlrtRTEI = { 207,// lineNo
  15,                                  // colNo
  "pspectrogram",                      // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pName 
};

static emlrtRTEInfo bb_emlrtRTEI = { 207,// lineNo
  7,                                   // colNo
  "pspectrogram",                      // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pName 
};

// Function Definitions
void centerOutputs(const emlrtStack *sp, coder::array<creal_T, 2U> &y, real_T
                   f_data[], const int32_T f_size[1], coder::array<real_T, 2U>
                   &Pxx)
{
  int32_T vlend2;
  int32_T vspread;
  int32_T i2;
  real_T xtmp_re;
  int32_T i;
  int32_T i1;
  int32_T ia;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ad_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &dd_emlrtRSI;
  if (iseven(&b_st, static_cast<real_T>(y.size(0)))) {
    b_st.site = &ed_emlrtRSI;
    circshift(&b_st, y, static_cast<real_T>(y.size(0)) / 2.0 - 1.0);
  } else {
    vlend2 = y.size(0) / 2 - 1;
    vspread = y.size(0);
    if ((vlend2 + 1) << 1 == y.size(0)) {
      i2 = 1;
      for (i = 0; i < 98; i++) {
        i1 = i2;
        i2 += vspread;
        ia = i1 - 1;
        i1 += vlend2;
        for (k = 0; k <= vlend2; k++) {
          real_T xtmp_im;
          xtmp_re = y[ia].re;
          xtmp_im = y[ia].im;
          y[ia] = y[i1];
          y[i1].re = xtmp_re;
          y[i1].im = xtmp_im;
          ia++;
          i1++;
        }
      }
    } else {
      i2 = 1;
      for (i = 0; i < 98; i++) {
        real_T xtmp_im;
        i1 = i2;
        i2 += vspread;
        ia = i1 - 1;
        i1 += vlend2;
        xtmp_re = y[i1].re;
        xtmp_im = y[i1].im;
        for (k = 0; k <= vlend2; k++) {
          y[i1] = y[ia];
          y[ia] = y[i1 + 1];
          ia++;
          i1++;
        }

        y[i1].re = xtmp_re;
        y[i1].im = xtmp_im;
      }
    }
  }

  st.site = &bd_emlrtRSI;
  b_st.site = &xd_emlrtRSI;
  if (iseven(&b_st, static_cast<real_T>(f_size[0]))) {
    xtmp_re = static_cast<real_T>(f_size[0]) / 2.0;
    if (xtmp_re != muDoubleScalarFloor(xtmp_re)) {
      emlrtIntegerCheckR2012b(xtmp_re, &c_emlrtDCI, &st);
    }

    vlend2 = f_size[0];
    i1 = static_cast<int32_T>(xtmp_re);
    if ((i1 < 1) || (i1 > vlend2)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, vlend2, &s_emlrtBCI, &st);
    }

    xtmp_re = f_data[i1 - 1];
    i1 = f_size[0];
    for (vlend2 = 0; vlend2 < i1; vlend2++) {
      f_data[vlend2] -= xtmp_re;
    }
  } else {
    xtmp_re = (static_cast<real_T>(f_size[0]) + 1.0) / 2.0;
    if (xtmp_re != muDoubleScalarFloor(xtmp_re)) {
      emlrtIntegerCheckR2012b(xtmp_re, &d_emlrtDCI, &st);
    }

    vlend2 = f_size[0];
    i1 = static_cast<int32_T>(xtmp_re);
    if ((i1 < 1) || (i1 > vlend2)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, vlend2, &t_emlrtBCI, &st);
    }

    xtmp_re = f_data[i1 - 1];
    i1 = f_size[0];
    for (vlend2 = 0; vlend2 < i1; vlend2++) {
      f_data[vlend2] -= xtmp_re;
    }
  }

  st.site = &cd_emlrtRSI;
  b_st.site = &dd_emlrtRSI;
  if (iseven(&b_st, static_cast<real_T>(Pxx.size(0)))) {
    b_st.site = &ed_emlrtRSI;
    b_circshift(&b_st, Pxx, static_cast<real_T>(Pxx.size(0)) / 2.0 - 1.0);
  } else {
    vlend2 = Pxx.size(0) / 2 - 1;
    vspread = Pxx.size(0);
    if ((vlend2 + 1) << 1 == Pxx.size(0)) {
      i2 = 1;
      for (i = 0; i < 98; i++) {
        i1 = i2;
        i2 += vspread;
        ia = i1 - 1;
        i1 += vlend2;
        for (k = 0; k <= vlend2; k++) {
          xtmp_re = Pxx[ia];
          Pxx[ia] = Pxx[i1];
          Pxx[i1] = xtmp_re;
          ia++;
          i1++;
        }
      }
    } else {
      i2 = 1;
      for (i = 0; i < 98; i++) {
        i1 = i2;
        i2 += vspread;
        ia = i1 - 1;
        i1 += vlend2;
        xtmp_re = Pxx[i1];
        for (k = 0; k <= vlend2; k++) {
          Pxx[i1] = Pxx[ia];
          Pxx[ia] = Pxx[i1 + 1];
          ia++;
          i1++;
        }

        Pxx[i1] = xtmp_re;
      }
    }
  }
}

void compute_PSD(const emlrtStack *sp, const coder::array<creal_T, 2U> &y,
                 real_T f_data[], int32_T f_size[1], const char_T options_range
                 [8], coder::array<real_T, 2U> &Pxx)
{
  real_T d;
  int32_T i;
  coder::array<creal_T, 2U> r;
  int32_T loop_ub;
  coder::array<real_T, 2U> b_y;
  int32_T b_f_size[1];
  real_T b_f_data[512];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  d = 0.0;
  for (i = 0; i < 400; i++) {
    d += dv[i] * dv[i];
  }

  r.set_size((&ab_emlrtRTEI), sp, y.size(0), 98);
  loop_ub = y.size(0) * y.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i].re = y[i].re;
    r[i].im = -y[i].im;
  }

  emlrtSizeEqCheckNDR2012b(((coder::array<creal_T, 2U> *)&y)->size(), r.size(),
    &e_emlrtECI, sp);
  b_y.set_size((&bb_emlrtRTEI), sp, y.size(0), 98);
  loop_ub = y.size(0) * y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_y[i] = (y[i].re * r[i].re - y[i].im * r[i].im) / d;
  }

  b_f_size[0] = f_size[0];
  loop_ub = f_size[0] - 1;
  if (0 <= loop_ub) {
    memcpy(&b_f_data[0], &f_data[0], (loop_ub + 1) * sizeof(real_T));
  }

  st.site = &tc_emlrtRSI;
  computepsd(&st, b_y, b_f_data, b_f_size, options_range, Pxx, f_data, f_size);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (pspectrogram.cpp)
