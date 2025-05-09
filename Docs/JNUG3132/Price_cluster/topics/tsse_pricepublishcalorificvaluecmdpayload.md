# tsSE\_PricePublishCalorificValueCmdPayload

This structure is used to hold information to be added to a calorific value list of the Price cluster:

```
typedef struct {
    zenum8                u8CalorificValueUnit;
    zbmap8                u8CalorificValueTrailingDigit;
    uint32                u32IssuerEventId;
    uint32                u32StartTime;
    uint32                u32CalorificValue;
}tsSE_PricePublishCalorificValueCmdPayload;

```

where:

-   `u8CalorificValueUnit` is an 8-bit enumerated value which defines the unit for the `u32CalorificValue` field \(below\). It indicates whether the calorific value is quantified per unit volume or per unit mass - see [Section 40.12.3](calorific_value_unit_enumerations.md#id_93ef83ba-644d-4ac6-8f63-f720382e0725).

-   `u8CalorificValueTrailingDigit` is an 8-bit bitmap which indicates the location of the decimal point in the `u32CalorificValue` field \(below\). The most significant 4 bits indicate the number of digits after the decimal point. The remaining bits are reserved

-   `u32IssuerEventId` is a unique identifier for the calorific value information - the higher the value, the more recently the information was issued

-   `u32StartTime` is the start-time of the calorific value. This is the time at which the conversion factor value is scheduled to become active

-   `u32CalorificValue` is used only for gas and indicates the quantity of energy in MJ that is generated per unit volume or unit mass of gas burned \(see `u8CalorificValueUnit`\). The position of the decimal point is indicated by `u8CalorificValueTrailingDigit` described above


**Parent topic:**[Structures](../../Price_cluster/topics/structures.md)

