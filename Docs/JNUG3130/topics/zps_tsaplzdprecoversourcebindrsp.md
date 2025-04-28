# ZPS\_tsAplZdpRecoverSourceBindRsp

This structure is used to store Recover\_Source\_Bind\_rsp message data - a response to a call to the function **ZPS\_eAplZdpRecoverSourceBindRequest\(\)**. This response indicates the status of the recover request and contains the recovered binding table entries.

The `ZPS_tsAplZdpRecoverSourceBindRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16StartIndex;
    uint16 u16SourceTableEntries;
    uint16 u16SourceTableListCount;
    /* Rest of the message is variable length */
    uint64* pu64SourceTableList;
} ZPS_tsAplZdpRecoverSourceBindRsp;
```

where:

-   `u8Status`is the return status for the function **ZPS\_eAplZdpRecoverSourceBindRequest\(\)**.

-   `u16StartIndex`is the binding table index of the first entry in the set of recovered binding table entries \(`pu64SourceTableList`\).
-   `u16SourceTableEntries`is the total number of source binding table entries in the back-up binding table cache.
-   `u16SourceTableListCount`is the number of entries in the set of recovered binding table entries. \(`pu64SourceTableList`\).
-   `pu64SourceTableList`is a pointer to the first item in the list of recovered binding table entries.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

