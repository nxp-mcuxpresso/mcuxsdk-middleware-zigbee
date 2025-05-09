# On/Off Cluster Structure and Attribute

The structure definition for the On/Off cluster is:

```
typedef struct
{
#ifdef ONOFF_SERVER
    zbool                   bOnOff;
#ifdef CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL
    zbool                   bGlobalSceneControl;
#endif
#ifdef CLD_ONOFF_ATTR_ON_TIME
    zuint16                 u16OnTime;
#endif
#ifdef CLD_ONOFF_ATTR_OFF_WAIT_TIME
    zuint16                 u16OffWaitTime;
#endif
#ifdef CLD_ONOFF_ATTR_STARTUP_ONOFF
    /* ZLO extension for OnOff Cluster    */             
    zenum8                  eStartUpOnOff;
#endif
#ifdef CLD_ONOFF_ATTR_ATTRIBUTE_REPORTING_STATUS
    zenum8                  u8AttributeReportingStatus;
#endif
#endif
    zuint16                 u16ClusterRevision;
} tsCLD_OnOff;

```

where:

-   `bOnOff` is the on/off state of the device \(TRUE = on, FALSE = off\).

-   `bGlobalSceneControl` is an optional attribute for lighting that is used with the global scene - the value of this attribute determines whether to permit saving the current light settings to the global scene:

    -   TRUE - Current light settings can be saved to the global scene

    -   FALSE - Current light settings cannot be saved to the global scene

-   `u16OnTime` is an optional attribute for lighting used to store the time, in tenths of a second, for which the lights remain ‘on’ after a switch-on with ‘timed off’

    \(that is, the time before starting the transition from the ‘on’ state to the ‘off’ state\). The special values 0x0000 and 0xFFFF indicate that the lamp must be maintained in the ‘on’ state indefinitely \(no timed off\).

-   `u16OffWaitTime` is an optional attribute for lighting used to store the waiting time, in tenths of a second, following a ‘timed off’ before the lights can be again switched on with a ‘timed off’.


**Note:** If the `bGlobalSceneControl` attribute and global scene are to be used, the Scenes and Groups clusters must also be enabled - see [Chapter 13](../../Scenes_cluster/topics/scenes_cluster.md#id_6e49ba6c-88c2-4dbb-a986-2965b3fc17f7) and [Chapter 12](../../Groups_cluster/topics/groups_cluster.md#id_b6af3456-b2dc-4439-8085-c09909bffbe2).

-   `eStartUpOnOff` is an optional attribute that is used in the lighting domain to define the required start-up behavior of a light device when it is supplied with power. It determines the initial value of `bOnOff` on start-up. The possible values and behaviors are as follows:


|**eStartUpOnOff**|**Behavior**|
|-----------------|------------|
|0x00|Put the light in the off state - set `bOnOff` to FALSE|
|0x01|Put the light in the on state - set `bOnOff` to TRUE|
|0x02|Toggle the light from its previous state:

 -   If `bOnOff` was FALSE, set it to TRUE

-   If `bOnOff` was TRUE, set it to FALSE


|
|0x03-0xFE|Reserved|
|0xFF|Put the light in its previous state - set `bOnOff` to its previous value|

-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md).
-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md).

**Parent topic:**[On/Off Cluster](../../OnOff_cluster/topics/onoff_cluster.md)

