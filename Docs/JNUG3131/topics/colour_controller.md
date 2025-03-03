# Colour Controller

The Colour Controller device is used in a node that issues colour-control commands to adjust the intensity or colour of a lighting device, or switch it on/off.

-   The Device ID is 0x0800.

-   The header file for the device is **colour\_controller.h**.

-   The clusters supported by the device are listed in [Section 3.16.1](supported_clusters_003.md#ID_9A28754E-450A-4CD2-914F-7E31207A9B85).

-   The device structure, `tsZLO_ColourControllerDevice`, is listed in [Section 3.16.2](device_structure_017.md#ID_3791419E-8373-4AEA-BDE4-AF1A163E2B96).

-   The endpoint registration function for the device, **eZLO\_RegisterColourRemoteEndPoint\(\)**, is detailed in [Section 3.16.3](registration_function_013.md#ID_9459AF03-7B2A-41CF-A468-092129FB347F).



```{include} ../topics/supported_clusters_003.md
:heading-offset: 2
```

```{include} ../topics/device_structure_017.md
:heading-offset: 2
```

```{include} ../topics/registration_function_013.md
:heading-offset: 2
```

**Parent topic:**[Lighting and Occupancy Device Types](../topics/lighting_and_occupancy_device_types.md)

