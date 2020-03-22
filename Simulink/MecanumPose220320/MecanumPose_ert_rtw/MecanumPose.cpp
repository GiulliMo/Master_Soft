//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MecanumPose.cpp
//
// Code generated for Simulink model 'MecanumPose'.
//
// Model version                  : 1.5
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sun Mar 22 11:28:49 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "MecanumPose.h"
#include "MecanumPose_private.h"
#include "MecanumPose_dt.h"

// Block signals (default storage)
B_MecanumPose_T MecanumPose_B;

// Block states (default storage)
DW_MecanumPose_T MecanumPose_DW;

// Real-time model
RT_MODEL_MecanumPose_T MecanumPose_M_ = RT_MODEL_MecanumPose_T();
RT_MODEL_MecanumPose_T *const MecanumPose_M = &MecanumPose_M_;

// Forward declaration for local functions
static void MecanumPose_SystemCore_step(boolean_T *varargout_1, int16_T
  varargout_2_Data[128], uint32_T *varargout_2_Data_SL_Info_Curren, uint32_T
  *varargout_2_Data_SL_Info_Receiv, uint32_T *varargout_2_Layout_DataOffset,
  SL_Bus_MecanumPose_std_msgs_MultiArrayDimension varargout_2_Layout_Dim[16],
  uint32_T *varargout_2_Layout_Dim_SL_Info_, uint32_T
  *varargout_2_Layout_Dim_SL_Inf_0);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj);
