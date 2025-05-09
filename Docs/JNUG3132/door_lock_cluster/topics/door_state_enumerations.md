# ‘Door State’ Enumerations

The following enumerations are used to set the optional `eDoorState` element in the Door Lock cluster structure `tsCLD_DoorLock`.

```
typedef enum 
{
    E_CLD_DOORLOCK_DOOR_STATE_OPEN  = 0x00,
    E_CLD_DOORLOCK_DOOR_STATE_CLOSED,
    E_CLD_DOORLOCK_DOOR_STATE_ERROR_JAMMED,
    E_CLD_DOORLOCK_DOOR_STATE_ERROR_FORCED_OPEN,
    E_CLD_DOORLOCK_DOOR_STATE_ERROR_UNSPECIFIED,
    E_CLD_DOORLOCK_DOOR_STATE_UNDEFINED = 0xFF
} teCLD_DoorLock_DoorState;;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_DOORLOCK\_DOOR\_STATE\_OPEN|Door is open|
|E\_CLD\_DOORLOCK\_DOOR\_STATE\_CLOSED|Door is closed|
|E\_CLD\_DOORLOCK\_DOOR\_STATE\_ERROR\_JAMMED|Door is jammed|
|E\_CLD\_DOORLOCK\_DOOR\_STATE\_ERROR\_FORCED\_OPEN|Door has been forced open|
|E\_CLD\_DOORLOCK\_DOOR\_STATE\_ERROR\_UNSPECIFIED|Door is in an unknown state|

**Parent topic:**[Enumerations](../../door_lock_cluster/topics/enumerations.md)

