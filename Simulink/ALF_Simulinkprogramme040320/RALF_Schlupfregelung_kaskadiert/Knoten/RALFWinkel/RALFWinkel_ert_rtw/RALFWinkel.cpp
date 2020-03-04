//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: RALFWinkel.cpp
//
// Code generated for Simulink model 'RALFWinkel'.
//
// Model version                  : 1.5
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Thu Nov 15 17:12:57 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "RALFWinkel.h"
#include "RALFWinkel_private.h"
#include "RALFWinkel_dt.h"
#define RALFWinkel_MessageQueueLen     (1)

// Block signals (auto storage)
B_RALFWinkel_T RALFWinkel_B;

// Continuous states
X_RALFWinkel_T RALFWinkel_X;

// Block states (auto storage)
DW_RALFWinkel_T RALFWinkel_DW;

// Real-time model
RT_MODEL_RALFWinkel_T RALFWinkel_M_;
RT_MODEL_RALFWinkel_T *const RALFWinkel_M = &RALFWinkel_M_;

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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  RALFWinkel_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  RALFWinkel_step();
  RALFWinkel_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  RALFWinkel_step();
  RALFWinkel_derivatives();

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

// Model step function
void RALFWinkel_step(void)
{
  int16_T b_output[3];
  uint8_T SwappedDataBytes;
  uint8_T status;
  uint8_T output_raw[6];
  int16_T b_output_0[3];
  SL_Bus_RALFWinkel_geometry_msgs_Point rtb_BusAssignment;
  int32_T i;
  if (rtmIsMajorTimeStep(RALFWinkel_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&RALFWinkel_M->solverInfo,
                          ((RALFWinkel_M->Timing.clockTick0+1)*
      RALFWinkel_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(RALFWinkel_M)) {
    RALFWinkel_M->Timing.t[0] = rtsiGetT(&RALFWinkel_M->solverInfo);
  }

  // Integrator: '<Root>/Integrator1'
  RALFWinkel_B.phi = RALFWinkel_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(RALFWinkel_M)) {
    // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
    status = 24U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(RALFWinkel_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(RALFWinkel_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
                        output_raw, 6U, false, true);
      memcpy((void *)&b_output[0], (void *)&output_raw[0], (uint32_T)((size_t)3 *
              sizeof(int16_T)));
    } else {
      b_output[0] = 0;
      b_output[1] = 0;
      b_output[2] = 0;
    }

    status = 40U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(RALFWinkel_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(RALFWinkel_DW.obj.i2cobj_A_G.MW_I2C_HANDLE, 106U,
                        output_raw, 6U, false, true);
      memcpy((void *)&b_output_0[0], (void *)&output_raw[0], (uint32_T)((size_t)
              3 * sizeof(int16_T)));
    }

    status = 40U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(RALFWinkel_DW.obj.i2cobj_MAG.MW_I2C_HANDLE, 28U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(RALFWinkel_DW.obj.i2cobj_MAG.MW_I2C_HANDLE, 28U,
                        output_raw, 6U, false, true);
      memcpy((void *)&b_output_0[0], (void *)&output_raw[0], (uint32_T)((size_t)
              3 * sizeof(int16_T)));
    }

    for (i = 0; i < 3; i++) {
      RALFWinkel_B.LSM9DS1IMUSensor_o1[i] = (((RALFWinkel_DW.obj.CalGyroA[3 * i
        + 1] * (real_T)b_output[1] + RALFWinkel_DW.obj.CalGyroA[3 * i] * (real_T)
        b_output[0]) + RALFWinkel_DW.obj.CalGyroA[3 * i + 2] * (real_T)b_output
        [2]) + RALFWinkel_DW.obj.CalGyroB[i]) * 245.0 / 32768.0;
    }

    // End of Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'

    // Sum: '<Root>/Sum1' incorporates:
    //   Constant: '<Root>/Constant'

    RALFWinkel_B.omega = RALFWinkel_B.LSM9DS1IMUSensor_o1[2] +
      RALFWinkel_P.Constant_Value_h;

    // Product: '<Root>/Product1' incorporates:
    //   Constant: '<S2>/Constant'
    //   RelationalOperator: '<S2>/Compare'

    RALFWinkel_B.sum1 = (real_T)(RALFWinkel_B.omega >=
      RALFWinkel_P.CompareToConstant1_const) * RALFWinkel_B.omega;

    // Product: '<Root>/Product2' incorporates:
    //   Constant: '<S3>/Constant'
    //   RelationalOperator: '<S3>/Compare'

    RALFWinkel_B.sum2 = (real_T)(RALFWinkel_B.omega <=
      RALFWinkel_P.CompareToConstant2_const) * RALFWinkel_B.omega;

    // Constant: '<S1>/Constant'
    RALFWinkel_B.Constant = RALFWinkel_P.Constant_Value;
  }

  // Integrator: '<Root>/Integrator'
  RALFWinkel_B.phi_ohneF = RALFWinkel_X.Integrator_CSTATE;

  // BusAssignment: '<Root>/Bus Assignment'
  rtb_BusAssignment = RALFWinkel_B.Constant;
  rtb_BusAssignment.Z = RALFWinkel_B.phi_ohneF;
  rtb_BusAssignment.Y = RALFWinkel_B.omega;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S4>/SinkBlock'
  Pub_RALFWinkel_96.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(RALFWinkel_M)) {
  }

  // TransferFcn: '<Root>/Transfer Fcn'
  RALFWinkel_B.omega_filter = 0.0;
  RALFWinkel_B.omega_filter += RALFWinkel_P.TransferFcn_C *
    RALFWinkel_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(RALFWinkel_M)) {
    // Sum: '<Root>/Sum'
    RALFWinkel_B.sumergebnis = RALFWinkel_B.sum1 + RALFWinkel_B.sum2;
  }

  if (rtmIsMajorTimeStep(RALFWinkel_M)) {
    // External mode
    rtExtModeUploadCheckTrigger(2);

    {                                  // Sample time: [0.0s, 0.0s]
      rtExtModeUpload(0, RALFWinkel_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(RALFWinkel_M)) {// Sample time: [0.01s, 0.0s]
      rtExtModeUpload(1, ((RALFWinkel_M->Timing.clockTick1) * 0.01));
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(RALFWinkel_M)) {
    // signal main to stop simulation
    {                                  // Sample time: [0.0s, 0.0s]
      if ((rtmGetTFinal(RALFWinkel_M)!=-1) &&
          !((rtmGetTFinal(RALFWinkel_M)-((RALFWinkel_M->Timing.clockTick1) *
             0.01)) > ((RALFWinkel_M->Timing.clockTick1) * 0.01) * (DBL_EPSILON)))
      {
        rtmSetErrorStatus(RALFWinkel_M, "Simulation finished");
      }

      if (rtmGetStopRequested(RALFWinkel_M)) {
        rtmSetErrorStatus(RALFWinkel_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&RALFWinkel_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++RALFWinkel_M->Timing.clockTick0;
    RALFWinkel_M->Timing.t[0] = rtsiGetSolverStopTime(&RALFWinkel_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.01s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.01, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      RALFWinkel_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void RALFWinkel_derivatives(void)
{
  XDot_RALFWinkel_T *_rtXdot;
  _rtXdot = ((XDot_RALFWinkel_T *) RALFWinkel_M->derivs);

  // Derivatives for Integrator: '<Root>/Integrator1'
  _rtXdot->Integrator1_CSTATE = RALFWinkel_B.omega_filter;

  // Derivatives for Integrator: '<Root>/Integrator'
  _rtXdot->Integrator_CSTATE = RALFWinkel_B.sumergebnis;

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn'
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += RALFWinkel_P.TransferFcn_A *
    RALFWinkel_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += RALFWinkel_B.sumergebnis;
}

// Model initialize function
void RALFWinkel_initialize(void)
{
  // Registration code

  // initialize real-time model
  (void) memset((void *)RALFWinkel_M, 0,
                sizeof(RT_MODEL_RALFWinkel_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&RALFWinkel_M->solverInfo,
                          &RALFWinkel_M->Timing.simTimeStep);
    rtsiSetTPtr(&RALFWinkel_M->solverInfo, &rtmGetTPtr(RALFWinkel_M));
    rtsiSetStepSizePtr(&RALFWinkel_M->solverInfo,
                       &RALFWinkel_M->Timing.stepSize0);
    rtsiSetdXPtr(&RALFWinkel_M->solverInfo, &RALFWinkel_M->derivs);
    rtsiSetContStatesPtr(&RALFWinkel_M->solverInfo, (real_T **)
                         &RALFWinkel_M->contStates);
    rtsiSetNumContStatesPtr(&RALFWinkel_M->solverInfo,
      &RALFWinkel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&RALFWinkel_M->solverInfo,
      &RALFWinkel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&RALFWinkel_M->solverInfo,
      &RALFWinkel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&RALFWinkel_M->solverInfo,
      &RALFWinkel_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&RALFWinkel_M->solverInfo, (&rtmGetErrorStatus
      (RALFWinkel_M)));
    rtsiSetRTModelPtr(&RALFWinkel_M->solverInfo, RALFWinkel_M);
  }

  rtsiSetSimTimeStep(&RALFWinkel_M->solverInfo, MAJOR_TIME_STEP);
  RALFWinkel_M->intgData.y = RALFWinkel_M->odeY;
  RALFWinkel_M->intgData.f[0] = RALFWinkel_M->odeF[0];
  RALFWinkel_M->intgData.f[1] = RALFWinkel_M->odeF[1];
  RALFWinkel_M->intgData.f[2] = RALFWinkel_M->odeF[2];
  RALFWinkel_M->contStates = ((X_RALFWinkel_T *) &RALFWinkel_X);
  rtsiSetSolverData(&RALFWinkel_M->solverInfo, (void *)&RALFWinkel_M->intgData);
  rtsiSetSolverName(&RALFWinkel_M->solverInfo,"ode3");
  rtmSetTPtr(RALFWinkel_M, &RALFWinkel_M->Timing.tArray[0]);
  rtmSetTFinal(RALFWinkel_M, -1);
  RALFWinkel_M->Timing.stepSize0 = 0.01;

  // External mode info
  RALFWinkel_M->Sizes.checksums[0] = (2697412868U);
  RALFWinkel_M->Sizes.checksums[1] = (1874277108U);
  RALFWinkel_M->Sizes.checksums[2] = (2915317031U);
  RALFWinkel_M->Sizes.checksums[3] = (3028919781U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    RALFWinkel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(RALFWinkel_M->extModeInfo,
      &RALFWinkel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RALFWinkel_M->extModeInfo, RALFWinkel_M->Sizes.checksums);
    rteiSetTPtr(RALFWinkel_M->extModeInfo, rtmGetTPtr(RALFWinkel_M));
  }

  // block I/O
  (void) memset(((void *) &RALFWinkel_B), 0,
                sizeof(B_RALFWinkel_T));

  // states (continuous)
  {
    (void) memset((void *)&RALFWinkel_X, 0,
                  sizeof(X_RALFWinkel_T));
  }

  // states (dwork)
  (void) memset((void *)&RALFWinkel_DW, 0,
                sizeof(DW_RALFWinkel_T));

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    RALFWinkel_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    uint8_T SwappedDataBytes;
    uint8_T b_SwappedDataBytes[2];
    uint8_T SwappedDataBytes_0[2];
    uint8_T CastedData;
    static const char_T tmp[8] = { '/', 'm', 'y', '_', 'p', 'h', 'i', '2' };

    static const int8_T tmp_0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    char_T tmp_1[9];
    int32_T i;

    // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
    obj = &RALFWinkel_DW.obj;
    for (i = 0; i < 9; i++) {
      RALFWinkel_DW.obj.CalGyroA[i] = tmp_0[i];
    }

    RALFWinkel_DW.obj.CalGyroB[0] = 0.0;
    RALFWinkel_DW.obj.CalGyroB[1] = 0.0;
    RALFWinkel_DW.obj.CalGyroB[2] = 0.0;
    for (i = 0; i < 9; i++) {
      RALFWinkel_DW.obj.CalAccelA[i] = tmp_0[i];
    }

    RALFWinkel_DW.obj.CalAccelB[0] = 0.0;
    RALFWinkel_DW.obj.CalAccelB[1] = 0.0;
    RALFWinkel_DW.obj.CalAccelB[2] = 0.0;
    for (i = 0; i < 9; i++) {
      RALFWinkel_DW.obj.CalMagA[i] = tmp_0[i];
    }

    RALFWinkel_DW.obj.CalMagB[0] = 0.0;
    RALFWinkel_DW.obj.CalMagB[1] = 0.0;
    RALFWinkel_DW.obj.CalMagB[2] = 0.0;
    RALFWinkel_DW.obj.isInitialized = 0;
    obj->i2cobj_A_G.isInitialized = 0;
    obj->i2cobj_MAG.isInitialized = 0;
    obj = &RALFWinkel_DW.obj;
    RALFWinkel_DW.obj.isInitialized = 1;
    i2cname = 1;
    obj->i2cobj_A_G.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0U);
    obj->i2cobj_A_G.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(obj->i2cobj_A_G.MW_I2C_HANDLE, obj->i2cobj_A_G.BusSpeed);
    CastedData = 96U;
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 16U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes_0,
                       2U, false, false);
    CastedData = 0U;
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 17U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes_0,
                       2U, false, false);
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 18U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes_0,
                       2U, false, false);
    CastedData = 56U;
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 30U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes_0,
                       2U, false, false);
    CastedData = 0U;
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 19U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes_0,
                       2U, false, false);
    CastedData = 56U;
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 31U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes_0,
                       2U, false, false);
    CastedData = 103U;
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 32U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes_0,
                       2U, false, false);
    CastedData = 0U;
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 33U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes_0,
                       2U, false, false);
    CastedData = 4U;
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 34U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_A_G.MW_I2C_HANDLE, 106U, SwappedDataBytes_0,
                       2U, false, false);
    i2cname = 1;
    obj->i2cobj_MAG.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0U);
    obj->i2cobj_MAG.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(obj->i2cobj_MAG.MW_I2C_HANDLE, obj->i2cobj_MAG.BusSpeed);
    CastedData = 24U;
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 32U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes_0,
                       2U, false, false);
    CastedData = 0U;
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 33U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes_0,
                       2U, false, false);
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 34U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes_0,
                       2U, false, false);
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 35U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes_0,
                       2U, false, false);
    memcpy((void *)&SwappedDataBytes, (void *)&CastedData, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 36U;
    b_SwappedDataBytes[1] = SwappedDataBytes;
    memcpy((void *)&SwappedDataBytes_0[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cobj_MAG.MW_I2C_HANDLE, 28U, SwappedDataBytes_0,
                       2U, false, false);

    // End of Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'

    // Start for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    RALFWinkel_DW.obj_j.isInitialized = 0;
    RALFWinkel_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_1[i] = tmp[i];
    }

    tmp_1[8] = '\x00';
    Pub_RALFWinkel_96.createPublisher(tmp_1, RALFWinkel_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish'

    // InitializeConditions for Integrator: '<Root>/Integrator1'
    RALFWinkel_X.Integrator1_CSTATE = RALFWinkel_P.Integrator1_IC;

    // InitializeConditions for Integrator: '<Root>/Integrator'
    RALFWinkel_X.Integrator_CSTATE = RALFWinkel_P.Integrator_IC;

    // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn'
    RALFWinkel_X.TransferFcn_CSTATE = 0.0;
  }
}

// Model terminate function
void RALFWinkel_terminate(void)
{
  boolean_T flag;
  raspi_internal_lsm9ds1Block_R_T *obj;

  // Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'
  flag = (RALFWinkel_DW.obj.isInitialized == 1);
  if (flag) {
    obj = &RALFWinkel_DW.obj;
    if (RALFWinkel_DW.obj.isInitialized == 1) {
      RALFWinkel_DW.obj.isInitialized = 2;
      MW_I2C_Close(obj->i2cobj_A_G.MW_I2C_HANDLE);
      MW_I2C_Close(obj->i2cobj_MAG.MW_I2C_HANDLE);
    }
  }

  // End of Start for MATLABSystem: '<Root>/LSM9DS1 IMU Sensor'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S4>/SinkBlock'
  if (RALFWinkel_DW.obj_j.isInitialized == 1) {
    RALFWinkel_DW.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
