# Non-Colour Controller

The Non-Colour Controller device is used in nodes that issue control commands that are not related to colour - for example, to control a Dimmable Light.

-   The Device ID is 0x0820.

-   The header file for the device is **non\_colour\_controller.h**.

-   The clusters supported by the device are listed in [Section 3.18.1](supported_clusters_013.md#ID_6BCEF108-3CB8-41D7-8403-D30D4F542B49).

-   The device structure, `tsZLO_NonColourControllerDevice`, is listed in [Section 3.18.2](device_structure_016.md#ID_DA94A763-8560-42E6-B9F7-FE4919F0749C).

-   The endpoint registration function for the device, **eZLO\_RegisterNonColourControllerEndPoint\(\)**, is detailed in [Section 3.18.3](registration_function_012.md#ID_D3A6E172-9418-404F-9AC3-A6B063E0D26A).



```{include} ../topics/supported_clusters_013.md
:heading-offset: 2
```

```{include} ../topics/device_structure_016.md
:heading-offset: 2
```

```{include} ../topics/registration_function_012.md
:heading-offset: 2
```

**Parent topic:**[Lighting and Occupancy Device Types](../topics/lighting_and_occupancy_device_types.md)

