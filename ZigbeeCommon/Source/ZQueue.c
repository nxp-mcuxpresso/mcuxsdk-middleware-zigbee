/****************************************************************************
 *
 * Copyright 2020, 2023-2024 NXP
 *
 * NXP Confidential.
 *
 * This software is owned or controlled by NXP and may only be used strictly
 * in accordance with the applicable license terms.
 * By expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms.
 * If you do not agree to be bound by the applicable license terms,
 * then you may not retain, install, activate or otherwise use the software.
 *
 *
 ****************************************************************************/


/****************************************************************************
 *
 * MODULE:    ZQueue.c
 *
 * DESCRIPTION:
 *
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "MicroSpecific.h"
#include "ZQueue.h"
#include "dbg.h"
#include "pwrm.h"
#include "zb_platform.h"

#if ZIGBEE_USE_FRAMEWORK
    #if IS_MCXW_SERIES_OR_RW_SERIES
        #include "fsl_component_messaging.h"
    #else
        #include "Messaging.h"
    #endif

    #include "FunctionLib.h"
    #include "fsl_os_abstraction.h"
    /*! The MemManager Pool Id used by the Zigbee layer */
    #ifndef gZbPoolId_d
        #define gZbPoolId_d 0
    #endif
    /* Default memory allocator */
    #ifndef ZB_BufferAlloc
        #if IS_MCXW_SERIES_OR_RW_SERIES
            #define ZB_BufferAlloc(numBytes)   MSG_Alloc(numBytes)
        #else
            #define ZB_BufferAlloc(numBytes)   MEM_BufferAllocWithId(numBytes, gZbPoolId_d, (void*)__get_LR())
        #endif
    #endif
#else
#include <stdlib.h>
#define ZB_BufferAlloc(numBytes)    malloc(numBytes)
#endif
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifdef DEBUG_ZQUEUE
#define TRACE_ZQUEUE    TRUE
#else
#define TRACE_ZQUEUE    FALSE
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

PUBLIC void ZQ_vQueueCreate ( tszQueue*       psQueueHandle,
                              const uint32    u32QueueLength,
                              const uint32    u32ItemSize,
                              uint8*          pu8StartQueue )
{
        psQueueHandle->pfCallback = NULL;
#if ZIGBEE_USE_FRAMEWORK
#if IS_MCXW_SERIES_OR_RW_SERIES
        LIST_Init(&psQueueHandle->list,u32QueueLength);
#else
        ListInit(&psQueueHandle->list,u32QueueLength);
#endif
        psQueueHandle->u32ItemSize =  u32ItemSize;
#else
        if (pu8StartQueue == NULL)
        {
            psQueueHandle->pvHead = malloc(u32ItemSize * u32QueueLength);
        }
        else
        {
            psQueueHandle->pvHead =  pu8StartQueue;
        }
        psQueueHandle->u32ItemSize =  u32ItemSize;
        psQueueHandle->u32Length =  u32QueueLength;
        psQueueHandle->pvWriteTo =  psQueueHandle->pvHead;
        psQueueHandle->u32MessageWaiting =  0;
        psQueueHandle->pvReadFrom =  psQueueHandle->pvHead;
        DBG_vPrintf(TRACE_ZQUEUE, "ZQ: Initialised a queue: Handle=%08x Length=%d ItemSize=%d\n", (uint32)psQueueHandle, u32QueueLength, u32ItemSize);
#endif

}

