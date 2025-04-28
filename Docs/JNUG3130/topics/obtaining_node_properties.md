# Obtaining node properties

Functions are provided to obtain information about the properties of network nodes. Much of this information is held on a node in special structures, referred to as descriptors. Five types of descriptor are used:

-   Node descriptor
-   Node Power descriptor
-   Simple descriptor
-   User descriptor
-   Complex descriptor

In addition to the above, information can be obtained about the active endpoints, primary discovery cache and services of a node.

The required functions are detailed below. Functions are provided to obtain descriptors from the local node and from a remote node. When obtaining information from a remote node, the function sends a request in an APDU \(Application Protocol Data Unit\) which must first be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)**. The results of the request are reported in a response which must be collected using the function **ZQ\_bZQueueReceive\(\)**.

**Note:**

1.  When obtaining a descriptor of a remote node, the request can be submitted to the node itself or to another node which may hold the required descriptor in its primary discovery cache.
2.  The structures that contain the descriptors \(referenced below\) are described in [Section 7.2](!) and Section 8.2.1.
3.  Where 64-bit IEEE/MAC addresses are used to identify remote nodes, the corresponding 16-bit network addresses must be available in the local Address Map - see Section 5.2.3.


```{include} ../topics/node_descriptor_002.md
:heading-offset: 3
```

```{include} ../topics/power_descriptor.md
:heading-offset: 3
```

```{include} ../topics/simple_descriptor_001.md
:heading-offset: 3
```

```{include} ../topics/user_descriptor.md
:heading-offset: 3
```

```{include} ../topics/complex_descriptor.md
:heading-offset: 3
```

```{include} ../topics/active_endpoints.md
:heading-offset: 3
```

```{include} ../topics/primary_discovery_cache.md
:heading-offset: 3
```

```{include} ../topics/servers.md
:heading-offset: 3
```

**Parent topic:**[Discovering the network](../topics/discovering_the_network.md)

