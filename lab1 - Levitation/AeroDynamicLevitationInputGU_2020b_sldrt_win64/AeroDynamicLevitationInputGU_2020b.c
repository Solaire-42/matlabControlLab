/*
 * AeroDynamicLevitationInputGU_2020b.c
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

#include "AeroDynamicLevitationInputGU_2020b.h"
#include "AeroDynamicLevitationInputGU_2020b_private.h"
#include "AeroDynamicLevitationInputGU_2020b_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.002, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCIe-6321", 4294967295U, 7, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_AeroDynamicLevitationInputGU_2020b_T AeroDynamicLevitationInputGU_2020b_B;

/* Block states (default storage) */
DW_AeroDynamicLevitationInputGU_2020b_T AeroDynamicLevitationInputGU_2020b_DW;

/* Real-time model */
static RT_MODEL_AeroDynamicLevitationInputGU_2020b_T
  AeroDynamicLevitationInputGU_2020b_M_;
RT_MODEL_AeroDynamicLevitationInputGU_2020b_T *const
  AeroDynamicLevitationInputGU_2020b_M = &AeroDynamicLevitationInputGU_2020b_M_;

/* Model output function */
void AeroDynamicLevitationInputGU_2020b_output(void)
{
  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Base Voltage'
   *  Constant: '<Root>/Eject Voltage'
   *  Constant: '<Root>/Refinement'
   *  Constant: '<Root>/Step Voltage'
   */
  AeroDynamicLevitationInputGU_2020b_B.voltagefan =
    ((AeroDynamicLevitationInputGU_2020b_P.BaseVoltage_Value +
      AeroDynamicLevitationInputGU_2020b_P.Refinement_Value) +
     AeroDynamicLevitationInputGU_2020b_P.StepVoltage_Value) +
    AeroDynamicLevitationInputGU_2020b_P.EjectVoltage_Value;

  /* S-Function (sldrtao): '<Root>/Analog Output' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_RangeMode;
      parm.rangeidx =
        AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_Channels,
                     ((real_T*)
                      (&AeroDynamicLevitationInputGU_2020b_B.voltagefan)), &parm);
    }
  }

  /* S-Function (sldrtai): '<Root>/Analog Input' */
  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE)
      AeroDynamicLevitationInputGU_2020b_P.AnalogInput_RangeMode;
    parm.rangeidx = AeroDynamicLevitationInputGU_2020b_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &AeroDynamicLevitationInputGU_2020b_P.AnalogInput_Channels,
                   &AeroDynamicLevitationInputGU_2020b_B.voltagesensor, &parm);
    AeroDynamicLevitationInputGU_2020b_B.AnalogInput_o2 = 0;/* Missed Ticks value is always zero */
  }
}

/* Model update function */
void AeroDynamicLevitationInputGU_2020b_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++AeroDynamicLevitationInputGU_2020b_M->Timing.clockTick0)) {
    ++AeroDynamicLevitationInputGU_2020b_M->Timing.clockTickH0;
  }

  AeroDynamicLevitationInputGU_2020b_M->Timing.t[0] =
    AeroDynamicLevitationInputGU_2020b_M->Timing.clockTick0 *
    AeroDynamicLevitationInputGU_2020b_M->Timing.stepSize0 +
    AeroDynamicLevitationInputGU_2020b_M->Timing.clockTickH0 *
    AeroDynamicLevitationInputGU_2020b_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void AeroDynamicLevitationInputGU_2020b_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_RangeMode;
      parm.rangeidx =
        AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_Channels,
                     &AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }
}

/* Model terminate function */
void AeroDynamicLevitationInputGU_2020b_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_RangeMode;
      parm.rangeidx =
        AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_Channels,
                     &AeroDynamicLevitationInputGU_2020b_P.AnalogOutput_FinalValue,
                     &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  AeroDynamicLevitationInputGU_2020b_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  AeroDynamicLevitationInputGU_2020b_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  AeroDynamicLevitationInputGU_2020b_initialize();
}

void MdlTerminate(void)
{
  AeroDynamicLevitationInputGU_2020b_terminate();
}

