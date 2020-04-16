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
#include "AsyncBuffercg.h"
#include "AsyncBuffercgHelper.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"
#include <string.h>

// Type Definitions
struct cell_4
{
  char_T f1[4];
  char_T f2[2];
  char_T f3[4];
  char_T f4[2];
  char_T f5[3];
  char_T f6[2];
  char_T f7[5];
  char_T f8[4];
  char_T f9[2];
  char_T f10[3];
  char_T f11[7];
  char_T f12[10];
};

struct c_matlab_internal_coder_categor
{
  uint8_T codes[12];
  cell_4 categoryNames;
  boolean_T isProtected;
  boolean_T isOrdinal;
};

struct struct_T
{
  c_matlab_internal_coder_categor labels;
};

// Variable Definitions
static emlrtRTEInfo emlrtRTEI = { 12,  // lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo b_emlrtRTEI = { 18,// lineNo
  9,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo c_emlrtRTEI = { 20,// lineNo
  5,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRSInfo emlrtRSI = { 6,     // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtRSInfo b_emlrtRSI = { 7,   // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtRSInfo c_emlrtRSI = { 16,  // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtRSInfo d_emlrtRSI = { 17,  // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtRSInfo e_emlrtRSI = { 18,  // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtRSInfo f_emlrtRSI = { 21,  // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtRSInfo g_emlrtRSI = { 1,   // lineNo
  "audioDeviceReader/releaseImpl",     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/compiled/audioDeviceReader.p"// pathName 
};

static emlrtRSInfo h_emlrtRSI = { 1,   // lineNo
  "audioDeviceReader/get.SamplesPerFrame",// fcnName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/compiled/audioDeviceReader.p"// pathName 
};

static emlrtRSInfo i_emlrtRSI = { 1,   // lineNo
  "System/System",                     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"// pathName 
};

static emlrtRSInfo j_emlrtRSI = { 1,   // lineNo
  "SystemProp/clearTunablePropertyChanged",// fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"// pathName 
};

static emlrtRSInfo k_emlrtRSI = { 1,   // lineNo
  "SystemCore/releaseWrapper",         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pathName 
};

static emlrtRSInfo l_emlrtRSI = { 30,  // lineNo
  "AsyncBuffercg/AsyncBuffercg",       // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercg.m"// pathName 
};

static emlrtRSInfo m_emlrtRSI = { 31,  // lineNo
  "AsyncBuffercg",                     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercg.m"// pathName 
};

static emlrtRSInfo n_emlrtRSI = { 176, // lineNo
  "AsyncBuffercgHelper/AsyncBuffercgHelper",// fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pathName 
};

static emlrtRSInfo o_emlrtRSI = { 1,   // lineNo
  "SystemProp/SystemProp",             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"// pathName 
};

static emlrtRSInfo p_emlrtRSI = { 1,   // lineNo
  "SystemCore/SystemCore",             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pathName 
};

static emlrtRSInfo db_emlrtRSI = { 114,// lineNo
  "AsyncBuffercg/read",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercg.m"// pathName 
};

static emlrtRSInfo eb_emlrtRSI = { 334,// lineNo
  "AsyncBuffercgHelper/read",          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pathName 
};

static emlrtRTEInfo d_emlrtRTEI = { 1, // lineNo
  1,                                   // colNo
  "SystemCore/releaseWrapper",         // fName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pName 
};

static emlrtRTEInfo e_emlrtRTEI = { 15,// lineNo
  1,                                   // colNo
  "reset",                             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/scomp/reset.m"// pName
};

static emlrtRTEInfo f_emlrtRTEI = { 43,// lineNo
  1,                                   // colNo
  "setup",                             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/scomp/setup.m"// pName
};

static emlrtRTEInfo g_emlrtRTEI = { 324,// lineNo
  13,                                  // colNo
  "AsyncBuffercgHelper/read",          // fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static emlrtRTEInfo h_emlrtRTEI = { 51,// lineNo
  5,                                   // colNo
  "step",                              // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/scomp/step.m"// pName
};

static emlrtRSInfo kb_emlrtRSI = { 12, // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

// Function Declarations
static const mxArray *b_emlrt_marshallOut(const coder::array<real_T, 1U> &u);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct_T u);

// Function Definitions
static const mxArray *b_emlrt_marshallOut(const coder::array<real_T, 1U> &u)
{
  const mxArray *y;
  const mxArray *m;
  real_T *pData;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(1, ((coder::array<real_T, 1U> *)&u)->size(),
    mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i = 0; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i];
    i++;
  }

  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct_T u)
{
  const mxArray *y;
  static const char * sv[1] = { "labels" };

  const mxArray *b_y;
  const mxArray *m;
  const mxArray *c_y;
  const mxArray *d_y;
  static const int32_T iv[1] = { 12 };

  uint8_T *pData;
  int32_T i;
  const mxArray *propValues[5];
  int32_T iv1[1];
  static const int32_T iv2[2] = { 1, 4 };

  static const int32_T iv3[2] = { 1, 2 };

  static const int32_T iv4[2] = { 1, 4 };

  static const int32_T iv5[2] = { 1, 2 };

  static const int32_T iv6[2] = { 1, 3 };

  static const int32_T iv7[2] = { 1, 2 };

  static const int32_T iv8[2] = { 1, 5 };

  static const int32_T iv9[2] = { 1, 4 };

  static const int32_T iv10[2] = { 1, 2 };

  static const int32_T iv11[2] = { 1, 3 };

  static const int32_T iv12[2] = { 1, 7 };

  static const int32_T iv13[2] = { 1, 10 };

  const char * propNames[5] = { "codes", "categoryNames", "isProtected",
    "isOrdinal", "numCategoriesUpperBound" };

  const char * propClasses[5] = { "matlab.internal.coder.categorical",
    "matlab.internal.coder.categorical", "matlab.internal.coder.categorical",
    "matlab.internal.coder.categorical", "matlab.internal.coder.categorical" };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, &sv[0]));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateClassInstance("matlab.internal.coder.categorical"));
  m = NULL;
  c_y = NULL;
  d_y = emlrtCreateNumericArray(1, &iv[0], mxUINT8_CLASS, mxREAL);
  pData = (uint8_T *)emlrtMxGetData(d_y);
  i = 0;
  for (int32_T b_i = 0; b_i < 12; b_i++) {
    pData[i] = u.labels.codes[b_i];
    i++;
  }

  const mxArray *m1;
  const mxArray *m2;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *m6;
  const mxArray *m7;
  const mxArray *m8;
  const mxArray *m9;
  const mxArray *m10;
  const mxArray *m11;
  const mxArray *m12;
  const mxArray *m13;
  const mxArray *m14;
  const mxArray *m15;
  emlrtAssign(&c_y, d_y);
  emlrtAssign(&m, c_y);
  propValues[0] = m;
  m = NULL;
  c_y = NULL;
  iv1[0] = 12;
  emlrtAssign(&c_y, emlrtCreateCellArrayR2014a(1, &iv1[0]));
  d_y = NULL;
  m1 = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a(sp, 4, m1, &u.labels.categoryNames.f1[0]);
  emlrtAssign(&d_y, m1);
  emlrtSetCell(c_y, 0, d_y);
  d_y = NULL;
  m2 = emlrtCreateCharArray(2, &iv3[0]);
  emlrtInitCharArrayR2013a(sp, 2, m2, &u.labels.categoryNames.f2[0]);
  emlrtAssign(&d_y, m2);
  emlrtSetCell(c_y, 1, d_y);
  d_y = NULL;
  m3 = emlrtCreateCharArray(2, &iv4[0]);
  emlrtInitCharArrayR2013a(sp, 4, m3, &u.labels.categoryNames.f3[0]);
  emlrtAssign(&d_y, m3);
  emlrtSetCell(c_y, 2, d_y);
  d_y = NULL;
  m4 = emlrtCreateCharArray(2, &iv5[0]);
  emlrtInitCharArrayR2013a(sp, 2, m4, &u.labels.categoryNames.f4[0]);
  emlrtAssign(&d_y, m4);
  emlrtSetCell(c_y, 3, d_y);
  d_y = NULL;
  m5 = emlrtCreateCharArray(2, &iv6[0]);
  emlrtInitCharArrayR2013a(sp, 3, m5, &u.labels.categoryNames.f5[0]);
  emlrtAssign(&d_y, m5);
  emlrtSetCell(c_y, 4, d_y);
  d_y = NULL;
  m6 = emlrtCreateCharArray(2, &iv7[0]);
  emlrtInitCharArrayR2013a(sp, 2, m6, &u.labels.categoryNames.f6[0]);
  emlrtAssign(&d_y, m6);
  emlrtSetCell(c_y, 5, d_y);
  d_y = NULL;
  m7 = emlrtCreateCharArray(2, &iv8[0]);
  emlrtInitCharArrayR2013a(sp, 5, m7, &u.labels.categoryNames.f7[0]);
  emlrtAssign(&d_y, m7);
  emlrtSetCell(c_y, 6, d_y);
  d_y = NULL;
  m8 = emlrtCreateCharArray(2, &iv9[0]);
  emlrtInitCharArrayR2013a(sp, 4, m8, &u.labels.categoryNames.f8[0]);
  emlrtAssign(&d_y, m8);
  emlrtSetCell(c_y, 7, d_y);
  d_y = NULL;
  m9 = emlrtCreateCharArray(2, &iv10[0]);
  emlrtInitCharArrayR2013a(sp, 2, m9, &u.labels.categoryNames.f9[0]);
  emlrtAssign(&d_y, m9);
  emlrtSetCell(c_y, 8, d_y);
  d_y = NULL;
  m10 = emlrtCreateCharArray(2, &iv11[0]);
  emlrtInitCharArrayR2013a(sp, 3, m10, &u.labels.categoryNames.f10[0]);
  emlrtAssign(&d_y, m10);
  emlrtSetCell(c_y, 9, d_y);
  d_y = NULL;
  m11 = emlrtCreateCharArray(2, &iv12[0]);
  emlrtInitCharArrayR2013a(sp, 7, m11, &u.labels.categoryNames.f11[0]);
  emlrtAssign(&d_y, m11);
  emlrtSetCell(c_y, 10, d_y);
  d_y = NULL;
  m12 = emlrtCreateCharArray(2, &iv13[0]);
  emlrtInitCharArrayR2013a(sp, 10, m12, &u.labels.categoryNames.f12[0]);
  emlrtAssign(&d_y, m12);
  emlrtSetCell(c_y, 11, d_y);
  emlrtAssign(&m, c_y);
  propValues[1] = m;
  m = NULL;
  c_y = NULL;
  m13 = emlrtCreateLogicalScalar(u.labels.isProtected);
  emlrtAssign(&c_y, m13);
  emlrtAssign(&m, c_y);
  propValues[2] = m;
  m = NULL;
  c_y = NULL;
  m14 = emlrtCreateLogicalScalar(u.labels.isOrdinal);
  emlrtAssign(&c_y, m14);
  emlrtAssign(&m, c_y);
  propValues[3] = m;
  m = NULL;
  c_y = NULL;
  m15 = emlrtCreateDoubleScalar(12.0);
  emlrtAssign(&c_y, m15);
  emlrtAssign(&m, c_y);
  propValues[4] = m;
  emlrtSetAllProperties(sp, &b_y, 0, 5, propNames, propClasses, propValues);
  emlrtAssign(&b_y, emlrtConvertInstanceToRedirectSource(sp, b_y, 0,
    "matlab.internal.coder.categorical"));
  emlrtSetFieldR2017b(y, 0, "labels", b_y, 0);
  return y;
}

