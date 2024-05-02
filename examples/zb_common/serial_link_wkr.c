/*
* Copyright 2023 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef TRACE_SERIAL_LINK
#define TRACE_SERIAL_LINK            FALSE
#endif

#define TRACE_SERIAL_ERROR  TRUE

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include <string.h>
#include <dbg.h>
#include "serial_link_wkr.h"
#include "portmacro.h"
#ifdef SL_JN_TO_HOST_SECURE
#include "aessw_ccm.h"
#endif
#include "app_common.h"
#include "ZTimer.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define MAX_BYTES_WITHIN_200MS_ON_115k2_BAUD        500

#define UART_BAUD_RATE_SETTINGS_ADDRESS (0x00080010UL)
#define UART_ACKS_SETTINGS_ADDRESS      (0x00080011UL)
#define UART_BAUD_RATE_115k2    (115200UL)
#define UART_BAUD_RATE_1M       (1000000UL)
#define UART_115k2_SETTINGS             (0x00U)
#define UART_1M_SETTINGS                (0x01U)
#define UART_ACKS_DISABLED              (0x00U)
#define UART_ACKS_ENABLED               (0x01U)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/* Enumerated list of states for receive state machine */
typedef enum
{
    E_STATE_RX_WAIT_START,
    E_STATE_RX_WAIT_TYPEMSB,
    E_STATE_RX_WAIT_TYPELSB,
    E_STATE_RX_WAIT_LENMSB,
    E_STATE_RX_WAIT_LENLSB,
    E_STATE_RX_WAIT_TX_SEQ_NO,
    E_STATE_RX_WAIT_RX_SEQ_NO,
    E_STATE_RX_WAIT_CRC,
    E_STATE_RX_WAIT_DATA,
}teSL_RxState;

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

PRIVATE uint8 u8SL_CalculateCRC( uint16 u16Type,
                                 uint16 u16Length,
                                 uint8 u8TxSeq,
                                 uint8 u8RxSeq,
                                 uint8 *pu8Data,
                                 PDUM_thAPduInstance hAPduInst);
PRIVATE void vSL_TxByte(bool bSpecialCharacter, uint8 u8Data);

#ifdef SL_JN_TO_HOST_SECURE
PRIVATE bool_t SEC_bDecryptBlock(uint8 *pu8Data, uint16 u16Length, uint8 *pu8Mic);
PRIVATE void SEC_vEncryptBlock(uint8 *pu8Data, uint16 u16Length, uint8 *pu8Mic, PDUM_thAPduInstance hAPduInst);
PUBLIC bool_t bAES_CCMstar_Local(
            AESSW_Block_u *puKeyData,
            bool_t         bLoadKey,
            uint8          u8AESmode,
            uint8          u8M,
            uint8          u8alength,
            uint16          u8mlength,
            AESSW_Block_u *puNonce,
            uint8         *pau8authenticationData,
            uint8         *pau8inputData,
            uint8         *pau8checksumData,
            bool_t        *pbChecksumVerify);

PUBLIC bool_t bAES_CCMstar_Encrypt2Buffer(
            AESSW_Block_u *puKeyData,
            bool_t         bLoadKey,
            uint8          u8AESmode,
            uint8          u8M,
            uint8          u8alength,
            uint16          u8mlength,
            AESSW_Block_u *puNonce,
            uint8         *pau8authenticationData,
            uint8         *pau8inputData,
            uint8         *pau8checksumData,
            uint16         u16Length2,
            uint8          *pu8inputData2);
#endif

#ifdef SERIAL_DEBUG
PRIVATE void vLogInit(void);
PRIVATE void vLogPutch(char c);
PRIVATE void vLogFlush(void);
PRIVATE void vLogAssert(void);
#endif

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
volatile teSL_AckState eAckState;
extern uint16 u16AckTimeout;
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
static teSL_RxState eRxState = E_STATE_RX_WAIT_START;
#ifdef SERIAL_DEBUG
uint8   au8LogBuffer[256];
uint8   u8LogStart = 0;
uint8   u8LogEnd   = 0;
bool_t  bLogging = FALSE;
#endif
PRIVATE bool_t bSL_UARTMutex = FALSE;
PRIVATE uint32_t sIntStore;

uint8 u8JNTxSeqNo = 0;

uint8 u8LPCLastTxSeqNo;

uint32 u32SLRxCount = 0;
uint32 u32SLRxFail = 0;

uint32 u32SLTxStatusMsg = 0;
uint32 u32SLTxEventMsg = 0;
uint32 u32SLTxRetries = 0;
uint32 u32SLTxFailures = 0;
uint32 u32SL5Ms = 0;
uint32 u32SL8Ms = 0;
uint32 u32SL10Ms = 0;
uint32 u32Greater10Ms = 0;

uint32 u32OverwrittenRXMessage = 0;

