# ZigBee Device Objects \(ZDO\)

A special application, common to all ZigBee devices, is provided to manage the various processes that have been described. This application is the ZigBee Device Objects or ZDO. It resides in the Application layer of a node, and can communicate with remote nodes via endpoint 0 using the ZigBee Device Profile \(ZDP\) and associated clusters. It has the following roles:

-   Defines the type of network device: Coordinator, Router or End Device
-   initializes the node to allow applications to be run
-   Performs the device discovery and service discovery processes
-   Implements the processes needed to allow a Coordinator to create a network, and Routers and End Devices to join and leave a network
-   Initiates and responds to binding requests \(see [Section 3.6.2](binding.md)\)
-   Provides security services which allow secure relationships to be established between applications
-   Allows remote nodes to retrieve information from the node, such as Routing and Binding tables, and to perform remote management of the node, such as instructing it to leave the network

The ZDO uses services within the stack to implement these roles and provides a means of allowing user applications to access stack services.

**Parent topic:**[Application level concepts](../topics/application_level_concepts.md)

