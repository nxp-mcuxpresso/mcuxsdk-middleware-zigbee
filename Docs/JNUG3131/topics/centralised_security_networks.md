# Centralized security networks

A centralized security network is formed by a Coordinator, which also acts as the Trust Centre for the network. When a node attempts to join the network, it is authenticated by this Trust Centre before it is allowed into the network.

For participation in centralized security networks, all nodes must be pre-configured with a link key. This key is used to encrypt the network key when passing it from the Trust Centre to a newly joined node. When a node joins a network with centralized security, the ZigBee Base Device automatically uses the relevant pre-configured link key. Similar is the case for a Coordinator that forms a new centralized security network.

The following key types can be pre-configured for centralized security:

-   **Default Global Trust Centre Link Key:** This key is factory-programmed into all nodes and is used to encrypt communications between the Trust Centre and a joining node.

-   **Touchlink Pre-configured Link Key:** This key is factory-programmed into all nodes that can employ Touchlink commissioning and is used to encrypt communications between the Router parent and a joining node. The Touchlink Pre-configured Link Key can be one of three types:

    -   Development key, used during development before ZigBee certification

    -   Master key, used after successful ZigBee certification

    -   Certification key, used during ZigBee certification testing

        -   The link key used in the final products should be a ‘master key’, which results from the successful ZigBee certification of the product.
-   **Install Code-derived Pre-configured Link Key:** This key is derived by the ZigBee stack from a random install code which is assigned to each Router and End Device node in the factory. The install code is factory-programmed into the node but provided to the Trust Centre via out-of-band means when the node is commissioned. The use of install codes is described in more detail below.


## Install Codes 

An install code is used to create an initial link key employed in commissioning an individual node into a centralized security network. An install code is assigned to the node in the factory. It is a random code but is not necessarily unique \(the same install code may be randomly generated for more than one node\). The ZigBee stack derives a link key from the install code using a Matyas-Meyer-Oseas hash function. The install code is factory-programmed into the node and also accompanies the node \(for example: in printed form\) when it leaves the factory. The process of using an install code to commission a node is outlined below.

In the factory:

1. An install code is randomly generated for the individual node.

2. The install code is programmed into the node.

3. A pre-configured link key is derived from the install code by the ZigBee stack.

4. The install code is shipped with the node \(by some unspecified means\).

During installation:

5. The install code that was shipped with the node is installed into the Co-ordinator/Trust Centre.

6. The pre-configured link key is derived from the install code by the ZigBee stack of the Co-ordinator/Trust Centre.

7. The Trust Centre and node then use the pre-configured link key in joining the node to the network \(for example: to encrypt/decrypt the network key\).

More detailed information about install codes are available in the *ZigBee Base Device Behavior Specification \(13-0402-08\)*.

**Parent topic:**[Network security](../topics/network_security.md)

