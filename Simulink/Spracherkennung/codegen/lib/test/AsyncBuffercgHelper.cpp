//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: AsyncBuffercgHelper.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Apr-2020 12:22:45
//

// Include Files
#include "AsyncBuffercgHelper.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "matlabCodegenHandle.h"
#include "test.h"

// Function Definitions

//
// Arguments    : const dsp_private_AsyncBuffercgHelper *obj
//                coder::array<double, 1U> &out
//                int *underrun
//                int *overlapUnderrun
//                int *c
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::ReadSamplesFromBuffer(const
  dsp_private_AsyncBuffercgHelper *obj, coder::array<double, 1U> &out, int
  *underrun, int *overlapUnderrun, int *c)
{
  int wPtr;
  int qY;
  int b_qY;
  int yk;
  int rPtr;
  int a;
  int y_data[16001];
  int k;
  coder::array<int, 2U> readIdx;
  coder::array<int, 2U> y;
  wPtr = obj->WritePointer;
  qY = 0;
  b_qY = 0;
  yk = obj->ReadPointer;
  if (yk > 2147483646) {
    rPtr = MAX_int32_T;
  } else {
    rPtr = yk + 1;
  }

  if (rPtr > 16001) {
    rPtr = 1;
  }

  if (rPtr < -2147468448) {
    a = MIN_int32_T;
    yk = MIN_int32_T;
  } else {
    a = rPtr - 15200;
    yk = rPtr - 15200;
  }

  *c = yk + 15999;
  if (a < 1) {
    int n;
    int y_size_idx_1;
    a += 16001;
    n = 16002 - a;
    y_size_idx_1 = 16002 - a;
    y_data[0] = a;
    yk = a;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }

    y.set_size(1, (*c));
    y[0] = 1;
    yk = 1;
    for (k = 2; k <= *c; k++) {
      yk++;
      y[k - 1] = yk;
    }

    readIdx.set_size(1, (y_size_idx_1 + y.size(1)));
    for (k = 0; k < y_size_idx_1; k++) {
      readIdx[k] = y_data[k];
    }

    yk = y.size(1);
    for (k = 0; k < yk; k++) {
      readIdx[k + y_size_idx_1] = y[k];
    }

    if ((rPtr <= wPtr) && (wPtr <= *c)) {
      if ((*c >= 0) && (wPtr < *c - MAX_int32_T)) {
        a = MAX_int32_T;
      } else if ((*c < 0) && (wPtr > *c - MIN_int32_T)) {
        a = MIN_int32_T;
      } else {
        a = *c - wPtr;
      }

      if (a > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = a + 1;
      }
    } else if (wPtr < rPtr) {
      if (a < -2147467646) {
        a = MAX_int32_T;
      } else {
        a = 16001 - a;
      }

      if (a > 2147483646) {
        a = MAX_int32_T;
      } else {
        a++;
      }

      if (wPtr > MAX_int32_T - a) {
        b_qY = MAX_int32_T;
      } else {
        b_qY = a + wPtr;
      }
    } else {
      if (wPtr > a) {
        if ((wPtr >= 0) && (a < wPtr - MAX_int32_T)) {
          a = MAX_int32_T;
        } else if ((wPtr < 0) && (a > wPtr - MIN_int32_T)) {
          a = MIN_int32_T;
        } else {
          a = wPtr - a;
        }

        if (a > 2147483646) {
          b_qY = MAX_int32_T;
        } else {
          b_qY = a + 1;
        }
      }
    }
  } else if (*c > 16001) {
    int n;
    int y_size_idx_1;
    *c -= 16001;
    n = 16002 - a;
    y_size_idx_1 = 16002 - a;
    y_data[0] = a;
    yk = a;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }

    y.set_size(1, (*c));
    y[0] = 1;
    yk = 1;
    for (k = 2; k <= *c; k++) {
      yk++;
      y[k - 1] = yk;
    }

    readIdx.set_size(1, (y_size_idx_1 + y.size(1)));
    for (k = 0; k < y_size_idx_1; k++) {
      readIdx[k] = y_data[k];
    }

    yk = y.size(1);
    for (k = 0; k < yk; k++) {
      readIdx[k + y_size_idx_1] = y[k];
    }

    if (rPtr <= wPtr) {
      if (wPtr < -2147467646) {
        a = MAX_int32_T;
      } else {
        a = 16001 - wPtr;
      }

      if (a > 2147483646) {
        a = MAX_int32_T;
      } else {
        a++;
      }

      if ((a < 0) && (*c < MIN_int32_T - a)) {
        qY = MIN_int32_T;
      } else if ((a > 0) && (*c > MAX_int32_T - a)) {
        qY = MAX_int32_T;
      } else {
        qY = a + *c;
      }
    } else if (wPtr <= *c) {
      if (wPtr < *c - MAX_int32_T) {
        a = MAX_int32_T;
      } else {
        a = *c - wPtr;
      }

      if (a > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = a + 1;
      }
    } else {
      if ((a < wPtr) && (wPtr < rPtr)) {
        b_qY = (wPtr - a) + 1;
      }
    }
  } else {
    int n;
    if (*c < a) {
      n = 0;
    } else {
      n = (*c - a) + 1;
    }

    if (n > 0) {
      y_data[0] = a;
      yk = a;
      for (k = 2; k <= n; k++) {
        yk++;
        y_data[k - 1] = yk;
      }
    }

    readIdx.set_size(1, n);
    for (k = 0; k < n; k++) {
      readIdx[k] = y_data[k];
    }

    if ((rPtr <= wPtr) && (wPtr <= *c)) {
      if ((*c >= 0) && (wPtr < *c - MAX_int32_T)) {
        a = MAX_int32_T;
      } else if ((*c < 0) && (wPtr > *c - MIN_int32_T)) {
        a = MIN_int32_T;
      } else {
        a = *c - wPtr;
      }

      if (a > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = a + 1;
      }
    } else {
      if ((a <= wPtr) && (wPtr < rPtr)) {
        b_qY = (wPtr - a) + 1;
      }
    }
  }

  out.set_size(readIdx.size(1));
  yk = readIdx.size(1);
  for (k = 0; k < yk; k++) {
    out[k] = obj->Cache[readIdx[k] - 1];
  }

  if (qY != 0) {
    if (qY < -2147467647) {
      a = MAX_int32_T;
    } else {
      a = 16000 - qY;
    }

    if (a > 2147483646) {
      a = MAX_int32_T;
    } else {
      a++;
    }

    if (a > 16000) {
      a = 1;
    }

    for (k = 0; k < qY; k++) {
      out[(a + k) - 1] = 0.0;
    }
  } else {
    if (b_qY != 0) {
      if (b_qY == 16000) {
        out.set_size(16000);
        for (k = 0; k < 16000; k++) {
          out[k] = 0.0;
        }
      } else {
        for (k = 0; k < b_qY; k++) {
          out[k] = 0.0;
        }
      }
    }
  }

  *underrun = qY;
  *overlapUnderrun = b_qY;
}

