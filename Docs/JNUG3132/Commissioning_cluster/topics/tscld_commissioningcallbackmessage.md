# tsCLD\_CommissioningCallBackMessage

For a Commissioning event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_CommissioningCallBackMessage` structure:

```
typedef struct
{
    uint8                      u8CommandId;
    union
    {
        tsCLD_Commissioning_RestartDevicePayload                    
                              *psRestartDevicePayload;
        tsCLD_Commissioning_ModifyStartupParametersPayload          
                              *psModifyStartupParamsPayload; 
    } uReqMessage;
    union
    {
        tsCLD_Commissioning_ResponsePayload                         
                              *psCommissioningResponsePayload; 
    } uRespMessage;
} tsCLD_CommissioningCallBackMessage;

```

where:

-   `u8CommandId` indicates the type of Commissioning command that has been received by a cluster server or client \(the same enumerations are used for requests on the server and responses on the client\), one of:

    -   E\_CLD\_COMMISSIONING\_CMD\_RESTART\_DEVICE

    -   E\_CLD\_COMMISSIONING\_CMD\_SAVE\_STARTUP\_PARAMS

    -   E\_CLD\_COMMISSIONING\_CMD\_RESTORE\_STARTUP\_PARAMS

    -   E\_CLD\_COMMISSIONING\_CMD\_RESET\_STARTUP\_PARAMS

-   `uReqMessage` is a union containing the payload of a request command in the following form:

    -   `psRestartDevicePayload` is a pointer to a structure containing the Restart Device command payload - see [Section 43.9.2](tscld_commissioning_restartdevicepayload.md#id_1df93820-8802-4516-b816-5ad7a67552ec)

    -   `psModifyStartupParamsPayload` is a pointer to a structure containing the \(common\) payload for the Save Start-up Parameters, Restore Start-up Parameters and Reset Start-up Parameters commands - see [Section](tscld_commissioning_modifystartupparameterspayload.md#id_cbb888a3-3740-4fb9-856f-c0b6af1a4c41)43.9.3

-   `uRespMessage` is a union containing the payload of a response command in the following form:

    -   `psCommissioningResponsePayload` is a pointer to a structure containing the \(common\) payload for the Save Start-up Parameters, Restore Start-up Parameters and Reset Start-up Parameters responses - see [Section 43.9.4](tscld_commissioning_responsepayload.md#id_8d27a367-f596-401a-8c9d-c38c428b2fdc)


For further information on Commissioning cluster events, refer to [Section 43.6](commissioning_events.md#id_d75ba71a-55d6-4c86-a586-bbfbbfab97d8).

**Parent topic:**[Structures](../../Commissioning_cluster/topics/structures.md)

