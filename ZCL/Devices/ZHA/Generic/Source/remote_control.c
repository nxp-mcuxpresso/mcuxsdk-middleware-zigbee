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
 * MODULE:             Remote Control
 *
 * COMPONENT:          remote_control.c
 *
 * DESCRIPTION:        ZigBee Remote Control profile functions
 *
 *****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <string.h>

#include "zps_apl.h"
#include "zcl_heap.h"
#include "zcl.h"
#include "zcl_options.h"
#include "Basic.h"
#include "Identify.h"
#include "PowerConfiguration.h"
#include "DeviceTemperatureConfiguration.h"
#include "Alarms.h"
#include "OnOff.h"
#include "LevelControl.h"
#include "Groups.h"
#include "Scenes.h"
#include "ColourControl.h"
#include "OOSC.h"
#include "TemperatureMeasurement.h"
#include "IlluminanceLevelSensing.h"
#include "IlluminanceMeasurement.h"
#include "remote_control.h"
#ifdef CLD_OTA
#include "OTA.h"
#endif
#include "ZclTime.h"
#ifdef CLD_POLL_CONTROL
    #include "PollControl.h"
#endif
#ifdef CLD_DOOR_LOCK
    #include "DoorLock.h"
#endif
#ifdef CLD_THERMOSTAT
    #include "Thermostat.h"
#endif
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: eHA_RegisterConfigurationToolEndPoint
 *
 * DESCRIPTION:
 * Registers a Configuration Tool device with the ZCL layer
 *
 * PARAMETERS:  Name                            Usage
 *              u8EndPointIdentifier            Endpoint being registered
 *              cbCallBack                      Pointer to endpoint callback
 *              psDeviceInfo                    Pointer to struct containing
 *                                              data for endpoint
 *
 * RETURNS:
 * teZCL_Status
 *
 ****************************************************************************/
