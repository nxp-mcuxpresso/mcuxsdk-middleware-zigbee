# Link cost

For the purpose of packet filtering, LQI values are translated into ‘link cost’ values. Thus, a range of LQI values maps to a single link cost, which is an integer value. The default mappings implemented by the ZigBee PRO stack are shown in the table below.

**‘LQI to Link Cost’ Mappings**

|**LQI Range**|**Link Cost**|
|-------------|-------------|
|≥ 51|1|
|46 - 50|2|
|41 - 45|3|
|39 - 40|4|
|36 - 38|5|
|25 - 35|6|
|≤ 24|7|

The above mappings can be modified, as described in [Section 6.10.3.3](packet_filtering_configuration.md). A link cost of 5 is used as the packet filtering threshold by the NXP ZigBee PRO stack. Thus, packets with link costs greater than 5 may be discarded. For the device, this threshold is more suitable than the value of 3 proposed in the ZigBee specification. However, the threshold is configurable, as described in [Section 6.10.3.3](packet_filtering_configuration.md).

**Parent topic:**[Filtering packets on LQI Value/Link cost](../topics/filtering_packets_on_lqi_value_link_cost.md)

