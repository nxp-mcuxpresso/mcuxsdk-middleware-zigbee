/*
* Copyright 2019, 2024 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/


/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "EmbeddedTypes.h"
#include "ZQueue.h"
#include "ZTimer.h"
#include "zigbee_config.h"
#include "fsl_gpio.h"
#include "app_crypto.h"
#if IS_MCXW7x_SERIES
#include "fwk_platform.h"
#include "fwk_platform_ics.h"
#include "fsl_component_mem_manager.h"
#include "fsl_component_timer_manager.h"
#else
#include "MemManager.h"
#include "TimersManager.h"
#endif
#include "app_buttons.h"
#include "app_main.h"
#include "app_end_device_node.h"
#include "app_leds.h"
#include "app_signals.h"
#include "PWR_Interface.h"
#include "pwrm.h"

#include "fsl_os_abstraction.h"
#ifdef FSL_RTOS_FREE_RTOS
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "portmacro.h"
#endif
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef OT_ZB_SUPPORT
#define APP_NUM_STD_TMRS             (1)
#else
#define APP_NUM_STD_TMRS             (2)
#endif
#define APP_QUEUE_SIZE               (1)
#define APP_ZTIMER_STORAGE           ( APP_NUM_STD_TMRS )


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
void ZPS_task();
void APP_task();
void vWakeCallBackZtimer();
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
uint8_t  u8TimerPoll;
#ifdef OT_ZB_SUPPORT
uint8_t  u8TimerScan;
uint8_t  u8TimerFb;
#endif
/* queue handles */
tszQueue APP_msgAppEvents;
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
static ZTIMER_tsTimer asTimers[APP_ZTIMER_STORAGE + ZIGBEE_TIMER_STORAGE];
extern const uint8_t gUseRtos_c;
static uint8_t initialized = FALSE;
static OSA_TASK_DEFINE(ZPS_task, gMainThreadPriority_c, 1, gMainThreadStackSize_c, 0);

OSA_TASK_HANDLE_DEFINE(ZPS_taskHandle);

OSA_SEMAPHORE_HANDLE_DEFINE(ZPS_semaphoreHandle);
OSA_SEMAPHORE_HANDLE_DEFINE(APP_semaphoreHandle);
OSA_MUTEX_HANDLE_DEFINE(zb_task_lock);

PWR_tsWakeTimerEvent sZTimer;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

extern void vAppMain(bool_t bColdStart);

/****************************************************************************
 *
 * NAME: main_task
 *
 * DESCRIPTION:
 * Main  execution loop
 *
 * RETURNS:
 * Never
 *
 ****************************************************************************/
#ifndef OT_ZB_SUPPORT
void main_task (uint32_t parameter)
{
    if(!initialized)
    {
        /* place initialization code here... */
#if IS_MCXW7x_SERIES
        PLATFORM_SwitchToOsc32k();
        PLATFORM_InitTimerManager();
#endif
        PWR_vColdStart();
#if IS_NOT_MCXW7x_SERIES
        TMR_Init();
#endif

        CRYPTO_u8RandomInit();
        CRYPTO_Init();
        MEM_Init();

#if IS_MCXW7x_SERIES
#if defined(USE_NBU) && (USE_NBU == 1)
        PLATFORM_InitNbu();
        PLATFORM_InitMulticore();
        PLATFORM_FwkSrvInit();
        PLATFORM_SendChipRevision();
        PLATFORM_LoadHwParams();
#endif
#endif
        (void)OSA_SemaphoreCreate((osa_semaphore_handle_t)ZPS_semaphoreHandle, 1);
        (void)OSA_SemaphoreCreate((osa_semaphore_handle_t)APP_semaphoreHandle, 1);
        (void)OSA_MutexCreate((osa_mutex_handle_t)zb_task_lock);

        vAppMain(TRUE);

        (void)OSA_TaskCreate(ZPS_taskHandle, OSA_TASK(ZPS_task), NULL);

        memset( &sZTimer, 0x0, sizeof(PWR_tsWakeTimerEvent));
        PWR_eScheduleActivity(&sZTimer, 250, vWakeCallBackZtimer);
        initialized = TRUE;
    }
    APP_task();
}
#endif

