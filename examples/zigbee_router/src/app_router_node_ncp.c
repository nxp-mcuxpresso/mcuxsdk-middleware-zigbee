/*
* Copyright 2019, 2023-2024 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#include "app.h"
#include "bdb_api.h"
#include "app_common_ncp.h"
#include "PDM.h"

#include "PDM_IDs.h"
#include "app_zcl_task.h"
#include "app_reporting.h"

#include "app_buttons.h"
#include "dbg.h"
#include "app_main.h"
#include "MicroSpecific.h"
#include "app_router_node.h"
#include "zigbee_config.h"
#include "app_main.h"
#ifndef NCP_HOST
#ifdef LNT_MODE_APP
#include "app_crypto.h"
#endif
#ifdef KPI_MODE_APP
#include "tp2.h"
#endif
#endif
#include "serial_link_ctrl.h"
#include "serial_link_cmds_ctrl.h"
/* Needed for calloc/malloc */
#include <stdlib.h>

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#define GREEN_POWER_ENDPOINT                   242
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef TRACE_APP
    #define TRACE_APP   FALSE
#endif

#ifndef TRACE_APP_INIT
#define TRACE_APP_INIT FALSE
#endif

#ifndef TRACE_APP_EVENT
    #define TRACE_APP_EVENT   FALSE
#endif

#ifndef TRACE_APP_BDB
    #define TRACE_APP_BDB     FALSE
#endif

#define ASSOCIATION_ATTEMPTS   (5)

#ifndef MAX_HOST_TO_COPROCESSOR_COMMS_ATTEMPS
#define MAX_HOST_TO_COPROCESSOR_COMMS_ATTEMPS (5)
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
static void APP_StartFindAndBind(void);
static void vAppHandleAfEvent( BDB_tsZpsAfEvent *psZpsAfEvent);
static void vAppHandleZdoEvents( BDB_tsZpsAfEvent *psZpsAfEvent);
static void APP_vBdbInit(void);

PUBLIC void vApp_ProcessMessage(uintptr_t uiMsg);
PUBLIC void vApp_ProcessMessageVal(uintptr_t uiMsg);
PUBLIC void APP_vHandleNwkStackEvents(ZPS_tsAfEvent *psStackEvent);

static void vPrintAPSTable(void);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
tsNcpDeviceDesc sNcpDeviceDesc = {FACTORY_NEW, E_STARTUP, ZPS_ZDO_DEVICE_ROUTER};
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
uint32_t u32OldFrameCtr;
extern bool_t bZCLQueueFull;

const uint8_t gUseRtos_c = 1;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME:        pvZCL_HeapAlloc
 *
 * DESCRIPTION:
 * Allocates a block of memory from the heap.
 *
 * RETURNS:
 * Pointer to block, or NULL if the heap didn't have enough space. If block
 * was already assigned, returns original value and doesn't take anything
 * from heap.
 *
 * NOTES:
 * If buffer has already been allocated, it is not cleared. If it is a fresh
 * allocation, it is cleared on request.
 *
 ****************************************************************************/
void* pvZCL_HeapAlloc(void *pvPointer, uint32 u32BytesNeeded, bool_t bClear)
{
        if (bClear)
        {
                return calloc(1, u32BytesNeeded);
        }
        else
        {
                return malloc(u32BytesNeeded);
        }

}

extern void zps_vNwkSecClearMatSet(void *psNwk);

/****************************************************************************
 *
 * NAME: APP_vInitialiseRouter
 *
 * DESCRIPTION:
 * Initialises the application related functions
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void APP_vInitialiseRouter(void)
{
    uint16 u16ByteRead;
    PDM_teStatus eStatusReportReload;

    sNcpDeviceDesc.eNodeState = E_STARTUP;
    sNcpDeviceDesc.eState = FACTORY_NEW;

    sNcpDeviceDesc.u8DeviceType = ZPS_ZDO_DEVICE_ROUTER;
    PDM_eReadDataFromRecord(PDM_ID_APP_ROUTER,
                            &sNcpDeviceDesc,
                            sizeof(tsNcpDeviceDesc),
                            &u16ByteRead);

    /* Restore any report data that is previously saved to flash */
    eStatusReportReload = eRestoreReports();

    ZPS_eAplAibSetApsUseInstallCode(BDB_JOIN_USES_INSTALL_CODE_KEY);

    /* Initialise ZCL */
    APP_ZCL_vInitialise();

    /* Initialise other software modules
     * HERE
     */
    APP_eZbModuleInitialise();
    APP_vBdbInit();

    DBG_vPrintf(TRACE_APP, "Start Up State %d On Network %d\r\n",
            sNcpDeviceDesc.eNodeState,
            sBDB.sAttrib.bbdbNodeIsOnANetwork);

    /*Load the reports from the PDM or the default ones depending on the PDM load record status*/
    if(eStatusReportReload !=PDM_E_STATUS_OK )
    {
        /*Load Defaults if the data was not correct*/
        vLoadDefaultConfigForReportable();
    }
    /*Make the reportable attributes */
    vMakeSupportedAttributesReportable();

    vPrintAPSTable();
