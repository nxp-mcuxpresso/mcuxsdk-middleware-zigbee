# eCLD\_CommissioningCommandRestartDeviceSend

```
teZCL_Status eCLD_CommissioningCommandRestartDeviceSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber, tsCLD_Commissioning_RestartDevicePayload *psPayload);
```

## Description 

This function can be used on a Commissioning cluster client to send a Restart Device command to a cluster server on a remote device. This command is used to run the start-up procedure with a new set of values for the Start-up Parameters attributes \(these values must already be installed\). The new values may be implemented immediately or after a specified delay with an optional jitter.

When the command arrives, a ZCL custom event will be generated and the request should be handled by the user-defined callback function for the endpoint on which the application is located \(see [Section 43.6](commissioning_events.md#id_d75ba71a-55d6-4c86-a586-bbfbbfab97d8)\). Before running the start-up procedure or starting the countdown \(for the delay\), the server will send a Restart Device Response to the requesting client, where a ZCL custom event will be generated.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*        Number of the local endpoint through which to send the request. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values
-   *u8DestinationEndPointId*        Number of the endpoint on the remote node to which the request is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *psDestinationAddress*        Pointer to a structure holding the address of the node to which the request is sent
-   *pu8TransactionSequenceNumber*        Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the request
-   *psPayload*        Pointer to a structure containing the payload for this message \(see [Section 43.9.2](tscld_commissioning_restartdevicepayload.md#id_1df93820-8802-4516-b816-5ad7a67552ec)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Functions](../../Commissioning_cluster/topics/functions.md)

