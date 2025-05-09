# Requesting Identification Effects

The function **eCLD\_IdentifyCommandTriggerEffectSend\(\)** can be used to request a particular identification effect or behavior on a light of a remote node. This function can be used for entering and leaving identification mode instead of **eCLD\_IdentifyCommandIdentifyRequestSend\(\)**.

The possible behaviors that can be requested are as follows:

-   **Blink:** Light is switched on and then off \(once\)

-   **Breathe**: Light is switched on and off by smoothly increasing and then decreasing its brightness over a 1 second period, and then this process is repeated 15 times.

-   **Okay:**

    -   Colour light goes green for 1 second.

    -   Monochrome light flashes twice in 1 second.

-   **Channel change:**

    -   Colour light goes orange for 8 seconds.

    -   Monochrome light switches to maximum brightness for 0.5 s and then to minimum brightness for 7.5 s.

-   **Finish effect:** Current stage of effect is completed and then identification mode is terminated \(for example, for the Breathe effect, only the current 1 second cycle is completed\).

-   **Stop effect**: Current effect and identification mode are terminated as soon as possible.


**Parent topic:**[Sending Commands](../../Identify_cluster/topics/sending_commands.md)

