//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: AsyncBuffercg.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Apr-2020 12:22:45
//

// Include Files
#include "AsyncBuffercg.h"
#include "AsyncBuffercgHelper.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "SystemCore.h"
#include "matlabCodegenHandle.h"
#include "test.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : dsp_private_AsyncBuffercg *
//
dsp_private_AsyncBuffercg *dsp_private_AsyncBuffercg::init()
{
  dsp_private_AsyncBuffercg *obj;
  obj = this;
  obj->pBuffer.init();
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// Arguments    : coder::array<double, 1U> &out
// Return Type  : void
//
void dsp_private_AsyncBuffercg::read(coder::array<double, 1U> &out)
{
  int underrun;
  this->pBuffer.read(out, (&underrun));
}

//
// Arguments    : const double in_data[]
// Return Type  : void
//
void dsp_private_AsyncBuffercg::write(const double in_data[])
{
  this->pBuffer.step(in_data);
}

//
// File trailer for AsyncBuffercg.cpp
//
// [EOF]
//
