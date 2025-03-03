# Device Structure

The following `tsZLO_OnOffBallastDevice` structure is the shared structure for an On/Off Ballast device:

```
typedef struct
{
    tsZCL_EndPointDefinition sEndPoint;
    /* Cluster instances */
    tsZLO_OnOffBallastDeviceClusterInstances sClusterInstance;
    /* Mandatory server clusters */
    #if (defined CLD_BASIC) && (defined BASIC_SERVER)
        /* Basic Cluster - Server */
        tsCLD_Basic sBasicServerCluster;
    #endif
    #if (defined CLD_IDENTIFY) && (defined IDENTIFY_SERVER)
        /* Identify Cluster - Server */
        tsCLD_Identify sIdentifyServerCluster;
        tsCLD_IdentifyCustomDataStructure
            sIdentifyServerCustomDataStructure;
    #endif
    #if (defined CLD_ONOFF) && (defined ONOFF_SERVER)
    /* On/Off Cluster - Server */
      tsCLD_OnOff sOnOffServerCluster;
      tsCLD_OnOffCustomDataStructure sOnOffServerCustomDataStructure;
    #endif
    #if (defined CLD_SCENES) && (defined SCENES_SERVER)
    /* Scenes Cluster - Server */
      tsCLD_Scenes sScenesServerCluster;
      tsCLD_ScenesCustomDataStructure sScenesServerCustomDataStructure;
    #endif
    #if (defined CLD_GROUPS) && (defined GROUPS_SERVER)
    /* Groups Cluster - Server */
      tsCLD_Groups sGroupsServerCluster;
      tsCLD_GroupsCustomDataStructure sGroupsServerCustomDataStructure;
    #endif
    /* Optional server clusters */
    #if (defined CLD_POWER_CONFIGURATION) && (defined
  POWER_CONFIGURATION_SERVER)
    /* Power Configuration Cluster - Server */
      tsCLD_PowerConfiguration sPowerConfigServerCluster;
    #endif
    #if (defined CLD_DEVICE_TEMPERATURE_CONFIGURATION) && (defined
        DEVICE_TEMPERATURE_CONFIGURATION_SERVER)
        /* Device Temperature Configuration Cluster - Server */
        tsCLD_DeviceTemperatureConfiguration
            sDeviceTemperatureConfigurationServerCluster;
    #endif
    #if (defined CLD_BALLAST_CONFIGURATION) && (defined
      BALLAST_CONFIGURATION_SERVER)
      tsCLD_BallastConfiguration sBallastConfigurationServerCluster;
    #endif
   /* Recommended Optional server clusters */
    #if (defined CLD_LEVEL_CONTROL) && (defined LEVEL_CONTROL_SERVER)
    /* LevelControl Cluster - Server */
        tsCLD_LevelControl sLevelControlServerCluster;
        tsCLD_LevelControlCustomDataStructure
        sLevelControlServerCustomDataStructure;
    #endif
    #if (defined CLD_ILLUMINANCE_LEVEL_SENSING) && (defined
        ILLUMINANCE_LEVEL_SENSING_SERVER)
      tsCLD_IlluminanceLevelSensing
      sIlluminanceLevelSensingServerCluster;
    #endif
    #if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_SERVER)
      tsCLD_ZllCommission sZllCommissionServerCluster;
      tsCLD_ZllCommissionCustomDataStructure
            sZllCommissionServerCustomDataStructure;
    #endif
    /*Recommended Optional client clusters */
    #if (defined CLD_OTA) && (defined OTA_CLIENT)
        /* OTA cluster - Client */
        tsCLD_AS_Ota sCLD_OTA;
        tsOTA_Common sCLD_OTA_CustomDataStruct;
    #endif
    #if (defined CLD_ILLUMINANCE_MEASUREMENT) && (defined
 ILLUMINANCE_MEASUREMENT_CLIENT)
        /* Illuminance Measurement Cluster - Client */
         tsCLD_IlluminanceMeasurement sIlluminanceMeasurementClientCluster;
    #endif
    #if (defined CLD_ILLUMINANCE_LEVEL_SENSING) && (defined
  ILLUMINANCE_LEVEL_SENSING_CLIENT)
      tsCLD_IlluminanceLevelSensing
        sIlluminanceLevelSensingClientCluster;
    #endif
    #if (defined CLD_OCCUPANCY_SENSING) && (defined
  OCCUPANCY_SENSING_CLIENT)
    /* Occupancy Sensing Cluster - Client */
       tsCLD_OccupancySensing sOccupancySensingClientCluster;
    #endif
} tsZLO_OnOffBallastDevice;
```

**Parent topic:**[On/Off Ballast](../topics/on_off_ballast.md)

