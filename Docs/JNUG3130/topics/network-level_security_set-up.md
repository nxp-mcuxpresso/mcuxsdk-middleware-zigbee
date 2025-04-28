# Network-level security set-up

The function **zps\_vAplSecSetInitialSecurityState\(\)**, described above, initiates the set-up process for network-level security and requires the type of initial security key to be specified as one of:

-   Pre-configured global link key
-   Pre-configured unique link key

These keys are described in [Section 5.8.2](security_key_types.md). They are used to encrypt the network key when it is transported to a joining node.

The Trust Centre and other nodes must be pre-programmed with the relevant pre- configured link key\(s\). This key can be specified in the application code for the node and referenced by **zps\_vAplSecSetInitialSecurityState\(\)** or can be set through the Key Descriptor parameter *Key*in the ZPS Configuration Editor on both the Trust Centre and other node\(s\). In the case of a unique link key, the IEEE/MAC address of the node must also be pre-programmed into the Trust Centre along with the link key. For the Key Descriptor parameters, refer to [Section 11.7.9](key_descriptor_table.md).

**Note:** Pre-configured link keys entered via the ZPS Configuration Editor are held in a Key Descriptor Table on the Trust Centre, with one entry for each node/key. The key for a node with a given IEEE/MAC address can be obtained \(locally\) from this table using the function **zps\_psGetActiveKey\(\)**.

The Trust Centre generates a random network key to be used in network-level communications between all nodes. When a new node joins the network, the Trust Centre transports this network key, encrypted using the appropriate pre-configured link key, to the newly joined node.

**Note:**

1.  The application on the Trust Centre can take control \(from the stack\) of whether a node is allowed to join the network \(possibly using its pre-configured link key\) through a user-defined callback function. If required, this callback function must be registered using the **function zps\_vTCSetCallback\(\)**. For more details, refer to the function description.
2.  When a device joins a ZigBee network and requires authentication which involves transporting a network key to it, the parent opens an authentication interval during which the joining device must announce itself to the network. This interval begins from the transmission of a rejoin response \(if the device joins through a NWK layer rejoin\) or an association response \(if it joins through an IEEE 802.15.4 association\). If the device fails to announce itself during this interval, the parent removes the Neighbor table entry for the joining device to ensure that the child capacity of the parent is maintained. This authentication interval must be set on all potential parent nodes via the network parameter APS Security Timeout Period \(see Section 11.7\), which is 1 second by default but 6 seconds is a more reasonable setting.

**Parent topic:**[Setting up ZigBee security](../topics/setting_up_zigbee_security.md)

