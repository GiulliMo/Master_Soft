//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  audioDeviceReader.cpp
//
//  Code generation for function 'audioDeviceReader'
//


// Include files
#include "audioDeviceReader.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"
#include "test.h"

// Function Definitions
audioDeviceReader *c_audioDeviceReader_audioDevice(audioDeviceReader *obj)
{
  audioDeviceReader *b_obj;
  b_obj = obj;
  b_obj->isInitialized = 0;

  // System object Constructor function: audiointerface.audioDeviceReader
  b_obj->pInterface.S0_isInitialized = 0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

// End of code generation (audioDeviceReader.cpp)
