# ZPS\_tsAplZdpBindUnbindReq

This structure is used by the function **ZPS\_eAplZdpBindUnbindRequest\(\)**. It represents a request for a modification of the Binding table on the target node, in order to either bind or unbind two nodes in the network.

The `ZPS_tsAplZdpBindUnbindReq`structure is detailed below.

```
typedef struct {
uint64 u64SrcAddress;
uint8 u8SrcEndpoint;
uint16 u16ClusterId;
uint8 u8DstAddrMode;
union {
  struct {
      uint16 u16DstAddress;
         } sShort;
  struct {
      uint64 u64DstAddress;
      uint8 u8DstEndPoint;
         } sExtended;
  } uAddressField;
} ZPS_tsAplZdpBindUnbindReq;
```

where:

-   `u64SrcAddress`is the IEEE address of the source node for the binding
-   `u8SrcEndpoint`is the number of the source endpoint for the binding \(1-240\)
-   `u16ClusterId`is the ID of the cluster \(on the local endpoint\) for the binding
-   `u8DstAddrMode`is the destination addressing mode \(see Table 14 below\):
    -   ZPS\_E\_ADDR\_MODE\_SHORT: network address \(`u8DstEndPoint`is unspecified\)
    -   ZPS\_E\_ADDR\_MODE\_IEEE: IEEE address \(`u8DstEndPoint`is specified\)
    -   All other values are reserved
-   `u16DstAddress`or `u64DstAddress`is the address of the destination node for the binding:
    -   network address `u16DstAddress`if `u8DstAddrMode`is set to ZPS\_E\_ADDR\_MODE\_SHORT
    -   IEEE address `u64DstAddress`if `8DstAddrMode`is set to ZPS\_E\_ADDR\_MODE\_IEEE
-   `u8DstEndPoint`is the number of the destination endpoint for the binding

\(1-240\) - not required if `u8DstAddrMode`set to ZPS\_E\_ADDR\_MODE\_SHORT \(network address\)

**Addressing modes**

|**u8DstAddrMode**|**Code**|**Description**|
|--|--|--|
|0x02|ZPS\_E\_ADDR\_MODE\_SHORT|16-bit Network \(Short\) address|
|0x03|ZPS\_E\_ADDR\_MODE\_IEEE|64-bit IEEE/MAC address|

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

