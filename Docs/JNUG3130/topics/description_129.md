# Description

This function can be used on the Trust Centre to send the network key to one or multiple nodes. On reaching the target node\(s\), the key is only stored but can be subsequently designated the active network key using the function **ZPS\_eAplZdoSwitchKeyReq\(\)**.

The target node can be specified by means of its network address or IEEE/MAC address. A broadcast to multiple nodes in the network can be achieved by specifying a special network address or IEEE/MAC address - see [Section 9.3](broadcast_addresses.md).

If the destination is a single node, it is possible to send the key to the parent of the destination node.

**Note:** This function also resets the frame counter on the target node\(s\).

**Parent topic:**[ZPS\_eAplZdoTransportNwkKey](../topics/zps_eaplzdotransportnwkkey.md)

