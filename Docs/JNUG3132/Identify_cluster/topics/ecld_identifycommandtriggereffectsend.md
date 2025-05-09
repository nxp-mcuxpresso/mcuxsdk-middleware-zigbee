# eCLD\_IdentifyCommandTriggerEffectSend

```
teZCL_Status eCLD_IdentifyCommandTriggerEffectSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    teCLD_Identify_EffectId eEffectId,
    uint8 u8EffectVariant);

```

## Description 

This function can be called on a client device to send a custom command to a server device, in order to control the identification effect on a light of the target node. Therefore, this function can be used to start and stop identification mode instead of **eCLD\_IdentifyCommandIdentifyRequestSend\(\)**. Use of the ‘Trigger Effect’ function must be enabled via a compile-time option, as described in [Section 11.9](compile-time_options.md#id_585cc0f6-5292-4da8-bbbe-79babb2e0a4d).

The following effect commands can be sent using this function:

|**Effect command**|**Description**|
|------------------|---------------|
|Blink|Light is switched on and then off \(once\)|
|Breathe|Light is switched on and off by smoothly increasing and then decreasing its brightness over a 1-second period, and then this is repeated 15 times|
|Okay|-   Color light goes green for 1 second

-   Monochrome light flashes twice in 1 second


|
|Channel change|-   Color light goes orange for 8 seconds

-   Monochrome light switches to

maximum brightness for 0.5 s and then to

minimum brightness for 7.5 s


|
|Finish effect|Current stage of effect is completed and then identification mode is terminated \(for example, for the Breathe effect, only the current 1-second cycle is completed\)|
|Stop effect|Current effect and identification mode are terminated as soon as possible|

A variant of the selected effect can also be specified, but currently only the default \(as described above\) is available.

A device which receives this command generates a callback event on the endpoint on which the Identify cluster was registered.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which to send the request. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values.
-   *u8DestinationEndPointId*: Number of the endpoint on the remote node to which the request is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP.
-   *psDestinationAddress*: Pointer to a structure holding the address of the node to which the request is sent.
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the request.
-   *eEffectId*: Effect command to send \(see above\), one of:
    -   E\_CLD\_IDENTIFY\_EFFECT\_BLINK
    -   E\_CLD\_IDENTIFY\_EFFECT\_BREATHE
    -   E\_CLD\_IDENTIFY\_EFFECT\_OKAY
    -   E\_CLD\_IDENTIFY\_EFFECT\_CHANNEL\_CHANGE
    -   E\_CLD\_IDENTIFY\_EFFECT\_FINISH\_EFFECT
    -   E\_CLD\_IDENTIFY\_EFFECT\_STOP\_EFFECT
-   *u8EffectVariant*: Required variant of specified effect - set to zero for default \(as no variants are currently available\).

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

