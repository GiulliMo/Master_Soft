//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: RALFWinkel17b.cpp
//
// Code generated for Simulink model 'RALFWinkel17b'.
//
// Model version                  : 1.9
// Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
// C/C++ source code generated on : Thu Nov 29 15:56:00 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "RALFWinkel17b.h"
#include "RALFWinkel17b_private.h"
#include "RALFWinkel17b_dt.h"
#define RALFWinkel17b_MessageQueueLen  (1)

// Block signals (default storage)
B_RALFWinkel17b_T RALFWinkel17b_B;

// Continuous states
X_RALFWinkel17b_T RALFWinkel17b_X;

// Block states (default storage)
DW_RALFWinkel17b_T RALFWinkel17b_DW;

// Real-time model
RT_MODEL_RALFWinkel17b_T RALFWinkel17b_M_;
RT_MODEL_RALFWinkel17b_T *const RALFWinkel17b_M = &RALFWinkel17b_M_;

// Forward declaration for local functions
static void SystemProp_matlabCodegenSet_gbl(robotics_slros_internal_block_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabC_gbl(robotics_slros_internal_block_T *obj);
static void SystemProp_matlabCodegenSetAnyP(raspi_internal_lsm9ds1Block_R_T *obj,
  boolean_T value);
static void RALFWinkel17_SystemCore_release(const
  raspi_internal_lsm9ds1Block_R_T *obj);
static void RALFWinkel17b_SystemCore_delete(const
  raspi_internal_lsm9ds1Block_R_T *obj);
static void matlabCodegenHandle_matlabCodeg(raspi_internal_lsm9ds1Block_R_T *obj);
static void SystemProp_matlabCodegenSetA_gb(codertarget_raspi_internal__g_T *obj,
  boolean_T value);
static void RALFWinke_SystemCore_release_gb(codertarget_raspi_internal__g_T *obj);
static void RALFWinkel_SystemCore_delete_gb(codertarget_raspi_internal__g_T *obj);
static void matlabCodegenHandle_matlabCo_gb(codertarget_raspi_internal__g_T *obj);
static void SystemProp_matlabCodegenSetAn_g(codertarget_raspi_internal_I2_T *obj,
  boolean_T value);
static void RALFWinkel_SystemCore_release_g(codertarget_raspi_internal_I2_T *obj);
static void RALFWinkel1_SystemCore_delete_g(codertarget_raspi_internal_I2_T *obj);
static void matlabCodegenHandle_matlabCod_g(codertarget_raspi_internal_I2_T *obj);

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
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
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
                (uint_T)nXc*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  RALFWinkel17b_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  RALFWinkel17b_step();
  RALFWinkel17b_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  RALFWinkel17b_step();
  RALFWinkel17b_derivatives();

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

static void SystemProp_matlabCodegenSet_gbl(robotics_slros_internal_block_T *obj,
  boolean_T value)
{
  // Start for MATLABSystem: '<S4>/SinkBlock'
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabC_gbl(robotics_slros_internal_block_T *obj)
{
  // Start for MATLABSystem: '<S4>/SinkBlock'
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSet_gbl(obj, true);
  }

  // End of Start for MATLABSystem: '<S4>/SinkBlock'
}

static void SystemProp_matlabCodegenSetAnyP(raspi_internal_lsm9ds1Block_R_T *obj,
  boolean_T value)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  obj->matlabCodegenIsDeleted = value;
}

static void RALFWinkel17_SystemCore_release(const
  raspi_internal_lsm9ds1Block_R_T *obj)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->i2cobj_A_G.MW_I2C_HANDLE);
    MW_I2C_Close(obj->i2cobj_MAG.MW_I2C_HANDLE);
  }

  // End of Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
}

static void RALFWinkel17b_SystemCore_delete(const
  raspi_internal_lsm9ds1Block_R_T *obj)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  RALFWinkel17_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(raspi_internal_lsm9ds1Block_R_T *obj)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAnyP(obj, true);
    RALFWinkel17b_SystemCore_delete(obj);
  }

  // End of Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
}

static void SystemProp_matlabCodegenSetA_gb(codertarget_raspi_internal__g_T *obj,
  boolean_T value)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  obj->matlabCodegenIsDeleted = value;
}

static void RALFWinke_SystemCore_release_gb(codertarget_raspi_internal__g_T *obj)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
}

static void RALFWinkel_SystemCore_delete_gb(codertarget_raspi_internal__g_T *obj)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  RALFWinke_SystemCore_release_gb(obj);
}

static void matlabCodegenHandle_matlabCo_gb(codertarget_raspi_internal__g_T *obj)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetA_gb(obj, true);
    RALFWinkel_SystemCore_delete_gb(obj);
  }

  // End of Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
}