/* Registration function */
RT_MODEL_AeroDynamicLevitationInputGU_2020b_T
  *AeroDynamicLevitationInputGU_2020b(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)AeroDynamicLevitationInputGU_2020b_M, 0,
                sizeof(RT_MODEL_AeroDynamicLevitationInputGU_2020b_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      AeroDynamicLevitationInputGU_2020b_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    AeroDynamicLevitationInputGU_2020b_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    AeroDynamicLevitationInputGU_2020b_M->Timing.sampleTimes =
      (&AeroDynamicLevitationInputGU_2020b_M->Timing.sampleTimesArray[0]);
    AeroDynamicLevitationInputGU_2020b_M->Timing.offsetTimes =
      (&AeroDynamicLevitationInputGU_2020b_M->Timing.offsetTimesArray[0]);

    /* task periods */
    AeroDynamicLevitationInputGU_2020b_M->Timing.sampleTimes[0] = (0.002);

    /* task offsets */
    AeroDynamicLevitationInputGU_2020b_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(AeroDynamicLevitationInputGU_2020b_M,
             &AeroDynamicLevitationInputGU_2020b_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      AeroDynamicLevitationInputGU_2020b_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    AeroDynamicLevitationInputGU_2020b_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(AeroDynamicLevitationInputGU_2020b_M, -1);
  AeroDynamicLevitationInputGU_2020b_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  AeroDynamicLevitationInputGU_2020b_M->Sizes.checksums[0] = (3656220256U);
  AeroDynamicLevitationInputGU_2020b_M->Sizes.checksums[1] = (2978375880U);
  AeroDynamicLevitationInputGU_2020b_M->Sizes.checksums[2] = (4056045928U);
  AeroDynamicLevitationInputGU_2020b_M->Sizes.checksums[3] = (265390408U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    AeroDynamicLevitationInputGU_2020b_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(AeroDynamicLevitationInputGU_2020b_M->extModeInfo,
      &AeroDynamicLevitationInputGU_2020b_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(AeroDynamicLevitationInputGU_2020b_M->extModeInfo,
                        AeroDynamicLevitationInputGU_2020b_M->Sizes.checksums);
    rteiSetTPtr(AeroDynamicLevitationInputGU_2020b_M->extModeInfo, rtmGetTPtr
                (AeroDynamicLevitationInputGU_2020b_M));
  }

  AeroDynamicLevitationInputGU_2020b_M->solverInfoPtr =
    (&AeroDynamicLevitationInputGU_2020b_M->solverInfo);
  AeroDynamicLevitationInputGU_2020b_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&AeroDynamicLevitationInputGU_2020b_M->solverInfo, 0.002);
  rtsiSetSolverMode(&AeroDynamicLevitationInputGU_2020b_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  AeroDynamicLevitationInputGU_2020b_M->blockIO = ((void *)
    &AeroDynamicLevitationInputGU_2020b_B);
  (void) memset(((void *) &AeroDynamicLevitationInputGU_2020b_B), 0,
                sizeof(B_AeroDynamicLevitationInputGU_2020b_T));

  /* parameters */
  AeroDynamicLevitationInputGU_2020b_M->defaultParam = ((real_T *)
    &AeroDynamicLevitationInputGU_2020b_P);

  /* states (dwork) */
  AeroDynamicLevitationInputGU_2020b_M->dwork = ((void *)
    &AeroDynamicLevitationInputGU_2020b_DW);
  (void) memset((void *)&AeroDynamicLevitationInputGU_2020b_DW, 0,
                sizeof(DW_AeroDynamicLevitationInputGU_2020b_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    AeroDynamicLevitationInputGU_2020b_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  AeroDynamicLevitationInputGU_2020b_M->Sizes.numContStates = (0);/* Number of continuous states */
  AeroDynamicLevitationInputGU_2020b_M->Sizes.numY = (0);/* Number of model outputs */
  AeroDynamicLevitationInputGU_2020b_M->Sizes.numU = (0);/* Number of model inputs */
  AeroDynamicLevitationInputGU_2020b_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  AeroDynamicLevitationInputGU_2020b_M->Sizes.numSampTimes = (1);/* Number of sample times */
  AeroDynamicLevitationInputGU_2020b_M->Sizes.numBlocks = (9);/* Number of blocks */
  AeroDynamicLevitationInputGU_2020b_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  AeroDynamicLevitationInputGU_2020b_M->Sizes.numBlockPrms = (16);/* Sum of parameter "widths" */
  return AeroDynamicLevitationInputGU_2020b_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
