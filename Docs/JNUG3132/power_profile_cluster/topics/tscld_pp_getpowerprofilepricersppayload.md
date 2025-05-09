# tsCLD\_PP\_GetPowerProfilePriceRspPayload

This structure contains the payload of a Get Power Profile Price Response, which is returned in reply to a Get Power Profile Price Request and a Get Power Profile Price Extended Request.

```
typedef struct
{
     zuint8   u8PowerProfileId;
     zuint16   u16Currency;
     zuint32   u32Price;
     zuint8   u8PriceTrailingDigits;
}tsCLD_PP_GetPowerProfilePriceRspPayload;

```

where:

-   `u8PowerProfileId` is the identifier of the power profile

-   `u16Currency` is a value representing the currency in which the price is quoted

-   `u32Price` is the price as an integer value \(without a decimal point\)

-   `u8PriceTrailingDigits` specifies the position of the decimal point in the price `u32Price`, by indicating the number of digits after the decimal point


**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

