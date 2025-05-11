/*
* Copyright 2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef APP_ZIGBEE_H
#define APP_ZIGBEE_H

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "ZQueue.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define ZIGBEE_ADVERTISE_NAME       "NXP_ZIR"

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef enum {
    eBleAdvStopEvent,
    eBleDisconnectionEvent,
    eBleNotRunningEvent,
    e15_4FactoryResetEvent,
} eDualModeEvent;

/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/
void APP_InitZigbee(void);
void APP_vInitResources(void);
void APP_cbTimerId(void *pvParam);
void APP_cbTimerLed(void *pvParam);
void APP_ZigbeeShellCommand(uint8_t *buffer, uint32_t length);
void APP_ZigbeeProcessBleEvent(void *pParam);
void APP_PrintZigbeeNwkKey(void);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
/* timers */
extern uint8_t u8TimerId;
extern uint8_t  u8LedTimer;
/* queue handles */
extern tszQueue APP_msgSerialRx;
extern tszQueue APP_msgAppEvents;

extern uint32_t u32Togglems;

#endif /* APP_ZIGBEE_H */
