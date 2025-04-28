# Description

This function can be used to introduce a filter that will be used for filtering beacons in network searches \(on a Router or End Device\). Beacons can be filtered on the basis of PAN ID, Extended PAN ID, LQI value and device joining status/capacity. The filter details are provided in a `tsBeaconFilterType`structure \(see [Section 8.2.3.5](tsbeaconfiltertype.md)\).

If required, this function should be called immediately before **ZPS\_eAplZdoDiscoverNetworks\(\)**, **ZPS\_eAplZdoRejoinNetwork\(\)** or **ZPS\_eAplZdoStartStack\(\)**.

**Note:** A filter should NOT be implemented unless attempting a join, as this would prevent some stack operations from working correctly.

Once the join or discovery has completed, the filter is automatically removed and needs to be re-instated if a retry is required.

Guidelines on the implementation of beacon filters are provided in , Appendix B.4, "[Beacon filtering guidelines](beacon_filtering_guidelines.md)".

**Parent topic:**[ZPS\_bAppAddBeaconFilter](../topics/zps_bappaddbeaconfilter.md)

