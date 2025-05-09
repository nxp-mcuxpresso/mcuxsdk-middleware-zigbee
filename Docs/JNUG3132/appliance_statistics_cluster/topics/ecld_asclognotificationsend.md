# eCLD\_ASCLogNotificationSend

```
teZCL_Status eCLD_ASCLogNotificationSend(
        uint8 u8SourceEndPointId,
        uint8 u8DestinationEndPointId,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        tsCLD_ASC_LogNotificationORLogResponsePayload
*psPayload);

```

## Description 

This function can be used on an Appliance Statistics cluster server to send an unsolicited ‘Log Notification’ message to a cluster client. The function is an alternative to **eCLD\_ASCLogNotificationORLogResponseSend\(\)**.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint through which to send the message. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values
-   *u8DestinationEndPointId* Number of the endpoint on the remote node to which the message is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *psDestinationAddress* Pointer to a structure holding the address of the node to which the message is sent
-   *pu8TransactionSequenceNumber* Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *psPayload* Pointer to structure containing payload for message \(see [Section 48.9.3](tscld_asc_lognotificationorlogresponsepayload.md#id_5db27449-4b3a-4b18-a4d1-a8f63b7b0d61)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Functions](../../appliance_statistics_cluster/topics/functions.md)

