/*
* Copyright 2023-2024 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "EmbeddedTypes.h"
#include "dbg.h"
#include "zps_gen.h"
#include "app_zcl_task.h"
#include "app_buttons.h"
#include "app_common.h"
#include "serial_link_wkr.h"
#include "serial_link_cmds_wkr.h"
#include "app_main.h"
#include "ZQueue.h"
#include "ZTimer.h"
#if IS_NOT_MCXW_SERIES
#include "fsl_reset.h"
#endif
#include "app_uart.h"
#if defined(FSL_RTOS_FREE_RTOS) &&  DEBUG_STACK_DEPTH
#include "FreeRTOS.h"
#include "task.h"
#endif
#include "app_main.h"
#include "PDM_IDs.h"
#include "app_crypto.h"

#include <version.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef TRACE_SERIAL
    #define TRACE_SERIAL      FALSE
#endif

#define MCPS_RD_STATUS_BIT      0
#define NPDU_STATUS_BIT         1
#define APDU_0_STATUS_BIT       2
#define APDU_1_STATUS_BIT       3
#define APDU_2_STATUS_BIT       4

#define MCPS_RD_STATUS_MASK     (1<<MCPS_RD_STATUS_BIT)
#define NPDU_STATUS_MASK            (1<<NPDU_STATUS_BIT)
#define APDU_0_STATUS_MASK      (1<<APDU_0_STATUS_BIT)
#define APDU_1_STATUS_MASK      (1<<APDU_1_STATUS_BIT)
#define APDU_2_STATUS_MASK      (1<<APDU_2_STATUS_BIT)

#ifndef TRACE_APP
#define TRACE_APP   TRUE
#endif
#ifndef TRACE_TX_BUFFERS
#define TRACE_TX_BUFFERS    FALSE
#endif

#define BDB_TRSP_KEY_DECIDER_TABLE_SIZE       8

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef enum
{
    E_DECIDER_ALLOW_ALL = 0,
    E_DECIDER_WHITELIST,
    E_DECIDER_BLACKLIST
} BDB_eTrspKeyDeciderPolicy;

typedef uint64 BDB_tsTrspKeyDeciderEntry;

typedef struct
{
    BDB_tsTrspKeyDeciderEntry *psTrspKeyDeciderEntry;
    uint16  u16SizeOfTrspKeyDeciderTable;
    BDB_eTrspKeyDeciderPolicy eTrspKeyDeciderPolicy;
} BDB_tsTrspKeyDeciderTable;

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE ZPS_teStatus eZdpMgmtIeeeJoinListReq(uint64 u64ExtAddr, uint8 u8StartIndex);
PRIVATE ZPS_teStatus eZdpMgmtLeave(uint16 u16DstAddr, uint64 u64DeviceAddr,
        bool_t bRejoin, bool_t bRemoveChildren, uint8* pu8Seq);
PRIVATE ZPS_teStatus eZdpNodeDescReq(uint16 u16Addr, uint8* pu8Seq);
PRIVATE ZPS_teStatus eZdpPowerDescReq(uint16 u16Addr, uint8* pu8Seq);
PRIVATE ZPS_teStatus eZdpSimpleDescReq(bool_t bIsExtAddr,
                                       ZPS_tuAddress uDstAddr,
                                       ZPS_tsAplZdpSimpleDescReq *psZdpSimpleDescReq,
                                       uint8* pu8Seq);
PRIVATE ZPS_teStatus eZdpActiveEndpointReq(ZPS_tuAddress uDstAddr, uint16 u16TargetAddr, uint8* pu8Seq);
PRIVATE ZPS_teStatus eZdpMatchDescReq(uint16 u16Addr, uint16 u16profile,
        uint16 u16NwkAoI, uint8 u8InputCount, uint16* pu16InputList,
        uint8 u8OutputCount, uint16* pu16OutputList, uint8* pu8Seq);
PRIVATE ZPS_teStatus eZdpIeeeAddrReq(uint16 u16Dst, uint16 u16Addr,
        uint8 u8RequestType, uint8 u8StartIndex, uint8* pu8Seq);
PRIVATE ZPS_teStatus eZdpNwkAddrReq(uint16 u16Dst, uint64 u64Addr,
        uint8 u8RequestType, uint8 u8StartIndex, uint8* pu8Seq);
PRIVATE ZPS_teStatus eZdpPermitJoiningReq(uint16 u16DstAddr,
        uint8 u8PermitDuration,
        bool bTcSignificance,uint8* pu8Seq);
PRIVATE ZPS_teStatus eBindUnbindEntry(bool_t bBind, uint64 u64SrcAddr,
        uint8 u8SrcEndpoint, uint16 u16ClusterId, ZPS_tuAddress *puDstAddress,
        uint8 u8DstEndpoint, uint8 u8DstAddrMode, uint8* pu8Seq);
PRIVATE void vControlNodeScanStart(void);
PRIVATE uint8 u8ControlNodeStartNetwork(void);
PRIVATE uint8 u8ControlNodeSetUpForInterPan(uint32 u32ChannelMask);
PRIVATE uint8 u8AppChangeChannel( uint32 u32Channel);
PRIVATE bool_t bGetDeviceStats(uint64 u64Mac, uint8 *pu8LastLqi, uint8 *pu8AverageLqi);
PRIVATE uint16 u16GetTemp(void);
PRIVATE void vAPPSendZPSData (teSL_MsgType PktType, uint8 *pu8Buffer, uint16 *pu16ClusterId, uint8 *pu8SeqNum, uint8 *pu8Status);
//#if (defined MAC_TYPE_SOC)
PRIVATE uint8 u8Set2G4ChannelFromMask(uint32 u32ChannelMask);
//#endif

extern void * zps_psNwkMcpsMgrAllocateReqDescr(void *pvNwk);

PUBLIC void vAppHandlePDMError(void);
PUBLIC void vSendPdmStatusToHost(teSL_PdmCmdType eCmdType, uint8 u8PDMStatus);
PRIVATE uint16 u16SearchKeyTableByIeeeAddress(uint64 u64IEEEAddress);

PUBLIC uint8 u8EnableBoundDevices( bool_t bState);
PUBLIC uint8 u8EnableBoundDevice(uint64 u64Address, bool_t bState);

PRIVATE uint8 vAddTrspKeyDeciderEntry(BDB_tsTrspKeyDeciderEntry s_TrspKeyDeciderEntry);
PRIVATE uint8 vRemoveTrspKeyDeciderEntry(BDB_tsTrspKeyDeciderEntry s_TrspKeyDeciderEntry);
PRIVATE void vClearTrspKeyDeciderTable();
PRIVATE uint8 u8GetTrspKeyDeciderFreeIndex();
PRIVATE uint8 u8GetTrspKeyDeciderIndex(BDB_tsTrspKeyDeciderEntry s_TrspKeyDeciderEntry);
PRIVATE bool_t doSendTransportKey(uint64 u64DeviceAddress);
PUBLIC bool_t vNfTcCallback (uint16 u16ShortAddress,
                             uint64 u64DeviceAddress,
                             uint64 u64ParentAddress,
                             uint8 u8Status,
                             uint16 u16MacId);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
uint32_t u32StatusFlags;

PUBLIC uint8 u8LastMsgLqi =0; /* last message received Lqi. */
PUBLIC uint8 u8TempExtendedError = 0;
PUBLIC tsNwkStats sNwkStats;

extern bool_t g_bExternalPermitJoinControl;
extern uint8  g_u8SuspendBoundTransmission;
extern uint32_t u32OverwrittenRXMessage;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE BDB_tsTrspKeyDeciderEntry s_TrspKeyDeciderTableStorage[BDB_TRSP_KEY_DECIDER_TABLE_SIZE];
PRIVATE BDB_tsTrspKeyDeciderTable s_TrspKeyDeciderTable = {s_TrspKeyDeciderTableStorage, 0, 0};
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
PUBLIC uint8 au8LinkRxBuffer[MAX_PACKET_RX_SIZE];
PUBLIC uint16 u16PacketType, u16PacketLength;
PUBLIC uint8 u8ReceivedSeqNo;

PUBLIC bool_t bRxBufferLocked = FALSE;
PUBLIC bool_t bBlockApduError = FALSE;

uint16 u16AckTimeout = 30;

/****************************************************************************
  *
  * NAME: vProcessIncomingSerialCommands
  *
  * DESCRIPTION: Handles incoming Serial Commands
  *
  * PARAMETERS:
  * void
  *
  * RETURNS:
  * void
  *
  ****************************************************************************/
