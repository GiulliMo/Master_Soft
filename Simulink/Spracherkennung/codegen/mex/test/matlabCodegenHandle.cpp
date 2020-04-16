//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  matlabCodegenHandle.cpp
//
//  Code generation for function 'matlabCodegenHandle'
//


// Include files
#include "matlabCodegenHandle.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "rt_nonfinite.h"
#include "test.h"

// Function Definitions
void c_matlabCodegenHandle_matlabCod(const emlrtStack *sp, audioDeviceReader
  *obj)
{
  char_T *sErr;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
      if (obj->isSetupComplete && (obj->pInterface.S0_isInitialized == 1)) {
        // System object Destructor function: audiointerface.audioDeviceReader
        obj->pInterface.S0_isInitialized = 2;

        // System object Terminate function: audiointerface.audioDeviceReader
        sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
        LibTerminate(&obj->pInterface.W0_AudioDeviceLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }

        LibDestroy_Audio(&obj->pInterface.W0_AudioDeviceLib[0U], 0, 1);
        DestroyHostLibrary(&obj->pInterface.W0_AudioDeviceLib[0U]);
      }
    }
  }
}

void d_matlabCodegenHandle_matlabCod(const emlrtStack *sp,
  dsp_private_AsyncBuffercg *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

void e_matlabCodegenHandle_matlabCod(const emlrtStack *sp,
  dsp_private_AsyncBuffercgHelper *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
      if (obj->isSetupComplete) {
        obj->ReadPointer = 1;
        obj->WritePointer = 2;
        obj->CumulativeOverrun = 0;
        obj->CumulativeUnderrun = 0;
        obj->c_AsyncBuffercgHelper_isInitial = false;
        obj->NumChannels = -1;
      }
    }
  }
}

// End of code generation (matlabCodegenHandle.cpp)
