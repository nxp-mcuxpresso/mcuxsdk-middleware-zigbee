# eCLD\_ThermostatCommandSetpointRaiseOrLowerSend

```
teZCL_Status eCLD_ThermostatCommandSetpointRaiseOrLowerSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_Thermostat_SetpointRaiseOrLowerPayload
*psPayload);

```

## Description 

This function can be used on a Thermostat cluster client to send a ‘Setpoint Raise Or Lower’ command to the cluster server. This command is used to increase or decrease the heating setpoint and/or cooling setpoint by requesting a change to the values of the attribute `i16OccupiedHeatingSetpoint` and/or the attribute `i16OccupiedCoolingSetpoint`. The relevant setpoint\(s\) and the required temperature change are specified in the command payload structure t`sCLD_Thermostat_SetpointRaiseOrLowerPayload` \(see [Section 33.9.3](tscld_thermostat_setpointraiseorlowerpayload.md#id_f5882254-946e-4ef4-9661-3ef2bb77c132)\).

A pointer must be specified to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request.

## Parameters 

-   *u8SourceEndPointId*                Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId*                Number of the remote endpoint to which the request is sent
-   *psDestinationAddress*                Pointer to a structure containing the address of the remote node to which the request is sent
-   *pu8TransactionSequenceNumber*                Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *psPayload*        Pointer to the command payload \(see [Section](tscld_thermostat_setpointraiseorlowerpayload.md#id_f5882254-946e-4ef4-9661-3ef2bb77c132)33.9.3\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Functions](../../thermostat_cluster/topics/functions.md)

