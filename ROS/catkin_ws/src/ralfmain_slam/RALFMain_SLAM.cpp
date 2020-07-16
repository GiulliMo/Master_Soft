//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: RALFMain_SLAM.cpp
//
// Code generated for Simulink model 'RALFMain_SLAM'.
//
// Model version                  : 1.191
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Thu Jul 16 13:44:06 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "RALFMain_SLAM.h"
#include "RALFMain_SLAM_private.h"

// Block signals (default storage)
B_RALFMain_SLAM_T RALFMain_SLAM_B;

// Block states (default storage)
DW_RALFMain_SLAM_T RALFMain_SLAM_DW;

// Real-time model
RT_MODEL_RALFMain_SLAM_T RALFMain_SLAM_M_ = RT_MODEL_RALFMain_SLAM_T();
RT_MODEL_RALFMain_SLAM_T *const RALFMain_SLAM_M = &RALFMain_SLAM_M_;

// Forward declaration for local functions
static uint32_T RALFMain_SLAM_MWDSP_EPH_R_S32(int32_T evt, uint32_T *sta);
static real32_T RALFMain_SLAM_rt_atan2f_snf(real32_T u0, real32_T u1);
static real32_T RALFMain_SLAM_rt_hypotf_snf(real32_T u0, real32_T u1);
static real_T RALFMain_SLAM_rt_atan2d_snf(real_T u0, real_T u1);
static void matlabCodegenHandle_matlabCod_l(ros_slros_internal_block_GetP_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj);
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

//
// System initialize for atomic system:
//    synthesized block
//    synthesized block
//
void CoordinateTransformationCo_Init(DW_CoordinateTransformationCo_T *localDW)
{
  // Start for MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

//
// Output and update for atomic system:
//    synthesized block
//    synthesized block
//
void CoordinateTransformationConvers(const real_T rtu_0[4],
  B_CoordinateTransformationCon_T *localB)
{
  real_T b;
  real_T b_z1_idx_0;
  real_T b_z1_idx_1;
  real_T b_z1_idx_2;
  real_T CoordinateTransformationConve_l;
  real_T CoordinateTransformationConve_0;
  real_T CoordinateTransformationConve_1;

  // MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
  b = 1.0 / sqrt(((rtu_0[0] * rtu_0[0] + rtu_0[1] * rtu_0[1]) + rtu_0[2] *
                  rtu_0[2]) + rtu_0[3] * rtu_0[3]);
  b_z1_idx_0 = rtu_0[0] * b;
  b_z1_idx_1 = rtu_0[1] * b;
  b_z1_idx_2 = rtu_0[2] * b;
  b *= rtu_0[3];
  localB->aSinInput = (b_z1_idx_1 * b - b_z1_idx_0 * b_z1_idx_2) * -2.0;
  localB->b = localB->aSinInput;
  if (localB->aSinInput > 1.0) {
    localB->b = 1.0;
  }

  localB->c = localB->b;
  if (localB->b < -1.0) {
    localB->c = -1.0;
  }

  localB->aSinInput = b_z1_idx_0 * b_z1_idx_0;
  CoordinateTransformationConve_l = b_z1_idx_1 * b_z1_idx_1;
  CoordinateTransformationConve_0 = b_z1_idx_2 * b_z1_idx_2;
  CoordinateTransformationConve_1 = b * b;
  localB->CoordinateTransformationConve_l[0] = rt_atan2d_snf((b_z1_idx_1 *
    b_z1_idx_2 + b_z1_idx_0 * b) * 2.0, ((localB->aSinInput +
    CoordinateTransformationConve_l) - CoordinateTransformationConve_0) -
    CoordinateTransformationConve_1);
  localB->CoordinateTransformationConve_l[1] = asin(localB->c);
  localB->CoordinateTransformationConve_l[2] = rt_atan2d_snf((b_z1_idx_2 * b +
    b_z1_idx_0 * b_z1_idx_1) * 2.0, ((localB->aSinInput -
    CoordinateTransformationConve_l) - CoordinateTransformationConve_0) +
    CoordinateTransformationConve_1);

  // End of MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
}

//
// System initialize for atomic system:
//    synthesized block
//    synthesized block
//
void CoordinateTransformation_n_Init(DW_CoordinateTransformation_f_T *localDW)
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
void CoordinateTransformationConve_p(const real32_T rtu_0[3],
  B_CoordinateTransformationC_c_T *localB)
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

static uint32_T RALFMain_SLAM_MWDSP_EPH_R_S32(int32_T evt, uint32_T *sta)
{
  uint32_T retVal;

  // S-Function (sdspcount2): '<S2>/Counter'
  // Detect rising edge events
  RALFMain_SLAM_B.previousState = *sta;
  retVal = 0U;
  RALFMain_SLAM_B.lastzcevent = 0;
  RALFMain_SLAM_B.newState = 5;
  RALFMain_SLAM_B.newStateR = 5;
  if (evt > 0) {
    RALFMain_SLAM_B.curState = 2;
  } else {
    RALFMain_SLAM_B.curState = (evt >= 0);
  }

  if (*sta == 5U) {
    RALFMain_SLAM_B.newStateR = RALFMain_SLAM_B.curState;
  } else {
    if (static_cast<uint32_T>(RALFMain_SLAM_B.curState) != *sta) {
      if (*sta == 3U) {
        if (static_cast<uint32_T>(RALFMain_SLAM_B.curState) == 1U) {
          RALFMain_SLAM_B.newStateR = 1;
        } else {
          RALFMain_SLAM_B.lastzcevent = 2;
          RALFMain_SLAM_B.previousState = 1U;
        }
      }

      if (RALFMain_SLAM_B.previousState == 4U) {
        if (static_cast<uint32_T>(RALFMain_SLAM_B.curState) == 1U) {
          RALFMain_SLAM_B.newStateR = 1;
        } else {
          RALFMain_SLAM_B.lastzcevent = 3;
          RALFMain_SLAM_B.previousState = 1U;
        }
      }

      if ((RALFMain_SLAM_B.previousState == 1U) && (static_cast<uint32_T>
           (RALFMain_SLAM_B.curState) == 2U)) {
        retVal = 2U;
      }

      if (RALFMain_SLAM_B.previousState == 0U) {
        retVal = 2U;
      }

      if (retVal == static_cast<uint32_T>(RALFMain_SLAM_B.lastzcevent)) {
        retVal = 0U;
      }

      if ((static_cast<uint32_T>(RALFMain_SLAM_B.curState) == 1U) && (retVal ==
           2U)) {
        RALFMain_SLAM_B.newState = 3;
      } else {
        RALFMain_SLAM_B.newState = RALFMain_SLAM_B.curState;
      }
    }
  }

  if (static_cast<uint32_T>(RALFMain_SLAM_B.newStateR) != 5U) {
    *sta = static_cast<uint32_T>(RALFMain_SLAM_B.newStateR);
    retVal = 0U;
  }

  if (static_cast<uint32_T>(RALFMain_SLAM_B.newState) != 5U) {
    *sta = static_cast<uint32_T>(RALFMain_SLAM_B.newState);
  }

  // End of S-Function (sdspcount2): '<S2>/Counter'
  return retVal;
}

static real32_T RALFMain_SLAM_rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      RALFMain_SLAM_B.u0_p = 1;
    } else {
      RALFMain_SLAM_B.u0_p = -1;
    }

    if (u1 > 0.0F) {
      RALFMain_SLAM_B.u1_c = 1;
    } else {
      RALFMain_SLAM_B.u1_c = -1;
    }

    y = static_cast<real32_T>(atan2(static_cast<real_T>(static_cast<real32_T>
      (RALFMain_SLAM_B.u0_p)), static_cast<real_T>(static_cast<real32_T>
      (RALFMain_SLAM_B.u1_c))));
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

static real32_T RALFMain_SLAM_rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  RALFMain_SLAM_B.a = static_cast<real32_T>(fabs(static_cast<real_T>(u0)));
  y = static_cast<real32_T>(fabs(static_cast<real_T>(u1)));
  if (RALFMain_SLAM_B.a < y) {
    RALFMain_SLAM_B.a /= y;
    y *= static_cast<real32_T>(sqrt(static_cast<real_T>(RALFMain_SLAM_B.a *
      RALFMain_SLAM_B.a + 1.0F)));
  } else if (RALFMain_SLAM_B.a > y) {
    y /= RALFMain_SLAM_B.a;
    y = static_cast<real32_T>(sqrt(static_cast<real_T>(y * y + 1.0F))) *
      RALFMain_SLAM_B.a;
  } else {
    if (!rtIsNaNF(y)) {
      y = RALFMain_SLAM_B.a * 1.41421354F;
    }
  }

  return y;
}

static real_T RALFMain_SLAM_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      RALFMain_SLAM_B.u0 = 1;
    } else {
      RALFMain_SLAM_B.u0 = -1;
    }

    if (u1 > 0.0) {
      RALFMain_SLAM_B.u1 = 1;
    } else {
      RALFMain_SLAM_B.u1 = -1;
    }

    y = atan2(static_cast<real_T>(RALFMain_SLAM_B.u0), static_cast<real_T>
              (RALFMain_SLAM_B.u1));
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

