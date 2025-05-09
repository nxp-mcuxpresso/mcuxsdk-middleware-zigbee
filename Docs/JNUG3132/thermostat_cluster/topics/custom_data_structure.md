# Custom Data Structure

The Thermostat cluster requires extra storage space to be allocated for use by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
    tsZCL_ReceiveEventAddress         sReceiveEventAddress;
    tsZCL_CallBackEvent               sCustomCallBackEvent;
    tsCLD_ThermostatCallBackMessage   sCallBackMessage;
} tsCLD_ThermostatCustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../thermostat_cluster/topics/structures.md)

