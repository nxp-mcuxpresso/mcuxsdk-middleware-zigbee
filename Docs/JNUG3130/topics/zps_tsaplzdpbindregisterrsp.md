# ZPS\_tsAplZdpBindRegisterRsp

This structure is used to store Bind\_Register\_rsp message data - a response to a call to the function **ZPS\_eAplZdpBindRegisterRequest\(\)**. This response contains binding information held on the responding node concerning the requesting node.

The `ZPS_tsAplZdpBindRegisterRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16BindingTableEntries;
    uint16 u16BindingTableListCount;
    /* Rest of the message is variable Length */
    ZPS_tsAplZdpBindingTable sBindingTableList;
} ZPS_tsAplZdpBindRegisterRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpBindRegisterRequest\(\)**.
-   `u16BindingTableEntries`is the total number of binding table entries concerning the requesting node held on the responding node.
-   `u16BindingTableListCount`is the number of binding table entries concerning the requesting node contained in this response.
-   `sBindingTableList`is a pointer to the first item in the list of reported binding table entries. A list item is of type `ZPS_tsAplZdpBindingTable`detailed below.


```{include} ../topics/zps_tsaplzdpbindingtable.md
:heading-offset: 4
```

```{include} ../topics/zps_tsaplzdpbindingtableentry.md
:heading-offset: 4
```

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

