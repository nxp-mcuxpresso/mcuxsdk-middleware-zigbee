# eSM\_GetFreeMirrorEndPoint

```
teZCL_Status eSM_GetFreeMirrorEndPoint(
    uint16 *pu16FreeEP);

```

## Description 

This function can be used on the mirroring server \(ESP\) to obtain the number of the next available mirror endpoint. If there are no free mirror endpoints, the function sets the returned endpoint number to 0xFFFF.

The function is normally used in the ESP callback function to check the availability of mirror endpoints before updating the `u8PhysicalEnvironment` attribute of the Basic cluster \(this attribute is set to zero if no more mirror endpoints are available\).

Use of this function is described in [Section 42.5.1](configuring_mirroring_on_esp.md#id_56382dc2-f3cb-45d7-b933-601ecbbcede8).

## Parameters 

-   *pu16FreeEP*: Pointer to location to receive next free endpoint number

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Functions](../../Simple_Metering_cluster/topics/functions.md)

