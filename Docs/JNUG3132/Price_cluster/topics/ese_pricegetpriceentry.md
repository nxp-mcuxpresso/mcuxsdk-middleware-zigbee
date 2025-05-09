# eSE\_PriceGetPriceEntry

```
teSE_PriceStatus eSE_PriceGetPriceEntry(
    uint8 u8SourceEndPointId,
    bool_t bIsServer,
    uint8 u8TableIndex,
    tsSE_PricePublishPriceCmdPayload **psPricePayload);

```

## Description 

This function can be used to obtain the entry with specified index from a price list on the local device. For example, the function can be used on an IPD to obtain a price to display.

You must specify the endpoint on which the local Price cluster resides and whether this cluster instance is a server or a client.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint for the price list to be accessed
-   *bIsServer* Nature of the Price cluster instance containing the price list:
    -   TRUE - server \(for example, on ESP\)
    -   FALSE - client \(for example, on IPD\)
-   *u8TableIndex* The index of the price entry to obtain from the price list \(index 0 is the entry with the oldest start-time and may contain the currently active price\)
-   *psPricePayload* Pointer to a pointer to a structure which will be used to store the obtained price information \(see [Section 40.11.1](tsse_pricepublishpricecmdpayload.md#id_33de0832-fd7e-46e1-b6e3-7d58ef09b32a)\), if found. The pointer value that is returned in this parameter points to the structure in the internal storage associated with the list. The data in the structure will be valid as long as the item remains in the list

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_SE\_PRICE\_TABLE\_NOT\_FOUND

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