#ifndef NCP_HOST
#ifdef LNT_MODE_APP
#include "lnt_init.h"
    lnt_init();
#endif
#endif
}

/****************************************************************************
 *
 * NAME: APP_vBdbCallback
 *
 * DESCRIPTION:
 * Callback from the BDB
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void APP_vBdbCallback(BDB_tsBdbEvent *psBdbEvent)
{
    switch(psBdbEvent->eEventType)
    {
        case BDB_EVENT_NONE:
            break;

        case BDB_EVENT_ZPSAF:                // Use with BDB_tsZpsAfEvent
            vAppHandleAfEvent(&psBdbEvent->uEventData.sZpsAfEvent);
            break;

        case BDB_EVENT_INIT_SUCCESS:
            DBG_vPrintf(TRACE_APP,"APP: BDB_EVENT_INIT_SUCCESS\r\n");
            if (sNcpDeviceDesc.eNodeState == E_STARTUP)
            {
#ifndef KPI_MODE_APP
            BDB_teStatus eStatus = BDB_eNsStartNwkSteering();
            DBG_vPrintf(TRACE_APP, "BDB Try Steering status %d\r\n",eStatus);
#endif
            }
            else
            {
                DBG_vPrintf(TRACE_APP, "BDB Init go Running");
                sNcpDeviceDesc.eNodeState = E_RUNNING;
                PDM_eSaveRecordData(PDM_ID_APP_ROUTER,&sNcpDeviceDesc,sizeof(tsNcpDeviceDesc));
            }
            break;

        case BDB_EVENT_NO_NETWORK:
            DBG_vPrintf(TRACE_APP,"APP: BDB No Networks\r\n");
#ifndef NCP_HOST
#ifdef LNT_MODE_APP
        #define LNT_TIME 1
            extern uint8 u8LntTimerTick;
            ZTIMER_eStart(u8LntTimerTick, ZTIMER_TIME_SEC((LNT_TIME + (uint8)CRYPTO_u32RandomGet(0, LNT_TIME))));
            break;
        #undef LNT_TIME
#endif
#endif
        case BDB_EVENT_OOB_FAIL:
        case BDB_EVENT_REJOIN_FAILURE:
#ifndef KPI_MODE_APP
            if (BDB_bIsBaseIdle())
            {
                BDB_teStatus eStatus = BDB_eNsStartNwkSteering();
                DBG_vPrintf(TRACE_APP, "BDB Try Steering status %d\r\n",eStatus);
            }
#endif
            break;

        case BDB_EVENT_NWK_STEERING_SUCCESS:
            DBG_vPrintf(TRACE_APP,"APP: NwkSteering Success \r\n");
#ifndef NCP_HOST
#ifdef LNT_MODE_APP
            int lnt_BleAdvDisabled();
            void lnt_EnableBleAdv();
            void BleApp_Start();
            /* start BLE adv after joining ZB network */
            if (lnt_BleAdvDisabled())
            {
                lnt_EnableBleAdv();
                BleApp_Start();
            }
#endif
#endif
        case BDB_EVENT_OOB_FORM_SUCCESS:
        case BDB_EVENT_OOB_JOIN_SUCCESS:
        case BDB_EVENT_REJOIN_SUCCESS:
            DBG_vPrintf(TRACE_APP,"APP: BDB_EVENT_REJOIN_SUCCESS \r\n");
#ifndef NCP_HOST
#ifdef KPI_MODE_APP
        case BDB_EVENT_NWK_FORMATION_SUCCESS:
            DBG_vPrintf(TRACE_APP, "APP-BDB: NwkFormation Success, Addr %04x, Channel %d\r\n",
                        ZPS_u16AplZdoGetNwkAddr(), ZPS_u8AplZdoGetRadioChannel());
#endif
#endif
            sNcpDeviceDesc.eNodeState = E_RUNNING;
            PDM_eSaveRecordData(PDM_ID_APP_ROUTER,&sNcpDeviceDesc,sizeof(tsNcpDeviceDesc));
            break;

        default:
            break;
    }
}

