/*
 * Code generation for system model 'asbCubeSatACS'
 *
 * Model                      : asbCubeSatACS
 * Model version              : 1.189
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Apr  1 18:06:23 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "asbCubeSatACS.h"
#include "asbCubeSatACS_private.h"
#include "rt_atan2d_snf.h"

/* Named constants for Chart: '<S1>/Pointing Mode Selection' */
#define asbCubeSatACS_IN_Earth         ((uint8_T)1U)
#define asbCubeSatACS_IN_Off           ((uint8_T)1U)
#define asbCubeSatACS_IN_On            ((uint8_T)2U)
#define asbCubeSatACS_IN_Sun           ((uint8_T)2U)
#define asbCubeSatACS_IN_Transition    ((uint8_T)3U)
#define asbCubeSatAC_IN_NO_ACTIVE_CHILD ((uint8_T)0U)

const StatesOutBus asbCubeSatACS_rtZStatesOutBus = {
  {
    0.0, 0.0, 0.0 }
  ,                                    /* V_ecef */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* X_ecef */

  {
    0.0, 0.0, 0.0, 0.0 }
  ,                                    /* q_ecef2b */

  {
    0.0, 0.0, 0.0, 0.0 }
  ,                                    /* q_eci2b */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* Euler */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* LatLonAlt */

  {
    0.0, 0.0, 0.0 }
  /* x_sun_eci */
} ;                                    /* StatesOutBus ground */

const EnvBus asbCubeSatACS_rtZEnvBus = {
  {
    0.0, 0.0, 0.0 }
  ,                                    /* envForces_body */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* envTorques_body */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* x_sun_eci */
  0.0                                  /* earthAngRate */
} ;                                    /* EnvBus ground */

/*
 * Output and update for action system:
 *    '<S67>/If Action Subsystem2'
 *    '<S166>/If Action Subsystem2'
 */
void asbCubeSatAC_IfActionSubsystem2(real_T rtu_In, real_T *rty_OutOrig)
{
  /* Inport: '<S70>/In' */
  *rty_OutOrig = rtu_In;
}

/*
 * Output and update for action system:
 *    '<S77>/If Action Subsystem'
 *    '<S78>/If Action Subsystem'
 *    '<S111>/If Action Subsystem'
 *    '<S126>/If Action Subsystem'
 */
void asbCubeSatACS_IfActionSubsystem(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S88>/Out1' incorporates:
   *  Constant: '<S88>/Constant'
   */
  *rty_Out1 = 1.0;
}

/*
 * Output and update for action system:
 *    '<S77>/If Action Subsystem1'
 *    '<S78>/If Action Subsystem1'
 *    '<S111>/If Action Subsystem1'
 *    '<S126>/If Action Subsystem1'
 */
void asbCubeSatAC_IfActionSubsystem1(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S89>/Out1' incorporates:
   *  Constant: '<S89>/Constant'
   */
  *rty_Out1 = -1.0;
}

/*
 * Output and update for action system:
 *    '<S77>/If Action Subsystem2'
 *    '<S78>/If Action Subsystem2'
 *    '<S111>/If Action Subsystem2'
 *    '<S126>/If Action Subsystem2'
 */
void asbCubeSat_IfActionSubsystem2_j(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S90>/Out1' incorporates:
   *  Constant: '<S90>/Constant'
   */
  *rty_Out1 = 0.0;
}

