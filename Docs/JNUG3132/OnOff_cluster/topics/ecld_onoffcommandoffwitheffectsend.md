# eCLD\_OnOffCommandOffWithEffectSend

```
teZCL_Status eCLD_OnOffCommandOffWithEffectSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_OnOff_OffWithEffectRequestPayload *psPayload);

```

## Description 

This function sends a custom ‘Off With Effect’ command instructing the target lighting device to switch off one or more lights with the specified effect, which can be one of:

-   fade \(in two phases or no fade\)

-   rise and fall


Each of these effects is available in variants. The required effect and variant are specified in the command payload. For the payload details, refer to ["Off With Effect Request Payload](custom_command_payloads.md#id_eae61fc7-fda9-48b2-acb0-5aa333dc3c39) ".

The device receiving this message generates a callback event on the endpoint on which the On/Off cluster was registered.

Following a call to this function, the light settings on the target device are saved to a global scene, after which the attribute `bGlobalSceneControl` is set to FALSE - for more details, refer to [Section 14.6](saving_light_settings.md#id_3cd235e7-bcd7-411a-8914-56f7163653a0).

If used, the ‘Off With Effect’ command must be enabled in the compile-time options on both the client and server, as described in [Section 14.10](compile-time_options.md#id_bfec7b3c-d152-4003-ac21-999c7d5ad203).

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which to send the request. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values.
-   *u8DestinationEndPointId*: Number of the endpoint on the remote node to which the request is sent. This parameter is ignored when sending to address types `eZCL_AMBOUND and eZCL_AMGROUP`.
-   *psDestinationAddress*: Pointer to a structure holding the address of the node to which the request is sent.
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the request.
-   *psPayload*: Pointer to a structure containing the payload for this message \(see [Section 14.8.2](custom_command_payloads.md#id_8b50e748-31b4-4744-938a-84649970bdf5)\).

## Returns 


-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

If an error is returned by the ZigBee PRO stack function which is invoked by this function to transmit the data, this error may be obtained by calling **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Functions](../../OnOff_cluster/topics/functions.md)

