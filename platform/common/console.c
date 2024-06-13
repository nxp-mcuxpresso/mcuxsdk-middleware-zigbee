/*!
 * \file console.c
 * \brief ZB platform abstraction implementation for console module
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
#include <stddef.h>

#include "zb_platform.h"

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

bool zbPlatConsoleInit(void)
{
    /* invoke Uart init */
    return zbPlatUartInit(NULL);
}

bool zbPlatConsoleReceiveChar(uint8_t* pu8Data)
{
    /* invoke Uart buffer receive */
    return zbPlatUartReceiveChar(pu8Data);
}

bool zbPlatConsoleCanTransmit(void)
{
    return zbPlatUartCanTransmit();
}

bool zbPlatConsoleTransmit(uint8_t pu8Data)
{
    /* invoke Uart buffer transmit */
    return zbPlatUartTransmit(pu8Data);
}

void zbPlatConsoleSetBaudRate(uint32_t baud)
{
    zbPlatUartSetBaudRate(baud);
}