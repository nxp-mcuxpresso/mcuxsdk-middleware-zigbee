# Updating network settings

If one or more of the network settings change \(e.g. the radio channel used\), all nodes of the network need to be updated with the new settings.

To allow nodes to keep track of the status of the network settings, the Network Update Identifier is used. This identifier takes a value in the range 0x00 to 0xFF and is incremented when a network update has occurred \(the value wraps around at 0xFF\).

A node can be instructed to update its network settings by sending a Network Update Request to it. The required function is:

**eCLD\_ZllCommissionCommandNetworkUpdateReqCommandSend\(\)**

The payload of the sent command contains the latest network settings and the current value of the Network Update Identifier \(see [Section 44.8.17](tscld_zllcommission_networkupdatereqcommandpayload.md#id_2f60b1a7-5129-41f0-9525-b2a79e7388f2)\). If the payload value is more recent than the value held by the target node, the node should update its network settings with those in the payload.

**Parent topic:**[Using Touchlink](../../touchlink_cluster/topics/using_touchlink.md)

