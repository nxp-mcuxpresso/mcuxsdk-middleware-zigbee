# Beacon filtering guidelines

A filter can be introduced for filtering beacons in network searches \(on a Router or End Device\). Beacons can be filtered on the basis of Extended PAN ID \(EPID\), LQI value and device joining status/capacity \(see below\). The filter can be applied using the function **ZPS\_bAppAddBeaconFilter\(\)**.

If required, the above function must be called immediately before **ZPS\_eAplZdoDiscoverNetworks\(\)**, **ZPS\_eAplZdoRejoinNetwork\(\)** or **ZPS\_eAplZdoStartStack\(\)**.

A `tsBeaconFilterType`structure is supplied to the **ZPS\_bAppAddBeaconFilter\(\)**

function in order to specify the details of the filter to be implemented, including:

-   A blacklist or whitelist of networks in terms of a list of EPIDs.
-   The PAN ID of the network from which acceptable beacons should come.
-   The minimum LQI value of an acceptable beacon.
-   Flags indicating the properties on which beacons will be filtered, which include:
    -   LQI value of beacon.
    -   Permit Join enabled on sending device.
    -   Capacity of sending device to accept Router children.
    -   Capacity of sending device to accept End Device children.

After each discovery or rejoin, the flags are cleared while all other fields of the structure remain intact. The structure is detailed in [Section 8.2.3.5](tsbeaconfiltertype.md).

The following general guidelines should be followed in using beacon filters:

-   **Do not** implement a filter unless attempting a join, as this would prevent some stack operations from working correctly.
-   **Do not** enable a blacklist and whitelist at the same time.
-   **Do not** declare your filter structure as a local variable in a function, as it needs to exist for the duration of the discovery.

The following guidelines are relevant to network rejoins and associations.


```{include} ../topics/network_rejoin.md
:heading-offset: 2
```

```{include} ../topics/association.md
:heading-offset: 2
```

**Parent topic:**[Appendix B: Application design notes](../topics/application_design_notes.md)

