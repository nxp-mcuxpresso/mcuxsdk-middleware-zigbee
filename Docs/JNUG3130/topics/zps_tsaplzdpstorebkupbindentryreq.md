# ZPS\_tsAplZdpStoreBkupBindEntryReq

This structure is used by the function **ZPS\_eAplZdpStoreBkupBindEntryRequest\(\)**. It represents a request to a remote node to save a back-up of an entry from the local primary binding table cache.

The `ZPS_tsAplZdpStoreBkupBindEntryReq`structure is detailed below.

```
typedef struct {
uint64 u64SrcAddress;
uint8 u8SrcEndPoint;
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
     };
} ZPS_tsAplZdpStoreBkupBindEntryReq;
```

where:

-   `u64SrcAddress`is the IEEE address of the source node for the binding entry
-   `u8SrcEndpoint`is the number of the source endpoint for the binding \(1-240\)
-   `u16ClusterId`is the ID of the cluster \(on the local endpoint\) for the binding
-   `u8DstAddrMode`is the destination addressing mode for remaining elements \(see Table 15 below\)
-   `u16DstAddress`is the address of the destination node for the binding \(address type according to setting of `u8DstAddrMode`\)
-   `u8DstEndPoint`is the number of the destination endpoint for the binding \(1-240\)

**Addressing modes**

|**u8DstAddrMode**|**Code**|**Description**|
|-----------------|--------|---------------|
|0x01|ZPS\_E\_ADDR\_MODE\_GROUP|16-bit Group address|
|0x03|ZPS\_E\_ADDR\_MODE\_IEEE|64-bit IEEE/MAC address|

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

