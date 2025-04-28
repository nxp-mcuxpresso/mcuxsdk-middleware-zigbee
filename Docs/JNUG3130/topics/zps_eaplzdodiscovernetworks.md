# ZPS\_eAplZdoDiscoverNetworks

```
ZPS\_teStatus ZPS\_eAplZdoDiscoverNetworks\(uint32 u32ChannelMask\);
```

**Description**

This function can be used by a Router or End Device to initiate a network discovery

- that is, to find a network to join.

A network discovery is performed when the stack is started using the function **ZPS\_eAplZdoStartStack\(\)**. The function **ZPS\_eAplZdoDiscoverNetworks\(\)** can be used to perform subsequent network discoveries \(for example, if the initial search did not yield any suitable networks\).

As part of this function call, you must specify a value which indicates the 2400-MHz radio channels \(numbered 11 to 26\) to be used in the network search. There are two ways of setting this parameter:

-   A single value in the range 11 to 26 can be specified, indicating that the corresponding channel \(and no other\) must be used - for example, 12 indicates use channel 12.
-   A 32-bit mask can be used to specify a set of channels that the device will scan to find a network - each of bits 11 to 26 represents the corresponding radio channel, where the channel will be included in the scan if the bit is set to 1 \(and excluded if cleared to 0\). Therefore, the value 0x07FFF800 represents all channels.

**Note:** If an invalid value is specified for this parameter, the default value of 0x07FFF800 \(all channels\) will be used.

If this function successfully initiates a network discovery, ZPS\_E\_SUCCESS will be returned. The network discovery results will then be reported through the event ZPS\_EVENT\_NWK\_DISCOVERY\_COMPLETE \(for details of this event, refer to [Section 7.2.2.9](zps_tsafnwkdiscoveryevent.md)\). This includes a list of the detected networks and the index \(in the list\) of the recommended network to join. You should then call **ZPS\_eAplZdoJoinNetwork\(\)** to join the desired network.

**Parameters**

*u32ChannelMask* Radio channel\(s\) for network discovery \(see above\)

**Returns**

`ZPS_E_SUCCESS` \(network discovery started\)

-   APS return codes, listed and described in [Section 11.2.2](aps_codes.md)
-   NWK return codes, listed and described in [Section 11.2.3](nwk_codes.md)
-   MAC return codes, listed and described in [Section 11.2.4](mac_codes.md)

**Parent topic:**[Network deployment functions](../topics/network_deployment_functions.md)