PRIVATE uint8 u8LastLpxTxSeqNo = 0;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PRIVATE INLINE uint8 u8ReadUARTAcksSettings(void)
{
#ifdef ENABLE_UART_ACK_FROM_HOST
    return UART_ACKS_ENABLED;
#else
    return UART_ACKS_DISABLED;
#endif
}

PUBLIC void vAppSwDelayOneUs(void)
{
    uint8 i=0u;

    asm volatile (" isb");
    while (i < 8)
    {
        asm volatile ("and r0, r0");
        i++;
    }
}

PUBLIC void vAppSwDelayMs(uint32 ms)
{
    uint32 i = 1000U * ms;
    while(i--)
    {
        vAppSwDelayOneUs();
    }
}
/****************************************************************************
 *
 * NAME: Get_UartRxState
 *
 * DESCRIPTION:
 * Get the state of the uart
 *
 * PARAMETERS:  Void
 *
 * RETURNS: Uart State
 *
 ****************************************************************************/
PUBLIC uint8 Get_UartRxState(void)
{
    uint8 status;
    return (status = (eRxState)?1:0);
}
/****************************************************************************
 *
 * NAME: vSL_Mutex
 *
 * DESCRIPTION:
 * Get address of UART mutex
 *
 * PARAMETERS:  Void
 *
 * RETURNS: Pointer to UART mutex
 *
 ****************************************************************************/
PUBLIC void* vSL_Mutex(void)
{
    return &bSL_UARTMutex;
}

PUBLIC void vGetSerialMutex( void)
{
    ZPS_eEnterCriticalSection((void*)vSL_Mutex, (uint32*)&sIntStore);
}

PUBLIC void vFreeSerialMutex( void)
{
    ZPS_eExitCriticalSection((void*)vSL_Mutex, (uint32*)&sIntStore);
}

/*************  ***************************************************************
 *
 * NAME: bSL_ReadMessage
 *
 * DESCRIPTION:
 * Attempt to read a complete message from the serial link
 *
 * PARAMETERS  Name                    RW  Usage
 *             pu16Type                W   Location to store incoming message type
 *             pu16Length              W   Location to store incoming message length
 *             u16MaxLength            R   Length of allocated message buffer
 *             pu8Message              W   Location to store message payload
 *             u8Data                  R   UART data byte
 *
 * RETURNS:
 * TRUE if a complete valid message has been received
 *
 ****************************************************************************/
