# ZPS\_tsAplZdpMgmtBindRsp

This structure is used to store Mgmt\_Bind\_rsp message data - a response to a call to the function **ZPS\_eAplZdpMgmtBindRequest\(\)**. This response reports the contents of the remote node’s Binding table.

The `ZPS_tsAplZdpMgmtBindRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16BindingTableEntries;
    uint16 u16StartIndex;
    uint16 u16BindingTableListCount;
    /* Rest of the message is variable length */
    ZPS_tsAplZdpBindingTable sBindingTableList;
} ZPS_tsAplZdpMgmtBindRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpMgmtBindRequest\(\)**
-   `u16BindingTableEntries`is the total number of Binding table entries on the remote node
-   `u8StartIndex`is the Binding table index of the first entry reported in this response \(through `sBindingTableList`\)
-   `u16BindingTableListCount`is the number of Binding table entries reported in this response \(through `sBindingTableList`\)
-   `sBindingTableList`is a pointer to the first entry in the list of reported Binding table entries. Each entry is of the type `ZPS_tsAplZdpBindingTable`, detailed in [Section 9.2.2.29](zps_tsaplzdpbackupbindtablereq.md)

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

