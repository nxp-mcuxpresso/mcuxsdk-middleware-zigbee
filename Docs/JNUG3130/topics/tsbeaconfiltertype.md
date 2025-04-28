# tsBeaconFilterType

This structure contains the details of a beacon filter that can be introduced using the function **ZPS\_bAppAddBeaconFilter\(\)**.

The `tsBeaconFilterType`structure is detailed below.

```
typedef struct
{
    uint64     *pu64ExtendPanIdList;
    uint16     u16Panid;
    uint16     u16FilterMap;
    uint8      u8ListSize;
    uint8      u8Lqi;
    uint8      u8Depth;
} tsBeaconFilterType;
```

where:

-   `pu64ExtendPanIdList`is a pointer to a list of 64-bit Extended PAN IDs \(EPIDs\) which acts as a blacklist or whitelist of networks, depending on the settings of bits 0 and 1 in the `u8FilterMap`bitmap:
    -   If this is a blacklist, beacons from networks with EPIDs in the list will not be accepted
    -   If this is a whitelist, only beacons from networks with EPIDs in the list will be accepted
-   `u16Panid`is a 16-bit PAN ID on which beacons can be filtered
-   `u8ListSize`is the number of Extended PAN IDs in the list pointed to by

`pu64ExtendPanIdList`

-   `u8Lqi`is the minimum LQI value \(in the range 0 to 255\) of an acceptable beacon \(any beacon with LQI value less than this minimum will be filtered out\) - if required, this field must be enabled through bit 2 in the `u8FilterMap`bitmap
-   `u8Depth`is the tree depth of the neighbor device. A value of 0x00 indicates that the device is the ZigBee coordinator for the network.
-   `u16FilterMap`is an 16-bit bitmap detailing the filtering requirements, as follows:

|**Bit**|**Enumeration**|**Description**|
|-------|---------------|---------------|
|0|BF\_BITMAP\_BLACKLIST\(0x1\)|If set, field `pu64ExtendPanIdList`points to a blacklist of networks.|
|1|BF\_BITMAP\_WHITELIST \(0x2\)|If set, field `pu64ExtendPanIdList`points to a whitelist of networks.|
|2|BF\_BITMAP\_LQI \(0x4\)|If set, beacons must be filtered according to LQI value using the minimum in field `u8Lqi`.|
|3|BF\_BITMAP\_CAP\_ENDDEVICE \(0x8\)|If set, beacons from nodes with capacity for End Device children can be accepted.|
|4|BF\_BITMAP\_CAP\_ROUTER \(0x10\)|If set, beacons from nodes with capacity for Router children can be accepted.|
|5|BF\_BITMAP\_PERMIT\_JOIN \(0x20\)|If set, beacons from nodes with ‘permit join- ing’ enabled can be accepted.|
|6|BF\_BITMAP\_SHORT\_PAN \(0x40\)|If set, beacons from nodes on a network with the PAN ID in `u16Panid`can be accepted.|
|7|-|Reserved.|
|8|BF\_BITMAP\_DEPTH|If set, beacons from nodes on a network with the depth in u8Depth. if it is set to 0xff - filters out any beacon which is not from the coordinator. Any other value of u8Depth, filters out beacons with greater than or equal to `u8Depth`.|

**Note:** Bits 0 and 1 must not both be set.

**Note:** After each discovery or rejoin, the flags contained in the u16FilterMap field are cleared, while all other fields of this structure remain intact.

**Parent topic:**[Other structures](../topics/other_structures.md)

