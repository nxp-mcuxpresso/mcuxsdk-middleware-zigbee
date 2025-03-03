# Device structure

The following `tsZLO_OnOffSensorDevice` structure is the shared structure for a On/Off Sensor device:

```
typedef struct
{
  tsZCL_EndPointDefinition sEndPoint;
  /* Cluster instances */
  tsZLO_OnOffSensorDeviceClusterInstances sClusterInstance;
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
  /* Recommended Optional Server Cluster */
  #if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_SERVER)
    tsCLD_ZllCommission sZllCommissionServerCluster;
    tsCLD_ZllCommissionCustomDataStructure
          sZllCommissionServerCustomDataStructure;
  #endif
/** Mandatory client clusters*/
  #if (defined CLD_IDENTIFY) && (defined IDENTIFY_CLIENT)
    /* Identify Cluster - Client */
    tsCLD_Identify sIdentifyClientCluster;
    tsCLD_IdentifyCustomDataStructure
          sIdentifyClientCustomDataStructure;
  #endif
  #if (defined CLD_ONOFF) && (defined ONOFF_CLIENT)
  /* On/Off Cluster - Client */
  tsCLD_OnOff sOnOffClientCluster;
  #endif
  /* Recommended Optional Client CLuster */
  #if (defined CLD_LEVEL_CONTROL) && (defined LEVEL_CONTROL_CLIENT)
    /* Level Control Cluster - Client */
    tsCLD_LevelControl sLevelControlClientCluster;
    tsCLD_LevelControlCustomDataStructure
          sLevelControlClientCustomDataStructure;
  #endif
  #if (defined CLD_SCENES) && (defined SCENES_CLIENT)
  /* Scenes Cluster - Client */
  tsCLD_Scenes sScenesClientCluster;
  tsCLD_ScenesCustomDataStructure sScenesClientCustomDataStructure;
  #endif
  #if (defined CLD_GROUPS) && (defined GROUPS_CLIENT)
    /* Groups Cluster - Client */
    tsCLD_Groups sGroupsClientCluster;
    tsCLD_GroupsCustomDataStructure sGroupsClientCustomDataStructure;
  #endif
  #if (defined CLD_COLOUR_CONTROL) && (defined COLOUR_CONTROL_CLIENT)
    /* Colour Control Cluster - Client */
    tsCLD_ColourControl sColourControlClientCluster;
    tsCLD_ColourControlCustomDataStructure
            sColourControlClientCustomDataStructure;
  #endif
  #if (defined CLD_OTA) && (defined OTA_CLIENT)
    /* OTA cluster - Client */
    tsCLD_AS_Ota sCLD_OTA;
    tsOTA_Common sCLD_OTA_CustomDataStruct;
  #endif
  #if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_CLIENT)
  tsCLD_ZllCommission sZllCommissionClientCluster;
  tsCLD_ZllCommissionCustomDataStructure
          sZllCommissionClientCustomDataStructure;
  #endif
} tsZLO_OnOffSensorDevice;
```

**Parent topic:**[On/Off Sensor](../topics/on_off_sensor.md)

