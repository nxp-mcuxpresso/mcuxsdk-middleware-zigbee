/*
* Copyright 2019, 2023-2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef APP_ZIGBEE_H
#define APP_ZIGBEE_H

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "ZQueue.h"
#include "ZTimer.h"
#include "bdb_api.h"

/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/
int APP_InitZigbee(void);
bool APP_IsZigbeeReady(void);
void APP_vInitResources(void);
void APP_cbTimerId(void *pvParam);
void APP_cbTimerLed(void *pvParam);

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
