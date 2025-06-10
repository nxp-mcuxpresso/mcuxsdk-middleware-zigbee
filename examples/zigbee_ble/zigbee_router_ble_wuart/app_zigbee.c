/*
* Copyright 2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "fwk_platform_ics.h"

/* ble includes */
#include "gap_types.h"
#include "wireless_uart.h"

#include "zb_platform.h"
#include "EmbeddedTypes.h"

#include "ZQueue.h"
#include "ZTimer.h"
#include "zigbee_config.h"
#include "app_crypto.h"
#include "fsl_gpio.h"
#include "fwk_platform.h"
#include "fsl_component_mem_manager.h"
#include "app_router_node.h"
#include "app_uart.h"
#include "app_buttons.h"
#include "app_zigbee.h"
#include "app_leds.h"
#include "zps_apl_zdo.h"
#include "bdb_DeviceCommissioning.h"
#include "fsl_os_abstraction.h"
#include "fsl_component_serial_manager.h"

#include "app_shell.h"
#include "zigbee_config.h"
#include "fsl_format.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define APP_NUM_STD_TMRS             (1)
#define APP_QUEUE_SIZE               (1)

#define APP_ZTIMER_STORAGE           ( APP_NUM_STD_TMRS )

extern SERIAL_MANAGER_HANDLE_DEFINE(s_writeHandle);
#define APP_Serial_Print(a)         do{ \
                                            union \
                                            { \
                                                const char *pStr; \
                                                uint8_t *pUint8; \
                                            } temp; \
                                            temp.pStr = (a); \
                                            (void)SerialManager_WriteBlocking((serial_write_handle_t)s_writeHandle, (uint8_t *)temp.pUint8, strlen(temp.pStr)); \
                                        } while(0);
#define APP_Serial_PrintHex(a)      (void)SerialManager_WriteBlocking((serial_write_handle_t)s_writeHandle, FORMAT_Hex2Ascii(a), strlen((const char*)FORMAT_Hex2Ascii(a)))

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
#define COMMAND_BUF_SIZE   250

typedef struct
{
    uint8_t  au8Buffer[COMMAND_BUF_SIZE];
    uint8_t  u8Pos;
}tsCommand;

#define stricmp strcasecmp

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
/* timers */
uint8_t  u8LedTimer;
/* queue handles */
tszQueue APP_msgAppEvents;
uint32_t u32Togglems;

extern BDB_tsOobWriteDataToCommission bdb_oob;

OSA_MUTEX_HANDLE_DEFINE(app_zigbee_mutex);

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
static ZTIMER_tsTimer asTimers[APP_ZTIMER_STORAGE + ZIGBEE_TIMER_STORAGE];

static tsCommand sCommand;

static bool_t bleDoStackStop = FALSE;
static bool_t zbDoFactoryReset = FALSE;

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

    status = OSA_MutexLock(app_zigbee_mutex, osaWaitForever_c);
    assert(status == KOSA_StatusSuccess);
    (void)status;
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

    status = OSA_MutexUnlock(app_zigbee_mutex);
    assert(status == KOSA_StatusSuccess);
    (void)status;
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
    ZTIMER_eOpen(&u8LedTimer,           APP_cbTimerLed,  NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZQ_vQueueCreate(&APP_msgAppEvents,  APP_QUEUE_SIZE,  sizeof(APP_tsEvent),         NULL);
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

/****************************************************************************
 *
 * NAME: APP_ZigbeeShellCommand
 *
 * DESCRIPTION:
 * Process received Zigbee Shell command
 *
 * PARAMETERS: Name        RW  Usage
 *             buffer      Received command
 *             length      Received command length
 *
 * RETURNS: none
 *
 ****************************************************************************/
void APP_ZigbeeShellCommand(uint8_t *buffer, uint32_t length)
{
    const uint8_t ASCII_CR = 0x0D;
    const uint8_t ASCII_LF = 0x0A;
    static uint8_t u8PreviousIsCR = 0;

    if (buffer)
    {
        for (int i = 0; i < length; i++)
        {
            uint8_t u8Char = buffer[i];

            if ((sCommand.u8Pos < COMMAND_BUF_SIZE)  && (u8Char != ASCII_CR) && (u8Char != ASCII_LF))
            {
                sCommand.au8Buffer[sCommand.u8Pos++] = u8Char;
            }
            else if (sCommand.u8Pos >= COMMAND_BUF_SIZE)
            {
                APP_Serial_Print("OverFlow\r\n");
                memset(sCommand.au8Buffer, 0, COMMAND_BUF_SIZE);
                sCommand.u8Pos = 0;
            }

            if (u8Char == ASCII_CR)
            {
                if (sCommand.u8Pos)
                {
                    SHELL_ZigbeeProcessCommand(sCommand.au8Buffer, sCommand.u8Pos);
                    memset(sCommand.au8Buffer, 0, COMMAND_BUF_SIZE);
                    sCommand.u8Pos = 0;
                }
                u8PreviousIsCR = 1;
            }
            else if (u8Char == ASCII_LF)
            {
                if (u8PreviousIsCR)
                {
                    /* CRLF, so skip the LF line break */
                    u8PreviousIsCR = 0;
                }
                else
                {
                    if (sCommand.u8Pos)
                    {
                        SHELL_ZigbeeProcessCommand(sCommand.au8Buffer, sCommand.u8Pos);
                        memset(sCommand.au8Buffer, 0, COMMAND_BUF_SIZE);
                        sCommand.u8Pos = 0;
                    }
                }
            }
            else
            {
                u8PreviousIsCR = 0;
            }
        }
    }
    else
    {
        APP_Serial_Print("Invalid zigbee shell command buffer\n");
    }
}

/*! *********************************************************************************
* \brief  Process any event from Ble and take action depending of the event
*
* \param[in] pParam
*
********************************************************************************** */
void APP_ZigbeeProcessBleEvent(void *pParam)
{
    eDualModeEvent event = (eDualModeEvent) pParam;
    switch (event)
    {
        case eBleAdvStopEvent:
        case eBleDisconnectionEvent:
        case eBleNotRunningEvent:
            /* was Ble Stop requested */
            if (!bleDoStackStop)
            {
                /* restart Ble advertise */
                BleApp_Start(gGapPeripheral_c);
            }
            else if (bleDoStackStop && zbDoFactoryReset)
            {
                APP_tsEvent sButtonEvent;

                sButtonEvent.eType = APP_E_EVENT_POR_FACTORY_RESET;
                APP_ZigbeeMutexLock();
                if(!ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent))
                {
                    APP_Serial_Print("FACTORY_RESET_FAILURE");
                }
                APP_ZigbeeMutexUnlock();
                zbDoFactoryReset = FALSE;
            }
            bleDoStackStop = FALSE;
            break;
        case e15_4FactoryResetEvent:
            bleDoStackStop = TRUE;
            zbDoFactoryReset = TRUE;
            BleApp_Stop();
            break;
        default:
            break;
    }
}

/*! *********************************************************************************
* \brief  Print NWK Key obtained from OOB info
*
*
********************************************************************************** */
void APP_PrintZigbeeNwkKey(void)
{
    APP_Serial_Print("Zigbee NWK key ---> ");
    for (uint8_t i = 0; i < ZB_OOB_KEY_SIZE; i++)
    {
        APP_Serial_PrintHex(bdb_oob.pu8NwkKey[i]);
    }
    APP_Serial_Print("\n");
}
