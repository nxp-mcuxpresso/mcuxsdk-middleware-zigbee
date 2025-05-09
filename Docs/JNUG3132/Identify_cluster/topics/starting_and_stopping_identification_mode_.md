# Starting and Stopping Identification Mode

The function **eCLD\_IdentifyCommandIdentifyRequestSend\(\)** is used on the cluster client to send a command to the cluster server requesting identification mode to be started or stopped on the server device. The required action is contained in the payload of the command \(see [Section 11.7.2](custom_command_payloads.md#id_74e17b62-3335-44eb-90a8-5abb83392fda)\):

-   Setting the payload element *u16IdentifyTime* to a non-zero value has the effect of requesting that the server device enters identification mode for a time \(in seconds\) corresponding to the specified value.

-   Setting the payload element *u16IdentifyTime* to zero has the effect of requesting the immediate termination of any identification mode that is in progress on the server device.


Identification mode can alternatively be started and stopped on a light of a remote node as described in [Section 11.4.2](requesting_identification_effects.md#id_e84b7701-22c2-4ea5-828a-3221f7cdc0db).

**Parent topic:**[Sending Commands](../../Identify_cluster/topics/sending_commands.md)

