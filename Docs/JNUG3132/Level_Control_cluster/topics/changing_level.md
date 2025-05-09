# Changing Level

Three functions \(see below\) are provided for sending commands to change the current level on a device. These commands modify the ‘current level’ attribute of the Level Control cluster.

Each of the three level functions can be implemented with the On/Off cluster. In this case:

-   If the command increases the current level, the OnOff attribute of the On/Off cluster is set to ‘on’.

-   If the command decreases the current level to the minimum permissible level for the device, the OnOff attribute of the On/Off cluster is set to ‘off’.


Use of the three functions/commands are described below.

## Move to Level Command 

The current level can be moved \(up or down\) to a new level over a given time using the function **eCLD\_LevelControlCommandMoveToLevelCommandSend\(\)**. The target level and transition time are specified in the command payload \(see [Section](move_to_level_command_payload.md#id_d29a3a21-87b6-4c7e-bf54-be9bd839c736)16.8.3.1\).

## Move Command 

The current level can be moved \(up or down\) at a specified rate using the function **eCLD\_LevelControlCommandMoveCommandSend\(\)**. The level varies until stopped \(see [Section 16.5.2](stopping_a_level_change.md#id_052880f9-faf1-4177-9f05-83f299519de5)\) or until the maximum or minimum level is reached. The direction and rate are specified in the command payload \(see [Section 16.8.3.2](move_command_payload.md#id_68bf0e81-1a15-474c-b2f5-cc62d79da035)\).

## Step Command 

The current level can be moved \(up or down\) to a new level in a single step over a given time using the function **eCLD\_LevelControlCommandStepCommandSend\(\)**. The direction, step size and, transition time are specified in the command payload \(see [Section 16.8.3.3](step_command_payload.md#id_b8a3ef8a-625f-441b-9846-53b2e17aee87)\).

**Parent topic:**[Sending Remote Commands](../../Level_Control_cluster/topics/sending_remote_commands.md)

