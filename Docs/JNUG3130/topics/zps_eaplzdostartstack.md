# ZPS\_eAplZdoStartStack

```
ZPS\_teStatus ZPS\_eAplZdoStartStack\(void\);
```

**Description**

This function starts the ZigBee PRO stack. The steps taken depend on the node type:

-   If the device is the Coordinator, this function starts the network formation process.
-   If the device is a Router or End Device, this function starts the network discovery process - that is, the device searches for a network to join.

When the stack starts, the 2400 MHz radio channel to be used by the device is selected. The channels \(in the range 11 to 26\) available to the device should be specified in advance using the ZPS Configuration Editor \(see [Chapter 13](zps_configuration_editor.md)\) and can be either of the following:

-   A fixed channel
-   A set of channels for a channel scan:
    -   If the device is the Coordinator, this is the set of channels that the device scans to find a suitable operating channel for the network.
    -   If the device is a Router or End Device, this is the set of channels that the device scans to find a network to join.

If this function successfully initiates network formation or discovery, it returns ZPS\_E\_SUCCESS. Subsequent results from this process are then reported through stack events \(see [Events](events.md) for details of these events\):

-   If the Coordinator successfully creates a network, the event ZPS\_EVENT\_NWK\_STARTED is generated. Otherwise, the event ZPS\_EVENT\_NWK\_FAILED\_TO\_START is generated.
-   When the network discovery process for a Router or End Device is complete, the subsequent actions depend on the Extended PAN ID \(EPID\) that is pre-set using the ZPS Configuration Editor:
    -   If a zero EPID value was pre-set, the stack event `ZPS_EVENT_NWK_DISCOVERY_COMPLETE` is generated. This includes a list of the detected networks and the index \(in the list\) of the recommended network to join. You can then call **ZPS\_eAplZdoJoinNetwork\(\)** to join the desired network.
    -   If a non-zero EPID value was pre-set, the device automatically attempts to join the network with this EPID, provided that such a network has been discovered. Note that the ‘permit joining’ setting of the potential parent is ignored.

The maximum depth \(number of levels below the Coordinator\) of the network is 15.


```{include} ../topics/parameters_127.md
:heading-offset: 4
```

```{include} ../topics/returns_129.md
:heading-offset: 4
```

**Parent topic:**[Network deployment functions](../topics/network_deployment_functions.md)

