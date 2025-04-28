# ZPS\_tsAplZdpBindingTableEntry

```
typedef struct
{
    uint8 u8SourceEndpoint;
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
}ZPS_tsAplZdpBindingTableEntry;
```

where:

-   `u8SourceEndpoint`is the number of the bound endpoint \(1-240\) on the source node of the binding
-   `u16ClusterId`is the ID of the cluster involved in the binding, on the source node of the binding
-   `u8DstAddrMode`is the addressing mode used in the rest of the structure \(see Table 19 below\)
-   `u16DstAddress`is the network address of the destination node of the binding \(this is only application if `u8DstAddrMode`is set to 0x03\)
-   `u64DstAddress`is the IEEE address of the destination node of the binding \(this is only application if `u8DstAddrMode`is set to 0x04\)
-   `u8DstEndPoint`is the number of the bound endpoint \(1-240\) on the destination node of the binding

**Addressing modes**

|**u8DstAddrMode**|**Code**|**Description**|
|-----------------|--------|---------------|
|0x00|ZPS\_E\_ADDR\_MODE\_BOUND|Bound endpoint|
|0x01|ZPS\_E\_ADDR\_MODE\_GROUP|16-bit Group address|
|0x02|ZPS\_E\_ADDR\_MODE\_SHORT|16-bit Network \(Short\) address|
|0x03|ZPS\_E\_ADDR\_MODE\_IEEE|64-bit IEEE/MAC address|

**Parent topic:**[ZPS\_tsAplZdpBindRegisterRsp](../topics/zps_tsaplzdpbindregisterrsp.md)

