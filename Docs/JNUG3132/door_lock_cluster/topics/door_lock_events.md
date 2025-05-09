# Door Lock Events

The Door Lock cluster has its own events that are handled through the callback mechanism outlined in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). If a device uses the Door Lock cluster then Door Lock event handling must be included in the callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function \(for example, through **eHA\_RegisterDoorLockEndPoint\(\)** for a Door Lock device\). The relevant callback function will then be invoked when a Door Lock event occurs.

For a Door Lock event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_DoorLockCallBackMessage` structure:

```
typedef struct
{
    uint8    u8CommandId;
    union
    {
       tsCLD_DoorLock_LockUnlockResponsePayload *psLockUnlockResponsePayload;
    }uMessage;
 }tsCLD_DoorLockCallBackMessage;

```

When a Door Lock event occurs, one of two command types could have been received. The relevant command type is specified through the `u8CommandId` field of the `tsCLD_DoorLockCallBackMessage` structure. The possible command types are detailed below.

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|        E\_CLD\_DOOR\_LOCK\_CMD\_LOCK|A lock request command has been received by the clus-ter server|
|E\_CLD\_DOOR\_LOCK\_CMD\_UNLOCK|An unlock request command has been received by the cluster server|

**Parent topic:**[Door Lock Cluster](../../door_lock_cluster/topics/door_lock_cluster.md)

