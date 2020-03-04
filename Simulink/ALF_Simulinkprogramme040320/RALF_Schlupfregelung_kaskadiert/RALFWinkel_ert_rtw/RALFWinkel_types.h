//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: RALFWinkel_types.h
//
// Code generated for Simulink model 'RALFWinkel'.
//
// Model version                  : 1.7
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Tue Dec 18 08:39:41 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_RALFWinkel_types_h_
#define RTW_HEADER_RALFWinkel_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_RALFWinkel_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_RALFWinkel_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_RALFWinkel_geometry_msgs_Point;

#endif

// Custom Type definition for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
#include "MW_SVD.h"
#include <stddef.h>
#ifndef typedef_codertarget_raspi_internal_Ha_T
#define typedef_codertarget_raspi_internal_Ha_T

typedef struct {
  int32_T __dummy;
} codertarget_raspi_internal_Ha_T;

#endif                                 //typedef_codertarget_raspi_internal_Ha_T

#ifndef typedef_codertarget_raspi_internal_I2_T
#define typedef_codertarget_raspi_internal_I2_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  codertarget_raspi_internal_Ha_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
} codertarget_raspi_internal_I2_T;

#endif                                 //typedef_codertarget_raspi_internal_I2_T

#ifndef typedef_codertarget_raspi_internal__o_T
#define typedef_codertarget_raspi_internal__o_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  codertarget_raspi_internal_Ha_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
} codertarget_raspi_internal__o_T;

#endif                                 //typedef_codertarget_raspi_internal__o_T

#ifndef typedef_robotics_slros_internal_block_T
#define typedef_robotics_slros_internal_block_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} robotics_slros_internal_block_T;

#endif                                 //typedef_robotics_slros_internal_block_T

#ifndef typedef_raspi_internal_lsm9ds1Block_R_T
#define typedef_raspi_internal_lsm9ds1Block_R_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T CalGyroA[9];
  real_T CalGyroB[3];
  real_T CalAccelA[9];
  real_T CalAccelB[3];
  real_T CalMagA[9];
  real_T CalMagB[3];
  codertarget_raspi_internal_I2_T i2cobj_A_G;
  codertarget_raspi_internal__o_T i2cobj_MAG;
} raspi_internal_lsm9ds1Block_R_T;

#endif                                 //typedef_raspi_internal_lsm9ds1Block_R_T

// Parameters (default storage)
typedef struct P_RALFWinkel_T_ P_RALFWinkel_T;

// Forward declaration for rtModel
typedef struct tag_RTM_RALFWinkel_T RT_MODEL_RALFWinkel_T;

#endif                                 // RTW_HEADER_RALFWinkel_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
