# Description

This function requests that a back-up of the locally held primary binding table cache is performed on a remote node - the whole or part of the table can be backed up. The destination node of the request must hold the corresponding back-up binding table cache. The latter must already exist and be associated with the cache on the local node through a previous discovery.

**Note:** This function is provided in the NXP ZDP API for the reason of interoperability with nodes running non-NXP ZigBee PRO stacks that support the generated request. On receiving a request from this function, the NXP ZigBee PRO stack will return the status `ZPS_ZDP_NOT_SUPPORTED`.

This request must include the binding table entries to be backed up. The request is represented by the structure below \(further detailed in [Section 9.2.2.29](zps_tsaplzdpbackupbindtablereq.md)\).

`typedef struct {`

`uint16 u16BindingTableEntries; uint16 u16StartIndex;`

`uint16 u16BindingTableListCount;`

`/* Rest of message is variable length */ ZPS_tsAplZdpBindingTable sBindingTable;`

`} ZPS_tsAplZdpBackupBindTableReq;`

On receiving the request, the remote node saves the new binding table, if possible, overwriting existing entries. If the new table is longer than the previous one, as many extra entries as possible will be saved.

The remote node replies with a Backup\_Bind\_Table\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpBackupBindTableRsp`\(detailed in [Section 9.2.3.29](zps_tsaplzdpbackupbindtablersp.md)\).

**Parent topic:**[ZPS\_eAplZdpBackupBindTableRequest](../topics/zps_eaplzdpbackupbindtablerequest.md)

