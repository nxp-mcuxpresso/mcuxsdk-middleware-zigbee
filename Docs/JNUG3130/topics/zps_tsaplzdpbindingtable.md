# ZPS\_tsAplZdpBindingTable

```
typedef struct
{
uint64 u64SourceAddress;
ZPS_tsAplZdpBindingTableEntry* psBindingTableEntryForSpSrcAddr;
}ZPS_tsAplZdpBindingTable;
```

where:

-   `u64SourceAddress`is the IEEE address of the node to which the binding table entry relates.
-   `psBindingTableEntryForSpSrcAddr`is a pointer to the relevant binding table information. This information is contained in a structure of type `ZPS_tsAplZdpBindingTableEntry`detailed below.

**Parent topic:**[ZPS\_tsAplZdpBindRegisterRsp](../topics/zps_tsaplzdpbindregisterrsp.md)

