# Compile-time Options

To enable the Colour Control cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_COLOUR_CONTROL

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define COLOUR_CONTROL_CLIENT
#define COLOUR_CONTROL_SERVER

```

The Colour Cluster cluster attributes reside on the server only. Therefore, attributes should not be enabled in the **zcl\_options.h** file for the cluster client.

## Optional Attributes 

The optional attributes of the Colour Control cluster are enabled/disabled by defining the following in the **zcl\_options.h** file:

-   For optional attributes from the ‘Colour Information’ attribute set:

    -   CLD\_COLOURCONTROL\_ATTR\_REMAINING\_TIME

    -   CLD\_COLOURCONTROL\_ATTR\_DRIFT\_COMPENSATION

    -   CLD\_COLOURCONTROL\_ATTR\_COMPENSATION\_TEXT

    -   CLD\_COLOURCONTROL\_ATTR\_COLOUR\_MODE

        -   Certain attributes from this attribute set are enabled through a [‘Colour](#id_936ab29a-c650-4988-8331-743ba7e33e21)Capabilities’ Definition \(see below\) - these are `u8CurrentHue`, `u8CurrentSaturation` and `u16ColourTemperatureMired`.
-   For optional attributes from the ‘Defined Primaries Information’ and ‘Additional Defined Primaries Information’ attribute sets, the macro

    -   CLD\_COLOURCONTROL\_ATTR\_NUMBER\_OF\_PRIMARIES

        -   is used to define the required number of colour primaries, N, in the range 1 to 6 \(0xFF can also be specified if the number of primaries is not known\). This macro is used to automatically enable the required attributes from these attribute sets - for example, if N is set to 4 then the following attributes are enabled:
        -   `u16Primary1X`, `u16Primary1Y`, `u8Primary1Intensity`, `u16Primary2X`, `u16Primary2Y`, `u8Primary2Intensity`, `u16Primary3X`, `u16Primary3Y`, `u8Primary3Intensity`, `u16Primary4X`, `u16Primary4Y`, `u8Primary4Intensity`.
-   For optional attributes from the ‘Defined Colour Points Settings’ attribute set:

    -   CLD\_COLOURCONTROL\_ATTR\_WHITE\_POINT\_X

    -   CLD\_COLOURCONTROL\_ATTR\_WHITE\_POINT\_Y

    -   CLD\_COLOURCONTROL\_ATTR\_COLOUR\_POINT\_R\_X

    -   CLD\_COLOURCONTROL\_ATTR\_COLOUR\_POINT\_R\_Y

    -   CLD\_COLOURCONTROL\_ATTR\_COLOUR\_POINT\_R\_INTENSITY

    -   CLD\_COLOURCONTROL\_ATTR\_COLOUR\_POINT\_G\_X

    -   CLD\_COLOURCONTROL\_ATTR\_COLOUR\_POINT\_G\_Y

    -   CLD\_COLOURCONTROL\_ATTR\_COLOUR\_POINT\_G\_INTENSITY

    -   CLD\_COLOURCONTROL\_ATTR\_COLOUR\_POINT\_B\_X

    -   CLD\_COLOURCONTROL\_ATTR\_COLOUR\_POINT\_B\_Y

    -   CLD\_COLOURCONTROL\_ATTR\_COLOUR\_POINT\_B\_INTENSITY

-   For optional attributes from the ‘Enhanced Colour Mode’ attributes, the following must be defined:

    -   CLD\_COLOURCONTROL\_ATTR\_ENHANCED\_COLOUR\_MODE

    -   CLD\_COLOURCONTROL\_ATTR\_COLOUR\_CAPABILITIES

        -   The required ‘Enhanced Colour Mode’ attributes for a device must then be enabled through a [‘Colour Capabilities’ Definition](#id_936ab29a-c650-4988-8331-743ba7e33e21) \(see below\).

## Global Attributes 

Add this line to enable the optional Attribute Reporting Status attribute:

```
#define CLD_COLOURCONTROL_ATTR_ID_ATTRIBUTE_REPORTING_STATUS

