/****************************************************************************
 *
 * Copyright 2020 NXP
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


/*****************************************************************************
 *
 * MODULE:             None Colour Remote
 *
 * COMPONENT:          none_colour_controller.h
 *
 * DESCRIPTION:        Header for ZigBee Light Link None Colour Remote profile functions
 *
 *****************************************************************************/

#ifndef NONE_COLOUR_CONTROLLER_H
#define NONE_COLOUR_CONTROLLER_H

#if defined __cplusplus
extern "C" {
#endif

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"
#include "Basic.h"
#ifdef CLD_ZLL_COMMISSION
    #include "zll_utility.h"
    #include "zll_commission.h"
#endif
#include "Identify.h"
#include "OnOff.h"
#include "LevelControl.h"
#include "Groups.h"
#ifdef CLD_OTA
#include "OTA.h"
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/* Holds cluster instances */
typedef struct 
{
    /*
     * All ZLL devices have following mandatory clusters
     */
    #if (defined CLD_BASIC) && (defined BASIC_SERVER)
        tsZCL_ClusterInstance sBasicServer;
    #endif

    #if (defined CLD_IDENTIFY) && (defined IDENTIFY_SERVER)
        tsZCL_ClusterInstance sIdentifyServer;
    #endif

    /* Other Mandatory server cluster */
    #if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_SERVER)
        tsZCL_ClusterInstance sZllCommissionServer;
    #endif

    /*
     *  Non Colour Remote device has 4 mandatory client clusters
     */
    #if (defined CLD_IDENTIFY) && (defined IDENTIFY_CLIENT)
        tsZCL_ClusterInstance sIdentifyClient;
    #endif

    #if (defined CLD_BASIC) && (defined BASIC_CLIENT)
        tsZCL_ClusterInstance sBasicClient;
    #endif
    
    #if (defined CLD_ONOFF) && (defined ONOFF_CLIENT)
        tsZCL_ClusterInstance sOnOffClient;
    #endif

    #if (defined CLD_LEVEL_CONTROL) && (defined LEVEL_CONTROL_CLIENT)
        tsZCL_ClusterInstance sLevelControlClient;
    #endif

    
    /* Recommended optional client clusters*/
    #if (defined CLD_GROUPS) && (defined GROUPS_CLIENT)
        tsZCL_ClusterInstance sGroupsClient;
    #endif
    
    /* OTA Cluster Instance */
    #if (defined CLD_OTA) && (defined OTA_CLIENT)
        tsZCL_ClusterInstance sOTAClient;
    #endif
    
    #if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_CLIENT)
        tsZCL_ClusterInstance sZllCommissionClient;
    #endif

} tsZLO_NonColourControllerDeviceClusterInstances __attribute__ ((aligned(4)));


/* Holds everything required to create an instance of a Non Color Remote */
typedef struct
{
    tsZCL_EndPointDefinition sEndPoint;

    /* Cluster instances */
    tsZLO_NonColourControllerDeviceClusterInstances sClusterInstance;

    #if (defined CLD_BASIC) && (defined BASIC_SERVER)
        /* Basic Cluster - Server */
        tsCLD_Basic sBasicServerCluster;
    #endif

    #if (defined CLD_IDENTIFY) && (defined IDENTIFY_SERVER)
        /* Identify Cluster - Server */
        tsCLD_Identify sIdentifyServerCluster;
        tsCLD_IdentifyCustomDataStructure sIdentifyServerCustomDataStructure;
    #endif

    #if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_SERVER)
        tsCLD_ZllCommission                         sZllCommissionServerCluster;
        tsCLD_ZllCommissionCustomDataStructure      sZllCommissionServerCustomDataStructure;
    #endif

        /* Mandatory client clusters */
    #if (defined CLD_IDENTIFY) && (defined IDENTIFY_CLIENT)
        /* Identify Cluster - Client */
        tsCLD_Identify sIdentifyClientCluster;
        tsCLD_IdentifyCustomDataStructure sIdentifyClientCustomDataStructure;
    #endif

    #if (defined CLD_BASIC) && (defined BASIC_CLIENT)
        /* Basic Cluster - Client */
        tsCLD_Basic sBasicClientCluster;
    #endif
    
    #if (defined CLD_ONOFF) && (defined ONOFF_CLIENT)
        /* On/Off Cluster - Client */
        tsCLD_OnOffClient sOnOffClientCluster;
    #endif

    #if (defined CLD_LEVEL_CONTROL) && (defined LEVEL_CONTROL_CLIENT)
        /* Level Control Cluster - Client */
        tsCLD_LevelControlClient sLevelControlClientCluster;
        tsCLD_LevelControlCustomDataStructure sLevelControlClientCustomDataStructure;
    #endif

    #if (defined CLD_GROUPS) && (defined GROUPS_CLIENT)
        /* Groups Cluster - Client */
        tsCLD_Groups sGroupsClientCluster;
        tsCLD_GroupsCustomDataStructure sGroupsClientCustomDataStructure;
    #endif
    
    #if (defined CLD_OTA) && (defined OTA_CLIENT)
        /* OTA cluster - Client */
        tsCLD_AS_Ota sCLD_OTA;
        tsOTA_Common sCLD_OTA_CustomDataStruct;
    #endif
    
    #if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_CLIENT)
        tsCLD_ZllCommission                         sZllCommissionClientCluster;
        tsCLD_ZllCommissionCustomDataStructure      sZllCommissionClientCustomDataStructure;
    #endif
    
} tsZLO_NonColourControllerDevice;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eZLO_RegisterNonColourControllerEndPoint(uint8 u8EndPointIdentifier,
                                              tfpZCL_ZCLCallBackFunction cbCallBack,
                                              tsZLO_NonColourControllerDevice *psDeviceInfo);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/


#if defined __cplusplus
}
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* NONE_COLOUR_CONTROLLER_H */
