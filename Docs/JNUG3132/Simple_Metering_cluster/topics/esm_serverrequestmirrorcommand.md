# eSM\_ServerRequestMirrorCommand

```
teZCL_Status eSM_ServerRequestMirrorCommand(
    uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress);

```

## Description 

This function can be used by a Metering Device to request a mirror on the ESP, for the central storage of its metering data. A mirror is useful for a Metering Device which sleeps, in order to allow access to its metering data while the device is sleeping.

The function sends an ‘Add Mirror’ request to the ESP. The address of the ESP device must be specified as well as the endpoint that will receive and process the request - this is the main endpoint on which the ESP is registered on the Co-ordinator. If successful, the request will result in the allocation of a mirror endpoint \(on the ESP\) to the Metering Device.

**Note:** Before using this function to send an ‘Add Mirror’ request, the Metering Device application should check whether the ESP is currently accepting these requests by calling the function **eZCL\_SendReadAttributesRequest\(\)** to obtain the value of the `u8PhysicalEnvironment` attribute of the Basic cluster on the ESP. This attribute value will be non-zero if ‘Add Mirror’ requests are being accepted.

**eSM\_ServerRequestMirrorCommand\(\)** is a non-blocking function and so returns immediately after the request has been sent. The application must then wait for a response, indicated by the event E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND containing the command E\_CLD\_SM\_REQUEST\_MIRROR\_RESPONSE. If a mirror was successfully created, the number of the allocated mirror endpoint on the ESP is included in the event.

Mirroring and mirror set-up are fully described in [Section 42.5](mirroring_metering_data.md#id_5c7e7e7a-7756-4e07-8334-371d731931ac).

## Parameters 

-   *u8SourceEndpoint*: Number of local endpoint through which request is sent
-   *u8DestinationEndpoint*: Number of ESP endpoint to which request is sent \(main endpoint of ESP\)
-   *psDestinationAddress*: Pointer to a structure containing the address of the ESP device \(to which the request is sent\)

## Returns

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_CLUSTER\_ID\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_EP\_RANGE

**Parent topic:**[Functions](../../Simple_Metering_cluster/topics/functions.md)

