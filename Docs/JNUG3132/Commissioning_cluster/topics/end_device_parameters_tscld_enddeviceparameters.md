# End Device Parameters \(tsCLD\_EndDeviceParameters\)

The `tsCLD_EndDeviceParameters` structure below contains the attributes of the End Device Parameters attribute set:

```
typedef struct
{
#ifdef     CLD_COMMISSIONING_ATTR_INDIRECT_POLL_RATE
    uint16         u16IndirectPollRate;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_PARENT_RETRY_THRSHLD
    uint8          u8ParentRetryThreshold;
#endif
} tsCLD_EndDeviceParameters;

```

where:

-   `u16IndirectPollRate` is the time-interval, in milliseconds, between consecutive polls from an End Device which polls its parent while awake \(an End Device with a receiver that is inactive while sleeping\).

-   `u8ParentRetryThreshold` is the number of times that an End Device should attempt to re-contact its parent before initiating the rejoin process.


**Parent topic:**[Commissioning Cluster structure and attributes](../../Commissioning_cluster/topics/commissioning_cluster_structure_and_attributes.md)

