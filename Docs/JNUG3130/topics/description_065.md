# Description

This function can be used to register a user-defined callback function that defines custom mappings between LQI values and link costs that are to be used in packet filtering, based on link cost. When packet filtering is enabled, the stack uses a default set of mappings, detailed in [Section 6.10.3.1](link_cost.md). The callback function is only needed if custom mappings are to be used that will over-ride the default mappings. If required, this registration function must be called before **ZPS\_eAplAfInit\(\)**, and on both cold and warm starts.

The user-defined callback function to be registered has the following prototype:

**uint8 APP\_u8LinkCost\(uint8** _u8Lqi_\);

This callback function translates a measured LQI value \(*u8Lqi*\) into a link cost value. An example function is given in [Section 6.10.3.3](packet_filtering_configuration.md).

For more information on packet filtering and link costs, refer to [Section 6.10.3](filtering_packets_on_lqi_value_link_cost.md).

**Parent topic:**[ZPS\_vNwkLinkCostCallbackRegister](../topics/zps_vnwklinkcostcallbackregister.md)

