# Scenes Cluster structure and attributes

The structure definition for the Scenes cluster is:

```
typedef struct
{
#ifdef SCENES_SERVER
   zuint8  u8SceneCount;
   zuint8  u8CurrentScene;
   zuint16 u16CurrentGroup;
   zbool   bSceneValid;
   zuint8  u8NameSupport;
#ifdef CLD_SCENES_ATTR_LAST_CONFIGURED_BY
   zieeeaddress  u64LastConfiguredBy;
#endif
#endif
    zuint16 u16ClusterRevision;
} tsCLD_Scenes;

```

where:

-   `u8SceneCount` is the number of scenes currently in the Scene table.

-   `u8CurrentScene` is the scene ID of the last scene invoked on the device.

-   `u16CurrentGroup` is the group ID of the group associated with the last scene invoked \(or 0x0000 if this scene is not associated with a group\).

-   `bSceneValid` indicates whether the current state of the device corresponds to the values of the `CurrentScene` and `CurrentGroup` attributes \(TRUE if they do, FALSE if they do not\).

-   `u8NameSupport` indicates whether scene names are supported - if the most significant bit is 1 then they are supported, otherwise they are not supported.

-   `u64LastConfiguredBy` is the 64-bit IEEE address of the device that last configured the Scene table \(0xFFFFFFFFFFFFFFFF indicates that the address is unknown or the table has not been configured\).

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Scenes Cluster](../../Scenes_cluster/topics/scenes_cluster.md)