//
// Arguments    : void
// Return Type  : dsp_private_AsyncBuffercgHelper *
//
dsp_private_AsyncBuffercgHelper *dsp_private_AsyncBuffercgHelper::init()
{
  dsp_private_AsyncBuffercgHelper *obj;
  obj = this;
  obj->NumChannels = -1;
  obj->isInitialized = 0;
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// Arguments    : coder::array<double, 1U> &out
//                int *underrun
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::read(coder::array<double, 1U> &out, int
  *underrun)
{
  int overlapUnderrun;
  int c;
  int qY;
  dsp_private_AsyncBuffercgHelper::ReadSamplesFromBuffer((this), (out),
    (underrun), (&overlapUnderrun), (&c));
  overlapUnderrun = this->WritePointer;
  if (overlapUnderrun < -2147483647) {
    qY = MIN_int32_T;
  } else {
    qY = overlapUnderrun - 1;
  }

  overlapUnderrun = this->CumulativeUnderrun;
  if ((overlapUnderrun < 0) && (*underrun < MIN_int32_T - overlapUnderrun)) {
    overlapUnderrun = MIN_int32_T;
  } else if ((overlapUnderrun > 0) && (*underrun > MAX_int32_T - overlapUnderrun))
  {
    overlapUnderrun = MAX_int32_T;
  } else {
    overlapUnderrun += *underrun;
  }

  this->CumulativeUnderrun = overlapUnderrun;
  if (*underrun != 0) {
    this->ReadPointer = qY;
  } else {
    this->ReadPointer = c;
  }
}

//
// Arguments    : const double in_data[]
// Return Type  : int
//
int dsp_private_AsyncBuffercgHelper::write(const double in_data[])
{
  int overrun;
  int wPtr;
  int rPtr;
  int yk;
  int c;
  int y_data[16001];
  coder::array<int, 2U> bc;
  int k;
  coder::array<int, 2U> y;
  short tmp_data[16800];
  wPtr = this->WritePointer;
  rPtr = this->ReadPointer;
  overrun = 0;
  if (wPtr > 2147482847) {
    yk = MAX_int32_T;
  } else {
    yk = wPtr + 800;
  }

  c = yk - 1;
  if (c > 16001) {
    int n;
    int y_size_idx_1;
    c -= 16001;
    n = 16002 - wPtr;
    y_size_idx_1 = 16002 - wPtr;
    y_data[0] = wPtr;
    yk = wPtr;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }

    y.set_size(1, c);
    y[0] = 1;
    yk = 1;
    for (k = 2; k <= c; k++) {
      yk++;
      y[k - 1] = yk;
    }

    bc.set_size(1, (y_size_idx_1 + y.size(1)));
    for (k = 0; k < y_size_idx_1; k++) {
      bc[k] = y_data[k];
    }

    yk = y.size(1);
    for (k = 0; k < yk; k++) {
      bc[k + y_size_idx_1] = y[k];
    }

    if (wPtr <= rPtr) {
      if (rPtr < -2147467646) {
        yk = MAX_int32_T;
      } else {
        yk = 16001 - rPtr;
      }

      if (yk > 2147483646) {
        yk = MAX_int32_T;
      } else {
        yk++;
      }

      if ((yk < 0) && (c < MIN_int32_T - yk)) {
        overrun = MIN_int32_T;
      } else if ((yk > 0) && (c > MAX_int32_T - yk)) {
        overrun = MAX_int32_T;
      } else {
        overrun = yk + c;
      }
    } else {
      if (rPtr <= c) {
        if (rPtr < c - MAX_int32_T) {
          yk = MAX_int32_T;
        } else {
          yk = c - rPtr;
        }

        if (yk > 2147483646) {
          overrun = MAX_int32_T;
        } else {
          overrun = yk + 1;
        }
      }
    }
  } else {
    int n;
    if (c < wPtr) {
      n = 0;
    } else {
      n = (c - wPtr) + 1;
    }

    if (n > 0) {
      y_data[0] = wPtr;
      yk = wPtr;
      for (k = 2; k <= n; k++) {
        yk++;
        y_data[k - 1] = yk;
      }
    }

    bc.set_size(1, n);
    for (k = 0; k < n; k++) {
      bc[k] = y_data[k];
    }

    if ((wPtr <= rPtr) && (rPtr <= c)) {
      if ((c >= 0) && (rPtr < c - MAX_int32_T)) {
        yk = MAX_int32_T;
      } else if ((c < 0) && (rPtr > c - MIN_int32_T)) {
        yk = MIN_int32_T;
      } else {
        yk = c - rPtr;
      }

      if (yk > 2147483646) {
        overrun = MAX_int32_T;
      } else {
        overrun = yk + 1;
      }
    }
  }

  yk = bc.size(1);
  for (k = 0; k < yk; k++) {
    tmp_data[k] = static_cast<short>(static_cast<short>(bc[k]) - 1);
  }

  for (k = 0; k < 800; k++) {
    this->Cache[tmp_data[k]] = in_data[k];
  }

  if (c + 1 > 16001) {
    wPtr = 1;
  } else {
    wPtr = c + 1;
  }

  if (overrun != 0) {
    rPtr = wPtr;
  }

  yk = this->CumulativeOverrun;
  if ((yk < 0) && (overrun < MIN_int32_T - yk)) {
    yk = MIN_int32_T;
  } else if ((yk > 0) && (overrun > MAX_int32_T - yk)) {
    yk = MAX_int32_T;
  } else {
    yk += overrun;
  }

  this->CumulativeOverrun = yk;
  this->WritePointer = wPtr;
  this->ReadPointer = rPtr;
  return overrun;
}

//
// File trailer for AsyncBuffercgHelper.cpp
//
// [EOF]
//
