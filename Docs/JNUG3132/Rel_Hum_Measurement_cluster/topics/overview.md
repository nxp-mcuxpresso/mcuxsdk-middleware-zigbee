# Overview

The Relative Humidity Measurement cluster provides an interface to a humidity measuring device, allowing the configuration of relative humidity measuring and the reporting of measurements.

To use the functionality of this cluster, you must include the file **RelativeHumidityMeasurement.h** in your application and enable the cluster by defining CLD\_RELATIVE\_HUMIDITY\_MEASUREMENT in the **zcl\_options.h** file.

A Relative Humidity Measurement cluster instance can act as a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Relative Humidity Measurement cluster are fully detailed in [Section 28.6](compile-time_options.md#id_0cf0fdcd-7b3a-4630-a26f-819aeb3bcd51).

**Parent topic:**[Relative Humidity Measurement Cluster](../../Rel_Hum_Measurement_cluster/topics/relative_humidity_measurement_cluster.md)