PUBLIC void vProcessIncomingSerialCommands(void)
{
    static uint8 u8ApsTSN = 0;
    static uint8 u8Status = E_SL_MSG_STATUS_SUCCESS;
    static uint8 u8LastRxSeqNo = 0xff;
    uint8 u8TxLength = 0x04;
    uint16 u16TargetAddress;
    uint8 au8values[132];
    uint16 u16ClusterId;
    uint16 u16ReturnMsgType = E_SL_MSG_STATUS_MSG;
    uint8 u8TempLen = 0;

    memcpy(&u16TargetAddress, &au8LinkRxBuffer[1], sizeof(uint16));

//  if (!bProcessMessages)
//  {
//      u8Status = E_SL_MSG_STATUS_BUSY;
//      ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8Status, u8TempLen);
//      ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8ApsTSN, u8TempLen);
//      ZNC_BUF_U16_UPD   ( &au8values[u8TempLen], u16PacketType, u8TempLen);
//      vSL_WriteMessage(E_SL_MSG_STATUS_MSG, 4,  &u8ReceivedSeqNo, au8values);
//      return;
//  }

    //DBG_vPrintf(TRUE, "\n Got SL_CMD: x%04x\n", u16PacketType);

    switch (u16PacketType)
    {
    case E_SL_MSG_UNICAST_ACK_DATA_REQ:
    case E_SL_MSG_UNICAST_DATA_REQ:
    case E_SL_MSG_UNICAST_IEEE_ACK_DATA_REQ:
    case E_SL_MSG_UNICAST_IEEE_DATA_REQ:
    case E_SL_MSG_BOUND_ACK_DATA_REQ:
    case E_SL_MSG_BOUND_DATA_REQ:
    case E_SL_MSG_BROADCAST_DATA_REQ:
    case E_SL_MSG_MATCH_DESCRIPTOR_REQUEST:
    case E_SL_MSG_NODE_DESCRIPTOR_REQUEST:
    case E_SL_MSG_SIMPLE_DESCRIPTOR_REQUEST:
    case E_SL_MSG_IEEE_ADDRESS_REQUEST:
    case E_SL_MSG_NETWORK_ADDRESS_REQUEST:
    case E_SL_MSG_POWER_DESCRIPTOR_REQUEST:
    case E_SL_MSG_ACTIVE_ENDPOINT_REQUEST:
    case E_SL_MSG_NETWORK_REMOVE_DEVICE:
    case E_SL_MSG_REMOVE_REMOTE_DEVICE:
    case E_SL_MSG_BIND:
    case E_SL_MSG_UNBIND:
    case E_SL_MSG_ZDO_PERMIT_JOIN_REQUEST:
    case E_SL_MSG_SEND_MGMT_NWK_UNS_ENH_UPDATE_NOTIFY:
    case E_SL_MSG_SEND_MGMT_NWK_ENH_UPDATE_REQ:

        if (u8ReceivedSeqNo == u8LastRxSeqNo)
        {
            ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8Status, u8TempLen);
            ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8ApsTSN, u8TempLen);
            ZNC_BUF_U16_UPD   ( &au8values[u8TempLen], u16PacketType, u8TempLen);
            vSL_WriteMessage(E_SL_MSG_STATUS_MSG, 4,  &u8ReceivedSeqNo, au8values);
            u16PacketType = 9;
            return;
        }

        break;
    default:
        break;
    }

    u8ApsTSN = 0;
    u8Status = E_SL_MSG_STATUS_SUCCESS;
    u8LastRxSeqNo = u8ReceivedSeqNo;


    switch (u16PacketType)
    {
    case (E_SL_MSG_HOST_JN_ACK):
    {
        DBG_vPrintf(TRACE_APP, "\n ****Received ACK From Host****\n");
        return;
    }
    case (E_SL_MSG_HOST_JN_NACK):
    {
        DBG_vPrintf(TRACE_APP, "\n ****Received NACK From Host****\n");
        return;
    }
    case (E_SL_MSG_SET_JN_ACK_TIMEOUT):
    {
        uint16 u16Time;
        u16Time = ZNC_RTN_U16( au8LinkRxBuffer, 0 );
        if (u16Time < 1001)
        {
            u16AckTimeout = u16Time;
            DBG_vPrintf(TRACE_APP, "\n ***Set Ack Timeout = %d****\n",u16AckTimeout);
        }
        else
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
    }
    break;
    case (E_SL_MSG_GET_VERSION):
    {
        /* Version is Zigbee component version: SDK package or SHA commit */
        uint32 u32Version = ZIGBEE_VERSION;
        uint32 u32SDKVersion = SDK_VERSION;

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32Version, u8TxLength );

        /* For now we do not support Zigbee device type, MAC type and options */
        ZNC_BUF_U8_UPD(  &au8values[u8TxLength],  0, u8TxLength );
        ZNC_BUF_U8_UPD(  &au8values[u8TxLength],  0, u8TxLength );
        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  0, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32SDKVersion, u8TxLength );

        u16ReturnMsgType = E_SL_MSG_STATUS_SHORT_MSG;
    }
    break;
    case (E_SL_SET_ED_THRESHOLD):
    {
        ZPS_psAplZdoGetNib()->u8VsFormEdThreshold = au8LinkRxBuffer[0];
        DBG_vPrintf(TRACE_APP, "\n ***ED Threshold Value = %d****\n",ZPS_psAplZdoGetNib()->u8VsFormEdThreshold);
    }
    break;
    case (E_SL_MSG_SET_EXT_PANID):
    {
        uint64 u64Value;
        u64Value = ZNC_RTN_U64( au8LinkRxBuffer, 0);
        u8Status = ZPS_eAplAibSetApsUseExtendedPanId(u64Value);
    }
    break;

    case (E_SL_MSG_SET_CHANNELMASK):
        {
            uint32 u32Value = ZNC_RTN_U32( au8LinkRxBuffer, 0);
            uint8 u8ChanMaskValidStatus = ZPS_eMacValidateChannelMask(u32Value);
            if(MAC_ENUM_SUCCESS == u8ChanMaskValidStatus)
            {
                u8Status = ZPS_eAplAibSetApsChannelMask(u32Value);
            }
            else
            {
                u8Status = u8ChanMaskValidStatus;
            }

            DBG_vPrintf(TRACE_APP, "\nChannel Mask 0x%08x, u8Status: %d channelMaskList = 0x%08x \n", u32Value, u8Status, g_u32ChannelMaskList[0]);
        }
        break;

    case E_SL_MSG_UNICAST_ACK_DATA_REQ:
    {
        vAPPSendZPSData(E_SL_MSG_UNICAST_ACK_DATA_REQ, au8LinkRxBuffer,&u16ClusterId,&u8ApsTSN, &u8Status);
        break;
    }

    case E_SL_MSG_UNICAST_DATA_REQ:
    {
        vAPPSendZPSData(E_SL_MSG_UNICAST_DATA_REQ, au8LinkRxBuffer,&u16ClusterId,&u8ApsTSN, &u8Status);
        break;
    }

    case E_SL_MSG_UNICAST_IEEE_ACK_DATA_REQ:
    {
        vAPPSendZPSData(E_SL_MSG_UNICAST_IEEE_ACK_DATA_REQ, au8LinkRxBuffer,&u16ClusterId,&u8ApsTSN, &u8Status);
        break;
    }

    case E_SL_MSG_UNICAST_IEEE_DATA_REQ:
    {
        vAPPSendZPSData(E_SL_MSG_UNICAST_IEEE_DATA_REQ, au8LinkRxBuffer,&u16ClusterId,&u8ApsTSN, &u8Status);
        break;
    }

    case E_SL_MSG_BOUND_ACK_DATA_REQ:
    {
        vAPPSendZPSData(E_SL_MSG_BOUND_ACK_DATA_REQ, au8LinkRxBuffer,&u16ClusterId,&u8ApsTSN, &u8Status);
        break;
    }

    case E_SL_MSG_BOUND_DATA_REQ:
    {
        vAPPSendZPSData(E_SL_MSG_BOUND_DATA_REQ, au8LinkRxBuffer,&u16ClusterId,&u8ApsTSN, &u8Status);
        break;
    }

    case E_SL_MSG_BROADCAST_DATA_REQ:
    {
        vAPPSendZPSData(E_SL_MSG_BROADCAST_DATA_REQ, au8LinkRxBuffer,&u16ClusterId,&u8ApsTSN, &u8Status);
        break;
    }

    case E_SL_MSG_GROUP_DATA_REQ:
    {
        vAPPSendZPSData(E_SL_MSG_GROUP_DATA_REQ, au8LinkRxBuffer,&u16ClusterId,&u8ApsTSN, &u8Status);
        break;
    }

    case E_SL_MSG_INTERPAN_DATA_REQ:
    {
        PDUM_thAPduInstance hAPduInst;
        uint16 u16ClusterId, u16ProfileId, u16PanId;
        uint16 u16Index = 0x00, u16PayloadLen;
        uint8 u8DstAddrMode, u8Handle;
        ZPS_tuAddress uDstAddress;
        ZPS_tsInterPanAddress sInterPanAddress;

        /* check length, allocate PDU based on length */
        hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
        u32StatusFlags &= ~APDU_0_STATUS_MASK;

        /* check instance */
        if (hAPduInst)
        {
            /* copy u16ClusterId */
            u16ClusterId = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index);

            /* copy u16ProfileId */
            u16ProfileId = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index);

            /* copy u8DstAddrMode */
            u8DstAddrMode = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

            /* copy u16PanId */
            u16PanId = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index);

            if(u8DstAddrMode == ZPS_E_AM_INTERPAN_IEEE)
            {
                uDstAddress.u64Addr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index);
            }
            else
            {
                uDstAddress.u16Addr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index);
            }
            /* copy u8Handle */
            u8Handle = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

            /* copy u16PayloadLen */
            u16PayloadLen = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index);

            sInterPanAddress.eMode = u8DstAddrMode;
            sInterPanAddress.u16PanId = u16PanId;
            sInterPanAddress.uAddress = uDstAddress;

            /* Copy Payload */
            memcpy((uint8 *)(PDUM_pvAPduInstanceGetPayload(hAPduInst)),
                            &au8LinkRxBuffer[u16Index],
                            u16PayloadLen);
            u16Index += u16PayloadLen;
            /* Set Payload Size */
            PDUM_eAPduInstanceSetPayloadSize(hAPduInst, u16PayloadLen);


            u8Status = ZPS_eAplAfInterPanDataReq(hAPduInst,
                                                     u16ClusterId,
                                                     u16ProfileId,
                                                     &sInterPanAddress,
                                                     u8Handle);

            if (u8Status != ZPS_E_SUCCESS)
            {
                PDUM_eAPduFreeAPduInstance(hAPduInst);
            }
        }
        else
        {
            u8Status = E_SL_MSG_NO_APDU_BUFFERS;
        }
        break;
    }
    case E_SL_MSG_FIND_EXT_ADDR:
    {
        uint16 u16NwkAddr;
        uint64 u64IEEEAddr;

        /* copy NWK Address */
        u16NwkAddr = ZNC_RTN_U16( au8LinkRxBuffer, 0);

        u64IEEEAddr = ZPS_u64AplZdoLookupIeeeAddr(u16NwkAddr);

        /* Copy IEEE Address for sending over serial */
        ZNC_BUF_U64_UPD( &au8values[u8TxLength], u64IEEEAddr, u8TxLength);
        break;
    }

    case E_SL_MSG_GET_DEVICE_PERMISSIONS:
    {
        uint8 u8DevicePermissions;
        uint64 u64IEEEAddr;

        /* copy NWK Address */
        u64IEEEAddr = ZNC_RTN_U64( au8LinkRxBuffer, 0 );

        u8Status = ZPS_bAplZdoTrustCenterGetDevicePermissions(u64IEEEAddr,
                &u8DevicePermissions);

        /* Copy u8DevicePermissions for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8DevicePermissions, u8TxLength );
        break;
    }

    case E_SL_MSG_SET_DEVICE_PERMISSIONS:
    {
        uint8 u8DevicePermissions;
        uint64 u64IEEEAddr;
        ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();
        uint32 idx;
        uint16 u16Index = 0x00;

        /* copy u64IEEEAddr */
        u64IEEEAddr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index);

        /* copy u8DevicePermissions */
        u8DevicePermissions = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u8Status = ZPS_APL_APS_E_ILLEGAL_REQUEST;
        for (idx=0; idx < psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable; idx++)
        {
            /* check for matched entry */
            if(ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(),
                                              psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[idx].u16ExtAddrLkup)
                                   == u64IEEEAddr)
            {
                /* device is i the aps key table */
                u8Status = ZPS_bAplZdoTrustCenterSetDevicePermissions(u64IEEEAddr,u8DevicePermissions);

                break;
            }
        }
        break;
    }

    case E_SL_MSG_SET_END_DEVICE_PERMISSIONS:
    {
        uint8 u8DevicePermissions;
        /* copy u8DevicePermissions */
        u8DevicePermissions = au8LinkRxBuffer[0];

        ZPS_eAplZdoSetDevicePermission(
                (ZPS_teDevicePermissions) u8DevicePermissions);
        break;
    }

    case E_SL_MSG_GET_REPROVISSION_DATA:
    {
        uint64 u64Address;
        u64Address = ZNC_RTN_U64( &au8LinkRxBuffer[0], 0 );

        ZPS_tsAplApsKeyDescriptorEntry *psEntry;
        int idx;
        ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();
        u8Status = ZPS_APL_APS_E_ILLEGAL_REQUEST;
        for (idx=0; idx < psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable; idx++)
        {
            psEntry = &psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[idx];
            /* check for matched entry */
            if(ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(),
                                              psEntry->u16ExtAddrLkup)
                                              == u64Address)
            {
                /* device is in the aps key table */
                memcpy(&au8values[u8TxLength], psEntry->au8LinkKey,
                                    ZPS_SEC_KEY_LENGTH);
                u8TxLength += ZPS_SEC_KEY_LENGTH;

                ZNC_BUF_U32_UPD( &au8values[u8TxLength],  psAib->pu32IncomingFrameCounter[idx], u8TxLength );

                ZNC_BUF_U32_UPD( &au8values[u8TxLength],  psEntry->u32OutgoingFrameCounter, u8TxLength );

                u8Status = ZPS_bAplZdoTrustCenterGetDevicePermissions( u64Address,
                                &au8values[u8TxLength]);
                u8TxLength++;

                u8Status = ZPS_E_SUCCESS;
                break;


            }
        }
    }
    break;

    case E_SL_MSG_SET_REPROVISSION_DATA:
    {
        uint8 au8Key[16];
        uint64 u64Address;
        uint32 u32InFc;
        uint32 u32OutFc;
        uint8 u8Permissions;
        uint16 u16Index = 0x00;
        ZPS_tsAplApsKeyDescriptorEntry *psEntry;
        ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();
        int idx;

        // endian this mem cpy should be ok byte array to ayte array
        memcpy( au8Key, &au8LinkRxBuffer[0], 16);
        u16Index += 16;

        u64Address = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u32InFc = ZNC_RTN_U32_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u32OutFc = ZNC_RTN_U32_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u8Permissions = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u8Status = ZPS_eAplZdoAddReplaceLinkKey(u64Address, au8Key, ZPS_APS_UNIQUE_LINK_KEY);
        if (u8Status == 0)
        {
            ZPS_bAplZdoTrustCenterSetDevicePermissions( u64Address, u8Permissions);
            for (idx=0; idx < psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable; idx++)
            {
                psEntry = &psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[idx];
                /* check for matched entry */
                if(ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(),
                                                  psEntry->u16ExtAddrLkup)
                                                  == u64Address)
                {
                    psAib->pu32IncomingFrameCounter[idx] = u32InFc;
                    psEntry->u32OutgoingFrameCounter = u32OutFc;
                    vSaveDevicePdmRecord();
                    break;
                }
            }

        }
    }
    break;

    case E_SL_MSG_ADD_REPLACE_LINK_KEY:
    {
        uint64 u64IEEEAddr;
        uint8 au8Key[ZPS_SEC_KEY_LENGTH], u8KeyType;
        uint16 u16Index = 0x00;

        /* copy u64IEEEAddr */
        u64IEEEAddr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        /* copy au8Key */
        /* Both are byte arrays, endianness irrelevant */
        memcpy(au8Key, &au8LinkRxBuffer[u16Index], ZPS_SEC_KEY_LENGTH);
        u16Index += ZPS_SEC_KEY_LENGTH;

        /* copy u8KeyType */
        u8KeyType = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u8Status = ZPS_eAplZdoAddReplaceLinkKey(u64IEEEAddr, au8Key,
                (ZPS_teApsLinkKeyType) u8KeyType);
        break;

    }

    case E_SL_MSG_ADD_REPLACE_INSTALL_CODES:
    {
        uint64 u64IEEEAddr;
        uint8 au8InstallCode[ZPS_SEC_KEY_LENGTH], u8KeyType;
        uint16 u16Index = 0x00;

        /* copy u64IEEEAddr */
        u64IEEEAddr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        /* copy au8InstallCode */
        /* Both are byte arrays, endianness irrelevant */
        memcpy(au8InstallCode, &au8LinkRxBuffer[u16Index], ZPS_SEC_KEY_LENGTH);
        u16Index += ZPS_SEC_KEY_LENGTH;

        /* copy u8KeyType */
        u8KeyType = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u8Status = ZPS_eAplZdoAddReplaceInstallCodes(u64IEEEAddr, au8InstallCode, 16, (ZPS_teApsLinkKeyType) u8KeyType);
        break;
    }

    case E_SL_MSG_GET_EXT_ADDR:
    {
        uint64 u64Addr;

        u64Addr = ZPS_u64NwkNibGetExtAddr(ZPS_pvAplZdoGetNwkHandle());

        /* Copy u64Addr for sending over serial */
        ZNC_BUF_U64_UPD( &au8values[u8TxLength], u64Addr , u8TxLength );

        u8Status = 0x00;
        break;
    }

    case E_SL_MSG_GET_NWK_KEY:
    {
        uint8 u8NWKKey = *(( uint8* ) ZPS_pvNwkSecGetNetworkKey ( ZPS_pvAplZdoGetNwkHandle ( ) ));
        u8Status = ZPS_E_SUCCESS;

        /* Copy u8NWKKey for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8NWKKey, u8TxLength );
        break;
    }

    case E_SL_MSG_SET_TC_ADDRESS:
    {
        uint64 u64IEEEAddr = ZNC_RTN_U64(au8LinkRxBuffer, 0);

        /* copy u64IEEEAddr */
        u8Status = ZPS_eAplAibSetApsTrustCenterAddress(u64IEEEAddr);

        break;
    }

    case E_SL_MSG_SET_INIT_SEC_STATE:
    {
        ZPS_teZdoNwkKeyState eKeyState;
        uint8 au8Key[ZPS_SEC_KEY_LENGTH];
        uint8 u8KeySeqNum, u8KeyType;
        uint16 u16Index = 0x00;

        /* copy eKeyState */
        eKeyState = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        /* copy au8Key
         * endian OK byte array to byte array*/
        memcpy(au8Key, &au8LinkRxBuffer[u16Index], ZPS_SEC_KEY_LENGTH);
        u16Index += ZPS_SEC_KEY_LENGTH;

        /* copy u8KeySeqNum */
        u8KeySeqNum = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        /* copy eKeyType */
        u8KeyType = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u8Status = ZPS_vAplSecSetInitialSecurityState(eKeyState, au8Key,
                u8KeySeqNum, (ZPS_teApsLinkKeyType) u8KeyType);
        break;
    }

    case E_SL_MSG_GET_NWK_ADDR:
    {
        uint16 u16NWKAddr;

        u16NWKAddr = ZPS_u16NwkNibGetNwkAddr(ZPS_pvNwkGetHandle());
        u8Status = ZPS_E_SUCCESS;

        /* Copy u16NWKAddr for sending over serial */
        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  u16NWKAddr, u8TxLength );
        break;
    }

    case E_SL_MSG_SET_NWK_ADDR:
    {
        uint16 u16NWKAddr = ZNC_RTN_U16(au8LinkRxBuffer, 0);
        ZPS_vNwkNibSetNwkAddr( ZPS_pvNwkGetHandle(), u16NWKAddr);
        break;
    }

    case E_SL_MSG_GET_EXT_PANID:
    {
        uint64 u64ExtPanId = ZPS_u64AplZdoGetNetworkExtendedPanId();
        u8Status = ZPS_E_SUCCESS;

        DBG_vPrintf(TRACE_APP, "u64ExtPanId = 0x%llx\r\n", u64ExtPanId);
        /* Copy u64ExtPanId for sending over serial */
        ZNC_BUF_U64_UPD( &au8values[u8TxLength],  u64ExtPanId, u8TxLength );
        break;
    }
    case E_SL_MSG_GET_PERMIT_JOIN:
    {
        bool_t bStatus = ZPS_vNwkGetPermitJoiningStatus(
                                        ZPS_pvAplZdoGetNwkHandle());
        u8Status = ZPS_E_SUCCESS;

        /* Copy permit join status for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  bStatus, u8TxLength );
        break;
    }
    case E_SL_MSG_GET_CURRENT_CHANNEL:
    {
        uint8 u8Channel = ZPS_u8AplZdoGetRadioChannel();
        u8Status = ZPS_E_SUCCESS;
        DBG_vPrintf(TRACE_APP, "u8Channel = %d, 0x%x \r\n", u8Channel, u8Channel);
        /* Copy u64ExtPanId for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8Channel, u8TxLength );

        u8Status = 0x00;
        break;
    }

    case E_SL_MSG_GET_CHANNELMASK:
    {
        uint8_t u8ChannelMasksCount = 0;
        uint32_t *pau32ApsChannelMask = NULL;

        pau32ApsChannelMask = ZPS_pu32AplAibGetApsChannelMask(&u8ChannelMasksCount);

        /* First send channel mask count over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8ChannelMasksCount, u8TxLength);

        for (int i = 0; i < u8ChannelMasksCount; i++) {
            /* Now send each mask over the serial */
            ZNC_BUF_U32_UPD( &au8values[u8TxLength],  pau32ApsChannelMask[i], u8TxLength );
        }
        if (u8ChannelMasksCount)
        {
            u8Status = ZPS_E_SUCCESS;
        }
        break;
    }

    case E_SL_MSG_GET_SHORT_ADDRESS_OF_DEVICE:
    {
        uint64 u64LongAddress;
        uint16 u16ShortAddress;

        u64LongAddress = ZNC_RTN_U64( au8LinkRxBuffer, 0 );

        u16ShortAddress = ZPS_u16AplZdoLookupAddr(u64LongAddress);
        u8Status = ZPS_E_SUCCESS;
        DBG_vPrintf(
                    TRACE_APP,
                    "0x%016llx Look up gives u16ShortAddress= 0x%04x \r\n",
                    u64LongAddress, u16ShortAddress);
        /* Copy u16NWKAddr for sending over serial */
        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  u16ShortAddress, u8TxLength );
        break;
    }

    case E_SL_MSG_GET_SHORT_PANID:
    {
        uint16 u16NetworkPanId;

        u16NetworkPanId = ZPS_u16AplZdoGetNetworkPanId();
        u8Status = ZPS_E_SUCCESS;
        DBG_vPrintf(
                TRACE_APP,
                "E_SL_MSG_GET_SHORT_ADDRESS_OF_DEVICE u16NetworkPanId= 0x%4x \r\n",
                u16NetworkPanId);
        /* Copy u16NWKAddr for sending over serial */
        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  u16NetworkPanId, u8TxLength );
        break;
    }

    case E_SL_MSG_GET_ENDPOINT_STATE:
    {
        uint8 u8Endpoint, u8Temp;
        bool bEnabled;

        /* copy u8Endpoint */
        u8Endpoint = au8LinkRxBuffer[0];

        u8Status = ZPS_eAplAfGetEndpointState(u8Endpoint, &bEnabled);

        u8Temp = (uint8) bEnabled;

        /* Copy u8EPState for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8Temp, u8TxLength );
        break;
    }

    case E_SL_MSG_SET_ENDPOINT_STATE:
    {
        uint16 u16Index = 0x00;
        uint8 u8Endpoint, u8EPState;

        /* copy u8Endpoint */
        u8Endpoint = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        /* copy u8EPState */
        u8EPState = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u8Status = ZPS_eAplAfSetEndpointState(u8Endpoint, u8EPState);

        break;
    }

    case E_SL_MSG_GET_BINDING_ENTRY:
    {
        uint16 u16TableIndex;
        ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();
        ZPS_tsAplApsmeBindingTableStoreEntry sEntry;

        /* copy u16TableIndex */
        u16TableIndex = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        if (psAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable->u32SizeOfBindingTable
                <= u16TableIndex)
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
        else
        {
            sEntry
                    = psAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable->pvAplApsmeBindingTableEntryForSpSrcAddr[u16TableIndex];

            /* Copy sEntry for sending over serial */
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8DstAddrMode, u8TxLength );

            if (sEntry.u8DstAddrMode == ZPS_E_ADDR_MODE_IEEE)
            {
                uint64 u64Addr = ZPS_u64NwkNibGetMappedIeeeAddr( ZPS_pvAplZdoGetNwkHandle(), sEntry.u16NwkAddrResolved);
                ZNC_BUF_U64_UPD( &au8values[u8TxLength],  u64Addr, u8TxLength );

            }
            else
            {
                ZNC_BUF_U16_UPD( &au8values[u8TxLength], sEntry.u16NwkAddrResolved, u8TxLength );

            }

            ZNC_BUF_U16_UPD( &au8values[u8TxLength],  sEntry.u16ClusterId, u8TxLength );

            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8SourceEndpoint, u8TxLength );

            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8DestinationEndPoint, u8TxLength );

            u8Status = ZPS_E_SUCCESS;
        }
        break;
    }

    case E_SL_MSG_GET_KEY_TABLE_ENTRY:
    {
        uint8 u8QueryType;
        uint16 u16TableIndex, u16Index = 0x00;
        uint64 u64IEEEAddress;
        ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();
        ZPS_tsAplApsKeyDescriptorEntry sEntry;

        /*
         * Backwards compatibility with older hosts:
         *
         * if the message length = 2B, then it's an older invocation, for
         * the newer ones, a parameter is added so that the total length is
         * 1B + 8B (to accommodate the IEEE address) = 9B
         * */
        if (u16PacketLength == sizeof(uint16))
        {
            u16TableIndex = (uint16)ZNC_RTN_U16( au8LinkRxBuffer, u16Index);
            DBG_vPrintf(TRACE_APP,
                        "Got older type of E_SL_MSG_GET_KEY_TABLE_ENTRY len = %d, idx = %d",
                        u16PacketLength, u16TableIndex);
        }
        else
        {
            /* copy query type */
            u8QueryType = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

            /* copy u16TableIndex/u64 */
            if (u8QueryType == 0)
            {
                u16TableIndex = (uint16)ZNC_RTN_U64( au8LinkRxBuffer, u16Index);
            }
            else
            {
                u64IEEEAddress = ZNC_RTN_U64( au8LinkRxBuffer, u16Index);
                u16TableIndex = u16SearchKeyTableByIeeeAddress(u64IEEEAddress);
            }
        }

        if ( (psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable+1)
                <= u16TableIndex)
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
        else
        {
            sEntry
                    = psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[u16TableIndex];

            /* Copy sEntry for sending over serial */
            ZNC_BUF_U16_UPD( &au8values[u8TxLength], sEntry.u16ExtAddrLkup, u8TxLength );

            /* Both are byte arrays, endianness irrelevant */
            memcpy(&au8values[u8TxLength], sEntry.au8LinkKey,
                    ZPS_SEC_KEY_LENGTH);
            u8TxLength += ZPS_SEC_KEY_LENGTH;

            ZNC_BUF_U32_UPD( &au8values[u8TxLength],  sEntry.u32OutgoingFrameCounter, u8TxLength );

            ZNC_BUF_U32_UPD( &au8values[u8TxLength],  psAib->pu32IncomingFrameCounter[u16TableIndex], u8TxLength );

            /*
             * This is done in the same way in zigbee/ZPSAPL/Source/APS/zps_apl_aib.c, in
             * function zps_u8AplAibGetDeviceApsKeyType
             */
            if (sEntry.u8BitMapSecLevl == ZPS_APS_NO_KEY_PRESENT)
            {
                ZNC_BUF_U8_UPD( &au8values[u8TxLength], ZPS_APS_UNIQUE_LINK_KEY, u8TxLength);
            }
            else
            {
                ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8BitMapSecLevl, u8TxLength );
            }
            u8Status = ZPS_E_SUCCESS;
        }
        break;
    }

    case E_SL_MSG_GET_APS_FC_IEEE:
    {
        uint64 u64IeeeAddr;
        u64IeeeAddr = ZNC_RTN_U64( au8LinkRxBuffer, 0 );
        int idx;
        uint32 u32OutFc, u32InFc;
        ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();
        u32OutFc = 0xffffffff;
        u32InFc = 0xffffffff;
        /* asume its not there */
        u8Status = ZPS_APL_ZDP_E_DEVICE_NOT_FOUND;
        if ( ( u64IeeeAddr != 0u) && ( u64IeeeAddr != 0xfffffffffffffffful ))
        {
            for (idx=0; idx < psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable; idx++)
            {
                /* check for matched entry */
                if(ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(),
                                                  psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[idx].u16ExtAddrLkup)
                                       == u64IeeeAddr)
                {
                    /* found it get counts and set sucess status */
                    u32OutFc = psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[idx].u32OutgoingFrameCounter;
                    u32InFc =  psAib->pu32IncomingFrameCounter[idx];
                    u8Status = 0;
                    break;
                }
            }
        }
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32OutFc, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32InFc, u8TxLength );
    }
    break;
    case E_SL_MSG_GET_APS_SERIAL_STATS:
    {
        /* don't include this message in these stats returned */
        u32SLRxCount--;
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32SLRxCount, u8TxLength );
        /* correct the rx count */
        u32SLRxCount++;

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32SLRxFail, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32SLTxStatusMsg, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32SLTxEventMsg, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32OverwrittenRXMessage, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32SLTxRetries, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32SLTxFailures, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32SL5Ms, u8TxLength );
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32SL8Ms, u8TxLength );
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32SL10Ms, u8TxLength );
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32Greater10Ms, u8TxLength );

    }
    break;
    case E_SL_MSG_SERIAL_SEQ_TEST:
    {
        uint8 au8Buffer[6];
        au8Buffer[0] =  0xff;
        au8Buffer[1] = 0xf7;
        au8Buffer[2] = 0xaa;


        vSL_WriteMessage(E_SL_MSG_NWK_STATUS_INDICATION, 3,  &u8ReceivedSeqNo, au8Buffer);
    }
    break;
    case E_SL_MSG_GET_MAC_TABLE_ENTRY:
    {
        uint16 u16TableIndex;
        ZPS_tsNwkNib *psNib = ZPS_psAplZdoGetNib();
        uint64 u64Address;

        /* copy u16TableIndex */
        u16TableIndex = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        if (psNib->sTblSize.u16MacAddTableSize <= u16TableIndex)
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
        else
        {
            u64Address = psNib->sTbl.pu64AddrExtAddrMap[u16TableIndex];
            ZNC_BUF_U64_UPD( &au8values[u8TxLength],  u64Address, u8TxLength );
        }
    }
    break;
    case E_SL_MSG_SET_KEY_TABLE_ENTRY:
    {
        uint16 u16TableIndex, u16Index;
        ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();

        u16Index = 0;

        /* copy u16TableIndex */
        u16TableIndex = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        if (psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable
                <= u16TableIndex)
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
        else
        {
            /* Copy sEntry for sending over serial */
            psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[u16TableIndex].u16ExtAddrLkup =
                    ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

            /* Both are byte arrays, endianness irrelevant */
            memcpy(psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[u16TableIndex].au8LinkKey,
                    &au8LinkRxBuffer[u16Index],
                    ZPS_SEC_KEY_LENGTH);
            u16Index += ZPS_SEC_KEY_LENGTH;

            psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[u16TableIndex].u32OutgoingFrameCounter =
                    ZNC_RTN_U32_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

            ZPS_vSaveAllZpsRecords();
            u8Status = ZPS_E_SUCCESS;
        }
        break;
    }

    case E_SL_SET_KEY_SEQ_NUMBER:
    {
        uint8 u8ActiveKeySeqNumber = au8LinkRxBuffer[0];
        ZPS_vNwkNibSetKeySeqNum(ZPS_pvAplZdoGetNwkHandle(), u8ActiveKeySeqNumber);

        break; 
    }
    case E_SL_MSG_REMOVE_DEVICE_FROM_BINDING_TABLE:
    {
        uint64 u64DeviceAddress = 0;

        /* copy u64MACAddress */
        u64DeviceAddress = ZNC_RTN_U64( au8LinkRxBuffer, 0);
        u8Status = zps_eAplAibRemoveBindTableEntryForMacAddress(ZPS_pvAplZdoGetAplHandle(), u64DeviceAddress );
    }

        break;
    case E_SL_MSG_GET_NWK_KEY_TABLE_ENTRY:
    {
        ZPS_tsNwkNib * thisNib;
        uint8 i;
        void * thisNet = ZPS_pvAplZdoGetNwkHandle();
        thisNib = ZPS_psNwkNibGetHandle(thisNet);

        for(i=0;i<thisNib->sTblSize.u8SecMatSet;i++)
        {
            if(thisNib->sTbl.psSecMatSet[i].u8KeySeqNum == thisNib->sPersist.u8ActiveKeySeqNumber)
            {
                /* endian ok, byte array to byte array */
                memcpy(&au8values[4], thisNib->sTbl.psSecMatSet[i].au8Key, ZPS_NWK_KEY_LENGTH);
                break;
            }
        }
        u8TxLength += ZPS_NWK_KEY_LENGTH;
    }
    break;

    case E_SL_MSG_GET_CLUSTER_DISCOVERY_STATE: {
        uint8 u8Endpoint;
        uint16 u16ClusterId;
        bool_t bOutput;
        bool_t bDiscoverable;

        uint16 u16Index = 0;

        /* copy u8Endpoint */
        u8Endpoint = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        /* copy u16ClusterId */
        u16ClusterId = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        /* copy bOutput */
        bOutput = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u8Status = ZPS_eAplAfGetEndpointDiscovery(u8Endpoint, u16ClusterId,
                bOutput, &bDiscoverable);

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  bDiscoverable, u8TxLength );

        break;
    }
    case E_SL_MSG_SET_CLUSTER_DISCOVERY_STATE: {
        uint8 u8Endpoint;
        uint16 u16ClusterId;
        bool_t bOutput;
        bool_t bDiscoverable;

        uint16 u16Index = 0;

        /* copy u8Endpoint */
        u8Endpoint = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        /* copy u16ClusterId */
        u16ClusterId = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        /* copy bOutput */
        bOutput = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        /* copy bDiscoverable */
        bDiscoverable = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u8Status = ZPS_eAplAfSetEndpointDiscovery(u8Endpoint, u16ClusterId,
                bOutput, bDiscoverable);
        break;
    }

    case E_SL_MSG_ZDO_REMOVE_DEVICE_REQ: {
        uint64 u64ParentAddr, u64ChildAddr;

        uint16 u16Index = 0;

        /* copy u64ParentAddr */
        u64ParentAddr= ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        /* copy u64ChildAddr */
        u64ChildAddr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u8Status = ZPS_eAplZdoRemoveDeviceReq(u64ParentAddr, u64ChildAddr);

        vCleanStackTables(u64ChildAddr);
        break;
    }
    case E_SL_MSG_ZDO_REMOVE_DEVICE_FROM_TABLES: {
            uint64 u64ParentAddr, u64ChildAddr;

            uint16 u16Index = 0;

            /* copy u64ParentAddr */
            u64ParentAddr= ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

            /* copy u64ChildAddr */
            u64ChildAddr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

            if (u64ParentAddr == ZPS_u64NwkNibGetExtAddr(ZPS_pvAplZdoGetNwkHandle()))
            {
                vCleanStackTables(u64ChildAddr);
            }
            else
            {
                u8Status = ZPS_eAplZdoRemoveDeviceReq(u64ParentAddr, u64ChildAddr);

                vCleanStackTables(u64ChildAddr);
            }
            break;
        }

    case E_SL_MSG_SET_APS_FRAME_COUNTER:
    {
        uint16 u16Index = 0;
        ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();
        uint64 u64IEEEAddress;
        uint32 u32FrameCounter;
        uint8 bInFC;
        uint16 u16TableIndex = 0;

        /* copy u32FrameCounter */
        u32FrameCounter = ZNC_RTN_U32_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        /* copy bIsInOrOut */
        bInFC = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        /* copy u64IEEEAddress */
        u64IEEEAddress = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;

        DBG_vPrintf(TRACE_APP, "Set Aps FC for %016llx bIn %d to %d\n", u64IEEEAddress, bInFC, u32FrameCounter);

        while(u16TableIndex < psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable)
        {
            /* check for matched entry */
            if(ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(),psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[u16TableIndex].u16ExtAddrLkup) == u64IEEEAddress)
            {
                if(!bInFC)
                {
                    psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[u16TableIndex].u32OutgoingFrameCounter = u32FrameCounter;
                }
                else
                {
                    psAib->pu32IncomingFrameCounter[u16TableIndex] = u32FrameCounter;
                }
                ZPS_vSaveAllZpsRecords();
                u8Status = 0;
                break;
            }

            u16TableIndex++;
        }
        break;
    }
    case E_SL_MSG_SET_NWK_FRAME_COUNT:
    {
        ZPS_tsNwkNib * thisNib;
        thisNib = ZPS_psNwkNibGetHandle( ZPS_pvAplZdoGetNwkHandle());
        uint16 u16Index = 0;
        uint16 u16NwkAddress;
        uint32 u32FrameCounter;
        uint8 bInFC;
        int i;

        u8Status = 0;

        /* copy u32FrameCounter */
        u32FrameCounter = ZNC_RTN_U32_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        /* copy bIsInOrOut */
        bInFC = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        /* copy u64IEEEAddress */
        u16NwkAddress = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        if (bInFC)
        {
            /* set the in FC for Device x */
            u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
            for (i=0; i<thisNib->sTblSize.u16NtActv; i++)
            {
                if (u16NwkAddress == thisNib->sTbl.psNtActv[i].u16NwkAddr)
                {
                    thisNib->sTbl.pu32InFCSet[i] = u32FrameCounter;
                    u8Status = 0;
                    break;
                }
            }
        }
        else
        {
            /* Set the out fc ofr this device */
            thisNib->sPersist.u32OutFC = u32FrameCounter;
        }
    }
    break;

    case E_SL_MSG_SET_NWK_STATE_ACTIVE:
    {
        ZPS_vSetNwkStateActive(ZPS_pvAplZdoGetNwkHandle());
    }
    break;

    case (E_SL_MSG_NETWORK_REMOVE_DEVICE): {
        uint64 u64LookupAddress;
        uint16 u16Index = 0;

        u16TargetAddress = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u64LookupAddress = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u8Status = eZdpMgmtLeave(u16TargetAddress, u64LookupAddress,
                au8LinkRxBuffer[10], au8LinkRxBuffer[11], &u8ApsTSN);
    }
        break;
    case (E_SL_MSG_REMOVE_REMOTE_DEVICE): {
        uint64 u64LookupAddress;

        u64LookupAddress = ZNC_RTN_U64( au8LinkRxBuffer,0 );

        u8Status = ZPS_eAplZdoLeaveNetwork(u64LookupAddress,
                au8LinkRxBuffer[8], au8LinkRxBuffer[9]);
    }
        break;
    case (E_SL_MSG_BIND):
    case (E_SL_MSG_UNBIND): {
        uint64 u64BindAddress;
        uint16 u16Clusterid;
        uint8 u8SrcEp, /*offset = 0,*/  u8DstEp, u8DstAddrMode;
        ZPS_tuAddress uDstAddress;
        bool_t bBind;
        uint16 u16Index = 0;

        u64BindAddress = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u8SrcEp = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u16Clusterid = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u8DstAddrMode = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        if (u8DstAddrMode == 0x3) {
            uDstAddress.u64Addr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

            u8DstEp = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        } else {
            uDstAddress.u16Addr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
            u8DstEp = 0;
        }
        if (u16PacketType == E_SL_MSG_BIND) {
            bBind = TRUE;
        } else {
            bBind = FALSE;
        }
        u8Status = eBindUnbindEntry(bBind, u64BindAddress, u8SrcEp,
                u16Clusterid, &uDstAddress, u8DstEp, u8DstAddrMode,
                &u8ApsTSN);
    }
        break;
    case E_SL_MSG_ZDO_BIND:
    {
        uint16 u16ClusterId;
        uint8 u8SrcEndpoint;
        uint16 u16DstNwkAddr;
        uint64 u64DstIeeeAddr;
        uint8 u8DstEndpoint;
        uint8 u8DstAddrMode;
        uint16 u16Index = 0;

        u64DstIeeeAddr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u16ClusterId = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u16DstNwkAddr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u8SrcEndpoint = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        u8DstEndpoint = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        u8DstAddrMode = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        if (u8DstAddrMode == ZPS_E_ADDR_MODE_GROUP)
        {
            u8Status = ZPS_eAplZdoBindGroup( u16ClusterId,
                                             u8SrcEndpoint,
                                             u16DstNwkAddr);
        }
        else
        {
            u8Status = ZPS_eAplZdoBind( u16ClusterId,
                                        u8SrcEndpoint,
                                        u16DstNwkAddr,
                                        u64DstIeeeAddr,
                                        u8DstEndpoint);
        }
    }
    break;
    case E_SL_MSG_ZDO_UNBIND:
    {
        uint16 u16ClusterId;
        uint8 u8SrcEndpoint;
        uint16 u16DstNwkAddr;
        uint64 u64DstIeeeAddr;
        uint8 u8DstEndpoint;
        uint8 u8DstAddrMode;
        uint16 u16Index = 0;

        u64DstIeeeAddr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u16ClusterId = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u16DstNwkAddr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u8SrcEndpoint = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        u8DstEndpoint = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        u8DstAddrMode = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        if (u8DstAddrMode == ZPS_E_ADDR_MODE_GROUP)
        {
            u8Status = ZPS_eAplZdoUnbindGroup( u16ClusterId,
                                             u8SrcEndpoint,
                                             u16DstNwkAddr);
        }
        else
        {
            u8Status = ZPS_eAplZdoUnbind( u16ClusterId,
                                        u8SrcEndpoint,
                                        u16DstNwkAddr,
                                        u64DstIeeeAddr,
                                        u8DstEndpoint);
        }
    }
    break;
    case (E_SL_MSG_RESET): {
        ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8Status, u8TempLen);
        ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8ApsTSN, u8TempLen);
        ZNC_BUF_U16_UPD   ( &au8values[u8TempLen], u16PacketType, u8TempLen);

        bRxBufferLocked = FALSE;
        vSL_WriteMessage(E_SL_MSG_STATUS_MSG, u8TxLength,  &u8ReceivedSeqNo, au8values);
        /* wait for response to be sent, then reset the module */
        //vAppWaitUARTTx();
        do { } while (!UART_bTxReady());
