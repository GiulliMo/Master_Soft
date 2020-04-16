//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: SystemCore.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Apr-2020 12:22:45
//

// Include Files
#include "SystemCore.h"
#include "AsyncBuffercgHelper.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "matlabCodegenHandle.h"
#include "test.h"
#include <cstring>

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void audioDeviceReader::checkTunableProps()
{
  if (this->TunablePropsChanged) {
    this->TunablePropsChanged = false;
  }
}

//
// Arguments    : void
// Return Type  : void
//
void audioDeviceReader::releaseWrapper()
{
  char *sErr;
  if (this->isSetupComplete && (this->pInterface.S0_isInitialized == 1)) {
    // System object Destructor function: audiointerface.audioDeviceReader
    this->pInterface.S0_isInitialized = 2;

    // System object Terminate function: audiointerface.audioDeviceReader
    sErr = GetErrorBuffer(&this->pInterface.W0_AudioDeviceLib[0U]);
    LibTerminate(&this->pInterface.W0_AudioDeviceLib[0U]);
    if (*sErr != 0) {
      PrintError(sErr);
    }

    LibDestroy_Audio(&this->pInterface.W0_AudioDeviceLib[0U], 0, 1);
    DestroyHostLibrary(&this->pInterface.W0_AudioDeviceLib[0U]);
  }
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::releaseWrapper()
{
  if (this->isSetupComplete) {
    this->ReadPointer = 1;
    this->WritePointer = 2;
    this->CumulativeOverrun = 0;
    this->CumulativeUnderrun = 0;
    this->c_AsyncBuffercgHelper_isInitial = false;
    this->NumChannels = -1;
  }
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::setup()
{
  this->isSetupComplete = false;
  this->isInitialized = 1;
  this->NumChannels = 1;
  this->c_AsyncBuffercgHelper_isInitial = true;
  std::memset(&this->Cache[0], 0, 16001U * sizeof(double));
  this->isSetupComplete = true;
}

//
// Arguments    : void
// Return Type  : void
//
void audioDeviceReader::setup()
{
  char *sErr;
  this->isSetupComplete = false;
  this->isInitialized = 1;
  if (this->pInterface.S0_isInitialized != 1) {
    this->pInterface.S0_isInitialized = 1;

    // System object Start function: audiointerface.audioDeviceReader
    sErr = GetErrorBuffer(&this->pInterface.W0_AudioDeviceLib[0U]);
    CreateHostLibrary("libmwhostlibaudio.so",
                      &this->pInterface.W0_AudioDeviceLib[0U]);
    if (*sErr == 0) {
      LibCreate_Audio(&this->pInterface.W0_AudioDeviceLib[0U], 0, "Default", 8,
                      0, 1, 16000.0, 3, 800, 8000, 800, 5, NULL);
    }

    if (*sErr != 0) {
      DestroyHostLibrary(&this->pInterface.W0_AudioDeviceLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
    }
  }

  this->isSetupComplete = true;
  this->TunablePropsChanged = false;
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::setupAndReset()
{
  this->setup();
  this->ReadPointer = 1;
  this->WritePointer = 2;
  this->CumulativeOverrun = 0;
  this->CumulativeUnderrun = 0;
  std::memset(&this->Cache[0], 0, 16001U * sizeof(double));
}

//
// Arguments    : void
// Return Type  : void
//
void audioDeviceReader::setupAndReset()
{
  this->setup();
}

//
// Arguments    : void
// Return Type  : void
//
void audioDeviceReader::release()
{
  if (this->isInitialized == 1) {
    this->isInitialized = 2;
    this->releaseWrapper();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::release()
{
  if (this->isInitialized == 1) {
    this->isInitialized = 2;
    this->releaseWrapper();
  }
}

//
// Arguments    : const double varargin_1_data[]
// Return Type  : int
//
int dsp_private_AsyncBuffercgHelper::step(const double varargin_1_data[])
{
  if (this->isInitialized != 1) {
    this->setupAndReset();
  }

  return this->write(varargin_1_data);
}

//
// Arguments    : double varargout_1[800]
// Return Type  : void
//
void audioDeviceReader::step(double varargout_1[800])
{
  char *sErr;
  if (this->isInitialized != 1) {
    this->setupAndReset();
  }

  this->checkTunableProps();
  if (this->pInterface.S0_isInitialized != 1) {
    this->pInterface.S0_isInitialized = 1;

    // System object Start function: audiointerface.audioDeviceReader
    sErr = GetErrorBuffer(&this->pInterface.W0_AudioDeviceLib[0U]);
    CreateHostLibrary("libmwhostlibaudio.so",
                      &this->pInterface.W0_AudioDeviceLib[0U]);
    if (*sErr == 0) {
      LibCreate_Audio(&this->pInterface.W0_AudioDeviceLib[0U], 0, "Default", 8,
                      0, 1, 16000.0, 3, 800, 8000, 800, 5, NULL);
    }

    if (*sErr != 0) {
      DestroyHostLibrary(&this->pInterface.W0_AudioDeviceLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
    }
  }

  // System object Outputs function: audiointerface.audioDeviceReader
  sErr = GetErrorBuffer(&this->pInterface.W0_AudioDeviceLib[0U]);
  LibOutputs_Audio(&this->pInterface.W0_AudioDeviceLib[0U],
                   &this->pInterface.O0_Y0[0U], 5, 800, &this->pInterface.O1_Y1);
  if (*sErr != 0) {
    PrintError(sErr);
  }

  for (int i = 0; i < 800; i++) {
    varargout_1[i] = this->pInterface.O0_Y0[i];
  }
}

//
// File trailer for SystemCore.cpp
//
// [EOF]
//