/****************************************************************************
 *
 * NAME: APP_taskRouter
 *
 * DESCRIPTION:
 * Task that handles application related functions
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void APP_taskRouter(void)
{
    APP_tsEvent sAppEvent;
    sAppEvent.eType = APP_E_EVENT_NONE;

    if (ZQ_bQueueReceive(&APP_msgAppEvents, &sAppEvent) == TRUE)
    {
        DBG_vPrintf(TRACE_APP, "ZPR: App event %d, NodeState=%d\r\n", sAppEvent.eType, sNcpDeviceDesc.eNodeState);

        if(sAppEvent.eType == APP_E_EVENT_SERIAL_FIND_BIND_START)
        {
            APP_StartFindAndBind();
        }
    }
}

/****************************************************************************
 *
 * NAME: APP_StartFindAndBind
 *
 * DESCRIPTION:
 * Starts Find and Bind procedure
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
static void APP_StartFindAndBind(void)
{
    BDB_teStatus eStatus;

    DBG_vPrintf(TRACE_APP_EVENT, "APP_EVENT: Network steering and F&B as Target\r\n");
    eStatus = BDB_eNsStartNwkSteering();
    if (eStatus != 0)
    {
        DBG_vPrintf(TRACE_APP_EVENT, "APP_EVENT: Network Steering %02x\r\n", eStatus);
    }
    eStatus = BDB_eFbTriggerAsTarget(APP_u8GetDeviceEndpoint());
    if (eStatus != 0 && eStatus != 9)
    {
        DBG_vPrintf(TRACE_APP_EVENT, "APP_EVENT: Find and Bind Failed %02x\r\n", eStatus);
    }
}


/****************************************************************************
 *
 * NAME: vAppHandleAfEvent
 *
 * DESCRIPTION:
 * Application handler for stack events
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
static void vAppHandleAfEvent( BDB_tsZpsAfEvent *psZpsAfEvent)
{
#ifndef NCP_HOST
#ifdef KPI_MODE_APP
    if ((psZpsAfEvent->u8EndPoint == ROUTER_DEVICEUNDERTEST_REQ_ENDPOINT) ||
        (psZpsAfEvent->u8EndPoint == ROUTER_DEVICEUNDERTEST_RSP_2_ENDPOINT) ||
        (psZpsAfEvent->u8EndPoint == ROUTER_DEVICEUNDERTEST_RSP_ENDPOINT))
    {
        return APP_msgTp2Events(&psZpsAfEvent->sStackEvent);
    }
    if (psZpsAfEvent->u8EndPoint == ROUTER_DEVDIAGNOSTICS_ENDPOINT)
    {
        if ((psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_DATA_INDICATION) ||
            (psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_INTERPAN_DATA_INDICATION))
        {
            APP_ZCL_vEventHandler(&psZpsAfEvent->sStackEvent);
        }
    }
    else
#endif
#endif
    if (psZpsAfEvent->u8EndPoint == APP_u8GetDeviceEndpoint())
    {
//        DBG_vPrintf(TRACE_APP, "Pass to ZCL\r\n");
        if ((psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_DATA_INDICATION) ||
            (psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_INTERPAN_DATA_INDICATION))
        {
            APP_ZCL_vEventHandler( &psZpsAfEvent->sStackEvent);
        }
    }
    else if (psZpsAfEvent->u8EndPoint == 0)
    {
        vAppHandleZdoEvents( psZpsAfEvent);
    }
    else if ((psZpsAfEvent->u8EndPoint == GREEN_POWER_ENDPOINT) ||  (psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_ZGP_DATA_CONFIRM))
    {
        if ((psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_DATA_INDICATION) ||
            (psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_ZGP_DATA_INDICATION)||
            (psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_ZGP_DATA_CONFIRM))
        {

            APP_ZCL_vEventHandler( &psZpsAfEvent->sStackEvent);
        }
    }
    /* Ensure Freeing of Apdus */
    if (psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_DATA_INDICATION)
    {
        PDUM_eAPduFreeAPduInstance(psZpsAfEvent->sStackEvent.uEvent.sApsDataIndEvent.hAPduInst);
    }
    else if ( psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_INTERPAN_DATA_INDICATION )
    {
        PDUM_eAPduFreeAPduInstance(psZpsAfEvent->sStackEvent.uEvent.sApsInterPanDataIndEvent.hAPduInst);
    }

}

