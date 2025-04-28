# ZPS\_tsAplZdpSimpleDescType

The ZDP Simple descriptor structure `ZPS_tsAplZdpSimpleDescType`is shown below.

```
typedef struct {
        uint8 u8Endpoint;
        uint16 u16ApplicationProfileId;
        uint16 u16DeviceId;
    union
    {
        ZPS_tsAplZdpSimpleDescBitFields sBitFields;
        uint8 u8Value;
    }uBitUnion;
uint8 u8InClusterCount;
uint16* pu16InClusterList;
uint8 u8OutClusterCount;
uint16* pu16OutClusterList;
}ZPS_tsAplZdpSimpleDescType;
```

where:

-   `u8Endpoint`is the number, in the range 1-240, of the endpoint to which the Simple descriptor corresponds.
-   `u16ApplicationProfileId`is the 16-bit identifier of the ZigBee application profile supported by the endpoint. This must be an application profile identifier issued by the ZigBee Alliance \(for Lighting &amp; Occupancy devices, it is 0x0104\).
-   `u16DeviceId`is the 16-bit identifier of the ZigBee device description supported by the endpoint. This must be a device description identifier issued by the ZigBee Alliance.
-   `sBitFields`is a structure of type `ZPS_tsAplZdpSimpleDescBitFields` \(described below\) containing information about the endpoint.

-   `u8Value`is used for the union and must be set to 0x00.
-   `u8InClusterCount`is an 8-bit count of the number of input clusters, supported on the endpoint, that will appear in the list pointed to by the `pu16InClusterList`element.
-   `*pu16InClusterList`is a pointer to the list of input clusters supported by the endpoint \(for use during the service discovery and binding procedures\). This is a sequence of 16-bit values, representing the cluster numbers \(in the range 1-240\), where the number of values is equal to count `u8InClusterCount`. If this count is zero, the pointer can be set to NULL.
-   `u8OutClusterCount`is an 8-bit count of the number of output clusters, supported on the endpoint, that will appear in the `pu16OutClusterList`element.
-   `*pu16OutClusterList`is a pointer to the list of output clusters supported by the endpoint \(for use during the service discovery and binding procedures\). This is a sequence of 16-bit values, representing the cluster numbers \(in the range 1-240\), where the number of values is equal to count `u8OutClusterCount`. If this count is zero, the pointer can be set to NULL.


```{include} ../topics/zps_tsaplzdpsimpledescbitfields.md
:heading-offset: 4
```

**Parent topic:**[Descriptor structures](../topics/descriptor_structures_001.md)

