# Controlling Hue

Colour can be controlled in terms of hue, which is related to the dominant wavelength \(or frequency\) of the light emitted by a lighting device. On a device that supports the Colour Control cluster, the hue is controlled by means of the ‘current hue’ attribute \(`u8CurrentHue`\) of the cluster. This attribute can take a value in the range 0-254, which can be converted to hue in degrees using the following formula:

Hue in degrees = `u8CurrentHue` x 360/254

The ‘current hue’ attribute can be controlled in a number of ways using commands of the Colour Control cluster. API functions are available to send these commands to endpoints on remote devices.

## ‘Move to Hue’ Command 

The ‘Move to Hue’ command allows the ‘current hue’ attribute to be moved \(increased or decreased\) to a specified target value in a continuous manner over a specified transition time. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandMoveToHueCommandSend\(\)**

Since the possible hues are represented on a closed boundary, the target hue can be reached by moving the attribute value in either direction, up or down \(the attribute value wraps around\). Options are also provided for taking the ‘shortest route’ and ‘longest route’ around the boundary.

## ‘Move Hue’ Command 

The ‘Move Hue’ command allows the ‘current hue’ attribute to be moved in a given direction \(increased or decreased\) at a specified rate indefinitely, until stopped. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandMoveHueCommandSend\(\)**

Since the possible hues are represented on a closed boundary, the movement is cyclic \(the attribute value wraps around\). The above function can also be used to stop the movement.

## ‘Step Hue’ Command 

The ‘Step Hue’ command allows the ‘current hue’ attribute to be moved \(increased or decreased\) by a specified amount in a continuous manner over a specified transition time. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandStepHueCommandSend\(\)**

**Note:** Hue can also be moved in conjunction with saturation, as described in [Section 31.5.7](controlling_hue_and_saturation.md#id_852d9844-60f6-46e8-8db5-9699b933426e). The ‘enhanced’ hue can be moved in similar ways, as described in [Section 31.5.5](controlling_enhanced_hue.md#id_b964d041-3d95-40e4-b9e1-d0596385dcb9).

**Parent topic:**[Sending Commands](../../Colour_Control_cluster/topics/sending_commands.md)

