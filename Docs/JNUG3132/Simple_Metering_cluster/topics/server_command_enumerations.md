# ‘Server Command’ Enumerations

The comands issued by a Simple Metering cluster server and received by a client are enumerated in the `teSM_ClusterServerCommands` structure below:

```
typedef enum PACK
{
    E_CLD_SM_GET_PROFILE_RESPONSE,
    E_CLD_SM_REQUEST_MIRROR,
    E_CLD_SM_REMOVE_MIRROR,
    E_CLD_SM_REQUEST_FAST_POLL_MODE_RESPONSE,
    E_CLD_SM_CLIENT_ERROR
}teSM_ClusterServerCommands;

```

|**Command Enumeration**|**Description**|
|-----------------------|---------------|
|E\_CLD\_SM\_GET\_PROFILE\_RESPONSE|Response to ‘Get Profile’ request - content of response is contained in the structure `tsS`-`M_GetProfileResponseCommand` in the event \(see [Section 42.11.9](tssm_getprofileresponsecommand.md#id_76cac5c2-b5e4-4ffb-8a53-6454675922be)\)|
|E\_CLD\_SM\_REQUEST\_MIRROR|An ‘Add Mirror’ request|
|E\_CLD\_SM\_REMOVE\_MIRROR|A ‘Remove Mirror’ request|
|E\_CLD\_SM\_REQUEST\_FAST\_POLL\_MODE\_-RESPONSE|Response to ‘Fast Polling’ request \(*for future use*\)|
|E\_CLD\_SM\_CLIENT\_ERROR|Error condition - content of error is contained in the structure `tsSM_Error` in the event \(see [Section 42.11.10](tssm_error.md#id_a4d1e778-b82c-4196-abf0-d71b369c0afe)\)|

**Parent topic:**[Enumerations](../../Simple_Metering_cluster/topics/enumerations.md)

