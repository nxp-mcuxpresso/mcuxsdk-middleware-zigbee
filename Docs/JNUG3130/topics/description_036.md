# Description

This function requests that a back-up of the locally held source binding table is performed on a remote node. This source binding table contains entries only relevant to the local node. The function must be called from a node with a primary binding table cache and the destination node of the request must hold the corresponding back-up binding table cache.

**Note:** This function is provided in the NXP ZDP API for the reason of interoperability with nodes running non-NXP ZigBee PRO stacks that support the generated request. On receiving a request from this function, the NXP ZigBee PRO stack will return the status `ZPS_ZDP_NOT_SUPPORTED`.

This request must include the source binding table entries to be backed up. The request is represented by the structure below \(further detailed in [Section 9.2.2.31](zps_tsaplzdpbackupsourcebindreq.md)\).

`typedef struct {`

`uint16 u16SourceTableEntries; uint16 u16StartIndex;`

`uint16 u16SourceTableListCount;`

`/* Rest of message is variable length */ uint64* pu64SourceAddress;`

`} ZPS_tsAplZdpBackupSourceBindReq;`

On receiving the request, the remote node saves the new source binding table, if possible, overwriting existing entries. If the new table is longer than the previous one, as many extra entries as possible will be saved.

The remote node replies with a Backup\_Source\_Bind\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpBackupSourceBindRsp`\(detailed in [Section 9.2.3.31](zps_tsaplzdpbackupsourcebindrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpBackupSourceBindRequest](../topics/zps_eaplzdpbackupsourcebindrequest.md)

