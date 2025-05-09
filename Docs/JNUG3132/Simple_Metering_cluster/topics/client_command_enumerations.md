# ‘Client Command’ Enumerations

The comands issued by a Simple Metering cluster client and received by the server are enumerated in the `teSM_ClusterClientCommands` structure below:

```
typedef enum PACK
{
    E_CLD_SM_GET_PROFILE,
    E_CLD_SM_REQUEST_MIRROR_RESPONSE,
    E_CLD_SM_MIRROR_REMOVED,
    E_CLD_SM_REQUEST_FAST_POLL_MODE,
    E_CLD_SM_SERVER_ERROR
}teSM_ClusterClientCommands;

```

|**Command Enumeration**|**Description**|
|-----------------------|---------------|
|E\_CLD\_SM\_GET\_PROFILE|A ‘Get Profile’ request - content of request is contained in the structure `tsSM_GetProfile`-`RequestCommand` in the event \(see [Section](tssm_getprofilerequestcommand.md#id_fdfdc3c8-933b-4e97-a9cc-334ccc4ed745)42.11.8\)|
|E\_CLD\_SM\_REQUEST\_MIRROR\_RESPONSE|Response to ‘Add Mirror’ request - content of response is contained in the structure `tsS`-`M_RequestMirrorResponseCommand` in the event \(see [Section 42.11.6](tssm_requestmirrorresponsecommand.md#id_f0a8bde1-a77f-4d19-81d9-dd153d2af499)\)|
|E\_CLD\_SM\_MIRROR\_REMOVED|Response to ‘Remove Mirror’ request - content of response is contained in the structure `tsS`-`M_MirrorRemovedResponseCommand` in the event \(see [Section 42.11.7](tssm_mirrorremovedresponsecommand.md#id_afda06de-379c-47e5-a279-92227bc99fb4)\)|
|E\_CLD\_SM\_REQUEST\_FAST\_POLL\_MODE|A ‘Fast Polling’ request \(*for future use*\)|
|E\_CLD\_SM\_SERVER\_ERROR|Error condition - content of error is contained in the structure `tsSM_Error` in the event \(see [Section 42.11.10](tssm_error.md#id_a4d1e778-b82c-4196-abf0-d71b369c0afe)\)|

**Parent topic:**[Enumerations](../../Simple_Metering_cluster/topics/enumerations.md)