/* System initialize for referenced model: 'asbCubeSatACS' */
void asbCubeSatACS_Init(ACSOutBus *rty_ACSOut, B_asbCubeSatACS_c_T *localB,
  DW_asbCubeSatACS_f_T *localDW)
{
  /* SystemInitialize for Chart: '<S1>/Pointing Mode Selection' */
  localDW->is_On = asbCubeSatAC_IN_NO_ACTIVE_CHILD;
  localDW->is_active_c1_asbCubeSatACS = 0U;
  localDW->is_c1_asbCubeSatACS = asbCubeSatAC_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for DiscreteIntegrator: '<S201>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0;

  /* InitializeConditions for Delay: '<S196>/UD' */
  localDW->UD_DSTATE[0] = 0.0;

  /* SystemInitialize for Chart: '<S1>/Pointing Mode Selection' */
  localB->PointingCmd[0] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S201>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0;

  /* InitializeConditions for Delay: '<S196>/UD' */
  localDW->UD_DSTATE[1] = 0.0;

  /* SystemInitialize for Chart: '<S1>/Pointing Mode Selection' */
  localB->PointingCmd[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S201>/Integrator' */
  localDW->Integrator_DSTATE[2] = 0.0;

  /* InitializeConditions for Delay: '<S196>/UD' */
  localDW->UD_DSTATE[2] = 0.0;

  /* SystemInitialize for Chart: '<S1>/Pointing Mode Selection' */
  localB->PointingCmd[2] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/On.Earth' */
  /* SystemInitialize for Merge: '<S13>/Merge' incorporates:
   *  Chart: '<S1>/Pointing Mode Selection'
   */
  localB->Merge_e[0] = 1.0;
  localB->Merge_e[1] = 0.0;
  localB->Merge_e[2] = 0.0;
  localB->Merge_e[3] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S3>/On.Earth' */

  /* SystemInitialize for BusCreator generated from: '<Root>/Bus Creator' */
  rty_ACSOut->AttitudeError.Roll = localB->PointingCmd[0];
  rty_ACSOut->AttitudeError.Pitch = localB->PointingCmd[1];
  rty_ACSOut->AttitudeError.Yaw = localB->PointingCmd[2];
}

/* System reset for referenced model: 'asbCubeSatACS' */
void asbCubeSatACS_Reset(B_asbCubeSatACS_c_T *localB, DW_asbCubeSatACS_f_T
  *localDW)
{
  /* SystemReset for Chart: '<S1>/Pointing Mode Selection' */
  localDW->is_On = asbCubeSatAC_IN_NO_ACTIVE_CHILD;
  localDW->is_active_c1_asbCubeSatACS = 0U;
  localDW->is_c1_asbCubeSatACS = asbCubeSatAC_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for DiscreteIntegrator: '<S201>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0;

  /* InitializeConditions for Delay: '<S196>/UD' */
  localDW->UD_DSTATE[0] = 0.0;

  /* SystemReset for Chart: '<S1>/Pointing Mode Selection' */
  localB->PointingCmd[0] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S201>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0;

  /* InitializeConditions for Delay: '<S196>/UD' */
  localDW->UD_DSTATE[1] = 0.0;

  /* SystemReset for Chart: '<S1>/Pointing Mode Selection' */
  localB->PointingCmd[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S201>/Integrator' */
  localDW->Integrator_DSTATE[2] = 0.0;

  /* InitializeConditions for Delay: '<S196>/UD' */
  localDW->UD_DSTATE[2] = 0.0;

  /* SystemReset for Chart: '<S1>/Pointing Mode Selection' */
  localB->PointingCmd[2] = 0.0;
}

/* Outputs for referenced model: 'asbCubeSatACS' */
void asbCubeSatACS(const real_T rtu_SensorsOut_V_ecef[3], const real_T
                   rtu_SensorsOut_X_ecef[3], const real_T
                   rtu_SensorsOut_q_ecef2b[4], const real_T
                   rtu_SensorsOut_q_eci2b[4], const real_T rtu_SensorsOut_Euler
                   [3], const real_T rtu_SensorsOut_LatLonAlt[3], const real_T
                   rtu_SensorsOut_x_sun_eci[3], const real_T *rtu_AttitudeMode,
                   const real_T rtu_Environment_envForces_body[3], const real_T
                   rtu_Environment_envTorques_body[3], const real_T
                   rtu_Environment_x_sun_eci[3], const real_T
                   *rtu_Environment_earthAngRate, ACSOutBus *rty_ACSOut,
                   B_asbCubeSatACS_c_T *localB, DW_asbCubeSatACS_f_T *localDW)
{
  real_T uTmp;
  real_T uTmp_0;
  int32_T i;
  real_T tmp;
  real_T tmp_0;
  real_T uTmp_idx_2;
  real_T tmp_1;
  real_T uTmp_idx_1;
  real_T tmp_2;
  real_T uTmp_idx_0;

  /* BusCreator generated from: '<S1>/Pointing Mode Selection' */
  localB->BusConversion_InsertedFor_Point.V_ecef[0] = rtu_SensorsOut_V_ecef[0];
  localB->BusConversion_InsertedFor_Point.X_ecef[0] = rtu_SensorsOut_X_ecef[0];
  localB->BusConversion_InsertedFor_Point.V_ecef[1] = rtu_SensorsOut_V_ecef[1];
  localB->BusConversion_InsertedFor_Point.X_ecef[1] = rtu_SensorsOut_X_ecef[1];
  localB->BusConversion_InsertedFor_Point.V_ecef[2] = rtu_SensorsOut_V_ecef[2];
  localB->BusConversion_InsertedFor_Point.X_ecef[2] = rtu_SensorsOut_X_ecef[2];
  localB->BusConversion_InsertedFor_Point.q_ecef2b[0] = rtu_SensorsOut_q_ecef2b
    [0];
  localB->BusConversion_InsertedFor_Point.q_eci2b[0] = rtu_SensorsOut_q_eci2b[0];
  localB->BusConversion_InsertedFor_Point.q_ecef2b[1] = rtu_SensorsOut_q_ecef2b
    [1];
  localB->BusConversion_InsertedFor_Point.q_eci2b[1] = rtu_SensorsOut_q_eci2b[1];
  localB->BusConversion_InsertedFor_Point.q_ecef2b[2] = rtu_SensorsOut_q_ecef2b
    [2];
  localB->BusConversion_InsertedFor_Point.q_eci2b[2] = rtu_SensorsOut_q_eci2b[2];
  localB->BusConversion_InsertedFor_Point.q_ecef2b[3] = rtu_SensorsOut_q_ecef2b
    [3];
  localB->BusConversion_InsertedFor_Point.q_eci2b[3] = rtu_SensorsOut_q_eci2b[3];
  localB->BusConversion_InsertedFor_Point.Euler[0] = rtu_SensorsOut_Euler[0];
  localB->BusConversion_InsertedFor_Point.LatLonAlt[0] =
    rtu_SensorsOut_LatLonAlt[0];
  localB->BusConversion_InsertedFor_Point.x_sun_eci[0] =
    rtu_SensorsOut_x_sun_eci[0];

  /* BusCreator generated from: '<S1>/Pointing Mode Selection' */
  localB->BusConversion_InsertedFor_Poi_e.envForces_body[0] =
    rtu_Environment_envForces_body[0];
  localB->BusConversion_InsertedFor_Poi_e.envTorques_body[0] =
    rtu_Environment_envTorques_body[0];
  localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[0] =
    rtu_Environment_x_sun_eci[0];

  /* BusCreator generated from: '<S1>/Pointing Mode Selection' */
  localB->BusConversion_InsertedFor_Point.Euler[1] = rtu_SensorsOut_Euler[1];
  localB->BusConversion_InsertedFor_Point.LatLonAlt[1] =
    rtu_SensorsOut_LatLonAlt[1];
  localB->BusConversion_InsertedFor_Point.x_sun_eci[1] =
    rtu_SensorsOut_x_sun_eci[1];

  /* BusCreator generated from: '<S1>/Pointing Mode Selection' */
  localB->BusConversion_InsertedFor_Poi_e.envForces_body[1] =
    rtu_Environment_envForces_body[1];
  localB->BusConversion_InsertedFor_Poi_e.envTorques_body[1] =
    rtu_Environment_envTorques_body[1];
  localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[1] =
    rtu_Environment_x_sun_eci[1];

  /* BusCreator generated from: '<S1>/Pointing Mode Selection' */
  localB->BusConversion_InsertedFor_Point.Euler[2] = rtu_SensorsOut_Euler[2];
  localB->BusConversion_InsertedFor_Point.LatLonAlt[2] =
    rtu_SensorsOut_LatLonAlt[2];
  localB->BusConversion_InsertedFor_Point.x_sun_eci[2] =
    rtu_SensorsOut_x_sun_eci[2];

  /* BusCreator generated from: '<S1>/Pointing Mode Selection' */
  localB->BusConversion_InsertedFor_Poi_e.envForces_body[2] =
    rtu_Environment_envForces_body[2];
  localB->BusConversion_InsertedFor_Poi_e.envTorques_body[2] =
    rtu_Environment_envTorques_body[2];
  localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[2] =
    rtu_Environment_x_sun_eci[2];
  localB->BusConversion_InsertedFor_Poi_e.earthAngRate =
    *rtu_Environment_earthAngRate;

  /* Chart: '<S1>/Pointing Mode Selection' incorporates:
   *  DotProduct: '<S111>/Dot Product2'
   *  DotProduct: '<S111>/Dot Product3'
   *  DotProduct: '<S126>/Dot Product1'
   *  DotProduct: '<S126>/Dot Product2'
   *  DotProduct: '<S126>/Dot Product3'
   *  DotProduct: '<S78>/Dot Product1'
   *  DotProduct: '<S78>/Dot Product2'
   *  DotProduct: '<S78>/Dot Product3'
   *  DotProduct: '<S84>/Dot Product2'
   *  DotProduct: '<S84>/Dot Product3'
   *  If: '<S77>/If'
   */
  /* Gateway: Attitude Control/Pointing Mode Selection */
  /* During: Attitude Control/Pointing Mode Selection */
  if (localDW->is_active_c1_asbCubeSatACS == 0U) {
    /* Entry: Attitude Control/Pointing Mode Selection */
    localDW->is_active_c1_asbCubeSatACS = 1U;

    /* Entry Internal: Attitude Control/Pointing Mode Selection */
    /* Transition: '<S3>:6' */
    localDW->is_c1_asbCubeSatACS = asbCubeSatACS_IN_Off;

    /* SignalConversion generated from: '<S4>/PointingCmd' */
    localB->PointingCmd[0] = 0.0;
    localB->PointingCmd[1] = 0.0;
    localB->PointingCmd[2] = 0.0;
  } else if (localDW->is_c1_asbCubeSatACS == asbCubeSatACS_IN_Off) {
    /* During 'Off': '<S3>:50' */
    if (*rtu_AttitudeMode != 0.0) {
      /* Transition: '<S3>:53' */
      localB->ControlMode = 1.0;
      localDW->is_c1_asbCubeSatACS = asbCubeSatACS_IN_On;

      /* Entry Internal 'On': '<S3>:37' */
      /* Transition: '<S3>:54' */
      localDW->is_On = asbCubeSatACS_IN_Transition;
    } else {
      /* SignalConversion generated from: '<S4>/PointingCmd' */
      localB->PointingCmd[0] = 0.0;
      localB->PointingCmd[1] = 0.0;
      localB->PointingCmd[2] = 0.0;
    }
  } else {
    /* During 'On': '<S3>:37' */
    if (*rtu_AttitudeMode == 0.0) {
      /* Transition: '<S3>:41' */
      localB->ControlMode = 0.0;

      /* Exit Internal 'On': '<S3>:37' */
      localDW->is_On = asbCubeSatAC_IN_NO_ACTIVE_CHILD;
      localDW->is_c1_asbCubeSatACS = asbCubeSatACS_IN_Off;

      /* SignalConversion generated from: '<S4>/PointingCmd' */
      localB->PointingCmd[0] = 0.0;
      localB->PointingCmd[1] = 0.0;
      localB->PointingCmd[2] = 0.0;
    } else {
      switch (localDW->is_On) {
       case asbCubeSatACS_IN_Earth:
        /* During 'Earth': '<S3>:48' */
        if (*rtu_AttitudeMode == 2.0) {
          /* Transition: '<S3>:56' */
          localB->ControlMode = 1.0;
          localDW->is_On = asbCubeSatACS_IN_Transition;
        } else {
          /* Product: '<S19>/j x k' */
          localB->jxk_n = localB->BusConversion_InsertedFor_Point.V_ecef[1] *
            localB->BusConversion_InsertedFor_Point.X_ecef[2];

          /* Product: '<S19>/k x i' */
          localB->kxi_p = localB->BusConversion_InsertedFor_Point.V_ecef[2] *
            localB->BusConversion_InsertedFor_Point.X_ecef[0];

          /* Product: '<S19>/i x j' */
          localB->ixj_k3 = localB->BusConversion_InsertedFor_Point.V_ecef[0] *
            localB->BusConversion_InsertedFor_Point.X_ecef[1];

          /* Product: '<S20>/k x j' */
          localB->kxj_n = localB->BusConversion_InsertedFor_Point.V_ecef[2] *
            localB->BusConversion_InsertedFor_Point.X_ecef[1];

          /* Product: '<S20>/i x k' */
          localB->ixk_k = localB->BusConversion_InsertedFor_Point.V_ecef[0] *
            localB->BusConversion_InsertedFor_Point.X_ecef[2];

          /* Product: '<S20>/j x i' */
          localB->jxi_b = localB->BusConversion_InsertedFor_Point.V_ecef[1] *
            localB->BusConversion_InsertedFor_Point.X_ecef[0];

          /* Sum: '<S12>/Sum' */
          localB->Sum_ou[0] = localB->jxk_n - localB->kxj_n;
          localB->Sum_ou[1] = localB->kxi_p - localB->ixk_k;
          localB->Sum_ou[2] = localB->ixj_k3 - localB->jxi_b;

          /* Gain: '<S7>/z = -r' */
          localB->zr[0] = -localB->BusConversion_InsertedFor_Point.X_ecef[0];
          localB->zr[1] = -localB->BusConversion_InsertedFor_Point.X_ecef[1];
          localB->zr[2] = -localB->BusConversion_InsertedFor_Point.X_ecef[2];

          /* Product: '<S17>/i x j' */
          localB->ixj_i = localB->Sum_ou[0] * localB->zr[1];

          /* Product: '<S17>/j x k' */
          localB->jxk_i = localB->Sum_ou[1] * localB->zr[2];

          /* Product: '<S17>/k x i' */
          localB->kxi_os = localB->Sum_ou[2] * localB->zr[0];

          /* Product: '<S18>/i x k' */
          localB->ixk_g = localB->Sum_ou[0] * localB->zr[2];

          /* Product: '<S18>/j x i' */
          localB->jxi_ok = localB->Sum_ou[1] * localB->zr[0];

          /* Product: '<S18>/k x j' */
          localB->kxj_g = localB->Sum_ou[2] * localB->zr[1];

          /* Sum: '<S11>/Sum' */
          localB->Sum_dv[0] = localB->jxk_i - localB->kxj_g;
          localB->Sum_dv[1] = localB->kxi_os - localB->ixk_g;
          localB->Sum_dv[2] = localB->ixj_i - localB->jxi_ok;

          /* DotProduct: '<S14>/Dot Product' */
          uTmp = localB->Sum_dv[0];
          tmp = localB->Sum_dv[0];
          uTmp_0 = uTmp * tmp;
          uTmp = localB->Sum_dv[1];
          tmp = localB->Sum_dv[1];
          uTmp_0 += uTmp * tmp;
          uTmp = localB->Sum_dv[2];
          tmp = localB->Sum_dv[2];
          uTmp_0 += uTmp * tmp;
          localB->DotProduct = uTmp_0;

          /* Sum: '<S14>/Sum of Elements' */
          uTmp_idx_0 = localB->DotProduct;
          localB->SumofElements = uTmp_idx_0;

          /* Math: '<S14>/Math Function1'
           *
           * About '<S14>/Math Function1':
           *  Operator: sqrt
           */
          uTmp_idx_0 = localB->SumofElements;
          if (uTmp_idx_0 < 0.0) {
            localB->MathFunction1 = -sqrt(fabs(uTmp_idx_0));
          } else {
            localB->MathFunction1 = sqrt(uTmp_idx_0);
          }

          /* Product: '<S14>/Divide' */
          localB->ORFtoECEF[0] = localB->Sum_dv[0] / localB->MathFunction1;

          /* DotProduct: '<S15>/Dot Product' */
          uTmp = localB->Sum_ou[0];
          tmp = localB->Sum_ou[0];
          uTmp_0 = uTmp * tmp;

          /* Product: '<S14>/Divide' */
          localB->ORFtoECEF[1] = localB->Sum_dv[1] / localB->MathFunction1;

          /* DotProduct: '<S15>/Dot Product' */
          uTmp = localB->Sum_ou[1];
          tmp = localB->Sum_ou[1];
          uTmp_0 += uTmp * tmp;

          /* Product: '<S14>/Divide' */
          localB->ORFtoECEF[2] = localB->Sum_dv[2] / localB->MathFunction1;

          /* DotProduct: '<S15>/Dot Product' */
          uTmp = localB->Sum_ou[2];
          tmp = localB->Sum_ou[2];
          uTmp_0 += uTmp * tmp;
          localB->DotProduct_m = uTmp_0;

          /* Sum: '<S15>/Sum of Elements' */
          uTmp_idx_0 = localB->DotProduct_m;
          localB->SumofElements_h = uTmp_idx_0;

          /* Math: '<S15>/Math Function1'
           *
           * About '<S15>/Math Function1':
           *  Operator: sqrt
           */
          uTmp_idx_0 = localB->SumofElements_h;
          if (uTmp_idx_0 < 0.0) {
            localB->MathFunction1_n = -sqrt(fabs(uTmp_idx_0));
          } else {
            localB->MathFunction1_n = sqrt(uTmp_idx_0);
          }

          /* Product: '<S15>/Divide' */
          localB->ORFtoECEF[3] = localB->Sum_ou[0] / localB->MathFunction1_n;

          /* DotProduct: '<S16>/Dot Product' */
          uTmp = localB->zr[0];
          tmp = localB->zr[0];
          uTmp_0 = uTmp * tmp;

          /* Product: '<S15>/Divide' */
          localB->ORFtoECEF[4] = localB->Sum_ou[1] / localB->MathFunction1_n;

          /* DotProduct: '<S16>/Dot Product' */
          uTmp = localB->zr[1];
          tmp = localB->zr[1];
          uTmp_0 += uTmp * tmp;

          /* Product: '<S15>/Divide' */
          localB->ORFtoECEF[5] = localB->Sum_ou[2] / localB->MathFunction1_n;

          /* DotProduct: '<S16>/Dot Product' */
          uTmp = localB->zr[2];
          tmp = localB->zr[2];
          uTmp_0 += uTmp * tmp;
          localB->DotProduct_b = uTmp_0;

          /* Sum: '<S16>/Sum of Elements' */
          uTmp_idx_0 = localB->DotProduct_b;
          localB->SumofElements_g = uTmp_idx_0;

          /* Math: '<S16>/Math Function1'
           *
           * About '<S16>/Math Function1':
           *  Operator: sqrt
           */
          uTmp_idx_0 = localB->SumofElements_g;
          if (uTmp_idx_0 < 0.0) {
            localB->MathFunction1_ni = -sqrt(fabs(uTmp_idx_0));
          } else {
            localB->MathFunction1_ni = sqrt(uTmp_idx_0);
          }

          /* Product: '<S16>/Divide' */
          localB->ORFtoECEF[6] = localB->zr[0] / localB->MathFunction1_ni;
          localB->ORFtoECEF[7] = localB->zr[1] / localB->MathFunction1_ni;
          localB->ORFtoECEF[8] = localB->zr[2] / localB->MathFunction1_ni;

          /* Math: '<S7>/ECEF to ORF' */
          for (i = 0; i < 3; i++) {
            localB->ECEFtoORF[3 * i] = localB->ORFtoECEF[i];
            localB->ECEFtoORF[3 * i + 1] = localB->ORFtoECEF[i + 3];
            localB->ECEFtoORF[3 * i + 2] = localB->ORFtoECEF[i + 6];
          }

          /* Sum: '<S24>/Add' */
          uTmp_idx_0 = localB->ECEFtoORF[0];
          uTmp_idx_1 = localB->ECEFtoORF[4];
          uTmp_idx_2 = localB->ECEFtoORF[8];
          uTmp_idx_0 += uTmp_idx_1;
          uTmp_idx_0 += uTmp_idx_2;
          localB->Add = uTmp_idx_0;

          /* If: '<S13>/If' incorporates:
           *  If: '<S21>/Find Maximum Diagonal Value'
           */
          if (localB->Add > 0.0) {
            /* Outputs for IfAction SubSystem: '<S13>/Positive Trace' incorporates:
             *  ActionPort: '<S22>/Action Port'
             */
            /* Sum: '<S22>/Sum' incorporates:
             *  Constant: '<S22>/Constant'
             */
            localB->Sum_dx = localB->Add + 1.0;

            /* Sqrt: '<S22>/sqrt' */
            localB->sqrt_b = sqrt(localB->Sum_dx);

            /* Gain: '<S22>/Gain' */
            localB->Merge_e[0] = 0.5 * localB->sqrt_b;

            /* Gain: '<S22>/Gain1' */
            localB->Gain1_lg = 2.0 * localB->sqrt_b;

            /* Sum: '<S45>/Add' */
            localB->Add_i5 = localB->ECEFtoORF[7] - localB->ECEFtoORF[5];

            /* Sum: '<S44>/Add' */
            localB->Add_fn = localB->ECEFtoORF[2] - localB->ECEFtoORF[6];

            /* Sum: '<S46>/Add' */
            localB->Add_mp = localB->ECEFtoORF[3] - localB->ECEFtoORF[1];

            /* Product: '<S22>/Product' */
            localB->Merge_e[1] = localB->Add_i5 / localB->Gain1_lg;
            localB->Merge_e[2] = localB->Add_fn / localB->Gain1_lg;
            localB->Merge_e[3] = localB->Add_mp / localB->Gain1_lg;

            /* End of Outputs for SubSystem: '<S13>/Positive Trace' */
          } else {
            /* Outputs for IfAction SubSystem: '<S13>/Negative Trace' incorporates:
             *  ActionPort: '<S21>/Action Port'
             */
            if ((localB->ECEFtoORF[4] > localB->ECEFtoORF[0]) &&
                (localB->ECEFtoORF[4] > localB->ECEFtoORF[8])) {
              /* Outputs for IfAction SubSystem: '<S21>/Maximum Value at DCM(2,2)' incorporates:
               *  ActionPort: '<S26>/Action Port'
               */
              /* If: '<S21>/Find Maximum Diagonal Value' incorporates:
               *  Constant: '<S37>/Constant1'
               *  Constant: '<S38>/Constant'
               *  Gain: '<S26>/Gain'
               *  Gain: '<S26>/Gain1'
               *  Gain: '<S26>/Gain3'
               *  Gain: '<S26>/Gain4'
               *  Product: '<S26>/Product'
               *  Product: '<S37>/Product'
               *  Sqrt: '<S26>/sqrt'
               *  Sum: '<S34>/Add'
               *  Sum: '<S35>/Add'
               *  Sum: '<S36>/Add'
               *  Sum: '<S38>/Add'
               *  Switch: '<S37>/Switch'
               */
              localB->Add_hm = ((localB->ECEFtoORF[4] - localB->ECEFtoORF[0]) -
                                localB->ECEFtoORF[8]) + 1.0;
              localB->sqrt_p = sqrt(localB->Add_hm);
              localB->Merge_e[2] = 0.5 * localB->sqrt_p;
              localB->Add_o = localB->ECEFtoORF[1] + localB->ECEFtoORF[3];
              localB->Add_f = localB->ECEFtoORF[5] + localB->ECEFtoORF[7];
              localB->Add_b4 = localB->ECEFtoORF[2] - localB->ECEFtoORF[6];
              if (localB->sqrt_p != 0.0) {
                localB->Switch_f1[0] = 0.5;
                localB->Switch_f1[1] = localB->sqrt_p;
              } else {
                localB->Switch_f1[0] = 0.0;
                localB->Switch_f1[1] = 1.0;
              }

              localB->Product_jp = localB->Switch_f1[0] / localB->Switch_f1[1];
              localB->Product_oi[0] = localB->Add_o * localB->Product_jp;
              localB->Product_oi[1] = localB->Add_f * localB->Product_jp;
              localB->Product_oi[2] = localB->Add_b4 * localB->Product_jp;
              localB->Merge_e[1] = localB->Product_oi[0];
              localB->Merge_e[3] = localB->Product_oi[1];
              localB->Merge_e[0] = localB->Product_oi[2];

              /* End of Outputs for SubSystem: '<S21>/Maximum Value at DCM(2,2)' */
            } else if (localB->ECEFtoORF[8] > localB->ECEFtoORF[0]) {
              /* Outputs for IfAction SubSystem: '<S21>/Maximum Value at DCM(3,3)' incorporates:
               *  ActionPort: '<S27>/Action Port'
               */
              /* If: '<S21>/Find Maximum Diagonal Value' incorporates:
               *  Constant: '<S42>/Constant1'
               *  Constant: '<S43>/Constant'
               *  Gain: '<S27>/Gain'
               *  Gain: '<S27>/Gain1'
               *  Gain: '<S27>/Gain2'
               *  Gain: '<S27>/Gain3'
               *  Product: '<S27>/Product'
               *  Product: '<S42>/Product'
               *  Sqrt: '<S27>/sqrt'
               *  Sum: '<S39>/Add'
               *  Sum: '<S40>/Add'
               *  Sum: '<S41>/Add'
               *  Sum: '<S43>/Add'
               *  Switch: '<S42>/Switch'
               */
              localB->Add_h = ((localB->ECEFtoORF[8] - localB->ECEFtoORF[0]) -
                               localB->ECEFtoORF[4]) + 1.0;
              localB->sqrt_o2 = sqrt(localB->Add_h);
              localB->Merge_e[3] = 0.5 * localB->sqrt_o2;
              localB->Add_b = localB->ECEFtoORF[2] + localB->ECEFtoORF[6];
              localB->Add_a = localB->ECEFtoORF[5] + localB->ECEFtoORF[7];
              localB->Add_p = localB->ECEFtoORF[3] - localB->ECEFtoORF[1];
              if (localB->sqrt_o2 != 0.0) {
                localB->Switch_o[0] = 0.5;
                localB->Switch_o[1] = localB->sqrt_o2;
              } else {
                localB->Switch_o[0] = 0.0;
                localB->Switch_o[1] = 1.0;
              }

              localB->Product_ph = localB->Switch_o[0] / localB->Switch_o[1];
              localB->Product_oe[0] = localB->Add_b * localB->Product_ph;
              localB->Product_oe[1] = localB->Add_a * localB->Product_ph;
              localB->Product_oe[2] = localB->Add_p * localB->Product_ph;
              localB->Merge_e[1] = localB->Product_oe[0];
              localB->Merge_e[2] = localB->Product_oe[1];
              localB->Merge_e[0] = localB->Product_oe[2];

              /* End of Outputs for SubSystem: '<S21>/Maximum Value at DCM(3,3)' */
            } else {
              /* Outputs for IfAction SubSystem: '<S21>/Maximum Value at DCM(1,1)' incorporates:
               *  ActionPort: '<S25>/Action Port'
               */
              /* If: '<S21>/Find Maximum Diagonal Value' incorporates:
               *  Constant: '<S32>/Constant1'
               *  Constant: '<S33>/Constant'
               *  Gain: '<S25>/Gain'
               *  Gain: '<S25>/Gain1'
               *  Gain: '<S25>/Gain2'
               *  Gain: '<S25>/Gain3'
               *  Product: '<S25>/Product'
               *  Product: '<S32>/Product'
               *  Sqrt: '<S25>/sqrt'
               *  Sum: '<S29>/Add'
               *  Sum: '<S30>/Add'
               *  Sum: '<S31>/Add'
               *  Sum: '<S33>/Add'
               *  Switch: '<S32>/Switch'
               */
              localB->Add_d = ((localB->ECEFtoORF[0] - localB->ECEFtoORF[4]) -
                               localB->ECEFtoORF[8]) + 1.0;
              localB->sqrt_nk = sqrt(localB->Add_d);
              localB->Merge_e[1] = 0.5 * localB->sqrt_nk;
              if (localB->sqrt_nk != 0.0) {
                localB->Switch_f[0] = 0.5;
                localB->Switch_f[1] = localB->sqrt_nk;
              } else {
                localB->Switch_f[0] = 0.0;
                localB->Switch_f[1] = 1.0;
              }

              localB->Product_n4 = localB->Switch_f[0] / localB->Switch_f[1];
              localB->Add_de = localB->ECEFtoORF[1] + localB->ECEFtoORF[3];
              localB->Add_i = localB->ECEFtoORF[2] + localB->ECEFtoORF[6];
              localB->Add_m = localB->ECEFtoORF[7] - localB->ECEFtoORF[5];
              localB->Product_i[0] = localB->Product_n4 * localB->Add_de;
              localB->Product_i[1] = localB->Product_n4 * localB->Add_i;
              localB->Product_i[2] = localB->Product_n4 * localB->Add_m;
              localB->Merge_e[2] = localB->Product_i[0];
              localB->Merge_e[3] = localB->Product_i[1];
              localB->Merge_e[0] = localB->Product_i[2];

              /* End of Outputs for SubSystem: '<S21>/Maximum Value at DCM(1,1)' */
            }

            /* End of Outputs for SubSystem: '<S13>/Negative Trace' */
          }

          /* Product: '<S60>/Product' */
          localB->Product_ky = localB->BusConversion_InsertedFor_Point.q_ecef2b
            [0] * localB->BusConversion_InsertedFor_Point.q_ecef2b[0];

          /* Product: '<S60>/Product1' */
          localB->Product1_li = localB->
            BusConversion_InsertedFor_Point.q_ecef2b[1] *
            localB->BusConversion_InsertedFor_Point.q_ecef2b[1];

          /* Product: '<S60>/Product2' */
          localB->Product2_gb = localB->
            BusConversion_InsertedFor_Point.q_ecef2b[2] *
            localB->BusConversion_InsertedFor_Point.q_ecef2b[2];

          /* Product: '<S60>/Product3' */
          localB->Product3_an = localB->
            BusConversion_InsertedFor_Point.q_ecef2b[3] *
            localB->BusConversion_InsertedFor_Point.q_ecef2b[3];

          /* Sum: '<S60>/Sum' */
          localB->Sum_hk = ((localB->Product_ky + localB->Product1_li) +
                            localB->Product2_gb) + localB->Product3_an;

          /* Product: '<S8>/Divide' */
          localB->Divide_j = localB->BusConversion_InsertedFor_Point.q_ecef2b[0]
            / localB->Sum_hk;

          /* UnaryMinus: '<S59>/Unary Minus' */
          localB->UnaryMinus = -localB->
            BusConversion_InsertedFor_Point.q_ecef2b[1];

          /* Product: '<S8>/Divide1' */
          localB->Divide1_d = localB->UnaryMinus / localB->Sum_hk;

          /* UnaryMinus: '<S59>/Unary Minus1' */
          localB->UnaryMinus1 =
            -localB->BusConversion_InsertedFor_Point.q_ecef2b[2];

          /* Product: '<S8>/Divide2' */
          localB->Divide2 = localB->UnaryMinus1 / localB->Sum_hk;

          /* UnaryMinus: '<S59>/Unary Minus2' */
          localB->UnaryMinus2 =
            -localB->BusConversion_InsertedFor_Point.q_ecef2b[3];

          /* Product: '<S8>/Divide3' */
          localB->Divide3 = localB->UnaryMinus2 / localB->Sum_hk;

          /* Product: '<S61>/Product' */
          localB->Product_pb = localB->Divide_j * localB->Merge_e[0];

          /* Product: '<S61>/Product1' */
          localB->Product1_pg = localB->Divide1_d * localB->Merge_e[1];

          /* Product: '<S61>/Product2' */
          localB->Product2_mw = localB->Divide2 * localB->Merge_e[2];

          /* Product: '<S61>/Product3' */
          localB->Product3_cd = localB->Divide3 * localB->Merge_e[3];

          /* Sum: '<S61>/Sum' */
          localB->Sum_fj = ((localB->Product_pb - localB->Product1_pg) -
                            localB->Product2_mw) - localB->Product3_cd;

          /* Product: '<S62>/Product' */
          localB->Product_la = localB->Divide_j * localB->Merge_e[1];

          /* Product: '<S62>/Product1' */
          localB->Product1_p5 = localB->Divide1_d * localB->Merge_e[0];

          /* Product: '<S62>/Product2' */
          localB->Product2_jd = localB->Divide2 * localB->Merge_e[3];

          /* Product: '<S62>/Product3' */
          localB->Product3_db = localB->Divide3 * localB->Merge_e[2];

          /* Sum: '<S62>/Sum' */
          localB->Sum_c3 = ((localB->Product_la + localB->Product1_p5) +
                            localB->Product2_jd) - localB->Product3_db;

          /* Product: '<S63>/Product' */
          localB->Product_nm = localB->Divide_j * localB->Merge_e[2];

          /* Product: '<S63>/Product1' */
          localB->Product1_o = localB->Divide1_d * localB->Merge_e[3];

          /* Product: '<S63>/Product2' */
          localB->Product2_bn = localB->Divide2 * localB->Merge_e[0];

          /* Product: '<S63>/Product3' */
          localB->Product3_gc = localB->Divide3 * localB->Merge_e[1];

          /* Sum: '<S63>/Sum' */
          localB->Sum_hn = ((localB->Product_nm - localB->Product1_o) +
                            localB->Product2_bn) + localB->Product3_gc;

          /* Product: '<S64>/Product' */
          localB->Product_m0 = localB->Divide_j * localB->Merge_e[3];

          /* Product: '<S64>/Product1' */
          localB->Product1_eo = localB->Divide1_d * localB->Merge_e[2];

          /* Product: '<S64>/Product2' */
          localB->Product2_dz = localB->Divide2 * localB->Merge_e[1];

          /* Product: '<S64>/Product3' */
          localB->Product3_ox = localB->Divide3 * localB->Merge_e[0];

          /* Sum: '<S64>/Sum' */
          localB->Sum_h4 = ((localB->Product_m0 + localB->Product1_eo) -
                            localB->Product2_dz) + localB->Product3_ox;

          /* Product: '<S72>/Product' */
          localB->Product_mx = localB->Sum_fj * localB->Sum_fj;

          /* Product: '<S72>/Product1' */
          localB->Product1_fz = localB->Sum_c3 * localB->Sum_c3;

          /* Product: '<S72>/Product2' */
          localB->Product2_p4 = localB->Sum_hn * localB->Sum_hn;

          /* Product: '<S72>/Product3' */
          localB->Product3_kb = localB->Sum_h4 * localB->Sum_h4;

          /* Sum: '<S72>/Sum' */
          localB->Sum_k = ((localB->Product_mx + localB->Product1_fz) +
                           localB->Product2_p4) + localB->Product3_kb;

          /* Sqrt: '<S71>/sqrt' */
          localB->sqrt_jz = sqrt(localB->Sum_k);

          /* Product: '<S66>/Product' */
          localB->Product_j5 = localB->Sum_fj / localB->sqrt_jz;

          /* Product: '<S66>/Product1' */
          localB->Product1_ik = localB->Sum_c3 / localB->sqrt_jz;

          /* Product: '<S66>/Product2' */
          localB->Product2_ev = localB->Sum_hn / localB->sqrt_jz;

          /* Product: '<S66>/Product3' */
          localB->Product3_f = localB->Sum_h4 / localB->sqrt_jz;

          /* Fcn: '<S10>/fcn3' */
          localB->fcn3_l = (localB->Product1_ik * localB->Product3_f +
                            localB->Product_j5 * localB->Product2_ev) * 2.0;

          /* If: '<S67>/If' incorporates:
           *  Constant: '<S68>/Constant'
           *  Constant: '<S69>/Constant'
           */
          if (localB->fcn3_l > 1.0) {
            /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem' incorporates:
             *  ActionPort: '<S68>/Action Port'
             */
            localB->Merge_cv = 1.0;

            /* End of Outputs for SubSystem: '<S67>/If Action Subsystem' */
          } else if (localB->fcn3_l < -1.0) {
            /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S69>/Action Port'
             */
            localB->Merge_cv = 1.0;

            /* End of Outputs for SubSystem: '<S67>/If Action Subsystem1' */
          } else {
            /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S70>/Action Port'
             */
            asbCubeSatAC_IfActionSubsystem2(localB->fcn3_l, &localB->Merge_cv);

            /* End of Outputs for SubSystem: '<S67>/If Action Subsystem2' */
          }

          /* Fcn: '<S10>/fcn1' */
          localB->fcn1_l = (localB->Product2_ev * localB->Product3_f -
                            localB->Product_j5 * localB->Product1_ik) * -2.0;

          /* Fcn: '<S10>/fcn2' */
          localB->fcn2_k = ((localB->Product_j5 * localB->Product_j5 -
                             localB->Product1_ik * localB->Product1_ik) -
                            localB->Product2_ev * localB->Product2_ev) +
            localB->Product3_f * localB->Product3_f;

          /* Trigonometry: '<S65>/Trigonometric Function1' */
          localB->PointingCmd[0] = rt_atan2d_snf(localB->fcn1_l, localB->fcn2_k);

          /* Fcn: '<S10>/fcn4' */
          localB->fcn4_e = (localB->Product1_ik * localB->Product2_ev -
                            localB->Product_j5 * localB->Product3_f) * -2.0;

          /* Fcn: '<S10>/fcn5' */
          localB->fcn5_p = ((localB->Product_j5 * localB->Product_j5 +
                             localB->Product1_ik * localB->Product1_ik) -
                            localB->Product2_ev * localB->Product2_ev) -
            localB->Product3_f * localB->Product3_f;

          /* Trigonometry: '<S65>/Trigonometric Function3' */
          localB->PointingCmd[2] = rt_atan2d_snf(localB->fcn4_e, localB->fcn5_p);

          /* Trigonometry: '<S65>/trigFcn' */
          uTmp = localB->Merge_cv;
          if (uTmp > 1.0) {
            uTmp = 1.0;
          } else {
            if (uTmp < -1.0) {
              uTmp = -1.0;
            }
          }

          localB->PointingCmd[1] = asin(uTmp);
        }
        break;

       case asbCubeSatACS_IN_Sun:
        /* During 'Sun': '<S3>:49' */
        if (*rtu_AttitudeMode == 1.0) {
          /* Transition: '<S3>:55' */
          localB->ControlMode = 1.0;
          localDW->is_On = asbCubeSatACS_IN_Transition;
        } else {
          if (asbCubeSatACS_ConstB.Abs < 1.0E-6) {
            /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem' incorporates:
             *  ActionPort: '<S88>/Action Port'
             */
            /* If: '<S77>/If' */
            asbCubeSatACS_IfActionSubsystem(&localB->Merge);

            /* End of Outputs for SubSystem: '<S77>/If Action Subsystem' */
          } else if (asbCubeSatACS_ConstB.Abs1 < 1.0E-6) {
            /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S89>/Action Port'
             */
            /* If: '<S77>/If' */
            asbCubeSatAC_IfActionSubsystem1(&localB->Merge);

            /* End of Outputs for SubSystem: '<S77>/If Action Subsystem1' */
          } else {
            /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S90>/Action Port'
             */
            /* If: '<S77>/If' */
            asbCubeSat_IfActionSubsystem2_j(&localB->Merge);

            /* End of Outputs for SubSystem: '<S77>/If Action Subsystem2' */
          }

          /* Product: '<S157>/Product' incorporates:
           *  If: '<S77>/If'
           */
          localB->Product = localB->BusConversion_InsertedFor_Point.q_eci2b[0] *
            localB->BusConversion_InsertedFor_Point.q_eci2b[0];

          /* Product: '<S157>/Product1' */
          localB->Product1 = localB->BusConversion_InsertedFor_Point.q_eci2b[1] *
            localB->BusConversion_InsertedFor_Point.q_eci2b[1];

          /* Product: '<S157>/Product2' */
          localB->Product2 = localB->BusConversion_InsertedFor_Point.q_eci2b[2] *
            localB->BusConversion_InsertedFor_Point.q_eci2b[2];

          /* Product: '<S157>/Product3' */
          localB->Product3 = localB->BusConversion_InsertedFor_Point.q_eci2b[3] *
            localB->BusConversion_InsertedFor_Point.q_eci2b[3];

          /* Sum: '<S157>/Sum' */
          localB->Sum_n = ((localB->Product + localB->Product1) +
                           localB->Product2) + localB->Product3;

          /* Sqrt: '<S156>/sqrt' */
          localB->sqrt_o = sqrt(localB->Sum_n);

          /* Product: '<S152>/Product2' */
          localB->Product2_f = localB->BusConversion_InsertedFor_Point.q_eci2b[2]
            / localB->sqrt_o;

          /* Product: '<S153>/Product6' */
          localB->Product6 = localB->Product2_f * localB->Product2_f;

          /* Product: '<S152>/Product3' */
          localB->Product3_b = localB->BusConversion_InsertedFor_Point.q_eci2b[3]
            / localB->sqrt_o;

          /* Product: '<S153>/Product7' */
          localB->Product7 = localB->Product3_b * localB->Product3_b;

          /* Sum: '<S153>/Sum3' incorporates:
           *  Constant: '<S153>/Constant'
           */
          localB->Sum3 = (0.5 - localB->Product6) - localB->Product7;

          /* Gain: '<S153>/Gain2' */
          localB->Gain2 = 2.0 * localB->Sum3;

          /* Product: '<S153>/Product8' */
          localB->Product8 = localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[0]
            * localB->Gain2;

          /* Product: '<S152>/Product1' */
          localB->Product1_d = localB->BusConversion_InsertedFor_Point.q_eci2b[1]
            / localB->sqrt_o;

          /* Product: '<S153>/Product' */
          localB->Product_m = localB->Product1_d * localB->Product2_f;

          /* Product: '<S152>/Product' */
          localB->Product_b = localB->BusConversion_InsertedFor_Point.q_eci2b[0]
            / localB->sqrt_o;

          /* Product: '<S153>/Product1' */
          localB->Product1_l = localB->Product_b * localB->Product3_b;

          /* Sum: '<S153>/Sum1' */
          localB->Sum1 = localB->Product_m + localB->Product1_l;

          /* Gain: '<S153>/Gain' */
          localB->Gain = 2.0 * localB->Sum1;

          /* Product: '<S153>/Product4' */
          localB->Product4 = localB->Gain *
            localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[1];

          /* Product: '<S153>/Product2' */
          localB->Product2_e = localB->Product_b * localB->Product2_f;

          /* Product: '<S153>/Product3' */
          localB->Product3_i = localB->Product1_d * localB->Product3_b;

          /* Sum: '<S153>/Sum2' */
          localB->Sum2 = localB->Product3_i - localB->Product2_e;

          /* Gain: '<S153>/Gain1' */
          localB->Gain1 = 2.0 * localB->Sum2;

          /* Product: '<S153>/Product5' */
          localB->Product5 = localB->Gain1 *
            localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[2];

          /* Sum: '<S153>/Sum' */
          localB->Sum_p = (localB->Product8 + localB->Product4) +
            localB->Product5;

          /* Product: '<S154>/Product' */
          localB->Product_l = localB->Product1_d * localB->Product2_f;

          /* Product: '<S154>/Product1' */
          localB->Product1_g = localB->Product_b * localB->Product3_b;

          /* Sum: '<S154>/Sum1' */
          localB->Sum1_m = localB->Product_l - localB->Product1_g;

          /* Gain: '<S154>/Gain' */
          localB->Gain_a = 2.0 * localB->Sum1_m;

          /* Product: '<S154>/Product4' */
          localB->Product4_k = localB->
            BusConversion_InsertedFor_Poi_e.x_sun_eci[0] * localB->Gain_a;

          /* Product: '<S154>/Product6' */
          localB->Product6_o = localB->Product1_d * localB->Product1_d;

          /* Product: '<S154>/Product7' */
          localB->Product7_d = localB->Product3_b * localB->Product3_b;

          /* Sum: '<S154>/Sum3' incorporates:
           *  Constant: '<S154>/Constant'
           */
          localB->Sum3_g = (0.5 - localB->Product6_o) - localB->Product7_d;

          /* Gain: '<S154>/Gain2' */
          localB->Gain2_n = 2.0 * localB->Sum3_g;

          /* Product: '<S154>/Product8' */
          localB->Product8_a = localB->Gain2_n *
            localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[1];

          /* Product: '<S154>/Product2' */
          localB->Product2_a = localB->Product_b * localB->Product1_d;

          /* Product: '<S154>/Product3' */
          localB->Product3_h = localB->Product2_f * localB->Product3_b;

          /* Sum: '<S154>/Sum2' */
          localB->Sum2_o = localB->Product2_a + localB->Product3_h;

          /* Gain: '<S154>/Gain1' */
          localB->Gain1_f = 2.0 * localB->Sum2_o;

          /* Product: '<S154>/Product5' */
          localB->Product5_p = localB->Gain1_f *
            localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[2];

          /* Sum: '<S154>/Sum' */
          localB->Sum_o = (localB->Product4_k + localB->Product8_a) +
            localB->Product5_p;

          /* Product: '<S155>/Product' */
          localB->Product_p = localB->Product1_d * localB->Product3_b;

          /* Product: '<S155>/Product1' */
          localB->Product1_dq = localB->Product_b * localB->Product2_f;

          /* Sum: '<S155>/Sum1' */
          localB->Sum1_j = localB->Product_p + localB->Product1_dq;

          /* Gain: '<S155>/Gain' */
          localB->Gain_j = 2.0 * localB->Sum1_j;

          /* Product: '<S155>/Product4' */
          localB->Product4_g = localB->
            BusConversion_InsertedFor_Poi_e.x_sun_eci[0] * localB->Gain_j;

          /* Product: '<S155>/Product2' */
          localB->Product2_l = localB->Product_b * localB->Product1_d;

          /* Product: '<S155>/Product3' */
          localB->Product3_g = localB->Product2_f * localB->Product3_b;

          /* Sum: '<S155>/Sum2' */
          localB->Sum2_m = localB->Product3_g - localB->Product2_l;

          /* Gain: '<S155>/Gain1' */
          localB->Gain1_o = 2.0 * localB->Sum2_m;

          /* Product: '<S155>/Product5' */
          localB->Product5_b = localB->Gain1_o *
            localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[1];

          /* Product: '<S155>/Product6' */
          localB->Product6_c = localB->Product1_d * localB->Product1_d;

          /* Product: '<S155>/Product7' */
          localB->Product7_g = localB->Product2_f * localB->Product2_f;

          /* Sum: '<S155>/Sum3' incorporates:
           *  Constant: '<S155>/Constant'
           */
          localB->Sum3_c = (0.5 - localB->Product6_c) - localB->Product7_g;

          /* Gain: '<S155>/Gain2' */
          localB->Gain2_a = 2.0 * localB->Sum3_c;

          /* Product: '<S155>/Product8' */
          localB->Product8_m = localB->Gain2_a *
            localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[2];

          /* Sum: '<S155>/Sum' */
          localB->Sum_j = (localB->Product4_g + localB->Product5_b) +
            localB->Product8_m;

          /* SignalConversion generated from: '<S78>/Dot Product1' */
          localB->TmpSignalConversionAtDotProduct[0] = localB->Sum_p;
          localB->TmpSignalConversionAtDotProduct[1] = localB->Sum_o;
          localB->TmpSignalConversionAtDotProduct[2] = localB->Sum_j;

          /* Product: '<S163>/Product' */
          localB->Product_bp = localB->BusConversion_InsertedFor_Point.q_eci2b[0]
            * localB->BusConversion_InsertedFor_Point.q_eci2b[0];

          /* Product: '<S163>/Product1' */
          localB->Product1_f = localB->BusConversion_InsertedFor_Point.q_eci2b[1]
            * localB->BusConversion_InsertedFor_Point.q_eci2b[1];

          /* Product: '<S163>/Product2' */
          localB->Product2_j = localB->BusConversion_InsertedFor_Point.q_eci2b[2]
            * localB->BusConversion_InsertedFor_Point.q_eci2b[2];

          /* Product: '<S163>/Product3' */
          localB->Product3_d = localB->BusConversion_InsertedFor_Point.q_eci2b[3]
            * localB->BusConversion_InsertedFor_Point.q_eci2b[3];

          /* Sum: '<S163>/Sum' */
          localB->Sum_h = ((localB->Product_bp + localB->Product1_f) +
                           localB->Product2_j) + localB->Product3_d;

          /* Sqrt: '<S162>/sqrt' */
          localB->sqrt_n = sqrt(localB->Sum_h);

          /* Product: '<S158>/Product2' */
          localB->Product2_c = localB->BusConversion_InsertedFor_Point.q_eci2b[2]
            / localB->sqrt_n;

          /* Product: '<S159>/Product6' */
          localB->Product6_b = localB->Product2_c * localB->Product2_c;

          /* Product: '<S158>/Product3' */
          localB->Product3_e = localB->BusConversion_InsertedFor_Point.q_eci2b[3]
            / localB->sqrt_n;

          /* Product: '<S159>/Product7' */
          localB->Product7_b = localB->Product3_e * localB->Product3_e;

          /* Sum: '<S159>/Sum3' incorporates:
           *  Constant: '<S159>/Constant'
           */
          localB->Sum3_j = (0.5 - localB->Product6_b) - localB->Product7_b;

          /* Gain: '<S159>/Gain2' */
          localB->Gain2_k = 2.0 * localB->Sum3_j;

          /* Product: '<S159>/Product8' */
          localB->Product8_o = 0.0 * localB->Gain2_k;

          /* Product: '<S158>/Product1' */
          localB->Product1_a = localB->BusConversion_InsertedFor_Point.q_eci2b[1]
            / localB->sqrt_n;

          /* Product: '<S159>/Product' */
          localB->Product_n = localB->Product1_a * localB->Product2_c;

          /* Product: '<S158>/Product' */
          localB->Product_e = localB->BusConversion_InsertedFor_Point.q_eci2b[0]
            / localB->sqrt_n;

          /* Product: '<S159>/Product1' */
          localB->Product1_k = localB->Product_e * localB->Product3_e;

          /* Sum: '<S159>/Sum1' */
          localB->Sum1_n = localB->Product_n + localB->Product1_k;

          /* Gain: '<S159>/Gain' */
          localB->Gain_m = 2.0 * localB->Sum1_n;

          /* Product: '<S159>/Product4' */
          localB->Product4_p = localB->Gain_m * 0.0;

          /* Product: '<S159>/Product2' */
          localB->Product2_h = localB->Product_e * localB->Product2_c;

          /* Product: '<S159>/Product3' */
          localB->Product3_m = localB->Product1_a * localB->Product3_e;

          /* Sum: '<S159>/Sum2' */
          localB->Sum2_g = localB->Product3_m - localB->Product2_h;

          /* Gain: '<S159>/Gain1' */
          localB->Gain1_p = 2.0 * localB->Sum2_g;

          /* Product: '<S159>/Product5' */
          localB->Product5_f = localB->Gain1_p;

          /* Sum: '<S159>/Sum' */
          localB->Sum_oq = (localB->Product8_o + localB->Product4_p) +
            localB->Product5_f;

          /* Product: '<S160>/Product' */
          localB->Product_g = localB->Product1_a * localB->Product2_c;

          /* Product: '<S160>/Product1' */
          localB->Product1_af = localB->Product_e * localB->Product3_e;

          /* Sum: '<S160>/Sum1' */
          localB->Sum1_h = localB->Product_g - localB->Product1_af;

          /* Gain: '<S160>/Gain' */
          localB->Gain_n = 2.0 * localB->Sum1_h;

          /* Product: '<S160>/Product4' */
          localB->Product4_c = 0.0 * localB->Gain_n;

          /* Product: '<S160>/Product6' */
          localB->Product6_p = localB->Product1_a * localB->Product1_a;

          /* Product: '<S160>/Product7' */
          localB->Product7_dp = localB->Product3_e * localB->Product3_e;

          /* Sum: '<S160>/Sum3' incorporates:
           *  Constant: '<S160>/Constant'
           */
          localB->Sum3_m = (0.5 - localB->Product6_p) - localB->Product7_dp;

          /* Gain: '<S160>/Gain2' */
          localB->Gain2_h = 2.0 * localB->Sum3_m;

          /* Product: '<S160>/Product8' */
          localB->Product8_p = localB->Gain2_h * 0.0;

          /* Product: '<S160>/Product2' */
          localB->Product2_k = localB->Product_e * localB->Product1_a;

          /* Product: '<S160>/Product3' */
          localB->Product3_c = localB->Product2_c * localB->Product3_e;

          /* Sum: '<S160>/Sum2' */
          localB->Sum2_e = localB->Product2_k + localB->Product3_c;

          /* Gain: '<S160>/Gain1' */
          localB->Gain1_c = 2.0 * localB->Sum2_e;

          /* Product: '<S160>/Product5' */
          localB->Product5_i = localB->Gain1_c;

          /* Sum: '<S160>/Sum' */
          localB->Sum_i = (localB->Product4_c + localB->Product8_p) +
            localB->Product5_i;

          /* Product: '<S161>/Product' */
          localB->Product_k = localB->Product1_a * localB->Product3_e;

          /* Product: '<S161>/Product1' */
          localB->Product1_m = localB->Product_e * localB->Product2_c;

          /* Sum: '<S161>/Sum1' */
          localB->Sum1_l = localB->Product_k + localB->Product1_m;

          /* Gain: '<S161>/Gain' */
          localB->Gain_k = 2.0 * localB->Sum1_l;

          /* Product: '<S161>/Product4' */
          localB->Product4_i = 0.0 * localB->Gain_k;

          /* Product: '<S161>/Product2' */
          localB->Product2_m = localB->Product_e * localB->Product1_a;

          /* Product: '<S161>/Product3' */
          localB->Product3_p = localB->Product2_c * localB->Product3_e;

          /* Sum: '<S161>/Sum2' */
          localB->Sum2_l = localB->Product3_p - localB->Product2_m;

          /* Gain: '<S161>/Gain1' */
          localB->Gain1_g = 2.0 * localB->Sum2_l;

          /* Product: '<S161>/Product5' */
          localB->Product5_d = localB->Gain1_g * 0.0;

          /* Product: '<S161>/Product6' */
          localB->Product6_i = localB->Product1_a * localB->Product1_a;

          /* Product: '<S161>/Product7' */
          localB->Product7_bn = localB->Product2_c * localB->Product2_c;

          /* Sum: '<S161>/Sum3' incorporates:
           *  Constant: '<S161>/Constant'
           */
          localB->Sum3_g2 = (0.5 - localB->Product6_i) - localB->Product7_bn;

          /* Gain: '<S161>/Gain2' */
          localB->Gain2_m = 2.0 * localB->Sum3_g2;

          /* Product: '<S161>/Product8' */
          localB->Product8_me = localB->Gain2_m;

          /* Sum: '<S161>/Sum' */
          localB->Sum_d = (localB->Product4_i + localB->Product5_d) +
            localB->Product8_me;

          /* SignalConversion generated from: '<S78>/Dot Product2' */
          localB->TmpSignalConversionAtDotProdu_k[0] = localB->Sum_oq;
          localB->TmpSignalConversionAtDotProdu_k[1] = localB->Sum_i;
          localB->TmpSignalConversionAtDotProdu_k[2] = localB->Sum_d;

          /* DotProduct: '<S78>/Dot Product3' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[0];
          tmp_0 = localB->TmpSignalConversionAtDotProdu_k[0];
          uTmp = uTmp_idx_2 * tmp_0;

          /* DotProduct: '<S78>/Dot Product1' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[0];
          tmp_0 = localB->TmpSignalConversionAtDotProduct[0];
          uTmp_idx_0 = uTmp_idx_2;
          tmp_2 = tmp_0;

          /* DotProduct: '<S78>/Dot Product3' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[1];
          tmp_0 = localB->TmpSignalConversionAtDotProdu_k[1];
          uTmp += uTmp_idx_2 * tmp_0;

          /* DotProduct: '<S78>/Dot Product1' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[1];
          tmp_0 = localB->TmpSignalConversionAtDotProduct[1];
          uTmp_idx_1 = uTmp_idx_2;
          tmp_1 = tmp_0;

          /* DotProduct: '<S78>/Dot Product3' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[2];
          tmp_0 = localB->TmpSignalConversionAtDotProdu_k[2];
          uTmp += uTmp_idx_2 * tmp_0;

          /* DotProduct: '<S78>/Dot Product1' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[2];
          tmp_0 = localB->TmpSignalConversionAtDotProduct[2];

          /* DotProduct: '<S78>/Dot Product3' */
          localB->DotProduct3 = uTmp;
          tmp = tmp_2;
          uTmp = uTmp_idx_0;

          /* DotProduct: '<S78>/Dot Product1' */
          uTmp_0 = uTmp * tmp;

          /* DotProduct: '<S78>/Dot Product2' */
          uTmp = localB->TmpSignalConversionAtDotProdu_k[0];
          tmp = localB->TmpSignalConversionAtDotProdu_k[0];
          uTmp_idx_0 = uTmp;
          tmp_2 = tmp;
          tmp = tmp_1;
          uTmp = uTmp_idx_1;

          /* DotProduct: '<S78>/Dot Product1' incorporates:
           *  DotProduct: '<S78>/Dot Product2'
           */
          uTmp_0 += uTmp * tmp;

          /* DotProduct: '<S78>/Dot Product2' */
          uTmp = localB->TmpSignalConversionAtDotProdu_k[1];
          tmp = localB->TmpSignalConversionAtDotProdu_k[1];
          uTmp_idx_1 = uTmp;
          tmp_1 = tmp;
          tmp = tmp_0;
          uTmp = uTmp_idx_2;

          /* DotProduct: '<S78>/Dot Product1' incorporates:
           *  DotProduct: '<S78>/Dot Product2'
           */
          uTmp_0 += uTmp * tmp;

          /* DotProduct: '<S78>/Dot Product2' */
          uTmp = localB->TmpSignalConversionAtDotProdu_k[2];
          tmp = localB->TmpSignalConversionAtDotProdu_k[2];
          uTmp_idx_2 = uTmp;
          tmp_0 = tmp;

          /* DotProduct: '<S78>/Dot Product1' incorporates:
           *  DotProduct: '<S78>/Dot Product2'
           */
          localB->DotProduct1 = uTmp_0;

          /* DotProduct: '<S78>/Dot Product2' */
          uTmp = uTmp_idx_0 * tmp_2;
          uTmp += uTmp_idx_1 * tmp_1;
          uTmp += uTmp_idx_2 * tmp_0;
          localB->DotProduct2 = uTmp;

          /* Product: '<S78>/Divide1' */
          localB->Divide1 = localB->DotProduct1 * localB->DotProduct2;

          /* Sqrt: '<S78>/Sqrt3' */
          localB->Sqrt3 = sqrt(localB->Divide1);

          /* Product: '<S78>/Divide' */
          localB->Divide = localB->DotProduct3 / localB->Sqrt3;

          /* Bias: '<S78>/Bias' */
          localB->Bias = localB->Divide + -1.0;

          /* Abs: '<S78>/Abs' */
          localB->Abs = fabs(localB->Bias);

          /* Bias: '<S78>/Bias1' */
          localB->Bias1 = localB->Divide + 1.0;

          /* Abs: '<S78>/Abs1' */
          localB->Abs1 = fabs(localB->Bias1);

          /* If: '<S78>/If' */
          if (localB->Abs < 1.0E-6) {
            /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem' incorporates:
             *  ActionPort: '<S91>/Action Port'
             */
            asbCubeSatACS_IfActionSubsystem(&localB->Merge_d);

            /* End of Outputs for SubSystem: '<S78>/If Action Subsystem' */
          } else if (localB->Abs1 < 1.0E-6) {
            /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S92>/Action Port'
             */
            asbCubeSatAC_IfActionSubsystem1(&localB->Merge_d);

            /* End of Outputs for SubSystem: '<S78>/If Action Subsystem1' */
          } else {
            /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S93>/Action Port'
             */
            asbCubeSat_IfActionSubsystem2_j(&localB->Merge_d);

            /* End of Outputs for SubSystem: '<S78>/If Action Subsystem2' */
          }

          /* RelationalOperator: '<S79>/Compare' incorporates:
           *  Constant: '<S79>/Constant'
           */
          localB->Compare = (localB->Merge != 0.0);

          /* RelationalOperator: '<S80>/Compare' incorporates:
           *  Constant: '<S80>/Constant'
           */
          localB->Compare_k = (localB->Merge_d != 0.0);

          /* Logic: '<S73>/OR' */
          localB->OR = (localB->Compare || localB->Compare_k);

          /* DotProduct: '<S84>/Dot Product3' */
          tmp_0 = localB->TmpSignalConversionAtDotProduct[0];
          uTmp = 0.0 * tmp_0;

          /* DotProduct: '<S84>/Dot Product2' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[0];
          tmp_0 = localB->TmpSignalConversionAtDotProduct[0];
          uTmp_idx_0 = uTmp_idx_2;
          tmp_2 = tmp_0;

          /* DotProduct: '<S84>/Dot Product3' */
          tmp_0 = localB->TmpSignalConversionAtDotProduct[1];
          uTmp += 0.0 * tmp_0;

          /* DotProduct: '<S84>/Dot Product2' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[1];
          tmp_0 = localB->TmpSignalConversionAtDotProduct[1];
          uTmp_idx_1 = uTmp_idx_2;
          tmp_1 = tmp_0;

          /* DotProduct: '<S84>/Dot Product3' */
          tmp_0 = localB->TmpSignalConversionAtDotProduct[2];
          uTmp += -tmp_0;

          /* DotProduct: '<S84>/Dot Product2' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[2];
          tmp_0 = localB->TmpSignalConversionAtDotProduct[2];

          /* DotProduct: '<S84>/Dot Product3' */
          localB->DotProduct3_g = uTmp;
          tmp = tmp_2;

          /* DotProduct: '<S84>/Dot Product2' */
          uTmp = uTmp_idx_0 * tmp;

          /* DotProduct: '<S111>/Dot Product3' */
          tmp = localB->TmpSignalConversionAtDotProduct[0];
          tmp_2 = tmp;
          tmp = tmp_1;
          uTmp_idx_0 = uTmp_idx_1;

          /* DotProduct: '<S84>/Dot Product2' incorporates:
           *  DotProduct: '<S111>/Dot Product3'
           */
          uTmp += uTmp_idx_0 * tmp;

          /* DotProduct: '<S111>/Dot Product3' */
          tmp = localB->TmpSignalConversionAtDotProduct[1];
          tmp_1 = tmp;
          tmp = tmp_0;
          uTmp_idx_0 = uTmp_idx_2;

          /* DotProduct: '<S84>/Dot Product2' incorporates:
           *  DotProduct: '<S111>/Dot Product3'
           */
          uTmp += uTmp_idx_0 * tmp;

          /* DotProduct: '<S111>/Dot Product3' */
          tmp = localB->TmpSignalConversionAtDotProduct[2];
          tmp_0 = tmp;

          /* DotProduct: '<S84>/Dot Product2' incorporates:
           *  DotProduct: '<S111>/Dot Product3'
           */
          localB->DotProduct2_j = uTmp;

          /* Product: '<S84>/Divide1' */
          localB->Divide1_e = asbCubeSatACS_ConstB.DotProduct1_d *
            localB->DotProduct2_j;

          /* Sqrt: '<S84>/Sqrt3' */
          localB->Sqrt3_n = sqrt(localB->Divide1_e);

          /* Sum: '<S84>/Add2' */
          localB->Add2 = localB->DotProduct3_g + localB->Sqrt3_n;

          /* Product: '<S124>/Product' */
          localB->Product_e5 = localB->Add2 * localB->Add2;
          tmp = tmp_2;

          /* DotProduct: '<S111>/Dot Product3' */
          uTmp = 0.0 * tmp;

          /* DotProduct: '<S111>/Dot Product2' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[0];
          tmp = localB->TmpSignalConversionAtDotProduct[0];
          uTmp_idx_0 = uTmp_idx_2;
          tmp_2 = tmp;
          tmp = tmp_1;

          /* DotProduct: '<S111>/Dot Product3' incorporates:
           *  DotProduct: '<S111>/Dot Product2'
           */
          uTmp += 0.0 * tmp;

          /* DotProduct: '<S111>/Dot Product2' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[1];
          tmp = localB->TmpSignalConversionAtDotProduct[1];
          uTmp_idx_1 = uTmp_idx_2;
          tmp_1 = tmp;
          tmp = tmp_0;

          /* DotProduct: '<S111>/Dot Product3' incorporates:
           *  DotProduct: '<S111>/Dot Product2'
           */
          uTmp += -tmp;

          /* DotProduct: '<S111>/Dot Product2' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[2];
          tmp = localB->TmpSignalConversionAtDotProduct[2];
          tmp_0 = tmp;

          /* DotProduct: '<S111>/Dot Product3' incorporates:
           *  DotProduct: '<S111>/Dot Product2'
           */
          localB->DotProduct3_f = uTmp;

          /* DotProduct: '<S111>/Dot Product2' */
          uTmp = uTmp_idx_0 * tmp_2;
          uTmp += uTmp_idx_1 * tmp_1;
          uTmp += uTmp_idx_2 * tmp_0;
          localB->DotProduct2_f = uTmp;

          /* Product: '<S111>/Divide1' */
          localB->Divide1_n = asbCubeSatACS_ConstB.DotProduct1_m *
            localB->DotProduct2_f;

          /* Sqrt: '<S111>/Sqrt3' */
          localB->Sqrt3_j = sqrt(localB->Divide1_n);

          /* Product: '<S111>/Divide' */
          localB->Divide_d = localB->DotProduct3_f / localB->Sqrt3_j;

          /* Bias: '<S111>/Bias' */
          localB->Bias_i = localB->Divide_d + -1.0;

          /* Abs: '<S111>/Abs' */
          localB->Abs_l = fabs(localB->Bias_i);

          /* Bias: '<S111>/Bias1' */
          localB->Bias1_n = localB->Divide_d + 1.0;

          /* Abs: '<S111>/Abs1' */
          localB->Abs1_n = fabs(localB->Bias1_n);

          /* If: '<S111>/If' */
          if (localB->Abs_l < 1.0E-6) {
            /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem' incorporates:
             *  ActionPort: '<S117>/Action Port'
             */
            asbCubeSatACS_IfActionSubsystem(&localB->Merge_m);

            /* End of Outputs for SubSystem: '<S111>/If Action Subsystem' */
          } else if (localB->Abs1_n < 1.0E-6) {
            /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S118>/Action Port'
             */
            asbCubeSatAC_IfActionSubsystem1(&localB->Merge_m);

            /* End of Outputs for SubSystem: '<S111>/If Action Subsystem1' */
          } else {
            /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S119>/Action Port'
             */
            asbCubeSat_IfActionSubsystem2_j(&localB->Merge_m);

            /* End of Outputs for SubSystem: '<S111>/If Action Subsystem2' */
          }

          /* RelationalOperator: '<S112>/Compare' incorporates:
           *  Constant: '<S112>/Constant'
           */
          localB->Compare_h = (localB->Merge_m != -1.0);

          /* Switch: '<S84>/is 180deg Rot' */
          if (localB->Compare_h) {
            /* Product: '<S116>/j x i' */
            localB->jxi_g = 0.0 * localB->Sum_p;

            /* Product: '<S116>/i x k' */
            localB->ixk_f = 0.0 * localB->Sum_j;

            /* Product: '<S116>/k x j' */
            localB->kxj_d = -localB->Sum_o;

            /* Product: '<S115>/i x j' */
            localB->ixj_k = 0.0 * localB->Sum_o;

            /* Product: '<S115>/k x i' */
            localB->kxi_d = -localB->Sum_p;

            /* Product: '<S115>/j x k' */
            localB->jxk_d = 0.0 * localB->Sum_j;

            /* Sum: '<S110>/Sum' */
            localB->Sum_jb[0] = localB->jxk_d - localB->kxj_d;
            localB->Sum_jb[1] = localB->kxi_d - localB->ixk_f;
            localB->Sum_jb[2] = localB->ixj_k - localB->jxi_g;
            localB->is180degRot[0] = localB->Sum_jb[0];
            localB->is180degRot[1] = localB->Sum_jb[1];
            localB->is180degRot[2] = localB->Sum_jb[2];
          } else {
            localB->is180degRot[0] = asbCubeSatACS_ConstB.Sum[0];
            localB->is180degRot[1] = asbCubeSatACS_ConstB.Sum[1];
            localB->is180degRot[2] = asbCubeSatACS_ConstB.Sum[2];
          }

          /* Product: '<S124>/Product1' */
          localB->Product1_df = localB->is180degRot[0] * localB->is180degRot[0];

          /* Product: '<S124>/Product2' */
          localB->Product2_mt = localB->is180degRot[1] * localB->is180degRot[1];

          /* Product: '<S124>/Product3' */
          localB->Product3_n = localB->is180degRot[2] * localB->is180degRot[2];

          /* Sum: '<S124>/Sum' */
          localB->Sum_c = ((localB->Product_e5 + localB->Product1_df) +
                           localB->Product2_mt) + localB->Product3_n;

          /* Sqrt: '<S123>/sqrt' */
          localB->sqrt_j = sqrt(localB->Sum_c);

          /* Product: '<S114>/Product' */
          localB->Product_c = localB->Add2 / localB->sqrt_j;

          /* Product: '<S114>/Product2' */
          localB->Product2_mn = localB->is180degRot[1] / localB->sqrt_j;

          /* Product: '<S103>/Product' */
          localB->Product_po = localB->Product_c * localB->Product_c;

          /* Product: '<S114>/Product1' */
          localB->Product1_gf = localB->is180degRot[0] / localB->sqrt_j;

          /* Product: '<S103>/Product1' */
          localB->Product1_h = localB->Product1_gf * localB->Product1_gf;

          /* Product: '<S103>/Product2' */
          localB->Product2_o = localB->Product2_mn * localB->Product2_mn;

          /* Product: '<S114>/Product3' */
          localB->Product3_j = localB->is180degRot[2] / localB->sqrt_j;

          /* Product: '<S103>/Product3' */
          localB->Product3_o = localB->Product3_j * localB->Product3_j;

          /* Sum: '<S103>/Sum' */
          localB->Sum_pg = ((localB->Product_po + localB->Product1_h) +
                            localB->Product2_o) + localB->Product3_o;

          /* Sqrt: '<S102>/sqrt' */
          localB->sqrt_om = sqrt(localB->Sum_pg);

          /* Product: '<S98>/Product2' */
          localB->Product2_i = localB->Product2_mn / localB->sqrt_om;

          /* Product: '<S99>/Product6' */
          localB->Product6_f = localB->Product2_i * localB->Product2_i;

          /* Product: '<S98>/Product3' */
          localB->Product3_k = localB->Product3_j / localB->sqrt_om;

          /* Product: '<S99>/Product7' */
          localB->Product7_f = localB->Product3_k * localB->Product3_k;

          /* Sum: '<S99>/Sum3' incorporates:
           *  Constant: '<S99>/Constant'
           */
          localB->Sum3_mb = (0.5 - localB->Product6_f) - localB->Product7_f;

          /* Gain: '<S99>/Gain2' */
          localB->Gain2_d = 2.0 * localB->Sum3_mb;

          /* Product: '<S99>/Product8' */
          localB->Product8_d = asbCubeSatACS_ConstB.Sum_d[0] * localB->Gain2_d;

          /* Product: '<S98>/Product1' */
          localB->Product1_l2 = localB->Product1_gf / localB->sqrt_om;

          /* Product: '<S99>/Product' */
          localB->Product_ks = localB->Product1_l2 * localB->Product2_i;

          /* Product: '<S98>/Product' */
          localB->Product_mm = localB->Product_c / localB->sqrt_om;

          /* Product: '<S99>/Product1' */
          localB->Product1_b = localB->Product_mm * localB->Product3_k;

          /* Sum: '<S99>/Sum1' */
          localB->Sum1_k = localB->Product_ks + localB->Product1_b;

          /* Gain: '<S99>/Gain' */
          localB->Gain_g = 2.0 * localB->Sum1_k;

          /* Product: '<S99>/Product4' */
          localB->Product4_n = localB->Gain_g * asbCubeSatACS_ConstB.Sum_d[1];

          /* Product: '<S99>/Product2' */
          localB->Product2_hp = localB->Product_mm * localB->Product2_i;

          /* Product: '<S99>/Product3' */
          localB->Product3_a = localB->Product1_l2 * localB->Product3_k;

          /* Sum: '<S99>/Sum2' */
          localB->Sum2_lr = localB->Product3_a - localB->Product2_hp;

          /* Gain: '<S99>/Gain1' */
          localB->Gain1_m = 2.0 * localB->Sum2_lr;

          /* Product: '<S99>/Product5' */
          localB->Product5_c = localB->Gain1_m * asbCubeSatACS_ConstB.Sum_d[2];

          /* Sum: '<S99>/Sum' */
          localB->Sum_pp = (localB->Product8_d + localB->Product4_n) +
            localB->Product5_c;

          /* Product: '<S100>/Product' */
          localB->Product_h = localB->Product1_l2 * localB->Product2_i;

          /* Product: '<S100>/Product1' */
          localB->Product1_p = localB->Product_mm * localB->Product3_k;

          /* Sum: '<S100>/Sum1' */
          localB->Sum1_hn = localB->Product_h - localB->Product1_p;

          /* Gain: '<S100>/Gain' */
          localB->Gain_b = 2.0 * localB->Sum1_hn;

          /* Product: '<S100>/Product4' */
          localB->Product4_j = asbCubeSatACS_ConstB.Sum_d[0] * localB->Gain_b;

          /* Product: '<S100>/Product6' */
          localB->Product6_d = localB->Product1_l2 * localB->Product1_l2;

          /* Product: '<S100>/Product7' */
          localB->Product7_l = localB->Product3_k * localB->Product3_k;

          /* Sum: '<S100>/Sum3' incorporates:
           *  Constant: '<S100>/Constant'
           */
          localB->Sum3_k = (0.5 - localB->Product6_d) - localB->Product7_l;

          /* Gain: '<S100>/Gain2' */
          localB->Gain2_f = 2.0 * localB->Sum3_k;

          /* Product: '<S100>/Product8' */
          localB->Product8_h = localB->Gain2_f * asbCubeSatACS_ConstB.Sum_d[1];

          /* Product: '<S100>/Product2' */
          localB->Product2_p = localB->Product_mm * localB->Product1_l2;

          /* Product: '<S100>/Product3' */
          localB->Product3_o3 = localB->Product2_i * localB->Product3_k;

          /* Sum: '<S100>/Sum2' */
          localB->Sum2_d = localB->Product2_p + localB->Product3_o3;

          /* Gain: '<S100>/Gain1' */
          localB->Gain1_l = 2.0 * localB->Sum2_d;

          /* Product: '<S100>/Product5' */
          localB->Product5_j = localB->Gain1_l * asbCubeSatACS_ConstB.Sum_d[2];

          /* Sum: '<S100>/Sum' */
          localB->Sum_e = (localB->Product4_j + localB->Product8_h) +
            localB->Product5_j;

          /* Product: '<S101>/Product' */
          localB->Product_j = localB->Product1_l2 * localB->Product3_k;

          /* Product: '<S101>/Product1' */
          localB->Product1_ly = localB->Product_mm * localB->Product2_i;

          /* Sum: '<S101>/Sum1' */
          localB->Sum1_k2 = localB->Product_j + localB->Product1_ly;

          /* Gain: '<S101>/Gain' */
          localB->Gain_o = 2.0 * localB->Sum1_k2;

          /* Product: '<S101>/Product4' */
          localB->Product4_l = asbCubeSatACS_ConstB.Sum_d[0] * localB->Gain_o;

          /* Product: '<S101>/Product2' */
          localB->Product2_a1 = localB->Product_mm * localB->Product1_l2;

          /* Product: '<S101>/Product3' */
          localB->Product3_j0 = localB->Product2_i * localB->Product3_k;

          /* Sum: '<S101>/Sum2' */
          localB->Sum2_gz = localB->Product3_j0 - localB->Product2_a1;

          /* Gain: '<S101>/Gain1' */
          localB->Gain1_d = 2.0 * localB->Sum2_gz;

          /* Product: '<S101>/Product5' */
          localB->Product5_pr = localB->Gain1_d * asbCubeSatACS_ConstB.Sum_d[1];

          /* Product: '<S101>/Product6' */
          localB->Product6_k = localB->Product1_l2 * localB->Product1_l2;

          /* Product: '<S101>/Product7' */
          localB->Product7_e = localB->Product2_i * localB->Product2_i;

          /* Sum: '<S101>/Sum3' incorporates:
           *  Constant: '<S101>/Constant'
           */
          localB->Sum3_o = (0.5 - localB->Product6_k) - localB->Product7_e;

          /* Gain: '<S101>/Gain2' */
          localB->Gain2_p = 2.0 * localB->Sum3_o;

          /* Product: '<S101>/Product8' */
          localB->Product8_f = localB->Gain2_p * asbCubeSatACS_ConstB.Sum_d[2];

          /* Sum: '<S101>/Sum' */
          localB->Sum_di = (localB->Product4_l + localB->Product5_pr) +
            localB->Product8_f;

          /* SignalConversion generated from: '<S126>/Dot Product1' */
          localB->TmpSignalConversionAtDotProdu_p[0] = localB->Sum_pp;
          localB->TmpSignalConversionAtDotProdu_p[1] = localB->Sum_e;
          localB->TmpSignalConversionAtDotProdu_p[2] = localB->Sum_di;

          /* Product: '<S148>/j x k' */
          localB->jxk = localB->Sum_o * localB->Sum_d;

          /* Product: '<S148>/k x i' */
          localB->kxi = localB->Sum_j * localB->Sum_oq;

          /* Product: '<S148>/i x j' */
          localB->ixj = localB->Sum_p * localB->Sum_i;

          /* Product: '<S149>/k x j' */
          localB->kxj = localB->Sum_j * localB->Sum_i;

          /* Product: '<S149>/i x k' */
          localB->ixk = localB->Sum_p * localB->Sum_d;

          /* Product: '<S149>/j x i' */
          localB->jxi = localB->Sum_o * localB->Sum_oq;

          /* Sum: '<S146>/Sum' */
          localB->Sum_f[0] = localB->jxk - localB->kxj;
          localB->Sum_f[1] = localB->kxi - localB->ixk;
          localB->Sum_f[2] = localB->ixj - localB->jxi;

          /* Product: '<S150>/j x k' */
          localB->jxk_g = localB->Sum_f[1] * localB->Sum_j;

          /* Product: '<S150>/k x i' */
          localB->kxi_f = localB->Sum_f[2] * localB->Sum_p;

          /* Product: '<S150>/i x j' */
          localB->ixj_j = localB->Sum_f[0] * localB->Sum_o;

          /* Product: '<S151>/k x j' */
          localB->kxj_j = localB->Sum_f[2] * localB->Sum_o;

          /* Product: '<S151>/i x k' */
          localB->ixk_p = localB->Sum_f[0] * localB->Sum_j;

          /* Product: '<S151>/j x i' */
          localB->jxi_d = localB->Sum_f[1] * localB->Sum_p;

          /* Sum: '<S147>/Sum' */
          localB->Sum_a[0] = localB->jxk_g - localB->kxj_j;
          localB->Sum_a[1] = localB->kxi_f - localB->ixk_p;
          localB->Sum_a[2] = localB->ixj_j - localB->jxi_d;

          /* Product: '<S109>/Product' */
          localB->Product_lv = localB->Product_c * localB->Product_c;

          /* Product: '<S109>/Product1' */
          localB->Product1_fw = localB->Product1_gf * localB->Product1_gf;

          /* Product: '<S109>/Product2' */
          localB->Product2_ie = localB->Product2_mn * localB->Product2_mn;

          /* Product: '<S109>/Product3' */
          localB->Product3_c5 = localB->Product3_j * localB->Product3_j;

          /* Sum: '<S109>/Sum' */
          localB->Sum_hq = ((localB->Product_lv + localB->Product1_fw) +
                            localB->Product2_ie) + localB->Product3_c5;

          /* Sqrt: '<S108>/sqrt' */
          localB->sqrt_d = sqrt(localB->Sum_hq);

          /* Product: '<S104>/Product2' */
          localB->Product2_b = localB->Product2_mn / localB->sqrt_d;

          /* Product: '<S105>/Product6' */
          localB->Product6_h = localB->Product2_b * localB->Product2_b;

          /* Product: '<S104>/Product3' */
          localB->Product3_nk = localB->Product3_j / localB->sqrt_d;

          /* Product: '<S105>/Product7' */
          localB->Product7_p = localB->Product3_nk * localB->Product3_nk;

          /* Sum: '<S105>/Sum3' incorporates:
           *  Constant: '<S105>/Constant'
           */
          localB->Sum3_h = (0.5 - localB->Product6_h) - localB->Product7_p;

          /* Gain: '<S105>/Gain2' */
          localB->Gain2_j = 2.0 * localB->Sum3_h;

          /* Product: '<S105>/Product8' */
          localB->Product8_b = localB->Sum_a[0] * localB->Gain2_j;

          /* Product: '<S104>/Product1' */
          localB->Product1_e = localB->Product1_gf / localB->sqrt_d;

          /* Product: '<S105>/Product' */
          localB->Product_a = localB->Product1_e * localB->Product2_b;

          /* Product: '<S104>/Product' */
          localB->Product_ji = localB->Product_c / localB->sqrt_d;

          /* Product: '<S105>/Product1' */
          localB->Product1_j = localB->Product_ji * localB->Product3_nk;

          /* Sum: '<S105>/Sum1' */
          localB->Sum1_mh = localB->Product_a + localB->Product1_j;

          /* Gain: '<S105>/Gain' */
          localB->Gain_ms = 2.0 * localB->Sum1_mh;

          /* Product: '<S105>/Product4' */
          localB->Product4_b = localB->Gain_ms * localB->Sum_a[1];

          /* Product: '<S105>/Product2' */
          localB->Product2_ll = localB->Product_ji * localB->Product2_b;

          /* Product: '<S105>/Product3' */
          localB->Product3_ek = localB->Product1_e * localB->Product3_nk;

          /* Sum: '<S105>/Sum2' */
          localB->Sum2_f = localB->Product3_ek - localB->Product2_ll;

          /* Gain: '<S105>/Gain1' */
          localB->Gain1_lz = 2.0 * localB->Sum2_f;

          /* Product: '<S105>/Product5' */
          localB->Product5_fk = localB->Gain1_lz * localB->Sum_a[2];

          /* Sum: '<S105>/Sum' */
          localB->Sum_eb = (localB->Product8_b + localB->Product4_b) +
            localB->Product5_fk;

          /* Product: '<S106>/Product' */
          localB->Product_o = localB->Product1_e * localB->Product2_b;

          /* Product: '<S106>/Product1' */
          localB->Product1_pi = localB->Product_ji * localB->Product3_nk;

          /* Sum: '<S106>/Sum1' */
          localB->Sum1_g = localB->Product_o - localB->Product1_pi;

          /* Gain: '<S106>/Gain' */
          localB->Gain_jv = 2.0 * localB->Sum1_g;

          /* Product: '<S106>/Product4' */
          localB->Product4_e = localB->Sum_a[0] * localB->Gain_jv;

          /* Product: '<S106>/Product6' */
          localB->Product6_fq = localB->Product1_e * localB->Product1_e;

          /* Product: '<S106>/Product7' */
          localB->Product7_c = localB->Product3_nk * localB->Product3_nk;

          /* Sum: '<S106>/Sum3' incorporates:
           *  Constant: '<S106>/Constant'
           */
          localB->Sum3_n = (0.5 - localB->Product6_fq) - localB->Product7_c;

          /* Gain: '<S106>/Gain2' */
          localB->Gain2_o = 2.0 * localB->Sum3_n;

          /* Product: '<S106>/Product8' */
          localB->Product8_bs = localB->Gain2_o * localB->Sum_a[1];

          /* Product: '<S106>/Product2' */
          localB->Product2_g = localB->Product_ji * localB->Product1_e;

          /* Product: '<S106>/Product3' */
          localB->Product3_jj = localB->Product2_b * localB->Product3_nk;

          /* Sum: '<S106>/Sum2' */
          localB->Sum2_dw = localB->Product2_g + localB->Product3_jj;

          /* Gain: '<S106>/Gain1' */
          localB->Gain1_fu = 2.0 * localB->Sum2_dw;

          /* Product: '<S106>/Product5' */
          localB->Product5_g = localB->Gain1_fu * localB->Sum_a[2];

          /* Sum: '<S106>/Sum' */
          localB->Sum_oc = (localB->Product4_e + localB->Product8_bs) +
            localB->Product5_g;

          /* Product: '<S107>/Product' */
          localB->Product_ex = localB->Product1_e * localB->Product3_nk;

          /* Product: '<S107>/Product1' */
          localB->Product1_i = localB->Product_ji * localB->Product2_b;

          /* Sum: '<S107>/Sum1' */
          localB->Sum1_f = localB->Product_ex + localB->Product1_i;

          /* Gain: '<S107>/Gain' */
          localB->Gain_gb = 2.0 * localB->Sum1_f;

          /* Product: '<S107>/Product4' */
          localB->Product4_d = localB->Sum_a[0] * localB->Gain_gb;

          /* Product: '<S107>/Product2' */
          localB->Product2_gk = localB->Product_ji * localB->Product1_e;

          /* Product: '<S107>/Product3' */
          localB->Product3_nl = localB->Product2_b * localB->Product3_nk;

          /* Sum: '<S107>/Sum2' */
          localB->Sum2_fp = localB->Product3_nl - localB->Product2_gk;

          /* Gain: '<S107>/Gain1' */
          localB->Gain1_k = 2.0 * localB->Sum2_fp;

          /* Product: '<S107>/Product5' */
          localB->Product5_e = localB->Gain1_k * localB->Sum_a[1];

          /* Product: '<S107>/Product6' */
          localB->Product6_br = localB->Product1_e * localB->Product1_e;

          /* Product: '<S107>/Product7' */
          localB->Product7_d2 = localB->Product2_b * localB->Product2_b;

          /* Sum: '<S107>/Sum3' incorporates:
           *  Constant: '<S107>/Constant'
           */
          localB->Sum3_f = (0.5 - localB->Product6_br) - localB->Product7_d2;

          /* Gain: '<S107>/Gain2' */
          localB->Gain2_h1 = 2.0 * localB->Sum3_f;

          /* Product: '<S107>/Product8' */
          localB->Product8_c = localB->Gain2_h1 * localB->Sum_a[2];

          /* Sum: '<S107>/Sum' */
          localB->Sum_jt = (localB->Product4_d + localB->Product5_e) +
            localB->Product8_c;

          /* SignalConversion generated from: '<S126>/Dot Product2' */
          localB->TmpSignalConversionAtDotProdu_f[0] = localB->Sum_eb;
          localB->TmpSignalConversionAtDotProdu_f[1] = localB->Sum_oc;
          localB->TmpSignalConversionAtDotProdu_f[2] = localB->Sum_jt;

          /* DotProduct: '<S126>/Dot Product3' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[0];
          tmp_0 = localB->TmpSignalConversionAtDotProdu_f[0];
          uTmp = uTmp_idx_2 * tmp_0;

          /* DotProduct: '<S126>/Dot Product1' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[0];
          tmp_0 = localB->TmpSignalConversionAtDotProdu_p[0];
          uTmp_idx_0 = uTmp_idx_2;
          tmp_2 = tmp_0;

          /* DotProduct: '<S126>/Dot Product3' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[1];
          tmp_0 = localB->TmpSignalConversionAtDotProdu_f[1];
          uTmp += uTmp_idx_2 * tmp_0;

          /* DotProduct: '<S126>/Dot Product1' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[1];
          tmp_0 = localB->TmpSignalConversionAtDotProdu_p[1];
          uTmp_idx_1 = uTmp_idx_2;
          tmp_1 = tmp_0;

          /* DotProduct: '<S126>/Dot Product3' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[2];
          tmp_0 = localB->TmpSignalConversionAtDotProdu_f[2];
          uTmp += uTmp_idx_2 * tmp_0;

          /* DotProduct: '<S126>/Dot Product1' */
          uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[2];
          tmp_0 = localB->TmpSignalConversionAtDotProdu_p[2];

          /* DotProduct: '<S126>/Dot Product3' */
          localB->DotProduct3_n = uTmp;
          tmp = tmp_2;
          uTmp = uTmp_idx_0;

          /* DotProduct: '<S126>/Dot Product1' */
          uTmp_0 = uTmp * tmp;

          /* DotProduct: '<S126>/Dot Product2' */
          uTmp = localB->TmpSignalConversionAtDotProdu_f[0];
          tmp = localB->TmpSignalConversionAtDotProdu_f[0];
          uTmp_idx_0 = uTmp;
          tmp_2 = tmp;
          tmp = tmp_1;
          uTmp = uTmp_idx_1;

          /* DotProduct: '<S126>/Dot Product1' incorporates:
           *  DotProduct: '<S126>/Dot Product2'
           */
          uTmp_0 += uTmp * tmp;

          /* DotProduct: '<S126>/Dot Product2' */
          uTmp = localB->TmpSignalConversionAtDotProdu_f[1];
          tmp = localB->TmpSignalConversionAtDotProdu_f[1];
          uTmp_idx_1 = uTmp;
          tmp_1 = tmp;
          tmp = tmp_0;
          uTmp = uTmp_idx_2;

          /* DotProduct: '<S126>/Dot Product1' incorporates:
           *  DotProduct: '<S126>/Dot Product2'
           */
          uTmp_0 += uTmp * tmp;

          /* DotProduct: '<S126>/Dot Product2' */
          uTmp = localB->TmpSignalConversionAtDotProdu_f[2];
          tmp = localB->TmpSignalConversionAtDotProdu_f[2];
          uTmp_idx_2 = uTmp;
          tmp_0 = tmp;

          /* DotProduct: '<S126>/Dot Product1' incorporates:
           *  DotProduct: '<S126>/Dot Product2'
           */
          localB->DotProduct1_n = uTmp_0;

          /* DotProduct: '<S126>/Dot Product2' */
          uTmp = uTmp_idx_0 * tmp_2;
          uTmp += uTmp_idx_1 * tmp_1;
          uTmp += uTmp_idx_2 * tmp_0;
          localB->DotProduct2_k = uTmp;

          /* Product: '<S126>/Divide1' */
          localB->Divide1_l = localB->DotProduct1_n * localB->DotProduct2_k;

          /* Sqrt: '<S126>/Sqrt3' */
          localB->Sqrt3_j1 = sqrt(localB->Divide1_l);

          /* Product: '<S126>/Divide' */
          localB->Divide_l = localB->DotProduct3_n / localB->Sqrt3_j1;

          /* Bias: '<S126>/Bias' */
          localB->Bias_h = localB->Divide_l + -1.0;

          /* Abs: '<S126>/Abs' */
          localB->Abs_c = fabs(localB->Bias_h);

          /* Bias: '<S126>/Bias1' */
          localB->Bias1_d = localB->Divide_l + 1.0;

          /* Abs: '<S126>/Abs1' */
          localB->Abs1_e = fabs(localB->Bias1_d);

          /* If: '<S126>/If' */
          if (localB->Abs_c < 1.0E-6) {
            /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem' incorporates:
             *  ActionPort: '<S132>/Action Port'
             */
            asbCubeSatACS_IfActionSubsystem(&localB->Merge_c);

            /* End of Outputs for SubSystem: '<S126>/If Action Subsystem' */
          } else if (localB->Abs1_e < 1.0E-6) {
            /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S133>/Action Port'
             */
            asbCubeSatAC_IfActionSubsystem1(&localB->Merge_c);

            /* End of Outputs for SubSystem: '<S126>/If Action Subsystem1' */
          } else {
            /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S134>/Action Port'
             */
            asbCubeSat_IfActionSubsystem2_j(&localB->Merge_c);

            /* End of Outputs for SubSystem: '<S126>/If Action Subsystem2' */
          }

          /* Switch: '<S73>/Switch' incorporates:
           *  DotProduct: '<S85>/Dot Product1'
           *  DotProduct: '<S85>/Dot Product2'
           *  DotProduct: '<S85>/Dot Product3'
           */
          if (localB->OR) {
            localB->Switch[0] = localB->Product_c;
            localB->Switch[1] = localB->Product1_gf;
            localB->Switch[2] = localB->Product2_mn;
            localB->Switch[3] = localB->Product3_j;
          } else {
            /* RelationalOperator: '<S127>/Compare' incorporates:
             *  Constant: '<S127>/Constant'
             */
            localB->Compare_i = (localB->Merge_c != -1.0);

            /* Switch: '<S85>/is 180deg Rot' */
            if (localB->Compare_i) {
              /* Product: '<S131>/j x i' */
              localB->jxi_o = localB->Sum_e * localB->Sum_eb;

              /* Product: '<S131>/i x k' */
              localB->ixk_l = localB->Sum_pp * localB->Sum_jt;

              /* Product: '<S131>/k x j' */
              localB->kxj_b = localB->Sum_di * localB->Sum_oc;

              /* Product: '<S130>/i x j' */
              localB->ixj_f = localB->Sum_pp * localB->Sum_oc;

              /* Product: '<S130>/k x i' */
              localB->kxi_o = localB->Sum_di * localB->Sum_eb;

              /* Product: '<S130>/j x k' */
              localB->jxk_h = localB->Sum_e * localB->Sum_jt;

              /* Sum: '<S125>/Sum' */
              localB->Sum_le[0] = localB->jxk_h - localB->kxj_b;
              localB->Sum_le[1] = localB->kxi_o - localB->ixk_l;
              localB->Sum_le[2] = localB->ixj_f - localB->jxi_o;
              localB->is180degRot_c[0] = localB->Sum_le[0];
              localB->is180degRot_c[1] = localB->Sum_le[1];
              localB->is180degRot_c[2] = localB->Sum_le[2];
            } else {
              /* RelationalOperator: '<S128>/x>z' */
              localB->xz = (localB->Sum_pp > localB->Sum_di);

              /* Switch: '<S128>/Switch3' incorporates:
               *  Constant: '<S128>/Constant'
               *  Constant: '<S128>/Constant1'
               */
              if (localB->xz) {
                /* Gain: '<S128>/Gain' */
                localB->Gain_b2 = -localB->Sum_e;
                localB->Switch3[0] = localB->Gain_b2;
                localB->Switch3[1] = localB->Sum_pp;
                localB->Switch3[2] = 0.0;
              } else {
                /* Gain: '<S128>/Gain2' */
                localB->Gain2_od = -localB->Sum_di;
                localB->Switch3[0] = 0.0;
                localB->Switch3[1] = localB->Gain2_od;
                localB->Switch3[2] = localB->Sum_e;
              }

              /* Product: '<S137>/j x i' */
              localB->jxi_c = localB->Sum_e * localB->Switch3[0];

              /* Product: '<S137>/i x k' */
              localB->ixk_m = localB->Sum_pp * localB->Switch3[2];

              /* Product: '<S137>/k x j' */
              localB->kxj_c = localB->Sum_di * localB->Switch3[1];

              /* Product: '<S136>/i x j' */
              localB->ixj_m = localB->Sum_pp * localB->Switch3[1];

              /* Product: '<S136>/k x i' */
              localB->kxi_dm = localB->Sum_di * localB->Switch3[0];

              /* Product: '<S136>/j x k' */
              localB->jxk_m = localB->Sum_e * localB->Switch3[2];

              /* Sum: '<S135>/Sum' */
              localB->Sum_g[0] = localB->jxk_m - localB->kxj_c;
              localB->Sum_g[1] = localB->kxi_dm - localB->ixk_m;
              localB->Sum_g[2] = localB->ixj_m - localB->jxi_c;
              localB->is180degRot_c[0] = localB->Sum_g[0];
              localB->is180degRot_c[1] = localB->Sum_g[1];
              localB->is180degRot_c[2] = localB->Sum_g[2];
            }

            /* Product: '<S139>/Product3' */
            localB->Product3_mu = localB->is180degRot_c[2] *
              localB->is180degRot_c[2];

            /* Product: '<S139>/Product2' */
            localB->Product2_d = localB->is180degRot_c[1] *
              localB->is180degRot_c[1];

            /* Product: '<S139>/Product1' */
            localB->Product1_fq = localB->is180degRot_c[0] *
              localB->is180degRot_c[0];

            /* DotProduct: '<S85>/Dot Product2' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_f[0];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_f[0];
            uTmp = uTmp_idx_2 * tmp_0;

            /* DotProduct: '<S85>/Dot Product1' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[0];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_p[0];
            uTmp_idx_0 = uTmp_idx_2;
            tmp_2 = tmp_0;

            /* DotProduct: '<S85>/Dot Product2' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_f[1];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_f[1];
            uTmp += uTmp_idx_2 * tmp_0;

            /* DotProduct: '<S85>/Dot Product1' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[1];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_p[1];
            uTmp_idx_1 = uTmp_idx_2;
            tmp_1 = tmp_0;

            /* DotProduct: '<S85>/Dot Product2' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_f[2];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_f[2];
            uTmp += uTmp_idx_2 * tmp_0;

            /* DotProduct: '<S85>/Dot Product1' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[2];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_p[2];

            /* DotProduct: '<S85>/Dot Product2' */
            localB->DotProduct2_b = uTmp;
            tmp = tmp_2;
            uTmp = uTmp_idx_0;

            /* DotProduct: '<S85>/Dot Product1' */
            uTmp_0 = uTmp * tmp;

            /* DotProduct: '<S85>/Dot Product3' */
            uTmp = localB->TmpSignalConversionAtDotProdu_p[0];
            tmp = localB->TmpSignalConversionAtDotProdu_f[0];
            uTmp_idx_0 = uTmp;
            tmp_2 = tmp;
            tmp = tmp_1;
            uTmp = uTmp_idx_1;

            /* DotProduct: '<S85>/Dot Product1' incorporates:
             *  DotProduct: '<S85>/Dot Product3'
             */
            uTmp_0 += uTmp * tmp;

            /* DotProduct: '<S85>/Dot Product3' */
            uTmp = localB->TmpSignalConversionAtDotProdu_p[1];
            tmp = localB->TmpSignalConversionAtDotProdu_f[1];
            uTmp_idx_1 = uTmp;
            tmp_1 = tmp;
            tmp = tmp_0;
            uTmp = uTmp_idx_2;

            /* DotProduct: '<S85>/Dot Product1' incorporates:
             *  DotProduct: '<S85>/Dot Product3'
             */
            uTmp_0 += uTmp * tmp;

            /* DotProduct: '<S85>/Dot Product3' */
            uTmp = localB->TmpSignalConversionAtDotProdu_p[2];
            tmp = localB->TmpSignalConversionAtDotProdu_f[2];
            uTmp_idx_2 = uTmp;
            tmp_0 = tmp;

            /* DotProduct: '<S85>/Dot Product1' incorporates:
             *  DotProduct: '<S85>/Dot Product3'
             */
            localB->DotProduct1_b = uTmp_0;

            /* Product: '<S85>/Divide1' */
            localB->Divide1_m = localB->DotProduct1_b * localB->DotProduct2_b;

            /* Sqrt: '<S85>/Sqrt3' */
            localB->Sqrt3_b = sqrt(localB->Divide1_m);

            /* DotProduct: '<S85>/Dot Product3' */
            uTmp = uTmp_idx_0 * tmp_2;
            uTmp += uTmp_idx_1 * tmp_1;
            uTmp += uTmp_idx_2 * tmp_0;
            localB->DotProduct3_i = uTmp;

            /* Sum: '<S85>/Add2' */
            localB->Add2_a = localB->DotProduct3_i + localB->Sqrt3_b;

            /* Product: '<S139>/Product' */
            localB->Product_mk = localB->Add2_a * localB->Add2_a;

            /* Sum: '<S139>/Sum' */
            localB->Sum_b = ((localB->Product_mk + localB->Product1_fq) +
                             localB->Product2_d) + localB->Product3_mu;

            /* Sqrt: '<S138>/sqrt' */
            localB->sqrt_c = sqrt(localB->Sum_b);

            /* Product: '<S129>/Product3' */
            localB->Product3_mk = localB->is180degRot_c[2] / localB->sqrt_c;

            /* Product: '<S94>/Product3' */
            localB->Product3_i2 = localB->Product3_j * localB->Product3_mk;

            /* Product: '<S129>/Product2' */
            localB->Product2_jr = localB->is180degRot_c[1] / localB->sqrt_c;

            /* Product: '<S94>/Product2' */
            localB->Product2_lv = localB->Product2_mn * localB->Product2_jr;

            /* Product: '<S129>/Product1' */
            localB->Product1_hl = localB->is180degRot_c[0] / localB->sqrt_c;

            /* Product: '<S94>/Product1' */
            localB->Product1_bp = localB->Product1_gf * localB->Product1_hl;

            /* Product: '<S129>/Product' */
            localB->Product_kg = localB->Add2_a / localB->sqrt_c;

            /* Product: '<S94>/Product' */
            localB->Product_bpv = localB->Product_c * localB->Product_kg;

            /* Sum: '<S94>/Sum' */
            localB->Sum_m = ((localB->Product_bpv - localB->Product1_bp) -
                             localB->Product2_lv) - localB->Product3_i2;

            /* Product: '<S95>/Product3' */
            localB->Product3_ee = localB->Product3_j * localB->Product2_jr;

            /* Product: '<S95>/Product2' */
            localB->Product2_o2 = localB->Product2_mn * localB->Product3_mk;

            /* Product: '<S95>/Product1' */
            localB->Product1_ju = localB->Product1_gf * localB->Product_kg;

            /* Product: '<S95>/Product' */
            localB->Product_f = localB->Product_c * localB->Product1_hl;

            /* Sum: '<S95>/Sum' */
            localB->Sum_ei = ((localB->Product_f + localB->Product1_ju) +
                              localB->Product2_o2) - localB->Product3_ee;

            /* Product: '<S96>/Product3' */
            localB->Product3_l = localB->Product3_j * localB->Product1_hl;

            /* Product: '<S96>/Product2' */
            localB->Product2_oq = localB->Product2_mn * localB->Product_kg;

            /* Product: '<S96>/Product1' */
            localB->Product1_f1 = localB->Product1_gf * localB->Product3_mk;

            /* Product: '<S96>/Product' */
            localB->Product_gh = localB->Product_c * localB->Product2_jr;

            /* Sum: '<S96>/Sum' */
            localB->Sum_l = ((localB->Product_gh - localB->Product1_f1) +
                             localB->Product2_oq) + localB->Product3_l;

            /* Product: '<S97>/Product3' */
            localB->Product3_mo = localB->Product3_j * localB->Product_kg;

            /* Product: '<S97>/Product2' */
            localB->Product2_kz = localB->Product2_mn * localB->Product1_hl;

            /* Product: '<S97>/Product1' */
            localB->Product1_mz = localB->Product1_gf * localB->Product2_jr;

            /* Product: '<S97>/Product' */
            localB->Product_eo = localB->Product_c * localB->Product3_mk;

            /* Sum: '<S97>/Sum' */
            localB->Sum_nv = ((localB->Product_eo + localB->Product1_mz) -
                              localB->Product2_kz) + localB->Product3_mo;
            localB->Switch[0] = localB->Sum_m;
            localB->Switch[1] = localB->Sum_ei;
            localB->Switch[2] = localB->Sum_l;
            localB->Switch[3] = localB->Sum_nv;
          }

          /* Product: '<S171>/Product' */
          localB->Product_d = localB->Switch[0] * localB->Switch[0];

          /* Product: '<S171>/Product1' */
          localB->Product1_h4 = localB->Switch[1] * localB->Switch[1];

          /* Product: '<S171>/Product2' */
          localB->Product2_po = localB->Switch[2] * localB->Switch[2];

          /* Product: '<S171>/Product3' */
          localB->Product3_pz = localB->Switch[3] * localB->Switch[3];

          /* Sum: '<S171>/Sum' */
          localB->Sum_aq = ((localB->Product_d + localB->Product1_h4) +
                            localB->Product2_po) + localB->Product3_pz;

          /* Sqrt: '<S170>/sqrt' */
          localB->sqrt_k = sqrt(localB->Sum_aq);

          /* Product: '<S165>/Product' */
          localB->Product_mw = localB->Switch[0] / localB->sqrt_k;

          /* Product: '<S165>/Product1' */
          localB->Product1_lc = localB->Switch[1] / localB->sqrt_k;

          /* Product: '<S165>/Product2' */
          localB->Product2_el = localB->Switch[2] / localB->sqrt_k;

          /* Product: '<S165>/Product3' */
          localB->Product3_e1 = localB->Switch[3] / localB->sqrt_k;

          /* Fcn: '<S76>/fcn3' */
          localB->fcn3 = (localB->Product1_lc * localB->Product3_e1 +
                          localB->Product_mw * localB->Product2_el) * 2.0;

          /* If: '<S166>/If' incorporates:
           *  Constant: '<S167>/Constant'
           *  Constant: '<S168>/Constant'
           */
          if (localB->fcn3 > 1.0) {
            /* Outputs for IfAction SubSystem: '<S166>/If Action Subsystem' incorporates:
             *  ActionPort: '<S167>/Action Port'
             */
            localB->Merge_j = 1.0;

            /* End of Outputs for SubSystem: '<S166>/If Action Subsystem' */
          } else if (localB->fcn3 < -1.0) {
            /* Outputs for IfAction SubSystem: '<S166>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S168>/Action Port'
             */
            localB->Merge_j = 1.0;

            /* End of Outputs for SubSystem: '<S166>/If Action Subsystem1' */
          } else {
            /* Outputs for IfAction SubSystem: '<S166>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S169>/Action Port'
             */
            asbCubeSatAC_IfActionSubsystem2(localB->fcn3, &localB->Merge_j);

            /* End of Outputs for SubSystem: '<S166>/If Action Subsystem2' */
          }

          /* Fcn: '<S76>/fcn1' */
          localB->fcn1 = (localB->Product2_el * localB->Product3_e1 -
                          localB->Product_mw * localB->Product1_lc) * -2.0;

          /* Fcn: '<S76>/fcn2' */
          localB->fcn2 = ((localB->Product_mw * localB->Product_mw -
                           localB->Product1_lc * localB->Product1_lc) -
                          localB->Product2_el * localB->Product2_el) +
            localB->Product3_e1 * localB->Product3_e1;

          /* Trigonometry: '<S164>/Trigonometric Function1' */
          localB->PointingCmd[0] = rt_atan2d_snf(localB->fcn1, localB->fcn2);

          /* Fcn: '<S76>/fcn4' */
          localB->fcn4 = (localB->Product1_lc * localB->Product2_el -
                          localB->Product_mw * localB->Product3_e1) * -2.0;

          /* Fcn: '<S76>/fcn5' */
          localB->fcn5 = ((localB->Product_mw * localB->Product_mw +
                           localB->Product1_lc * localB->Product1_lc) -
                          localB->Product2_el * localB->Product2_el) -
            localB->Product3_e1 * localB->Product3_e1;

          /* Trigonometry: '<S164>/Trigonometric Function3' */
          localB->PointingCmd[2] = rt_atan2d_snf(localB->fcn4, localB->fcn5);

          /* Trigonometry: '<S164>/trigFcn' */
          uTmp = localB->Merge_j;
          if (uTmp > 1.0) {
            uTmp = 1.0;
          } else {
            if (uTmp < -1.0) {
              uTmp = -1.0;
            }
          }

          localB->PointingCmd[1] = asin(uTmp);
        }
        break;

       default:
        /* During 'Transition': '<S3>:52' */
        if (*rtu_AttitudeMode == 1.0) {
          /* Transition: '<S3>:40' */
          localB->ControlMode = 2.0;
          localDW->is_On = asbCubeSatACS_IN_Earth;

          /* Product: '<S19>/j x k' */
          localB->jxk_n = localB->BusConversion_InsertedFor_Point.V_ecef[1] *
            localB->BusConversion_InsertedFor_Point.X_ecef[2];

          /* Product: '<S19>/k x i' */
          localB->kxi_p = localB->BusConversion_InsertedFor_Point.V_ecef[2] *
            localB->BusConversion_InsertedFor_Point.X_ecef[0];

          /* Product: '<S19>/i x j' */
          localB->ixj_k3 = localB->BusConversion_InsertedFor_Point.V_ecef[0] *
            localB->BusConversion_InsertedFor_Point.X_ecef[1];

          /* Product: '<S20>/k x j' */
          localB->kxj_n = localB->BusConversion_InsertedFor_Point.V_ecef[2] *
            localB->BusConversion_InsertedFor_Point.X_ecef[1];

          /* Product: '<S20>/i x k' */
          localB->ixk_k = localB->BusConversion_InsertedFor_Point.V_ecef[0] *
            localB->BusConversion_InsertedFor_Point.X_ecef[2];

          /* Product: '<S20>/j x i' */
          localB->jxi_b = localB->BusConversion_InsertedFor_Point.V_ecef[1] *
            localB->BusConversion_InsertedFor_Point.X_ecef[0];

          /* Sum: '<S12>/Sum' */
          localB->Sum_ou[0] = localB->jxk_n - localB->kxj_n;
          localB->Sum_ou[1] = localB->kxi_p - localB->ixk_k;
          localB->Sum_ou[2] = localB->ixj_k3 - localB->jxi_b;

          /* Gain: '<S7>/z = -r' */
          localB->zr[0] = -localB->BusConversion_InsertedFor_Point.X_ecef[0];
          localB->zr[1] = -localB->BusConversion_InsertedFor_Point.X_ecef[1];
          localB->zr[2] = -localB->BusConversion_InsertedFor_Point.X_ecef[2];

          /* Product: '<S17>/i x j' */
          localB->ixj_i = localB->Sum_ou[0] * localB->zr[1];

          /* Product: '<S17>/j x k' */
          localB->jxk_i = localB->Sum_ou[1] * localB->zr[2];

          /* Product: '<S17>/k x i' */
          localB->kxi_os = localB->Sum_ou[2] * localB->zr[0];

          /* Product: '<S18>/i x k' */
          localB->ixk_g = localB->Sum_ou[0] * localB->zr[2];

          /* Product: '<S18>/j x i' */
          localB->jxi_ok = localB->Sum_ou[1] * localB->zr[0];

          /* Product: '<S18>/k x j' */
          localB->kxj_g = localB->Sum_ou[2] * localB->zr[1];

          /* Sum: '<S11>/Sum' */
          localB->Sum_dv[0] = localB->jxk_i - localB->kxj_g;
          localB->Sum_dv[1] = localB->kxi_os - localB->ixk_g;
          localB->Sum_dv[2] = localB->ixj_i - localB->jxi_ok;

          /* DotProduct: '<S14>/Dot Product' */
          uTmp = localB->Sum_dv[0];
          tmp = localB->Sum_dv[0];
          uTmp_0 = uTmp * tmp;
          uTmp = localB->Sum_dv[1];
          tmp = localB->Sum_dv[1];
          uTmp_0 += uTmp * tmp;
          uTmp = localB->Sum_dv[2];
          tmp = localB->Sum_dv[2];
          uTmp_0 += uTmp * tmp;
          localB->DotProduct = uTmp_0;

          /* Sum: '<S14>/Sum of Elements' */
          uTmp_idx_0 = localB->DotProduct;
          localB->SumofElements = uTmp_idx_0;

          /* Math: '<S14>/Math Function1'
           *
           * About '<S14>/Math Function1':
           *  Operator: sqrt
           */
          uTmp_idx_0 = localB->SumofElements;
          if (uTmp_idx_0 < 0.0) {
            localB->MathFunction1 = -sqrt(fabs(uTmp_idx_0));
          } else {
            localB->MathFunction1 = sqrt(uTmp_idx_0);
          }

          /* Product: '<S14>/Divide' */
          localB->ORFtoECEF[0] = localB->Sum_dv[0] / localB->MathFunction1;

          /* DotProduct: '<S15>/Dot Product' */
          uTmp = localB->Sum_ou[0];
          tmp = localB->Sum_ou[0];
          uTmp_0 = uTmp * tmp;

          /* Product: '<S14>/Divide' */
          localB->ORFtoECEF[1] = localB->Sum_dv[1] / localB->MathFunction1;

          /* DotProduct: '<S15>/Dot Product' */
          uTmp = localB->Sum_ou[1];
          tmp = localB->Sum_ou[1];
          uTmp_0 += uTmp * tmp;

          /* Product: '<S14>/Divide' */
          localB->ORFtoECEF[2] = localB->Sum_dv[2] / localB->MathFunction1;

          /* DotProduct: '<S15>/Dot Product' */
          uTmp = localB->Sum_ou[2];
          tmp = localB->Sum_ou[2];
          uTmp_0 += uTmp * tmp;
          localB->DotProduct_m = uTmp_0;

          /* Sum: '<S15>/Sum of Elements' */
          uTmp_idx_0 = localB->DotProduct_m;
          localB->SumofElements_h = uTmp_idx_0;

          /* Math: '<S15>/Math Function1'
           *
           * About '<S15>/Math Function1':
           *  Operator: sqrt
           */
          uTmp_idx_0 = localB->SumofElements_h;
          if (uTmp_idx_0 < 0.0) {
            localB->MathFunction1_n = -sqrt(fabs(uTmp_idx_0));
          } else {
            localB->MathFunction1_n = sqrt(uTmp_idx_0);
          }

          /* Product: '<S15>/Divide' */
          localB->ORFtoECEF[3] = localB->Sum_ou[0] / localB->MathFunction1_n;

          /* DotProduct: '<S16>/Dot Product' */
          uTmp = localB->zr[0];
          tmp = localB->zr[0];
          uTmp_0 = uTmp * tmp;

          /* Product: '<S15>/Divide' */
          localB->ORFtoECEF[4] = localB->Sum_ou[1] / localB->MathFunction1_n;

          /* DotProduct: '<S16>/Dot Product' */
          uTmp = localB->zr[1];
          tmp = localB->zr[1];
          uTmp_0 += uTmp * tmp;

          /* Product: '<S15>/Divide' */
          localB->ORFtoECEF[5] = localB->Sum_ou[2] / localB->MathFunction1_n;

          /* DotProduct: '<S16>/Dot Product' */
          uTmp = localB->zr[2];
          tmp = localB->zr[2];
          uTmp_0 += uTmp * tmp;
          localB->DotProduct_b = uTmp_0;

          /* Sum: '<S16>/Sum of Elements' */
          uTmp_idx_0 = localB->DotProduct_b;
          localB->SumofElements_g = uTmp_idx_0;

          /* Math: '<S16>/Math Function1'
           *
           * About '<S16>/Math Function1':
           *  Operator: sqrt
           */
          uTmp_idx_0 = localB->SumofElements_g;
          if (uTmp_idx_0 < 0.0) {
            localB->MathFunction1_ni = -sqrt(fabs(uTmp_idx_0));
          } else {
            localB->MathFunction1_ni = sqrt(uTmp_idx_0);
          }

          /* Product: '<S16>/Divide' */
          localB->ORFtoECEF[6] = localB->zr[0] / localB->MathFunction1_ni;
          localB->ORFtoECEF[7] = localB->zr[1] / localB->MathFunction1_ni;
          localB->ORFtoECEF[8] = localB->zr[2] / localB->MathFunction1_ni;

          /* Math: '<S7>/ECEF to ORF' */
          for (i = 0; i < 3; i++) {
            localB->ECEFtoORF[3 * i] = localB->ORFtoECEF[i];
            localB->ECEFtoORF[3 * i + 1] = localB->ORFtoECEF[i + 3];
            localB->ECEFtoORF[3 * i + 2] = localB->ORFtoECEF[i + 6];
          }

          /* Sum: '<S24>/Add' */
          uTmp_idx_0 = localB->ECEFtoORF[0];
          uTmp_idx_1 = localB->ECEFtoORF[4];
          uTmp_idx_2 = localB->ECEFtoORF[8];
          uTmp_idx_0 += uTmp_idx_1;
          uTmp_idx_0 += uTmp_idx_2;
          localB->Add = uTmp_idx_0;

          /* If: '<S13>/If' incorporates:
           *  If: '<S21>/Find Maximum Diagonal Value'
           */
          if (localB->Add > 0.0) {
            /* Outputs for IfAction SubSystem: '<S13>/Positive Trace' incorporates:
             *  ActionPort: '<S22>/Action Port'
             */
            /* Sum: '<S22>/Sum' incorporates:
             *  Constant: '<S22>/Constant'
             */
            localB->Sum_dx = localB->Add + 1.0;

            /* Sqrt: '<S22>/sqrt' */
            localB->sqrt_b = sqrt(localB->Sum_dx);

            /* Gain: '<S22>/Gain' */
            localB->Merge_e[0] = 0.5 * localB->sqrt_b;

            /* Gain: '<S22>/Gain1' */
            localB->Gain1_lg = 2.0 * localB->sqrt_b;

            /* Sum: '<S45>/Add' */
            localB->Add_i5 = localB->ECEFtoORF[7] - localB->ECEFtoORF[5];

            /* Sum: '<S44>/Add' */
            localB->Add_fn = localB->ECEFtoORF[2] - localB->ECEFtoORF[6];

            /* Sum: '<S46>/Add' */
            localB->Add_mp = localB->ECEFtoORF[3] - localB->ECEFtoORF[1];

            /* Product: '<S22>/Product' */
            localB->Merge_e[1] = localB->Add_i5 / localB->Gain1_lg;
            localB->Merge_e[2] = localB->Add_fn / localB->Gain1_lg;
            localB->Merge_e[3] = localB->Add_mp / localB->Gain1_lg;

            /* End of Outputs for SubSystem: '<S13>/Positive Trace' */
          } else {
            /* Outputs for IfAction SubSystem: '<S13>/Negative Trace' incorporates:
             *  ActionPort: '<S21>/Action Port'
             */
            if ((localB->ECEFtoORF[4] > localB->ECEFtoORF[0]) &&
                (localB->ECEFtoORF[4] > localB->ECEFtoORF[8])) {
              /* Outputs for IfAction SubSystem: '<S21>/Maximum Value at DCM(2,2)' incorporates:
               *  ActionPort: '<S26>/Action Port'
               */
              /* If: '<S21>/Find Maximum Diagonal Value' incorporates:
               *  Constant: '<S37>/Constant1'
               *  Constant: '<S38>/Constant'
               *  Gain: '<S26>/Gain'
               *  Gain: '<S26>/Gain1'
               *  Gain: '<S26>/Gain3'
               *  Gain: '<S26>/Gain4'
               *  Product: '<S26>/Product'
               *  Product: '<S37>/Product'
               *  Sqrt: '<S26>/sqrt'
               *  Sum: '<S34>/Add'
               *  Sum: '<S35>/Add'
               *  Sum: '<S36>/Add'
               *  Sum: '<S38>/Add'
               *  Switch: '<S37>/Switch'
               */
              localB->Add_hm = ((localB->ECEFtoORF[4] - localB->ECEFtoORF[0]) -
                                localB->ECEFtoORF[8]) + 1.0;
              localB->sqrt_p = sqrt(localB->Add_hm);
              localB->Merge_e[2] = 0.5 * localB->sqrt_p;
              localB->Add_o = localB->ECEFtoORF[1] + localB->ECEFtoORF[3];
              localB->Add_f = localB->ECEFtoORF[5] + localB->ECEFtoORF[7];
              localB->Add_b4 = localB->ECEFtoORF[2] - localB->ECEFtoORF[6];
              if (localB->sqrt_p != 0.0) {
                localB->Switch_f1[0] = 0.5;
                localB->Switch_f1[1] = localB->sqrt_p;
              } else {
                localB->Switch_f1[0] = 0.0;
                localB->Switch_f1[1] = 1.0;
              }

              localB->Product_jp = localB->Switch_f1[0] / localB->Switch_f1[1];
              localB->Product_oi[0] = localB->Add_o * localB->Product_jp;
              localB->Product_oi[1] = localB->Add_f * localB->Product_jp;
              localB->Product_oi[2] = localB->Add_b4 * localB->Product_jp;
              localB->Merge_e[1] = localB->Product_oi[0];
              localB->Merge_e[3] = localB->Product_oi[1];
              localB->Merge_e[0] = localB->Product_oi[2];

              /* End of Outputs for SubSystem: '<S21>/Maximum Value at DCM(2,2)' */
            } else if (localB->ECEFtoORF[8] > localB->ECEFtoORF[0]) {
              /* Outputs for IfAction SubSystem: '<S21>/Maximum Value at DCM(3,3)' incorporates:
               *  ActionPort: '<S27>/Action Port'
               */
              /* If: '<S21>/Find Maximum Diagonal Value' incorporates:
               *  Constant: '<S42>/Constant1'
               *  Constant: '<S43>/Constant'
               *  Gain: '<S27>/Gain'
               *  Gain: '<S27>/Gain1'
               *  Gain: '<S27>/Gain2'
               *  Gain: '<S27>/Gain3'
               *  Product: '<S27>/Product'
               *  Product: '<S42>/Product'
               *  Sqrt: '<S27>/sqrt'
               *  Sum: '<S39>/Add'
               *  Sum: '<S40>/Add'
               *  Sum: '<S41>/Add'
               *  Sum: '<S43>/Add'
               *  Switch: '<S42>/Switch'
               */
              localB->Add_h = ((localB->ECEFtoORF[8] - localB->ECEFtoORF[0]) -
                               localB->ECEFtoORF[4]) + 1.0;
              localB->sqrt_o2 = sqrt(localB->Add_h);
              localB->Merge_e[3] = 0.5 * localB->sqrt_o2;
              localB->Add_b = localB->ECEFtoORF[2] + localB->ECEFtoORF[6];
              localB->Add_a = localB->ECEFtoORF[5] + localB->ECEFtoORF[7];
              localB->Add_p = localB->ECEFtoORF[3] - localB->ECEFtoORF[1];
              if (localB->sqrt_o2 != 0.0) {
                localB->Switch_o[0] = 0.5;
                localB->Switch_o[1] = localB->sqrt_o2;
              } else {
                localB->Switch_o[0] = 0.0;
                localB->Switch_o[1] = 1.0;
              }

              localB->Product_ph = localB->Switch_o[0] / localB->Switch_o[1];
              localB->Product_oe[0] = localB->Add_b * localB->Product_ph;
              localB->Product_oe[1] = localB->Add_a * localB->Product_ph;
              localB->Product_oe[2] = localB->Add_p * localB->Product_ph;
              localB->Merge_e[1] = localB->Product_oe[0];
              localB->Merge_e[2] = localB->Product_oe[1];
              localB->Merge_e[0] = localB->Product_oe[2];

              /* End of Outputs for SubSystem: '<S21>/Maximum Value at DCM(3,3)' */
            } else {
              /* Outputs for IfAction SubSystem: '<S21>/Maximum Value at DCM(1,1)' incorporates:
               *  ActionPort: '<S25>/Action Port'
               */
              /* If: '<S21>/Find Maximum Diagonal Value' incorporates:
               *  Constant: '<S32>/Constant1'
               *  Constant: '<S33>/Constant'
               *  Gain: '<S25>/Gain'
               *  Gain: '<S25>/Gain1'
               *  Gain: '<S25>/Gain2'
               *  Gain: '<S25>/Gain3'
               *  Product: '<S25>/Product'
               *  Product: '<S32>/Product'
               *  Sqrt: '<S25>/sqrt'
               *  Sum: '<S29>/Add'
               *  Sum: '<S30>/Add'
               *  Sum: '<S31>/Add'
               *  Sum: '<S33>/Add'
               *  Switch: '<S32>/Switch'
               */
              localB->Add_d = ((localB->ECEFtoORF[0] - localB->ECEFtoORF[4]) -
                               localB->ECEFtoORF[8]) + 1.0;
              localB->sqrt_nk = sqrt(localB->Add_d);
              localB->Merge_e[1] = 0.5 * localB->sqrt_nk;
              if (localB->sqrt_nk != 0.0) {
                localB->Switch_f[0] = 0.5;
                localB->Switch_f[1] = localB->sqrt_nk;
              } else {
                localB->Switch_f[0] = 0.0;
                localB->Switch_f[1] = 1.0;
              }

              localB->Product_n4 = localB->Switch_f[0] / localB->Switch_f[1];
              localB->Add_de = localB->ECEFtoORF[1] + localB->ECEFtoORF[3];
              localB->Add_i = localB->ECEFtoORF[2] + localB->ECEFtoORF[6];
              localB->Add_m = localB->ECEFtoORF[7] - localB->ECEFtoORF[5];
              localB->Product_i[0] = localB->Product_n4 * localB->Add_de;
              localB->Product_i[1] = localB->Product_n4 * localB->Add_i;
              localB->Product_i[2] = localB->Product_n4 * localB->Add_m;
              localB->Merge_e[2] = localB->Product_i[0];
              localB->Merge_e[3] = localB->Product_i[1];
              localB->Merge_e[0] = localB->Product_i[2];

              /* End of Outputs for SubSystem: '<S21>/Maximum Value at DCM(1,1)' */
            }

            /* End of Outputs for SubSystem: '<S13>/Negative Trace' */
          }

          /* Product: '<S60>/Product' */
          localB->Product_ky = localB->BusConversion_InsertedFor_Point.q_ecef2b
            [0] * localB->BusConversion_InsertedFor_Point.q_ecef2b[0];

          /* Product: '<S60>/Product1' */
          localB->Product1_li = localB->
            BusConversion_InsertedFor_Point.q_ecef2b[1] *
            localB->BusConversion_InsertedFor_Point.q_ecef2b[1];

          /* Product: '<S60>/Product2' */
          localB->Product2_gb = localB->
            BusConversion_InsertedFor_Point.q_ecef2b[2] *
            localB->BusConversion_InsertedFor_Point.q_ecef2b[2];

          /* Product: '<S60>/Product3' */
          localB->Product3_an = localB->
            BusConversion_InsertedFor_Point.q_ecef2b[3] *
            localB->BusConversion_InsertedFor_Point.q_ecef2b[3];

          /* Sum: '<S60>/Sum' */
          localB->Sum_hk = ((localB->Product_ky + localB->Product1_li) +
                            localB->Product2_gb) + localB->Product3_an;

          /* Product: '<S8>/Divide' */
          localB->Divide_j = localB->BusConversion_InsertedFor_Point.q_ecef2b[0]
            / localB->Sum_hk;

          /* UnaryMinus: '<S59>/Unary Minus' */
          localB->UnaryMinus = -localB->
            BusConversion_InsertedFor_Point.q_ecef2b[1];

          /* Product: '<S8>/Divide1' */
          localB->Divide1_d = localB->UnaryMinus / localB->Sum_hk;

          /* UnaryMinus: '<S59>/Unary Minus1' */
          localB->UnaryMinus1 =
            -localB->BusConversion_InsertedFor_Point.q_ecef2b[2];

          /* Product: '<S8>/Divide2' */
          localB->Divide2 = localB->UnaryMinus1 / localB->Sum_hk;

          /* UnaryMinus: '<S59>/Unary Minus2' */
          localB->UnaryMinus2 =
            -localB->BusConversion_InsertedFor_Point.q_ecef2b[3];

          /* Product: '<S8>/Divide3' */
          localB->Divide3 = localB->UnaryMinus2 / localB->Sum_hk;

          /* Product: '<S61>/Product' */
          localB->Product_pb = localB->Divide_j * localB->Merge_e[0];

          /* Product: '<S61>/Product1' */
          localB->Product1_pg = localB->Divide1_d * localB->Merge_e[1];

          /* Product: '<S61>/Product2' */
          localB->Product2_mw = localB->Divide2 * localB->Merge_e[2];

          /* Product: '<S61>/Product3' */
          localB->Product3_cd = localB->Divide3 * localB->Merge_e[3];

          /* Sum: '<S61>/Sum' */
          localB->Sum_fj = ((localB->Product_pb - localB->Product1_pg) -
                            localB->Product2_mw) - localB->Product3_cd;

          /* Product: '<S62>/Product' */
          localB->Product_la = localB->Divide_j * localB->Merge_e[1];

          /* Product: '<S62>/Product1' */
          localB->Product1_p5 = localB->Divide1_d * localB->Merge_e[0];

          /* Product: '<S62>/Product2' */
          localB->Product2_jd = localB->Divide2 * localB->Merge_e[3];

          /* Product: '<S62>/Product3' */
          localB->Product3_db = localB->Divide3 * localB->Merge_e[2];

          /* Sum: '<S62>/Sum' */
          localB->Sum_c3 = ((localB->Product_la + localB->Product1_p5) +
                            localB->Product2_jd) - localB->Product3_db;

          /* Product: '<S63>/Product' */
          localB->Product_nm = localB->Divide_j * localB->Merge_e[2];

          /* Product: '<S63>/Product1' */
          localB->Product1_o = localB->Divide1_d * localB->Merge_e[3];

          /* Product: '<S63>/Product2' */
          localB->Product2_bn = localB->Divide2 * localB->Merge_e[0];

          /* Product: '<S63>/Product3' */
          localB->Product3_gc = localB->Divide3 * localB->Merge_e[1];

          /* Sum: '<S63>/Sum' */
          localB->Sum_hn = ((localB->Product_nm - localB->Product1_o) +
                            localB->Product2_bn) + localB->Product3_gc;

          /* Product: '<S64>/Product' */
          localB->Product_m0 = localB->Divide_j * localB->Merge_e[3];

          /* Product: '<S64>/Product1' */
          localB->Product1_eo = localB->Divide1_d * localB->Merge_e[2];

          /* Product: '<S64>/Product2' */
          localB->Product2_dz = localB->Divide2 * localB->Merge_e[1];

          /* Product: '<S64>/Product3' */
          localB->Product3_ox = localB->Divide3 * localB->Merge_e[0];

          /* Sum: '<S64>/Sum' */
          localB->Sum_h4 = ((localB->Product_m0 + localB->Product1_eo) -
                            localB->Product2_dz) + localB->Product3_ox;

          /* Product: '<S72>/Product' */
          localB->Product_mx = localB->Sum_fj * localB->Sum_fj;

          /* Product: '<S72>/Product1' */
          localB->Product1_fz = localB->Sum_c3 * localB->Sum_c3;

          /* Product: '<S72>/Product2' */
          localB->Product2_p4 = localB->Sum_hn * localB->Sum_hn;

          /* Product: '<S72>/Product3' */
          localB->Product3_kb = localB->Sum_h4 * localB->Sum_h4;

          /* Sum: '<S72>/Sum' */
          localB->Sum_k = ((localB->Product_mx + localB->Product1_fz) +
                           localB->Product2_p4) + localB->Product3_kb;

          /* Sqrt: '<S71>/sqrt' */
          localB->sqrt_jz = sqrt(localB->Sum_k);

          /* Product: '<S66>/Product' */
          localB->Product_j5 = localB->Sum_fj / localB->sqrt_jz;

          /* Product: '<S66>/Product1' */
          localB->Product1_ik = localB->Sum_c3 / localB->sqrt_jz;

          /* Product: '<S66>/Product2' */
          localB->Product2_ev = localB->Sum_hn / localB->sqrt_jz;

          /* Product: '<S66>/Product3' */
          localB->Product3_f = localB->Sum_h4 / localB->sqrt_jz;

          /* Fcn: '<S10>/fcn3' */
          localB->fcn3_l = (localB->Product1_ik * localB->Product3_f +
                            localB->Product_j5 * localB->Product2_ev) * 2.0;

          /* If: '<S67>/If' incorporates:
           *  Constant: '<S68>/Constant'
           *  Constant: '<S69>/Constant'
           */
          if (localB->fcn3_l > 1.0) {
            /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem' incorporates:
             *  ActionPort: '<S68>/Action Port'
             */
            localB->Merge_cv = 1.0;

            /* End of Outputs for SubSystem: '<S67>/If Action Subsystem' */
          } else if (localB->fcn3_l < -1.0) {
            /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S69>/Action Port'
             */
            localB->Merge_cv = 1.0;

            /* End of Outputs for SubSystem: '<S67>/If Action Subsystem1' */
          } else {
            /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S70>/Action Port'
             */
            asbCubeSatAC_IfActionSubsystem2(localB->fcn3_l, &localB->Merge_cv);

            /* End of Outputs for SubSystem: '<S67>/If Action Subsystem2' */
          }

          /* Fcn: '<S10>/fcn1' */
          localB->fcn1_l = (localB->Product2_ev * localB->Product3_f -
                            localB->Product_j5 * localB->Product1_ik) * -2.0;

          /* Fcn: '<S10>/fcn2' */
          localB->fcn2_k = ((localB->Product_j5 * localB->Product_j5 -
                             localB->Product1_ik * localB->Product1_ik) -
                            localB->Product2_ev * localB->Product2_ev) +
            localB->Product3_f * localB->Product3_f;

          /* Trigonometry: '<S65>/Trigonometric Function1' */
          localB->PointingCmd[0] = rt_atan2d_snf(localB->fcn1_l, localB->fcn2_k);

          /* Fcn: '<S10>/fcn4' */
          localB->fcn4_e = (localB->Product1_ik * localB->Product2_ev -
                            localB->Product_j5 * localB->Product3_f) * -2.0;

          /* Fcn: '<S10>/fcn5' */
          localB->fcn5_p = ((localB->Product_j5 * localB->Product_j5 +
                             localB->Product1_ik * localB->Product1_ik) -
                            localB->Product2_ev * localB->Product2_ev) -
            localB->Product3_f * localB->Product3_f;

          /* Trigonometry: '<S65>/Trigonometric Function3' */
          localB->PointingCmd[2] = rt_atan2d_snf(localB->fcn4_e, localB->fcn5_p);

          /* Trigonometry: '<S65>/trigFcn' */
          uTmp = localB->Merge_cv;
          if (uTmp > 1.0) {
            uTmp = 1.0;
          } else {
            if (uTmp < -1.0) {
              uTmp = -1.0;
            }
          }

          localB->PointingCmd[1] = asin(uTmp);
        } else {
          if (*rtu_AttitudeMode == 2.0) {
            /* Transition: '<S3>:51' */
            localB->ControlMode = 2.0;
            localDW->is_On = asbCubeSatACS_IN_Sun;

            /* If: '<S77>/If' */
            if (asbCubeSatACS_ConstB.Abs < 1.0E-6) {
              /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem' incorporates:
               *  ActionPort: '<S88>/Action Port'
               */
              asbCubeSatACS_IfActionSubsystem(&localB->Merge);

              /* End of Outputs for SubSystem: '<S77>/If Action Subsystem' */
            } else if (asbCubeSatACS_ConstB.Abs1 < 1.0E-6) {
              /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S89>/Action Port'
               */
              asbCubeSatAC_IfActionSubsystem1(&localB->Merge);

              /* End of Outputs for SubSystem: '<S77>/If Action Subsystem1' */
            } else {
              /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S90>/Action Port'
               */
              asbCubeSat_IfActionSubsystem2_j(&localB->Merge);

              /* End of Outputs for SubSystem: '<S77>/If Action Subsystem2' */
            }

            /* Product: '<S157>/Product' */
            localB->Product = localB->BusConversion_InsertedFor_Point.q_eci2b[0]
              * localB->BusConversion_InsertedFor_Point.q_eci2b[0];

            /* Product: '<S157>/Product1' */
            localB->Product1 = localB->BusConversion_InsertedFor_Point.q_eci2b[1]
              * localB->BusConversion_InsertedFor_Point.q_eci2b[1];

            /* Product: '<S157>/Product2' */
            localB->Product2 = localB->BusConversion_InsertedFor_Point.q_eci2b[2]
              * localB->BusConversion_InsertedFor_Point.q_eci2b[2];

            /* Product: '<S157>/Product3' */
            localB->Product3 = localB->BusConversion_InsertedFor_Point.q_eci2b[3]
              * localB->BusConversion_InsertedFor_Point.q_eci2b[3];

            /* Sum: '<S157>/Sum' */
            localB->Sum_n = ((localB->Product + localB->Product1) +
                             localB->Product2) + localB->Product3;

            /* Sqrt: '<S156>/sqrt' */
            localB->sqrt_o = sqrt(localB->Sum_n);

            /* Product: '<S152>/Product2' */
            localB->Product2_f = localB->
              BusConversion_InsertedFor_Point.q_eci2b[2] / localB->sqrt_o;

            /* Product: '<S153>/Product6' */
            localB->Product6 = localB->Product2_f * localB->Product2_f;

            /* Product: '<S152>/Product3' */
            localB->Product3_b = localB->
              BusConversion_InsertedFor_Point.q_eci2b[3] / localB->sqrt_o;

            /* Product: '<S153>/Product7' */
            localB->Product7 = localB->Product3_b * localB->Product3_b;

            /* Sum: '<S153>/Sum3' incorporates:
             *  Constant: '<S153>/Constant'
             */
            localB->Sum3 = (0.5 - localB->Product6) - localB->Product7;

            /* Gain: '<S153>/Gain2' */
            localB->Gain2 = 2.0 * localB->Sum3;

            /* Product: '<S153>/Product8' */
            localB->Product8 = localB->
              BusConversion_InsertedFor_Poi_e.x_sun_eci[0] * localB->Gain2;

            /* Product: '<S152>/Product1' */
            localB->Product1_d = localB->
              BusConversion_InsertedFor_Point.q_eci2b[1] / localB->sqrt_o;

            /* Product: '<S153>/Product' */
            localB->Product_m = localB->Product1_d * localB->Product2_f;

            /* Product: '<S152>/Product' */
            localB->Product_b = localB->BusConversion_InsertedFor_Point.q_eci2b
              [0] / localB->sqrt_o;

            /* Product: '<S153>/Product1' */
            localB->Product1_l = localB->Product_b * localB->Product3_b;

            /* Sum: '<S153>/Sum1' */
            localB->Sum1 = localB->Product_m + localB->Product1_l;

            /* Gain: '<S153>/Gain' */
            localB->Gain = 2.0 * localB->Sum1;

            /* Product: '<S153>/Product4' */
            localB->Product4 = localB->Gain *
              localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[1];

            /* Product: '<S153>/Product2' */
            localB->Product2_e = localB->Product_b * localB->Product2_f;

            /* Product: '<S153>/Product3' */
            localB->Product3_i = localB->Product1_d * localB->Product3_b;

            /* Sum: '<S153>/Sum2' */
            localB->Sum2 = localB->Product3_i - localB->Product2_e;

            /* Gain: '<S153>/Gain1' */
            localB->Gain1 = 2.0 * localB->Sum2;

            /* Product: '<S153>/Product5' */
            localB->Product5 = localB->Gain1 *
              localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[2];

            /* Sum: '<S153>/Sum' */
            localB->Sum_p = (localB->Product8 + localB->Product4) +
              localB->Product5;

            /* Product: '<S154>/Product' */
            localB->Product_l = localB->Product1_d * localB->Product2_f;

            /* Product: '<S154>/Product1' */
            localB->Product1_g = localB->Product_b * localB->Product3_b;

            /* Sum: '<S154>/Sum1' */
            localB->Sum1_m = localB->Product_l - localB->Product1_g;

            /* Gain: '<S154>/Gain' */
            localB->Gain_a = 2.0 * localB->Sum1_m;

            /* Product: '<S154>/Product4' */
            localB->Product4_k =
              localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[0] *
              localB->Gain_a;

            /* Product: '<S154>/Product6' */
            localB->Product6_o = localB->Product1_d * localB->Product1_d;

            /* Product: '<S154>/Product7' */
            localB->Product7_d = localB->Product3_b * localB->Product3_b;

            /* Sum: '<S154>/Sum3' incorporates:
             *  Constant: '<S154>/Constant'
             */
            localB->Sum3_g = (0.5 - localB->Product6_o) - localB->Product7_d;

            /* Gain: '<S154>/Gain2' */
            localB->Gain2_n = 2.0 * localB->Sum3_g;

            /* Product: '<S154>/Product8' */
            localB->Product8_a = localB->Gain2_n *
              localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[1];

            /* Product: '<S154>/Product2' */
            localB->Product2_a = localB->Product_b * localB->Product1_d;

            /* Product: '<S154>/Product3' */
            localB->Product3_h = localB->Product2_f * localB->Product3_b;

            /* Sum: '<S154>/Sum2' */
            localB->Sum2_o = localB->Product2_a + localB->Product3_h;

            /* Gain: '<S154>/Gain1' */
            localB->Gain1_f = 2.0 * localB->Sum2_o;

            /* Product: '<S154>/Product5' */
            localB->Product5_p = localB->Gain1_f *
              localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[2];

            /* Sum: '<S154>/Sum' */
            localB->Sum_o = (localB->Product4_k + localB->Product8_a) +
              localB->Product5_p;

            /* Product: '<S155>/Product' */
            localB->Product_p = localB->Product1_d * localB->Product3_b;

            /* Product: '<S155>/Product1' */
            localB->Product1_dq = localB->Product_b * localB->Product2_f;

            /* Sum: '<S155>/Sum1' */
            localB->Sum1_j = localB->Product_p + localB->Product1_dq;

            /* Gain: '<S155>/Gain' */
            localB->Gain_j = 2.0 * localB->Sum1_j;

            /* Product: '<S155>/Product4' */
            localB->Product4_g =
              localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[0] *
              localB->Gain_j;

            /* Product: '<S155>/Product2' */
            localB->Product2_l = localB->Product_b * localB->Product1_d;

            /* Product: '<S155>/Product3' */
            localB->Product3_g = localB->Product2_f * localB->Product3_b;

            /* Sum: '<S155>/Sum2' */
            localB->Sum2_m = localB->Product3_g - localB->Product2_l;

            /* Gain: '<S155>/Gain1' */
            localB->Gain1_o = 2.0 * localB->Sum2_m;

            /* Product: '<S155>/Product5' */
            localB->Product5_b = localB->Gain1_o *
              localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[1];

            /* Product: '<S155>/Product6' */
            localB->Product6_c = localB->Product1_d * localB->Product1_d;

            /* Product: '<S155>/Product7' */
            localB->Product7_g = localB->Product2_f * localB->Product2_f;

            /* Sum: '<S155>/Sum3' incorporates:
             *  Constant: '<S155>/Constant'
             */
            localB->Sum3_c = (0.5 - localB->Product6_c) - localB->Product7_g;

            /* Gain: '<S155>/Gain2' */
            localB->Gain2_a = 2.0 * localB->Sum3_c;

            /* Product: '<S155>/Product8' */
            localB->Product8_m = localB->Gain2_a *
              localB->BusConversion_InsertedFor_Poi_e.x_sun_eci[2];

            /* Sum: '<S155>/Sum' */
            localB->Sum_j = (localB->Product4_g + localB->Product5_b) +
              localB->Product8_m;

            /* SignalConversion generated from: '<S78>/Dot Product1' */
            localB->TmpSignalConversionAtDotProduct[0] = localB->Sum_p;
            localB->TmpSignalConversionAtDotProduct[1] = localB->Sum_o;
            localB->TmpSignalConversionAtDotProduct[2] = localB->Sum_j;

            /* Product: '<S163>/Product' */
            localB->Product_bp = localB->
              BusConversion_InsertedFor_Point.q_eci2b[0] *
              localB->BusConversion_InsertedFor_Point.q_eci2b[0];

            /* Product: '<S163>/Product1' */
            localB->Product1_f = localB->
              BusConversion_InsertedFor_Point.q_eci2b[1] *
              localB->BusConversion_InsertedFor_Point.q_eci2b[1];

            /* Product: '<S163>/Product2' */
            localB->Product2_j = localB->
              BusConversion_InsertedFor_Point.q_eci2b[2] *
              localB->BusConversion_InsertedFor_Point.q_eci2b[2];

            /* Product: '<S163>/Product3' */
            localB->Product3_d = localB->
              BusConversion_InsertedFor_Point.q_eci2b[3] *
              localB->BusConversion_InsertedFor_Point.q_eci2b[3];

            /* Sum: '<S163>/Sum' */
            localB->Sum_h = ((localB->Product_bp + localB->Product1_f) +
                             localB->Product2_j) + localB->Product3_d;

            /* Sqrt: '<S162>/sqrt' */
            localB->sqrt_n = sqrt(localB->Sum_h);

            /* Product: '<S158>/Product2' */
            localB->Product2_c = localB->
              BusConversion_InsertedFor_Point.q_eci2b[2] / localB->sqrt_n;

            /* Product: '<S159>/Product6' */
            localB->Product6_b = localB->Product2_c * localB->Product2_c;

            /* Product: '<S158>/Product3' */
            localB->Product3_e = localB->
              BusConversion_InsertedFor_Point.q_eci2b[3] / localB->sqrt_n;

            /* Product: '<S159>/Product7' */
            localB->Product7_b = localB->Product3_e * localB->Product3_e;

            /* Sum: '<S159>/Sum3' incorporates:
             *  Constant: '<S159>/Constant'
             */
            localB->Sum3_j = (0.5 - localB->Product6_b) - localB->Product7_b;

            /* Gain: '<S159>/Gain2' */
            localB->Gain2_k = 2.0 * localB->Sum3_j;

            /* Product: '<S159>/Product8' */
            localB->Product8_o = 0.0 * localB->Gain2_k;

            /* Product: '<S158>/Product1' */
            localB->Product1_a = localB->
              BusConversion_InsertedFor_Point.q_eci2b[1] / localB->sqrt_n;

            /* Product: '<S159>/Product' */
            localB->Product_n = localB->Product1_a * localB->Product2_c;

            /* Product: '<S158>/Product' */
            localB->Product_e = localB->BusConversion_InsertedFor_Point.q_eci2b
              [0] / localB->sqrt_n;

            /* Product: '<S159>/Product1' */
            localB->Product1_k = localB->Product_e * localB->Product3_e;

            /* Sum: '<S159>/Sum1' */
            localB->Sum1_n = localB->Product_n + localB->Product1_k;

            /* Gain: '<S159>/Gain' */
            localB->Gain_m = 2.0 * localB->Sum1_n;

            /* Product: '<S159>/Product4' */
            localB->Product4_p = localB->Gain_m * 0.0;

            /* Product: '<S159>/Product2' */
            localB->Product2_h = localB->Product_e * localB->Product2_c;

            /* Product: '<S159>/Product3' */
            localB->Product3_m = localB->Product1_a * localB->Product3_e;

            /* Sum: '<S159>/Sum2' */
            localB->Sum2_g = localB->Product3_m - localB->Product2_h;

            /* Gain: '<S159>/Gain1' */
            localB->Gain1_p = 2.0 * localB->Sum2_g;

            /* Product: '<S159>/Product5' */
            localB->Product5_f = localB->Gain1_p;

            /* Sum: '<S159>/Sum' */
            localB->Sum_oq = (localB->Product8_o + localB->Product4_p) +
              localB->Product5_f;

            /* Product: '<S160>/Product' */
            localB->Product_g = localB->Product1_a * localB->Product2_c;

            /* Product: '<S160>/Product1' */
            localB->Product1_af = localB->Product_e * localB->Product3_e;

            /* Sum: '<S160>/Sum1' */
            localB->Sum1_h = localB->Product_g - localB->Product1_af;

            /* Gain: '<S160>/Gain' */
            localB->Gain_n = 2.0 * localB->Sum1_h;

            /* Product: '<S160>/Product4' */
            localB->Product4_c = 0.0 * localB->Gain_n;

            /* Product: '<S160>/Product6' */
            localB->Product6_p = localB->Product1_a * localB->Product1_a;

            /* Product: '<S160>/Product7' */
            localB->Product7_dp = localB->Product3_e * localB->Product3_e;

            /* Sum: '<S160>/Sum3' incorporates:
             *  Constant: '<S160>/Constant'
             */
            localB->Sum3_m = (0.5 - localB->Product6_p) - localB->Product7_dp;

            /* Gain: '<S160>/Gain2' */
            localB->Gain2_h = 2.0 * localB->Sum3_m;

            /* Product: '<S160>/Product8' */
            localB->Product8_p = localB->Gain2_h * 0.0;

            /* Product: '<S160>/Product2' */
            localB->Product2_k = localB->Product_e * localB->Product1_a;

            /* Product: '<S160>/Product3' */
            localB->Product3_c = localB->Product2_c * localB->Product3_e;

            /* Sum: '<S160>/Sum2' */
            localB->Sum2_e = localB->Product2_k + localB->Product3_c;

            /* Gain: '<S160>/Gain1' */
            localB->Gain1_c = 2.0 * localB->Sum2_e;

            /* Product: '<S160>/Product5' */
            localB->Product5_i = localB->Gain1_c;

            /* Sum: '<S160>/Sum' */
            localB->Sum_i = (localB->Product4_c + localB->Product8_p) +
              localB->Product5_i;

            /* Product: '<S161>/Product' */
            localB->Product_k = localB->Product1_a * localB->Product3_e;

            /* Product: '<S161>/Product1' */
            localB->Product1_m = localB->Product_e * localB->Product2_c;

            /* Sum: '<S161>/Sum1' */
            localB->Sum1_l = localB->Product_k + localB->Product1_m;

            /* Gain: '<S161>/Gain' */
            localB->Gain_k = 2.0 * localB->Sum1_l;

            /* Product: '<S161>/Product4' */
            localB->Product4_i = 0.0 * localB->Gain_k;

            /* Product: '<S161>/Product2' */
            localB->Product2_m = localB->Product_e * localB->Product1_a;

            /* Product: '<S161>/Product3' */
            localB->Product3_p = localB->Product2_c * localB->Product3_e;

            /* Sum: '<S161>/Sum2' */
            localB->Sum2_l = localB->Product3_p - localB->Product2_m;

            /* Gain: '<S161>/Gain1' */
            localB->Gain1_g = 2.0 * localB->Sum2_l;

            /* Product: '<S161>/Product5' */
            localB->Product5_d = localB->Gain1_g * 0.0;

            /* Product: '<S161>/Product6' */
            localB->Product6_i = localB->Product1_a * localB->Product1_a;

            /* Product: '<S161>/Product7' */
            localB->Product7_bn = localB->Product2_c * localB->Product2_c;

            /* Sum: '<S161>/Sum3' incorporates:
             *  Constant: '<S161>/Constant'
             */
            localB->Sum3_g2 = (0.5 - localB->Product6_i) - localB->Product7_bn;

            /* Gain: '<S161>/Gain2' */
            localB->Gain2_m = 2.0 * localB->Sum3_g2;

            /* Product: '<S161>/Product8' */
            localB->Product8_me = localB->Gain2_m;

            /* Sum: '<S161>/Sum' */
            localB->Sum_d = (localB->Product4_i + localB->Product5_d) +
              localB->Product8_me;

            /* SignalConversion generated from: '<S78>/Dot Product2' */
            localB->TmpSignalConversionAtDotProdu_k[0] = localB->Sum_oq;
            localB->TmpSignalConversionAtDotProdu_k[1] = localB->Sum_i;
            localB->TmpSignalConversionAtDotProdu_k[2] = localB->Sum_d;

            /* DotProduct: '<S78>/Dot Product3' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[0];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_k[0];
            uTmp = uTmp_idx_2 * tmp_0;

            /* DotProduct: '<S78>/Dot Product1' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[0];
            tmp_0 = localB->TmpSignalConversionAtDotProduct[0];
            uTmp_idx_0 = uTmp_idx_2;
            tmp_2 = tmp_0;

            /* DotProduct: '<S78>/Dot Product3' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[1];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_k[1];
            uTmp += uTmp_idx_2 * tmp_0;

            /* DotProduct: '<S78>/Dot Product1' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[1];
            tmp_0 = localB->TmpSignalConversionAtDotProduct[1];
            uTmp_idx_1 = uTmp_idx_2;
            tmp_1 = tmp_0;

            /* DotProduct: '<S78>/Dot Product3' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[2];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_k[2];
            uTmp += uTmp_idx_2 * tmp_0;

            /* DotProduct: '<S78>/Dot Product1' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[2];
            tmp_0 = localB->TmpSignalConversionAtDotProduct[2];

            /* DotProduct: '<S78>/Dot Product3' */
            localB->DotProduct3 = uTmp;
            tmp = tmp_2;
            uTmp = uTmp_idx_0;

            /* DotProduct: '<S78>/Dot Product1' */
            uTmp_0 = uTmp * tmp;

            /* DotProduct: '<S78>/Dot Product2' */
            uTmp = localB->TmpSignalConversionAtDotProdu_k[0];
            tmp = localB->TmpSignalConversionAtDotProdu_k[0];
            uTmp_idx_0 = uTmp;
            tmp_2 = tmp;
            tmp = tmp_1;
            uTmp = uTmp_idx_1;

            /* DotProduct: '<S78>/Dot Product1' incorporates:
             *  DotProduct: '<S78>/Dot Product2'
             */
            uTmp_0 += uTmp * tmp;

            /* DotProduct: '<S78>/Dot Product2' */
            uTmp = localB->TmpSignalConversionAtDotProdu_k[1];
            tmp = localB->TmpSignalConversionAtDotProdu_k[1];
            uTmp_idx_1 = uTmp;
            tmp_1 = tmp;
            tmp = tmp_0;
            uTmp = uTmp_idx_2;

            /* DotProduct: '<S78>/Dot Product1' incorporates:
             *  DotProduct: '<S78>/Dot Product2'
             */
            uTmp_0 += uTmp * tmp;

            /* DotProduct: '<S78>/Dot Product2' */
            uTmp = localB->TmpSignalConversionAtDotProdu_k[2];
            tmp = localB->TmpSignalConversionAtDotProdu_k[2];
            uTmp_idx_2 = uTmp;
            tmp_0 = tmp;

            /* DotProduct: '<S78>/Dot Product1' incorporates:
             *  DotProduct: '<S78>/Dot Product2'
             */
            localB->DotProduct1 = uTmp_0;

            /* DotProduct: '<S78>/Dot Product2' */
            uTmp = uTmp_idx_0 * tmp_2;
            uTmp += uTmp_idx_1 * tmp_1;
            uTmp += uTmp_idx_2 * tmp_0;
            localB->DotProduct2 = uTmp;

            /* Product: '<S78>/Divide1' */
            localB->Divide1 = localB->DotProduct1 * localB->DotProduct2;

            /* Sqrt: '<S78>/Sqrt3' */
            localB->Sqrt3 = sqrt(localB->Divide1);

            /* Product: '<S78>/Divide' */
            localB->Divide = localB->DotProduct3 / localB->Sqrt3;

            /* Bias: '<S78>/Bias' */
            localB->Bias = localB->Divide + -1.0;

            /* Abs: '<S78>/Abs' */
            localB->Abs = fabs(localB->Bias);

            /* Bias: '<S78>/Bias1' */
            localB->Bias1 = localB->Divide + 1.0;

            /* Abs: '<S78>/Abs1' */
            localB->Abs1 = fabs(localB->Bias1);

            /* If: '<S78>/If' */
            if (localB->Abs < 1.0E-6) {
              /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem' incorporates:
               *  ActionPort: '<S91>/Action Port'
               */
              asbCubeSatACS_IfActionSubsystem(&localB->Merge_d);

              /* End of Outputs for SubSystem: '<S78>/If Action Subsystem' */
            } else if (localB->Abs1 < 1.0E-6) {
              /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S92>/Action Port'
               */
              asbCubeSatAC_IfActionSubsystem1(&localB->Merge_d);

              /* End of Outputs for SubSystem: '<S78>/If Action Subsystem1' */
            } else {
              /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S93>/Action Port'
               */
              asbCubeSat_IfActionSubsystem2_j(&localB->Merge_d);

              /* End of Outputs for SubSystem: '<S78>/If Action Subsystem2' */
            }

            /* RelationalOperator: '<S79>/Compare' incorporates:
             *  Constant: '<S79>/Constant'
             */
            localB->Compare = (localB->Merge != 0.0);

            /* RelationalOperator: '<S80>/Compare' incorporates:
             *  Constant: '<S80>/Constant'
             */
            localB->Compare_k = (localB->Merge_d != 0.0);

            /* Logic: '<S73>/OR' */
            localB->OR = (localB->Compare || localB->Compare_k);

            /* DotProduct: '<S84>/Dot Product3' */
            tmp_0 = localB->TmpSignalConversionAtDotProduct[0];
            uTmp = 0.0 * tmp_0;

            /* DotProduct: '<S84>/Dot Product2' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[0];
            tmp_0 = localB->TmpSignalConversionAtDotProduct[0];
            uTmp_idx_0 = uTmp_idx_2;
            tmp_2 = tmp_0;

            /* DotProduct: '<S84>/Dot Product3' */
            tmp_0 = localB->TmpSignalConversionAtDotProduct[1];
            uTmp += 0.0 * tmp_0;

            /* DotProduct: '<S84>/Dot Product2' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[1];
            tmp_0 = localB->TmpSignalConversionAtDotProduct[1];
            uTmp_idx_1 = uTmp_idx_2;
            tmp_1 = tmp_0;

            /* DotProduct: '<S84>/Dot Product3' */
            tmp_0 = localB->TmpSignalConversionAtDotProduct[2];
            uTmp += -tmp_0;

            /* DotProduct: '<S84>/Dot Product2' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[2];
            tmp_0 = localB->TmpSignalConversionAtDotProduct[2];

            /* DotProduct: '<S84>/Dot Product3' */
            localB->DotProduct3_g = uTmp;
            tmp = tmp_2;

            /* DotProduct: '<S84>/Dot Product2' */
            uTmp = uTmp_idx_0 * tmp;

            /* DotProduct: '<S111>/Dot Product3' */
            tmp = localB->TmpSignalConversionAtDotProduct[0];
            tmp_2 = tmp;
            tmp = tmp_1;
            uTmp_idx_0 = uTmp_idx_1;

            /* DotProduct: '<S84>/Dot Product2' incorporates:
             *  DotProduct: '<S111>/Dot Product3'
             */
            uTmp += uTmp_idx_0 * tmp;

            /* DotProduct: '<S111>/Dot Product3' */
            tmp = localB->TmpSignalConversionAtDotProduct[1];
            tmp_1 = tmp;
            tmp = tmp_0;
            uTmp_idx_0 = uTmp_idx_2;

            /* DotProduct: '<S84>/Dot Product2' incorporates:
             *  DotProduct: '<S111>/Dot Product3'
             */
            uTmp += uTmp_idx_0 * tmp;

            /* DotProduct: '<S111>/Dot Product3' */
            tmp = localB->TmpSignalConversionAtDotProduct[2];
            tmp_0 = tmp;

            /* DotProduct: '<S84>/Dot Product2' incorporates:
             *  DotProduct: '<S111>/Dot Product3'
             */
            localB->DotProduct2_j = uTmp;

            /* Product: '<S84>/Divide1' */
            localB->Divide1_e = asbCubeSatACS_ConstB.DotProduct1_d *
              localB->DotProduct2_j;

            /* Sqrt: '<S84>/Sqrt3' */
            localB->Sqrt3_n = sqrt(localB->Divide1_e);

            /* Sum: '<S84>/Add2' */
            localB->Add2 = localB->DotProduct3_g + localB->Sqrt3_n;

            /* Product: '<S124>/Product' */
            localB->Product_e5 = localB->Add2 * localB->Add2;
            tmp = tmp_2;

            /* DotProduct: '<S111>/Dot Product3' */
            uTmp = 0.0 * tmp;

            /* DotProduct: '<S111>/Dot Product2' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[0];
            tmp = localB->TmpSignalConversionAtDotProduct[0];
            uTmp_idx_0 = uTmp_idx_2;
            tmp_2 = tmp;
            tmp = tmp_1;

            /* DotProduct: '<S111>/Dot Product3' incorporates:
             *  DotProduct: '<S111>/Dot Product2'
             */
            uTmp += 0.0 * tmp;

            /* DotProduct: '<S111>/Dot Product2' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[1];
            tmp = localB->TmpSignalConversionAtDotProduct[1];
            uTmp_idx_1 = uTmp_idx_2;
            tmp_1 = tmp;
            tmp = tmp_0;

            /* DotProduct: '<S111>/Dot Product3' incorporates:
             *  DotProduct: '<S111>/Dot Product2'
             */
            uTmp += -tmp;

            /* DotProduct: '<S111>/Dot Product2' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProduct[2];
            tmp = localB->TmpSignalConversionAtDotProduct[2];
            tmp_0 = tmp;

            /* DotProduct: '<S111>/Dot Product3' incorporates:
             *  DotProduct: '<S111>/Dot Product2'
             */
            localB->DotProduct3_f = uTmp;

            /* DotProduct: '<S111>/Dot Product2' */
            uTmp = uTmp_idx_0 * tmp_2;
            uTmp += uTmp_idx_1 * tmp_1;
            uTmp += uTmp_idx_2 * tmp_0;
            localB->DotProduct2_f = uTmp;

            /* Product: '<S111>/Divide1' */
            localB->Divide1_n = asbCubeSatACS_ConstB.DotProduct1_m *
              localB->DotProduct2_f;

            /* Sqrt: '<S111>/Sqrt3' */
            localB->Sqrt3_j = sqrt(localB->Divide1_n);

            /* Product: '<S111>/Divide' */
            localB->Divide_d = localB->DotProduct3_f / localB->Sqrt3_j;

            /* Bias: '<S111>/Bias' */
            localB->Bias_i = localB->Divide_d + -1.0;

            /* Abs: '<S111>/Abs' */
            localB->Abs_l = fabs(localB->Bias_i);

            /* Bias: '<S111>/Bias1' */
            localB->Bias1_n = localB->Divide_d + 1.0;

            /* Abs: '<S111>/Abs1' */
            localB->Abs1_n = fabs(localB->Bias1_n);

            /* If: '<S111>/If' */
            if (localB->Abs_l < 1.0E-6) {
              /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem' incorporates:
               *  ActionPort: '<S117>/Action Port'
               */
              asbCubeSatACS_IfActionSubsystem(&localB->Merge_m);

              /* End of Outputs for SubSystem: '<S111>/If Action Subsystem' */
            } else if (localB->Abs1_n < 1.0E-6) {
              /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S118>/Action Port'
               */
              asbCubeSatAC_IfActionSubsystem1(&localB->Merge_m);

              /* End of Outputs for SubSystem: '<S111>/If Action Subsystem1' */
            } else {
              /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S119>/Action Port'
               */
              asbCubeSat_IfActionSubsystem2_j(&localB->Merge_m);

              /* End of Outputs for SubSystem: '<S111>/If Action Subsystem2' */
            }

            /* RelationalOperator: '<S112>/Compare' incorporates:
             *  Constant: '<S112>/Constant'
             */
            localB->Compare_h = (localB->Merge_m != -1.0);

            /* Switch: '<S84>/is 180deg Rot' */
            if (localB->Compare_h) {
              /* Product: '<S116>/j x i' */
              localB->jxi_g = 0.0 * localB->Sum_p;

              /* Product: '<S116>/i x k' */
              localB->ixk_f = 0.0 * localB->Sum_j;

              /* Product: '<S116>/k x j' */
              localB->kxj_d = -localB->Sum_o;

              /* Product: '<S115>/i x j' */
              localB->ixj_k = 0.0 * localB->Sum_o;

              /* Product: '<S115>/k x i' */
              localB->kxi_d = -localB->Sum_p;

              /* Product: '<S115>/j x k' */
              localB->jxk_d = 0.0 * localB->Sum_j;

              /* Sum: '<S110>/Sum' */
              localB->Sum_jb[0] = localB->jxk_d - localB->kxj_d;
              localB->Sum_jb[1] = localB->kxi_d - localB->ixk_f;
              localB->Sum_jb[2] = localB->ixj_k - localB->jxi_g;
              localB->is180degRot[0] = localB->Sum_jb[0];
              localB->is180degRot[1] = localB->Sum_jb[1];
              localB->is180degRot[2] = localB->Sum_jb[2];
            } else {
              localB->is180degRot[0] = asbCubeSatACS_ConstB.Sum[0];
              localB->is180degRot[1] = asbCubeSatACS_ConstB.Sum[1];
              localB->is180degRot[2] = asbCubeSatACS_ConstB.Sum[2];
            }

            /* Product: '<S124>/Product1' */
            localB->Product1_df = localB->is180degRot[0] * localB->is180degRot[0];

            /* Product: '<S124>/Product2' */
            localB->Product2_mt = localB->is180degRot[1] * localB->is180degRot[1];

            /* Product: '<S124>/Product3' */
            localB->Product3_n = localB->is180degRot[2] * localB->is180degRot[2];

            /* Sum: '<S124>/Sum' */
            localB->Sum_c = ((localB->Product_e5 + localB->Product1_df) +
                             localB->Product2_mt) + localB->Product3_n;

            /* Sqrt: '<S123>/sqrt' */
            localB->sqrt_j = sqrt(localB->Sum_c);

            /* Product: '<S114>/Product' */
            localB->Product_c = localB->Add2 / localB->sqrt_j;

            /* Product: '<S114>/Product2' */
            localB->Product2_mn = localB->is180degRot[1] / localB->sqrt_j;

            /* Product: '<S103>/Product' */
            localB->Product_po = localB->Product_c * localB->Product_c;

            /* Product: '<S114>/Product1' */
            localB->Product1_gf = localB->is180degRot[0] / localB->sqrt_j;

            /* Product: '<S103>/Product1' */
            localB->Product1_h = localB->Product1_gf * localB->Product1_gf;

            /* Product: '<S103>/Product2' */
            localB->Product2_o = localB->Product2_mn * localB->Product2_mn;

            /* Product: '<S114>/Product3' */
            localB->Product3_j = localB->is180degRot[2] / localB->sqrt_j;

            /* Product: '<S103>/Product3' */
            localB->Product3_o = localB->Product3_j * localB->Product3_j;

            /* Sum: '<S103>/Sum' */
            localB->Sum_pg = ((localB->Product_po + localB->Product1_h) +
                              localB->Product2_o) + localB->Product3_o;

            /* Sqrt: '<S102>/sqrt' */
            localB->sqrt_om = sqrt(localB->Sum_pg);

            /* Product: '<S98>/Product2' */
            localB->Product2_i = localB->Product2_mn / localB->sqrt_om;

            /* Product: '<S99>/Product6' */
            localB->Product6_f = localB->Product2_i * localB->Product2_i;

            /* Product: '<S98>/Product3' */
            localB->Product3_k = localB->Product3_j / localB->sqrt_om;

            /* Product: '<S99>/Product7' */
            localB->Product7_f = localB->Product3_k * localB->Product3_k;

            /* Sum: '<S99>/Sum3' incorporates:
             *  Constant: '<S99>/Constant'
             */
            localB->Sum3_mb = (0.5 - localB->Product6_f) - localB->Product7_f;

            /* Gain: '<S99>/Gain2' */
            localB->Gain2_d = 2.0 * localB->Sum3_mb;

            /* Product: '<S99>/Product8' */
            localB->Product8_d = asbCubeSatACS_ConstB.Sum_d[0] * localB->Gain2_d;

            /* Product: '<S98>/Product1' */
            localB->Product1_l2 = localB->Product1_gf / localB->sqrt_om;

            /* Product: '<S99>/Product' */
            localB->Product_ks = localB->Product1_l2 * localB->Product2_i;

            /* Product: '<S98>/Product' */
            localB->Product_mm = localB->Product_c / localB->sqrt_om;

            /* Product: '<S99>/Product1' */
            localB->Product1_b = localB->Product_mm * localB->Product3_k;

            /* Sum: '<S99>/Sum1' */
            localB->Sum1_k = localB->Product_ks + localB->Product1_b;

            /* Gain: '<S99>/Gain' */
            localB->Gain_g = 2.0 * localB->Sum1_k;

            /* Product: '<S99>/Product4' */
            localB->Product4_n = localB->Gain_g * asbCubeSatACS_ConstB.Sum_d[1];

            /* Product: '<S99>/Product2' */
            localB->Product2_hp = localB->Product_mm * localB->Product2_i;

            /* Product: '<S99>/Product3' */
            localB->Product3_a = localB->Product1_l2 * localB->Product3_k;

            /* Sum: '<S99>/Sum2' */
            localB->Sum2_lr = localB->Product3_a - localB->Product2_hp;

            /* Gain: '<S99>/Gain1' */
            localB->Gain1_m = 2.0 * localB->Sum2_lr;

            /* Product: '<S99>/Product5' */
            localB->Product5_c = localB->Gain1_m * asbCubeSatACS_ConstB.Sum_d[2];

            /* Sum: '<S99>/Sum' */
            localB->Sum_pp = (localB->Product8_d + localB->Product4_n) +
              localB->Product5_c;

            /* Product: '<S100>/Product' */
            localB->Product_h = localB->Product1_l2 * localB->Product2_i;

            /* Product: '<S100>/Product1' */
            localB->Product1_p = localB->Product_mm * localB->Product3_k;

            /* Sum: '<S100>/Sum1' */
            localB->Sum1_hn = localB->Product_h - localB->Product1_p;

            /* Gain: '<S100>/Gain' */
            localB->Gain_b = 2.0 * localB->Sum1_hn;

            /* Product: '<S100>/Product4' */
            localB->Product4_j = asbCubeSatACS_ConstB.Sum_d[0] * localB->Gain_b;

            /* Product: '<S100>/Product6' */
            localB->Product6_d = localB->Product1_l2 * localB->Product1_l2;

            /* Product: '<S100>/Product7' */
            localB->Product7_l = localB->Product3_k * localB->Product3_k;

            /* Sum: '<S100>/Sum3' incorporates:
             *  Constant: '<S100>/Constant'
             */
            localB->Sum3_k = (0.5 - localB->Product6_d) - localB->Product7_l;

            /* Gain: '<S100>/Gain2' */
            localB->Gain2_f = 2.0 * localB->Sum3_k;

            /* Product: '<S100>/Product8' */
            localB->Product8_h = localB->Gain2_f * asbCubeSatACS_ConstB.Sum_d[1];

            /* Product: '<S100>/Product2' */
            localB->Product2_p = localB->Product_mm * localB->Product1_l2;

            /* Product: '<S100>/Product3' */
            localB->Product3_o3 = localB->Product2_i * localB->Product3_k;

            /* Sum: '<S100>/Sum2' */
            localB->Sum2_d = localB->Product2_p + localB->Product3_o3;

            /* Gain: '<S100>/Gain1' */
            localB->Gain1_l = 2.0 * localB->Sum2_d;

            /* Product: '<S100>/Product5' */
            localB->Product5_j = localB->Gain1_l * asbCubeSatACS_ConstB.Sum_d[2];

            /* Sum: '<S100>/Sum' */
            localB->Sum_e = (localB->Product4_j + localB->Product8_h) +
              localB->Product5_j;

            /* Product: '<S101>/Product' */
            localB->Product_j = localB->Product1_l2 * localB->Product3_k;

            /* Product: '<S101>/Product1' */
            localB->Product1_ly = localB->Product_mm * localB->Product2_i;

            /* Sum: '<S101>/Sum1' */
            localB->Sum1_k2 = localB->Product_j + localB->Product1_ly;

            /* Gain: '<S101>/Gain' */
            localB->Gain_o = 2.0 * localB->Sum1_k2;

            /* Product: '<S101>/Product4' */
            localB->Product4_l = asbCubeSatACS_ConstB.Sum_d[0] * localB->Gain_o;

            /* Product: '<S101>/Product2' */
            localB->Product2_a1 = localB->Product_mm * localB->Product1_l2;

            /* Product: '<S101>/Product3' */
            localB->Product3_j0 = localB->Product2_i * localB->Product3_k;

            /* Sum: '<S101>/Sum2' */
            localB->Sum2_gz = localB->Product3_j0 - localB->Product2_a1;

            /* Gain: '<S101>/Gain1' */
            localB->Gain1_d = 2.0 * localB->Sum2_gz;

            /* Product: '<S101>/Product5' */
            localB->Product5_pr = localB->Gain1_d * asbCubeSatACS_ConstB.Sum_d[1];

            /* Product: '<S101>/Product6' */
            localB->Product6_k = localB->Product1_l2 * localB->Product1_l2;

            /* Product: '<S101>/Product7' */
            localB->Product7_e = localB->Product2_i * localB->Product2_i;

            /* Sum: '<S101>/Sum3' incorporates:
             *  Constant: '<S101>/Constant'
             */
            localB->Sum3_o = (0.5 - localB->Product6_k) - localB->Product7_e;

            /* Gain: '<S101>/Gain2' */
            localB->Gain2_p = 2.0 * localB->Sum3_o;

            /* Product: '<S101>/Product8' */
            localB->Product8_f = localB->Gain2_p * asbCubeSatACS_ConstB.Sum_d[2];

            /* Sum: '<S101>/Sum' */
            localB->Sum_di = (localB->Product4_l + localB->Product5_pr) +
              localB->Product8_f;

            /* SignalConversion generated from: '<S126>/Dot Product1' */
            localB->TmpSignalConversionAtDotProdu_p[0] = localB->Sum_pp;
            localB->TmpSignalConversionAtDotProdu_p[1] = localB->Sum_e;
            localB->TmpSignalConversionAtDotProdu_p[2] = localB->Sum_di;

            /* Product: '<S148>/j x k' */
            localB->jxk = localB->Sum_o * localB->Sum_d;

            /* Product: '<S148>/k x i' */
            localB->kxi = localB->Sum_j * localB->Sum_oq;

            /* Product: '<S148>/i x j' */
            localB->ixj = localB->Sum_p * localB->Sum_i;

            /* Product: '<S149>/k x j' */
            localB->kxj = localB->Sum_j * localB->Sum_i;

            /* Product: '<S149>/i x k' */
            localB->ixk = localB->Sum_p * localB->Sum_d;

            /* Product: '<S149>/j x i' */
            localB->jxi = localB->Sum_o * localB->Sum_oq;

            /* Sum: '<S146>/Sum' */
            localB->Sum_f[0] = localB->jxk - localB->kxj;
            localB->Sum_f[1] = localB->kxi - localB->ixk;
            localB->Sum_f[2] = localB->ixj - localB->jxi;

            /* Product: '<S150>/j x k' */
            localB->jxk_g = localB->Sum_f[1] * localB->Sum_j;

            /* Product: '<S150>/k x i' */
            localB->kxi_f = localB->Sum_f[2] * localB->Sum_p;

            /* Product: '<S150>/i x j' */
            localB->ixj_j = localB->Sum_f[0] * localB->Sum_o;

            /* Product: '<S151>/k x j' */
            localB->kxj_j = localB->Sum_f[2] * localB->Sum_o;

            /* Product: '<S151>/i x k' */
            localB->ixk_p = localB->Sum_f[0] * localB->Sum_j;

            /* Product: '<S151>/j x i' */
            localB->jxi_d = localB->Sum_f[1] * localB->Sum_p;

            /* Sum: '<S147>/Sum' */
            localB->Sum_a[0] = localB->jxk_g - localB->kxj_j;
            localB->Sum_a[1] = localB->kxi_f - localB->ixk_p;
            localB->Sum_a[2] = localB->ixj_j - localB->jxi_d;

            /* Product: '<S109>/Product' */
            localB->Product_lv = localB->Product_c * localB->Product_c;

            /* Product: '<S109>/Product1' */
            localB->Product1_fw = localB->Product1_gf * localB->Product1_gf;

            /* Product: '<S109>/Product2' */
            localB->Product2_ie = localB->Product2_mn * localB->Product2_mn;

            /* Product: '<S109>/Product3' */
            localB->Product3_c5 = localB->Product3_j * localB->Product3_j;

            /* Sum: '<S109>/Sum' */
            localB->Sum_hq = ((localB->Product_lv + localB->Product1_fw) +
                              localB->Product2_ie) + localB->Product3_c5;

            /* Sqrt: '<S108>/sqrt' */
            localB->sqrt_d = sqrt(localB->Sum_hq);

            /* Product: '<S104>/Product2' */
            localB->Product2_b = localB->Product2_mn / localB->sqrt_d;

            /* Product: '<S105>/Product6' */
            localB->Product6_h = localB->Product2_b * localB->Product2_b;

            /* Product: '<S104>/Product3' */
            localB->Product3_nk = localB->Product3_j / localB->sqrt_d;

            /* Product: '<S105>/Product7' */
            localB->Product7_p = localB->Product3_nk * localB->Product3_nk;

            /* Sum: '<S105>/Sum3' incorporates:
             *  Constant: '<S105>/Constant'
             */
            localB->Sum3_h = (0.5 - localB->Product6_h) - localB->Product7_p;

            /* Gain: '<S105>/Gain2' */
            localB->Gain2_j = 2.0 * localB->Sum3_h;

            /* Product: '<S105>/Product8' */
            localB->Product8_b = localB->Sum_a[0] * localB->Gain2_j;

            /* Product: '<S104>/Product1' */
            localB->Product1_e = localB->Product1_gf / localB->sqrt_d;

            /* Product: '<S105>/Product' */
            localB->Product_a = localB->Product1_e * localB->Product2_b;

            /* Product: '<S104>/Product' */
            localB->Product_ji = localB->Product_c / localB->sqrt_d;

            /* Product: '<S105>/Product1' */
            localB->Product1_j = localB->Product_ji * localB->Product3_nk;

            /* Sum: '<S105>/Sum1' */
            localB->Sum1_mh = localB->Product_a + localB->Product1_j;

            /* Gain: '<S105>/Gain' */
            localB->Gain_ms = 2.0 * localB->Sum1_mh;

            /* Product: '<S105>/Product4' */
            localB->Product4_b = localB->Gain_ms * localB->Sum_a[1];

            /* Product: '<S105>/Product2' */
            localB->Product2_ll = localB->Product_ji * localB->Product2_b;

            /* Product: '<S105>/Product3' */
            localB->Product3_ek = localB->Product1_e * localB->Product3_nk;

            /* Sum: '<S105>/Sum2' */
            localB->Sum2_f = localB->Product3_ek - localB->Product2_ll;

            /* Gain: '<S105>/Gain1' */
            localB->Gain1_lz = 2.0 * localB->Sum2_f;

            /* Product: '<S105>/Product5' */
            localB->Product5_fk = localB->Gain1_lz * localB->Sum_a[2];

            /* Sum: '<S105>/Sum' */
            localB->Sum_eb = (localB->Product8_b + localB->Product4_b) +
              localB->Product5_fk;

            /* Product: '<S106>/Product' */
            localB->Product_o = localB->Product1_e * localB->Product2_b;

            /* Product: '<S106>/Product1' */
            localB->Product1_pi = localB->Product_ji * localB->Product3_nk;

            /* Sum: '<S106>/Sum1' */
            localB->Sum1_g = localB->Product_o - localB->Product1_pi;

            /* Gain: '<S106>/Gain' */
            localB->Gain_jv = 2.0 * localB->Sum1_g;

            /* Product: '<S106>/Product4' */
            localB->Product4_e = localB->Sum_a[0] * localB->Gain_jv;

            /* Product: '<S106>/Product6' */
            localB->Product6_fq = localB->Product1_e * localB->Product1_e;

            /* Product: '<S106>/Product7' */
            localB->Product7_c = localB->Product3_nk * localB->Product3_nk;

            /* Sum: '<S106>/Sum3' incorporates:
             *  Constant: '<S106>/Constant'
             */
            localB->Sum3_n = (0.5 - localB->Product6_fq) - localB->Product7_c;

            /* Gain: '<S106>/Gain2' */
            localB->Gain2_o = 2.0 * localB->Sum3_n;

            /* Product: '<S106>/Product8' */
            localB->Product8_bs = localB->Gain2_o * localB->Sum_a[1];

            /* Product: '<S106>/Product2' */
            localB->Product2_g = localB->Product_ji * localB->Product1_e;

            /* Product: '<S106>/Product3' */
            localB->Product3_jj = localB->Product2_b * localB->Product3_nk;

            /* Sum: '<S106>/Sum2' */
            localB->Sum2_dw = localB->Product2_g + localB->Product3_jj;

            /* Gain: '<S106>/Gain1' */
            localB->Gain1_fu = 2.0 * localB->Sum2_dw;

            /* Product: '<S106>/Product5' */
            localB->Product5_g = localB->Gain1_fu * localB->Sum_a[2];

            /* Sum: '<S106>/Sum' */
            localB->Sum_oc = (localB->Product4_e + localB->Product8_bs) +
              localB->Product5_g;

            /* Product: '<S107>/Product' */
            localB->Product_ex = localB->Product1_e * localB->Product3_nk;

            /* Product: '<S107>/Product1' */
            localB->Product1_i = localB->Product_ji * localB->Product2_b;

            /* Sum: '<S107>/Sum1' */
            localB->Sum1_f = localB->Product_ex + localB->Product1_i;

            /* Gain: '<S107>/Gain' */
            localB->Gain_gb = 2.0 * localB->Sum1_f;

            /* Product: '<S107>/Product4' */
            localB->Product4_d = localB->Sum_a[0] * localB->Gain_gb;

            /* Product: '<S107>/Product2' */
            localB->Product2_gk = localB->Product_ji * localB->Product1_e;

            /* Product: '<S107>/Product3' */
            localB->Product3_nl = localB->Product2_b * localB->Product3_nk;

            /* Sum: '<S107>/Sum2' */
            localB->Sum2_fp = localB->Product3_nl - localB->Product2_gk;

            /* Gain: '<S107>/Gain1' */
            localB->Gain1_k = 2.0 * localB->Sum2_fp;

            /* Product: '<S107>/Product5' */
            localB->Product5_e = localB->Gain1_k * localB->Sum_a[1];

            /* Product: '<S107>/Product6' */
            localB->Product6_br = localB->Product1_e * localB->Product1_e;

            /* Product: '<S107>/Product7' */
            localB->Product7_d2 = localB->Product2_b * localB->Product2_b;

            /* Sum: '<S107>/Sum3' incorporates:
             *  Constant: '<S107>/Constant'
             */
            localB->Sum3_f = (0.5 - localB->Product6_br) - localB->Product7_d2;

            /* Gain: '<S107>/Gain2' */
            localB->Gain2_h1 = 2.0 * localB->Sum3_f;

            /* Product: '<S107>/Product8' */
            localB->Product8_c = localB->Gain2_h1 * localB->Sum_a[2];

            /* Sum: '<S107>/Sum' */
            localB->Sum_jt = (localB->Product4_d + localB->Product5_e) +
              localB->Product8_c;

            /* SignalConversion generated from: '<S126>/Dot Product2' */
            localB->TmpSignalConversionAtDotProdu_f[0] = localB->Sum_eb;
            localB->TmpSignalConversionAtDotProdu_f[1] = localB->Sum_oc;
            localB->TmpSignalConversionAtDotProdu_f[2] = localB->Sum_jt;

            /* DotProduct: '<S126>/Dot Product3' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[0];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_f[0];
            uTmp = uTmp_idx_2 * tmp_0;

            /* DotProduct: '<S126>/Dot Product1' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[0];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_p[0];
            uTmp_idx_0 = uTmp_idx_2;
            tmp_2 = tmp_0;

            /* DotProduct: '<S126>/Dot Product3' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[1];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_f[1];
            uTmp += uTmp_idx_2 * tmp_0;

            /* DotProduct: '<S126>/Dot Product1' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[1];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_p[1];
            uTmp_idx_1 = uTmp_idx_2;
            tmp_1 = tmp_0;

            /* DotProduct: '<S126>/Dot Product3' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[2];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_f[2];
            uTmp += uTmp_idx_2 * tmp_0;

            /* DotProduct: '<S126>/Dot Product1' */
            uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[2];
            tmp_0 = localB->TmpSignalConversionAtDotProdu_p[2];

            /* DotProduct: '<S126>/Dot Product3' */
            localB->DotProduct3_n = uTmp;
            tmp = tmp_2;
            uTmp = uTmp_idx_0;

            /* DotProduct: '<S126>/Dot Product1' */
            uTmp_0 = uTmp * tmp;

            /* DotProduct: '<S126>/Dot Product2' */
            uTmp = localB->TmpSignalConversionAtDotProdu_f[0];
            tmp = localB->TmpSignalConversionAtDotProdu_f[0];
            uTmp_idx_0 = uTmp;
            tmp_2 = tmp;
            tmp = tmp_1;
            uTmp = uTmp_idx_1;

            /* DotProduct: '<S126>/Dot Product1' incorporates:
             *  DotProduct: '<S126>/Dot Product2'
             */
            uTmp_0 += uTmp * tmp;

            /* DotProduct: '<S126>/Dot Product2' */
            uTmp = localB->TmpSignalConversionAtDotProdu_f[1];
            tmp = localB->TmpSignalConversionAtDotProdu_f[1];
            uTmp_idx_1 = uTmp;
            tmp_1 = tmp;
            tmp = tmp_0;
            uTmp = uTmp_idx_2;

            /* DotProduct: '<S126>/Dot Product1' incorporates:
             *  DotProduct: '<S126>/Dot Product2'
             */
            uTmp_0 += uTmp * tmp;

            /* DotProduct: '<S126>/Dot Product2' */
            uTmp = localB->TmpSignalConversionAtDotProdu_f[2];
            tmp = localB->TmpSignalConversionAtDotProdu_f[2];
            uTmp_idx_2 = uTmp;
            tmp_0 = tmp;

            /* DotProduct: '<S126>/Dot Product1' incorporates:
             *  DotProduct: '<S126>/Dot Product2'
             */
            localB->DotProduct1_n = uTmp_0;

            /* DotProduct: '<S126>/Dot Product2' */
            uTmp = uTmp_idx_0 * tmp_2;
            uTmp += uTmp_idx_1 * tmp_1;
            uTmp += uTmp_idx_2 * tmp_0;
            localB->DotProduct2_k = uTmp;

            /* Product: '<S126>/Divide1' */
            localB->Divide1_l = localB->DotProduct1_n * localB->DotProduct2_k;

            /* Sqrt: '<S126>/Sqrt3' */
            localB->Sqrt3_j1 = sqrt(localB->Divide1_l);

            /* Product: '<S126>/Divide' */
            localB->Divide_l = localB->DotProduct3_n / localB->Sqrt3_j1;

            /* Bias: '<S126>/Bias' */
            localB->Bias_h = localB->Divide_l + -1.0;

            /* Abs: '<S126>/Abs' */
            localB->Abs_c = fabs(localB->Bias_h);

            /* Bias: '<S126>/Bias1' */
            localB->Bias1_d = localB->Divide_l + 1.0;

            /* Abs: '<S126>/Abs1' */
            localB->Abs1_e = fabs(localB->Bias1_d);

            /* If: '<S126>/If' */
            if (localB->Abs_c < 1.0E-6) {
              /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem' incorporates:
               *  ActionPort: '<S132>/Action Port'
               */
              asbCubeSatACS_IfActionSubsystem(&localB->Merge_c);

              /* End of Outputs for SubSystem: '<S126>/If Action Subsystem' */
            } else if (localB->Abs1_e < 1.0E-6) {
              /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S133>/Action Port'
               */
              asbCubeSatAC_IfActionSubsystem1(&localB->Merge_c);

              /* End of Outputs for SubSystem: '<S126>/If Action Subsystem1' */
            } else {
              /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S134>/Action Port'
               */
              asbCubeSat_IfActionSubsystem2_j(&localB->Merge_c);

              /* End of Outputs for SubSystem: '<S126>/If Action Subsystem2' */
            }

            /* Switch: '<S73>/Switch' incorporates:
             *  DotProduct: '<S85>/Dot Product1'
             *  DotProduct: '<S85>/Dot Product2'
             *  DotProduct: '<S85>/Dot Product3'
             */
            if (localB->OR) {
              localB->Switch[0] = localB->Product_c;
              localB->Switch[1] = localB->Product1_gf;
              localB->Switch[2] = localB->Product2_mn;
              localB->Switch[3] = localB->Product3_j;
            } else {
              /* RelationalOperator: '<S127>/Compare' incorporates:
               *  Constant: '<S127>/Constant'
               */
              localB->Compare_i = (localB->Merge_c != -1.0);

              /* Switch: '<S85>/is 180deg Rot' */
              if (localB->Compare_i) {
                /* Product: '<S131>/j x i' */
                localB->jxi_o = localB->Sum_e * localB->Sum_eb;

                /* Product: '<S131>/i x k' */
                localB->ixk_l = localB->Sum_pp * localB->Sum_jt;

                /* Product: '<S131>/k x j' */
                localB->kxj_b = localB->Sum_di * localB->Sum_oc;

                /* Product: '<S130>/i x j' */
                localB->ixj_f = localB->Sum_pp * localB->Sum_oc;

                /* Product: '<S130>/k x i' */
                localB->kxi_o = localB->Sum_di * localB->Sum_eb;

                /* Product: '<S130>/j x k' */
                localB->jxk_h = localB->Sum_e * localB->Sum_jt;

                /* Sum: '<S125>/Sum' */
                localB->Sum_le[0] = localB->jxk_h - localB->kxj_b;
                localB->Sum_le[1] = localB->kxi_o - localB->ixk_l;
                localB->Sum_le[2] = localB->ixj_f - localB->jxi_o;
                localB->is180degRot_c[0] = localB->Sum_le[0];
                localB->is180degRot_c[1] = localB->Sum_le[1];
                localB->is180degRot_c[2] = localB->Sum_le[2];
              } else {
                /* RelationalOperator: '<S128>/x>z' */
                localB->xz = (localB->Sum_pp > localB->Sum_di);

                /* Switch: '<S128>/Switch3' incorporates:
                 *  Constant: '<S128>/Constant'
                 *  Constant: '<S128>/Constant1'
                 */
                if (localB->xz) {
                  /* Gain: '<S128>/Gain' */
                  localB->Gain_b2 = -localB->Sum_e;
                  localB->Switch3[0] = localB->Gain_b2;
                  localB->Switch3[1] = localB->Sum_pp;
                  localB->Switch3[2] = 0.0;
                } else {
                  /* Gain: '<S128>/Gain2' */
                  localB->Gain2_od = -localB->Sum_di;
                  localB->Switch3[0] = 0.0;
                  localB->Switch3[1] = localB->Gain2_od;
                  localB->Switch3[2] = localB->Sum_e;
                }

                /* Product: '<S137>/j x i' */
                localB->jxi_c = localB->Sum_e * localB->Switch3[0];

                /* Product: '<S137>/i x k' */
                localB->ixk_m = localB->Sum_pp * localB->Switch3[2];

                /* Product: '<S137>/k x j' */
                localB->kxj_c = localB->Sum_di * localB->Switch3[1];

                /* Product: '<S136>/i x j' */
                localB->ixj_m = localB->Sum_pp * localB->Switch3[1];

                /* Product: '<S136>/k x i' */
                localB->kxi_dm = localB->Sum_di * localB->Switch3[0];

                /* Product: '<S136>/j x k' */
                localB->jxk_m = localB->Sum_e * localB->Switch3[2];

                /* Sum: '<S135>/Sum' */
                localB->Sum_g[0] = localB->jxk_m - localB->kxj_c;
                localB->Sum_g[1] = localB->kxi_dm - localB->ixk_m;
                localB->Sum_g[2] = localB->ixj_m - localB->jxi_c;
                localB->is180degRot_c[0] = localB->Sum_g[0];
                localB->is180degRot_c[1] = localB->Sum_g[1];
                localB->is180degRot_c[2] = localB->Sum_g[2];
              }

              /* Product: '<S139>/Product3' */
              localB->Product3_mu = localB->is180degRot_c[2] *
                localB->is180degRot_c[2];

              /* Product: '<S139>/Product2' */
              localB->Product2_d = localB->is180degRot_c[1] *
                localB->is180degRot_c[1];

              /* Product: '<S139>/Product1' */
              localB->Product1_fq = localB->is180degRot_c[0] *
                localB->is180degRot_c[0];

              /* DotProduct: '<S85>/Dot Product2' */
              uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_f[0];
              tmp_0 = localB->TmpSignalConversionAtDotProdu_f[0];
              uTmp = uTmp_idx_2 * tmp_0;

              /* DotProduct: '<S85>/Dot Product1' */
              uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[0];
              tmp_0 = localB->TmpSignalConversionAtDotProdu_p[0];
              uTmp_idx_0 = uTmp_idx_2;
              tmp_2 = tmp_0;

              /* DotProduct: '<S85>/Dot Product2' */
              uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_f[1];
              tmp_0 = localB->TmpSignalConversionAtDotProdu_f[1];
              uTmp += uTmp_idx_2 * tmp_0;

              /* DotProduct: '<S85>/Dot Product1' */
              uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[1];
              tmp_0 = localB->TmpSignalConversionAtDotProdu_p[1];
              uTmp_idx_1 = uTmp_idx_2;
              tmp_1 = tmp_0;

              /* DotProduct: '<S85>/Dot Product2' */
              uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_f[2];
              tmp_0 = localB->TmpSignalConversionAtDotProdu_f[2];
              uTmp += uTmp_idx_2 * tmp_0;

              /* DotProduct: '<S85>/Dot Product1' */
              uTmp_idx_2 = localB->TmpSignalConversionAtDotProdu_p[2];
              tmp_0 = localB->TmpSignalConversionAtDotProdu_p[2];

              /* DotProduct: '<S85>/Dot Product2' */
              localB->DotProduct2_b = uTmp;
              tmp = tmp_2;
              uTmp = uTmp_idx_0;

              /* DotProduct: '<S85>/Dot Product1' */
              uTmp_0 = uTmp * tmp;

              /* DotProduct: '<S85>/Dot Product3' */
              uTmp = localB->TmpSignalConversionAtDotProdu_p[0];
              tmp = localB->TmpSignalConversionAtDotProdu_f[0];
              uTmp_idx_0 = uTmp;
              tmp_2 = tmp;
              tmp = tmp_1;
              uTmp = uTmp_idx_1;

              /* DotProduct: '<S85>/Dot Product1' incorporates:
               *  DotProduct: '<S85>/Dot Product3'
               */
              uTmp_0 += uTmp * tmp;

              /* DotProduct: '<S85>/Dot Product3' */
              uTmp = localB->TmpSignalConversionAtDotProdu_p[1];
              tmp = localB->TmpSignalConversionAtDotProdu_f[1];
              uTmp_idx_1 = uTmp;
              tmp_1 = tmp;
              tmp = tmp_0;
              uTmp = uTmp_idx_2;

              /* DotProduct: '<S85>/Dot Product1' incorporates:
               *  DotProduct: '<S85>/Dot Product3'
               */
              uTmp_0 += uTmp * tmp;

              /* DotProduct: '<S85>/Dot Product3' */
              uTmp = localB->TmpSignalConversionAtDotProdu_p[2];
              tmp = localB->TmpSignalConversionAtDotProdu_f[2];
              uTmp_idx_2 = uTmp;
              tmp_0 = tmp;

              /* DotProduct: '<S85>/Dot Product1' incorporates:
               *  DotProduct: '<S85>/Dot Product3'
               */
              localB->DotProduct1_b = uTmp_0;

              /* Product: '<S85>/Divide1' */
              localB->Divide1_m = localB->DotProduct1_b * localB->DotProduct2_b;

              /* Sqrt: '<S85>/Sqrt3' */
              localB->Sqrt3_b = sqrt(localB->Divide1_m);

              /* DotProduct: '<S85>/Dot Product3' */
              uTmp = uTmp_idx_0 * tmp_2;
              uTmp += uTmp_idx_1 * tmp_1;
              uTmp += uTmp_idx_2 * tmp_0;
              localB->DotProduct3_i = uTmp;

              /* Sum: '<S85>/Add2' */
              localB->Add2_a = localB->DotProduct3_i + localB->Sqrt3_b;

              /* Product: '<S139>/Product' */
              localB->Product_mk = localB->Add2_a * localB->Add2_a;

              /* Sum: '<S139>/Sum' */
              localB->Sum_b = ((localB->Product_mk + localB->Product1_fq) +
                               localB->Product2_d) + localB->Product3_mu;

              /* Sqrt: '<S138>/sqrt' */
              localB->sqrt_c = sqrt(localB->Sum_b);

              /* Product: '<S129>/Product3' */
              localB->Product3_mk = localB->is180degRot_c[2] / localB->sqrt_c;

              /* Product: '<S94>/Product3' */
              localB->Product3_i2 = localB->Product3_j * localB->Product3_mk;

              /* Product: '<S129>/Product2' */
              localB->Product2_jr = localB->is180degRot_c[1] / localB->sqrt_c;

              /* Product: '<S94>/Product2' */
              localB->Product2_lv = localB->Product2_mn * localB->Product2_jr;

              /* Product: '<S129>/Product1' */
              localB->Product1_hl = localB->is180degRot_c[0] / localB->sqrt_c;

              /* Product: '<S94>/Product1' */
              localB->Product1_bp = localB->Product1_gf * localB->Product1_hl;

              /* Product: '<S129>/Product' */
              localB->Product_kg = localB->Add2_a / localB->sqrt_c;

              /* Product: '<S94>/Product' */
              localB->Product_bpv = localB->Product_c * localB->Product_kg;

              /* Sum: '<S94>/Sum' */
              localB->Sum_m = ((localB->Product_bpv - localB->Product1_bp) -
                               localB->Product2_lv) - localB->Product3_i2;

              /* Product: '<S95>/Product3' */
              localB->Product3_ee = localB->Product3_j * localB->Product2_jr;

              /* Product: '<S95>/Product2' */
              localB->Product2_o2 = localB->Product2_mn * localB->Product3_mk;

              /* Product: '<S95>/Product1' */
              localB->Product1_ju = localB->Product1_gf * localB->Product_kg;

              /* Product: '<S95>/Product' */
              localB->Product_f = localB->Product_c * localB->Product1_hl;

              /* Sum: '<S95>/Sum' */
              localB->Sum_ei = ((localB->Product_f + localB->Product1_ju) +
                                localB->Product2_o2) - localB->Product3_ee;

              /* Product: '<S96>/Product3' */
              localB->Product3_l = localB->Product3_j * localB->Product1_hl;

              /* Product: '<S96>/Product2' */
              localB->Product2_oq = localB->Product2_mn * localB->Product_kg;

              /* Product: '<S96>/Product1' */
              localB->Product1_f1 = localB->Product1_gf * localB->Product3_mk;

              /* Product: '<S96>/Product' */
              localB->Product_gh = localB->Product_c * localB->Product2_jr;

              /* Sum: '<S96>/Sum' */
              localB->Sum_l = ((localB->Product_gh - localB->Product1_f1) +
                               localB->Product2_oq) + localB->Product3_l;

              /* Product: '<S97>/Product3' */
              localB->Product3_mo = localB->Product3_j * localB->Product_kg;

              /* Product: '<S97>/Product2' */
              localB->Product2_kz = localB->Product2_mn * localB->Product1_hl;

              /* Product: '<S97>/Product1' */
              localB->Product1_mz = localB->Product1_gf * localB->Product2_jr;

              /* Product: '<S97>/Product' */
              localB->Product_eo = localB->Product_c * localB->Product3_mk;

              /* Sum: '<S97>/Sum' */
              localB->Sum_nv = ((localB->Product_eo + localB->Product1_mz) -
                                localB->Product2_kz) + localB->Product3_mo;
              localB->Switch[0] = localB->Sum_m;
              localB->Switch[1] = localB->Sum_ei;
              localB->Switch[2] = localB->Sum_l;
              localB->Switch[3] = localB->Sum_nv;
            }

            /* Product: '<S171>/Product' */
            localB->Product_d = localB->Switch[0] * localB->Switch[0];

            /* Product: '<S171>/Product1' */
            localB->Product1_h4 = localB->Switch[1] * localB->Switch[1];

            /* Product: '<S171>/Product2' */
            localB->Product2_po = localB->Switch[2] * localB->Switch[2];

            /* Product: '<S171>/Product3' */
            localB->Product3_pz = localB->Switch[3] * localB->Switch[3];

            /* Sum: '<S171>/Sum' */
            localB->Sum_aq = ((localB->Product_d + localB->Product1_h4) +
                              localB->Product2_po) + localB->Product3_pz;

            /* Sqrt: '<S170>/sqrt' */
            localB->sqrt_k = sqrt(localB->Sum_aq);

            /* Product: '<S165>/Product' */
            localB->Product_mw = localB->Switch[0] / localB->sqrt_k;

            /* Product: '<S165>/Product1' */
            localB->Product1_lc = localB->Switch[1] / localB->sqrt_k;

            /* Product: '<S165>/Product2' */
            localB->Product2_el = localB->Switch[2] / localB->sqrt_k;

            /* Product: '<S165>/Product3' */
            localB->Product3_e1 = localB->Switch[3] / localB->sqrt_k;

            /* Fcn: '<S76>/fcn3' */
            localB->fcn3 = (localB->Product1_lc * localB->Product3_e1 +
                            localB->Product_mw * localB->Product2_el) * 2.0;

            /* If: '<S166>/If' incorporates:
             *  Constant: '<S167>/Constant'
             *  Constant: '<S168>/Constant'
             */
            if (localB->fcn3 > 1.0) {
              /* Outputs for IfAction SubSystem: '<S166>/If Action Subsystem' incorporates:
               *  ActionPort: '<S167>/Action Port'
               */
              localB->Merge_j = 1.0;

              /* End of Outputs for SubSystem: '<S166>/If Action Subsystem' */
            } else if (localB->fcn3 < -1.0) {
              /* Outputs for IfAction SubSystem: '<S166>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S168>/Action Port'
               */
              localB->Merge_j = 1.0;

              /* End of Outputs for SubSystem: '<S166>/If Action Subsystem1' */
            } else {
              /* Outputs for IfAction SubSystem: '<S166>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S169>/Action Port'
               */
              asbCubeSatAC_IfActionSubsystem2(localB->fcn3, &localB->Merge_j);

              /* End of Outputs for SubSystem: '<S166>/If Action Subsystem2' */
            }

            /* Fcn: '<S76>/fcn1' */
            localB->fcn1 = (localB->Product2_el * localB->Product3_e1 -
                            localB->Product_mw * localB->Product1_lc) * -2.0;

            /* Fcn: '<S76>/fcn2' */
            localB->fcn2 = ((localB->Product_mw * localB->Product_mw -
                             localB->Product1_lc * localB->Product1_lc) -
                            localB->Product2_el * localB->Product2_el) +
              localB->Product3_e1 * localB->Product3_e1;

            /* Trigonometry: '<S164>/Trigonometric Function1' */
            localB->PointingCmd[0] = rt_atan2d_snf(localB->fcn1, localB->fcn2);

            /* Fcn: '<S76>/fcn4' */
            localB->fcn4 = (localB->Product1_lc * localB->Product2_el -
                            localB->Product_mw * localB->Product3_e1) * -2.0;

            /* Fcn: '<S76>/fcn5' */
            localB->fcn5 = ((localB->Product_mw * localB->Product_mw +
                             localB->Product1_lc * localB->Product1_lc) -
                            localB->Product2_el * localB->Product2_el) -
              localB->Product3_e1 * localB->Product3_e1;

            /* Trigonometry: '<S164>/Trigonometric Function3' */
            localB->PointingCmd[2] = rt_atan2d_snf(localB->fcn4, localB->fcn5);

            /* Trigonometry: '<S164>/trigFcn' */
            uTmp = localB->Merge_j;
            if (uTmp > 1.0) {
              uTmp = 1.0;
            } else {
              if (uTmp < -1.0) {
                uTmp = -1.0;
              }
            }

            localB->PointingCmd[1] = asin(uTmp);
          }
        }
        break;
      }
    }
  }

  /* End of Chart: '<S1>/Pointing Mode Selection' */

  /* BusCreator generated from: '<Root>/Bus Creator' */
  rty_ACSOut->AttitudeError.Roll = localB->PointingCmd[0];
  rty_ACSOut->AttitudeError.Pitch = localB->PointingCmd[1];
  rty_ACSOut->AttitudeError.Yaw = localB->PointingCmd[2];

  /* BusCreator: '<Root>/Bus Creator' */
  rty_ACSOut->NavMode = *rtu_AttitudeMode;

  /* Gain: '<S206>/Proportional Gain' */
  localB->ProportionalGain[0] = 1.0E-5 * localB->PointingCmd[0];

  /* DiscreteIntegrator: '<S201>/Integrator' */
  localB->Integrator[0] = localDW->Integrator_DSTATE[0];

  /* Gain: '<S195>/Derivative Gain' */
  localB->DerivativeGain[0] = 0.01 * localB->PointingCmd[0];

  /* SampleTimeMath: '<S196>/TSamp'
   *
   * About '<S196>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *  Multiplication by K = weightedTsampQuantized is being
   *  done implicitly by changing the scaling of the input signal.
   *  No work needs to be done here.  Downstream blocks may need
   *  to do work to handle the scaling of the output; this happens
   *  automatically.
   */
  localB->TSamp[0] = localB->DerivativeGain[0];

  /* Delay: '<S196>/UD' */
  localB->UD[0] = localDW->UD_DSTATE[0];

  /* Sum: '<S196>/Diff' */
  localB->Diff[0] = localB->TSamp[0] - localB->UD[0];

  /* Sum: '<S210>/Sum' */
  localB->Sum[0] = (localB->ProportionalGain[0] + localB->Integrator[0]) +
    localB->Diff[0];

  /* BusCreator: '<Root>/Bus Creator' */
  rty_ACSOut->TorqueCmds[0] = localB->Sum[0];

  /* Gain: '<S198>/Integral Gain' */
  localB->IntegralGain[0] = 1.0E-10 * localB->PointingCmd[0];

  /* Gain: '<S206>/Proportional Gain' */
  localB->ProportionalGain[1] = 1.0E-5 * localB->PointingCmd[1];

  /* DiscreteIntegrator: '<S201>/Integrator' */
  localB->Integrator[1] = localDW->Integrator_DSTATE[1];

  /* Gain: '<S195>/Derivative Gain' */
  localB->DerivativeGain[1] = 0.01 * localB->PointingCmd[1];

  /* SampleTimeMath: '<S196>/TSamp'
   *
   * About '<S196>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *  Multiplication by K = weightedTsampQuantized is being
   *  done implicitly by changing the scaling of the input signal.
   *  No work needs to be done here.  Downstream blocks may need
   *  to do work to handle the scaling of the output; this happens
   *  automatically.
   */
  localB->TSamp[1] = localB->DerivativeGain[1];

  /* Delay: '<S196>/UD' */
  localB->UD[1] = localDW->UD_DSTATE[1];

  /* Sum: '<S196>/Diff' */
  localB->Diff[1] = localB->TSamp[1] - localB->UD[1];

  /* Sum: '<S210>/Sum' */
  localB->Sum[1] = (localB->ProportionalGain[1] + localB->Integrator[1]) +
    localB->Diff[1];

  /* BusCreator: '<Root>/Bus Creator' */
  rty_ACSOut->TorqueCmds[1] = localB->Sum[1];

  /* Gain: '<S198>/Integral Gain' */
  localB->IntegralGain[1] = 1.0E-10 * localB->PointingCmd[1];

  /* Gain: '<S206>/Proportional Gain' */
  localB->ProportionalGain[2] = 1.0E-5 * localB->PointingCmd[2];

  /* DiscreteIntegrator: '<S201>/Integrator' */
  localB->Integrator[2] = localDW->Integrator_DSTATE[2];

  /* Gain: '<S195>/Derivative Gain' */
  localB->DerivativeGain[2] = 0.01 * localB->PointingCmd[2];

  /* SampleTimeMath: '<S196>/TSamp'
   *
   * About '<S196>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *  Multiplication by K = weightedTsampQuantized is being
   *  done implicitly by changing the scaling of the input signal.
   *  No work needs to be done here.  Downstream blocks may need
   *  to do work to handle the scaling of the output; this happens
   *  automatically.
   */
  localB->TSamp[2] = localB->DerivativeGain[2];

  /* Delay: '<S196>/UD' */
  localB->UD[2] = localDW->UD_DSTATE[2];

  /* Sum: '<S196>/Diff' */
  localB->Diff[2] = localB->TSamp[2] - localB->UD[2];

  /* Sum: '<S210>/Sum' */
  localB->Sum[2] = (localB->ProportionalGain[2] + localB->Integrator[2]) +
    localB->Diff[2];

  /* BusCreator: '<Root>/Bus Creator' */
  rty_ACSOut->TorqueCmds[2] = localB->Sum[2];

  /* Gain: '<S198>/Integral Gain' */
  localB->IntegralGain[2] = 1.0E-10 * localB->PointingCmd[2];
}

/* Update for referenced model: 'asbCubeSatACS' */
void asbCubeSatACS_Update(B_asbCubeSatACS_c_T *localB, DW_asbCubeSatACS_f_T
  *localDW)
{
  /* Update for DiscreteIntegrator: '<S201>/Integrator' */
  localDW->Integrator_DSTATE[0] += localB->IntegralGain[0];

  /* Update for Delay: '<S196>/UD' */
  localDW->UD_DSTATE[0] = localB->TSamp[0];

  /* Update for DiscreteIntegrator: '<S201>/Integrator' */
  localDW->Integrator_DSTATE[1] += localB->IntegralGain[1];

  /* Update for Delay: '<S196>/UD' */
  localDW->UD_DSTATE[1] = localB->TSamp[1];

  /* Update for DiscreteIntegrator: '<S201>/Integrator' */
  localDW->Integrator_DSTATE[2] += localB->IntegralGain[2];

  /* Update for Delay: '<S196>/UD' */
  localDW->UD_DSTATE[2] = localB->TSamp[2];
}

/* Model initialize function */
void asbCubeSatACS_initialize(const char_T **rt_errorStatus,
  RT_MODEL_asbCubeSatACS_T *const asbCubeSatACS_M, B_asbCubeSatACS_c_T *localB,
  DW_asbCubeSatACS_f_T *localDW)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(asbCubeSatACS_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(B_asbCubeSatACS_c_T));

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      localB->ORFtoECEF[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      localB->ECEFtoORF[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      localB->MathFunction[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      localB->Product_mn[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      localB->Bias1_e[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      localB->Abs2[i] = 0.0;
    }

    localB->BusConversion_InsertedFor_Point = asbCubeSatACS_rtZStatesOutBus;
    localB->BusConversion_InsertedFor_Poi_e = asbCubeSatACS_rtZEnvBus;
    localB->ProportionalGain[0] = 0.0;
    localB->ProportionalGain[1] = 0.0;
    localB->ProportionalGain[2] = 0.0;
    localB->Integrator[0] = 0.0;
    localB->Integrator[1] = 0.0;
    localB->Integrator[2] = 0.0;
    localB->DerivativeGain[0] = 0.0;
    localB->DerivativeGain[1] = 0.0;
    localB->DerivativeGain[2] = 0.0;
    localB->TSamp[0] = 0.0;
    localB->TSamp[1] = 0.0;
    localB->TSamp[2] = 0.0;
    localB->UD[0] = 0.0;
    localB->UD[1] = 0.0;
    localB->UD[2] = 0.0;
    localB->Diff[0] = 0.0;
    localB->Diff[1] = 0.0;
    localB->Diff[2] = 0.0;
    localB->Sum[0] = 0.0;
    localB->Sum[1] = 0.0;
    localB->Sum[2] = 0.0;
    localB->IntegralGain[0] = 0.0;
    localB->IntegralGain[1] = 0.0;
    localB->IntegralGain[2] = 0.0;
    localB->ControlMode = 0.0;
    localB->PointingCmd[0] = 0.0;
    localB->PointingCmd[1] = 0.0;
    localB->PointingCmd[2] = 0.0;
    localB->Merge = 0.0;
    localB->Product = 0.0;
    localB->Product1 = 0.0;
    localB->Product2 = 0.0;
    localB->Product3 = 0.0;
    localB->Sum_n = 0.0;
    localB->sqrt_o = 0.0;
    localB->Product2_f = 0.0;
    localB->Product6 = 0.0;
    localB->Product3_b = 0.0;
    localB->Product7 = 0.0;
    localB->Sum3 = 0.0;
    localB->Gain2 = 0.0;
    localB->Product8 = 0.0;
    localB->Product1_d = 0.0;
    localB->Product_m = 0.0;
    localB->Product_b = 0.0;
    localB->Product1_l = 0.0;
    localB->Sum1 = 0.0;
    localB->Gain = 0.0;
    localB->Product4 = 0.0;
    localB->Product2_e = 0.0;
    localB->Product3_i = 0.0;
    localB->Sum2 = 0.0;
    localB->Gain1 = 0.0;
    localB->Product5 = 0.0;
    localB->Sum_p = 0.0;
    localB->Product_l = 0.0;
    localB->Product1_g = 0.0;
    localB->Sum1_m = 0.0;
    localB->Gain_a = 0.0;
    localB->Product4_k = 0.0;
    localB->Product6_o = 0.0;
    localB->Product7_d = 0.0;
    localB->Sum3_g = 0.0;
    localB->Gain2_n = 0.0;
    localB->Product8_a = 0.0;
    localB->Product2_a = 0.0;
    localB->Product3_h = 0.0;
    localB->Sum2_o = 0.0;
    localB->Gain1_f = 0.0;
    localB->Product5_p = 0.0;
    localB->Sum_o = 0.0;
    localB->Product_p = 0.0;
    localB->Product1_dq = 0.0;
    localB->Sum1_j = 0.0;
    localB->Gain_j = 0.0;
    localB->Product4_g = 0.0;
    localB->Product2_l = 0.0;
    localB->Product3_g = 0.0;
    localB->Sum2_m = 0.0;
    localB->Gain1_o = 0.0;
    localB->Product5_b = 0.0;
    localB->Product6_c = 0.0;
    localB->Product7_g = 0.0;
    localB->Sum3_c = 0.0;
    localB->Gain2_a = 0.0;
    localB->Product8_m = 0.0;
    localB->Sum_j = 0.0;
    localB->TmpSignalConversionAtDotProduct[0] = 0.0;
    localB->TmpSignalConversionAtDotProduct[1] = 0.0;
    localB->TmpSignalConversionAtDotProduct[2] = 0.0;
    localB->Product_bp = 0.0;
    localB->Product1_f = 0.0;
    localB->Product2_j = 0.0;
    localB->Product3_d = 0.0;
    localB->Sum_h = 0.0;
    localB->sqrt_n = 0.0;
    localB->Product2_c = 0.0;
    localB->Product6_b = 0.0;
    localB->Product3_e = 0.0;
    localB->Product7_b = 0.0;
    localB->Sum3_j = 0.0;
    localB->Gain2_k = 0.0;
    localB->Product8_o = 0.0;
    localB->Product1_a = 0.0;
    localB->Product_n = 0.0;
    localB->Product_e = 0.0;
    localB->Product1_k = 0.0;
    localB->Sum1_n = 0.0;
    localB->Gain_m = 0.0;
    localB->Product4_p = 0.0;
    localB->Product2_h = 0.0;
    localB->Product3_m = 0.0;
    localB->Sum2_g = 0.0;
    localB->Gain1_p = 0.0;
    localB->Product5_f = 0.0;
    localB->Sum_oq = 0.0;
    localB->Product_g = 0.0;
    localB->Product1_af = 0.0;
    localB->Sum1_h = 0.0;
    localB->Gain_n = 0.0;
    localB->Product4_c = 0.0;
    localB->Product6_p = 0.0;
    localB->Product7_dp = 0.0;
    localB->Sum3_m = 0.0;
    localB->Gain2_h = 0.0;
    localB->Product8_p = 0.0;
    localB->Product2_k = 0.0;
    localB->Product3_c = 0.0;
    localB->Sum2_e = 0.0;
    localB->Gain1_c = 0.0;
    localB->Product5_i = 0.0;
    localB->Sum_i = 0.0;
    localB->Product_k = 0.0;
    localB->Product1_m = 0.0;
    localB->Sum1_l = 0.0;
    localB->Gain_k = 0.0;
    localB->Product4_i = 0.0;
    localB->Product2_m = 0.0;
    localB->Product3_p = 0.0;
    localB->Sum2_l = 0.0;
    localB->Gain1_g = 0.0;
    localB->Product5_d = 0.0;
    localB->Product6_i = 0.0;
    localB->Product7_bn = 0.0;
    localB->Sum3_g2 = 0.0;
    localB->Gain2_m = 0.0;
    localB->Product8_me = 0.0;
    localB->Sum_d = 0.0;
    localB->TmpSignalConversionAtDotProdu_k[0] = 0.0;
    localB->TmpSignalConversionAtDotProdu_k[1] = 0.0;
    localB->TmpSignalConversionAtDotProdu_k[2] = 0.0;
    localB->DotProduct3 = 0.0;
    localB->DotProduct1 = 0.0;
    localB->DotProduct2 = 0.0;
    localB->Divide1 = 0.0;
    localB->Sqrt3 = 0.0;
    localB->Divide = 0.0;
    localB->Bias = 0.0;
    localB->Abs = 0.0;
    localB->Bias1 = 0.0;
    localB->Abs1 = 0.0;
    localB->Merge_d = 0.0;
    localB->DotProduct3_g = 0.0;
    localB->DotProduct2_j = 0.0;
    localB->Divide1_e = 0.0;
    localB->Sqrt3_n = 0.0;
    localB->Add2 = 0.0;
    localB->Product_e5 = 0.0;
    localB->DotProduct3_f = 0.0;
    localB->DotProduct2_f = 0.0;
    localB->Divide1_n = 0.0;
    localB->Sqrt3_j = 0.0;
    localB->Divide_d = 0.0;
    localB->Bias_i = 0.0;
    localB->Abs_l = 0.0;
    localB->Bias1_n = 0.0;
    localB->Abs1_n = 0.0;
    localB->Merge_m = 0.0;
    localB->is180degRot[0] = 0.0;
    localB->is180degRot[1] = 0.0;
    localB->is180degRot[2] = 0.0;
    localB->Product1_df = 0.0;
    localB->Product2_mt = 0.0;
    localB->Product3_n = 0.0;
    localB->Sum_c = 0.0;
    localB->sqrt_j = 0.0;
    localB->Product_c = 0.0;
    localB->Product2_mn = 0.0;
    localB->Product_po = 0.0;
    localB->Product1_gf = 0.0;
    localB->Product1_h = 0.0;
    localB->Product2_o = 0.0;
    localB->Product3_j = 0.0;
    localB->Product3_o = 0.0;
    localB->Sum_pg = 0.0;
    localB->sqrt_om = 0.0;
    localB->Product2_i = 0.0;
    localB->Product6_f = 0.0;
    localB->Product3_k = 0.0;
    localB->Product7_f = 0.0;
    localB->Sum3_mb = 0.0;
    localB->Gain2_d = 0.0;
    localB->Product8_d = 0.0;
    localB->Product1_l2 = 0.0;
    localB->Product_ks = 0.0;
    localB->Product_mm = 0.0;
    localB->Product1_b = 0.0;
    localB->Sum1_k = 0.0;
    localB->Gain_g = 0.0;
    localB->Product4_n = 0.0;
    localB->Product2_hp = 0.0;
    localB->Product3_a = 0.0;
    localB->Sum2_lr = 0.0;
    localB->Gain1_m = 0.0;
    localB->Product5_c = 0.0;
    localB->Sum_pp = 0.0;
    localB->Product_h = 0.0;
    localB->Product1_p = 0.0;
    localB->Sum1_hn = 0.0;
    localB->Gain_b = 0.0;
    localB->Product4_j = 0.0;
    localB->Product6_d = 0.0;
    localB->Product7_l = 0.0;
    localB->Sum3_k = 0.0;
    localB->Gain2_f = 0.0;
    localB->Product8_h = 0.0;
    localB->Product2_p = 0.0;
    localB->Product3_o3 = 0.0;
    localB->Sum2_d = 0.0;
    localB->Gain1_l = 0.0;
    localB->Product5_j = 0.0;
    localB->Sum_e = 0.0;
    localB->Product_j = 0.0;
    localB->Product1_ly = 0.0;
    localB->Sum1_k2 = 0.0;
    localB->Gain_o = 0.0;
    localB->Product4_l = 0.0;
    localB->Product2_a1 = 0.0;
    localB->Product3_j0 = 0.0;
    localB->Sum2_gz = 0.0;
    localB->Gain1_d = 0.0;
    localB->Product5_pr = 0.0;
    localB->Product6_k = 0.0;
    localB->Product7_e = 0.0;
    localB->Sum3_o = 0.0;
    localB->Gain2_p = 0.0;
    localB->Product8_f = 0.0;
    localB->Sum_di = 0.0;
    localB->TmpSignalConversionAtDotProdu_p[0] = 0.0;
    localB->TmpSignalConversionAtDotProdu_p[1] = 0.0;
    localB->TmpSignalConversionAtDotProdu_p[2] = 0.0;
    localB->jxk = 0.0;
    localB->kxi = 0.0;
    localB->ixj = 0.0;
    localB->kxj = 0.0;
    localB->ixk = 0.0;
    localB->jxi = 0.0;
    localB->Sum_f[0] = 0.0;
    localB->Sum_f[1] = 0.0;
    localB->Sum_f[2] = 0.0;
    localB->jxk_g = 0.0;
    localB->kxi_f = 0.0;
    localB->ixj_j = 0.0;
    localB->kxj_j = 0.0;
    localB->ixk_p = 0.0;
    localB->jxi_d = 0.0;
    localB->Sum_a[0] = 0.0;
    localB->Sum_a[1] = 0.0;
    localB->Sum_a[2] = 0.0;
    localB->Product_lv = 0.0;
    localB->Product1_fw = 0.0;
    localB->Product2_ie = 0.0;
    localB->Product3_c5 = 0.0;
    localB->Sum_hq = 0.0;
    localB->sqrt_d = 0.0;
    localB->Product2_b = 0.0;
    localB->Product6_h = 0.0;
    localB->Product3_nk = 0.0;
    localB->Product7_p = 0.0;
    localB->Sum3_h = 0.0;
    localB->Gain2_j = 0.0;
    localB->Product8_b = 0.0;
    localB->Product1_e = 0.0;
    localB->Product_a = 0.0;
    localB->Product_ji = 0.0;
    localB->Product1_j = 0.0;
    localB->Sum1_mh = 0.0;
    localB->Gain_ms = 0.0;
    localB->Product4_b = 0.0;
    localB->Product2_ll = 0.0;
    localB->Product3_ek = 0.0;
    localB->Sum2_f = 0.0;
    localB->Gain1_lz = 0.0;
    localB->Product5_fk = 0.0;
    localB->Sum_eb = 0.0;
    localB->Product_o = 0.0;
    localB->Product1_pi = 0.0;
    localB->Sum1_g = 0.0;
    localB->Gain_jv = 0.0;
    localB->Product4_e = 0.0;
    localB->Product6_fq = 0.0;
    localB->Product7_c = 0.0;
    localB->Sum3_n = 0.0;
    localB->Gain2_o = 0.0;
    localB->Product8_bs = 0.0;
    localB->Product2_g = 0.0;
    localB->Product3_jj = 0.0;
    localB->Sum2_dw = 0.0;
    localB->Gain1_fu = 0.0;
    localB->Product5_g = 0.0;
    localB->Sum_oc = 0.0;
    localB->Product_ex = 0.0;
    localB->Product1_i = 0.0;
    localB->Sum1_f = 0.0;
    localB->Gain_gb = 0.0;
    localB->Product4_d = 0.0;
    localB->Product2_gk = 0.0;
    localB->Product3_nl = 0.0;
    localB->Sum2_fp = 0.0;
    localB->Gain1_k = 0.0;
    localB->Product5_e = 0.0;
    localB->Product6_br = 0.0;
    localB->Product7_d2 = 0.0;
    localB->Sum3_f = 0.0;
    localB->Gain2_h1 = 0.0;
    localB->Product8_c = 0.0;
    localB->Sum_jt = 0.0;
    localB->TmpSignalConversionAtDotProdu_f[0] = 0.0;
    localB->TmpSignalConversionAtDotProdu_f[1] = 0.0;
    localB->TmpSignalConversionAtDotProdu_f[2] = 0.0;
    localB->DotProduct3_n = 0.0;
    localB->DotProduct1_n = 0.0;
    localB->DotProduct2_k = 0.0;
    localB->Divide1_l = 0.0;
    localB->Sqrt3_j1 = 0.0;
    localB->Divide_l = 0.0;
    localB->Bias_h = 0.0;
    localB->Abs_c = 0.0;
    localB->Bias1_d = 0.0;
    localB->Abs1_e = 0.0;
    localB->Merge_c = 0.0;
    localB->Switch[0] = 0.0;
    localB->Switch[1] = 0.0;
    localB->Switch[2] = 0.0;
    localB->Switch[3] = 0.0;
    localB->Product_d = 0.0;
    localB->Product1_h4 = 0.0;
    localB->Product2_po = 0.0;
    localB->Product3_pz = 0.0;
    localB->Sum_aq = 0.0;
    localB->sqrt_k = 0.0;
    localB->Product_mw = 0.0;
    localB->Product1_lc = 0.0;
    localB->Product2_el = 0.0;
    localB->Product3_e1 = 0.0;
    localB->fcn3 = 0.0;
    localB->Merge_j = 0.0;
    localB->fcn1 = 0.0;
    localB->fcn2 = 0.0;
    localB->fcn4 = 0.0;
    localB->fcn5 = 0.0;
    localB->jxi_g = 0.0;
    localB->ixk_f = 0.0;
    localB->kxj_d = 0.0;
    localB->ixj_k = 0.0;
    localB->kxi_d = 0.0;
    localB->jxk_d = 0.0;
    localB->Sum_jb[0] = 0.0;
    localB->Sum_jb[1] = 0.0;
    localB->Sum_jb[2] = 0.0;
    localB->is180degRot_c[0] = 0.0;
    localB->is180degRot_c[1] = 0.0;
    localB->is180degRot_c[2] = 0.0;
    localB->Product3_mu = 0.0;
    localB->Product2_d = 0.0;
    localB->Product1_fq = 0.0;
    localB->DotProduct2_b = 0.0;
    localB->DotProduct1_b = 0.0;
    localB->Divide1_m = 0.0;
    localB->Sqrt3_b = 0.0;
    localB->DotProduct3_i = 0.0;
    localB->Add2_a = 0.0;
    localB->Product_mk = 0.0;
    localB->Sum_b = 0.0;
    localB->sqrt_c = 0.0;
    localB->Product3_mk = 0.0;
    localB->Product3_i2 = 0.0;
    localB->Product2_jr = 0.0;
    localB->Product2_lv = 0.0;
    localB->Product1_hl = 0.0;
    localB->Product1_bp = 0.0;
    localB->Product_kg = 0.0;
    localB->Product_bpv = 0.0;
    localB->Sum_m = 0.0;
    localB->Product3_ee = 0.0;
    localB->Product2_o2 = 0.0;
    localB->Product1_ju = 0.0;
    localB->Product_f = 0.0;
    localB->Sum_ei = 0.0;
    localB->Product3_l = 0.0;
    localB->Product2_oq = 0.0;
    localB->Product1_f1 = 0.0;
    localB->Product_gh = 0.0;
    localB->Sum_l = 0.0;
    localB->Product3_mo = 0.0;
    localB->Product2_kz = 0.0;
    localB->Product1_mz = 0.0;
    localB->Product_eo = 0.0;
    localB->Sum_nv = 0.0;
    localB->jxi_o = 0.0;
    localB->ixk_l = 0.0;
    localB->kxj_b = 0.0;
    localB->ixj_f = 0.0;
    localB->kxi_o = 0.0;
    localB->jxk_h = 0.0;
    localB->Sum_le[0] = 0.0;
    localB->Sum_le[1] = 0.0;
    localB->Sum_le[2] = 0.0;
    localB->Switch3[0] = 0.0;
    localB->Switch3[1] = 0.0;
    localB->Switch3[2] = 0.0;
    localB->jxi_c = 0.0;
    localB->ixk_m = 0.0;
    localB->kxj_c = 0.0;
    localB->ixj_m = 0.0;
    localB->kxi_dm = 0.0;
    localB->jxk_m = 0.0;
    localB->Sum_g[0] = 0.0;
    localB->Sum_g[1] = 0.0;
    localB->Sum_g[2] = 0.0;
    localB->Gain_b2 = 0.0;
    localB->Gain2_od = 0.0;
    localB->jxk_n = 0.0;
    localB->kxi_p = 0.0;
    localB->ixj_k3 = 0.0;
    localB->kxj_n = 0.0;
    localB->ixk_k = 0.0;
    localB->jxi_b = 0.0;
    localB->Sum_ou[0] = 0.0;
    localB->Sum_ou[1] = 0.0;
    localB->Sum_ou[2] = 0.0;
    localB->zr[0] = 0.0;
    localB->zr[1] = 0.0;
    localB->zr[2] = 0.0;
    localB->ixj_i = 0.0;
    localB->jxk_i = 0.0;
    localB->kxi_os = 0.0;
    localB->ixk_g = 0.0;
    localB->jxi_ok = 0.0;
    localB->kxj_g = 0.0;
    localB->Sum_dv[0] = 0.0;
    localB->Sum_dv[1] = 0.0;
    localB->Sum_dv[2] = 0.0;
    localB->DotProduct = 0.0;
    localB->SumofElements = 0.0;
    localB->MathFunction1 = 0.0;
    localB->DotProduct_m = 0.0;
    localB->SumofElements_h = 0.0;
    localB->MathFunction1_n = 0.0;
    localB->DotProduct_b = 0.0;
    localB->SumofElements_g = 0.0;
    localB->MathFunction1_ni = 0.0;
    localB->Add = 0.0;
    localB->Merge_e[0] = 0.0;
    localB->Merge_e[1] = 0.0;
    localB->Merge_e[2] = 0.0;
    localB->Merge_e[3] = 0.0;
    localB->Product_ky = 0.0;
    localB->Product1_li = 0.0;
    localB->Product2_gb = 0.0;
    localB->Product3_an = 0.0;
    localB->Sum_hk = 0.0;
    localB->Divide_j = 0.0;
    localB->UnaryMinus = 0.0;
    localB->Divide1_d = 0.0;
    localB->UnaryMinus1 = 0.0;
    localB->Divide2 = 0.0;
    localB->UnaryMinus2 = 0.0;
    localB->Divide3 = 0.0;
    localB->Product_pb = 0.0;
    localB->Product1_pg = 0.0;
    localB->Product2_mw = 0.0;
    localB->Product3_cd = 0.0;
    localB->Sum_fj = 0.0;
    localB->Product_la = 0.0;
    localB->Product1_p5 = 0.0;
    localB->Product2_jd = 0.0;
    localB->Product3_db = 0.0;
    localB->Sum_c3 = 0.0;
    localB->Product_nm = 0.0;
    localB->Product1_o = 0.0;
    localB->Product2_bn = 0.0;
    localB->Product3_gc = 0.0;
    localB->Sum_hn = 0.0;
    localB->Product_m0 = 0.0;
    localB->Product1_eo = 0.0;
    localB->Product2_dz = 0.0;
    localB->Product3_ox = 0.0;
    localB->Sum_h4 = 0.0;
    localB->Product_mx = 0.0;
    localB->Product1_fz = 0.0;
    localB->Product2_p4 = 0.0;
    localB->Product3_kb = 0.0;
    localB->Sum_k = 0.0;
    localB->sqrt_jz = 0.0;
    localB->Product_j5 = 0.0;
    localB->Product1_ik = 0.0;
    localB->Product2_ev = 0.0;
    localB->Product3_f = 0.0;
    localB->fcn3_l = 0.0;
    localB->Merge_cv = 0.0;
    localB->fcn1_l = 0.0;
    localB->fcn2_k = 0.0;
    localB->fcn4_e = 0.0;
    localB->fcn5_p = 0.0;
    localB->Product_f0 = 0.0;
    localB->Product1_ey = 0.0;
    localB->Product2_os = 0.0;
    localB->Product3_bo = 0.0;
    localB->Product4_i1 = 0.0;
    localB->Product5_pt = 0.0;
    localB->detMatrix = 0.0;
    localB->Bias_c = 0.0;
    localB->Abs1_o = 0.0;
    localB->Add_d = 0.0;
    localB->sqrt_nk = 0.0;
    localB->Switch_f[0] = 0.0;
    localB->Switch_f[1] = 0.0;
    localB->Product_n4 = 0.0;
    localB->Add_de = 0.0;
    localB->Add_i = 0.0;
    localB->Add_m = 0.0;
    localB->Product_i[0] = 0.0;
    localB->Product_i[1] = 0.0;
    localB->Product_i[2] = 0.0;
    localB->Add_h = 0.0;
    localB->sqrt_o2 = 0.0;
    localB->Add_b = 0.0;
    localB->Add_a = 0.0;
    localB->Add_p = 0.0;
    localB->Switch_o[0] = 0.0;
    localB->Switch_o[1] = 0.0;
    localB->Product_ph = 0.0;
    localB->Product_oe[0] = 0.0;
    localB->Product_oe[1] = 0.0;
    localB->Product_oe[2] = 0.0;
    localB->Add_hm = 0.0;
    localB->sqrt_p = 0.0;
    localB->Add_o = 0.0;
    localB->Add_f = 0.0;
    localB->Add_b4 = 0.0;
    localB->Switch_f1[0] = 0.0;
    localB->Switch_f1[1] = 0.0;
    localB->Product_jp = 0.0;
    localB->Product_oi[0] = 0.0;
    localB->Product_oi[1] = 0.0;
    localB->Product_oi[2] = 0.0;
    localB->Sum_dx = 0.0;
    localB->sqrt_b = 0.0;
    localB->Gain1_lg = 0.0;
    localB->Add_i5 = 0.0;
    localB->Add_fn = 0.0;
    localB->Add_mp = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_asbCubeSatACS_f_T));
  localDW->Integrator_DSTATE[0] = 0.0;
  localDW->Integrator_DSTATE[1] = 0.0;
  localDW->Integrator_DSTATE[2] = 0.0;
  localDW->UD_DSTATE[0] = 0.0;
  localDW->UD_DSTATE[1] = 0.0;
  localDW->UD_DSTATE[2] = 0.0;
}
