//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: RALFMain_SLAM_private.h
//
// Code generated for Simulink model 'RALFMain_SLAM'.
//
// Model version                  : 1.191
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Thu Jul 16 13:44:06 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_RALFMain_SLAM_private_h_
#define RTW_HEADER_RALFMain_SLAM_private_h_
#include "rtwtypes.h"
#include "RALFMain_SLAM.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern "C" void CAN_send(SimStruct *rts);
extern void CoordinateTransformationCo_Init(DW_CoordinateTransformationCo_T
  *localDW);
extern void CoordinateTransformationConvers(const real_T rtu_0[4],
  B_CoordinateTransformationCon_T *localB);
extern void CoordinateTransformation_n_Init(DW_CoordinateTransformation_f_T
  *localDW);
extern void CoordinateTransformationConve_p(const real32_T rtu_0[3],
  B_CoordinateTransformationC_c_T *localB);

#endif                                 // RTW_HEADER_RALFMain_SLAM_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
