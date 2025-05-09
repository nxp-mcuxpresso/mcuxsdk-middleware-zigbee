# tsCLD\_PP\_GetPowerProfilePriceExtendedPayload

This structure contains the payload of a Get Power Profile Price Extended Request, which requests certain price information relating to a particular power profile.

```
typedef struct
{
    zbmap8   u8Options;
    zuint8   u8PowerProfileId;
    zuint16   u16PowerProfileStartTime;
}tsCLD_PP_GetPowerProfilePriceExtendedPayload;

```

where:

-   `u8Options` is a bitmap indicating the type of request:

    -   If bit 0 is set to ‘1’ then the `u16PowerProfileStartTime` field is used, otherwise it is ignored

    -   If bit 1 is set to ‘0’ then an estimated price is required for contiguous energy phases \(with no gaps between them\); if bit 1 is set ‘1’ then an estimated price is required for the energy phases as scheduled \(with any scheduled gaps between them\)

-   `u8PowerProfileId` is the identifier of the power profile

-   `u16PowerProfileStartTime` is an optional value \(see `u8Options` above\) which indicates the required start-time for execution of the power profile, in minutes, as measured from the current time


**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

