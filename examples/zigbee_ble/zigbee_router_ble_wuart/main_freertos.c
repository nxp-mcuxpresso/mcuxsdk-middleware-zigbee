/*
* Copyright 2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/


/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "fsl_os_abstraction.h"
#include "app.h"
#include "app_conn.h"
#include "zigbee_config.h"
#include "app_router_node.h"
#include "fwk_platform.h"
#include "app_zigbee.h"

#include "app_signals.h"
#include "pwrm.h"
#include "app_crypto.h"
#include "fsl_component_mem_manager.h"
#include "fwk_platform.h"
#include "fwk_platform_ics.h"
#include "bdb_api.h"

#if defined(gAppUseSensors_d) && (gAppUseSensors_d > 0)
#include "sensors.h"
#endif

#if defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 0)
/* board_comp.h only required for above services   */
#include "board_comp.h"
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define WAKEUP_TIMER_VALUE_MS 10

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
static void zigbee_task(void *argument);
static void ble_task(void *argument);
static void ZPS_task(void *argument);
static void APP_task(void);
static void vWakeCallBackZtimer(void);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
extern OSA_MUTEX_HANDLE_DEFINE(app_zigbee_mutex);

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
static OSA_TASK_HANDLE_DEFINE(s_zigbeeTaskHandle);
static OSA_TASK_HANDLE_DEFINE(ZPS_taskHandle);
static OSA_TASK_HANDLE_DEFINE(s_bleTaskHandle);

static OSA_TASK_DEFINE(zigbee_task, gMainThreadPriority_c, 1, gMainThreadStackSize_c, 0);
static OSA_TASK_DEFINE(ZPS_task, gMainThreadPriority_c, 1, gMainThreadStackSize_c, 0);
static OSA_TASK_DEFINE(ble_task, gMainThreadPriority_c, 1, gMainThreadStackSize_c, 0);

OSA_SEMAPHORE_HANDLE_DEFINE(ZPS_semaphoreHandle);
OSA_SEMAPHORE_HANDLE_DEFINE(APP_semaphoreHandle);
OSA_MUTEX_HANDLE_DEFINE(zb_task_lock);

bool_t initialized = FALSE;

PWR_tsWakeTimerEvent sZTimer;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
extern void vAppMain(void);


/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/
int main(void)
{
    /* Init OSA: should be called before any other OSA API */
    OSA_Init();

    BOARD_InitHardware();

    /* Initialize Timers for Application */
    (void)PLATFORM_InitTimerManager();

#if defined(gAppUseSensors_d) && (gAppUseSensors_d > 0)
    /* for battery/temperature  measurement */
    SENSORS_Init();

    /* Trig the ADC on the battery voltage during initialization for BLE battery service profile
      SENSORS_RefreshBatteryLevel() shall be called at second step to get the updated value*/
    SENSORS_TriggerBatteryMeasurement();
#endif

#if (defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 0))
    /* init application serial manager*/
    BOARD_InitSerialManager((serial_handle_t)gSerMgrIf);
#endif

#if defined(gAppUseSensors_d) && (gAppUseSensors_d > 0)
    /* Measure battery voltage during initialization for BLE battery service profile */
    (void)SENSORS_RefreshBatteryLevel();
#endif

#if defined(gAppLowpowerEnabled_d) && (gAppLowpowerEnabled_d > 0)
    APP_ServiceInitLowpower();
#endif

    (void)OSA_MutexCreate((osa_mutex_handle_t)app_zigbee_mutex);
    (void)OSA_TaskCreate((osa_task_handle_t)s_zigbeeTaskHandle, OSA_TASK(zigbee_task), NULL);
    (void)OSA_TaskCreate((osa_task_handle_t)s_bleTaskHandle,    OSA_TASK(ble_task), NULL);

    /* Start scheduler*/
    OSA_Start();

    /*won't run here*/
    assert(FALSE);
    return 0;
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: zigbee_task
 *
 * DESCRIPTION:
 * Initialize zigbee resources and create zigbee tasks
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
static void zigbee_task(void *argument)
{
#if DEBUG_STACK_DEPTH
    UBaseType_t uxHighWaterMark;
#endif

    /* e.g. osaEventFlags_t ev; */

    if(!initialized)
    {
        PLATFORM_SwitchToOsc32k();
        PLATFORM_InitTimerManager();

        CRYPTO_Init();
        CRYPTO_u8RandomInit();
        MEM_Init();

        PLATFORM_InitNbu();
        PLATFORM_InitMulticore();
        PLATFORM_FwkSrvInit();
        PLATFORM_SendChipRevision();
        PLATFORM_LoadHwParams();

#if defined(FSL_RTOS_FREE_RTOS) && DEBUG_STACK_DEPTH
        uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
        DBG_vPrintf(TRUE, "Stack High Watermark = %d B\r\n",
        uxHighWaterMark * sizeof(unsigned int));
#endif
        (void)OSA_SemaphoreCreate((osa_semaphore_handle_t)ZPS_semaphoreHandle, 1);
        (void)OSA_SemaphoreCreate((osa_semaphore_handle_t)APP_semaphoreHandle, 1);

        vAppMain();

        (void)OSA_TaskCreate(ZPS_taskHandle, OSA_TASK(ZPS_task), NULL);

        memset( &sZTimer, 0x0, sizeof(PWR_tsWakeTimerEvent));
        PWR_eScheduleActivity(&sZTimer, WAKEUP_TIMER_VALUE_MS, vWakeCallBackZtimer);
        initialized = TRUE;
    }
    APP_task();
}

/****************************************************************************
 *
 * NAME: ble_task
 *
 * DESCRIPTION:
 * Initialize BLE resources and create BLE tasks
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
static void ble_task(void *argument)
{
    /* Start BLE Platform related resources such as clocks, Link layer and HCI transport to Link Layer */
    (void)APP_InitBle();

    /* Start Host stack */
    BluetoothLEHost_AppInit();

    while(TRUE)
    {
        BluetoothLEHost_HandleMessages();
    }
}

