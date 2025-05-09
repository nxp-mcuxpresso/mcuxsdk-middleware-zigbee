# tsCLD\_DoorLockCallBackMessage

For a Door Lock event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_DoorLockCallBackMessage` structure:

```
typedef struct
{
    uint8 u8CommandId;
    union
    {
      tsCLD_DoorLock_LockUnlockResponsePayload *psLockUnlockResponsePayload;
    }uMessage;
 }tsCLD_DoorLockCallBackMessage; 

```

where:

-   `u``8CommandId` indicates the type of Door Lock command \(lock or unlock\) that has been received, one of:

    -   E\_CLD\_DOOR\_LOCK\_CMD\_LOCK

    -   E\_CLD\_DOOR\_LOCK\_CMD\_UNLOCK

-   `uMessage` is a union containing the command payload in the following form:

    -   `psLockUnlockResponsePayload` is a pointer to a structure containing the response payload of the received command - see [Section 36.8.2](tscld_doorlock_lockunlockresponsepayload.md#id_aa41d60b-1c31-461c-8fe8-194ffab4f559)


**Parent topic:**[Structures](../../door_lock_cluster/topics/structures.md)

