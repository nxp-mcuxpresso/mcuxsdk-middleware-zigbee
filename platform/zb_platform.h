/*
* Copyright 2023 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* ZB Platform and board dependent functions */

#ifndef ZB_PLATFORM_H
#define ZB_PLATFORM_H

#include <stdint.h>
#include <stdbool.h>

/* Button related functions */
typedef void (*button_cb)(uint8_t button);

bool zbPlatButtonInit(uint8_t num_buttons, button_cb cb);
uint32_t zbPlatButtonGetState(void);

/* Led related functions */
bool zbPlatLedInit(uint8_t num_leds);
void zbPlatLedSetState(uint8_t led, uint8_t state);
uint8_t zbPlatLedGetStates();

/* Console related functions */
bool zbPlatConsoleInit(void);
bool zbPlatConsoleReceiveChar(uint8_t *ch);

/* Uart related functions */
bool zbPlatUartInit(void *device);
bool zbPlatUartSetBaudRate(uint32_t baud);
bool zbPlatUartCanTransmit(void);
bool zbPlatUartTransmit(uint8_t ch);
bool zbPlatUartReceiveChar(uint8_t *ch);
bool zbPlatUartReceiveBuffer(uint8_t* buffer, uint32_t *length);
void zbPlatUartFree(void);

/* Time related functions */
uint32_t zbPlatGetTime(void);

/* Watchdog related functions */
/* Registration for callbacks */
void zbPlatWdogIntRegisterPrologue(int (*fp)(void *));
void zbPlatWdogIntRegisterEpilogue(int (*fp)(void *));
void zbPlatWdogRegisterResetCheckCallback(int (*fp)(void *));

/* General management functions */
void zbPlatWdogInit(void);
void zbPlatWdogKick(void);
void zbPlatWdogDeInit(void);

/* Crypto related functions */
uint8_t zbPlatCryptoRandomInit(void);
uint32_t zbPlatCryptoRandomGet(uint32_t u32Min, uint32_t u32Max);
uint32_t zbPlatCryptoRandom256Get(void);

/* Boot-time functions */
void zbPlatWdogResetCheckSource(void);

#endif
