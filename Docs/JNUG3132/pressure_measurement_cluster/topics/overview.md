# Overview

The Pressure Measurement cluster provides an interface for configuring and querying devices that perform pressure measurements.

-   The server is located on the device which makes the pressure measurements

-   The client is located on another device and queries the server for measurements


The cluster is enabled by defining CLD\_PRESSURE\_MEASUREMENT in the **zcl\_options.h** file. Further compile-time options for the Pressure Measurement cluster are detailed in [Section 26.9](compile-time_options.md#id_480d51ac-b571-4322-8862-07098d444d51).

The information that can potentially be stored in this cluster is organized into the following attribute sets:

-   Pressure Measurement Information

-   Extended Pressure Measurement Information

-   Global


Note that not all of the above attribute sets are currently implemented in the NXP software and not all attributes within a supported attribute set are implemented \(see [Section 26.2](cluster_structure_and_attributes.md#id_54d80c28-6623-4cbe-b5ea-57983a64cd1b) for the supported attribute sets and attributes\).

**Parent topic:**[Pressure Measurement Cluster](../../pressure_measurement_cluster/topics/pressure_measurement_cluster.md)