static void matlabCodegenHandle_matlabCod_l(ros_slros_internal_block_GetP_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void RALFMain_SLAM_step(void)
{
  // MATLABSystem: '<S3>/Get Parameter'
  ParamGet_RALFMain_SLAM_1266.get_parameter(16U, RALFMain_SLAM_B.charValue,
    &RALFMain_SLAM_B.receivedLength);

  // Outputs for Atomic SubSystem: '<S2>/Subscribe'
  // MATLABSystem: '<S15>/SourceBlock' incorporates:
  //   Inport: '<S27>/In1'

  RALFMain_SLAM_B.LogicalOperator1_c = Sub_RALFMain_SLAM_869.getLatestMessage
    (&RALFMain_SLAM_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S15>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S27>/Enable'

  if (RALFMain_SLAM_B.LogicalOperator1_c) {
    RALFMain_SLAM_B.In1_i = RALFMain_SLAM_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S15>/SourceBlock'
  // End of Outputs for SubSystem: '<S15>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S2>/Subscribe'

  // Product: '<S10>/Divide' incorporates:
  //   Constant: '<S10>/Constant'
  //   Constant: '<S10>/Constant1'
  //   Sum: '<S10>/Add'

  RALFMain_SLAM_B.rtb_Divide_idx_0 = (RALFMain_SLAM_B.In1_i.Axes[2] -
    RALFMain_SLAM_P.Constant_Value_gx) / RALFMain_SLAM_P.Constant1_Value;
  RALFMain_SLAM_B.rtb_Divide_idx_1 = (RALFMain_SLAM_B.In1_i.Axes[5] -
    RALFMain_SLAM_P.Constant_Value_gx) / RALFMain_SLAM_P.Constant1_Value;

  // Gain: '<S10>/Gain'
  RALFMain_SLAM_B.Product2_i = RALFMain_SLAM_P.Gain_Gain_c *
    RALFMain_SLAM_B.In1_i.Axes[0];

  // BusAssignment: '<S2>/Bus Assignment' incorporates:
  //   Constant: '<S17>/Constant'
  //   Product: '<S10>/Product1'
  //   RelationalOperator: '<S17>/Compare'

  RALFMain_SLAM_B.rtb_BusAssignment_Axes_idx_2 = static_cast<real32_T>(
    static_cast<real_T>(RALFMain_SLAM_B.rtb_Divide_idx_0 >=
                        RALFMain_SLAM_P.CompareToConstant1_const) *
    RALFMain_SLAM_B.rtb_Divide_idx_0);
  RALFMain_SLAM_B.rtb_BusAssignment_Axes_idx_3 = static_cast<real32_T>(
    static_cast<real_T>(RALFMain_SLAM_B.rtb_Divide_idx_1 >=
                        RALFMain_SLAM_P.CompareToConstant1_const) *
    RALFMain_SLAM_B.rtb_Divide_idx_1);

  // DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
  //   Constant: '<Root>/Constant'

  RALFMain_SLAM_B.rtb_Divide_idx_0 = floor(RALFMain_SLAM_P.Constant_Value_d);
  if (rtIsNaN(RALFMain_SLAM_B.rtb_Divide_idx_0) || rtIsInf
      (RALFMain_SLAM_B.rtb_Divide_idx_0)) {
    RALFMain_SLAM_B.rtb_Divide_idx_0 = 0.0;
  } else {
    RALFMain_SLAM_B.rtb_Divide_idx_0 = fmod(RALFMain_SLAM_B.rtb_Divide_idx_0,
      65536.0);
  }

  RALFMain_SLAM_B.DataTypeConversion = static_cast<int16_T>
    (RALFMain_SLAM_B.rtb_Divide_idx_0 < 0.0 ? static_cast<int32_T>
     (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-RALFMain_SLAM_B.rtb_Divide_idx_0)))) : static_cast<int32_T>(
      static_cast<int16_T>(static_cast<uint16_T>
       (RALFMain_SLAM_B.rtb_Divide_idx_0))));

  // End of DataTypeConversion: '<Root>/Data Type Conversion'

  // S-Function (any2byte): '<Root>/Byte Pack'

  // Pack: <Root>/Byte Pack
  (void) memcpy(&RALFMain_SLAM_B.BytePack[0],
                &RALFMain_SLAM_B.DataTypeConversion,
                2);

  // S-Function (sdspcount2): '<S2>/Counter' incorporates:
  //   BusAssignment: '<S2>/Bus Assignment'

  if (RALFMain_SLAM_MWDSP_EPH_R_S32(RALFMain_SLAM_B.In1_i.Buttons[4],
       &RALFMain_SLAM_DW.Counter_ClkEphState) != 0U) {
    if (RALFMain_SLAM_DW.Counter_Count < 255) {
      RALFMain_SLAM_DW.Counter_Count = static_cast<uint8_T>
        (RALFMain_SLAM_DW.Counter_Count + 1U);
    } else {
      RALFMain_SLAM_DW.Counter_Count = 0U;
    }
  }

  // S-Function (sdspcount2): '<S2>/Counter1' incorporates:
  //   BusAssignment: '<S2>/Bus Assignment'

  if (RALFMain_SLAM_MWDSP_EPH_R_S32(RALFMain_SLAM_B.In1_i.Buttons[5],
       &RALFMain_SLAM_DW.Counter1_ClkEphState) != 0U) {
    if (RALFMain_SLAM_DW.Counter1_Count < 255) {
      RALFMain_SLAM_DW.Counter1_Count = static_cast<uint8_T>
        (RALFMain_SLAM_DW.Counter1_Count + 1U);
    } else {
      RALFMain_SLAM_DW.Counter1_Count = 0U;
    }
  }

  // DataTypeConversion: '<S53>/Data Type Conversion' incorporates:
  //   Constant: '<S57>/Constant'
  //   RelationalOperator: '<S57>/Compare'

  RALFMain_SLAM_B.DataTypeConversion_p =
    (RALFMain_SLAM_B.rtb_BusAssignment_Axes_idx_2 >
     RALFMain_SLAM_P.CompareToConstant_const);

  // Outputs for Atomic SubSystem: '<S5>/Subscribe1'
  // MATLABSystem: '<S41>/SourceBlock' incorporates:
  //   Inport: '<S43>/In1'

  RALFMain_SLAM_B.LogicalOperator1_c = Sub_RALFMain_SLAM_876.getLatestMessage
    (&RALFMain_SLAM_B.b_varargout_2_k);

  // Outputs for Enabled SubSystem: '<S41>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S43>/Enable'

  if (RALFMain_SLAM_B.LogicalOperator1_c) {
    RALFMain_SLAM_B.In1_ic = RALFMain_SLAM_B.b_varargout_2_k;
  }

  // End of Outputs for SubSystem: '<S41>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S5>/Subscribe1'

  // SignalConversion generated from: '<S5>/Coordinate Transformation Conversion' 
  RALFMain_SLAM_B.istquat[0] = RALFMain_SLAM_B.In1_ic.Pose.Orientation.X;
  RALFMain_SLAM_B.istquat[1] = RALFMain_SLAM_B.In1_ic.Pose.Orientation.Y;
  RALFMain_SLAM_B.istquat[2] = RALFMain_SLAM_B.In1_ic.Pose.Orientation.Z;
  RALFMain_SLAM_B.istquat[3] = RALFMain_SLAM_B.In1_ic.Pose.Orientation.W;
  CoordinateTransformationConvers(RALFMain_SLAM_B.istquat,
    &RALFMain_SLAM_B.CoordinateTransformationCon_pna);

  // Outputs for Atomic SubSystem: '<S5>/Subscribe1'
  // CombinatorialLogic: '<S38>/Logic' incorporates:
  //   MATLABSystem: '<S41>/SourceBlock'
  //   Memory: '<S38>/Memory'

  RALFMain_SLAM_B.rowIdx = static_cast<int32_T>((((static_cast<uint32_T>
    (RALFMain_SLAM_B.LogicalOperator1_c) << 1) + false) << 1) +
    RALFMain_SLAM_DW.Memory_PreviousInput);

  // End of Outputs for SubSystem: '<S5>/Subscribe1'

  // Outputs for Atomic SubSystem: '<S5>/Subscribe'
  // MATLABSystem: '<S40>/SourceBlock' incorporates:
  //   Inport: '<S42>/In1'

  RALFMain_SLAM_B.LogicalOperator1_c = Sub_RALFMain_SLAM_1247.getLatestMessage
    (&RALFMain_SLAM_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S40>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S42>/Enable'

  if (RALFMain_SLAM_B.LogicalOperator1_c) {
    RALFMain_SLAM_B.In1 = RALFMain_SLAM_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S40>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S5>/Subscribe'

  // SignalConversion generated from: '<S5>/Coordinate Transformation Conversion1' 
  RALFMain_SLAM_B.istquat_k[0] = RALFMain_SLAM_B.In1.Pose.Pose.Orientation.X;
  RALFMain_SLAM_B.istquat_k[1] = RALFMain_SLAM_B.In1.Pose.Pose.Orientation.Y;
  RALFMain_SLAM_B.istquat_k[2] = RALFMain_SLAM_B.In1.Pose.Pose.Orientation.Z;
  RALFMain_SLAM_B.istquat_k[3] = RALFMain_SLAM_B.In1.Pose.Pose.Orientation.W;
  CoordinateTransformationConvers(RALFMain_SLAM_B.istquat_k,
    &RALFMain_SLAM_B.CoordinateTransformationConv_pn);

  // Outputs for Atomic SubSystem: '<S5>/Subscribe'
  // CombinatorialLogic: '<S39>/Logic' incorporates:
  //   MATLABSystem: '<S40>/SourceBlock'
  //   Memory: '<S39>/Memory'

  RALFMain_SLAM_B.rowIdx_b = static_cast<int32_T>((((static_cast<uint32_T>
    (RALFMain_SLAM_B.LogicalOperator1_c) << 1) + false) << 1) +
    RALFMain_SLAM_DW.Memory_PreviousInput_h);

  // End of Outputs for SubSystem: '<S5>/Subscribe'

  // ASCIIToString: '<S3>/ASCII to String' incorporates:
  //   MATLABSystem: '<S3>/Get Parameter'

  for (RALFMain_SLAM_B.rtb_Switch_idx_4 = 0; RALFMain_SLAM_B.rtb_Switch_idx_4 <
       16; RALFMain_SLAM_B.rtb_Switch_idx_4++) {
    RALFMain_SLAM_B.rtb_ASCIItoString_c[RALFMain_SLAM_B.rtb_Switch_idx_4] =
      static_cast<int8_T>(static_cast<uint8_T>
                          (RALFMain_SLAM_B.charValue[RALFMain_SLAM_B.rtb_Switch_idx_4]));
  }

  memset(&RALFMain_SLAM_B.rtb_ASCIItoString_c[16], 0, 240U * sizeof(char_T));

  // Outputs for Atomic SubSystem: '<S4>/Subscribe'
  // MATLABSystem: '<S30>/SourceBlock' incorporates:
  //   Inport: '<S36>/In1'

  RALFMain_SLAM_B.LogicalOperator1_c = Sub_RALFMain_SLAM_963.getLatestMessage
    (&RALFMain_SLAM_B.b_varargout_2_c);

  // Outputs for Enabled SubSystem: '<S30>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S36>/Enable'

  if (RALFMain_SLAM_B.LogicalOperator1_c) {
    RALFMain_SLAM_B.In1_m = RALFMain_SLAM_B.b_varargout_2_c;
  }

  // End of MATLABSystem: '<S30>/SourceBlock'
  // End of Outputs for SubSystem: '<S30>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S4>/Subscribe'

  // Switch: '<S3>/Switch' incorporates:
  //   ASCIIToString: '<S3>/ASCII to String'
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
  //   DataTypeConversion: '<S13>/Data Type Conversion1'
  //   DataTypeConversion: '<S29>/Data Type Conversion1'
  //   DataTypeConversion: '<S2>/Data Type Conversion'
  //   DataTypeConversion: '<S2>/Data Type Conversion3'
  //   DataTypeConversion: '<S2>/Data Type Conversion6'
  //   DataTypeConversion: '<S2>/Data Type Conversion7'
  //   DataTypeConversion: '<S3>/Cast'
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   DataTypeConversion: '<S4>/Data Type Conversion2'
  //   Fcn: '<S26>/x->theta'
  //   Fcn: '<S37>/x->theta'
  //   Gain: '<S2>/Gain'
  //   Gain: '<S2>/Gain1'
  //   Logic: '<S13>/Logical Operator1'
  //   Logic: '<S29>/Logical Operator1'
  //   RelationalOperator: '<S22>/Compare'
  //   RelationalOperator: '<S23>/Compare'
  //   RelationalOperator: '<S24>/Compare'
  //   RelationalOperator: '<S25>/Compare'
  //   RelationalOperator: '<S32>/Compare'
  //   RelationalOperator: '<S33>/Compare'
  //   RelationalOperator: '<S34>/Compare'
  //   RelationalOperator: '<S35>/Compare'
  //   S-Function (sdspcount2): '<S2>/Counter'
  //   S-Function (sdspcount2): '<S2>/Counter1'
  //   StringCompare: '<S3>/String Compare'
  //   StringConstant: '<S3>/String Constant'
  //   Sum: '<S2>/Sum'
  //   Sum: '<S5>/Add'

  if (static_cast<real32_T>(strcmp(&RALFMain_SLAM_B.rtb_ASCIItoString_c[0],
        &RALFMain_SLAM_P.StringConstant_String[0]) == 0) >
      RALFMain_SLAM_P.Switch_Threshold_f) {
    // ComplexToMagnitudeAngle: '<S16>/Complex to Magnitude-Angle' incorporates:
    //   BusAssignment: '<S2>/Bus Assignment'

    RALFMain_SLAM_B.Product1_d = RALFMain_SLAM_rt_atan2f_snf
      (RALFMain_SLAM_B.In1_i.Axes[1], RALFMain_SLAM_B.Product2_i);

    // RelationalOperator: '<S28>/Compare' incorporates:
    //   BusAssignment: '<S2>/Bus Assignment'
    //   ComplexToMagnitudeAngle: '<S16>/Complex to Magnitude-Angle'
    //   Constant: '<S28>/Constant'

    RALFMain_SLAM_B.LogicalOperator1_c = (RALFMain_SLAM_rt_hypotf_snf
      (RALFMain_SLAM_B.Product2_i, RALFMain_SLAM_B.In1_i.Axes[1]) >=
      RALFMain_SLAM_P.CompareToConstant_const_m);

    // Product: '<S16>/Product2' incorporates:
    //   MagnitudeAngleToComplex: '<S16>/Magnitude-Angle to Complex'

    RALFMain_SLAM_B.Product2_b = RALFMain_SLAM_P.MagnitudeAngletoComplex_Constan
      * static_cast<real32_T>(cos(static_cast<real_T>(RALFMain_SLAM_B.Product1_d)))
      * static_cast<real32_T>(RALFMain_SLAM_B.LogicalOperator1_c);

    // Product: '<S16>/Product1' incorporates:
    //   MagnitudeAngleToComplex: '<S16>/Magnitude-Angle to Complex'

    RALFMain_SLAM_B.Product1_d = RALFMain_SLAM_P.MagnitudeAngletoComplex_Constan
      * static_cast<real32_T>(sin(static_cast<real_T>(RALFMain_SLAM_B.Product1_d)))
      * static_cast<real32_T>(RALFMain_SLAM_B.LogicalOperator1_c);
    RALFMain_SLAM_B.rtb_Switch_idx_0 = static_cast<real32_T>
      (RALFMain_SLAM_P.Gain_Gain_j * static_cast<real_T>
       (RALFMain_SLAM_DW.Counter_Count) + RALFMain_SLAM_P.Gain1_Gain_k *
       static_cast<real_T>(RALFMain_SLAM_DW.Counter1_Count));
    RALFMain_SLAM_B.Product2_i = static_cast<real32_T>
      (RALFMain_SLAM_rt_atan2d_snf(static_cast<real_T>
        (RALFMain_SLAM_B.Product2_b), static_cast<real_T>
        (RALFMain_SLAM_B.Product1_d)));
    RALFMain_SLAM_B.rtb_Switch_idx_2 = RALFMain_SLAM_P.Constant_Value_la;

    // Switch: '<S5>/Switch' incorporates:
    //   CombinatorialLogic: '<S38>/Logic'
    //   Constant: '<S3>/Constant'
    //   Constant: '<S5>/Constant1'
    //   DataTypeConversion: '<S2>/Data Type Conversion'
    //   DataTypeConversion: '<S2>/Data Type Conversion3'
    //   DataTypeConversion: '<S2>/Data Type Conversion6'
    //   DataTypeConversion: '<S2>/Data Type Conversion7'
    //   DataTypeConversion: '<S5>/Cast2'
    //   DataTypeConversion: '<S5>/Data Type Conversion'
    //   Fcn: '<S26>/x->theta'
    //   Gain: '<S2>/Gain'
    //   Gain: '<S2>/Gain1'
    //   Gain: '<S5>/Gain'
    //   S-Function (sdspcount2): '<S2>/Counter'
    //   S-Function (sdspcount2): '<S2>/Counter1'
    //   Sum: '<S2>/Sum'

    if (static_cast<real32_T>(RALFMain_SLAM_P.Logic_table[static_cast<uint32_T>
         (RALFMain_SLAM_B.rowIdx)]) > RALFMain_SLAM_P.Switch_Threshold) {
      RALFMain_SLAM_B.rtb_Switch_idx_3 = static_cast<real32_T>
        (RALFMain_SLAM_P.Gain_Gain *
         RALFMain_SLAM_B.CoordinateTransformationCon_pna.CoordinateTransformationConve_l
         [2]);
    } else {
      RALFMain_SLAM_B.rtb_Switch_idx_3 = RALFMain_SLAM_P.Constant1_Value_a;
    }

    // End of Switch: '<S5>/Switch'

    // Switch: '<S5>/Switch1' incorporates:
    //   CombinatorialLogic: '<S39>/Logic'
    //   Constant: '<S5>/Constant2'
    //   DataTypeConversion: '<S5>/Cast1'
    //   DataTypeConversion: '<S5>/Data Type Conversion1'
    //   Gain: '<S5>/Gain1'

    if (static_cast<real32_T>(RALFMain_SLAM_P.Logic_table_e[static_cast<uint32_T>
         (RALFMain_SLAM_B.rowIdx_b)]) > RALFMain_SLAM_P.Switch1_Threshold) {
      RALFMain_SLAM_B.f = static_cast<real32_T>(RALFMain_SLAM_P.Gain1_Gain *
        RALFMain_SLAM_B.CoordinateTransformationConv_pn.CoordinateTransformationConve_l
        [2]);
    } else {
      RALFMain_SLAM_B.f = RALFMain_SLAM_P.Constant2_Value_c;
    }

    // End of Switch: '<S5>/Switch1'
    RALFMain_SLAM_B.rtb_Switch_idx_3 += RALFMain_SLAM_B.f;
    RALFMain_SLAM_B.rtb_Switch_idx_4 = ((RALFMain_SLAM_B.Product1_d >=
      RALFMain_SLAM_P.CompareToConstant_const_o) || (RALFMain_SLAM_B.Product1_d <=
      RALFMain_SLAM_P.CompareToConstant1_const_p) || (RALFMain_SLAM_B.Product2_b
      >= RALFMain_SLAM_P.CompareToConstant3_const) ||
      (RALFMain_SLAM_B.Product2_b <= RALFMain_SLAM_P.CompareToConstant2_const));
  } else {
    RALFMain_SLAM_B.rtb_Switch_idx_0 = RALFMain_SLAM_P.Constant_Value_la;
    RALFMain_SLAM_B.Product2_i = RALFMain_SLAM_rt_atan2f_snf
      (RALFMain_SLAM_P.Constant_Value_gi, static_cast<real32_T>
       (RALFMain_SLAM_B.In1_m.Linear.X));
    RALFMain_SLAM_B.rtb_Switch_idx_2 = static_cast<real32_T>
      (RALFMain_SLAM_B.In1_m.Angular.Z);
    RALFMain_SLAM_B.rtb_Switch_idx_3 = RALFMain_SLAM_P.Constant_Value_la;
    RALFMain_SLAM_B.rtb_Switch_idx_4 = ((static_cast<real32_T>
      (RALFMain_SLAM_B.In1_m.Linear.X) >=
      RALFMain_SLAM_P.CompareToConstant_const_j) || (static_cast<real32_T>
      (RALFMain_SLAM_B.In1_m.Linear.X) <=
      RALFMain_SLAM_P.CompareToConstant1_const_l) ||
      (RALFMain_SLAM_P.Constant_Value_gi >=
       RALFMain_SLAM_P.CompareToConstant3_const_f) ||
      (RALFMain_SLAM_P.Constant_Value_gi <=
       RALFMain_SLAM_P.CompareToConstant2_const_i));
  }

  // End of Switch: '<S3>/Switch'

  // Gain: '<S6>/Gain2' incorporates:
  //   Constant: '<S6>/Constant'
  //   DataTypeConversion: '<S6>/Data Type Conversion'

  RALFMain_SLAM_B.Gain2_f[0] = RALFMain_SLAM_P.Gain2_Gain_l *
    RALFMain_SLAM_B.rtb_Switch_idx_3;
  RALFMain_SLAM_B.Product1_d = RALFMain_SLAM_P.Gain2_Gain_l *
    static_cast<real32_T>(RALFMain_SLAM_P.Constant_Value_jl);
  RALFMain_SLAM_B.Gain2_f[1] = RALFMain_SLAM_B.Product1_d;
  RALFMain_SLAM_B.Gain2_f[2] = RALFMain_SLAM_B.Product1_d;
  CoordinateTransformationConve_p(RALFMain_SLAM_B.Gain2_f,
    &RALFMain_SLAM_B.CoordinateTransformation_pnaevv);

  // Gain: '<S6>/Gain' incorporates:
  //   Constant: '<S6>/Constant'
  //   DataTypeConversion: '<S6>/Data Type Conversion'

  RALFMain_SLAM_B.Gain_f[0] = RALFMain_SLAM_P.Gain_Gain_f *
    RALFMain_SLAM_B.rtb_Switch_idx_0;
  RALFMain_SLAM_B.rtb_Switch_idx_0 = RALFMain_SLAM_P.Gain_Gain_f *
    static_cast<real32_T>(RALFMain_SLAM_P.Constant_Value_jl);
  RALFMain_SLAM_B.Gain_f[1] = RALFMain_SLAM_B.rtb_Switch_idx_0;
  RALFMain_SLAM_B.Gain_f[2] = RALFMain_SLAM_B.rtb_Switch_idx_0;
  CoordinateTransformationConve_p(RALFMain_SLAM_B.Gain_f,
    &RALFMain_SLAM_B.CoordinateTransformationC_pnaev);

  // DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
  //   Product: '<S59>/Product'
  //   Product: '<S59>/Product1'
  //   Product: '<S59>/Product2'
  //   Product: '<S59>/Product3'
  //   Product: '<S60>/Product'
  //   Product: '<S60>/Product1'
  //   Product: '<S60>/Product2'
  //   Product: '<S60>/Product3'
  //   Product: '<S61>/Product'
  //   Product: '<S61>/Product1'
  //   Product: '<S61>/Product2'
  //   Product: '<S61>/Product3'
  //   Product: '<S62>/Product'
  //   Product: '<S62>/Product1'
  //   Product: '<S62>/Product2'
  //   Product: '<S62>/Product3'
  //   Sum: '<S59>/Sum'
  //   Sum: '<S60>/Sum'
  //   Sum: '<S61>/Sum'
  //   Sum: '<S62>/Sum'
  //   UnaryMinus: '<S46>/Unary Minus'
  //   UnaryMinus: '<S46>/Unary Minus1'
  //   UnaryMinus: '<S46>/Unary Minus2'

  RALFMain_SLAM_B.rtb_Multiply_idx_0 =
    ((RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[0] *
      RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[0] -
      RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[1] *
      -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[1]) -
     RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[2] *
     -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[2]) -
    RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[3] *
    -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[3];
  RALFMain_SLAM_B.rtb_Multiply_idx_1 =
    ((RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[0] *
      -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[1] +
      RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[1] *
      RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[0]) +
     RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[2] *
     -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[3]) -
    RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[3] *
    -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[2];
  RALFMain_SLAM_B.rtb_Multiply_idx_2 =
    ((RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[0] *
      -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[2] -
      RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[1] *
      -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[3]) +
     RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[2] *
     RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[0]) +
    RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[3] *
    -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[1];
  RALFMain_SLAM_B.rtb_Divide_idx_0 =
    ((RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[0] *
      -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[3] +
      RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[1] *
      -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[2]) -
     RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[2] *
     -RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[1]) +
    RALFMain_SLAM_B.CoordinateTransformation_pnaevv.soll_quat[3] *
    RALFMain_SLAM_B.CoordinateTransformationC_pnaev.soll_quat[0];

  // Sqrt: '<S69>/sqrt' incorporates:
  //   Product: '<S70>/Product'
  //   Product: '<S70>/Product1'
  //   Product: '<S70>/Product2'
  //   Product: '<S70>/Product3'
  //   Sum: '<S70>/Sum'

  RALFMain_SLAM_B.rtb_Divide_idx_1 = sqrt(((RALFMain_SLAM_B.rtb_Multiply_idx_0 *
    RALFMain_SLAM_B.rtb_Multiply_idx_0 + RALFMain_SLAM_B.rtb_Multiply_idx_1 *
    RALFMain_SLAM_B.rtb_Multiply_idx_1) + RALFMain_SLAM_B.rtb_Multiply_idx_2 *
    RALFMain_SLAM_B.rtb_Multiply_idx_2) + RALFMain_SLAM_B.rtb_Divide_idx_0 *
    RALFMain_SLAM_B.rtb_Divide_idx_0);

  // Product: '<S64>/Product'
  RALFMain_SLAM_B.rtb_Multiply_idx_0 /= RALFMain_SLAM_B.rtb_Divide_idx_1;

  // Product: '<S64>/Product1'
  RALFMain_SLAM_B.rtb_Multiply_idx_1 /= RALFMain_SLAM_B.rtb_Divide_idx_1;

  // Product: '<S64>/Product2'
  RALFMain_SLAM_B.rtb_Multiply_idx_2 /= RALFMain_SLAM_B.rtb_Divide_idx_1;

  // Product: '<S64>/Product3'
  RALFMain_SLAM_B.rtb_Divide_idx_1 = RALFMain_SLAM_B.rtb_Divide_idx_0 /
    RALFMain_SLAM_B.rtb_Divide_idx_1;

  // Gain: '<S6>/Gain3' incorporates:
  //   Fcn: '<S48>/fcn1'
  //   Fcn: '<S48>/fcn2'
  //   Trigonometry: '<S63>/Trigonometric Function1'

  RALFMain_SLAM_B.rtb_Divide_idx_0 = RALFMain_SLAM_rt_atan2d_snf
    ((RALFMain_SLAM_B.rtb_Multiply_idx_1 * RALFMain_SLAM_B.rtb_Multiply_idx_2 +
      RALFMain_SLAM_B.rtb_Multiply_idx_0 * RALFMain_SLAM_B.rtb_Divide_idx_1) *
     2.0, ((RALFMain_SLAM_B.rtb_Multiply_idx_0 *
            RALFMain_SLAM_B.rtb_Multiply_idx_0 +
            RALFMain_SLAM_B.rtb_Multiply_idx_1 *
            RALFMain_SLAM_B.rtb_Multiply_idx_1) -
           RALFMain_SLAM_B.rtb_Multiply_idx_2 *
           RALFMain_SLAM_B.rtb_Multiply_idx_2) -
     RALFMain_SLAM_B.rtb_Divide_idx_1 * RALFMain_SLAM_B.rtb_Divide_idx_1) *
    RALFMain_SLAM_P.Gain3_Gain;

  // DataTypeConversion: '<S44>/Data Type Conversion' incorporates:
  //   Constant: '<S51>/Constant'
  //   Constant: '<S52>/Constant'
  //   Product: '<S51>/Product1'
  //   RelationalOperator: '<S52>/Compare'
  //   Sum: '<S51>/Sum4'

  RALFMain_SLAM_B.rtb_Switch_idx_0 = static_cast<real32_T>((static_cast<real_T>
    (RALFMain_SLAM_B.rtb_BusAssignment_Axes_idx_2 >
     RALFMain_SLAM_P.CompareToConstant_const_l) +
    RALFMain_SLAM_P.Constant_Value_f) * RALFMain_SLAM_P.Constant_Value_f);

  // SwitchCase: '<S44>/Switch Case' incorporates:
  //   DataTypeConversion: '<S6>/Data Type Conversion2'
  //   Inport: '<S50>/In1'

  if (RALFMain_SLAM_B.rtb_Switch_idx_0 < 0.0F) {
    RALFMain_SLAM_B.rtb_Switch_idx_3 = static_cast<real32_T>(ceil
      (static_cast<real_T>(RALFMain_SLAM_B.rtb_Switch_idx_0)));
  } else {
    RALFMain_SLAM_B.rtb_Switch_idx_3 = static_cast<real32_T>(floor
      (static_cast<real_T>(RALFMain_SLAM_B.rtb_Switch_idx_0)));
  }

  if (rtIsNaNF(RALFMain_SLAM_B.rtb_Switch_idx_3) || rtIsInfF
      (RALFMain_SLAM_B.rtb_Switch_idx_3)) {
    RALFMain_SLAM_B.rtb_Switch_idx_3 = 0.0F;
  } else {
    RALFMain_SLAM_B.rtb_Switch_idx_3 = static_cast<real32_T>(fmod
      (static_cast<real_T>(RALFMain_SLAM_B.rtb_Switch_idx_3), 4.294967296E+9));
  }

  if ((RALFMain_SLAM_B.rtb_Switch_idx_3 < 0.0F ? -static_cast<int32_T>(
        static_cast<uint32_T>(-RALFMain_SLAM_B.rtb_Switch_idx_3)) : static_cast<
       int32_T>(static_cast<uint32_T>(RALFMain_SLAM_B.rtb_Switch_idx_3))) == 1)
  {
    // Outputs for IfAction SubSystem: '<S44>/If Action Subsystem' incorporates:
    //   ActionPort: '<S50>/Action Port'

    RALFMain_SLAM_B.In1_e = static_cast<real32_T>
      (RALFMain_SLAM_B.rtb_Divide_idx_0);

    // End of Outputs for SubSystem: '<S44>/If Action Subsystem'
  }

  // End of SwitchCase: '<S44>/Switch Case'

  // Sum: '<S6>/Sum9' incorporates:
  //   DataTypeConversion: '<S6>/Data Type Conversion2'

  RALFMain_SLAM_B.rtb_Switch_idx_0 = static_cast<real32_T>
    (RALFMain_SLAM_B.rtb_Divide_idx_0) - RALFMain_SLAM_B.In1_e;

  // Saturate: '<S6>/Saturation'
  if (RALFMain_SLAM_B.rtb_Switch_idx_0 > RALFMain_SLAM_P.Saturation_UpperSat) {
    RALFMain_SLAM_B.rtb_Switch_idx_0 = RALFMain_SLAM_P.Saturation_UpperSat;
  } else {
    if (RALFMain_SLAM_B.rtb_Switch_idx_0 < RALFMain_SLAM_P.Saturation_LowerSat)
    {
      RALFMain_SLAM_B.rtb_Switch_idx_0 = RALFMain_SLAM_P.Saturation_LowerSat;
    }
  }

  // End of Saturate: '<S6>/Saturation'

  // Gain: '<S55>/Gain4'
  RALFMain_SLAM_B.Product1_d = RALFMain_SLAM_P.pwinkel *
    RALFMain_SLAM_B.rtb_Switch_idx_0;

  // Product: '<S55>/Product2' incorporates:
  //   Constant: '<S55>/Constant1'

  RALFMain_SLAM_B.Product2_m[0] = RALFMain_SLAM_P.Constant1_Value_d[0] *
    RALFMain_SLAM_B.Product1_d;
  RALFMain_SLAM_B.Product2_m[1] = RALFMain_SLAM_P.Constant1_Value_d[1] *
    RALFMain_SLAM_B.Product1_d;
  RALFMain_SLAM_B.Product2_m[2] = RALFMain_SLAM_P.Constant1_Value_d[2] *
    RALFMain_SLAM_B.Product1_d;
  RALFMain_SLAM_B.Product2_m[3] = RALFMain_SLAM_P.Constant1_Value_d[3] *
    RALFMain_SLAM_B.Product1_d;

  // Gain: '<S56>/Gain4'
  RALFMain_SLAM_B.Product1_d = RALFMain_SLAM_P.pwinkel_vel *
    RALFMain_SLAM_B.rtb_Switch_idx_2;

  // SignalConversion generated from: '<S54>/Product1' incorporates:
  //   Fcn: '<S58>/r->x'
  //   Fcn: '<S58>/theta->y'

  RALFMain_SLAM_B.rtb_Switch_idx_0 = static_cast<real32_T>
    (RALFMain_SLAM_B.rtb_Switch_idx_4) * static_cast<real32_T>(cos
    (static_cast<real_T>(RALFMain_SLAM_B.Product2_i)));
  RALFMain_SLAM_B.Product2_i = static_cast<real32_T>
    (RALFMain_SLAM_B.rtb_Switch_idx_4) * static_cast<real32_T>(sin
    (static_cast<real_T>(RALFMain_SLAM_B.Product2_i)));
  for (RALFMain_SLAM_B.rtb_Switch_idx_4 = 0; RALFMain_SLAM_B.rtb_Switch_idx_4 <
       4; RALFMain_SLAM_B.rtb_Switch_idx_4++) {
    // Product: '<S54>/Product1' incorporates:
    //   Constant: '<S54>/Constant'

    RALFMain_SLAM_B.rtb_Switch_idx_3 =
      RALFMain_SLAM_P.Constant_Value_h[RALFMain_SLAM_B.rtb_Switch_idx_4 + 4] *
      RALFMain_SLAM_B.Product2_i +
      RALFMain_SLAM_P.Constant_Value_h[RALFMain_SLAM_B.rtb_Switch_idx_4] *
      RALFMain_SLAM_B.rtb_Switch_idx_0;

    // Saturate: '<S54>/Saturation3'
    if (RALFMain_SLAM_B.rtb_Switch_idx_3 > RALFMain_SLAM_P.Saturation3_UpperSat)
    {
      RALFMain_SLAM_B.rtb_Switch_idx_3 = RALFMain_SLAM_P.Saturation3_UpperSat;
    } else {
      if (RALFMain_SLAM_B.rtb_Switch_idx_3 <
          RALFMain_SLAM_P.Saturation3_LowerSat) {
        RALFMain_SLAM_B.rtb_Switch_idx_3 = RALFMain_SLAM_P.Saturation3_LowerSat;
      }
    }

    // Product: '<S45>/Product' incorporates:
    //   Constant: '<S56>/Constant1'
    //   Product: '<S56>/Product2'
    //   Saturate: '<S54>/Saturation3'
    //   Sum: '<S45>/Sum'

    RALFMain_SLAM_B.Product2_m[RALFMain_SLAM_B.rtb_Switch_idx_4] =
      ((RALFMain_SLAM_B.rtb_Switch_idx_3 +
        RALFMain_SLAM_B.Product2_m[RALFMain_SLAM_B.rtb_Switch_idx_4]) +
       RALFMain_SLAM_P.Constant1_Value_i[RALFMain_SLAM_B.rtb_Switch_idx_4] *
       RALFMain_SLAM_B.Product1_d) * static_cast<real32_T>
      (RALFMain_SLAM_B.DataTypeConversion_p) *
      RALFMain_SLAM_B.rtb_BusAssignment_Axes_idx_3;
  }

  // DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
  //   Constant: '<S8>/Constant'
  //   RelationalOperator: '<S8>/Compare'

  RALFMain_SLAM_B.Product1_d = (RALFMain_SLAM_B.rtb_BusAssignment_Axes_idx_2 >
    RALFMain_SLAM_P.CompareToConstant_const_g);

  // DataTypeConversion: '<S1>/Conversion ' incorporates:
  //   Constant: '<S1>/Constant'
  //   Gain: '<S45>/Gain'
  //   Gain: '<S45>/Gain1'
  //   Gain: '<S45>/Gain2'
  //   Gain: '<S45>/Gain3'
  //   Product: '<S1>/Multiply'
  //   Product: '<S1>/Product'

  RALFMain_SLAM_B.rtb_Divide_idx_0 = floor(static_cast<real_T>
    (RALFMain_SLAM_P.nmax) * RALFMain_SLAM_B.Product2_m[0] *
    RALFMain_SLAM_B.Product1_d * RALFMain_SLAM_P.Constant_Value_b[0]);
  if (rtIsNaN(RALFMain_SLAM_B.rtb_Divide_idx_0) || rtIsInf
      (RALFMain_SLAM_B.rtb_Divide_idx_0)) {
    RALFMain_SLAM_B.rtb_Divide_idx_0 = 0.0;
  } else {
    RALFMain_SLAM_B.rtb_Divide_idx_0 = fmod(RALFMain_SLAM_B.rtb_Divide_idx_0,
      65536.0);
  }

  RALFMain_SLAM_B.Conversion[0] = static_cast<int16_T>
    (RALFMain_SLAM_B.rtb_Divide_idx_0 < 0.0 ? static_cast<int32_T>
     (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-RALFMain_SLAM_B.rtb_Divide_idx_0)))) : static_cast<int32_T>(
      static_cast<int16_T>(static_cast<uint16_T>
       (RALFMain_SLAM_B.rtb_Divide_idx_0))));
  RALFMain_SLAM_B.rtb_Divide_idx_0 = floor(static_cast<real_T>
    (RALFMain_SLAM_P.nmax) * RALFMain_SLAM_B.Product2_m[1] *
    RALFMain_SLAM_B.Product1_d * RALFMain_SLAM_P.Constant_Value_b[1]);
  if (rtIsNaN(RALFMain_SLAM_B.rtb_Divide_idx_0) || rtIsInf
      (RALFMain_SLAM_B.rtb_Divide_idx_0)) {
    RALFMain_SLAM_B.rtb_Divide_idx_0 = 0.0;
  } else {
    RALFMain_SLAM_B.rtb_Divide_idx_0 = fmod(RALFMain_SLAM_B.rtb_Divide_idx_0,
      65536.0);
  }

  RALFMain_SLAM_B.Conversion[1] = static_cast<int16_T>
    (RALFMain_SLAM_B.rtb_Divide_idx_0 < 0.0 ? static_cast<int32_T>
     (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-RALFMain_SLAM_B.rtb_Divide_idx_0)))) : static_cast<int32_T>(
      static_cast<int16_T>(static_cast<uint16_T>
       (RALFMain_SLAM_B.rtb_Divide_idx_0))));
  RALFMain_SLAM_B.rtb_Divide_idx_0 = floor(static_cast<real_T>
    (RALFMain_SLAM_P.Gain3_Gain_i) * RALFMain_SLAM_B.Product2_m[3] *
    RALFMain_SLAM_B.Product1_d * RALFMain_SLAM_P.Constant_Value_b[2]);
  if (rtIsNaN(RALFMain_SLAM_B.rtb_Divide_idx_0) || rtIsInf
      (RALFMain_SLAM_B.rtb_Divide_idx_0)) {
    RALFMain_SLAM_B.rtb_Divide_idx_0 = 0.0;
  } else {
    RALFMain_SLAM_B.rtb_Divide_idx_0 = fmod(RALFMain_SLAM_B.rtb_Divide_idx_0,
      65536.0);
  }

  RALFMain_SLAM_B.Conversion[2] = static_cast<int16_T>
    (RALFMain_SLAM_B.rtb_Divide_idx_0 < 0.0 ? static_cast<int32_T>
     (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-RALFMain_SLAM_B.rtb_Divide_idx_0)))) : static_cast<int32_T>(
      static_cast<int16_T>(static_cast<uint16_T>
       (RALFMain_SLAM_B.rtb_Divide_idx_0))));
  RALFMain_SLAM_B.rtb_Divide_idx_0 = floor(static_cast<real_T>
    (RALFMain_SLAM_P.Gain2_Gain_d) * RALFMain_SLAM_B.Product2_m[2] *
    RALFMain_SLAM_B.Product1_d * RALFMain_SLAM_P.Constant_Value_b[3]);
  if (rtIsNaN(RALFMain_SLAM_B.rtb_Divide_idx_0) || rtIsInf
      (RALFMain_SLAM_B.rtb_Divide_idx_0)) {
    RALFMain_SLAM_B.rtb_Divide_idx_0 = 0.0;
  } else {
    RALFMain_SLAM_B.rtb_Divide_idx_0 = fmod(RALFMain_SLAM_B.rtb_Divide_idx_0,
      65536.0);
  }

  RALFMain_SLAM_B.Conversion[3] = static_cast<int16_T>
    (RALFMain_SLAM_B.rtb_Divide_idx_0 < 0.0 ? static_cast<int32_T>
     (static_cast<int16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-RALFMain_SLAM_B.rtb_Divide_idx_0)))) : static_cast<int32_T>(
      static_cast<int16_T>(static_cast<uint16_T>
       (RALFMain_SLAM_B.rtb_Divide_idx_0))));

  // End of DataTypeConversion: '<S1>/Conversion '

  // S-Function (any2byte): '<S1>/Byte Pack'

  // Pack: <S1>/Byte Pack
  (void) memcpy(&RALFMain_SLAM_B.BytePack_e[0], &RALFMain_SLAM_B.Conversion[0],
                8);

  // S-Function (CAN_send): '<S1>/CAN send back left'

  // Level2 S-Function Block: '<S1>/CAN send back left' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  // S-Function (CAN_send): '<S1>/CAN send back right'

  // Level2 S-Function Block: '<S1>/CAN send back right' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  // S-Function (CAN_send): '<S1>/CAN send front left'

  // Level2 S-Function Block: '<S1>/CAN send front left' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  // S-Function (CAN_send): '<S1>/CAN send front right'

  // Level2 S-Function Block: '<S1>/CAN send front right' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  // S-Function (saeroclockpacer): '<Root>/Simulation Pace'
  //
  //  The Clock Pacer generates no code, it is only active in
  //  interpreted simulation.


  // Update for Memory: '<S38>/Memory' incorporates:
  //   CombinatorialLogic: '<S38>/Logic'

  RALFMain_SLAM_DW.Memory_PreviousInput = RALFMain_SLAM_P.Logic_table[
    static_cast<uint32_T>(RALFMain_SLAM_B.rowIdx)];

  // Update for Memory: '<S39>/Memory' incorporates:
  //   CombinatorialLogic: '<S39>/Logic'

  RALFMain_SLAM_DW.Memory_PreviousInput_h = RALFMain_SLAM_P.Logic_table_e[
    static_cast<uint32_T>(RALFMain_SLAM_B.rowIdx_b)];

  // Update for S-Function (CAN_send): '<S1>/CAN send back left'
  // Level2 S-Function Block: '<S1>/CAN send back left' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[0];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  // Update for S-Function (CAN_send): '<S1>/CAN send back right'
  // Level2 S-Function Block: '<S1>/CAN send back right' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[1];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  // Update for S-Function (CAN_send): '<S1>/CAN send front left'
  // Level2 S-Function Block: '<S1>/CAN send front left' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[2];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  // Update for S-Function (CAN_send): '<S1>/CAN send front right'
  // Level2 S-Function Block: '<S1>/CAN send front right' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[3];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  RALFMain_SLAM_M->Timing.t[0] =
    ((time_T)(++RALFMain_SLAM_M->Timing.clockTick0)) *
    RALFMain_SLAM_M->Timing.stepSize0;
}

