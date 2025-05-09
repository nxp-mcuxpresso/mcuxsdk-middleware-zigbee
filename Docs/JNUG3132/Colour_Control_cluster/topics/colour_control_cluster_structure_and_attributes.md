# Colour Control Cluster structure and attributes

The structure definition for the Colour Control cluster is:

```
typedef struct
{
#ifdef COLOUR_CONTROL_SERVER
    /* Colour information attribute set */
#ifdef CLD_COLOURCONTROL_ATTR_CURRENT_HUE
    zuint8                u8CurrentHue;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_CURRENT_SATURATION
    zuint8                u8CurrentSaturation;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_REMAINING_TIME
    zuint16               u16RemainingTime;
#endif
    zuint16                 u16CurrentX;
    zuint16                u16CurrentY;
#ifdef CLD_COLOURCONTROL_ATTR_DRIFT_COMPENSATION
    zenum8                u8DriftCompensation;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COMPENSATION_TEXT
    tsZCL_CharacterString   sCompensationText;
    uint8             au8CompensationText[
        CLD_COLOURCONTROL_COMPENSATION_TEXT_MAX_STRING_LENGTH];
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_TEMPERATURE_MIRED
    zuint16               16ColourTemperatureMired;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_MODE
    zenum8                  u8ColourMode;
#endif
    zbmap8                  u8Options;
    /* Defined Primaries Information attribute set */
#ifdef CLD_COLOURCONTROL_ATTR_NUMBER_OF_PRIMARIES
    zuint8               u8NumberOfPrimaries;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_1_X
    zuint16                 u16Primary1X;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_1_Y
    zuint16                 u16Primary1Y;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_1_INTENSITY
    zuint8               u8Primary1Intensity;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_2_X
    zuint16                 u16Primary2X;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_2_Y
    zuint16                 u16Primary2Y;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_2_INTENSITY
    zuint8                u8Primary2Intensity;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_3_X
    zuint16                 u16Primary3X;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_3_Y
    zuint16                 u16Primary3Y;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_3_INTENSITY
    zuint8              u8Primary3Intensity;
#endif
    /* Additional Defined Primaries Information attribute set */
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_4_X
    zuint16                 u16Primary4X;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_4_Y
    zuint16                 u16Primary4Y;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_4_INTENSITY
    zuint8               u8Primary4Intensity;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_5_X
    zuint16                 u16Primary5X;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_5_Y
    zuint16                 u16Primary5Y;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_5_INTENSITY
    zuint8                u8Primary5Intensity;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_6_X
    zuint16                 u16Primary6X;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_6_Y
    zuint16                 u16Primary6Y;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_PRIMARY_6_INTENSITY
    zuint8                  u8Primary6Intensity;
#endif
    /* Defined Colour Points Settings attribute set */
#ifdef CLD_COLOURCONTROL_ATTR_WHITE_POINT_X
    zuint16               u16WhitePointX;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_WHITE_POINT_Y
    zuint16                u16WhitePointY;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_POINT_R_X
    zuint16                u16ColourPointRX;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_POINT_R_Y
    zuint16                u16ColourPointRY;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_POINT_R_INTENSITY
    zuint8             u8ColourPointRIntensity;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_POINT_G_X
    zuint16            u16ColourPointGX;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_POINT_G_Y
    zuint16                u16ColourPointGY;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_POINT_G_INTENSITY
    zuint8              u8ColourPointGIntensity;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_POINT_B_X
    zuint16                u16ColourPointBX;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_POINT_B_Y
    zuint16                u16ColourPointBY;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_POINT_B_INTENSITY
    zuint8              u8ColourPointBIntensity;
#endif
/* Colour information attribute set */
#ifdef CLD_COLOURCONTROL_ATTR_ENHANCED_CURRENT_HUE
    zuint16                u16EnhancedCurrentHue;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_ENHANCED_COLOUR_MODE
    zenum8                u8EnhancedColourMode;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_LOOP_ACTIVE
    zuint8              u8ColourLoopActive;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_LOOP_DIRECTION
    zuint8             u8ColourLoopDirection;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_LOOP_TIME
    zuint16             u16ColourLoopTime;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_LOOP_START_ENHANCED_HUE
    zuint16             u16ColourLoopStartEnhancedHue;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_LOOP_STORED_ENHANCED_HUE
    zuint16                 u16ColourLoopStoredEnhancedHue;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_CAPABILITIES
    zuint16                 u16ColourCapabilities;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_TEMPERATURE_MIRED_PHY_MIN
    zuint16           u16ColourTemperatureMiredPhyMin;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COLOUR_TEMPERATURE_MIRED_PHY_MAX
    zuint16          u16ColourTemperatureMiredPhyMax;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_COUPLE_COLOUR_TEMPERATURE_TO_LEVEL_MIN_MIRED
    zuint16    u16CoupleColourTempToLevelMinMired;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_STARTUP_COLOUR_TEMPERATURE_MIRED
    zuint16          u16StartupColourTemperatureMired;
#endif
#ifdef CLD_COLOURCONTROL_ATTR_ATTRIBUTE_REPORTING_STATUS
    zenum8           u8AttributeReportingStatus;
#endif
#endif
    zuint16           u16ClusterRevision;
} tsCLD_ColourControl;

```

