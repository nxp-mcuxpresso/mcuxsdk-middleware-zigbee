# Initializing and maintaining price lists

A list of prices is held on both the Price cluster server \(ESP\) and client\(s\). The price list on a client must be maintained to mirror the price list on the server. On device startup, the Price cluster software initializes the device’s price list as empty. The price lists are then built and maintained as described below.

The ESP receives price information from the utility company and populates its price list with this information. The application on the ESP does this by calling the function **eSE\_PriceAddPriceEntry\(\)** for each new price received from the utility company. This function also sends out a Publish Price command containing the new price information to all Price cluster clients in the network. On receiving this command, a Price cluster client automatically adds this price information to its own price list \(see [Section 40.5.1](unsolicited_price_updates.md#id_8a77360e-56a4-4ea8-8248-f0a4215f6789)\). However, at ESP startup, there may be no other active nodes in the network to receive the Publish Price commands \(since the ESP is normally also the ZigBee Co-ordinator and is, therefore, the first node to be started\). For this reason, the Price cluster clients should normally request the scheduled prices from the ESP when they start up, as described in [Section 40.5.3](get_scheduled_prices.md#id_26bb5320-478f-479a-ab70-8d123b1a81a5).

**Note:** When initializing the price list at ESP startup, the ESP application should call **eSE\_PriceAddPriceEntry\(\)** with the address mode parameter set to E\_ZCL\_AM\_NO\_TRANSMIT, so that the price additions are not subsequently transmitted.

**Note:** A Price cluster server should take precautions to prevent clients from attempting to read the server price list during ESP initialization, before the prices have been received from the utility company. This can be achieved by adding the obtained prices to the server price list after the call to the relevant endpoint registration function \(for example, **eSE\_RegisterEspEndPoint\(\)**\) but before the call **to ZPS\_eAplZdoStartStack\(\)**.

A price list is maintained in time order and if there is an active price, it is positioned at the head of the list \(with index 0\). Price lists on clients are updated to reflect the price list on the server, as described in [Section 40.5](publishing_price_information.md#id_0e05590b-cdd5-46ef-81a0-e55d97df116b).

**Note:** The Price cluster of ZigBee Smart Energy automatically deletes a price entry from a client or server price list immediately after the price event has expired. This is because the start-time of a price event is a universal time \(UTC\) and therefore corresponds to a one-off event. In practice, the price list may need a new price schedule daily, which may be provided by the utility company. Alternatively, if a similar schedule is required every day, the ESP application can keep a local copy of the schedule, which it can modify \(e.g. start-times\) and add to the price list on a daily basis.

The active price is always at the head of the price list \(entry zero\). The application should check that the entry at the head of the list is active before displaying it as the current price. If it is not active, a message may be displayed indicating that the current price is not known. The item at the head of the list is active if both of the following hold:

-   Its start time is less than or equal to the current time, obtained by **u32ZCL\_GetUTCTime\(\)**

-   The time on the client has been synchronized, i.e. a call to **bZCL\_GetTimeHasBeenSynchronised\(\)** returns TRUE


In addition to the function **eSE\_PriceAddPriceEntry\(\)**, the following functions allow an ESP application to access and manipulate its price list:

-   **eSE\_PriceGetPriceEntry\(\)** obtains the price entry with the specified index.

-   **eSE\_PriceDoesPriceEntryExist\(\)** checks whether there is a price entry with the specified start-time.

-   **eSE\_PriceRemovePriceEntry\(\)** deletes the price entry with the specified

    start-time.

-   **eSE\_PriceClearAllPriceEntries\(\)** deletes all price entries in the list.


These functions are fully detailed in [Section 40.9](functions.md#id_9b700b63-9af9-4fe5-bace-72e8fdeb15d3).

**Parent topic:**[Price Cluster](../../Price_cluster/topics/price_cluster.md)

