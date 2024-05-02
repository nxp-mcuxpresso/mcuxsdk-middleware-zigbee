/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier:    BSD-3-Clause
 */

#include "jendefs.h"
#include "zps_apl.h"
#include "zps_apl_af.h"
#include "app.h"

#include "serial_link_ctrl.h"
#include "serial_link_cmds_ctrl.h"
#include "app_common.h"
#include "zps_apl.h"
#include "zps_apl_aib.h"
#include "zps_apl_zdo.h"
#include <string.h>
#include "dbg.h"
#include "zcl_options.h"
#include "app_zcl_task.h"
#include "PDM.h"

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
PUBLIC tsDevicePersist sDevice;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
#define APP_PARENT_ADDRESS_TABLE_SIZE   32U

PUBLIC bool_t bDeviceInAPSKeyTable(uint64 u64LongAddress);
PUBLIC void APP_vHandleNwkStackEvents(ZPS_tsAfEvent *psStackEvent);
PUBLIC void APP_vGenCallback(uint8 u8Endpoint, ZPS_tsAfEvent *psStackEvent);

/********************************************************************************
  *
  * @fn PUBLIC void vApp_ProcessMessage
  *
  */
 /**
  *
  * @param u32Msg uint32
  *
  * @brief
  *
  * @return void
  *
  * @note
  *
  * imported description
 ********************************************************************************/
PUBLIC void vApp_ProcessMessage(uint32 u32Msg)
{
    ZPS_tsAfEvent sStackEvent;
    PDUM_thAPduInstance         myPDUM_thAPduInstance = PDUM_INVALID_HANDLE;

    if((SL_MSG_TYPE_NWK == *((uint8*)u32Msg)) || (SL_MSG_TYPE_ZDP_MSG == *((uint8*)u32Msg) ))
    {
        ZPS_tsAfZdpEvent sApsZdpEvent;
        uint8 u8MsgType =  *(uint8*)u32Msg;
        (void)ZBmemset(&sStackEvent, 0x00, sizeof(ZPS_tsAfEvent));
        (void)ZBmemset(&sApsZdpEvent, 0x00, sizeof(sApsZdpEvent));
        if(SL_MSG_TYPE_NWK == u8MsgType)
        {
            vSL_HandleNwkEvent((uint8*)u32Msg, &sStackEvent, &sApsZdpEvent);
        }
        else
        {
            vSL_HandleZDPMsgEvent((uint8*)u32Msg, &myPDUM_thAPduInstance, &sStackEvent, &sApsZdpEvent);
        }

        /* Handle Nwk stack events */
        APP_vHandleNwkStackEvents(&sStackEvent);
        if(SL_MSG_TYPE_ZDP_MSG == u8MsgType)
        {
            /* Delete APDU allocated */
            if (myPDUM_thAPduInstance != PDUM_INVALID_HANDLE)
            {
                (void)PDUM_eAPduFreeAPduInstance(myPDUM_thAPduInstance);
            }
        }
    }
    else if(*((uint8*)u32Msg) == SL_MSG_TYPE_APDU)
    {
        (void)ZBmemset(&sStackEvent, 0x00, sizeof(ZPS_tsAfEvent));
        PDUM_thAPduInstance tempPDUM_thAPduInstance = PDUM_INVALID_HANDLE;
        /* Process the serial buffer */
        vSL_HandleApduEvent((uint8*)u32Msg, &tempPDUM_thAPduInstance, &sStackEvent);

        /* APS data indication, ACK, and confirm available for App for diagnostic pro stack */
        if((sStackEvent.eType == (ZPS_teAfEventType)ZPS_EVENT_APS_DATA_ACK) || (sStackEvent.eType == (ZPS_teAfEventType)ZPS_EVENT_APS_DATA_INDICATION))
        {
            //vHandleNwkDataEvents(&sStackEvent);
        }

        /* Delete APDU before returning */
        if (tempPDUM_thAPduInstance != PDUM_INVALID_HANDLE)
        {
            (void)PDUM_eAPduFreeAPduInstance(tempPDUM_thAPduInstance);
        }
    }
    else if(*((uint8*)u32Msg) == (uint32)APP_MSG_TYPE_USER_CMD)
    {
        //vPREPARSE_SubstHook(((uint8*)u32Msg + 1));
        DBG_vPrintf(TRUE, "Got APP_MSG_TYPE_USER_CMD\n");
    }
    else if(*((uint8*)u32Msg) == (uint32)APP_MSG_TYPE_USER_CMD_TX)
    {
        //vProcess_UserCmdTx();
        DBG_vPrintf(TRUE, "Got APP_MSG_TYPE_USER_CMD_TX\n");
    }
    else if(*((uint8*)u32Msg) == (uint32)APP_MSG_TYPE_PERMIT_JOIN_CHANGED)
    {
        //APP_vHandlePermitJoinChangedHook();
    }
    else if(*((uint8*)u32Msg) == SL_MSG_TYPE_NODE_PARENT)
    {
        uint16 u16ShortAddress, u16ID;
        uint64 u64LongAddress, u64ParentAddress;
        uint8 u8Status;
        vSL_HandleNodeParentIndication((uint8*)u32Msg, &u16ShortAddress, &u64LongAddress, &u64ParentAddress, &u8Status, &u16ID);
        DBG_vPrintf((bool_t)1, "Update Msg short 0x%04x 0x%016llx parent 0x%016llx, Status %d ID %d\n",
                u16ShortAddress, u64LongAddress, u64ParentAddress, u8Status, u16ID );
    }
}

