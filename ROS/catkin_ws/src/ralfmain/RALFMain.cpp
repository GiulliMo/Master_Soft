//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: RALFMain.cpp
//
// Code generated for Simulink model 'RALFMain'.
//
// Model version                  : 1.188
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Mon Apr 27 13:52:35 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "RALFMain.h"
#include "RALFMain_private.h"

// Block signals (default storage)
B_RALFMain_T RALFMain_B;

// Block states (default storage)
DW_RALFMain_T RALFMain_DW;

// Real-time model
RT_MODEL_RALFMain_T RALFMain_M_ = RT_MODEL_RALFMain_T();
RT_MODEL_RALFMain_T *const RALFMain_M = &RALFMain_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj);

//
// System initialize for atomic system:
//    synthesized block
//    synthesized block
//
void CoordinateTransformationCo_Init(DW_CoordinateTransformationCo_T *localDW)
{
  // Start for MATLABSystem: '<S6>/Coordinate Transformation Conversion1'
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

//
// Output and update for atomic system:
//    synthesized block
//    synthesized block
//
void CoordinateTransformationConvers(const real32_T rtu_0[3],
  B_CoordinateTransformationCon_T *localB)
{
  real32_T c_idx_0;
  real32_T c_idx_1;
  real32_T c_idx_2;
  real32_T s_idx_0;
  real32_T s_idx_1;
  real32_T s_idx_2;
  real32_T soll_quat_tmp;
  real32_T soll_quat_tmp_0;

  // MATLABSystem: '<S6>/Coordinate Transformation Conversion1'
  s_idx_2 = rtu_0[0] / 2.0F;
  c_idx_0 = s_idx_2;
  s_idx_0 = s_idx_2;
  s_idx_2 = rtu_0[1] / 2.0F;
  c_idx_1 = s_idx_2;
  s_idx_1 = s_idx_2;
  s_idx_2 = rtu_0[2] / 2.0F;
  c_idx_0 = static_cast<real32_T>(cos(static_cast<real_T>(c_idx_0)));
  c_idx_1 = static_cast<real32_T>(cos(static_cast<real_T>(c_idx_1)));
  c_idx_2 = static_cast<real32_T>(cos(static_cast<real_T>(s_idx_2)));
  s_idx_0 = static_cast<real32_T>(sin(static_cast<real_T>(s_idx_0)));
  s_idx_1 = static_cast<real32_T>(sin(static_cast<real_T>(s_idx_1)));
  s_idx_2 = static_cast<real32_T>(sin(static_cast<real_T>(s_idx_2)));
  soll_quat_tmp = c_idx_0 * c_idx_1;
  soll_quat_tmp_0 = s_idx_0 * s_idx_1;
  localB->soll_quat[0] = soll_quat_tmp * c_idx_2 + soll_quat_tmp_0 * s_idx_2;
  localB->soll_quat[1] = soll_quat_tmp * s_idx_2 - soll_quat_tmp_0 * c_idx_2;
  soll_quat_tmp = s_idx_0 * c_idx_1;
  soll_quat_tmp_0 = c_idx_0 * s_idx_1;
  localB->soll_quat[2] = soll_quat_tmp_0 * c_idx_2 + soll_quat_tmp * s_idx_2;
  localB->soll_quat[3] = soll_quat_tmp * c_idx_2 - soll_quat_tmp_0 * s_idx_2;
}

uint32_T MWDSP_EPH_R_S32(int32_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int32_T curState;
  int32_T newState;
  int32_T newStateR;
  int32_T lastzcevent;
  uint32_T previousState;

  // S-Function (sdspcount2): '<S2>/Counter'
  // Detect rising edge events
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt > 0) {
    curState = 2;
  } else {
    curState = (evt >= 0);
  }

  if (*sta == 5U) {
    newStateR = curState;
  } else {
    if (static_cast<uint32_T>(curState) != *sta) {
      if (*sta == 3U) {
        if (static_cast<uint32_T>(curState) == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 2;
          previousState = 1U;
        }
      }

      if (previousState == 4U) {
        if (static_cast<uint32_T>(curState) == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 3;
          previousState = 1U;
        }
      }

      if ((previousState == 1U) && (static_cast<uint32_T>(curState) == 2U)) {
        retVal = 2U;
      }

      if (previousState == 0U) {
        retVal = 2U;
      }

      if (retVal == static_cast<uint32_T>(lastzcevent)) {
        retVal = 0U;
      }

      if ((static_cast<uint32_T>(curState) == 1U) && (retVal == 2U)) {
        newState = 3;
      } else {
        newState = curState;
      }
    }
  }

  if (static_cast<uint32_T>(newStateR) != 5U) {
    *sta = static_cast<uint32_T>(newStateR);
    retVal = 0U;
  }

  if (static_cast<uint32_T>(newState) != 5U) {
    *sta = static_cast<uint32_T>(newState);
  }

  // End of S-Function (sdspcount2): '<S2>/Counter'
  return retVal;
}

uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int32_T curState;
  int32_T newState;
  int32_T newStateR;
  int32_T lastzcevent;
  uint32_T previousState;

  // S-Function (sdspcount2): '<S18>/Counter'
  // Detect rising edge events
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt) {
    curState = 2;
  } else {
    curState = 1;
  }

  if (*sta == 5U) {
    newStateR = curState;
  } else {
    if (static_cast<uint32_T>(curState) != *sta) {
      if (*sta == 3U) {
        if (static_cast<uint32_T>(curState) == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 2;
          previousState = 1U;
        }
      }

      if (previousState == 4U) {
        if (static_cast<uint32_T>(curState) == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 3;
          previousState = 1U;
        }
      }

      if ((previousState == 1U) && (static_cast<uint32_T>(curState) == 2U)) {
        retVal = 2U;
      }

      if (previousState == 0U) {
        retVal = 2U;
      }

      if (retVal == static_cast<uint32_T>(lastzcevent)) {
        retVal = 0U;
      }

      if ((static_cast<uint32_T>(curState) == 1U) && (retVal == 2U)) {
        newState = 3;
      } else {
        newState = curState;
      }
    }
  }

  if (static_cast<uint32_T>(newStateR) != 5U) {
    *sta = static_cast<uint32_T>(newStateR);
    retVal = 0U;
  }

  if (static_cast<uint32_T>(newState) != 5U) {
    *sta = static_cast<uint32_T>(newState);
  }

  // End of S-Function (sdspcount2): '<S18>/Counter'
  return retVal;
}

real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  boolean_T yEq;
  real32_T q;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    y = static_cast<real32_T>(fmod(static_cast<real_T>(u0), static_cast<real_T>
      (u1)));
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > static_cast<real32_T>(floor(static_cast<real_T>(u1)))))
    {
      q = static_cast<real32_T>(fabs(static_cast<real_T>(u0 / u1)));
      yEq = !(static_cast<real32_T>(fabs(static_cast<real_T>(q -
                 static_cast<real32_T>(floor(static_cast<real_T>(q + 0.5F)))))) >
              FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else {
      if ((u0 < 0.0F) != (u1 < 0.0F)) {
        y += u1;
      }
    }
  }

  return y;
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0F) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = static_cast<real32_T>(atan2(static_cast<real_T>(static_cast<real32_T>
      (u0_0)), static_cast<real_T>(static_cast<real32_T>(u1_0))));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = static_cast<real32_T>(atan2(static_cast<real_T>(u0), static_cast<real_T>
      (u1)));
  }

  return y;
}

