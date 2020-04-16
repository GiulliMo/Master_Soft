//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: matlabCodegenHandle.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Apr-2020 12:22:45
//

// Include Files
#include "matlabCodegenHandle.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "SystemCore.h"
#include "test.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
audioDeviceReader::~audioDeviceReader()
{
  this->matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : void
//
dsp_private_AsyncBuffercg::~dsp_private_AsyncBuffercg()
{
  this->matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : void
//
dsp_private_AsyncBuffercgHelper::~dsp_private_AsyncBuffercgHelper()
{
  this->matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : void
//
void audioDeviceReader::matlabCodegenDestructor()
{
  if (!this->matlabCodegenIsDeleted) {
    this->matlabCodegenIsDeleted = true;
    this->release();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercg::matlabCodegenDestructor()
{
  if (!this->matlabCodegenIsDeleted) {
    this->matlabCodegenIsDeleted = true;
  }
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::matlabCodegenDestructor()
{
  if (!this->matlabCodegenIsDeleted) {
    this->matlabCodegenIsDeleted = true;
    this->release();
  }
}

//
// File trailer for matlabCodegenHandle.cpp
//
// [EOF]
//
