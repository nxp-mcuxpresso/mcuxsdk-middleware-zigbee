# Controlling Hue and Saturation

Colour can be completely specified in terms of hue and saturation, which respectively represent the dominant wavelength \(or frequency\) of the light and the spread of wavelengths \(around the former\) within the light. Therefore, the Colour Control cluster provides commands to change both the hue and saturation at the same time. In fact, commands are provided to control the values of the:

-   ‘current hue’ and ‘current saturation’ attributes

-   ‘enhanced current hue’ and ‘current saturation’ attributes


API functions are available to send these commands to endpoints on remote devices.

## ‘Move to Hue and Saturation’ Command 

The ‘Move to Hue and Saturation’ command allows the ‘current hue’ and ‘current saturation’attributes to be moved to specified target values in a continuous manner over a specified transition time. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandMoveToHueCommandSend\(\)**

## ‘Enhanced Move to Hue and Saturation’ Command 

The ‘Enhanced Move to Hue and Saturation’ command allows the ‘enhanced current hue’ and ‘current saturation’attributes to be moved to specified target values in a continuous manner over a specified transition time. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandEnhancedMoveToHueAndSaturationCommandSend\(\)**

**Parent topic:**[Sending Commands](../../Colour_Control_cluster/topics/sending_commands.md)

