# Custom Command Payloads

The following structure contains the payload for an Identify cluster custom command \(sent using the function **eCLD\_IdentifyCommandIdentifyRequestSend\(\)**\):

```
/* Identify request command payload */
typedef struct
{
    zuint16                 u16IdentifyTime;
} tsCLD_Identify_IdentifyRequestPayload;

```

where `u16IdentifyTime` is the amount of time, in seconds, for which the target device is to remain in identification mode. If this element is set to 0x0000 and the target device is in identification mode, the mode is terminated immediately.

**Parent topic:**[Structures](../../Identify_cluster/topics/structures.md)

