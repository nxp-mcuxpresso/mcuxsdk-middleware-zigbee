# Overview

A scene is a set of stored attribute values for one or more cluster instances, where these cluster instances may exist on endpoints on one or more devices.

The Scenes cluster allows standard values for these attributes to be set and retrieved. Thus, the cluster can be used to put the network or part of the network into a pre-defined mode \(for example, Night or Day mode for a lighting network\). These pre-defined scenes can be used as a basis for ‘mood lighting’. A Scenes cluster instance must be created on each endpoint which contains a cluster that is part of a scene.

A scene is often associated with a group \(which collects together a set of endpoints over one or more devices\) - groups are described in [Chapter 12](../../Groups_cluster/topics/groups_cluster.md#id_b6af3456-b2dc-4439-8085-c09909bffbe2). A scene may, however, be used without a group.

**Note:** When the Scenes cluster is used on an endpoint, a Groups cluster instance must always be created on the same endpoint, even if a group is not used for the scene.

If a cluster on a device is used in a scene, an entry for the scene must be contained in the Scene table on the device. A Scene table entry includes the scene ID, the group ID associated with the scene \(0x0000 if there is no associated group\), the scene transition time \(amount of time to switch to the scene\), and the attribute settings for the clusters on the device. The scene ID must be unique within the group with which the scene is associated.

To use the functionality of this cluster, you must include the file **Scenes.h** in your application and enable the cluster by defining CLD\_SCENES in the **zcl\_options.h** file.

It is also necessary to enable the cluster as a server or client, or as both:

-   The cluster server is able to receive commands to access scenes.

-   The cluster client is able to send commands to the server to request read or write access to scenes.


The inclusion of the client or server software must be pre-defined in the compile-time options of the application \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Scenes cluster are fully detailed in [Section 13.9](compile-time_options.md#id_b45fbe71-47cf-4b04-8f54-855e84da4e3a).

**Parent topic:**[Scenes Cluster](../../Scenes_cluster/topics/scenes_cluster.md)

