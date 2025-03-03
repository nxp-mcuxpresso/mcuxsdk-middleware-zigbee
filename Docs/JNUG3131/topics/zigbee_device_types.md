# ZigBee device types

A device type is a software entity which defines the functionality of a ZigBee node. The device type defines a collection of clusters that make up this functionality. A cluster is therefore a basic building-block of device functionality. Some clusters are mandatory and some are optional. For example, the Thermostat device uses the Basic and Temperature Measurement clusters, and can also use one or more optional clusters.

**Note:** The clusters used by a device type are supplied in the ZigBee Cluster Library \(ZCL\). The ZCL is detailed in the *ZigBee Cluster Library \(for ZigBee 3.0\) User Guide \(JNUG3132\)*.

A device is an instance of a device type.

A network node can support more than one device type. The application for a device type runs on a software entity called an endpoint and each node can have up to 240 endpoints, numbered from 1.

In addition, every ZigBee 3.0 node must employ the following devices:

-  **ZigBee Base Device (ZBD):** This is a standard device type which handles fundamental operations such as commissioning. This device does not need an endpoint. The ZigBee Base Device is fully detailed in [Zigbee Base Device](zigbee_base_device.md).

-   **ZigBee Device Objects (ZDO):** This represents the ZigBee node type \(Coordinator, Router, or End Device\) and has a number of communication roles. This device occupies endpoint 0.


The relative locations of the different devices are indicated in [Software Architecture](software_architecture.md#).

**Parent topic:**[Introduction](../topics/introduction.md)

