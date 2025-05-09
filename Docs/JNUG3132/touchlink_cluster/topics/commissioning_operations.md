# Commissioning operations

Commissioning involves forming a network or adding a new node to an existing network. A node from which commissioning can be initiated is referred to as an ‘initiator’ - this may be a remote control unit, but could also be a lamp.

-   An ‘initiator’ node must support the Touchlink Commissioning cluster as a client.

-   A node to be added to the network must support the Touchlink Commissioning cluster as a server \(or as both a server and client\).


Note that commissioning a new network involves adding at least one node to the new network \(as well as the initiator\).

Commissioning may involve two stages, depending on the type of node added to the network by the initiator:

1. The node is added to the network using the Touchlink commands of the Touchlink Commissioning cluster. In practice for the user, this typically involves bringing the initiator node physically close to the target node and pressing a button.

2. If the initiator node and the new node will both be used to control lights in the network, the new node must learn certain information \(such as controlled endpoints and configured groups\) from the initiator. This exchange of information uses the Commissioning Utility commands of the Touchlink Commissioning cluster.

**Note:** **Note:**The Touchlink Commissioning cluster instance for Touchlink must reside on its own endpoint on a node. Therefore, a Touchlink commissioning application must be provided which is distinct from the main application. However, the cluster instance for the Commissioning Utility can reside on the same endpoint as the main application \(and be used in this application\).

Commissioning using the supplied functions for Touchlink and the Commissioning Utilty is described in [Section 44.4](using_touchlink.md#id_f01fd7b4-9690-422c-a1bd-7aeddd320a43) and [Section 44.5](using_the_commissioning_utility.md#id_ba07220a-e60c-4f4b-9c9c-f8ef4fef96f8).

**Parent topic:**[Touchlink Commissioning Cluster](../../touchlink_cluster/topics/touchlink_commissioning_cluster.md)

