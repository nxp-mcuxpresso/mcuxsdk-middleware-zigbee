# Description

This function allows packet filtering based on ‘link cost’ to be enabled/disabled, as well as some basic configuration of the filtering. Packet filtering is disabled by default.

The default ‘link cost threshold’ is 5. This means that when packet filtering is enabled, received packets with a link cost of 5 or less are discarded by the stack and not queued for processing. The link cost threshold can be modified \(from the default value of 5\) using this function.

If required, this function can be called at any time after **ZPS\_eAplAfInit\(\)**.

For more information on packet filtering and link costs, refer to **Section 6.10.3**, [Filtering packets on LQI Value/Link cost](filtering_packets_on_lqi_value_link_cost.md).

**Parent topic:**[ZPS\_vAplAfEnableMcpsFilter](../topics/zps_vaplafenablemcpsfilter.md)

