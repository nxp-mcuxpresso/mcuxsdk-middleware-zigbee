# Initialization

Initialization of the various software components used with the OTA Upgrade cluster \(see [Section 49.5](application_requirements.md#id_3d2800f8-8c81-4871-91a1-6a36b9a696ec)\) must be performed in a particular order in the application code. The initialization could be incorporated in a function **APP\_vInitialise\(\)**, as is the case in the NXP *ZigBee PRO Application Template \(JN-AN-1248\)*.

Initialization must be performed in the following order:

1. The NVM module must first be initialized using the function **NvModuleInit\(\)**.

2. The persistent data record\(s\) should then be initialized using the function and registered **NVM\_RegisterDataSet\(\)**.

3. The ZigBee PRO stack must now be started by first calling the function **ZPS\_vSetOverrideLocalMacAddress\(\)** to over-ride the existing MAC address, followed by **ZPS\_eAplAfInit\(\)** to initialize the Application Framework and then **ZPS\_eAplZdoStartStack\(\)** to start the stack.

4. The ZCL initialization function, **eZCL\_Initialise\(\)**, can now be called. An OTA Upgrade cluster instance should then be created using **eOTA\_Create\(\)**, followed by a call to **eOTA\_UpdateClientAttributes\(\)** or **eOTA\_RestoreClientData\(\)** on a client to initialize the cluster attributes.

5. The Flash programming of the OTA Upgrade cluster must now be initialized using the function **vOTA\_FlashInit\(\)**.

6. The required device endpoint\(s\) can now be registered \(for example, a Simple Sensor device\).

7. The function **eOTA\_AllocateEndpointOTASpace\(\)** must be called to allocate Flash memory space to an endpoint. The information provided to this function includes the numbers of the start sectors for storage of application images and the maximum number of sectors per image.

8. On the server, a set of client devices can be defined for which OTA upgrades are authorized - that is, a list of clients that are allowed to use the server for OTA upgrades. This client list is set up using the function **eOTA\_SetServerAuthorisation\(\)**.

9. For a client, a server must be found \(provided this is a first-time start or a reboot with no persisted data, and so there is no record of a previous server address\). This can be done by sending out a Match Descriptor Request using the function **ZPS\_eAplZdpMatchDescRequest\(\)**, described in the *ZigBee 3.0 Stack User Guide \(JNUG3130\)*. Once a server has been found, its address must be registered with the OTA Upgrade cluster using the function **eOTA\_SetServerAddress\(\)**.

The coding that is then required to implement OTA upgrade in the server and client applications is outlined in [Section 49.7](implementing_ota_upgrade_mechanism_.md#id_dd5d3237-7c2e-4a47-ad47-9815f483cd62).

**Parent topic:**[OTA Upgrade cluster](../../OTA_upgrade_cluster/topics/ota_upgrade_cluster.md)

