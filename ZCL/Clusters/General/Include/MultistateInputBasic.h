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
 * MODULE:             Multistate Input Basic Cluster
 *
 * COMPONENT:          MultistateInputBasic.h
 *
 * DESCRIPTION:        Header for Multistate Input Basic Cluster
 *
 *****************************************************************************/

#ifndef MULTISTATE_INPUT_BASIC_H
#define MULTISTATE_INPUT_BASIC_H

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef CLD_MULTISTATE_INPUT_BASIC_ATTR_NUMBER_OF_STATES
    #define CLD_MULTISTATE_INPUT_BASIC_ATTR_NUMBER_OF_STATES                 6
#endif  
/****************************************************************************/
/*             Multistate Input Basic Cluster - Optional Attributes         */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the multistate input basic cluster.                        */
/****************************************************************************/

/* Enable the optional Stack Version attribute*/
//#define   CLD_MULTISTATE_INPUT_BASIC_ATTR_DESCRIPTION

/* Enable the optional Reliability attribute */
//#define   CLD_MULTISTATE_INPUT_BASIC_ATTR_RELIABILITY

/* Enable the optional Application type attribute */
//#define   CLD_MULTISTATE_INPUT_BASIC_ATTR_APPLICATION_TYPE

/* Enable the optional Attribute Reporting Status attribute */
//#define   CLD_MULTISTATE_INPUT_BASIC_ATTR_ATTRIBUTE_REPORTING_STATUS

/* End of optional attributes */


/* Cluster ID's */
#define GENERAL_CLUSTER_ID_MULTISTATE_INPUT_BASIC                            0x0012

/* Status Flags - bit definitions and bit masks */
#define MULTISTATE_INPUT_BASIC_STATUS_FLAGS_IN_ALARM                              0
#define MULTISTATE_INPUT_BASIC_STATUS_FLAGS_FAULT                                 1
#define MULTISTATE_INPUT_BASIC_STATUS_FLAGS_OVERRIDDEN                            2
#define MULTISTATE_INPUT_BASIC_STATUS_FLAGS_OUT_OF_SERVICE                        3

#define MULTISTATE_INPUT_BASIC_STATUS_FLAGS_IN_ALARM_MASK                          (1 << MULTISTATE_INPUT_BASIC_STATUS_FLAGS_IN_ALARM)
#define MULTISTATE_INPUT_BASIC_STATUS_FLAGS_FAULT_MASK                             (1 << MULTISTATE_INPUT_BASIC_STATUS_FLAGS_FAULT)
#define MULTISTATE_INPUT_BASIC_STATUS_FLAGS_OVERRIDDEN_MASK                        (1 << MULTISTATE_INPUT_BASIC_STATUS_FLAGS_OVERRIDDEN)
#define MULTISTATE_INPUT_BASIC_STATUS_FLAGS_OUT_OF_SERVICE_MASK                    (1 << MULTISTATE_INPUT_BASIC_STATUS_FLAGS_OUT_OF_SERVICE)

#ifndef CLD_MULTISTATE_INPUT_BASIC_CLUSTER_REVISION
    #define CLD_MULTISTATE_INPUT_BASIC_CLUSTER_REVISION                         1
#endif 

#ifndef CLD_MULTISTATE_INPUT_BASIC_FEATURE_MAP
    #define CLD_MULTISTATE_INPUT_BASIC_FEATURE_MAP                              0
#endif 

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/* Command codes */


typedef enum 
{
    /* Multistate Input (Basic) Device Information attribute set attribute ID's (3.14.7.1.2) */
    E_CLD_MULTISTATE_INPUT_BASIC_ATTR_ID_DESCRIPTION                    =                0x001C, /*Optional */
    E_CLD_MULTISTATE_INPUT_BASIC_ATTR_ID_NUMBER_OF_STATES               =                0x004A, /*Mandatory */
    E_CLD_MULTISTATE_INPUT_BASIC_ATTR_ID_OUT_OF_SERVICE                 =                0x0051, /*Mandatory */
    E_CLD_MULTISTATE_INPUT_BASIC_ATTR_ID_PRESENT_VALUE                  =                0x0055, /* Mandatory */
    E_CLD_MULTISTATE_INPUT_BASIC_ATTR_ID_RELIABILITY                    =                0x0067, /*Optional */
    E_CLD_MULTISTATE_INPUT_BASIC_ATTR_ID_STATUS_FLAGS                   =                0x006F, /* Mandatory */
    E_CLD_MULTISTATE_INPUT_BASIC_ATTR_ID_APPLICATION_TYPE               =                0x0100, /*Optional */
} teCLD_MultistateInputBasicCluster_AttrID;