#ifndef DUAL_MODE_APP
        /*
         * If OT was initialized, it will receive a RCP RESET / Timeout (depending if
         * it was sending commands at that time.
         */
        App_vSoftwareReset();
#endif
        return;
    }
        break;
    case (E_SL_MSG_START_NETWORK):
    {
        u8Status = u8ControlNodeStartNetwork();
    }
        break;
    case (E_SL_MSG_ORPHAN_REJOIN_NWK):
    {
        u8Status = ZPS_eAplZdoOrphanRejoinNetwork();
    }
        break;
    case (E_SL_MSG_START_SCAN): {
        DBG_vPrintf(TRACE_APP, "\E_SL_MSG_START_SCAN\n");
        vControlNodeScanStart();
    }
        break;
    case (E_SL_MSG_SETUP_FOR_INTERPAN):
    {
        uint32 u32ChannelMask;

        u32ChannelMask = ZNC_RTN_U16( au8LinkRxBuffer, 0 );
        u8Status = u8ControlNodeSetUpForInterPan( u32ChannelMask);
    }
        break;
    case E_SL_MSG_REJOIN_NETWORK:

        break;
    case E_SL_MSG_INSECURE_REJOIN_NETWORK:

         break;

    case E_SL_MSG_INSECURE_REJOIN_SHORT_PAN:
    {
    }
    break;

    case E_SL_MSG_GET_DEFAULT_DISTRIBUTED_APS_LINK_KEY:
    {
        ZPS_tsAplApsKeyDescriptorEntry* psKeyDescr;

        if (*(ZPS_psAplDefaultDistributedAPSLinkKey()) == NULL)
        {
            u8Status = ZPS_APL_ZDP_E_NO_MATCH;
        }
        else
        {
            psKeyDescr = *(ZPS_psAplDefaultDistributedAPSLinkKey());

            /* Copy sEntry for sending over serial */
            ZNC_BUF_U16_UPD( &au8values[u8TxLength], psKeyDescr->u16ExtAddrLkup, u8TxLength );

            /* Both are byte arrays, endianness irrelevant */
            memcpy(&au8values[u8TxLength], psKeyDescr->au8LinkKey,
                    ZPS_SEC_KEY_LENGTH);
            u8TxLength += ZPS_SEC_KEY_LENGTH;

            ZNC_BUF_U32_UPD( &au8values[u8TxLength],  psKeyDescr->u32OutgoingFrameCounter, u8TxLength );

            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  psKeyDescr->u8BitMapSecLevl, u8TxLength );

            u8Status = ZPS_E_SUCCESS;
        }
    }
       break;
    case E_SL_MSG_GET_DEFAULT_GLOBAL_APS_LINK_KEY:
    {
        ZPS_tsAplApsKeyDescriptorEntry* psKeyDescr;

        if (*(ZPS_psAplDefaultGlobalAPSLinkKey()) == NULL)
        {
            u8Status = ZPS_APL_ZDP_E_NO_MATCH;
        }
        else
        {
            psKeyDescr = *(ZPS_psAplDefaultGlobalAPSLinkKey());

            /* Copy sEntry for sending over serial */
            ZNC_BUF_U16_UPD( &au8values[u8TxLength], psKeyDescr->u16ExtAddrLkup, u8TxLength );

            /* Both are byte arrays, endianness irrelevant */
            memcpy(&au8values[u8TxLength], psKeyDescr->au8LinkKey,
                    ZPS_SEC_KEY_LENGTH);
            u8TxLength += ZPS_SEC_KEY_LENGTH;

            ZNC_BUF_U32_UPD( &au8values[u8TxLength],  psKeyDescr->u32OutgoingFrameCounter, u8TxLength );

            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  psKeyDescr->u8BitMapSecLevl, u8TxLength );

            u8Status = ZPS_E_SUCCESS;
        }
    }
    break;

    case E_SL_MSG_GET_DEFAULT_TC_APS_LINK_KEY:
    {
        ZPS_tsAplApsKeyDescriptorEntry* psKeyDescr;

        if (*(ZPS_psAplDefaultTrustCenterAPSLinkKey()) == NULL)
        {
        u8Status = ZPS_APL_ZDP_E_NO_MATCH;
        }
        else
        {
            psKeyDescr = *(ZPS_psAplDefaultTrustCenterAPSLinkKey());

            /* Copy sEntry for sending over serial */
            ZNC_BUF_U16_UPD( &au8values[u8TxLength], psKeyDescr->u16ExtAddrLkup, u8TxLength );

            /* Both are byte arrays, endianness irrelevant */
            memcpy(&au8values[u8TxLength], psKeyDescr->au8LinkKey,
                ZPS_SEC_KEY_LENGTH);
            u8TxLength += ZPS_SEC_KEY_LENGTH;

            ZNC_BUF_U32_UPD( &au8values[u8TxLength],  psKeyDescr->u32OutgoingFrameCounter, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  psKeyDescr->u8BitMapSecLevl, u8TxLength );

            u8Status = ZPS_E_SUCCESS;
            }
        }
         break;

    case (E_SL_MSG_GET_APS_SEQ_NUM):
    {
        uint8 u8ApsSeqNum = ZPS_u8ApsGetSeqNum(ZPS_pvAplZdoGetAplHandle());

        /* Copy APS next sequence number for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8ApsSeqNum, u8TxLength );

        u8Status = ZPS_E_SUCCESS;
        break;
    }

    case (E_SL_MSG_GET_FRAGMENTATION_SUPPORT):
    {
        bool_t bFragSup = ZPS_bAplDoesDeviceSupportFragmentation(ZPS_pvAplZdoGetAplHandle());

        /* Copy fragmentation support for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  bFragSup, u8TxLength );

        u8Status = ZPS_E_SUCCESS;
        break;
    }

    case (E_SL_MSG_GET_MAX_PAYLOAD_SIZE):
    {
        bool_t u8MaxPayloadSize;
        uint16_t u16Addr;
        
        u16Addr = ZNC_RTN_U16( au8LinkRxBuffer, 0 );
        u8MaxPayloadSize = ZPS_u8AplGetMaxPayloadSize(ZPS_pvAplZdoGetAplHandle(), u16Addr);

        /* Copy max payload size for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8MaxPayloadSize, u8TxLength );

        u8Status = ZPS_E_SUCCESS;
        break;
    }

    case (E_SL_MSG_SET_SECURITY): 
    {
        ZPS_vAplSecSetInitialSecurityState(au8LinkRxBuffer[0],
                &au8LinkRxBuffer[3], au8LinkRxBuffer[1], au8LinkRxBuffer[2]);
    }
        break;

    case E_SL_MSG_SET_DEPTH:
    {
        uint8 u8Depth = au8LinkRxBuffer[0];
        ZPS_vNwkNibSetDepth(ZPS_pvAplZdoGetNwkHandle(), u8Depth);
    }
        break;

    case (E_SL_MSG_ERASE_PERSISTENT_DATA): {
        DBG_vPrintf(TRACE_APP, "Clearing Context\n");
        PDM_vDeleteAllDataRecords();

        ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8Status, u8TempLen);
        ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8ApsTSN, u8TempLen);
        ZNC_BUF_U16_UPD   ( &au8values[u8TempLen], u16PacketType, u8TempLen);

        bRxBufferLocked = FALSE;

        vSL_WriteMessage(u16ReturnMsgType, u8TxLength,  &u8ReceivedSeqNo, au8values);
        //vAppWaitUARTTx();
        do { } while(!UART_bTxReady());
#ifndef DUAL_MODE_APP
        /*
         * If OT was initialized, it will receive a RCP RESET / Timeout (depending if
         * it was sending commands at that time.
         */
        App_vSoftwareReset();
#endif
        return;
    }
        break;
    case (E_SL_MSG_MATCH_DESCRIPTOR_REQUEST): {
        uint16 au16InClusterList[10], au16OutClusterList[10];
        uint16 u16Profile, u16Index = 0, u16NwkAoI;
        uint8 u8InClusterCount, u8OutClusterCount;
        int i;
        /*
         * The layout in the serial buffer is as follows:
         *
         * +--------+--------+--------+----+--------+   +--------+----+--------+   +--------+
         * |Dst Addr|AoI     |Profile |# IC|IC0     |...|ICn     |# OC|OC0     |...|OCn     |
         * +--------+--------+--------+----+--------+   +--------+----+--------+   +--------+
         * 0        2        4        6    7        9            ^    ^
         *                                                       |    |
         *                                                       |    +-- 8 + #IC x 2
         *                                                       |
         *                                                       +-- 7 + #IC x 2
         * All calculations above are made on bytes
         */
        u16TargetAddress = ZNC_RTN_U16_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        u16NwkAoI = ZNC_RTN_U16_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        u16Profile = ZNC_RTN_U16_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        u8InClusterCount = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        for (i=0; i<u8InClusterCount; i++)
        {
            au16InClusterList[i] = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }

        u8OutClusterCount = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        for (i=0; i<u8OutClusterCount; i++)
        {
            au16OutClusterList[i] = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }

        DBG_vPrintf(TRACE_APP, "u8InClusterCount = %d\n", u8InClusterCount);
        DBG_vPrintf(TRACE_APP, "u8OutClusterCount = %d\n", u8OutClusterCount);
        DBG_vPrintf(TRACE_APP, "u16TargetAddress = %d\n", u16TargetAddress);
        DBG_vPrintf(TRACE_APP, "u16NwkAoI = %d\n", u16NwkAoI);
        DBG_vPrintf(TRACE_APP, "u16Profile = %d\n", u16Profile);

        u8Status = eZdpMatchDescReq(u16TargetAddress, u16NwkAoI, u16Profile,
                u8InClusterCount, au16InClusterList, u8OutClusterCount,
                au16OutClusterList, &u8ApsTSN);

    }
        break;

    case (E_SL_MSG_NODE_DESCRIPTOR_REQUEST): {
        u16TargetAddress = ZNC_RTN_U16( au8LinkRxBuffer, 0 );
        u8Status = eZdpNodeDescReq(u16TargetAddress, &u8ApsTSN);
    }
        break;

    case (E_SL_MSG_SIMPLE_DESCRIPTOR_REQUEST): {
        uint16 u16Index = 0;
        ZPS_tuAddress uDstAddr;
        bool_t bIsExtAddress;
        ZPS_tsAplZdpSimpleDescReq sZdpSimpleDescReq;

        /* copy bIsExtAddress */
        bIsExtAddress = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        if(bIsExtAddress)
        {   /* copy u64IEEEAddress */
            uDstAddr.u64Addr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }
        else
        {
            /* copy u16ShortAddress */
            uDstAddr.u16Addr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }

        /* copy u16ShortAddress */
        sZdpSimpleDescReq.u16NwkAddrOfInterest = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        /* copy u8Endpoint */
        sZdpSimpleDescReq.u8EndPoint = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u8Status = eZdpSimpleDescReq(bIsExtAddress, uDstAddr, &sZdpSimpleDescReq,
                &u8ApsTSN);
    }
        break;
    case (E_SL_MSG_IEEE_ADDRESS_REQUEST): {
        uint16 u16LookupAddress;
        uint16 u16Index = 0;

        u16TargetAddress = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u16LookupAddress = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u8Status = eZdpIeeeAddrReq(u16TargetAddress, u16LookupAddress,
                au8LinkRxBuffer[4], au8LinkRxBuffer[5], &u8ApsTSN);
    }
        break;

    case (E_SL_MSG_NETWORK_ADDRESS_REQUEST): {
        uint64 u64LookupAddress;
        uint16 u16Index = 0;

        u16TargetAddress = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u64LookupAddress = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        uint8 u8RequestType = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        uint8 u8StartIndex = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u8Status = eZdpNwkAddrReq(u16TargetAddress, u64LookupAddress,
                u8RequestType, u8StartIndex, &u8ApsTSN);
    }
        break;
    case (E_SL_MSG_PERMIT_JOINING_REQUEST): {
        u8Status = ZPS_eAplZdoPermitJoining(au8LinkRxBuffer[0]);
    }
        break;
    case (E_SL_MSG_ZDO_PERMIT_JOIN_REQUEST): {
        u16TargetAddress = ZNC_RTN_U16( au8LinkRxBuffer, 0 );
        u8Status = eZdpPermitJoiningReq(u16TargetAddress,au8LinkRxBuffer[2],au8LinkRxBuffer[3],&u8ApsTSN);
    }
        break;

    case (E_SL_MSG_POWER_DESCRIPTOR_REQUEST): {
        u16TargetAddress = ZNC_RTN_U16( au8LinkRxBuffer, 0 );
        u8Status = eZdpPowerDescReq(u16TargetAddress, &u8ApsTSN);
    }
        break;

    case (E_SL_MSG_ACTIVE_ENDPOINT_REQUEST): {
        uint16 u16TargetAddr, u16Index = 0;
        ZPS_tuAddress uDstAddr;
        bool_t bIsExtAddress;

        /* copy bIsExtAddress */
        bIsExtAddress = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        if(bIsExtAddress)
        {   /* copy u64IEEEAddress */
            uDstAddr.u64Addr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }
        else
        {
            /* copy u16ShortAddress */
            uDstAddr.u16Addr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }

        /* copy target address */
        u16TargetAddr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u8Status = eZdpActiveEndpointReq(uDstAddr, u16TargetAddr, &u8ApsTSN);
    }
        break;
    case (E_SL_MSG_IS_DEVICE_KEY_PRESENT): {
        uint16 i;
        bool_t bIsKeyPresent = FALSE;
        uint64 u64IeeeAddress;
        ZPS_tsAplAib *psAib =
                zps_psAplAibGetAib(ZPS_pvAplZdoGetAplHandle());

        /* copy u64MACAddress */
        u64IeeeAddress = ZNC_RTN_U64( au8LinkRxBuffer, 0 );

        if(0x0000000000000000U != u64IeeeAddress)
        {
            for (i = 0; i
                    < psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable; i++) {
                if (u64IeeeAddress
                        == ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(),psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[i].u16ExtAddrLkup)) {
                    bIsKeyPresent = TRUE;
                }
            }
        }

        /* Copy Is key present for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  bIsKeyPresent, u8TxLength );
        u8Status = ZPS_E_SUCCESS;
    }
        break;
    case E_SL_MSG_GET_APS_KEY_TABLE_SIZE: {
        uint16 u16KeyTableSize;
        ZPS_tsAplAib *psAib =
                zps_psAplAibGetAib(ZPS_pvAplZdoGetAplHandle());

        u16KeyTableSize
                = (uint16) psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable;
        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  u16KeyTableSize, u8TxLength );
    }
        break;
    case E_SL_MSG_GET_GROUP_TABLE_SIZE: {
        uint32 u32KeyTableSize;
        ZPS_tsAplAib *psAib =
                zps_psAplAibGetAib(ZPS_pvAplZdoGetAplHandle());

        u32KeyTableSize
                = (uint32) psAib->psAplApsmeGroupTable->u32SizeOfGroupTable;
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32KeyTableSize, u8TxLength );
    }
        break;
    case E_SL_MSG_GET_NEIGHBOR_TABLE_SIZE: {
        uint16 u16TableSize;
        ZPS_tsNwkNib * thisNib;

        void * thisNet = ZPS_pvAplZdoGetNwkHandle();
        thisNib = ZPS_psNwkNibGetHandle(thisNet);

        u16TableSize = thisNib->sTblSize.u16NtActv;

        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  u16TableSize, u8TxLength );
    }
        break;
    case E_SL_MSG_GET_ADDRESS_MAP_TABLE_SIZE: {
        uint16 u16TableSize;
        ZPS_tsNwkNib * thisNib;

        void * thisNet = ZPS_pvAplZdoGetNwkHandle();
        thisNib = ZPS_psNwkNibGetHandle(thisNet);

        u16TableSize = thisNib->sTblSize.u16AddrMap;
        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  u16TableSize, u8TxLength );
    }
        break;
    case E_SL_MSG_GET_ROUTING_TABLE_SIZE:
    {
        uint16 u16TableSize;
        ZPS_tsNwkNib * thisNib;

        void * thisNet = ZPS_pvAplZdoGetNwkHandle();
        thisNib = ZPS_psNwkNibGetHandle(thisNet);

        u16TableSize = thisNib->sTblSize.u16Rt;

        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  u16TableSize, u8TxLength );
    }
    break;
    case E_SL_MSG_GET_GROUP_TABLE_ENTRY_GROUP_ID:
    {
        uint16 u16GroupId;
        uint32 u32Index;
        ZPS_tsAplAib *psAib = zps_psAplAibGetAib(ZPS_pvAplZdoGetAplHandle());

        u32Index = ZNC_RTN_U32( au8LinkRxBuffer, 0 );
        u16GroupId = psAib->psAplApsmeGroupTable->psAplApsmeGroupTableId[u32Index].u16Groupid;

        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  u16GroupId, u8TxLength );
    }
        break;
    case E_SL_MSG_GET_GROUP_TABLE_ENTRY_ENDPOINT_ELEMENT:
    {
        uint8 u8Endpoint, u8ByteOffset;
        uint16 u16Index = 0;
        uint32 u32EntryIndex;
        ZPS_tsAplAib *psAib = zps_psAplAibGetAib(ZPS_pvAplZdoGetAplHandle());

        /* Copy u8ByteOffset */
        u8ByteOffset = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        /* Copy u32EntryIndex */
        u32EntryIndex =  ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u8Endpoint = psAib->psAplApsmeGroupTable->psAplApsmeGroupTableId[u32EntryIndex].au8Endpoint[u8ByteOffset];

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8Endpoint, u8TxLength );
    }
        break;
    case E_SL_MSG_SET_SECURITY_TIMEOUT:
    {
        ZPS_tsAplAib *psAib = zps_psAplAibGetAib(ZPS_pvAplZdoGetAplHandle());
        uint8 u8TimeOut = au8LinkRxBuffer[0];
        if ((u8TimeOut >= 1) && (u8TimeOut <= 65))
        {
            psAib->u16ApsSecurityTimeOutPeriod = u8TimeOut * 1000;
            u8Status = 0;
        }
        else
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
    }
    break;

    case E_SL_MSG_ADD_ADDRESS_MAP_ENTRY:
    {
        uint64 u64ExtAddress;
        uint16 u16NwkAddr;
        ZPS_teStatus eStatus;

        u16NwkAddr = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        u64ExtAddress = ZNC_RTN_U64( au8LinkRxBuffer, 2 );

        eStatus = ZPS_eAplZdoAddAddrMapEntry(u16NwkAddr, u64ExtAddress, TRUE);
        if (eStatus == ZPS_E_SUCCESS)
        {
            u8Status = TRUE;
        }
        else
        {
            u8Status = FALSE;
        }
    }
    break;

    case E_SL_MSG_REQUEST_KEY_REQ:
    {
        uint64 u64IeeePartnerAddress;
        uint8 u8KeyType;
        u8KeyType = au8LinkRxBuffer[0];

        u64IeeePartnerAddress = ZNC_RTN_U64( au8LinkRxBuffer, 1 );

        u8Status = ZPS_eAplZdoRequestKeyReq(u8KeyType,
                u64IeeePartnerAddress);
    }
    break;

    case E_SL_MSG_GET_NEIGHBOR_TABLE_ENTRY:
    {
        uint16 u16TableIndex;
        uint16 u16Index = 0;
        ZPS_tsNwkNib * thisNib;
        void * thisNet = ZPS_pvAplZdoGetNwkHandle();
        thisNib = ZPS_psNwkNibGetHandle(thisNet);
        ZPS_tsNwkActvNtEntry sEntry;
        uint64 u64IeeeAddr;

        /* copy u16TableIndex */
        u16TableIndex = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        if (thisNib->sTblSize.u16NtActv <= u16TableIndex)
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
        else
        {
            sEntry = thisNib->sTbl.psNtActv[u16TableIndex];

            /* Copy sEntry for sending over serial */
            memcpy(&au8values[4], &sEntry.sNode, sizeof(zps_tsNwkSlistNode));
            u8TxLength += sizeof(zps_tsNwkSlistNode);

            u64IeeeAddr = ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(), sEntry.u16Lookup    );

            ZNC_BUF_U64_UPD( &au8values[u8TxLength],  u64IeeeAddr, u8TxLength );
            ZNC_BUF_U16_UPD( &au8values[u8TxLength],  sEntry.u16NwkAddr, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8TxFailed, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8LinkQuality, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8Age, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8ZedTimeoutindex, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.i8TXPower, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8MacID, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.uAncAttrs.au8Field[0], u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.uAncAttrs.au8Field[1], u8TxLength );

            u8Status = ZPS_E_SUCCESS;
        }
    }
    break;
    case E_SL_MSG_GET_NEIGHBOR_TABLE_ENTRY_BY_ADDRESS:
    {
        uint8 u8AddrMode;
        uint16 u16Index = 0U, u16i;
        ZPS_tsNwkNib * thisNib;
        thisNib = ZPS_psNwkNibGetHandle(ZPS_pvAplZdoGetNwkHandle());
        ZPS_tsNwkActvNtEntry sEntry;
        bool_t found = FALSE;
        ZPS_tuAddress uAddr;
        uint64 u64IeeeAddr;

        /* copy u8AddrMode */
        u8AddrMode = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        if (u8AddrMode == ZPS_E_ADDR_MODE_IEEE)
        {
            uAddr.u64Addr = ZNC_RTN_U64_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        }
        else
        {
            uAddr.u16Addr = ZNC_RTN_U16_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        }

        for (u16i = 0U; u16i <= thisNib->sTblSize.u16NtActv; u16i++)
        {
            sEntry = thisNib->sTbl.psNtActv[u16i];

            if ((u8AddrMode == ZPS_E_ADDR_MODE_IEEE) && (ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(), sEntry.u16Lookup) == uAddr.u64Addr))
            {
                found = TRUE;
                break;
            }
            if ((u8AddrMode != ZPS_E_ADDR_MODE_IEEE) && (sEntry.u16NwkAddr == uAddr.u16Addr))
            {
                found = TRUE;
                break;
            }
        }

        if (found)
        {
            /* Copy sEntry for sending over serial */
            memcpy(&au8values[4], &sEntry.sNode, sizeof(zps_tsNwkSlistNode));
            u8TxLength += sizeof(zps_tsNwkSlistNode);

            u64IeeeAddr = ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(), sEntry.u16Lookup);
            ZNC_BUF_U64_UPD(&au8values[u8TxLength], u64IeeeAddr, u8TxLength);
            ZNC_BUF_U16_UPD(&au8values[u8TxLength], sEntry.u16NwkAddr, u8TxLength);
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8TxFailed, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8LinkQuality, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8Age, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8ZedTimeoutindex, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.i8TXPower, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8MacID, u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.uAncAttrs.au8Field[0], u8TxLength );
            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.uAncAttrs.au8Field[1], u8TxLength );

            u8Status = ZPS_E_SUCCESS;
        }
        else {
            // Not found error
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
    }
    break;

    case E_SL_MSG_GET_ADDRESS_MAP_TABLE_ENTRY:
    {
        uint16 u16TableIndex;
        uint16 u16Index = 0;
        ZPS_tsNwkNib * thisNib;
        uint64 u64IeeeAddress;
        void * thisNet = ZPS_pvAplZdoGetNwkHandle();
        thisNib = ZPS_psNwkNibGetHandle(thisNet);

        /* copy u16TableIndex */
        u16TableIndex = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        if (thisNib->sTblSize.u16AddrMap <= u16TableIndex)
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
        else
        {
            /* Copy sEntry for sending over serial */
            ZNC_BUF_U16_UPD( &au8values[u8TxLength],  thisNib->sTbl.pu16AddrMapNwk[u16TableIndex], u8TxLength );

            u64IeeeAddress = ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(),thisNib->sTbl.pu16AddrLookup[u16TableIndex]);
            ZNC_BUF_U64_UPD( &au8values[u8TxLength],  u64IeeeAddress, u8TxLength );

            u8Status = ZPS_E_SUCCESS;
        }
    }
    break;

    case E_SL_MSG_GET_ROUTING_TABLE_ENTRY:
    {
        uint16 u16TableIndex;
        ZPS_tsNwkNib * thisNib;
        void * thisNet = ZPS_pvAplZdoGetNwkHandle();
        thisNib = ZPS_psNwkNibGetHandle(thisNet);
        ZPS_tsNwkRtEntry sEntry;
        /* copy u16TableIndex */
        u16TableIndex = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        if (thisNib->sTblSize.u16Rt <= u16TableIndex)
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
        else
        {
            sEntry = thisNib->sTbl.psRt[u16TableIndex];

            /* Copy sEntry for sending over serial */
            ZNC_BUF_U16_UPD( &au8values[u8TxLength],  sEntry.u16NwkDstAddr, u8TxLength );
            ZNC_BUF_U16_UPD( &au8values[u8TxLength],  sEntry.u16NwkNxtHopAddr, u8TxLength );

            u8Status = ZPS_E_SUCCESS;
        }
    }
    break;

    case E_SL_MSG_CHANGE_CHANNEL:
    {
        uint32 u32Value;

        u32Value = ZNC_RTN_U32( au8LinkRxBuffer, 0 );

        u8Status = u8AppChangeChannel(u32Value);
    }
    break;

    case E_SL_MSG_SET_CHANNEL:
    {
        ZPS_vNwkNibSetChannel( ZPS_pvAplZdoGetNwkHandle(), au8LinkRxBuffer[0]);
    }
    break; 

    case E_SL_MSG_SET_UPDATE_ID:
    {
        ZPS_vNwkNibSetUpdateId(ZPS_pvAplZdoGetNwkHandle(), au8LinkRxBuffer[0]);
        break;
    }
 
    case E_SL_MSG_SET_TX_POWER:
    {
        uint32 u32Power;

        u32Power = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        u8Status = eAppApiPlmeSet(PHY_PIB_ATTR_TX_POWER, u32Power);
        if ( PHY_ENUM_SUCCESS == u8Status )
        {
            u8Status = MAC_ENUM_SUCCESS;
        }
        else if ( PHY_ENUM_INVALID_PARAMETER == u8Status )
        {
            u8Status = MAC_ENUM_INVALID_PARAMETER;
        }
        else if ( PHY_ENUM_UNSUPPORTED_ATTRIBUTE == u8Status )
        {
            u8Status = MAC_ENUM_UNSUPPORTED_ATTRIBUTE;
        }
        else
        {
            DBG_vPrintf(TRACE_APP, "Unknown return value for eAppApiPlmeSet u8Status: %d \r\n", u8Status);
        }
        DBG_vPrintf(TRACE_APP, "\n eAppApiPlmeSet done = %d, u8Status: %d \r\n", u32Power, u8Status);

    }
    break;
    case E_SL_MSG_REMOVE_LINK_KEY:
    {
        uint64 u64IeeeAddr;

        u64IeeeAddr = ZNC_RTN_U64( au8LinkRxBuffer, 0 );

        u8Status = ZPS_eAplZdoRemoveLinkKey(u64IeeeAddr);
        DBG_vPrintf(TRACE_APP, "\n ZPS_eAplZdoRemoveLinkKey status = %d \r\n", u8Status);
    }
    break;
    case E_SL_MSG_CONVERT_ENERGY_TO_DBM:
    {
        uint8 u8Energy;
        int16 i16EnergyIndBm;

        u8Energy = au8LinkRxBuffer[0];

        u8Energy = 255;
        i16EnergyIndBm = -1;

        /* Just to get rid of unused warning */
        u8Energy++;

        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  i16EnergyIndBm, u8TxLength );
    }
    break;

    case E_SL_MSG_CONVERT_LQI_TO_RSSI_DBM:
    {
        uint8 u8Lqi, u8MacIf;
        int16 i16Rssi;

        u8Lqi = au8LinkRxBuffer[0];
        u8MacIf = au8LinkRxBuffer[1];

        if (u8MacIf < ZPS_psMacIFTGetTable()->u8NumInterfaces)
        {
            if (u8MacIf == MAC_ID_SOC)
            {
                i16Rssi = -127;
            }
            else
            {
                i16Rssi = ( ( (u8Lqi * 53970 ) >> 17) - 100);
            }
            ZNC_BUF_U16_UPD( &au8values[u8TxLength],  i16Rssi, u8TxLength );
        }
        else
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
    }
    break;

    case E_SL_MSG_NWK_MANAGER_STATE:
    {
        uint8 u8NwkManagerState;

        u8NwkManagerState = ZPS_u8NwkManagerState();

        DBG_vPrintf(TRACE_APP, "\n u8NwkManagerState = %d \r\n", u8NwkManagerState);
        DBG_vPrintf(TRACE_APP, "\n au8values[4] = %d \r\n", au8values[4]);

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8NwkManagerState, u8TxLength );
    }
    break;
    case E_SL_MSG_GET_TC_ADDRESS:
    {
        uint64 u64IEEEAddr;

        u64IEEEAddr = ZPS_eAplAibGetApsTrustCenterAddress();

        ZNC_BUF_U64_UPD( &au8values[u8TxLength],  u64IEEEAddr, u8TxLength );
    }
    break;

    case E_SL_MSG_UPDATE_DEFAULT_LINK_KEY:
    {
        ZPS_tsAplAib *psAib = zps_psAplAibGetAib(ZPS_pvAplZdoGetAplHandle());

        memcpy(psAib->psAplDefaultTCAPSLinkKey->au8LinkKey,au8LinkRxBuffer,16);
        ZPS_vSaveAllZpsRecords();
    }
    break;

    case E_SL_MSG_TRANSPORT_NETWORK_KEY:
    {
        uint8 au8Key[ZPS_SEC_KEY_LENGTH], u8KeySeqNum;
        uint16 u16Index = 0x00;
        uint8 u8DstAddrMode;
        ZPS_tuAddress uDstAddress;
        bool_t bUseParent;
        uint64 u64ParentAddr = 0;

        /* copy u8DstAddrMode */
        u8DstAddrMode = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        if(u8DstAddrMode == ZPS_E_ADDR_MODE_IEEE)
        {
            uDstAddress.u64Addr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }
        else
        {
            uDstAddress.u16Addr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }
        /* copy au8Key */
        /* Both are byte arrays, endianness irrelevant */
        memcpy(au8Key, &au8LinkRxBuffer[u16Index], ZPS_SEC_KEY_LENGTH);
        u16Index += ZPS_SEC_KEY_LENGTH;

        /* copy u8KeySeqNum */
        u8KeySeqNum = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        /* copy bUseParent */
        bUseParent = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        if(bUseParent)
        {
            u64ParentAddr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }
        u8Status = ZPS_eAplZdoTransportNwkKey(u8DstAddrMode, uDstAddress, au8Key,
                                              u8KeySeqNum,bUseParent,u64ParentAddr);
    }
    break;

    case E_SL_MSG_SWITCH_KEY_REQUEST:
    {
        uint8 u8KeySeqNum;
        uint16 u16Index = 0x00;
        uint8 u8DstAddrMode;
        ZPS_tuAddress uDstAddress;

        /* copy u8DstAddrMode */
        u8DstAddrMode = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        if(u8DstAddrMode == ZPS_E_ADDR_MODE_IEEE)
        {
            uDstAddress.u64Addr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }
        else
        {
            uDstAddress.u16Addr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }
        /* copy u8KeySeqNum */
        u8KeySeqNum = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        u8Status = ZPS_eAplZdoSwitchKeyReq(u8DstAddrMode, uDstAddress,u8KeySeqNum);
    }
    break;

    case E_SL_MSG_CLEAR_NETWORK_KEY:
    {
        uint8 j;
        ZPS_tsNwkNib * thisNib;

        thisNib = ZPS_psNwkNibGetHandle(ZPS_pvAplZdoGetNwkHandle());
        for(j=0;j<thisNib->sTblSize.u8SecMatSet;j++)
        {
            if(thisNib->sTbl.psSecMatSet[j].u8KeySeqNum == au8LinkRxBuffer[0])
            {
                thisNib->sTbl.psSecMatSet[j].u8KeySeqNum = 0xFF;
                thisNib->sTbl.psSecMatSet[j].au8Key[0] = 0xFF;
                ZPS_vNwkSaveSecMat(ZPS_pvAplZdoGetNwkHandle());
            }
        }
    }
    break;

    case E_SL_MSG_SET_NETWORK_KEY:
    {
        ZPS_tsNwkNib * s_psNib;

        s_psNib = ZPS_psNwkNibGetHandle(ZPS_pvAplZdoGetNwkHandle());


        /* Store the Network Key */
        /* Both are byte arrays, endianness irrelevant */
        s_psNib->sTbl.psSecMatSet[0].u8KeySeqNum = 0;
        memcpy(s_psNib->sTbl.psSecMatSet[0].au8Key, au8LinkRxBuffer, ZPS_NWK_KEY_LENGTH);
        s_psNib->sTbl.psSecMatSet[0].u8KeyType = ZPS_NWK_SEC_NETWORK_KEY;

        /* Make this the Active Key */
        ZPS_vNwkNibSetKeySeqNum(ZPS_pvAplZdoGetNwkHandle(),0);
        ZPS_vNwkSaveSecMat(ZPS_pvAplZdoGetNwkHandle());
    }
    break;

    case E_SL_MSG_SET_TC_LOCKDOWN_OVERRIDE:
    {
        uint8_t u8RemoteOverride = au8LinkRxBuffer[0];
        bool_t bDisableAuthentications = au8LinkRxBuffer[1];

        ZPS_vSetTCLockDownOverride(ZPS_pvAplZdoGetAplHandle(),u8RemoteOverride,bDisableAuthentications);
    }
    break; 
    
    case E_SL_MSG_GET_SIMPLE_DESCRIPTOR:
    {
        ZPS_tsAplAfSimpleDescriptor sSimpleDescriptor;
        uint8 u8FlagsByteCount = 0;
        int i;
        u8Status = ZPS_eAplAfGetSimpleDescriptor(au8LinkRxBuffer[0],&sSimpleDescriptor);

        /* Copy sSimpleDescriptor for sending over serial */
        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  sSimpleDescriptor.u16ApplicationProfileId, u8TxLength );

        ZNC_BUF_U16_UPD( &au8values[u8TxLength],  sSimpleDescriptor.u16DeviceId, u8TxLength );

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sSimpleDescriptor.u8DeviceVersion, u8TxLength );

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sSimpleDescriptor.u8Endpoint, u8TxLength );

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sSimpleDescriptor.u8InClusterCount, u8TxLength );

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sSimpleDescriptor.u8OutClusterCount, u8TxLength );

        for (i=0; i<sSimpleDescriptor.u8InClusterCount; i++)
        {
            ZNC_BUF_U16_UPD( &au8values[u8TxLength],  sSimpleDescriptor.pu16InClusterList[i], u8TxLength );
        }

        for (i=0; i<sSimpleDescriptor.u8OutClusterCount; i++)
        {
            ZNC_BUF_U16_UPD( &au8values[u8TxLength],  sSimpleDescriptor.pu16OutClusterList[i], u8TxLength );
        }

        u8FlagsByteCount = sSimpleDescriptor.u8InClusterCount/8;
        if(sSimpleDescriptor.u8InClusterCount % 8)
        {
            u8FlagsByteCount++;
        }

        /* Both are byte arrays, endianness irrelevant */
        memcpy(&au8values[u8TxLength], sSimpleDescriptor.au8InDiscoveryEnabledFlags, u8FlagsByteCount);
        u8TxLength += u8FlagsByteCount;

        u8FlagsByteCount = sSimpleDescriptor.u8OutClusterCount/8;
        if(sSimpleDescriptor.u8OutClusterCount % 8)
        {
            u8FlagsByteCount++;
        }

        /* Both are byte arrays, endianness irrelevant */
        memcpy(&au8values[u8TxLength], sSimpleDescriptor.au8OutDiscoveryEnabledFlags, u8FlagsByteCount);
        u8TxLength += u8FlagsByteCount;
    }
    break;

    case E_SL_MSG_GET_USE_EXT_PANID :
    {
        uint64 u64extPanId;

        u64extPanId = ZPS_u64AplAibGetApsUseExtendedPanId();

        ZNC_BUF_U64_UPD( &au8values[u8TxLength],  u64extPanId, u8TxLength );
    }
    break;

    case E_SL_MSG_GET_USE_INSECURE_JOIN :
    {
        bool_t bUseInsecureJoin = ZPS_bAplAibGetApsUseInsecureJoin();

        /* Copy permit join status for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  bUseInsecureJoin, u8TxLength );

        u8Status = ZPS_E_SUCCESS;
    }
    break;

    case E_SL_MSG_SET_USE_INSTALL_CODE :
    {
        /* copy bUseInstallCode */
        bool_t bUseInstallCode = au8LinkRxBuffer[0];

        u8Status = ZPS_eAplAibSetApsUseInstallCode(bUseInstallCode);
    }
    break;

    case E_SL_MSG_GET_MAPPED_IEEE_ADDR:{
        uint16 u16ExtAddrLkup;
        uint64 u64IeeeAddr;

        /* copy u16TableIndex */
        u16ExtAddrLkup = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        u64IeeeAddr = ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(),u16ExtAddrLkup);
        ZNC_BUF_U64_UPD( &au8values[u8TxLength],  u64IeeeAddr, u8TxLength );
    }
    break;

    case E_SL_MSG_GET_SEC_MAT_SET_SIZE:
    {
        void *pvNwk = ZPS_pvAplZdoGetNwkHandle();
        ZPS_tsNwkNib *psNib = ZPS_psNwkNibGetHandle( pvNwk);

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  psNib->sTblSize.u8SecMatSet, u8TxLength );
    }
    break;

    case E_SL_MSG_GET_SEC_MAT_SET_ENTRY:
    {
        void *pvNwk = ZPS_pvAplZdoGetNwkHandle();
        ZPS_tsNwkNib *psNib = ZPS_psNwkNibGetHandle( pvNwk);
        uint8 u8TableIndex = au8LinkRxBuffer[0];

        if(u8TableIndex >= psNib->sTblSize.u8SecMatSet)
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
        else
        {
            /* Copy sEntry for sending over serial */
            /* Both are byte arrays, endianness irrelevant */
            memcpy(&au8values[4], psNib->sTbl.psSecMatSet[u8TableIndex].au8Key,
                    ZPS_NWK_KEY_LENGTH);
            u8TxLength += ZPS_NWK_KEY_LENGTH;

            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  psNib->sTbl.psSecMatSet[u8TableIndex].u8KeySeqNum, u8TxLength );

            ZNC_BUF_U8_UPD( &au8values[u8TxLength],  psNib->sTbl.psSecMatSet[u8TableIndex].u8KeyType, u8TxLength );

            u8Status = ZPS_E_SUCCESS;
        }
    }
    break;
    case E_SL_MSG_CLEAR_SEC_MAT_SET_ENTRY:
    {
        ZPS_tsNwkNib *psNib = ZPS_psNwkNibGetHandle( ZPS_pvAplZdoGetNwkHandle());
        uint8 u8TableIndex = au8LinkRxBuffer[0];

        if(u8TableIndex >= psNib->sTblSize.u8SecMatSet)
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
        else
        {
            /* Copy sEntry for sending over serial */
            memset(psNib->sTbl.psSecMatSet[u8TableIndex].au8Key, 0,
                    ZPS_NWK_KEY_LENGTH);
            psNib->sTbl.psSecMatSet[u8TableIndex].u8KeySeqNum = 0;
            psNib->sTbl.psSecMatSet[u8TableIndex].u8KeyType = ZPS_NWK_SEC_KEY_INVALID_KEY;
            ZPS_vNwkSaveSecMat(ZPS_pvAplZdoGetNwkHandle());
            u8Status = ZPS_E_SUCCESS;
        }
    }
    break;
    case E_SL_MSG_SET_JN_INTERNAL_ATTENUATOR:
    {
        uint32 u32PhyPACTRL = 0;

        if (au8LinkRxBuffer[0] != 0) /* 3dB attenuation */
        {
            /* set PA_ATTEN */
            u32PhyPACTRL |= (0x1 << 4);
        }
        else
        {
            u32PhyPACTRL &= ~(0x1 << 4);
        }
        break;
    }

    case E_SL_MSG_GET_LAST_RSSI:
    {
        au8values[4] =  (u8LastMsgLqi/3)+20;
        u8TxLength += sizeof(uint8);
    }
    break;

    case E_SL_MSG_GET_GLOBAL_STATS:

        /* Copy sNwkStats for sending over serial */
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  sNwkStats.u32TotalSuccessfulTX, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  sNwkStats.u32TotalFailTX, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  sNwkStats.u32TotalRX, u8TxLength );
        break;

    case E_SL_MSG_GET_DEVICE_STATS:
    {
        uint64 u64MacAddress;

        u64MacAddress = ZNC_RTN_U64( au8LinkRxBuffer, 0 );

        if(TRUE == bGetDeviceStats(u64MacAddress, &au8values[4], &au8values[5]))
        {
            u8TxLength += 2;
            u8Status = TRUE;
        }
        else
        {
            u8Status = FALSE;
        }
    }
        break;

    case E_SL_MSG_CHANGE_EXT_PANID:
    {
        uint64 u64Value;

        u64Value = ZNC_RTN_U64( au8LinkRxBuffer, 0 );

        ZPS_vNwkNibSetExtPanId (ZPS_pvAplZdoGetNwkHandle(), u64Value);
    }
    break;

    case E_SL_MSG_CHANGE_PANID:
    {
        uint16 u16Value;

        u16Value = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        ZPS_vNwkNibSetPanId(ZPS_pvAplZdoGetNwkHandle(), u16Value);
    }
    break;
    case E_SL_MSG_DISCOVER_NETWORKS:
    {
        uint32 u32ChannelMask;

        /* copy u32ChannelMask */
        u32ChannelMask = ZNC_RTN_U32( au8LinkRxBuffer, 0 );

#ifdef ZB_COORD_DEVICE
        {
            MAC_MlmeReqRsp_s     sMlmeReqRsp;
            MAC_MlmeSyncCfm_s    sMlmeSyncCfm;

            sMlmeReqRsp.u8Type                          =  MAC_MLME_REQ_SCAN;
            sMlmeReqRsp.u8ParamLength                   =  sizeof(MAC_MlmeReqScan_s);
            sMlmeReqRsp.uParam.sReqScan.u32ScanChannels =  u32ChannelMask;
            sMlmeReqRsp.uParam.sReqScan.u8ScanDuration  =  5;
            sMlmeReqRsp.uParam.sReqScan.u8ScanType      =  MAC_MLME_SCAN_TYPE_ACTIVE;
            ZPS_vMacHandleMlmeVsReqRsp(NULL, &sMlmeReqRsp, &sMlmeSyncCfm);
            DBG_vPrintf(TRACE_APP, "\n u32ChannelMask = 0x%8x, MAC_vHandleMlmeVsReqRsp... sMlmeSyncCfm.u8Status = %d \r\n", u32ChannelMask ,sMlmeSyncCfm.u8Status);
            if(( sMlmeSyncCfm.u8Status== MAC_MLME_CFM_DEFERRED)||(MAC_MLME_CFM_OK ==sMlmeSyncCfm.u8Status ))
            {
                u8Status = 0;
            }
            else
            {
                u8Status = 1;
            }
#if 0
            u8APPScanStatus = E_APP_SCAN_STARTED;


            vStartStopTimer(u8APP_DiscoveryTimer,ZTIMER_TIME_MSEC(5000),NULL,0);
#endif
        }

#else
            u8Status = ZPS_eAplZdoDiscoverNetworks(u32ChannelMask);
            DBG_vPrintf(TRACE_APP, "\n u32ChannelMask = 0x%8x, ZPS_eAplZdoDiscoverNetworks... u8Status = %d \r\n", u32ChannelMask ,u8Status);
#endif

    }

    break;

    case E_SL_MSG_SET_ENHANCED_BEACON_MODE:
    {
        DBG_vPrintf(TRACE_APP, "SET_ENHANCED_BEACON_MODE: = 0x%2x\n", au8LinkRxBuffer[0]);
        void *pvNwk = ZPS_pvAplZdoGetNwkHandle();
        ZPS_vNwkNibSetMacEnhancedMode(pvNwk, au8LinkRxBuffer[0] ? TRUE : FALSE);
        break;
    }

    case E_SL_MSG_SET_IEEE_PERMIT_POLICY:
    {
        DBG_vPrintf(TRACE_APP, "IEEE-SET-PERMIT-POLICY = 0x%2x\n", au8LinkRxBuffer[0]);
        u8Status = ZPS_u8MacMibIeeeSetPolicy(au8LinkRxBuffer[0]);
        break;
    }

    case E_SL_MSG_GET_IEEE_PERMIT_POLICY:
    {
        uint8 u8Policy;
        u8Status = ZPS_u8MacMibIeeeGetPolicy(&u8Policy);

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8Policy, u8TxLength );

        DBG_vPrintf(TRACE_APP, "IEEE-PERMIT_POLICY = 0x%2x\n", u8Policy);
        break;
    }

    case E_SL_MSG_ADD_IEEE_PERMIT_TABLE:
    {
        uint8 u8Count;
        uint64 u64ExtAddr;


        u64ExtAddr = ZNC_RTN_U64( au8LinkRxBuffer, 0 );

        DBG_vPrintf(TRACE_APP, "E_SL_MSG_ADD_IEEE_PERMIT_TABLE: = 0x%16x\n", u64ExtAddr);
        u8Status =  ZPS_u8MacMibIeeeAddDevice(u64ExtAddr, &u8Count);
        break;
    }

    case E_SL_MSG_CLEAR_IEEE_PERMIT_TABLE:
    {
        u8Status = ZPS_u8MacMibIeeeSetTable(0, 0, NULL);
        break;
    }

