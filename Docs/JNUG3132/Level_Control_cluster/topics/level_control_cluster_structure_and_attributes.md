# Level Control Cluster structure and attributes

The structure definition for the Level Control cluster is shown below.

```
typedef struct
{
#ifdef LEVEL_CONTROL_SERVER    
    zuint8                  u8CurrentLevel;
#ifdef CLD_LEVELCONTROL_ATTR_REMAINING_TIME
    zuint16                 u16RemainingTime;
#endif
    zbmap8                  u8Options;
#ifdef CLD_LEVELCONTROL_ATTR_ON_OFF_TRANSITION_TIME
    zuint16                 u16OnOffTransitionTime;
#endif
#ifdef CLD_LEVELCONTROL_ATTR_ON_LEVEL
    zuint8                  u8OnLevel;
#endif
#ifdef CLD_LEVELCONTROL_ATTR_ON_TRANSITION_TIME
    zuint16                 u16OnTransitionTime;
#endif
#ifdef CLD_LEVELCONTROL_ATTR_OFF_TRANSITION_TIME
    zuint16                 u16OffTransitionTime;
#endif
#ifdef CLD_LEVELCONTROL_ATTR_DEFAULT_MOVE_RATE
    zuint8                  u8DefaultMoveRate;
#endif
#ifdef CLD_LEVELCONTROL_ATTR_STARTUP_CURRENT_LEVEL
    zuint8                  u8StartUpCurrentLevel;
#endif
#ifdef CLD_LEVELCONTROL_ATTR_ATTRIBUTE_REPORTING_STATUS
    zenum8                  u8AttributeReportingStatus;
#endif
#endif
    zuint16                 u16ClusterRevision;
} tsCLD_LevelControl;

```

where:

-   `u8CurrentLevel` is the current level on the device, in the range 0x01 to 0xFE \(0x00 is not used and 0xFF represents an undefined level\).

-   `u16RemainingTime` is the time remaining \(in tenths of a second\) at the current level

-   `u8Options` is a bitmap which allows behaviors connected with certain commands to be defined \(these behaviors should only be defined during commissioning\), as follows:


|**Bits**|**Name**|**Description**|
|--------|--------|---------------|
|0|ChangeIfOff|Defines whether changes to the Level Control cluster can be made from control clusters \(for example, Colour Control\) when the `bOnOff` attribute of the On/Off cluster is zero \(off\):

 -   1 – Allow changes

-   0 – Do not allow changes


|
|1|CoupleColorTempToLevel|Defines whether changes to the `u8CurrentLevel` attribute are to be coupled with colour temperature:

 -   1 – Couple changes

-   0 – Do not couple changes


|
|2-7|-|Reserved|

-   `u16OnOffTransitionTime` is the time taken \(in tenths of a second\) to increase from ‘off’ to the target level or decrease from the target level to ‘off’ when an On or Off command is received, respectively \(see below for target level\)

-   `u8OnLevel` is the target level to which `u8CurrentLevel` is set when an On command is received. The value must be in the range 0x01 to 0xFE. If maximum and minimum levels are implemented using the final four attributes of the cluster \(see below\), the value must be within the permissible range.

-   `u16OnTransitionTime` is an optional attribute representing the time taken \(in tenths of a second\) to increase the level from 0 \(off\) to 255 \(on\) when an ‘On’ command of the On/Off cluster is received. The special value of 0xFFFF indicates that the transition time `u16OnOffTransitionTime` must be used instead \(which is also used if `u16OnTransitionTime` is not enabled\).

-   `u16OffTransitionTime` is an optional attribute representing the time taken \(in tenths of a second\) to decrease the level from 255 \(on\) to 0 \(off\) when an ‘Off’ command of the On/Off cluster is received. The special value of 0xFFFF indicates that the transition time `u16OnOffTransitionTime` must be used instead \(which is also be used if `u16OffTransitionTime` is not enabled\).

-   `u8DefaultMoveRate` is an optional attribute representing the rate of movement \(in units per second\) to be used when a Move command is received with a rate value \(`u8Rate`\) equal to 0xFF \(see [Section 16.8.3.2](move_command_payload.md#id_68bf0e81-1a15-474c-b2f5-cc62d79da035)\).

-   `u8StartUpCurrentLevel` is an optional attribute that is used in the lighting domain to define the required start-up level of a light device when it is supplied with power. It determines the initial value of `u8CurrentLevel` on start-up \(in the range 0x01 to 0xFE\).

-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Parent topic:**[Level Control Cluster](../../Level_Control_cluster/topics/level_control_cluster.md)