where:

## ‘Colour Information’ Attribute Set 

Note that the attributes `u8CurrentHue`, `u8CurrentSaturation`, `u16CurrentX,``u16CurrentY` and `u16ColourTemperatureMired` are enabled as part of ‘Colour Capabilities’ groups - see [Table 34 on page 704](compile-time_options.md#id_d6675cb0-6090-4409-b15f-2c832f964ed4).

-   `u8CurrentHue` is the current hue value of the light in the range 0-254. This value can be converted to hue in degrees using the following formula:

    hue = `u8CurrentHue` x 360/254. This attribute is only valid when the attributes `u8CurrentSaturation` and `u8ColorMode` are also implemented.

-   `u8CurrentSaturation` is the current saturation value of the light in the range 0-254. This value can be converted to saturation as a fraction using the following formula: saturation = `u8CurrentSaturation`/254. This attribute is only valid when the attributes `u8CurrentHue` and `u8ColorMode` are also implemented.

-   `u16RemainingTime` is the time duration, in tenths of a second, before the currently active command completes.

-   `u16CurrentX` is the current value for the chromaticity x, as defined in the CIE xyY colour space, in the range 0-65279. The normal value of x is calculated using the following formula: x = `u16CurrentX`/65536.

-   `u16CurrentY` is the current value for the chromaticity y, as defined in the CIE xyY colour space, in the range 0-65279. The normal value of y is calculated using the following formula: y = `u16CurrentY`/65536.

-   `u8DriftCompensation` indicates the mechanism, if any, is being used to compensate for colour/intensity drift over time. One of the following values is specified:


|**u8DriftCompensation**|**Drift Compensation Mechanism**|
|-----------------------|--------------------------------|
|0x00|None|
|0x01|Other or unknown|
|0x02|Temperature monitoring|
|0x03|Optical luminance monitoring and feedback|
|0x04|Optical colour monitoring and feedback|
|0x05 - 0xFF|Reserved|

-   The following optional pair of attributes are used to store a textual indication of the drift compensation mechanism used:

    -   `sCompensationText` is a `tsZCL_CharacterString` structure \(see [Section 6.1.14](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)\) for a character string representing the drift compensation method used

    -   `au8CompensationText[]` is a byte-array which contains the character data bytes representing the drift compensation method used

-   `u16ColourTemperatureMired` is the colour temperature of the light expressed as a micro reciprocal degree \(mired\) value. It is a scaled reciprocal of the current value of the colour temperature, in the range 1-65279

    \(0 is undefined and 65535 indicates an invalid value\). The colour temperature, in Kelvin, is calculated using the following formula:

    T = 1000000/`u16ColourTemperature``Mired`. This attribute is only valid when the attribute `u8Colo``u``rMode` is also implemented.

-   `u8ColourMode` indicates which method is currently being used to control the colour of the light. One of the following values is specified:


|**u8ColourMode**|**Colour Control Method/Attributes**|
|----------------|------------------------------------|
|0x00|Hue and saturation

 \(`u8CurrentHue` and `u8CurrentSaturation`\)

|
|0x01|Chromaticities x and y from CIE xyY colour space

 \(`u16CurrentX` and `u16CurrentY`\)

|
|0x02|Colour temperature \(`u16ColourTemperature``Mired`\)|
|0x03 - 0xFF|Reserved|

-   `u8Options` is a bitmap which allows behaviors connected with certain commands to be defined \(these behaviors should only be defined during commissioning\), as follows:


|**Bits**|**Name**|**Description**|
|--------|--------|---------------|
|0|ChangeIfOff|Defines whether changes to the Colour Control cluster can be made from control clusters \(e.g. Level Control\) when the `bOnOff` attribute of the On/Off cluster is zero \(off\):

 -   1 – Allow changes

-   0 – Do not allow changes


|
|1-7|-|Reserved|

## ‘Defined Primaries Information’ 

-   `u8NumberOfPrimaries` is the number of colour primaries implemented on the device, in the range 1-6 \(0xFF is used if the number of primaries is unknown\).

    -   For each colour primary, there is a set of three attributes used \(see below\) - for example, for the first primary this attribute trio comprises `u16Primary1X`, `u16Primary1Y` and `u8Primary1Intensity`. Therefore, the number of primaries specified determines the number of these attribute trios used.

**Note:** The number of primaries is set using a macro at compile-time \(see [Section 31.9](compile-time_options.md#id_a8b0fac5-e0c9-4b31-97d5-1255b76f2311)\). This automatically enables the relevant `u16PrimaryNX`, `u16PrimaryNY` and `u8PrimaryNIntensity` \(N=1 to 6\) attributes.

-   The attribute definitions below are valid for colour primary N, where N is 1, 2 or 3.
-   `u16PrimaryNX` is the value for the chromaticity x for colour primary N, as defined in the CIE xyY colour space, in the range 0-65279. The normalized value of x is calculated using the following formula: x = `u16PrimaryNX`/65536.
-   `u16PrimaryNY` is the value for the chromaticity y for colour primary N, as defined in the CIE xyY colour space, in the range 0-65279. The normalized value of y is calculated using the following formula: y = `u16PrimaryNY`/65536.
-   `u8PrimaryNIntensity` is a representation of the maximum intensity of colour primary 1, normalized such that the primary with the highest maximum intensity has the value 0xFE.

## ‘Additional Defined Primaries Information’ Attribute Set 

-   The attribute definitions for this set are as for `u16PrimaryNX`, `u16PrimaryNY` and `u8PrimaryNIntensity` above, where N is 4, 5 or 6.
-   As indicated in the Note above for the [‘Defined Primaries Information’ Attribute](#id_160ad704-e74a-461d-9670-1b2a7e4da6f9)Set, these attributes are enabled automatically according to the number of required primaries defined at compile-time \(see [Section 31.9](compile-time_options.md#id_a8b0fac5-e0c9-4b31-97d5-1255b76f2311)\).

## ‘Defined Colour Points Settings’ 

-   `u16WhitePointX` is the value for the chromaticity x for the white point of the device, as defined in the CIE xyY colour space, in the range 0-65279. The normalized value of x is calculated using the following formula:

    x = `u16WhitePointX`/65536.

-   `u16WhitePointY` is the value for the chromaticity y for the white point of the device, as defined in the CIE xyY colour space, in the range 0-65279. The normalized value of y is calculated using the following formula:

    y = `u16WhitePointY`/65536.

-   `u16ColourPointRX` is the value for the chromaticity x for the red colour point of the device, as defined in the CIE xyY colour space, in the range 0-65279. The normalized value of x is calculated using the following formula:

    x = `u16ColourPointRX`/65536.

-   `u16ColourPointRY` is the value for the chromaticity y for the red colour point of the device, as defined in the CIE xyY colour space, in the range 0-65279. The normalized value of y is calculated using the following formula:

    y = `u16ColourPointRY`/65536.

-   `u8ColourPointRIntensity` is a representation of the relative intensity of the red colour point of the device, normalized such that the colour point with the highest relative intensity has the value 0xFE \(the value 0xFF indicates an invalid value\).

-   `u16ColourPointGX` is the value for the chromaticity x for the green colour point of the device, as defined in the CIE xyY colour space, in the range 0-65279. The normalized value of x is calculated using the following formula:

    x = `u16ColourPointGX`/65536.

-   `u16ColourPointGY` is the value for the chromaticity y for the green colour point of the device, as defined in the CIE xyY colour space, in the range 0-65279. The normalized value of y is calculated using the following formula:

    y = `u16ColourPointGY`/65536.

-   `u8ColourPointGIntensity` is a representation of the relative intensity of the green colour point of the device, normalized such that the colour point with the highest relative intensity has the value 0xFE \(the value 0xFF indicates an invalid value\).

-   `u16ColourPointBX` is the value for the chromaticity x for the blue colour point of the device, as defined in the CIE xyY colour space, in the range 0-65279. The normalized value of x is calculated using the following formula:

    x = `u16ColourPointBX`/65536.

-   `u16ColourPointBY` is the value for the chromaticity y for the blue colour point of the device, as defined in the CIE xyY colour space, in the range 0-65279. The normalized value of y is calculated using the following formula:

    y = `u16ColourPointBY`/65536.

-   `u8ColourPointBIntensity` is a representation of the relative intensity of the blue colour point of the device, normalized such that the colour point with the highest relative intensity has the value 0xFE \(the value 0xFF indicates an invalid value\).


## Enhanced Colour Mode Attributes 

These attributes are enabled as part of ‘Colour Capabilities’ groups - see [Table 34 on](compile-time_options.md#id_d6675cb0-6090-4409-b15f-2c832f964ed4)page 704.

-   `u16EnhancedCurrentHue` contains the current hue of the light in terms of \(unequal\) steps around the CIE colour ‘triangle’:

    -   8 most significant bits represent an index into the XY look-up table that contains the step values, thus indicating the current step used

    -   8 least significant bits represent a linear interpolation value between the current step and next step \(up\), facilitating a colour zoom

        -   The value of the `u8CurrentHue` attribute is calculated from the above values.
-   `u8EnhancedColourMode` indicates which method is currently being used to control the colour of the light. One of the following values is specified:


|**u8ColourMode**|**Colour Control Method/Attributes**|
|----------------|------------------------------------|
|0x00|Current hue and current saturation

 \(`u8CurrentHue` and `u8CurrentSaturation`\)

|
|0x01|Chromaticities x and y from CIE xyY colour space

 \(`u16CurrentX` and `u16CurrentY`\)

|
|0x02|Colour temperature \(`u16ColourTemperature``Mired`\)|
|0x03|Enhanced hue and current saturation

 \(`u16EnhancedCurrentHue` and `u8CurrentSaturation`\)

|
|0x03 - 0xFF|Reserved|

-   `u8ColourLoopActive` indicates whether the colour loop is currently active: 0x01 - active, 0x00 - not active \(all other values are reserved\). The colour loop follows the hue steps around the CIE colour ‘triangle’ by incrementing or decrementing the value of `u16EnhancedCurrentHue`.

-   `u8ColourLoopDirection` indicates the current direction of the colour loop in terms of the direction of change of `u16EnhancedCurrentHue`:

    0x01 - incrementing, 0x00 - decrementing \(all other values are reserved\).

-   `u16ColourLoopTime` is the period, in seconds, of a full colour loop - that is, the time to cycle all possible values of `u16EnhancedCurrentHue`.

-   `u16ColourLoopStartEnhancedHue` indicates the value of `u16EnhancedCurrentHue` at which the colour loop must be started.

-   `u16ColourLoopStoredEnhancedHue` contains the value of `u16EnhancedCurrentHue` at which the last colour loop completed \(this value is stored on completing a colour loop\).

-   `u16ColourCapabilities` is a bitmap indicating the Colour Control cluster features \(and attributes\) supported by the device, as detailed below \(a bit is set to ‘1’ if the feature is supported or ‘0’ otherwise\):


|**Bits**|**Feature**|**Attributes**|
|--------|-----------|--------------|
|0|Hue/Saturation|```
u8CurrentHue
u8CurrentSaturation

```

|
|1|Enhanced Hue

 \(Hue/Saturation must also be supported\)

|```
u16EnhancedCurrentHue

```

|
|2|Colour Loop

 \(Enhanced Hue must also be supported\)

|```
u8ColourLoopActive
u8ColourLoopDirection
u16ColourLoopTime
u16ColourLoopStartEnhancedHue
u16ColourLoopStoredEnhancedHue
u16ColourCapabilities

```

|
|3|CIE XY Values|```
u16CurrentX
u16CurrentY

```

|
|4|Colour Temperature \(Mired\)|```
u16ColourTemperatureMired
u16ColourTemperatureMiredPhyMin
u16ColourTemperatureMiredPhyMax

```

|
|5-15|Reserved|-|

Macros are provided to select the required Colour Capabilities at compile-time - see [Table 34 on page 704](compile-time_options.md#id_d6675cb0-6090-4409-b15f-2c832f964ed4).

-   `u16ColourTemperature``Mired``PhyMin` indicates the minimum value \(supported by the hardware\) of the mired colour temperature attribute.
-   `u16ColourTemperature``Mired``PhyMax` indicates the maximum value \(supported by the hardware\) of the mired colour temperature attribute.
-   `u16CoupleColourTempToLevelMinMired` is an optional attribute that is used when the `u16ColourTemperatureMired` attribute is coupled to the `u8CurrentLevel` attribute of the Level Control cluster \(this is the case when the CoupleColorTempToLevel bit of the `u8Options` attribute of the Level Control cluster is equal to 1\). `u16CoupleColourTempToLevelMinMired` specifies a lower bound on the value of the `u16ColourTemperatureMired` attribute, where this lower bound corresponds to a `u8CurrentLevel` value of 0xFE \(100%\). Note that because the colour temperature is represented as a mired \(reciprocal\) value, a high value of `u8CurrentLevel` corresponds to a low value of `u16ColourTemperatureMired` and the `16CoupleColourTempToLevelMinMired` attribute corresponds to an upper bound on the value of the colour temperature supported by the device. The value of this attribute must be at least equal to the value of `u16ColourTemperatureMiredPhyMin`.
-   `u16StartupColourTemperatureMired` is an optional attribute to define the required start-up colour temperature of a light when it is supplied with power. It determines the initial value of `u16ColourTemperatureMired` on start-up.

## Global Attributes 

-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


u16ClusterRevision is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCLr6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in[Section2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Parent topic:**[Colour Control Cluster](../../Colour_Control_cluster/topics/colour_control_cluster.md)

