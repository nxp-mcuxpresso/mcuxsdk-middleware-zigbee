# Custom Command Payloads

The following structures contain the payloads for the Colour Control cluster custom commands.

## Move to Hue Command Payload 

```
typedef struct
{
    uint8                           u8Hue;
    teCLD_ColourControl_Direction   eDirection;
    uint16                          u16TransitionTime;
} tsCLD_ColourControl_MoveToHueCommandPayload;

```

where:

-   `u8Hue` is the target hue value.

-   `eDirection` indicates the direction/path of the change in hue:


|**eDirection**|**Direction/Path**|
|--------------|------------------|
|0x00|Shortest path|
|0x01|Longest path|
|0x02|Up|
|0x03|Down|
|0x04 – 0xFF|Reserved|

-   `u16TransitionTime` is the time period, in tenths of a second, over which the change in hue should be implemented.


## Move Hue Command Payload 

```
typedef struct
{
    teCLD_ColourControl_MoveMode    eMode;
    uint8                           u8Rate;
    zbmap8                          u8OptionsMask;
    zbmap8                          u8OptionsOverride;    
} tsCLD_ColourControl_MoveHueCommandPayload;

```

where:

-   `eMode` indicates the required action and/or direction of the change in hue:


|**eMode**|**Action/Direction**|
|---------|--------------------|
|0x00|Stop existing movement in hue|
|0x01|Start increasing hue|
|0x02|Reserved|
|0x03|Start decreasing hue|
|0x04 – 0xFF|Reserved|

-   `u8Rate` is the required rate of movement in hue steps per second \(a step is one unit of hue for the device\).

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Step Hue Command Payload 

```
typedef struct
{
    teCLD_ColourControl_StepMode    eMode;
    uint8                           u8StepSize;
    uint8                           u8TransitionTime;
    zbmap8                          u8OptionsMask;
    zbmap8                          u8OptionsOverride;     
} tsCLD_ColourControl_StepHueCommandPayload;

```

where:

-   `eMode` indicates the required direction of the change in hue:


|**eMode**|**Action/Direction**|
|---------|--------------------|
|0x00|Reserved|
|0x01|Increase hue|
|0x02|Reserved|
|0x03|Decrease hue|
|0x04 – 0xFF|Reserved|

-   `u8StepSize` is the amount by which the hue is to be changed \(increased or decreased\), in units of hue for the device.

-   `u8TransitionTime` is the time period, in tenths of a second, over which the change in hue should be implemented.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Move To Saturation Command Payload 

```
typedef struct
{
    uint8                          u8Saturation;
    uint16                         u16TransitionTime;
    zbmap8                         u8OptionsMask;
    zbmap8                         u8OptionsOverride;     
} tsCLD_ColourControl_MoveToSaturationCommandPayload;

```

where:

-   `u8Saturation` is the target saturation value.

-   `u16TransitionTime` is the time period, in tenths of a second, over which the change in saturation should be implemented.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Move Saturation Command Payload 

```
typedef struct
{
    teCLD_ColourControl_MoveMode    eMode;
    uint8                           u8Rate;
    zbmap8                          u8OptionsMask;
    zbmap8                          u8OptionsOverride;     
} tsCLD_ColourControl_MoveSaturationCommandPayload;

```

where:

-   `eMode` indicates the required action and/or direction of the change in saturation:


|**eMode**|**Action/Direction**|
|---------|--------------------|
|0x00|Stop existing movement in hue|
|0x01|Start increasing saturation|
|0x02|Reserved|
|0x03|Start decreasing saturation|
|0x04 – 0xFF|Reserved|

-   `u8Rate` is the required rate of movement in saturation steps per second \(a step is one unit of saturation for the device\).

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Step Saturation Command Payload 

```
typedef struct
{
    teCLD_ColourControl_StepMode    eMode;
    uint8                           u8StepSize;
    uint8                           u8TransitionTime;
    zbmap8                          u8OptionsMask;
    zbmap8                          u8OptionsOverride;     
} tsCLD_ColourControl_StepSaturationCommandPayload;

```

where:

-   `eMode` indicates the required direction of the change in saturation:


|**eMode**|**Action/Direction**|
|---------|--------------------|
|0x00|Reserved|
|0x01|Increase saturation|
|0x02|Reserved|
|0x03|Decrease saturation|
|0x04 – 0xFF|Reserved|