// Model initialize function
void RALFMain_SLAM_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtsiSetSolverName(&RALFMain_SLAM_M->solverInfo,"FixedStepDiscrete");
  RALFMain_SLAM_M->solverInfoPtr = (&RALFMain_SLAM_M->solverInfo);

  // Initialize timing info
  {
    int_T *mdlTsMap = RALFMain_SLAM_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    RALFMain_SLAM_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    RALFMain_SLAM_M->Timing.sampleTimes =
      (&RALFMain_SLAM_M->Timing.sampleTimesArray[0]);
    RALFMain_SLAM_M->Timing.offsetTimes =
      (&RALFMain_SLAM_M->Timing.offsetTimesArray[0]);

    // task periods
    RALFMain_SLAM_M->Timing.sampleTimes[0] = (0.01);

    // task offsets
    RALFMain_SLAM_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(RALFMain_SLAM_M, &RALFMain_SLAM_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = RALFMain_SLAM_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    RALFMain_SLAM_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(RALFMain_SLAM_M, -1);
  RALFMain_SLAM_M->Timing.stepSize0 = 0.01;
  RALFMain_SLAM_M->solverInfoPtr = (&RALFMain_SLAM_M->solverInfo);
  RALFMain_SLAM_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&RALFMain_SLAM_M->solverInfo, 0.01);
  rtsiSetSolverMode(&RALFMain_SLAM_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  // block I/O
  (void) memset((static_cast<void *>(&RALFMain_SLAM_B)), 0,
                sizeof(B_RALFMain_SLAM_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&RALFMain_SLAM_DW), 0,
                sizeof(DW_RALFMain_SLAM_T));

  // child S-Function registration
  {
    RTWSfcnInfo *sfcnInfo = &RALFMain_SLAM_M->NonInlinedSFcns.sfcnInfo;
    RALFMain_SLAM_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(RALFMain_SLAM_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &RALFMain_SLAM_M->Sizes.numSampTimes);
    RALFMain_SLAM_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (RALFMain_SLAM_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,RALFMain_SLAM_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(RALFMain_SLAM_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(RALFMain_SLAM_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(RALFMain_SLAM_M));
    rtssSetStepSizePtr(sfcnInfo, &RALFMain_SLAM_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(RALFMain_SLAM_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &RALFMain_SLAM_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &RALFMain_SLAM_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &RALFMain_SLAM_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &RALFMain_SLAM_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &RALFMain_SLAM_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &RALFMain_SLAM_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &RALFMain_SLAM_M->solverInfoPtr);
  }

  RALFMain_SLAM_M->Sizes.numSFcns = (4);

  // register each child
  {
    (void) memset(static_cast<void *>
                  (&RALFMain_SLAM_M->NonInlinedSFcns.childSFunctions[0]), 0,
                  4*sizeof(SimStruct));
    RALFMain_SLAM_M->childSfunctions =
      (&RALFMain_SLAM_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    RALFMain_SLAM_M->childSfunctions[0] =
      (&RALFMain_SLAM_M->NonInlinedSFcns.childSFunctions[0]);
    RALFMain_SLAM_M->childSfunctions[1] =
      (&RALFMain_SLAM_M->NonInlinedSFcns.childSFunctions[1]);
    RALFMain_SLAM_M->childSfunctions[2] =
      (&RALFMain_SLAM_M->NonInlinedSFcns.childSFunctions[2]);
    RALFMain_SLAM_M->childSfunctions[3] =
      (&RALFMain_SLAM_M->NonInlinedSFcns.childSFunctions[3]);

    // Level2 S-Function Block: RALFMain_SLAM/<S1>/CAN send back left (CAN_send) 
    {
      SimStruct *rts = RALFMain_SLAM_M->childSfunctions[0];

      // timing info
      time_T *sfcnPeriod = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset(static_cast<void*>(sfcnPeriod), 0,
                    sizeof(time_T)*1);
      (void) memset(static_cast<void*>(sfcnOffset), 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RALFMain_SLAM_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RALFMain_SLAM_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, RALFMain_SLAM_M->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods2[0]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods3[0]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods4[0]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &RALFMain_SLAM_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RALFMain_SLAM_B.BytePack_e[4]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      // states
      ssSetDiscStates(rts, (real_T *) &RALFMain_SLAM_DW.CANsendbackleft_DSTATE);

      // path info
      ssSetModelName(rts, "CAN send back left");
      ssSetPath(rts,
                "RALFMain_SLAM/Drehzahl Conversion und CAN send/CAN send back left");
      ssSetRTModel(rts,RALFMain_SLAM_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RALFMain_SLAM_P.CANsendbackleft_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RALFMain_SLAM_P.CANsendbackleft_P2_Size);
      }

      // work vectors
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        // DSTATE
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWorkUsedAsDState(rts, 0, 1);
        ssSetDWork(rts, 0, &RALFMain_SLAM_DW.CANsendbackleft_DSTATE);
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

    // Level2 S-Function Block: RALFMain_SLAM/<S1>/CAN send back right (CAN_send) 
    {
      SimStruct *rts = RALFMain_SLAM_M->childSfunctions[1];

      // timing info
      time_T *sfcnPeriod = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset(static_cast<void*>(sfcnPeriod), 0,
                    sizeof(time_T)*1);
      (void) memset(static_cast<void*>(sfcnOffset), 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RALFMain_SLAM_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RALFMain_SLAM_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, RALFMain_SLAM_M->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods2[1]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods3[1]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods4[1]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &RALFMain_SLAM_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RALFMain_SLAM_B.BytePack_e[6]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      // states
      ssSetDiscStates(rts, (real_T *) &RALFMain_SLAM_DW.CANsendbackright_DSTATE);

      // path info
      ssSetModelName(rts, "CAN send back right");
      ssSetPath(rts,
                "RALFMain_SLAM/Drehzahl Conversion und CAN send/CAN send back right");
      ssSetRTModel(rts,RALFMain_SLAM_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       RALFMain_SLAM_P.CANsendbackright_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       RALFMain_SLAM_P.CANsendbackright_P2_Size);
      }

      // work vectors
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        // DSTATE
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWorkUsedAsDState(rts, 0, 1);
        ssSetDWork(rts, 0, &RALFMain_SLAM_DW.CANsendbackright_DSTATE);
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

    // Level2 S-Function Block: RALFMain_SLAM/<S1>/CAN send front left (CAN_send) 
    {
      SimStruct *rts = RALFMain_SLAM_M->childSfunctions[2];

      // timing info
      time_T *sfcnPeriod = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset(static_cast<void*>(sfcnPeriod), 0,
                    sizeof(time_T)*1);
      (void) memset(static_cast<void*>(sfcnOffset), 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RALFMain_SLAM_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RALFMain_SLAM_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, RALFMain_SLAM_M->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods2[2]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods3[2]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods4[2]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &RALFMain_SLAM_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RALFMain_SLAM_B.BytePack_e[2]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      // states
      ssSetDiscStates(rts, (real_T *) &RALFMain_SLAM_DW.CANsendfrontleft_DSTATE);

      // path info
      ssSetModelName(rts, "CAN send front left");
      ssSetPath(rts,
                "RALFMain_SLAM/Drehzahl Conversion und CAN send/CAN send front left");
      ssSetRTModel(rts,RALFMain_SLAM_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       RALFMain_SLAM_P.CANsendfrontleft_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       RALFMain_SLAM_P.CANsendfrontleft_P2_Size);
      }

      // work vectors
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        // DSTATE
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWorkUsedAsDState(rts, 0, 1);
        ssSetDWork(rts, 0, &RALFMain_SLAM_DW.CANsendfrontleft_DSTATE);
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

    // Level2 S-Function Block: RALFMain_SLAM/<S1>/CAN send front right (CAN_send) 
    {
      SimStruct *rts = RALFMain_SLAM_M->childSfunctions[3];

      // timing info
      time_T *sfcnPeriod = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = RALFMain_SLAM_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset(static_cast<void*>(sfcnPeriod), 0,
                    sizeof(time_T)*1);
      (void) memset(static_cast<void*>(sfcnOffset), 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RALFMain_SLAM_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RALFMain_SLAM_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, RALFMain_SLAM_M->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods2[3]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods3[3]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &RALFMain_SLAM_M->NonInlinedSFcns.methods4[3]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &RALFMain_SLAM_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RALFMain_SLAM_B.BytePack_e[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      // states
      ssSetDiscStates(rts, (real_T *) &RALFMain_SLAM_DW.CANsendfrontright_DSTATE);

      // path info
      ssSetModelName(rts, "CAN send front right");
      ssSetPath(rts,
                "RALFMain_SLAM/Drehzahl Conversion und CAN send/CAN send front right");
      ssSetRTModel(rts,RALFMain_SLAM_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       RALFMain_SLAM_P.CANsendfrontright_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       RALFMain_SLAM_P.CANsendfrontright_P2_Size);
      }

      // work vectors
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RALFMain_SLAM_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        // DSTATE
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWorkUsedAsDState(rts, 0, 1);
        ssSetDWork(rts, 0, &RALFMain_SLAM_DW.CANsendfrontright_DSTATE);
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
    char_T initialValue;
    char_T tmp[5];
    char_T tmp_0[11];
    char_T tmp_1[9];
    char_T tmp_2[6];
    int32_T i;
    static const char_T tmp_3[14] = { '/', 's', 'l', 'a', 'm', '_', 'o', 'u',
      't', '_', 'p', 'o', 's', 'e' };

    static const char_T tmp_4[10] = { '/', 'a', 'm', 'c', 'l', '_', 'p', 'o',
      's', 'e' };

    static const char_T tmp_5[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_6[5] = { '/', 'm', 'o', 'd', 'e' };

    // InitializeConditions for S-Function (sdspcount2): '<S2>/Counter'
    RALFMain_SLAM_DW.Counter_ClkEphState = 5U;
    RALFMain_SLAM_DW.Counter_Count = RALFMain_SLAM_P.Counter_InitialCount;

    // InitializeConditions for S-Function (sdspcount2): '<S2>/Counter1'
    RALFMain_SLAM_DW.Counter1_ClkEphState = 5U;
    RALFMain_SLAM_DW.Counter1_Count = RALFMain_SLAM_P.Counter1_InitialCount;

    // InitializeConditions for Memory: '<S38>/Memory'
    RALFMain_SLAM_DW.Memory_PreviousInput =
      RALFMain_SLAM_P.SRFlipFlop_initial_condition;

    // InitializeConditions for Memory: '<S39>/Memory'
    RALFMain_SLAM_DW.Memory_PreviousInput_h =
      RALFMain_SLAM_P.SRFlipFlop1_initial_condition;

    // InitializeConditions for S-Function (CAN_send): '<S1>/CAN send back left' 
    // Level2 S-Function Block: '<S1>/CAN send back left' (CAN_send)
    {
      SimStruct *rts = RALFMain_SLAM_M->childSfunctions[0];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    // InitializeConditions for S-Function (CAN_send): '<S1>/CAN send back right' 
    // Level2 S-Function Block: '<S1>/CAN send back right' (CAN_send)
    {
      SimStruct *rts = RALFMain_SLAM_M->childSfunctions[1];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    // InitializeConditions for S-Function (CAN_send): '<S1>/CAN send front left' 
    // Level2 S-Function Block: '<S1>/CAN send front left' (CAN_send)
    {
      SimStruct *rts = RALFMain_SLAM_M->childSfunctions[2];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    // InitializeConditions for S-Function (CAN_send): '<S1>/CAN send front right' 
    // Level2 S-Function Block: '<S1>/CAN send front right' (CAN_send)
    {
      SimStruct *rts = RALFMain_SLAM_M->childSfunctions[3];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    // SystemInitialize for Atomic SubSystem: '<S2>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S15>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S27>/Out1'
    RALFMain_SLAM_B.In1_i = RALFMain_SLAM_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S15>/Enabled Subsystem'

    // Start for MATLABSystem: '<S15>/SourceBlock'
    RALFMain_SLAM_DW.obj_p.matlabCodegenIsDeleted = false;
    RALFMain_SLAM_DW.obj_p.isInitialized = 1;
    tmp[0] = '/';
    tmp[1] = 'j';
    tmp[2] = 'o';
    tmp[3] = 'y';
    tmp[4] = '\x00';
    Sub_RALFMain_SLAM_869.createSubscriber(tmp, 1);
    RALFMain_SLAM_DW.obj_p.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S2>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<S5>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S41>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S43>/Out1'
    RALFMain_SLAM_B.In1_ic = RALFMain_SLAM_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S41>/Enabled Subsystem'

    // Start for MATLABSystem: '<S41>/SourceBlock'
    RALFMain_SLAM_DW.obj_d.matlabCodegenIsDeleted = false;
    RALFMain_SLAM_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      RALFMain_SLAM_B.cv[i] = tmp_3[i];
    }

    RALFMain_SLAM_B.cv[14] = '\x00';
    Sub_RALFMain_SLAM_876.createSubscriber(RALFMain_SLAM_B.cv, 1);
    RALFMain_SLAM_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S41>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S5>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<S5>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S40>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S42>/Out1'
    RALFMain_SLAM_B.In1 = RALFMain_SLAM_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S40>/Enabled Subsystem'

    // Start for MATLABSystem: '<S40>/SourceBlock'
    RALFMain_SLAM_DW.obj_k.matlabCodegenIsDeleted = false;
    RALFMain_SLAM_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      tmp_0[i] = tmp_4[i];
    }

    tmp_0[10] = '\x00';
    Sub_RALFMain_SLAM_1247.createSubscriber(tmp_0, 1);
    RALFMain_SLAM_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S40>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S5>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<S4>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S30>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S36>/Out1'
    RALFMain_SLAM_B.In1_m = RALFMain_SLAM_P.Out1_Y0_j;

    // End of SystemInitialize for SubSystem: '<S30>/Enabled Subsystem'

    // Start for MATLABSystem: '<S30>/SourceBlock'
    RALFMain_SLAM_DW.obj_d2.matlabCodegenIsDeleted = false;
    RALFMain_SLAM_DW.obj_d2.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_1[i] = tmp_5[i];
    }

    tmp_1[8] = '\x00';
    Sub_RALFMain_SLAM_963.createSubscriber(tmp_1, 1);
    RALFMain_SLAM_DW.obj_d2.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S30>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S4>/Subscribe'

    // SystemInitialize for IfAction SubSystem: '<S44>/If Action Subsystem'
    // SystemInitialize for Outport: '<S50>/Out1'
    RALFMain_SLAM_B.In1_e = RALFMain_SLAM_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S44>/If Action Subsystem'

    // Start for MATLABSystem: '<S3>/Get Parameter'
    RALFMain_SLAM_DW.obj.matlabCodegenIsDeleted = false;
    RALFMain_SLAM_DW.obj.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      tmp_2[i] = tmp_6[i];
    }

    tmp_2[5] = '\x00';
    ParamGet_RALFMain_SLAM_1266.initialize(tmp_2);
    ParamGet_RALFMain_SLAM_1266.initialize_error_codes(0, 1, 2, 3);
    initialValue = '\x00';
    ParamGet_RALFMain_SLAM_1266.set_initial_value(&initialValue, 1U);
    RALFMain_SLAM_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Get Parameter'
    CoordinateTransformationCo_Init
      (&RALFMain_SLAM_DW.CoordinateTransformationCon_pna);
    CoordinateTransformationCo_Init
      (&RALFMain_SLAM_DW.CoordinateTransformationConv_pn);
    CoordinateTransformation_n_Init
      (&RALFMain_SLAM_DW.CoordinateTransformation_pnaevv);
    CoordinateTransformation_n_Init
      (&RALFMain_SLAM_DW.CoordinateTransformationC_pnaev);
  }
}

// Model terminate function
void RALFMain_SLAM_terminate(void)
{
  // Terminate for MATLABSystem: '<S3>/Get Parameter'
  matlabCodegenHandle_matlabCod_l(&RALFMain_SLAM_DW.obj);

  // Terminate for Atomic SubSystem: '<S2>/Subscribe'
  // Terminate for MATLABSystem: '<S15>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&RALFMain_SLAM_DW.obj_p);

  // End of Terminate for SubSystem: '<S2>/Subscribe'

  // Terminate for Atomic SubSystem: '<S5>/Subscribe1'
  // Terminate for MATLABSystem: '<S41>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&RALFMain_SLAM_DW.obj_d);

  // End of Terminate for SubSystem: '<S5>/Subscribe1'

  // Terminate for Atomic SubSystem: '<S5>/Subscribe'
  // Terminate for MATLABSystem: '<S40>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&RALFMain_SLAM_DW.obj_k);

  // End of Terminate for SubSystem: '<S5>/Subscribe'

  // Terminate for Atomic SubSystem: '<S4>/Subscribe'
  // Terminate for MATLABSystem: '<S30>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&RALFMain_SLAM_DW.obj_d2);

  // End of Terminate for SubSystem: '<S4>/Subscribe'

  // Terminate for S-Function (CAN_send): '<S1>/CAN send back left'
  // Level2 S-Function Block: '<S1>/CAN send back left' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  // Terminate for S-Function (CAN_send): '<S1>/CAN send back right'
  // Level2 S-Function Block: '<S1>/CAN send back right' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  // Terminate for S-Function (CAN_send): '<S1>/CAN send front left'
  // Level2 S-Function Block: '<S1>/CAN send front left' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  // Terminate for S-Function (CAN_send): '<S1>/CAN send front right'
  // Level2 S-Function Block: '<S1>/CAN send front right' (CAN_send)
  {
    SimStruct *rts = RALFMain_SLAM_M->childSfunctions[3];
    sfcnTerminate(rts);
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
