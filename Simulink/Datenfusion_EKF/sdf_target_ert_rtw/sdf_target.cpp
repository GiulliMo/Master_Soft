//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: sdf_target.cpp
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
#include "sdf_target.h"
#include "sdf_target_private.h"

// Block signals (default storage)
B_sdf_target_T sdf_target_B;

// Continuous states
X_sdf_target_T sdf_target_X;

// Block states (default storage)
DW_sdf_target_T sdf_target_DW;

// Real-time model
RT_MODEL_sdf_target_T sdf_target_M_ = RT_MODEL_sdf_target_T();
RT_MODEL_sdf_target_T *const sdf_target_M = &sdf_target_M_;

// Forward declaration for local functions
static void sdf_target_SystemCore_release(const raspi_internal_lsm9ds1Block_s_T *
  obj);
static void sdf_target_SystemCore_delete(const raspi_internal_lsm9ds1Block_s_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(raspi_internal_lsm9ds1Block_s_T *obj);
static void sdf_targe_SystemCore_release_fa(j_codertarget_raspi_internal__T *obj);
static void sdf_target_SystemCore_delete_fa(j_codertarget_raspi_internal__T *obj);
static void matlabCodegenHandle_matlabCo_fa(j_codertarget_raspi_internal__T *obj);
static void sdf_target_SystemCore_release_f(i_codertarget_raspi_internal__T *obj);
static void sdf_target_SystemCore_delete_f(i_codertarget_raspi_internal__T *obj);
static void matlabCodegenHandle_matlabCod_f(i_codertarget_raspi_internal__T *obj);
static void matlabCodegenHandle_matlabC_fa1(ros_slros_internal_block_Publ_T *obj);
static raspi_internal_lsm9ds1Block_s_T *sdf_t_lsm9ds1Block_lsm9ds1Block
  (raspi_internal_lsm9ds1Block_s_T *obj);
static void sdf_target_SystemCore_setup(raspi_internal_lsm9ds1Block_s_T *obj);

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  sdf_target_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  sdf_target_step();
  sdf_target_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  sdf_target_step();
  sdf_target_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void sdf_target_SystemCore_release(const raspi_internal_lsm9ds1Block_s_T *
  obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->i2cobj_A_G.MW_I2C_HANDLE);
    MW_I2C_Close(obj->i2cobj_MAG.MW_I2C_HANDLE);
  }
}

static void sdf_target_SystemCore_delete(const raspi_internal_lsm9ds1Block_s_T
  *obj)
{
  sdf_target_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(raspi_internal_lsm9ds1Block_s_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    sdf_target_SystemCore_delete(obj);
  }
}

static void sdf_targe_SystemCore_release_fa(j_codertarget_raspi_internal__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void sdf_target_SystemCore_delete_fa(j_codertarget_raspi_internal__T *obj)
{
  sdf_targe_SystemCore_release_fa(obj);
}

static void matlabCodegenHandle_matlabCo_fa(j_codertarget_raspi_internal__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    sdf_target_SystemCore_delete_fa(obj);
  }
}

static void sdf_target_SystemCore_release_f(i_codertarget_raspi_internal__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void sdf_target_SystemCore_delete_f(i_codertarget_raspi_internal__T *obj)
{
  sdf_target_SystemCore_release_f(obj);
}

static void matlabCodegenHandle_matlabCod_f(i_codertarget_raspi_internal__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    sdf_target_SystemCore_delete_f(obj);
  }
}

static void matlabCodegenHandle_matlabC_fa1(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static raspi_internal_lsm9ds1Block_s_T *sdf_t_lsm9ds1Block_lsm9ds1Block
  (raspi_internal_lsm9ds1Block_s_T *obj)
{
  raspi_internal_lsm9ds1Block_s_T *b_obj;
  int32_T i;
  static const int8_T tmp[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  for (i = 0; i < 9; i++) {
    obj->CalGyroA[i] = tmp[i];
  }

  obj->CalGyroB[0] = 0.0;
  obj->CalGyroB[1] = 0.0;
  obj->CalGyroB[2] = 0.0;
  for (i = 0; i < 9; i++) {
    obj->CalAccelA[i] = tmp[i];
  }

  obj->CalAccelB[0] = 0.0;
  obj->CalAccelB[1] = 0.0;
  obj->CalAccelB[2] = 0.0;
  for (i = 0; i < 9; i++) {
    obj->CalMagA[i] = tmp[i];
  }

  obj->CalMagB[0] = 0.0;
  obj->CalMagB[1] = 0.0;
  obj->CalMagB[2] = 0.0;
  obj->isInitialized = 0;
  b_obj = obj;
  obj->i2cobj_A_G.isInitialized = 0;
  obj->i2cobj_A_G.matlabCodegenIsDeleted = false;
  obj->i2cobj_MAG.isInitialized = 0;
  obj->i2cobj_MAG.matlabCodegenIsDeleted = false;
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void sdf_target_SystemCore_setup(raspi_internal_lsm9ds1Block_s_T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  uint8_T b_SwappedDataBytes[2];
  uint8_T CastedData;
  uint8_T SwappedDataBytes[2];
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 1;
  obj->i2cobj_A_G.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cobj_A_G.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj_A_G.MW_I2C_HANDLE, obj->i2cobj_A_G.BusSpeed);
  CastedData = 96U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 16U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 17U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 18U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 56U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 30U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 19U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 56U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 31U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 103U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 32U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 33U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 4U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 34U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                     false, false);
  ModeType = MW_I2C_MASTER;
  i2cname = 1;
  obj->i2cobj_MAG.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cobj_MAG.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj_MAG.MW_I2C_HANDLE, obj->i2cobj_MAG.BusSpeed);
  CastedData = 24U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 32U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 33U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 34U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 35U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                     false, false);
  CastedData = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)((size_t)
          1 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 36U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                     false, false);
  obj->isSetupComplete = true;
}

