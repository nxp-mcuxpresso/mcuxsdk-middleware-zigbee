# eCLD\_ACSignalStateNotificationSend

```
teZCL_Status eCLD_ACSignalStateNotificationSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    bool bApplianceStatusTwoPresent,
    tsCLD_AC_SignalStateResponseORSignalStateNotificationPayload**        
*psPayload);

```

## Description 

This function can be used on an Appliance Control cluster server to send an unsolicited ‘Signal State Notification’ message to a cluster client. The function is an alternative to **eCLD\_ACSignalStateResponseORSignalStateNotificationSend\(\)**.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which to send the message. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values
-   *u8DestinationEndPointId*: Number of the endpoint on the remote node to which the message is sent. This parameter is ignored when sending to address types `eZCL_AMBOUND` and `eZCL_AMGROUP`
-   *psDestinationAddress*: Pointer to a structure holding the address of the node to which the message is sent
-   *psDestinationAddress*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *bApplianceStatusTwoPresent*: Boolean indicating whether additional appliance status data is present in payload:
    -   TRUE - Present
    -   FALSE - Not present
-   **psPPayload*: Pointer to structure containing payload for message \(see above and [Section 45.9.3](tscld_ac_signalstateresponseorsignalstatenotificat.md#id_62cbbba6-9e68-43f7-8ffc-b7f9112099d1)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Functions](../../appliance_control_cluster/topics/functions.md)

