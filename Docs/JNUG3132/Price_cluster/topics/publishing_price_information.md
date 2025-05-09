# Publishing price information

This section and its sub-sections describe the ways in which price information can be published \(distributed\) in a ZigBee network. As introduced in [Section 40.1](overview.md#id_db73e354-4b0b-4b2c-b613-1a021e01e05a), there are three ways in which price information may be published to the network from the Price cluster server \(ESP\):

-   Unsolicited unicasts - refer to [Section 40.5.1](unsolicited_price_updates.md#id_8a77360e-56a4-4ea8-8248-f0a4215f6789)

-   Response to a Get Current Price command - refer to [Section 40.5.2](get_current_price.md#id_4b60492f-41f6-4573-bede-13bf7f20e978)

-   Response to a Get Scheduled Prices command - refer to [Section 40.5.3](get_scheduled_prices.md#id_26bb5320-478f-479a-ab70-8d123b1a81a5)


All of the above methods require the ESP to send a Publish Price command to the relevant device\(s\), where the payload of this command includes information such as resource \(for example, gas\), unit of measure, currency, price, current time, start-time, and duration. On receipt of this command, if valid, the received price information is automatically added to the price list on the device. If it is successfully added, an E\_SE\_PRICE\_TABLE\_ADD event is generated on the receiving device and this event is handled by the callback function registered for the relevant endpoint.


```{include} ../../Price_cluster/topics/unsolicited_price_updates.md
:heading-offset: 2
```

```{include} ../../Price_cluster/topics/get_current_price.md
:heading-offset: 2
```

```{include} ../../Price_cluster/topics/get_scheduled_prices.md
:heading-offset: 2
```

**Parent topic:**[Price Cluster](../../Price_cluster/topics/price_cluster.md)

