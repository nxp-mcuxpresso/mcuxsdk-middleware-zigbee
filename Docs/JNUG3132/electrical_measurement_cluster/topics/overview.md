# Overview

The Electrical Measurement cluster provides an interface for querying devices for electrical measurements.

-   The server is located on the device which makes the electrical measurements

-   The client is located on another device and queries the server for measurements


Separate instances of the Electrical Measurement cluster server can be implemented across multiple endpoints within the same physical unit - that is, one server instance per endpoint. An example is a power extension unit containing multiple outlets, where each power outlet allows electrical measurements to be made on the supplied power 
\(e.g. AC RMS voltage and current\).

The cluster is enabled by defining CLD\_ELECTRICAL\_MEASUREMENT in the **zcl\_options.h** file. Further compile-time options for the Electrical Measurement cluster are detailed in [Section 30.9](compile-time_options.md#id_1df03f54-f007-4972-bb6b-c21e8e5b68b6).

The information that can potentially be stored in this cluster is organised into the following attribute sets:

-   Basic Information

-   DC Measurement

-   DC Formatting

-   AC \(Non-phase Specific\) Measurements

-   AC \(Non-phase Specific\) Formatting

-   AC \(Single Phase or Phase A\) Measurements

-   AC Formatting

-   DC Manufacturer Threshold Alarms

-   AC Manufacturer Threshold Alarms

-   AC Phase B Measurements

-   AC Phase C Measurements


Note that not all of the above attribute sets are currently implemented in the NXP software and not all attributes within a supported attribute set are implemented \(see [Section 30.2](cluster_structure_and_attributes.md#id_ab865248-0ff3-4f63-94bd-dd14a8edf2ac) for the supported attribute sets and attributes\).

**Parent topic:**[Electrical Measurement Cluster](../../electrical_measurement_cluster/topics/electrical_measurement_cluster.md)

