# Controlling Colour Temperature

Colour can be controlled in terms of colour temperature, which is the temperature of an ideal black body which radiates light of a similar hue to that of the lighting device. On a device that supports the Colour Control cluster, the colour temperature is controlled by means of the ‘mired colour temperature’ attribute \(`u16ColourTemperature``Mired`\) of the cluster. This attribute stores a micro reciprocal degree \(mired\) value, which is a scaled reciprocal of the current value of the colour temperature of the light, in the range 1-65279. The colour temperature, in Kelvin, can be calculated from the attribute value using the following formula:

T = 1000000/`u16ColourTemperature``Mired`

**Note:** The movement of colour temperature through colour space always follows the ‘Black Body Line'.

## ‘Move to Colour Temperature’ Command 

The ‘Move to Colour Temperature’ command allows the ‘mired colour temperature’ attribute to be moved \(increased or decreased\) to a specified target value in a continuous manner over a specified transition time. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandMoveToColourTemperatureCommandSend\(\)**

## ‘Move Colour Temperature’ Command 

The ‘Move Colour Temperature’ command allows the ‘mired colour temperature’ attribute to be moved in a given direction \(increased or decreased\) at a specified rate until stopped. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandMoveColourTemperatureCommandSend\(\)**

The above function can also be used to stop the movement.

Maximum and minimum values for the ‘mired colour temperature’ attribute during the movement are also specified. If the attribute value reaches the specified maximum or minimum before the required change has been achieved, the movement will automatically stop.

## ‘Step Colour Temperature’ Command 

The ‘Step Colour Temperature’ command allows the ‘mired colour temperature’ attribute to be moved \(increased or decreased\) by a specified amount in a continuous manner over a specified transition time. This command can be sent to an endpoint on a remote device using the function

**eCLD\_ColourControlCommandStepColourTemperatureCommandSend\(\)**

Maximum and minimum values for the ‘mired colour temperature’ attribute during the movement are also specified. If the attribute value reaches the specified maximum or minimum before the required change has been achieved, the movement will automatically stop.

**Parent topic:**[Sending Commands](../../Colour_Control_cluster/topics/sending_commands.md)

