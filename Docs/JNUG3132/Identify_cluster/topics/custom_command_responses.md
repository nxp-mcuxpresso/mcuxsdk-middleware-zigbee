# Custom Command Responses

The following structure contains the response to a query whether a device is in identification mode \(the original query is sent using the function **eCLD\_IdentifyCommandIdentifyQueryRequestSend\(\)**\):

```
/* Identify query response command payload */
typedef struct
{
    zuint16                 u16Timeout;
} tsCLD_Identify_IdentifyQueryResponsePayload;

```

where `u16Timeout` is the amount of time, in seconds, that the responding device remains in identification mode.

**Parent topic:**[Structures](../../Identify_cluster/topics/structures.md)

