//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  spectrogram.cpp
//
//  Code generation for function 'spectrogram'
//


// Include files
#include "spectrogram.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "SECodegen_data.h"
#include "circshift.h"
#include "computeDFT.h"
#include "getSTFTColumns.h"
#include "mwmathutil.h"
#include "psdfreqvec.h"
#include "pspectrogram.h"
#include "rt_nonfinite.h"
#include "welchparse.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo q_emlrtRSI = { 191, // lineNo
  "spectrogram",                       // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/spectrogram.m"// pathName
};

static emlrtRSInfo r_emlrtRSI = { 30,  // lineNo
  "pspectrogram",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pathName 
};

static emlrtRSInfo s_emlrtRSI = { 59,  // lineNo
  "pspectrogram",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pathName 
};

static emlrtRSInfo t_emlrtRSI = { 67,  // lineNo
  "pspectrogram",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pathName 
};

static emlrtRSInfo u_emlrtRSI = { 71,  // lineNo
  "pspectrogram",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pathName 
};

static emlrtRSInfo v_emlrtRSI = { 78,  // lineNo
  "pspectrogram",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pathName 
};

static emlrtRSInfo w_emlrtRSI = { 30,  // lineNo
  "welchparse",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/welchparse.m"// pathName 
};

static emlrtRSInfo x_emlrtRSI = { 37,  // lineNo
  "welchparse",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/welchparse.m"// pathName 
};

static emlrtRSInfo y_emlrtRSI = { 94,  // lineNo
  "parse_inputs",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/welchparse.m"// pathName 
};

static emlrtRSInfo ab_emlrtRSI = { 76, // lineNo
  "validateattributes",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/lang/validateattributes.m"// pathName 
};

static emlrtRSInfo rc_emlrtRSI = { 338,// lineNo
  "formatSpectrogram",                 // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pathName 
};

static emlrtRTEInfo g_emlrtRTEI = { 14,// lineNo
  37,                                  // colNo
  "validatefinite",                    // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+valattr/validatefinite.m"// pName 
};

static emlrtRTEInfo h_emlrtRTEI = { 14,// lineNo
  37,                                  // colNo
  "validatenonnan",                    // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+valattr/validatenonnan.m"// pName 
};

static emlrtRTEInfo r_emlrtRTEI = { 351,// lineNo
  5,                                   // colNo
  "pspectrogram",                      // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pName 
};

static emlrtRTEInfo s_emlrtRTEI = { 339,// lineNo
  5,                                   // colNo
  "pspectrogram",                      // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/pspectrogram.m"// pName 
};

// Function Definitions
void spectrogram(SECodegenStackData *SD, const emlrtStack *sp, const real_T x
                 [16000], coder::array<creal_T, 2U> &varargout_1, real_T
                 varargout_2_data[], int32_T varargout_2_size[1], real_T
                 varargout_3[98], coder::array<real_T, 2U> &varargout_4)
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  char_T options_range[8];
  int32_T c_tmp;
  static const char_T b_cv[8] = { 't', 'w', 'o', 's', 'i', 'd', 'e', 'd' };

  coder::array<creal_T, 2U> b_y1;
  boolean_T b_bool;
  static const char_T cv1[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd' };

  real_T tmp_data[257];
  int32_T tmp_size[1];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  memcpy(&SD->f2.r.f1[0], &x[0], 16000U * sizeof(real_T));
  st.site = &q_emlrtRSI;
  b_st.site = &r_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  d_st.site = &y_emlrtRSI;
  e_st.site = &ab_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 16000)) {
    if ((!muDoubleScalarIsInf(SD->f2.r.f1[k])) && (!muDoubleScalarIsNaN
         (SD->f2.r.f1[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&e_st, &g_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:pwelch:expectedFinite", 3, 4, 1, "x");
  }

  e_st.site = &ab_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 16000)) {
    if (!muDoubleScalarIsNaN(SD->f2.r.f1[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&e_st, &h_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:pwelch:expectedNonNaN", 3, 4, 1, "x");
  }

  c_st.site = &x_emlrtRSI;
  welch_options(&c_st, &p, options_range);
  if (p) {
    for (c_tmp = 0; c_tmp < 8; c_tmp++) {
      options_range[c_tmp] = b_cv[c_tmp];
    }
  }

  getSTFTColumns(SD, SD->f2.r.f1, SD->f2.xin, varargout_3);
  for (k = 0; k < 98; k++) {
    for (int32_T b_k = 0; b_k < 400; b_k++) {
      c_tmp = b_k + 400 * k;
      SD->f2.c[c_tmp] = dv[b_k] * SD->f2.xin[c_tmp];
    }
  }

  b_st.site = &s_emlrtRSI;
  computeDFT(&b_st, SD->f2.c, b_y1, varargout_2_data, varargout_2_size);
  b_st.site = &t_emlrtRSI;
  b_bool = false;
  c_tmp = 0;
  int32_T exitg2;
  do {
    exitg2 = 0;
    if (c_tmp < 8) {
      if (cv[static_cast<uint8_T>(options_range[c_tmp])] != cv
          [static_cast<int32_T>(cv1[c_tmp])]) {
        exitg2 = 1;
      } else {
        c_tmp++;
      }
    } else {
      b_bool = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_bool) {
    c_st.site = &rc_emlrtRSI;
    b_psdfreqvec(tmp_data, tmp_size);
    varargout_2_size[0] = 257;
    memcpy(&varargout_2_data[0], &tmp_data[0], 257U * sizeof(real_T));
    varargout_1.set_size((&s_emlrtRTEI), (&b_st), 257, 98);
    for (c_tmp = 0; c_tmp < 98; c_tmp++) {
      for (k = 0; k < 257; k++) {
        varargout_1[k + varargout_1.size(0) * c_tmp] = b_y1[k + 512 * c_tmp];
      }
    }
  } else {
    varargout_1.set_size((&r_emlrtRTEI), (&b_st), 512, 98);
    for (c_tmp = 0; c_tmp < 50176; c_tmp++) {
      varargout_1[c_tmp] = b_y1[c_tmp];
    }
  }

  b_st.site = &u_emlrtRSI;
  compute_PSD(&b_st, varargout_1, varargout_2_data, varargout_2_size,
              options_range, varargout_4);
  if (p) {
    b_st.site = &v_emlrtRSI;
    centerOutputs(&b_st, varargout_1, varargout_2_data, varargout_2_size,
                  varargout_4);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (spectrogram.cpp)
