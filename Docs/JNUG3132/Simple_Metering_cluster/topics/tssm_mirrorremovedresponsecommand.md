# tsSM\_MirrorRemovedResponseCommand

This structure contains the details of a ‘Remove Mirror’ response \(from a cluster client\). It is included in the structure `tsSM_CallBackMessage` when an E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND event containing the command E\_CLD\_SM\_MIRROR\_REMOVED is generated on the cluster server.

```
typedef struct
{
    uint16 u16Endpoint;
}tsSM_MirrorRemovedResponseCommand;

```

where `u16Endpoint` is the number of the endpoint from which the mirror was successfully removed, or takes the value 0xFFFF if the remove request failed.

**Parent topic:**[Structures](../../Simple_Metering_cluster/topics/structures.md)

