/*
* Copyright 2019, 2024-2025 NXP
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
#include "app_crypto.h"
#include "fsl_gpio.h"
#include "app_crypto.h"
#include "fwk_platform.h"
#include "fsl_component_mem_manager.h"
#include "app_buttons.h"
#include "app_zigbee.h"
#include "app_router_node.h"
#include "app_leds.h"
#include "fsl_os_abstraction.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define APP_NUM_STD_TMRS             (1)

#define APP_QUEUE_SIZE               (1)

#define APP_ZTIMER_STORAGE           ( APP_NUM_STD_TMRS )

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
static void zigbee_task(void *argument);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
uint8_t  u8LedTimer;
/* queue handles */
tszQueue APP_msgAppEvents;
uint32_t u32Togglems;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
static ZTIMER_tsTimer asTimers[APP_ZTIMER_STORAGE + ZIGBEE_TIMER_STORAGE];
static bool zigbeeReady = false;
static OSA_TASK_HANDLE_DEFINE(s_zigbeeTaskHandle);
static OSA_TASK_DEFINE(zigbee_task, gMainThreadPriority_c, 1, gMainThreadStackSize_c, 0);
static OSA_MUTEX_HANDLE_DEFINE(app_zb_mutex);

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
extern void vAppMain(void);

/****************************************************************************
 *
 * NAME: APP_InitZigbee
 *
 * DESCRIPTION:
 * Init Zigbee
 *
 * RETURNS:
 * 0 if success, negative values in case of failure
 *
 ****************************************************************************/
int APP_InitZigbee(void)
{
    int ret = 0;
    osa_status_t status;

    do
    {
        if (PLATFORM_InitTimerManager() < 0)
        {
            ret = -1;
            break;
        }

        CRYPTO_Init();
        CRYPTO_u8RandomInit();

        if(MEM_Init() != kStatus_MemSuccess)
        {
            ret = -2;
            break;
        }

        /* Event processing task */
        status = OSA_TaskCreate((osa_task_handle_t)s_zigbeeTaskHandle, OSA_TASK(zigbee_task), NULL);
        if(status != KOSA_StatusSuccess)
        {
            ret = -3;
            break;
        }

        status = OSA_MutexCreate(app_zb_mutex);
        if(status != KOSA_StatusSuccess)
        {
            ret = -4;
            break;
        }
    } while (false);

    return ret;
}

/****************************************************************************
 *
 * NAME: APP_IsZigbeeReady
 *
 * DESCRIPTION:
 * Check if Zigbee is reeady
 *
 * RETURNS:
 * True if Zigbee is ready
 *
 ****************************************************************************/
bool APP_IsZigbeeReady(void)
{
    return zigbeeReady;
}

/****************************************************************************
 *
 * NAME: APP_ZigbeeMutexLock
 *
 * DESCRIPTION:
 * Locks a mutex used by the Zigbee loop to avoid concurrent access
 * with other tasks.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void APP_ZigbeeMutexLock(void)
{
    osa_status_t status;

    status = OSA_MutexLock(app_zb_mutex, osaWaitForever_c);
    assert(status == KOSA_StatusSuccess);
}

/****************************************************************************
 *
 * NAME: APP_ZigbeeMutexUnlock
 *
 * DESCRIPTION:
 * Unlocks the mutex locked by APP_ZigbeeMutexLock.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void APP_ZigbeeMutexUnlock(void)
{
    osa_status_t status;

    status = OSA_MutexUnlock(app_zb_mutex);
    assert(status == KOSA_StatusSuccess);
}

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
    ZTIMER_eOpen(&u8LedTimer,           APP_cbTimerLed,         NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZQ_vQueueCreate(&APP_msgAppEvents,        APP_QUEUE_SIZE,       sizeof(APP_tsEvent),         NULL);
}

/****************************************************************************
*
* NAME: APP_cbTimerLed
*
* DESCRIPTION:
* Timer callback to to toggle LEDs
*
* PARAMETER:
*
* RETURNS:
*
****************************************************************************/
void APP_cbTimerLed(void *pvParam)
{
    static bool_t bCurrentState = TRUE;

    APP_vSetLed(APP_E_LEDS_LED_2, bCurrentState);

    if( ZPS_bGetPermitJoiningStatus()|| u32Togglems != 250)
    {
        ZTIMER_eStop(u8LedTimer);
        ZTIMER_eStart(u8LedTimer, ZTIMER_TIME_MSEC(u32Togglems));
        bCurrentState = !bCurrentState;
    }
    else
    {
        APP_vSetLed(APP_E_LEDS_LED_2, APP_E_LED_ON);
    }
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
static void zigbee_task(void *argument)
{
    /* Initialize zigbee stack, ressources (timers, queue's etc) and app */
    vAppMain();

    /* 
     * BLE fails to initialize before Zigbee.
     * zigbeeReady is used as a workaround to hang the BLE init execution until zigbee is ready.
     * wireless_uart task will start BLE/Wireless_uart initialization after that.
     * TODO: Fix BLE initialization order constraint, and remove workaround.
     */
    zigbeeReady = true;

    while(true)
    {
        APP_ZigbeeMutexLock();
        /* place event handler code here... */
        APP_vRunZigbee();
        ZTIMER_vTask();
        APP_taskRouter();
        APP_ZigbeeMutexUnlock();
    }
}
