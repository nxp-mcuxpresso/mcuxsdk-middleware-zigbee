# eCLD\_ASCLogQueueResponseORStatisticsAvailableSend

```
teZCL_Status eCLD_ASCLogQueueResponseORStatisticsAvailableSend(
        uint8 u8SourceEndPointId,
        uint8 u8DestinationEndPointId,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        teCLD_ApplianceStatistics_ServerCommandId 
eCommandId);

```

## Description 

This function can be used on an Appliance Statistics cluster server to send a ‘Log Queue Response’ message \(in reply to a ‘Log Queue Request’ message\) or an unsolicited ‘Statistics Available’ message to a cluster client.

The command to be sent must be specified as one of:

-   E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_QUEUE\_RESPONSE

-   E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_STATISTICS\_AVAILABLE


You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint through which to send the message. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values
-   *u8DestinationEndPointId* Number of the endpoint on the remote node to which the message is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *psDestinationAddress* Pointer to a structure holding the address of the node to which the message is sent
-   *pu8TransactionSequenceNumber* Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *eCommandId* Enumeration indicating the command to be sent \(see above and [Section 48.8.3](server_command_id_enumerations.md#id_6b8b25cb-008a-4739-a65d-c754a1c31738)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Functions](../../appliance_statistics_cluster/topics/functions.md)

