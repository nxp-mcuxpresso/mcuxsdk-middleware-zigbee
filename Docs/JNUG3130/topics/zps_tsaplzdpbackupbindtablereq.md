# ZPS\_tsAplZdpBackupBindTableReq

This structure is used by the function **ZPS\_eAplZdpBackupBindTableRequest\(\)**. It represents a request to a remote node to save a back-up of the local primary binding table cache \(whole or in part\).

The `ZPS_tsAplZdpBackupBindTableReq`structure is detailed below.

```
typedef struct {
    uint16 u16BindingTableEntries;
    uint16 u16StartIndex;
    uint16 u16BindingTableListCount;
    /* Rest of message is variable length */
    ZPS_tsAplZdpBindingTable sBindingTable;
} ZPS_tsAplZdpBackupBindTableReq;
```

where:

-   `u16BindingTableEntries`is the total number of entries in the primary binding table cache.
-   `u16StartIndex`is the binding table index of the first entry to be backed up.
-   `u16BindingTableListCount`is the number of binding table entries in the list to be backed up \(`sBindingTable`\).
-   `sBindingTable`is a pointer to the list of binding table entries to be backed up. Each list item is of the type `ZPS_tsAplZdpBindingTable`detailed below:

**ZPS\_tsAplZdpBindingTable**

```
typedef struct
{
uint64 u64SourceAddress;
ZPS_tsAplZdpBindingTableEntry* psBindingTableEntryForSpSrcAddr;
}ZPS_tsAplZdpBindingTable;
```

where:

-   `u64SourceAddress`is the IEEE source address for the binding table entry.
-   `psBindingTableEntryForSpSrcAddr`is the binding table entry. This is of the type `ZPS_tsAplZdpBindingTableEntry`detailed below.

**ZPS\_tsAplZdpBindingTableEntry**

```
typedef struct
{
    uint16 u16ClusterId;
    uint8 u8SourceEndpoint;
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

-   `u16ClusterId`is the ID of the cluster \(on the local endpoint\) for the binding
-   `u8SrcEndpoint`is the number of the source endpoint for the binding \(1-240\)
-   `u8DstAddrMode`is the destination addressing mode for remaining elements \(see Table below\)
-   `u16DstAddress`is the address the destination node for the binding \(address type according to setting of `u8DstAddrMode`\)
-   `u8DstEndPoint`is the number of the destination endpoint for the binding \(1-240\)

**Addressing modes**

|**u8DstAddrMode**|**Code**|**Description**|
|--|--|--|
|0x01|ZPS\_E\_ADDR\_MODE\_GROUP|16-bit Group address|
|0x03|ZPS\_E\_ADDR\_MODE\_IEEE|64-bit IEEE/MAC address|

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