PUBLIC bool bSL_ReadMessage(uint16 *pu16Type,
                            uint16 *pu16Length,
                            uint16 u16MaxLength,
                            uint8 *pu8Seq,
                            uint8 *pu8Message,
                            uint8 u8Data)
{

    static uint8 u8CRC;
    static uint16 u16Bytes;
    static bool bInEsc = FALSE;
    static uint16 u16Type = 0, u16Length = 0;
    static uint8 u8TxSeqNo = 0;
    static uint8 u8RxSeqNo = 0;
    switch(u8Data)
    {
    case SL_START_CHAR:
        /* Reset state machine */
        u16Bytes = 0;
        bInEsc = FALSE;
        if (eRxState != E_STATE_RX_WAIT_START)
        {
            DBG_vPrintf(TRACE_SERIAL_ERROR, "Unexpected start char on state %d\n", eRxState);
        }
        DBG_vPrintf(TRACE_SERIAL_LINK, "\nRX Start ");
        eRxState = E_STATE_RX_WAIT_TYPEMSB;
        break;

    case SL_ESC_CHAR:
        /* Escape next character */
        bInEsc = TRUE;
        break;

    case SL_END_CHAR:
        /* End message */
        DBG_vPrintf(TRACE_SERIAL_LINK, "\nGot END");
        eRxState = E_STATE_RX_WAIT_START;
        if (u16Bytes < u16Length)
        {
            DBG_vPrintf(TRACE_SERIAL_ERROR, "Unexpected end char got %d expected %d Type %04x\n",
                    u16Bytes, u16Length, u16Type);
        }
        if((u16Length < u16MaxLength) && (u16Length == u16Bytes))
        {
#ifdef SL_JN_TO_HOST_SECURE
            if(u16Length > 8)
            {
                u16Length -= 8;
                if(SEC_bDecryptBlock(pu8Message, u16Length, pu8Message+(u16Length)) == FALSE)
                {
                    /* Bad MIC is a fatal error as the JN and the Arm are now out of sync */
                    /* Need to watchdog and reboot */
                    DBG_vPrintf(TRACE_SERIAL_LINK, "\nDecryption fail");
                    return FALSE;
                }
            }
#endif
            if(u8CRC == u8SL_CalculateCRC(u16Type, u16Length, u8TxSeqNo, u8RxSeqNo, pu8Message,NULL))
            {
                if(u16Type == E_SL_MSG_HOST_JN_ACK)
                {
                    DBG_vPrintf(TRACE_SERIAL_LINK, "\n Host ACK received");
                    eAckState = E_STATE_ACK_RECEIVED;
                    return(FALSE);
                }
                if(u16Type == E_SL_MSG_HOST_JN_NACK)
                {
                    eAckState = E_STATE_NACK_RECEIVED;
                    return(FALSE);
                }
                /* CRC matches - valid packet */
                u32SLRxCount++;

                *pu16Type = u16Type;
                *pu16Length = u16Length;
                *pu8Seq = u8TxSeqNo;
                u8LastLpxTxSeqNo = u8RxSeqNo;
            //  DBG_vPrintf(TRACE_SERIAL_LINK|1, "\nbSL_ReadMessage(%04x, Tx Seq %d, Rx Seq %d CRC %02x)\n",
            //                          u16Type, u8TxSeqNo, u8RxSeqNo, u8CRC);
                return(TRUE);
            }
            else
            {
                Send_Nack_Host_JN();
                u32SLRxFail++;
                DBG_vPrintf(TRACE_SERIAL_ERROR, "CRC Failure\n");
            }
        }
        DBG_vPrintf(TRACE_SERIAL_LINK, "\nCRC BAD");
        break;

    default:
        if(bInEsc)
        {
            /* Unescape the character */
            u8Data ^= 0x8;
            bInEsc = FALSE;
        }
        DBG_vPrintf(TRACE_SERIAL_LINK, "\nData 0x%x", u8Data & 0xFF);

        switch(eRxState)
        {
        case E_STATE_RX_WAIT_START:
            break;

        case E_STATE_RX_WAIT_TYPEMSB:
            u16Type = (uint16)u8Data << 8;
            eRxState++;
            break;

        case E_STATE_RX_WAIT_TYPELSB:
            u16Type += (uint16)u8Data;
            DBG_vPrintf(TRACE_SERIAL_LINK, "\nType 0x%x", u16Type & 0xFFFF);
            eRxState++;
            break;

        case E_STATE_RX_WAIT_LENMSB:
            u16Length = (uint16)u8Data << 8;
            eRxState++;
            break;

        case E_STATE_RX_WAIT_LENLSB:
            u16Length += (uint16)u8Data;
            DBG_vPrintf(TRACE_SERIAL_LINK, "\nLength %d", u16Length);
            if(u16Length > u16MaxLength)
            {
                uint8 au8String[] = "LNP"; /*Length Not Proper (LNP)*/
                vSL_WriteMessage(E_SL_MSG_EXCEPTION, 4,NULL, au8String);
                u16PacketType = 0;
                DBG_vPrintf(TRACE_SERIAL_LINK, "\nLength > MaxLength");
                u32SLRxFail++;
                eRxState = E_STATE_RX_WAIT_START;
            }
            else
            {
                if ( (u16Type == (uint16)E_SL_MSG_GET_VERSION) ||
                     (u16Type == E_SL_MSG_GET_PIB_ATTR) )
                {
                    eRxState = E_STATE_RX_WAIT_CRC;
                    u8TxSeqNo = 0;
                    u8RxSeqNo = 0;

                }
                else
                {
                    eRxState++;
                }
            }
            break;

        case E_STATE_RX_WAIT_TX_SEQ_NO:
            u8TxSeqNo = u8Data;
            //DBG_vPrintf(1, "Got Rx seq No %d\n", u8TxSeqNo);
            eRxState++;
            break;

        case E_STATE_RX_WAIT_RX_SEQ_NO:
            u8RxSeqNo = u8Data;
            //DBG_vPrintf(1, "Got Rx seq No %d\n", u8TxSeqNo);
            eRxState++;
            break;

        case E_STATE_RX_WAIT_CRC:
            DBG_vPrintf(TRACE_SERIAL_LINK, "\nCRC %02x\n", u8Data);
            u8CRC = u8Data;
            eRxState++;
            break;

        case E_STATE_RX_WAIT_DATA:
            if(u16Bytes < u16Length)
            {
                DBG_vPrintf(TRACE_SERIAL_LINK, "%02x ", u8Data);
                pu8Message[u16Bytes++] = u8Data;
            }
            else
            {
                DBG_vPrintf(TRACE_SERIAL_ERROR, "Expected an end char\n");
                eRxState = E_STATE_RX_WAIT_START;
                u16Bytes = 0;
                u32SLRxFail++;
                bInEsc = FALSE;
            }
            break;
        default:
            break;
        }
        break;
    }
    return(FALSE);
}

/****************************************************************************
 *
 * NAME: vSL_WriteMessageFromTwoBuffers
 *
 * DESCRIPTION:
 * Write message to the serial link
 *
 * PARAMETERS: Name                   RW  Usage
 *             u16Type                R   Message type
 *             u16Length              R   Message length
 *             pu8Data                R   Message payload
 *             hAPduInst              R   APDU
 * RETURNS:
 * void
 ****************************************************************************/
