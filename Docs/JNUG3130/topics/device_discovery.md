# Device discovery

Device discovery returns information about the addresses of a network node. The retrieved information can be the IEEE/MAC address of the node with a given network address, or the network address of a node with a given IEEE/MAC address. If the node being interrogated is a Router or Coordinator, it may optionally supply the addresses of all the devices that are associated with it, as well as its own address. In this way, it is possible to discover all the devices on a network by requesting this information from the Coordinator \(network address 0x0000\) and then using the list of addresses corresponding to the children of the Coordinator to launch other queries about their child nodes.

**Parent topic:**[Discovery](../topics/discovery.md)

