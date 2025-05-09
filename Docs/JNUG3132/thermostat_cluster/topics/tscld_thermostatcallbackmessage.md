# tsCLD\_ThermostatCallBackMessage

For a Thermostat cluster event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_ThermostatCallBackMessage` structure:

```
typedef struct
{
    uint8                                           u8CommandId;
    union
    {
      tsCLD_Thermostat_SetpointRaiseOrLowerPayload *psSetpointRaiseOrLowerPayload;
    } uMessage;
} tsCLD_ThermostatCallBackMessage; 

```

where:

-   `u``8CommandId` indicates the type of Thermostat cluster command that has been received - there is only one possibility: E\_CLD\_THERMOSTAT\_CMD\_SETPOINT\_RAISE\_LOWER

-   `u``Message` is a union containing the command payload in the following form: `psSetpointRaiseOrLowerPayload` is a pointer to a structure containing the payload of a ‘Setpoint Raise Or Lower’ command - see [Section 33.9.3](tscld_thermostat_setpointraiseorlowerpayload.md#id_f5882254-946e-4ef4-9661-3ef2bb77c132).


**Parent topic:**[Structures](../../thermostat_cluster/topics/structures.md)

