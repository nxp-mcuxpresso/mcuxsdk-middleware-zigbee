# Copying a Scene

Scene settings can be copied from one scene to another scene on the same remote endpoint using the **eCLD\_ScenesCommandCopySceneSceneRequestSend\(\)** function. This function allows the settings from an existing scene with a specified source scene ID and associated group ID to be copied to a new scene with a specified destination scene ID and associated group ID.

**Note:** If an entry corresponding to the target scene ID and group ID exists in the Scene table on the endpoint, the entry settings are overwritten with the copied settings. Otherwise, a new Scene table entry is created with these settings.

The above function also allows all scenes associated with particular group ID to be copied to another group ID. In this case, the original scene IDs are maintained but are associated with the new group ID \(any specified source and destination scene IDs are ignored\). Thus, the same scene IDs are associated with two different group IDs.

**Parent topic:**[Sending Remote Commands](../../Scenes_cluster/topics/sending_remote_commands.md)

