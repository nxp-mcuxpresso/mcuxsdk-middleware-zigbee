# eSM\_CreateMirror

```
teSM_Status eSM_CreateMirror(
    uint8 u8MirrorEndpoint,
    uint64 u64RemoteIeeeAddress);

```

## Description 

This function can be used on the mirroring server \(ESP\) to create a mirror with the specified endpoint number for the Metering Device with the specified IEEE address. The endpoint number must be within the valid range for mirror endpoints on the ESP.

An error will be returned if there is no free mirror endpoint on which to create a mirror.

The function is normally used by an ESP application following a device reset, in order to recreate mirrors that were lost during the reset. This recovery assumes that the relevant IEEE addresses \(for Metering Devices\) associated with the mirror endpoints can be retrieved from non-volatile memory, where they were saved before the reset.

## Parameters 

-   *u8MirrorEndpoint*: Number of endpoint on which mirror will be created \(must be within valid range for mirror endpoints\)
-   *u64RemoteIeeeAddress*: IEEE address of Metering Device to be mirrored

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_RANGE
-   E\_CLD\_SM\_STATUS\_EP\_NOT\_AVAILABLE

**Parent topic:**[Functions](../../Simple_Metering_cluster/topics/functions.md)

