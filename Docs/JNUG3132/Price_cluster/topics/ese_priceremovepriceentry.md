# eSE\_PriceRemovePriceEntry

```
teSE_PriceStatus eSE_PriceRemovePriceEntry(
    uint8 u8SourceEndPointId,
    bool_t bIsServer,
    uint32 u32StartTime);

```

## Description 

This function can be used to delete a price entry with specified start-time from a price list on the local device.

You must specify the endpoint on which the local Price cluster resides and whether this cluster instance is a server or a client.

For the successful deletion of a price entry, the specified start-time must exactly match the start-time of an entry in the price list, otherwise the status code E\_SE\_PRICE\_NOT\_FOUND will be returned.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint on which Price cluster resides
-   *bIsServer* Nature of the Price cluster instance containing the price list:
    -   TRUE - server
    -   FALSE - client
-   *u32StartTime* The start-time of the price entry to delete

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_SE\_PRICE\_NOT\_FOUND
-   E\_SE\_PRICE\_TABLE\_NOT\_FOUND

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

