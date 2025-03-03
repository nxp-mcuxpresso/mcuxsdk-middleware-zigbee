# Device Structure

The following `tsZLO_LightLevelSensorDevice` structure is the shared structure for a Light Level Sensor device:

```
typedef struct
{
  tsZCL_EndPointDefinition sEndPoint;
 /* Cluster instances */
  tsZLO_LightLevelSensorDeviceClusterInstances sClusterInstance;
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
  #if (defined CLD_ILLUMINANCE_LEVEL_SENSING) && (defined
 ILLUMINANCE_LEVEL_SENSING_SERVER)
    tsCLD_IlluminanceLevelSensing
      sIlluminanceLevelSensingServerCluster;
  #endif
  /* Optional server clusters */
  #if (defined CLD_POLL_CONTROL) && (defined POLL_CONTROL_SERVER)
    tsCLD_PollControl sPollControlServerCluster;
    tsCLD_PollControlCustomDataStructure
    sPollControlServerCustomDataStructure;
  #endif
  /* Mandatory server clusters */
  #if (defined CLD_IDENTIFY) && (defined IDENTIFY_CLIENT)
    /* Identify Cluster - Client */
    tsCLD_Identify sIdentifyClientCluster;
    tsCLD_IdentifyCustomDataStructure
    sIdentifyClientCustomDataStructure;
  #endif
  /* Recommended Optional client clusters */
  #if (defined CLD_GROUPS) && (defined GROUPS_CLIENT)
    /* Groups Cluster - Client */
    tsCLD_Groups sGroupsClientCluster;
    tsCLD_GroupsCustomDataStructure sGroupsClientCustomDataStructure;
  #endif
  #if (defined CLD_OTA) && (defined OTA_CLIENT)
    tsCLD_AS_Ota sCLD_OTA;
    tsOTA_Common sCLD_OTA_CustomDataStruct;
  #endif
} tsZLO_LightLevelSensorDevice;
```

**Parent topic:**[Light Level Sensor](../topics/light_level_sensor.md)