#ifndef  MAC_TYPE_SOC
    case E_SL_MSG_CHANGE_SUB_GHZ_CHANNEL:
    {
        uint32 u32ChanMask;
        u32ChanMask = ZNC_RTN_U32( au8LinkRxBuffer, 0 );

        u8Status = u8SetSubGigChannel(u32ChanMask);

        break;
    }
#endif
    case E_SL_MSG_SET_NWK_INTERFACE_REQ:
    {
        uint8 u8InterfaceIndex;
        bool_t bState;
        bool_t bRoutersAllowed;
        uint32 u32ChanToUse;
        uint8  u8ChanCount;
        uint32 u32ChanMask[4u];
        uint16 u16WarThr;
        uint16 u16CritThr;
        uint16 u16ReguThr;

        uint8 u8Index;
        uint8 u8Count;
        uint16 u16Offset = 0;

        VAR_UNUSED(u16WarThr);
        VAR_UNUSED(u16CritThr);
        VAR_UNUSED(u16ReguThr);

        u8InterfaceIndex = ZNC_RTN_U8_OFFSET( au8LinkRxBuffer, u16Offset, u16Offset );
        bState = ZNC_RTN_U8_OFFSET( au8LinkRxBuffer, u16Offset, u16Offset );
        bRoutersAllowed = ZNC_RTN_U32_OFFSET( au8LinkRxBuffer, u16Offset, u16Offset );
        u32ChanToUse = ZNC_RTN_U32_OFFSET( au8LinkRxBuffer, u16Offset, u16Offset );
        u8ChanCount = ZNC_RTN_U8_OFFSET( au8LinkRxBuffer, u16Offset, u16Offset );

        u8Count = u8ChanCount;
        for (u8Index = 0u; u8Count>0u; u8Count--, u8Index++)
        {
            u32ChanMask[u8Index] = ZNC_RTN_U32_OFFSET( au8LinkRxBuffer, u16Offset, u16Offset );
        }
        /*
         * The three values below are NOT sent from the LPC. Furthermore, the crit, warn
         * and regular threshold for OL are set through a diffrerent command
         */
        u16WarThr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Offset, u16Offset );

        u16CritThr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Offset, u16Offset );

        u16ReguThr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Offset, u16Offset );

        ZPS_tsNwkNlmeReqRsp sNlmeReqRsp;
        ZPS_tsNwkNlmeSyncCfm sNlmeSyncCfm;

        sNlmeReqRsp.u8Type = ZPS_NWK_NLME_REQ_SET_INTERFACE;
        sNlmeReqRsp.u8ParamLength = sizeof(ZPS_tsNwkNlmeReqSetInterface);
        sNlmeReqRsp.uParam.sReqSetInterface.u8InterfaceIndex = u8InterfaceIndex;
        sNlmeReqRsp.uParam.sReqSetInterface.bState = bState;
        sNlmeReqRsp.uParam.sReqSetInterface.bRoutersAllowed = bRoutersAllowed;
        sNlmeReqRsp.uParam.sReqSetInterface.u32ChannelToUse = u32ChanToUse;
        sNlmeReqRsp.uParam.sReqSetInterface.sSupportedChannels.u8ChannelPageCount = u8ChanCount;
        sNlmeReqRsp.uParam.sReqSetInterface.sSupportedChannels.u32ChannelField[0u] = u32ChanMask[0];
        sNlmeReqRsp.uParam.sReqSetInterface.sSupportedChannels.u32ChannelField[1u] = u32ChanMask[1];
        sNlmeReqRsp.uParam.sReqSetInterface.sSupportedChannels.u32ChannelField[2u] = u32ChanMask[2];
        sNlmeReqRsp.uParam.sReqSetInterface.sSupportedChannels.u32ChannelField[3u] = u32ChanMask[3];

        DBG_vPrintf(TRACE_APP, "NLME Set Network Interface Request\n");

        ZPS_vNwkHandleNlmeReqRsp(ZPS_pvAplZdoGetNwkHandle(), &sNlmeReqRsp, &sNlmeSyncCfm);

        DBG_vPrintf(TRACE_APP, "Status returned = %02x\n", sNlmeSyncCfm.u8Status);

        if (sNlmeSyncCfm.u8Status != ZPS_NWK_NLME_CFM_OK)
        {
            u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
        }
        break;
    }

    case E_SL_MSG_ZDO_SET_DEVICETYPE:
    {
        uint8 u8DeviceType = au8LinkRxBuffer[0];
        zps_vSetZdoDeviceType(ZPS_pvAplZdoGetAplHandle(),u8DeviceType);

        break;
    }

    case E_SL_MSG_NWK_SET_DEVICETYPE:
    {
        ZPS_teNwkDeviceType eNwkDeviceType = (ZPS_teNwkDeviceType) au8LinkRxBuffer[0];
        ZPS_vNwkSetDeviceType(ZPS_pvAplZdoGetNwkHandle(), eNwkDeviceType);
    }
    
    case E_SL_MSG_GET_NWK_INTERFACE_REQ:
    {
        uint8 u8InterfaceIndex;
        uint8 u8Index;
        uint8 u8Count;

        u8InterfaceIndex =  au8LinkRxBuffer[0];

        ZPS_tsNwkNlmeReqRsp sNlmeReqRsp;
        ZPS_tsNwkNlmeSyncCfm sNlmeSyncCfm;

        sNlmeReqRsp.u8Type = ZPS_NWK_NLME_REQ_GET_INTERFACE;
        sNlmeReqRsp.u8ParamLength = sizeof(ZPS_tsNwkNlmeReqGetInterface);
        sNlmeReqRsp.uParam.sReqGetInterface.u8InterfaceIndex = u8InterfaceIndex;

        DBG_vPrintf(TRACE_APP, "NLME Get Network Interface Request\n");

        ZPS_vNwkHandleNlmeReqRsp(ZPS_pvAplZdoGetNwkHandle(), &sNlmeReqRsp, &sNlmeSyncCfm);

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.u8Status, u8TxLength );

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.u8InterfaceIndex, u8TxLength );

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.bState, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.u32ChannelInUse, u8TxLength );

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.sSupportedChannels.u8ChannelPageCount, u8TxLength );

        u8Count = sNlmeSyncCfm.uParam.sCfmGetInterface.sSupportedChannels.u8ChannelPageCount;
        for (u8Index=0u; u8Count > 0u; u8Count--,u8Index++)
        {
            ZNC_BUF_U32_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.sSupportedChannels.u32ChannelField[u8Index], u8TxLength );
        }

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.bRoutersAllowed, u8TxLength );

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.bPowerNegotiationSupported, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.u32MacTxUcastAccRetry, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.u32MacTxUcastAvgRetry, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.u32MacTxUcastFail, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength], sNlmeSyncCfm.uParam.sCfmGetInterface.u32MacTxUcastFail , u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.u32APSTxUcastRetry, u8TxLength );

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  sNlmeSyncCfm.uParam.sCfmGetInterface.u32APSTxUcastFail, u8TxLength );


        break;
    }

    case E_SL_MSG_SEND_ED_LINK_POWER_DELTA_REQ:
    {
        void *pvNwk = ZPS_pvAplZdoGetNwkHandle();

        if(TRUE != ZPS_bNwkEndDeviceLinkPowerDeltaReq(pvNwk))
        {
            u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
        }
        break;
    }

    case E_SL_MSG_SEND_ZCR_LINK_POWER_DELTA_NTF:
    {
        void *pvNwk = ZPS_pvAplZdoGetNwkHandle();

        if((sNcpDeviceDesc.u8DeviceType == ZPS_ZDO_DEVICE_COORD) ||
          (sNcpDeviceDesc.u8DeviceType == ZPS_ZDO_DEVICE_ROUTER))
        {
            if(TRUE != ZPS_bNwkCoordLinkPowerDeltaNtfcn(pvNwk))
            {
                u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
            }
        }
        else
        {
            u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
        }
        break;
    }

    case E_SL_MSG_SEND_MGMT_NWK_ENH_UPDATE_REQ:
    {
        PDUM_thAPduInstance hAPduInst;

        hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
        u32StatusFlags &= ~APDU_0_STATUS_MASK;

        uint32 u32ChanMask;
        uint16 u16DstAddr;
        uint8 u8ScanDuration;
        uint8 u8ScanCount;
        uint8 u8ScanPageCount = 0u;
        uint8 u8Index;
        uint8 u8Len;

        u16DstAddr = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        u8ScanDuration = au8LinkRxBuffer[2];

        u8ScanCount = au8LinkRxBuffer[3];

        memcpy(&u32ChanMask, &au8LinkRxBuffer[4], sizeof(uint32));

        if (PDUM_INVALID_HANDLE != hAPduInst)
        {
            ZPS_tsAplZdpMgmtNwkEnhanceUpdateReq sMgmtNwkEnhanceUpdateReq;
             ZPS_tuAddress uDstAddr;
            ZPS_tsNwkNib *psNib = ZPS_psAplZdoGetNib();

            uDstAddr.u16Addr = u16DstAddr;

            sMgmtNwkEnhanceUpdateReq.u8ScanDuration = u8ScanDuration;
            sMgmtNwkEnhanceUpdateReq.u8ScanCount = u8ScanCount;
            sMgmtNwkEnhanceUpdateReq.u8NwkUpdateId = psNib->sPersist.u8UpdateId + 1;

            if (0xFFu == u8ScanDuration)
            {
                /* Get channel mask count and channel mask list from MAC Interface table */
                for(u8Index = 0u; u8Index < ZPS_psMacIFTGetTable()->u8NumInterfaces; u8Index++)
                {
                    MAC_tsMacInterface *psMacIf = ZPS_psMacIFTGetInterface(u8Index);
                    if(NULL != psMacIf)
                    {
                        const uint32 *pu32ChannelMaskList = &(ZPS_psMacIFTGetTable())->pu32ChannelMaskList[ZPS_u8GetChannelOffset(u8Index)];
                        u8Len = ZPS_u8MacIFTGetChannelMaskCount(u8Index);
                        while ((*pu32ChannelMaskList != MAC_CHANNEL_MASK_LIST_TERMINATOR) && (u8Len > 0u))
                        {
                            sMgmtNwkEnhanceUpdateReq.sZdpScanChannelList.pu32ChannelField[u8ScanPageCount] = *pu32ChannelMaskList;
                            u8Len--;
                            pu32ChannelMaskList++;
                            u8ScanPageCount++;
                        }
                    }
                }
            }
            else /* for Scan duration == 0xFE ==> (Channel Change) or (0 to 5) ==> Scan request*/
            {
                u8ScanPageCount = 1u;
                sMgmtNwkEnhanceUpdateReq.sZdpScanChannelList.pu32ChannelField[0u] = u32ChanMask;
            }

            sMgmtNwkEnhanceUpdateReq.sZdpScanChannelList.u8ChannelPageCount = u8ScanPageCount;

            /* The valid Network Manager Address in a centralized network is 0x0000 */
            sMgmtNwkEnhanceUpdateReq.u16NwkManagerAddr = 0x0000u;

            u8Status = ZPS_eAplZdpMgmtNwkEnhanceUpdateRequest(
                        hAPduInst,
                        uDstAddr,
                        FALSE,
                        &u8ApsTSN,
                        &sMgmtNwkEnhanceUpdateReq);
        }
        else
        {
            u8Status = E_SL_MSG_NO_APDU_BUFFERS;
        }
        break;
    }

    case E_SL_MSG_SEND_MGMT_NWK_UNS_ENH_UPDATE_NOTIFY:
    {
        PDUM_thAPduInstance hAPduInst;
        uint8 u8Location = 0u;

        hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
        u32StatusFlags &= ~APDU_0_STATUS_MASK;

        if (PDUM_INVALID_HANDLE != hAPduInst)
        {
            ZPS_tsAplZdpMgmtNwkUnSolictedUpdateNotify sMgmtNwkUnSolicitedUpdateNotify;

            ZPS_tuAddress uDstAddr;

            uDstAddr.u16Addr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u8Location, u8Location );

            sMgmtNwkUnSolicitedUpdateNotify.u32ChannelInUse = ZNC_RTN_U32_OFFSET( au8LinkRxBuffer, u8Location, u8Location );

            sMgmtNwkUnSolicitedUpdateNotify.u16MACTxUnicastTotal = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u8Location, u8Location );

            sMgmtNwkUnSolicitedUpdateNotify.u16MACTxUnicastFailures = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u8Location, u8Location );

            sMgmtNwkUnSolicitedUpdateNotify.u16MACTxUnicastRetries = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u8Location, u8Location );

            sMgmtNwkUnSolicitedUpdateNotify.u8PeriodOfTimeForResults = ZNC_RTN_U8_OFFSET( au8LinkRxBuffer, u8Location, u8Location );

            sMgmtNwkUnSolicitedUpdateNotify.u8Status = ZPS_E_SUCCESS;

            u8Status = ZPS_eAplZdpMgmtUnsolicitedEnhancedUpdateNotify(
                        hAPduInst,
                        uDstAddr,
                        FALSE,
                        &sMgmtNwkUnSolicitedUpdateNotify,
                        &u8ApsTSN);

        }
        else
        {
            u8Status = E_SL_MSG_NO_APDU_BUFFERS;
        }
        break;
    }

    case E_SL_MSG_START_ED_SCAN:
    {
        uint32 u32ScanChannels;
        uint8 u8ScanDuration;
        ZPS_tsNwkNlmeReqRsp sNlmeReqRsp;
        ZPS_tsNwkNlmeSyncCfm sNlmeSyncCfm;
        void *pvNwk;
        pvNwk = ZPS_pvAplZdoGetNwkHandle();

        /* Copy scan channel mask */
        u32ScanChannels = ZNC_RTN_U32( au8LinkRxBuffer, 0 );

        /* Copy scan duration */
        u8ScanDuration = au8LinkRxBuffer[4];

        sNlmeReqRsp.u8Type = ZPS_NWK_NLME_REQ_ED_SCAN;
        sNlmeReqRsp.u8ParamLength = sizeof(ZPS_tsNwkNlmeReqEdScan);
        sNlmeReqRsp.uParam.sReqEdScan.sScan.u32ScanChannels = u32ScanChannels;
        sNlmeReqRsp.uParam.sReqEdScan.sScan.u8ScanDuration = u8ScanDuration;

        ZPS_vNwkHandleNlmeReqRsp(pvNwk, &sNlmeReqRsp, &sNlmeSyncCfm);

        if (ZPS_NWK_NLME_CFM_ERROR == sNlmeSyncCfm.u8Status)
        {
            u8Status = sNlmeSyncCfm.uParam.sCfmEdScan.u8Status;
        }
        break;
    }

    case (E_SL_MSG_IS_COPROCESSOR_NEW_MODULE):
    {
        bool_t bCoproFactoryNew = (sNcpDeviceDesc.eState == FACTORY_NEW);

        /* Copy factory new state for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  bCoproFactoryNew, u8TxLength );

        break;
    }

    case E_SL_MSG_GET_MAC_INTERFACE_INDEX:
    {
        u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
        uint16 u16NwkAddr;
        uint16 u16TableIndex;
        ZPS_tsNwkNib * thisNib;
        thisNib = ZPS_psNwkNibGetHandle(ZPS_pvAplZdoGetNwkHandle());
        ZPS_tsNwkActvNtEntry sEntry;

        /* copy u16NwkAddr */
        u16NwkAddr = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        for(u16TableIndex = 0u; u16TableIndex < thisNib->sTblSize.u16NtActv; u16TableIndex++)
        {
            sEntry = thisNib->sTbl.psNtActv[u16TableIndex];
            if (u16NwkAddr == sEntry.u16NwkAddr)
            {
                u8Status = E_SL_MSG_STATUS_SUCCESS;

                ZNC_BUF_U8_UPD( &au8values[u8TxLength],  sEntry.u8MacID, u8TxLength );
                break;
            }
        }
        break;
    }
