# Advanced device parameters

These are advanced parameters for Coordinator, Router, and End Device.

**Advanced device parameters**
| Parameter Name | Description | Default Value | Range |
| --- | --- | --- | --- |
|**AF Parameters**|
| - |  |  |  |
| **AIB Parameters** |  |
| APS Designated Coordinator(read only) | Indicates that on start-up the node should assume the Coordinator role within the network. | •    true for Coordinator<br>•    false for Routers / End Devices | true / false |  |
| APS Use Extended PAN ID | Indicates the Extended PAN ID (EPID) that the device will use. This is the globallyunique 64-bit identifier for the network. This identifier is used to avoid PAN ID conflicts between distinct net- works and must be unique among the networks overlappingin a given area. If the value is zero on the Coordinator, the device will use its own IEEE/MAC address as the EPID. A zero value on a Router/End Device means that the device will not look for a particular EPID when joining a network. | Default Extended PAN ID | 64 bits |  |
| APS Inter-frame Delay | Number of milliseconds between APS data frames. Following transmission of each data block, the APS starts a timer. If there are more unacknowledged blocks to send in the current transmission window, then, after a delay of apsInterframeDelaymilliseconds, the next block is passed to the NWK data service. Otherwise, the timer is set to apscAckWaitDuration seconds. | 10 | 10-255 |  |
| APS Max Window Size | APS fragmented data window size. Fragmentation is a way of sending messages (APDUs) longer than the payload of a single NPDU. The ASDU is segmented and split across a number of NPDUs, then reassembled at thedestination. APS Max Window Size defines how many fragments are sent before an acknowledgment is expected. For example, if APS Max Window Size is set to 4 anda message is split into 16 fragments, then an acknowledgment is expected after sending fragments 1-4. Sending offragments 5-8 does not commence until this acknowledgment is received. | 8 | 1-8 |  |
| APS Non-member Radius | Multicast non-member radius size. Defines the number of hops away from the core multi-cast members that a multi-cast transmission can be received. | 2 | 0-7 |  |
| APS Security Timeout Period | Authentication timeout period in milliseconds for nodes joining the network. If either the initiator or responder waits for an expected incoming message for a time greater than APS Security Timeout Period, then a TIMEOUT error is generated. | 1000(6000 is advised) |  |  |
| APS Use Insecure Join | Controls action when a secured network rejoin fails. If true, a join using the MAC layer association procedure is performedwhen a secure rejoin fails. | true | true / false |  |
| **APS Layer Configuration Parameters** |  |
| APS Duplicate Table Size | The size of the APS layer duplicate rejection table. This removes duplicated APS packets. | 8 | 1 or higher |  |
| APS Persistence Time | Time, in milliseconds, for which the resources associated with an incoming fragmented message will be retained after the complete message has been received. | 100 | 1-255 |  |
| Maximum Number of Simultaneous Data Requests | The maximum number of simultaneous APSDE data requests without APS acknowledgments. Should be set to the maximum number of target nodes in one bound transmission. | 5 | 1 or higher |  |
| Maximum Number of Simultaneous Data Requests with Acks | The maximum number of simultaneous APSDE data requests with APS acknowledgments. Should be set to the maximum number of target nodes in one bound transmission. | 3 | 1 or higher |  |
| Inter PAN | True if inter PAN functionality is enabled, see Section 6.5.1.5 | false | true or false |  |
| APS Poll Period | The polling period, in milliseconds, of a sleeping End Device collecting data of any kind (received messages, received fragmented messages and all transmit acknowledgments). | 100 | 25 or higher |  |
| Maximum Number of Received Simultaneous Fragmented Messages | Maximum number of simultaneous fragmented APSDE incoming data requests. Set to a non-zero value to enable reception of fragmented messages (note that doing this increases the stack size). | 0 | 1 or higher |  |
| Maximum Number of Transmitted Simultaneous Fragmented Messages | Maximum number of simultaneous fragmented APSDE outgoing data requests. Set to a non-zero value to enabletransmission of fragmented messages (note that doing this increases the stack size). | 0 | 1 or higher |  |
| **Network Layer Configuration Parameters for Coordinator and Routers** |  |
| Active Neighbor Table Size | Size of the active Neighbor table. Each routing node (Coordinator or Router) has a Neighbor table which must be large enough to accommodate entries for the node’s immediate children, for its own parent and, in a Mesh network, for all peer Routers with which the node has direct radio communication. | 26 | 1 or higher |  |
| Child Table Size | Size of the persisted sub-table of the active Neighbor table. This sub-table contains entries for the node’s parent and immediate children. This value therefore determines the number of children that the node is allowed to have. It is one greater than thepermitted number of children, for example, with the default value of 5, up to 4 children are allowed.This value must not be greater than two- thirds of the Active Neighbor Table Size value. | 5 | 1 or higher |  |
| Address Map Table Size | Size of the address map, which maps 64- bit IEEE addresses to 16-bit network (short) addresses. Should be set to the number of nodes in the network. | 10 | 1 or higher |  |
| Broadcast Transaction Table Size | Size of broadcast transaction table. The broadcast transaction table stores the broadcast transaction records, which are records of the broadcast messages received by the node. | 9 | 1 or higher |  |
| Discovery Neighbor Table Size | Size of the Discovery Neighbor table. This table keeps a list of the neighboring devices associated with the node. | 8 | 8-16 |  |
| Route Discovery Table Size | Size of the Route Discovery table.This table is used by the node to store temporary information used during route discovery. Route Discovery table entries last only as long as the duration of a single route discovery operation. | 2 | 1 or higher |  |
| Route Record Table Size | Size of the Route Record table. Each route record contains the destination network address, a count of the number of relay nodes to reach the destination, and a list of the network addresses of the relay nodes. | 1 | 1 or higher |  |
| Routing Table Size | Size of the Routing table. This table stores the information required for the nodeto participate in the routing of message packets. Each table entry contains the destination address, the status of the route, various flags and the network address of the next hop on the way to the destination. A Routing table entry is made when a new route is initiated by the node or routed via the node. The entry is stored in the Routing table and is read whenever that route is used; the entry is only deleted if the route is no longer valid. A node is said to have routing capacity if there are free entries in the routing table. | 70 | 1 or higher |  |
| Security Material Sets | Number of supported network keys. | 2 | 1 or higher |  |
| **Network Layer Configuration Parameters for End Devices** |
| Active Neighbor Table Size | Size of the active Neighbor table. Set to one (for the parent). | 2 | 1 |
| Address Map Table Size | Size of the address map, which maps 64- bit IEEE addresses to 16-bit network (short) addresses. Should be set to the number of nodes that the End Device applicationneeds to communicate with plus one (for the parent). | 10 | 1 or higher |
| Broadcast Transaction Table Size | Size of broadcast transaction table. The broadcast transaction table stores the broadcast transaction records, which are records of the broadcast messages received by the node. | 9 | 1 or higher |
| Discovery Neighbor Table Size | Size of the Discovery Neighbor table. This table keeps a list of the neighboring devices associated with the node. | 8 | 8-16 |
| Route Discovery Table Size | Not applicable - set to one. | 2 | 1 |
| Route Record Table Size | Not applicable - set to one. | 1 | 1 |
| Routing Table Size | Not applicable - set to one. | 70 | 1 |
| Security Material Sets | Number of supported network keys. | 2 | 1 or higher |
| Stack Profile | The ZigBee Stack Profile which defines the stack features supported. Set to one for ZigBee, two for ZigBee PRO or any other value for a private stack profile. | 2 | 0 to 15 |


```{include} ../topics/endpoint_parameters.md
:heading-offset: 2
```

```{include} ../topics/bound_addressing_table.md
:heading-offset: 2
```

```{include} ../topics/pdu_manager.md
:heading-offset: 2
```

```{include} ../topics/group_addressing_table.md
:heading-offset: 2
```

```{include} ../topics/rf_channels.md
:heading-offset: 2
```

```{include} ../topics/mac_interface_table.md
:heading-offset: 2
```

```{include} ../topics/node_descriptor_001.md
:heading-offset: 2
```

```{include} ../topics/node_power_descriptor.md
:heading-offset: 2
```

```{include} ../topics/key_descriptor_table.md
:heading-offset: 2
```

```{include} ../topics/trust_centre.md
:heading-offset: 2
```

**Parent topic:**[ZigBee network parameters](../topics/zigbee_network_parameters.md)

