# eSM\_ServerRemoveMirrorCommand

```
teZCL_Status eSM_ServerRemoveMirrorCommand(
    uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress);

```

## Description 

This function can be used on a Metering Device to request the removal of the corresponding mirror on the ESP. The function should only be used to remove a mirror that has been previously set up by the Metering Device application using the function **eSM\_ServerRequestMirrorCommand\(\)**.

The function sends a ‘Remove Mirror’ request to the ESP. The address of the ESP must be specified as well as the endpoint number of the mirror to be removed.

This is a non-blocking function and so returns immediately after the request has been sent. The application must then wait for a response.

-   If the request was successful, a response will be received from the ESP resulting in the generation of the event E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND containing the command E\_CLD\_SM\_MIRROR\_REMOVED

-   If the request was unsuccessful, a ZCL default response will be received from the ESP to indicate that the request was not authorised \(E\_ZCL\_CMDS\_NOT\_AUTHORIZED\)


Mirror removal is fully described in [Section 42.5.5](removing_a_mirror.md#id_9333737e-544b-445f-aa26-20bcbc235032).

## Parameters 

-   *u8SourceEndpoint*: Number of local endpoint through which request is sent
-   *u8DestinationEndpoint*: Number of ESP endpoint which contains the mirror to be removed
-   *psDestinationAddress*:         Pointer to a structure containing the address of the ESP device \(to which the request is sent\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_CLUSTER\_ID\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_EP\_RANGE

**Parent topic:**[Functions](../../Simple_Metering_cluster/topics/functions.md)

