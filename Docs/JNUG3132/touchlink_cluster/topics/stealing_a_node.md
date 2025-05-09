# Stealing a node

A node that is already part of a network can be taken or ‘stolen’ by another network using Touchlink \(in which case, the stolen node will cease to be a member of its previous network\). This transfer can only be performed on a node which supports one or more Lighting devices \(and not Controller devices\).

The node is stolen using an initiator in the new network, e.g. from a remote control unit. The ‘stealing’ process is as follows:

1. The initiator sends a Scan Request to nodes in its vicinity. The required function is:

-   **eCLD\_ZllCommissionCommandScanReqCommandSend\(\)**

2. A receiving node replies to the Scan Request by sending a Scan Response. The required function is:

-   **eCLD\_ZllCommissionCommandScanRspCommandSend\(\)**

3. The initiator receives Scan Responses from one or more nodes and, based on these responses, selects a node \(containing a Lighting device\) that is already a member of another network.

4. The initiator then sends a Reset To Factory New Request to the desired node. The required function is:

-   **eCLD\_ZllCommissionCommandFactoryResetReqCommandSend\(\)**

5. On receiving this request on the target node, the event E\_CLD\_COMMISSION\_CMD\_FACTORY\_RESET\_REQ is generated and the function **ZPS\_eAplZdoLeaveNetwork\(\)** should be called. In addition, all persistent data should be reset.

6. The node can then be commissioned into the new network by following the process in [Section 44.4.2](adding_to_an_existing_network.md#id_720ce516-2e3f-45a7-8bbf-3353c5e086a5) from Step3.

Alternatively, instead of following the above process, a node can be stolen by either:

-   Following the full process for creating a network in [Section 44.4.1](creating_a_network.md#id_6d866c73-990f-4fe5-91d0-771984815a0d) and calling **ZPS\_eAplZdoLeaveNetwork\(\)**on the target node when a Network Start Request is received.

-   Following the full process for adding a node in [Section 44.4.2](adding_to_an_existing_network.md#id_720ce516-2e3f-45a7-8bbf-3353c5e086a5) and calling **ZPS\_eAplZdoLeaveNetwork\(\)**on the target node when a Network Join Router Request or Network Join End Device Request is received.


**Note:** If a node containing a Controller device \(e.g. a remote control unit\) is to be used in another network, it must first be reset using a Reset To Factory New Request. It can then be used to create a new network \(see [Section 44.4.1](creating_a_network.md#id_6d866c73-990f-4fe5-91d0-771984815a0d)\) or to learn the control information of an existing network \(see [Section 44.5](using_the_commissioning_utility.md#id_ba07220a-e60c-4f4b-9c9c-f8ef4fef96f8)\).

**Parent topic:**[Using Touchlink](../../touchlink_cluster/topics/using_touchlink.md)