/* Reliability attribute */
typedef enum 
{ 
    E_CLD_MULTISTATE_INPUT_BASIC_RELIABILITY_NO_FAULT_DETECTED         =                0x0000,
    E_CLD_MULTISTATE_INPUT_BASIC_RELIABILITY_NO_SENSOR,
    E_CLD_MULTISTATE_INPUT_BASIC_RELIABILITY_OVER_RANGE,
    E_CLD_MULTISTATE_INPUT_BASIC_RELIABILITY_UNDER_RANGE,
    E_CLD_MULTISTATE_INPUT_BASIC_RELIABILITY_OPEN_LOOP,
    E_CLD_MULTISTATE_INPUT_BASIC_RELIABILITY_SHORTED_LOOP,
    E_CLD_MULTISTATE_INPUT_BASIC_RELIABILITY_NO_OUTPUT,
    E_CLD_MULTISTATE_INPUT_BASIC_RELIABILITY_UNRELIABLE_OTHER,
    E_CLD_MULTISTATE_INPUT_BASIC_RELIABILITY_PROCESS_ERROR,
    E_CLD_MULTISTATE_INPUT_BASIC_RELIABILITY_MULTISTATE_FAULT,
    E_CLD_MULTISTATE_INPUT_BASIC_RELIABILITY_CONFIGURATION_ERROR
 }teCLD_MultistateInputBasic_Reliability;


/* Multistate Input Basic Cluster */
#ifdef MULTISTATE_INPUT_BASIC_SERVER
typedef struct
{
#ifdef CLD_MULTISTATE_INPUT_BASIC_ATTR_DESCRIPTION                
    tsZCL_CharacterString       sDescription;
    uint8                       au8Description[16];
#endif

    zuint16                     u16NumberOfStates;
    
    zbool                       bOutOfService;

    zuint16                     u16PresentValue;

#ifdef CLD_MULTISTATE_INPUT_BASIC_ATTR_RELIABILITY
    zenum8                      u8Reliability;
#endif

    zbmap8                      u8StatusFlags;

#ifdef CLD_MULTISTATE_INPUT_BASIC_ATTR_APPLICATION_TYPE
    zuint32                     u32ApplicationType;
#endif

#ifdef CLD_MULTISTATE_INPUT_BASIC_ATTR_ATTRIBUTE_REPORTING_STATUS
    zenum8                      u8AttributeReportingStatus;
#endif
    zbmap32                     u32FeatureMap;
    
    zuint16                     u16ClusterRevision;
} tsCLD_MultistateInputBasic;
#endif

#ifdef MULTISTATE_INPUT_BASIC_CLIENT
typedef struct
{
   zbmap32                     u32FeatureMap;
  
   zuint16                     u16ClusterRevision;
} tsCLD_MultistateInputBasicClient;
#endif
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_MultistateInputBasicCreateMultistateInputBasic(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits);
                            
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
#ifdef MULTISTATE_INPUT_BASIC_SERVER
    extern tsZCL_ClusterDefinition sCLD_MultistateInputBasic;
    extern tsZCL_AttributeDefinition asCLD_MultistateInputBasicClusterAttributeDefinitions[];
    extern uint8 au8MultistateInputBasicAttributeControlBits[];
#endif

#ifdef MULTISTATE_INPUT_BASIC_CLIENT
    extern tsZCL_ClusterDefinition sCLD_MultistateInputBasicClient;
    extern tsZCL_AttributeDefinition asCLD_MultistateInputBasicClientClusterAttributeDefinitions[];
    extern uint8 au8MultistateInputBasicClientAttributeControlBits[];
#endif    
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* BASIC_H */
