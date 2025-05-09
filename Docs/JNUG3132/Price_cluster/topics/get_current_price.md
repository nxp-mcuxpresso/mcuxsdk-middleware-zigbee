# Get Current Price

Any device which supports the Price cluster can request the currently active price information from the ESP by sending a Get Current Price command. The function **eSE\_PriceGetCurrentPriceSend\(\)** allows a Price cluster client to send this command to the Price cluster server and deal with the response.

-   On receiving the command, the server automatically responds with a Publish Price command containing the requested price information.

-   On receiving the response, the client checks whether the received price information is currently in the client’s price list. If it is not, the client adds the new price information to the list and generates an E\_SE\_PRICE\_TABLE\_ADD event - this event is handled by the callback function registered for the relevant endpoint.


The Get Current Price command contains information on whether the radio receiver of the sending device remains active when the node is otherwise idle \(e.g. sleeping\). If this is true, the ESP application can use the address of the node to update a list of such devices, which it may use when sending out unsolicited Publish Price commands \(see [Section 40.5.1](unsolicited_price_updates.md#id_8a77360e-56a4-4ea8-8248-f0a4215f6789)\). The ESP application can extract this information from the event E\_SE\_PRICE\_GET\_CURRENT\_PRICE\_RECEIVED which is generated when a Get Current Price command is received by the server - this event is handled by the callback function registered for the relevant endpoint.

**Parent topic:**[Publishing price information](../../Price_cluster/topics/publishing_price_information.md)