-   `u8StepSize` is the amount by which the saturation is to be changed \(increased or decreased\), in units of saturation for the device.

-   `u8TransitionTime` is the time period, in tenths of a second, over which the change in hue should be implemented.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Move To Hue And Saturation Command Payload 

```
typedef struct
{
    uint8                           u8Hue;
    uint8                           u8Saturation;
    uint16                          u16TransitionTime;
    zbmap8                          u8OptionsMask;
    zbmap8                          u8OptionsOverride;     
} tsCLD_ColourControl_MoveToHueAndSaturationCommandPayload;

```

where:

-   `u8Hue` is the target hue value.

-   `u8Saturation` is the target saturation value.

-   `16TransitionTime` is the time period, in tenths of a second, over which the change in hue and saturation should be implemented.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Move To Colour Command Payload 

```
typedef struct
{
    uint16                         u16ColourX;
    uint16                         u16ColourY;
    uint16                         u16TransitionTime;
    zbmap8                         u8OptionsMask;
    zbmap8                         u8OptionsOverride;     
} tsCLD_ColourControl_MoveToColourCommandPayload;

```

where:

-   `u16ColourX` is the target x-chromaticity in the CIE xyY colour space

-   `u16ColourY` is the target y-chromaticity in the CIE xyY colour space

-   `u16TransitionTime` is the time period, in tenths of a second, over which the colour change should be implemented.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Move Colour Command Payload 

```
typedef struct
{
    int16                          i16RateX;
    int16                          i16RateY;
    zbmap8                         u8OptionsMask;
    zbmap8                         u8OptionsOverride;     
} tsCLD_ColourControl_MoveColourCommandPayload;

```

where:

-   `i16RateX` is the required rate of movement of x-chromaticity in the CIE xyY colour space, in steps per second \(a step is one unit of x-chromaticity for the device\).

-   `i16RateY` is the required rate of movement of y-chromaticity in the CIE xyY colour space, in steps per second \(a step is one unit of y-chromaticity for the device\).

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Step Colour Command Payload 

```
typedef struct
{
    int16                           i16StepX;
    int16                           i16StepY;
    uint16                          u16TransitionTime;
    zbmap8                          u8OptionsMask;
    zbmap8                          u8OptionsOverride;     
} tsCLD_ColourControl_StepColourCommandPayload;

```

where:

-   `i16StepX` is the amount by which the x-chromaticity in the CIE xyY colour space is to be changed \(increased or decreased\), in units of x-chromaticity for the device.

-   `i16StepY` is the amount by which the y-chromaticity in the CIE xyY colour space is to be changed \(increased or decreased\), in units of y-chromaticity for the device.

-   `u16TransitionTime` is the time period, in tenths of a second, over which the colour change should be implemented.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Move To Colour Temperature Command Payload 

```
typedef struct
{
    uint16                          u16ColourTemperatureMired;
    uint16                          u16TransitionTime;
    zbmap8                          u8OptionsMask;
    zbmap8                          u8OptionsOverride;     
} tsCLD_ColourControl_MoveToColourTemperatureCommandPayload;

```

where:

