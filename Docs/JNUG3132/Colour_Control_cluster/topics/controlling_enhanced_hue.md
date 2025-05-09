# Controlling ‘Enhanced’ Hue

Colour can be controlled in terms of hue, which is related to the dominant wavelength \(or frequency\) of the light emitted by a lighting device. The hue can alternatively be controlled by means of the ‘enhanced current hue’ attribute \(`u16EnhancedCurrentHue`\), instead of the ‘current hue’ attribute \(the ‘current hue’ attribute is automatically adjusted when the ‘enhanced current hue’ attribute value changes\).

The ‘enhanced current hue’ attribute allows hue to be controlled on a finer scale than the ‘current hue’ attribute. Hue steps are defined in a look-up table and values between the steps can be achieved through linear interpolation. This 16-bit attribute value therefore comprises two 8-bit components, as described below.

|**Bits 15-8**|**Bits 7-0**|
|-------------|------------|
|Index into the look-up table that

 contains the hue step values, thus indicating the current step used

|Linear interpolation value between the

 current step and next step \(up\)

|

Thus, if the current hue step value is *Hi* \(where *i* is the relevant table index\) and the linear interpolation value is *interp*, the ‘enhanced’ hue is given by the formula:

Enhanced hue = *Hi* + \(*interp*/255\) x \(*Hi+1* - *Hi* \)

To convert this hue to a value in degrees, it is then necessary to multiply by 360/255.

The ‘enhanced current hue’ attribute can be controlled in a number of ways using commands of the Colour Control cluster. API functions are available to send these commands to endpoints on remote devices.

**Note:** **Note:**These commands are issued by a cluster client and are performed on a cluster server. The look-up table is user-defined on the server. When this command is received by the server, the user-defined callback function that is invoked must read the entry with the specified index from the look-up table and calculate the corresponding ‘enhanced’ hue value.

## ‘Enhanced Move to Hue’ Command 

The ‘Enhanced Move to Hue’ command allows the ‘enhanced current hue’ attribute to be moved \(increased or decreased\) to a specified target value in a continuous manner over a specified transition time \(the ‘current hue’ attribute is also moved to a value based on the target ‘enhanced current hue’ value\). This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandEnhancedMoveToHueCommandSend\(\)**

Since the possible hues are represented on a closed boundary, the target hue can be reached by moving the attribute value in either direction, up or down \(the attribute value wraps around\). Options are also provided for taking the ‘shortest route’ and ‘longest route’ around the boundary.

## ‘Enhanced Move Hue’ Command 

The ‘Enhanced Move Hue’ command allows the ‘enhanced current hue’ attribute to be moved in a given direction \(increased or decreased\) at a specified rate indefinitely, until stopped \(the ‘current hue’ attribute is also moved through values based on the ‘enhanced current hue’ value\). This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandEnhancedMoveHueCommandSend\(\)**

The above function can also be used to stop the movement.

Since the possible hues are represented on a closed boundary, the movement is cyclic \(the attribute value wraps around\). The above function can also be used to stop the movement.

## ‘Enhanced Step Hue’ Command 

The ‘Enhanced Step Hue’ command allows the ‘enhanced current hue’ attribute to be moved \(increased or decreased\) by a specified amount in a continuous manner over a specified transition time \(the ‘current hue’ attribute is also moved through values based on the ‘enhanced current hue’ value\). This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandEnhancedStepHueCommandSend\(\)**

**Note:** **Note 1:** ‘Enhanced’ hue can also be moved in conjunction with saturation, as described in [Section](controlling_hue_and_saturation.md#id_852d9844-60f6-46e8-8db5-9699b933426e)31.5.7.

**Note:** **Note 2:** The value of the ‘enhanced current hue’ attribute can be moved around a colour loop, as described in [Section 31.5.6](controlling_a_colour_loop_.md#id_02c690ca-bffd-4c27-bebd-463647ea6e8a).

**Parent topic:**[Sending Commands](../../Colour_Control_cluster/topics/sending_commands.md)