#ifdef ZPS_FRQAG
    case E_SL_MSG_GET_CLEAR_TX_UCAST_BYTE_COUNT:
    {
        uint8 u8GetClear;
        uint16 u16NwkAddr;
        u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
        void *pvNwk;
        pvNwk = ZPS_pvAplZdoGetNwkHandle();

        /* copy u8GetClear mode */
        u8GetClear = au8LinkRxBuffer[0u];

        /* copy u16NwkAddr */
        u16NwkAddr = ZNC_RTN_U16( au8LinkRxBuffer, 1 );

        uint32 u32TxUcastByteCount = 0;
        if ((u8GetClear < 2u) && (0xFFFFu != u16NwkAddr))
        {
            uint32 u32TxUcastByteCount;
            if (FALSE == ZPS_bNibNwkGetTxCount (pvNwk, u16NwkAddr, &u32TxUcastByteCount))
            {
                u8Status = ZPS_NWK_ENUM_UNKNOWN_DEVICE;
            }
            else
            {
                u8Status = E_SL_MSG_STATUS_SUCCESS;
                if (1u == u8GetClear)
                {
                    /* clear the count */
                    (void)ZPS_bNibNwkClearTxCount (pvNwk, u16NwkAddr);
                }
            }
        }
        else
        {
            /* invalid option */
            u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
        }
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32TxUcastByteCount, u8TxLength );

        DBG_vPrintf(TRACE_APP, "Get Tx Count u16NwkAddr: 0x%04x, Status %02x Byte Count: %d\n",
                u16NwkAddr, u8Status, u32TxUcastByteCount);

        break;
    }

    case E_SL_MSG_GET_CLEAR_RX_UCAST_BYTE_COUNT:
    {
        uint8 u8GetClear;
        uint16 u16NwkAddr;
        u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
        void *pvNwk;
        pvNwk = ZPS_pvAplZdoGetNwkHandle();

        /* copy u8GetClear mode */
        u8GetClear = au8LinkRxBuffer[0];

        /* copy u16NwkAddr */
        u16NwkAddr = ZNC_RTN_U16( au8LinkRxBuffer, 1 );

        uint32 u32RxUcastByteCount = 0;
        if ((u8GetClear < 2u) && (0xFFFFu != u16NwkAddr))
        {
            if (FALSE == ZPS_bNibNwkGetRxCount (pvNwk, u16NwkAddr, &u32RxUcastByteCount))
            {
                u8Status = ZPS_NWK_ENUM_UNKNOWN_DEVICE;
            }
            else
            {
                u8Status = E_SL_MSG_STATUS_SUCCESS;
                if (1u == u8GetClear)
                {
                    /* clear the count */
                    (void)ZPS_bNibNwkClearRxCount (pvNwk, u16NwkAddr);
                }
            }
        }
        else
        {
            /* invalid option */
            u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
        }
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32RxUcastByteCount, u8TxLength );

        DBG_vPrintf(TRACE_APP, "Get Rx Count u16NwkAddr: 0x%04x Status %02X RxcastByte count: %D\n",
                u16NwkAddr, u8Status, u32RxUcastByteCount);
        break;
    }
