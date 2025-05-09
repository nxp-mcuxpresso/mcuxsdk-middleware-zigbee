# Switching On Timed Lights

In the case of lighting, lights can be switched on temporarily and automatically switched off at the end of a timed period. This kind of switch-on can be initiated remotely using the function **CLD\_OnOffCommandOnWithTimedOffSend\(\)** on an On/Off cluster client. In addition, a waiting time can be implemented after the automatic switch-off, during which the lights cannot be switched on again using the above function \(although a normal switch-on is possible\).

The following values must be specified:

-   Time for which the lights remain on \(in tenths of a second\)

-   Waiting time following the automatic switch-off \(in tenths of a second\)


In addition, the circumstances in which the command can be accepted must be specified - that is, accepted at any time \(except during the waiting time\) or only when the lights are already on. The latter case can be used to initiate a timed switch-off.

**Parent topic:**[Sending Commands](../../OnOff_cluster/topics/sending_commands.md)