real32_T rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T a;
  a = static_cast<real32_T>(fabs(static_cast<real_T>(u0)));
  y = static_cast<real32_T>(fabs(static_cast<real_T>(u1)));
  if (a < y) {
    a /= y;
    y *= static_cast<real32_T>(sqrt(static_cast<real_T>(a * a + 1.0F)));
  } else if (a > y) {
    y /= a;
    y = static_cast<real32_T>(sqrt(static_cast<real_T>(y * y + 1.0F))) * a;
  } else {
    if (!rtIsNaNF(y)) {
      y = a * 1.41421354F;
    }
  }

  return y;
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

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void RALFMain_step(void)
{
  boolean_T rtb_LogicalOperator1_i;
  real32_T rtb_BusAssignment_Axes_idx_2;
  real32_T rtb_BusAssignment_Axes_idx_3;

  // Outputs for Atomic SubSystem: '<S2>/Subscribe'
  // MATLABSystem: '<S15>/SourceBlock' incorporates:
  //   Inport: '<S27>/In1'

  rtb_LogicalOperator1_i = Sub_RALFMain_869.getLatestMessage
    (&RALFMain_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S15>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S27>/Enable'

  if (rtb_LogicalOperator1_i) {
    RALFMain_B.In1_i = RALFMain_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S15>/SourceBlock'
  // End of Outputs for SubSystem: '<S15>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S2>/Subscribe'

  // Product: '<S10>/Divide' incorporates:
  //   Constant: '<S10>/Constant'
  //   Constant: '<S10>/Constant1'
  //   Sum: '<S10>/Add'

  RALFMain_B.rtb_Divide_idx_0 = (RALFMain_B.In1_i.Axes[2] -
    RALFMain_P.Constant_Value_gx) / RALFMain_P.Constant1_Value;
  RALFMain_B.rtb_Divide_idx_1 = (RALFMain_B.In1_i.Axes[5] -
    RALFMain_P.Constant_Value_gx) / RALFMain_P.Constant1_Value;

  // Gain: '<S10>/Gain'
  RALFMain_B.Product2_i = RALFMain_P.Gain_Gain_c * RALFMain_B.In1_i.Axes[0];

  // BusAssignment: '<S2>/Bus Assignment' incorporates:
  //   Constant: '<S17>/Constant'
  //   Product: '<S10>/Product1'
  //   RelationalOperator: '<S17>/Compare'

  rtb_BusAssignment_Axes_idx_2 = static_cast<real32_T>(static_cast<real_T>
    (RALFMain_B.rtb_Divide_idx_0 >= RALFMain_P.CompareToConstant1_const) *
    RALFMain_B.rtb_Divide_idx_0);
  rtb_BusAssignment_Axes_idx_3 = static_cast<real32_T>(static_cast<real_T>
    (RALFMain_B.rtb_Divide_idx_1 >= RALFMain_P.CompareToConstant1_const) *
    RALFMain_B.rtb_Divide_idx_1);

  // S-Function (sdspcount2): '<S2>/Counter' incorporates:
  //   BusAssignment: '<S2>/Bus Assignment'

  if (MWDSP_EPH_R_S32(RALFMain_B.In1_i.Buttons[4],
                      &RALFMain_DW.Counter_ClkEphState) != 0U) {
    if (RALFMain_DW.Counter_Count < 255) {
      RALFMain_DW.Counter_Count = static_cast<uint8_T>(RALFMain_DW.Counter_Count
        + 1U);
    } else {
      RALFMain_DW.Counter_Count = 0U;
    }
  }

  // S-Function (sdspcount2): '<S2>/Counter1' incorporates:
  //   BusAssignment: '<S2>/Bus Assignment'

  if (MWDSP_EPH_R_S32(RALFMain_B.In1_i.Buttons[5],
                      &RALFMain_DW.Counter1_ClkEphState) != 0U) {
    if (RALFMain_DW.Counter1_Count < 255) {
      RALFMain_DW.Counter1_Count = static_cast<uint8_T>
        (RALFMain_DW.Counter1_Count + 1U);
    } else {
      RALFMain_DW.Counter1_Count = 0U;
    }
  }

  // S-Function (sdspcount2): '<S18>/Counter' incorporates:
  //   BusAssignment: '<S2>/Bus Assignment'
  //   DataTypeConversion: '<S18>/Data Type Conversion'
  //   DataTypeConversion: '<S19>/Data Type Conversion'
  //   Delay: '<S19>/Delay'
  //   Logic: '<S19>/Logical Operator'
  //   Logic: '<S19>/Logical Operator1'

  if (MWDSP_EPH_R_B((RALFMain_B.In1_i.Buttons[1] != 0.0F) &&
                    (!RALFMain_DW.Delay_DSTATE),
                    &RALFMain_DW.Counter_ClkEphState_a) != 0U) {
    if (RALFMain_DW.Counter_Count_i < 255) {
      RALFMain_DW.Counter_Count_i = static_cast<uint8_T>
        (RALFMain_DW.Counter_Count_i + 1U);
    } else {
      RALFMain_DW.Counter_Count_i = 0U;
    }
  }

  // DataTypeConversion: '<S48>/Data Type Conversion' incorporates:
  //   Constant: '<S52>/Constant'
  //   RelationalOperator: '<S52>/Compare'

  RALFMain_B.DataTypeConversion_p = (rtb_BusAssignment_Axes_idx_2 >
    RALFMain_P.CompareToConstant_const);

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S38>/In1'

  rtb_LogicalOperator1_i = Sub_RALFMain_1223.getLatestMessage
    (&RALFMain_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S38>/Enable'

  if (rtb_LogicalOperator1_i) {
    RALFMain_B.In1 = RALFMain_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // MATLABSystem: '<Root>/Coordinate Transformation Conversion' incorporates:
  //   SignalConversion generated from: '<Root>/Coordinate Transformation Conversion'

  RALFMain_B.rtb_istquat_idx_0 = 1.0 / sqrt
    (((RALFMain_B.In1.Pose.Pose.Orientation.X *
       RALFMain_B.In1.Pose.Pose.Orientation.X +
       RALFMain_B.In1.Pose.Pose.Orientation.Y *
       RALFMain_B.In1.Pose.Pose.Orientation.Y) +
      RALFMain_B.In1.Pose.Pose.Orientation.Z *
      RALFMain_B.In1.Pose.Pose.Orientation.Z) +
     RALFMain_B.In1.Pose.Pose.Orientation.W *
     RALFMain_B.In1.Pose.Pose.Orientation.W);
  RALFMain_B.rtb_Divide_idx_0 = RALFMain_B.In1.Pose.Pose.Orientation.X *
    RALFMain_B.rtb_istquat_idx_0;
  RALFMain_B.rtb_Divide_idx_1 = RALFMain_B.In1.Pose.Pose.Orientation.Y *
    RALFMain_B.rtb_istquat_idx_0;
  RALFMain_B.rtb_istquat_idx_2 = RALFMain_B.In1.Pose.Pose.Orientation.Z *
    RALFMain_B.rtb_istquat_idx_0;
  RALFMain_B.rtb_istquat_idx_0 *= RALFMain_B.In1.Pose.Pose.Orientation.W;

  // Outputs for Atomic SubSystem: '<S4>/Subscribe'
  // MATLABSystem: '<S30>/SourceBlock' incorporates:
  //   Inport: '<S36>/In1'

  rtb_LogicalOperator1_i = Sub_RALFMain_963.getLatestMessage
    (&RALFMain_B.b_varargout_2_c);

  // Outputs for Enabled SubSystem: '<S30>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S36>/Enable'

  if (rtb_LogicalOperator1_i) {
    RALFMain_B.In1_m = RALFMain_B.b_varargout_2_c;
  }

  // End of MATLABSystem: '<S30>/SourceBlock'
  // End of Outputs for SubSystem: '<S30>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S4>/Subscribe'

  // Switch: '<S3>/Switch' incorporates:
  //   Constant: '<S18>/Constant'
  //   Constant: '<S22>/Constant'
  //   Constant: '<S23>/Constant'
  //   Constant: '<S24>/Constant'
  //   Constant: '<S25>/Constant'
  //   Constant: '<S32>/Constant'
  //   Constant: '<S33>/Constant'
  //   Constant: '<S34>/Constant'
  //   Constant: '<S35>/Constant'
  //   Constant: '<S3>/Constant'
  //   Constant: '<S4>/Constant'
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   DataTypeConversion: '<S13>/Data Type Conversion1'
  //   DataTypeConversion: '<S18>/Data Type Conversion1'
  //   DataTypeConversion: '<S29>/Data Type Conversion1'
  //   DataTypeConversion: '<S2>/Data Type Conversion'
  //   DataTypeConversion: '<S2>/Data Type Conversion3'
  //   DataTypeConversion: '<S2>/Data Type Conversion6'
  //   DataTypeConversion: '<S2>/Data Type Conversion7'
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   DataTypeConversion: '<S4>/Data Type Conversion2'
  //   Fcn: '<S26>/x->theta'
  //   Fcn: '<S37>/x->theta'
  //   Gain: '<Root>/Gain'
  //   Gain: '<S2>/Gain'
  //   Gain: '<S2>/Gain1'
  //   Logic: '<S13>/Logical Operator1'
  //   Logic: '<S29>/Logical Operator1'
  //   MATLABSystem: '<Root>/Coordinate Transformation Conversion'
  //   Math: '<S18>/Math Function'
  //   RelationalOperator: '<S22>/Compare'
  //   RelationalOperator: '<S23>/Compare'
  //   RelationalOperator: '<S24>/Compare'
  //   RelationalOperator: '<S25>/Compare'
  //   RelationalOperator: '<S32>/Compare'
  //   RelationalOperator: '<S33>/Compare'
  //   RelationalOperator: '<S34>/Compare'
  //   RelationalOperator: '<S35>/Compare'
  //   S-Function (sdspcount2): '<S18>/Counter'
  //   S-Function (sdspcount2): '<S2>/Counter'
  //   S-Function (sdspcount2): '<S2>/Counter1'
  //   Sum: '<S2>/Sum'

  if (rt_modf_snf(static_cast<real32_T>(RALFMain_DW.Counter_Count_i),
                  RALFMain_P.Constant_Value_p) > RALFMain_P.Switch_Threshold) {
    // ComplexToMagnitudeAngle: '<S16>/Complex to Magnitude-Angle' incorporates:
    //   BusAssignment: '<S2>/Bus Assignment'

    RALFMain_B.Product1_d = rt_atan2f_snf(RALFMain_B.In1_i.Axes[1],
      RALFMain_B.Product2_i);

    // RelationalOperator: '<S28>/Compare' incorporates:
    //   BusAssignment: '<S2>/Bus Assignment'
    //   ComplexToMagnitudeAngle: '<S16>/Complex to Magnitude-Angle'
    //   Constant: '<S28>/Constant'

    rtb_LogicalOperator1_i = (rt_hypotf_snf(RALFMain_B.Product2_i,
      RALFMain_B.In1_i.Axes[1]) >= RALFMain_P.CompareToConstant_const_m);

    // Product: '<S16>/Product2' incorporates:
    //   MagnitudeAngleToComplex: '<S16>/Magnitude-Angle to Complex'

    RALFMain_B.Product2_b = RALFMain_P.MagnitudeAngletoComplex_Constan *
      static_cast<real32_T>(cos(static_cast<real_T>(RALFMain_B.Product1_d))) *
      static_cast<real32_T>(rtb_LogicalOperator1_i);

    // Product: '<S16>/Product1' incorporates:
    //   MagnitudeAngleToComplex: '<S16>/Magnitude-Angle to Complex'

    RALFMain_B.Product1_d = RALFMain_P.MagnitudeAngletoComplex_Constan *
      static_cast<real32_T>(sin(static_cast<real_T>(RALFMain_B.Product1_d))) *
      static_cast<real32_T>(rtb_LogicalOperator1_i);
    RALFMain_B.rtb_Switch_idx_0 = static_cast<real32_T>(RALFMain_P.Gain_Gain *
      static_cast<real_T>(RALFMain_DW.Counter_Count) + RALFMain_P.Gain1_Gain *
      static_cast<real_T>(RALFMain_DW.Counter1_Count));
    RALFMain_B.Product2_i = static_cast<real32_T>(rt_atan2d_snf
      (static_cast<real_T>(RALFMain_B.Product2_b), static_cast<real_T>
       (RALFMain_B.Product1_d)));
    RALFMain_B.rtb_Switch_idx_2 = RALFMain_P.Constant_Value_l;
    RALFMain_B.rtb_Switch_idx_3 = static_cast<real32_T>(rt_atan2d_snf
      ((RALFMain_B.rtb_istquat_idx_2 * RALFMain_B.rtb_istquat_idx_0 +
        RALFMain_B.rtb_Divide_idx_0 * RALFMain_B.rtb_Divide_idx_1) * 2.0,
       ((RALFMain_B.rtb_Divide_idx_0 * RALFMain_B.rtb_Divide_idx_0 -
         RALFMain_B.rtb_Divide_idx_1 * RALFMain_B.rtb_Divide_idx_1) -
        RALFMain_B.rtb_istquat_idx_2 * RALFMain_B.rtb_istquat_idx_2) +
       RALFMain_B.rtb_istquat_idx_0 * RALFMain_B.rtb_istquat_idx_0) *
      RALFMain_P.Gain_Gain_j);
    RALFMain_B.rtb_Switch_idx_4 = ((RALFMain_B.Product1_d >=
      RALFMain_P.CompareToConstant_const_o) || (RALFMain_B.Product1_d <=
      RALFMain_P.CompareToConstant1_const_p) || (RALFMain_B.Product2_b >=
      RALFMain_P.CompareToConstant3_const) || (RALFMain_B.Product2_b <=
      RALFMain_P.CompareToConstant2_const));
  } else {
    RALFMain_B.rtb_Switch_idx_0 = RALFMain_P.Constant_Value_l;
    RALFMain_B.Product2_i = rt_atan2f_snf(RALFMain_P.Constant_Value_gi,
      static_cast<real32_T>(RALFMain_B.In1_m.Linear.X));
    RALFMain_B.rtb_Switch_idx_2 = static_cast<real32_T>
      (RALFMain_B.In1_m.Angular.Z);
    RALFMain_B.rtb_Switch_idx_3 = RALFMain_P.Constant_Value_l;
    RALFMain_B.rtb_Switch_idx_4 = ((static_cast<real32_T>
      (RALFMain_B.In1_m.Linear.X) >= RALFMain_P.CompareToConstant_const_j) || (
      static_cast<real32_T>(RALFMain_B.In1_m.Linear.X) <=
      RALFMain_P.CompareToConstant1_const_l) || (RALFMain_P.Constant_Value_gi >=
      RALFMain_P.CompareToConstant3_const_f) || (RALFMain_P.Constant_Value_gi <=
      RALFMain_P.CompareToConstant2_const_i));
  }

  // End of Switch: '<S3>/Switch'

  // Gain: '<S6>/Gain2' incorporates:
  //   Constant: '<S6>/Constant'
  //   DataTypeConversion: '<S6>/Data Type Conversion'

  RALFMain_B.Gain2_f[0] = RALFMain_P.Gain2_Gain_l * RALFMain_B.rtb_Switch_idx_3;
  RALFMain_B.Product1_d = RALFMain_P.Gain2_Gain_l * static_cast<real32_T>
    (RALFMain_P.Constant_Value_jl);
  RALFMain_B.Gain2_f[1] = RALFMain_B.Product1_d;
  RALFMain_B.Gain2_f[2] = RALFMain_B.Product1_d;
  CoordinateTransformationConvers(RALFMain_B.Gain2_f,
    &RALFMain_B.CoordinateTransformationCo_pnae);

  // Gain: '<S6>/Gain' incorporates:
  //   Constant: '<S6>/Constant'
  //   DataTypeConversion: '<S6>/Data Type Conversion'

  RALFMain_B.Gain_f[0] = RALFMain_P.Gain_Gain_f * RALFMain_B.rtb_Switch_idx_0;
  RALFMain_B.rtb_Switch_idx_0 = RALFMain_P.Gain_Gain_f * static_cast<real32_T>
    (RALFMain_P.Constant_Value_jl);
  RALFMain_B.Gain_f[1] = RALFMain_B.rtb_Switch_idx_0;
  RALFMain_B.Gain_f[2] = RALFMain_B.rtb_Switch_idx_0;
  CoordinateTransformationConvers(RALFMain_B.Gain_f,
    &RALFMain_B.CoordinateTransformationCon_pna);

  // DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
  //   Product: '<S54>/Product'
  //   Product: '<S54>/Product1'
  //   Product: '<S54>/Product2'
  //   Product: '<S54>/Product3'
  //   Product: '<S55>/Product'
  //   Product: '<S55>/Product1'
  //   Product: '<S55>/Product2'
  //   Product: '<S55>/Product3'
  //   Product: '<S56>/Product'
  //   Product: '<S56>/Product1'
  //   Product: '<S56>/Product2'
  //   Product: '<S56>/Product3'
  //   Product: '<S57>/Product'
  //   Product: '<S57>/Product1'
  //   Product: '<S57>/Product2'
  //   Product: '<S57>/Product3'
  //   Sum: '<S54>/Sum'
  //   Sum: '<S55>/Sum'
  //   Sum: '<S56>/Sum'
  //   Sum: '<S57>/Sum'
  //   UnaryMinus: '<S41>/Unary Minus'
  //   UnaryMinus: '<S41>/Unary Minus1'
  //   UnaryMinus: '<S41>/Unary Minus2'

  RALFMain_B.rtb_istquat_idx_0 =
    ((RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[0] *
      RALFMain_B.CoordinateTransformationCon_pna.soll_quat[0] -
      RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[1] *
      -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[1]) -
     RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[2] *
     -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[2]) -
    RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[3] *
    -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[3];
  RALFMain_B.rtb_istquat_idx_1 =
    ((RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[0] *
      -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[1] +
      RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[1] *
      RALFMain_B.CoordinateTransformationCon_pna.soll_quat[0]) +
     RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[2] *
     -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[3]) -
    RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[3] *
    -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[2];
  RALFMain_B.rtb_istquat_idx_2 =
    ((RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[0] *
      -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[2] -
      RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[1] *
      -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[3]) +
     RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[2] *
     RALFMain_B.CoordinateTransformationCon_pna.soll_quat[0]) +
    RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[3] *
    -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[1];
  RALFMain_B.rtb_Divide_idx_0 =
    ((RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[0] *
      -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[3] +
      RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[1] *
      -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[2]) -
     RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[2] *
     -RALFMain_B.CoordinateTransformationCon_pna.soll_quat[1]) +
    RALFMain_B.CoordinateTransformationCo_pnae.soll_quat[3] *
    RALFMain_B.CoordinateTransformationCon_pna.soll_quat[0];

  // Sqrt: '<S64>/sqrt' incorporates:
  //   Product: '<S65>/Product'
  //   Product: '<S65>/Product1'
  //   Product: '<S65>/Product2'
  //   Product: '<S65>/Product3'
  //   Sum: '<S65>/Sum'

  RALFMain_B.rtb_Divide_idx_1 = sqrt(((RALFMain_B.rtb_istquat_idx_0 *
    RALFMain_B.rtb_istquat_idx_0 + RALFMain_B.rtb_istquat_idx_1 *
    RALFMain_B.rtb_istquat_idx_1) + RALFMain_B.rtb_istquat_idx_2 *
    RALFMain_B.rtb_istquat_idx_2) + RALFMain_B.rtb_Divide_idx_0 *
    RALFMain_B.rtb_Divide_idx_0);

  // Product: '<S59>/Product'
  RALFMain_B.rtb_istquat_idx_0 /= RALFMain_B.rtb_Divide_idx_1;

  // Product: '<S59>/Product1'
  RALFMain_B.rtb_istquat_idx_1 /= RALFMain_B.rtb_Divide_idx_1;

  // Product: '<S59>/Product2'
  RALFMain_B.rtb_istquat_idx_2 /= RALFMain_B.rtb_Divide_idx_1;

  // Product: '<S59>/Product3'
  RALFMain_B.rtb_Divide_idx_1 = RALFMain_B.rtb_Divide_idx_0 /
    RALFMain_B.rtb_Divide_idx_1;

  // Gain: '<S6>/Gain3' incorporates:
  //   Fcn: '<S43>/fcn1'
  //   Fcn: '<S43>/fcn2'
  //   Trigonometry: '<S58>/Trigonometric Function1'

  RALFMain_B.rtb_Divide_idx_0 = rt_atan2d_snf((RALFMain_B.rtb_istquat_idx_1 *
    RALFMain_B.rtb_istquat_idx_2 + RALFMain_B.rtb_istquat_idx_0 *
    RALFMain_B.rtb_Divide_idx_1) * 2.0, ((RALFMain_B.rtb_istquat_idx_0 *
    RALFMain_B.rtb_istquat_idx_0 + RALFMain_B.rtb_istquat_idx_1 *
    RALFMain_B.rtb_istquat_idx_1) - RALFMain_B.rtb_istquat_idx_2 *
    RALFMain_B.rtb_istquat_idx_2) - RALFMain_B.rtb_Divide_idx_1 *
    RALFMain_B.rtb_Divide_idx_1) * RALFMain_P.Gain3_Gain;

  // DataTypeConversion: '<S39>/Data Type Conversion' incorporates:
  //   Constant: '<S46>/Constant'
  //   Constant: '<S47>/Constant'
  //   Product: '<S46>/Product1'
  //   RelationalOperator: '<S47>/Compare'
  //   Sum: '<S46>/Sum4'

  RALFMain_B.rtb_Switch_idx_0 = static_cast<real32_T>((static_cast<real_T>
    (rtb_BusAssignment_Axes_idx_2 > RALFMain_P.CompareToConstant_const_l) +
    RALFMain_P.Constant_Value_f) * RALFMain_P.Constant_Value_f);

  // SwitchCase: '<S39>/Switch Case' incorporates:
  //   DataTypeConversion: '<S6>/Data Type Conversion2'
  //   Inport: '<S45>/In1'

  if (RALFMain_B.rtb_Switch_idx_0 < 0.0F) {
    RALFMain_B.Product1_d = static_cast<real32_T>(ceil(static_cast<real_T>
      (RALFMain_B.rtb_Switch_idx_0)));
  } else {
    RALFMain_B.Product1_d = static_cast<real32_T>(floor(static_cast<real_T>
      (RALFMain_B.rtb_Switch_idx_0)));
  }

  if (rtIsNaNF(RALFMain_B.Product1_d) || rtIsInfF(RALFMain_B.Product1_d)) {
    RALFMain_B.Product1_d = 0.0F;
  } else {
    RALFMain_B.Product1_d = static_cast<real32_T>(fmod(static_cast<real_T>
      (RALFMain_B.Product1_d), 4.294967296E+9));
  }

  if ((RALFMain_B.Product1_d < 0.0F ? -static_cast<int32_T>(static_cast<uint32_T>
        (-RALFMain_B.Product1_d)) : static_cast<int32_T>(static_cast<uint32_T>
        (RALFMain_B.Product1_d))) == 1) {
    // Outputs for IfAction SubSystem: '<S39>/If Action Subsystem' incorporates:
    //   ActionPort: '<S45>/Action Port'

    RALFMain_B.In1_e = static_cast<real32_T>(RALFMain_B.rtb_Divide_idx_0);

    // End of Outputs for SubSystem: '<S39>/If Action Subsystem'
  }

  // End of SwitchCase: '<S39>/Switch Case'

  // Sum: '<S6>/Sum9' incorporates:
  //   DataTypeConversion: '<S6>/Data Type Conversion2'

  RALFMain_B.rtb_Switch_idx_0 = static_cast<real32_T>
    (RALFMain_B.rtb_Divide_idx_0) - RALFMain_B.In1_e;

  // Saturate: '<S6>/Saturation'
  if (RALFMain_B.rtb_Switch_idx_0 > RALFMain_P.Saturation_UpperSat) {
    RALFMain_B.rtb_Switch_idx_0 = RALFMain_P.Saturation_UpperSat;
  } else {
    if (RALFMain_B.rtb_Switch_idx_0 < RALFMain_P.Saturation_LowerSat) {
      RALFMain_B.rtb_Switch_idx_0 = RALFMain_P.Saturation_LowerSat;
    }
  }

  // End of Saturate: '<S6>/Saturation'

  // Gain: '<S50>/Gain4'
  RALFMain_B.rtb_Switch_idx_3 = RALFMain_P.pwinkel * RALFMain_B.rtb_Switch_idx_0;

  // Product: '<S50>/Product2' incorporates:
  //   Constant: '<S50>/Constant1'

  RALFMain_B.Product2_m[0] = RALFMain_P.Constant1_Value_d[0] *
    RALFMain_B.rtb_Switch_idx_3;
  RALFMain_B.Product2_m[1] = RALFMain_P.Constant1_Value_d[1] *
    RALFMain_B.rtb_Switch_idx_3;
  RALFMain_B.Product2_m[2] = RALFMain_P.Constant1_Value_d[2] *
    RALFMain_B.rtb_Switch_idx_3;
  RALFMain_B.Product2_m[3] = RALFMain_P.Constant1_Value_d[3] *
    RALFMain_B.rtb_Switch_idx_3;

  // Gain: '<S51>/Gain4'
  RALFMain_B.rtb_Switch_idx_3 = RALFMain_P.pwinkel_vel *
    RALFMain_B.rtb_Switch_idx_2;

  // SignalConversion generated from: '<S49>/Product1' incorporates:
  //   Fcn: '<S53>/r->x'
  //   Fcn: '<S53>/theta->y'

  RALFMain_B.rtb_Switch_idx_0 = static_cast<real32_T>
    (RALFMain_B.rtb_Switch_idx_4) * static_cast<real32_T>(cos(static_cast<real_T>
    (RALFMain_B.Product2_i)));
  RALFMain_B.Product2_i = static_cast<real32_T>(RALFMain_B.rtb_Switch_idx_4) *
    static_cast<real32_T>(sin(static_cast<real_T>(RALFMain_B.Product2_i)));
  for (RALFMain_B.rtb_Switch_idx_4 = 0; RALFMain_B.rtb_Switch_idx_4 < 4;
       RALFMain_B.rtb_Switch_idx_4++) {
    // Product: '<S49>/Product1' incorporates:
    //   Constant: '<S49>/Constant'

    RALFMain_B.Product1_d =
      RALFMain_P.Constant_Value_h[RALFMain_B.rtb_Switch_idx_4 + 4] *
      RALFMain_B.Product2_i +
      RALFMain_P.Constant_Value_h[RALFMain_B.rtb_Switch_idx_4] *
      RALFMain_B.rtb_Switch_idx_0;

    // Saturate: '<S49>/Saturation3'
    if (RALFMain_B.Product1_d > RALFMain_P.Saturation3_UpperSat) {
      RALFMain_B.Product1_d = RALFMain_P.Saturation3_UpperSat;
    } else {
      if (RALFMain_B.Product1_d < RALFMain_P.Saturation3_LowerSat) {
        RALFMain_B.Product1_d = RALFMain_P.Saturation3_LowerSat;
      }
    }

    // Product: '<S40>/Product' incorporates:
    //   Constant: '<S51>/Constant1'
    //   Product: '<S51>/Product2'
    //   Saturate: '<S49>/Saturation3'
    //   Sum: '<S40>/Sum'

    RALFMain_B.Product2_m[RALFMain_B.rtb_Switch_idx_4] = ((RALFMain_B.Product1_d
      + RALFMain_B.Product2_m[RALFMain_B.rtb_Switch_idx_4]) +
      RALFMain_P.Constant1_Value_i[RALFMain_B.rtb_Switch_idx_4] *
      RALFMain_B.rtb_Switch_idx_3) * static_cast<real32_T>
      (RALFMain_B.DataTypeConversion_p) * rtb_BusAssignment_Axes_idx_3;
  }

  // DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
  //   Constant: '<S8>/Constant'
  //   RelationalOperator: '<S8>/Compare'

  RALFMain_B.rtb_Switch_idx_3 = (rtb_BusAssignment_Axes_idx_2 >
    RALFMain_P.CompareToConstant_const_g);

  // DataTypeConversion: '<S1>/Conversion ' incorporates:
  //   Constant: '<S1>/Constant'
  //   Gain: '<S40>/Gain'
  //   Gain: '<S40>/Gain1'
  //   Gain: '<S40>/Gain2'
  //   Gain: '<S40>/Gain3'
  //   Product: '<S1>/Multiply'
  //   Product: '<S1>/Product'

  RALFMain_B.rtb_Divide_idx_0 = floor(static_cast<real_T>(RALFMain_P.nmax) *
    RALFMain_B.Product2_m[0] * RALFMain_B.rtb_Switch_idx_3 *
    RALFMain_P.Constant_Value_b[0]);
  if (rtIsNaN(RALFMain_B.rtb_Divide_idx_0) || rtIsInf
      (RALFMain_B.rtb_Divide_idx_0)) {
    RALFMain_B.rtb_Divide_idx_0 = 0.0;
  } else {
    RALFMain_B.rtb_Divide_idx_0 = fmod(RALFMain_B.rtb_Divide_idx_0, 65536.0);
  }

  RALFMain_B.Conversion[0] = static_cast<int16_T>(RALFMain_B.rtb_Divide_idx_0 <
    0.0 ? static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-RALFMain_B.rtb_Divide_idx_0)))) : static_cast<int32_T>
    (static_cast<int16_T>(static_cast<uint16_T>(RALFMain_B.rtb_Divide_idx_0))));
  RALFMain_B.rtb_Divide_idx_0 = floor(static_cast<real_T>(RALFMain_P.nmax) *
    RALFMain_B.Product2_m[1] * RALFMain_B.rtb_Switch_idx_3 *
    RALFMain_P.Constant_Value_b[1]);
  if (rtIsNaN(RALFMain_B.rtb_Divide_idx_0) || rtIsInf
      (RALFMain_B.rtb_Divide_idx_0)) {
    RALFMain_B.rtb_Divide_idx_0 = 0.0;
  } else {
    RALFMain_B.rtb_Divide_idx_0 = fmod(RALFMain_B.rtb_Divide_idx_0, 65536.0);
  }

  RALFMain_B.Conversion[1] = static_cast<int16_T>(RALFMain_B.rtb_Divide_idx_0 <
    0.0 ? static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-RALFMain_B.rtb_Divide_idx_0)))) : static_cast<int32_T>
    (static_cast<int16_T>(static_cast<uint16_T>(RALFMain_B.rtb_Divide_idx_0))));
  RALFMain_B.rtb_Divide_idx_0 = floor(static_cast<real_T>
    (RALFMain_P.Gain3_Gain_i) * RALFMain_B.Product2_m[3] *
    RALFMain_B.rtb_Switch_idx_3 * RALFMain_P.Constant_Value_b[2]);
  if (rtIsNaN(RALFMain_B.rtb_Divide_idx_0) || rtIsInf
      (RALFMain_B.rtb_Divide_idx_0)) {
    RALFMain_B.rtb_Divide_idx_0 = 0.0;
  } else {
    RALFMain_B.rtb_Divide_idx_0 = fmod(RALFMain_B.rtb_Divide_idx_0, 65536.0);
  }

  RALFMain_B.Conversion[2] = static_cast<int16_T>(RALFMain_B.rtb_Divide_idx_0 <
    0.0 ? static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-RALFMain_B.rtb_Divide_idx_0)))) : static_cast<int32_T>
    (static_cast<int16_T>(static_cast<uint16_T>(RALFMain_B.rtb_Divide_idx_0))));
  RALFMain_B.rtb_Divide_idx_0 = floor(static_cast<real_T>
    (RALFMain_P.Gain2_Gain_d) * RALFMain_B.Product2_m[2] *
    RALFMain_B.rtb_Switch_idx_3 * RALFMain_P.Constant_Value_b[3]);
  if (rtIsNaN(RALFMain_B.rtb_Divide_idx_0) || rtIsInf
      (RALFMain_B.rtb_Divide_idx_0)) {
    RALFMain_B.rtb_Divide_idx_0 = 0.0;
  } else {
    RALFMain_B.rtb_Divide_idx_0 = fmod(RALFMain_B.rtb_Divide_idx_0, 65536.0);
  }

  RALFMain_B.Conversion[3] = static_cast<int16_T>(RALFMain_B.rtb_Divide_idx_0 <
    0.0 ? static_cast<int32_T>(static_cast<int16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-RALFMain_B.rtb_Divide_idx_0)))) : static_cast<int32_T>
    (static_cast<int16_T>(static_cast<uint16_T>(RALFMain_B.rtb_Divide_idx_0))));

  // End of DataTypeConversion: '<S1>/Conversion '

  // S-Function (any2byte): '<S1>/Byte Pack'

  // Pack: <S1>/Byte Pack
  (void) memcpy(&RALFMain_B.BytePack[0], &RALFMain_B.Conversion[0],
                8);

  // S-Function (CAN_send): '<S1>/CAN send back left'

  // Level2 S-Function Block: '<S1>/CAN send back left' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  // S-Function (CAN_send): '<S1>/CAN send back right'

  // Level2 S-Function Block: '<S1>/CAN send back right' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  // S-Function (CAN_send): '<S1>/CAN send front left'

  // Level2 S-Function Block: '<S1>/CAN send front left' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  // S-Function (CAN_send): '<S1>/CAN send front right'

  // Level2 S-Function Block: '<S1>/CAN send front right' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  // DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
  //   Constant: '<Root>/Constant'

  RALFMain_B.rtb_Divide_idx_0 = floor(RALFMain_P.Constant_Value_d);
  if (rtIsNaN(RALFMain_B.rtb_Divide_idx_0) || rtIsInf
      (RALFMain_B.rtb_Divide_idx_0)) {
    RALFMain_B.rtb_Divide_idx_0 = 0.0;
  } else {
    RALFMain_B.rtb_Divide_idx_0 = fmod(RALFMain_B.rtb_Divide_idx_0, 65536.0);
  }

  RALFMain_B.DataTypeConversion = static_cast<int16_T>
    (RALFMain_B.rtb_Divide_idx_0 < 0.0 ? static_cast<int32_T>
     (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-RALFMain_B.rtb_Divide_idx_0)))) : static_cast<int32_T>
     (static_cast<int16_T>(static_cast<uint16_T>(RALFMain_B.rtb_Divide_idx_0))));

  // End of DataTypeConversion: '<Root>/Data Type Conversion'

  // S-Function (any2byte): '<Root>/Byte Pack'

  // Pack: <Root>/Byte Pack
  (void) memcpy(&RALFMain_B.BytePack_k[0], &RALFMain_B.DataTypeConversion,
                2);

  // S-Function (CAN_send): '<Root>/CAN send SYNC'

  // Level2 S-Function Block: '<Root>/CAN send SYNC' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  // S-Function (saeroclockpacer): '<Root>/Simulation Pace'
  //
  //  The Clock Pacer generates no code, it is only active in
  //  interpreted simulation.


  // Update for Delay: '<S19>/Delay' incorporates:
  //   BusAssignment: '<S2>/Bus Assignment'
  //   DataTypeConversion: '<S18>/Data Type Conversion'
  //   DataTypeConversion: '<S19>/Data Type Conversion'

  RALFMain_DW.Delay_DSTATE = (RALFMain_B.In1_i.Buttons[1] != 0.0F);

  // Update for S-Function (CAN_send): '<S1>/CAN send back left'
  // Level2 S-Function Block: '<S1>/CAN send back left' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[0];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  // Update for S-Function (CAN_send): '<S1>/CAN send back right'
  // Level2 S-Function Block: '<S1>/CAN send back right' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[1];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  // Update for S-Function (CAN_send): '<S1>/CAN send front left'
  // Level2 S-Function Block: '<S1>/CAN send front left' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[2];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  // Update for S-Function (CAN_send): '<S1>/CAN send front right'
  // Level2 S-Function Block: '<S1>/CAN send front right' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[3];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  // Update for S-Function (CAN_send): '<Root>/CAN send SYNC'
  // Level2 S-Function Block: '<Root>/CAN send SYNC' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[4];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  RALFMain_M->Timing.t[0] =
    ((time_T)(++RALFMain_M->Timing.clockTick0)) * RALFMain_M->Timing.stepSize0;
}

