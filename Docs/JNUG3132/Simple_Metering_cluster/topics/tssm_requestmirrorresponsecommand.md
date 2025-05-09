# tsSM\_RequestMirrorResponseCommand

This structure contains the details of an ‘Add Mirror’ response \(from a cluster client\). It is included in the structure `tsSM_CallBackMessage` when an E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND event containing the command E\_CLD\_SM\_REQUEST\_MIRROR\_RESPONSE is generated on the cluster server.

```
typedef struct
{
    uint16 u16Endpoint;
}tsSM_RequestMirrorResponseCommand;

```

where `u16Endpoint` is the number of the endpoint on which the mirror was successfully added or takes the value 0xFFFF if the request failed because no free endpoint was available for the mirror.

**Parent topic:**[Structures](../../Simple_Metering_cluster/topics/structures.md)

