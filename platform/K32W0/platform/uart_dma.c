/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdint.h>
#include <stdbool.h>
#include "zb_platform.h"
#include "board.h"
#include "app.h"
#include "fsl_usart.h"
#include "UART_Helper.h"

bool zbPlatUartInit(void *device)
{
    (void)device;

    /* Debug console pins are initialized by BOARD_InitHardware */
    vAHI_UartEnable(UART_DMA);

    return true;
}

bool zbPlatUartSetBaudRate(uint32_t baud)
{
    bool result = true;

    if (kStatus_Success != USART_SetBaudRate(UART, baud, CLOCK_GetFreq(kCLOCK_Fro32M)))
    {
        result = false;
    }

    return result;
}

bool zbPlatUartCanTransmit()
{
    return ((kUSART_TxFifoEmptyFlag | kUSART_TxFifoNotFullFlag) & USART_GetStatusFlags(UART));
}

bool zbPlatUartTransmit(uint8_t ch)
{
    USART_WriteByte(UART, ch);
    /* Wait to finish transfer */
    while (!(UART->FIFOSTAT & USART_FIFOSTAT_TXEMPTY_MASK))
    {
    }

    return true;
}

bool zbPlatUartReceiveChar(uint8_t *ch)
{
    bool result        = true;
    if (u16AHI_UartReadRxFifoLevel(UART_DMA))
    {
        *ch = u8AHI_UartReadData(UART_DMA);
        result = true;
    }
    else
    {
        result = false;
    }
    return result;
}

bool zbPlatUartReceiveBuffer(uint8_t *buffer, uint32_t *length)
{
    bool result        = true;
    uint32_t readBytes = 0;
    int i;

    if ((readBytes = u16AHI_UartReadRxFifoLevel(UART_DMA)) == 0)
    {
        result = false;
    }
    else
    {
        for (i = 0; i < readBytes; i++)
        {
            buffer[i] = u8AHI_UartReadData(UART_DMA);
        }
    }

    *length = readBytes;
    return result;
}

void zbPlatUartFree(void)
{
    vAHI_UartDisable(UART_DMA);
}
