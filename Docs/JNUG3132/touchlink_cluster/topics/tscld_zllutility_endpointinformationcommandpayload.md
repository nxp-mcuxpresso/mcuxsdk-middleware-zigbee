# tsCLD\_ZllUtility\_EndpointInformationCommandPayload

This structure is used to hold the payload data for a Commissioning Utility Endpoint Information command.

```
typedef struct
{
 uint64  u64IEEEAddr;
 uint16  u16NwkAddr;
 uint8u8Endpoint;
 uint16  u16ProfileID;
 uint16  u16DeviceID;
 uint8u8Version;
} tsCLD_ZllUtility_EndpointInformationCommandPayload;

```

where:

-   `u64IEEEAddr` is the IEEE \(MAC\) address of the local node.

-   `u16NwkAddr` is the network \(short\) address of the local node.

-   `u8Endpoint` is the number of the local endpoint \(1-240\).

-   `u16ProfileID` is the identifier of the ZigBee application profile supported on the local endpoint.

-   `u16DeviceID` is identifier of the ZigBee device on the local endpoint.

-   `u8Version` specifies the version number of the ZigBee device on the local endpoint.


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

