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
#include "app_coordinator.h"
#include "app_uart.h"
#include "app_buttons.h"
#include "app_zigbee.h"
#include "app_leds.h"
#include "zps_apl_zdo.h"
#include "PDM.h"
#include "fsl_os_abstraction.h"
#include "fsl_component_serial_manager.h"

#include "app_shell.h"
#include "zigbee_config.h"
#include "fsl_format.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define APP_NUM_STD_TMRS             (2)
#define APP_QUEUE_SIZE               (1)

#define APP_ZTIMER_STORAGE           ( APP_NUM_STD_TMRS )

/* Serial Handle obtained from BLE */
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
#define COMMAND_BUF_SIZE   200

typedef struct
{
    uint8_t  au8Buffer[COMMAND_BUF_SIZE];
    uint8_t  u8Pos;
}tsCommand;

#define stricmp strcasecmp

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
static void APP_vInitialise(void);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
/* timers */
uint8_t u8TimerId;
uint8_t  u8LedTimer;
/* queue handles */
tszQueue APP_msgAppEvents;
uint32_t u32Togglems;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
static ZTIMER_tsTimer asTimers[APP_ZTIMER_STORAGE + ZIGBEE_TIMER_STORAGE];

static tsCommand sCommand;

static bool_t bleDoStackStop = FALSE;
static bool_t zbDoFactoryReset = FALSE;



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
void APP_InitZigbee(void)
{

#if IS_MCXW_SERIES
    PLATFORM_SwitchToOsc32k();
#endif

    CRYPTO_Init();
    CRYPTO_u8RandomInit();
    MEM_Init();

#if IS_MCXW_SERIES
#if defined(USE_NBU) && (USE_NBU == 1)
    PLATFORM_InitNbu();
    PLATFORM_InitMulticore();
    PLATFORM_FwkSrvInit();
    PLATFORM_SendChipRevision();
    PLATFORM_LoadHwParams();
#endif
#endif

    vAppMain();
}

/****************************************************************************
 *
 * NAME: vAppMain
 *
 * DESCRIPTION:
 * Entry point for application from a cold start.
 *
 * RETURNS:
 * Never returns.
 *
 ****************************************************************************/
void vAppMain(void)
{
    APP_vLedInitialise();
    APP_vInitResources();
    APP_vInitZigbeeResources();
    APP_vInitialise();
    BDB_vStart();
}

/****************************************************************************
 *
 * NAME: APP_vInitialise
 *
 * DESCRIPTION:
 * Initialises Zigbee stack, hardware and application.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
static void APP_vInitialise(void)
{
    /* Initialise the Persistent Data Manager */
    PDM_eInitialise(1200, 63, NULL);

    /* Initialise application */
    APP_vInitialiseCoordinator();
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
    ZTIMER_eOpen(&u8TimerId,            APP_cbTimerId,   NULL, ZTIMER_FLAG_PREVENT_SLEEP);
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
    if( ZPS_bGetPermitJoiningStatus()|| u32Togglems != 500)
    {
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
                if(!ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent))
                {
                    APP_Serial_Print("FACTORY_RESET_FAILURE");
                }
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
* \brief  Print Zigbee plain NWK Key
*
*
********************************************************************************** */
void APP_PrintZigbeeNwkKey(void)
{
    /* Print Network Key */
    uint8* pu8Key =  ( uint8* ) ZPS_pvNwkSecGetNetworkKey ( ZPS_pvAplZdoGetNwkHandle( ));

    APP_Serial_Print("Zigbee NWK key ---> ");
    for (uint8_t i = 0; i < ZB_OOB_KEY_SIZE; i++)
    {
        APP_Serial_PrintHex(pu8Key[i]);
    }
    APP_Serial_Print("\n");
}

