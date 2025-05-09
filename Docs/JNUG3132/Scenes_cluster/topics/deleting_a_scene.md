# Deleting a Scene

Two functions are provided for removing scenes from the system:

-   **eCLD\_ScenesCommandRemoveSceneRequestSend\(\)** can be used to request the removal of the destination endpoint from a particular scene - that is, to remove the scene from the Scene table on the target device.

-   **eCLD\_ScenesCommandRemoveAllScenesRequestSend\(\)** can be used to request that the target device removes scenes associated with a particular group ID/address - that is, remove all Scene table entries relating to this group ID. Specifying a group ID of 0x0000 removes all scenes not associated with a group.


**Parent topic:**[Sending Remote Commands](../../Scenes_cluster/topics/sending_remote_commands.md)

