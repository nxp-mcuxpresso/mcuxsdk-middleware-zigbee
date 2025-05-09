# Touchlink Commissioning events

Touchlink Commissioning cluster events that result from receiving Touchlink requests and responses must be handled at the application level \(while events that result from Commissioning Utility requests and responses are handled by the ZCL\).

When a Touchlink request or response command \(e.g. a Scan Request\) is received by a node, a stack event is generated which is wrapped in a `tsZCL_CallBackEvent` structure. In this structure:

-   `eEventType` field is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM

-   `sClusterCustomMessage` field’s `tsZCL_ClusterCustomMessage` structure is filled in by:

    -   setting `u16ClusterId` to ZLL\_CLUSTER\_ID\_COMMISSIONING

    -   pointing `pvCustomData` to the payload data of the received command

        -   The above structure is described in [Section 6.1.15](../../ZCL_structures/topics/tszcl_clustercustommessage.md#id_78bfa34d-151f-4908-a056-d83228e45d56).

The payload data contains a command ID, which uses one of the enumerations listed in [Section 44.6.1](touchlink_command_events.md#id_9ffb3bb1-010d-459b-8d49-cea000a973b1). The event is passed to the ZCL event handler which checks that the command ID is valid for the target endpoint. If it is valid, the user-defined callback function is invoked that was specified through the function **eZLL\_RegisterCommissionEndPoint\(\)**. The callback function can access the payload through the `tsCLD_ZllCommissionCustomDataStructure` structure, which is created when the above function is called.

Thus, the above user-defined callback function must be designed to handle the relevant Touchlink events:

-   For a request, the callback function may need to populate a structure with the required data and send a response using the appropriate response function, e.g. by calling **eCLD\_ZllCommissionCommandScanRspCommandSend\(\)** to respond to a Scan Request.

-   For a response, the callback function may just need to extract the returned data from the event.


Alternatively, the callback function may simply notify the main application of the received command and provide the payload, so that the application can process the command.


```{include} ../../touchlink_cluster/topics/touchlink_command_events.md
:heading-offset: 2
```

```{include} ../../touchlink_cluster/topics/commissioning_utility_command_events.md
:heading-offset: 2
```

**Parent topic:**[Touchlink Commissioning Cluster](../../touchlink_cluster/topics/touchlink_commissioning_cluster.md)

