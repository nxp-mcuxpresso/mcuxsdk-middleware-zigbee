# eCLD\_IASACE\_PanelStatusChanged

```
teZCL_Status eCLD_IASACE_PanelStatusChanged(
        uint8 u8SourceEndPointId,
        uint8 u8DestinationEndPointId,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        teCLD_IASACE_ServerCmdId eCommandId,
        tsCLD_IASACE_PanelStatusChangedOrGetPanelStatusRespPayload
        *psPayload);

```

## Description 

This function can be used on an IAS ACE cluster server to send an IAS ACE Panel Status Changed command to an IAS ACE client. This command informs the client that the value of the panel parameter `ePanelStatus` \(see [Section 38.7.4](panel_parameters.md#id_404b2665-5072-489a-a49d-24efc8eca54a)\) on the \(local\) CIE device has changed.

**Note:**

1.  The IAS ACE Panel Status Changed command is sent automatically when the function **eCLD\_IASACESetPanelParameter\(\)** is called to update the `ePanelStatus` parameter.
2.  The function alternatively provides the option of sending an IAS ACE Get Panel Status Response but, in practice, this response is sent automatically when a Get Panel Status Request is received.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which to send the request. This parameter is used both to send the command and to identify the instance of the shared structure holding the required attribute values
-   *u8DestinationEndPointId*: Number of the endpoint on the remote node to which the request is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *psDestinationAddress*: Pointer to a structure holding the address of the node to which the request is sent
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the request
-   *eCommandId*: Identifier of command to be sent - for Panel Status Changed command, always set to:: E\_CLD\_IASACE\_CMD\_PANEL\_STATUS\_CHANGED
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