```

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_COLOURCONTROL_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

## ‘Colour Capabilities’ Definition 

If required, certain ‘Colour Information’ attributes and all ‘Enhanced Colour Mode’ attributes must be enabled through a ‘Colour Capabilities’ definition. Attributes are enabled as a group according to the required capability/functionality. The capabilities are detailed in the table below, with their corresponding attributes and macros.
<html>
<table class="table frame-all table--pgwide-1" id="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88"><caption><span class="table--title-label">Table 1. </span><span id="topic_d3123d89-def6-4bff-8451-058193f5834e__tableTitle_35fc63ff-aded-4e93-9728-f3aef316034d" class="title"><span class="ph" id="topic_d3123d89-def6-4bff-8451-058193f5834e__id_d6675cb0-6090-4409-b15f-2c832f964ed4">‘Colour Capabilities’ Macros</span></span></caption><colgroup><col style="width:16.447368421052634%"><col style="width:34.70394736842105%"><col style="width:48.848684210526315%"></colgroup><thead class="thead">
                        <tr class="row">
                            <th class="entry valign-middle" id="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__1">
                                <p class="p"><strong class="ph b">Capability/Functionality</strong></p>
                            </th>
                            <th class="entry valign-middle" id="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__2">
                                <p class="p"><strong class="ph b">Attributes</strong></p>
                            </th>
                            <th class="entry valign-middle" id="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__3">
                                <p class="p"><strong class="ph b">Macro</strong></p>
                            </th>
                        </tr>
                    </thead><tbody class="tbody">
                        <tr class="row">
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__1">
                                <p class="p">Hue/Saturation</p>
                            </td>
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__2">u8CurrentHue u8CurrentSaturation </td>
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__3">
                                <p class="p">COLOUR_CAPABILITY_HUE_SATURATION_SUPPORTED</p>
                            </td>
                        </tr>
                        <tr class="row">
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__1">
                                <p class="p">Enhanced Hue</p>
                                <p class="p">(also need Hue/Saturation)</p>
                            </td>
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__2">u16EnhancedCurrentHue* </td>
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__3">
                                <p class="p">COLOUR_CAPABILITY_ENHANCE_HUE_SUPPORTED</p>
                            </td>
                        </tr>
                        <tr class="row">
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__1">
                                <p class="p">Colour Loop</p>
                                <p class="p">(also need Enhanced Hue)</p>
                            </td>
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__2">u8ColourLoopActive* u8ColourLoopDirection*
                                u16ColourLoopTime* u16ColourLoopStartEnhancedHue*
                                u16ColourLoopStoredEnhancedHue* </td>
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__3">
                                <p class="p">COLOUR_CAPABILITY_COLOUR_LOOP_SUPPORTED</p>
                            </td>
                        </tr>
                        <tr class="row">
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__1">
                                <p class="p">CIE XY Values</p>
                                <p class="p">(this is mandatory)</p>
                            </td>
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__2">u16CurrentX u16CurrentY </td>
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__3">
                                <p class="p">COLOUR_CAPABILITY_XY_SUPPORTED</p>
                            </td>
                        </tr>
                        <tr class="row">
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__1">
                                <p class="p">Colour Temperature</p>
                            </td>
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__2">u16ColourTemperatureMired
                                u16ColourTemperatureMiredPhyMin* u16ColourTemperatureMiredPhyMax*
                                u16ColourTemperatureMiredMin* u16ColourTemperatureMiredMax*
                                bColourCoupleTemperatureMired-ToLevel*
                                u16StartupColourTemperatureMired* </td>
                            <td class="entry" headers="topic_d3123d89-def6-4bff-8451-058193f5834e__table_78603250-5a58-4db8-9d1e-b356f6b30d88__entry__3">
                                <p class="p">COLOUR_CAPABILITY_COLOUR_TEMPERATURE_SUPPORTED</p>
                            </td>
                        </tr>
                    </tbody></table>
</html>
The ‘Enhanced Colour Mode’ attributes also require ‘enhanced colour mode’ to be enabled through `#``define CLD_COLOURCONTROL_ATTR_ENHANCED_COLOUR_MODE`

The above macros automatically invoke the macros for the individual attributes in the capability group. For example, E\_CLD\_COLOURCONTROL\_ATTR\_CURRENT\_HUE is invoked for the attribute `u8CurrentHue`.

The enabled Colour Capabilities are reflected in the ‘Enhanced Colour Mode’ attribute \(bitmap\) `u16ColourCapabilities`.

Example Colour Capabilities definitions are provided below for different devices.

**ZLO Extended Colour Light:**

```
#define CLD_COLOURCONTROL_COLOUR_CAPABILITIES 
           (COLOUR_CAPABILITY_HUE_SATURATION_SUPPORTED | \\
         COLOUR_CAPABILITY_ENHANCE_HUE_SUPPORTED  | \\
         COLOUR_CAPABILITY_COLOUR_LOOP_SUPPORTED | \\
         COLOUR_CAPABILITY_XY_SUPPORTED | \\
         COLOUR_CAPABILITY_COLOUR_TEMPERATURE_SUPPORTED)

```

**ZLO Colour Light:**

```
#define CLD_COLOURCONTROL_COLOUR_CAPABILITIES                    
              (COLOUR_CAPABILITY_HUE_SATURATION_SUPPORTED | \\
              COLOUR_CAPABILITY_ENHANCE_HUE_SUPPORTED    | \\
              COLOUR_CAPABILITY_COLOUR_LOOP_SUPPORTED    | \\
              COLOUR_CAPABILITY_XY_SUPPORTED)

```

**ZLO Colour Temperature Light:**

```
#define CLD_COLOURCONTROL_COLOUR_CAPABILITIES             
        (COLOUR_CAPABILITY_COLOUR_TEMPERATURE_SUPPORTED)

```

**Parent topic:**[Colour Control Cluster](../../Colour_Control_cluster/topics/colour_control_cluster.md)

