# Custom Data Structure

The Alarms cluster requires extra storage space to be allocated for use by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
  DLIST   lAlarmsAllocList;
  DLIST   lAlarmsDeAllocList;
  tsZCL_ReceiveEventAddress       sReceiveEventAddress;
  tsZCL_CallBackEvent             sCustomCallBackEvent;
  tsCLD_AlarmsCallBackMessage     sCallBackMessage;
  tsCLD_AlarmsTableEntry          
  asAlarmsTableEntry[CLD_ALARMS_MAX_NUMBER_OF_ALARMS];
} tsCLD_AlarmsCustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../Alarms_cluster/topics/structures.md)

