/*
* Copyright 2019, 2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef APP_ZIGBEE_H
#define APP_ZIGBEE_H

#include "ZQueue.h"
#include "tsv_pub.h"
#include "bdb_api.h"

/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/
int APP_InitZigbee(void);
bool APP_IsZigbeeReady(void);
void APP_ZigbeeMutexLock(void);
void APP_ZigbeeMutexUnlock(void);
void APP_vInitResources(void);
void APP_vMainLoop(void);
void APP_cbTimerLed(void *pvParam);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern uint8_t u8LedTimer;
extern uint32_t u32Togglems;
/* queue handles */
extern tszQueue APP_msgBdbEvents;
extern tszQueue APP_msgAppEvents;

#endif /* APP_ZIGBEE_H */
