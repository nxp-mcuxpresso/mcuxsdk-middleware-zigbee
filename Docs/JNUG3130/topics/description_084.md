# Description

This function requests that a back-up of an entry in the local primary binding table cache is performed on a remote node. The destination node of the request must hold the corresponding back-up binding table cache. The back-up operation is normally required when a new entry has been added to the primary binding table cache.

**Note:** This function is provided in the NXP ZDP API for the reason of interoperability with nodes running non-NXP ZigBee PRO stacks that support the generated request. On receiving a request from this function, the NXP ZigBee PRO stack will return the status `ZPS_ZDP_NOT_SUPPORTED`.

This request must include the binding table entry to be backed up. The request is represented by the structure below \(further detailed in [Section 9.2.2.27](zps_tsaplzdpstorebkupbindentryreq.md)\).

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

On receiving the request, the remote node adds the specified binding table entry to its back-up binding table cache, if possible.

The remote node replies with a Store\_Bkup\_Bind\_Entry\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpStoreBkupBindEntryRsp`\(detailed in [Section 9.2.3.27](zps_tsaplzdpstorebkupbindentryrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpStoreBkupBindEntryRequest](../topics/zps_eaplzdpstorebkupbindentryrequest.md)

