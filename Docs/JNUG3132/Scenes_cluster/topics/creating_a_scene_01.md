# Creating a Scene

A scene can be created on the local node using either of the following functions:

-   **eCLD\_ScenesAdd\(\):** This function can be used to add a new scene to the Scene table on the specified local endpoint. A scene ID and an associated group ID must be specified \(the latter must be set to 0x0000 if there is no group association\). If a scene with these IDs exists in the table, the existing entry is overwritten.

-   **eCLD\_ScenesStore\(\):** This function can be used to save the currently implemented attribute values on the device to a scene in the Scene table on the specified local endpoint. A scene ID and an associated group ID must be specified \(the latter must be set to 0x0000 if there is no group association\). If a scene with these IDs exists in the table, the existing entry is overwritten except for the transition time and scene name fields.


**Parent topic:**[Issuing Local Commands](../../Scenes_cluster/topics/issuing_local_commands.md)

