# ZPS\_tsAplZdpBackupSourceBindReq

This structure is used by the function **ZPS\_eAplZdpBackupSourceBindRequest\(\)**. It represents a request to a remote node to save a back-up of the local node’s source binding table \(whole or in part\).

The `ZPS_tsAplZdpBackupSourceBindReq`structure is detailed below.

```
typedef struct {
  uint16 u16SourceTableEntries;
  uint16 u16StartIndex;
  uint16 u16SourceTableListCount;
  /* Rest of message is variable length */
  uint64* pu64SourceAddress;
} ZPS_tsAplZdpBackupSourceBindReq;
```

where:

-   `u16SourceTableEntries`is the total number of entries in the source binding table.
-   `u16StartIndex`is the binding table index of the first entry to be backed up.
-   `u16SourceTableListCount`is the number of binding table entries in the list to be backed up \(`pu64SourceAddress`\).
-   `pu64SourceAddress`is a pointer to the list of IEEE source addresses corresponding to the binding table entries to be backed up.

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

