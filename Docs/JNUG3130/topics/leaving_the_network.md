# Leaving the network

A node may leave the network intentionally or unintentionally:

-   The node may be intentionally \(and temporarily\) removed from the network for maintenance work, such as the replacement of batteries.
-   The node may unintentionally leave the network due to unforeseen circumstances, such as a broken radio link with its parent \(an obstacle may have been introduced into the path of the signal\).

A node can be intentionally removed from the network using the function **zps\_eAplZdoLeaveNetwork\(\)**, which issues a leave request. The target node can be the requesting node itself or a child of the requesting node. The application may be designed to call this function when a button is pressed on the requesting node.

When calling **zps\_eAplZdoLeaveNetwork\(\)**:

-   You can specify whether the children of the leaving node should also be requested to leave the network. If this is the case, the leaving node will first automatically call **zps\_eAplZdoLeaveNetwork\(\)** for each of its children.
-   You can specify whether the leaving node should immediately attempt to rejoin the same network after leaving \(see [Section 5.6.2](rejoining_the_network.md)\).

The stack event zps\_EVENT\_NWK\_LEAVE\_INDICATION is generated on the node which has been requested to leave \(this event is also generated when a neighboring node has left the network\). Once a node has been successfully removed from the network as the result of a call to **zps\_eAplZdoLeaveNetwork\(\)**, the stack event zps\_EVENT\_NWK\_LEAVE\_CONFIRM is generated on the requesting node.

The function **zps\_eAplZdpMgmtLeaveRequest\(\)** is also provided which can be used to request a remote node to leave the network.

By default, a Router will always act on leave request messages. However, it may be desirable for a Router to ignore leave request messages in order to prevent a rogue node from disrupting the network. If the function **zps\_vNwkNibSetLeaveAllowed\(\)** is called with the *bLeave*parameter as FALSE, the Router will ignore network leave requests. End Devices always act on leave requests from their parent and ignore leave requests from other nodes.

Alternatively, a callback function can be defined that is invoked when a leave request is received, where this function determines whether the leave request is to be obeyed

- this decision may depend on where the leave request came from. The callback function is registered using **zps\_eAplZdoRegisterZdoLeaveActionCallback\(\)**- refer to the description of this function for details of the callback function.

**Parent topic:**[Leaving and rejoining the network](../topics/leaving_and_rejoining_the_network.md)

