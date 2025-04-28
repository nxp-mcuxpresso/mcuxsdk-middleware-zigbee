# Description

This function requests the removal of an entry in the back-up binding table cache on a remote node. The function must be called from the node with the corresponding primary binding table cache. The removal of a back-up entry is normally required when an entry in the primary binding table cache has been removed.

**Note:** This function is provided in the NXP ZDP API for the reason of interoperability with nodes running non-NXP ZigBee PRO stacks that support the generated request. On receiving a request from this function, the NXP ZigBee PRO stack will return the status `ZPS_ZDP_NOT_SUPPORTED`.

This request must include the binding table entry to be removed. The request is represented by the structure below \(further detailed in [Section 9.2.2.28](zps_tsaplzdpremovebkupbindentryreq.md)\).

`typedef struct {`

`uint64 u64SrcAddress; uint8 u8SrcEndPoint; uint16 u16ClusterId; uint8 u8DstAddrMode; union {`

`struct {`

`uint16 u16DstAddress;`

`} sShort; struct {`

`uint64 u64DstAddress; uint8 u8DstEndPoint;`

`} sExtended;`

`};`

`} ZPS_tsAplZdpRemoveBkupBindEntryReq;`

On receiving the request, the remote node removes the specified binding table entry from its back-up binding table cache, if possible.

The remote node replies with a Remove\_Bkup\_Bind\_Entry\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)**and stored in a structure of type `ZPS_tsAplZdpRemoveBkupBindEntryRsp`\(detailed in [Section](zps_tsaplzdpremovebkupbindentryrsp.md)[9.2.3.28](zps_tsaplzdpremovebkupbindentryrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpRemoveBkupBindEntryRequest](../topics/zps_eaplzdpremovebkupbindentryrequest.md)

