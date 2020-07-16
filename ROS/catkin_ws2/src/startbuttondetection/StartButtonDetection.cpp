//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: StartButtonDetection.cpp
//
// Code generated for Simulink model 'StartButtonDetection'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Tue Jul  7 13:27:15 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "StartButtonDetection.h"
#include "StartButtonDetection_private.h"

// Block signals (default storage)
B_StartButtonDetection_T StartButtonDetection_B;

// Block states (default storage)
DW_StartButtonDetection_T StartButtonDetection_DW;

// Real-time model
RT_MODEL_StartButtonDetection_T StartButtonDetection_M_ =
  RT_MODEL_StartButtonDetection_T();
RT_MODEL_StartButtonDetection_T *const StartButtonDetection_M =
  &StartButtonDetection_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCod_p(ros_slros_internal_block_Subs_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
static void matlabCodegenHandle_matlabCod_p(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void StartButtonDetection_step(void)
{
  boolean_T b_varargout_1;
  SL_Bus_StartButtonDetection_std_msgs_Int16 rtb_BusAssignment;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S5>/In1'

  b_varargout_1 = Sub_StartButtonDetection_1.getLatestMessage
    (&StartButtonDetection_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S5>/Enable'

  if (b_varargout_1) {
    StartButtonDetection_B.In1 = StartButtonDetection_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion'
  //   MATLAB Function: '<Root>/MATLAB Function'

  rtb_BusAssignment.Data = static_cast<int16_T>
    (StartButtonDetection_B.In1.Buttons[7]);

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_StartButtonDetection_29.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // S-Function (saeroclockpacer): '<Root>/Simulation Pace'
  //
  //  The Clock Pacer generates no code, it is only active in
  //  interpreted simulation.

}

// Model initialize function
void StartButtonDetection_initialize(void)
{
  {
    char_T tmp[5];
    char_T tmp_0[13];
    int32_T i;
    static const char_T tmp_1[12] = { '/', 's', 't', 'a', 'r', 't', 'b', 'u',
      't', 't', 'o', 'n' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S5>/Out1'
    StartButtonDetection_B.In1 = StartButtonDetection_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    StartButtonDetection_DW.obj_n.matlabCodegenIsDeleted = false;
    StartButtonDetection_DW.obj_n.isInitialized = 1;
    tmp[0] = '/';
    tmp[1] = 'j';
    tmp[2] = 'o';
    tmp[3] = 'y';
    tmp[4] = '\x00';
    Sub_StartButtonDetection_1.createSubscriber(tmp, 1);
    StartButtonDetection_DW.obj_n.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    StartButtonDetection_DW.obj.matlabCodegenIsDeleted = false;
    StartButtonDetection_DW.obj.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_0[i] = tmp_1[i];
    }

    tmp_0[12] = '\x00';
    Pub_StartButtonDetection_29.createPublisher(tmp_0, 1);
    StartButtonDetection_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void StartButtonDetection_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  matlabCodegenHandle_matlabCod_p(&StartButtonDetection_DW.obj_n);

  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&StartButtonDetection_DW.obj);

  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
