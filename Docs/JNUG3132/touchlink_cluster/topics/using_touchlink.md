# Using Touchlink

Touchlink is used for the basic commissioning of a new network or adding a new node to an existing network. A dedicated Touchlink application \(which is distinct from the main application on the node\) must reside on its own endpoint. This requires:

-   a Touchlink Commissioning cluster instance as a client to be created on the endpoint on the initiator node.

-   a Touchlink Commissioning cluster instance as a server to be created on the endpoint on the target node.


The initiator node also requires a Touchlink Commissioning cluster instance as a server \(on the same endpoint\), since the node also needs the capability to join an existing network.

An endpoint is registered for Touchlink \(on both nodes\) using the function **eZLL\_RegisterCommissionEndPoint\(\)**. This function also creates a Touchlink Commissioning cluster instance of the type \(server, client or both\) determined by the compile-time options in the header file **zcl\_options.h** \(see [Section 44.10](compile-time_options.md#id_b35eeb86-3074-417e-8aae-7184fa911842)\).

The initiator must then send a sequence of request commands to the target node. The Touchlink request command set is summarized in [Table 1](using_touchlink.md#table_6ebf31ca-9136-43fd-8da4-20bc355ef70b). Touchlink functions for issuing these commands are provided and are detailed in [Section 44.7.1](touchlink_functions.md#id_506de37b-4fe5-4bd5-874e-336a4019c8a4).  

**Using Touchlink**

|**Command**|**Identifier**|**Description**|
|-----------|--------------|---------------|
|Scan Request \*|0x00|Requests other devices \(potential nodes\) in the local neighbourhood to respond. A scan request is first performed on channel 11, up to five times until a response is received. If no response is received, a scan request is then performed once on each of channels 15, 20 and 25, and then the remaining channels \(12, 13, 14, 16, etc\) until a response is detected.|
|Device Information Request \*|0x02|Requests information about the devices on a remote node|
|Identify Request|0x06|Requests a remote node to physically identify itself \(for example, visually by flashing an LED\)|
|Reset To Factory New Request|0x07|Requests a factory reset of a remote node|
|Network Start Request \*|0x10|Requests a new network to be created comprising the initiator and a detected Router|
|Network Join Router Request \*|0x12|Requests a Router to join the network|
|Network Join End Device Request \*|0x14|Requests an End Device to join the network|
|Network Update Request \*|0x16|Requests an update of the network settings on a remote node \(if the supplied Network Update Identifier is more recent than the one on the node\)|

\* These commands have corresponding responses.

All Touchlink commands are sent as inter-PAN messages.

Use of the above commands and associated functions is described in the sub-sections below.


```{include} ../../touchlink_cluster/topics/creating_a_network.md
:heading-offset: 2
```

```{include} ../../touchlink_cluster/topics/adding_to_an_existing_network.md
:heading-offset: 2
```

```{include} ../../touchlink_cluster/topics/updating_network_settings.md
:heading-offset: 2
```

```{include} ../../touchlink_cluster/topics/stealing_a_node.md
:heading-offset: 2
```

**Parent topic:**[Touchlink Commissioning Cluster](../../touchlink_cluster/topics/touchlink_commissioning_cluster.md)

