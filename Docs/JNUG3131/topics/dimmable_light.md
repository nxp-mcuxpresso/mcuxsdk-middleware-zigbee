# Dimmable Light

The Dimmable Light device is a light that can have its luminance varied, and can be switched on and off. The permitted range of light levels is 0x01 to 0xFE.

-   The Device ID is 0x0101.

-   The header file for the device is **dimmable\_light.h**.

-   The clusters supported by the device are listed in [Section 3.2.1](supported_clusters_005.md#ID_7F8FB811-384C-4D1B-9949-990EC3C571CE).

-   The device structure, `tsZLO_DimmableLightDevice`, is listed in [Section 3.2.2](device_structure_009.md#ID_6A65962D-CA5D-4FF0-9B85-2F4BA59797B6).

-   The endpoint registration function for the device, **eZLO\_RegisterDimmableLightEndPoint\(\)**, is detailed in [Section 3.2.3](registration_function_014.md#ID_244EB143-2AA3-4668-B2CA-A4A8658A7CAD).



```{include} ../topics/supported_clusters_005.md
:heading-offset: 2
```

```{include} ../topics/device_structure_009.md
:heading-offset: 2
```

```{include} ../topics/registration_function_014.md
:heading-offset: 2
```

**Parent topic:**[Lighting and Occupancy Device Types](../topics/lighting_and_occupancy_device_types.md)