// Model step function
void sdf_target_step(void)
{
  int32_T p1;
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  boolean_T rEQ0;
  int16_T b_RegisterValue[3];
  uint8_T SwappedDataBytes;
  uint8_T status;
  uint8_T output_raw[6];
  real_T rtb_degToRad_idx_1;
  real_T rtb_degToRad_idx_2;
  real_T K_idx_1;
  if (rtmIsMajorTimeStep(sdf_target_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&sdf_target_M->solverInfo,
                          ((sdf_target_M->Timing.clockTick0+1)*
      sdf_target_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(sdf_target_M)) {
    sdf_target_M->Timing.t[0] = rtsiGetT(&sdf_target_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(sdf_target_M)) {
    // MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
    status = 24U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(sdf_target_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(sdf_target_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
                        output_raw, 6U, false, true);
      memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint32_T)
             ((size_t)3 * sizeof(int16_T)));
    } else {
      b_RegisterValue[0] = 0;
      b_RegisterValue[1] = 0;
      b_RegisterValue[2] = 0;
    }

    memcpy(&sdf_target_B.Pp[0], &sdf_target_DW.obj.CalGyroA[0], 9U * sizeof
           (real_T));
    for (p1 = 0; p1 < 3; p1++) {
      sdf_target_B.LSM9DS1IMUSensor_o1[p1] = ((sdf_target_B.Pp[3 * p1 + 1] *
        static_cast<real_T>(b_RegisterValue[1]) + sdf_target_B.Pp[3 * p1] *
        static_cast<real_T>(b_RegisterValue[0])) + sdf_target_B.Pp[3 * p1 + 2] *
        static_cast<real_T>(b_RegisterValue[2])) + sdf_target_DW.obj.CalGyroB[p1];
    }

    status = 40U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(sdf_target_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(sdf_target_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
                        output_raw, 6U, false, true);
      memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint32_T)
             ((size_t)3 * sizeof(int16_T)));
    } else {
      b_RegisterValue[0] = 0;
      b_RegisterValue[1] = 0;
      b_RegisterValue[2] = 0;
    }

    memcpy(&sdf_target_B.Pp[0], &sdf_target_DW.obj.CalAccelA[0], 9U * sizeof
           (real_T));
    for (p1 = 0; p1 < 3; p1++) {
      sdf_target_B.LSM9DS1IMUSensor_o2[p1] = ((sdf_target_B.Pp[3 * p1 + 1] *
        static_cast<real_T>(b_RegisterValue[1]) + sdf_target_B.Pp[3 * p1] *
        static_cast<real_T>(b_RegisterValue[0])) + sdf_target_B.Pp[3 * p1 + 2] *
        static_cast<real_T>(b_RegisterValue[2])) +
        sdf_target_DW.obj.CalAccelB[p1];
    }

    status = 40U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(sdf_target_DW.obj.i2cobj_MAG.MW_I2C_HANDLE, 28U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(sdf_target_DW.obj.i2cobj_MAG.MW_I2C_HANDLE, 28U,
                        output_raw, 6U, false, true);
      memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint32_T)
             ((size_t)3 * sizeof(int16_T)));
    } else {
      b_RegisterValue[0] = 0;
      b_RegisterValue[1] = 0;
      b_RegisterValue[2] = 0;
    }

    memcpy(&sdf_target_B.Pp[0], &sdf_target_DW.obj.CalMagA[0], 9U * sizeof
           (real_T));
    for (p1 = 0; p1 < 3; p1++) {
      sdf_target_B.psi = ((sdf_target_B.Pp[3 * p1 + 1] * static_cast<real_T>
                           (b_RegisterValue[1]) + sdf_target_B.Pp[3 * p1] *
                           static_cast<real_T>(b_RegisterValue[0])) +
                          sdf_target_B.Pp[3 * p1 + 2] * static_cast<real_T>
                          (b_RegisterValue[2])) + sdf_target_DW.obj.CalMagB[p1];
      sdf_target_B.LSM9DS1IMUSensor_o1[p1] = sdf_target_B.LSM9DS1IMUSensor_o1[p1]
        * 245.0 / 32768.0;
      sdf_target_B.LSM9DS1IMUSensor_o3[p1] = sdf_target_B.psi * 4.0 / 32768.0;
      sdf_target_B.LSM9DS1IMUSensor_o2[p1] = sdf_target_B.LSM9DS1IMUSensor_o2[p1]
        * 2.0 / 32768.0;
    }

    // End of MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'

    // Gain: '<S2>/degToRad'
    rtb_degToRad_idx_1 = sdf_target_P.degToRad_Gain *
      sdf_target_B.LSM9DS1IMUSensor_o1[1];
    rtb_degToRad_idx_2 = sdf_target_P.degToRad_Gain *
      sdf_target_B.LSM9DS1IMUSensor_o1[0];

    // MATLAB Function: '<S2>/EKF' incorporates:
    //   Constant: '<Root>/Samplezeit'
    //   Gain: '<S2>/ToAccel'
    //   Gain: '<S2>/degToRad'
    //   SignalConversion generated from: '<S12>/ SFunction '

    sdf_target_B.A_d_tmp_c = tan(sdf_target_DW.x_dach_m[1]);
    sdf_target_B.A_d_tmp_b = sin(sdf_target_DW.x_dach_m[0]);
    K_idx_1 = cos(sdf_target_DW.x_dach_m[0]);
    sdf_target_B.A_d[0] = rtb_degToRad_idx_1 * K_idx_1 * sdf_target_B.A_d_tmp_c
      - rtb_degToRad_idx_2 * sdf_target_B.A_d_tmp_b * sdf_target_B.A_d_tmp_c;
    sdf_target_B.absx11 = cos(sdf_target_DW.x_dach_m[1]);
    sdf_target_B.psi = sdf_target_B.absx11 * sdf_target_B.absx11;
    sdf_target_B.A_d[3] = rtb_degToRad_idx_1 * sdf_target_B.A_d_tmp_b /
      sdf_target_B.psi + rtb_degToRad_idx_2 * K_idx_1 / sdf_target_B.psi;
    sdf_target_B.A_d[6] = 0.0;
    K_idx_1 = rtb_degToRad_idx_2 * cos(sdf_target_DW.x_dach_m[0]);
    sdf_target_B.A_d[1] = -rtb_degToRad_idx_1 * sdf_target_B.A_d_tmp_b - K_idx_1;
    sdf_target_B.A_d[4] = 0.0;
    sdf_target_B.A_d[7] = 0.0;
    sdf_target_B.A_d_tmp_b = rtb_degToRad_idx_1 * cos(sdf_target_DW.x_dach_m[0]);
    rtb_degToRad_idx_2 *= sin(sdf_target_DW.x_dach_m[0]);
    sdf_target_B.A_d[2] = sdf_target_B.A_d_tmp_b / sdf_target_B.absx11 -
      rtb_degToRad_idx_2 / sdf_target_B.absx11;
    sdf_target_B.A_d_tmp_p = sin(sdf_target_DW.x_dach_m[1]);
    sdf_target_B.absx31 = rtb_degToRad_idx_1 * sin(sdf_target_DW.x_dach_m[0]);
    sdf_target_B.A_d[5] = sdf_target_B.absx31 * sdf_target_B.A_d_tmp_p /
      (sdf_target_B.psi * 2.0) + K_idx_1 * sdf_target_B.A_d_tmp_p / (2.0 *
      sdf_target_B.absx11);
    sdf_target_B.A_d[8] = 0.0;
    for (p1 = 0; p1 < 9; p1++) {
      sdf_target_B.A_d[p1] = sdf_target_B.A_d[p1] *
        sdf_target_P.Samplezeit_Value + sdf_target_DW.I[p1];
    }

    sdf_target_B.psi = asin(sdf_target_P.ToAccel_Gain *
      sdf_target_B.LSM9DS1IMUSensor_o2[2] / 9.81);
    rtb_degToRad_idx_1 = sin(-sdf_target_DW.x_dach_m[0]);
    sdf_target_B.A_d_tmp_p = cos(-sdf_target_DW.x_dach_m[1]);
    sdf_target_B.q = sin(-sdf_target_DW.x_dach_m[1]);
    sdf_target_B.A_d_tmp_p = rt_atan2d_snf((sdf_target_B.LSM9DS1IMUSensor_o3[2] *
      rtb_degToRad_idx_1 * sdf_target_B.q + sdf_target_B.LSM9DS1IMUSensor_o3[1] *
      cos(-sdf_target_DW.x_dach_m[0])) - sdf_target_B.LSM9DS1IMUSensor_o3[0] *
      rtb_degToRad_idx_1 * sdf_target_B.A_d_tmp_p,
      sdf_target_B.LSM9DS1IMUSensor_o3[2] * sdf_target_B.A_d_tmp_p +
      sdf_target_B.LSM9DS1IMUSensor_o3[0] * sdf_target_B.q);
    if (rtIsNaN(sdf_target_B.A_d_tmp_p)) {
      rtb_degToRad_idx_1 = (rtNaN);
    } else if (rtIsInf(sdf_target_B.A_d_tmp_p)) {
      rtb_degToRad_idx_1 = (rtNaN);
    } else if (sdf_target_B.A_d_tmp_p == 0.0) {
      rtb_degToRad_idx_1 = 0.0;
    } else {
      rtb_degToRad_idx_1 = fmod(sdf_target_B.A_d_tmp_p, 6.2831853071795862);
      rEQ0 = (rtb_degToRad_idx_1 == 0.0);
      if (!rEQ0) {
        sdf_target_B.q = fabs(sdf_target_B.A_d_tmp_p / 6.2831853071795862);
        rEQ0 = !(fabs(sdf_target_B.q - floor(sdf_target_B.q + 0.5)) >
                 2.2204460492503131E-16 * sdf_target_B.q);
      }

      if (rEQ0) {
        rtb_degToRad_idx_1 = 0.0;
      } else {
        if (sdf_target_B.A_d_tmp_p < 0.0) {
          rtb_degToRad_idx_1 += 6.2831853071795862;
        }
      }
    }

    if (rtb_degToRad_idx_1 < 0.0) {
      rtb_degToRad_idx_1 += 6.2831853071795862;
    }

    sdf_target_B.A_d_tmp_c = ((sdf_target_B.absx31 * sdf_target_B.A_d_tmp_c +
      sdf_target_P.degToRad_Gain * sdf_target_B.LSM9DS1IMUSensor_o1[2]) +
      K_idx_1 * sdf_target_B.A_d_tmp_c) * sdf_target_P.Samplezeit_Value +
      sdf_target_DW.x_dach_m[0];
    sdf_target_B.A_d_tmp_b = (sdf_target_B.A_d_tmp_b - rtb_degToRad_idx_2) *
      sdf_target_P.Samplezeit_Value + sdf_target_DW.x_dach_m[1];
    K_idx_1 = (sdf_target_B.absx31 / sdf_target_B.absx11 + K_idx_1 /
               sdf_target_B.absx11) * sdf_target_P.Samplezeit_Value +
      sdf_target_DW.x_dach_m[2];
    for (p1 = 0; p1 < 3; p1++) {
      for (p2 = 0; p2 < 3; p2++) {
        p3 = p1 + 3 * p2;
        sdf_target_B.K[p3] = 0.0;
        sdf_target_B.K[p3] += sdf_target_DW.P_m[3 * p2] * sdf_target_B.A_d[p1];
        sdf_target_B.K[p3] += sdf_target_DW.P_m[3 * p2 + 1] *
          sdf_target_B.A_d[p1 + 3];
        sdf_target_B.K[p3] += sdf_target_DW.P_m[3 * p2 + 2] *
          sdf_target_B.A_d[p1 + 6];
      }

      for (p2 = 0; p2 < 3; p2++) {
        p3 = 3 * p2 + p1;
        sdf_target_B.Pp[p3] = ((sdf_target_B.K[p1 + 3] * sdf_target_B.A_d[p2 + 3]
          + sdf_target_B.K[p1] * sdf_target_B.A_d[p2]) + sdf_target_B.K[p1 + 6] *
          sdf_target_B.A_d[p2 + 6]) + sdf_target_DW.Q_i[p3];
      }
    }

    for (p1 = 0; p1 < 3; p1++) {
      for (p2 = 0; p2 < 3; p2++) {
        p3 = 3 * p2 + p1;
        sdf_target_B.A_d_tmp[p2 + 3 * p1] = sdf_target_DW.C_j[p3];
        sdf_target_B.K[p3] = 0.0;
        sdf_target_B.K[p3] += sdf_target_B.Pp[3 * p2] * sdf_target_DW.C_j[p1];
        sdf_target_B.K[p3] += sdf_target_B.Pp[3 * p2 + 1] * sdf_target_DW.C_j[p1
          + 3];
        sdf_target_B.K[p3] += sdf_target_B.Pp[3 * p2 + 2] * sdf_target_DW.C_j[p1
          + 6];
      }
    }

    for (p1 = 0; p1 < 3; p1++) {
      for (p2 = 0; p2 < 3; p2++) {
        p3 = 3 * p1 + p2;
        sdf_target_B.A_d[p3] = ((sdf_target_B.A_d_tmp[3 * p1 + 1] *
          sdf_target_B.K[p2 + 3] + sdf_target_B.A_d_tmp[3 * p1] *
          sdf_target_B.K[p2]) + sdf_target_B.A_d_tmp[3 * p1 + 2] *
          sdf_target_B.K[p2 + 6]) + sdf_target_DW.R_i[p3];
      }
    }

    memcpy(&sdf_target_B.K[0], &sdf_target_B.A_d[0], 9U * sizeof(real_T));
    p1 = 0;
    p2 = 3;
    p3 = 6;
    sdf_target_B.absx11 = fabs(sdf_target_B.A_d[0]);
    rtb_degToRad_idx_2 = fabs(sdf_target_B.A_d[1]);
    sdf_target_B.absx31 = fabs(sdf_target_B.A_d[2]);
    if ((rtb_degToRad_idx_2 > sdf_target_B.absx11) && (rtb_degToRad_idx_2 >
         sdf_target_B.absx31)) {
      p1 = 3;
      p2 = 0;
      sdf_target_B.K[0] = sdf_target_B.A_d[1];
      sdf_target_B.K[1] = sdf_target_B.A_d[0];
      sdf_target_B.K[3] = sdf_target_B.A_d[4];
      sdf_target_B.K[4] = sdf_target_B.A_d[3];
      sdf_target_B.K[6] = sdf_target_B.A_d[7];
      sdf_target_B.K[7] = sdf_target_B.A_d[6];
    } else {
      if (sdf_target_B.absx31 > sdf_target_B.absx11) {
        p1 = 6;
        p3 = 0;
        sdf_target_B.K[0] = sdf_target_B.A_d[2];
        sdf_target_B.K[2] = sdf_target_B.A_d[0];
        sdf_target_B.K[3] = sdf_target_B.A_d[5];
        sdf_target_B.K[5] = sdf_target_B.A_d[3];
        sdf_target_B.K[6] = sdf_target_B.A_d[8];
        sdf_target_B.K[8] = sdf_target_B.A_d[6];
      }
    }

    sdf_target_B.absx11 = sdf_target_B.K[1] / sdf_target_B.K[0];
    sdf_target_B.K[1] = sdf_target_B.absx11;
    rtb_degToRad_idx_2 = sdf_target_B.K[2] / sdf_target_B.K[0];
    sdf_target_B.K[2] = rtb_degToRad_idx_2;
    sdf_target_B.K[4] -= sdf_target_B.absx11 * sdf_target_B.K[3];
    sdf_target_B.K[5] -= rtb_degToRad_idx_2 * sdf_target_B.K[3];
    sdf_target_B.K[7] -= sdf_target_B.absx11 * sdf_target_B.K[6];
    sdf_target_B.K[8] -= rtb_degToRad_idx_2 * sdf_target_B.K[6];
    if (fabs(sdf_target_B.K[5]) > fabs(sdf_target_B.K[4])) {
      itmp = p2;
      p2 = p3;
      p3 = itmp;
      sdf_target_B.K[1] = rtb_degToRad_idx_2;
      sdf_target_B.K[2] = sdf_target_B.absx11;
      sdf_target_B.absx11 = sdf_target_B.K[4];
      sdf_target_B.K[4] = sdf_target_B.K[5];
      sdf_target_B.K[5] = sdf_target_B.absx11;
      sdf_target_B.absx11 = sdf_target_B.K[7];
      sdf_target_B.K[7] = sdf_target_B.K[8];
      sdf_target_B.K[8] = sdf_target_B.absx11;
    }

    sdf_target_B.absx11 = sdf_target_B.K[5] / sdf_target_B.K[4];
    sdf_target_B.K[8] -= sdf_target_B.absx11 * sdf_target_B.K[7];
    rtb_degToRad_idx_2 = (sdf_target_B.absx11 * sdf_target_B.K[1] -
                          sdf_target_B.K[2]) / sdf_target_B.K[8];
    sdf_target_B.absx31 = -(sdf_target_B.K[7] * rtb_degToRad_idx_2 +
      sdf_target_B.K[1]) / sdf_target_B.K[4];
    sdf_target_B.A_d[p1] = ((1.0 - sdf_target_B.K[3] * sdf_target_B.absx31) -
      sdf_target_B.K[6] * rtb_degToRad_idx_2) / sdf_target_B.K[0];
    sdf_target_B.A_d[p1 + 1] = sdf_target_B.absx31;
    sdf_target_B.A_d[p1 + 2] = rtb_degToRad_idx_2;
    rtb_degToRad_idx_2 = -sdf_target_B.absx11 / sdf_target_B.K[8];
    sdf_target_B.absx31 = (1.0 - sdf_target_B.K[7] * rtb_degToRad_idx_2) /
      sdf_target_B.K[4];
    sdf_target_B.A_d[p2] = -(sdf_target_B.K[3] * sdf_target_B.absx31 +
      sdf_target_B.K[6] * rtb_degToRad_idx_2) / sdf_target_B.K[0];
    sdf_target_B.A_d[p2 + 1] = sdf_target_B.absx31;
    sdf_target_B.A_d[p2 + 2] = rtb_degToRad_idx_2;
    rtb_degToRad_idx_2 = 1.0 / sdf_target_B.K[8];
    sdf_target_B.absx31 = -sdf_target_B.K[7] * rtb_degToRad_idx_2 /
      sdf_target_B.K[4];
    sdf_target_B.A_d[p3] = -(sdf_target_B.K[3] * sdf_target_B.absx31 +
      sdf_target_B.K[6] * rtb_degToRad_idx_2) / sdf_target_B.K[0];
    sdf_target_B.A_d[p3 + 1] = sdf_target_B.absx31;
    sdf_target_B.A_d[p3 + 2] = rtb_degToRad_idx_2;
    sdf_target_B.xp1[0] = sdf_target_B.A_d_tmp_c;
    sdf_target_B.xp1[1] = sdf_target_B.A_d_tmp_b;
    sdf_target_B.xp1[2] = K_idx_1;
    sdf_target_B.K_k[0] = asin(-(sdf_target_P.ToAccel_Gain *
      sdf_target_B.LSM9DS1IMUSensor_o2[1]) / (9.81 * cos(sdf_target_B.psi)));
    sdf_target_B.K_k[1] = sdf_target_B.psi;
    sdf_target_B.K_k[2] = rtb_degToRad_idx_1;
    for (p1 = 0; p1 < 3; p1++) {
      for (p2 = 0; p2 < 3; p2++) {
        p3 = p1 + 3 * p2;
        sdf_target_B.Pp_m[p3] = 0.0;
        sdf_target_B.Pp_m[p3] += sdf_target_B.A_d_tmp[3 * p2] *
          sdf_target_B.Pp[p1];
        sdf_target_B.Pp_m[p3] += sdf_target_B.A_d_tmp[3 * p2 + 1] *
          sdf_target_B.Pp[p1 + 3];
        sdf_target_B.Pp_m[p3] += sdf_target_B.A_d_tmp[3 * p2 + 2] *
          sdf_target_B.Pp[p1 + 6];
      }

      sdf_target_B.dv1[p1] = 0.0;
      for (p2 = 0; p2 < 3; p2++) {
        p3 = p1 + 3 * p2;
        sdf_target_B.K[p3] = 0.0;
        sdf_target_B.K[p3] += sdf_target_B.A_d[3 * p2] * sdf_target_B.Pp_m[p1];
        sdf_target_B.K[p3] += sdf_target_B.A_d[3 * p2 + 1] *
          sdf_target_B.Pp_m[p1 + 3];
        sdf_target_B.K[p3] += sdf_target_B.A_d[3 * p2 + 2] *
          sdf_target_B.Pp_m[p1 + 6];
        sdf_target_B.dv1[p1] += sdf_target_DW.C_j[p3] * sdf_target_B.xp1[p2];
      }

      sdf_target_B.dv2[p1] = sdf_target_B.K_k[p1] - sdf_target_B.dv1[p1];
    }

    sdf_target_B.xp1[0] = sdf_target_B.A_d_tmp_c;
    sdf_target_B.xp1[1] = sdf_target_B.A_d_tmp_b;
    sdf_target_B.xp1[2] = K_idx_1;
    for (p1 = 0; p1 < 3; p1++) {
      sdf_target_B.K_k[p1] = 0.0;
      for (p2 = 0; p2 < 3; p2++) {
        p3 = p1 + 3 * p2;
        sdf_target_B.A_d[p3] = 0.0;
        sdf_target_B.A_d[p3] += sdf_target_DW.C_j[3 * p2] * sdf_target_B.K[p1];
        sdf_target_B.A_d[p3] += sdf_target_DW.C_j[3 * p2 + 1] *
          sdf_target_B.K[p1 + 3];
        sdf_target_B.A_d[p3] += sdf_target_DW.C_j[3 * p2 + 2] *
          sdf_target_B.K[p1 + 6];
        sdf_target_B.K_k[p1] += sdf_target_B.K[p3] * sdf_target_B.dv2[p2];
      }

      sdf_target_DW.x_dach_m[p1] = sdf_target_B.xp1[p1] + sdf_target_B.K_k[p1];
      for (p2 = 0; p2 < 3; p2++) {
        p3 = 3 * p2 + p1;
        sdf_target_DW.P_m[p3] = sdf_target_B.Pp[p3] - ((sdf_target_B.Pp[3 * p2 +
          1] * sdf_target_B.A_d[p1 + 3] + sdf_target_B.Pp[3 * p2] *
          sdf_target_B.A_d[p1]) + sdf_target_B.Pp[3 * p2 + 2] *
          sdf_target_B.A_d[p1 + 6]);
      }
    }

    sdf_target_B.psi = sdf_target_DW.x_dach_m[2] * 180.0 / 3.1415926535897931;

    // BusAssignment: '<Root>/Bus Assignment3' incorporates:
    //   Gain: '<S2>/Gain3'
    //   Gain: '<S2>/Gain5'
    //   MATLAB Function: '<S2>/EKF'

    sdf_target_B.BusAssignment3.X = sdf_target_P.Gain5_Gain * rtb_degToRad_idx_1;
    sdf_target_B.BusAssignment3.Y = sdf_target_P.Gain3_Gain * K_idx_1;
    sdf_target_B.BusAssignment3.Z = sdf_target_B.psi;

    // Outputs for Atomic SubSystem: '<Root>/Publish3'
    // MATLABSystem: '<S7>/SinkBlock'
    Pub_sdf_target_102.publish(&sdf_target_B.BusAssignment3);

    // End of Outputs for SubSystem: '<Root>/Publish3'

    // MATLAB Function: '<S3>/KF_target'
    if (!sdf_target_DW.firstRun_not_empty) {
      sdf_target_DW.firstRun_not_empty = true;
      sdf_target_DW.Q[1] = 0.0;
      sdf_target_DW.Q[2] = 0.0;
      sdf_target_DW.Q[0] = 1.0;
      sdf_target_DW.Q[3] = 1.0;
      sdf_target_DW.Q[0] *= 0.001;
      sdf_target_DW.P[0] = 0.1;
      sdf_target_DW.Q[1] *= 0.001;
      sdf_target_DW.P[1] = 0.0;
      sdf_target_DW.Q[2] *= 0.001;
      sdf_target_DW.P[2] = 0.0;
      sdf_target_DW.Q[3] *= 0.001;
      sdf_target_DW.P[3] = 0.1;
      sdf_target_DW.x_dach[0] = sdf_target_B.psi;
      sdf_target_DW.x_dach[1] = 0.0;
    }

    for (p1 = 0; p1 < 2; p1++) {
      sdf_target_B.dv[p1] = 0.0;
      sdf_target_B.dv[p1] += sdf_target_DW.A_d[p1] * sdf_target_DW.P[0];
      rtb_degToRad_idx_1 = sdf_target_DW.A_d[p1 + 2];
      sdf_target_B.dv[p1] += rtb_degToRad_idx_1 * sdf_target_DW.P[1];
      sdf_target_B.dv[p1 + 2] = 0.0;
      sdf_target_B.dv[p1 + 2] += sdf_target_DW.A_d[p1] * sdf_target_DW.P[2];
      sdf_target_B.dv[p1 + 2] += rtb_degToRad_idx_1 * sdf_target_DW.P[3];
      sdf_target_B.Pp_c[p1] = (sdf_target_B.dv[p1 + 2] * sdf_target_DW.A_d[2] +
        sdf_target_B.dv[p1] * sdf_target_DW.A_d[0]) + sdf_target_DW.Q[p1];
      sdf_target_B.Pp_c[p1 + 2] = (sdf_target_B.dv[p1 + 2] * sdf_target_DW.A_d[3]
        + sdf_target_B.dv[p1] * sdf_target_DW.A_d[1]) + sdf_target_DW.Q[p1 + 2];
      sdf_target_B.xp[p1] = rtb_degToRad_idx_1 * sdf_target_DW.x_dach[1] +
        sdf_target_DW.A_d[p1] * sdf_target_DW.x_dach[0];
    }

    rtb_degToRad_idx_1 = sdf_target_DW.C[0] * sdf_target_B.Pp_c[0];
    K_idx_1 = sdf_target_DW.C[1] * sdf_target_B.Pp_c[3];
    sdf_target_B.absx11 = 1.0 / (((rtb_degToRad_idx_1 + sdf_target_DW.C[1] *
      sdf_target_B.Pp_c[1]) * sdf_target_DW.C[0] + (sdf_target_DW.C[0] *
      sdf_target_B.Pp_c[2] + K_idx_1) * sdf_target_DW.C[1]) + sdf_target_DW.R);
    rtb_degToRad_idx_1 = (rtb_degToRad_idx_1 + sdf_target_B.Pp_c[2] *
                          sdf_target_DW.C[1]) * sdf_target_B.absx11;
    K_idx_1 = (sdf_target_B.Pp_c[1] * sdf_target_DW.C[0] + K_idx_1) *
      sdf_target_B.absx11;
    sdf_target_B.A_d_tmp_c = sdf_target_B.psi - (sdf_target_DW.C[0] *
      sdf_target_B.xp[0] + sdf_target_DW.C[1] * sdf_target_B.xp[1]);
    sdf_target_DW.x_dach[0] = rtb_degToRad_idx_1 * sdf_target_B.A_d_tmp_c +
      sdf_target_B.xp[0];
    sdf_target_B.psi = rtb_degToRad_idx_1 * sdf_target_DW.C[0];
    sdf_target_B.absx11 = K_idx_1 * sdf_target_DW.C[0];
    sdf_target_DW.x_dach[1] = K_idx_1 * sdf_target_B.A_d_tmp_c +
      sdf_target_B.xp[1];
    rtb_degToRad_idx_1 *= sdf_target_DW.C[1];
    K_idx_1 *= sdf_target_DW.C[1];
    for (p1 = 0; p1 < 2; p1++) {
      p2 = p1 << 1;
      p3 = p2 + 1;
      sdf_target_DW.P[p2] = sdf_target_B.Pp_c[p2] - (sdf_target_B.Pp_c[p3] *
        rtb_degToRad_idx_1 + sdf_target_B.Pp_c[p2] * sdf_target_B.psi);
      sdf_target_DW.P[p3] = sdf_target_B.Pp_c[p3] - (sdf_target_B.Pp_c[p3] *
        K_idx_1 + sdf_target_B.Pp_c[p2] * sdf_target_B.absx11);
    }

    sdf_target_B.psikf = sdf_target_DW.x_dach[0];

    // End of MATLAB Function: '<S3>/KF_target'
  }

  // BusAssignment: '<Root>/Bus Assignment4' incorporates:
  //   Constant: '<S1>/Constant'
  //   Gain: '<S3>/Gain6'
  //   Integrator: '<S3>/Integrator'

  sdf_target_B.BusAssignment3 = sdf_target_P.Constant_Value;
  sdf_target_B.BusAssignment3.Y = sdf_target_P.Gain6_Gain *
    sdf_target_X.Integrator_CSTATE;
  sdf_target_B.BusAssignment3.Z = sdf_target_B.psikf;

  // Outputs for Atomic SubSystem: '<Root>/Publish4'
  // MATLABSystem: '<S8>/SinkBlock'
  Pub_sdf_target_104.publish(&sdf_target_B.BusAssignment3);

  // End of Outputs for SubSystem: '<Root>/Publish4'
  if (rtmIsMajorTimeStep(sdf_target_M)) {
    // BusAssignment: '<Root>/Bus Assignment'
    sdf_target_B.BusAssignment.X = sdf_target_B.LSM9DS1IMUSensor_o3[2];
    sdf_target_B.BusAssignment.Y = sdf_target_B.LSM9DS1IMUSensor_o3[1];
    sdf_target_B.BusAssignment.Z = sdf_target_B.LSM9DS1IMUSensor_o3[0];

    // Outputs for Atomic SubSystem: '<Root>/Publish'
    // MATLABSystem: '<S4>/SinkBlock'
    Pub_sdf_target_92.publish(&sdf_target_B.BusAssignment);

    // End of Outputs for SubSystem: '<Root>/Publish'

    // BusAssignment: '<Root>/Bus Assignment1'
    sdf_target_B.BusAssignment1.X = sdf_target_B.LSM9DS1IMUSensor_o2[2];
    sdf_target_B.BusAssignment1.Y = sdf_target_B.LSM9DS1IMUSensor_o2[1];
    sdf_target_B.BusAssignment1.Z = sdf_target_B.LSM9DS1IMUSensor_o2[0];

    // Outputs for Atomic SubSystem: '<Root>/Publish1'
    // MATLABSystem: '<S5>/SinkBlock'
    Pub_sdf_target_96.publish(&sdf_target_B.BusAssignment1);

    // End of Outputs for SubSystem: '<Root>/Publish1'

    // BusAssignment: '<Root>/Bus Assignment2'
    sdf_target_B.BusAssignment2.X = sdf_target_B.LSM9DS1IMUSensor_o1[2];
    sdf_target_B.BusAssignment2.Y = sdf_target_B.LSM9DS1IMUSensor_o1[1];
    sdf_target_B.BusAssignment2.Z = sdf_target_B.LSM9DS1IMUSensor_o1[0];

    // Outputs for Atomic SubSystem: '<Root>/Publish2'
    // MATLABSystem: '<S6>/SinkBlock'
    Pub_sdf_target_98.publish(&sdf_target_B.BusAssignment2);

    // End of Outputs for SubSystem: '<Root>/Publish2'
  }

  if (rtmIsMajorTimeStep(sdf_target_M)) {
    rt_ertODEUpdateContinuousStates(&sdf_target_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++sdf_target_M->Timing.clockTick0;
    sdf_target_M->Timing.t[0] = rtsiGetSolverStopTime(&sdf_target_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.01s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.01, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      sdf_target_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void sdf_target_derivatives(void)
{
  XDot_sdf_target_T *_rtXdot;
  _rtXdot = ((XDot_sdf_target_T *) sdf_target_M->derivs);

  // Derivatives for Integrator: '<S3>/Integrator'
  _rtXdot->Integrator_CSTATE = sdf_target_B.LSM9DS1IMUSensor_o1[0];
}

// Model initialize function
void sdf_target_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&sdf_target_M->solverInfo,
                          &sdf_target_M->Timing.simTimeStep);
    rtsiSetTPtr(&sdf_target_M->solverInfo, &rtmGetTPtr(sdf_target_M));
    rtsiSetStepSizePtr(&sdf_target_M->solverInfo,
                       &sdf_target_M->Timing.stepSize0);
    rtsiSetdXPtr(&sdf_target_M->solverInfo, &sdf_target_M->derivs);
    rtsiSetContStatesPtr(&sdf_target_M->solverInfo, (real_T **)
                         &sdf_target_M->contStates);
    rtsiSetNumContStatesPtr(&sdf_target_M->solverInfo,
      &sdf_target_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&sdf_target_M->solverInfo,
      &sdf_target_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&sdf_target_M->solverInfo,
      &sdf_target_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&sdf_target_M->solverInfo,
      &sdf_target_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&sdf_target_M->solverInfo, (&rtmGetErrorStatus
      (sdf_target_M)));
    rtsiSetRTModelPtr(&sdf_target_M->solverInfo, sdf_target_M);
  }

  rtsiSetSimTimeStep(&sdf_target_M->solverInfo, MAJOR_TIME_STEP);
  sdf_target_M->intgData.y = sdf_target_M->odeY;
  sdf_target_M->intgData.f[0] = sdf_target_M->odeF[0];
  sdf_target_M->intgData.f[1] = sdf_target_M->odeF[1];
  sdf_target_M->intgData.f[2] = sdf_target_M->odeF[2];
  sdf_target_M->contStates = ((X_sdf_target_T *) &sdf_target_X);
  rtsiSetSolverData(&sdf_target_M->solverInfo, static_cast<void *>
                    (&sdf_target_M->intgData));
  rtsiSetSolverName(&sdf_target_M->solverInfo,"ode3");
  rtmSetTPtr(sdf_target_M, &sdf_target_M->Timing.tArray[0]);
  sdf_target_M->Timing.stepSize0 = 0.01;

  // block I/O
  (void) memset((static_cast<void *>(&sdf_target_B)), 0,
                sizeof(B_sdf_target_T));

  // states (continuous)
  {
    (void) memset(static_cast<void *>(&sdf_target_X), 0,
                  sizeof(X_sdf_target_T));
  }

  // states (dwork)
  (void) memset(static_cast<void *>(&sdf_target_DW), 0,
                sizeof(DW_sdf_target_T));

  {
    char_T tmp[9];
    char_T tmp_0[12];
    char_T tmp_1[13];
    int32_T i;
    static const real_T tmp_2[9] = { 0.0001, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0,
      0.0, 0.1 };

    static const real_T tmp_3[9] = { 1.9, 0.0, 0.0, 0.0, 1.82, 0.0, 0.0, 0.0,
      11.0 };

    static const char_T tmp_4[8] = { '/', 'p', 's', 'i', '_', 'e', 'k', 'f' };

    static const char_T tmp_5[11] = { '/', 'p', 's', 'i', '_', 'e', 'k', 'f',
      '_', 'k', 'f' };

    static const char_T tmp_6[12] = { '/', 'm', 'a', 'g', '_', 'l', 's', 'm',
      '9', 'd', 's', '1' };

    static const char_T tmp_7[14] = { '/', 'a', 'c', 'c', 'e', 'l', '_', 'l',
      's', 'm', '9', 'd', 's', '1' };

    static const char_T tmp_8[15] = { '/', 'a', 'n', 'g', 'V', 'e', 'l', '_',
      'l', 's', 'm', '9', 'd', 's', '1' };

    // InitializeConditions for Integrator: '<S3>/Integrator'
    sdf_target_X.Integrator_CSTATE = sdf_target_P.Integrator_IC;

    // SystemInitialize for MATLAB Function: '<S2>/EKF'
    for (i = 0; i < 9; i++) {
      sdf_target_DW.Q_i[i] = tmp_2[i];
      sdf_target_DW.R_i[i] = tmp_3[i];
      sdf_target_DW.I[i] = 0.0;
    }

    sdf_target_DW.I[0] = 1.0;
    sdf_target_DW.I[4] = 1.0;
    sdf_target_DW.I[8] = 1.0;
    for (i = 0; i < 9; i++) {
      sdf_target_DW.C_j[i] = sdf_target_DW.I[i];
      sdf_target_DW.P_m[i] = 0.01 * sdf_target_DW.I[i];
    }

    sdf_target_DW.x_dach_m[0] = 0.0;
    sdf_target_DW.x_dach_m[1] = 0.0;
    sdf_target_DW.x_dach_m[2] = 0.0;

    // End of SystemInitialize for MATLAB Function: '<S2>/EKF'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish3'
    // Start for MATLABSystem: '<S7>/SinkBlock'
    sdf_target_DW.obj_o.matlabCodegenIsDeleted = false;
    sdf_target_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp[i] = tmp_4[i];
    }

    tmp[8] = '\x00';
    Pub_sdf_target_102.createPublisher(tmp, 1);
    sdf_target_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish3'

    // SystemInitialize for MATLAB Function: '<S3>/KF_target'
    sdf_target_DW.A_d[0] = 1.0;
    sdf_target_DW.A_d[1] = 0.0;
    sdf_target_DW.A_d[2] = 0.01;
    sdf_target_DW.A_d[3] = 1.0;
    sdf_target_DW.firstRun_not_empty = false;
    sdf_target_DW.C[0] = 1.0;
    sdf_target_DW.C[1] = 0.0;
    sdf_target_DW.R = 1.0;

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish4'
    // Start for MATLABSystem: '<S8>/SinkBlock'
    sdf_target_DW.obj_p.matlabCodegenIsDeleted = false;
    sdf_target_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_0[i] = tmp_5[i];
    }

    tmp_0[11] = '\x00';
    Pub_sdf_target_104.createPublisher(tmp_0, 1);
    sdf_target_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    sdf_target_DW.obj_l.matlabCodegenIsDeleted = false;
    sdf_target_DW.obj_l.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_1[i] = tmp_6[i];
    }

    tmp_1[12] = '\x00';
    Pub_sdf_target_92.createPublisher(tmp_1, 1);
    sdf_target_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    sdf_target_DW.obj_j.matlabCodegenIsDeleted = false;
    sdf_target_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      sdf_target_B.cv1[i] = tmp_7[i];
    }

    sdf_target_B.cv1[14] = '\x00';
    Pub_sdf_target_96.createPublisher(sdf_target_B.cv1, 1);
    sdf_target_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    sdf_target_DW.obj_h.matlabCodegenIsDeleted = false;
    sdf_target_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      sdf_target_B.cv[i] = tmp_8[i];
    }

    sdf_target_B.cv[15] = '\x00';
    Pub_sdf_target_98.createPublisher(sdf_target_B.cv, 1);
    sdf_target_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
    sdf_target_DW.obj.i2cobj_A_G.matlabCodegenIsDeleted = true;
    sdf_target_DW.obj.i2cobj_MAG.matlabCodegenIsDeleted = true;
    sdf_target_DW.obj.matlabCodegenIsDeleted = true;
    sdf_t_lsm9ds1Block_lsm9ds1Block(&sdf_target_DW.obj);
    sdf_target_SystemCore_setup(&sdf_target_DW.obj);
  }
}

