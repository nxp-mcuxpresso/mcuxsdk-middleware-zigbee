# eCLD\_IdentifyEZModeInvokeCommandSend

```
teZCL_Status eCLD_IdentifyEZModeInvokeCommandSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    bool bDirection,
    tsCLD_Identify_EZModeInvokePayload
    *psPayload);

```

## Description 

This function can be used to send an ‘EZ-mode Invoke’ to a remote device. The sent command requests one or more of the following stages of the EZ-mode commissioning process to be performed on the destination device. EZ-mode commissioning is a part of the ZigBee Base Device functionality and is described in the *ZigBee Devices User Guide \(JNUG3131\)*.

1. Factory Reset - clears all bindings, group table entries, and the `u8CommissionState` attribute, and reverts to the ‘Factory Fresh’ settings.

2. Network Steering - puts the destination device into the ‘Network Steering’ phase.

3. Find and Bind - puts the destination device into the ‘Find and Bind’ phase.

The required stages are specified in a bitmap in the command payload structure `tsCLD_Identify_EZModeInvokePayload` \(see [Section 11.7.4](ez-mode_commissioning_command_payloads.md#id_0a0d9e7d-cfe4-455d-a452-8ffad2dcda0f)\). If more than one stage is specified, they must be performed in the above order and be contiguous.

On receiving the ‘EZ-mode Invoke’ command on the destination device, an E\_CLD\_IDENTIFY\_CMD\_EZ\_MODE\_INVOKE event is generated with the required commissioning actions specified in the `u8Action` field of the `tsCLD_Identify_EZModeInvokePayload` structure. It is the responsibility of the local application to perform the requested actions using the functions of the EZ-mode Commissioning module \(see [Section 40.6](../../Price_cluster/topics/time-synchronisation_via_publish_price_commands.md)\).

Note that the ‘EZ-mode Invoke’ command is optional and, if necessary, must be enabled in the compile-time options \(see [Section 11.9](compile-time_options.md#id_585cc0f6-5292-4da8-bbbe-79babb2e0a4d)\).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which to send the request. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values.
-   *u8DestinationEndPointId*: Number of the endpoint on the remote node to which the request is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP.
-   *psDestinationAddress*: Pointer to a structure holding the address of the node to which the request is sent.
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the request.
-   *bDirection*: Boolean indicating the direction of the command, as follows \(this should always be set to TRUE\):
    -   TRUE - Identify cluster client to server
    -   FALSE - Identify cluster server to client
-   *psPayload*: Pointer to a structure containing the payload for the command \(see [Section 11.7.4](ez-mode_commissioning_command_payloads.md#id_0a0d9e7d-cfe4-455d-a452-8ffad2dcda0f)\).

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

If an error is returned by the ZigBee PRO stack function which is invoked by this function to transmit the data, this error may be obtained by calling **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Functions](../../Identify_cluster/topics/functions.md)

