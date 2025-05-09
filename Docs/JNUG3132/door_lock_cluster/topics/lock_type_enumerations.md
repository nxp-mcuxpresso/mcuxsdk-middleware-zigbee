# ‘Lock Type’ Enumerations

The following enumerations are used to set the `eLockType` element in the Door Lock cluster structure `tsCLD_DoorLock`.

```
typedef enum 
{
    E_CLD_DOORLOCK_LOCK_TYPE_DEAD_BOLT  = 0x00,
    E_CLD_DOORLOCK_LOCK_TYPE_MAGNETIC,
    E_CLD_DOORLOCK_LOCK_TYPE_OTHER,
    E_CLD_DOORLOCK_LOCK_TYPE_MORTISE,
    E_CLD_DOORLOCK_LOCK_TYPE_RIM,
    E_CLD_DOORLOCK_LOCK_TYPE_LATCH_BOLT,
    E_CLD_DOORLOCK_LOCK_TYPE_CYLINDRICAL_LOCK,
    E_CLD_DOORLOCK_LOCK_TYPE_TUBULAR_LOCK,
    E_CLD_DOORLOCK_LOCK_TYPE_INTERCONNECTED_LOCK,
    E_CLD_DOORLOCK_LOCK_TYPE_DEAD_LATCH,
    E_CLD_DOORLOCK_LOCK_TYPE_DOOR_FURNITURE
} teCLD_DoorLock_LockType;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_DOORLOCK\_LOCK\_TYPE\_DEAD\_BOLT|Dead bold lock|
|E\_CLD\_DOORLOCK\_LOCK\_TYPE\_MAGNETIC|Magnetic lock|
|E\_CLD\_DOORLOCK\_LOCK\_TYPE\_OTHER|Other type of lock|
|E\_CLD\_DOORLOCK\_LOCK\_TYPE\_MORTISE|Mortise lock|
|E\_CLD\_DOORLOCK\_LOCK\_TYPE\_RIM|Rim lock|
|E\_CLD\_DOORLOCK\_LOCK\_TYPE\_LATCH\_BOLT|Latch bolt|
|E\_CLD\_DOORLOCK\_LOCK\_TYPE\_CYLINDRICAL\_LOCK|Cylindrical lock|
|E\_CLD\_DOORLOCK\_LOCK\_TYPE\_TUBULAR\_LOCK|Tubular lock|
|E\_CLD\_DOORLOCK\_LOCK\_TYPE\_INTERCONNECTED\_LOCK|Interconnected lock|
|E\_CLD\_DOORLOCK\_LOCK\_TYPE\_DEAD\_LATCH|Dead latch|
|E\_CLD\_DOORLOCK\_LOCK\_TYPE\_DOOR\_FURNITURE|Door furniture lock|

**Parent topic:**[Enumerations](../../door_lock_cluster/topics/enumerations.md)