// Model terminate function
void sdf_target_terminate(void)
{
  // Terminate for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  matlabCodegenHandle_matlabCodeg(&sdf_target_DW.obj);
  matlabCodegenHandle_matlabCo_fa(&sdf_target_DW.obj.i2cobj_MAG);
  matlabCodegenHandle_matlabCod_f(&sdf_target_DW.obj.i2cobj_A_G);

  // Terminate for Atomic SubSystem: '<Root>/Publish3'
  // Terminate for MATLABSystem: '<S7>/SinkBlock'
  matlabCodegenHandle_matlabC_fa1(&sdf_target_DW.obj_o);

  // End of Terminate for SubSystem: '<Root>/Publish3'

  // Terminate for Atomic SubSystem: '<Root>/Publish4'
  // Terminate for MATLABSystem: '<S8>/SinkBlock'
  matlabCodegenHandle_matlabC_fa1(&sdf_target_DW.obj_p);

  // End of Terminate for SubSystem: '<Root>/Publish4'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  matlabCodegenHandle_matlabC_fa1(&sdf_target_DW.obj_l);

  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  matlabCodegenHandle_matlabC_fa1(&sdf_target_DW.obj_j);

  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  matlabCodegenHandle_matlabC_fa1(&sdf_target_DW.obj_h);

  // End of Terminate for SubSystem: '<Root>/Publish2'
}

//
// File trailer for generated code.
//
// [EOF]
//
