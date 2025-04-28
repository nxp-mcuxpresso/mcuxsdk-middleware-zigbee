# ZPS\_tsAplZdpMgmtDirectJoinReq

This structure is used by the function **ZPS\_eAplZdpMgmtDirectJoinRequest\(\)**. It requests a remote node to allow a particular device to join it \(and therefore the network\).

The `ZPS_tsAplZdpMgmtDirectJoinReq`structure is detailed below.

```
typedef struct { uint64 u64DeviceAddress; uint8 u8Capability; } ZPS_tsAplZdpMgmtDirectJoinReq;
```

where:

-   `u64DeviceAddress`is the IEEE address of the device to be allowed to join
-   `u8Capability`is a bitmask of the operating capabilities of the device to be allowed to join. This bitmap is detailed in [Table](zps_tsafnwkjoinindevent.md#TABLE_026A2BDC-B736-4A72-8700-BD9FF0F39F3E) in section [ZPS\_tsAfNwkJoinIndEvent](zps_tsafnwkjoinindevent.md).

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

