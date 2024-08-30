/****************************************************************************
 *
 * Copyright 2024 NXP
 *
 * NXP Confidential and Proprietary.
 *
 * This software is owned or controlled by NXP and may only be used strictly
 * in accordance with the applicable license terms.
 * By expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms.
 * If you do not agree to be bound by the applicable license terms,
 * then you may not retain, install, activate or otherwise use the software.
 *
 *
 ****************************************************************************/

#include <stddef.h>
#include <stdint.h>

#include "Include/pwrm.h"
#include "fsl_component_timer_manager.h"
#include "fsl_debug_console.h"
#include "fsl_pm_core.h"
#include "board_lp.h"
#include "fwk_platform_lowpower.h"

#include "PWR_Interface.h"

#include "fsl_device_registers.h"
#include "fsl_os_abstraction.h"
#include "dbg.h"

static void (*zb_lp_entry_cb)(void);
static void (*zb_lp_exit_cb)(void);
static status_t lp_cb(pm_event_type_t eventType, uint8_t powerState, void *data);
static pm_notify_element_t lp_cb_notify_group = {
    .notifyCallback = lp_cb,
    .data           = NULL,
};

/*---------------------------------------------------------------------------
 * Name: PWRM_eFinishActivity
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
PWRM_teStatus PWRM_eFinishActivity(void)
{
    PWR_AllowDeviceToSleep();
    return PWRM_E_OK;
}

/*---------------------------------------------------------------------------
 * Name: PWRM_eStartActivity
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
PWRM_teStatus PWRM_eStartActivity(void)
{
    PWR_DisallowDeviceToSleep();
    return PWRM_E_OK;
}

/*---------------------------------------------------------------------------
 * Name: PWRM_u16GetActivityCount
 * Description: -
 * Parameters: -
 * Return: uint16
 *---------------------------------------------------------------------------*/
uint16 PWRM_u16GetActivityCount(void)
{
    return (uint16)PWR_IsDeviceAllowedToSleep();
}

static status_t lp_cb(pm_event_type_t eventType, uint8_t powerState, void *data)
{
    status_t ret = kStatus_Success;

    if (eventType == kPM_EventEnteringSleep)
    {
        if (zb_lp_entry_cb)
        {
            zb_lp_entry_cb();
        }
    }
    else
    {
        if (zb_lp_exit_cb)
        {
            zb_lp_exit_cb();
        }
    }

    return ret;
}

void PWR_RegisterLowPowerEnterCallback(void (*lp_entry_cb)(void))
{
    zb_lp_entry_cb = lp_entry_cb;
}

void PWR_RegisterLowPowerExitCallback(void (*lp_exit_cb)(void))
{
    zb_lp_exit_cb = lp_exit_cb;
}

static void activity_tm_cb(void *param)
{
    pwrm_tsWakeTimerEvent *psWake = param;
    timer_status_t status;
    
    status = TM_Close(psWake->tmr);
    assert(kStatus_TimerSuccess == status);
    (void)status;

    psWake->prCallbackfn();
}

PWRM_teStatus PWR_eScheduleActivity(pwrm_tsWakeTimerEvent *psWake, uint32 u32TimeMs, void (*prCallbackfn)(void))
{
    psWake->prCallbackfn = prCallbackfn;
    timer_status_t status;

    status = TM_Open(psWake->tmr);
    assert(kStatus_TimerSuccess == status);

    status = TM_InstallCallback(psWake->tmr, activity_tm_cb, psWake);
    assert(kStatus_TimerSuccess == status);

    status = TM_Start(psWake->tmr, kTimerModeSingleShot, u32TimeMs);
    assert(kStatus_TimerSuccess == status);
    (void)status;

    return PWRM_E_OK;
}
PWRM_teStatus PWRM_eScheduleActivity(pwrm_tsWakeTimerEvent *psWake, uint32 u32TimeMs, void (*prCallbackfn)(void))
{
    return PWR_eScheduleActivity(psWake, u32TimeMs, prCallbackfn);
}

PWRM_teStatus PWR_eRemoveActivity(pwrm_tsWakeTimerEvent *psWake)
{
    TM_Close(psWake->tmr);

    return PWRM_E_OK;
}

PWRM_teStatus PWRM_eRemoveActivity(pwrm_tsWakeTimerEvent *psWake)
{
    return PWR_eRemoveActivity(psWake);
}

void PWR_vColdStart(void)
{
    /* Init and set constraint to DeepSleep */
    PWR_ReturnStatus_t status = PWR_Success;

    PWR_Init();

    /* Initialize board_lp module, likely to register the enter/exit
     * low power callback to Power Manager */
    BOARD_LowPowerInit();
#if FSL_OSA_BM_TIMER_CONFIG != FSL_OSA_BM_TIMER_NONE
    /*
     * Register first the OSA BM power callbacks, needed for
     * suspending and resuming SysTick.
     */
    PWR_SysTicksLowPowerInit();
#endif

    status = PWR_SetLowPowerModeConstraint(PWR_DeepSleep);
    assert(status == PWR_Success);

    /* Register PWR Callbacks */
    vAppRegisterPWRCallbacks();
    PM_RegisterNotify(kPM_NotifyGroup0, &lp_cb_notify_group);
}

void PWRM_vColdStart(void)
{
    PWR_vColdStart();
}
