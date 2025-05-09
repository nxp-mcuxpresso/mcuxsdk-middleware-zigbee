# eSM\_RemoveMirror

```
teSM_Status eSM_RemoveMirror(
    uint8 u8MirrorEndpoint,
    uint64 u64RemoteIeeeAddress);

```

## Description 

This function can be used on the mirroring server \(ESP\) to remove the mirror with the specified endpoint number for the Metering Device with the specified IEEE address. The endpoint will then become free to be re-allocated for another mirror.

An error will be returned if the specified mirror endpoint cannot be found.

## Parameters 

-   *u8MirrorEndpoint*: Number of endpoint which hosts mirror to be removed \(must be within valid range for mirror endpoints\)
-   *u64RemoteIeeeAddress*: : IEEE address of mirrored Metering Device

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_RANGE
-   E\_CLD\_SM\_STATUS\_EP\_NOT\_AVAILABLE
-   E\_ZCL\_FAIL

**Parent topic:**[Functions](../../Simple_Metering_cluster/topics/functions.md)

