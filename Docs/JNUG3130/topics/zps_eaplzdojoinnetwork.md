# ZPS\_eAplZdoJoinNetwork

```
ZPS\_teStatus ZPS\_eAplZdoJoinNetwork\(ZPS\_tsNwkNetworkDescr \*psNetworkDescr\);
```

**Description**

This function can be used by a Router or End Device to send a request to join a particular network, following a network discovery.

The required network is specified using its network descriptor, obtained in a `ZPS_EVENT_NWK_DISCOVERY_COMPLETE` event which results from a network discovery previously implemented using **ZPS\_eAplZdoStartStack\(\)** or **ZPS\_eAplZdoDiscoverNetworks\(\)**. For details of this event, refer to [ZPS\_tsAfNwkDiscoveryEvent](zps_tsafnwkdiscoveryevent.md).

If the join request is successfully sent, the function will return ZPS\_E\_SUCCESS \(note that this does not mean that device has joined the network\). The result of the join request will then be reported through a stack event \(see [Events](events.md) for details of these events\):

-   If the device successfully joined the network as a Router, the event **ZPS\_EVENT\_NWK\_JOINED\_AS\_ROUTER** is generated. The allocated 16-bit network address of the Router is returned as part of this stack event.
-   If the device successfully joined the network as an End Device, the event **ZPS\_EVENT\_NWK\_JOINED\_AS\_ENDDEVICE** is generated. The allocated 16-bit network address of the End Device is returned as part of this stack event.
-   If the join request was unsuccessful, the event ZPS\_EVENT\_NWK\_FAILED\_TO\_JOIN is generated.

**Note:** Note that nodes can join a ZigBee PRO network to a maximum depth of 15 \(levels below the Coordinator\).

**Parameters**

\**psNetworkDescr* Pointer to network descriptor of network to join.

**Returns**

-   ZPS\_E\_SUCCESS \(join request successfully sent\)

-   APS return codes, listed and described in [Section 11.2.2](aps_codes.md)
-   NWK return codes, listed and described in [Section 11.2.3](nwk_codes.md)
-   MAC return codes, listed and described in [Section 11.2.4](mac_codes.md)

**Parent topic:**[Network deployment functions](../topics/network_deployment_functions.md)

