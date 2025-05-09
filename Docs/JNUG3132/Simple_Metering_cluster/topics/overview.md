# Overview

The Simple Metering cluster is required in ZigBee devices as indicated in the table below.

||**Server-side**|**Client-side**|
|---|---------------|---------------|
|**Mandatory in...**|Metering Device||
|**Optional in...**|ESP|ESP

 IPD

 PCT

|

Thus, a Metering Device or ESP can use this cluster to store attributes and respond to commands relating to these attributes. An IPD or PCT may use this cluster to issue commands to interact with remote attributes held on a Metering Device or ESP.

The Simple Metering cluster is enabled by defining CLD\_SIMPLE\_METERING in the **zcl\_options.h** file. Further compile-time options for the Simple Metering cluster are detailed in [Section 42.12](compile-time_options.md#id_25334628-dcfd-426f-af0c-8d34a10f08a1).

The information that can potentially be stored in this cluster is organized into the following attribute sets:

-   Reading Information Set \(resource measurement information\)

-   TOU Information Set \(Time-Of-Use information\)

-   Meter Status

-   Formatting \(data formatting/interpretation guidance\)

-   Historical Consumption

-   Load Profile Configuration

-   Supply Limit

-   Block Information \(for future use - not certifiable in SE 1.1.1 or earlier\)

-   Alarms \(for future use - not certifiable in SE 1.1.1 or earlier\)


This information is stored in both mandatory and optional attributes - see [Section 42.3](attribute_settings.md#id_1a847f56-d06b-4c02-81c9-dfc3cf9f7c32).

**Note:** Many of the Simple Metering cluster attributes are not certifiable in SE 1.1.1 \(07-5356-17\) or earlier and are reserved for future use \(as indicated in [Section 42.2](simple_metering_cluster_structure_and_attributes.md#id_1c898ead-e5b8-46b9-9117-d5b84c56d269)\).

**Parent topic:**[Simple Metering Cluster](../../Simple_Metering_cluster/topics/simple_metering_cluster.md)