static void SystemProp_matlabCodegenSetAn_g(codertarget_raspi_internal_I2_T *obj,
  boolean_T value)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  obj->matlabCodegenIsDeleted = value;
}

static void RALFWinkel_SystemCore_release_g(codertarget_raspi_internal_I2_T *obj)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
}

static void RALFWinkel1_SystemCore_delete_g(codertarget_raspi_internal_I2_T *obj)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  RALFWinkel_SystemCore_release_g(obj);
}

static void matlabCodegenHandle_matlabCod_g(codertarget_raspi_internal_I2_T *obj)
{
  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAn_g(obj, true);
    RALFWinkel1_SystemCore_delete_g(obj);
  }

  // End of Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
}

// Model step function
void RALFWinkel17b_step(void)
{
  int16_T b_RegisterValue[3];
  uint8_T SwappedDataBytes;
  uint8_T status;
  uint8_T output_raw[6];
  int16_T b_output[3];
  real_T rtb_Sum1;
  real_T b_RegisterValue_0[3];
  int32_T i;
  if (rtmIsMajorTimeStep(RALFWinkel17b_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&RALFWinkel17b_M->solverInfo,
                          ((RALFWinkel17b_M->Timing.clockTick0+1)*
      RALFWinkel17b_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(RALFWinkel17b_M)) {
    RALFWinkel17b_M->Timing.t[0] = rtsiGetT(&RALFWinkel17b_M->solverInfo);
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'
  //   Integrator: '<Root>/Integrator'

  RALFWinkel17b_B.BusAssignment = RALFWinkel17b_P.Constant_Value;
  RALFWinkel17b_B.BusAssignment.Z = RALFWinkel17b_X.Integrator_CSTATE;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S4>/SinkBlock'
  Pub_RALFWinkel17b_101.publish(&RALFWinkel17b_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(RALFWinkel17b_M)) {
    // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
    status = 24U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(RALFWinkel17b_DW.obj.i2cobj_A_G.MW_I2C_HANDLE,
      106U, &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(RALFWinkel17b_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
                        output_raw, 6U, false, true);
      memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint32_T)
             ((size_t)3 * sizeof(int16_T)));
    } else {
      b_RegisterValue[0] = 0;
      b_RegisterValue[1] = 0;
      b_RegisterValue[2] = 0;
    }

    status = 40U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(RALFWinkel17b_DW.obj.i2cobj_A_G.MW_I2C_HANDLE,
      106U, &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(RALFWinkel17b_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
                        output_raw, 6U, false, true);
      memcpy((void *)&b_output[0], (void *)&output_raw[0], (uint32_T)((size_t)3 *
              sizeof(int16_T)));
    }

    status = 40U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(RALFWinkel17b_DW.obj.i2cobj_MAG.MW_I2C_HANDLE,
      28U, &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(RALFWinkel17b_DW.obj.i2cobj_MAG.MW_I2C_HANDLE, 28U,
                        output_raw, 6U, false, true);
      memcpy((void *)&b_output[0], (void *)&output_raw[0], (uint32_T)((size_t)3 *
              sizeof(int16_T)));
    }

    for (i = 0; i < 3; i++) {
      b_RegisterValue_0[i] = ((RALFWinkel17b_DW.obj.CalGyroA[3 * i + 1] *
        (real_T)b_RegisterValue[1] + RALFWinkel17b_DW.obj.CalGyroA[3 * i] *
        (real_T)b_RegisterValue[0]) + RALFWinkel17b_DW.obj.CalGyroA[3 * i + 2] *
        (real_T)b_RegisterValue[2]) + RALFWinkel17b_DW.obj.CalGyroB[i];
    }

    // Sum: '<Root>/Sum1' incorporates:
    //   Constant: '<Root>/Constant'
    //   MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
    //   MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'

    rtb_Sum1 = b_RegisterValue_0[0] * 245.0 / 32768.0 +
      RALFWinkel17b_P.Constant_Value_h;

    // Sum: '<Root>/Sum' incorporates:
    //   Constant: '<S2>/Constant'
    //   Constant: '<S3>/Constant'
    //   Product: '<Root>/Product1'
    //   Product: '<Root>/Product2'
    //   RelationalOperator: '<S2>/Compare'
    //   RelationalOperator: '<S3>/Compare'

    RALFWinkel17b_B.Sum = (real_T)(rtb_Sum1 >=
      RALFWinkel17b_P.CompareToConstant1_const) * rtb_Sum1 + (real_T)(rtb_Sum1 <=
      RALFWinkel17b_P.CompareToConstant2_const) * rtb_Sum1;
  }

  if (rtmIsMajorTimeStep(RALFWinkel17b_M)) {
    // External mode
    rtExtModeUploadCheckTrigger(2);

    {                                  // Sample time: [0.0s, 0.0s]
      rtExtModeUpload(0, RALFWinkel17b_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(RALFWinkel17b_M)) {// Sample time: [0.01s, 0.0s]
      rtExtModeUpload(1, ((RALFWinkel17b_M->Timing.clockTick1) * 0.01));
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(RALFWinkel17b_M)) {
    // signal main to stop simulation
    {                                  // Sample time: [0.0s, 0.0s]
      if ((rtmGetTFinal(RALFWinkel17b_M)!=-1) &&
          !((rtmGetTFinal(RALFWinkel17b_M)-((RALFWinkel17b_M->Timing.clockTick1)
             * 0.01)) > ((RALFWinkel17b_M->Timing.clockTick1) * 0.01) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(RALFWinkel17b_M, "Simulation finished");
      }

      if (rtmGetStopRequested(RALFWinkel17b_M)) {
        rtmSetErrorStatus(RALFWinkel17b_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&RALFWinkel17b_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++RALFWinkel17b_M->Timing.clockTick0;
    RALFWinkel17b_M->Timing.t[0] = rtsiGetSolverStopTime
      (&RALFWinkel17b_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.01s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.01, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      RALFWinkel17b_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void RALFWinkel17b_derivatives(void)
{
  XDot_RALFWinkel17b_T *_rtXdot;
  _rtXdot = ((XDot_RALFWinkel17b_T *) RALFWinkel17b_M->derivs);

  // Derivatives for Integrator: '<Root>/Integrator'
  _rtXdot->Integrator_CSTATE = RALFWinkel17b_B.Sum;
}

// Model initialize function
void RALFWinkel17b_initialize(void)
{
  // Registration code

  // initialize real-time model
  (void) memset((void *)RALFWinkel17b_M, 0,
                sizeof(RT_MODEL_RALFWinkel17b_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&RALFWinkel17b_M->solverInfo,
                          &RALFWinkel17b_M->Timing.simTimeStep);
    rtsiSetTPtr(&RALFWinkel17b_M->solverInfo, &rtmGetTPtr(RALFWinkel17b_M));
    rtsiSetStepSizePtr(&RALFWinkel17b_M->solverInfo,
                       &RALFWinkel17b_M->Timing.stepSize0);
    rtsiSetdXPtr(&RALFWinkel17b_M->solverInfo, &RALFWinkel17b_M->derivs);
    rtsiSetContStatesPtr(&RALFWinkel17b_M->solverInfo, (real_T **)
                         &RALFWinkel17b_M->contStates);
    rtsiSetNumContStatesPtr(&RALFWinkel17b_M->solverInfo,
      &RALFWinkel17b_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&RALFWinkel17b_M->solverInfo,
      &RALFWinkel17b_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&RALFWinkel17b_M->solverInfo,
      &RALFWinkel17b_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&RALFWinkel17b_M->solverInfo,
      &RALFWinkel17b_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&RALFWinkel17b_M->solverInfo, (&rtmGetErrorStatus
      (RALFWinkel17b_M)));
    rtsiSetRTModelPtr(&RALFWinkel17b_M->solverInfo, RALFWinkel17b_M);
  }

  rtsiSetSimTimeStep(&RALFWinkel17b_M->solverInfo, MAJOR_TIME_STEP);
  RALFWinkel17b_M->intgData.y = RALFWinkel17b_M->odeY;
  RALFWinkel17b_M->intgData.f[0] = RALFWinkel17b_M->odeF[0];
  RALFWinkel17b_M->intgData.f[1] = RALFWinkel17b_M->odeF[1];
  RALFWinkel17b_M->intgData.f[2] = RALFWinkel17b_M->odeF[2];
  RALFWinkel17b_M->contStates = ((X_RALFWinkel17b_T *) &RALFWinkel17b_X);
  rtsiSetSolverData(&RALFWinkel17b_M->solverInfo, (void *)
                    &RALFWinkel17b_M->intgData);
  rtsiSetSolverName(&RALFWinkel17b_M->solverInfo,"ode3");
  rtmSetTPtr(RALFWinkel17b_M, &RALFWinkel17b_M->Timing.tArray[0]);
  rtmSetTFinal(RALFWinkel17b_M, -1);
  RALFWinkel17b_M->Timing.stepSize0 = 0.01;

  // External mode info
  RALFWinkel17b_M->Sizes.checksums[0] = (1565728590U);
  RALFWinkel17b_M->Sizes.checksums[1] = (3457407394U);
  RALFWinkel17b_M->Sizes.checksums[2] = (751550472U);
  RALFWinkel17b_M->Sizes.checksums[3] = (1170155489U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    RALFWinkel17b_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(RALFWinkel17b_M->extModeInfo,
      &RALFWinkel17b_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RALFWinkel17b_M->extModeInfo,
                        RALFWinkel17b_M->Sizes.checksums);
    rteiSetTPtr(RALFWinkel17b_M->extModeInfo, rtmGetTPtr(RALFWinkel17b_M));
  }

  // block I/O
  (void) memset(((void *) &RALFWinkel17b_B), 0,
                sizeof(B_RALFWinkel17b_T));

  // states (continuous)
  {
    (void) memset((void *)&RALFWinkel17b_X, 0,
                  sizeof(X_RALFWinkel17b_T));
  }

  // states (dwork)
  (void) memset((void *)&RALFWinkel17b_DW, 0,
                sizeof(DW_RALFWinkel17b_T));

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    RALFWinkel17b_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    raspi_internal_lsm9ds1Block_R_T *obj;
    uint32_T i2cname;
    uint8_T b_SwappedDataBytes[2];
    uint8_T SwappedDataBytes[2];
    uint8_T CastedData;
    static const char_T tmp[11] = { '/', 'r', 'a', 'l', 'f', 'w', 'i', 'n', 'k',
      'e', 'l' };

    static const int8_T tmp_0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    char_T tmp_1[12];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    RALFWinkel17b_DW.obj_b.matlabCodegenIsDeleted = true;
    RALFWinkel17b_DW.obj_b.isInitialized = 0;
    RALFWinkel17b_DW.obj_b.matlabCodegenIsDeleted = false;
    RALFWinkel17b_DW.obj_b.isSetupComplete = false;
    RALFWinkel17b_DW.obj_b.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_1[i] = tmp[i];
    }

    tmp_1[11] = '\x00';
    Pub_RALFWinkel17b_101.createPublisher(tmp_1, RALFWinkel17b_MessageQueueLen);
    RALFWinkel17b_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish'

    // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
    RALFWinkel17b_DW.obj.i2cobj_A_G.matlabCodegenIsDeleted = true;
    RALFWinkel17b_DW.obj.i2cobj_MAG.matlabCodegenIsDeleted = true;
    RALFWinkel17b_DW.obj.matlabCodegenIsDeleted = true;
    obj = &RALFWinkel17b_DW.obj;
    for (i = 0; i < 9; i++) {
      RALFWinkel17b_DW.obj.CalGyroA[i] = tmp_0[i];
    }

    RALFWinkel17b_DW.obj.CalGyroB[0] = 0.0;
    RALFWinkel17b_DW.obj.CalGyroB[1] = 0.0;
    RALFWinkel17b_DW.obj.CalGyroB[2] = 0.0;
    for (i = 0; i < 9; i++) {
      RALFWinkel17b_DW.obj.CalAccelA[i] = tmp_0[i];
    }

    RALFWinkel17b_DW.obj.CalAccelB[0] = 0.0;
    RALFWinkel17b_DW.obj.CalAccelB[1] = 0.0;
    RALFWinkel17b_DW.obj.CalAccelB[2] = 0.0;
    for (i = 0; i < 9; i++) {
      RALFWinkel17b_DW.obj.CalMagA[i] = tmp_0[i];
    }

    RALFWinkel17b_DW.obj.CalMagB[0] = 0.0;
    RALFWinkel17b_DW.obj.CalMagB[1] = 0.0;
    RALFWinkel17b_DW.obj.CalMagB[2] = 0.0;
    RALFWinkel17b_DW.obj.isInitialized = 0;
    obj->i2cobj_A_G.isInitialized = 0;

    // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
    obj->i2cobj_A_G.matlabCodegenIsDeleted = false;

    // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
    obj->i2cobj_MAG.isInitialized = 0;
    obj->i2cobj_MAG.matlabCodegenIsDeleted = false;
    RALFWinkel17b_DW.obj.matlabCodegenIsDeleted = false;
    obj = &RALFWinkel17b_DW.obj;
    RALFWinkel17b_DW.obj.isSetupComplete = false;
    RALFWinkel17b_DW.obj.isInitialized = 1;
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
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 34U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                       false, false);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 35U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                       false, false);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 36U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes, 2U,
                       false, false);
    RALFWinkel17b_DW.obj.isSetupComplete = true;

    // InitializeConditions for Integrator: '<Root>/Integrator'
    RALFWinkel17b_X.Integrator_CSTATE = RALFWinkel17b_P.Integrator_IC;
  }
}

// Model terminate function
void RALFWinkel17b_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  matlabCodegenHandle_matlabC_gbl(&RALFWinkel17b_DW.obj_b);

  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  matlabCodegenHandle_matlabCodeg(&RALFWinkel17b_DW.obj);
  matlabCodegenHandle_matlabCo_gb(&RALFWinkel17b_DW.obj.i2cobj_MAG);
  matlabCodegenHandle_matlabCod_g(&RALFWinkel17b_DW.obj.i2cobj_A_G);
}

//
// File trailer for generated code.
//
// [EOF]
//
