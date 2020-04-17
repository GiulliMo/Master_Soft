//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  computepsd.cpp
//
//  Code generation for function 'computepsd'
//


// Include files
#include "computepsd.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "circshift.h"
#include "indexShapeCheck.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo uc_emlrtRSI = { 47, // lineNo
  "computepsd",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/computepsd.m"// pathName
};

static emlrtBCInfo r_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  47,                                  // lineNo
  11,                                  // colNo
  "",                                  // aName
  "computepsd",                        // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/computepsd.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo v_emlrtRTEI = { 49,// lineNo
  5,                                   // colNo
  "computepsd",                        // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/computepsd.m"// pName
};

static emlrtRTEInfo w_emlrtRTEI = { 44,// lineNo
  7,                                   // colNo
  "computepsd",                        // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/computepsd.m"// pName
};

static emlrtRTEInfo x_emlrtRTEI = { 45,// lineNo
  7,                                   // colNo
  "computepsd",                        // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/computepsd.m"// pName
};

static emlrtRTEInfo y_emlrtRTEI = { 65,// lineNo
  17,                                  // colNo
  "computepsd",                        // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/computepsd.m"// pName
};

// Function Definitions
void computepsd(const emlrtStack *sp, const coder::array<real_T, 2U> &Sxx1,
                const real_T w2_data[], const int32_T w2_size[1], const char_T
                range[8], coder::array<real_T, 2U> &varargout_1, real_T
                varargout_2_data[], int32_T varargout_2_size[1])
{
  coder::array<real_T, 2U> Sxx;
  int32_T loop_ub;
  int32_T i;
  coder::array<real_T, 2U> Sxx_unscaled;
  int32_T iv[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (c_strcmp(range)) {
    int32_T i1;
    Sxx_unscaled.set_size((&w_emlrtRTEI), sp, 257, 98);
    Sxx.set_size((&x_emlrtRTEI), sp, 257, 98);
    for (i = 0; i < 98; i++) {
      for (i1 = 0; i1 < 257; i1++) {
        Sxx_unscaled[i1 + Sxx_unscaled.size(0) * i] = Sxx1[i1 + Sxx1.size(0) * i];
      }

      Sxx[Sxx.size(0) * i] = Sxx_unscaled[Sxx_unscaled.size(0) * i];
      for (i1 = 0; i1 < 255; i1++) {
        Sxx[(i1 + Sxx.size(0) * i) + 1] = 2.0 * Sxx_unscaled[(i1 +
          Sxx_unscaled.size(0) * i) + 1];
      }

      Sxx[Sxx.size(0) * i + 256] = Sxx_unscaled[Sxx_unscaled.size(0) * i + 256];
    }

    iv[0] = 1;
    iv[1] = 257;
    st.site = &uc_emlrtRSI;
    indexShapeCheck(&st, w2_size[0], iv);
    varargout_2_size[0] = 257;
    i = w2_size[0];
    for (i1 = 0; i1 < 257; i1++) {
      loop_ub = i1 + 1;
      if (loop_ub > i) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &r_emlrtBCI, sp);
      }

      varargout_2_data[i1] = w2_data[loop_ub - 1];
    }
  } else {
    Sxx.set_size((&v_emlrtRTEI), sp, Sxx1.size(0), 98);
    loop_ub = Sxx1.size(0) * Sxx1.size(1);
    for (i = 0; i < loop_ub; i++) {
      Sxx[i] = Sxx1[i];
    }

    varargout_2_size[0] = w2_size[0];
    loop_ub = w2_size[0];
    if (0 <= loop_ub - 1) {
      memcpy(&varargout_2_data[0], &w2_data[0], loop_ub * sizeof(real_T));
    }
  }

  varargout_1.set_size((&y_emlrtRTEI), sp, Sxx.size(0), 98);
  loop_ub = Sxx.size(0) * Sxx.size(1);
  for (i = 0; i < loop_ub; i++) {
    varargout_1[i] = Sxx[i] / 16000.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (computepsd.cpp)
