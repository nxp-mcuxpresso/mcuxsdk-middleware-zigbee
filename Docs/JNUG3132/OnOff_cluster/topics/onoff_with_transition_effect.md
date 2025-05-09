# On/Off with Transition Effect

If the Level Control cluster \(see [Chapter 16](../../Level_Control_cluster/topics/level_control_cluster.md#id_492efae6-d88d-4203-be53-0039b6fe8f2d)\) is also used on the target device, an ‘On’ or ‘Off’ command can be implemented with a transition effect, as follows:

-   If the optional Level Control ‘On Transition Time’ attribute is enabled, an ‘On’ command results in a gradual transition. This transition is from the ‘off’ level to the ‘on’ level over the time-interval specified by the attribute.

-   If the optional Level Control ‘Off Transition Time’ attribute is enabled, an ‘Off’ command results in a gradual transition from the ‘on’ level to the ‘off’ level over the time-interval specified by the attribute.


**Parent topic:**[Switching On and Off](../../OnOff_cluster/topics/switching_on_and_off.md)

