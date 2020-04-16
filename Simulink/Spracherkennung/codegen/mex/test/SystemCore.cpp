//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  SystemCore.cpp
//
//  Code generation for function 'SystemCore'
//


// Include files
#include "SystemCore.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"
#include "test.h"
#include "test_data.h"

// Variable Definitions
static emlrtRSInfo h_emlrtRSI = { 1,   // lineNo
  "audioDeviceReader/releaseImpl",     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/compiled/audioDeviceReader.p"// pathName 
};

static emlrtRTEInfo fc_emlrtRTEI = { 1,// lineNo
  1,                                   // colNo
  "SystemCore/release",                // fName
  "/usr/local/MATLAB/R2020a/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"// pName 
};

static emlrtRTEInfo gc_emlrtRTEI = { 15,// lineNo
  1,                                   // colNo
  "reset",                             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/scomp/reset.m"// pName
};

static emlrtRTEInfo hc_emlrtRTEI = { 43,// lineNo
  1,                                   // colNo
  "setup",                             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/scomp/setup.m"// pName
};

static emlrtRTEInfo ic_emlrtRTEI = { 51,// lineNo
  5,                                   // colNo
  "step",                              // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/scomp/step.m"// pName
};

// Function Definitions
void SystemCore_step(const emlrtStack *sp, audioDeviceReader *obj, real_T
                     varargout_1[800])
{
  char_T *sErr;
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
  if (obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(sp, &fc_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen",
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (obj->isInitialized != 1) {
    st.site = &l_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    obj->isSetupComplete = false;
    if (obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &fc_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    obj->isInitialized = 1;
    c_st.site = &l_emlrtRSI;
    d_st.site = &h_emlrtRSI;
    if (obj->pInterface.S0_isInitialized != 1) {
      if (obj->pInterface.S0_isInitialized == 2) {
        emlrtErrorWithMessageIdR2018a(&d_st, &hc_emlrtRTEI,
          "MATLAB:system:setupCalledWhenLockedReleasedCodegen",
          "MATLAB:system:setupCalledWhenLockedReleasedCodegen", 0);
      }

      obj->pInterface.S0_isInitialized = 1;

      // System object Start function: audiointerface.audioDeviceReader
      sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
      CreateHostLibrary("libmwhostlibaudio.so",
                        &obj->pInterface.W0_AudioDeviceLib[0U]);
      if (*sErr == 0) {
        LibCreate_Audio(&obj->pInterface.W0_AudioDeviceLib[0U], 0, "Default", 8,
                        0, 1, 16000.0, 3, 800, 8000, 800, 5, NULL);
      }

      if (*sErr != 0) {
        DestroyHostLibrary(&obj->pInterface.W0_AudioDeviceLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
      }
    } else {
      emlrtErrorWithMessageIdR2018a(&d_st, &hc_emlrtRTEI,
        "MATLAB:system:setupCalledWhenLockedCodegen",
        "MATLAB:system:setupCalledWhenLockedCodegen", 0);
    }

    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    b_st.site = &l_emlrtRSI;
    c_st.site = &h_emlrtRSI;
    if (obj->pInterface.S0_isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(&c_st, &gc_emlrtRTEI,
        "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen",
        "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen", 0);
    }
  }

  st.site = &l_emlrtRSI;
  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
  }

  st.site = &l_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  if (obj->pInterface.S0_isInitialized != 1) {
    if (obj->pInterface.S0_isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(&b_st, &ic_emlrtRTEI,
        "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen",
        "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen", 0);
    }

    obj->pInterface.S0_isInitialized = 1;
    c_st.site = NULL;

    // System object Start function: audiointerface.audioDeviceReader
    sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
    CreateHostLibrary("libmwhostlibaudio.so", &obj->
                      pInterface.W0_AudioDeviceLib[0U]);
    if (*sErr == 0) {
      LibCreate_Audio(&obj->pInterface.W0_AudioDeviceLib[0U], 0, "Default", 8, 0,
                      1, 16000.0, 3, 800, 8000, 800, 5, NULL);
    }

    if (*sErr != 0) {
      DestroyHostLibrary(&obj->pInterface.W0_AudioDeviceLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
    }
  }

  c_st.site = NULL;

  // System object Outputs function: audiointerface.audioDeviceReader
  sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
  LibOutputs_Audio(&obj->pInterface.W0_AudioDeviceLib[0U],
                   &obj->pInterface.O0_Y0[0U], 5, 800, &obj->pInterface.O1_Y1);
  if (*sErr != 0) {
    PrintError(sErr);
  }

  for (int32_T i = 0; i < 800; i++) {
    varargout_1[i] = obj->pInterface.O0_Y0[i];
  }
}

// End of code generation (SystemCore.cpp)
