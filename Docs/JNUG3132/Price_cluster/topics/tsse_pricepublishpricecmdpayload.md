# tsSE\_PricePublishPriceCmdPayload

This structure is used to hold price information to be added to a price list of a Price cluster:

```
typedef struct {
    uint8               u8UnitOfMeasure;
    uint8               u8PriceTrailingDigitAndPriceTier;
    uint8               u8NumberOfPriceTiersAndRegisterTiers;
    uint8               u8PriceRatio;
    uint8               u8GenerationPriceRatio;
    uint8               u8AlternateCostUnit;
    uint8               u8AlternateCostTrailingDigit;
    uint8               u8NumberOfBlockThresholds;
    uint8               u8PriceControl;
    uint16              u16Currency;
    uint16              u16DurationInMinutes;
    uint32              u32ProviderId;
    uint32              u32IssuerEventId;
    uint32              u32StartTime;
    uint32              u32Price;
    uint32              u32GenerationPrice;
    uint32              u32AlternateCostDelivered;
    tsZCL_OctetString   sRateLabel;
} tsSE_PricePublishPriceCmdPayload;

```

where:

-   `u8UnitOfMeasure` indicates the resource \(e.g. electricity\) and unit of measure \(e.g. kWh\) for the pricing \(see [Section 42.10.3](../../Simple_Metering_cluster/topics/unit_of_measure_enumerations.md#id_ee7f39b7-56bc-4008-b2e9-3e13449c50d0)\)

-   `u8PriceTrailingDigitAndPriceTier` is an 8-bit bitmap indicating the price tier and the number of digits after the decimal point in the price:

    -   The 4 most significant bits give the number of digits to the right of the decimal point in the price

    -   The 4 least significant bits give the price tier in the range 1 to 6

-   `u8NumberOfPriceTiersAndRegisterTiers` is an 8-bit bitmap indicating the number of price tiers available and the particular tier that the price information in the structure relates to:

    -   The 4 most significant bits give the number of available price tiers in the range 0 to 6

    -   The 4 least significant bits give the price tier used in the range 1 to 6

        \(this value must be less than or equal to the value in the 4 leading bits\)

-   `u8PriceRatio` \(optional\) is the ratio of the price quoted in `u32Price` to the ‘normal’ price offered by the utility company. The actual price ratio should be multiplied by 10 for encoding this field, so that a field value of 0x01 represents 0.1 and 0xFE represents 25.4, while 0xFF indicates that the field is not used

-   `u8GenerationPriceRatio` \(optional\) is the ratio of the price quoted in `u32GenerationPrice` to the ‘normal’ price offered by the utility company. The actual price ratio should be multiplied by 10 for encoding this field, so that a field value of 0x01 represents 0.1 and 0xFE represents 25.4, while 0xFF is reserved to indicate that the field is not used

-   `u8AlternateCostUnit` \(optional\) is an 8-bit bitmap indicating the unit for the alternative cost in `u32AlternateCostDelivered`. Currently, the only supported unit is kilograms of CO2, indicated by the value 0x01

-   `u8AlternateCostTrailingDigit` \(optional\) is an 8-bit bitmap in which the 4 most significant bits indicate the number of digits after the decimal point in `u32AlternateCostDelivered` \(the 4 least significant bits are reserved\)

-   `u8NumberOfBlockThresholds` is reserved for future use \(for Block mode\)

-   `u8PriceControl` is reserved for future use \(for Block mode\)

-   `u16Currency` indicates the currency \(e.g. Euro\) used for the price - this field should be set to the appropriate value defined by ISO 4217

-   `u16DurationInMinutes` indicates the duration, in minutes, for which the price will be valid \(0xFFFF indicates that price will remain valid until changed\)

-   `u32ProviderId` is an identifier for the utility company

-   `u``32IssuerEventId` is a unique identifier for the price information - the higher its value, the more recently the price information was issued \(a UTC time-stamp could be used in this field\)

-   `u``32StartTime` indicates the start-time \(UTC\) for the price, in seconds. The special value 0x00000000 denotes a start-time of ‘now’

-   `u``32Price` is the resource price per unit indicated in `u8UnitOfMeasure`, expressed in the currency indicated in `u16Currency`, with the position of the decimal point as indicated in `u8PriceTrailingDigitAndPriceTie``r`

-   `u``32GenerationPrice` \(optional\) is the resource price per unit indicated in `u8UnitOfMeasure`, expressed in the currency indicated in `u16Currency` and with the position of the decimal point as indicated in `u8PriceTrailingDigitAndPriceTier`, for a resource that is generated on the customer premises and supplied to the utility company \(e.g. solar-sourced electric power supplied to the national grid\). A value of 0xFFFFFFFF indicates that this field is not used

-   `u32AlternateCostDelivered` \(optional\) indicates an alternative cost \(per resource consumption unit\) which is measured by a means other than monetary - for example, the amount of CO2 emitted per unit of gas consumed This alternative cost is interpreted as specified by `u8AlternateCostUnit` and `u8AlternateCostTrailingDigit`

-   `sRateLabel` is a string of up to 12 characters containing a label for the price information in the structure


**Parent topic:**[Structures](../../Price_cluster/topics/structures.md)

