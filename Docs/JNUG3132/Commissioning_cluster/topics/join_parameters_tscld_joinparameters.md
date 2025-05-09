# Join Parameters \(tsCLD\_JoinParameters\)

The `tsCLD_JoinParameters` structure below contains the attributes of the Join Parameters attribute set:

```
typedef struct
{
#ifdef     CLD_COMMISSIONING_ATTR_SCAN_ATTEMPTS
    uint8         u8ScanAttempts;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_TIME_BW_SCANS
    uint16         u16TimeBwScans;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_REJOIN_INTERVAL
    uint16         u16RejoinInterval;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_MAX_REJOIN_INTERVAL
    uint16         u16MaxRejoinInterval;
#endif
} tsCLD_JoinParameters;

```

where:

-   `u8ScanAttempts` is the number of scan attempts to make before selecting a parent to join. The default value is 0x05.

-   `u16TimeBwScans` is the time-interval, in milliseconds, between consecutive scan attempts. The default value is 0x64.

-   `u16RejoinInterval` is the time-interval, in seconds, between consecutive attempts to rejoin the network for an End Device which has lost its network connection. The default value is 0x3C.

-   `u16MaxRejoinInterval` is an upper limit, in seconds, on the value of the `u16RejoinInterval` attribute. The default value is 0x0E10.


**Parent topic:**[Commissioning Cluster structure and attributes](../../Commissioning_cluster/topics/commissioning_cluster_structure_and_attributes.md)

