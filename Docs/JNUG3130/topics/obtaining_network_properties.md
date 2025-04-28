# Obtaining network properties

A ‘network discovery’ is implemented when the function **zps\_eAplZdoStartStack\(\)**is called to start the stack on an End Device or Router node \(which needs to find a network to join\). In addition, a network discovery can be explicitly started by calling the function **zps\_eAplZdoDiscoverNetworks\(\)**. For example, this function could be called if the initial network discovery did not find any suitable networks to join, in which case the function may be used to initiate a scan of previously unscanned channels \(detailed in the stack event described below, resulting from the initial discovery\).

Both of these function calls eventually result in the stack event zps\_EVENT\_NWK\_DISCOVERY\_COMPLETE on the End Device or Router, where this event reports the following properties of the discovered networks:

-   Extended PAN ID
-   ZigBee version
-   ZigBee stack profile

This stack event also indicates the recommended network to join, which is taken to be the first ZigBee PRO network detected that is allowing nodes to join.

For information on joining a network, refer to [Section 6.1.2](starting_routers_and_end_devices.md).

**Parent topic:**[Discovering the network](../topics/discovering_the_network.md)

