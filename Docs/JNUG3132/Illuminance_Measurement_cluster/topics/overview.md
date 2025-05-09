# Overview

The Illuminance Measurement cluster provides an interface to an illuminance measuring device, allowing the configuration of measuring and the reporting of measurements.

To use the functionality of this cluster, you must include the file **IlluminanceMeasurement.h** in your application and enable the cluster by defining CLD\_ILLUMINANCE\_MEASUREMENT in the **zcl\_options.h** file.

An Illuminance Measurement cluster instance can act as a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Illuminance Measurement cluster are fully detailed in [Section 23.6](compile-time_options.md#id_f3e76827-c1d1-4dcc-b693-78131f602337).

**Parent topic:**[Illuminance Measurement Cluster](../../Illuminance_Measurement_cluster/topics/illuminance_measurement_cluster.md)

