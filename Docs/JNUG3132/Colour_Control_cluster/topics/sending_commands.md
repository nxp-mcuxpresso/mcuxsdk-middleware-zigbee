# Sending Commands

The NXP implementation of the ZCL provides functions for sending commands between a Colour Control cluster client and server. A command is sent from the client to one or more endpoints on the server. Multiple endpoints can usually be targeted using binding or group addressing.

**Note:** Any ‘Move to’, ‘Move’ or ‘Step’ command that is currently in progress can be stopped at any time by calling the function: **eCLD\_ColourControlCommandStopMoveStepCommandSend\(\)**


```{include} ../../Colour_Control_cluster/topics/controlling_hue.md
:heading-offset: 2
```

```{include} ../../Colour_Control_cluster/topics/controlling_saturation.md
:heading-offset: 2
```

```{include} ../../Colour_Control_cluster/topics/controlling_colour_cie_x_and_y_chromaticities.md
:heading-offset: 2
```

```{include} ../../Colour_Control_cluster/topics/controlling_colour_temperature.md
:heading-offset: 2
```

```{include} ../../Colour_Control_cluster/topics/controlling_enhanced_hue.md
:heading-offset: 2
```

```{include} ../../Colour_Control_cluster/topics/controlling_a_colour_loop_.md
:heading-offset: 2
```

```{include} ../../Colour_Control_cluster/topics/controlling_hue_and_saturation.md
:heading-offset: 2
```

**Parent topic:**[Colour Control Cluster](../../Colour_Control_cluster/topics/colour_control_cluster.md)

