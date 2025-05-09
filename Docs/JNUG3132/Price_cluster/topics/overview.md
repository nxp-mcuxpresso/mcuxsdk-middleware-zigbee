# Overview

The Price cluster is required in ZigBee devices as indicated in the table below.

||**Server-side**|**Client-side**|
|---|---------------|---------------|
|**Mandatory in...**|ESP|Smart Appliance|
|**Optional in...**||ESP Metering Device, IPD, PCT, Load Control Device

 

 
The ESP normally acts as the Price cluster server, holding price information received from the utility company. Other devices act as clients and receive price information from the ESP. The clients’ price information must be kept up-to-date with the server’s price information.

The Price cluster is enabled by defining CLD\_PRICE in the **zcl\_options.h** file. Further compile-time options for the Price cluster are detailed in [Section 40.13](compile-time_options.md#id_d7c0b485-9cb7-41c2-b7ba-4c8aff1d72fe).

The Price cluster can operate in a mode in which pricing is based on the time at which the consumption occurs - this is called Time-Of-Use \(TOU\) mode. The cluster allows up to fifteen price ‘tiers’, numbered 1 to 15, which correspond to different time periods. Each price tier is given a label, which is used to identify the tier - typical labels are "Normal", "Shoulder", "Peak", "Real-time Pricing" and "Critical Peak". The tiers must be numbered consecutively in price order, with Tier 1 being the cheapest.*Note that tiers 7 to 15 are not certifiable in SE 1.1.1 or earlier and are reserved for future use.*

The information that can potentially be stored in the Price cluster is organised into the following attribute sets: Tier Label, Block Threshold, Block Period, Commodity, Block Price Information, Billing Period Information. The attribute sets Block Threshold, Block Period, Block Price Information and Billing Period Information are reserved for future use \(with Block mode\). There is also a set of attributes exclusively for use on a Price cluster client.

The cluster includes commands for requesting and publishing \(distributing\) price information. The price information that is valid for a certain time is sent from the Price cluster server \(ESP\) to the Price cluster clients using **Publish Price**commands, which may be sent from the ESP under the following circumstances:

-   Unsolicited from the server - for example, when new pricing information has been received from the utility company or a new price tier becomes active

-   In response to a **Get Current Price** command, sent by a client that needs the price for the current time period

-   In response to a **Get Scheduled Prices** command, sent by a client that needs both current and future prices


Functions are provided for implementing the cluster commands. These functions are referenced in [Section 40.4](initialising_and_maintaining_price_lists.md#id_d693ce1d-578c-4436-a1b5-6243109ba412) and [Section 40.5](publishing_price_information.md#id_0e05590b-cdd5-46ef-81a0-e55d97df116b), and detailed in [Section 40.9](functions.md#id_9b700b63-9af9-4fe5-bace-72e8fdeb15d3).

**Parent topic:**[Price Cluster](../../Price_cluster/topics/price_cluster.md)

