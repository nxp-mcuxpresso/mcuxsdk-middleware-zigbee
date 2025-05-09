# eSE\_PriceGetCalorificValueEntry

```
teSE_PriceStatus eSE_PriceGetCalorificValueEntry(
    uint8 u8SourceEndPointId,
    bool_t bIsServer,
    uint8 u8TableIndex,
    sSE_PricePublishCalorificValueCmdPayload
    **ppsPublishCalorificValueCmdPayload);

```

## Description 

This function can be used to obtain the entry with the specified index from the calorific value list on the local device. For example, the function can be used on an IPD to obtain a calorific value to display.

You must specify the endpoint on which the local Price cluster resides and whether this cluster instance is a server or a client.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint for the calorific value list to be accessed
-   *bIsServer* Nature of the Price cluster instance containing the list:
    -   TRUE - server \(example on ESP\)
    -   FALSE - client \(example on IPD\)
-   *u8TableIndex* The index of the entry to obtain from the calorific value list \(index 0 is the entry with the oldest start-time and may contain the currently active calorific value\)
-   **ppsPublishCalorificValueCmdPayload: Pointer to a pointer to a structure which will be used to store the obtained calorific value information \(see [Section 40.11.3](tsse_pricepublishcalorificvaluecmdpayload.md#id_ed99c8fb-38d1-413f-ab81-cec209022de8)\), if found. The pointer value that is returned in this parameter points to the structure in the internal storage associated with the list. The data in the structure will be valid as long as the item remains in the list

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_SE\_PRICE\_TABLE\_NOT\_FOUND

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

