# tsSE\_PricePublishConversionCmdPayload

This structure is used to hold information to be added to a conversion factor list of a Price cluster:

```
typedef struct {
    uint32          u32IssuerEventId;
    uint32          u32StartTime;
    uint32          u32ConversionFactor;
    zbmap8          u8ConversionFactorTrailingDigit;
}tsSE_PricePublishConversionCmdPayload;

```

where:

-   `u32IssuerEventId` is a unique identifier for the conversion factor information - the higher the value, the more recently the information was issued

-   `u32StartTime` is the start-time of the conversion factor value. This is the time at which the conversion factor value is scheduled to become active

-   `u32ConversionFactor` is used only for gas and accounts for the variation in the volume of gas with temperature and pressure \(the value is dimensionless\)

-   `u8ConversionFactorTrailingDigit` is an 8-bit bitmap which indicates the location of the decimal point in the `u32ConversionFactor` field. The most significant 4 bits indicate the number of digits after the decimal point. The remaining bits are reserved


**Parent topic:**[Structures](../../Price_cluster/topics/structures.md)

