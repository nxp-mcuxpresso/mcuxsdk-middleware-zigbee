# eCLD\_ACExecutionOfCommandSend

```
teZCL_Status eCLD_ACExecutionOfCommandSend(
        uint8 u8SourceEndPointId,
        uint8 u8DestinationEndPointId,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        tsCLD_AC_ExecutionOfCommandPayload *psPayload);

```

## Description 

This function can be used on an Appliance Control cluster client to send an ‘Execution of Command’ message to a cluster server \(appliance\), where this message may specify one of the following control commands:

-   Start appliance cycle

-   Stop appliance cycle

-   Pause appliance cycle

-   Start superfreezing cycle

-   Stop superfreezing cycle

-   Start supercooling cycle

-   Stop supercooling cycle

-   Disable gas

-   Enable gas


The required command is specified in the payload of the message \(a pointer to this payload must be provided\). The commands are fully detailed in the British Standards document BS EN 50523.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameter 

-   *u8SourceEndPointId* Number of the local endpoint through which to send the message. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values
-   *u8DestinationEndPointId* Number of the endpoint on the remote node to which the message is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *psDestinationAddress* Pointer to a structure holding the address of the node to which the request is sent
-   *pu8TransactionSequenceNumber* Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *psPayload* Pointer to a structure containing the payload for the message \(see [Section 45.9.2](tscld_ac_executionofcommandpayload.md#id_dd9eab9f-773f-4836-aa62-b17497b01b1b)\).

## Returns 
-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Functions](../../appliance_control_cluster/topics/functions.md)

