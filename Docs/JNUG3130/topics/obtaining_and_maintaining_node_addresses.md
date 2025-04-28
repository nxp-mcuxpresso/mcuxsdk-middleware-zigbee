# Obtaining and maintaining node addresses

The addresses of network nodes are needed in order to access node information \(see [Section 6.2.4](obtaining_node_properties.md)\), send data from one node to another \(see [Section 6.5](transferring_data.md)\) and bind nodes together \(see [Section 6.4](binding_001.md)\). In most of these operations, an application can specify either 64-bit IEEE/MAC addresses or 16-bit network addresses, but the ZigBee PRO stack always works with network addresses. If the IEEE address \(rather than the network address\) of a remote node is specified by the application, the network address must still be available to the stack in an Address Map - see below.

The IEEE address of a node is assigned at the time of device manufacture and is fixed, while its network address is dynamically allocated by its parent when the device joins the network \(this address may change if the network is re-started or the device later leaves and rejoins the network\). Functions are provided to obtain the IEEE address of a node given its network address or to obtain the network address given the IEEE address. Use of these functions is described in [Section 6.2.3.1](obtaining_ieee_address.md) and [Section 6.2.3.2](obtaining_network_address.md).

**Note:** The IEEE/MAC and network addresses of a node can be broadcast to all other nodes in the network using the function zps\_eAplZdpDeviceAnnceRequest\(\). For example, this function would typically be called when the node joins or rejoins the network. The information is sent in a Device\_annce announcement, which must be collected by the recipient nodes using the function ZQ\_bZQueueReceive\(\).

An Address Map table can be maintained on a node, where each entry of this table contains the pair of addresses for a remote node - the 64-bit IEEE/MAC address and 16-bit network address. In fact, the IEEE/MAC address is not directly stored in the Address Map table but in a MAC Address table - the Address Map table contains the index of this address in the MAC Address table. The Address Map is automatically updated by the stack when a Device\_annce announcement is received from a remote node \(described in the Note above\), but you can also add an address-pair to this table using the function **zps\_eAplZdoAddAddrMapEntry\(\)**- *never write to the Address Map table directly*. The Address Map must be properly maintained if the application employs IEEE/MAC addresses to identify remote nodes. In addition, when application- level security \(see [Section 6.8](implementing_zigbee_security.md)\) is used in sending data from one node to another, the Address Map on the sending node must contain an entry for the target node.


```{include} ../topics/obtaining_ieee_address.md
:heading-offset: 3
```

```{include} ../topics/obtaining_network_address.md
:heading-offset: 3
```

**Parent topic:**[Discovering the network](../topics/discovering_the_network.md)

