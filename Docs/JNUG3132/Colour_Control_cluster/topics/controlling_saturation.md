# Controlling Saturation

Colour can be controlled in terms of saturation, which is related to the spread of wavelengths \(or frequencies\) in the light emitted by a lighting device. On a device that supports the Colour Control cluster, the saturation is controlled by means of the ‘current saturation’ attribute \(`u8CurrentSaturation`\) of the cluster. This attribute can take a value in the range 0-254, which can be converted to saturation as a fraction using the following formula:

Saturation = `u8CurrentSaturation`/254

The ‘current saturation’ attribute can be controlled in a number of ways using commands of the Colour Control cluster. API functions are available to send these commands to endpoints on remote devices.

## ‘Move to Saturation’ Command 
The ‘Move to Saturation’ command allows the ‘current saturation’ attribute to be moved \(increased or decreased\) to a specified target value in a continuous manner over a specified transition time. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandMoveToSaturationCommandSend\(\)**

## ‘Move Saturation’ Command 

The ‘Move Saturation’ command allows the ‘current saturation’ attribute to be moved in a given direction \(increased or decreased\) at a specified rate until stopped or until the current saturation reaches its minimum or maximum value. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandMoveSaturationCommandSend\(\)**

The above function can also be used to stop the movement.

## ‘Step Saturation’ Command 

The ‘Step Saturation’ command allows the ‘current saturation’ attribute to be moved \(increased or decreased\) by a specified amount in a continuous manner over a specified transition time. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandStepSaturationCommandSend\(\)**

**Note:** Saturation can also be moved in conjunction with hue, as described in [Section 31.5.7](controlling_hue_and_saturation.md#id_852d9844-60f6-46e8-8db5-9699b933426e).

**Parent topic:**[Sending Commands](../../Colour_Control_cluster/topics/sending_commands.md)

