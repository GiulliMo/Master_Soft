//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  designMelFilterBank.cpp
//
//  Code generation for function 'designMelFilterBank'
//


// Include files
#include "designMelFilterBank.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo n_emlrtRSI = { 101, // lineNo
  "designMelFilterBank",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m"// pathName 
};

static emlrtRTEInfo d_emlrtRTEI = { 76,// lineNo
  5,                                   // colNo
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m"// pName 
};

static emlrtRTEInfo e_emlrtRTEI = { 92,// lineNo
  13,                                  // colNo
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m"// pName 
};

static emlrtBCInfo e_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  95,                                  // lineNo
  22,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo f_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  95,                                  // lineNo
  27,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo g_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  99,                                  // lineNo
  49,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo h_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  99,                                  // lineNo
  62,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo i_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  101,                                 // lineNo
  45,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo j_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  101,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo k_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  101,                                 // lineNo
  83,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo l_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  101,                                 // lineNo
  96,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo m_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  94,                                  // lineNo
  22,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo n_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  94,                                  // lineNo
  27,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo b_emlrtECI = { -1,  // nDims
  94,                                  // lineNo
  9,                                   // colNo
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m"// pName 
};

static emlrtBCInfo o_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  98,                                  // lineNo
  22,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo p_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  98,                                  // lineNo
  35,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo c_emlrtECI = { -1,  // nDims
  98,                                  // lineNo
  9,                                   // colNo
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m"// pName 
};

static emlrtDCInfo emlrtDCI = { 77,    // lineNo
  31,                                  // colNo
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  4                                    // checkKind
};

static emlrtBCInfo q_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  83,                                  // lineNo
  17,                                  // colNo
  "",                                  // aName
  "designMelFilterBank",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m",// pName 
  0                                    // checkKind
};

