# eCLD\_IASWDUpdate

```
teZCL_Status eCLD_IASWDUpdate(
uint8 u8SourceEndPoint);

```

## Description 

This function can be used on an IAS WD cluster server to update the timing requirements of the Warning Device. The function should be called by the application at a rate of once every 100 ms.

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS WD cluster resides

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Functions](../../IAS_WD_cluster/topics/functions.md)

