# Parameters

-   *pvNwk* Pointer to NWK layer instance
-   *u16DstAddress* Network address of the remote node to which the status command relates \(for example, the node for which a routing problem is being reported\)
-   *u16TargetAddress* Network address of the node to which the status command is to be sent \(for example, the parent of the local node\)
-   *u8CommandId* Value representing the network status command to be sent \(the possible values are provided in the ZigBee PRO specification\)
-   *u8Radius* Maximum number of hops permitted to target node \(zero value specifies that default maximum is to be used\)

**Parent topic:**[ZPS\_vNwkSendNwkStatusCommand](../topics/zps_vnwksendnwkstatuscommand.md)

