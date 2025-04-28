# Device types

To ensure the interoperability of ZigBee nodes from different manufacturers, the ZigBee Alliance has defined a set of standard device types. A device type \(for example, Dimmable Light\) is a software entity which defines the functionality of a device. This functionality is itself defined by the clusters included in the device type, where each cluster corresponds to a specific functional aspect \(for example, Level Control\) of the device. For more information on clusters, refer to [Section 3.4.5](clusters_and_attributes.md).

A device is an instance of a device type and is implemented by an application that runs on an endpoint. A device type usually supports both mandatory and optional clusters, so a device can be customized in terms of the optional clusters used. The device type implemented by an application is specified in the application’s Simple Descriptor \(see [Section 3.4.2.1](simple_descriptor.md)\). A node may implement more than one device type, each corresponding to a device application that runs on its own endpoint.

Every ZigBee 3.0 node must employ the ZigBee Base Device, which provides a framework for using ZigBee device types and handles fundamental operations such as commissioning \(this device does not need an endpoint\).

The NXP implementations of the ZigBee device types and ZigBee Base Device are described in the *ZigBee Devices User Guide \(JNUG3131\)*.

**Parent topic:**[Application level concepts](../topics/application_level_concepts.md)