/****************************************************************************
 *
 * NAME: vAppHandleZdoEvents
 *
 * DESCRIPTION:
 * Application handler for stack events for end point 0 (ZDO)
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
static void vAppHandleZdoEvents( BDB_tsZpsAfEvent *psZpsAfEvent)
{
    ZPS_tsAfEvent *psAfEvent = &(psZpsAfEvent->sStackEvent);

    switch(psAfEvent->eType)
    {
        case ZPS_EVENT_APS_DATA_INDICATION:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Data Indication Status %02x from %04x Src Ep Dst %d Ep %d Profile %04x Cluster %04x\r\n",
                    psAfEvent->uEvent.sApsDataIndEvent.eStatus,
                    psAfEvent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr,
                    psAfEvent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                    psAfEvent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                    psAfEvent->uEvent.sApsDataIndEvent.u16ProfileId,
                    psAfEvent->uEvent.sApsDataIndEvent.u16ClusterId);

            break;

        case ZPS_EVENT_APS_DATA_CONFIRM:
            break;

        case ZPS_EVENT_APS_DATA_ACK:
            break;
            break;

        case ZPS_EVENT_NWK_JOINED_AS_ROUTER:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Joined Network Addr %04x Rejoin %d\r\n",
                    psAfEvent->uEvent.sNwkJoinedEvent.u16Addr,
                    psAfEvent->uEvent.sNwkJoinedEvent.bRejoin);

            /* Save to PDM */
            sNcpDeviceDesc.eNodeState = E_RUNNING;
            PDM_eSaveRecordData(PDM_ID_APP_ROUTER,&sNcpDeviceDesc,sizeof(tsNcpDeviceDesc));

            ZPS_eAplAibSetApsUseExtendedPanId( ZPS_u64NwkNibGetEpid(ZPS_pvAplZdoGetNwkHandle()) );
            break;
        case ZPS_EVENT_NWK_FAILED_TO_JOIN:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Failed To Join %02x Rejoin %d\r\n",
                    psAfEvent->uEvent.sNwkJoinFailedEvent.u8Status,
                    psAfEvent->uEvent.sNwkJoinFailedEvent.bRejoin);
            break;

        case ZPS_EVENT_NWK_NEW_NODE_HAS_JOINED:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: New Node %04x Has Joined\r\n",
                    psAfEvent->uEvent.sNwkJoinIndicationEvent.u16NwkAddr);
            break;

        case ZPS_EVENT_NWK_DISCOVERY_COMPLETE:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Discovery Complete %02x\r\n",
                    psAfEvent->uEvent.sNwkDiscoveryEvent.eStatus);
            break;

        case ZPS_EVENT_NWK_LEAVE_INDICATION:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Leave Indication %016llx Rejoin %d\r\n",
                    psAfEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr,
                    psAfEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin);
            if ( (psAfEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr == 0UL) &&
                 (psAfEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin == 0) )
            {
                /* We sare asked to Leave without rejoin */
                DBG_vPrintf(TRACE_APP, "LEAVE IND -> For Us No Rejoin\r\n");
#ifndef KPI_MODE_APP
                APP_vFactoryResetRecords();
                MICRO_DISABLE_INTERRUPTS();
#endif
            }
            break;

        case ZPS_EVENT_NWK_LEAVE_CONFIRM:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Leave Confirm status %02x Addr %016llx\r\n",
                    psAfEvent->uEvent.sNwkLeaveConfirmEvent.eStatus,
                    psAfEvent->uEvent.sNwkLeaveConfirmEvent.u64ExtAddr);
            if ((psAfEvent->uEvent.sNwkLeaveConfirmEvent.eStatus == ZPS_E_SUCCESS) &&
                (psAfEvent->uEvent.sNwkLeaveConfirmEvent.u64ExtAddr == 0UL))
            {
                DBG_vPrintf(TRACE_APP, "Leave -> Reset Data Structures\r\n");
#ifndef NCP_HOST
#if defined(KPI_MODE_APP)
                sBDB.sAttrib.bbdbNodeIsOnANetwork = FALSE;
                sNcpDeviceDesc.eNodeState = E_STARTUP;
                PDM_eSaveRecordData(PDM_ID_APP_ROUTER,&sNcpDeviceDesc,sizeof(tsNcpDeviceDesc));
#else
                APP_vFactoryResetRecords();
                MICRO_DISABLE_INTERRUPTS();
#if !defined(K32W1480_SERIES) && !defined(MCXW716A_SERIES) && !defined(MCXW716C_SERIES) && !defined(RW612_SERIES)
                vMMAC_Disable();
#endif
                RESET_SystemReset();
#endif
#endif
            }
            break;

        case ZPS_EVENT_NWK_STATUS_INDICATION:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Network status Indication %02x addr %04x\r\n",
                    psAfEvent->uEvent.sNwkStatusIndicationEvent.u8Status,
                    psAfEvent->uEvent.sNwkStatusIndicationEvent.u16NwkAddr);
            break;

        case ZPS_EVENT_NWK_ROUTE_DISCOVERY_CONFIRM:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Discovery Confirm\r\n");
            break;

        case ZPS_EVENT_NWK_ED_SCAN:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Energy Detect Scan %02x\r\n",
                    psAfEvent->uEvent.sNwkEdScanConfirmEvent.u8Status);
            break;
        case ZPS_EVENT_ZDO_BIND:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Zdo Bind event\r\n");
            break;

        case ZPS_EVENT_ZDO_UNBIND:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Zdo Unbiind Event\r\n");
            break;

        case ZPS_EVENT_ZDO_LINK_KEY:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Zdo Link Key Event Type %d Addr %016llx\r\n",
                        psAfEvent->uEvent.sZdoLinkKeyEvent.u8KeyType,
                        psAfEvent->uEvent.sZdoLinkKeyEvent.u64IeeeLinkAddr);
            break;

        case ZPS_EVENT_BIND_REQUEST_SERVER:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Bind Request Server Event\r\n");
            break;

        case ZPS_EVENT_ERROR:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: AF Error Event %d\r\n", psAfEvent->uEvent.sAfErrorEvent.eError);
            break;

        case ZPS_EVENT_TC_STATUS:
            DBG_vPrintf(TRACE_APP, "APP-ZDO: Trust Center Status %02x\r\n", psAfEvent->uEvent.sApsTcEvent.u8Status);
            break;

        case ZPS_EVENT_NWK_DUTYCYCLE_INDICATION:
            DBG_vPrintf(TRUE, "Nwk Duty Cycle Indication, mode = %d\n", psAfEvent->uEvent.sNwkDutyCycleIndicationEvent.u8Mode);

            break;

        default:
            break;
    }
}


