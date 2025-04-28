# Discovery

The ZigBee specification provides the facility for devices to find out about the capabilities of other nodes on a network, such as their addresses, which types of applications are running on them, their power source and sleep behavior. This information is stored in descriptors \(see [Section 3.4.6](discovery.md)\) on each node, and is used by the enquiring node to adapt its behavior to the requirements of the network.

Discovery is typically used when a node is being introduced into a user-configured network, such as a domestic security or lighting control system. It may require the user to press a button or similar to begin the process of integration of the device into the network. The first task is to find out if there are any appropriate devices with which the new node can communicate.


```{include} ../topics/device_discovery.md
:heading-offset: 3
```

```{include} ../topics/service_discovery_001.md
:heading-offset: 3
```

**Parent topic:**[Application level concepts](../topics/application_level_concepts.md)