#endif /* ZPS_FRQAG */
    case E_SL_MSG_GET_CLEAR_TX_FAIL_COUNT:
    {
        uint8 u8GetClear;
        uint8 u8MacIF;
        u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;

        /* copy u8GetClear mode */
        u8GetClear = au8LinkRxBuffer[0];

        /* copy u8MacIF */
        u8MacIF = au8LinkRxBuffer[1];

        MAC_tsMacInterfaceTable* psMacIfTable = ZPS_psMacIFTGetTable();
        uint32 u32MacTxUcastFail = 0;
        if (NULL != psMacIfTable)
        {
            if (psMacIfTable->u8NumInterfaces > u8MacIF)
            {
                if (u8GetClear < 2u)
                {
                    u32MacTxUcastFail = psMacIfTable->pu32MacTxUcastFail[u8MacIF];
                    /* clear Tx Unicast Fail Count */
                    if (1u == u8GetClear)
                    {
                        psMacIfTable->pu32MacTxUcastFail[u8MacIF] = 0u;
                    }
                    u8Status = E_SL_MSG_STATUS_SUCCESS;

                }
                else
                {
                    /* Ivalid option */
                    u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
                }
            }
            else
            {
                /* Invalid Mac IF ID*/
                u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
            }
        }
        else
        {
            u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
        }
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32MacTxUcastFail, u8TxLength );

        DBG_vPrintf(TRACE_APP, "GCTF Status %02x Mac Tx Ucast Fail[%d]: %d\n", u8MacIF,
                u8Status, u32MacTxUcastFail);
        break;
    }

    case E_SL_MSG_GET_CLEAR_TX_RETRY_COUNT:
    {
        uint8 u8GetClear;
        uint8 u8MacIF;
        u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;

        /* copy u8GetClear mode */
        u8GetClear = au8LinkRxBuffer[0];

        /* copy u8MacIF */
        u8MacIF = au8LinkRxBuffer[1];

        MAC_tsMacInterfaceTable* psMacIfTable = ZPS_psMacIFTGetTable();
        uint32 u32MacTxUcastAccRetry = 0;
        if (NULL != psMacIfTable)
        {
            if (psMacIfTable->u8NumInterfaces > u8MacIF)
            {
                if (u8GetClear < 2u)
                {
                    /* clear Tx Unicast Fail Count */
                    u32MacTxUcastAccRetry = psMacIfTable->pu32MacTxUcastRetry[u8MacIF];

                    if (1u == u8GetClear)
                    {
                        psMacIfTable->pu32MacTxUcastRetry[u8MacIF] = 0u;
                    }
                    u8Status = E_SL_MSG_STATUS_SUCCESS;
                }
                else
                {
                    /* Ivalid option */
                    u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
                }
            }
            else
            {
                /* Invalid Mac IF ID*/
                u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
            }
        }
        else
        {
            u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
        }
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  psMacIfTable->pu32MacTxUcastRetry[u8MacIF], u8TxLength );

        DBG_vPrintf(TRACE_APP, "GCTR Status %02x Mac Tx Ucast Fail[%d]: %d\n",
                u8Status, u8MacIF, u32MacTxUcastAccRetry);
        break;
    }
    case E_SL_MSG_GET_CLEAR_TX_COUNT:
    {
        uint8 u8GetClear;
        uint8 u8MacIF;
        u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;

        /* copy u8GetClear mode */
        u8GetClear = au8LinkRxBuffer[0];
        /* copy u8MacIF */
        u8MacIF = au8LinkRxBuffer[1];

        MAC_tsMacInterfaceTable* psMacIfTable = ZPS_psMacIFTGetTable();
        uint32 u32MacTxUcast = 0;
        if (NULL != psMacIfTable)
        {
            if (psMacIfTable->u8NumInterfaces > u8MacIF)
            {
                if (u8GetClear < 2u)
                {
                    /* clear Tx Unicast Fail Count */
                    u32MacTxUcast = psMacIfTable->pu32MacTxUcast[u8MacIF];
                    if (1u == u8GetClear)
                    {
                        psMacIfTable->pu32MacTxUcast[u8MacIF] = 0u;
                    }
                    u8Status = E_SL_MSG_STATUS_SUCCESS;
                }
                else
                {
                    /* Ivalid option */
                    u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
                }
            }
            else
            {
                /* Invalid Mac IF ID*/
                u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
            }
        }
        else
        {
            u8Status = ZPS_NWK_ENUM_INVALID_PARAMETER;
        }

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32MacTxUcast, u8TxLength );


        DBG_vPrintf(TRACE_APP, "GCTC Ststus %02x  u32MacTxUcast[%d]: 0x%08x\n",
                u8Status, u8MacIF, u32MacTxUcast );
        break;
    }
    case E_SL_MSG_GET_IEEE_PERMIT_TABLE_SIZE:
    {
        uint8 u8Count;
        u8Status = ZPS_u8MacMibIeeeGetCount(&u8Count);
        au8values[4] = u8Count;
        u8TxLength++;

        break;
    }
    case E_SL_MSG_GET_IEEE_PERMIT_TABLE:
    {
        uint8 u8Index = au8LinkRxBuffer[0];
        uint64 u64Addr = 0;
        u8Status = ZPS_u8MacMibIeeeGetTable(u8Index, 1, &u64Addr);

        ZNC_BUF_U64_UPD( &au8values[u8TxLength],  u64Addr, u8TxLength );
        break;
    }
    case E_SL_MSG_SET_EBR_PERMIT_JOIN_ON:
    {
        DBG_vPrintf(TRACE_APP, "SET_EBR_PERMIT_JOIN_MODE: = 0x%2x\n", au8LinkRxBuffer[0]);
        break;
    }
    case E_SL_MSG_GET_DUTY_CYCLE_THRESHOLD:
    {
        uint8 u8ThresholdID;
        uint16 u16ThrInPer;

        /* copy u8ThresholdID */
        u8ThresholdID = au8LinkRxBuffer[0];

        /* Warning Threshold */
        if (0u == u8ThresholdID)
        {
            u16ThrInPer = ZPS_u16MacPibGetDutyCyleWarningThreshold(MAC_ID_SERIAL1);
        }
        /* Critical Threshold */
        else if (1u == u8ThresholdID)
        {
            u16ThrInPer = ZPS_u16MacPibGetDutyCyleCriticalThreshold(MAC_ID_SERIAL1);
        }
        /* Regulated Threshold */
        else if (2u == u8ThresholdID)
        {
            u16ThrInPer = ZPS_u16MacPibGetDutyCyleRegulated(MAC_ID_SERIAL1);
        }
        else
        {
            u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
            /* To remove warning below that u16ThrInPer might be used uninitialized */
            u16ThrInPer = 0;
        }
        if (E_SL_MSG_STATUS_INCORRECT_PARAMETERS != u8Status)
        {
            ZNC_BUF_U16_UPD( &au8values[u8TxLength],  u16ThrInPer, u8TxLength );
        }
        break;
    }
    case E_SL_MSG_SET_DUTY_CYCLE_THRESHOLD:
    {
        uint8 u8ThresholdID;
        uint16 u16ThrInHundOfPer;

        /* copy u8ThresholdID */
        u8ThresholdID = au8LinkRxBuffer[0];

        /* copy u16ThrInHundOfPer */
        u16ThrInHundOfPer = ZNC_RTN_U16( au8LinkRxBuffer, 1 );

        /* Warning Threshold */
        if (0u == u8ThresholdID)
        {
            ZPS_vMacPibSetDutyCyleWarningThreshold(u16ThrInHundOfPer);
        }
        /* Critical Threshold */
        else if (1u == u8ThresholdID)
        {
            ZPS_vMacPibSetDutyCyleCriticalThreshold(u16ThrInHundOfPer);
        }
        /* Regulated Threshold */
        else if (2u == u8ThresholdID)
        {
            ZPS_vMacPibSetDutyCyleRegulated(u16ThrInHundOfPer);
        }
        else
        {
            u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
        }
        break;
    }
    case E_SL_MSG_CLEAR_MIT_CHANMASK_LIST:
    {
        uint8 u8Index;
        zps_tsAplAfMMServerContext * s_sMMserver =  ZPS_u8MacIFTGetMultiMaskServer();
        uint8 u8LenChanMaskList = (s_sMMserver)->u8ChanMaskListCount;
        for (u8Index = 0u; u8Index < u8LenChanMaskList; u8Index++)
        {
            (ZPS_psMacIFTGetTable())->pu32ChannelMaskList[u8Index] = MAC_CHANNEL_MASK_LIST_TERMINATOR;
        }
        break;
    }

    case E_SL_MSG_GET_RESTORE_POINT:
    {
        ZPS_tsAfRestorePointStruct sRestorePoint;
        zps_tsPersistNeighboursTable sActvNtEntry;
        ZPS_tsNwkSecMaterialSet asSecMatSet[2];
        uint8 *pu8Buffer = &au8values[4];
        memset( &sRestorePoint, 0, sizeof(ZPS_tsAfRestorePointStruct) );

        sRestorePoint.psActvNtEntry = &sActvNtEntry;
        sRestorePoint.psSecMatSet = asSecMatSet;
        sRestorePoint.psAplApsKeyDescriptorEntry = NULL;
        sRestorePoint.psAplDefaultApsKeyDescriptorEntry = NULL;
        sRestorePoint.pRwAddressMap = NULL;
        sRestorePoint.u16NtTable = 1;
        sRestorePoint.u16AddressLkmp = 0;
        sRestorePoint.u16KeyDescTableSize = 0;
        sRestorePoint.bEndDeviceOnly = FALSE;
        sRestorePoint.bRecoverJoiner = FALSE;

        ZPS_vGetRestorePoint(&sRestorePoint);

        /* Copy sRestorePoint for sending over serial */
        memcpy( pu8Buffer, &sActvNtEntry, sizeof(zps_tsPersistNeighboursTable));
        u8TxLength += sizeof(zps_tsPersistNeighboursTable);
        pu8Buffer += sizeof(zps_tsPersistNeighboursTable);

        memcpy( pu8Buffer, &asSecMatSet[0].au8Key, 16 );
        u8TxLength += 16;
        pu8Buffer += 16;
        *pu8Buffer++ = asSecMatSet[0].u8KeySeqNum;
        u8TxLength++;
        *pu8Buffer++ = asSecMatSet[0].u8KeyType;
        u8TxLength++;

        memcpy( pu8Buffer, &asSecMatSet[1].au8Key, 16 );
        u8TxLength += 16;
        pu8Buffer += 16;
        *pu8Buffer++ = asSecMatSet[1].u8KeySeqNum;
        u8TxLength++;
        *pu8Buffer++ = asSecMatSet[1].u8KeyType;
        u8TxLength++;


        memcpy( pu8Buffer, &sRestorePoint.sPersist, sizeof(ZPS_tsNWkNibPersist));
        u8TxLength += sizeof(ZPS_tsNWkNibPersist);
        pu8Buffer += sizeof(ZPS_tsNWkNibPersist);

        memcpy( pu8Buffer, &sRestorePoint.u64TcAddress, sizeof(uint64));
        u8TxLength += sizeof(uint64);
        pu8Buffer += sizeof(uint64);

        memcpy( pu8Buffer, &sRestorePoint.u32OutgoingFrameCounter, sizeof(uint32));
        u8TxLength += sizeof(uint32);
        pu8Buffer += sizeof(uint32);

        *pu8Buffer++ = sRestorePoint.u8KeyType;
        u8TxLength++;


    }
    break;

    case E_SL_MSG_GET_MAC_ADDR_TABLE:
    {
        uint8 u8MacAddTableSize,i;
        void *pvNwk = ZPS_pvAplZdoGetNwkHandle();
        ZPS_tsNwkNib *psNib = ZPS_psNwkNibGetHandle( pvNwk);
        u8MacAddTableSize = psNib->sTblSize.u16MacAddTableSize;

        if(u8MacAddTableSize > 16)
        {
            u8MacAddTableSize = 16;
        }
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8MacAddTableSize, u8TxLength );

        for (i=0; i<u8MacAddTableSize; i++)
        {
            ZNC_BUF_U64_UPD( &au8values[u8TxLength], psNib->sTbl.pu64AddrExtAddrMap[i], u8TxLength );
        }

        DBG_vPrintf(TRACE_APP, "E_SL_MSG_GET_MAC_ADDR_TABLE\n");
        DBG_vPrintf(TRACE_APP, "u8MacAddTableSize %d\n",psNib->sTblSize.u16MacAddTableSize);
        for(i=0;i<u8MacAddTableSize;i++)
        {
            DBG_vPrintf(TRACE_APP, "MAC %d : %016llx\n",i+1,psNib->sTbl.pu64AddrExtAddrMap[i]);
        }
    }
    break;

    case E_SL_MSG_SET_RESTORE_POINT:
    {
        uint16 u16TableSize;
        ZPS_tsAfRestorePointStruct sRestorePoint;
        zps_tsPersistNeighboursTable sActvNtEntry;
        ZPS_tsNwkSecMaterialSet asSecMatSet[2];

        uint16 u16Index = 0x0;
        memset( &sRestorePoint, 0, sizeof(ZPS_tsAfRestorePointStruct) );

        sRestorePoint.psActvNtEntry = &sActvNtEntry;
        sRestorePoint.psSecMatSet = asSecMatSet;
        sRestorePoint.psAplApsKeyDescriptorEntry = NULL;
        sRestorePoint.psAplDefaultApsKeyDescriptorEntry = NULL;
        sRestorePoint.pRwAddressMap = NULL;
        sRestorePoint.u16NtTable = 1;
        sRestorePoint.u16AddressLkmp = 0;
        sRestorePoint.u16KeyDescTableSize = 0;
        sRestorePoint.bEndDeviceOnly = FALSE;
        sRestorePoint.bRecoverJoiner = FALSE;

        /* Copy sRestorePoint for sending over serial */
        u16Index += sizeof(zps_tsPersistNeighboursTable);

        /* Both are byte arrays, endianness irrelevant */
        memcpy( &asSecMatSet[0].au8Key, &au8LinkRxBuffer[u16Index], 16);
        u16Index += 16;

        asSecMatSet[0].u8KeySeqNum = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        asSecMatSet[0].u8KeyType =  ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        /* Both are byte arrays, endianness irrelevant */
        memcpy( &asSecMatSet[1].au8Key, &au8LinkRxBuffer[u16Index], 16);
        u16Index += 16;

        asSecMatSet[1].u8KeySeqNum =  ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);;

        asSecMatSet[1].u8KeyType = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        memcpy( &sRestorePoint.sPersist, &au8LinkRxBuffer[u16Index], sizeof(ZPS_tsNWkNibPersist));
        u16Index += sizeof(ZPS_tsNWkNibPersist);

        sRestorePoint.u64TcAddress = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        sRestorePoint.u32OutgoingFrameCounter = ZNC_RTN_U32_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        sRestorePoint.u8KeyType = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        
        ZPS_tsNwkNib *psNib = ZPS_psNwkNibGetHandle( ZPS_pvAplZdoGetNwkHandle());

        ZPS_vSetRestorePoint( &sRestorePoint );
        /* clear the network frame counter */
        u16TableSize = psNib->sTblSize.u16NtActv;

        memset(psNib->sTbl.pu32InFCSet,0, sizeof(uint32)*u16TableSize);
        ZPS_vSaveAllZpsRecords();

    }
    break;

    case E_SL_MSG_SET_MAC_ADDR_TABLE:
    {
        ZPS_tsNwkNib *psNib = ZPS_psNwkNibGetHandle( ZPS_pvAplZdoGetNwkHandle());
        uint8 u8MacAddTableSize,i;

        u8MacAddTableSize = au8LinkRxBuffer[0];

        for(i=0;i<u8MacAddTableSize;i++)
        {
            psNib->sTbl.pu64AddrExtAddrMap[i] = ZNC_RTN_U64( au8LinkRxBuffer, 8*i+1);
        }
        
        ZPS_vSaveAllZpsRecords();
        DBG_vPrintf(TRACE_APP, "E_SL_MSG_SET_MAC_ADDR_TABLE\n");
        DBG_vPrintf(TRACE_APP, "u8MacAddTableSize %d\n",u8MacAddTableSize);
        for(i=0;i<u8MacAddTableSize;i++)
        {
            DBG_vPrintf(TRACE_APP, "MAC %d : %016llx\n",i+1,psNib->sTbl.pu64AddrExtAddrMap[i]);
        }
    }
    break;

    case E_SL_MSG_SET_MAC_CAPABILITY:
    {
        uint8 u8MacCapability = au8LinkRxBuffer[0];
        zps_vAplAfSetMacCapability(ZPS_pvAplZdoGetAplHandle(), u8MacCapability);
    }
    break;
    
    case E_SL_MSG_READ_JN_TEMP_VALUE:
    {
        uint16 u16TempResult = u16GetTemp();

        ZNC_BUF_U16_UPD( &au8values[u8TxLength], u16TempResult , u8TxLength );
    }
    break;
    case E_SL_MSG_FRAGMENTED_PACKET_CHECK:
    {
         bool_t bIsActive = ZPS_bIsFragmentationEngineActive();   //API to check Fragmented Packet
         ZNC_BUF_U8_UPD( &au8values[u8TxLength],  bIsActive, u8TxLength );
    }
    break;
    case E_SL_MSG_SET_ED_TIMEOUT_ON_PARENT:
    {
        uint16 u16EDAddr;
        uint8  u8TimeoutConstIndex;

        /* copy u16DestAddr */
        u16EDAddr = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        /* copy u8TimeoutConstIndex */
        u8TimeoutConstIndex = au8LinkRxBuffer[2];

        /* Set ED Timeout on Parent */
        ZPS_vAplAfSetLocalEndDeviceTimeout(u16EDAddr , u8TimeoutConstIndex);
        break;
    }

    case E_SL_MSG_IEEE_MIB_ADD_LIST_REQ:
    {
        uint8 u8StartIndex;
        uint64 u64ExtAddr;

        /* Copy u64ExtAddr */
        u64ExtAddr = ZNC_RTN_U64( au8LinkRxBuffer, 0 );

        /* Copy u8StartIndex */
        u8StartIndex = au8LinkRxBuffer[8];

        u8Status = eZdpMgmtIeeeJoinListReq(u64ExtAddr, u8StartIndex);
        break;
    }
    case E_SL_MSG_NWK_CLEAR_DISC_NT:
    {
        ZPS_vNwkNibClearDiscoveryNT(ZPS_pvAplZdoGetNwkHandle());
        break;
    }
    case E_SL_MSG_SERIAL_LINK_REQ_NEGATIVE:
    {
        uint8 u8TestCase;

        u8TestCase = au8LinkRxBuffer[0];
        if (u8TestCase == 5)
        {
            Send_Nack_Host_JN();
            u8Status = 0;
        }
        else if (u8TestCase == 6)
        {
            uint8 au8Buffer[6];
            au8Buffer[0] =  0xff;
            au8Buffer[1] = 0xf7;
            au8Buffer[2] = 0xaa;

            vSL_WriteMessage(E_SL_MSG_NWK_STATUS_INDICATION, 3,  &u8ReceivedSeqNo, au8Buffer);
            vSL_WriteMessage(E_SL_MSG_NWK_STATUS_INDICATION, 3,  &u8ReceivedSeqNo, au8Buffer);
            u8Status = 0x34;
        }
        else if (u8TestCase == 7)
        {
            u8Status = 0x35;
            ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8Status, u8TempLen);
            ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8ApsTSN, u8TempLen);
            ZNC_BUF_U16_UPD   ( &au8values[u8TempLen], u16PacketType, u8TempLen);
            bRxBufferLocked = FALSE;
            vSL_WriteMessage(E_SL_MSG_STATUS_MSG, u8TxLength,  &u8ReceivedSeqNo, au8values);
        }
        else
        {
            u8Status = u8SendNegateTest(u8TestCase, &au8values[10] );
        }
        if (u8Status == 0)
        {
            /* response has already been sent */
            u16PacketType = 0;
            return;
        }

    }
    break;
    case E_SL_MSG_START_ROUTER:
    {
        ZPS_tsAftsStartParamsDistributed sStartParms;
        uint16 u16Index = 0;
        uint64 u64TCAddr;
        uint8 au8NwkKey[16];

        /* Both are byte arrays, endianness irrelevant */
        memcpy(au8NwkKey, au8LinkRxBuffer, 16);
        u16Index     += 16;

        sStartParms.u64ExtPanId = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        u64TCAddr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

        sStartParms.u8KeyIndex       = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);
        sStartParms.u8LogicalChannel = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        ZNC_RTN_U16_OFFSET( &au8LinkRxBuffer[u16Index],  sStartParms.u16NwkAddr, u16Index );
        ZNC_RTN_U16_OFFSET( &au8LinkRxBuffer[u16Index],  sStartParms.u16PanId, u16Index );

        sStartParms.pu8NwkKey = au8NwkKey;

        u8Status = ZPS_eAplFormDistributedNetworkRouter( &sStartParms, TRUE);

        ZPS_eAplAibSetApsTrustCenterAddress(u64TCAddr);
        /* set and save the device state */
        sNcpDeviceDesc.eNodeState = E_RUNNING;
        sNcpDeviceDesc.eState = NOT_FACTORY_NEW;
        vSaveDevicePdmRecord();
        break;
    }
    case E_SL_MSG_GET_MAC_TYPE:
    {
        /* Version is <Installer version : 16bits><Node version : 16bits> */
        uint8 u8ActiveMacId = 0;

    if (1u == ZPS_u8MacIFTGetIntfState(MAC_ID_SOC))
    {
        u8ActiveMacId = MAC_ID_SOC;
    }
    else if (1u == ZPS_u8MacIFTGetIntfState(MAC_ID_SERIAL1))
    {
        u8ActiveMacId = MAC_ID_SERIAL1;
    }
    else
    {
        u8ActiveMacId = 0xFF;
    }
        DBG_vPrintf(TRACE_APP, "E_SL_MSG_GET_MAC_TYPE: %u\n", u8ActiveMacId);

        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  u8ActiveMacId, u8TxLength );
    }
    break;

    case E_SL_MSG_SERIAL_LINK_HALT_JN:
    {
        u8Status = 0;

        ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8Status, u8TempLen);
        ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8ApsTSN, u8TempLen);
        ZNC_BUF_U16_UPD   ( &au8values[u8TempLen], u16PacketType, u8TempLen);

        vSL_WriteMessage(E_SL_MSG_STATUS_MSG, u8TxLength,  &u8ReceivedSeqNo, au8values);
        DBG_vPrintf(TRUE, "vAppDeepSleep();\n");

        return;
    }
    break;

    case E_SL_MSG_SERIAL_LINK_COUNT_APDU:
    {
        PDUM_thAPduInstance ahHandles[10];
        PDUM_thAPduInstance hAPduInst = PDUM_INVALID_HANDLE;
        int idx;
        au8values[4] = 0;
        au8values[5] = 0;
        au8values[6] = 0;
        au8values[7] = 0;
        bBlockApduError = TRUE;
        for (idx=0; idx<10; idx++)
        {
            ahHandles[idx] = PDUM_INVALID_HANDLE;
        }
        hAPduInst = (PDUM_thAPduInstance)1;
        idx = 0;
        while (hAPduInst != PDUM_INVALID_HANDLE)
        {
            hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
            ahHandles[idx] = hAPduInst;
            if (hAPduInst != PDUM_INVALID_HANDLE)
            {
                au8values[4]++;

            }
            idx++;
        };
        idx = 0;
        while (ahHandles[idx] != PDUM_INVALID_HANDLE)
        {
            PDUM_eAPduFreeAPduInstance(ahHandles[idx]);

            ahHandles[idx] = PDUM_INVALID_HANDLE;
            idx++;
        };

        au8values[5] = 0xff;

        hAPduInst = (PDUM_thAPduInstance)1;
        idx = 0;
#if 0
        while (hAPduInst != PDUM_INVALID_HANDLE)
        {
            hAPduInst = PDUM_hAPduAllocateAPduInstance(apduJUMBOZCL);
            ahHandles[idx] = hAPduInst;
            if (hAPduInst != PDUM_INVALID_HANDLE)
            {
                au8values[6]++;

            }
            idx++;
        };
#endif
        idx = 0;
        while (ahHandles[idx] != PDUM_INVALID_HANDLE)
        {
            PDUM_eAPduFreeAPduInstance(ahHandles[idx]);
            ahHandles[idx] = PDUM_INVALID_HANDLE;
            idx++;
        };

        u8TxLength += 4U;
        bBlockApduError = FALSE;
    }
    break;
    case E_SL_MSG_SERIAL_LINK_EXHAUST_APDU:
    {
        u32StatusFlags &= ~(APDU_0_STATUS_MASK | APDU_1_STATUS_MASK | APDU_2_STATUS_MASK);
        bBlockApduError = TRUE;
        PDUM_thAPduInstance hAPduInst =  (PDUM_thAPduInstance)1;
        while (hAPduInst != PDUM_INVALID_HANDLE)
        {
            hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);

        }
        bBlockApduError = FALSE;
    }
    break;

    case E_SL_MSG_SERIAL_LINK_STACK_POLL_RATE:
    {
        uint16 u16Rate;

        u16Rate = ZNC_RTN_U16( au8LinkRxBuffer, 0 );


        if (u16Rate > 0)
        {
            ZPS_vSetLocalPollInterval(u16Rate);
            u8Status = 0;
        }
        else
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
    }
    break;
    case E_SL_MSG_SERIAL_LINK_GET_NWK_INFC:
    {
        uint16 u16Idx;
        ZPS_tsNwkNib * thisNib;
        uint32 u32InFC = 0;

        void * thisNet = ZPS_pvAplZdoGetNwkHandle();
        thisNib = ZPS_psNwkNibGetHandle(thisNet);

        u16Idx = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        if (u16Idx < thisNib->sTblSize.u16NtActv)
        {
            u32InFC = thisNib->sTbl.pu32InFCSet[u16Idx];
            u8Status = 0x00;
        }
        else
        {
            u8Status = E_SL_MSG_STATUS_INVALID_PARAMETER;
        }
        /* Copy u64Addr for sending over serial */
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32InFC, u8TxLength );

                u8Status = 0x00;



    }
    break;
    case E_SL_MSG_SERIAL_LINK_SET_LEAVE_DECIDER:
    {
        sNcpDeviceDesc.u8BlockLeaves = au8LinkRxBuffer[0];
        vSaveDevicePdmRecord();
    }
    break;

    case E_SL_MSG_SERIAL_LINK_EXHAUST_REQ_DESC:
    {
        void* pvNwk = ZPS_pvNwkGetHandle();
        void* pvReqDescr = (void*)1;
        while (pvReqDescr != NULL)
        {
            pvReqDescr = (void*)zps_psNwkMcpsMgrAllocateReqDescr(pvNwk);
            u8Status++;
        }
        u8Status--;
    }
    break;

#ifndef MAC_TYPE_SOC
    case E_SL_MSG_SERIAL_LINK_GET_OL_REALIGN:
    {
        u8Status = ZPS_E_SUCCESS;
        extern uint32 u32RealignResetCount;

        /* Copy u16NWKAddr for sending over serial */
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32RealignResetCount, u8TxLength );
    }
    break;
    case E_SL_MSG_SERIAL_LINK_GET_OL_CHANNEL:
    {
        uint32 u32ChannelAux = 0xffffffffu;

        u8Status = ZPS_eMacPlmeGet(PHY_PIB_ATTR_AUX_CHANNEL, &u32ChannelAux);
        if (u8Status == PHY_ENUM_SUCCESS)
        {
            u8Status = 0U;
        }
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32ChannelAux, u8TxLength );

    }
    break;
    case E_SL_MSG_SERIAL_LINK_TOGGLE_OL_RESET:
    {
        vMDI_ToggleReset868MtG();
    }
    break;
    case E_SL_MSG_SERIAL_LINK_FORCE_OL_ALIGN:
    {
        ZPS_tsNwkNib * thisNib;
        void * thisNet = ZPS_pvAplZdoGetNwkHandle();
        thisNib = ZPS_psNwkNibGetHandle(thisNet);
        thisNib->sPersist.u16VsPanId++;
    }
    break;
#endif

    case E_SL_MSG_GET_NWK_OUTGOING_FRAME_COUNT:
    {
        ZPS_tsNwkNib *thisNib;

        thisNib = ZPS_psNwkNibGetHandle( ZPS_pvAplZdoGetNwkHandle());

        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  thisNib->sPersist.u32OutFC, u8TxLength );

    }
    break;

    case E_SL_MSG_SERIAL_LINK_RESET_BIND_SERVER:
    {
        ZPS_vResetBoundServerContext();
    }
    break;

    case E_SL_MSG_SERIAL_LINK_TEST_ERR_CODE:
        //just echo the status code back
        u8Status = au8LinkRxBuffer[0];
        break;

    case E_SL_MSG_SERIAL_LINK_GET_STATUS_FLAGS:
        ZNC_BUF_U32_UPD( &au8values[u8TxLength],  u32StatusFlags, u8TxLength );
        //u32StatusFlags &= ~(MCPS_RD_STATUS_MASK | NPDU_STATUS_MASK);

    break;
    case E_SL_MSG_SERIAL_LINK_ENABLE_BOUND_DEVICES:
    {
        bool_t bState;
        bState = (bool_t)au8LinkRxBuffer[0];
        u8Status = u8EnableBoundDevices( bState);
    }
    break;
    case E_SL_MSG_SERIAL_LINK_SET_BOUND_DEVICE:
    {
        uint64 u64Address;
        bool_t bState;

        u64Address = ZNC_RTN_U64( au8LinkRxBuffer, 0 );

        bState = (bool_t)au8LinkRxBuffer[sizeof(uint64)];

        u8Status = u8EnableBoundDevice(u64Address, bState);
    }
    break;

    case E_SL_MSG_SERIAL_LINK_GET_NWK_STATE:
    {
        au8values[4] = ZPS_u8NwkManagerState();
        au8values[5] = ZPS_u8ReturnNwkState ( ZPS_pvAplZdoGetNwkHandle() );
        u8TxLength += (sizeof(uint8)*2);
    }
    break;

    case E_SL_MSG_SERIAL_LINK_SET_MANUFACTURER_CODE:
    {
        /* Recover the Manufacturer Code from the Serial Link packet */
        uint16 u16ManCode;

        u16ManCode = ZNC_RTN_U16( au8LinkRxBuffer, 0 );

        /* Get the pointer of the Local Node Descriptor and change
         * the Manufacturer Code value by the one received on the Serial Link
         */
        zps_psGetLocalNodeDescriptor( ZPS_pvAplZdoGetAplHandle() )->u16ManufacturerCode = u16ManCode;
        break;
    }

    case E_SL_MSG_SET_PARENT_TIMEOUT:
    {

                            uint8 u8Method = au8LinkRxBuffer[0];
        /* ensure power negotiation flag is never cleared */
        u8Method |= CHILD_POWER_NEGOTIATION_SUPPORTED;
        /* clear out the unused bits */
        u8Method &= (CHILD_POWER_NEGOTIATION_SUPPORTED | CHILD_KEEP_ALIVE_POLL | CHILD_KEEP_ALIVE_TO_REQ);
        ZPS_vNwkSetParentTimeoutMethod( ZPS_pvNwkGetHandle(), u8Method);
        u8Status = 0;
        break;
    }

    case E_SL_MSG_SET_PANID_CNFL_RSVL:
    {
        /* This is related to CCB2313 hotfix */
        extern bool_t bResolvedConflictAllowed;

        /* This should be replaced by the API call ZPS_vNwkSetOverrideConflictBehaviour() */
        uint8 u8Method = au8LinkRxBuffer[0];
        ZPS_tsNwkNib *s_psNib = ZPS_psAplZdoGetNib();
        DBG_vPrintf(TRACE_APP, "Set cnfl rsvl old %04x new %04x\n", bResolvedConflictAllowed, u8Method);
        bResolvedConflictAllowed = (u8Method == 0U ? FALSE : TRUE);

        if (s_psNib != NULL) {
            /* Reset the last PAN ID conflict */
            s_psNib->u64VsLastPanIdConflict = 0;
            u8Status = 0;
        } else {
            u8Status = ZPS_NWK_ENUM_INVALID_REQUEST;
        }

        break;
    }
    case E_SL_MSG_NETWORK_CHANGE_ADDRESS:
    {
        uint16 u16NwkAddr;

        u16NwkAddr = ZNC_RTN_U16( au8LinkRxBuffer, 0 );
        ZPS_vNwkNibSetNwkAddr(ZPS_pvAplZdoGetNwkHandle(), u16NwkAddr);
        u8Status = 0;
    }
    break;
    case E_SL_MSG_GET_SECURITY_TIMEOUT:
    {
        ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();

        ZNC_BUF_U16_UPD(&au8values[u8TxLength], psAib->u16ApsSecurityTimeOutPeriod, u8TxLength);
    }
    break;

    case E_SL_MSG_JN_GET_STATE:
    {
        /*
         * Sending 4 bytes to LPC (and not 1) since the handling is shared with
         * another function
         */
        ZNC_BUF_U32_UPD(&au8values[u8TxLength], u8JNReadyForCmds, u8TxLength);
    }
    break;

    case E_SL_MSG_ZPS_DEFAULT_STACK:
    {
        zps_vDefaultStack(ZPS_pvAplZdoGetAplHandle());
    }
    break;

    case E_SL_MSG_ZPS_SET_KEYS:
    {
        ZPS_vSetKeys();
    }
    break;

    case E_SL_MSG_ZPS_SAVE_ALL_RECORDS:
    {
        zps_vSaveAllZpsRecords(ZPS_pvAplZdoGetAplHandle());
    }
    break;

    case E_SL_MSG_GET_TRSP_KEY_DECIDER_TABLE_MAX_SIZE:
    {
        /* Copy max table size for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength],  BDB_TRSP_KEY_DECIDER_TABLE_SIZE, u8TxLength );

        u8Status = 0x00;
        break;
    }

    case E_SL_MSG_GET_TRSP_KEY_DECIDER_TABLE_ENTRY:
    {
        uint8 u8TableIndex;
        uint16 u16Index = 0;
        BDB_tsTrspKeyDeciderEntry sEntry;

        /* copy u16TableIndex */
        u8TableIndex = ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        if (BDB_TRSP_KEY_DECIDER_TABLE_SIZE <= u8TableIndex)
        {
            u8Status = 0x01;
        }
        else
        {
            sEntry = s_TrspKeyDeciderTable.psTrspKeyDeciderEntry[u8TableIndex];

            /* Copy sEntry for sending over serial */
            ZNC_BUF_U64_UPD( &au8values[u8TxLength],  (uint64)sEntry, u8TxLength );
            u8Status = 0x00;
        }
        break;
    }
    
    case E_SL_MSG_ADD_TRSP_KEY_DECIDER_TABLE_ENTRY:
    {
        BDB_tsTrspKeyDeciderEntry sEntry;

        /* copy entry */
        sEntry = (BDB_tsTrspKeyDeciderEntry)ZNC_RTN_U64( au8LinkRxBuffer, 0 );

        u8Status = vAddTrspKeyDeciderEntry(sEntry);
        break;
    }

    case E_SL_MSG_REMOVE_TRSP_KEY_DECIDER_TABLE_ENTRY:
    {
        BDB_tsTrspKeyDeciderEntry sEntry;

        /* copy entry */
        sEntry = (BDB_tsTrspKeyDeciderEntry)ZNC_RTN_U64( au8LinkRxBuffer, 0 );

        u8Status = vRemoveTrspKeyDeciderEntry(sEntry);
        break;
    }
    
    case E_SL_MSG_CLEAR_TRSP_KEY_DECIDER_TABLE:
    {
        vClearTrspKeyDeciderTable();
        u8Status = 0x00;
        break;
    }
    
    case E_SL_MSG_GET_TRSP_KEY_DECIDER_TABLE_POLICY:
    {
        /* Copy policy for sending over serial */
        ZNC_BUF_U8_UPD( &au8values[u8TxLength], s_TrspKeyDeciderTable.eTrspKeyDeciderPolicy, u8TxLength );
        u8Status = 0x00;
        break;
    }
   
    case E_SL_MSG_SET_TRSP_KEY_DECIDER_TABLE_POLICY:
    {
        BDB_eTrspKeyDeciderPolicy ePolicy;
        uint16 u16Index = 0;

        /* copy policy */
        ePolicy = (BDB_eTrspKeyDeciderPolicy)ZNC_RTN_U8_OFFSET(au8LinkRxBuffer, u16Index, u16Index);

        if(ePolicy > 2)
        {
            /* Invalid policy value*/
            u8Status = 0x01;
        }
        else
        {
            s_TrspKeyDeciderTable.eTrspKeyDeciderPolicy = ePolicy;
            u8Status = 0x00;
        }
        break;
    }

    default:
        u8Status = E_SL_MSG_STATUS_UNSUPPORTED_COMMAND;
        DBG_vPrintf(TRUE, "Unhandled serial command 0x%04x\n", u16PacketType);
    }
    ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8Status, u8TempLen);
    ZNC_BUF_U8_UPD   ( &au8values[u8TempLen], u8ApsTSN, u8TempLen);
    ZNC_BUF_U16_UPD   ( &au8values[u8TempLen], u16PacketType, u8TempLen);
    bRxBufferLocked = FALSE;
    vSL_WriteMessage(u16ReturnMsgType, u8TxLength,  &u8ReceivedSeqNo, au8values);
}


