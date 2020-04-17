//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  computeDFT.cpp
//
//  Code generation for function 'computeDFT'
//


// Include files
#include "computeDFT.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "circshift.h"
#include "computepsd.h"
#include "mtimes.h"
#include "psdfreqvec.h"
#include "pspectrogram.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo dc_emlrtRSI = { 45, // lineNo
  "computeDFT",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/computeDFT.m"// pathName 
};

static emlrtRSInfo ec_emlrtRSI = { 92, // lineNo
  "computeDFTviaFFT",                  // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/computeDFT.m"// pathName 
};

static emlrtRSInfo fc_emlrtRSI = { 91, // lineNo
  "computeDFTviaFFT",                  // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/computeDFT.m"// pathName 
};

static emlrtRSInfo gc_emlrtRSI = { 62, // lineNo
  "fft",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/fft.m"// pathName
};

static emlrtRSInfo hc_emlrtRSI = { 23, // lineNo
  "fft",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+fft/fft.m"// pathName 
};

static emlrtRSInfo ic_emlrtRSI = { 52, // lineNo
  "executeCallback",                   // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+fft/fft.m"// pathName 
};

static emlrtRSInfo jc_emlrtRSI = { 44, // lineNo
  "Custom1DFFTCallback/fft",           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/coder/coder/lib/+coder/+internal/Custom1DFFTCallback.m"// pathName 
};

static emlrtRSInfo kc_emlrtRSI = { 54, // lineNo
  "Custom1DFFTCallback/fftLoop",       // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/coder/coder/lib/+coder/+internal/Custom1DFFTCallback.m"// pathName 
};

static emlrtRTEInfo t_emlrtRTEI = { 88,// lineNo
  5,                                   // colNo
  "computeDFT",                        // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/computeDFT.m"// pName
};

static emlrtRTEInfo u_emlrtRTEI = { 54,// lineNo
  13,                                  // colNo
  "Custom1DFFTCallback",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/shared/coder/coder/lib/+coder/+internal/Custom1DFFTCallback.m"// pName 
};

// Function Definitions
void computeDFT(const emlrtStack *sp, const real_T xin[39200], coder::array<
                creal_T, 2U> &Xx, real_T f_data[], int32_T f_size[1])
{
  coder::array<real_T, 2U> xw;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &dc_emlrtRSI;
  xw.set_size((&t_emlrtRTEI), (&st), 400, 98);
  for (int32_T i = 0; i < 39200; i++) {
    xw[i] = xin[i];
  }

  b_st.site = &fc_emlrtRSI;
  c_st.site = &gc_emlrtRSI;
  d_st.site = &hc_emlrtRSI;
  e_st.site = &ic_emlrtRSI;
  f_st.site = &jc_emlrtRSI;
  g_st.site = &kc_emlrtRSI;
  emlrtFFTWSetNumThreads(4);
  Xx.set_size((&u_emlrtRTEI), (&g_st), 512, 98);
  emlrtFFTW_1D_R2C(&(xw.data())[0], (real_T *)&(Xx.data())[0], 1, 512, 400, 98,
                   -1);
  b_st.site = &ec_emlrtRSI;
  psdfreqvec(f_data, f_size);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (computeDFT.cpp)
