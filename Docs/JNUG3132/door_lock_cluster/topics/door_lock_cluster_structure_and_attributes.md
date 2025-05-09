# Door Lock Cluster structure and attributes

The Door Lock cluster is contained in the following `ts``CLD_DoorLock` structure:

```
typedef struct
{
#ifdef DOOR_LOCK_SERVER
    zenum8                   eLockState;
    zenum8                   eLockType;
    zbool                    bActuatorEnabled;
#ifdef CLD_DOOR_LOCK_ATTR_DOOR_STATE
    zenum8                   eDoorState;
#endif
#ifdef CLD_DOOR_LOCK_ATTR_NUMBER_OF_DOOR_OPEN_EVENTS
    zuint32                   u32NumberOfDoorOpenEvent;
#endif
#ifdef CLD_DOOR_LOCK_ATTR_NUMBER_OF_DOOR_CLOSED_EVENTS
    zuint32                   u32NumberOfDoorClosedEvent;
#endif
#ifdef CLD_DOOR_LOCK_ATTR_NUMBER_OF_MINUTES_DOOR_OPENED
    zuint16                   u16NumberOfMinutesDoorOpened;
#endif
#ifdef CLD_DOOR_LOCK_ZIGBEE_SECUTRITY_LEVEL
    zuint8                     u8ZigbeeSecurityLevel;
#endif
#ifdef CLD_DOOR_LOCK_ATTRIBUTE_REPORTING_STATUS
    zuint8                     u8AttributeReportingStatus;
#endif
#endif
    zuint16                    u16ClusterRevision;
} tsCLD_DoorLock;

```

where:

-   `eLockState` is a mandatory attribute indicating the state of the lock, one of:

    -   E\_CLD\_DOORLOCK\_LOCK\_STATE\_NOT\_FULLY\_LOCKED

    -   E\_CLD\_DOORLOCK\_LOCK\_STATE\_LOCK

    -   E\_CLD\_DOORLOCK\_LOCK\_STATE\_UNLOCK

-   `eLockType` is a mandatory attribute representing the type of door lock, one of:

    -   E\_CLD\_DOORLOCK\_LOCK\_TYPE\_DEAD\_BOLT

    -   E\_CLD\_DOORLOCK\_LOCK\_TYPE\_MAGNETIC

    -   E\_CLD\_DOORLOCK\_LOCK\_TYPE\_OTHER

    -   E\_CLD\_DOORLOCK\_LOCK\_TYPE\_MORTISE

    -   E\_CLD\_DOORLOCK\_LOCK\_TYPE\_RIM

    -   E\_CLD\_DOORLOCK\_LOCK\_TYPE\_LATCH\_BOLT

    -   E\_CLD\_DOORLOCK\_LOCK\_TYPE\_CYLINDRICAL\_LOCK

    -   E\_CLD\_DOORLOCK\_LOCK\_TYPE\_TUBULAR\_LOCK

    -   E\_CLD\_DOORLOCK\_LOCK\_TYPE\_INTERCONNECTED\_LOCK

    -   E\_CLD\_DOORLOCK\_LOCK\_TYPE\_DEAD\_LATCH

    -   E\_CLD\_DOORLOCK\_LOCK\_TYPE\_DOOR\_FURNITURE

-   `bActuatorEnabled` is a mandatory attribute indicating whether the actuator for the door lock is enabled:

    -   TRUE - enabled

    -   FALSE - disabled

-   `eDoorState` is an optional attribute indicating the current state of the door, one of:

    -   E\_CLD\_DOORLOCK\_DOOR\_STATE\_OPEN

    -   E\_CLD\_DOORLOCK\_DOOR\_STATE\_CLOSED

    -   E\_CLD\_DOORLOCK\_DOOR\_STATE\_ERROR\_JAMMED

    -   E\_CLD\_DOORLOCK\_DOOR\_STATE\_ERROR\_FORCED\_OPEN

    -   E\_CLD\_DOORLOCK\_DOOR\_STATE\_ERROR\_UNSPECIFIED

-   `u32NumberOfDoorOpenEvent` is an optional attribute representing the number of ‘door open’ events that have occurred

-   `u32NumberOfDoorClosedEvent` is an optional attribute representing the number of ‘door close’ events that have occurred

-   `u16NumberOfMinutesDoorOpened` is an optional attribute representing the length of time, in minutes, that the door has been open since the last ‘door open’ event

-   `u8ZigbeeSecurityLevel` is an optional attribute representing the ZigBee PRO security level that should be applied to communications between a cluster server and client:

    -   0: Network-level security only

    -   1 or higher: Application-level security \(in addition to Network-level security\)

        -   Application-level security is an enhancement to the Door Lock cluster and is currently not certifiable.

**Note:** The application must not write directly to the `u8ZigbeeSecurityLevel` attribute. If required, Application-level security should be enabled only using the function **eCLD\_DoorLockSetSecurityLevel\(\)**. For more information, refer to the description of this function on page [771](ecld_doorlocksetsecuritylevel.md#id_0580c572-a509-419b-9f88-d846ccfbfeba).

```
u8AttributeReportingStatus is an optional attribute that should be enabled when attribute reporting is used for the cluster (see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)). The value of this attribute indicates whether there are attribute reports still pending (0x00) or the attribute reports are complete (0x01) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).
u16ClusterRevision is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

```

**Parent topic:**[Door Lock Cluster](../../door_lock_cluster/topics/door_lock_cluster.md)

