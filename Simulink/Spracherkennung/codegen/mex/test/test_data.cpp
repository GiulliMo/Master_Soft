//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  test_data.cpp
//
//  Code generation for function 'test_data'
//


// Include files
#include "test_data.h"
#include "rt_nonfinite.h"
#include "test.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,// bFirstTime
  false,                               // bInitialized
  131594U,                             // fVersionInfo
  NULL,                                // fErrorFunction
  "test",                              // fFunctionName
  NULL,                                // fRTCallStack
  false,                               // bDebugMode
  { 837580427U, 366578640U, 3423171347U, 1296972372U },// fSigWrd
  NULL                                 // fSigMem
};

emlrtRSInfo b_emlrtRSI = { 9,          // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

emlrtRSInfo c_emlrtRSI = { 7,          // lineNo
  "test",                              // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/test.m"// pathName 
};

emlrtRSInfo f_emlrtRSI = { 444,        // lineNo
  "resizeAlongDim",                    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/images/imresize.m"// pathName 
};

emlrtRSInfo g_emlrtRSI = { 16,         // lineNo
  "sub2ind",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/sub2ind.m"// pathName
};

emlrtRSInfo h_emlrtRSI = { 457,        // lineNo
  "resizeAlongDim",                    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/images/imresize.m"// pathName 
};

emlrtRSInfo i_emlrtRSI = { 466,        // lineNo
  "resizeAlongDim",                    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/images/imresize.m"// pathName 
};

emlrtRSInfo j_emlrtRSI = { 69,         // lineNo
  "loadDeepLearningNetwork",           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/coder/coder/lib/+coder/loadDeepLearningNetwork.m"// pathName 
};

emlrtRSInfo k_emlrtRSI = { 1,          // lineNo
  "loadDeepLearningNetwork",           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/dlcoder_base/dlcoder_base/+coder/+internal/loadDeepLearningNetwork.p"// pathName 
};

emlrtRSInfo l_emlrtRSI = { 1,          // lineNo
  "DeepLearningNetwork/callPredict",   // fcnName
  "/home/alf/Documents/MATLAB/SupportPackages/R2020a/toolbox/shared/dlcoder_base/supportpackages/shared_dl_targets/+coder/@DeepLear"
  "ningNetwork/DeepLearningNetwork.p"  // pathName
};

emlrtRSInfo m_emlrtRSI = { 1,          // lineNo
  "DeepLearningNetwork/predict",       // fcnName
  "/home/alf/Documents/MATLAB/SupportPackages/R2020a/toolbox/shared/dlcoder_base/supportpackages/shared_dl_targets/+coder/@DeepLear"
  "ningNetwork/predict.p"              // pathName
};

// End of code generation (test_data.cpp)
