# eCLD\_ColourControlCommandMoveToColourTemperatureCommandSend

```
teZCL_Status eCLD_ColourControlCommandMoveToColourTemperatureCommandSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_ColourControl_MoveToColourTemperatureCommandPayload
*psPayload);

```

## Description 

This function sends a Move to Colour Temperature command to instruct a device to move its ‘mired colour temperature’ attribute to a target value in a continuous manner within a given time. The attribute value is a scaled reciprocal of colour temperature, as indicated in [Section 31.5.4](controlling_colour_temperature.md#id_1d344768-d9ff-4fb4-a738-8346770be141). The target attribute value, direction and transition time are specified in the payload of the command \(see [Section 31.7.2](custom_command_payloads.md#id_9e6d37c2-c3fb-4f2f-83d7-bbac06d8c829)\).

The movement through colour space will follow the ‘Black Body Line'.

The device receiving this message will generate a callback event on the endpoint on which the Colour Control cluster was registered. The device must first ensure that ‘colour temperature’ mode is selected by setting the ‘colour mode’ attribute to 0x02, if required. It can then move the ‘mired colour temperature’ value as requested.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

This function can only be used when the ‘mired colour temperature’ attribute is enabled in the Colour Control cluster.

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which to send the request. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values
-   *u8DestinationEndPointId*: Number of the endpoint on the remote node to which the request is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *psDestinationAddress*: Pointer to a structure holding the address of the node to which the request is sent
-   *psDestinationAddress*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the request
-   **psPayload*: Pointer to a structure containing the payload for this message \(see [Section 31.7.2](custom_command_payloads.md#id_9e6d37c2-c3fb-4f2f-83d7-bbac06d8c829)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

If an error is returned by the ZigBee PRO stack function which is invoked by this function to transmit the data, this error may be obtained by calling **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Functions](../../Colour_Control_cluster/topics/functions.md)

