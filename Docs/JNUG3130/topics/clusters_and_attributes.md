# Clusters and attributes

A data entity \(for example, temperature measurement\) handled by a ZigBee endpoint is referred to as an attribute. The application may communicate via a set of attributes - for example, a thermostat application may have attributes for temperature, minimum temperature, maximum temperature and tolerance.

ZigBee applications use the concept of a "cluster" for communicating attribute values. A cluster consists of a set of related attributes together with a set of commands to interact with the attributes - for example, commands for reading the attribute values.

A cluster corresponds to a specific piece of functionality for a device application. The total functionality for the application is determined by the ZigBee device type that it implements and the clusters that the device type uses \(see [Section 3.4.4](device_types_001.md)\). Thus, clusters are the functional building blocks of devices.

A cluster has two aspects, which are respectively concerned with receiving and sending commands \(one or both aspects may be used by a ZigBee application\):

-   **Input Cluster or Server Cluster:** This side of a cluster is used to store attributes and receive commands to manipulate the stored attributes \(to which the cluster may return responses\) - for example, an input cluster would store a temperature measurement and associated attributes, and respond to commands which request readings of these attributes.
-   **Output Cluster or Client Cluster:** This side of a cluster is used to manipulate attributes in the corresponding input cluster by sending commands to it \(and receiving the responses\). Normally, these are write commands to set attribute values and read commands to obtain attribute values \(the read values being returned in responses\).

The Output/Client and Input/Server sides of a cluster are illustrated in below figure.

**Input (Server) and Output (Client) Clusters**

![](../images/fig5.svg "Input (Server) and Output (Client) Clusters")

The input clusters and output clusters communicated via an endpoint are listed \(separately\) in the endpoint’s Simple descriptor \(see [Section 3.4.2.1](simple_descriptor.md)\).

For consistency and interoperability, the ZigBee Alliance have defined a number of standard clusters for different functional areas. These are collected together in the ZigBee Cluster Library \(ZCL\). Thus, developers can use standard clusters from the ZCL in their device applications. The ZCL is fully detailed in the *ZigBee Cluster Library Specification \(075123\)* from the ZigBee Alliance. The NXP implementation of these clusters is detailed in the *ZigBee Cluster Library User Guide \(JNUG3132\)*.

A Default cluster \(with ID of 0xFFFF\) is also available. If the Default cluster is present on an endpoint and a message is received which is destined for a cluster that is not in the endpoint's list of supported input clusters, this message will still be passed to the application \(provided it comes from a defined application profile\). If it is required, the Default cluster must be explicitly added to the endpoint \(see [Section 13.4.3](setting_coordinator_properties.md)\).

**Parent topic:**[Application level concepts](../topics/application_level_concepts.md)