/****************************************************************************
 *
 * NAME: ZPS_task
 *
 * DESCRIPTION:
 * Responsible for triggering the main ZDO OS Task
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
static void ZPS_task(void *argument)
{
    while(1)
    {
        if (OSA_SemaphoreWait((osa_semaphore_handle_t)ZPS_semaphoreHandle, osaWaitForever_c) == KOSA_StatusSuccess)
        {
            APP_ZigbeeMutexLock();
            zps_taskZPS();
            APP_ZigbeeMutexUnlock();
        }
        if(!gUseRtos_c)
        {
            break;
        }
    }
}

/****************************************************************************
 *
 * NAME: APP_task
 *
 * DESCRIPTION:
 * Responsible for running the main router task
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
static void APP_task(void)
{
    while(1)
    {
        if (OSA_SemaphoreWait((osa_semaphore_handle_t)APP_semaphoreHandle, osaWaitForever_c) == KOSA_StatusSuccess)
        {
            APP_ZigbeeMutexLock();
            ZTIMER_vTask();
            APP_taskRouter();
            bdb_taskBDB();
            APP_ZigbeeMutexUnlock();
        }
        if(!gUseRtos_c)
        {
            break;
        }
    }
}

/****************************************************************************
 *
 * NAME: vWakeCallBackZtimer
 *
 * DESCRIPTION:
 * Responsible for triggering the zigbee Application task periodically
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
static void vWakeCallBackZtimer(void)
{
    zbTaskletsSignalApp();
    memset( &sZTimer, 0x0, sizeof(PWR_tsWakeTimerEvent));
    PWR_eScheduleActivity(&sZTimer, WAKEUP_TIMER_VALUE_MS, vWakeCallBackZtimer);
}

/****************************************************************************
 *
 * NAME: zbTaskletsSignalZps
 *
 * DESCRIPTION:
 * Responsible for signaling the ZPS task that event was received
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void zbTaskletsSignalZps(void)
{
    if (initialized)
    {
        OSA_SemaphorePost((osa_semaphore_handle_t)ZPS_semaphoreHandle);
    }
}

/****************************************************************************
 *
 * NAME: zbTaskletsSignalApp
 *
 * DESCRIPTION:
 * Responsible for signaling the APP task that event was received
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void zbTaskletsSignalApp(void)
{
    if (initialized)
    {
        OSA_SemaphorePost((osa_semaphore_handle_t)APP_semaphoreHandle);

    }
}
