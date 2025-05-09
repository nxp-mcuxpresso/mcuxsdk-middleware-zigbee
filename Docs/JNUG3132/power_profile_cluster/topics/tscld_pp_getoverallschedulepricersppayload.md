# tsCLD\_PP\_GetOverallSchedulePriceRspPayload

This structure contains the payload of a Energy Phases Schedule Response, which contains the overall cost of all the power profiles that will be executed over the next 24 hours.

```
typedef struct
{
   zuint16   u16Currency;
   zuint32   u32Price;
   zuint8   u8PriceTrailingDigits;
}tsCLD_PP_GetOverallSchedulePriceRspPayload;

```

where:

-   `u16Currency` is a value representing the currency in which the price is quoted

-   `u32Price` represents the price as an integer value \(without a decimal point\)

-   `u8PriceTrailingDigits` specifies the position of the decimal point in the price `u32Price`, by indicating the number of digits after the decimal point


**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

