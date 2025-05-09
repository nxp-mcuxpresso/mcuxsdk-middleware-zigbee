# Controlling a Colour Loop

The colour of a device can be controlled by moving the value of the ‘enhanced current hue’ attribute around a colour loop corresponding to the CIE colour ‘triangle’ - refer to [Section 31.5.5](controlling_enhanced_hue.md#id_b964d041-3d95-40e4-b9e1-d0596385dcb9) for details of the ‘enhanced current hue’ attribute.

Movement along the colour loop can be controlled using the ‘Colour Loop Set’ command of the Colour Control cluster. A function is available to send this command to endpoints on remote devices.

## ‘Colour Loop Set’ Command 

The ‘Colour Loop Set’ command allows movement of the ‘enhanced current hue’ attribute value around the colour loop to be configured and started. The direction\(up or down\), start ‘enhanced’ hue and duration of the movement can be specified. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandColourLoopSetCommandSend\(\)**

The above function can also be used to stop the movement.

**Parent topic:**[Sending Commands](../../Colour_Control_cluster/topics/sending_commands.md)

