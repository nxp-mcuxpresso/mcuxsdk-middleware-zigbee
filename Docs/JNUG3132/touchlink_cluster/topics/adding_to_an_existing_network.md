# Adding to an existing network

A network \(that has been set up as described in [Section 44.4.1](creating_a_network.md#id_6d866c73-990f-4fe5-91d0-771984815a0d)\) can be extended by adding a node. The Touchlink extension process is described below and illustrated in the figure below (also refer to the command list in [Table 1](using_touchlink.md#table_6ebf31ca-9136-43fd-8da4-20bc355ef70b)\).

**Note:** Received Touchlink requests and responses are handled as ZigBee PRO events. The event handling is not detailed below but is outlined in [Section 44.6](touchlink_commissioning_events.md#id_f14c3fbe-3d56-47d4-b26a-0df6fdc28ad1).

1. **Scan Request:** The initiator sends a Scan Request to nodes in its vicinity. The required function is:

-   **eCLD\_ZllCommissionCommandScanReqCommandSend\(\)**

2. **Scan Response:** A receiving node replies to the Scan Request by sending a Scan Response. The required function is:

-   **eCLD\_ZllCommissionCommandScanRspCommandSend\(\)**

3. **Device Information Request:** The initiator sends a Device Information Request to those detected nodes that are of interest. The required function is:

-   **eCLD\_ZllCommissionCommandDeviceInfoReqCommandSend\(\)**

4. **Device Information Response:** A receiving node replies to the Device Information Request by sending a Device Information Response. The required function is:

-   **eCLD\_ZllCommissionCommandDeviceInfoRspCommandSend\(\)**

5. **Identify Request \(Optional\):** The initiator may send an Identify Request to the node which has been chosen to be added to the network, in order to confirm that the correct physical node is being commissioned. The required function is:

-   **eCLD\_ZllCommissionCommandDeviceIdentifyReqCommandSend\(\)**

6. **Network Join Request:** Depending on the target node type, the initiator sends a Network Join Router Request or Network Join End Device Request, as appropriate, to the target node. The required function is one of:

-   **eCLD\_ZllCommissionCommandNetworkJoinRouterReqCommandSend\(\)**
-   **eCLD\_ZllCommissionCommandNetworkJoinEndDeviceReqCommandSend\(\)**

7. **Network Join Response:** Depending on the receiving node type, the node replies to the join request by sending a Network Join Router Response or Network Join End Device Response. The required function is one of:

-   **eCLD\_ZllCommissionCommandNetworkJoinRouterRspCommandSend\(\)**
-   **eCLD\_ZllCommissionCommandNetworkJoinEndDeviceRspCommandSend\(\)**

The node should now be a member of the network. The initiator then collects endpoint and cluster information from any Lighting device\(s\) on the new node, and stores this information in its local lighting database.

If the new node is to be used to control the light nodes of the network then it will need to learn certain information \(such as controlled endpoints and configured groups\) from the initiator - this is done using the Commissioning Utility commands, as described in [Section 44.5](using_the_commissioning_utility.md#id_ba07220a-e60c-4f4b-9c9c-f8ef4fef96f8).  


**Extending a Network (Adding a Node)**

![Extending a Network (Adding a Node)](../images/touchlink1.svg "Extending a Network (Adding a Node)")

**Parent topic:**[Using Touchlink](../../touchlink_cluster/topics/using_touchlink.md)

