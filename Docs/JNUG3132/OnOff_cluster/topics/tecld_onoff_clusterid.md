# teCLD\_OnOff\_ClusterID

The following structure contains the enumerations used to identify the attributes of the On/Off cluster.

```
typedef enum 
{
    E_CLD_ONOFF_ATTR_ID_ONOFF                           = 0x0000,
    E_CLD_ONOFF_ATTR_ID_GLOBAL_SCENE_CONTROL            = 0x4000,
    E_CLD_ONOFF_ATTR_ID_ON_TIME,          
    E_CLD_ONOFF_ATTR_ID_OFF_WAIT_TIME,  
    #ifdef CLD_ONOFF_ATTR_STARTUP_ONOFF
    /* ZLO extension for OnOff Cluster    */             
    E_CLD_ONOFF_ATTR_ID_STARTUP_ONOFF,                         
    #endif
} teCLD_OnOff_ClusterID;  

```

**Parent topic:**[Enumerations](../../OnOff_cluster/topics/enumerations.md)

