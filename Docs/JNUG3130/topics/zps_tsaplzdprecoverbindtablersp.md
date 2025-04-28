# ZPS\_tsAplZdpRecoverBindTableRsp

This structure is used to store Recover\_Bind\_Table\_rsp message data - a response to a call to the function **ZPS\_eAplZdpRecoverBindTableRequest\(\)**. This response indicates the status of the recover request and contains the recovered binding table entries.

The `ZPS_tsAplZdpRecoverBindTableRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16StartIndex;
    uint16 u16BindingTableEntries;
    uint16 u16BindingTableListCount;
    /* Rest of the message is variable length */
    ZPS_tsAplZdpBindingTable sBindingTableList;
} ZPS_tsAplZdpRecoverBindTableRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpRecoverBindTableRequest\(\)**
-   `u16StartIndex`is the binding table index of the first entry in the set of recovered binding table entries \(`sBindingTableList`\)
-   `u16BindingTableEntries`is the total number of entries in the back-up binding table cache
-   `u16BindingTableListCount`is the number of entries in the set of recovered binding table entries \(`sBindingTableList`\)
-   `sBindingTableList`is a pointer to the first item in the list of recovered binding table entries. A list item is of type `ZPS_tsAplZdpBindingTable`, detailed in [Section 8.2.3.26](zps_tsaplzdpbindregisterrsp.md).

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

