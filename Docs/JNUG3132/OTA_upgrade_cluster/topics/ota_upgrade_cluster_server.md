# OTA Upgrade Cluster Server

The OTA Upgrade cluster server is a network node that distributes application upgrades to other nodes of the network \(as well as performing its own functions\). The server must, therefore, be connected to the provider of the upgrade software. The server would also usually be the Coordinator of the ZigBee network.

The server may need to store different upgrade images for different nodes \(possibly from different manufacturers\) and must have ample Flash memory space for this purpose. Therefore, the server must keep a record of the software required by each client in the network and the software version number that the client is currently on. When a new version of an application image becomes available, the server may notify the relevant client\(s\) or respond to poll requests for software upgrades from the clients \(see [Section 49.4.2](ota_upgrade_cluster_client.md#id_9d07e96d-4d54-4a38-a18e-c3f63f125c0b) below\).

**Parent topic:**[Basic Principles](../../OTA_upgrade_cluster/topics/basic_principles.md)