-   `u16ColourTemperature``Mired` is the target value of the mired colour temperature attribute `u16ColourTemperature``Mired` \(this value is a scaled reciprocal of colour temperature - for details, refer to the attribute description in [Section 31.2](colour_control_cluster_structure_and_attributes.md#id_54c4562a-44a1-4034-8ede-37dcd0963729)\).

-   `u16TransitionTime` is the time period, in tenths of a second, over which the change in colour temperature should be implemented.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Move Colour Temperature Command Payload 

```
typedef struct
{
    teCLD_ColourControl_MoveMode     eMode;
    uint16                           u16Rate;
    uint16                           u16ColourTemperatureMiredMin;
    uint16                           u16ColourTemperatureMiredMax;
    zbmap8                           u8OptionsMask;
    zbmap8                           u8OptionsOverride;    
} tsCLD_ColourControl_MoveColourTemperatureCommandPayload;

```

where:

-   `eMode` indicates the required action and/or direction of the change in the mired colour temperature attribute value:


|**eMode**|**Action/Direction**|
|---------|--------------------|
|0x00|Stop existing movement in colour temperature|
|0x01|Start increasing mired colour temperature attribute value|
|0x02|Reserved|
|0x03|Start decreasing mired colour temperature attribute value|
|0x04 – 0xFF|Reserved|

-   `u16Rate` is the required rate of movement in mired colour temperature steps per second \(a step is one unit of the mired colour temperature attribute\).

-   `u16ColourTemperature``Mired``Min` is the lower limit for the mired colour temperature attribute during the operation resulting from this command.

-   `u16ColourTemperature``Mired``Max` is the upper limit for the mired colour temperature attribute during the operation resulting from this command.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Step Colour Temperature Command Payload 
```
typedef struct
{
    teCLD_ColourControl_StepMode     eMode;
    uint16                           u16StepSize;
    uint16                           u16TransitionTime;
    uint16                           u16ColourTemperatureMiredMin;
    uint16                           u16ColourTemperatureMiredMax;
    zbmap8                           u8OptionsMask;
    zbmap8                           u8OptionsOverride;    
} tsCLD_ColourControl_StepColourTemperatureCommandPayload;

```

where:

-   `eMode` indicates the required direction of the change in the mired colour temperature attribute value:


|**eMode**|**Action/Direction**|
|---------|--------------------|
|0x00|Reserved|
|0x01|Increase mired colour temperature attribute value|
|0x02|Reserved|
|0x03|Decrease mired colour temperature attribute value|
|0x04 – 0xFF|Reserved|

-   `u16StepSize` is the amount by which the mired colour temperature attribute is to be changed \(increased or decreased\).

-   `u16TransitionTime` is the time period, in tenths of a second, over which the change in the mired colour temperature attribute should be implemented.

-   `u16ColourTemperature``Mired``Min` is the lower limit for the mired colour temperature attribute during the operation resulting from this command.

-   `u16ColourTemperature``Mired``Max` is the upper limit for the mired colour temperature attribute during the operation resulting from this command.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Enhanced Move To Hue Command Payload 

```
typedef struct
{
    uint16                              u16EnhancedHue;
    teCLD_ColourControl_Direction       eDirection;
    uint16                              u16TransitionTime;
    zbmap8                              u8OptionsMask;
    zbmap8                              u8OptionsOverride;     
} tsCLD_ColourControl_EnhancedMoveToHueCommandPayload;

```

where:

-   `u16EnhancedHue` is the target ‘enhanced’ hue value in terms of a step around the CIE colour ‘triangle’ - for the format, refer to the description of the attribute `u16EnhancedCurrentHue` in [Section 31.2](colour_control_cluster_structure_and_attributes.md#id_54c4562a-44a1-4034-8ede-37dcd0963729).

-   `eDirection` indicates the direction/path of the change in hue:


|**eDirection**|**Direction/Path**|
|--------------|------------------|
|0x00|Shortest path|
|0x01|Longest path|
|0x02|Up|
|0x03|Down|
|0x04 – 0xFF|Reserved|

-   `u16TransitionTime` is the time period, in tenths of a second, over which the change in hue should be implemented.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Enhanced Move Hue Command Payload 

```
typedef struct
{
    teCLD_ColourControl_MoveMode        eMode;
    uint16                              u16Rate;
    zbmap8                              u8OptionsMask;
    zbmap8                              u8OptionsOverride;     
} tsCLD_ColourControl_EnhancedMoveHueCommandPayload;

```

where:

-   `eMode` indicates the required action and/or direction of the change in hue:


|**eMode**|**Action/Direction**|
|---------|--------------------|
|0x00|Stop existing movement in hue|
|0x01|Start increase in hue|
|0x02|Reserved|
|0x03|Start decrease in hue|
|0x04 – 0xFF|Reserved|

-   `u16Rate` is the required rate of movement in ‘enhanced’ hue steps per second \(a step is one unit of hue for the device\).

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Enhanced Step Hue Command Payload 

```
typedef struct
{
    teCLD_ColourControl_StepMode        eMode;
    uint16                              u16StepSize;
    uint16                              u16TransitionTime;
    zbmap8                              u8OptionsMask;
    zbmap8                              u8OptionsOverride;     
} tsCLD_ColourControl_EnhancedStepHueCommandPayload;

```

where:

-   `eMode` indicates the required direction of the change in hue:


|**eMode**|**Action/Direction**|
|---------|--------------------|
|0x00|Reserved|
|0x01|Increase in hue|
|0x02|Reserved|
|0x03|Decrease in hue|
|0x04 – 0xFF|Reserved|

-   `u16StepSize` is the amount by which the ‘enhanced’ hue is to be changed \(increased or decreased\) - for the format, refer to the description of the attribute `u16EnhancedCurrentHue` in [Section 31.2](colour_control_cluster_structure_and_attributes.md#id_54c4562a-44a1-4034-8ede-37dcd0963729).

-   `u8TransitionTime` is the time period, in tenths of a second, over which the change in hue should be implemented.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Enhanced Move To Hue And Saturation Command Payload 

```
typedef struct
{
    uint16                             u16EnhancedHue;
    uint8                              u8Saturation;
    uint16                             u16TransitionTime;
    zbmap8                             u8OptionsMask;
    zbmap8                             u8OptionsOverride;    
} tsCLD_ColourControl_EnhancedMoveToHueAndSaturationCommandPayload;

```

where:

-   `u16EnhancedHue` is the target ‘enhanced’ hue value in terms of a step around the CIE colour ‘triangle’ - for the format, refer to the description of the attribute `u16EnhancedCurrentHue` in [Section 31.2](colour_control_cluster_structure_and_attributes.md#id_54c4562a-44a1-4034-8ede-37dcd0963729).

-   `u8Saturation` is the target saturation value.

-   `16TransitionTime` is the time period, in tenths of a second, over which the change in hue and saturation should be implemented.

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Colour Loop Set Command Payload 

```
typedef struct
{
    uint8                               u8UpdateFlags;
    teCLD_ColourControl_LoopAction      eAction;
    teCLD_ColourControl_LoopDirection   eDirection;
    uint16                              u16Time;
    uint16                              u16StartHue;
    zbmap8                              u8OptionsMask;
    zbmap8                              u8OptionsOverride;    
} tsCLD_ColourControl_ColourLoopSetCommandPayload;

```

where:

-   `u8UpdateFlags` is a bitmap indicating which of the other fields of the structure must be set \(a bit must be set to ‘1’ to enable the corresponding field, and ‘0’ otherwise\):


|**Bits**|**Field**|
|--------|---------|
|0|```
eAction

```

|
|1|```
eDirection

```

|
|2|```
u16Time

```

|
|3|```
u16StartHue

```

|
|4–7|Reserved|

-   `eAction` indicates the colour loop action to be taken \(if enabled through `u8UpdateFlags`\), as one of:


|**Enumeration**|**Value**|**Action**|
|---------------|---------|----------|
|E\_CLD\_COLOURCONTROL\_COLOURLOOP\_ACTION\_

 DEACTIVATE

|0x00|Deactivate colour loop|
|E\_CLD\_COLOURCONTROL\_COLOURLOOP\_ACTION\_

 ACTIVATE\_FROM\_START

|0x01|Activate colour loop from specified start \(enhanced\) hue value|
|E\_CLD\_COLOURCONTROL\_COLOURLOOP\_ACTION\_

 ACTIVATE\_FROM\_CURRENT

|0x02|Activate colour from current \(enhanced\) hue value|

-   `eDirection` indicates the direction to be taken around the colour loop \(if enabled through `u8UpdateFlags`\) in terms of the direction of change of `u16EnhancedCurrentHue`:


|**Enumeration**|**Value**|**Direction**|
|---------------|---------|-------------|
|E\_CLD\_COLOURCONTROL\_COLOURLOOP\_

 DIRECTION\_DECREMENT

|0x00|Decrement current \(enhanced\) hue value|
|E\_CLD\_COLOURCONTROL\_COLOURLOOP\_

 DIRECTION\_INCREMENT

|0x01|Increment current \(enhanced\) hue value|

-   `u16Time` is the period, in seconds, of a full colour loop - that is, the time to cycle all possible values of `u16EnhancedCurrentHue`.

-   `u16StartHue` is the value of `u16EnhancedCurrentHue` at which the colour loop is to be started \(if enabled through `u8UpdateFlags`\).

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


## Stop Move Step Command Payload 

```
typedef struct
{
    zbmap8                 u8OptionsMask;
    zbmap8                 u8OptionsOverride;    
} tsCLD_ColourControl_StopMoveStepCommandPayload;

```

where `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.

**Parent topic:**[Structures](../../Colour_Control_cluster/topics/structures.md)

