//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: audio_stream.cpp
//
// Code generated for Simulink model 'audio_stream'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Wed Jun  3 10:55:28 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "audio_stream.h"
#include "audio_stream_private.h"

// Block signals (default storage)
B_audio_stream_T audio_stream_B;

// Block states (default storage)
DW_audio_stream_T audio_stream_DW;

// Real-time model
RT_MODEL_audio_stream_T audio_stream_M_ = RT_MODEL_audio_stream_T();
RT_MODEL_audio_stream_T *const audio_stream_M = &audio_stream_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void audio_stream_step(void)
{
  char_T *sErr;
  SL_Bus_audio_stream_geometry_msgs_Point rtb_BusAssignment1;

  // S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader'
  sErr = GetErrorBuffer(&audio_stream_DW.AudioDeviceReader_AudioDeviceLi[0U]);
  LibOutputs_Audio(&audio_stream_DW.AudioDeviceReader_AudioDeviceLi[0U],
                   &audio_stream_B.AudioDeviceReader[0U], 2, 2048, 0);
  if (*sErr != 0) {
    rtmSetErrorStatus(audio_stream_M, sErr);
    rtmSetStopRequested(audio_stream_M, 1);
  }

  // End of S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<S1>/Constant'

  audio_stream_B.BusAssignment = audio_stream_P.Constant_Value;
  memcpy(&audio_stream_B.BusAssignment.Data[0],
         &audio_stream_B.AudioDeviceReader[0], sizeof(int16_T) << 11U);
  audio_stream_B.BusAssignment.Data_SL_Info.CurrentLength =
    audio_stream_P.Constant1_Value;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_audio_stream_6.publish(&audio_stream_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<S2>/Constant'

  rtb_BusAssignment1 = audio_stream_P.Constant_Value_m;
  rtb_BusAssignment1.X = audio_stream_P.Constant_Value_c;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_audio_stream_10.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'
}

// Model initialize function
void audio_stream_initialize(void)
{
  {
    char_T *sErr;
    char_T tmp[14];
    char_T tmp_0[4];
    int32_T i;
    static const char_T tmp_1[13] = { '/', 'a', 'u', 'd', 'i', 'o', '_', 's',
      't', 'r', 'e', 'a', 'm' };

    // Start for S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader' 
    sErr = GetErrorBuffer(&audio_stream_DW.AudioDeviceReader_AudioDeviceLi[0U]);
    CreateHostLibrary("libmwhostlibaudio.so",
                      &audio_stream_DW.AudioDeviceReader_AudioDeviceLi[0U]);
    if (*sErr == 0) {
      LibCreate_Audio(&audio_stream_DW.AudioDeviceReader_AudioDeviceLi[0U], 0,
                      "Xbox NUI Sensor: USB Audio (hw:0,0)", 8, 0, 1, 16000.0, 3,
                      2048, 20480, 2048, 2, NULL);
    }

    if (*sErr != 0) {
      DestroyHostLibrary(&audio_stream_DW.AudioDeviceReader_AudioDeviceLi[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(audio_stream_M, sErr);
        rtmSetStopRequested(audio_stream_M, 1);
      }
    }

    // End of Start for S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader' 

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    audio_stream_DW.obj_e.matlabCodegenIsDeleted = false;
    audio_stream_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp[i] = tmp_1[i];
    }

    tmp[13] = '\x00';
    Pub_audio_stream_6.createPublisher(tmp, 1);
    audio_stream_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    audio_stream_DW.obj.matlabCodegenIsDeleted = false;
    audio_stream_DW.obj.isInitialized = 1;
    tmp_0[0] = '/';
    tmp_0[1] = 'm';
    tmp_0[2] = 'y';
    tmp_0[3] = '\x00';
    Pub_audio_stream_10.createPublisher(tmp_0, 1);
    audio_stream_DW.obj.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Publish1'
  }
}

// Model terminate function
void audio_stream_terminate(void)
{
  char_T *sErr;

  // Terminate for S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader' 
  sErr = GetErrorBuffer(&audio_stream_DW.AudioDeviceReader_AudioDeviceLi[0U]);
  LibTerminate(&audio_stream_DW.AudioDeviceReader_AudioDeviceLi[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(audio_stream_M, sErr);
    rtmSetStopRequested(audio_stream_M, 1);
  }

  LibDestroy_Audio(&audio_stream_DW.AudioDeviceReader_AudioDeviceLi[0U], 0, 1);
  DestroyHostLibrary(&audio_stream_DW.AudioDeviceReader_AudioDeviceLi[0U]);

  // End of Terminate for S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader' 

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&audio_stream_DW.obj_e);

  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&audio_stream_DW.obj);

  // End of Terminate for SubSystem: '<Root>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