void vWakeCallBackZtimer(void)
{
    zbTaskletsSignalApp();
    memset( &sZTimer, 0x0, sizeof(PWR_tsWakeTimerEvent));
    PWR_eScheduleActivity(&sZTimer, 250, vWakeCallBackZtimer);
}

void APP_task()
{
    while(1)
    {
        if (OSA_SemaphoreWait((osa_semaphore_handle_t)APP_semaphoreHandle, osaWaitForever_c) == KOSA_StatusSuccess)
        {
            OSA_MutexLock((osa_mutex_handle_t) zb_task_lock, osaWaitForever_c);
            ZTIMER_vTask();
            APP_taskEndDevicNode();
            bdb_taskBDB();
#ifndef FSL_RTOS_FREE_RTOS
#if IS_NOT_MCXW7x_SERIES
        PWR_EnterLowPower();
#else
        PWR_EnterLowPower(0);
#endif
#endif
            OSA_MutexUnlock((osa_mutex_handle_t) zb_task_lock);
        }
        if(!gUseRtos_c)
        {
            break;
        }
    }
}

void ZPS_task()
{
    while(1)
    {
        if (OSA_SemaphoreWait((osa_semaphore_handle_t)ZPS_semaphoreHandle, osaWaitForever_c) == KOSA_StatusSuccess)
        {
            OSA_MutexLock((osa_mutex_handle_t) zb_task_lock, osaWaitForever_c);
            zps_taskZPS();
            OSA_MutexUnlock((osa_mutex_handle_t) zb_task_lock);
        }
        if(!gUseRtos_c)
        {
            break;
        }
    }
}

void zbTaskletsSignalZps()
{
    OSA_SemaphorePost((osa_semaphore_handle_t)ZPS_semaphoreHandle);
}

void zbTaskletsSignalApp()
{
    OSA_SemaphorePost((osa_semaphore_handle_t)APP_semaphoreHandle);
}

#ifdef FSL_RTOS_FREE_RTOS
void vPortSuppressTicksAndSleep(TickType_t xExpectedIdleTime)
{
    if (initialized)
    {
        bool abortIdle = false;
        uint64_t actualIdleTimeUs = 0U, expectedIdleTimeUs = 0U;

        /* The OSA_InterruptDisable() API will prevent us to wakeup so we use
         * OSA_DisableIRQGlobal() */
        OSA_DisableIRQGlobal();

        /* Disable and prepare systicks for low power */
        abortIdle = PWR_SysticksPreProcess((uint32_t)xExpectedIdleTime, &expectedIdleTimeUs);

        if (abortIdle == false)
        {
                /* Enter low power with a maximal timeout */
                actualIdleTimeUs = PWR_EnterLowPower(expectedIdleTimeUs);

                /* Re enable systicks and compensate systick timebase */
                PWR_SysticksPostProcess(expectedIdleTimeUs, actualIdleTimeUs);
        }
        /* Exit from critical section */
        OSA_EnableIRQGlobal();
    }
}
#endif
/****************************************************************************
 *
 * NAME: APP_vInitResources
 *
 * DESCRIPTION:
 * Initialise resources (timers, queue's etc)
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void APP_vInitResources(void)
{
    /* Initialise the Z timer module */
    ZTIMER_eInit(asTimers, sizeof(asTimers) / sizeof(ZTIMER_tsTimer));

    /* Create Z timers */
    ZTIMER_eOpen(&u8TimerPoll,          APP_cbTimerPoll,        NULL, ZTIMER_FLAG_PREVENT_SLEEP);
#ifdef OT_ZB_SUPPORT
    ZTIMER_eOpen(&u8TimerScan,          APP_cbTimerScan,        NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZTIMER_eOpen(&u8TimerFb,            APP_cbTimerFb,          NULL, ZTIMER_FLAG_PREVENT_SLEEP);
#endif
    ZQ_vQueueCreate(&APP_msgAppEvents,  APP_QUEUE_SIZE,       sizeof(APP_tsEvent),         NULL);
    ZQ_vRegisterCallback(&APP_msgAppEvents, zbTaskletsSignalApp);
}


/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
