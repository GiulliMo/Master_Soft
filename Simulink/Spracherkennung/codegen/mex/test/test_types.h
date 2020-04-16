//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  test_types.h
//
//  Code generation for function 'test_types'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#ifdef _MSC_VER

#pragma warning(push)
#pragma warning(disable : 4251)

#endif

// Type Definitions
struct cell_wrap_3
{
  uint32_T f1[8];
};

struct dsp_private_AsyncBuffercgHelper
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_3 inputVarSize[1];
  int32_T NumChannels;
  real_T Cache[16001];
  int32_T CumulativeOverrun;
  int32_T CumulativeUnderrun;
  int32_T ReadPointer;
  int32_T WritePointer;
  boolean_T c_AsyncBuffercgHelper_isInitial;
};

struct dsp_private_AsyncBuffercg
{
  boolean_T matlabCodegenIsDeleted;
  dsp_private_AsyncBuffercgHelper pBuffer;
};

struct testStackData
{
  struct {
    dsp_private_AsyncBuffercg audioBuffer;
  } f0;
};

struct c_audiointerface_audioDeviceRea
{
  int32_T S0_isInitialized;
  uint8_T W0_AudioDeviceLib[1096];
  real_T O0_Y0[800];
  uint32_T O1_Y1;
};

struct audioDeviceReader
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  c_audiointerface_audioDeviceRea pInterface;
};

#ifdef _MSC_VER

#pragma warning(pop)

#endif

// End of code generation (test_types.h)