/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/


/****************************************************************************
 *
 * NAME: APP_vFactoryResetRecords
 *
 * DESCRIPTION:
 * Resets persisted data structures to factory new state
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void APP_vFactoryResetRecords(void)
{
    /* clear out the stack */
    ZPS_vDefaultStack();
    ZPS_eAplAibSetApsUseExtendedPanId(0);
    ZPS_vSetKeys();
    ZPS_vSaveAllZpsRecords();

    DBG_vPrintf(TRUE, "Erasing PDM data on Coprocessor...");
    u8ErasePersistentData();

    /* wait for coprocessor to be ready */
    vSetJNState(JN_NOT_READY);
    vWaitForJNReady(JN_READY_TIME_MS);
    vSL_SetStandardResponsePeriod();

    /* handle NCP HOST side */
    PDM_vDeleteAllDataRecords();
    APP_vNcpHostReset();
}

/****************************************************************************
 *
 * NAME: APP_vBdbInit
 *
 * DESCRIPTION:
 * Function to initialize BDB attributes and message queue
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
static void APP_vBdbInit(void)
{
    BDB_tsInitArgs sInitArgs;

    sBDB.sAttrib.bbdbNodeIsOnANetwork = ((sNcpDeviceDesc.eNodeState >= E_RUNNING)?(TRUE):(FALSE));
    sInitArgs.hBdbEventsMsgQ = &APP_msgBdbEvents;
    BDB_vInit(&sInitArgs);
}

/****************************************************************************
 *
 * NAME: APP_eGetNodeDeviceType
 *
 * DESCRIPTION:
 * Returns the node device type
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
uint8 APP_eGetNodeDeviceType(void)
{
    return sNcpDeviceDesc.u8DeviceType;
}

/****************************************************************************
 *
 * NAME: vPrintAPSTable
 *
 * DESCRIPTION:
 * Prints the content of APS table
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vPrintAPSTable(void)
{
    uint8 i;
    uint8 j;

    uint16  u16SizeOfKeyDescriptorTable = ZPS_u16AplAibGetDeviceKeyPairTableSize();
    
    for ( i = 0 ; i < (u16SizeOfKeyDescriptorTable + 1) ; i++ )
    {
        ZPS_tsAplApsKeyDescriptorEntry tsAplApsKeyDescriptorEntry = ZPS_tsAplAibGetDeviceKeyPairTableEntry(i);

        DBG_vPrintf(TRUE, "%d MAC: %016llx Key: ", i, ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(),tsAplApsKeyDescriptorEntry.u16ExtAddrLkup));
       
        for(j=0; j<16;j++)
        {
            DBG_vPrintf(TRUE, "%02x ", tsAplApsKeyDescriptorEntry.au8LinkKey[j]);
        }
        DBG_vPrintf(TRUE, "\n");
    }
}


/****************************************************************************
 *
 * NAME: eGetNodeState
 *
 * DESCRIPTION:
 * Returns the node state
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
teNodeState eGetNodeState(void)
{
    return sNcpDeviceDesc.eNodeState;
}

/****************************************************************************
 *
 * NAME: APP_u8GetDeviceEndpoint
 *
 * DESCRIPTION:
 * Return the application endpoint
 *
 * PARAMETER: void
 *
 * RETURNS: uint8_t
 *
 ****************************************************************************/