PUBLIC bool_t ZQ_bQueueSend ( void*          pvQueueHandle,
                              const void*    pvItemToQueue )
{
#if ZIGBEE_USE_FRAMEWORK
    OSA_InterruptDisable();
    tszQueue *psQueueHandle = (tszQueue *)pvQueueHandle;
    /* Put a message in a queue. */

#if IS_MCXW_SERIES_OR_RW_SERIES
    if(LIST_GetAvailableSize(&psQueueHandle->list) || (0 == psQueueHandle->list.max))
#else
    if(ListGetAvailable(&psQueueHandle->list) || (0 == psQueueHandle->list.max))
#endif
    {
        void* pMsg = ZB_BufferAlloc(psQueueHandle->u32ItemSize);
        if(pMsg)
        {
            FLib_MemCpy(pMsg, (void*)pvItemToQueue, psQueueHandle->u32ItemSize);

            /* Put a message in a queue. */
#if IS_MCXW_SERIES_OR_RW_SERIES
            MSG_QueueAddTail(&psQueueHandle->list, pMsg);
#else
            MSG_Queue(&psQueueHandle->list, pMsg);
#endif
            /* Increase power manager activity count */
            PWRM_eStartActivity();
            if (psQueueHandle->pfCallback)
            {
                psQueueHandle->pfCallback();
            }
            OSA_InterruptEnable();
            return TRUE;
        }
    }
    OSA_InterruptEnable();
    return FALSE;
#else
    uint32 u32Store;
    tszQueue *psQueueHandle = (tszQueue *)pvQueueHandle;
    bool bReturn = FALSE;
    MICRO_DISABLE_AND_SAVE_INTERRUPTS(u32Store);
    if(psQueueHandle->u32MessageWaiting >= psQueueHandle->u32Length)
    {
        DBG_vPrintf(TRACE_ZQUEUE, "ZQ: Queue overflow: Handle=%08x\n", (uint32)pvQueueHandle);
    }
    else
    {
        if( psQueueHandle->pvWriteTo >= (psQueueHandle->pvHead+(psQueueHandle->u32Length*psQueueHandle->u32ItemSize)))
        {
             psQueueHandle->pvWriteTo = psQueueHandle->pvHead;
        }
        ( void ) memcpy( psQueueHandle->pvWriteTo, pvItemToQueue, psQueueHandle->u32ItemSize );
        psQueueHandle->u32MessageWaiting++;
        psQueueHandle->pvWriteTo += psQueueHandle->u32ItemSize;
        /* Increase power manager activity count */
        PWRM_eStartActivity();
        if (psQueueHandle->pfCallback)
        {
            psQueueHandle->pfCallback();
        }
        bReturn = TRUE;
    }
    MICRO_RESTORE_INTERRUPTS(u32Store);
    return bReturn;
#endif
}

PUBLIC bool_t ZQ_bQueueReceive ( void*    pvQueueHandle,
                                 void*    pvItemFromQueue )
{
#if ZIGBEE_USE_FRAMEWORK
    OSA_InterruptDisable();
    tszQueue *psQueueHandle = (tszQueue *)pvQueueHandle;

#if IS_MCXW_SERIES_OR_RW_SERIES
    if( MSG_QueueGetHead(&psQueueHandle->list))
#else
    if( MSG_Pending(&psQueueHandle->list))
#endif
    {
#if IS_MCXW_SERIES_OR_RW_SERIES
        void* pMsg = MSG_QueueRemoveHead(&psQueueHandle->list);
#else
        void* pMsg = MSG_DeQueue(&psQueueHandle->list);
#endif
        FLib_MemCpy( pvItemFromQueue, pMsg, psQueueHandle->u32ItemSize );
        MSG_Free(pMsg);
        /* Decrease power manager activity count */
        PWRM_eFinishActivity();
    }
    else
    {
        OSA_InterruptEnable();
        return FALSE;
    }
    OSA_InterruptEnable();
    return TRUE;

#else
    uint32 u32Store;
    tszQueue *psQueueHandle = (tszQueue *)pvQueueHandle;
    bool bReturn = FALSE;
    MICRO_DISABLE_AND_SAVE_INTERRUPTS(u32Store);
    if( psQueueHandle->u32MessageWaiting >  0)
    {
        if( psQueueHandle->pvReadFrom >= (psQueueHandle->pvHead+(psQueueHandle->u32Length*psQueueHandle->u32ItemSize) ))
        {
            psQueueHandle->pvReadFrom = psQueueHandle->pvHead;
        }
        ( void ) memcpy( pvItemFromQueue, psQueueHandle->pvReadFrom, psQueueHandle->u32ItemSize );
        psQueueHandle->pvReadFrom += psQueueHandle->u32ItemSize;
        psQueueHandle->u32MessageWaiting--;

        /* Decrease power manager activity count */
        PWRM_eFinishActivity();
        bReturn = TRUE;
    }
    else
    {
        bReturn =  FALSE;
    }
    MICRO_RESTORE_INTERRUPTS(u32Store);
    return bReturn;
#endif
}

