# Overview

The Device Temperature Configuration cluster allows:

-   Information to be obtained about the internal temperature of a device.

-   Over-temperature and under-temperature alarms to be configured.


To use the functionality of this cluster, you must include the file **DeviceTemperatureConfiguration.h** in your application and enable the cluster by defining CLD\_DEVICE\_TEMPERATURE\_CONFIGURATION in the **zcl\_options.h** file.

It is also necessary to enable the cluster as a server or client, or as both:

-   The cluster server is able to receive commands to access internal temperature data on the local device.

-   The cluster client is able to send commands to access the internal temperature data on the remote device.


The inclusion of the client or server software must be pre-defined in the compile-time options of the application. In addition, if the cluster is designed to reside on a custom endpoint, then the role of client or server must also be specified when creating the cluster instance.

The compile-time options for the Device Temperature Configuration cluster are fully detailed in [Section 10.5](compile-time_options.md#id_0661fbe7-4087-4efa-afb2-dd94484c4eb2).

**Parent topic:**[Device Temperature Configuration Cluster](../../Device_Temp_Configuration_cluster/topics/device_temperature_configuration_cluster.md)