/********************************************************************************
  *
  * @fn PUBLIC void vApp_ProcessMessageVal
  *
  */
 /**
  *
  * @param u32Msg uint32
  *
  * @brief process message received as value, not pointer
  *
  * @return PUBLIC void
  *
  * @note
  *
 ********************************************************************************/
PUBLIC void vApp_ProcessMessageVal(uint32 u32Msg)
{
    PDUM_thAPduInstance         myPDUM_thAPduInstance;

    (void)ZBmemset(&myPDUM_thAPduInstance, 0, sizeof(myPDUM_thAPduInstance));

    if(u32Msg == SL_MSG_TYPE_JN_RESETED)
    {
        DBG_vPrintf((bool_t)TRUE, "SL_MSG_TYPE_JN_RESETED\n");
        vWaitForJNReady(JN_READY_TIME_MS);
#ifdef ENABLE_UART_ACK_FROM_HOST
        (void)vConfigureCoprocessorUartAckTimeout(JN_UART_ACK_TIMEOUT);
#endif
    }
    else if(u32Msg == SL_MSG_STACK_STARTED_RUNNING)
    {
        DBG_vPrintf((bool_t)TRUE, "ZdoStartStack In Running State (JN has restarted)\n");
        //vApp_ReProvisionJN();
    }
    else if(u32Msg == SL_MSG_TYPE_EXCEPTION)
    {
        /* When an exception occurs, the JN is supposed to reset itself after printed the stack dump
         * - If not for an unknown reason, the next message the LPC is going to send will not have no response from the JN
         *   Therefore, after 4 attempts, the LPC is going to automatically reset the JN which will place it in the correct state
         * - If so, the JN will be in the correct state and the next LPC message will be processed as expected
         * We still need to change the SL timeout value to be extended, to allow the JN to send the stack dump.
         * The vSL_SetStandardResponsePeriod is called upon the reception of E_SL_MSG_EVENT_RESET
         */

        vSL_SetLongResponsePeriod();
    }
}

/********************************************************************************
  *
  * @fn PUBLIC bool_t bDeviceInAPSKeyTable
  *
  */
 /**
  *
  * @param u64LongAddress uint64
  *
  * @brief Check device is in APS key table
  *
  * @return bool
  *
  * @note
  *
  * imported description
 ********************************************************************************/
PUBLIC bool_t bDeviceInAPSKeyTable(uint64 u64LongAddress)
{
    uint16 u16Index = 0U;
    ZPS_tsAplApsKeyDescriptorEntry sEntry;
    uint64 u64IeeeAddr;

    while(E_ZCL_SUCCESS == eAPP_GetKeyTableEntry(u16Index++,&sEntry))
    {
        u64IeeeAddr = ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(),sEntry.u16ExtAddrLkup);
        if (u64IeeeAddr == u64LongAddress)
        {
            return (bool_t)TRUE;
        }

    }
    return (bool_t)FALSE;
}

/********************************************************************************
  *
  * @fn PUBLIC void APP_vVerifyFatalTest
  *
  */
 /**
  *
  * @param bIsOk bool_t
  * @param strErr const char *
  * @param u32ErrorLevel uint32
  * @param s16Line int16
  *
  * @brief Verify the expression is true or execute fatal error recovery
  *
  * @return None
  *
  * @note
  *
  * imported description
 ********************************************************************************/
