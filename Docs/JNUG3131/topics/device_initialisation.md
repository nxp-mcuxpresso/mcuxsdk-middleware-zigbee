# Device initialization

A ZigBee 3.0 application is initialized as described in the section "Forming and Joining a Network" of the *ZigBee 3.0 Stack User Guide \(JNUG3130\)*. In addition, some device initialization must be performed.

ZigBee devices must be initialized in the following order and steps:

1. In the header file **zcl\_options.h**, enable the required compile-time options. These options include the clusters to be used by the device, the client/server status of each cluster and the optional attributes for each cluster. For more information on compile-time options, refer to [Compile-time options](compile-time_options.md#ID_F49D08A4-FE5C-4975-8606-A218B3EC2802).

2. In the application, create an instance of the device structure by declaring a file scope variable - for example:

```
tsZLO_DimmableLightDevicesDevice;

```

3. In the initialization part of the application, set up the device handled by your code, as follows:

a\) Set the initial values of the cluster attributes to be used by the device - for example:

```
sDevice.sBasicCluster.u8StackVersion=1;
sDevice.sBasicCluster....

```

b\) After calling **eZCL\_Initialise\(\)** and before calling **ZPS\_eAplAfInit\(\)**, register the device by calling the relevant device registration function - for example, **eZLO\_RegisterDimmableLightEndPoint\(\)**. In this function call, the device allocates a unique endpoint \(in the range 1-240\). In addition, its device structure is specified as well as a user-defined callback function is invoked when an event occurs relating to the endpoint \(see [Section 1.5](endpoint_callback_functions.md#ID_6E39F726-AEDC-4434-946C-56B0D7BEAAEC)\). As soon as this function has been called, the shared device structure is read by another device.

c\) After calling **ZPS\_eAplAfInit\(\)**, initialize and start the ZigBee Base Device \(ZBD\) by calling **BDB\_vInit\(\)** and then **BDB\_vStart\(\)**. Refer to [Section 2.1](initialising_and_starting_the_zigbee_base_device.md) for more details of ZigBee Base Device initialization.

**Note:**

1.  The set of endpoint registration functions for the different device types is detailed in the device type descriptions - for example, in [Chapter 3](lighting_and_occupancy_device_types.md) for Lighting and Occupancy devices.
2.  The device registration functions create instances of all the clusters used by the device. Thus, there is no need to call the individual cluster creation functions explicitly, for example, **eCLD\_IdentifyCreateIdentify\(\)** for the Identify cluster.

**Parent topic:**[Introduction](../topics/introduction.md)