PUBLIC bool_t ZQ_bQueueIsEmpty ( void*    pvQueueHandle )
{
    tszQueue *psQueueHandle = (tszQueue *)pvQueueHandle;
#if ZIGBEE_USE_FRAMEWORK
    if (psQueueHandle->list.size == 0) return (TRUE);
    else return (FALSE);
#else
    uint32 u32Store;

    bool bReturn = FALSE;
    MICRO_DISABLE_AND_SAVE_INTERRUPTS(u32Store);
    if (psQueueHandle->u32MessageWaiting == 0)
    {
        bReturn = TRUE;
    }
    else
    {
        bReturn = FALSE;
    }
    MICRO_RESTORE_INTERRUPTS(u32Store);
    return (bReturn);
#endif
}


PUBLIC uint32 ZQ_u32QueueGetQueueSize ( void*    pvQueueHandle )
{
    tszQueue *psQueueHandle = (tszQueue *)pvQueueHandle;
#if ZIGBEE_USE_FRAMEWORK
    return (uint32)psQueueHandle->list.max;
#else
    return psQueueHandle->u32Length;
#endif
}

PUBLIC uint32 ZQ_u32QueueGetQueueMessageWaiting ( void*    pvQueueHandle )
{
    tszQueue *psQueueHandle = (tszQueue *)pvQueueHandle;
#if ZIGBEE_USE_FRAMEWORK
    return (uint32)psQueueHandle->list.size;
#else
    return psQueueHandle->u32MessageWaiting;
#endif
}

PUBLIC void* ZQ_pvGetFirstElementOnQueue ( void* pvQueueHandle )
{

#if ZIGBEE_USE_FRAMEWORK
#if IS_MCXW_SERIES_OR_RW_SERIES
    return LIST_GetHead(&((tszQueue *)pvQueueHandle)->list);
#else
    return ListGetHeadMsg(&((tszQueue *)pvQueueHandle)->list);
#endif
#else
    uint32 u32Store;
    void* pvReadFrom = NULL;
    MICRO_DISABLE_AND_SAVE_INTERRUPTS(u32Store);
    pvReadFrom = ( (tszQueue *) pvQueueHandle)->pvReadFrom;
    if (( (tszQueue *) pvQueueHandle )->pvReadFrom >=  (( (tszQueue *) pvQueueHandle )->pvHead +
        ( ( (tszQueue *) pvQueueHandle )->u32Length * ( (tszQueue *) pvQueueHandle )->u32ItemSize) ))
    {
        pvReadFrom = (( (tszQueue *) pvQueueHandle)->pvHead);
    }
    MICRO_RESTORE_INTERRUPTS(u32Store);
    return (pvReadFrom);
#endif
}

PUBLIC void* ZQ_pvGetNextElementOnQueue ( void* pvQueueHandle, void* pvMsg )
{
    if( pvQueueHandle == NULL || pvMsg == NULL )
        return NULL;

#if ZIGBEE_USE_FRAMEWORK
    void* pvReadFrom = NULL;
#if IS_MCXW_SERIES_OR_RW_SERIES
    pvReadFrom = LIST_GetNext(pvMsg);
#else
    pvReadFrom = ListGetNextMsg(pvMsg);
#endif
    return pvReadFrom;
#else
    uint32 u32Store;
    MICRO_DISABLE_AND_SAVE_INTERRUPTS(u32Store);
    if(pvMsg < (( (tszQueue *) pvQueueHandle)->pvHead +
               ( ( (tszQueue *) pvQueueHandle)->u32Length * ( (tszQueue *) pvQueueHandle)->u32ItemSize) ))
    {
        pvMsg += ( (tszQueue *) pvQueueHandle)->u32ItemSize;
    }
    else
    {
        pvMsg = NULL;
    }
    MICRO_RESTORE_INTERRUPTS(u32Store);
    return pvMsg;
#endif
}
#ifdef NCP_HOST
PUBLIC void ZQ_bQueueFlush (void *pvQueueHandle)
{
    uint32 u32Store;
    tszQueue *psQueueHandle = (tszQueue *)pvQueueHandle;

    MICRO_DISABLE_AND_SAVE_INTERRUPTS(u32Store);

    psQueueHandle->pvWriteTo =  psQueueHandle->pvHead;
    psQueueHandle->u32MessageWaiting =  0;
    psQueueHandle->pvReadFrom =  psQueueHandle->pvHead;

    MICRO_RESTORE_INTERRUPTS(u32Store);
}
#endif
PUBLIC void ZQ_vRegisterCallback(void *pvQueueHandle, ZQueue_pfCallback pfCallback)
{
    tszQueue *psQueueHandle = (tszQueue *)pvQueueHandle;
    psQueueHandle->pfCallback = pfCallback;
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