uint8_t APP_u8GetDeviceEndpoint( void)
{
    return ROUTER_APPLICATION_ENDPOINT;
}

/********************************************************************************
  *
  * @fn PRIVATE void APP_vNcpMainTask
  *
  */
 /**
  *
  * @param p_arg void *
  *
  * @brief Main State Machine for local Node
  *
  * @return void
  *
  * @note
  *
  * imported description
 ********************************************************************************/
void APP_vNcpMainTask(void)
{
    bool pBT;
    uintptr_t uiMsg;

    /* handle serial messages  */
    (void)vSL_CheckAndHandleSerialMsg();

    /* handle zcl messages  */
    pBT = ZQ_bQueueReceive((void *)&zclQueueHandle, (void*)&uiMsg);

    if (bZCLQueueFull == (bool_t)TRUE)
    {
        DBG_vPrintf((bool_t)TRUE, "Reading ZCL Queue After Post Fail Main Task %d\n", pBT);
        bZCLQueueFull = (bool_t)FALSE;
    }

    if(pBT == TRUE)
    {
        APP_vProcessZCLMessage(uiMsg);
    }
    /* handle application messages */
    pBT = ZQ_bQueueReceive((void *)&appQueueHandle, (void*)&uiMsg);

    if(pBT == TRUE)
    {
            if ((uiMsg & QUEUE_MSG_BY_VALUE) == QUEUE_MSG_BY_VALUE )
            {
                uintptr_t uiLocalMsg =  uiMsg & (~QUEUE_MSG_BY_VALUE);
                vApp_ProcessMessageVal(uiLocalMsg);
            }
            else
            {
                vApp_ProcessMessage(uiMsg);
            }
    }
}

/********************************************************************************
  *
  * @fn PUBLIC void vApp_ProcessMessage
  *
  */
 /**
  *
  * @param uiMsg uintptr_t
  *
  * @brief
  *
  * @return void
  *
  * @note
  *
  * imported description
 ********************************************************************************/
