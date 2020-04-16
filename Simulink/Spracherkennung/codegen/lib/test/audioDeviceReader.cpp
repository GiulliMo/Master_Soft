//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: audioDeviceReader.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Apr-2020 12:22:45
//

// Include Files
#include "audioDeviceReader.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "matlabCodegenHandle.h"
#include "test.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : audioDeviceReader *
//
audioDeviceReader *audioDeviceReader::init()
{
  audioDeviceReader *obj;
  obj = this;
  obj->isInitialized = 0;

  // System object Constructor function: audiointerface.audioDeviceReader
  obj->pInterface.S0_isInitialized = 0;
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// File trailer for audioDeviceReader.cpp
//
// [EOF]
//