/****************************************************************************
 *
 * NAME: eZdpMgmtIeeeJoinListReq
 *
 * DESCRIPTION:
 *
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eZdpMgmtIeeeJoinListReq(uint64 u64ExtAddr, uint8 u8StartIndex)
{
    PDUM_thAPduInstance hAPduInst;
    ZPS_teStatus eStatus = E_SL_MSG_STATUS_INVALID_PARAMETER;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
    u32StatusFlags &= ~APDU_0_STATUS_MASK;
    if (PDUM_INVALID_HANDLE != hAPduInst)
    {
        ZPS_tsAplZdpMgmtMibIeeeReq sMibIeeeReq;
        uint8 u8SeqNumber;
        ZPS_tuAddress tAddress;
        bool_t bExtAddr = TRUE;

        tAddress.u64Addr = u64ExtAddr;

        sMibIeeeReq.u8StartIndex = u8StartIndex;

        DBG_vPrintf(TRACE_APP, "MibIeee Req: Ext Addr = %016llx, Start Index = %d\n", u64ExtAddr, u8StartIndex );

        eStatus =  zps_eAplZdpMgmtMibIeeeRequest(
                ZPS_pvAplZdoGetAplHandle(),
                hAPduInst,
                tAddress,
                bExtAddr,
                &u8SeqNumber,
                &sMibIeeeReq);

        if(eStatus)
        {
            DBG_vPrintf(TRACE_APP, "zps_eAplZdpMgmtMibIeeeRequest() returned eStatus = %x\n", eStatus);
        }
    }
    else
    {
        DBG_vPrintf(TRACE_APP, "MibIeee Req: Can't alloc APDU\n");
        eStatus = E_SL_MSG_NO_APDU_BUFFERS;
    }
    return eStatus;
}

/****************************************************************************
 *
 * NAME: eZdpMgmtLeave
 *
 * DESCRIPTION: Send Management Leave
 *
 * PARAMETERS:
 * uint16 u16DstAddr - Destination Address
 * uint64 u64DeviceAddr - Source Address
 * bool_t bRejoin - Allow Rejoin after leave
 * bool_t bRemoveChildren - Remove Children
 * uint8* pu8Seq - Pointer to Sequence Number
 *
 * RETURNS:
 * ZPS_teStatus
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eZdpMgmtLeave(uint16 u16DstAddr, uint64 u64DeviceAddr,
        bool_t bRejoin, bool_t bRemoveChildren, uint8* pu8Seq) {
    PDUM_thAPduInstance hAPduInst;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
    u32StatusFlags &= ~APDU_0_STATUS_MASK;

    if (PDUM_INVALID_HANDLE != hAPduInst)
    {
        ZPS_tsAplZdpMgmtLeaveReq sMgmtLeaveReq;
        ZPS_tuAddress uDstAddr;

        uDstAddr.u16Addr = u16DstAddr;

        sMgmtLeaveReq.u64DeviceAddress = u64DeviceAddr;
        sMgmtLeaveReq.u8Flags = bRejoin ? 1 : 0;
        sMgmtLeaveReq.u8Flags |= bRemoveChildren ? 2 : 0;

        return ZPS_eAplZdpMgmtLeaveRequest(hAPduInst, uDstAddr, FALSE, pu8Seq,
                &sMgmtLeaveReq);
    }

    return  E_SL_MSG_NO_APDU_BUFFERS;
}

/****************************************************************************
 *
 * NAME: eZdpNodeDescReq
 *
 * DESCRIPTION: Node Descriptor Request
 *
 * PARAMETERS:
 * uint16 u16Addr - Destination Address
 * uint8* pu8SeqNum - Pointer to Sequence Number
 *
 * RETURNS:
 * ZPS_teStatus
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eZdpNodeDescReq(uint16 u16Addr, uint8* pu8SeqNum) {
    PDUM_thAPduInstance hAPduInst;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
    u32StatusFlags &= ~APDU_0_STATUS_MASK;

    if (PDUM_INVALID_HANDLE != hAPduInst)
    {
        ZPS_tsAplZdpNodeDescReq sNodeDescReq;
        ZPS_tuAddress uDstAddr;

        /* always send to node of interest rather than a cache */
        uDstAddr.u16Addr = u16Addr;

        sNodeDescReq.u16NwkAddrOfInterest = u16Addr;
        return ZPS_eAplZdpNodeDescRequest(hAPduInst, uDstAddr, FALSE,
                pu8SeqNum, &sNodeDescReq);
    }

    return  E_SL_MSG_NO_APDU_BUFFERS;
}

/****************************************************************************
 *
 * NAME: eZdpPowerDescReq
 *
 * DESCRIPTION: Power Descriptor Request
 *
 * PARAMETERS:
 * uint16 u16Addr - Destination Address
 * uint8* pu8SeqNum - Pointer to Sequence Number
 *
 * RETURNS:
 * ZPS_teStatus
 *
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eZdpPowerDescReq(uint16 u16Addr, uint8* pu8SeqNum) {
    PDUM_thAPduInstance hAPduInst;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
    u32StatusFlags &= ~APDU_0_STATUS_MASK;

    if (PDUM_INVALID_HANDLE != hAPduInst)
    {
        ZPS_tsAplZdpPowerDescReq sPowerDescReq;
        ZPS_tuAddress uDstAddr;

        /* always send to node of interest rather than a cache */
        uDstAddr.u16Addr = u16Addr;

        sPowerDescReq.u16NwkAddrOfInterest = u16Addr;
        return ZPS_eAplZdpPowerDescRequest(hAPduInst, uDstAddr, FALSE,
                pu8SeqNum, &sPowerDescReq);
    }

    return E_SL_MSG_NO_APDU_BUFFERS;
}

/****************************************************************************
 *
 * NAME: eZdpSimpleDescReq
 *
 * DESCRIPTION: Send Simple Descriptor
 *
 * PARAMETERS:
 * bool_t bIsExtAddr - Extended address?
 * ZPS_tuAddress uDstAddr - Destination Address
 * ZPS_tsAplZdpSimpleDescReq *psZdpSimpleDescReq - Structure of Network address and Endpoint
 * uint8* pu8Seq - Pointer to Sequence Number
 *
 * RETURNS:
 * ZPS_teStatus
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eZdpSimpleDescReq(bool_t bIsExtAddr, ZPS_tuAddress uDstAddr, ZPS_tsAplZdpSimpleDescReq *psZdpSimpleDescReq,
        uint8* pu8Seq) {
    PDUM_thAPduInstance hAPduInst;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
    u32StatusFlags &= ~APDU_0_STATUS_MASK;

    if (PDUM_INVALID_HANDLE != hAPduInst)
    {

        return ZPS_eAplZdpSimpleDescRequest(hAPduInst, uDstAddr, bIsExtAddr, pu8Seq,
                psZdpSimpleDescReq);
    }

    return E_SL_MSG_NO_APDU_BUFFERS;
}

/****************************************************************************
 *
 * NAME: eZdpActiveEndpointReq
 *
 * DESCRIPTION: Request Active Endpoints
 *
 * PARAMETERS:
 * uint16 u16Addr - Destination Address
 * uint8* pu8SeqNum - Pointer to Sequence Number
 *
 * RETURNS:
 * ZPS_teStatus
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eZdpActiveEndpointReq(ZPS_tuAddress uDstAddr, uint16 u16TargetAddr, uint8* pu8SeqNum) {
    PDUM_thAPduInstance hAPduInst;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
    u32StatusFlags &= ~APDU_0_STATUS_MASK;
    if (PDUM_INVALID_HANDLE != hAPduInst)
    {
        ZPS_tsAplZdpActiveEpReq sActiveEpReq;
        sActiveEpReq.u16NwkAddrOfInterest = u16TargetAddr;
        return ZPS_eAplZdpActiveEpRequest(hAPduInst, uDstAddr, FALSE,
                pu8SeqNum, &sActiveEpReq);
    }

    return E_SL_MSG_NO_APDU_BUFFERS;
}

/****************************************************************************
 *
 * NAME: eZdpMatchDescReq
 *
 * DESCRIPTION: Send Match Descriptor
 *
 * PARAMETERS:
 * uint16 u16Addr - Destination Address
 * uint16 u16NwkAoi - Nwk Address of Interest
 * uint16 u16profile - Profile
 * uint8 u8InputCount - Number of Input Clusters
 * uint16* pu16InputList - Pointer to List of Input Clusters to be Matched
 * uint8 u8OutputCount - Number of Output Clusters
 * uint16* pu16OutputList - Pointer to List of Output Clusters to be Matched
 * uint8* pu8SeqNum - Pointer to Sequence Number
 *
 * RETURNS:
 * ZPS_teStatus
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eZdpMatchDescReq(uint16 u16Addr, uint16 u16NwkAoI,
        uint16 u16profile, uint8 u8InputCount, uint16* pu16InputList,
        uint8 u8OutputCount, uint16* pu16OutputList, uint8* pu8SeqNum) {
    PDUM_thAPduInstance hAPduInst;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
    u32StatusFlags &= ~APDU_0_STATUS_MASK;
    if (PDUM_INVALID_HANDLE != hAPduInst)
    {
        ZPS_tsAplZdpMatchDescReq sMatchDescReq;
        ZPS_tuAddress uDstAddr;
        uDstAddr.u16Addr = u16Addr;
        sMatchDescReq.u16NwkAddrOfInterest = u16NwkAoI;

        sMatchDescReq.u16ProfileId = u16profile;
        sMatchDescReq.u8NumInClusters = u8InputCount;
        sMatchDescReq.pu16InClusterList = pu16InputList;;
        sMatchDescReq.u8NumOutClusters = u8OutputCount;
        sMatchDescReq.pu16OutClusterList = (u8OutputCount == 0) ? NULL : pu16OutputList;
        return ZPS_eAplZdpMatchDescRequest(hAPduInst, uDstAddr, FALSE,
                pu8SeqNum, &sMatchDescReq);

    }

    return E_SL_MSG_NO_APDU_BUFFERS;
}

/****************************************************************************
 *
 * NAME: eZdpIeeeAddrReq
 *
 * DESCRIPTION: IEEE Address Request
 *
 * PARAMETERS:
 * uint16 u16Dst - Destination Address
 * uint16 u16Addr - Network Address of Node in Interest
 * uint8 u8RequestType - The type of response required (Single Device/Extended Response)
 * uint8 u8StartIndex - Neighbour Table Index of the first node to be included if Extended Response selected.
 * uint8* pu8Seq - Pointer to Sequence Number
 *
 * RETURNS:
 * ZPS_teStatus
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eZdpIeeeAddrReq(uint16 u16Dst, uint16 u16Addr,
        uint8 u8RequestType, uint8 u8StartIndex, uint8* pu8Seq) {
    PDUM_thAPduInstance hAPduInst;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
    u32StatusFlags &= ~APDU_0_STATUS_MASK;

    if (PDUM_INVALID_HANDLE != hAPduInst)
    {
        ZPS_tsAplZdpIeeeAddrReq sAplZdpIeeeAddrReq;
        ZPS_tuAddress uDstAddr;

        /* always send to node of interest rather than a cache */
        uDstAddr.u16Addr = u16Dst;
        sAplZdpIeeeAddrReq.u16NwkAddrOfInterest = u16Addr;
        sAplZdpIeeeAddrReq.u8RequestType = u8RequestType;
        sAplZdpIeeeAddrReq.u8StartIndex = u8StartIndex;
        return ZPS_eAplZdpIeeeAddrRequest(hAPduInst, uDstAddr, FALSE, pu8Seq,
                &sAplZdpIeeeAddrReq);
    }

    return E_SL_MSG_NO_APDU_BUFFERS;

}

/****************************************************************************
 *
 * NAME: eZdpNwkAddrReq
 *
 * DESCRIPTION: Network Address Request
 *
 * PARAMETERS:
 * uint16 u16Dst - Destination Address
 * uint64 u64Addr - IEEE Address of Node in Interest
 * uint8 u8RequestType - The type of response required (Single Device/Extended Response)
 * uint8 u8StartIndex - Neighbour Table Index of the first node to be included if Extended Response selected.
 * uint8* pu8Seq - Pointer to Sequence Number
 *
 * RETURNS:
 * ZPS_teStatus
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eZdpNwkAddrReq(uint16 u16Dst, uint64 u64Addr,
        uint8 u8RequestType, uint8 u8StartIndex, uint8* pu8Seq) {
    PDUM_thAPduInstance hAPduInst;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
    u32StatusFlags &= ~APDU_0_STATUS_MASK;

    if (PDUM_INVALID_HANDLE != hAPduInst)
    {
        ZPS_tsAplZdpNwkAddrReq sAplZdpNwkAddrReq;
        ZPS_tuAddress uDstAddr;

        /* always send to node of interest rather than a cache */
        uDstAddr.u16Addr = u16Dst;
        sAplZdpNwkAddrReq.u64IeeeAddr = u64Addr;
        sAplZdpNwkAddrReq.u8RequestType = u8RequestType;
        sAplZdpNwkAddrReq.u8StartIndex = u8StartIndex;
        return ZPS_eAplZdpNwkAddrRequest(hAPduInst, uDstAddr, FALSE, pu8Seq,
                &sAplZdpNwkAddrReq);
    }

    return E_SL_MSG_NO_APDU_BUFFERS;

}

/****************************************************************************
 *
 * NAME: eZdpPermitJoiningReq
  *
 * DESCRIPTION: IEEE Address Request
 *
 * PARAMETERS:
 * uint16 u16DstAddr - Destination Address
 * uint8 u8PermitDuration - Length of time to allow join
 * bool bTcSignificance - Is device trust centre?
 * uint8* pu8Seq - Pointer to Sequence Number
 *
 * RETURNS:
 * ZPS_teStatus
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eZdpPermitJoiningReq(uint16 u16DstAddr,
        uint8 u8PermitDuration,
        bool bTcSignificance,uint8* pu8Seq)
{

    if(u16DstAddr != ZPS_u16NwkNibGetNwkAddr(ZPS_pvAplZdoGetNwkHandle()))
    {
        PDUM_thAPduInstance hAPduInst;
        hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
        u32StatusFlags &= ~APDU_0_STATUS_MASK;
        if (PDUM_INVALID_HANDLE != hAPduInst)
        {
            ZPS_tsAplZdpMgmtPermitJoiningReq sAplZdpMgmtPermitJoiningReq;
            ZPS_tuAddress uDstAddr;

            /* always send to node of interest rather than a cache */
            uDstAddr.u16Addr = u16DstAddr;
            sAplZdpMgmtPermitJoiningReq.u8PermitDuration = u8PermitDuration;
            sAplZdpMgmtPermitJoiningReq.bTcSignificance = bTcSignificance;
            return ZPS_eAplZdpMgmtPermitJoiningRequest(
                    hAPduInst,
                    uDstAddr,
                    FALSE,
                    pu8Seq,
                    &sAplZdpMgmtPermitJoiningReq);
        }
        return E_SL_MSG_NO_APDU_BUFFERS;
    }
    else
    {
        return ZPS_eAplZdoPermitJoining(u8PermitDuration);
    }

    return E_SL_MSG_STATUS_INVALID_PARAMETER;
}

/****************************************************************************
 *
 * NAME: eBindUnbindEntry
 *
 * DESCRIPTION: Bind/Unbind endpoint on local node with endpoint on remote node.
 *
 * PARAMETERS:
 * bool_t bBind - Bind or Unbind
 * uint64 u64SrcAddr - Source Address
 * uint8 u8SrcEndpoint - Source Endpoint
 * uint16 u16ClusterId - Cluster ID of Cluster on Source Node to be Bound
 * ZPS_tuAddress *puDstAddress - Pointer to Destination addresses
 * uint8 u8DstEndpoint - Destination Endpoint
 * uint8 u8DstAddrMode - Destination Address Mode
 * uint8* pu8Seq - Pointer to Sequence Number
 *
 * RETURNS:
 * ZPS_teStatus
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eBindUnbindEntry(bool_t bBind, uint64 u64SrcAddr,
        uint8 u8SrcEndpoint, uint16 u16ClusterId, ZPS_tuAddress *puDstAddress,
        uint8 u8DstEndpoint, uint8 u8DstAddrMode, uint8* pu8Seq)
{
    ZPS_teStatus eReturnCode = E_SL_MSG_STATUS_INVALID_PARAMETER;
    ZPS_tuAddress uAddr;
    ZPS_tsAplZdpBindUnbindReq sAplZdpBindReq;

    if (u8DstAddrMode == 0x1) {
        sAplZdpBindReq.uAddressField.sShort.u16DstAddress = uAddr.u16Addr
                = puDstAddress->u16Addr;
    } else {
        u8DstAddrMode = 0x3;
        uAddr.u64Addr = puDstAddress->u64Addr;
        sAplZdpBindReq.uAddressField.sExtended.u64DstAddress
                = puDstAddress->u64Addr;
        sAplZdpBindReq.uAddressField.sExtended.u8DstEndPoint = u8DstEndpoint;
    }

    if (ZPS_u64NwkNibGetExtAddr(ZPS_pvAplZdoGetNwkHandle()) == u64SrcAddr) {
        if (bBind) {
            /* should now be done by Zdo Bind Request serial message directly */
            eReturnCode = E_SL_MSG_STATUS_ILLEGAL_REQUEST;
        } else {
            /* should now be done by remove mac address from binding serial message directly */
            eReturnCode = E_SL_MSG_STATUS_ILLEGAL_REQUEST;
        }
    } else {
        PDUM_thAPduInstance hAPduInst;

        hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
        u32StatusFlags &= ~APDU_0_STATUS_MASK;

        if (PDUM_INVALID_HANDLE != hAPduInst)
        {
            ZPS_tuAddress uDstAddr;
            /* always send to node of interest rather than a cache */
            uDstAddr.u64Addr = u64SrcAddr;
            sAplZdpBindReq.u64SrcAddress = u64SrcAddr;
            sAplZdpBindReq.u8SrcEndpoint = u8SrcEndpoint;
            sAplZdpBindReq.u16ClusterId = u16ClusterId;
            sAplZdpBindReq.u8DstAddrMode = u8DstAddrMode;
            if (bBind) {
                eReturnCode = ZPS_eAplZdpBindUnbindRequest(hAPduInst, uDstAddr,
                        TRUE, pu8Seq, TRUE, &sAplZdpBindReq);
            } else {
                eReturnCode = ZPS_eAplZdpBindUnbindRequest(hAPduInst, uDstAddr,
                        TRUE, pu8Seq, FALSE, &sAplZdpBindReq);
            }
        }
        else
        {
            eReturnCode = E_SL_MSG_NO_APDU_BUFFERS;
        }
    }
    return eReturnCode;
}

/****************************************************************************
 *
 * NAME: vControlNodeScanStart
 *
 * DESCRIPTION: Starts network processes for node
 *
 * PARAMETERS:
 * void
 *
 * RETURNS:
 * void
 ****************************************************************************/
PRIVATE void vControlNodeScanStart(void)
{
    if (sNcpDeviceDesc.eState == FACTORY_NEW)
    {
        /* factory new start up */
        if (sNcpDeviceDesc.u8DeviceType == ZPS_ZDO_DEVICE_COORD)
        {
            ZPS_eAplZdoStartStack();
            sNcpDeviceDesc.eState = NOT_FACTORY_NEW;
            sNcpDeviceDesc.eNodeState = E_RUNNING;
        }
        else
        {
            sNcpDeviceDesc.eNodeState = E_DISCOVERY;
            vSaveDevicePdmRecord();

        }
    }
    else
    {
        if (sNcpDeviceDesc.u8DeviceType == ZPS_ZDO_DEVICE_COORD)
        {
            ZPS_eAplZdoStartStack();
            sNcpDeviceDesc.eState = NOT_FACTORY_NEW;
            sNcpDeviceDesc.eNodeState = E_RUNNING;
        }
        else
        {
            ZPS_eAplZdoStartStack();
        }
    }
}

/****************************************************************************
 *
 * NAME: u8ControlNodeStartNetwork
 *
 * DESCRIPTION: Start network when Factory New
 *
 * PARAMETERS:
 * void
 *
 * RETURNS:
 * void
 ****************************************************************************/
PRIVATE uint8 u8ControlNodeStartNetwork(void)
{

    ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();
    uint8 u8Status = E_SL_MSG_STATUS_ILLEGAL_REQUEST;

    if (sNcpDeviceDesc.eState == FACTORY_NEW)
    {
        if (sNcpDeviceDesc.u8DeviceType == ZPS_ZDO_DEVICE_COORD)
        {
            if (sNcpDeviceDesc.eState == FACTORY_NEW)
            {
                sNcpDeviceDesc.eState = NOT_FACTORY_NEW;
                sNcpDeviceDesc.eNodeState = E_RUNNING;

                if (psAib->u64ApsUseExtendedPanid == 0)
                {
                    psAib->u64ApsUseExtendedPanid = CRYPTO_u32RandomGet(1,
                            0xffffffff);
                    psAib->u64ApsUseExtendedPanid <<= 32;
                    psAib->u64ApsUseExtendedPanid |= CRYPTO_u32RandomGet(0,
                            0xffffffff);
                }

                u8Status = ZPS_eAplZdoStartStack();
                DBG_vPrintf(TRACE_APP, "ZPS_eAplZdoStartStack status %02x... \r\n", u8Status);

                vSaveDevicePdmRecord();
            }
            else
            {
                u8Status = ZPS_eAplZdoStartStack();
            }
        }
    }
    return u8Status;
}

/****************************************************************************
 *
 * NAME: u8ControlNodeSetUpForInterPan
 *
 * DESCRIPTION: Set up for Inter-PAN Transfer
 *
 * PARAMETERS:
 * uint8 u8ChannelNumber
 *
 * RETURNS:
 * status
 ****************************************************************************/
PRIVATE uint8 u8ControlNodeSetUpForInterPan(uint32 u32ChannelMask)
{
    bool bEnabled = FALSE;
    uint8 u8Page;
    uint8 u8Status = 0;
    if(sNcpDeviceDesc.eNodeState != E_RUNNING)
    {
        ZPS_vNwkNibSetPanId(ZPS_pvAplZdoGetNwkHandle(), (uint16) CRYPTO_u32RandomGet(1, 0xfff0) );
    }

    u8Page = MAC_PAGE_FROM_MASK(u32ChannelMask);
#ifdef MAC_TYPE_SOC
    if (u8Page == MAC_CHAN_MASK_PAGE_0)
    {
        u8Status = u8Set2G4ChannelFromMask(u32ChannelMask);
    }
    else
    {
        u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
    }
#else
  #ifdef MAC_SG_ONLY
    if ((u8Page == MAC_CHAN_MASK_PAGE_28) ||
        (u8Page == MAC_CHAN_MASK_PAGE_29) ||
        (u8Page == MAC_CHAN_MASK_PAGE_30) ||
        (u8Page == MAC_CHAN_MASK_PAGE_31) )
    {
        u8Status = u8SetSubGigChannel(u32ChannelMask);
    }
    else
    {
        u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
    }
  #endif

#endif
    ZPS_eAplAfGetEndpointState(1, &bEnabled);
    if(bEnabled == FALSE)
    {
        ZPS_eAplAfSetEndpointState(1, TRUE);
    }
    return u8Status;
}

//#if (defined MAC_TYPE_SOC)
/****************************************************************************
 *
 * NAME: u8Set2G4ChannelFromMask
 *
 * DESCRIPTION: This function set the 2g4 channel from a given mask
 *
 * PARAMETERS:
 * uint32 u32Channel
 *
 * RETURNS:
 * uint8 status code
 *
 ****************************************************************************/
PRIVATE uint8 u8Set2G4ChannelFromMask(uint32 u32ChannelMask)
{
    uint8 u8Status = E_SL_MSG_STATUS_SUCCESS;
    u32ChannelMask = MAC_CHANNELMASK_FROM_MASK(u32ChannelMask);

    if (u32ChannelMask != 0U)
    {
        uint8 u8Channel = 0;

        if(u8Status==E_SL_MSG_STATUS_SUCCESS)
        {
            while( (u32ChannelMask & 1U) == 0U)
            {
                u8Channel++;
                u32ChannelMask >>= 1;
            }
            ZPS_vNwkNibSetChannel( ZPS_pvAplZdoGetNwkHandle(), u8Channel);

        }
        else
        {
            u8Status = E_SL_MSG_STATUS_HARDWARE_FAILURE;
        }
    }
    else
    {
        u8Status = E_SL_MSG_STATUS_INCORRECT_PARAMETERS;
    }

    return u8Status;
}
//#endif

/****************************************************************************
 *
 * NAME: u8AppChangeChannel
 *
 * DESCRIPTION: This function changes the channel randomly to one of the other primaries
 *
 * PARAMETERS:
 * uint32 u32Channel
 *
 * RETURNS:
 * uint8 status code
 *
 ****************************************************************************/
PRIVATE uint8 u8AppChangeChannel( uint32 u32Channel)
{
    PDUM_thAPduInstance hAPduInst;
    uint8 u8Status;
    ZPS_tuAddress uDstAddr;
    uint8 u8Seq;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
    u32StatusFlags &= ~APDU_0_STATUS_MASK;
    if (hAPduInst != NULL)
    {
        ZPS_tsAplZdpMgmtNwkEnhanceUpdateReq sMgmtNwkEnhanceUpdateReq;

        uDstAddr.u16Addr = 0xfffd;

        sMgmtNwkEnhanceUpdateReq.u8ScanDuration = 0xfe;
        /* Scan Count is used in case of ED Scan, and is don't care here */
        sMgmtNwkEnhanceUpdateReq.u8ScanCount = 1u;
        sMgmtNwkEnhanceUpdateReq.u8NwkUpdateId = ZPS_psAplZdoGetNib()->sPersist.u8UpdateId + 1;
        /* Only one valid channel mask in case of channel change */
        sMgmtNwkEnhanceUpdateReq.sZdpScanChannelList.u8ChannelPageCount = 1u;
        sMgmtNwkEnhanceUpdateReq.sZdpScanChannelList.pu32ChannelField[0]= u32Channel;
        /* rest of channel masks are don't cares, initializing them to 0x00000000 */
        sMgmtNwkEnhanceUpdateReq.sZdpScanChannelList.pu32ChannelField[1]= 0x00000000;
        sMgmtNwkEnhanceUpdateReq.sZdpScanChannelList.pu32ChannelField[2]= 0x00000000;
        sMgmtNwkEnhanceUpdateReq.sZdpScanChannelList.pu32ChannelField[3]= 0x00000000;
        sMgmtNwkEnhanceUpdateReq.sZdpScanChannelList.pu32ChannelField[4]= 0x00000000;
        /* The valid Network Manager Address in a centralized network is 0x0000 */
        sMgmtNwkEnhanceUpdateReq.u16NwkManagerAddr = 0x0000u;

        u8Status = ZPS_eAplZdpMgmtNwkEnhanceUpdateRequest( hAPduInst,
                                                           uDstAddr,
                                                           FALSE,
                                                           &u8Seq,
                                                           &sMgmtNwkEnhanceUpdateReq);
        if(0 == u8Status)
        {
            ZPS_psAplZdoGetNib()->sPersist.u8UpdateId++;            ZPS_vSaveAllZpsRecords();

        }

    }
    else
    {
        u8Status = E_SL_MSG_NO_APDU_BUFFERS;
    }
    return u8Status;
}

