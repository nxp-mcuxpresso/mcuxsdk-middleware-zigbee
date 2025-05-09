# Switching Off Lights with Effect

In the case of lighting, lights can be \(remotely\) switched off with an effect by calling the function **eCLD\_OnOffCommandOffWithEffectSend\(\)** on an On/Off cluster client.

Two ‘off effects’ are available and there are variants of each effect:

-   **Fade**, with the following variants:

    -   Fade to off in 0.8 seconds \(default\)

    -   Reduce brightness by 50 % in 0.8 seconds then fade to off in 4 seconds

    -   No fade

-   **Rise and fall**, with \(currently\) only one variant:

    -   Increase brightness by 20 % \(if possible\) in 0.5 seconds then fade to off in 1 second \(default\)


**Parent topic:**[Sending Commands](../../OnOff_cluster/topics/sending_commands.md)

