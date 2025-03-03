# BDB\_tsFindAndBindEvent

The following structure contains the data for a ‘Finding and Binding’ event \(see [Section 2.9](events.md#ID_774854A3-F20F-4D45-A0CA-5E90A3F46A92)\), which is passed to the application during the Finding and Binding process on the initiator.

```
typedef struct{
    uint8 u8InitiatorEp;
    uint8 u8TargetEp;
    uint16 u16TargetAddress;
    uint16 u16ProfileId;
    uint16 u16DeviceId;
    uint8 u8DeviceVersion;
    union {
        uint16 u16ClusterId;
        uint16 u16GroupId;
    }uEvent;
    ZPS_tsAfZdpEvent *psAfZdpEvent;
    bool bAllowBindOrGroup;
    bool bGroupCast;
}BDB_tsFindAndBindEvent;

```

where:

-   `u8InitiatorEp` is the number of the endpoint involved in the binding/grouping on the initiator node.
-   `u8TargetEp` is the number of the endpoint involved in the binding/grouping on the target node.
-   `u16TargetAddress` is the 16-bit network address of the target node.
-   `u16ProfileId` is the identifier of the ZigBee application profile supported by the two nodes \(for Lighting & Occupancy devices, this is 0x0104\)
-   `u16DeviceId` is the 16-bit identifier of the ZigBee device type supported by the target endpoints. This must be a device type identifier issued by the ZigBee Alliance.
-   `u8DeviceVersion` contains 4 bits \(bits 0-3\) representing the version of the supported device description on the target node \(the default is 0000, unless set to another value according to the application profile used\).
-   `uEvent` is a union of the following two fields:
    -   `u16ClusterId` is the identifier of the cluster involved in the binding.
    -   `u16GroupId` is the address of the group to which the target endpoint is assigned.
-   `psAfZdpEvent` is a pointer to a ZPS\_tsAfZdpEvent structure containing the generated Finding and Binding event - this ZPS structure is detailed in the ZigBee 3.0 Stack User Guide \(JNUG3130\). The event can be any of the following \(detailed in Section 2.9\):
    -   BDB\_EVENT\_FB\_HANDLE\_SIMPLE\_DESC\_RESP\_OF\_TARGET
    -   BDB\_EVENT\_FB\_CHECK\_BEFORE\_BINDING\_CLUSTER\_FOR\_TARGET
    -   BDB\_EVENT\_FB\_CLUSTER\_BIND\_CREATED\_FOR\_TARGET
    -   BDB\_EVENT\_FB\_BIND\_CREATED\_FOR\_TARGET
    -   BDB\_EVENT\_FB\_GROUP\_ADDED\_TO\_TARGET
    -   BDB\_EVENT\_FB\_ERR\_BINDING\_FAILED
    -   BDB\_EVENT\_FB\_ERR\_BINDING\_TABLE\_FULL
    -   BDB\_EVENT\_FB\_ERR\_GROUPING\_FAILED
    -   BDB\_EVENT\_FB\_NO\_QUERY\_RESPONSE
    -   BDB\_EVENT\_FB\_TIMEOUT
-   `bAllowBindOrGroup` is a Boolean flag that indicates whether the relevant cluster is permitted to participate in a binding or grouping. The default value is TRUE \(permitted\) but if the application must exclude the cluster \(and block the binding/grouping\) then it should set this field to FALSE.
-   `bGroupCast` is a Boolean flag that indicates whether an 'Add Group If Identifying' command should be broadcast to all the identifying targets \(TRUE\) or an 'Add Group' request should be individually unicast to all the identifying targets. The default value is TRUE.

**Parent topic:**[Structures](../topics/structures.md)

