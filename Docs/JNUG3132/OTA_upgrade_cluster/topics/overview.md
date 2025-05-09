# Overview

The Over-The-Air \(OTA\) Upgrade cluster provides the facility to upgrade \(or downgrade or re-install\) application software on the nodes of a ZigBee PRO network by:

1. Distributing the replacement software through the network \(over the air\) from a designated node.

2. Updating the software in a node with minimal interruption to the operation of the node.

The OTA Upgrade cluster acts as a server on the node that distributes the software and as a client on the nodes that receive software updates from the server. The cluster server receives the software from outside the network.

An application that uses the OTA Upgrade cluster must include the header files **zcl\_options.h** and **OTA.h**.

The OTA Upgrade cluster is enabled by defining CLD\_OTA in the **zcl\_options.h** file. Further compile-time options for the OTA Upgrade cluster are detailed in [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31).

When including the OTA Upgrade facility in your application, you should increase the CPU stack size from the default value \(as described in [Section 49.5](application_requirements.md#id_3d2800f8-8c81-4871-91a1-6a36b9a696ec)\).

**Parent topic:**[OTA Upgrade cluster](../../OTA_upgrade_cluster/topics/ota_upgrade_cluster.md)

