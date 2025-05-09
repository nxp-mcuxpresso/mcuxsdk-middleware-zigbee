# Setting Level

The level on the device on a local endpoint can be set using the function **eCLD\_LevelControlSetLevel\(\)**. This function sets the value of the ‘current level’ attribute of the Level Control cluster. A transition time must also be specified, in units of tenths of a second, during which the level moves toward the target value \(this transition should be as smooth as possible, not stepped\).

The specified level must be in the range 0x01 to 0xFE \(the extreme values 0x00 and 0xFF are not used\), where:

-   0x01 represents the minimum possible level for the device

-   0x02 to 0xFD are device-dependent values

-   0xFE represents the maximum level for the device


When the On/Off cluster is also enabled, calling the above function can have the following outcomes:

-   If the operation is to increase the current level, the OnOff attribute of the On/Off cluster is set to ‘on’.

-   If the operation is to decrease the current level to the minimum permissible level for the device, the OnOff attribute of the On/Off cluster is set to ‘off’.


**Parent topic:**[Issuing Local Commands](../../Level_Control_cluster/topics/issuing_local_commands.md)

