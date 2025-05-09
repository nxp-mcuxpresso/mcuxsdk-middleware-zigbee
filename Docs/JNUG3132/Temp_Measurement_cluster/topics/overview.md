# Overview

The Temperature Measurement cluster provides an interface to a temperature measuring device, allowing the configuration of measuring and the reporting of measurements.

To use the functionality of this cluster, you must include the file **TemperatureMeasurement.h** in your application and enable the cluster by defining CLD\_TEMPERATURE\_MEASUREMENT in the **zcl\_options.h** file.

A Temperature Measurement cluster instance can act as a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Temperature Measurement cluster are fully detailed in [Section 25.6](compile-time_options.md#id_f550563d-abb5-4f8b-a2e9-a9e645f3d436).

**Parent topic:**[Temperature Measurement Cluster](../../Temp_Measurement_cluster/topics/temperature_measurement_cluster.md)

