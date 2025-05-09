# Adding Endpoints to Groups

Two functions are provided for adding one or more endpoints to a group on a remote device. Each function sends a command to the endpoints to be added to the group, where the required group is specified in the payload of the command. If the group does not exist in the Group table of the target device, it is added to the table.

-   **eCLD\_GroupsCommandAddGroupRequestSend\(\)** can be used to request the addition of the target endpoints to the specified group.

-   **eCLD\_GroupsCommandAddGroupIfIdentifyingRequestSend\(\)** can be used to request the addition of the target endpoints to the specified group if the target device is in identification mode of the Identity cluster \(see [Chapter 11](../../Identify_cluster/topics/identify_cluster.md#id_8d39ccb7-5ec3-439b-af2c-8b6105768b6d)\).


An endpoint can also be added to a local group, as described in [Section 12.3](initialisation.md#id_e3453974-3262-440c-9858-d2fc6731129b).

**Parent topic:**[Sending Commands](../../Groups_cluster/topics/sending_commands.md)

