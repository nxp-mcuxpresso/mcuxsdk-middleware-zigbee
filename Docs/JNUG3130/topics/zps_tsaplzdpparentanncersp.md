# ZPS\_tsAplZdpParentAnnceRsp

This structure is used to store the data for a response to a Parent Announcement message that was sent using the function **ZPS\_eAplZdpParentAnnceReq\(\)**. This response reports any child nodes of the responding node that conflict with child nodes specified in the received Parent Announcement message.

The `ZPS_tsAplZdpParentAnnceRsp`structure is detailed below.

```
typedef struct {
   uint64* pu64ChildList;
   uint8 u8NumberOfChildren;
   uint8 u8Status;
} ZPS_tsAplZdpParentAnnceRsp;
```

where:

-   `pu64ChildList`is a pointer to a list of 64-bit IEEE/MAC addresses of the child nodes in common.
-   `u8NumberOfChildren`is the number of child nodes in common.
-   `u8Status`is the status of the response.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

