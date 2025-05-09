# Get Scheduled Prices

Any device which supports the Price cluster can request the current price schedule from the ESP by sending a Get Scheduled Prices command - the schedule includes a set of prices with their start-times and durations. The function **eSE\_PriceGetScheduledPricesSend\(\)** allows a Price cluster client to send this command to the Price cluster server and deal with the responses.

-   On receiving the command, the server automatically responds with a sequence of Publish Price commands, where each of these responses contains the information for one scheduled price.

-   On receiving a response, the client checks whether the received price information is currently in the client’s price list. If it is not, the client adds the new price information to the list and generates an E\_SE\_PRICE\_TABLE\_ADD event - this event is handled by the callback function registered for the relevant endpoint.


**Parent topic:**[Publishing price information](../../Price_cluster/topics/publishing_price_information.md)

