# Saving Light Settings

In the case of lighting, the current light \(attribute\) settings can be automatically saved to a ‘global scene’ when switching off the lights using the function **eCLD\_OnOffCommandOffWithEffectSend\(\)**. If the lights are, then switched on with the E\_CLD\_ONOFF\_CMD\_ON\_RECALL\_GLOBAL\_SCENE option in **eCLD\_OnOffCommandSend\(\)**, the saved light settings are reloaded. In this way, the system remembers the last light settings used before switch-off and resumes with these settings at the next switch-on. This feature is useful when the light levels are adjustable using the Level Control cluster \([Chapter 16](../../Level_Control_cluster/topics/level_control_cluster.md#id_492efae6-d88d-4203-be53-0039b6fe8f2d)\) and/or the light colours are adjustable using the Colour Control cluster \([Chapter 31](../../Colour_Control_cluster/topics/colour_control_cluster.md#id_058f8405-367f-45f1-8eb4-5c7cccdee478)\).

The attribute values corresponding to the current light settings are saved \(locally\) to a global scene with scene ID and group ID both equal to zero. Therefore, to use this feature:

-   Scenes cluster must be enabled and a cluster instance created

-   Groups cluster must be enabled and a cluster instance created

-   Optional On/Off cluster attribute `bGlobalSceneControl` must be enabled


The above attribute is a boolean which determines whether to permit the current light settings to be saved to the global scene. The attribute is set to FALSE after a switch-off using the function **eCLD\_OnOffCommandOffWithEffectSend\(\)**. It is set to TRUE after a switch-on or a change in the light settings \(attributes\) - more specifically, after a change resulting from a Level Control cluster ‘Move to Level with On/Off’ command, from a Scenes cluster ‘Recall Scene’ command, or from an On/Off cluster 'On' command or 'On With Recall Global Scene' command.

**Parent topic:**[On/Off Cluster](../../OnOff_cluster/topics/onoff_cluster.md)

