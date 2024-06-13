/*
* Copyright 2023 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#include <stdint.h>
#include <stdbool.h>
#include "board.h"
#include "fsl_common.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include "fsl_os_abstraction.h"
#include "pin_mux.h"

#include "zb_platform.h"

/* Use Debug port */
#define BOARD_UART_INSTANCE (BOARD_DEBUG_UART_INSTANCE)

#ifdef DUAL_MODE_APP

static LPUART_Type *const lpuart_base[] = LPUART_BASE_PTRS;

bool zbPlatUartInit(void *device)
{
    (void)device;

    /* Pins and UART configurations ar part of BOARD init code */
    BOARD_InitDebugConsole();

    return true;
}

bool zbPlatUartSetBaudRate(uint32_t baud)
{
    bool result = true;

    if (kStatus_Success !=
        LPUART_SetBaudRate(lpuart_base[BOARD_UART_INSTANCE], baud,
                BOARD_DEBUG_UART_CLK_FREQ))
    {
        result = false;
    }

    return result;
}

bool zbPlatUartCanTransmit(void)
{
    return true;
}

bool zbPlatUartTransmit(uint8_t ch)
{
    bool result = true;

    if (DbgConsole_Putchar(ch) != 1)
    {
        result = false;
    }

    return result;
}

bool zbPlatUartReceiveChar(uint8_t *ch)
{

    bool result = false;
    if (kStatus_Success == DbgConsole_TryGetchar((char *)ch))
    {
        result = true;
    }

    return result;
}

bool zbPlatUartReceiveBuffer(uint8_t *buffer, uint32_t *length)
{
    bool result         = false;
    uint32_t u32Counter = 0;

    for (u32Counter = 0; u32Counter < *length; u32Counter++)
    {
        if (kStatus_Success != DbgConsole_TryGetchar((char *)&buffer[u32Counter]))
            break;
        result = true;
    }
    *length = u32Counter;
    return result;
}

void zbPlatUartFree(void)
{
    return;
}
#endif /* DUAL_MODE_APP */
