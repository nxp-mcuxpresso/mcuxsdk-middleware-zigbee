# ZPS\_tsAfNwkDiscoveryEvent

This structure is used in the ZPS\_EVENT\_NWK\_DISCOVERY\_COMPLETE event, which reports the details of the networks detected in a network discovery initiated by a Router or End Device that needs to join a network.

The `ZPS_tsAfNwkDiscoveryEvent`structure is detailed below.

```
typedef struct
{
    uint32        u32UnscannedChannels;
    uint8         eStatus;
    uint8         u8NetworkCount;
    uint8         u8SelectedNetwork;
    ZPS_tsNwkNetworkDescr *psNwkDescriptors;
} ZPS_tsAfNwkDiscoveryEvent;
```

where:

-   `u32UnscannedChannels`is a 32-bit bitmap representing the set of channels from the network discovery that had not yet been scanned when this event was generated. Bits 11 to 26 represent the 2400-MHz channels 11 to 26, where 1 indicates channel scanned and 0 indicates channel not yet scanned.
-   `estatus`is the status of the network discovery process, returned by the lower layers \(see [Section 11.2](return_status_codes.md)\) - MAC\_ENUM\_SUCCESS, if the discovery was successfully completed.
-   `u8NetworkCount`is the number of networks that had been discovered when this event was generated.
-   `u8SelectedNetwork`is the index of the recommended network in the array of reported networks \(see below\).
-   `psNwkDescriptors`is a pointer to the network discovery table in the network NIB. The network discovery table contains an array of data structures, where each structure contains details of a discovered network. Each array element is a structure of the type `ZPS_tsNwkNetworkDescr`, described in [Section 8.2.3.1](zps_tsnwknetworkdescr.md). The number of array elements is given by `u8NetworkCount`, described above.

**Parent topic:**[Event structures](../topics/event_structures.md)

