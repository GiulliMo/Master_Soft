//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: RALFMain_SLAM_data.cpp
//
// Code generated for Simulink model 'RALFMain_SLAM'.
//
// Model version                  : 1.189
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Tue Apr 28 13:32:56 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "RALFMain_SLAM.h"
#include "RALFMain_SLAM_private.h"

// Block parameters (default storage)
P_RALFMain_SLAM_T RALFMain_SLAM_P = {
  // Variable: nmax
  //  Referenced by:
  //    '<S41>/Gain'
  //    '<S41>/Gain1'

  200.0F,

  // Variable: pwinkel
  //  Referenced by: '<S51>/Gain4'

  0.05F,

  // Variable: pwinkel_vel
  //  Referenced by: '<S52>/Gain4'

  -4.0F,

  // Mask Parameter: CompareToConstant1_const
  //  Referenced by: '<S17>/Constant'

  0.05,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S53>/Constant'

  0.9F,

  // Mask Parameter: CompareToConstant_const_m
  //  Referenced by: '<S28>/Constant'

  0.05F,

  // Mask Parameter: CompareToConstant_const_o
  //  Referenced by: '<S22>/Constant'

  0.1F,

  // Mask Parameter: CompareToConstant1_const_p
  //  Referenced by: '<S23>/Constant'

  -0.1F,

  // Mask Parameter: CompareToConstant3_const
  //  Referenced by: '<S25>/Constant'

  0.1F,

  // Mask Parameter: CompareToConstant2_const
  //  Referenced by: '<S24>/Constant'

  -0.1F,

  // Mask Parameter: CompareToConstant_const_j
  //  Referenced by: '<S32>/Constant'

  0.1F,

  // Mask Parameter: CompareToConstant1_const_l
  //  Referenced by: '<S33>/Constant'

  -0.1F,

  // Mask Parameter: CompareToConstant3_const_f
  //  Referenced by: '<S35>/Constant'

  0.1F,

  // Mask Parameter: CompareToConstant2_const_i
  //  Referenced by: '<S34>/Constant'

  -0.1F,

  // Mask Parameter: CompareToConstant_const_l
  //  Referenced by: '<S48>/Constant'

  0.9F,

  // Mask Parameter: CompareToConstant_const_g
  //  Referenced by: '<S8>/Constant'

  0.9F,

  // Mask Parameter: Counter_HitValue
  //  Referenced by: '<S2>/Counter'

  32U,

  // Mask Parameter: Counter1_HitValue
  //  Referenced by: '<S2>/Counter1'

  32U,

  // Mask Parameter: Counter_HitValue_f
  //  Referenced by: '<S18>/Counter'

  32U,

  // Mask Parameter: Counter_InitialCount
  //  Referenced by: '<S2>/Counter'

  0U,

  // Mask Parameter: Counter1_InitialCount
  //  Referenced by: '<S2>/Counter1'

  0U,

  // Mask Parameter: Counter_InitialCount_n
  //  Referenced by: '<S18>/Counter'

  0U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S27>/Out1'

  {
    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // Axes

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Axes_SL_Info

    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    ,                                  // Buttons

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Buttons_SL_Info

    {
      0U,                              // Seq

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // FrameId_SL_Info

      {
        0.0,                           // Sec
        0.0                            // Nsec
      }                                // Stamp
    }                                  // Header
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S15>/Constant'

  {
    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // Axes

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Axes_SL_Info

    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    ,                                  // Buttons

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Buttons_SL_Info

    {
      0U,                              // Seq

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // FrameId_SL_Info

      {
        0.0,                           // Sec
        0.0                            // Nsec
      }                                // Stamp
    }                                  // Header
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S11>/Constant'

  {
    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // Axes

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Axes_SL_Info

    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    ,                                  // Buttons

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Buttons_SL_Info

    {
      0U,                              // Seq

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // FrameId_SL_Info

      {
        0.0,                           // Sec
        0.0                            // Nsec
      }                                // Stamp
    }                                  // Header
  },

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S39>/Out1'

  {
    {
      0U,                              // Seq

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // FrameId_SL_Info

      {
        0.0,                           // Sec
        0.0                            // Nsec
      }                                // Stamp
    },                                 // Header

    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Position

      {
        0.0,                           // X
        0.0,                           // Y
        0.0,                           // Z
        0.0                            // W
      }                                // Orientation
    }                                  // Pose
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S38>/Constant'

  {
    {
      0U,                              // Seq

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // FrameId_SL_Info

      {
        0.0,                           // Sec
        0.0                            // Nsec
      }                                // Stamp
    },                                 // Header

    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Position

      {
        0.0,                           // X
        0.0,                           // Y
        0.0,                           // Z
        0.0                            // W
      }                                // Orientation
    }                                  // Pose
  },

  // Computed Parameter: Out1_Y0_j
  //  Referenced by: '<S36>/Out1'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S30>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Expression: -5
  //  Referenced by: '<S2>/Gain1'

  -5.0,

  // Expression: 5
  //  Referenced by: '<S2>/Gain'

  5.0,

  // Expression: 180/pi
  //  Referenced by: '<S5>/Gain'

  57.295779513082323,

  // Expression: 1
  //  Referenced by: '<S62>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S63>/Constant'

  1.0,

  // Expression: -2
  //  Referenced by: '<S10>/Constant1'

  -2.0,

  // Expression: 1
  //  Referenced by: '<S10>/Constant'

  1.0,

  // Expression: 8
  //  Referenced by: '<S2>/Constant2'

  8.0,

  // Expression: 11
  //  Referenced by: '<S2>/Constant3'

  11.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S6>/Gain3'

  57.295779513082323,

  // Expression: -1
  //  Referenced by: '<S47>/Constant'

  -1.0,

  // Expression: [-1;1;-1;1]
  //  Referenced by: '<S1>/Constant'

  { -1.0, 1.0, -1.0, 1.0 },

  // Computed Parameter: CANsendbackleft_P1_Size
  //  Referenced by: '<S1>/CAN send back left'

  { 1.0, 1.0 },

  // Expression: Port
  //  Referenced by: '<S1>/CAN send back left'

  1.0,

  // Computed Parameter: CANsendbackleft_P2_Size
  //  Referenced by: '<S1>/CAN send back left'

  { 1.0, 1.0 },

  // Expression: Identifier
  //  Referenced by: '<S1>/CAN send back left'

  289.0,

  // Computed Parameter: CANsendbackright_P1_Size
  //  Referenced by: '<S1>/CAN send back right'

  { 1.0, 1.0 },

  // Expression: Port
  //  Referenced by: '<S1>/CAN send back right'

  1.0,

  // Computed Parameter: CANsendbackright_P2_Size
  //  Referenced by: '<S1>/CAN send back right'

  { 1.0, 1.0 },

  // Expression: Identifier
  //  Referenced by: '<S1>/CAN send back right'

  305.0,

  // Computed Parameter: CANsendfrontleft_P1_Size
  //  Referenced by: '<S1>/CAN send front left'

  { 1.0, 1.0 },

  // Expression: Port
  //  Referenced by: '<S1>/CAN send front left'

  1.0,

  // Computed Parameter: CANsendfrontleft_P2_Size
  //  Referenced by: '<S1>/CAN send front left'

  { 1.0, 1.0 },

  // Expression: Identifier
  //  Referenced by: '<S1>/CAN send front left'

  273.0,

  // Computed Parameter: CANsendfrontright_P1_Size
  //  Referenced by: '<S1>/CAN send front right'

  { 1.0, 1.0 },

  // Expression: Port
  //  Referenced by: '<S1>/CAN send front right'

  1.0,

  // Computed Parameter: CANsendfrontright_P2_Size
  //  Referenced by: '<S1>/CAN send front right'

  { 1.0, 1.0 },

  // Expression: Identifier
  //  Referenced by: '<S1>/CAN send front right'

  257.0,

  // Expression: SimulationPace
  //  Referenced by: '<Root>/Simulation Pace'

  1.0,

  // Expression: 1
  //  Referenced by: '<Root>/Simulation Pace'

  1.0,

  // Expression: OutputPaceError
  //  Referenced by: '<Root>/Simulation Pace'

  0.0,

  // Expression: SampleTime
  //  Referenced by: '<Root>/Simulation Pace'

  -1.0,

  // Computed Parameter: Constant_Value_gi
  //  Referenced by: '<S4>/Constant'

  0.0F,

  // Computed Parameter: MagnitudeAngletoComplex_Constan
  //  Referenced by: '<S16>/Magnitude-Angle to Complex'

  1.0F,

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S46>/Out1'

  0.0F,

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S50>/Constant'

  { 1.0F, 1.0F, 1.0F, 1.0F, -1.0F, 1.0F, 1.0F, -1.0F },

  // Computed Parameter: Gain_Gain_c
  //  Referenced by: '<S10>/Gain'

  -1.0F,

  // Computed Parameter: Gain1_Gain_o
  //  Referenced by: '<S10>/Gain1'

  -1.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S10>/Gain2'

  -1.0F,

  // Computed Parameter: Constant_Value_la
  //  Referenced by: '<S3>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S18>/Constant'

  2.0F,

  // Computed Parameter: Switch_Threshold
  //  Referenced by: '<S3>/Switch'

  0.0F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: '<S50>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: '<S50>/Saturation3'

  -1.0F,

  // Computed Parameter: Gain2_Gain_l
  //  Referenced by: '<S6>/Gain2'

  0.0174532924F,

  // Computed Parameter: Gain_Gain_f
  //  Referenced by: '<S6>/Gain'

  0.0174532924F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S6>/Saturation'

  20.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S6>/Saturation'

  -20.0F,

  // Computed Parameter: Constant1_Value_d
  //  Referenced by: '<S51>/Constant1'

  { -1.0F, 1.0F, -1.0F, 1.0F },

  // Computed Parameter: Constant1_Value_i
  //  Referenced by: '<S52>/Constant1'

  { -1.0F, 1.0F, -1.0F, 1.0F },

  // Computed Parameter: Gain3_Gain_i
  //  Referenced by: '<S41>/Gain3'

  -200.0F,

  // Computed Parameter: Gain2_Gain_d
  //  Referenced by: '<S41>/Gain2'

  -200.0F,

  // Computed Parameter: Delay_InitialCondition
  //  Referenced by: '<S19>/Delay'

  1
};

//
// File trailer for generated code.
//
// [EOF]
//
