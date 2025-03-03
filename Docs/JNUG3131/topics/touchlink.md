# Touchlink

Touchlink commissioning is used to form a new network and/or join a node to an existing network. Touchlink is initiated on a node called the ‘initiator’ which either is a member of an existing network or \(if not\) creates a new network. In both cases, the initiator joins a second node to the network, called the ‘target’ node.

Touchlink is provided as a cluster in the **ZigBee Cluster Library \(ZCL\)**. The initiator must support the Touchlink cluster as a client and the target node must support the cluster as a server. If it is required on a node, Touchlink commissioning must be enabled via the ZigBee Base Device attribute *u8bdbCommissioningMode*. For detailed information on the Touchlink Commissioning cluster and how to implement Touchlink, refer to the *(ZigBee Cluster Library User Guide \(JNUG3132\)[https://kex-daily.nxp.com/mcuxsdk-internal/latest/html/_static/wireless/Zigbee/JN-UG-3132-ZigBee3-Cluster-Library.pdf]*.

A ‘Touchlink Pre-configured Link Key’ is provided, which is used during the commissioning of a node into a secured network \(see [Network security](network_security.md#ID_4C903549-A2A4-4958-A885-54D50242FB72)\).

If Touchlink commissioning is not successful, this is indicated by a status of `NO_SCAN_RESPONSE` through the attribute *ebdbCommissioningStatus* \(all other states indicate success\).

**Parent topic:**[Network commissioning](../topics/network_commissioning.md)

