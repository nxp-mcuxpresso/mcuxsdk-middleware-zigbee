# ZPS\_tsAplZdpDeviceAnnceReq

This structure is used by the function **ZPS\_eAplZdpDeviceAnnceRequest\(\)**. It represents an announcement that the sending node has joined or rejoined the network.

The `ZPS_tsAplZdpDeviceAnnceReq`structure is detailed below.

`typedef struct { uint16 u16NwkAddr; uint64 u64IeeeAddr;`

`uint8 u8Capability;`

`} ZPS_tsAplZdpDeviceAnnceReq;`

where:

-   `u16NwkAddr`is the network address of the sending node
-   `u64IeeeAddr`is the IEEE address of the sending node
-   `u8Capability`is a bitmap representing the capabilities of the sending node. This bitmap is detailed in [Table 1](zps_tsafnwkjoinindevent.md#TABLE_026A2BDC-B736-4A72-8700-BD9FF0F39F3E) in section [ZPS\_tsAfNwkJoinIndEvent](zps_tsafnwkjoinindevent.md).

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

