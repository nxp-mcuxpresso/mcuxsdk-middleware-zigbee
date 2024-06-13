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
#include "fsl_lpuart_edma.h"
#include "fsl_os_abstraction.h"
#include "pin_mux.h"

#include "zb_platform.h"

/* Use Debug port */
#define BOARD_UART_INSTANCE (BOARD_DEBUG_UART_INSTANCE)

#define LPUART_RX_DMA_CHANNEL 1
#define LPUART_DMA_BASEADDR DMA0
#define EDMA_INSTANCE 0

#if (BOARD_UART_INSTANCE == 0)
#define LPUART_RX_DMA_REQUEST kDmaRequestLPUART0Rx
#elif (BOARD_UART_INSTANCE == 1)
#define LPUART_RX_DMA_REQUEST kDmaRequestLPUART1Rx
#else
#error "No LPUART IRQHandler defined"
#endif

static LPUART_Type *const lpuart_base[] = LPUART_BASE_PTRS;
static const IRQn_Type lpuart_irqs[] = LPUART_RX_TX_IRQS;
static const IRQn_Type edma_irqs[][FSL_FEATURE_EDMA_MODULE_CHANNEL] = DMA_IRQS;

static edma_handle_t rx_dma_handle;

static volatile uint32_t dmaRxTransfers;
static volatile uint32_t receivedBytes;
static volatile uint32_t ringBufferIndex;

#define RING_BUFFER_SIZE (1024)

/* allocate ring buffer section. */
AT_NONCACHEABLE_SECTION_INIT(uint8_t ringBuffer[RING_BUFFER_SIZE]) = {0};

/* Allocate TCD memory poll with ring buffer used. */
AT_QUICKACCESS_SECTION_DATA_ALIGN(static edma_tcd_t tcdMemoryPoolPtr[1], sizeof(edma_tcd_t));

static void RxTransferComplete(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds)
{
    dmaRxTransfers++;
}

static void UartInitEDMA(void)
{
    edma_config_t config;

    /* Init the EDMA module */
    EDMA_GetDefaultConfig(&config);
    EDMA_Init(LPUART_DMA_BASEADDR, &config);
    EDMA_CreateHandle(&rx_dma_handle, LPUART_DMA_BASEADDR, LPUART_RX_DMA_CHANNEL);
    EDMA_SetChannelMux(LPUART_DMA_BASEADDR, LPUART_RX_DMA_CHANNEL, LPUART_RX_DMA_REQUEST);
}

/* Start ring buffer. */
static void SartRingBufferEDMA(void)
{
    edma_transfer_config_t xferConfig;

    /* Install TCD memory for using only one TCD queue. */
    EDMA_InstallTCDMemory(&rx_dma_handle, (edma_tcd_t *)&tcdMemoryPoolPtr[0], 1U);

    /* Prepare transfer to receive data to ring buffer. */
    EDMA_PrepareTransfer(&xferConfig, (void *)(uint32_t *)LPUART_GetDataRegisterAddress(lpuart_base[BOARD_UART_INSTANCE]),
                         sizeof(uint8_t), ringBuffer, sizeof(uint8_t), sizeof(uint8_t), RING_BUFFER_SIZE,
                         kEDMA_PeripheralToMemory);

    /* Submit transfer. */
    rx_dma_handle.tcdUsed = 1U;
    rx_dma_handle.tail    = 0U;
    EDMA_TcdReset(&rx_dma_handle.tcdPool[0U]);
    EDMA_TcdSetTransferConfig(&rx_dma_handle.tcdPool[0U], &xferConfig, tcdMemoryPoolPtr);

    /* Enable major interrupt for counting received bytes. */
    EDMA_TcdEnableInterrupts(&rx_dma_handle.tcdPool[0U], kEDMA_MajorInterruptEnable);

    /* There is no live chain, TCD block need to be installed in TCD registers. */
    EDMA_InstallTCD(rx_dma_handle.base, rx_dma_handle.channel, &rx_dma_handle.tcdPool[0U]);

    /* Setup call back function. */
    EDMA_SetCallback(&rx_dma_handle, RxTransferComplete, NULL);

    /* Start EDMA transfer. */
    EDMA_StartTransfer(&rx_dma_handle);

    /* Enable LPUART RX EDMA. */
    LPUART_EnableRxDMA(lpuart_base[BOARD_UART_INSTANCE], true);

    /* Enable RX interrupt for detecting the IDLE line interrupt. */
    LPUART_EnableInterrupts(lpuart_base[BOARD_UART_INSTANCE], kLPUART_IdleLineInterruptEnable |  kLPUART_RxOverrunInterruptEnable);
}

