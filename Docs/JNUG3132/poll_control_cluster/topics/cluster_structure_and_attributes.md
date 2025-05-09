# Cluster structure and attributes

The structure definition for the Poll Control cluster \(server\) is:

```
typedef struct
{
#ifdef POLL_CONTROL_SERVER
    zuint32     u32CheckinInterval;
    zuint32     u32LongPollInterval;
    zuint16     u16ShortPollInterval;
    zuint16     u16FastPollTimeout;
#ifdef CLD_POLL_CONTROL_ATTR_CHECKIN_INTERVAL_MIN
    zuint32     u32CheckinIntervalMin;
#endif
#ifdef CLD_POLL_CONTROL_ATTR_LONG_POLL_INTERVAL_MIN
    zuint32     u32LongPollIntervalMin;
#endif
#ifdef CLD_POLL_CONTROL_ATTR_FAST_POLL_TIMEOUT_MAX
    zuint16     u16FastPollTimeoutMax;
#endif
#endif
    zuint16     u16ClusterRevision;
} tsCLD_PollControl;

```

where:

-   `u32CheckinInterval` is the ‘check-in interval’, used by the server in checking whether a client requires the poll mode to be changed - this is the period, in quarter-seconds, between consecutive checks. The valid range of values is 1 to 7208960. A user-defined minimum value for this attribute can be set via the optional attribute `u32CheckinIntervalMin` \(see below\). Zero is a special value indicating that the Poll Control cluster server is disabled. The default value is 14400 \(1 hour\).

-   `u32LongPollInterval` is the ‘long poll interval’ of the End Device, employed when operating in normal poll mode - this is the period, in quarter-seconds, between consecutive polls of the parent for data. The valid range of values is 4 to 7208960. A user-defined minimum value for this attribute can be set via the optional attribute `u32LongPollIntervalMin` \(see below\). 0xFFFF is a special value indicating that the long poll interval is unknown/undefined. The default value is 20 \(5 seconds\).

-   `u16ShortPollInterval` is the ‘short poll interval’ of the End Device, employed when operating in fast poll mode - this is the period, in quarter-seconds, between consecutive polls of the parent for data. The valid range of values is 1 to 65535 and the default value is 2 \(0.5 seconds\).

-   `u16FastPollTimeout` is the ‘fast poll timeout’ representing the time-interval, in quarter-seconds, for which the server should normally stay in fast poll mode \(unless over-ridden by a client command\). The valid range of values is 1 to 65535. It is recommended that this timeout is greater than 7.68 seconds. A user-defined maximum value for this attribute can be set via the optional attribute `u16FastPollTimeoutMax` \(see below\). The default value is 40

    \(10 seconds\).

-   `u32CheckinIntervalMin` is an optional lower limit on the ‘check-in interval’ defined by `u32CheckinInterval`. This limit can be used to ensure that the interval is not inadvertently set to a low value which will quickly drain the energy resources of the End Device node.

-   `u32LongPollIntervalMin` is an optional lower limit on the ‘long poll interval’ defined by `u32LongPollInterval`. This limit can be used to ensure that the interval is not inadvertently set \(for example, by another device\) to a low value which will quickly drain the energy resources of the End Device node.

-   `u16FastPollTimeoutMax` is an optional upper limit on the ‘fast poll timeout’ defined by `u16FastPollTimeout`. This limit can be used to ensure that the interval is not inadvertently set \(for example, by another device\) to a high value which quickly drains the energy resources of the End Device node.


**Note:**

1.  Valid ranges \(maximum and minimum values\) for the four mandatory attributes can alternatively be set using macros in the **zcl\_options.h** file, as described in [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed). Some of these macros can only be used when the equivalent optional attribute is disabled.
2.  For general guidance on attribute settings, refer to [Section 20.3](attribute_settings.md#id_0c2962ce-71ee-49ee-a0bd-7c5a5bdf6014). Configuration through the attributes is also described in [Section 20.4.2](configuration.md#id_09459fb8-b194-477b-9860-6f94a298b676).

u16ClusterRevision is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Parent topic:**[Poll Control Cluster](../../poll_control_cluster/topics/poll_control_cluster.md)