/****************************************************************************
 *
 * NAME: bGetDeviceStats
 *
 * DESCRIPTION: Gets last and average LQI values for the device
 *
 * PARAMETERS:
 * uint64 u64Mac - Device MAC Address
 * uint8 *pu8LastLqi - Pointer to Last LQI value
 * uint8 *pu8AverageLqi - Pointer to Average LQI Value
 *
 * RETURNS:
 * bool_t
 *
 ****************************************************************************/
PRIVATE bool_t bGetDeviceStats(uint64 u64Mac, uint8 *pu8LastLqi, uint8 *pu8AverageLqi)
{
    uint8 i;

    /*search in the device stats table entry*/
    for(i=0;i<MAX_NUMBER_OF_STATS_ENTRY;i++)
    {
        if((sNwkStats.sDeviceStats[i].u64MacAddress == u64Mac)&&(sNwkStats.sDeviceStats[i].u64MacAddress != 0))
        {
            *pu8LastLqi = sNwkStats.sDeviceStats[i].u8LastLQI;
            *pu8AverageLqi = sNwkStats.sDeviceStats[i].u8AverageLQI;
            return TRUE;
        }
    }
    return FALSE;
}

/****************************************************************************
 *
 * NAME: u16GetTemp
 *
 * DESCRIPTION: Reads the Temperature value
 *
 * PARAMETERS:
 * void
 *
 * RETURNS:
 * uint16 - Temperature value
 *
 ****************************************************************************/
PRIVATE uint16 u16GetTemp(void)
{
  DBG_vPrintf(TRUE, "return u16AppGetTemp();");
  return 0;
}

/****************************************************************************
 *
 * NAME: vAPPSendZPSData
 *
 * DESCRIPTION: Sends ZPS data based on incoming serial commands
 *
 * PARAMETERS:
 * uint8 PktType - Type of Command
 * uint8 *pu8Buffer - Pointer to command data
 * uint16 *pu16ClusterId - Pointer to Cluster ID
 * uint8 *pu8SeqNum - Pointer to Sequence Number
 * uint8 *pu8Status - Pointer to Status
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vAPPSendZPSData (teSL_MsgType PktType, uint8 *pu8Buffer, uint16 *pu16ClusterId, uint8 *pu8SeqNum, uint8 *pu8Status)
{
    tsCommon Params = {0,0,0,0,0,0,0};
    PDUM_thAPduInstance hAPduInst;
    uint16 u16Index = 0x00;

    hAPduInst = NULL;

    /* copy u32ClId_DstEp_SrcEp */
    Params.u32ClId_DstEp_SrcEp = ZNC_RTN_U32_OFFSET( pu8Buffer, u16Index, u16Index );

    if(PktType == E_SL_MSG_BROADCAST_DATA_REQ)
    {
        Params.u8BrdAddrMode = ZNC_RTN_U8_OFFSET( pu8Buffer, u16Index, u16Index);
    }
    else if(PktType == E_SL_MSG_GROUP_DATA_REQ)
    {
        /* copy u16GrpAddr */
        Params.u16GrpAddr = ZNC_RTN_U16_OFFSET( pu8Buffer, u16Index, u16Index );
    }
    else if((PktType == E_SL_MSG_UNICAST_IEEE_ACK_DATA_REQ) || (PktType == E_SL_MSG_UNICAST_IEEE_DATA_REQ))
    {
        /* copy u64DestAddr */
        Params.u64DestAddr = ZNC_RTN_U64_OFFSET( pu8Buffer, u16Index, u16Index );
    }
    else if((PktType == E_SL_MSG_UNICAST_DATA_REQ) || (PktType == E_SL_MSG_UNICAST_ACK_DATA_REQ))
    {
        /*check who requires destination address*/
        /* copy u16DestAddr */
        Params.u16DestAddr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
    }
    else if(PktType == E_SL_MSG_APSDE_DATA_REQUEST)
    {
        /* copy u8DestAddrMode*/
        Params.u8DestAddrMode = ZNC_RTN_U8_OFFSET( pu8Buffer, u16Index, u16Index);

        if (Params.u8DestAddrMode == ZPS_E_ADDR_MODE_IEEE) 
        {
            /* copy u64DestAddr */
            Params.u64DestAddr = ZNC_RTN_U64_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        } else {
            /* copy u16DestAddr */
            Params.u16DestAddr = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );
        }

        /* copy u16ProfileId*/
        Params.u16ProfileId = ZNC_RTN_U16_OFFSET( pu8Buffer, u16Index, u16Index );
    }

    /* copy u16SecMd_Radius */
    Params.u16SecMd_Radius = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );

    /* copy u16PayloadLen */
    Params.u16PayloadLen = ZNC_RTN_U16_OFFSET( au8LinkRxBuffer, u16Index, u16Index );


    /* copy u32ClId_DstEp_SrcEp */
    *pu16ClusterId = (Params.u32ClId_DstEp_SrcEp >> 16);

    /* check Payload size */
    /* try for the smallest buffer */
    DBG_vPrintf(TRACE_TX_BUFFERS, "[BUFTX] Cluster %04x Ep %d Size %d > ",
            (uint16)(Params.u32ClId_DstEp_SrcEp >> 16),
            (uint8)(Params.u32ClId_DstEp_SrcEp & 0xff),
            Params.u16PayloadLen );
    bBlockApduError = TRUE;
    if ( Params.u16PayloadLen <= PDUM_u16APduGetSize(apduZCL) )
    {
        hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
        if (hAPduInst != NULL)
        {
            DBG_vPrintf(TRACE_TX_BUFFERS, "Standard-btx\n");
        }
        u32StatusFlags &= ~APDU_0_STATUS_MASK;
    }
    /* if still  not yet got a buffer try the largest */
    bBlockApduError = FALSE;
#if 0
    if (( hAPduInst == NULL) && ( Params.u16PayloadLen <= PDUM_u16APduGetSize(apduJUMBOZCL) ))
    {
        hAPduInst = PDUM_hAPduAllocateAPduInstance(apduJUMBOZCL);
        if (hAPduInst != NULL)
         {
            DBG_vPrintf(TRACE_TX_BUFFERS, "Jumbo-btx\n");
        }
        u32StatusFlags &= ~APDU_2_STATUS_MASK;
    }
    bBlockApduError = FALSE;
#endif
    if (hAPduInst)
    {
        /* Copy Payload */
        memcpy(
                (uint8 *) (PDUM_pvAPduInstanceGetPayload(hAPduInst)),
                &pu8Buffer[u16Index], Params.u16PayloadLen);

        /* Set Payload Size */
        PDUM_eAPduInstanceSetPayloadSize(hAPduInst, Params.u16PayloadLen);

        u8TempExtendedError = 0u;

        switch(PktType)
        {
            case E_SL_MSG_UNICAST_ACK_DATA_REQ:

                *pu8Status = zps_eAplAfUnicastAckDataReq(
                        ZPS_pvAplZdoGetAplHandle(), hAPduInst,
                        Params.u32ClId_DstEp_SrcEp, Params.u16DestAddr, Params.u16SecMd_Radius,
                        pu8SeqNum);
                break;

            case E_SL_MSG_UNICAST_DATA_REQ:

                *pu8Status = zps_eAplAfUnicastDataReq(
                                        ZPS_pvAplZdoGetAplHandle(), hAPduInst,
                                        Params.u32ClId_DstEp_SrcEp, Params.u16DestAddr, Params.u16SecMd_Radius,
                                        pu8SeqNum);
                break;

            case E_SL_MSG_UNICAST_IEEE_ACK_DATA_REQ:

                *pu8Status = zps_eAplAfUnicastIeeeAckDataReq(
                        ZPS_pvAplZdoGetAplHandle(), hAPduInst,
                        Params.u32ClId_DstEp_SrcEp, &Params.u64DestAddr, Params.u16SecMd_Radius,
                        pu8SeqNum);
                break;

            case E_SL_MSG_UNICAST_IEEE_DATA_REQ:

                *pu8Status = zps_eAplAfUnicastIeeeDataReq(
                                        ZPS_pvAplZdoGetAplHandle(), hAPduInst,
                                        Params.u32ClId_DstEp_SrcEp, &Params.u64DestAddr, Params.u16SecMd_Radius,
                                        pu8SeqNum);
                break;

            case E_SL_MSG_BOUND_ACK_DATA_REQ:

                *pu8Status = zps_eAplAfBoundAckDataReq(
                        ZPS_pvAplZdoGetAplHandle(), hAPduInst,
                        Params.u32ClId_DstEp_SrcEp, Params.u16SecMd_Radius, pu8SeqNum);
                break;

            case E_SL_MSG_BOUND_DATA_REQ:

                *pu8Status = zps_eAplAfBoundDataReq(
                        ZPS_pvAplZdoGetAplHandle(), hAPduInst,
                        Params.u32ClId_DstEp_SrcEp, Params.u16SecMd_Radius, pu8SeqNum);
                break;

            case E_SL_MSG_BROADCAST_DATA_REQ:

                *pu8Status = zps_eAplAfBroadcastDataReq(
                        ZPS_pvAplZdoGetAplHandle(), hAPduInst,
                        Params.u32ClId_DstEp_SrcEp, Params.u8BrdAddrMode,
                        Params.u16SecMd_Radius, pu8SeqNum);
                break;

            case E_SL_MSG_GROUP_DATA_REQ:

                *pu8Status = zps_eAplAfGroupDataReq(
                        ZPS_pvAplZdoGetAplHandle(), hAPduInst,
                        Params.u32ClId_DstEp_SrcEp, Params.u16GrpAddr, Params.u16SecMd_Radius,
                        pu8SeqNum);
                break;

            case E_SL_MSG_APSDE_DATA_REQUEST:
            {
                ZPS_tsAfProfileDataReq sProfileDataReq;
                sProfileDataReq.uDstAddr.u16Addr = Params.u16DestAddr;
                sProfileDataReq.u16ClusterId = *pu16ClusterId;
                sProfileDataReq.u16ProfileId = Params.u16ProfileId;
                sProfileDataReq.u8SrcEp = Params.u32ClId_DstEp_SrcEp & 0xFF;
                sProfileDataReq.eDstAddrMode =Params.u8DestAddrMode;
                sProfileDataReq.u8DstEp = (Params.u32ClId_DstEp_SrcEp >> 8) & 0xFF;
                sProfileDataReq.eSecurityMode = Params.u16SecMd_Radius;
                sProfileDataReq.u8Radius = Params.u16SecMd_Radius;
                *pu8Status = zps_eAplAfApsdeDataReq(
                        ZPS_pvAplZdoGetAplHandle(), hAPduInst, 
                        &sProfileDataReq, pu8SeqNum, 0);
                break;
            }
            default:
                break;

        }
        if ( *pu8Status != ZPS_E_SUCCESS )
        {
            PDUM_eAPduFreeAPduInstance(hAPduInst);
            if ( u8TempExtendedError != 0u )
            {
                /* during process of the api there was an extended error
                 * change the return code */
                *pu8Status = E_SL_MSG_STATUS_C2_SUBSTITUTION;
            }
        }
    }
    else
    {
        DBG_vPrintf(TRACE_TX_BUFFERS, "No tramsmit buffer\n");
        *pu8Status = E_SL_MSG_NO_APDU_BUFFERS;
    }


}

PUBLIC void vAppHandlePDMError(void)
{
    DBG_vPrintf(TRUE, "vAppHandlePDMError\n");
}

PUBLIC void vSendPdmStatusToHost(teSL_PdmCmdType eCmdType, uint8 u8PDMStatus)
{
    DBG_vPrintf(TRUE, "vSendPdmStatusToHost\n");
}

PUBLIC void vSaveDevicePdmRecord(void)
{
    uint8 u8PDMStatus;
    uint16 u16len;

    if( PDM_bDoesDataExist(PDM_ID_APP_COORD, &u16len))
    {
        u8PDMStatus = PDM_eSaveRecordData(PDM_ID_APP_COORD, &sNcpDeviceDesc, sizeof(tsNcpDeviceDesc));
        if(PDM_E_STATUS_OK != u8PDMStatus)
        {
            DBG_vPrintf(TRUE, "\n PDM_eSaveRecordData PDM_ID_APP_COPROCESSOR_NODE ERROR: 0x%02x\n", u8PDMStatus);
            vSendPdmStatusToHost(E_SL_PDM_CMD_SAVE, u8PDMStatus);
            vAppHandlePDMError();
        }
    }
    else {
        /* Handle error, record should exist, send to host and call handle pdm error */
        u8PDMStatus = PDM_E_STATUS_NOT_SAVED;
        DBG_vPrintf(TRUE, "\n PDM_eSaveRecordData couldn't find PDM_ID_APP_COPROCESSOR_NODE record\n");
        vSendPdmStatusToHost(E_SL_PDM_CMD_SAVE, u8PDMStatus);
        vAppHandlePDMError();
    }
}

PUBLIC void vCleanStackTables(uint64 u64RemoveDevice)
{
    if ((u64RemoveDevice != 0U) && (u64RemoveDevice != 0xffffffffffffffffUL))
    {
        ZPS_vNMPurgeEntry (u64RemoveDevice);
    }
}

PUBLIC uint8 u8EnableBoundDevices( bool_t bState)
{
    uint64 u64Address;

    ZPS_tsAplApsKeyDescriptorEntry *psEntry;
    int idx;
    ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();
    void * pvNwk = ZPS_pvAplZdoGetNwkHandle();

    for (idx=0; idx < psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable; idx++)
    {
        psEntry = &psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[idx];
        /* check for matched entry */
        u64Address = ZPS_u64NwkNibGetMappedIeeeAddr( pvNwk, psEntry->u16ExtAddrLkup);
        if( ( u64Address > 0) && ( u64Address < ZPS_E_BROADCAST_ALL_IEEE) )
        {
            /* valid mac address so set the key type */
            (void)u8EnableBoundDevice(u64Address, bState);
        }
    }

    return 0;
}


/****************************************************************************
 *
 * NAME: u8EnableBoundDevice
 *
 * DESCRIPTION:
 * Adds/removes the block on bound devices by setting the APS key type to
 * ZPS_APS_INSTALL_KEY/ZPS_APS_INSTALL_KEY
 *
 * PARAMETERS
 * None
 *
 * RETURNS:
 * uint16 u16OptionMaskValue
 *
 ****************************************************************************/
PUBLIC uint8 u8EnableBoundDevice(uint64 u64Address, bool_t bState)
{
    uint8 u8Status;

    /*
     * TODO: The logic below has been changed to take into account that in the stack
     * the logic for a bound transmission is reversed:
     *  - done when the APS device key type is NOT ZPS_APS_NEG_LINK_KEY ( = ZPS_APS_NEG_LINK_KEY)
     *  - NOT done when APS device key type is ZPS_APS_INSTALL_KEY
     *
     *  While waiting for a new SDK to fix this, since we don't want to affect the host
     *  API, the simplest solution is to reverse the logic here.
     *
     */
    if (bState == FALSE)
    {
        u8Status = ZPS_eAplAibSetDeviceApsKeyType(u64Address, ZPS_APS_INSTALL_KEY);
    }
    else
    {
        u8Status = ZPS_eAplAibSetDeviceApsKeyType(u64Address, ZPS_APS_NEG_LINK_KEY);
    }

    return u8Status;
}

PRIVATE uint16 u16SearchKeyTableByIeeeAddress(uint64 u64IEEEAddress)
{
    bool_t bFound = FALSE;
    uint16 u16TableIndex = 0;
    ZPS_tsAplApsKeyDescriptorEntry *sEntry;
    ZPS_tsAplAib *psAib = ZPS_psAplAibGetAib();

    while (!bFound && (u16TableIndex < psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable))
    {
        sEntry = &psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry[u16TableIndex];
        DBG_vPrintf(TRACE_APP, "Lookup address: x%04x\n", sEntry->u16ExtAddrLkup);
        if (ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(), sEntry->u16ExtAddrLkup) ==
                u64IEEEAddress)
        {
            bFound = TRUE;
            DBG_vPrintf(TRACE_APP, "Found at pos %d\n", u16TableIndex);

        }
        else
        {
            u16TableIndex++;
        }
    }

    if (!bFound)
    {
        u16TableIndex = psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable + 1;
    }

    return u16TableIndex;

}

/****************************************************************************
 *
 * NAME: vAddTrspKeyDeciderEntry
 *
 * DESCRIPTION:
 *  Adds given entry to transport key decider table if not already present. 
 *  Fails if table full.
 *
 * PARAMETERS:      Name                    RW      Usage
 *                  s_TrspKeyDeciderEntry           Entry to add
 * RETURNS:
 *  uint8
 *
 ****************************************************************************/
PUBLIC uint8 vAddTrspKeyDeciderEntry(BDB_tsTrspKeyDeciderEntry s_TrspKeyDeciderEntry)
{
    if(u8GetTrspKeyDeciderIndex(s_TrspKeyDeciderEntry) != BDB_TRSP_KEY_DECIDER_TABLE_SIZE)
    {
        /* Entry already present, nothing to do */
        return 0x00;
    }

    if(s_TrspKeyDeciderTable.u16SizeOfTrspKeyDeciderTable == BDB_TRSP_KEY_DECIDER_TABLE_SIZE)
    {
        /* Table full */
        return 0x01;
    }

    uint8 u8FreeIndex = u8GetTrspKeyDeciderFreeIndex();
    s_TrspKeyDeciderTable.psTrspKeyDeciderEntry[u8FreeIndex] = s_TrspKeyDeciderEntry;
    s_TrspKeyDeciderTable.u16SizeOfTrspKeyDeciderTable++;
    return 0x00;
}

/****************************************************************************
 *
 * NAME: vRemoveTrspKeyDeciderEntry
 *
 * DESCRIPTION:
 *  Removes given entry from transport key decider table if not already missing. 
 *  Fails if table empty.
 *
 * PARAMETERS:      Name                    RW      Usage
 *                  s_TrspKeyDeciderEntry           Entry to remove
 * RETURNS:
 *  uint8
 *
 ****************************************************************************/
PUBLIC uint8 vRemoveTrspKeyDeciderEntry(BDB_tsTrspKeyDeciderEntry s_TrspKeyDeciderEntry)
{
    if(u8GetTrspKeyDeciderIndex(s_TrspKeyDeciderEntry) == BDB_TRSP_KEY_DECIDER_TABLE_SIZE)
    {
        /* Entry already absent, nothing to do */
        return 0x00;
    }

    if(s_TrspKeyDeciderTable.u16SizeOfTrspKeyDeciderTable == 0)
    {
        /* Table empty */
        return 0x01;
    }

    uint8 u8IndexToRemove = u8GetTrspKeyDeciderIndex(s_TrspKeyDeciderEntry);
    s_TrspKeyDeciderTable.psTrspKeyDeciderEntry[u8IndexToRemove] = 0;
    s_TrspKeyDeciderTable.u16SizeOfTrspKeyDeciderTable--;
    return 0x00;
}

/****************************************************************************
 *
 * NAME: vClearTrspKeyDeciderTable
 *
 * DESCRIPTION:
 *  Zeroes out the transport key decider table.
 *
 * PARAMETERS:      Name            RW  Usage
 * 
 * RETURNS:
 *  void
 *
 ****************************************************************************/
PUBLIC void vClearTrspKeyDeciderTable()
{
    uint8 u8Index;

    if(s_TrspKeyDeciderTable.u16SizeOfTrspKeyDeciderTable == 0)
    {
        /* Table empty */
        return;
    }
    else
    {   
        for(u8Index = 0; u8Index < BDB_TRSP_KEY_DECIDER_TABLE_SIZE; u8Index++)
        {
           s_TrspKeyDeciderTable.psTrspKeyDeciderEntry[u8Index] = 0;
        }
        s_TrspKeyDeciderTable.u16SizeOfTrspKeyDeciderTable = 0;
    }
}

PUBLIC bool_t vNfTcCallback (uint16 u16ShortAddress,
                             uint64 u64DeviceAddress,
                             uint64 u64ParentAddress,
                             uint8 u8Status,
                             uint16 u16MacId )
{
    /*If we are joining with default key we only need to remove the existing key */
    ZPS_tsAplAib *psAib                          = zps_psAplAibGetAib( ZPS_pvAplZdoGetAplHandle( ) );
    uint32 u32KeyTblSize                         = psAib->psAplDeviceKeyPairTable->u16SizeOfKeyDescriptorTable;
    ZPS_tsAplApsKeyDescriptorEntry *psKeyTbl     = psAib->psAplDeviceKeyPairTable->psAplApsKeyDescriptorEntry;
    uint32 i;

    /* we are only interested in insecure join , all other joins we should
     * use the normal key which is the TC key if negotiated else it is
     * the global or install code.
     */
    if(u8Status == ZPS_APL_SEC_STD_UNSEC_JOIN )
    {
        for (i = 0; i < u32KeyTblSize; i++)
        {
            if (u64DeviceAddress == ZPS_u64NwkNibGetMappedIeeeAddr( ZPS_pvAplZdoGetNwkHandle(), psKeyTbl[i].u16ExtAddrLkup ) )
            {
                ZPS_tsAplAib *psAib =
                zps_psAplAibGetAib(ZPS_pvAplZdoGetAplHandle());
                /* Getter for bUseInstallCode member to be implemented, acces it directly for now*/
            	if(psAib->bUseInstallCode == FALSE)
            	{
            		psAib->pu32IncomingFrameCounter[i]  = 0;
                	memset(&psKeyTbl[i], 0, sizeof(ZPS_tsAplApsKeyDescriptorEntry));
                	psKeyTbl[i].u16ExtAddrLkup          = 0xFFFF;
				}
                ZPS_vSaveAllZpsRecords();
            }
        }
    }
    /* Return TRUE or FALSE according to the transport key decider table */
     return doSendTransportKey(u64DeviceAddress);
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: u8GetTrspKeyDeciderFreeIndex
 *
 * DESCRIPTION:
 *  Returns the index of the first free entry in the transport key decider table.
 *
 * PARAMETERS:      Name            RW  Usage
 * 
 * RETURNS:
 *  uint8
 *
 ****************************************************************************/
PRIVATE uint8 u8GetTrspKeyDeciderFreeIndex()
{
    uint8 u8FreeIndex = 0;
    while(s_TrspKeyDeciderTable.psTrspKeyDeciderEntry[u8FreeIndex] && u8FreeIndex < BDB_TRSP_KEY_DECIDER_TABLE_SIZE)
    {
        u8FreeIndex++;
    }
    return u8FreeIndex;
}

/****************************************************************************
 *
 * NAME: u8GetTrspKeyDeciderIndex
 *
 * DESCRIPTION:
 *  Returns the index of the entry received as parameter
 *  If entry is not present, returns table size
 *
 * PARAMETERS:      Name                    RW  Usage
 *                  s_TrspKeyDeciderEntry       Searched entry
 * RETURNS:
 *  uint8
 *
 ****************************************************************************/
PRIVATE uint8 u8GetTrspKeyDeciderIndex(BDB_tsTrspKeyDeciderEntry s_TrspKeyDeciderEntry)
{
    uint8 u8Index;
    for(u8Index = 0; u8Index < BDB_TRSP_KEY_DECIDER_TABLE_SIZE; u8Index++)
    {
        if(s_TrspKeyDeciderTable.psTrspKeyDeciderEntry[u8Index] == s_TrspKeyDeciderEntry)
        {
            return u8Index;
        }
    }
    return BDB_TRSP_KEY_DECIDER_TABLE_SIZE;
}

/****************************************************************************
 *
 * NAME: doSendTransportKey
 *
 * DESCRIPTION:
 *  Returns true if the transport key is to be sent to the (re)joining device
 *  identified with the IEEE address u64DeviceAddress or false otherwise.
 *
 * PARAMETERS:      Name              RW  Usage
 *                  u64DeviceAddress      IEEE address of (re)joining device
 * RETURNS:
 *  uint8
 *
 ****************************************************************************/
PRIVATE bool_t doSendTransportKey(uint64 u64DeviceAddress)
{
    BDB_tsTrspKeyDeciderEntry s_TrspKeyDeciderEntry = (BDB_tsTrspKeyDeciderEntry)u64DeviceAddress;

    switch(s_TrspKeyDeciderTable.eTrspKeyDeciderPolicy)
    {
        case E_DECIDER_ALLOW_ALL:
            return TRUE;
        case E_DECIDER_WHITELIST:
            return (u8GetTrspKeyDeciderIndex(s_TrspKeyDeciderEntry) != BDB_TRSP_KEY_DECIDER_TABLE_SIZE);
        case E_DECIDER_BLACKLIST:
            return (u8GetTrspKeyDeciderIndex(s_TrspKeyDeciderEntry) == BDB_TRSP_KEY_DECIDER_TABLE_SIZE);
        default:
            return TRUE;
    }
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
