# Network steering

Network Steering is used to join the local node to an existing network or allow other nodes to join a network via the local node.

If Network Steering is required on a node, enable it via the attribute *u8bdbCommissioningMode*. You can start Network Steering from your application by calling the function **BDB\_eNsStartNwkSteering\(\)**.

The path taken depends on whether the local node is already a member of a network, as indicated by the Boolean attribute *bbdbNodeIsOnANetwork*. In all cases, the outcome of Network Steering is indicated by events passed into the callback function **APP\_vBdbCallback\(\)**.

## Node is already on a network

When the node is a member of a network, it opens the network for other nodes to join for a fixed time period. It performs this by broadcasting a Management Permit Joining request \(any node type can open the network in this way\). This period is 180 seconds by default, but can be configured \(in seconds\) through the ZigBee Base Device constant **BDBC\_MIN\_COMMISSIONING\_TIME** \(see [Constants](constants.md#ID_CB648524-D2DB-4870-A0F0-C766A7E87AA0)\). After initiating the above broadcast, the event `BDB_EVENT_NWK_STEERING_SUCCESS` is generated.

## Node is not on a network

When the node is not a member of a network and is a Router or End Device, it searches for a suitable network to join. If it finds one, it attempts to join the network, as follows:

1. The node performs a network discovery by scanning the primary set of radio channels specified through the *u32bdbPrimaryChannelSet* bitmap \(attribute\). If no open network is found, the network discovery is repeated on the secondary set of radio channels specified through the *u32bdbSecondaryChannelSet* bitmap \(attribute\). If still no network is found, the event `BDB_EVENT_NO_NETWORK` is generated and the Network Steering is abandoned.

2. If at least one open network is found, the node then attempts to join each discovered open network one by one, up to a maximum of **BDBC\_MAX\_SAME\_NETWORK\_RETRY\_ATTEMPTS** times. If a network is successfully joined, the attribute *bbdbNodeIsOnANetwork* is set to TRUE. If there is no successful join following a scan of the primary channels, the scan is repeated \(Step 1\) on the secondary channels. If there is still no successful join following this scan, the `BDB_EVENT_NWK_JOIN_FAILURE` event is generated and the Network Steering is abandoned.

3. The joining node is authenticated and receives the network key from its parent. If the network being joined has centralized security and therefore a Trust Centre, the node unicasts a Node Descriptor request to the Trust Centre. The Node Descriptor received back is checked to ensure that the Trust Centre supports the ZigBee PRO stack version r21 or above. If so, the node performs the procedure for retrieving a new Trust Centre link key to replace its pre-configured link key. Failure at any point is indicated to the application by a BDB\_EVENT\_NWK\_JOIN\_FAILURE event.

4. On successful completion of the above steps, the joining node requests that the ‘permit joining’ time \(for new nodes to join the network\) is extended by **BDBC\_MIN\_COMMISSIONING\_TIME** \(180 s by default\) and generates a `BDB_EVENT_NWK_STEERING_SUCCESS` event for the application.

Depending on the outcome of the above Network Steering process:

-   If the node successfully joins a network, you may wish to bind the node to another node or add the node to a group, wherein it is necessary to continue to the Finding and Binding stage, described in [Finding and Binding](finding_and_binding.md#).

-   If the node fails to join a network, you may wish to make sure that the desired network is open for joining and reinitiate this Network Steering procedure. If there is a Router node, the application may opt to form its own distributed network, wherein it is necessary to continue to the Network Formation stage described in [Network Formation](network_formation.md#ID_FF746201-046E-48EF-82F0-608A6E5D4F33).


**Parent topic:**[Network commissioning](../topics/network_commissioning.md)

