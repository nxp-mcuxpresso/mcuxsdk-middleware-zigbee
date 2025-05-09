# eCLD\_IASWDUpdateMaxDuration

```
teZCL_Status eCLD_IASWDUpdateMaxDuration(
uint8 u8SourceEndPointId,
uint16 u16MaxDuration);

```

## Description 

This function can be used on an IAS WD cluster server to set the value of the `u16MaxDuration` attribute, which represents the maximum duration, in seconds, for which the alarm can be continuously active.

The set value is the maximum duration, in seconds, for which the alarm can be active following a received Start Warning request.

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS WD cluster resides
-   *u16MaxDuration*: Value to which attribute will be set, in the range 0 to 65534

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Functions](../../IAS_WD_cluster/topics/functions.md)