PUBLIC void vApp_ProcessMessage(uintptr_t uiMsg)
{
    ZPS_tsAfEvent sStackEvent;
    PDUM_thAPduInstance         myPDUM_thAPduInstance = PDUM_INVALID_HANDLE;

    if((SL_MSG_TYPE_NWK == *((uint8*)uiMsg)) || (SL_MSG_TYPE_ZDP_MSG == *((uint8*)uiMsg) ))
    {
        ZPS_tsAfZdpEvent sApsZdpEvent;
        uint8 u8MsgType =  *(uint8*)uiMsg;
        (void)ZBmemset(&sStackEvent, 0x00, sizeof(ZPS_tsAfEvent));
        (void)ZBmemset(&sApsZdpEvent, 0x00, sizeof(sApsZdpEvent));
        if(SL_MSG_TYPE_NWK == u8MsgType)
        {
            vSL_HandleNwkEvent((uint8*)uiMsg, &sStackEvent, &sApsZdpEvent);
        }
        else
        {
            vSL_HandleZDPMsgEvent((uint8*)uiMsg, &myPDUM_thAPduInstance, &sStackEvent, &sApsZdpEvent);
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
    else if(*((uint8*)uiMsg) == SL_MSG_TYPE_APDU)
    {
        (void)ZBmemset(&sStackEvent, 0x00, sizeof(ZPS_tsAfEvent));
        PDUM_thAPduInstance tempPDUM_thAPduInstance = PDUM_INVALID_HANDLE;
        /* Process the serial buffer */
        vSL_HandleApduEvent((uint8*)uiMsg, &tempPDUM_thAPduInstance, &sStackEvent);

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
    else if(*((uint8*)uiMsg) == (uint32)APP_MSG_TYPE_USER_CMD)
    {
        //vPREPARSE_SubstHook(((uint8*)u32Msg + 1));
        DBG_vPrintf(TRUE, "Got APP_MSG_TYPE_USER_CMD\n");
    }
    else if(*((uint8*)uiMsg) == (uint32)APP_MSG_TYPE_USER_CMD_TX)
    {
        //vProcess_UserCmdTx();
        DBG_vPrintf(TRUE, "Got APP_MSG_TYPE_USER_CMD_TX\n");
    }
    else if(*((uint8*)uiMsg) == (uint32)APP_MSG_TYPE_PERMIT_JOIN_CHANGED)
    {
        //APP_vHandlePermitJoinChangedHook();
    }
    else if(*((uint8*)uiMsg) == SL_MSG_TYPE_NODE_PARENT)
    {
        uint16 u16ShortAddress, u16ID;
        uint64 u64LongAddress, u64ParentAddress;
        uint8 u8Status;
        vSL_HandleNodeParentIndication((uint8*)uiMsg, &u16ShortAddress, &u64LongAddress, &u64ParentAddress, &u8Status, &u16ID);
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
  * @param uiMsg uintptr_t
  *
  * @brief process message received as value, not pointer
  *
  * @return PUBLIC void
  *
  * @note
  *
 ********************************************************************************/
PUBLIC void vApp_ProcessMessageVal(uintptr_t uiMsg)
{
    PDUM_thAPduInstance         myPDUM_thAPduInstance;

    (void)ZBmemset(&myPDUM_thAPduInstance, 0, sizeof(myPDUM_thAPduInstance));

    if(uiMsg == SL_MSG_TYPE_JN_RESETED)
    {
        DBG_vPrintf((bool_t)TRUE, "SL_MSG_TYPE_JN_RESETED\n");
        vWaitForJNReady(JN_READY_TIME_MS);
#ifdef ENABLE_UART_ACK_FROM_HOST
        (void)vConfigureCoprocessorUartAckTimeout(JN_UART_ACK_TIMEOUT);
#endif
    }
    else if(uiMsg == SL_MSG_STACK_STARTED_RUNNING)
    {
        DBG_vPrintf((bool_t)TRUE, "ZdoStartStack In Running State (JN has restarted)\n");
        //vApp_ReProvisionJN();
    }
    else if(uiMsg == SL_MSG_TYPE_EXCEPTION)
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
  * @fn PUBLIC void APP_vProcessZCLMessage
  *
  */
 /**
  *
  * @param uiMsg uintptr_t
  *
  * @brief process ZCL messages
  *
  * @return void
  *
  * @note
  *
  * imported description
 ********************************************************************************/
PUBLIC void APP_vProcessZCLMessage(uintptr_t uiMsg)
{
    tsZCL_CallBackEvent  sCallBackEvent;
    ZPS_tsAfEvent sStackEvent;
#ifdef APP_ENABLE_PRINT_BUFFERS
    static uint16 u16appPrintBufferTimeInSecCount = 0U;
#endif

    if(*((uint8*)uiMsg) == (uint32)APP_MSG_TYPE_ZCL_TIMER)
    {

        sCallBackEvent.eEventType = E_ZCL_CBET_TIMER;
        vLockZCLMutex();
        //vZCL_SetUTCTimeWoSyncSet(APP_u32GetTime() - 1U);
        vZCL_EventHandler(&sCallBackEvent);
        vUnlockZCLMutex();
        //vApp_HandleZclTimerEvent();
#ifdef APP_ENABLE_PRINT_BUFFERS
        if(u16appPrintBufferTimeInSec>0){
            u16appPrintBufferTimeInSecCount++;
            if(u16appPrintBufferTimeInSecCount == u16appPrintBufferTimeInSec)
            {
                u16appPrintBufferTimeInSecCount = 0U;
                vSL_PrintRxBufferPool(TRUE);
                PDUM_vPrintAllocatedBuffers(TRUE);
            }
        }
#endif
    }
    else if(*((uint8*)uiMsg) == SL_MSG_TYPE_APDU)
    {
        PDUM_thAPduInstance myPDUM_thAPduInstance = PDUM_INVALID_HANDLE;
        uint8 u8EndPoint;

        /* clear StackEvent */
        (void)ZBmemset(&sStackEvent, 0x00, sizeof(ZPS_tsAfEvent));
        sCallBackEvent.eEventType = E_ZCL_CBET_ZIGBEE_EVENT;
        sCallBackEvent.pZPSevent = &sStackEvent;

        /* Process the serial buffer */
        vSL_HandleApduEvent((uint8*)uiMsg,&myPDUM_thAPduInstance, &sStackEvent);


        /* Before pushing the event to ZCL, construct the serial
         * payload as per stack event structure */
        if((sStackEvent.eType == (ZPS_teAfEventType)ZPS_EVENT_APS_DATA_INDICATION) ||
           (sStackEvent.eType == (ZPS_teAfEventType)ZPS_EVENT_APS_DATA_ACK))
        {
            bool bValidEp = (bool)TRUE;
            if (sStackEvent.eType == (ZPS_teAfEventType)ZPS_EVENT_APS_DATA_INDICATION)
            {
                u8EndPoint = sStackEvent.uEvent.sApsDataIndEvent.u8DstEndpoint;
                (void)ZPS_eAplAfGetEndpointState(sStackEvent.uEvent.sApsDataIndEvent.u8DstEndpoint, &bValidEp);
            }
            else /* sStackEvent.eType ==(ZPS_teAfEventType)ZPS_EVENT_APS_DATA_ACK */
            {
                u8EndPoint = sStackEvent.uEvent.sApsDataAckEvent.u8DstEndpoint;
                (void)ZPS_eAplAfGetEndpointState(sStackEvent.uEvent.sApsDataAckEvent.u8DstEndpoint, &bValidEp);
            }

            if (bValidEp)
            {
                if (u8EndPoint == COORDINATOR_ZDO_ENDPOINT) {
                    vAppHandleZdoEvents((BDB_tsZpsAfEvent*)&sStackEvent);
                } else {
                    vLockZCLMutex();
                    /* post to the ZCL as Event */
                    vZCL_EventHandler(&sCallBackEvent);
                    vUnlockZCLMutex();
                }
            }
            else
            {
                if (sStackEvent.eType ==(ZPS_teAfEventType)ZPS_EVENT_APS_DATA_INDICATION)
                {
                    DBG_vPrintf((bool_t)TRUE, "Data Indication for unsupported end point %d\n",
                          sStackEvent.uEvent.sApsDataIndEvent.u8DstEndpoint);
                }
                else
                {
                    DBG_vPrintf((bool_t)TRUE, "Data Ack for unspported end point %d\n",
                          sStackEvent.uEvent.sApsDataAckEvent.u8DstEndpoint);
                }
            }
         }
        if (myPDUM_thAPduInstance != PDUM_INVALID_HANDLE)
        {
            (void)PDUM_eAPduFreeAPduInstance(myPDUM_thAPduInstance);
        }
    }
    else if(*((uint8*)uiMsg) == SL_MSG_TYPE_INTERPAN)
    {
        PDUM_thAPduInstance myPDUM_thAPduInstance = PDUM_INVALID_HANDLE;
        /* clear StackEvent */
        (void)ZBmemset(&sStackEvent, 0x00, sizeof(ZPS_tsAfEvent));
        sCallBackEvent.eEventType = E_ZCL_CBET_ZIGBEE_EVENT;
        sCallBackEvent.pZPSevent = &sStackEvent;

        /* Process the serial buffer */
        vSL_HandleInterpanEvent((uint8*)uiMsg, &myPDUM_thAPduInstance, &sStackEvent);

        /* Before pushing the event to ZCL, construct the serial payload as per
         * stack event structure */
        if((sStackEvent.eType == (ZPS_teAfEventType)ZPS_EVENT_APS_INTERPAN_DATA_INDICATION)||
                (sStackEvent.eType == (ZPS_teAfEventType)ZPS_EVENT_APS_INTERPAN_DATA_CONFIRM))
        {
            /* Hook to handle raw GB spec inter pan messages and drop InterPan CBKE unless in correct state */
            //if ((bool_t)TRUE == bPassInterPanToZcl(&sStackEvent))
            {
                /* post to the ZCL as Event */
                vZCL_EventHandler(&sCallBackEvent);
            }
        }
        if (myPDUM_thAPduInstance != PDUM_INVALID_HANDLE)
        {
            (void)PDUM_eAPduFreeAPduInstance(myPDUM_thAPduInstance);
        }
    }
    else
    {
        /*nodefault action required */
    }

    //APP_vDirtyTimerHandler(uiMsg);
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
