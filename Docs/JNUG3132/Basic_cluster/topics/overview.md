# Overview

All devices implement the Basic cluster as a Server-side \(input\) cluster, so the cluster is able to store attributes and respond to commands relating to these attributes. The cluster’s attributes hold basic information about the node \(and apply to devices associated with all active endpoints on the host node\). The information that can potentially be stored in this cluster comprises: ZCL version, application version, stack version, hardware version, manufacturer name, model identifier, date, power source.

**Note:** The Basic cluster can also be implemented as a Client-side \(output\) cluster to allow the host device to act as a commissioning tool.

The Basic cluster contains only two mandatory attributes, the remaining attributes being optional - see [Section 8.2](basic_cluster_structure_and_attributes.md#id_db07b4c1-881a-43a8-8cfe-e74967cb40a6).

**Note:** Since the Basic cluster contains information about the entire node, only one set of Basic cluster attributes must be stored on the node, even if there are multiple instances of the Basic cluster server across multiple devices/endpoints. All cluster instances must refer to the same structure containing the attribute values.

The Basic cluster is enabled by defining CLD\_BASIC in the **zcl\_options.h** file.

A Basic cluster instance can act as a client and/or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Basic cluster are fully detailed in [Section 8.6](compile-time_options.md#id_109edd98-be6b-4f11-b13a-edf11be44178).

**Parent topic:**[Basic Cluster](../../Basic_cluster/topics/basic_cluster.md)

