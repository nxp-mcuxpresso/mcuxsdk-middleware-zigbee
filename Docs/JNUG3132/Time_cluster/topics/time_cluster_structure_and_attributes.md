# Time Cluster structure and attributes

The Time cluster is contained in the following `tsCLD_Time` structure:

```
typedef struct
{
#ifdef TIME_SERVER    
    zutctime                utctTime;
    zbmap8                  u8TimeStatus;
#ifdef CLD_TIME_ATTR_TIME_ZONE
    zint32                 i32TimeZone;
#endif
#ifdef CLD_TIME_ATTR_DST_START
    zuint32                u32DstStart;
#endif
#ifdef CLD_TIME_ATTR_DST_END
    zuint32                u32DstEnd;
#endif
#ifdef CLD_TIME_ATTR_DST_SHIFT
    zint32                 i32DstShift;
#endif
#ifdef CLD_TIME_ATTR_STANDARD_TIME
    zuint32                u32StandardTime;
#endif
#ifdef CLD_TIME_ATTR_LOCAL_TIME
    zuint32                u32LocalTime;
#endif
#ifdef CLD_TIME_ATTR_LAST_SET_TIME
    zutctime                u32LastSetTime;
#endif
#ifdef CLD_TIME_ATTR_VALID_UNTIL_TIME
    zutctime                u32ValidUntilTime;
#endif
#endif
    zuint16                 u16ClusterRevision;
} tsCLD_Time;;

```

where:

-   `utctTime` is a mandatory 32-bit attribute which holds the current time \(UTC\). This attribute can only be over-written using a remote ‘write attributes’ request if the local Time cluster is not configured as the time-master for the network - this is the case if bit 0 of the element `u8TimeStatus` \(see below\) is set to 0.

-   `u8TimeStatus` is a mandatory 8-bit attribute containing the following bitmap:

    |**Bits**|**Meaning**|**Description**|
    |--------|-----------|---------------|
    |0|Master|1: Time-master for network

 0: Not time-master for network

|
    |1|Synchronized|1: Synchronized to another device

 0: Not synchronized to another device

|
    |2|Master for Time Zone and DST \*|1: Master for time-zone and DST

 0: Not master for time-zone and DST

|
    |3-7|Reserved|-|

    \* DST= Daylight Saving Time

    Macros are provided for setting the individual bits of this bitmap:

    -   CLD\_TM\_TIME\_STATUS\_MASTER\_MASK \(bit 0\)
    -   CLD\_TM\_TIME\_STATUS\_SYNCHRONIZED\_MASK \(bit 1\)
    -   CLD\_TM\_TIME\_STATUS\_MASTER\_ZONE\_DST\_MASK \(bit 2\)

-   `i32TimeZone` is an optional attribute which indicates the local time-zone expressed as an offset from UTC, in seconds.
-   `u32DstStart` is an optional attribute which contains the start-time \(UTC\), in seconds, for daylight saving for the current year.
-   `u32DstEnd` is an optional attribute which contains the end-time \(UTC\), in seconds, for daylight saving for the current year.
-   `i32DstShift` is an optional attribute which contains the local time-shift, in seconds, relative to standard local time that is applied during the daylight saving period.
-   `u32StandardTime` is an optional attribute which contains the local standard time \(equal to `utctTime` + `i32TimeZone`\).
-   `u32LocalTime` is an optional attribute which contains the local time taking into account daylight saving, if applicable \(equal to `utctTime` + `i32TimeZone` + `i32DstShift` during the daylight saving period\).
-   `u32LastSetTime` is an optional attribute which indicates the most recent UTC time at which the Time attribute \(`utctTime`\) was set, either internally or over the ZigBee network.
-   `u32ValidUntilTime` is an optional attribute which indicates a UTC time \(later than `u32LastSetTime`\) up to which the Time attribute \(`utctTime`\) value may be trusted.
-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Note:** If necessary, the daylight saving attributes \(`u32DstStart`, `u32DstEnd` and, `i32DstShift`\) must all be enabled together.

The Time cluster structure contains two mandatory elements, `utctTime` and `u8TimeStatus`. The remaining elements are optional, each being enabled/disabled through a corresponding macro defined in the **zcl\_options.h** file - for example, the optional time zone element `i32TimeZone` is enabled/disabled through the macro CLD\_TIME\_ATTR\_TIME\_ZONE \(see [Section 18.3.2](optional_attributes.md#id_5fb3e4f1-97ed-4089-b34a-819f101833bd)\).

**Parent topic:**[Time Cluster and ZCL Time](../../Time_cluster/topics/time_cluster_and_zcl_time.md)

