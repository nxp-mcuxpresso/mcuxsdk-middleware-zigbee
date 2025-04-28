# Broadcast addresses

When sending a request using a ZDP API function, the request can be broadcast to all nodes in the network by specifying a special 16-bit network address \(0xFFFF\) or 64-bit IEEE/MAC address \(0xFFFFFFFFFFFFFFFF\). Other broadcast options are also available in order to target particular groups of nodes, as indicated in the table below.

|**Address Type**|**Broadcast Address**|**Target Nodes**|
|----------------|---------------------|----------------|
|Network \(16-bit\)|0xFFFF|All nodes in the network|
|0xFFFD|All nodes for which ‘Rx on when idle’ is TRUE|
|0xFFFC|All Routers and the Coordinator|
|IEEE/MAC \(64-bit\)|0xFFFFFFFFFFFFFFFF|All nodes in the network|

**Parent topic:**[ZigBee Device Profile \(ZDP\) API](../topics/zigbee_device_profile_zdp_api.md)

