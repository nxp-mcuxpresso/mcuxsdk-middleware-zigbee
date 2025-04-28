# ZPS\_eAplZdoOrphanRejoinNetwork

```
ZPS_teStatus ZPS_eAplZdoOrphanRejoinNetwork(void);
```

This function can be used by an orphaned node to attempt to rejoin the network - the orphaned node may be an End Device or a Router. The function should also be used for a first-time join for which the parent has been pre-determined using the function **ZPS\_eAplZdoDirectJoinNetwork\(\)**.

The function starts the stack on the node. Therefore, when this function is used, there is no need to explicitly start the stack using **ZPS\_eAplZdoStartStack\(\)**.

If the rejoin request is successfully sent, the function will return ZPS\_E\_SUCCESS \(note that this does not mean that device has rejoined the network\). The result of the rejoin request will then be reported through a stack event \(see [Section 10.1](events.md) for details of these events\):

-   If the device successfully rejoined the network as a Router, the event `ZPS_EVENT_NWK_JOINED_AS_ROUTER` is generated.
-   If the device successfully rejoined the network as an End Device, the event `ZPS_EVENT_NWK_JOINED_AS_ENDDEVICE` is generated.
-   If the rejoin request was unsuccessful, the event `ZPS_EVENT_NWK_FAILED_TO_JOIN` is generated.

In the case of a successful rejoin of a genuinely orphaned node, the node will retain its previously allocated 16-bit network address.

**Note:** The ‘permit joining’ status of the potential parent is ignored during a rejoin.


```{include} ../topics/parameters_077.md
:heading-offset: 4
```

```{include} ../topics/returns_053.md
:heading-offset: 4
```

**Parent topic:**[Network deployment functions](../topics/network_deployment_functions.md)

