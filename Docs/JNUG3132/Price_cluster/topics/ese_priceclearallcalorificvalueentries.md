# eSE\_PriceClearAllCalorificValueEntries

```
teSE_PriceStatus eSE_PriceClearAllCalorificValueEntries(
    uint8 u8SourceEndPointId,
    bool_t bIsServer);

```

## Description 

This function can be used to delete all entries in a calorific value list on the local device.

You must specify the endpoint on which the local Price cluster resides and whether this cluster instance is a server or a client.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint for the calorific value list to be cleared
-   *bIsServer* Nature of the Price cluster instance containing the price list:
    -   TRUE - server
    -   FALSE - client

## Returns

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

