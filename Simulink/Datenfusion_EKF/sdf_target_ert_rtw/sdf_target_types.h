//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: sdf_target_types.h
//
// Code generated for Simulink model 'sdf_target'.
//
// Model version                  : 1.22
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Wed Apr  1 19:10:30 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_sdf_target_types_h_
#define RTW_HEADER_sdf_target_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_sdf_target_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_sdf_target_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_sdf_target_geometry_msgs_Point;

#endif

// Custom Type definition for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
#include "MW_SVD.h"
#include "MW_I2C.h"
#ifndef struct_tag_R1xdlxXgEuZ2YKjrgC1tPF
#define struct_tag_R1xdlxXgEuZ2YKjrgC1tPF

struct tag_R1xdlxXgEuZ2YKjrgC1tPF
{
  int32_T __dummy;
};

#endif                                 //struct_tag_R1xdlxXgEuZ2YKjrgC1tPF

#ifndef typedef_e_codertarget_raspi_internal__T
#define typedef_e_codertarget_raspi_internal__T

typedef struct tag_R1xdlxXgEuZ2YKjrgC1tPF e_codertarget_raspi_internal__T;

#endif                                 //typedef_e_codertarget_raspi_internal__T

#ifndef struct_tag_wSflavgv0iM67EP96OKIZ
#define struct_tag_wSflavgv0iM67EP96OKIZ

struct tag_wSflavgv0iM67EP96OKIZ
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  e_codertarget_raspi_internal__T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 //struct_tag_wSflavgv0iM67EP96OKIZ

#ifndef typedef_i_codertarget_raspi_internal__T
#define typedef_i_codertarget_raspi_internal__T

typedef struct tag_wSflavgv0iM67EP96OKIZ i_codertarget_raspi_internal__T;

#endif                                 //typedef_i_codertarget_raspi_internal__T

#ifndef struct_tag_wPlwB1N2byXVSJAk9BGO9E
#define struct_tag_wPlwB1N2byXVSJAk9BGO9E

struct tag_wPlwB1N2byXVSJAk9BGO9E
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  e_codertarget_raspi_internal__T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 //struct_tag_wPlwB1N2byXVSJAk9BGO9E

#ifndef typedef_j_codertarget_raspi_internal__T
#define typedef_j_codertarget_raspi_internal__T

typedef struct tag_wPlwB1N2byXVSJAk9BGO9E j_codertarget_raspi_internal__T;

#endif                                 //typedef_j_codertarget_raspi_internal__T

#ifndef struct_tag_rkSooZHJZnr3Dpfu1LNqfH
#define struct_tag_rkSooZHJZnr3Dpfu1LNqfH

struct tag_rkSooZHJZnr3Dpfu1LNqfH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_rkSooZHJZnr3Dpfu1LNqfH

#ifndef typedef_ros_slros_internal_block_Publ_T
#define typedef_ros_slros_internal_block_Publ_T

typedef struct tag_rkSooZHJZnr3Dpfu1LNqfH ros_slros_internal_block_Publ_T;

#endif                                 //typedef_ros_slros_internal_block_Publ_T

#ifndef struct_tag_Mu1SNMC7dAyyNmAihLbeZF
#define struct_tag_Mu1SNMC7dAyyNmAihLbeZF

struct tag_Mu1SNMC7dAyyNmAihLbeZF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T CalGyroA[9];
  real_T CalGyroB[3];
  real_T CalAccelA[9];
  real_T CalAccelB[3];
  real_T CalMagA[9];
  real_T CalMagB[3];
  i_codertarget_raspi_internal__T i2cobj_A_G;
  j_codertarget_raspi_internal__T i2cobj_MAG;
};

#endif                                 //struct_tag_Mu1SNMC7dAyyNmAihLbeZF

#ifndef typedef_raspi_internal_lsm9ds1Block_s_T
#define typedef_raspi_internal_lsm9ds1Block_s_T

typedef struct tag_Mu1SNMC7dAyyNmAihLbeZF raspi_internal_lsm9ds1Block_s_T;

#endif                                 //typedef_raspi_internal_lsm9ds1Block_s_T

// Parameters (default storage)
typedef struct P_sdf_target_T_ P_sdf_target_T;

// Forward declaration for rtModel
typedef struct tag_RTM_sdf_target_T RT_MODEL_sdf_target_T;

#endif                                 // RTW_HEADER_sdf_target_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
