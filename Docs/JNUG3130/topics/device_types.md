# Device types

The complete functionality of a network node is determined by its device type. This defines a collection of clusters \(some mandatory and some optional\) that make up the supported features of the device. For example, the Thermostat device uses the Basic and Temperature Measurement clusters, and can also use one or more optional clusters. A device is an instance of a device type.

A network node can support more than one device type. The application for a device type runs on a software entity called an endpoint and each node can have up to 240 endpoints.

All ZigBee 3.0 nodes must implement the ZigBee Base Device \(which does not occupy an endpoint\), which handles fundamental operations such as commissioning.

The ZigBee device types and ZigBee Base Device are detailed in the *ZigBee Devices User Guide \(JNUG3131\)*.

**Parent topic:**[Device types and clusters](../topics/device_types_and_clusters.md)