// Model initialize function
void RALFMain_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtsiSetSolverName(&RALFMain_M->solverInfo,"FixedStepDiscrete");
  RALFMain_M->solverInfoPtr = (&RALFMain_M->solverInfo);

  // Initialize timing info
  {
    int_T *mdlTsMap = RALFMain_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    RALFMain_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    RALFMain_M->Timing.sampleTimes = (&RALFMain_M->Timing.sampleTimesArray[0]);
    RALFMain_M->Timing.offsetTimes = (&RALFMain_M->Timing.offsetTimesArray[0]);

    // task periods
    RALFMain_M->Timing.sampleTimes[0] = (0.01);

    // task offsets
    RALFMain_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(RALFMain_M, &RALFMain_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = RALFMain_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    RALFMain_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(RALFMain_M, -1);
  RALFMain_M->Timing.stepSize0 = 0.01;
  RALFMain_M->solverInfoPtr = (&RALFMain_M->solverInfo);
  RALFMain_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&RALFMain_M->solverInfo, 0.01);
  rtsiSetSolverMode(&RALFMain_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  // block I/O
  (void) memset((static_cast<void *>(&RALFMain_B)), 0,
                sizeof(B_RALFMain_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&RALFMain_DW), 0,
                sizeof(DW_RALFMain_T));

  // child S-Function registration
  {
    RTWSfcnInfo *sfcnInfo = &RALFMain_M->NonInlinedSFcns.sfcnInfo;
    RALFMain_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(RALFMain_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &RALFMain_M->Sizes.numSampTimes);
    RALFMain_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(RALFMain_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,RALFMain_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(RALFMain_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(RALFMain_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(RALFMain_M));
    rtssSetStepSizePtr(sfcnInfo, &RALFMain_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(RALFMain_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &RALFMain_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &RALFMain_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &RALFMain_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &RALFMain_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &RALFMain_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &RALFMain_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &RALFMain_M->solverInfoPtr);
  }

  RALFMain_M->Sizes.numSFcns = (5);

  // register each child
  {
    (void) memset(static_cast<void *>
                  (&RALFMain_M->NonInlinedSFcns.childSFunctions[0]), 0,
                  5*sizeof(SimStruct));
    RALFMain_M->childSfunctions =
      (&RALFMain_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        RALFMain_M->childSfunctions[i] =
          (&RALFMain_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    // Level2 S-Function Block: RALFMain/<S1>/CAN send back left (CAN_send)
    {
      SimStruct *rts = RALFMain_M->childSfunctions[0];

      // timing info
      time_T *sfcnPeriod = RALFMain_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = RALFMain_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = RALFMain_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset(static_cast<void*>(sfcnPeriod), 0,
                    sizeof(time_T)*1);
      (void) memset(static_cast<void*>(sfcnOffset), 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RALFMain_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RALFMain_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, RALFMain_M->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &RALFMain_M->NonInlinedSFcns.methods2[0]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &RALFMain_M->NonInlinedSFcns.methods3[0]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &RALFMain_M->NonInlinedSFcns.methods4[0]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &RALFMain_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &RALFMain_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RALFMain_B.BytePack[4]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      // states
      ssSetDiscStates(rts, (real_T *) &RALFMain_DW.CANsendbackleft_DSTATE);

      // path info
      ssSetModelName(rts, "CAN send back left");
      ssSetPath(rts,
                "RALFMain/Drehzahl Conversion und CAN send/CAN send back left");
      ssSetRTModel(rts,RALFMain_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **)
          &RALFMain_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RALFMain_P.CANsendbackleft_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RALFMain_P.CANsendbackleft_P2_Size);
      }

      // work vectors
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RALFMain_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RALFMain_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        // DSTATE
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWorkUsedAsDState(rts, 0, 1);
        ssSetDWork(rts, 0, &RALFMain_DW.CANsendbackleft_DSTATE);
      }

      // registration
      CAN_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      // adjust sample time
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      // set compiled values of dynamic vector attributes
      ssSetInputPortWidth(rts, 0, 2);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      // Update connectivity flags for each port
      _ssSetInputPortConnected(rts, 0, 1);

      // Update the BufferDstPort flags for each input port
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    // Level2 S-Function Block: RALFMain/<S1>/CAN send back right (CAN_send)
    {
      SimStruct *rts = RALFMain_M->childSfunctions[1];

      // timing info
      time_T *sfcnPeriod = RALFMain_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = RALFMain_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = RALFMain_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset(static_cast<void*>(sfcnPeriod), 0,
                    sizeof(time_T)*1);
      (void) memset(static_cast<void*>(sfcnOffset), 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RALFMain_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RALFMain_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, RALFMain_M->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &RALFMain_M->NonInlinedSFcns.methods2[1]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &RALFMain_M->NonInlinedSFcns.methods3[1]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &RALFMain_M->NonInlinedSFcns.methods4[1]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &RALFMain_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &RALFMain_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RALFMain_B.BytePack[6]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      // states
      ssSetDiscStates(rts, (real_T *) &RALFMain_DW.CANsendbackright_DSTATE);

      // path info
      ssSetModelName(rts, "CAN send back right");
      ssSetPath(rts,
                "RALFMain/Drehzahl Conversion und CAN send/CAN send back right");
      ssSetRTModel(rts,RALFMain_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **)
          &RALFMain_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RALFMain_P.CANsendbackright_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RALFMain_P.CANsendbackright_P2_Size);
      }

      // work vectors
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RALFMain_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RALFMain_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        // DSTATE
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWorkUsedAsDState(rts, 0, 1);
        ssSetDWork(rts, 0, &RALFMain_DW.CANsendbackright_DSTATE);
      }

      // registration
      CAN_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      // adjust sample time
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      // set compiled values of dynamic vector attributes
      ssSetInputPortWidth(rts, 0, 2);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      // Update connectivity flags for each port
      _ssSetInputPortConnected(rts, 0, 1);

      // Update the BufferDstPort flags for each input port
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    // Level2 S-Function Block: RALFMain/<S1>/CAN send front left (CAN_send)
    {
      SimStruct *rts = RALFMain_M->childSfunctions[2];

      // timing info
      time_T *sfcnPeriod = RALFMain_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = RALFMain_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = RALFMain_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset(static_cast<void*>(sfcnPeriod), 0,
                    sizeof(time_T)*1);
      (void) memset(static_cast<void*>(sfcnOffset), 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RALFMain_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RALFMain_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, RALFMain_M->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &RALFMain_M->NonInlinedSFcns.methods2[2]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &RALFMain_M->NonInlinedSFcns.methods3[2]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &RALFMain_M->NonInlinedSFcns.methods4[2]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &RALFMain_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &RALFMain_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RALFMain_B.BytePack[2]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      // states
      ssSetDiscStates(rts, (real_T *) &RALFMain_DW.CANsendfrontleft_DSTATE);

      // path info
      ssSetModelName(rts, "CAN send front left");
      ssSetPath(rts,
                "RALFMain/Drehzahl Conversion und CAN send/CAN send front left");
      ssSetRTModel(rts,RALFMain_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **)
          &RALFMain_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RALFMain_P.CANsendfrontleft_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RALFMain_P.CANsendfrontleft_P2_Size);
      }

      // work vectors
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RALFMain_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RALFMain_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        // DSTATE
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWorkUsedAsDState(rts, 0, 1);
        ssSetDWork(rts, 0, &RALFMain_DW.CANsendfrontleft_DSTATE);
      }

      // registration
      CAN_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      // adjust sample time
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      // set compiled values of dynamic vector attributes
      ssSetInputPortWidth(rts, 0, 2);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      // Update connectivity flags for each port
      _ssSetInputPortConnected(rts, 0, 1);

      // Update the BufferDstPort flags for each input port
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    // Level2 S-Function Block: RALFMain/<S1>/CAN send front right (CAN_send)
    {
      SimStruct *rts = RALFMain_M->childSfunctions[3];

      // timing info
      time_T *sfcnPeriod = RALFMain_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = RALFMain_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = RALFMain_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset(static_cast<void*>(sfcnPeriod), 0,
                    sizeof(time_T)*1);
      (void) memset(static_cast<void*>(sfcnOffset), 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RALFMain_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RALFMain_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, RALFMain_M->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &RALFMain_M->NonInlinedSFcns.methods2[3]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &RALFMain_M->NonInlinedSFcns.methods3[3]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &RALFMain_M->NonInlinedSFcns.methods4[3]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &RALFMain_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &RALFMain_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RALFMain_B.BytePack[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      // states
      ssSetDiscStates(rts, (real_T *) &RALFMain_DW.CANsendfrontright_DSTATE);

      // path info
      ssSetModelName(rts, "CAN send front right");
      ssSetPath(rts,
                "RALFMain/Drehzahl Conversion und CAN send/CAN send front right");
      ssSetRTModel(rts,RALFMain_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **)
          &RALFMain_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RALFMain_P.CANsendfrontright_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RALFMain_P.CANsendfrontright_P2_Size);
      }

      // work vectors
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RALFMain_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RALFMain_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        // DSTATE
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWorkUsedAsDState(rts, 0, 1);
        ssSetDWork(rts, 0, &RALFMain_DW.CANsendfrontright_DSTATE);
      }

      // registration
      CAN_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      // adjust sample time
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      // set compiled values of dynamic vector attributes
      ssSetInputPortWidth(rts, 0, 2);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      // Update connectivity flags for each port
      _ssSetInputPortConnected(rts, 0, 1);

      // Update the BufferDstPort flags for each input port
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    // Level2 S-Function Block: RALFMain/<Root>/CAN send SYNC (CAN_send)
    {
      SimStruct *rts = RALFMain_M->childSfunctions[4];

      // timing info
      time_T *sfcnPeriod = RALFMain_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = RALFMain_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = RALFMain_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset(static_cast<void*>(sfcnPeriod), 0,
                    sizeof(time_T)*1);
      (void) memset(static_cast<void*>(sfcnOffset), 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RALFMain_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RALFMain_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, RALFMain_M->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &RALFMain_M->NonInlinedSFcns.methods2[4]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &RALFMain_M->NonInlinedSFcns.methods3[4]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &RALFMain_M->NonInlinedSFcns.methods4[4]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &RALFMain_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &RALFMain_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn4.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RALFMain_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, RALFMain_B.BytePack_k);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      // states
      ssSetDiscStates(rts, (real_T *) &RALFMain_DW.CANsendSYNC_DSTATE);

      // path info
      ssSetModelName(rts, "CAN send SYNC");
      ssSetPath(rts, "RALFMain/CAN send SYNC");
      ssSetRTModel(rts,RALFMain_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **)
          &RALFMain_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RALFMain_P.CANsendSYNC_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RALFMain_P.CANsendSYNC_P2_Size);
      }

      // work vectors
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RALFMain_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RALFMain_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        // DSTATE
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWorkUsedAsDState(rts, 0, 1);
        ssSetDWork(rts, 0, &RALFMain_DW.CANsendSYNC_DSTATE);
      }

      // registration
      CAN_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      // adjust sample time
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      // set compiled values of dynamic vector attributes
      ssSetInputPortWidth(rts, 0, 2);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      // Update connectivity flags for each port
      _ssSetInputPortConnected(rts, 0, 1);

      // Update the BufferDstPort flags for each input port
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  {
    char_T tmp[5];
    char_T tmp_0[11];
    char_T tmp_1[9];
    int32_T i;
    static const char_T tmp_2[10] = { '/', 'a', 'm', 'c', 'l', '_', 'p', 'o',
      's', 'e' };

    static const char_T tmp_3[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // InitializeConditions for S-Function (sdspcount2): '<S2>/Counter'
    RALFMain_DW.Counter_ClkEphState = 5U;
    RALFMain_DW.Counter_Count = RALFMain_P.Counter_InitialCount;

    // InitializeConditions for S-Function (sdspcount2): '<S2>/Counter1'
    RALFMain_DW.Counter1_ClkEphState = 5U;
    RALFMain_DW.Counter1_Count = RALFMain_P.Counter1_InitialCount;

    // InitializeConditions for Delay: '<S19>/Delay'
    RALFMain_DW.Delay_DSTATE = RALFMain_P.Delay_InitialCondition;

    // InitializeConditions for S-Function (sdspcount2): '<S18>/Counter'
    RALFMain_DW.Counter_ClkEphState_a = 5U;
    RALFMain_DW.Counter_Count_i = RALFMain_P.Counter_InitialCount_n;

    // InitializeConditions for S-Function (CAN_send): '<S1>/CAN send back left' 
    // Level2 S-Function Block: '<S1>/CAN send back left' (CAN_send)
    {
      SimStruct *rts = RALFMain_M->childSfunctions[0];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    // InitializeConditions for S-Function (CAN_send): '<S1>/CAN send back right' 
    // Level2 S-Function Block: '<S1>/CAN send back right' (CAN_send)
    {
      SimStruct *rts = RALFMain_M->childSfunctions[1];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    // InitializeConditions for S-Function (CAN_send): '<S1>/CAN send front left' 
    // Level2 S-Function Block: '<S1>/CAN send front left' (CAN_send)
    {
      SimStruct *rts = RALFMain_M->childSfunctions[2];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    // InitializeConditions for S-Function (CAN_send): '<S1>/CAN send front right' 
    // Level2 S-Function Block: '<S1>/CAN send front right' (CAN_send)
    {
      SimStruct *rts = RALFMain_M->childSfunctions[3];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    // InitializeConditions for S-Function (CAN_send): '<Root>/CAN send SYNC'
    // Level2 S-Function Block: '<Root>/CAN send SYNC' (CAN_send)
    {
      SimStruct *rts = RALFMain_M->childSfunctions[4];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    // SystemInitialize for Atomic SubSystem: '<S2>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S15>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S27>/Out1'
    RALFMain_B.In1_i = RALFMain_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S15>/Enabled Subsystem'

    // Start for MATLABSystem: '<S15>/SourceBlock'
    RALFMain_DW.obj_p.matlabCodegenIsDeleted = false;
    RALFMain_DW.obj_p.isInitialized = 1;
    tmp[0] = '/';
    tmp[1] = 'j';
    tmp[2] = 'o';
    tmp[3] = 'y';
    tmp[4] = '\x00';
    Sub_RALFMain_869.createSubscriber(tmp, 1);
    RALFMain_DW.obj_p.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S2>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S38>/Out1'
    RALFMain_B.In1 = RALFMain_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    RALFMain_DW.obj.matlabCodegenIsDeleted = false;
    RALFMain_DW.obj.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      tmp_0[i] = tmp_2[i];
    }

    tmp_0[10] = '\x00';
    Sub_RALFMain_1223.createSubscriber(tmp_0, 1);
    RALFMain_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<S4>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S30>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S36>/Out1'
    RALFMain_B.In1_m = RALFMain_P.Out1_Y0_j;

    // End of SystemInitialize for SubSystem: '<S30>/Enabled Subsystem'

    // Start for MATLABSystem: '<S30>/SourceBlock'
    RALFMain_DW.obj_d.matlabCodegenIsDeleted = false;
    RALFMain_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_1[i] = tmp_3[i];
    }

    tmp_1[8] = '\x00';
    Sub_RALFMain_963.createSubscriber(tmp_1, 1);
    RALFMain_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S30>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S4>/Subscribe'

    // SystemInitialize for IfAction SubSystem: '<S39>/If Action Subsystem'
    // SystemInitialize for Outport: '<S45>/Out1'
    RALFMain_B.In1_e = RALFMain_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S39>/If Action Subsystem'
    CoordinateTransformationCo_Init(&RALFMain_DW.CoordinateTransformationCo_pnae);
    CoordinateTransformationCo_Init(&RALFMain_DW.CoordinateTransformationCon_pna);
  }
}

// Model terminate function
void RALFMain_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S2>/Subscribe'
  // Terminate for MATLABSystem: '<S15>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&RALFMain_DW.obj_p);

  // End of Terminate for SubSystem: '<S2>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&RALFMain_DW.obj);

  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<S4>/Subscribe'
  // Terminate for MATLABSystem: '<S30>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&RALFMain_DW.obj_d);

  // End of Terminate for SubSystem: '<S4>/Subscribe'

  // Terminate for S-Function (CAN_send): '<S1>/CAN send back left'
  // Level2 S-Function Block: '<S1>/CAN send back left' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  // Terminate for S-Function (CAN_send): '<S1>/CAN send back right'
  // Level2 S-Function Block: '<S1>/CAN send back right' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  // Terminate for S-Function (CAN_send): '<S1>/CAN send front left'
  // Level2 S-Function Block: '<S1>/CAN send front left' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  // Terminate for S-Function (CAN_send): '<S1>/CAN send front right'
  // Level2 S-Function Block: '<S1>/CAN send front right' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  // Terminate for S-Function (CAN_send): '<Root>/CAN send SYNC'
  // Level2 S-Function Block: '<Root>/CAN send SYNC' (CAN_send)
  {
    SimStruct *rts = RALFMain_M->childSfunctions[4];
    sfcnTerminate(rts);
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
