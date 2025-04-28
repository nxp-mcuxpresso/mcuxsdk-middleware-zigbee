# ZPS\_tsAplAfSimpleDescriptor

The AF Simple descriptor structure `ZPS_tsAplAfSimpleDescriptor`is shown below.

```
typedef struct {
    uint16 u16ApplicationProfileId;
    uint16 u16DeviceId;
    uint8 u8DeviceVersion;
    uint8 u8Endpoint;
    uint8 u8InClusterCount;
    uint8 u8OutClusterCount;
    uint16 *pu16InClusterList;
    uint16 *pu16OutClusterList;
} ZPS_tsAplAfSimpleDescriptor;
```

where:

-   `u16ApplicationProfileId`is the 16-bit identifier of the ZigBee application profile supported by the endpoint. This must be an application profile identifier issued by the ZigBee Alliance \(for Lighting and Occupancy devices, it is 0x0104\).
-   `u16DeviceId`is the 16-bit identifier of the ZigBee device type supported by the endpoint. This must be a device type identifier issued by the ZigBee Alliance.
-   `u8DeviceVersion`contains 4 bits \(bits 0-3\) representing the version of the supported device description \(default is 0000, unless set to another value according to the application profile used\).
-   `u8Endpoint`is the number, in the range 1-240, of the endpoint to which the Simple descriptor corresponds.
-   `u8InClusterCount`is an 8-bit count of the number of input clusters, supported on the endpoint, that will appear in the list pointed to by the `pu16InClusterList`element.
-   `u8OutClusterCount`is an 8-bit count of the number of output clusters, supported on the endpoint, that will appear in the `pu16OutClusterList`element.
-   `*pu16InClusterList`is a pointer to the list of input clusters supported by the endpoint \(for use during the service discovery and binding procedures\). This is a sequence of 16-bit values, representing the cluster numbers \(in the range 1-240\), where the number of values is equal to count `u8InClusterCount`. If this count is zero, the pointer can be set to NULL.
-   `*pu16OutClusterList`is a pointer to the list of output clusters supported by the endpoint \(for use during the service discovery and binding procedures\). This is a sequence of 16-bit values, representing the cluster numbers \(in the range 1-240\), where the number of values is equal to count `u8OutClusterCount`. If this count is zero, the pointer can be set to NULL.

**Parent topic:**[Descriptor structures](../topics/descriptor_structures.md)

