# eSE\_PriceAddPriceEntryToClient

```
teSE_PriceStatus eSE_PriceAddPriceEntryToClient(
    uint8 u8SourceEndPointId,
    bool_t bOverwritePrevious,
    tsSE_PricePublishPriceCmdPayload *psPricePayload);
    
```

## Description 

This function can be used on a Price cluster client to add a price to the local price list directly.

Normally, price entries are automatically added to the price list on a client when a Publish Price command is received from the server \(e.g. the ESP\). However, this function can be used by the local application to directly add a price entry to the price list on the client. The function should therefore only be used on a device which does not receive price information from the server \(but by some other means, such as via the Internet\).

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint through which the request is sent
-   *bOverwritePrevious* Action to be taken if the new price overlaps \(in time\) a price which is already in the price list:
    -   TRUE - existing price deleted, new price added
    -   FALSE - new price not added and error returned
-   *psPricePayload* Pointer to a structure containing the price information to be added \(see [Section 40.11.1](tsse_pricepublishpricecmdpayload.md#id_33de0832-fd7e-46e1-b6e3-7d58ef09b32a)\). This parameter only needs to remain in scope for the duration of this function call

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE
-   E\_ZCL\_ERR\_TIME\_NOT\_SYNCHRONISED
-   E\_ZCL\_ERR\_INSUFFICIENT\_SPACE
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_SE\_PRICE\_OVERFLOW
-   E\_SE\_PRICE\_DUPLICATE
-   E\_SE\_PRICE\_DATA\_OLD

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

