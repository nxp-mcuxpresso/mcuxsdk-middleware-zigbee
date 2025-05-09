# Unsolicited Price Updates

When the ESP receives updated price information from the utility company \(via the backhaul network\) or a new price tier becomes active, the ESP must inform all network devices that are using the Price cluster. The ESP therefore individually unicasts a Publish Price command to all these devices. This command is sent out automatically - there is no need for the application on the ESP to explicitly send the command. In the case of new prices received from the utility company, the ESP application must call the function **eSE\_PriceAddPriceEntry\(\)** to add the new price to the price list held by the server, and the Publish Price command is then automatically sent out \(possibly with a ‘start-time of now’\). Note that if the stack has not been started when **eSE\_PriceAddPriceEntry\(\)** is called, the function’s address mode parameter should be set to E\_ZCL\_AM\_NO\_TRANSMIT, so that no transmission is attempted.

It is recommended that price updates on the ESP are relayed to Price cluster clients with which the ESP has been \(previously\) bound.

**Note:** Each of these bindings is initiated on the client node \(e.g. IPD\) using the ZigBee PRO stack function **ZPS\_eAplZdpBindUnbindRequest\(\)** to add the client’s address and endpoint to the Binding table on the ESP. Binding is described in the *ZigBee 3.0 Stack User Guide \(JNUG3130\)*.

Therefore, when updating its price list, the ESP application should call **eSE\_PriceAddPriceEntry\(\)** with the address mode parameter set to E\_ZCL\_AM\_BOUND, so that the price updates are transmitted only to bound endpoints/nodes.

As an alternative to using binding, the ESP can maintain a list of network nodes that are able to receive unsolicited Publish Price commands at all times - that is, nodes with radio receivers that remain active during idle periods \(e.g. when sleeping\). Unsolicited updates are then only sent to clients in this group. The ESP gathers information for this group from the Get Current Price commands received from clients \(see [Section](get_current_price.md#id_4b60492f-41f6-4573-bede-13bf7f20e978)40.5.2\). This option requires the address node parameter to be set to ZPS\_E\_APL\_AF\_BROADCAST\_RX\_ON in **eSE\_PriceAddPriceEntry\(\)**.

The ESP can send unsolicited Publish Price commands with ‘start-time of now' when an E\_SE\_PRICE\_TABLE\_ACTIVE event indicates that a new price has become active \(see [Section 40.8](price_events.md#id_81b8d03f-c7fc-449a-a3ad-aff3c2d723ed)\). This command can be used by devices that do not implement a real-time clock.

**Parent topic:**[Publishing price information](../../Price_cluster/topics/publishing_price_information.md)