#if (BOARD_UART_INSTANCE == 0)
void LPUART0_IRQHandler(void)
#elif (BOARD_UART_INSTANCE == 1)
void LPUART1_IRQHandler(void)
#else
#error "No LPUART IRQHandler defined"
#endif

{
    uint32_t status            = LPUART_GetStatusFlags(lpuart_base[BOARD_UART_INSTANCE]);
    uint32_t enabledInterrupts = LPUART_GetEnabledInterrupts(lpuart_base[BOARD_UART_INSTANCE]);
    if (status & kLPUART_RxOverrunFlag)
    {
        /* Assert if rx overrun */
        assert(false);
    }

    /* If new data arrived. */
    if ((0U != ((uint32_t)kLPUART_IdleLineFlag & status)) &&
        (0U != ((uint32_t)kLPUART_IdleLineInterruptEnable & enabledInterrupts)))
    {
        (void)LPUART_ClearStatusFlags(lpuart_base[BOARD_UART_INSTANCE], kLPUART_IdleLineFlag);

        uint32_t edmaCount = EDMA_GetRemainingMajorLoopCount(LPUART_DMA_BASEADDR, LPUART_RX_DMA_CHANNEL);
        if ((edmaCount == 0) || (edmaCount == RING_BUFFER_SIZE))
        {
            if (NVIC_GetPendingIRQ(edma_irqs[EDMA_INSTANCE][LPUART_RX_DMA_CHANNEL]))
            {
                return;
            }
        }
        receivedBytes = RING_BUFFER_SIZE - edmaCount;
        receivedBytes += (RING_BUFFER_SIZE * dmaRxTransfers) - ringBufferIndex;

        /* Data has been overriden in the circular buffer */
        if (receivedBytes > RING_BUFFER_SIZE)
        {
            assert(false);
        }
    }
}

bool zbPlatUartInit(void *device)
{
    (void)device;

    /* Pins and UART configurations ar part of BOARD init code */
    BOARD_InitDebugConsole();

    /* Enable UART RX interrupts */
    LPUART_EnableInterrupts(lpuart_base[BOARD_UART_INSTANCE], kLPUART_RxDataRegFullInterruptEnable | kLPUART_RxOverrunInterruptEnable);

    UartInitEDMA();
    SartRingBufferEDMA();

    EnableIRQ(lpuart_irqs[BOARD_UART_INSTANCE]);

    return true;
}

bool zbPlatUartSetBaudRate(uint32_t baud)
{
    bool result = true;

    if (kStatus_Success !=
        LPUART_SetBaudRate(lpuart_base[BOARD_UART_INSTANCE], baud, CLOCK_GetFreq(kCLOCK_ScgSircClk)))
    {
        result = false;
    }

    return result;
}

bool zbPlatUartCanTransmit(void)
{
    return (kLPUART_TxFifoEmptyFlag & LPUART_GetStatusFlags(lpuart_base[BOARD_UART_INSTANCE]));
}

bool zbPlatUartTransmit(uint8_t ch)
{
    bool result = true;

    if (kStatus_Success != LPUART_WriteBlocking(lpuart_base[BOARD_UART_INSTANCE], &ch, 1))
    {
        result = false;
    }
    return result;
}

bool zbPlatUartReceiveChar(uint8_t *ch)
{
    bool result = false;

    if (receivedBytes > 0)
    {
        OSA_InterruptDisable();
        *ch = ringBuffer[ringBufferIndex++];
        if (ringBufferIndex == RING_BUFFER_SIZE)
        {
            ringBufferIndex = 0U;
            dmaRxTransfers--;
        }
        receivedBytes--;
        OSA_InterruptEnable();
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
        if (!zbPlatUartReceiveChar(&buffer[u32Counter]))
            break;
        result = true;
    }
    *length = u32Counter;
    return result;
}

void zbPlatUartFree(void)
{
    /* Disable interrupt */
    DisableIRQ(lpuart_irqs[BOARD_UART_INSTANCE]);

    /* Disable RX interrupts */
    LPUART_DisableInterrupts(lpuart_base[BOARD_UART_INSTANCE], kLPUART_RxDataRegFullInterruptEnable |
            kLPUART_IdleLineInterruptEnable |  kLPUART_RxOverrunInterruptEnable);

    /* Deinitialize the eDMA peripheral */
    EDMA_Deinit(LPUART_DMA_BASEADDR);

    /* Deinitialize debug console */
    BOARD_UninitDebugConsole();

    return;
}