void test(testStackData *SD, const emlrtStack *sp, real_T, coder::array<real_T,
          1U> &out)
{
  c_audiointerface_audioDeviceRea *obj;
  audioDeviceReader adr;
  audioDeviceReader *b_obj;
  int32_T wPtr;
  struct_T r;
  static const char_T b_cv[5] = { 'r', 'i', 'g', 'h', 't' };

  static const char_T cv1[7] = { 'u', 'n', 'k', 'n', 'o', 'w', 'n' };

  static const char_T cv2[10] = { 'b', 'a', 'c', 'k', 'g', 'r', 'o', 'u', 'n',
    'd' };

  char_T *sErr;
  real_T varargout_1[800];
  static const int32_T iv[1] = { 800 };

  int32_T underrun;
  int32_T overlapUnderrun;
  int32_T rPtr;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emlrtPushHeapReferenceStackR2018a(sp, &SD->f0.audioBuffer.pBuffer, (void *)
    &e_matlabCodegenHandle_matlabCod);
  SD->f0.audioBuffer.pBuffer.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2018a(sp, &SD->f0.audioBuffer, (void *)
    &d_matlabCodegenHandle_matlabCod);
  SD->f0.audioBuffer.matlabCodegenIsDeleted = true;
  st.site = NULL;
  obj = &adr.pInterface;
  obj->S0_isInitialized = 0;
  emlrtPushHeapReferenceStackR2018a(sp, &adr, (void *)
    &c_matlabCodegenHandle_matlabCod);
  adr.matlabCodegenIsDeleted = true;

  //  Rate?
  st.site = &emlrtRSI;
  b_obj = &adr;
  b_st.site = &g_emlrtRSI;
  c_st.site = &i_emlrtRSI;
  d_st.site = &j_emlrtRSI;
  c_st.site = &i_emlrtRSI;
  adr.isInitialized = 0;
  d_st.site = &k_emlrtRSI;
  b_st.site = &h_emlrtRSI;

  // System object Constructor function: audiointerface.audioDeviceReader
  b_obj->pInterface.S0_isInitialized = 0;
  adr.matlabCodegenIsDeleted = false;
  st.site = &b_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  SD->f0.audioBuffer.pBuffer.NumChannels = -1;
  c_st.site = &n_emlrtRSI;
  d_st.site = &i_emlrtRSI;
  e_st.site = &o_emlrtRSI;
  d_st.site = &i_emlrtRSI;
  SD->f0.audioBuffer.pBuffer.isInitialized = 0;
  e_st.site = &p_emlrtRSI;
  SD->f0.audioBuffer.pBuffer.matlabCodegenIsDeleted = false;
  SD->f0.audioBuffer.matlabCodegenIsDeleted = false;

  //  auslesen des Audiobuffers
  // YBuffer(1:classificationRate/2) = categorical({'background'});
  // YBuffer = categorical(1:10,1:10,{'background','background','background','background','background','background','background','background','background','background'}) 
  // YBuffer = categorical({'background'});
  // out = YBuffer;
  for (wPtr = 0; wPtr < 12; wPtr++) {
    r.labels.codes[wPtr] = static_cast<uint8_T>(wPtr + 1U);
  }

  r.labels.categoryNames.f1[0] = 'd';
  r.labels.categoryNames.f1[1] = 'o';
  r.labels.categoryNames.f1[2] = 'w';
  r.labels.categoryNames.f1[3] = 'n';
  r.labels.categoryNames.f2[0] = 'g';
  r.labels.categoryNames.f2[1] = 'o';
  r.labels.categoryNames.f3[0] = 'l';
  r.labels.categoryNames.f3[1] = 'e';
  r.labels.categoryNames.f3[2] = 'f';
  r.labels.categoryNames.f3[3] = 't';
  r.labels.categoryNames.f4[0] = 'n';
  r.labels.categoryNames.f4[1] = 'o';
  r.labels.categoryNames.f5[0] = 'o';
  r.labels.categoryNames.f5[1] = 'f';
  r.labels.categoryNames.f5[2] = 'f';
  r.labels.categoryNames.f6[0] = 'o';
  r.labels.categoryNames.f6[1] = 'n';
  for (wPtr = 0; wPtr < 5; wPtr++) {
    r.labels.categoryNames.f7[wPtr] = b_cv[wPtr];
  }

  r.labels.categoryNames.f8[0] = 's';
  r.labels.categoryNames.f8[1] = 't';
  r.labels.categoryNames.f8[2] = 'o';
  r.labels.categoryNames.f8[3] = 'p';
  r.labels.categoryNames.f9[0] = 'u';
  r.labels.categoryNames.f9[1] = 'p';
  r.labels.categoryNames.f10[0] = 'y';
  r.labels.categoryNames.f10[1] = 'e';
  r.labels.categoryNames.f10[2] = 's';
  for (wPtr = 0; wPtr < 7; wPtr++) {
    r.labels.categoryNames.f11[wPtr] = cv1[wPtr];
  }

  for (wPtr = 0; wPtr < 10; wPtr++) {
    r.labels.categoryNames.f12[wPtr] = cv2[wPtr];
  }

  r.labels.isProtected = false;
  r.labels.isOrdinal = false;
  st.site = &kb_emlrtRSI;
  emlrtDisplayR2012b(emlrt_marshallOut(&st, r), "labels", &emlrtRTEI, sp);
  st.site = &c_emlrtRSI;
  b_st.site = &k_emlrtRSI;
  if (adr.isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen",
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (adr.isInitialized != 1) {
    c_st.site = &k_emlrtRSI;
    d_st.site = &k_emlrtRSI;
    adr.isSetupComplete = false;
    if (adr.isInitialized != 0) {
      emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    adr.isInitialized = 1;
    e_st.site = &k_emlrtRSI;
    f_st.site = &g_emlrtRSI;
    if (adr.pInterface.S0_isInitialized != 1) {
      if (adr.pInterface.S0_isInitialized == 2) {
        emlrtErrorWithMessageIdR2018a(&f_st, &f_emlrtRTEI,
          "MATLAB:system:setupCalledWhenLockedReleasedCodegen",
          "MATLAB:system:setupCalledWhenLockedReleasedCodegen", 0);
      }

      adr.pInterface.S0_isInitialized = 1;

      // System object Start function: audiointerface.audioDeviceReader
      sErr = GetErrorBuffer(&adr.pInterface.W0_AudioDeviceLib[0U]);
      CreateHostLibrary("libmwhostlibaudio.so",
                        &adr.pInterface.W0_AudioDeviceLib[0U]);
      if (*sErr == 0) {
        LibCreate_Audio(&adr.pInterface.W0_AudioDeviceLib[0U], 0, "Default", 8,
                        0, 1, 16000.0, 3, 800, 8000, 800, 5, NULL);
      }

      if (*sErr != 0) {
        DestroyHostLibrary(&adr.pInterface.W0_AudioDeviceLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
      }
    } else {
      emlrtErrorWithMessageIdR2018a(&f_st, &f_emlrtRTEI,
        "MATLAB:system:setupCalledWhenLockedCodegen",
        "MATLAB:system:setupCalledWhenLockedCodegen", 0);
    }

    adr.isSetupComplete = true;
    adr.TunablePropsChanged = false;
    d_st.site = &k_emlrtRSI;
    e_st.site = &g_emlrtRSI;
    if (adr.pInterface.S0_isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(&e_st, &e_emlrtRTEI,
        "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen",
        "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen", 0);
    }
  }

  c_st.site = &k_emlrtRSI;
  if (adr.TunablePropsChanged) {
    adr.TunablePropsChanged = false;
  }

  c_st.site = &k_emlrtRSI;
  d_st.site = &g_emlrtRSI;
  if (adr.pInterface.S0_isInitialized != 1) {
    if (adr.pInterface.S0_isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(&d_st, &h_emlrtRTEI,
        "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen",
        "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen", 0);
    }

    adr.pInterface.S0_isInitialized = 1;
    e_st.site = NULL;

    // System object Start function: audiointerface.audioDeviceReader
    sErr = GetErrorBuffer(&adr.pInterface.W0_AudioDeviceLib[0U]);
    CreateHostLibrary("libmwhostlibaudio.so", &adr.pInterface.W0_AudioDeviceLib
                      [0U]);
    if (*sErr == 0) {
      LibCreate_Audio(&adr.pInterface.W0_AudioDeviceLib[0U], 0, "Default", 8, 0,
                      1, 16000.0, 3, 800, 8000, 800, 5, NULL);
    }

    if (*sErr != 0) {
      DestroyHostLibrary(&adr.pInterface.W0_AudioDeviceLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
    }
  }

  e_st.site = NULL;

  // System object Outputs function: audiointerface.audioDeviceReader
  sErr = GetErrorBuffer(&adr.pInterface.W0_AudioDeviceLib[0U]);
  LibOutputs_Audio(&adr.pInterface.W0_AudioDeviceLib[0U], &adr.pInterface.O0_Y0
                   [0U], 5, 800, &adr.pInterface.O1_Y1);
  if (*sErr != 0) {
    PrintError(sErr);
  }

  memcpy(&varargout_1[0], &adr.pInterface.O0_Y0[0], 800U * sizeof(real_T));
  st.site = &d_emlrtRSI;
  AsyncBuffercg_write(&st, &SD->f0.audioBuffer, varargout_1, iv);
  st.site = &e_emlrtRSI;
  b_st.site = &db_emlrtRSI;
  if (!SD->f0.audioBuffer.pBuffer.c_AsyncBuffercgHelper_isInitial) {
    emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
      "dsp:system:AsyncBuffer:isInitialized",
      "dsp:system:AsyncBuffer:isInitialized", 0);
  }

  wPtr = SD->f0.audioBuffer.pBuffer.WritePointer;
  c_st.site = &eb_emlrtRSI;
  c_AsyncBuffercgHelper_ReadSampl(&c_st, &SD->f0.audioBuffer.pBuffer, out,
    &underrun, &overlapUnderrun, &rPtr);
  if (underrun != 0) {
    if (wPtr < -2147483647) {
      rPtr = MIN_int32_T;
    } else {
      rPtr = wPtr - 1;
    }
  }

  wPtr = SD->f0.audioBuffer.pBuffer.CumulativeUnderrun;
  if ((wPtr < 0) && (underrun < MIN_int32_T - wPtr)) {
    wPtr = MIN_int32_T;
  } else if ((wPtr > 0) && (underrun > MAX_int32_T - wPtr)) {
    wPtr = MAX_int32_T;
  } else {
    wPtr += underrun;
  }

  SD->f0.audioBuffer.pBuffer.CumulativeUnderrun = wPtr;
  SD->f0.audioBuffer.pBuffer.ReadPointer = rPtr;
  emlrtDisplayR2012b(b_emlrt_marshallOut(out), "y", &b_emlrtRTEI, sp);
  emlrtDisplayR2012b(b_emlrt_marshallOut(out), "out", &c_emlrtRTEI, sp);
  st.site = &f_emlrtRSI;
  c_matlabCodegenHandle_matlabCod(&st, &adr);
  st.site = &f_emlrtRSI;
  obj = &adr.pInterface;

  // System object Destructor function: audiointerface.audioDeviceReader
  if (obj->S0_isInitialized == 1) {
    obj->S0_isInitialized = 2;
    b_st.site = NULL;

    // System object Terminate function: audiointerface.audioDeviceReader
    sErr = GetErrorBuffer(&obj->W0_AudioDeviceLib[0U]);
    LibTerminate(&obj->W0_AudioDeviceLib[0U]);
    if (*sErr != 0) {
      PrintError(sErr);
    }

    LibDestroy_Audio(&obj->W0_AudioDeviceLib[0U], 0, 1);
    DestroyHostLibrary(&obj->W0_AudioDeviceLib[0U]);
  }

  st.site = &f_emlrtRSI;
  d_matlabCodegenHandle_matlabCod(&st, &SD->f0.audioBuffer);
  st.site = &f_emlrtRSI;
  e_matlabCodegenHandle_matlabCod(&st, &SD->f0.audioBuffer.pBuffer);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (test.cpp)
