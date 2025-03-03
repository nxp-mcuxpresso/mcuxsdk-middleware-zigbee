# Device structure

The following `tsZLO_OnOffLightDevice` structure is the shared structure for an On/Off Light device:

```
typedef struct
{
            tsZCL_EndPointDefinition sEndPoint;
 /* Cluster instances */
            tsZLO_OnOffLightDeviceClusterInstances sClusterInstance;
            #if (defined CLD_BASIC) && (defined BASIC_SERVER)
/* Basic Cluster - Server */
            tsCLD_Basic sBasicServerCluster;
            #endif
            #if (defined CLD_ONOFF) && (defined ONOFF_SERVER)
/* On/Off Cluster - Server */
            tsCLD_OnOff sOnOffServerCluster;
            tsCLD_OnOffCustomDataStructure sOnOffServerCustomDataStructure;
            #endif
            #if (defined CLD_GROUPS) && (defined GROUPS_SERVER)
/* Groups Cluster - Server */
            tsCLD_Groups sGroupsServerCluster;
            tsCLD_GroupsCustomDataStructure sGroupsServerCustomDataStructure;
            #endif
            #if (defined CLD_SCENES) && (defined SCENES_SERVER)
/* Scenes Cluster - Server */
            tsCLD_Scenes sScenesServerCluster;
            tsCLD_ScenesCustomDataStructure sScenesServerCustomDataStructure;
            #endif
            #if (defined CLD_IDENTIFY) && (defined IDENTIFY_SERVER)
/* Identify Cluster - Server */
            tsCLD_Identify sIdentifyServerCluster;
            tsCLD_IdentifyCustomDataStructure
                        sIdentifyServerCustomDataStructure;
            #endif
/* On Off light device 2 optional clusters for the server */
            #if (defined CLD_LEVEL_CONTROL) && (defined LEVEL_CONTROL_SERVER)
/* LevelControl Cluster - Server */
            tsCLD_LevelControl sLevelControlServerCluster;
            tsCLD_LevelControlCustomDataStructure
                     sLevelControlServerCustomDataStructure;
            #endif
            #if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_SERVER)
            tsCLD_ZllCommission sZllCommissionServerCluster;
            tsCLD_ZllCommissionCustomDataStructure
            sZllCommissionServerCustomDataStructure;
            #endif
/* On Off light device 2 optional clusters for the client */
            #if (defined CLD_OTA) && (defined OTA_CLIENT)
            /* OTA cluster - Client */
            tsCLD_AS_Ota sCLD_OTA;
            tsOTA_Common sCLD_OTA_CustomDataStruct;
            #endif
            #if (defined CLD_OCCUPANCY_SENSING) && (defined
            OCCUPANCY_SENSING_CLIENT)
            /* Occupancy Sensing Cluster - Client */
            tsCLD_OccupancySensing sOccupancySensingClientCluster;
            #endif
} tsZLO_OnOffLightDevice;

```

**Parent topic:**[On/Off light](../topics/on_off_light.md)

