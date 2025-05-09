# eCLD\_CommissioningCommandModifyStartupParamsSend

```
teZCL_Status eCLD_CommissioningCommandModifyStartupParamsSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_Commissioning_ModifyStartupParametersPayload *psPayload,
    teCLD_Commissioning_Command eCLD_Commissioning_Command);

```

## Description 

This function can be used on a Commissioning cluster client to send a command to modify a set of values for the Start-up Parameters attributes in the cluster server on a remote device. One of four commands can be specified and sent, as listed and described in the table below:

|**Command**|**Description**|
|-----------|---------------|
|Restart Device|Used to run the start-up procedure with the current set of values for the Start-up Parameters attributes, as described for the function **eCLD\_Com**-**missioningCommandRestartDeviceSend\(\)**. These values may have been loaded using the Restore Start-up Parameters or Reset Start-up Parameters command.|
|Save Start-up Parameters|Used to save the current set of Start-up Parameter values with the speci-fied index, as described for the function **eCLD\_CommissioningCom**-**mandSaveStartupParamsSend\(\)**.|
|Restore Start-up Parameters|Used to load the saved set of Start-up Parameter values with the specified index, such that these values become the current Start-up Parameter val-ues, as described for the function **eCLD\_CommissioningCommandRe**-**storeStartupParamsSend\(\)**. Note that these values are not implemented, which requires a Restart Device command.|
|Reset Start-up Parameters|Used to reset the current Start-up Parameters to their defaults. One or all of any stored sets of Start-up Parameter values can also be reset to the defaults, as described for the function **eCLD\_CommissioningComman**-**dResetStartupParamsSend\(\)**. The command can also be used to delete a particular set of stored Start-up Parameters.|

It is the responsibility of the user application on the device hosting the server to implement the command. When the command arrives, a ZCL custom event will be generated and the request should be handled by the user-defined callback function for the endpoint on which the application is located \(see [Section 43.6](commissioning_events.md#id_d75ba71a-55d6-4c86-a586-bbfbbfab97d8)\). The server will automatically send a response for the relevant command to the client, where a ZCL custom event will be generated.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*        Number of the local endpoint through which to send the request. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values
-   *u8DestinationEndPointId*        Number of the endpoint on the remote node to which the request is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *psDestinationAddress*        Pointer to a structure holding the address of the node to which the request is sent
-   *pu8TransactionSequenceNumber*        Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the request
-   *psPayload*        Pointer to a structure containing the payload for this message \(see [Section 43.9.3](tscld_commissioning_modifystartupparameterspayload.md#id_cbb888a3-3740-4fb9-856f-c0b6af1a4c41)\)
-   *eCLD\_Commissioning\_Command*        Type of command to send, one of:
-   E\_CLD\_COMMISSIONING\_CMD\_RESTART\_DEVICE
-   E\_CLD\_COMMISSIONING\_CMD\_SAVE\_STARTUP\_PARAMS
-   E\_CLD\_COMMISSIONING\_CMD\_RESTORE\_STARTUP\_PARAMS
-   E\_CLD\_COMMISSIONING\_CMD\_RESET\_STARTUP\_PARAMS

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Functions](../../Commissioning_cluster/topics/functions.md)

