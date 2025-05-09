# eCLD\_ASCLogRequestSend

```
teZCL_Status eCLD_ASCLogRequestSend(
        uint8 u8SourceEndPointId,
        uint8 u8DestinationEndPointId,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        tsCLD_ASC_LogRequestPayload *psPayload);

```

## Description 

This function can be used on an Appliance Statistics cluster client to send a ‘Log Request’ message to a cluster server \(appliance\), in order request the data log with a specified log ID.

The function should normally be called after enquiring about log availability using the function **eCLD\_ASCLogQueueRequestSend\(\)** or after receiving an unsolicited ‘Statistics Available’ notification from the server.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint through which to send the message. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values
-   *u8DestinationEndPointId* Number of the endpoint on the remote node to which the message is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *psDestinationAddress* Pointer to a structure holding the address of the node to which the message is sent
-   *pu8TransactionSequenceNumber* Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *psPayload* Pointer to*a*structure containing the payload for the ‘Log Request’, including the relevant log ID \(see [Section 48.9.2](tscld_asc_logrequestpayload.md#id_f2d14175-9bec-422f-828f-82d40152ad61)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Functions](../../appliance_statistics_cluster/topics/functions.md)

