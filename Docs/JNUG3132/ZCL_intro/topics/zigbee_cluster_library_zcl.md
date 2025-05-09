# ZigBee Cluster Library \(ZCL\)

The ZigBee Cluster Library \(ZCL\) for ZigBee 3.0 contains standard clusters, as defined by the ZigBee Alliance, for use in ZigBee 3.0 applications over a diverse range of market sectors. Each cluster corresponds to a specific functionality, through a set of attributes and/or commands. Clusters can be selected from the ZCL to give an application the required set of capabilities.

The ZCL also provides a common means for applications to communicate. It defines a header and payload that sit inside the Protocol Data Unit \(PDU\) used for messages. It also defines attribute types \(such as integers and strings\), common commands \(for example, for reading attributes\), and default responses for indicating success or failure.

The NXP implementation of the ZCL, described in this manual, is supplied in the ZigBee 3.0 Software Developer’s Kit \(SDK\) available via the NXP web site \(see [Support Resources](../../front/topics/zigbee_cluster_library_for_zigbee_30.md#5)\). These SDKs provide only the clusters supported by NXP that are described in this manual. The ZCL is fully detailed in the *ZigBee Cluster Library Specification \(075123\)*, available from the ZigBee Alliance.


```{include} ../../ZCL_intro/topics/zcl_member_clusters.md
:heading-offset: 1
```

```{include} ../../ZCL_intro/topics/general_zcl_resources.md
:heading-offset: 1
```

```{include} ../../ZCL_intro/topics/zcl_compile-time_options.md
:heading-offset: 1
```

