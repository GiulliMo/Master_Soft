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
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "SystemCore.h"
#include "audioDeviceReader.h"
#include "matlabCodegenHandle.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "test_data.h"
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

struct b_struct_T
{
  real_T Window[400];
  real_T OverlapLength;
  real_T SampleRate;
  real_T FFTLength;
  char_T SpectralDescriptorInput[14];
  boolean_T barkSpectrum;
};

struct c_struct_T
{
  b_struct_T afestr;
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

static emlrtRTEInfo b_emlrtRTEI = { 13,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo c_emlrtRTEI = { 71,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo d_emlrtRTEI = { 75,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo e_emlrtRTEI = { 83,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo f_emlrtRTEI = { 93,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo g_emlrtRTEI = { 103,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo h_emlrtRTEI = { 113,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo i_emlrtRTEI = { 122,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo j_emlrtRTEI = { 131,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo k_emlrtRTEI = { 140,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo l_emlrtRTEI = { 149,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo m_emlrtRTEI = { 158,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo n_emlrtRTEI = { 167,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo o_emlrtRTEI = { 176,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo p_emlrtRTEI = { 181,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo q_emlrtRTEI = { 186,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo r_emlrtRTEI = { 191,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo s_emlrtRTEI = { 196,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo t_emlrtRTEI = { 201,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo u_emlrtRTEI = { 211,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo v_emlrtRTEI = { 216,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo w_emlrtRTEI = { 227,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo x_emlrtRTEI = { 232,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo y_emlrtRTEI = { 237,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo ab_emlrtRTEI = { 242,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo bb_emlrtRTEI = { 251,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo cb_emlrtRTEI = { 256,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo db_emlrtRTEI = { 261,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo eb_emlrtRTEI = { 264,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo fb_emlrtRTEI = { 265,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo gb_emlrtRTEI = { 266,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo hb_emlrtRTEI = { 267,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo ib_emlrtRTEI = { 268,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo jb_emlrtRTEI = { 269,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo kb_emlrtRTEI = { 270,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo lb_emlrtRTEI = { 271,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo mb_emlrtRTEI = { 272,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo nb_emlrtRTEI = { 279,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo ob_emlrtRTEI = { 280,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo pb_emlrtRTEI = { 281,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo qb_emlrtRTEI = { 282,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo rb_emlrtRTEI = { 283,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo sb_emlrtRTEI = { 284,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo tb_emlrtRTEI = { 285,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo ub_emlrtRTEI = { 286,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo vb_emlrtRTEI = { 287,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo wb_emlrtRTEI = { 288,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo xb_emlrtRTEI = { 289,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo yb_emlrtRTEI = { 290,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo ac_emlrtRTEI = { 291,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo bc_emlrtRTEI = { 292,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo cc_emlrtRTEI = { 293,// lineNo
  1,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo dc_emlrtRTEI = { 295,// lineNo
  5,                                   // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pName
};

static emlrtRTEInfo ec_emlrtRTEI = { 296,// lineNo
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

static emlrtRSInfo c_emlrtRSI = { 18,  // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtRSInfo d_emlrtRSI = { 19,  // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtRSInfo e_emlrtRSI = { 20,  // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtRSInfo f_emlrtRSI = { 1634,// lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtRSInfo g_emlrtRSI = { 21,  // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtDCInfo emlrtDCI = { 40,    // lineNo
  18,                                  // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo b_emlrtDCI = { 40,  // lineNo
  52,                                  // colNo
  "test",                              // fName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m",// pName
  4                                    // checkKind
};

static emlrtRSInfo ob_emlrtRSI = { 12, // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

static emlrtRSInfo pb_emlrtRSI = { 13, // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

// Function Declarations
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const c_struct_T
  *u);
static const mxArray *c_emlrt_marshallOut(const real_T u[1024]);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct_T u);

// Function Definitions
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const c_struct_T
  *u)
{
  const mxArray *y;
  static const char * sv[1] = { "afestr" };

  const mxArray *b_y;
  static const char * sv1[6] = { "Window", "OverlapLength", "SampleRate",
    "FFTLength", "SpectralDescriptorInput", "barkSpectrum" };

  const mxArray *c_y;
  const mxArray *m;
  static const int32_T iv[1] = { 400 };

  real_T *pData;
  int32_T i;
  static const int32_T iv1[2] = { 1, 14 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 1, &sv[0]));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 6, &sv1[0]));
  c_y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i = 0; b_i < 400; b_i++) {
    pData[i] = u->afestr.Window[b_i];
    i++;
  }

  const mxArray *m1;
  const mxArray *m2;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(b_y, 0, "Window", c_y, 0);
  c_y = NULL;
  m1 = emlrtCreateDoubleScalar(u->afestr.OverlapLength);
  emlrtAssign(&c_y, m1);
  emlrtSetFieldR2017b(b_y, 0, "OverlapLength", c_y, 1);
  c_y = NULL;
  m2 = emlrtCreateDoubleScalar(u->afestr.SampleRate);
  emlrtAssign(&c_y, m2);
  emlrtSetFieldR2017b(b_y, 0, "SampleRate", c_y, 2);
  c_y = NULL;
  m3 = emlrtCreateDoubleScalar(u->afestr.FFTLength);
  emlrtAssign(&c_y, m3);
  emlrtSetFieldR2017b(b_y, 0, "FFTLength", c_y, 3);
  c_y = NULL;
  m4 = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a(sp, 14, m4, &u->afestr.SpectralDescriptorInput[0]);
  emlrtAssign(&c_y, m4);
  emlrtSetFieldR2017b(b_y, 0, "SpectralDescriptorInput", c_y, 4);
  c_y = NULL;
  m5 = emlrtCreateLogicalScalar(u->afestr.barkSpectrum);
  emlrtAssign(&c_y, m5);
  emlrtSetFieldR2017b(b_y, 0, "barkSpectrum", c_y, 5);
  emlrtSetFieldR2017b(y, 0, "afestr", b_y, 0);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const real_T u[1024])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[1] = { 1024 };

  real_T *pData;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i = 0; b_i < 1024; b_i++) {
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
  int32_T i;
  struct_T r;
  static const char_T b_cv[5] = { 'r', 'i', 'g', 'h', 't' };

  static const char_T cv1[7] = { 'u', 'n', 'k', 'n', 'o', 'w', 'n' };

  static const char_T cv2[10] = { 'b', 'a', 'c', 'k', 'g', 'r', 'o', 'u', 'n',
    'd' };

  c_struct_T s;
  static const real_T t0_Window[400] = { 0.0, 6.1683759169706143E-5,
    0.0002467198171342, 0.00055506251901499271, 0.00098663578586422052,
    0.0015413331334360181, 0.0022190176984600019, 0.0030195222724101467,
    0.003942649342761062, 0.0049881711417212315, 0.0061558297024311148,
    0.0074453369226130661, 0.00885637463565564, 0.010388594689117125,
    0.012041619030626283, 0.013815039801161721, 0.015708419435684462,
    0.017721290771100962, 0.019853157161528467, 0.02210349260083494,
    0.024471741852423234, 0.026957320586227351, 0.029559615522887273,
    0.032277984585066366, 0.035111757055874271, 0.038060233744356631,
    0.04112268715800943, 0.044298361682277354, 0.047586473766990267,
    0.050986212119692176, 0.054496737905816051, 0.058117184955653267,
    0.061846659978068208, 0.0656842427809044, 0.069628986498028178,
    0.073679917822953855, 0.077836037248992462, 0.082096319315864863,
    0.086459712862719085, 0.0909251412874883, 0.095491502812526274,
    0.10015767075645471, 0.10492249381215479, 0.1097847963308351,
    0.11474337861210537, 0.11979701719998453, 0.12494446518477026,
    0.1301844525106951, 0.13551568628929422, 0.14093685111840554,
    0.14644660940672621, 0.15204360170384285, 0.15772644703565564,
    0.16349374324511334, 0.16934406733817409, 0.17527597583490823,
    0.18128800512565518, 0.18737867183214735, 0.1935464731735117,
    0.19978988733705794, 0.20610737385376343, 0.21249737397836072,
    0.21895831107393471, 0.2254885910009341, 0.23208660251050173,
    0.23875071764202555, 0.2454792921248144, 0.2522706657837962,
    0.25912316294914239, 0.26603509286971327, 0.27300475013022657,
    0.2800304150720424, 0.28711035421746367, 0.29424282069744556,
    0.30142605468260975, 0.30865828381745508, 0.31593772365766093,
    0.3232625781103714, 0.33063103987735426, 0.33804129090092527,
    0.34549150281252627, 0.35297983738384808, 0.36050444698038525,
    0.36806347501731351, 0.37565505641757252, 0.38327731807204724,
    0.39092837930172863, 0.39860635232174374, 0.40630934270713764,
    0.41403544986029522, 0.42178276747988452, 0.42954938403120868,
    0.43733338321784787, 0.44513284445447743, 0.45294584334074273,
    0.46077045213607748, 0.46860474023534326, 0.47644677464517865,
    0.4842946204609358, 0.49214634134408969, 0.49999999999999994,
    0.50785365865591026, 0.51570537953906415, 0.52355322535482129,
    0.53139525976465674, 0.53922954786392241, 0.54705415665925716,
    0.55486715554552257, 0.56266661678215213, 0.57045061596879132,
    0.57821723252011548, 0.58596455013970483, 0.59369065729286241,
    0.60139364767825609, 0.60907162069827114, 0.61672268192795254,
    0.62434494358242731, 0.63193652498268627, 0.63949555301961458,
    0.64702016261615192, 0.65450849718747373, 0.66195870909907462,
    0.66936896012264568, 0.67673742188962849, 0.684062276342339,
    0.69134171618254481, 0.69857394531739025, 0.70575717930255433,
    0.71288964578253633, 0.7199695849279576, 0.72699524986977337,
    0.73396490713028661, 0.74087683705085772, 0.7477293342162038,
    0.75452070787518566, 0.7612492823579744, 0.76791339748949849,
    0.7745114089990659, 0.78104168892606518, 0.78750262602163912,
    0.79389262614623646, 0.800210112662942, 0.80645352682648808,
    0.81262132816785249, 0.81871199487434487, 0.82472402416509172,
    0.83065593266182591, 0.83650625675488655, 0.84227355296434436,
    0.8479563982961571, 0.85355339059327373, 0.8590631488815943,
    0.86448431371070567, 0.8698155474893049, 0.8750555348152298,
    0.88020298280001541, 0.88525662138789452, 0.890215203669165,
    0.89507750618784521, 0.89984232924354524, 0.90450849718747373,
    0.90907485871251181, 0.913540287137281, 0.917903680684135,
    0.92216396275100743, 0.92632008217704609, 0.93037101350197182,
    0.93431575721909554, 0.93815334002193174, 0.94188281504434679,
    0.94550326209418389, 0.94901378788030777, 0.95241352623300968,
    0.95570163831772259, 0.95887731284199051, 0.96193976625564337,
    0.96488824294412567, 0.96772201541493363, 0.97044038447711278,
    0.97304267941377265, 0.97552825814757682, 0.977896507399165,
    0.98014684283847153, 0.982278709228899, 0.98429158056431554,
    0.98618496019883828, 0.98795838096937372, 0.98961140531088287,
    0.99114362536434431, 0.99255466307738693, 0.99384417029756889,
    0.99501182885827877, 0.99605735065723888, 0.9969804777275898,
    0.99778098230154, 0.998458666866564, 0.99901336421413578, 0.999444937480985,
    0.9997532801828658, 0.99993831624083029, 1.0, 0.99993831624083029,
    0.9997532801828658, 0.999444937480985, 0.99901336421413578,
    0.998458666866564, 0.99778098230154, 0.9969804777275898, 0.99605735065723888,
    0.99501182885827877, 0.99384417029756889, 0.99255466307738693,
    0.99114362536434431, 0.98961140531088287, 0.98795838096937372,
    0.98618496019883828, 0.98429158056431554, 0.982278709228899,
    0.98014684283847153, 0.977896507399165, 0.97552825814757682,
    0.97304267941377265, 0.97044038447711278, 0.96772201541493363,
    0.96488824294412567, 0.96193976625564337, 0.95887731284199051,
    0.95570163831772259, 0.95241352623300968, 0.94901378788030777,
    0.94550326209418389, 0.94188281504434679, 0.93815334002193174,
    0.93431575721909554, 0.93037101350197182, 0.92632008217704609,
    0.92216396275100743, 0.917903680684135, 0.913540287137281,
    0.90907485871251181, 0.90450849718747373, 0.89984232924354524,
    0.89507750618784521, 0.890215203669165, 0.88525662138789452,
    0.88020298280001541, 0.8750555348152298, 0.8698155474893049,
    0.86448431371070567, 0.8590631488815943, 0.85355339059327373,
    0.8479563982961571, 0.84227355296434436, 0.83650625675488655,
    0.83065593266182591, 0.82472402416509172, 0.81871199487434487,
    0.81262132816785249, 0.80645352682648808, 0.800210112662942,
    0.79389262614623646, 0.78750262602163912, 0.78104168892606518,
    0.7745114089990659, 0.76791339748949849, 0.7612492823579744,
    0.75452070787518566, 0.7477293342162038, 0.74087683705085772,
    0.73396490713028661, 0.72699524986977337, 0.7199695849279576,
    0.71288964578253633, 0.70575717930255433, 0.69857394531739025,
    0.69134171618254481, 0.684062276342339, 0.67673742188962849,
    0.66936896012264568, 0.66195870909907462, 0.65450849718747373,
    0.64702016261615192, 0.63949555301961458, 0.63193652498268627,
    0.62434494358242731, 0.61672268192795254, 0.60907162069827114,
    0.60139364767825609, 0.59369065729286241, 0.58596455013970483,
    0.57821723252011548, 0.57045061596879132, 0.56266661678215213,
    0.55486715554552257, 0.54705415665925716, 0.53922954786392241,
    0.53139525976465674, 0.52355322535482129, 0.51570537953906415,
    0.50785365865591026, 0.49999999999999994, 0.49214634134408969,
    0.4842946204609358, 0.47644677464517865, 0.46860474023534326,
    0.46077045213607748, 0.45294584334074273, 0.44513284445447743,
    0.43733338321784787, 0.42954938403120868, 0.42178276747988452,
    0.41403544986029522, 0.40630934270713764, 0.39860635232174374,
    0.39092837930172863, 0.38327731807204724, 0.37565505641757252,
    0.36806347501731351, 0.36050444698038525, 0.35297983738384808,
    0.34549150281252627, 0.33804129090092527, 0.33063103987735426,
    0.3232625781103714, 0.31593772365766093, 0.30865828381745508,
    0.30142605468260975, 0.29424282069744556, 0.28711035421746367,
    0.2800304150720424, 0.27300475013022657, 0.26603509286971327,
    0.25912316294914239, 0.2522706657837962, 0.2454792921248144,
    0.23875071764202555, 0.23208660251050173, 0.2254885910009341,
    0.21895831107393471, 0.21249737397836072, 0.20610737385376343,
    0.19978988733705794, 0.1935464731735117, 0.18737867183214735,
    0.18128800512565518, 0.17527597583490823, 0.16934406733817409,
    0.16349374324511334, 0.15772644703565564, 0.15204360170384285,
    0.14644660940672621, 0.14093685111840554, 0.13551568628929422,
    0.1301844525106951, 0.12494446518477026, 0.11979701719998453,
    0.11474337861210537, 0.1097847963308351, 0.10492249381215479,
    0.10015767075645471, 0.095491502812526274, 0.0909251412874883,
    0.086459712862719085, 0.082096319315864863, 0.077836037248992462,
    0.073679917822953855, 0.069628986498028178, 0.0656842427809044,
    0.061846659978068208, 0.058117184955653267, 0.054496737905816051,
    0.050986212119692176, 0.047586473766990267, 0.044298361682277354,
    0.04112268715800943, 0.038060233744356631, 0.035111757055874271,
    0.032277984585066366, 0.029559615522887273, 0.026957320586227351,
    0.024471741852423234, 0.02210349260083494, 0.019853157161528467,
    0.017721290771100962, 0.015708419435684462, 0.013815039801161721,
    0.012041619030626283, 0.010388594689117125, 0.00885637463565564,
    0.0074453369226130661, 0.0061558297024311148, 0.0049881711417212315,
    0.003942649342761062, 0.0030195222724101467, 0.0022190176984600019,
    0.0015413331334360181, 0.00098663578586422052, 0.00055506251901499271,
    0.0002467198171342, 6.1683759169706143E-5 };

  static const char_T t0_SpectralDescriptorInput[14] = { 'l', 'i', 'n', 'e', 'a',
    'r', 'S', 'p', 'e', 'c', 't', 'r', 'u', 'm' };

  real_T varargout_1[800];
  static const int32_T iv[1] = { 800 };

  static const real_T Window[1024] = { 0.080000000000000016, 0.08000865937000351,
    0.08003463715399356, 0.080077932373921246, 0.080138543399746076,
    0.080216467949497161, 0.0803117030893592, 0.080424245233783165,
    0.0805540901456207, 0.0807012329362844, 0.080865668065931373,
    0.081047389343671838, 0.081246389927802531, 0.0814626623260638,
    0.081696198395922126, 0.081946989344876486, 0.082215025730789426,
    0.082500297462242522, 0.082802793798916252, 0.083122503351994559,
    0.083459414084593453, 0.083813513312214261, 0.084184787703221187,
    0.084573223279343357, 0.084978805416200731, 0.085401518843855273,
    0.085841347647385158, 0.086298275267484625, 0.086772284501087038,
    0.08726335750201264, 0.087771475781640518, 0.0882966202096046,
    0.08883877101451404, 0.089397907784697361, 0.089974009468971272,
    0.090567054377433009, 0.091177020182276858, 0.091803883918635143,
    0.092447621985442319, 0.0931082101463242, 0.093785623530509787,
    0.094479836633768077, 0.095190823319368068, 0.095918556819062917,
    0.0966630097340977, 0.097424154036240884, 0.098201961068839771,
    0.098996401547899071, 0.099807445563183939, 0.10063506257934546,
    0.10147922143707083, 0.10233989035425617, 0.10321703692720313,
    0.10411062813183913, 0.10502063032496023, 0.10594700924549821,
    0.10688973001581042, 0.10784875714299264, 0.10882405452021554,
    0.10981558542808412, 0.11082331253602012, 0.11184719790366748,
    0.11288720298232086, 0.11394328861637676, 0.11501541504480811,
    0.11610354190266076, 0.11720762822257347, 0.11832763243632038,
    0.11946351237637592, 0.12061522527750229, 0.12178272777835975,
    0.12296597592313896, 0.12416492516321609, 0.12537953035882987,
    0.12660974578078127, 0.12785552511215481, 0.12911682145006298,
    0.13039358730741141, 0.13168577461468722, 0.13299333472176861,
    0.13431621839975671, 0.13565437584282858, 0.137007756670113,
    0.13837630992758659, 0.13975998408999274, 0.14115872706278138,
    0.14257248618407015, 0.14400120822662704, 0.14544483939987485,
    0.14690332535191575, 0.14837661117157802, 0.14986464139048328,
    0.15136735998513473, 0.15288471037902673, 0.15441663544477452,
    0.1559630775062652, 0.15752397834082921, 0.15909927918143235,
    0.16068892071888841, 0.16229284310409187, 0.16391098595027154,
    0.16554328833526377, 0.16718968880380641, 0.16885012536985233,
    0.17052453551890334, 0.1722128562103637, 0.17391502387991359,
    0.17563097444190234, 0.1773606432917611, 0.17910396530843542,
    0.18086087485683655, 0.18263130579031311, 0.184415191453141,
    0.18621246468303337, 0.1880230578136689, 0.18984690267723958,
    0.19168393060701711, 0.19353407243993825, 0.19539725851920869,
    0.19727341869692566, 0.19916248233671879, 0.20106437831640994,
    0.20297903503069015, 0.20490638039381642, 0.2068463418423252,
    0.20879884633776447, 0.21076382036944347, 0.21274118995720048,
    0.21473088065418816, 0.21673281754967638, 0.21874692527187251,
    0.22077312799075915, 0.22281134942094921, 0.22486151282455785,
    0.22692354101409157, 0.22899735635535462, 0.23108288077037153,
    0.23318003574032681, 0.23528874230852098, 0.23740892108334377,
    0.23954049224126267, 0.24168337552982827, 0.24383749027069596,
    0.24600275536266319, 0.2481790892847231, 0.25036641009913357,
    0.25256463545450225, 0.254773682588887, 0.2569934683329117,
    0.25922390911289767, 0.26146492095401025, 0.26371641948342028,
    0.26597831993348064, 0.26825053714491787, 0.27053298557003813,
    0.27282557927594836, 0.27512823194779118, 0.27744085689199505,
    0.27976336703953791, 0.28209567494922544, 0.28443769281098297,
    0.28678933244916183, 0.28915050532585868, 0.29152112254424922,
    0.29390109485193527, 0.29629033264430438, 0.2986887459679044,
    0.30109624452382888, 0.30351273767111808, 0.30593813443017076,
    0.30837234348616993, 0.31081527319252034, 0.31326683157429935,
    0.31572692633171945, 0.3181954648436035, 0.32067235417087181,
    0.32315750106004104, 0.32565081194673562, 0.32815219295920961,
    0.3306615499218819, 0.333178788358881, 0.33570381349760259,
    0.33823653027227729, 0.34077684332755009, 0.34332465702207021,
    0.34587987543209209, 0.34844240235508683, 0.35101214131336422,
    0.35358899555770473, 0.35617286807100251, 0.35876366157191791,
    0.36136127851853994, 0.36396562111205871, 0.36657659130044762,
    0.3691940907821547, 0.371818021009804, 0.37444828319390544,
    0.37708477830657439, 0.37972740708526015, 0.38237607003648261,
    0.38503066743957881, 0.38769109935045687, 0.39035726560535905,
    0.39302906582463282, 0.39570639941650987, 0.39838916558089393,
    0.40107726331315507, 0.40377059140793303, 0.40646904846294735,
    0.40917253288281497, 0.41188094288287563, 0.41459417649302349,
    0.41731213156154678, 0.42003470575897328, 0.42276179658192331,
    0.42549330135696872, 0.42822911724449858, 0.43096914124259106,
    0.43371327019089123, 0.43646140077449536, 0.43921342952783993,
    0.441969252838598, 0.44472876695157948, 0.44749186797263774,
    0.450258451872581, 0.45302841449108916, 0.45580165154063512,
    0.45857805861041157, 0.4613575311702614, 0.46413996457461382,
    0.46692525406642382, 0.46971329478111606, 0.47250398175053365,
    0.4752972099068894, 0.47809287408672196, 0.48089086903485517,
    0.48369108940836053, 0.48649342978052379, 0.48929778464481377,
    0.49210404841885486, 0.49491211544840208, 0.497721880011319,
    0.50053323632155766, 0.50334607853314217, 0.506160300744153,
    0.50897579700071449, 0.5117924613009841, 0.51461018759914268,
    0.51742886980938774, 0.52024840180992715, 0.52306867744697494,
    0.52588959053874718, 0.52871103487946036, 0.53153290424332977,
    0.53435509238856882, 0.537177493061389, 0.54, 0.542822506938611,
    0.54564490761143114, 0.54846709575667019, 0.5512889651205396,
    0.55411040946125278, 0.55693132255302513, 0.55975159819007281,
    0.56257113019061233, 0.56538981240085739, 0.568207538699016,
    0.57102420299928547, 0.573839699255847, 0.57665392146685779,
    0.5794667636784423, 0.58227811998868106, 0.58508788455159788,
    0.58789595158114516, 0.59070221535518619, 0.59350657021947617,
    0.59630891059163948, 0.59910913096514484, 0.601907125913278,
    0.60470279009311068, 0.60749601824946642, 0.610286705218884,
    0.61307474593357625, 0.61586003542538625, 0.61864246882973861,
    0.62142194138958851, 0.62419834845936484, 0.62697158550891086,
    0.629741548127419, 0.63250813202736222, 0.63527123304842048,
    0.638030747161402, 0.64078657047216, 0.64353859922550471,
    0.64628672980910873, 0.649030858757409, 0.65177088275550144,
    0.65450669864303124, 0.65723820341807671, 0.65996529424102679,
    0.66268786843845329, 0.66540582350697652, 0.66811905711712438,
    0.670827467117185, 0.67353095153705267, 0.676229408592067, 0.678922736686845,
    0.68161083441910608, 0.68429360058349009, 0.68697093417536725,
    0.689642734394641, 0.69230890064954309, 0.69496933256042115,
    0.69762392996351741, 0.70027259291473987, 0.70291522169342557,
    0.70555171680609463, 0.708181978990196, 0.71080590921784526,
    0.71342340869955245, 0.7160343788879413, 0.71863872148146013,
    0.7212363384280821, 0.7238271319289975, 0.72641100444229534,
    0.72898785868663585, 0.731557597644913, 0.73412012456790787,
    0.73667534297792969, 0.73922315667245, 0.74176346972772267,
    0.74429618650239748, 0.74682121164111914, 0.74933845007811817,
    0.75184780704079046, 0.75434918805326445, 0.75684249893995892,
    0.75932764582912815, 0.76180453515639646, 0.76427307366828046,
    0.76673316842570072, 0.76918472680747962, 0.77162765651383,
    0.77406186556982925, 0.776487262328882, 0.7789037554761713,
    0.78131125403209567, 0.78370966735569558, 0.78609890514806469,
    0.78847887745575074, 0.79084949467414134, 0.79321066755083813,
    0.795562307189017, 0.79790432505077458, 0.80023663296046221,
    0.80255914310800491, 0.80487176805220884, 0.80717442072405166,
    0.80946701442996194, 0.81174946285508209, 0.81402168006651943,
    0.81628358051657968, 0.81853507904598977, 0.82077609088710246,
    0.82300653166708826, 0.82522631741111308, 0.82743536454549771,
    0.82963358990086644, 0.831820910715277, 0.83399724463733693,
    0.83616250972930406, 0.83831662447017175, 0.84045950775873723,
    0.84259107891665619, 0.84471125769147914, 0.84681996425967321,
    0.84891711922962854, 0.8510026436446454, 0.85307645898590845,
    0.85513848717544216, 0.85718865057905091, 0.85922687200924086,
    0.86125307472812751, 0.86326718245032352, 0.86526911934581185,
    0.86725881004279959, 0.86923617963055655, 0.87120115366223561,
    0.87315365815767476, 0.87509361960618359, 0.87702096496930992,
    0.87893562168359018, 0.88083751766328111, 0.88272658130307446,
    0.88460274148079132, 0.88646592756006171, 0.888316069392983,
    0.89015309732276049, 0.89197694218633117, 0.89378753531696664,
    0.89558480854685907, 0.8973686942096869, 0.89913912514316352,
    0.90089603469156454, 0.90263935670823892, 0.90436902555809762,
    0.90608497612008643, 0.90778714378963643, 0.90947546448109673,
    0.91114987463014774, 0.9128103111961936, 0.9144567116647363,
    0.91608901404972853, 0.9177071568959082, 0.91931107928111166,
    0.92090072081856766, 0.922476021659171, 0.92403692249373481,
    0.92558336455522561, 0.92711528962097334, 0.92863264001486534,
    0.93013535860951668, 0.931623388828422, 0.93309667464808421,
    0.93455516060012522, 0.935998791773373, 0.93742751381592992,
    0.93884127293721864, 0.94024001591000728, 0.94162369007241353,
    0.942992243329887, 0.94434562415717149, 0.94568378160024325,
    0.94700666527823141, 0.94831422538531274, 0.94960641269258872,
    0.950883178549937, 0.95214447488784515, 0.95339025421921886,
    0.9546204696411702, 0.955835074836784, 0.95703402407686111,
    0.95821727222164033, 0.95938477472249772, 0.9605364876236242,
    0.96167236756367958, 0.9627923717774266, 0.96389645809733926,
    0.9649845849551919, 0.96605671138362337, 0.96711279701767916,
    0.96815280209633259, 0.96917668746398, 0.970184414571916,
    0.97117594547978447, 0.97215124285700738, 0.97311026998418959,
    0.97405299075450191, 0.97497936967503973, 0.97588937186816094,
    0.97678296307279688, 0.9776601096457439, 0.97852077856292929,
    0.97936493742065456, 0.98019255443681619, 0.98100359845210094,
    0.98179803893116024, 0.98257584596375913, 0.98333699026590238,
    0.98408144318093715, 0.984809176680632, 0.985520163366232,
    0.98621437646949028, 0.98689178985367587, 0.98755237801455764,
    0.98819611608136493, 0.98882297981772316, 0.989432945622567,
    0.99002599053102869, 0.99060209221530271, 0.99116122898548609,
    0.99170337979039547, 0.99222852421835961, 0.99273664249798743,
    0.99322771549891309, 0.99370172473251539, 0.99415865235261491,
    0.9945984811561448, 0.99502119458379934, 0.9954267767206566,
    0.99581521229677894, 0.99618648668778587, 0.99654058591540662,
    0.99687749664800551, 0.99719720620108387, 0.99749970253775755,
    0.99778497426921064, 0.99805301065512353, 0.998303801604078,
    0.99853733767393626, 0.99875361007219754, 0.99895261065632823,
    0.99913433193406864, 0.99929876706371568, 0.99944590985437931,
    0.999575754766217, 0.99968829691064087, 0.99978353205050285,
    0.99986145660025394, 0.99992206762607883, 0.99996536284600657,
    0.99999134062999651, 1.0, 0.99999134062999651, 0.99996536284600657,
    0.99992206762607883, 0.99986145660025394, 0.99978353205050285,
    0.99968829691064087, 0.999575754766217, 0.99944590985437931,
    0.99929876706371568, 0.99913433193406864, 0.99895261065632823,
    0.99875361007219754, 0.99853733767393626, 0.998303801604078,
    0.99805301065512353, 0.99778497426921064, 0.99749970253775755,
    0.99719720620108387, 0.99687749664800551, 0.99654058591540662,
    0.99618648668778587, 0.99581521229677894, 0.9954267767206566,
    0.99502119458379934, 0.9945984811561448, 0.99415865235261491,
    0.99370172473251539, 0.99322771549891309, 0.99273664249798743,
    0.99222852421835961, 0.99170337979039547, 0.99116122898548609,
    0.99060209221530271, 0.99002599053102869, 0.989432945622567,
    0.98882297981772316, 0.98819611608136493, 0.98755237801455764,
    0.98689178985367587, 0.98621437646949028, 0.985520163366232,
    0.984809176680632, 0.98408144318093715, 0.98333699026590238,
    0.98257584596375913, 0.98179803893116024, 0.98100359845210094,
    0.98019255443681619, 0.97936493742065456, 0.97852077856292929,
    0.9776601096457439, 0.97678296307279688, 0.97588937186816094,
    0.97497936967503973, 0.97405299075450191, 0.97311026998418959,
    0.97215124285700738, 0.97117594547978447, 0.970184414571916,
    0.96917668746398, 0.96815280209633259, 0.96711279701767916,
    0.96605671138362337, 0.9649845849551919, 0.96389645809733926,
    0.9627923717774266, 0.96167236756367958, 0.9605364876236242,
    0.95938477472249772, 0.95821727222164033, 0.95703402407686111,
    0.955835074836784, 0.9546204696411702, 0.95339025421921886,
    0.95214447488784515, 0.950883178549937, 0.94960641269258872,
    0.94831422538531274, 0.94700666527823141, 0.94568378160024325,
    0.94434562415717149, 0.942992243329887, 0.94162369007241353,
    0.94024001591000728, 0.93884127293721864, 0.93742751381592992,
    0.935998791773373, 0.93455516060012522, 0.93309667464808421,
    0.931623388828422, 0.93013535860951668, 0.92863264001486534,
    0.92711528962097334, 0.92558336455522561, 0.92403692249373481,
    0.922476021659171, 0.92090072081856766, 0.91931107928111166,
    0.9177071568959082, 0.91608901404972853, 0.9144567116647363,
    0.9128103111961936, 0.91114987463014774, 0.90947546448109673,
    0.90778714378963643, 0.90608497612008643, 0.90436902555809762,
    0.90263935670823892, 0.90089603469156454, 0.89913912514316352,
    0.8973686942096869, 0.89558480854685907, 0.89378753531696664,
    0.89197694218633117, 0.89015309732276049, 0.888316069392983,
    0.88646592756006171, 0.88460274148079132, 0.88272658130307446,
    0.88083751766328111, 0.87893562168359018, 0.87702096496930992,
    0.87509361960618359, 0.87315365815767476, 0.87120115366223561,
    0.86923617963055655, 0.86725881004279959, 0.86526911934581185,
    0.86326718245032352, 0.86125307472812751, 0.85922687200924086,
    0.85718865057905091, 0.85513848717544216, 0.85307645898590845,
    0.8510026436446454, 0.84891711922962854, 0.84681996425967321,
    0.84471125769147914, 0.84259107891665619, 0.84045950775873723,
    0.83831662447017175, 0.83616250972930406, 0.83399724463733693,
    0.831820910715277, 0.82963358990086644, 0.82743536454549771,
    0.82522631741111308, 0.82300653166708826, 0.82077609088710246,
    0.81853507904598977, 0.81628358051657968, 0.81402168006651943,
    0.81174946285508209, 0.80946701442996194, 0.80717442072405166,
    0.80487176805220884, 0.80255914310800491, 0.80023663296046221,
    0.79790432505077458, 0.795562307189017, 0.79321066755083813,
    0.79084949467414134, 0.78847887745575074, 0.78609890514806469,
    0.78370966735569558, 0.78131125403209567, 0.7789037554761713,
    0.776487262328882, 0.77406186556982925, 0.77162765651383,
    0.76918472680747962, 0.76673316842570072, 0.76427307366828046,
    0.76180453515639646, 0.75932764582912815, 0.75684249893995892,
    0.75434918805326445, 0.75184780704079046, 0.74933845007811817,
    0.74682121164111914, 0.74429618650239748, 0.74176346972772267,
    0.73922315667245, 0.73667534297792969, 0.73412012456790787,
    0.731557597644913, 0.72898785868663585, 0.72641100444229534,
    0.7238271319289975, 0.7212363384280821, 0.71863872148146013,
    0.7160343788879413, 0.71342340869955245, 0.71080590921784526,
    0.708181978990196, 0.70555171680609463, 0.70291522169342557,
    0.70027259291473987, 0.69762392996351741, 0.69496933256042115,
    0.69230890064954309, 0.689642734394641, 0.68697093417536725,
    0.68429360058349009, 0.68161083441910608, 0.678922736686845,
    0.676229408592067, 0.67353095153705267, 0.670827467117185,
    0.66811905711712438, 0.66540582350697652, 0.66268786843845329,
    0.65996529424102679, 0.65723820341807671, 0.65450669864303124,
    0.65177088275550144, 0.649030858757409, 0.64628672980910873,
    0.64353859922550471, 0.64078657047216, 0.638030747161402,
    0.63527123304842048, 0.63250813202736222, 0.629741548127419,
    0.62697158550891086, 0.62419834845936484, 0.62142194138958851,
    0.61864246882973861, 0.61586003542538625, 0.61307474593357625,
    0.610286705218884, 0.60749601824946642, 0.60470279009311068,
    0.601907125913278, 0.59910913096514484, 0.59630891059163948,
    0.59350657021947617, 0.59070221535518619, 0.58789595158114516,
    0.58508788455159788, 0.58227811998868106, 0.5794667636784423,
    0.57665392146685779, 0.573839699255847, 0.57102420299928547,
    0.568207538699016, 0.56538981240085739, 0.56257113019061233,
    0.55975159819007281, 0.55693132255302513, 0.55411040946125278,
    0.5512889651205396, 0.54846709575667019, 0.54564490761143114,
    0.542822506938611, 0.54, 0.537177493061389, 0.53435509238856882,
    0.53153290424332977, 0.52871103487946036, 0.52588959053874718,
    0.52306867744697494, 0.52024840180992715, 0.51742886980938774,
    0.51461018759914268, 0.5117924613009841, 0.50897579700071449,
    0.506160300744153, 0.50334607853314217, 0.50053323632155766,
    0.497721880011319, 0.49491211544840208, 0.49210404841885486,
    0.48929778464481377, 0.48649342978052379, 0.48369108940836053,
    0.48089086903485517, 0.47809287408672196, 0.4752972099068894,
    0.47250398175053365, 0.46971329478111606, 0.46692525406642382,
    0.46413996457461382, 0.4613575311702614, 0.45857805861041157,
    0.45580165154063512, 0.45302841449108916, 0.450258451872581,
    0.44749186797263774, 0.44472876695157948, 0.441969252838598,
    0.43921342952783993, 0.43646140077449536, 0.43371327019089123,
    0.43096914124259106, 0.42822911724449858, 0.42549330135696872,
    0.42276179658192331, 0.42003470575897328, 0.41731213156154678,
    0.41459417649302349, 0.41188094288287563, 0.40917253288281497,
    0.40646904846294735, 0.40377059140793303, 0.40107726331315507,
    0.39838916558089393, 0.39570639941650987, 0.39302906582463282,
    0.39035726560535905, 0.38769109935045687, 0.38503066743957881,
    0.38237607003648261, 0.37972740708526015, 0.37708477830657439,
    0.37444828319390544, 0.371818021009804, 0.3691940907821547,
    0.36657659130044762, 0.36396562111205871, 0.36136127851853994,
    0.35876366157191791, 0.35617286807100251, 0.35358899555770473,
    0.35101214131336422, 0.34844240235508683, 0.34587987543209209,
    0.34332465702207021, 0.34077684332755009, 0.33823653027227729,
    0.33570381349760259, 0.333178788358881, 0.3306615499218819,
    0.32815219295920961, 0.32565081194673562, 0.32315750106004104,
    0.32067235417087181, 0.3181954648436035, 0.31572692633171945,
    0.31326683157429935, 0.31081527319252034, 0.30837234348616993,
    0.30593813443017076, 0.30351273767111808, 0.30109624452382888,
    0.2986887459679044, 0.29629033264430438, 0.29390109485193527,
    0.29152112254424922, 0.28915050532585868, 0.28678933244916183,
    0.28443769281098297, 0.28209567494922544, 0.27976336703953791,
    0.27744085689199505, 0.27512823194779118, 0.27282557927594836,
    0.27053298557003813, 0.26825053714491787, 0.26597831993348064,
    0.26371641948342028, 0.26146492095401025, 0.25922390911289767,
    0.2569934683329117, 0.254773682588887, 0.25256463545450225,
    0.25036641009913357, 0.2481790892847231, 0.24600275536266319,
    0.24383749027069596, 0.24168337552982827, 0.23954049224126267,
    0.23740892108334377, 0.23528874230852098, 0.23318003574032681,
    0.23108288077037153, 0.22899735635535462, 0.22692354101409157,
    0.22486151282455785, 0.22281134942094921, 0.22077312799075915,
    0.21874692527187251, 0.21673281754967638, 0.21473088065418816,
    0.21274118995720048, 0.21076382036944347, 0.20879884633776447,
    0.2068463418423252, 0.20490638039381642, 0.20297903503069015,
    0.20106437831640994, 0.19916248233671879, 0.19727341869692566,
    0.19539725851920869, 0.19353407243993825, 0.19168393060701711,
    0.18984690267723958, 0.1880230578136689, 0.18621246468303337,
    0.184415191453141, 0.18263130579031311, 0.18086087485683655,
    0.17910396530843542, 0.1773606432917611, 0.17563097444190234,
    0.17391502387991359, 0.1722128562103637, 0.17052453551890334,
    0.16885012536985233, 0.16718968880380641, 0.16554328833526377,
    0.16391098595027154, 0.16229284310409187, 0.16068892071888841,
    0.15909927918143235, 0.15752397834082921, 0.1559630775062652,
    0.15441663544477452, 0.15288471037902673, 0.15136735998513473,
    0.14986464139048328, 0.14837661117157802, 0.14690332535191575,
    0.14544483939987485, 0.14400120822662704, 0.14257248618407015,
    0.14115872706278138, 0.13975998408999274, 0.13837630992758659,
    0.137007756670113, 0.13565437584282858, 0.13431621839975671,
    0.13299333472176861, 0.13168577461468722, 0.13039358730741141,
    0.12911682145006298, 0.12785552511215481, 0.12660974578078127,
    0.12537953035882987, 0.12416492516321609, 0.12296597592313896,
    0.12178272777835975, 0.12061522527750229, 0.11946351237637592,
    0.11832763243632038, 0.11720762822257347, 0.11610354190266076,
    0.11501541504480811, 0.11394328861637676, 0.11288720298232086,
    0.11184719790366748, 0.11082331253602012, 0.10981558542808412,
    0.10882405452021554, 0.10784875714299264, 0.10688973001581042,
    0.10594700924549821, 0.10502063032496023, 0.10411062813183913,
    0.10321703692720313, 0.10233989035425617, 0.10147922143707083,
    0.10063506257934546, 0.099807445563183939, 0.098996401547899071,
    0.098201961068839771, 0.097424154036240884, 0.0966630097340977,
    0.095918556819062917, 0.095190823319368068, 0.094479836633768077,
    0.093785623530509787, 0.0931082101463242, 0.092447621985442319,
    0.091803883918635143, 0.091177020182276858, 0.090567054377433009,
    0.089974009468971272, 0.089397907784697361, 0.08883877101451404,
    0.0882966202096046, 0.087771475781640518, 0.08726335750201264,
    0.086772284501087038, 0.086298275267484625, 0.085841347647385158,
    0.085401518843855273, 0.084978805416200731, 0.084573223279343357,
    0.084184787703221187, 0.083813513312214261, 0.083459414084593453,
    0.083122503351994559, 0.082802793798916252, 0.082500297462242522,
    0.082215025730789426, 0.081946989344876486, 0.081696198395922126,
    0.0814626623260638, 0.081246389927802531, 0.081047389343671838,
    0.080865668065931373, 0.0807012329362844, 0.0805540901456207,
    0.080424245233783165, 0.0803117030893592, 0.080216467949497161,
    0.080138543399746076, 0.080077932373921246, 0.08003463715399356,
    0.08000865937000351 };

  const mxArray *y;
  const mxArray *m;
  const mxArray *m1;
  static const int32_T iv1[2] = { 0, 0 };

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
  const mxArray *m16;
  const mxArray *m17;
  const mxArray *m18;
  const mxArray *m19;
  const mxArray *m20;
  const mxArray *m21;
  const mxArray *m22;
  const mxArray *m23;
  const mxArray *m24;
  const mxArray *m25;
  int32_T iv2[2];
  char_T *sErr;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = NULL;
  obj = &adr.pInterface;
  obj->S0_isInitialized = 0;
  emlrtPushHeapReferenceStackR2018a(sp, &adr, (void *)
    &c_matlabCodegenHandle_matlabCod);
  adr.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2018a(sp, &SD->f0.audioBuffer.pBuffer, (void *)
    &e_matlabCodegenHandle_matlabCod);
  SD->f0.audioBuffer.pBuffer.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2018a(sp, &SD->f0.audioBuffer, (void *)
    &d_matlabCodegenHandle_matlabCod);
  SD->f0.audioBuffer.matlabCodegenIsDeleted = true;

  //  Rate?
  st.site = &emlrtRSI;
  c_audioDeviceReader_audioDevice(&adr);
  st.site = &b_emlrtRSI;
  AsyncBuffercg_AsyncBuffercg(&SD->f0.audioBuffer);

  //  auslesen des Audiobuffers
  // YBuffer(1:classificationRate/2) = categorical({'background'});
  // YBuffer = categorical(1:10,1:10,{'background','background','background','background','background','background','background','background','background','background'}) 
  // YBuffer = categorical({'background'});
  // out = YBuffer;
  for (i = 0; i < 12; i++) {
    r.labels.codes[i] = static_cast<uint8_T>(i + 1U);
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
  for (i = 0; i < 5; i++) {
    r.labels.categoryNames.f7[i] = b_cv[i];
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
  for (i = 0; i < 7; i++) {
    r.labels.categoryNames.f11[i] = cv1[i];
  }

  for (i = 0; i < 10; i++) {
    r.labels.categoryNames.f12[i] = cv2[i];
  }

  r.labels.isProtected = false;
  r.labels.isOrdinal = false;
  st.site = &ob_emlrtRSI;
  emlrtDisplayR2012b(emlrt_marshallOut(&st, r), "var", &emlrtRTEI, sp);
  memcpy(&s.afestr.Window[0], &t0_Window[0], 400U * sizeof(real_T));
  s.afestr.OverlapLength = 240.0;
  s.afestr.SampleRate = 16000.0;
  s.afestr.FFTLength = 512.0;
  for (i = 0; i < 14; i++) {
    s.afestr.SpectralDescriptorInput[i] = t0_SpectralDescriptorInput[i];
  }

  s.afestr.barkSpectrum = true;
  st.site = &pb_emlrtRSI;
  emlrtDisplayR2012b(b_emlrt_marshallOut(&st, &s), "afe", &b_emlrtRTEI, sp);

  // setup(afe.afestr)
  st.site = &c_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  SystemCore_step(&b_st, &adr, varargout_1);
  st.site = &d_emlrtRSI;
  AsyncBuffercg_write(&st, &SD->f0.audioBuffer, varargout_1, iv);
  st.site = &e_emlrtRSI;
  AsyncBuffercg_read(&st, &SD->f0.audioBuffer, out);
  st.site = &g_emlrtRSI;

  //  extract audio features
  i = static_cast<int32_T>(muDoubleScalarFloor((16000.0 - static_cast<real_T>
    (out.size(0))) / 2.0));
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &emlrtDCI, sp);
  }

  i = static_cast<int32_T>(muDoubleScalarCeil((16000.0 - static_cast<real_T>
    (out.size(0))) / 2.0));
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &b_emlrtDCI, sp);
  }

  //  To extract audio features, call |extract|. The output is a Bark spectrum
  //  with time across rows.
  // features = extract(afe.afestr,xPadded)
  //  Determine the denormalization factor to apply.
  // features = features/unNorm;
  //  Take the log.
  // spec = log10(features + epsil);
  //
  // [YPredicted,probs] = classify(trainedNet,spec,'ExecutionEnvironment','cpu'); 
  // WINDOW Analysis window
  //  Specify the analysis window as a numeric vector with more than three
  //  elements. The default is hamming(1024,"periodic").
  emlrtDisplayR2012b(c_emlrt_marshallOut(Window), "Window", &c_emlrtRTEI, sp);

  // OVERLAPLENGTH Number of samples overlapped between windows
  //  Specify the number of samples overlapped between analysis windows as a
  //  positive scalar less than the analysis window length. The default is 512.
  y = NULL;
  m = emlrtCreateDoubleScalar(512.0);
  emlrtAssign(&y, m);
  emlrtDisplayR2012b(y, "OverlapLength", &d_emlrtRTEI, sp);

  // SAMPLERATE Sample rate (Hz)
  //  Specify sample rate as a positive scalar in Hz. The default is 44100 Hz.
  // FFTLENGTH FFT length
  //  Specify the DFT length as a positive scalar integer. The default of this
  //  property is [], which means that the DFT length is equal to the length
  //  of the Window property.
  y = NULL;
  m1 = emlrtCreateNumericArray(2, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&y, m1);
  emlrtDisplayR2012b(y, "FFTLength", &e_emlrtRTEI, sp);

  // SPECTRALDESCRIPTORINPUT Input to spectral descriptors
  //  Specify the input to the low-level spectral shape
  //  descriptors as "linearSpectrum", "melSpectrum", "barkSpectrum", or
  //  "erbSpectrum". The default is "linearSpectrum".
  // SpectralDescriptorInput (1,:) char {mustBeMember(SpectralDescriptorInput,{'linearSpectrum','melSpectrum','barkSpectrum','erbSpectrum'})} = 'linearSpectrum'; 
  // LINEARSPECTRUM Extract linear spectrum
  //  Extract the linear spectrum, specified as true or false. If
  //  linearSpectrum is true, then the object extracts the one-sided linear
  //  spectrum and appends it to the features returned. The default is false.
  y = NULL;
  m2 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m2);
  emlrtDisplayR2012b(y, "linearSpectrum", &f_emlrtRTEI, sp);

  // MELSPECTRUM Extract mel spectrum
  //  Extract the mel spectrum, specified as true or false. If melSpectrum is
  //  true, then the object extracts the mel spectrum and appends it to the
  //  features returned. The default is false.
  //
  //  The mel filter bank is designed using designAuditoryFilterBank. You can
  //  configure the mel spectrum extraction using setExtractorParams.
  //
  //  See also designAuditoryFilterBank, melSpectrogram, setExtractorParams
  y = NULL;
  m3 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m3);
  emlrtDisplayR2012b(y, "melSpectrum", &g_emlrtRTEI, sp);

  // BARKSPECTRUM Extract Bark spectrum
  //  Extract the Bark spectrum, specified as true or false. If barkSpectrum is
  //  true, then the object extracts the Bark spectrum and appends it to the
  //  features returned. The default is false.
  //
  //  The Bark filter bank is designed using designAuditoryFilterBank. You can
  //  configure the Bark spectrum extraction using setExtractorParams.
  //
  //  See also designAuditoryFilterBank, setExtractorParams
  y = NULL;
  m4 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m4);
  emlrtDisplayR2012b(y, "barkSpectrum", &h_emlrtRTEI, sp);

  // ERBSPECTRUM Extract ERB spectrum
  //  Extract the ERB spectrum, specified as true or false. If erbSpectrum is
  //  true, then the object extracts the ERB spectrum and appends it to the
  //  features returned. The default is false.
  //
  //  You can configure the ERB spectrum extraction using setExtractorParams.
  //
  //  See also designAuditoryFilterBank, setExtractorParams
  y = NULL;
  m5 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m5);
  emlrtDisplayR2012b(y, "erbSpectrum", &i_emlrtRTEI, sp);

  // MFCC Extract MFCC
  //  Extract the mfcc, specified as true or false. If mfcc is true, then the
  //  object extracts the mfcc and appends it to the features returned. The
  //  default is false.
  //
  //  You can configure the MFCC feature extraction using setExtractorParams.
  //
  //  See also setExtractorParams
  y = NULL;
  m6 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m6);
  emlrtDisplayR2012b(y, "mfcc", &j_emlrtRTEI, sp);

  // MFCCDELTA Extract delta mfcc
  //  Extract the delta mfcc, specified as true or false. If mfccDelta is true,
  //  then the object extracts the delta mfcc and appends it to the features
  //  returned. The default is false.
  //
  //  You can configure the MFCC feature extraction using setExtractorParams.
  //
  //  See also setExtractorParams
  y = NULL;
  m7 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m7);
  emlrtDisplayR2012b(y, "mfccDelta", &k_emlrtRTEI, sp);

  // MFCCDELTADELTA Extract delta-delta MFCC
  //  Extract the delta-delta MFCC, specified as true or false. If
  //  mfccDeltaDelta is true, then the object extracts the delta-delta mfcc and
  //  appends it to the features returned. The default is false.
  //
  //  You can configure the MFCC feature extraction using setExtractorParams.
  //
  //  See also setExtractorParams
  y = NULL;
  m8 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m8);
  emlrtDisplayR2012b(y, "mfccDeltaDelta", &l_emlrtRTEI, sp);

  // GTCC Extract GTCC
  //  Extract the GTCC, specified as true or false. If gtcc is true, then the
  //  object extracts the GTCC and appends it to the features returned. The
  //  default is false.
  //
  //  You can configure the GTCC feature extraction using setExtractorParams.
  //
  //  See also setExtractorParams
  y = NULL;
  m9 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m9);
  emlrtDisplayR2012b(y, "gtcc", &m_emlrtRTEI, sp);

  // GTCCDELTA Extract delta GTCC
  //  Extract the delta GTCC, specified as true or false. If gtccDelta is true,
  //  then the object extracts the delta GTCC and appends it to the features
  //  returned. The default is false.
  //
  //  You can configure the GTCC feature extraction using setExtractorParams.
  //
  //  See also setExtractorParams
  y = NULL;
  m10 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m10);
  emlrtDisplayR2012b(y, "gtccDelta", &n_emlrtRTEI, sp);

  // GTCCDELTADELTA Extract delta-delta GTCC
  //  Extract the delta-delta GTCC, specified as true or false. If
  //  gtccDeltaDelta is true, then the object extracts the delta-delta gtcc and
  //  appends it to the features returned. The default is false.
  //
  //  You can configure the GTCC feature extraction using setExtractorParams.
  //
  //  See also setExtractorParams
  y = NULL;
  m11 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m11);
  emlrtDisplayR2012b(y, "gtccDeltaDelta", &o_emlrtRTEI, sp);

  // SPECTRALCENTROID Extract spectral centroid
  //  Extract the spectral centroid, specified as true or false. If
  //  spectralCentroid is true, then the object extracts the spectral centroid
  //  and appends it to the features returned. The default is false.
  y = NULL;
  m12 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m12);
  emlrtDisplayR2012b(y, "spectralCentroid", &p_emlrtRTEI, sp);

  // SPECTRALCREST Extract spectral crest
  //  Extract the spectral crest, specified as true or false. If spectralCrest
  //  is true, then the object extracts the spectral crest and appends it to
  //  the features returned. The default is false.
  y = NULL;
  m13 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m13);
  emlrtDisplayR2012b(y, "spectralCrest", &q_emlrtRTEI, sp);

  // SPECTRALDECREASE Extract spectral decrease
  //  Extract the spectral decrease, specified as true or false. If
  //  spectralDecrease is true, then the object extracts the spectral decrease and 
  //  appends it to the features returned. The default is false.
  y = NULL;
  m14 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m14);
  emlrtDisplayR2012b(y, "spectralDecrease", &r_emlrtRTEI, sp);

  // SPECTRALENTROPY Extract spectral entropy
  //  Extract the spectral entropy, specified as true or false. If
  //  spectralEntropy is true, then the object extracts the spectral entropy
  //  and appends it to the features returned. The default is false.
  y = NULL;
  m15 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m15);
  emlrtDisplayR2012b(y, "spectralEntropy", &s_emlrtRTEI, sp);

  // SPECTRALFLATNESS Extract spectral flatness
  //  Extract the spectral flatness, specified as true or false. If
  //  spectralFlatness is true, then the object extracts the spectral flatness
  //  and appends it to the features returned. The default is false.
  y = NULL;
  m16 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m16);
  emlrtDisplayR2012b(y, "spectralFlatness", &t_emlrtRTEI, sp);

  // SPECTRALFLUX Extract spectral flux
  //  Extract the spectral flux, specified as true or false. If spectralFlux is
  //  true, then the object extracts the spectral flux and appends it to the
  //  features returned. The default is false.
  //
  //  You can configure the spectral flux feature extraction using
  //  setExtractorParams.
  //
  //  See also setExtractorParams
  y = NULL;
  m17 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m17);
  emlrtDisplayR2012b(y, "spectralFlux", &u_emlrtRTEI, sp);

  // SPECTRALKURTOSIS Extract spectral kurtosis
  //  Extract the spectral kurtosis, specified as true or false. If
  //  spectralKurtosis is true, then the object extracts the spectral kurtosis
  //  and appends it to the features returned. The default is false.
  y = NULL;
  m18 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m18);
  emlrtDisplayR2012b(y, "spectralKurtosis", &v_emlrtRTEI, sp);

  // SPECTRALROLLOFFPOINT Extract spectral rolloff point
  //  Extract the spectral rolloff point, specified as true or false. If
  //  spectralRolloffPoint is true, then the object extracts the spectral
  //  rolloff point and appends it to the features returned. The default is
  //  false.
  //
  //  You can configure the spectral rolloff point feature extraction using
  //  setExtractorParams.
  //
  //  See also setExtractorParams
  y = NULL;
  m19 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m19);
  emlrtDisplayR2012b(y, "spectralRolloffPoint", &w_emlrtRTEI, sp);

  // SPECTRALSKEWNESS Extract spectral skewness
  //  Extract the spectral skewness, specified as true or false. If
  //  spectralSkewness is true, then the object extracts the spectral skewness
  //  and appends it to the features returned. The default is false.
  y = NULL;
  m20 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m20);
  emlrtDisplayR2012b(y, "spectralSkewness", &x_emlrtRTEI, sp);

  // SPECTRALSLOPE Extract spectral slope
  //  Extract the spectral slope, specified as true or false. If spectralSlope
  //  is true, then the object extracts the spectral slope and appends it to
  //  the features returned. The default is false.
  y = NULL;
  m21 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m21);
  emlrtDisplayR2012b(y, "spectralSlope", &y_emlrtRTEI, sp);

  // SPECTRALSPREAD Extract spectral spread
  //  Extract the spectral spread, specified as true or false. If
  //  spectralSpread is true, then the object extracts the spectral spread and
  //  appends it to the features returned. The default is false.
  y = NULL;
  m22 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m22);
  emlrtDisplayR2012b(y, "spectralSpread", &ab_emlrtRTEI, sp);

  // PITCH Extract pitch
  //  Extract the pitch, specified as true or false. If pitch is true, then the
  //  object extracts the pitch and appends it to the features returned. The
  //  default is false.
  //
  //  You can configure the pitch feature extraction using setExtractorParams.
  //
  //  See also setExtractorParams
  y = NULL;
  m23 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m23);
  emlrtDisplayR2012b(y, "pitch", &bb_emlrtRTEI, sp);

  // HARMONICRATIO Extract harmonic ratio
  //  Extract the harmonic ratio, specified as true or false. If harmonicRatio
  //  is true, then the object extracts the harmonic ratio and appends it to
  //  the features returned. The default is false.
  y = NULL;
  m24 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m24);
  emlrtDisplayR2012b(y, "harmonicRatio", &cb_emlrtRTEI, sp);

  //  Flag for setup
  y = NULL;
  m25 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y, m25);
  emlrtDisplayR2012b(y, "pIsInitialized", &db_emlrtRTEI, sp);

  //  Properties to hold user-specified feature extractor parameters
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pmfccUserSpecifiedParams", &eb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pgtccUserSpecifiedParams", &fb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pspectralFluxUserSpecifiedParams", &gb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pspectralRolloffPointUserSpecifiedParams",
                     &hb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "plinearSpectrumUserSpecifiedParams", &ib_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pmelSpectrumUserSpecifiedParams", &jb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pbarkSpectrumUserSpecifiedParams", &kb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "perbSpectrumUserSpecifiedParams", &lb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "ppitchUserSpecifiedParams", &mb_emlrtRTEI, sp);

  //  Convenience properties to navigate the feature extraction pipeline
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pPipelineParameters", &nb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pExtractorParameters", &ob_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pOutputIndex", &pb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pOutputIndexReduced", &qb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pUseSpectrum", &rb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pUseHalfSpectrum", &sb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pUsePowerSpectrum", &tb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pUseMagnitudeSpectrum", &ub_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pExtractSpectralDescriptor", &vb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pCalculateGTCC", &wb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pCalculateMFCC", &xb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pCalculateBarkSpectrum", &yb_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pCalculateMelSpectrum", &ac_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pCalculateLinearSpectrum", &bc_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pCalculateERBSpectrum", &cc_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pFeaturesToExtract", &dc_emlrtRTEI, sp);
  y = NULL;
  iv2[0] = 0;
  iv2[1] = 0;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv2[0]));
  emlrtDisplayR2012b(y, "pFFTLength", &ec_emlrtRTEI, sp);

  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  st.site = &f_emlrtRSI;
  d_matlabCodegenHandle_matlabCod(&st, &SD->f0.audioBuffer);
  st.site = &f_emlrtRSI;
  e_matlabCodegenHandle_matlabCod(&st, &SD->f0.audioBuffer.pBuffer);
  st.site = &f_emlrtRSI;
  c_matlabCodegenHandle_matlabCod(&st, &adr);
  st.site = &f_emlrtRSI;
  obj = &adr.pInterface;

  // System object Destructor function: audiointerface.audioDeviceReader
  if (obj->S0_isInitialized == 1) {
    obj->S0_isInitialized = 2;

    // System object Terminate function: audiointerface.audioDeviceReader
    sErr = GetErrorBuffer(&obj->W0_AudioDeviceLib[0U]);
    LibTerminate(&obj->W0_AudioDeviceLib[0U]);
    if (*sErr != 0) {
      PrintError(sErr);
    }

    LibDestroy_Audio(&obj->W0_AudioDeviceLib[0U], 0, 1);
    DestroyHostLibrary(&obj->W0_AudioDeviceLib[0U]);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (test.cpp)
