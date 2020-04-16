//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  AsyncBuffercg.cpp
//
//  Code generation for function 'AsyncBuffercg'
//


// Include files
#include "AsyncBuffercg.h"
#include "AsyncBuffercgHelper.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"
#include "test.h"

// Variable Definitions
static emlrtRSInfo r_emlrtRSI = { 59,  // lineNo
  "AsyncBuffercg/write",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercg.m"// pathName 
};

static emlrtRSInfo s_emlrtRSI = { 1,   // lineNo
  "SystemCore/step",                   // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pathName 
};

static emlrtRSInfo t_emlrtRSI = { 1,   // lineNo
  "SystemCore/setupAndReset",          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pathName 
};

static emlrtRSInfo u_emlrtRSI = { 1,   // lineNo
  "SystemCore/setup",                  // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pathName 
};

static emlrtRSInfo eb_emlrtRSI = { 114,// lineNo
  "AsyncBuffercg/read",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercg.m"// pathName 
};

static emlrtRSInfo fb_emlrtRSI = { 334,// lineNo
  "AsyncBuffercgHelper/read",          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pathName 
};

static emlrtRTEInfo jc_emlrtRTEI = { 1,// lineNo
  1,                                   // colNo
  "SystemCore/step",                   // fName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pName 
};

static emlrtRTEInfo kc_emlrtRTEI = { 101,// lineNo
  13,                                  // colNo
  "AsyncBuffercgHelper/validateInputsImpl",// fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

static emlrtRTEInfo lc_emlrtRTEI = { 1,// lineNo
  1,                                   // colNo
  "SystemCore/setup",                  // fName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pName 
};

static emlrtRTEInfo mc_emlrtRTEI = { 324,// lineNo
  13,                                  // colNo
  "AsyncBuffercgHelper/read",          // fName
  "/usr/local/MATLAB/R2020a/toolbox/dsp/dsp/+dsp/+private/AsyncBuffercgHelper.m"// pName 
};

// Function Definitions
dsp_private_AsyncBuffercg *AsyncBuffercg_AsyncBuffercg(dsp_private_AsyncBuffercg
  *obj)
{
  dsp_private_AsyncBuffercg *b_obj;
  b_obj = obj;
  b_obj->pBuffer.NumChannels = -1;
  b_obj->pBuffer.isInitialized = 0;
  b_obj->pBuffer.matlabCodegenIsDeleted = false;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

void AsyncBuffercg_read(const emlrtStack *sp, dsp_private_AsyncBuffercg *obj,
  coder::array<real_T, 1U> &out)
{
  int32_T underrun;
  int32_T overlapUnderrun;
  int32_T rPtr;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!obj->pBuffer.c_AsyncBuffercgHelper_isInitial) {
    emlrtErrorWithMessageIdR2018a(&st, &mc_emlrtRTEI,
      "dsp:system:AsyncBuffer:isInitialized",
      "dsp:system:AsyncBuffer:isInitialized", 0);
  }

  b_st.site = &fb_emlrtRSI;
  c_AsyncBuffercgHelper_ReadSampl(&b_st, &obj->pBuffer, out, &underrun,
    &overlapUnderrun, &rPtr);
  if (underrun != 0) {
    overlapUnderrun = obj->pBuffer.WritePointer;
    if (overlapUnderrun < -2147483647) {
      rPtr = MIN_int32_T;
    } else {
      rPtr = overlapUnderrun - 1;
    }
  }

  overlapUnderrun = obj->pBuffer.CumulativeUnderrun;
  if ((overlapUnderrun < 0) && (underrun < MIN_int32_T - overlapUnderrun)) {
    overlapUnderrun = MIN_int32_T;
  } else if ((overlapUnderrun > 0) && (underrun > MAX_int32_T - overlapUnderrun))
  {
    overlapUnderrun = MAX_int32_T;
  } else {
    overlapUnderrun += underrun;
  }

  obj->pBuffer.CumulativeUnderrun = overlapUnderrun;
  obj->pBuffer.ReadPointer = rPtr;
}

void AsyncBuffercg_write(const emlrtStack *sp, dsp_private_AsyncBuffercg *obj,
  const real_T in_data[], const int32_T in_size[1])
{
  dsp_private_AsyncBuffercgHelper *b_obj;
  boolean_T anyInputSizeChanged;
  int32_T i;
  boolean_T exitg1;
  static const int16_T iv[8] = { 800, 1, 1, 1, 1, 1, 1, 1 };

  cell_wrap_3 varSizes[1];
  static const int16_T iv1[8] = { 800, 1, 1, 1, 1, 1, 1, 1 };

  static const int16_T inSize[8] = { 800, 1, 1, 1, 1, 1, 1, 1 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &r_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_obj = &obj->pBuffer;
  if (obj->pBuffer.isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(&st, &jc_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen",
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (obj->pBuffer.isInitialized != 1) {
    b_st.site = &s_emlrtRSI;
    c_st.site = &t_emlrtRSI;
    obj->pBuffer.isSetupComplete = false;
    if (obj->pBuffer.isInitialized != 0) {
      emlrtErrorWithMessageIdR2018a(&c_st, &lc_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    obj->pBuffer.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      varSizes[0].f1[i] = static_cast<uint32_T>(iv1[i]);
    }

    obj->pBuffer.inputVarSize[0] = varSizes[0];
    d_st.site = &u_emlrtRSI;
    if ((obj->pBuffer.NumChannels != -1) && (1 != obj->pBuffer.NumChannels)) {
      emlrtErrorWithMessageIdR2018a(&d_st, &kc_emlrtRTEI,
        "dsp:system:Shared:numChannels", "dsp:system:Shared:numChannels", 0);
    }

    obj->pBuffer.NumChannels = 1;
    obj->pBuffer.c_AsyncBuffercgHelper_isInitial = true;
    for (i = 0; i < 16001; i++) {
      obj->pBuffer.Cache[i] = 0.0;
    }

    obj->pBuffer.isSetupComplete = true;
    c_st.site = &t_emlrtRSI;
    obj->pBuffer.ReadPointer = 1;
    obj->pBuffer.WritePointer = 2;
    obj->pBuffer.CumulativeOverrun = 0;
    obj->pBuffer.CumulativeUnderrun = 0;
    for (i = 0; i < 16001; i++) {
      obj->pBuffer.Cache[i] = 0.0;
    }
  }

  b_st.site = &s_emlrtRSI;
  anyInputSizeChanged = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 8)) {
    if (b_obj->inputVarSize[0].f1[i] != static_cast<uint32_T>(iv[i])) {
      anyInputSizeChanged = true;
      for (i = 0; i < 8; i++) {
        b_obj->inputVarSize[0].f1[i] = static_cast<uint32_T>(inSize[i]);
      }

      exitg1 = true;
    } else {
      i++;
    }
  }

  if (anyInputSizeChanged) {
    b_st.site = &s_emlrtRSI;
    if ((obj->pBuffer.NumChannels != -1) && (1 != obj->pBuffer.NumChannels)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &kc_emlrtRTEI,
        "dsp:system:Shared:numChannels", "dsp:system:Shared:numChannels", 0);
    }
  }

  b_st.site = &s_emlrtRSI;
  AsyncBuffercgHelper_stepImpl(&b_st, &obj->pBuffer, in_data, in_size);
}

// End of code generation (AsyncBuffercg.cpp)
