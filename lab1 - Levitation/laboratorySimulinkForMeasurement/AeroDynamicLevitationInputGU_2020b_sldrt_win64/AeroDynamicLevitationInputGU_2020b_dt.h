/*
 * AeroDynamicLevitationInputGU_2020b_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "AeroDynamicLevitationInputGU_2020b".
 *
 * Model version              : 6.3
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Sat Jan 13 10:23:10 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&AeroDynamicLevitationInputGU_2020b_B.voltagefan), 0, 0, 2 },

  { (char_T *)(&AeroDynamicLevitationInputGU_2020b_B.AnalogInput_o2), 6, 0, 1 }
  ,

  { (char_T *)(&AeroDynamicLevitationInputGU_2020b_DW.AnalogOutput_PWORK), 11, 0,
    4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  3U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_FinalValue), 0,
    0, 6 },

  { (char_T *)(&AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_Channels), 6,
    0, 6 },

  { (char_T *)(&AeroDynamicLevitationInputGU_2020b_P.BaseVoltage_Value), 0, 0, 4
  }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] AeroDynamicLevitationInputGU_2020b_dt.h */
