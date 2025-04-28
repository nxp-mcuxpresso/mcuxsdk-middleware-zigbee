# Description

This function can be used \(normally by the Trust Centre\) to request one or multiple nodes to switch to a different active network key. The new network key is specified using its unique sequence number and the key must have been pre-loaded into the target node\(s\) using the function **ZPS\_eAplZdoTransportNwkKey\(\)** or **ZPS\_eAplZdoRequestKeyReq\(\)**.

The target node can be specified by means of its network address or IEEE/MAC address. A broadcast to multiple nodes in the network can be achieved by specifying a special network address or IEEE/MAC address - see [Section 9.3](broadcast_addresses.md).

**Parent topic:**[ZPS\_eAplZdoSwitchKeyReq](../topics/zps_eaplzdoswitchkeyreq.md)