// Function Definitions
void designMelFilterBank(const emlrtStack *sp, const real_T bandEdges[52],
  real_T filterBank[25600], real_T centerFrequencies[50], boolean_T
  *FFTLengthTooSmall)
{
  int32_T i;
  int32_T nz;
  boolean_T x[52];
  int32_T k;
  int32_T iyLead;
  int32_T ixLead;
  real_T work;
  int32_T m;
  real_T bw[51];
  int16_T p_data[52];
  int32_T tmp_size[2];
  real_T tmp_data[511];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i = 0; i < 52; i++) {
    x[i] = (bandEdges[i] - 8000.0 < 1.4901161193847656E-8);
  }

  nz = x[0];
  for (k = 0; k < 51; k++) {
    nz += x[k + 1];
  }

  memset(&filterBank[0], 0, 25600U * sizeof(real_T));
  memcpy(&centerFrequencies[0], &bandEdges[1], 50U * sizeof(real_T));
  *FFTLengthTooSmall = false;
  if (nz > 52) {
    emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (nz < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(nz), &emlrtDCI, sp);
  }

  for (iyLead = 0; iyLead < nz; iyLead++) {
    boolean_T exitg1;
    ixLead = 0;
    exitg1 = false;
    while ((!exitg1) && (ixLead < 512)) {
      if (31.25 * static_cast<real_T>(ixLead) > bandEdges[iyLead]) {
        i = static_cast<int32_T>(iyLead + 1U);
        if (i > nz) {
          emlrtDynamicBoundsCheckR2012b(i, 1, nz, &q_emlrtBCI, sp);
        }

        p_data[i - 1] = static_cast<int16_T>(ixLead + 1);
        exitg1 = true;
      } else {
        ixLead++;
      }
    }
  }

  ixLead = 1;
  iyLead = 0;
  work = bandEdges[0];
  for (m = 0; m < 51; m++) {
    real_T tmp2;
    tmp2 = work;
    work = bandEdges[ixLead];
    bw[iyLead] = bandEdges[ixLead] - tmp2;
    ixLead++;
    iyLead++;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, static_cast<real_T>(nz) - 2.0,
    mxDOUBLE_CLASS, nz - 2, &e_emlrtRTEI, sp);
  for (k = 0; k <= nz - 3; k++) {
    int32_T i1;
    int32_T i2;
    int32_T i3;
    int32_T i4;
    int32_T i5;
    int32_T i6;
    i = k + 1;
    if (i > nz) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nz, &e_emlrtBCI, sp);
    }

    i = k + 2;
    if (i > nz) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nz, &f_emlrtBCI, sp);
    }

    i1 = p_data[k + 1];
    ixLead = i1 - 1;
    if (p_data[k] > ixLead) {
      i2 = 0;
      i3 = 0;
    } else {
      i2 = p_data[k] - 1;
      i3 = ixLead;
    }

    i4 = k + 1;
    if (i4 > nz) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, nz, &m_emlrtBCI, sp);
    }

    if (i > nz) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nz, &n_emlrtBCI, sp);
    }

    if (p_data[k] > ixLead) {
      i4 = 0;
      i5 = 0;
    } else {
      i4 = p_data[k] - 1;
      i5 = ixLead;
    }

    tmp_size[0] = 1;
    iyLead = i3 - i2;
    tmp_size[1] = iyLead;
    for (i3 = 0; i3 < iyLead; i3++) {
      tmp_data[i3] = (31.25 * static_cast<real_T>(i2 + i3) - bandEdges[k]) /
        bw[k];
    }

    iyLead = i5 - i4;
    emlrtSubAssignSizeCheckR2012b(&iyLead, 1, &tmp_size[0], 2, &b_emlrtECI, sp);
    for (i2 = 0; i2 < iyLead; i2++) {
      filterBank[(i4 + i2) + (k << 9)] = tmp_data[i2];
    }

    if (i > nz) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nz, &g_emlrtBCI, sp);
    }

    i2 = k + 3;
    if (i2 > nz) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nz, &h_emlrtBCI, sp);
    }

    i3 = p_data[k + 2] - 1;
    if (i1 > i3) {
      i4 = 0;
      i5 = 0;
    } else {
      i4 = ixLead;
      i5 = i3;
    }

    if (i > nz) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nz, &o_emlrtBCI, sp);
    }

    if (i2 > nz) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nz, &p_emlrtBCI, sp);
    }

    if (i1 > i3) {
      m = 0;
      i6 = 0;
    } else {
      m = ixLead;
      i6 = i3;
    }

    tmp_size[0] = 1;
    iyLead = i5 - i4;
    tmp_size[1] = iyLead;
    for (i5 = 0; i5 < iyLead; i5++) {
      tmp_data[i5] = (bandEdges[k + 2] - 31.25 * static_cast<real_T>(i4 + i5)) /
        bw[k + 1];
    }

    iyLead = i6 - m;
    emlrtSubAssignSizeCheckR2012b(&iyLead, 1, &tmp_size[0], 2, &c_emlrtECI, sp);
    for (i4 = 0; i4 < iyLead; i4++) {
      filterBank[(m + i4) + (k << 9)] = tmp_data[i4];
    }

    if (!*FFTLengthTooSmall) {
      st.site = &n_emlrtRSI;
      i4 = k + 1;
      if (i4 > nz) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, nz, &i_emlrtBCI, &st);
      }

      if (i > nz) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nz, &j_emlrtBCI, &st);
      }

      if (ixLead < p_data[k]) {
        ixLead = 0;
      } else {
        ixLead = (ixLead - p_data[k]) + 1;
      }

      if (ixLead == 0) {
        *FFTLengthTooSmall = true;
      } else {
        st.site = &n_emlrtRSI;
        if (i > nz) {
          emlrtDynamicBoundsCheckR2012b(i, 1, nz, &k_emlrtBCI, &st);
        }

        if (i2 > nz) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, nz, &l_emlrtBCI, &st);
        }

        if (i3 < i1) {
          ixLead = 0;
        } else {
          ixLead = (i3 - i1) + 1;
        }

        if (ixLead == 0) {
          *FFTLengthTooSmall = true;
        }
      }
    }
  }
}

// End of code generation (designMelFilterBank.cpp)
