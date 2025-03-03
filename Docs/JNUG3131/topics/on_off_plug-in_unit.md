# On/Off Plug-in Unit

The On/Off Plug-in Unit device is typically used in nodes that contain a controllable mains plug or adaptor which includes an on/off switch. It may be controlled from a controller device such as an On/Off Light Switch.

-   The Device ID is 0x010A.

-   The header file for the device is **on\_off\_plug.h**.

-   The clusters supported by the device are listed in [Section 3.11.1](supported_clusters_012.md#ID_F6FADAA1-FDF7-4151-8AC5-27D78E77EA45).

-   The device structure, `tsZLO_OnOffPlugDevice`, is listed in [Section 3.11.2](device_structure_004.md#ID_D345EA38-83A8-42E6-A04D-C43EFB659572).

-   The endpoint registration function for the device, **eZLO\_RegisterOnOffPlugEndPoint\(\)**, is detailed in [Section 3.11.3](registration_function_018.md#ID_7F642F03-ECD8-4264-A6CB-3A46540DC16D).



```{include} ../topics/supported_clusters_012.md
:heading-offset: 2
```

```{include} ../topics/device_structure_004.md
:heading-offset: 2
```

```{include} ../topics/registration_function_018.md
:heading-offset: 2
```

**Parent topic:**[Lighting and Occupancy Device Types](../topics/lighting_and_occupancy_device_types.md)

