//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  AsyncBuffercgHelper.cpp
//
//  Code generation for function 'AsyncBuffercgHelper'
//


// Include files
#include "AsyncBuffercgHelper.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"
#include "test.h"

// Variable Definitions
static emlrtRSInfo v_emlrtRSI = { 116, // lineNo
  "AsyncBuffercgHelper/stepImpl",      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pathName 
};

static emlrtRSInfo w_emlrtRSI = { 208, // lineNo
  "AsyncBuffercgHelper/write",         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pathName 
};

static emlrtRSInfo x_emlrtRSI = { 222, // lineNo
  "AsyncBuffercgHelper/write",         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pathName 
};

static emlrtRSInfo gb_emlrtRSI = { 448,// lineNo
  "AsyncBuffercgHelper/ReadSamplesFromBuffer",// fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pathName 
};

static emlrtRSInfo hb_emlrtRSI = { 395,// lineNo
  "AsyncBuffercgHelper/ReadSamplesFromBuffer",// fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pathName 
};

static emlrtMCInfo emlrtMCI = { 27,    // lineNo
  5,                                   // colNo
  "error",                             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/lang/error.m"// pName
};

static emlrtECInfo emlrtECI = { -1,    // nDims
  227,                                 // lineNo
  13,                                  // colNo
  "AsyncBuffercgHelper/write",         // fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static emlrtBCInfo emlrtBCI = { 1,     // iFirst
  16001,                               // iLast
  227,                                 // lineNo
  23,                                  // colNo
  "",                                  // aName
  "AsyncBuffercgHelper/write",         // fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m",// pName 
  3                                    // checkKind
};

static emlrtECInfo b_emlrtECI = { -1,  // nDims
  468,                                 // lineNo
  21,                                  // colNo
  "AsyncBuffercgHelper/ReadSamplesFromBuffer",// fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static emlrtBCInfo b_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  468,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "AsyncBuffercgHelper/ReadSamplesFromBuffer",// fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo c_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  468,                                 // lineNo
  25,                                  // colNo
  "",                                  // aName
  "AsyncBuffercgHelper/ReadSamplesFromBuffer",// fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo c_emlrtDCI = { 468, // lineNo
  60,                                  // colNo
  "AsyncBuffercgHelper/ReadSamplesFromBuffer",// fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m",// pName 
  4                                    // checkKind
};

static emlrtECInfo c_emlrtECI = { -1,  // nDims
  462,                                 // lineNo
  17,                                  // colNo
  "AsyncBuffercgHelper/ReadSamplesFromBuffer",// fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static emlrtBCInfo d_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  462,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "AsyncBuffercgHelper/ReadSamplesFromBuffer",// fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo e_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  462,                                 // lineNo
  21,                                  // colNo
  "",                                  // aName
  "AsyncBuffercgHelper/ReadSamplesFromBuffer",// fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo d_emlrtDCI = { 463, // lineNo
  27,                                  // colNo
  "AsyncBuffercgHelper/ReadSamplesFromBuffer",// fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m",// pName 
  4                                    // checkKind
};

static emlrtBCInfo f_emlrtBCI = { 1,   // iFirst
  16001,                               // iLast
  457,                                 // lineNo
  29,                                  // colNo
  "",                                  // aName
  "AsyncBuffercgHelper/ReadSamplesFromBuffer",// fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo nc_emlrtRTEI = { 126,// lineNo
  9,                                   // colNo
  "colon",                             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"// pName
};

