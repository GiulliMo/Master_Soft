/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sdf_target.c
 *
 * Code generated for Simulink model 'sdf_target'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar  4 20:49:03 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sdf_target.h"
#include "sdf_target_private.h"
#include "sdf_target_dt.h"

/* Block signals (default storage) */
B_sdf_target_T sdf_target_B;

/* Continuous states */
X_sdf_target_T sdf_target_X;

/* Block states (default storage) */
DW_sdf_target_T sdf_target_DW;

/* Real-time model */
RT_MODEL_sdf_target_T sdf_target_M_;
RT_MODEL_sdf_target_T *const sdf_target_M = &sdf_target_M_;

/* Forward declaration for local functions */
static void sdf_target_SystemCore_release(const raspi_internal_lsm9ds1Block_s_T *
  obj);
static void sdf_target_SystemCore_delete(const raspi_internal_lsm9ds1Block_s_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(raspi_internal_lsm9ds1Block_s_T *obj);
static void sdf_targe_SystemCore_release_fa(codertarget_raspi_internal__f_T *obj);
static void sdf_target_SystemCore_delete_fa(codertarget_raspi_internal__f_T *obj);
static void matlabCodegenHandle_matlabCo_fa(codertarget_raspi_internal__f_T *obj);
static void sdf_target_SystemCore_release_f(codertarget_raspi_internal_I2_T *obj);
static void sdf_target_SystemCore_delete_f(codertarget_raspi_internal_I2_T *obj);
static void matlabCodegenHandle_matlabCod_f(codertarget_raspi_internal_I2_T *obj);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
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
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  sdf_target_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  sdf_target_step();
  sdf_target_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
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

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
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

    y = atan2(u0_0, u1_0);
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

static void sdf_targe_SystemCore_release_fa(codertarget_raspi_internal__f_T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void sdf_target_SystemCore_delete_fa(codertarget_raspi_internal__f_T *obj)
{
  sdf_targe_SystemCore_release_fa(obj);
}

static void matlabCodegenHandle_matlabCo_fa(codertarget_raspi_internal__f_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    sdf_target_SystemCore_delete_fa(obj);
  }
}

static void sdf_target_SystemCore_release_f(codertarget_raspi_internal_I2_T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void sdf_target_SystemCore_delete_f(codertarget_raspi_internal_I2_T *obj)
{
  sdf_target_SystemCore_release_f(obj);
}

static void matlabCodegenHandle_matlabCod_f(codertarget_raspi_internal_I2_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    sdf_target_SystemCore_delete_f(obj);
  }
}

/* Model step function */
void sdf_target_step(void)
{
  boolean_T rEQ0;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  int16_T b_RegisterValue[3];
  uint8_T SwappedDataBytes;
  uint8_T status;
  uint8_T output_raw[6];
  real_T A_d_tmp;
  real_T r_tmp;
  real_T r_tmp_0;
  if (rtmIsMajorTimeStep(sdf_target_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&sdf_target_M->solverInfo,
                          ((sdf_target_M->Timing.clockTick0+1)*
      sdf_target_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(sdf_target_M)) {
    sdf_target_M->Timing.t[0] = rtsiGetT(&sdf_target_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(sdf_target_M)) {
    /* MATLABSystem: '<Root>/LSM9DS1 IMU Sensor' incorporates:
     *  Gain: '<Root>/ToAccel'
     *  Gain: '<Root>/degToRad'
     */
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
      sdf_target_B.degToRad[p1] = ((sdf_target_B.Pp[3 * p1 + 1] * (real_T)
        b_RegisterValue[1] + sdf_target_B.Pp[3 * p1] * (real_T)b_RegisterValue[0])
        + sdf_target_B.Pp[3 * p1 + 2] * (real_T)b_RegisterValue[2]) +
        sdf_target_DW.obj.CalGyroB[p1];
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
      sdf_target_B.ToAccel[p1] = ((sdf_target_B.Pp[3 * p1 + 1] * (real_T)
        b_RegisterValue[1] + sdf_target_B.Pp[3 * p1] * (real_T)b_RegisterValue[0])
        + sdf_target_B.Pp[3 * p1 + 2] * (real_T)b_RegisterValue[2]) +
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
      sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b = ((sdf_target_B.Pp[3 * p1 + 1] *
        (real_T)b_RegisterValue[1] + sdf_target_B.Pp[3 * p1] * (real_T)
        b_RegisterValue[0]) + sdf_target_B.Pp[3 * p1 + 2] * (real_T)
        b_RegisterValue[2]) + sdf_target_DW.obj.CalMagB[p1];
      sdf_target_B.LSM9DS1IMUSensor_o1[p1] = sdf_target_B.degToRad[p1] * 245.0 /
        32768.0;
      sdf_target_B.LSM9DS1IMUSensor_o3[p1] =
        sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b * 4.0 / 32768.0;
      sdf_target_B.degToRad[p1] = sdf_target_P.degToRad_Gain *
        sdf_target_B.LSM9DS1IMUSensor_o1[p1];
      sdf_target_B.ToAccel[p1] = sdf_target_B.ToAccel[p1] * 2.0 / 32768.0 *
        sdf_target_P.ToAccel_Gain;
    }

    /* End of MATLABSystem: '<Root>/LSM9DS1 IMU Sensor' */

    /* MATLAB Function: '<Root>/EKF' incorporates:
     *  Constant: '<Root>/Samplezeit'
     */
    sdf_target_B.A_d_tmp_p = tan(sdf_target_DW.x_dach_g[1]);
    sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b = sin(sdf_target_DW.x_dach_g[0]);
    sdf_target_B.xp3 = cos(sdf_target_DW.x_dach_g[0]);
    A_d_tmp = sdf_target_B.degToRad[1] * sdf_target_B.xp3;
    sdf_target_B.absx31 = sdf_target_B.degToRad[2] *
      sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b;
    sdf_target_B.A_d[0] = A_d_tmp * sdf_target_B.A_d_tmp_p - sdf_target_B.absx31
      * sdf_target_B.A_d_tmp_p;
    sdf_target_B.absx11 = cos(sdf_target_DW.x_dach_g[1]);
    sdf_target_B.xp3 *= sdf_target_B.degToRad[2];
    sdf_target_B.absx21 = sdf_target_B.degToRad[1] *
      sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b;
    sdf_target_B.A_d[3] = sdf_target_B.absx21 / (sdf_target_B.absx11 *
      sdf_target_B.absx11) + sdf_target_B.xp3 / (sdf_target_B.absx11 *
      sdf_target_B.absx11);
    sdf_target_B.A_d[6] = 0.0;
    sdf_target_B.A_d[1] = -sdf_target_B.degToRad[1] *
      sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b - sdf_target_B.xp3;
    sdf_target_B.A_d[4] = 0.0;
    sdf_target_B.A_d[7] = 0.0;
    sdf_target_B.A_d[2] = A_d_tmp / sdf_target_B.absx11 - sdf_target_B.absx31 /
      sdf_target_B.absx11;
    sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b = sin(sdf_target_DW.x_dach_g[1]);
    sdf_target_B.A_d[5] = sdf_target_B.absx21 *
      sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b / (sdf_target_B.absx11 *
      sdf_target_B.absx11 * 2.0) + sdf_target_B.xp3 *
      sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b / (2.0 * sdf_target_B.absx11);
    sdf_target_B.A_d[8] = 0.0;
    for (p1 = 0; p1 < 9; p1++) {
      sdf_target_B.A_d[p1] = sdf_target_B.A_d[p1] *
        sdf_target_P.Samplezeit_Value + sdf_target_DW.I[p1];
    }

    sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b = asin(sdf_target_B.ToAccel[0] / 9.81);
    r_tmp = sin(-sdf_target_DW.x_dach_g[0]);
    r_tmp_0 = cos(-sdf_target_DW.x_dach_g[1]);
    sdf_target_B.q = sin(-sdf_target_DW.x_dach_g[1]);
    r_tmp_0 = rt_atan2d_snf((sdf_target_B.LSM9DS1IMUSensor_o3[0] * r_tmp *
      sdf_target_B.q + sdf_target_B.LSM9DS1IMUSensor_o3[1] * cos
      (-sdf_target_DW.x_dach_g[0])) - sdf_target_B.LSM9DS1IMUSensor_o3[2] *
      r_tmp * r_tmp_0, sdf_target_B.LSM9DS1IMUSensor_o3[0] * r_tmp_0 +
      sdf_target_B.LSM9DS1IMUSensor_o3[2] * sdf_target_B.q);
    if ((!rtIsInf(r_tmp_0)) && (!rtIsNaN(r_tmp_0))) {
      if (r_tmp_0 == 0.0) {
        r_tmp = 0.0;
      } else {
        r_tmp = fmod(r_tmp_0, 6.2831853071795862);
        rEQ0 = (r_tmp == 0.0);
        if (!rEQ0) {
          sdf_target_B.q = fabs(r_tmp_0 / 6.2831853071795862);
          rEQ0 = (fabs(sdf_target_B.q - floor(sdf_target_B.q + 0.5)) <=
                  2.2204460492503131E-16 * sdf_target_B.q);
        }

        if (rEQ0) {
          r_tmp = 0.0;
        } else {
          if (r_tmp_0 < 0.0) {
            r_tmp += 6.2831853071795862;
          }
        }
      }
    } else {
      r_tmp = (rtNaN);
    }

    if (r_tmp < 0.0) {
      r_tmp += 6.2831853071795862;
    }

    sdf_target_B.A_d_tmp_p = ((sdf_target_B.absx21 * sdf_target_B.A_d_tmp_p +
      sdf_target_B.degToRad[0]) + sdf_target_B.xp3 * sdf_target_B.A_d_tmp_p) *
      sdf_target_P.Samplezeit_Value + sdf_target_DW.x_dach_g[0];
    A_d_tmp = (A_d_tmp - sdf_target_B.absx31) * sdf_target_P.Samplezeit_Value +
      sdf_target_DW.x_dach_g[1];
    sdf_target_B.xp3 = (sdf_target_B.absx21 / sdf_target_B.absx11 +
                        sdf_target_B.xp3 / sdf_target_B.absx11) *
      sdf_target_P.Samplezeit_Value + sdf_target_DW.x_dach_g[2];
    for (p1 = 0; p1 < 3; p1++) {
      for (p2 = 0; p2 < 3; p2++) {
        p3 = p1 + 3 * p2;
        sdf_target_B.K[p3] = 0.0;
        itmp = 3 * p2 + p1;
        sdf_target_B.K[p3] = sdf_target_B.K[itmp] + sdf_target_DW.P_f[3 * p2] *
          sdf_target_B.A_d[p1];
        sdf_target_B.K[p3] = sdf_target_DW.P_f[3 * p2 + 1] * sdf_target_B.A_d[p1
          + 3] + sdf_target_B.K[itmp];
        sdf_target_B.K[p3] = sdf_target_DW.P_f[3 * p2 + 2] * sdf_target_B.A_d[p1
          + 6] + sdf_target_B.K[itmp];
      }

      for (p2 = 0; p2 < 3; p2++) {
        p3 = 3 * p2 + p1;
        sdf_target_B.Pp[p1 + 3 * p2] = ((sdf_target_B.K[p1 + 3] *
          sdf_target_B.A_d[p2 + 3] + sdf_target_B.K[p1] * sdf_target_B.A_d[p2])
          + sdf_target_B.K[p1 + 6] * sdf_target_B.A_d[p2 + 6]) +
          sdf_target_DW.Q_c[p3];
        sdf_target_B.A_d_tmp[p2 + 3 * p1] = sdf_target_DW.C_j[p3];
      }
    }

    for (p1 = 0; p1 < 3; p1++) {
      for (p2 = 0; p2 < 3; p2++) {
        p3 = p1 + 3 * p2;
        sdf_target_B.K[p3] = 0.0;
        itmp = 3 * p2 + p1;
        sdf_target_B.K[p3] = sdf_target_B.K[itmp] + sdf_target_B.Pp[3 * p2] *
          sdf_target_DW.C_j[p1];
        sdf_target_B.K[p3] = sdf_target_B.Pp[3 * p2 + 1] * sdf_target_DW.C_j[p1
          + 3] + sdf_target_B.K[itmp];
        sdf_target_B.K[p3] = sdf_target_B.Pp[3 * p2 + 2] * sdf_target_DW.C_j[p1
          + 6] + sdf_target_B.K[itmp];
      }

      for (p2 = 0; p2 < 3; p2++) {
        sdf_target_B.A_d[p1 + 3 * p2] = ((sdf_target_B.A_d_tmp[3 * p2 + 1] *
          sdf_target_B.K[p1 + 3] + sdf_target_B.A_d_tmp[3 * p2] *
          sdf_target_B.K[p1]) + sdf_target_B.A_d_tmp[3 * p2 + 2] *
          sdf_target_B.K[p1 + 6]) + sdf_target_DW.R_b[3 * p2 + p1];
      }
    }

    memcpy(&sdf_target_B.K[0], &sdf_target_B.A_d[0], 9U * sizeof(real_T));
    p1 = 0;
    p2 = 3;
    p3 = 6;
    sdf_target_B.absx11 = fabs(sdf_target_B.A_d[0]);
    sdf_target_B.absx21 = fabs(sdf_target_B.A_d[1]);
    sdf_target_B.absx31 = fabs(sdf_target_B.A_d[2]);
    if ((sdf_target_B.absx21 > sdf_target_B.absx11) && (sdf_target_B.absx21 >
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
    sdf_target_B.absx21 = sdf_target_B.K[2] / sdf_target_B.K[0];
    sdf_target_B.K[2] = sdf_target_B.absx21;
    sdf_target_B.K[4] -= sdf_target_B.absx11 * sdf_target_B.K[3];
    sdf_target_B.K[5] -= sdf_target_B.absx21 * sdf_target_B.K[3];
    sdf_target_B.K[7] -= sdf_target_B.absx11 * sdf_target_B.K[6];
    sdf_target_B.K[8] -= sdf_target_B.absx21 * sdf_target_B.K[6];
    if (fabs(sdf_target_B.K[5]) > fabs(sdf_target_B.K[4])) {
      itmp = p2;
      p2 = p3;
      p3 = itmp;
      sdf_target_B.K[1] = sdf_target_B.absx21;
      sdf_target_B.K[2] = sdf_target_B.absx11;
      sdf_target_B.absx11 = sdf_target_B.K[4];
      sdf_target_B.K[4] = sdf_target_B.K[5];
      sdf_target_B.K[5] = sdf_target_B.absx11;
      sdf_target_B.absx11 = sdf_target_B.K[7];
      sdf_target_B.K[7] = sdf_target_B.K[8];
      sdf_target_B.K[8] = sdf_target_B.absx11;
    }

    sdf_target_B.absx11 = sdf_target_B.K[5] / sdf_target_B.K[4];
    sdf_target_B.K[5] = sdf_target_B.absx11;
    sdf_target_B.K[8] -= sdf_target_B.absx11 * sdf_target_B.K[7];
    sdf_target_B.absx21 = (sdf_target_B.absx11 * sdf_target_B.K[1] -
      sdf_target_B.K[2]) / sdf_target_B.K[8];
    sdf_target_B.absx31 = -(sdf_target_B.K[7] * sdf_target_B.absx21 +
      sdf_target_B.K[1]) / sdf_target_B.K[4];
    sdf_target_B.A_d[p1] = ((1.0 - sdf_target_B.K[3] * sdf_target_B.absx31) -
      sdf_target_B.K[6] * sdf_target_B.absx21) / sdf_target_B.K[0];
    sdf_target_B.A_d[p1 + 1] = sdf_target_B.absx31;
    sdf_target_B.A_d[p1 + 2] = sdf_target_B.absx21;
    sdf_target_B.absx21 = -sdf_target_B.absx11 / sdf_target_B.K[8];
    sdf_target_B.absx31 = (1.0 - sdf_target_B.K[7] * sdf_target_B.absx21) /
      sdf_target_B.K[4];
    sdf_target_B.A_d[p2] = -(sdf_target_B.K[3] * sdf_target_B.absx31 +
      sdf_target_B.K[6] * sdf_target_B.absx21) / sdf_target_B.K[0];
    sdf_target_B.A_d[p2 + 1] = sdf_target_B.absx31;
    sdf_target_B.A_d[p2 + 2] = sdf_target_B.absx21;
    sdf_target_B.absx21 = 1.0 / sdf_target_B.K[8];
    sdf_target_B.absx31 = -sdf_target_B.K[7] * sdf_target_B.absx21 /
      sdf_target_B.K[4];
    sdf_target_B.A_d[p3] = -(sdf_target_B.K[3] * sdf_target_B.absx31 +
      sdf_target_B.K[6] * sdf_target_B.absx21) / sdf_target_B.K[0];
    sdf_target_B.A_d[p3 + 1] = sdf_target_B.absx31;
    sdf_target_B.A_d[p3 + 2] = sdf_target_B.absx21;
    sdf_target_B.degToRad[0] = sdf_target_B.A_d_tmp_p;
    sdf_target_B.degToRad[1] = A_d_tmp;
    sdf_target_B.degToRad[2] = sdf_target_B.xp3;
    sdf_target_B.LSM9DS1IMUSensor_o3[0] = asin(-sdf_target_B.ToAccel[1] / (9.81 *
      cos(sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b)));
    sdf_target_B.LSM9DS1IMUSensor_o3[1] = sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b;
    sdf_target_B.LSM9DS1IMUSensor_o3[2] = r_tmp;
    for (p1 = 0; p1 < 3; p1++) {
      for (p2 = 0; p2 < 3; p2++) {
        p3 = p1 + 3 * p2;
        sdf_target_B.Pp_m[p3] = 0.0;
        itmp = 3 * p2 + p1;
        sdf_target_B.Pp_m[p3] = sdf_target_B.Pp_m[itmp] + sdf_target_B.A_d_tmp[3
          * p2] * sdf_target_B.Pp[p1];
        sdf_target_B.Pp_m[p3] = sdf_target_B.A_d_tmp[3 * p2 + 1] *
          sdf_target_B.Pp[p1 + 3] + sdf_target_B.Pp_m[itmp];
        sdf_target_B.Pp_m[p3] = sdf_target_B.A_d_tmp[3 * p2 + 2] *
          sdf_target_B.Pp[p1 + 6] + sdf_target_B.Pp_m[itmp];
      }

      sdf_target_B.dv0[p1] = 0.0;
      for (p2 = 0; p2 < 3; p2++) {
        p3 = p1 + 3 * p2;
        sdf_target_B.K[p3] = 0.0;
        itmp = 3 * p2 + p1;
        sdf_target_B.K[p3] = sdf_target_B.K[itmp] + sdf_target_B.A_d[3 * p2] *
          sdf_target_B.Pp_m[p1];
        sdf_target_B.K[p3] = sdf_target_B.A_d[3 * p2 + 1] * sdf_target_B.Pp_m[p1
          + 3] + sdf_target_B.K[itmp];
        sdf_target_B.K[p3] = sdf_target_B.A_d[3 * p2 + 2] * sdf_target_B.Pp_m[p1
          + 6] + sdf_target_B.K[itmp];
        sdf_target_B.dv0[p1] += sdf_target_DW.C_j[itmp] *
          sdf_target_B.degToRad[p2];
      }

      sdf_target_B.ToAccel[p1] = sdf_target_B.LSM9DS1IMUSensor_o3[p1] -
        sdf_target_B.dv0[p1];
    }

    sdf_target_B.degToRad[0] = sdf_target_B.A_d_tmp_p;
    sdf_target_B.degToRad[1] = A_d_tmp;
    sdf_target_B.degToRad[2] = sdf_target_B.xp3;
    for (p1 = 0; p1 < 3; p1++) {
      sdf_target_B.LSM9DS1IMUSensor_o3[p1] = 0.0;
      for (p2 = 0; p2 < 3; p2++) {
        p3 = p1 + 3 * p2;
        sdf_target_B.A_d[p3] = 0.0;
        itmp = 3 * p2 + p1;
        sdf_target_B.A_d[p3] = sdf_target_B.A_d[itmp] + sdf_target_DW.C_j[3 * p2]
          * sdf_target_B.K[p1];
        sdf_target_B.A_d[p3] = sdf_target_DW.C_j[3 * p2 + 1] * sdf_target_B.K[p1
          + 3] + sdf_target_B.A_d[itmp];
        sdf_target_B.A_d[p3] = sdf_target_DW.C_j[3 * p2 + 2] * sdf_target_B.K[p1
          + 6] + sdf_target_B.A_d[itmp];
        sdf_target_B.LSM9DS1IMUSensor_o3[p1] += sdf_target_B.K[itmp] *
          sdf_target_B.ToAccel[p2];
      }

      sdf_target_DW.x_dach_g[p1] = sdf_target_B.degToRad[p1] +
        sdf_target_B.LSM9DS1IMUSensor_o3[p1];
      for (p2 = 0; p2 < 3; p2++) {
        sdf_target_DW.P_f[p1 + 3 * p2] = sdf_target_B.Pp[3 * p2 + p1] -
          ((sdf_target_B.Pp[3 * p2 + 1] * sdf_target_B.A_d[p1 + 3] +
            sdf_target_B.Pp[3 * p2] * sdf_target_B.A_d[p1]) + sdf_target_B.Pp[3 *
           p2 + 2] * sdf_target_B.A_d[p1 + 6]);
      }
    }

    sdf_target_B.psi = sdf_target_DW.x_dach_g[2] * 180.0 / 3.1415926535897931;

    /* Gain: '<Root>/Gain5' incorporates:
     *  MATLAB Function: '<Root>/EKF'
     */
    sdf_target_B.psi_magnetometer = sdf_target_P.Gain5_Gain * r_tmp;
  }

  /* Gain: '<Root>/Gain6' incorporates:
   *  Integrator: '<Root>/Integrator'
   */
  sdf_target_B.omega_integriert = sdf_target_P.Gain6_Gain *
    sdf_target_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(sdf_target_M)) {
    /* Gain: '<Root>/Gain3' */
    sdf_target_B.psi_predict = sdf_target_P.Gain3_Gain * sdf_target_B.xp3;

    /* MATLAB Function: '<Root>/KF_target' */
    if (!sdf_target_DW.firstRun_not_empty) {
      sdf_target_DW.firstRun_not_empty = true;
      sdf_target_DW.Q[0] = 0.0;
      sdf_target_DW.Q[1] = 0.0;
      sdf_target_DW.Q[2] = 0.0;
      sdf_target_DW.Q[3] = 0.0;
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
      sdf_target_B.K_k[p1] = 0.0;
      sdf_target_B.K_k[p1] += sdf_target_DW.A_d[p1] * sdf_target_DW.P[0];
      sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b = sdf_target_DW.A_d[p1 + 2];
      sdf_target_B.K_k[p1] += sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b *
        sdf_target_DW.P[1];
      sdf_target_B.K_k[p1 + 2] = 0.0;
      sdf_target_B.K_k[p1 + 2] += sdf_target_DW.A_d[p1] * sdf_target_DW.P[2];
      sdf_target_B.K_k[p1 + 2] += sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b *
        sdf_target_DW.P[3];
      r_tmp = sdf_target_B.K_k[p1 + 2];
      sdf_target_B.Pp_c[p1] = (r_tmp * sdf_target_DW.A_d[2] +
        sdf_target_B.K_k[p1] * sdf_target_DW.A_d[0]) + sdf_target_DW.Q[p1];
      sdf_target_B.Pp_c[p1 + 2] = (r_tmp * sdf_target_DW.A_d[3] +
        sdf_target_B.K_k[p1] * sdf_target_DW.A_d[1]) + sdf_target_DW.Q[p1 + 2];
      sdf_target_B.xp[p1] = sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b *
        sdf_target_DW.x_dach[1] + sdf_target_DW.A_d[p1] * sdf_target_DW.x_dach[0];
    }

    sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b = 1.0 / (((sdf_target_DW.C[0] *
      sdf_target_B.Pp_c[0] + sdf_target_DW.C[1] * sdf_target_B.Pp_c[1]) *
      sdf_target_DW.C[0] + (sdf_target_DW.C[0] * sdf_target_B.Pp_c[2] +
      sdf_target_DW.C[1] * sdf_target_B.Pp_c[3]) * sdf_target_DW.C[1]) +
      sdf_target_DW.R);
    sdf_target_B.K_c[0] = (sdf_target_B.Pp_c[0] * sdf_target_DW.C[0] +
      sdf_target_B.Pp_c[2] * sdf_target_DW.C[1]) *
      sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b;
    sdf_target_B.K_c[1] = (sdf_target_B.Pp_c[1] * sdf_target_DW.C[0] +
      sdf_target_B.Pp_c[3] * sdf_target_DW.C[1]) *
      sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b;
    sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b = sdf_target_B.psi -
      (sdf_target_DW.C[0] * sdf_target_B.xp[0] + sdf_target_DW.C[1] *
       sdf_target_B.xp[1]);
    for (p1 = 0; p1 < 2; p1++) {
      sdf_target_DW.x_dach[p1] = sdf_target_B.K_c[p1] *
        sdf_target_B.rtb_LSM9DS1IMUSensor_o3_b + sdf_target_B.xp[p1];
      sdf_target_B.K_k[p1] = sdf_target_B.K_c[p1] * sdf_target_DW.C[0];
      sdf_target_B.K_k[p1 + 2] = sdf_target_B.K_c[p1] * sdf_target_DW.C[1];
      r_tmp = sdf_target_B.K_k[p1 + 2];
      sdf_target_DW.P[p1] = sdf_target_B.Pp_c[p1] - (r_tmp * sdf_target_B.Pp_c[1]
        + sdf_target_B.K_k[p1] * sdf_target_B.Pp_c[0]);
      sdf_target_DW.P[p1 + 2] = sdf_target_B.Pp_c[p1 + 2] - (r_tmp *
        sdf_target_B.Pp_c[3] + sdf_target_B.K_k[p1] * sdf_target_B.Pp_c[2]);
    }

    sdf_target_B.psikf = sdf_target_DW.x_dach[0];

    /* End of MATLAB Function: '<Root>/KF_target' */
  }

  if (rtmIsMajorTimeStep(sdf_target_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)sdf_target_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(sdf_target_M)) {/* Sample time: [0.01s, 0.0s] */
      rtExtModeUpload(1, (real_T)((sdf_target_M->Timing.clockTick1) * 0.01));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(sdf_target_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(sdf_target_M)!=-1) &&
          !((rtmGetTFinal(sdf_target_M)-((sdf_target_M->Timing.clockTick1) *
             0.01)) > ((sdf_target_M->Timing.clockTick1) * 0.01) * (DBL_EPSILON)))
      {
        rtmSetErrorStatus(sdf_target_M, "Simulation finished");
      }

      if (rtmGetStopRequested(sdf_target_M)) {
        rtmSetErrorStatus(sdf_target_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&sdf_target_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++sdf_target_M->Timing.clockTick0;
    sdf_target_M->Timing.t[0] = rtsiGetSolverStopTime(&sdf_target_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      sdf_target_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void sdf_target_derivatives(void)
{
  XDot_sdf_target_T *_rtXdot;
  _rtXdot = ((XDot_sdf_target_T *) sdf_target_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = sdf_target_B.LSM9DS1IMUSensor_o1[2];
}

/* Model initialize function */
void sdf_target_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sdf_target_M, 0,
                sizeof(RT_MODEL_sdf_target_T));

  {
    /* Setup solver object */
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
  rtsiSetSolverData(&sdf_target_M->solverInfo, (void *)&sdf_target_M->intgData);
  rtsiSetSolverName(&sdf_target_M->solverInfo,"ode3");
  rtmSetTPtr(sdf_target_M, &sdf_target_M->Timing.tArray[0]);
  rtmSetTFinal(sdf_target_M, -1);
  sdf_target_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  sdf_target_M->Sizes.checksums[0] = (4106818165U);
  sdf_target_M->Sizes.checksums[1] = (4013622048U);
  sdf_target_M->Sizes.checksums[2] = (862371403U);
  sdf_target_M->Sizes.checksums[3] = (3914236441U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    sdf_target_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(sdf_target_M->extModeInfo,
      &sdf_target_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sdf_target_M->extModeInfo, sdf_target_M->Sizes.checksums);
    rteiSetTPtr(sdf_target_M->extModeInfo, rtmGetTPtr(sdf_target_M));
  }

  /* block I/O */
  (void) memset(((void *) &sdf_target_B), 0,
                sizeof(B_sdf_target_T));

  /* states (continuous) */
  {
    (void) memset((void *)&sdf_target_X, 0,
                  sizeof(X_sdf_target_T));
  }

  /* states (dwork) */
  (void) memset((void *)&sdf_target_DW, 0,
                sizeof(DW_sdf_target_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    sdf_target_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    raspi_internal_lsm9ds1Block_s_T *obj;
    uint32_T i2cname;
    uint8_T b_SwappedDataBytes[2];
    uint8_T SwappedDataBytes[2];
    uint8_T CastedData;
    static const int8_T tmp[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const real_T tmp_0[9] = { 0.0001, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0,
      0.0, 0.1 };

    static const real_T tmp_1[9] = { 1.9, 0.0, 0.0, 0.0, 1.82, 0.0, 0.0, 0.0,
      11.0 };

    int32_T i;

    /* Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor' */
    sdf_target_DW.obj.i2cobj_A_G.matlabCodegenIsDeleted = true;
    sdf_target_DW.obj.i2cobj_MAG.matlabCodegenIsDeleted = true;
    sdf_target_DW.obj.matlabCodegenIsDeleted = true;
    obj = &sdf_target_DW.obj;
    for (i = 0; i < 9; i++) {
      sdf_target_DW.obj.CalGyroA[i] = tmp[i];
    }

    sdf_target_DW.obj.CalGyroB[0] = 0.0;
    sdf_target_DW.obj.CalGyroB[1] = 0.0;
    sdf_target_DW.obj.CalGyroB[2] = 0.0;
    for (i = 0; i < 9; i++) {
      sdf_target_DW.obj.CalAccelA[i] = tmp[i];
    }

    sdf_target_DW.obj.CalAccelB[0] = 0.0;
    sdf_target_DW.obj.CalAccelB[1] = 0.0;
    sdf_target_DW.obj.CalAccelB[2] = 0.0;
    for (i = 0; i < 9; i++) {
      sdf_target_DW.obj.CalMagA[i] = tmp[i];
    }

    sdf_target_DW.obj.CalMagB[0] = 0.0;
    sdf_target_DW.obj.CalMagB[1] = 0.0;
    sdf_target_DW.obj.CalMagB[2] = 0.0;
    sdf_target_DW.obj.isInitialized = 0;
    obj->i2cobj_A_G.isInitialized = 0;
    obj->i2cobj_A_G.matlabCodegenIsDeleted = false;
    obj->i2cobj_MAG.isInitialized = 0;
    obj->i2cobj_MAG.matlabCodegenIsDeleted = false;
    sdf_target_DW.obj.matlabCodegenIsDeleted = false;
    obj = &sdf_target_DW.obj;
    sdf_target_DW.obj.isSetupComplete = false;
    sdf_target_DW.obj.isInitialized = 1;
    i2cname = 1;
    obj->i2cobj_A_G.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
    obj->i2cobj_A_G.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(obj->i2cobj_A_G.MW_I2C_HANDLE, obj->i2cobj_A_G.BusSpeed);
    CastedData = 96U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 16U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 17U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 18U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 56U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 30U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 19U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 56U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 31U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 103U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 32U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 33U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 4U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 34U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes, 2U,
                       false, false);
    i2cname = 1;
    obj->i2cobj_MAG.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
    obj->i2cobj_MAG.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(obj->i2cobj_MAG.MW_I2C_HANDLE, obj->i2cobj_MAG.BusSpeed);
    CastedData = 24U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 32U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 33U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 34U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 35U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                       false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 36U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                       false, false);
    sdf_target_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor' */

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    sdf_target_X.Integrator_CSTATE = sdf_target_P.Integrator_IC;

    /* SystemInitialize for MATLAB Function: '<Root>/EKF' */
    for (i = 0; i < 9; i++) {
      sdf_target_DW.Q_c[i] = tmp_0[i];
      sdf_target_DW.R_b[i] = tmp_1[i];
      sdf_target_DW.I[i] = 0.0;
    }

    sdf_target_DW.I[0] = 1.0;
    sdf_target_DW.I[4] = 1.0;
    sdf_target_DW.I[8] = 1.0;
    for (i = 0; i < 9; i++) {
      sdf_target_DW.C_j[i] = sdf_target_DW.I[i];
      sdf_target_DW.P_f[i] = 0.01 * sdf_target_DW.I[i];
    }

    sdf_target_DW.x_dach_g[0] = 0.0;
    sdf_target_DW.x_dach_g[1] = 0.0;
    sdf_target_DW.x_dach_g[2] = 0.0;

    /* End of SystemInitialize for MATLAB Function: '<Root>/EKF' */

    /* SystemInitialize for MATLAB Function: '<Root>/KF_target' */
    sdf_target_DW.A_d[0] = 1.0;
    sdf_target_DW.A_d[1] = 0.0;
    sdf_target_DW.A_d[2] = 0.01;
    sdf_target_DW.A_d[3] = 1.0;
    sdf_target_DW.firstRun_not_empty = false;
    sdf_target_DW.C[0] = 1.0;
    sdf_target_DW.C[1] = 0.0;
    sdf_target_DW.R = 1.0;
  }
}

/* Model terminate function */
void sdf_target_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor' */
  matlabCodegenHandle_matlabCodeg(&sdf_target_DW.obj);
  matlabCodegenHandle_matlabCo_fa(&sdf_target_DW.obj.i2cobj_MAG);
  matlabCodegenHandle_matlabCod_f(&sdf_target_DW.obj.i2cobj_A_G);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
