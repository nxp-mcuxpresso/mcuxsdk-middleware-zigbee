# Association

-   **Do** set up an LQI filter to reject distant beacons, if required.
-   **Do** filter on the Permit Join status to only find potential parents and networks that are accepting association requests.
-   **Do** filter on Router/End Device Capacity, if required, depending on device type.

**Note:** A blacklist can be built up over several attempts to discover and associate, by keeping on adding to the array of EPIDs, as each network is rejected.

**Parent topic:**[Beacon filtering guidelines](../topics/beacon_filtering_guidelines.md)

