# Thermostat Events

The Thermostat cluster has its own events that are handled through the callback mechanism outlined in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). If a device uses the Thermostat cluster then Thermostat event handling must be included in the callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function \(for example, through **eHA\_RegisterThermostatEndPoint\(\)** for a Thermostat device\). The relevant callback function will then be invoked when a Thermostat event occurs.

For a Thermostat event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_ThermostatCallBackMessage` structure:

```
typedef struct
{
    uint8                       u8CommandId;
    union
    {
      tsCLD_Thermostat_SetpointRaiseOrLowerPayload 
                               *psSetpointRaiseOrLowerPayload;
    } uMessage;
} tsCLD_ThermostatCallBackMessage;

```

The `u8CommandId` field of the above structure specifies the type of command that has been received - only one command type is possible and is described below.

## E\_CLD\_THERMOSTAT\_CMD\_SETPOINT\_RAISE\_LOWER 

In the `tsCLD_ThermostatCallBackMessage` structure, the `u8CommandId` is set to E\_CLD\_THERMOSTAT\_CMD\_SETPOINT\_RAISE\_LOWER on the Thermostat cluster server when a SetpointRaiseOrLower command has been received. On receipt of this command, the Thermostat command handler will be invoked.

**Parent topic:**[Thermostat Cluster](../../thermostat_cluster/topics/thermostat_cluster.md)

