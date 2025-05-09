# Switching On and Off

A remote device \(supporting the On/Off cluster server\) can be switched on, switched off or, toggled between the on and off states by calling the function **eCLD\_OnOffCommandSend\(\)** on a cluster client. In the case of a toggle, if the device is initially in the on state it is switched off and if the device is initially in the off state it is switched on.


```{include} ../../OnOff_cluster/topics/timeout_on_the_on_command.md
:heading-offset: 3
```

```{include} ../../OnOff_cluster/topics/onoff_with_transition_effect.md
:heading-offset: 3
```

**Parent topic:**[Sending Commands](../../OnOff_cluster/topics/sending_commands.md)

