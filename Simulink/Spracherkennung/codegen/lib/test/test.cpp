//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Apr-2020 12:22:45
//

// Include Files
#include "test.h"
#include "AsyncBuffercg.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "SystemCore.h"
#include "audioDeviceReader.h"
#include "matlabCodegenHandle.h"

// Function Definitions

//
// Arguments    : double in3
//                coder::array<double, 1U> *out
// Return Type  : void
//
void test(double, coder::array<double, 1U> &out)
{
  static dsp_private_AsyncBuffercg audioBuffer;
  c_audiointerface_audioDeviceRea *obj;
  audioDeviceReader adr;
  double varargout_1[800];
  char *sErr;
  audioBuffer.pBuffer.matlabCodegenIsDeleted = true;
  audioBuffer.matlabCodegenIsDeleted = true;
  obj = &adr.pInterface;
  obj->S0_isInitialized = 0;
  adr.matlabCodegenIsDeleted = true;

  //  Rate?
  adr.init();
  audioBuffer.init();

  //  auslesen des Audiobuffers
  // YBuffer(1:classificationRate/2) = categorical({'background'});
  // YBuffer = categorical(1:10,1:10,{'background','background','background','background','background','background','background','background','background','background'}) 
  // YBuffer = categorical({'background'});
  // out = YBuffer;
  adr.step(varargout_1);
  audioBuffer.write(varargout_1);
  audioBuffer.read(out);
  adr.matlabCodegenDestructor();
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

  audioBuffer.matlabCodegenDestructor();
  audioBuffer.pBuffer.matlabCodegenDestructor();
}

//
// File trailer for test.cpp
//
// [EOF]
//
