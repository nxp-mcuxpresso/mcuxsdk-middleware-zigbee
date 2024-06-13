/*!
 * \file uart.c
 * \brief ZB platform abstraction implementation for uart module
 *
 * Copyright 2024 NXP
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "zb_platform.h"
#include "fsl_debug_console.h"

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

bool zbPlatUartInit(void *device)
{
    /* We are using the debug console which is already initialized in BOARD_InitHardware */
    (void)device;
    return true;
}

bool zbPlatUartSetBaudRate(uint32_t baud)
{
    /* NOT IMPLEMENTED */
    (void)baud;
    return true;
}

bool zbPlatUartCanTransmit(void)
{
    /* NOT IMPLEMENTED */
    return true;
}

bool zbPlatUartTransmit(uint8_t ch)
{
    bool ret = true;

    if(DbgConsole_Putchar(ch) != ch)
    {
        ret = false;
    }

    return ret;
}

bool zbPlatUartReceiveChar(uint8_t *ch)
{
    bool ret = false;

    if(DbgConsole_TryGetchar((char *)ch) == kStatus_Success)
    {
        ret = true;
    }

    return ret;
}

bool zbPlatUartReceiveBuffer(uint8_t *buffer, uint32_t *length)
{
    bool ret = false;
    uint32_t cnt = 0U;

    for (cnt = 0; cnt < *length; cnt++)
    {
        if (!zbPlatUartReceiveChar(&buffer[cnt]))
            break;
        ret = true;
    }
    *length = cnt;
    return ret;
}

void zbPlatUartFree(void)
{
    /* NOT IMPLEMENTED */
    return;
}
