# eCLD\_IASZoneUpdateCIEAddress

```
teZCL_Status eCLD_IASZoneUpdateCIEAddress(
    uint8 u8SourceEndPoint,
    u64IEEEAddress u64CIEAddress);

```

## Description 

This function can be used on an IAS Zone cluster server to update the 64-bit IEEE/MAC address stored in the `u64IASCIEAddress` attribute. This is the address of the CIE device to which the local device should send commands and notifications.

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS Zone cluster resides
-   *u64CIEAddress*: IEEE/MAC address to be written to the attribute

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Functions](../../IAS_Zone_cluster/topics/functions.md)

