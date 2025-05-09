# Applying a Scene

The cluster settings of a scene stored in the Scene table can be retrieved and applied to the system by calling **eCLD\_ScenesCommandRecallSceneRequestSend\(\)**. Again, this function can send a request to a single device or to multiple devices \(using binding or group addressing\).

If the required scene does not contain any settings for a particular cluster or there are some missing attribute values for a cluster, these attribute values remain unchanged in the implementation of the cluster - that is, the corresponding parts of the system do not change their states.

**Parent topic:**[Sending Remote Commands](../../Scenes_cluster/topics/sending_remote_commands.md)

