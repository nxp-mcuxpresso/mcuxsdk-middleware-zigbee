# teCLD\_Scenes\_ClusterID

The following structure contains the enumerations used to identify the attributes of the Scenes cluster.

```
typedef enum 
{
    E_CLD_SCENES_ATTR_ID_SCENE_COUNT            = 0x0000,   /* Mandatory */
    E_CLD_SCENES_ATTR_ID_CURRENT_SCENE,                     /* Mandatory */
    E_CLD_SCENES_ATTR_ID_CURRENT_GROUP,                     /* Mandatory */
    E_CLD_SCENES_ATTR_ID_SCENE_VALID,                       /* Mandatory */
    E_CLD_SCENES_ATTR_ID_NAME_SUPPORT,                      /* Mandatory */
    E_CLD_SCENES_ATTR_ID_LAST_CONFIGURED_BY                 /* Optional  */
} teCLD_Scenes_ClusterID;

```

**Parent topic:**[Enumerations](../../Scenes_cluster/topics/enumerations.md)

