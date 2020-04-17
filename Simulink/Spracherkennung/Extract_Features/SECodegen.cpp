//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  SECodegen.cpp
//
//  Code generation for function 'SECodegen'
//


// Include files
#include "SECodegen.h"
#include "DeepLearningNetwork.h"
#include "SECodegen_data.h"
#include "classify.h"
#include "designAuditoryFilterBank.h"
#include "mtimes.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "spectrogram.h"
#include <string.h>

// Variable Definitions
static b_commandNet_0 trainedNet;
static boolean_T trainedNet_not_empty;
static emlrtRSInfo emlrtRSI = { 15,    // lineNo
  "SECodegen",                         // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m"// pathName 
};

static emlrtRSInfo b_emlrtRSI = { 22,  // lineNo
  "SECodegen",                         // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m"// pathName 
};

static emlrtRSInfo c_emlrtRSI = { 35,  // lineNo
  "SECodegen",                         // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m"// pathName 
};

static emlrtRSInfo d_emlrtRSI = { 43,  // lineNo
  "SECodegen",                         // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m"// pathName 
};

static emlrtRSInfo e_emlrtRSI = { 44,  // lineNo
  "SECodegen",                         // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m"// pathName 
};

static emlrtRSInfo f_emlrtRSI = { 50,  // lineNo
  "SECodegen",                         // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m"// pathName 
};

static emlrtRSInfo g_emlrtRSI = { 10,  // lineNo
  "SECodegen",                         // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m"// pathName 
};

static emlrtRSInfo h_emlrtRSI = { 69,  // lineNo
  "loadDeepLearningNetwork",           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/coder/coder/lib/+coder/loadDeepLearningNetwork.m"// pathName 
};

static emlrtRSInfo yd_emlrtRSI = { 79, // lineNo
  "eml_mtimes_helper",                 // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pathName 
};

static emlrtRSInfo ae_emlrtRSI = { 48, // lineNo
  "eml_mtimes_helper",                 // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pathName 
};

static emlrtRSInfo re_emlrtRSI = { 75, // lineNo
  "SECodegen/ftoBarks",                // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m"// pathName 
};

static emlrtRSInfo se_emlrtRSI = { 61, // lineNo
  "SECodegen/ptoPperfreq",             // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m"// pathName 
};

static emlrtRTEInfo emlrtRTEI = { 123, // lineNo
  23,                                  // colNo
  "dynamic_size_checks",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pName 
};

static emlrtRTEInfo b_emlrtRTEI = { 14,// lineNo
  9,                                   // colNo
  "log10",                             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/log10.m"// pName
};

static emlrtRTEInfo c_emlrtRTEI = { 14,// lineNo
  9,                                   // colNo
  "log",                               // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/log.m"// pName
};

static emlrtBCInfo emlrtBCI = { -1,    // iFirst
  -1,                                  // iLast
  75,                                  // lineNo
  28,                                  // colNo
  "f",                                 // aName
  "SECodegen/ftoBarks",                // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo b_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  75,                                  // lineNo
  42,                                  // colNo
  "f",                                 // aName
  "SECodegen/ftoBarks",                // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo c_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  75,                                  // lineNo
  5,                                   // colNo
  "z",                                 // aName
  "SECodegen/ftoBarks",                // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo d_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  61,                                  // lineNo
  31,                                  // colNo
  "f",                                 // aName
  "SECodegen/ptoPperfreq",             // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/SECodegen.m",// pName 
  0                                    // checkKind
};

// Function Definitions
void SECodegen(SECodegenStackData *SD, const emlrtStack *sp, const real_T y
               [16000], real32_T out[12])
{
  real_T CF2[50];
  b_commandNet_0 *iobj_0;
  coder::array<creal_T, 2U> unusedU0;
  real_T F_data[512];
  int32_T F_size[1];
  real_T T[98];
  coder::array<real_T, 2U> S;
  real_T SBark[4900];
  boolean_T p;
  int32_T k;
  real_T d;
  real_T x[4900];
  int32_T i;
  real_T b_x[4900];
  int32_T i1;
  int32_T f_size_idx_0;
  int32_T b_i;
  real_T f_data[512];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  //  Rate?
  if (!trainedNet_not_empty) {
    st.site = &g_emlrtRSI;
    iobj_0 = &trainedNet;
    b_st.site = &h_emlrtRSI;
    DeepLearningNetwork_setup(iobj_0);
    trainedNet_not_empty = true;

    //  beinhaltet trainedNet und wird hier in das Workspace geladen
    // load('left_test.mat')
  }

  st.site = &emlrtRSI;
  designAuditoryFilterBank(SD, &st, SD->f3.filterBank2, CF2);

  //   %% Compute spectrogram
  st.site = &b_emlrtRSI;
  spectrogram(SD, &st, y, unusedU0, F_data, F_size, T, S);

  //  Design auditory filter bank
  //    [filterBank,CF] = designAuditoryFilterBank(fs,'FFTLength',512,...
  //                        'NumBands',16,'Normalization','none');
  //  Visualize filter bank
  //    plot(F , filterBank2.')
  //    grid on
  //    title('Bark Filter Bank')
  //    xlabel('Frequency (Hz)')
  //  Compute mel spectrogram
  st.site = &c_emlrtRSI;
  b_st.site = &ae_emlrtRSI;
  if (257 != S.size(0)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI, "MATLAB:innerdim",
      "MATLAB:innerdim", 0);
  }

  b_st.site = &yd_emlrtRSI;
  mtimes(SD->f3.filterBank2, S, SBark);

  //  Take the log.
  st.site = &d_emlrtRSI;
  p = false;
  for (k = 0; k < 4900; k++) {
    d = SBark[k] / 4.9999999999999982E-5 + 1.0E-6;
    x[k] = d;
    if (p || (d < 0.0)) {
      p = true;
    }
  }

  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      5, "log10");
  }

  for (k = 0; k < 4900; k++) {
    x[k] = muDoubleScalarLog10(x[k]);
  }

  for (i = 0; i < 50; i++) {
    for (i1 = 0; i1 < 98; i1++) {
      b_x[i1 + 98 * i] = x[i + 50 * i1];
    }
  }

  st.site = &e_emlrtRSI;
  DeepLearningNetwork_classify(&st, &trainedNet, b_x, out);
  st.site = &f_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  f_size_idx_0 = F_size[0];
  i = F_size[0];
  for (b_i = 0; b_i < i; b_i++) {
    real_T a;
    c_st.site = &re_emlrtRSI;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > F_size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, F_size[0], &b_emlrtBCI, &c_st);
    }

    d = F_data[i1 - 1];
    a = d / 7500.0;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > F_size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, F_size[0], &emlrtBCI, &b_st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > f_size_idx_0)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, f_size_idx_0, &c_emlrtBCI, &b_st);
    }

    f_data[i1 - 1] = 13.0 * muDoubleScalarAtan(0.00076 * d) + 3.5 *
      muDoubleScalarAtan(a * a);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&b_st);
    }
  }

  for (b_i = 0; b_i < 50; b_i++) {
    i = b_i + 1;
    for (k = 0; k < 98; k++) {
      b_st.site = &se_emlrtRSI;
      i1 = b_i + 50 * k;
      if (SBark[i1] < 0.0) {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      if (i > f_size_idx_0) {
        emlrtDynamicBoundsCheckR2012b(i, 1, f_size_idx_0, &d_emlrtBCI, &st);
      }

      SBark[i1] = 20.0 * muDoubleScalarLog(SBark[i1]) / f_data[i - 1];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void SECodegen_init()
{
  trainedNet_not_empty = false;
}

// End of code generation (SECodegen.cpp)
