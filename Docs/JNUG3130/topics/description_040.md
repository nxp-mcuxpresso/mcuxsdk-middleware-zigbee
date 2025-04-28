# Description

This function initializes the Application Framework and must be the first network function called in your application code. The function first requests a reset of the Network \(NWK\) layer of the ZigBee PRO stack. It then initializes certain network parameters with values that have been pre-configured using the ZPS Configuration Editor \(see Chapter 13, [ZPS Configuration Editor](zps_configuration_editor.md)\). These parameters include the node type and the Extended PAN ID of the network.

The device is started as the pre-configured node type. If this is a Coordinator, the Extended PAN ID of the node is set to the pre-configured value. Note that if a zero value is specified, the Coordinator uses its own IEEE/MAC address for the Extended PAN ID.

**Parent topic:**[ZPS\_eAplAfInit](../topics/zps_eaplafinit.md)

