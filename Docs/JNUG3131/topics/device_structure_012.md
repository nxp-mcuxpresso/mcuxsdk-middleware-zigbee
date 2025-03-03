# Device Structure

The following `tsZLO_DimmerSwitchDevice` structure is the shared structure for a Dimmer Switch device:

```
typedef struct
{
  tsZCL_EndPointDefinition sEndPoint;
/* Cluster instances */
    tsZLO_DimmerSwitchDeviceClusterInstances sClusterInstance;
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
/* Optional server clusters */
#if (defined CLD_OOSC) && (defined OOSC_SERVER)
  /* On/Off Switch Configuration Cluster - Server */
  tsCLD_OOSC sOOSCServerCluster;
#endif
/* Mandatory client clusters */
#if (defined CLD_IDENTIFY) && (defined IDENTIFY_CLIENT)
  /* Identify Cluster - Client */
  tsCLD_Identify sIdentifyClientCluster;
  tsCLD_IdentifyCustomDataStructure
  sIdentifyClientCustomDataStructure;
#endif
#if (defined CLD_BASIC) && (defined BASIC_CLIENT)
  /* Basic Cluster - Client */
  tsCLD_Basic sBasicClientCluster;
  #endif
#if (defined CLD_ONOFF) && (defined ONOFF_CLIENT)
  tsCLD_OnOff sOnOffClientCluster;
#endif
#if (defined CLD_LEVEL_CONTROL) && (defined LEVEL_CONTROL_CLIENT)
  /* Level Control Cluster - Client */
  tsCLD_LevelControl sLevelControlClientCluster;
  tsCLD_LevelControlCustomDataStructure
        sLevelControlClientCustomDataStructure;
#endif
/* Recommended Optional client clusters */
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
#if (defined CLD_OTA) && (defined OTA_CLIENT)
  tsCLD_AS_Ota sCLD_OTA;
  tsOTA_Common sCLD_OTA_CustomDataStruct;
#endif
} tsZLO_DimmerSwitchDevice;
```

**Parent topic:**[Dimmer Switch](../topics/dimmer_switch.md)

