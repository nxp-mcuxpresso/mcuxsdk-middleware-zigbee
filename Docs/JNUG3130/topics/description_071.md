# Description

This function can be used to request a node to leave the network. The leaving node can be a child of the requesting node or can be the requesting node itself \(excluding the Coordinator\).

The node being asked to leave the network is specified by means of its IEEE \(MAC\) address \(or zero, if a node is requesting itself to leave the network\). You must also:

-   Use the parameter *bRemoveChildren* to specify whether children of the leaving node must leave their parent - if this is the case, the leaving node will automatically call **ZPS\_eAplZdoLeaveNetwork\(\)** for each of its children. This parameter must always be set to FALSE when the function is called on an End Device \(as there are no children\).
-   Use the parameter *bRejoin*to specify whether the leaving node must attempt to rejoin the network \(probably via another parent\) immediately after leaving.

**Note:** If you wish to move a whole network branch from under the requesting node to a different parent node, set `bRemoveChildren` to FALSE and `bRejoin` to TRUE.

If this function successfully initiates the removal of a node, ZPS\_E\_SUCCESS will be returned. Subsequently, when the removal is complete, the stack event ZPS\_EVENT\_NWK\_LEAVE\_CONFIRM is generated. For details of this event, refer to [Section 7.2.2.12](zps_tsafnwkleaveconfevent.md).

**Parent topic:**[ZPS\_eAplZdoLeaveNetwork](../topics/zps_eaplzdoleavenetwork.md)

