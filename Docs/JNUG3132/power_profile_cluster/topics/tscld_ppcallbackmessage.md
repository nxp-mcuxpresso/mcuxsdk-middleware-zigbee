# tsCLD\_PPCallBackMessage

For a Power Profile event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_PPCallBackMessage` structure:

```
typedef struct
{
    uint8 u8CommandId;
#ifdef PP_CLIENT
    bool bIsInfoAvailable;
#endif
union
{
    tsCLD_PP_PowerProfileReqPayload *psPowerProfileReqPayload;
    tsCLD_PP_GetPowerProfilePriceExtendedPayload
        *psGetPowerProfilePriceExtendedPayload;
} uReqMessage;
union
{    tsCLD_PP_GetPowerProfilePriceRspPayload *psGetPowerProfilePriceRspPayload;
    tsCLD_PP_GetOverallSchedulePriceRspPayload
            *psGetOverallSchedulePriceRspPayload;
    tsCLD_PP_EnergyPhasesSchedulePayload *psEnergyPhasesSchedulePayload;
    tsCLD_PP_PowerProfileScheduleConstraintsPayload
            *psPowerProfileScheduleConstraintsPayload;
    tsCLD_PP_PowerProfilePayload *psPowerProfilePayload;
    tsCLD_PP_PowerProfileStatePayload *psPowerProfileStatePayload;
}uRespMessage;
} tsCLD_PPCallBackMessage;
```

where:

-   `u``8CommandId` indicates the type of Power Profile command that has been received, one of:

    -   E\_CLD\_PP\_CMD\_POWER\_PROFILE\_REQ

    -   E\_CLD\_PP\_CMD\_ POWER\_PROFILE\_STATE\_REQ

    -   E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE\_RSP

    -   E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE\_EXTENDED\_RSP

    -   E\_CLD\_PP\_CMD\_GET\_OVERALL\_SCHEDULE\_PRICE\_RSP

    -   E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_NOTIFICATION

    -   E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_RSP

    -   E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_SCHEDULE\_CONSTRAINTS\_REQ

    -   E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_STATE\_REQ

    -   E\_CLD\_PP\_CMD\_POWER\_PROFILE\_NOTIFICATION

    -   E\_CLD\_PP\_CMD\_POWER\_PROFILE\_RSP

    -   E\_CLD\_PP\_CMD\_POWER\_PROFILE\_STATE\_RSP

    -   E\_CLD\_PP\_CMD\_POWER\_PROFILE\_STATE\_NOTIFICATION

    -   E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE

    -   E\_CLD\_PP\_CMD\_GET\_OVERALL\_SCHEDULE\_PRICE

    -   E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_REQ

    -   E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_STATE\_RSP

    -   E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_STATE\_NOTIFICATION

    -   E\_CLD\_PP\_CMD\_SCHEDULE\_CONSTRAINTS\_NOTIFICATION

    -   E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_SCHEDULE\_CONSTRAINTS\_RSP

    -   E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE\_EXTENDED

-   `bIsInfoAvailable` is a client-only boolean field which indicates whether the appropriate type of information \(to which the event relates\) is held on the client:

    TRUE if the information type is held on the client, FALSE otherwise

-   `uReqMessage` is a union containing the command payload for a request, as one of \(depending on the value of `u8CommandId`\):

    -   `psPowerProfileReqPayload` is a pointer to the payload of a Power Profile Request, a Get Power Profile Schedule Constraints Request, an Energy Phases Schedule Request, an Energy Phases Schedule State Request or a Get Power Profile Price Request \(see [Section 21.10.5](tscld_pp_powerprofilestatepayload.md#id_f342d466-8058-4515-977d-10b00eecb718)\).

    -   `psGetPowerProfilePriceExtendedPayload` is a pointer to the payload of a Get Power Profile Price Extended Request \(see [Section 21.10.8](tscld_pp_getpowerprofilepriceextendedpayload.md#id_a9ed2c50-d479-4d9b-a992-07732f0f069a)\).


-   `uRespMessage` is a union containing the command payload for a response or notification, as one of \(depending on the value of `u8CommandId`\):

    -   `psGetPowerProfilePriceRspPayload` is a pointer to the payload of a Get Power Profile Price Response or a Get Power Profile Price Extended Response \(see [Section 21.10.9](tscld_pp_getpowerprofilepricersppayload.md#id_e3e14a9b-2497-4cee-aef9-4826500661f3)\)

    -   `psGetOverallSchedulePriceRspPayload`is a pointer to the payload of a Get Overall Schedule Price Response \(see[Section 21.10.10](tscld_pp_getoverallschedulepricersppayload.md#id_0b0f4382-76c2-420d-bb99-d503dec06f43)\).

    -   `psEnergyPhasesSchedulePayload` is a pointer to the payload of an Energy Phases Schedule Response, an Energy Phases Schedule State Response, an Energy Phases Schedule Notification or an Energy Phases Schedule State Notification \(see [Section 21.6](power_profile_events.md#id_c65ba54d-c1c7-47c1-bd6c-5463e6afa17e)\).

    -   `psPowerProfileScheduleConstraintsPayload` is a pointer to the payload of a Power Profile Schedule Constraints Response or a Power Profile Schedule Constraints Notification \(see [Section 21.10.10](tscld_pp_getoverallschedulepricersppayload.md#id_0b0f4382-76c2-420d-bb99-d503dec06f43)\).

    -   `psPowerProfilePayload` is a pointer to the payload of a Power Profile Response or a Power Profile Notification \(see [Section 21.10.4](tscld_pp_powerprofilepayload.md#id_c895e2f5-5dde-4408-b3c5-72cc084ddd73)\).

    -   `psPowerProfileStatePayload` is a pointer to the payload of a Power Profile State Response or a Power Profile State Notification \(see [Section 21.10.5](tscld_pp_powerprofilestatepayload.md#id_f342d466-8058-4515-977d-10b00eecb718)\).


**Note:** The command payload for each command type is indicated in [Table 30](power_profile_events.md#id_a80128e4-4b34-4c06-979e-ebe4a1fdd7a2) and [Table 31](power_profile_events.md#id_a38fa960-f25e-4ce7-bc53-cb9a80dd9f3b) in [Section 21.6](power_profile_events.md#id_c65ba54d-c1c7-47c1-bd6c-5463e6afa17e).

**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