PUBLIC teZCL_Status eHA_RegisterRemoteControlEndPoint(uint8 u8EndPointIdentifier,
                                              tfpZCL_ZCLCallBackFunction cbCallBack,
                                              tsHA_RemoteControlDevice *psDeviceInfo)
{

    /* Fill in end point details */
    psDeviceInfo->sEndPoint.u8EndPointNumber = u8EndPointIdentifier;
    psDeviceInfo->sEndPoint.u16ManufacturerCode = ZCL_MANUFACTURER_CODE;
    psDeviceInfo->sEndPoint.u16ProfileEnum = HA_PROFILE_ID;
    psDeviceInfo->sEndPoint.bIsManufacturerSpecificProfile = FALSE;
    psDeviceInfo->sEndPoint.u16NumberOfClusters = sizeof(tsHA_RemoteControlDeviceClusterInstances) / sizeof(tsZCL_ClusterInstance);
    psDeviceInfo->sEndPoint.psClusterInstance = (tsZCL_ClusterInstance*)&psDeviceInfo->sClusterInstance;
    psDeviceInfo->sEndPoint.bDisableDefaultResponse = ZCL_DISABLE_DEFAULT_RESPONSES;
    psDeviceInfo->sEndPoint.pCallBackFunctions = cbCallBack;

    /* Mandatory server clusters */
#if (defined CLD_BASIC) && (defined BASIC_SERVER)
    /* Create an instance of a Basic cluster as a server */
    if(eCLD_BasicCreateBasic(&psDeviceInfo->sClusterInstance.sBasicServer,
                          TRUE,
                          &sCLD_Basic,
                          &psDeviceInfo->sBasicServerCluster,
                          &au8BasicClusterAttributeControlBits[0]) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_IDENTIFY) && (defined IDENTIFY_SERVER)
    /* Create an instance of an Identify cluster as a server */
    if(eCLD_IdentifyCreateIdentify(&psDeviceInfo->sClusterInstance.sIdentifyServer,
                          TRUE,
                          &sCLD_Identify,
                          &psDeviceInfo->sIdentifyServerCluster,
                          &au8IdentifyAttributeControlBits[0],
                          &psDeviceInfo->sIdentifyServerCustomDataStructure) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

    /* Optional server clusters */
#if (defined CLD_POWER_CONFIGURATION) && (defined POWER_CONFIGURATION_SERVER)
    /* Create an instance of a Power Configuration cluster as a server */
    if(eCLD_PowerConfigurationCreatePowerConfiguration(&psDeviceInfo->sClusterInstance.sPowerConfigurationServer,
                          TRUE,
                          &sCLD_PowerConfiguration,
                          &psDeviceInfo->sPowerConfigServerCluster,
                          &au8PowerConfigurationAttributeControlBits[0]) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    }
#endif

#if (defined CLD_DEVICE_TEMPERATURE_CONFIGURATION) && (defined DEVICE_TEMPERATURE_CONFIGURATION_SERVER)
    /* Create an instance of a Device Temperature Configuration cluster as a server */
    if(eCLD_DeviceTemperatureConfigurationCreateDeviceTemperatureConfiguration(&psDeviceInfo->sClusterInstance.sDeviceTemperatureConfigurationServer,
                          TRUE,
                          &sCLD_DeviceTemperatureConfiguration,
                          &psDeviceInfo->sDeviceTemperatureConfigurationServerCluster,
                          &au8DeviceTempConfigClusterAttributeControlBits[0]) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_ALARMS) && (defined ALARMS_SERVER)
    /* Create an instance of an Alarms cluster as a server */
    if(eCLD_AlarmsCreateAlarms(&psDeviceInfo->sClusterInstance.sAlarmsServer,
                          TRUE,
                          &sCLD_Alarms,
                          &psDeviceInfo->sAlarmsServerCluster,
                          &au8AlarmsAttributeControlBits[0],
                          &psDeviceInfo->sAlarmsServerCustomDataStructure) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_POLL_CONTROL) && (defined POLL_CONTROL_SERVER)
    /* Create an instance of a Poll Control cluster as a server */
    if(eCLD_PollControlCreatePollControl(
                          &psDeviceInfo->sClusterInstance.sPollControlServer,
                          TRUE,
                          &sCLD_PollControl,
                          &psDeviceInfo->sPollControlServerCluster,
                          &au8PollControlAttributeControlBits[0],
                          &psDeviceInfo->sPollControlServerCustomDataStructure) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

    /* Mandatory client clusters */
#if (defined CLD_BASIC) && (defined BASIC_CLIENT)
    /* Create an instance of a Basic cluster as a client */
    if(eCLD_BasicCreateBasic(&psDeviceInfo->sClusterInstance.sBasicClient,
                          FALSE,
                          &sCLD_Basic,
                          &psDeviceInfo->sBasicClientCluster,
                          &au8BasicClusterAttributeControlBits[0]) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_IDENTIFY) && (defined IDENTIFY_CLIENT)
    /* Create an instance of an Identify cluster as a client */
    if(eCLD_IdentifyCreateIdentify(&psDeviceInfo->sClusterInstance.sIdentifyClient,
                          FALSE,
                          &sCLD_Identify,
                          &psDeviceInfo->sIdentifyClientCluster,
                          &au8IdentifyAttributeControlBits[0],
                          &psDeviceInfo->sIdentifyClientCustomDataStructure) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_ONOFF) && (defined ONOFF_CLIENT)
    /* Create an instance of an On/Off cluster as a client */
    if(eCLD_OnOffCreateOnOff(&psDeviceInfo->sClusterInstance.sOnOffClient,
                          FALSE,
                          &sCLD_OnOffClient,
                          &psDeviceInfo->sOnOffClientCluster,
                          &au8OnOffClientAttributeControlBits[0],
                          NULL) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_LEVEL_CONTROL) && (defined LEVEL_CONTROL_CLIENT)
    /* Create an instance of a Level Control cluster as a client */
    if(eCLD_LevelControlCreateLevelControl(&psDeviceInfo->sClusterInstance.sLevelControlClient,
                          FALSE,
                          &sCLD_LevelControlClient,
                          &psDeviceInfo->sLevelControlClientCluster,
                          &au8LevelControlClientAttributeControlBits[0],
                          &psDeviceInfo->sLevelControlClientCustomDataStructure) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_GROUPS) && (defined GROUPS_CLIENT)
    /* Create an instance of a Groups cluster as a client */
    if(eCLD_GroupsCreateGroups(&psDeviceInfo->sClusterInstance.sGroupsClient,
                          FALSE,
                          &sCLD_Groups,
                          &psDeviceInfo->sGroupsClientCluster,
                          &au8GroupsAttributeControlBits[0],
                          &psDeviceInfo->sGroupsClientCustomDataStructure,
                          &psDeviceInfo->sEndPoint) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_SCENES) && (defined SCENES_CLIENT)
    /* Create an instance of a Scenes cluster as a client */
    if(eCLD_ScenesCreateScenes(&psDeviceInfo->sClusterInstance.sScenesClient,
                          FALSE,
                          &sCLD_Scenes,
                          &psDeviceInfo->sScenesClientCluster,
                          &au8ScenesAttributeControlBits[0],
                          &psDeviceInfo->sScenesClientCustomDataStructure,
                          &psDeviceInfo->sEndPoint) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

    /* Optional client clusters */
    
#if (defined CLD_POLL_CONTROL) && (defined POLL_CONTROL_CLIENT)
    /* Create an instance of a Poll Control cluster as a client */
    if(eCLD_PollControlCreatePollControl(
                          &psDeviceInfo->sClusterInstance.sPollControlClient,
                          FALSE,
                          &sCLD_PollControl,
                          &psDeviceInfo->sPollControlClientCluster,
                          &au8PollControlAttributeControlBits[0],
                          &psDeviceInfo->sPollControlClientCustomDataStructure) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_COLOUR_CONTROL) && (defined COLOUR_CONTROL_CLIENT)
    /* Create an instance of a Colour Control cluster as a client */
    if(eCLD_ColourControlCreateColourControl(
                          &psDeviceInfo->sClusterInstance.sColourControlClient,
                          FALSE,
                          &sCLD_ColourControl,
                          &psDeviceInfo->sColourControlClientCluster,
                          &au8ColourControlAttributeControlBits[0],
                          &psDeviceInfo->sColourControlClientCustomDataStructure) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_OOSC) && (defined OOSC_CLIENT)
    /* Create an instance of an On/Off Switch Configuration cluster as a client */
    if(eCLD_OOSCCreateOnOffSwitchConfig(&psDeviceInfo->sClusterInstance.sOOSCClient,
                          FALSE,
                          &sCLD_OOSC,
                          &psDeviceInfo->sOOSCClientCluster,
                          &au8OOSCAttributeControlBits[0]) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_TEMPERATURE_MEASUREMENT) && (defined TEMPERATURE_MEASUREMENT_CLIENT)
    /* Create an instance of a Temperature Measurement cluster as a client */
    if(eCLD_TemperatureMeasurementCreateTemperatureMeasurement(
                          &psDeviceInfo->sClusterInstance.sTemperatureMeasurementClient,
                          FALSE,
                          &sCLD_TemperatureMeasurement,
                          &psDeviceInfo->sTemperatureMeasurementClientCluster,
                          &au8TemperatureMeasurementAttributeControlBits[0]) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_ILLUMINANCE_LEVEL_SENSING) && (defined ILLUMINANCE_LEVEL_SENSING_CLIENT)
    /* Create an instance of an Illuminance Level Sensing  cluster as a client */
    if(eCLD_IlluminanceLevelSensingCreateIlluminanceLevelSensing(
                          &psDeviceInfo->sClusterInstance.sIlluminanceLevelSensingClient,
                          FALSE,
                          &sCLD_IlluminanceLevelSensing,
                          &psDeviceInfo->sIlluminanceLevelSensingClientCluster,
                          &au8IlluminanceLevelSensingAttributeControlBits[0]) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_ILLUMINANCE_MEASUREMENT) && (defined ILLUMINANCE_MEASUREMENT_CLIENT)
    /* Create an instance of an Illuminance Measurement cluster as a client */
    if(eCLD_IlluminanceMeasurementCreateIlluminanceMeasurement(
                          &psDeviceInfo->sClusterInstance.sIlluminanceMeasurementClient,
                          FALSE,
                          &sCLD_IlluminanceMeasurement,
                          &psDeviceInfo->sIlluminanceMeasurementClientCluster,
                          &au8IlluminanceMeasurementAttributeControlBits[0]) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_DOOR_LOCK) && (defined DOOR_LOCK_CLIENT)
    /* Create an instance of a Door Lock cluster as a client */
    if(eCLD_DoorLockCreateDoorLock(&psDeviceInfo->sClusterInstance.sDoorLockClient,
                          FALSE,
                          &sCLD_DoorLock,
                          &psDeviceInfo->sDoorLockClientCluster,
                          &au8DoorLockAttributeControlBits[0]) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#if (defined CLD_THERMOSTAT) && (defined THERMOSTAT_CLIENT)
    /* Create an instance of a Thermostat cluster as a server */
    if(eCLD_ThermostatCreateThermostat(&psDeviceInfo->sClusterInstance.sThermostatClient,
                          FALSE,
                          &sCLD_Thermostat,
                          &psDeviceInfo->sThermostatClientCluster,
                          &au8ThermostatAttributeControlBits[0],
                          &psDeviceInfo->sThermostatClientCustomDataStructure) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    } 
#endif

#ifdef CLD_OTA
    #ifdef OTA_CLIENT
   if (eOTA_Create(
       &psDeviceInfo->sClusterInstance.sOTAClient,
       FALSE,  /* client */
       &sCLD_OTA,
       &psDeviceInfo->sCLD_OTA,  /* cluster definition */
       u8EndPointIdentifier,
       NULL,
       &psDeviceInfo->sCLD_OTA_CustomDataStruct
       )!= E_ZCL_SUCCESS)

    {
        // Need to convert from cluster specific to ZCL return type so we lose the extra information of the return code
        return E_ZCL_FAIL;
    }
    #endif
    #ifdef OTA_SERVER
   if (eOTA_Create(
       &psDeviceInfo->sClusterInstance.sOTAServer,
       TRUE,  /* Server */
       &sCLD_OTA,
       &psDeviceInfo->sCLD_ServerOTA,  /* cluster definition */
       u8EndPointIdentifier,
       NULL,
       &psDeviceInfo->sCLD_OTA_ServerCustomDataStruct
       )!= E_ZCL_SUCCESS)

    {
        // Need to convert from cluster specific to ZCL return type so we lose the extra information of the return code
        return E_ZCL_FAIL;
    }
    #endif    
#endif
#if (defined CLD_TIME && defined TIME_CLIENT)
    if (eCLD_TimeCreateTime(
                    &psDeviceInfo->sClusterInstance.sTimeClient,
                    FALSE,
                    &sCLD_Time,
                    &psDeviceInfo->sTimeClientCluster,
                    &au8TimeClusterAttributeControlBits[0]) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    }
#endif
#if (defined CLD_ELECTRICAL_MEASUREMENT && defined ELECTRICAL_MEASUREMENT_SERVER)
    if (eCLD_ElectricalMeasurementCreateElectricalMeasurement(
            &psDeviceInfo->sClusterInstance.sElectricalMeasurementServer,
            TRUE,
            &sCLD_ElectricalMeasurement,
            &psDeviceInfo->sCLD_ElectricalMeasurement,
            au8ElectricalMeasurementAttributeControlBits)!= E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    }

#endif
    return eZCL_Register(&psDeviceInfo->sEndPoint);
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

