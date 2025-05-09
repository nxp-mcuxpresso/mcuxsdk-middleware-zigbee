# Initialization

Provided that the DRLC cluster is enabled in the compile-time options \(see [Section](compile-time_options.md#id_d99a7a68-c962-4f54-ab8a-35b360dbb023)41.12\), the cluster is automatically initialized when the ZCL is initialized and the ZigBee device is registered in the application - that is, by calling **eZCL\_Initialise\(\)** and the relevant endpoint registration function for the device, for example:

-   **eSE\_RegisterEspEndPoint\(\)** on a standalone ESP \(cluster server\)

-   **eSE\_RegisterIPDEndPoint\(\)** on an IPD \(cluster client\)


As part of this initialization, the DRLC cluster is created and, on the ESP, a DRLC timer server is registered to support time-stamps in the LCEs.

A DRLC cluster client must also perform a number of other initialization steps in order to establish communication with the cluster server. These are described below.

1. **Set ‘device class’ attribute:** The value of the ‘device class’ attribute \(see [Section 41.2](drlc_cluster_structure_and_attributes.md#id_7bc64896-4d9e-47c4-87c2-0bc3e3957607)\) must be set immediately after **eSE\_RegisterIPDEndPoint\(\)** is called and before the network is started.

2. **Bind to server:** A non-sleeping client should bind its endpoint to the server using the ZigBee PRO API function **ZPS\_eAplZdpBindUnbindRequest\(\)**. This allows the server to send out unsolicited LCEs to the client.

-   Before this binding can take place, the client must obtain the IEEE/MAC address of the ESP/server. This can be achieved by first using the function **ZPS\_eAplZdpMatchDescRequest\(\)** to find the ESP/Server and to obtain its network address. The function **ZPS\_eAplZdpIeeeAddrRequest\(\)** can then be used to obtain the corresponding IEEE/MAC address. Once found, both addresses must be added to the local Address Map using the function **ZPS\_eAplZdoAddAddrMapEntry\(\)**.
-   All four of the above ZPS functions are described in the *ZigBee 3.0 Stack User Guide \(JNUG3130\)*.

3. **Synchronize time with ESP:** A client should synchronize ZCL time with the ESP using the Time cluster as soon as initialization is complete. It is not possible to process unsolicited LCEs with a ‘start-time of now’ until ZCL time has been synchronized.

Once the clients have been set up, the ESP/server may need to configure the enrolment groups and randomization attributes of the DRLC clients \(see [Section](drlc_cluster_structure_and_attributes.md#id_7bc64896-4d9e-47c4-87c2-0bc3e3957607)41.2\). The ESP may use one of the following mechanisms to determine when a DRLC client has come on-line:

-   A Get Scheduled Events message is received from a new client

-   A Report Event Status message is received from a new client

-   A binding request is received from a new client


**Parent topic:**[Demand-Response and Load Control Cluster](../../DRLC_cluster/topics/demand-response_and_load_control_cluster.md)

