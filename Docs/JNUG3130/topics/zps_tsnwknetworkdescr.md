# ZPS\_tsNwkNetworkDescr

This structure is used in an array element in the structure `ZPS_tsAfNwkDiscoveryEvent`, which is created as part of the ZPS\_EVENT\_NWK\_DISCOVERY\_COMPLETE event. This event reports the networks detected during a network discovery \(see [Section 8.2.2.9](zps_tsafnwkdiscoveryevent.md)\).

The `ZPS_tsNwkNetworkDescr`structure contains information on a detected network and is detailed below.

```
typedef struct
{
    uint64 u64ExtPanId;
    uint8 u8LogicalChan;
    uint8 u8StackProfile;
    uint8 u8ZigBeeVersion;
    uint8 u8PermitJoining;
    uint8 u8RouterCapacity;
    uint8 u8EndDeviceCapacity;
} ZPS_tsNwkNetworkDescr;
```

where:

-   `u64ExtPanId`is the Extended PAN ID of the discovered network.
-   `u8LogicalChan`is the 2400-MHz channel on which the network was found.
-   `u8StackProfile`is the Stack Profile of the discovered network:
    -   0 - manufacturer-specific
    -   1 - ZigBee
    -   2 - ZigBee PRO
    -   other values reserved, and is fixed at 2 for the NXP stack

-   `u8ZigBeeVersion`is the ZigBee version of the discovered network.
-   `u8PermitJoining`indicates the number of detected nodes with ‘permit joining’ enabled \(and therefore allowing nodes to join the network through them\).
-   `u8RouterCapacity`indicates the number of detected nodes that are allowing Routers to join the network through them.
-   `u8EndDeviceCapacity`indicates the number of detected nodes that are allowing End Devices to join the network through them.

**Parent topic:**[Other structures](../topics/other_structures.md)