PUBLIC void APP_vVerifyFatalTest (bool_t bIsOk, const char *strErr, uint32 u32ErrorLevel, int16 s16Line)
{
    if (bIsOk)
    {
        return;
    }
    DBG_vPrintf((bool_t)TRUE, "***** Fatal error     ******\n");
    DBG_vPrintf((bool_t)TRUE, "%s. Error Level %d, Line %d\n", strErr, u32ErrorLevel, s16Line);

    /* Running tests - stop and loop forever*/
    DBG_vPrintf((bool_t)TRUE, "***** Looping forever ******\n");
    APP_vNcpHostReset();
}

/********************************************************************************
  *
  * @fn PUBLIC void APP_vHandleNwkStackEvents
  *
  */
 /**
  *
  * @param psStackEvent ZPS_tsAfEvent *
  *
  * @brief
  *
  * @return void
  *
  * @note
  *
  * imported description
 ********************************************************************************/
PUBLIC void APP_vHandleNwkStackEvents(ZPS_tsAfEvent *psStackEvent)
{
    /* check ZPS Event Type */
    if(psStackEvent->eType == (ZPS_teAfEventType)(ZPS_EVENT_NWK_NEW_NODE_HAS_JOINED))
    {
    }
    else if(psStackEvent->eType == ZPS_EVENT_NWK_STARTED)
    {
        sDevice.eState = E_NETWORK_RUN;
        //App_PDM_vSaveRecord(&sDevicePDDesc,PDM_DEVICE_INFO);
    }
    else if(psStackEvent->eType == (ZPS_teAfEventType)(ZPS_EVENT_NWK_LEAVE_INDICATION))
    {
            DBG_vPrintf((bool_t)1, "LEAVE_INDICATION Addr %016llx Rejoin %02x\n",
                    psStackEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr,
                    psStackEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin);
            if (psStackEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr == 0U)
            {
                /* this device was asked to leave */
                if ((psStackEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin != 0U))
                {
                    DBG_vPrintf((bool_t)1, "We were told to leave with rejoin\n");
                }
                else
                {
                    DBG_vPrintf((bool_t)1, "We were told to leave WITHOUT rejoin Clear Data\n");
                }
            }
            else
            {
                /* some other device has left */
                if ((psStackEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin != 0U))
                {
                    DBG_vPrintf((bool_t)1, "%016llx Leaving with rejoin\n", psStackEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr);
                    /* do nothing there are coming back */
                }
                else
                {
                    DBG_vPrintf((bool_t)1, "%016llx are Leaving WITHOUT rejoin\n",
                            psStackEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr);

                    DBG_vPrintf((bool_t)1, "Call APP_eCleanUpZclState\n");
                    //(void)APP_eCleanUpZclState(psStackEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr);
                }
            }
    }
    else if(psStackEvent->eType == (ZPS_teAfEventType)(ZPS_EVENT_NWK_LEAVE_CONFIRM))
    {
        DBG_vPrintf((bool_t)TRUE, "Nwk Evt: LEAVE_CONFIRM status %02x Addr %016llx Rejoin %d\r\n",
                psStackEvent->uEvent.sNwkLeaveConfirmEvent.eStatus,
                psStackEvent->uEvent.sNwkLeaveConfirmEvent.u64ExtAddr,
                psStackEvent->uEvent.sNwkLeaveConfirmEvent.bRejoin );
        if (psStackEvent->uEvent.sNwkLeaveConfirmEvent.u64ExtAddr == 0U)
        {
            /* leave confirm for this device */
            if (psStackEvent->uEvent.sNwkLeaveConfirmEvent.bRejoin == (bool_t)TRUE)
            {
                DBG_vPrintf((bool_t)1, "Self Leave with Rejoin\n");
            }
            else
            {
                DBG_vPrintf((bool_t)1, "Self Leave WITHOUT Rejoin - Clear Data\n");
            }
        }
        else
        {
            /* leave comfirm for some other device */
            if (psStackEvent->uEvent.sNwkLeaveConfirmEvent.bRejoin == (bool_t)TRUE)
            {
                DBG_vPrintf((bool_t)1, "We asked %016llx to Leave with Rejoin\n", psStackEvent->uEvent.sNwkLeaveConfirmEvent.u64ExtAddr);
            }
            else
            {
                DBG_vPrintf((bool_t)1, "We asked %016llx to Leave WITHOUT Rejoin\n", psStackEvent->uEvent.sNwkLeaveConfirmEvent.u64ExtAddr);
            }
        }
    }
    else if (psStackEvent->eType == (ZPS_teAfEventType)(ZPS_EVENT_ERROR))
    {
        /* no default action required */
    }
    else
    {
        /* No action required */
    }
    /* Invoke the BDB to handle the event */
    APP_vGenCallback(COORDINATOR_ZDO_ENDPOINT, psStackEvent);
}

