# ZPS\_eAplZdoRejoinNetwork

```
**ZPS\_teStatus ZPS\_eAplZdoRejoinNetwork\(bool\_t bWithDiscovery\);**
```

This function can be used by an active Router or End Device to send a request to rejoin its previous network. The function should be called if the application detects that it has lost its connection to the network - this is indicated by an excessive number of failed communications \(for example, with many missing acknowledgments\).

Options are provided to first perform a network discovery to find potential parents to join or simply rejoin the previous parent.

If the rejoin request is successfully sent, the function returns ZPS\_E\_SUCCESS. Note that this does not mean that device has rejoined the network. The result of the rejoin request is then reported through a stack event \(see [Section 10.1](events.md) for details of these events\):

-   If the device successfully rejoined the network as a Router, the event ZPS\_EVENT\_NWK\_JOINED\_AS\_ROUTER is generated.
-   If the device successfully rejoined the network as an End Device, the event ZPS\_EVENT\_NWK\_JOINED\_AS\_ENDDEVICE is generated.
-   If the rejoin request was unsuccessful, the event ZPS\_EVENT\_NWK\_FAILED\_TO\_JOIN is generated.

In the case of a successful rejoin, the node will retain its previously allocated 16-bit network address.

Note that the ‘permit joining’ status of the potential parent is ignored during a rejoin.

**Parameters**

*bWithDiscovery* Specifies whether a network discovery is required:

-   TRUE - perform network discovery before rejoining
-   FALSE - rejoin previous parent

-   TRUE - perform network discovery before rejoining
-   FALSE - rejoin previous parent

ZPS\_E\_SUCCESS \(rejoin request successfully sent\)

-   APS return codes, listed and described in [Section 11.2.2](aps_codes.md)
-   NWK return codes, listed and described in [Section 11.2.3](nwk_codes.md)
-   MAC return codes, listed and described in [Section 11.2.4](mac_codes.md)

**Parent topic:**[Network deployment functions](../topics/network_deployment_functions.md)

