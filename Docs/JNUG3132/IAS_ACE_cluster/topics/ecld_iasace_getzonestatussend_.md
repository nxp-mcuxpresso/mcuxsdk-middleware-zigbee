# eCLD\_IASACE\_GetZoneStatusSend

```
teZCL_Status eCLD_IASACE_GetZoneStatusSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_IASACE_GetZoneStatusPayload *psPayload);

```

## Description

This function can be used on an IAS ACE cluster client to send an IAS ACE Get Zone Status command to an IAS ACE server. This command requests either of the following:

-   a list of all enrolled zones with their status

-   a list of those zones with a particular status \(that is, all zones with the `b16ZoneStatus` attribute of the IAS Zone cluster having a certain value\)


The list required is specified in the `bZoneStatusMaskFlag` field of the command payload \(see [Section 38.7.5](custom_command_payloads.md#id_becec8e4-bbfa-4204-8937-a7f52c960d70)\). If the second of the above lists is required, the status to look for is also specified in the payload.

The requested information is returned by the server in a response which generates an E\_CLD\_IASACE\_CMD\_GET\_ZONE\_STATUS\_RESP event when received on the client. A single response may not be able to carry all the zone status information to be returned and more than one request \(and associated response\) would be needed. For this reason, the request allows a starting zone and the number of zones to be included in the response to be specified \(in the request payload\).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which to send the request. This parameter is used both to send the command and to identify the instance of the shared structure holding the required attribute values
-   *u8DestinationEndPointId*: Number of the endpoint on the remote node to which the request is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *psDestinationAddress*: Pointer to a structure holding the address of the node to which the request is sent
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the request
-   *psPayload*: Pointer to a structure containing the payload for the command \(see [Section 38.7.5](custom_command_payloads.md#id_becec8e4-bbfa-4204-8937-a7f52c960d70)\)

## Returns

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

If an error is returned by the ZigBee PRO stack function which is invoked by this function to transmit the data, this error may be obtained by calling **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Functions](../../IAS_ACE_cluster/topics/functions.md)

