# Searches for a network to join

As part of the **zps\_eAplZdoStartStack\(\)** function call, the device searches for networks by listening for beacons from Routers and Coordinators of ZigBee PRO networks in the neighborhood. The radio channel for this search is pre-configured via the ZPS Configuration Editor \(see [Section 13.4.3](setting_coordinator_properties.md)\). The configuration is done in the same way as for the Coordinator as either a fixed channel \(in the range 11-26\) or a set of channels to scan. Thus, the device listens for beacons in the relevant channel\(s\).

A beacon filter can be optionally introduced using the function **zps\_bAppAddBeaconFilter\(\)** to allow only beacons from networks of interest to be considered - beacons can be filtered on the basis of PAN ID, Extended PAN ID, LQI value, and device joining status/capacity \(see Appendix B.4, [Beacon filtering guidelines](beacon_filtering_guidelines.md)\).

On completion of this search, the subsequent actions depend on the pre-set value of the 64-bit Extended PAN ID \(EPID\), which is set via the advanced device parameter *APS Use Extended PAN ID*in the ZPS Configuration Editor \(see [Section 13.4.4](setting_advanced_device_parameters.md)\):

-   If the pre-set EPID value is non-zero, this value identifies a specific network to join \(assuming the Coordinator has been pre-set with the same EPID - see [Section 6.1.1](starting_the_coordinator.md)\). Provided that a network with this EPID has been discovered in the search, the device attempts to join this network as described in [Submits a join request to network](submits_a_join_request_to_network.md) \(therefore bypassing the steps listed in [Selects a network to join](selects_a_network_to_join.md)\).
-   If the pre-set EPID value is zero, the results of the search are reported in a zps\_EVENT\_NWK\_DISCOVERY\_COMPLETE stack event, which contains details of the networks discovered \(see [Section 6.2.1](obtaining_network_properties.md)\). The device must then select a network to join, as described in the following section.

**Parent topic:**[Starting Routers and End Devices](../topics/starting_routers_and_end_devices.md)

