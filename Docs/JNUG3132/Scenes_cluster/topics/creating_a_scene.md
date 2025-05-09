# Creating a Scene

In order to create a scene, add an entry for the scene to the Scene table on every device that contains a cluster, which is associated with the scene.

Use the function **eCLD\_ScenesCommandAddSceneRequestSend\(\)** to request a scene to be added to a Scene table on a remote device. Invoking this function sends a request to a single device or to multiple devices \(using binding or group addressing\). The fields of the Scene table entry are specified in the payload of the request.

Alternatively:

-   The function **eCLD\_ScenesCommandEnhancedAddSceneRequestSend\(\)** can be used to request that a scene is added to a Scene table on a remote device. This method allows the transition time for the scene to be set in units of tenths of a second \(rather than seconds\).

-   A scene can be created by saving the current attribute settings of the relevant clusters. In this way, the current state of the system can be captured as a scene and reapplied ‘at the touch of a button’ when required. For example scenes can be created for lighting levels in a ‘smart lighting’ system. The current settings are stored as a scene in the Scene table using **eCLD\_ScenesCommandStoreSceneRequestSend\(\)**. This function can send the request to a single device or multiple devices. If a Scene table entry exists with the same scene ID and group ID, the existing cluster settings in the entry are overwritten with the new ‘captured’ settings.


**Note:** This operation of capturing the current system state as a scene does not result in meaningful settings for the transition time and scene name fields of the Scene table entry. If non-null values are required for these fields, the table entry should be created in advance with the desired field values using **eCLD\_ScenesCommandAddSceneRequestSend\(\)**.

**Parent topic:**[Sending Remote Commands](../../Scenes_cluster/topics/sending_remote_commands.md)

