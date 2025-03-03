# Color Scene Controller

The color Scene Controller device is used in nodes that support scenes and that issue color-control commands. A typical use is to adjust the intensity or color of a lighting device, or switch it on/off. For example, it can be used as a controller for a Color Dimmable Light.

-   The Device ID is 0x0810.

-   The header file for the device is **colour\_scene\_controller.h**.

-   The clusters supported by the device are listed in [Supported clusters](supported_clusters_007.md#ID_285BE9AC-61D4-4C32-A7C2-26F628917F27).

-   The device structure, `tsZLO_ColourSceneControllerDevice`, is listed in [Device Structure](device_structure_010.md#ID_324D3DB7-3EA4-4495-B036-ED39E73124C7).

-   The endpoint registration function for the device, **eZLO\_RegisterColourSceneControllerEndPoint\(\)**, is detailed in [Registration Function](registration_function_008.md#ID_B5E00666-E2C9-444F-A8B2-47A606ACD21D).



```{include} ../topics/supported_clusters_007.md
:heading-offset: 2
```

```{include} ../topics/device_structure_010.md
:heading-offset: 2
```

```{include} ../topics/registration_function_008.md
:heading-offset: 2
```

**Parent topic:**[Lighting and Occupancy Device Types](../topics/lighting_and_occupancy_device_types.md)

