# eCLD\_IASZoneStatusChangeNotificationSend

```
teZCL_Status eCLD_IASZoneStatusChangeNotificationSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_IASZone_StatusChangeNotificationPayload
    *psPayload);

```

## Description 

This function can be used on IAS Zone cluster server to send a Zone Status Change Notification to the IAS Zone client.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which to send the request. This parameter is used both to send the command and to identify the instance of the shared structure holding the required attribute values
-   *u8DestinationEndPointId*: Number of the endpoint on the remote node to which the request is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *psDestinationAddress*: Pointer to a structure holding the address of the node to which the request is sent
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the request
-   *psPayload*: Pointer to a structure containing the payload for the command \(see [Section 37.6.2](custom_command_payloads.md#id_da793402-0c54-4342-a9e4-2980d444fc1e)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

If an error is returned by the ZigBee PRO stack function which is invoked by this function to transmit the data, this error may be obtained by calling **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Functions](../../IAS_Zone_cluster/topics/functions.md)

