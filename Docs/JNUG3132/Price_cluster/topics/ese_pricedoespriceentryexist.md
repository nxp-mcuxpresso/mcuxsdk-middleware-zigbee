# eSE\_PriceDoesPriceEntryExist

```
teSE_PriceStatus eSE_PriceDoesPriceEntryExist(
    uint8 u8SourceEndPointId,
    bool_t bIsServer,
    uint32 u32StartTime);

```

## Description 

This function can be used to check whether a price entry with the specified start-time is present in a price list on the local device.

You must specify the endpoint on which the local Price cluster resides and whether this cluster instance is a server or a client.

For a price entry to be successfully found, the specified start-time must exactly match the start-time of an entry in the price list, otherwise the status code E\_SE\_PRICE\_NOT\_FOUND will be returned.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint for the price list to be accessed
-   *bIsServer* Nature of the Price cluster instance containing the price list:
    -   TRUE - server
    -   FALSE - client
-   *u32StartTime* Start-time of the price entry to search for

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_SE\_PRICE\_NOT\_FOUND

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

