# tsCLD\_PP\_PowerProfileStatePayload

This structure contains the payload of a Power Profile State Response or of a Power Profile State Notification.

```
typedef struct
{
  zuint8                   u8PowerProfileCount;
  tsCLD_PP_PowerProfileRecord *psPowerProfileRecord;
}tsCLD_PP_PowerProfileStatePayload;

```

where:

-   `u8PowerProfileCount` is the number of power profiles in the payload

-   `psPowerProfileRecord` is a pointer to one or more power profile records \(see [Section 21.10.13](tscld_pp_powerprofiierecord.md#id_a9fed0bf-e5da-4474-926a-74e8412aefcb)\):

    -   For a Power Profile State Notification, it is a pointer to the power profile record of the currently active power profile on the server

    -   For a Power Profile State Response, it is a pointer to an array of power profile records for all the supported power profiles on the server


**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