PUBLIC void vSL_WriteMessageFromTwoBuffers( uint16 u16Type,
                                            uint16 u16Length,
                                            uint8 *pu8seq,
                                            uint8 *pu8Data,
                                            PDUM_thAPduInstance hAPduInst)
{
    int n;
    uint8 u8CRC;
    uint8 RetryCount;
    uint8 *dataPtr=NULL;
    uint16 u16Size = 0;
    uint16 u16TotalDataLen = 0;
    uint8 u8TxSeqNo;
    uint8 u8RxSeqNo;
#ifdef SL_JN_TO_HOST_SECURE
    uint8 au8Mic[8];
#endif
    if (pu8seq == NULL)
    {
        u8TxSeqNo = u8JNTxSeqNo;
        //DBG_vPrintf(1, "Type %04x use Transmit Seq No %d\n", u16Type, u8TxSeqNo);
        u8JNTxSeqNo++;
    }
    else
    {
        u8TxSeqNo = *pu8seq;
        //DBG_vPrintf(1, "Type %04x use Received Seq No %d\n", u16Type, u8TxSeqNo);
    }
    u8RxSeqNo = u8ReceivedSeqNo;
    if (u16Type == (uint16)E_SL_MSG_STATUS_SHORT_MSG)
    {
        u8TxSeqNo = 0;
        u8RxSeqNo = 0;
    }
    u8CRC = u8SL_CalculateCRC(u16Type, u16Length, u8TxSeqNo, u8RxSeqNo, pu8Data, hAPduInst);


    //DBG_vPrintf(1, "Send Msg type %04x SeqNo %d CRC %02x\n", u16Type, u8TxSeqNo, u8CRC);

    //DBG_vPrintf(TRACE_SERIAL_LINK, "\nvSL_WriteMessage(%d, %d, %02x)", u16Type, u16Length, u8CRC);
    if(hAPduInst != NULL)
    {
        dataPtr = (uint8*)PDUM_pvAPduInstanceGetPayload(hAPduInst);
        u16Size = PDUM_u16APduInstanceGetPayloadSize( hAPduInst);
    }
    u16TotalDataLen = u16Length + u16Size;

    if (( u16Type == E_SL_MSG_STATUS_MSG) ||
            ( u16Type == E_SL_MSG_STATUS_SHORT_MSG))
    {
        u32SLTxStatusMsg++;
    }
    else
    {
        u32SLTxEventMsg++;
    }

    for(RetryCount=0; RetryCount<3; RetryCount++)
    {
        ZPS_eEnterCriticalSection((void*)vSL_Mutex, (uint32*)&sIntStore);
        bRxBufferLocked = FALSE;
        DBG_vPrintf(TRACE_SERIAL_LINK, "\n Tx to host attempt %d", RetryCount+1);
        /* Send start character */
        vSL_TxByte(TRUE, SL_START_CHAR);

        /* Send message type */
        vSL_TxByte(FALSE, (u16Type >> 8) & 0xff);
        vSL_TxByte(FALSE, (u16Type >> 0) & 0xff);

        /* Send message length */
    #ifdef SL_JN_TO_HOST_SECURE
        if(u16TotalDataLen)
        {
            vSL_TxByte(FALSE, ((u16TotalDataLen+8) >> 8) & 0xff);
            vSL_TxByte(FALSE, ((u16TotalDataLen+8) >> 0) & 0xff);
        }
        else
        {
            vSL_TxByte(FALSE, ((u16TotalDataLen )>> 8) & 0xff);
            vSL_TxByte(FALSE, ((u16TotalDataLen) >> 0) & 0xff);
        }
    #else
        vSL_TxByte(FALSE, ((u16TotalDataLen) >> 8) & 0xff);
        vSL_TxByte(FALSE, ((u16TotalDataLen) >> 0) & 0xff);
    #endif

        if (u16Type != (uint16)E_SL_MSG_STATUS_SHORT_MSG)
        {
            /* send the sequence no */
            vSL_TxByte(FALSE, u8TxSeqNo);
            vSL_TxByte(FALSE, u8RxSeqNo);
        }

        /* Send message checksum */
        vSL_TxByte(FALSE, u8CRC);
    #ifdef SL_JN_TO_HOST_SECURE
        if(u16TotalDataLen)
        {
            SEC_vEncryptBlock(pu8Data, u16Length, au8Mic, hAPduInst);
        }
    #endif
        /* Send message payload */
        for(n = 0; n < u16Length; n++)
        {
            vSL_TxByte(FALSE, pu8Data[n]);
        }
        if(hAPduInst != NULL)
        {

            for(n = 0; n < u16Size; n++)
            {
                vSL_TxByte(FALSE, dataPtr[n]);
            }
        }
    #ifdef SL_JN_TO_HOST_SECURE
        if(u16Length)
        {
            /* Send message authentication */
            for(n = 0; n < 8; n++)
            {
                vSL_TxByte(FALSE, au8Mic[n]);
            }
        }
    #endif
        /* Send end character */

        vSL_TxByte(TRUE, SL_END_CHAR);


        ZPS_eExitCriticalSection((void*)vSL_Mutex, (uint32*)&sIntStore);

        if(UART_ACKS_ENABLED == u8ReadUARTAcksSettings())
        {
             if( (E_SL_MSG_STATUS_MSG  != u16Type) &&
                    (E_SL_MSG_STATUS_SHORT_MSG  != u16Type) )
            {
                eAckState = E_STATE_WAITING_FOR_ACK;
                uint32 u32Count = 0;
                while(E_STATE_WAITING_FOR_ACK == eAckState)
                {

                    vAppSwDelayMs(1);
                    u32Count++;
                    if (u32Count > u16AckTimeout)
                    {
                        eAckState = E_STATE_ACK_TIMEOUT;
                    }

                    bRxBufferLocked = FALSE;
                }
                bRxBufferLocked = FALSE;

                if (E_STATE_ACK_RECEIVED == eAckState)
                {
                    if (u32Count <= 5U)
                    {
                        u32SL5Ms++;
                    }
                    else if ((u32Count > 5U)&& (u32Count <= 8U))
                    {
                        u32SL8Ms++;
                    }
                    else if ((u32Count > 8U)&& (u32Count <= 10U))
                    {
                        u32SL10Ms++;
                    }
                    else
                    {
                        u32Greater10Ms++;
                        DBG_vPrintf(TRUE, "COUNT = %d, for packet = %x\n", u32Count, u16Type);
                    }
                    break;
                }
                if((E_STATE_ACK_TIMEOUT == eAckState) || (E_STATE_NACK_RECEIVED == eAckState))
                {
                    u32SLTxRetries++;
                    DBG_vPrintf(TRACE_SERIAL_LINK, "\n**Retry Count = %d type %04x state %d count %d**\n",
                            RetryCount, u16Type, eAckState, u32Count);
                }
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

    if (RetryCount == 3)
    {
        u32SLTxFailures++;
    }
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: u8SL_CalculateCRC
 *
 * DESCRIPTION:
 * Calculate CRC of packet
 *
 * PARAMETERS: Name                   RW  Usage
 *             u8Type                 R   Message type
 *             u16Length              R   Message length
 *             pu8Data                R   Message payload
 *             hAPduInst              R   APDU
 *
 * RETURNS: CRC of packet
 *
 ****************************************************************************/
PRIVATE uint8 u8SL_CalculateCRC( uint16 u16Type,
                                 uint16 u16Length,
                                 uint8 u8TxSeq,
                                 uint8 u8RxSeq,
                                 uint8 *pu8Data,
                                 PDUM_thAPduInstance hAPduInst)
{

    int n;
    uint8 u8CRC;
    uint8 *dataPtr;
    uint16 u16Size=0;
    uint16 u16TotalSize=0;
    if(hAPduInst != NULL)
    {
        dataPtr = (uint8*)PDUM_pvAPduInstanceGetPayload(hAPduInst);
        u16Size = PDUM_u16APduInstanceGetPayloadSize( hAPduInst);
    }
    u16TotalSize =u16Size + u16Length;
    u8CRC  = (u16Type   >> 0) & 0xff;
    u8CRC ^= (u16Type   >> 8) & 0xff;
    u8CRC ^= (u16TotalSize >> 0) & 0xff;
    u8CRC ^= (u16TotalSize >> 8) & 0xff;
    u8CRC ^= u8TxSeq;
    u8CRC ^= u8RxSeq;

    for(n = 0; n < u16Length; n++)
    {
        u8CRC ^= pu8Data[n];
    }
    if(hAPduInst != NULL)
    {
        for(n = 0; n < u16Size; n++)
        {
            u8CRC ^= dataPtr[n];
        }
    }
    return(u8CRC);
}

/****************************************************************************
 *
 * NAME: vSL_TxByte
 *
 * DESCRIPTION:
 * Send, escaping if required, a byte to the serial link
 *
 * PARAMETERS:  Name                RW  Usage
 *              bSpecialCharacter   R   TRUE if this byte should not be escaped
 *              u8Data              R   Character to send
 *
 * RETURNS:
 * void
 ****************************************************************************/
PRIVATE void vSL_TxByte(bool bSpecialCharacter, uint8 u8Data)
{
    if(!bSpecialCharacter && u8Data < 0x8)
    {
        /* Send escape character and escape byte */
        u8Data ^= 0x8;
        SL_WRITE(SL_ESC_CHAR);
        DBG_vPrintf(TRACE_SERIAL_LINK, "\n");
    }
    SL_WRITE(u8Data);
}

#ifdef SL_JN_TO_HOST_SECURE
/****************************************************************************
 *
 * NAME: SEC_bDecryptBlock
 *
 * PARAMETERS:  Name                RW  Usage
 *              pu8Data             R   Message Payload
 *              u16Length           R   Message length
 *              pu8Mic              R   Message Integrity Code
 * RETURNS:
 * void
 ****************************************************************************/
PRIVATE bool_t SEC_bDecryptBlock(uint8 *pu8Data, uint16 u16Length, uint8 *pu8Mic)
{
    bool_t bChecksumVerify = FALSE;
    AESSW_Block_u key,nonce;
    const uint8 au8key[16] = {0x00, 0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
    const uint8 au8nonce[16] = {0xa0, 0xa1, 0xa2, 0xa3,0xa4, 0xa5, 0xa6, 0xa7,0x03,0x02,0x01,0x00,0x06,0,0,0};
    const uint8 au8Auth[8] = {00, 01, 02, 03, 04, 05, 06, 07};

    memcpy(key.au8, au8key, 16);
    memcpy(nonce.au8, au8nonce, 16);
    /* Decryption */
    bAES_CCMstar_Local(&key,TRUE,XCV_REG_AES_SET_MODE_CCM_D,8,8,u16Length,&nonce,(uint8*)au8Auth,pu8Data,pu8Mic,&bChecksumVerify);
    return bChecksumVerify;
}

/****************************************************************************
 *
 * NAME: SEC_vEncryptBlock
 *
 * PARAMETERS:  Name                RW  Usage
 *              pu8Data             R   Message Payload
 *              u16Length           R   Message Length
 *              puMic               R   Message Integrity Code
 *              hAPduInst           R   APDU
 *
 * RETURNS:
 * void
 ****************************************************************************/
PRIVATE void SEC_vEncryptBlock(uint8 *pu8Data, uint16 u16Length, uint8 *pu8Mic,  PDUM_thAPduInstance hAPduInst)
{
    AESSW_Block_u key,nonce;
    const uint8 au8key[16] = {0x00, 0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
    const uint8 au8nonce[16] = {0xa0, 0xa1, 0xa2, 0xa3,0xa4, 0xa5, 0xa6, 0xa7,0x03,0x02,0x01,0x00,0x06,0,0,0};
    const uint8 au8Auth[8] = {00, 01, 02, 03, 04, 05, 06, 07};
    uint8 *pu8Data2;
    uint16 u16Length2=0;

    memcpy(key.au8, au8key, 16);
    memcpy(nonce.au8, au8nonce, 16);
    if(hAPduInst != NULL)
    {
        pu8Data2 = (uint8*)PDUM_pvAPduInstanceGetPayload(hAPduInst);
        u16Length2 = PDUM_u16APduInstanceGetPayloadSize( hAPduInst);
        bAES_CCMstar_Encrypt2Buffer(&key,TRUE,XCV_REG_AES_SET_MODE_CCM,8,8,u16Length,&nonce,(uint8*)au8Auth,pu8Data,pu8Mic,u16Length2,pu8Data2);
    }
    else
    {
        bAES_CCMstar_Local(&key,TRUE,XCV_REG_AES_SET_MODE_CCM,8,8,u16Length,&nonce,(uint8*)au8Auth,pu8Data,pu8Mic,NULL);
    }
}
#endif

#ifdef SERIAL_DEBUG
/****************************************************************************
 *
 * NAME: vSL_LogInit
 *
 * DESCRIPTION:
 * Initialise Serial Link logging
 * Set up DBG module to use serial link functions for its output
 *
 * PARAMETERS:  Name                RW  Usage
 *
 * RETURNS:
 * void
 ****************************************************************************/
PUBLIC void vSL_LogInit(void)
{
    tsDBG_FunctionTbl sFunctionTbl;

    sFunctionTbl.prInitHardwareCb   = vLogInit;
    sFunctionTbl.prPutchCb          = vLogPutch;
    sFunctionTbl.prFlushCb          = vLogFlush;
    sFunctionTbl.prFailedAssertCb   = vLogAssert;

    DBG_vInit(&sFunctionTbl);
}

/****************************************************************************
 *
 * NAME: vLogInit
 *
 * DESCRIPTION:
 * Callback function for DBG module to initialise output
 *
 * PARAMETERS:  Name                RW  Usage
 *
 * RETURNS:
 * void
 ****************************************************************************/
PRIVATE void vLogInit(void)
{

}


/****************************************************************************
 *
 * NAME: vLogPutch
 *
 * DESCRIPTION:
 * Callback function for DBG module to write out characters
 *
 * PARAMETERS:  Name                RW  Usage
 *
 * RETURNS:
 * void
 ****************************************************************************/
PRIVATE void vLogPutch(char c)
{
#if 0
    if (!bLogging)
    {
        /* Handle first character being the log level */
        if (c < 7)
        {
            /* Ensure log level is LOG_INFO or higher */
            au8LogBuffer[u8LogEnd] = c;
        }
        else
        {
            au8LogBuffer[u8LogEnd] = 6;
        }
        u8LogEnd++;
    }
#endif

    if (c >= 0x20 && c < 0x7F)
    {
        /* Add ASCII characters to the output buffer */
        au8LogBuffer[u8LogEnd] = c;
        u8LogEnd++;
    }

    bLogging = TRUE;
}


/****************************************************************************
 *
 * NAME: vLogFlush
 *
 * DESCRIPTION:
 * Callback function for DBG module to flush output buffer - used to terminate
 * an entry in the logbuffer
 *
 * PARAMETERS:  Name                RW  Usage
 *
 * RETURNS:
 * void
 ****************************************************************************/
PRIVATE void vLogFlush(void)
{
    au8LogBuffer[u8LogEnd] = '\0';
    u8LogEnd++;
    bLogging = FALSE;
    vSL_LogSend();
    u8LogEnd = 0;
    u8LogStart = 0;
}

/****************************************************************************
 *
 * NAME: vLogAssert
 *
 * DESCRIPTION:
 * Callback function for DBG module to assert - not used
 *
 * PARAMETERS:  Name                RW  Usage
 *
 * RETURNS:
 * void
 ****************************************************************************/
PRIVATE void vLogAssert(void)
{

}


/****************************************************************************
 *
 * NAME: vSL_LogSend
 *
 * DESCRIPTION:
 * Send log messages from the log buffer to the host
 *
 * PARAMETERS:  Name                RW  Usage
 *
 * RETURNS:
 * void
 ****************************************************************************/
PUBLIC void vSL_LogSend(void)
{
    int n;
    uint8 u8CRC;
    uint8 u8Length;

    u32SLTxEventMsg++;

    while (u8LogEnd - u8LogStart != 0)
    {
        /* Send start character */
        vSL_TxByte(TRUE, SL_START_CHAR);

        /* Send message type */
        vSL_TxByte(FALSE, (E_SL_MSG_LOG >> 8) & 0xff);
        vSL_TxByte(FALSE, (E_SL_MSG_LOG >> 0) & 0xff);

        u8CRC = ((E_SL_MSG_LOG >> 8) & 0xff) ^ ((E_SL_MSG_LOG >> 0) & 0xff);

        for (u8Length = 0; au8LogBuffer[(u8LogStart + u8Length) & 0xFF] |= '\0'; u8Length++)
        {
            u8CRC ^= au8LogBuffer[(u8LogStart + u8Length) & 0xFF];
        }
        u8CRC ^= 0;
        u8CRC ^= u8Length;

        /* Send message length */
        vSL_TxByte(FALSE, 0);
        vSL_TxByte(FALSE, u8Length);

        /* send the saquence numbers */
        vSL_TxByte(FALSE, u8JNTxSeqNo);
        vSL_TxByte(FALSE, u8ReceivedSeqNo);
        u8CRC ^= u8JNTxSeqNo;
        u8CRC ^= u8ReceivedSeqNo;
        u8JNTxSeqNo++;

        /* Send message checksum */
        vSL_TxByte(FALSE, u8CRC);

        /* Send message payload */
        for(n = 0; n < u8Length; n++)
        {
            vSL_TxByte(FALSE, au8LogBuffer[u8LogStart]);
            u8LogStart++;
        }
        u8LogStart++;

        /* Send end character */
        vSL_TxByte(TRUE, SL_END_CHAR);
    }
}
#endif



/****************************************************************************
 *
 * NAME: u8SendNegateTest
 *
 * DESCRIPTION:  Negative test messages for serial link
 *
 * RETURNS:
 * void
 ****************************************************************************/
PUBLIC uint8 u8SendNegateTest(uint8 u8TestCase, uint8* pu8TxBuffer)
{
    uint8 auRawPkt[] = { 0x01, 0x80, 0x02, 0x08, 0x02, 0x08, 0x0a,0x02, 0x08,0x02, 0x08, 0x5b, 0x02, 0x08,
                             0x02, 0x08, 0x80, 0x76, 0x54, 0x65, 0x73, 0x74, 0x20, 0x31,
                             0x03 };

    uint8 au8Extra[] = { 0x45, 0x78, 0x74, 0x72, 0x61 };
    uint8* pu8Buffer = pu8TxBuffer;
    uint8 u8Status = 0;

    int i;
    uint16 u16TotalLength;

    switch(u8TestCase)
    {
    case 0:
    {
        /* unexpected start char */
        memcpy(pu8Buffer, auRawPkt, sizeof(auRawPkt));
        pu8Buffer += 18;
        memcpy(pu8Buffer, auRawPkt, sizeof(auRawPkt));
        pu8Buffer += sizeof(auRawPkt);
        u8Status = 0;
    }
    break;
    case 1:
    {
        /* early end char */
        auRawPkt[18] = SL_END_CHAR;
        memcpy(pu8Buffer, auRawPkt, sizeof(auRawPkt));
        pu8Buffer += sizeof(auRawPkt);
        u8Status = 0x31;
    }
    break;
    case 2:
    {
        /* late end char (extra data bytes) */
        memcpy(pu8Buffer, auRawPkt, sizeof(auRawPkt));
        pu8Buffer += sizeof(auRawPkt);
        pu8Buffer--;
        memcpy(pu8Buffer, au8Extra, sizeof(au8Extra));
        pu8Buffer += sizeof(au8Extra);
        *pu8Buffer++ = SL_END_CHAR;
        u8Status = 0x32;
    }
    break;
    case 3:
    {
        /* bad crc */
        auRawPkt[18]++;
        memcpy(pu8Buffer, auRawPkt, sizeof(auRawPkt));
        pu8Buffer += sizeof(auRawPkt);
        u8Status = 0x33;
    }
    break;
    case 4:
    {
        /* message too large for the receivers buffer  */
        ZPS_eEnterCriticalSection((void*)vSL_Mutex, (uint32*)&sIntStore);
        SL_WRITE( SL_START_CHAR );
        SL_WRITE( 0x80 );               // type msb
        SL_WRITE( 0x02 );
        SL_WRITE( 0x08 );               // type lsb
        SL_WRITE( 0x02 );
        SL_WRITE( 0x0f );               // length msb
        SL_WRITE( 0xfa );               // length lsb
        SL_WRITE( 0xfa );
        SL_WRITE( 0 );              // seq tx
        SL_WRITE( 0 );              // rx seq
        for (i=0; i< 2042; i++)
        {
            SL_WRITE( 0x55 );

        }
        SL_WRITE( SL_END_CHAR );
        ZPS_eExitCriticalSection((void*)vSL_Mutex, (uint32*)&sIntStore);
        u8Status = 0x34;
        return u8Status;
    }
    break;
    default:
        return 0x36;
    break;
    }

    u16TotalLength = pu8Buffer - pu8TxBuffer;
    ZPS_eEnterCriticalSection((void*)vSL_Mutex, (uint32*)&sIntStore);
    for (i=0; i< u16TotalLength; i++)
    {
        SL_WRITE(*pu8TxBuffer++);

    }
    ZPS_eExitCriticalSection((void*)vSL_Mutex, (uint32*)&sIntStore);

    return u8Status;

}

PUBLIC void vResetSerialStats( void)
{
    u32SLRxCount = 0;
    u32SLRxFail = 0;

    u32SLTxStatusMsg = 0;
    u32SLTxEventMsg = 0;
    u32SLTxRetries = 0;
    u32SLTxFailures = 0;
    u32OverwrittenRXMessage = 0;

    u32SL5Ms = 0;
    u32SL8Ms = 0;
    u32SL10Ms = 0;
    u32Greater10Ms = 0;
}


/****************************************************************************
 *
 * NAME: Send_Nack_Host_JN
 *
 * DESCRIPTION:
 * Sends the UART Nack to JN from Host
 *
 * PARAMETERS: None
 * RETURNS: None
 ****************************************************************************/
PUBLIC void Send_Nack_Host_JN(void)
{
    uint16 u16TxLength = 0x00;
    uint8 u8CRC;

    u8CRC = u8SL_CalculateCRC((uint16)E_SL_MSG_HOST_JN_NACK, u16TxLength, 0, 0, NULL, NULL);

    vSL_TxByte((bool_t)TRUE, SL_START_CHAR);

    /* Send message type */
    vSL_TxByte((bool_t)FALSE, (uint8)(((uint16)E_SL_MSG_HOST_JN_NACK >> 8U) & 0xffU));
    vSL_TxByte((bool_t)FALSE, (uint8)(((uint16)E_SL_MSG_HOST_JN_NACK >> 0U) & 0xffU));

    vSL_TxByte((bool_t)FALSE, (uint8)((u16TxLength >> 8U) & 0xffU));
    vSL_TxByte((bool_t)FALSE, (uint8)((u16TxLength >> 0U) & 0xffU));

    /* send the seq */
    vSL_TxByte((bool_t)FALSE, 0);
    vSL_TxByte((bool_t)FALSE, 0);

    /* Send message checksum */
    vSL_TxByte((bool_t)FALSE, u8CRC);
    vSL_TxByte((bool_t)TRUE, SL_END_CHAR);
}


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
