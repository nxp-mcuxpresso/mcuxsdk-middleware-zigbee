# Cluster structure and attributes

The structure definition for the Power Profile cluster \(server\) is:

```
typedef struct
{
#ifdef PP_SERVER
   zuint8  u8TotalProfileNum;
   zbool  bMultipleScheduling;
   zbmap8  u8EnergyFormatting;
   zbool  bEnergyRemote;
   zbmap8  u8ScheduleMode;
#ifdef CLD_PP_ATTR_ATTRIBUTE_REPORTING_STATUS
   zuint8 u8AttributeReportingStatus;
#endif    
#endif    
   zuint16  u16ClusterRevision;
} tsCLD_PP;

```

where:

-   `u8TotalProfileNum` is the number of power profiles supported by the device \(must be between 1 and 254, inclusive\)

-   `bMultipleScheduling` is a boolean indicating whether the server side of the cluster supports the scheduling of multiple energy phases or just a single energy phase at a time \(according to commands received from the client\):

    -   TRUE if multiple energy phase scheduling is possible

    -   FALSE if only single energy phase scheduling is possible

-   `u8EnergyFormatting` indicates the format of the Energy fields in the Power Profile Notification and Power Profile Response:

    -   Bits 0-2: Number of digits to the right of the decimal point

    -   Bits 3-6: Number of digits to the left of the decimal point

    -   Bit 7: If set to ‘1’, any leading zeros are removed

-   `bEnergyRemote` is a boolean indicating whether the cluster server \(appliance\) is configured for remote control \(of energy management\):

    -   TRUE if at least one power profile is enabled for remote control

    -   FALSE if no power profile is enabled for remote control

        -   This attribute is linked to the `bPowerProfileRemoteControl` field in the power profile record \(see [Section 21.10.13](tscld_pp_powerprofiierecord.md#id_a9fed0bf-e5da-4474-926a-74e8412aefcb)\) - if the latter field is set to TRUE, the attribute is also automatically set to TRUE.
-   `u8ScheduleMode` indicates the criterion \(cheapest or greenest\) that should be used by the cluster client \(for example, energy management system\) to schedule the power profiles:

    -   0x00 - criterion is left to the cluster server to choose

    -   0x01 - cheapest mode \(minimize cost of energy usage\)

    -   0x02 - greenest mode \(maximize use of renewable energy sources\)

    -   0x03 - compromise between cheapest and greenest

        -   All other values are reserved.
-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Power Profile Cluster](../../power_profile_cluster/topics/power_profile_cluster.md)

