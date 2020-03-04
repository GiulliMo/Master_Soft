/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sdf_target_data.c
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

/* Block parameters (default storage) */
P_sdf_target_T sdf_target_P = {
  /* Expression: 9.81
   * Referenced by: '<Root>/ToAccel'
   */
  9.81,

  /* Expression: pi/180
   * Referenced by: '<Root>/degToRad'
   */
  0.017453292519943295,

  /* Expression: 0.01
   * Referenced by: '<Root>/Samplezeit'
   */
  0.01,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain5'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain6'
   */
  -1.0,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain3'
   */
  57.295779513082323
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
