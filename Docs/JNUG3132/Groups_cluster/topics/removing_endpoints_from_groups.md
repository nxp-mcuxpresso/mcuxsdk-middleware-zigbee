# Removing Endpoints from Groups

Two functions are provided for removing one or more endpoints from groups on a remote device. Each function sends a command to the endpoints to be removed from the groups. If a group is empty following the removal of the endpoint, it is deleted in the Group table.

-   **eCLD\_GroupsCommandRemoveGroupRequestSend\(\)** can be used to request the removal of the target endpoint from the group which is specified in the payload of the command.

-   **eCLD\_GroupsCommandRemoveAllGroupsRequestSend\(\)** can be used to request the removal of the target endpoint from all groups on the remote device.


If an endpoint is a member of a scene associated with a group to be removed, the above function calls also results in the removal of the endpoint from the scene.

**Parent topic:**[Sending Commands](../../Groups_cluster/topics/sending_commands.md)