static void MecanumPose_SystemCore_step(boolean_T *varargout_1, int16_T
  varargout_2_Data[128], uint32_T *varargout_2_Data_SL_Info_Curren, uint32_T
  *varargout_2_Data_SL_Info_Receiv, uint32_T *varargout_2_Layout_DataOffset,
  SL_Bus_MecanumPose_std_msgs_MultiArrayDimension varargout_2_Layout_Dim[16],
  uint32_T *varargout_2_Layout_Dim_SL_Info_, uint32_T
  *varargout_2_Layout_Dim_SL_Inf_0)
{
  *varargout_1 = Sub_MecanumPose_55.getLatestMessage
    (&MecanumPose_B.b_varargout_2);
  memcpy(&varargout_2_Data[0], &MecanumPose_B.b_varargout_2.Data[0], sizeof
         (int16_T) << 7U);
  *varargout_2_Data_SL_Info_Curren =
    MecanumPose_B.b_varargout_2.Data_SL_Info.CurrentLength;
  *varargout_2_Data_SL_Info_Receiv =
    MecanumPose_B.b_varargout_2.Data_SL_Info.ReceivedLength;
  *varargout_2_Layout_DataOffset = MecanumPose_B.b_varargout_2.Layout.DataOffset;
  memcpy(&varargout_2_Layout_Dim[0], &MecanumPose_B.b_varargout_2.Layout.Dim[0],
         sizeof(SL_Bus_MecanumPose_std_msgs_MultiArrayDimension) << 4U);
  *varargout_2_Layout_Dim_SL_Info_ =
    MecanumPose_B.b_varargout_2.Layout.Dim_SL_Info.CurrentLength;
  *varargout_2_Layout_Dim_SL_Inf_0 =
    MecanumPose_B.b_varargout_2.Layout.Dim_SL_Info.ReceivedLength;
}

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void MecanumPose_step(void)
{
  uint32_T b_varargout_2_Data_SL_Info_Curr;
  uint32_T b_varargout_2_Data_SL_Info_Rece;
  uint32_T b_varargout_2_Layout_DataOffset;
  uint32_T b_varargout_2_Layout_Dim_SL_Inf;
  uint32_T b_varargout_2_Layout_Dim_SL_I_0;
  boolean_T b_varargout_1;
  int32_T i;

  // Reset subsysRan breadcrumbs
  srClearBC(MecanumPose_DW.EnabledSubsystem_SubsysRanBC);

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S1>/SourceBlock' incorporates:
  //   Inport: '<S2>/In1'

  MecanumPose_SystemCore_step(&b_varargout_1, MecanumPose_B.b_varargout_2_Data,
    &b_varargout_2_Data_SL_Info_Curr, &b_varargout_2_Data_SL_Info_Rece,
    &b_varargout_2_Layout_DataOffset, MecanumPose_B.b_varargout_2_Layout_Dim,
    &b_varargout_2_Layout_Dim_SL_Inf, &b_varargout_2_Layout_Dim_SL_I_0);

  // Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S2>/Enable'

  if (b_varargout_1) {
    memcpy(&MecanumPose_B.In1.Data[0], &MecanumPose_B.b_varargout_2_Data[0],
           sizeof(int16_T) << 7U);
    MecanumPose_B.In1.Data_SL_Info.CurrentLength =
      b_varargout_2_Data_SL_Info_Curr;
    MecanumPose_B.In1.Data_SL_Info.ReceivedLength =
      b_varargout_2_Data_SL_Info_Rece;
    MecanumPose_B.In1.Layout.DataOffset = b_varargout_2_Layout_DataOffset;
    memcpy(&MecanumPose_B.In1.Layout.Dim[0],
           &MecanumPose_B.b_varargout_2_Layout_Dim[0], sizeof
           (SL_Bus_MecanumPose_std_msgs_MultiArrayDimension) << 4U);
    MecanumPose_B.In1.Layout.Dim_SL_Info.CurrentLength =
      b_varargout_2_Layout_Dim_SL_Inf;
    MecanumPose_B.In1.Layout.Dim_SL_Info.ReceivedLength =
      b_varargout_2_Layout_Dim_SL_I_0;
    srUpdateBC(MecanumPose_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S1>/SourceBlock'
  // End of Outputs for SubSystem: '<S1>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // SignalConversion generated from: '<Root>/Bus Selector'
  memcpy(&MecanumPose_B.Data[0], &MecanumPose_B.In1.Data[0], sizeof(int16_T) <<
         7U);
  for (i = 0; i < 4; i++) {
    // Product: '<Root>/Product' incorporates:
    //   Constant: '<Root>/Constant'
    //   Constant: '<Root>/Omega_Dot-Vel'
    //   Constant: '<Root>/X-Vel'
    //   Constant: '<Root>/Y-Vel'

    MecanumPose_B.Product[i] = 0.0;
    MecanumPose_B.Product[i] += MecanumPose_P.J[i] * MecanumPose_P.XVel_Value;
    MecanumPose_B.Product[i] += MecanumPose_P.J[i + 4] *
      MecanumPose_P.YVel_Value;
    MecanumPose_B.Product[i] += MecanumPose_P.J[i + 8] *
      MecanumPose_P.Omega_DotVel_Value;

    // Gain: '<Root>/Gain'
    MecanumPose_B.Gain[i] = MecanumPose_P.Gain_Gain * MecanumPose_B.Product[i];
  }

  // S-Function (saeroclockpacer): '<Root>/Simulation Pace'
  //
  //  The Clock Pacer generates no code, it is only active in
  //  interpreted simulation.


  // External mode
  rtExtModeUploadCheckTrigger(1);

  {                               // Sample time: [0.033333333333333333s, 0.0s]
    rtExtModeUpload(0, (real_T)MecanumPose_M->Timing.taskTime0);
  }

  // signal main to stop simulation
  {                               // Sample time: [0.033333333333333333s, 0.0s]
    if ((rtmGetTFinal(MecanumPose_M)!=-1) &&
        !((rtmGetTFinal(MecanumPose_M)-MecanumPose_M->Timing.taskTime0) >
          MecanumPose_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(MecanumPose_M, "Simulation finished");
    }

    if (rtmGetStopRequested(MecanumPose_M)) {
      rtmSetErrorStatus(MecanumPose_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  MecanumPose_M->Timing.taskTime0 =
    (++MecanumPose_M->Timing.clockTick0) * MecanumPose_M->Timing.stepSize0;
}

// Model initialize function
void MecanumPose_initialize(void)
{
  // Registration code
  rtmSetTFinal(MecanumPose_M, -1);
  MecanumPose_M->Timing.stepSize0 = 0.033333333333333333;

  // External mode info
  MecanumPose_M->Sizes.checksums[0] = (740626327U);
  MecanumPose_M->Sizes.checksums[1] = (1379849774U);
  MecanumPose_M->Sizes.checksums[2] = (2751554281U);
  MecanumPose_M->Sizes.checksums[3] = (3028142826U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    MecanumPose_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&MecanumPose_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(MecanumPose_M->extModeInfo,
      &MecanumPose_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MecanumPose_M->extModeInfo,
                        MecanumPose_M->Sizes.checksums);
    rteiSetTPtr(MecanumPose_M->extModeInfo, rtmGetTPtr(MecanumPose_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    MecanumPose_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    char_T tmp[9];
    int32_T i;
    static const char_T tmp_0[8] = { '/', 'C', 'A', 'N', 'r', 'e', 'a', 'd' };

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S1>/SourceBlock'
    MecanumPose_DW.obj.matlabCodegenIsDeleted = false;
    MecanumPose_DW.obj.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp[i] = tmp_0[i];
    }

    tmp[8] = '\x00';
    Sub_MecanumPose_55.createSubscriber(tmp, 1);
    MecanumPose_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S1>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S1>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S2>/Out1'
    MecanumPose_B.In1 = MecanumPose_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'
  }
}

// Model terminate function
void MecanumPose_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S1>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&MecanumPose_DW.obj);

  // End of Terminate for SubSystem: '<Root>/Subscribe'
}

//
// File trailer for generated code.
//
// [EOF]
//