static emlrtRTEInfo oc_emlrtRTEI = { 222,// lineNo
  17,                                  // colNo
  "AsyncBuffercgHelper",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static emlrtRTEInfo pc_emlrtRTEI = { 215,// lineNo
  17,                                  // colNo
  "AsyncBuffercgHelper",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static emlrtRTEInfo qc_emlrtRTEI = { 448,// lineNo
  21,                                  // colNo
  "AsyncBuffercgHelper",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static emlrtRTEInfo rc_emlrtRTEI = { 437,// lineNo
  21,                                  // colNo
  "AsyncBuffercgHelper",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static emlrtRTEInfo sc_emlrtRTEI = { 425,// lineNo
  21,                                  // colNo
  "AsyncBuffercgHelper",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static emlrtRTEInfo tc_emlrtRTEI = { 457,// lineNo
  13,                                  // colNo
  "AsyncBuffercgHelper",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static emlrtRTEInfo uc_emlrtRTEI = { 466,// lineNo
  21,                                  // colNo
  "AsyncBuffercgHelper",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static const char_T cv[25] = { 'P', 'o', 'i', 'n', 't', 'e', 'r', 's', ' ', 'm',
  'u', 's', 't', ' ', 'b', 'e', ' ', 'b', 'o', 'u', 'n', 'd', 'e', 'd', '.' };

static emlrtRSInfo qb_emlrtRSI = { 27, // lineNo
  "error",                             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/lang/error.m"// pathName
};

// Function Declarations
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

// Function Definitions
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

int32_T AsyncBuffercgHelper_stepImpl(const emlrtStack *sp,
  dsp_private_AsyncBuffercgHelper *obj, const real_T in_data[], const int32_T
  in_size[1])
{
  int32_T overrun;
  int32_T wPtr;
  int32_T rPtr;
  int32_T c;
  const mxArray *y;
  static const int32_T iv[2] = { 1, 25 };

  int32_T y_data[16001];
  int32_T yk;
  int32_T k;
  coder::array<int32_T, 2U> b_y;
  coder::array<int32_T, 2U> bc;
  int32_T tmp_size[1];
  int16_T tmp_data[16800];
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
  st.site = &v_emlrtRSI;
  wPtr = obj->WritePointer;
  rPtr = obj->ReadPointer;
  overrun = 0;
  if ((wPtr < 1) || (wPtr > 16001)) {
    const mxArray *m;
    b_st.site = &w_emlrtRSI;
    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&b_st, 25, m, &cv[0]);
    emlrtAssign(&y, m);
    c_st.site = &qb_emlrtRSI;
    error(&c_st, y, &emlrtMCI);
  }

  c = wPtr + 799;
  if (wPtr + 799 > 16001) {
    int32_T n;
    int32_T y_size_idx_1;
    c = wPtr - 15202;
    n = 16002 - wPtr;
    y_size_idx_1 = 16002 - wPtr;
    y_data[0] = wPtr;
    yk = wPtr;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }

    b_y.set_size((&nc_emlrtRTEI), (&st), 1, (wPtr - 15202));
    b_y[0] = 1;
    yk = 1;
    for (k = 2; k <= c; k++) {
      yk++;
      b_y[k - 1] = yk;
    }

    bc.set_size((&pc_emlrtRTEI), (&st), 1, (y_size_idx_1 + b_y.size(1)));
    for (k = 0; k < y_size_idx_1; k++) {
      bc[k] = y_data[k];
    }

    yk = b_y.size(1);
    for (k = 0; k < yk; k++) {
      bc[k + y_size_idx_1] = b_y[k];
    }

    if (wPtr <= rPtr) {
      overrun = (wPtr - rPtr) + 800;
    } else {
      if (rPtr <= wPtr - 15202) {
        yk = wPtr - 15202;
        if ((yk >= 0) && (rPtr < yk - MAX_int32_T)) {
          yk = MAX_int32_T;
        } else if ((yk < 0) && (rPtr > yk - MIN_int32_T)) {
          yk = MIN_int32_T;
        } else {
          yk -= rPtr;
        }

        if (yk > 2147483646) {
          overrun = MAX_int32_T;
        } else {
          overrun = yk + 1;
        }
      }
    }
  } else {
    int32_T n;
    b_st.site = &x_emlrtRSI;
    if (wPtr + 799 < wPtr) {
      n = 0;
    } else {
      n = 800;
    }

    if (n > 0) {
      y_data[0] = wPtr;
      yk = wPtr;
      for (k = 2; k <= n; k++) {
        yk++;
        y_data[k - 1] = yk;
      }
    }

    bc.set_size((&oc_emlrtRTEI), (&st), 1, n);
    for (k = 0; k < n; k++) {
      bc[k] = y_data[k];
    }

    if ((wPtr <= rPtr) && (rPtr <= wPtr + 799)) {
      overrun = (wPtr - rPtr) + 800;
    }
  }

  tmp_size[0] = bc.size(1);
  yk = bc.size(1);
  for (k = 0; k < yk; k++) {
    if ((static_cast<int16_T>(bc[k]) < 1) || (static_cast<int16_T>(bc[k]) >
         16001)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(static_cast<int16_T>
        (bc[k])), 1, 16001, &emlrtBCI, &st);
    }

    tmp_data[k] = static_cast<int16_T>(static_cast<int16_T>(bc[k]) - 1);
  }

  emlrtSubAssignSizeCheckR2012b(&tmp_size[0], 1, &in_size[0], 1, &emlrtECI, &st);
  for (k = 0; k < 800; k++) {
    obj->Cache[tmp_data[k]] = in_data[k];
  }

  if (c + 1 > 16001) {
    wPtr = 1;
  } else {
    wPtr = c + 1;
  }

  if (overrun != 0) {
    rPtr = wPtr;
  }

  yk = obj->CumulativeOverrun;
  if ((yk < 0) && (overrun < MIN_int32_T - yk)) {
    yk = MIN_int32_T;
  } else if ((yk > 0) && (overrun > MAX_int32_T - yk)) {
    yk = MAX_int32_T;
  } else {
    yk += overrun;
  }

  obj->CumulativeOverrun = yk;
  obj->WritePointer = wPtr;
  obj->ReadPointer = rPtr;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return overrun;
}

void c_AsyncBuffercgHelper_ReadSampl(const emlrtStack *sp, const
  dsp_private_AsyncBuffercgHelper *obj, coder::array<real_T, 1U> &out, int32_T
  *underrun, int32_T *overlapUnderrun, int32_T *c)
{
  int32_T wPtr;
  int32_T yk;
  int32_T rPtr;
  const mxArray *y;
  static const int32_T iv[2] = { 1, 25 };

  int32_T y_data[16001];
  int32_T k;
  coder::array<int32_T, 2U> b_y;
  coder::array<int32_T, 2U> readIdx;
  int32_T iv1[1];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  wPtr = obj->WritePointer;
  *underrun = 0;
  *overlapUnderrun = 0;
  yk = obj->ReadPointer;
  if (yk > 2147483646) {
    rPtr = MAX_int32_T;
  } else {
    rPtr = yk + 1;
  }

  if (rPtr > 16001) {
    rPtr = 1;
  }

  if ((wPtr < 1) || (wPtr > 16001) || (rPtr < 1)) {
    const mxArray *m;
    st.site = &hb_emlrtRSI;
    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 25, m, &cv[0]);
    emlrtAssign(&y, m);
    b_st.site = &qb_emlrtRSI;
    error(&b_st, y, &emlrtMCI);
  }

  *c = rPtr + 799;
  if (rPtr - 15200 < 1) {
    int32_T n;
    int32_T y_size_idx_1;
    n = 15201 - rPtr;
    y_size_idx_1 = 15201 - rPtr;
    y_data[0] = rPtr + 801;
    yk = rPtr + 801;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }

    b_y.set_size((&nc_emlrtRTEI), sp, 1, (rPtr + 799));
    b_y[0] = 1;
    yk = 1;
    for (k = 2; k <= *c; k++) {
      yk++;
      b_y[k - 1] = yk;
    }

    readIdx.set_size((&sc_emlrtRTEI), sp, 1, (y_size_idx_1 + b_y.size(1)));
    for (k = 0; k < y_size_idx_1; k++) {
      readIdx[k] = y_data[k];
    }

    yk = b_y.size(1);
    for (k = 0; k < yk; k++) {
      readIdx[k + y_size_idx_1] = b_y[k];
    }

    if ((rPtr <= wPtr) && (wPtr <= rPtr + 799)) {
      *underrun = (rPtr - wPtr) + 800;
    } else if (wPtr < rPtr) {
      *overlapUnderrun = (wPtr - rPtr) + 15201;
    } else {
      if (wPtr > rPtr + 801) {
        *overlapUnderrun = (wPtr - rPtr) - 800;
      }
    }
  } else if (rPtr + 799 > 16001) {
    int32_T n;
    int32_T y_size_idx_1;
    *c = rPtr - 15202;
    n = 31202 - rPtr;
    y_size_idx_1 = 31202 - rPtr;
    y_data[0] = rPtr - 15200;
    yk = rPtr - 15200;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }

    b_y.set_size((&nc_emlrtRTEI), sp, 1, (rPtr - 15202));
    b_y[0] = 1;
    yk = 1;
    for (k = 2; k <= *c; k++) {
      yk++;
      b_y[k - 1] = yk;
    }

    readIdx.set_size((&rc_emlrtRTEI), sp, 1, (y_size_idx_1 + b_y.size(1)));
    for (k = 0; k < y_size_idx_1; k++) {
      readIdx[k] = y_data[k];
    }

    yk = b_y.size(1);
    for (k = 0; k < yk; k++) {
      readIdx[k + y_size_idx_1] = b_y[k];
    }

    if (rPtr <= wPtr) {
      *underrun = (rPtr - wPtr) + 800;
    } else if (wPtr <= rPtr - 15202) {
      *underrun = (rPtr - wPtr) - 15201;
    } else {
      if ((rPtr - 15200 < wPtr) && (wPtr < rPtr)) {
        *overlapUnderrun = (wPtr - rPtr) + 15201;
      }
    }
  } else {
    int32_T n;
    st.site = &gb_emlrtRSI;
    if (rPtr + 799 < rPtr - 15200) {
      n = 0;
    } else {
      n = 16000;
    }

    if (n > 0) {
      y_data[0] = rPtr - 15200;
      yk = rPtr - 15200;
      for (k = 2; k <= n; k++) {
        yk++;
        y_data[k - 1] = yk;
      }
    }

    readIdx.set_size((&qc_emlrtRTEI), sp, 1, n);
    for (k = 0; k < n; k++) {
      readIdx[k] = y_data[k];
    }

    if ((rPtr <= wPtr) && (wPtr <= rPtr + 799)) {
      *underrun = (rPtr - wPtr) + 800;
    } else {
      if ((rPtr - 15200 <= wPtr) && (wPtr < rPtr)) {
        *overlapUnderrun = (wPtr - rPtr) + 15201;
      }
    }
  }

  out.set_size((&tc_emlrtRTEI), sp, readIdx.size(1));
  yk = readIdx.size(1);
  for (k = 0; k < yk; k++) {
    if ((readIdx[k] < 1) || (readIdx[k] > 16001)) {
      emlrtDynamicBoundsCheckR2012b(readIdx[k], 1, 16001, &f_emlrtBCI, sp);
    }

    out[k] = obj->Cache[readIdx[k] - 1];
  }

  if (*underrun != 0) {
    if (16001 - *underrun > 16000) {
      k = -1;
      yk = -1;
    } else {
      k = 16001 - *underrun;
      if ((k < 1) || (k > out.size(0))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, out.size(0), &e_emlrtBCI, sp);
      }

      k -= 2;
      if (16000 > out.size(0)) {
        emlrtDynamicBoundsCheckR2012b(16000, 1, out.size(0), &d_emlrtBCI, sp);
      }

      yk = 15999;
    }

    if (*underrun < 0) {
      emlrtNonNegativeCheckR2012b(static_cast<real_T>(*underrun), &d_emlrtDCI,
        sp);
    }

    iv1[0] = yk - k;
    emlrtSubAssignSizeCheckR2012b(&iv1[0], 1, underrun, 1, &c_emlrtECI, sp);
    for (yk = 0; yk < *underrun; yk++) {
      out[(k + yk) + 1] = 0.0;
    }
  } else {
    if (*overlapUnderrun != 0) {
      if (*overlapUnderrun == 16000) {
        out.set_size((&uc_emlrtRTEI), sp, 16000);
        for (k = 0; k < 16000; k++) {
          out[k] = 0.0;
        }
      } else {
        if (1 > *overlapUnderrun) {
          k = 0;
        } else {
          if (1 > out.size(0)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, out.size(0), &c_emlrtBCI, sp);
          }

          if (*overlapUnderrun > out.size(0)) {
            emlrtDynamicBoundsCheckR2012b(*overlapUnderrun, 1, out.size(0),
              &b_emlrtBCI, sp);
          }

          k = *overlapUnderrun;
        }

        if (*overlapUnderrun < 0) {
          emlrtNonNegativeCheckR2012b(static_cast<real_T>(*overlapUnderrun),
            &c_emlrtDCI, sp);
        }

        emlrtSubAssignSizeCheckR2012b(&k, 1, overlapUnderrun, 1, &b_emlrtECI, sp);
        for (k = 0; k < *overlapUnderrun; k++) {
          out[k] = 0.0;
        }
      }
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (AsyncBuffercgHelper.cpp)
