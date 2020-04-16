//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test_types.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Apr-2020 12:22:45
//
#ifndef TEST_TYPES_H
#define TEST_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#ifdef _MSC_VER

#pragma warning(push)
#pragma warning(disable : 4251)

#endif

// Type Definitions
struct c_audiointerface_audioDeviceRea
{
  int S0_isInitialized;
  unsigned char W0_AudioDeviceLib[1096];
  double O0_Y0[800];
  unsigned int O1_Y1;
};

class audioDeviceReader
{
 public:
  audioDeviceReader *init();
  void step(double varargout_1[800]);
  void setupAndReset();
  void setup();
  void checkTunableProps();
  void matlabCodegenDestructor();
  void release();
  void releaseWrapper();
  ~audioDeviceReader();
  boolean_T matlabCodegenIsDeleted;
  c_audiointerface_audioDeviceRea pInterface;
 private:
  int isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
};

struct cell_wrap_3
{
  unsigned int f1[8];
};

class dsp_private_AsyncBuffercgHelper
{
 public:
  dsp_private_AsyncBuffercgHelper *init();
  int step(const double varargin_1_data[]);
  void setupAndReset();
  void setup();
  int write(const double in_data[]);
  void read(coder::array<double, 1U> &out, int *underrun);
  static void ReadSamplesFromBuffer(const dsp_private_AsyncBuffercgHelper *obj,
    coder::array<double, 1U> &out, int *underrun, int *overlapUnderrun, int *c);
  void matlabCodegenDestructor();
  void release();
  void releaseWrapper();
  ~dsp_private_AsyncBuffercgHelper();
  boolean_T matlabCodegenIsDeleted;
  double Cache[16001];
  int ReadPointer;
  int WritePointer;
  boolean_T c_AsyncBuffercgHelper_isInitial;
 protected:
  int isInitialized;
  int CumulativeOverrun;
  int CumulativeUnderrun;
 private:
  boolean_T isSetupComplete;
  cell_wrap_3 inputVarSize[1];
  int NumChannels;
};

class dsp_private_AsyncBuffercg
{
 public:
  dsp_private_AsyncBuffercg *init();
  void write(const double in_data[]);
  void read(coder::array<double, 1U> &out);
  void matlabCodegenDestructor();
  ~dsp_private_AsyncBuffercg();
  boolean_T matlabCodegenIsDeleted;
  dsp_private_AsyncBuffercgHelper pBuffer;
};

#ifdef _MSC_VER

#pragma warning(pop)

#endif
#endif

//
// File trailer for test_types.h
//
// [EOF]
//
