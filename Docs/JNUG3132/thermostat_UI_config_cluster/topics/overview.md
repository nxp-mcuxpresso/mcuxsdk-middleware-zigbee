# Overview

The Thermostat UI Configuration cluster is required in ZigBee devices as indicated in the table below.

||**Server-side**|**Client-side**|
|---|---------------|---------------|
|**Mandatory in...**|||
|**Optional in...**|Thermostat|Configuration Tool

 Combined Interface

|

The Thermostat UI Configuration cluster is enabled by defining CLD\_THERMOSTAT\_UI\_CONFIG in the **zcl\_options.h** file.

The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Thermostat UI Configuration cluster are fully detailed in [Section 35.7](compile-time_options.md#id_e9c062f6-c18d-4582-9ee0-5106ed8a6678).

**Parent topic:**[Thermostat UI Configuration Cluster](../../thermostat_UI_config_cluster/topics/thermostat_ui_configuration_cluster.md)

