# eCLD\_ColourControl\_GetRGB

```
teZCL_Status eCLD_ColourControl_GetRGB(
    uint8 u8SourceEndPointId,
    uint8 *pu8Red,
    uint8 *pu8Green,
    uint8 *pu8Blue);

```

## Description 

This function obtains the current colour of the device on the specified \(local\) endpoint in terms of the Red \(R\), Green \(G\) and Blue \(B\) components.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which the device resides
-   *pu8Red*: Pointer to a location to receive the red value, in the range 0-255
-   *pu8Green*: Pointer to a location to receive the green value, in the range 0-255
-   *pu8Blue*: Pointer to a location to receive the blue value, in the range 0-255

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND

If an error is returned by the ZigBee PRO stack function which is invoked by this function to transmit the data, this error may be obtained by calling **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Functions](../../Colour_Control_cluster/topics/functions.md)

