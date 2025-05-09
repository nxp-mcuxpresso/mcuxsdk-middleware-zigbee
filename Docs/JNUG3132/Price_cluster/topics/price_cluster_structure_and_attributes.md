# Price cluster structure and attributes

The Price cluster is contained in the following `tsCLD_Price` structure:

```
typedef struct CLD_Price_tag
{
    /* Tier Price Label Set (D.4.2.2.1) */
#if (CLD_P_ATTR_TIER_PRICE_LABEL_MAX_COUNT != 0)
 tsZCL_OctetString  asTierPriceLabel[CLD_P_ATTR_TIER_PRICE_LABEL_MAX_COUNT];
 uint8  au8TierPriceLabel[CLD_P_ATTR_TIER_PRICE_LABEL_MAX_COUNT][SE_PRICE_SERVER_MAX_STRING_LENGTH];
#endif
 /* Block Threshold Set (D.4.2.2) */
#if (CLD_P_ATTR_BLOCK_THRESHOLD_MAX_COUNT != 0)
 zuint48        au48BlockThreshold[CLD_P_ATTR_BLOCK_THRESHOLD_MAX_COUNT];
#endif
    /* Block Period Set (D.4.2.2.3) */
#ifdef CLD_P_ATTR_START_OF_BLOCK_PERIOD
    zutctime           utctStartOfBlockPeriod;
#endif
#ifdef CLD_P_ATTR_BLOCK_PERIOD_DURATION
    zuint24            u24BlockPeriodDuration;
#endif
#ifdef CLD_P_ATTR_THRESHOLD_MULTIPLIER
    zuint24            u24ThresholdMultiplier;
#endif
#ifdef CLD_P_ATTR_THRESHOLD_DIVISOR
    zuint24            u24ThresholdDivisor;
#endif
    /* Commodity Set Set (D.4.2.2.4) */
#ifdef CLD_P_ATTR_COMMODITY_TYPE
    zenum8             e8CommodityType;
#endif
#ifdef CLD_P_ATTR_STANDING_CHARGE
    zuint32            u32StandingCharge;
#endif
#ifdef CLD_P_ATTR_CONVERSION_FACTOR
    zuint32            u32ConversionFactor;
#endif
#ifdef CLD_P_ATTR_CONVERSION_FACTOR_TRAILING_DIGIT
    zbmap8             b8ConversionFactorTrailingDigit;
#endif
#ifdef CLD_P_ATTR_CALORIFIC_VALUE
    zuint32            u32CalorificValue;
#endif
#ifdef CLD_P_ATTR_CALORIFIC_VALUE_UNIT
    zenum8             e8CalorificValueUnit;
#endif
#ifdef CLD_P_ATTR_CALORIFIC_VALUE_TRAILING_DIGIT
    zbmap8             b8CalorificValueTrailingDigit;
#endif
    /* Block Price Information Set (D.4.2.2.5) */
#if (CLD_P_ATTR_NO_TIER_BLOCK_PRICES_MAX_COUNT != 0)
    zuint32     au32NoTierBlockPrice[CLD_P_ATTR_NO_TIER_BLOCK_PRICES_MAX_COUNT];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 0)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
    zuint32     au32Tier1BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 1)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
    zuint32    au32Tier2BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 2)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
    zuint32   au32Tier3BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 3)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
  zuint32  au32Tier4BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 4)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
  zuint32     au32Tier5BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 5)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
  zuint32    au32Tier6BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 6)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
  zuint32   au32Tier7BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 7)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
  zuint32   au32Tier8BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 8)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
 zuint32     au32Tier9BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 9)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
    zuint32     au32Tier10BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 10)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
  zuint32     au32Tier11BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 11)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
  zuint32         au32Tier12BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 12)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
 zuint32        au32Tier13BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 13)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
  zuint32         au32Tier14BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#if ((CLD_P_ATTR_NUM_OF_TIERS_PRICE > 14)&&(CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE != 0))
  zuint32      au32Tier15BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE];
#endif
#ifdef CLD_P_ATTR_START_OF_BILLING_PERIOD
    zutctime           utctStartOfBillingPeriod;
#endif
#ifdef CLD_P_ATTR_BILLING_PERIOD_DURATION
    zuint24            u24BillingPeriodDuration;
#endif
#ifdef CLD_P_CLIENT_ATTR_PRICE_INCREASE_RANDOMIZE_MINUTES
    uint8              u8ClientIncreaseRandomize;
#endif
#ifdef CLD_P_CLIENT_ATTR_PRICE_DECREASE_RANDOMIZE_MINUTES
    uint8              u8ClientDecreaseRandomize;
#endif
#ifdef CLD_P_CLIENT_ATTR_COMMODITY_TYPE
    zenum8             e8ClientCommodityType;
#endif
} tsCLD_Price;

```

where:

## ‘Tier Label’ Attribute Set 

-   The following are optional attributes that are only relevant to TOU mode**\(*tiers 7 to 15 are not certifiable in SE 1.1.1 or earlier and are reserved for future use*\):

    -   `asTierPriceLabel[CLD_P_ATTR_TIER_PRICE_LABEL_MAX_COUNT]`

        is a `tsZCL_OctetString` structure containing information on tier labels. The maximum size of `asTierPriceLabel` is defined by assigning a value to `CLD_P_ATTR_TIER_PRICE_LABEL_MAX_COUNT`. This optional element is paired with `au8TierPriceLabel` \(below\)

    -   `au8TierPriceLabel[CLD_P_ATTR_TIER_PRICE_LABEL_MAX_COUNT]``[SE_PRICE_SERVER_MAX_STRING_LENGTH]` is an array containing the tier labels, e.g. "Peak". This optional element is paired with the element `asTierPriceLabel` \(above\)


**Note:** Memory space for each \(enabled\) price tier label is statically allocated and comprises 13 bytes per label \(plus one byte for the ‘octet count’\). Therefore, memory space remains allocated for unused bytes.

## ‘Block Threshold’ Attribute Set 

-   The following are optional attributes that relate to Block mode and are fully described in the *ZigBee Smart Energy Profile Specification*\(*these attributes are not certifiable in SE 1.1.1 or earlier and are for future use*\):


```
au48BlockThreshold[CLD_P_ATTR_BLOCK_THRESHOLD_MAX_COUNT]

```

## ‘Block Period’ Attribute Set 

-   The following are optional attributes that relate to Block mode and are fully described in the *ZigBee Smart Energy Profile Specification*\(*these attributes are not certifiable in SE 1.1.1 or earlier and are for future use*\):

    -   `utctStartOfBlockPeriod`

    -   `u24BlockPeriodDuration`

    -   `u24ThresholdMultiplier`

    -   `u24ThresholdDivisor`


## ‘Commodity’ Attribute Set 

-   The following are optional attributes:

    -   `e8CommodityType` is an enumeration representing the type of commodity \(e.g. gas\) to which the prices apply - the enumerations used are those provided in the `teCLD_SM_MeteringDeviceType` structure of the Simple Metering cluster and listed in [Section 42.10.6](../../Simple_Metering_cluster/topics/metering_device_type_enumerations.md#id_67ec54ac-d1b7-4ffe-adc7-1ce5ec2e3c08)

    -   `u32StandingCharge` is the value of a fixed daily 'standing charge' associated with supplying the commodity, expressed in the currency and with the decimal places indicated in the Publish Price command described in [Section 40.11.1](tsse_pricepublishpricecmdpayload.md#id_33de0832-fd7e-46e1-b6e3-7d58ef09b32a) \(the value 0xFFFFFFFF indicates that the field is not used\)

    -   `u32ConversionFactor` is used only for gas and accounts for the variation of gas volume with temperature and pressure \(and is dimensionless\). The Price server can change this conversion factor at any time and this attribute contains the currently active value. The default value is 1. The position of the decimal point is indicated by `b8``ConversionFactorTrailingDigit` described below.

    -   `b8``ConversionFactorTrailingDigit` is an 8-bit bitmap which indicates the location of the decimal point in the `u32ConversionFactor` attribute. The most significant 4 bits indicate the number of digits after the decimal point. The remaining bits are reserved.

    -   `u32CalorificValue` is used only for gas and indicates the quantity of energy in MJ that is generated per unit volume or unit mass of gas burned \(see `e8``CalorificValueUnit`\) - the value can be used to calculate energy consumption in kWh. The position of the decimal point is indicated by `b8``CalorificValueTrailingDigit` described below.

    -   `e8``CalorificValueUnit` is an enumerated value indicating whether `u32CalorificValue` is quantified per unit volume or per unit mass. The possible values are 0x01 for MJ/m3 and 0x02 for MJ/kg \(all other values are reserved\).

    -   `b8``CalorificValueTrailingDigit` is an 8-bit bitmap which indicates the location of the decimal point in the `u32CalorificValue` attribute. The most significant 4 bits indicate the number of digits after the decimal point. The remaining bits are reserved.


## ‘Block Price Information’ Attribute Set 

-   The following are optional attributes that relate to Block mode and are fully described in the *ZigBee Smart Energy Profile Specification*\(*these attributes are not certifiable in SE 1.1.1 or earlier and are for future use*\):

    ```
    au32NoTierBlockPrice[CLD_P_ATTR_NO_TIER_BLOCK_PRICES_MAX_COUNT]
    au32Tier1BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier2BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier3BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier4BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier5BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier6BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier7BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier8BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier9BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier10BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier11BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier12BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier13BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier14BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    au32Tier15BlockPrice[CLD_P_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_PRICE]
    
    ```


## ‘Billing Period Information’ Attribute Set 

-   The following are optional attributes that relate to Block mode \(*both attributes are not certifiable in SE 1.1.1 or earlier and are for future use*\):


```
utctStartOfBillingPeriod
u24BillingPeriodDuration

```

## Client Attribute Set 

-   The following set of attributes are only for use on a Price cluster client:

    -   `u8ClientIncreaseRandomize` represents the maximum length of time, in minutes, between a client node applying a price increase and taking a resulting action \(such as reducing its power consumption\). The action may be performed before or after the price increase is implemented, and the delay \(either way\) must be chosen at random by the application on the node. The maximum is set in minutes, in the range 0 to 60 minutes, but it is recommended that the random delay is selected in seconds.

    -   u8ClientDecreaseRandomize represents the maximum length of time, in minutes, between a client node applying a price decrease and taking a resulting action \(such as switching itself on\). The action may be performed before or after the price decrease is implemented, and the delay \(either way\) must be chosen at random by the application on the node. The maximum is set in minutes, in the range 0 to 60 minutes, but it is recommended that the random delay is selected in seconds.

    -   e8ClientCommodityType is an enumeration representing the commodity that is priced on the client device. This enumeration is one from the ‘Metering Device Type’ enumerations listed in [Table74](../../Simple_Metering_cluster/topics/metering_device_type_enumerations.md#id_1408cea6-25f9-4334-a8ce-e60c0f5c84a9).


**Note:** Price information for Time-Of-Use \(TOU\) mode is held in the `tsSE_PricePublishPriceCmdPayload` structure described in [Section 40.11.1](tsse_pricepublishpricecmdpayload.md#id_33de0832-fd7e-46e1-b6e3-7d58ef09b32a). Prices are matched to tiers using the strings defined in the Tier Label attributes.

**Parent topic:**[Price Cluster](../../Price_cluster/topics/price_cluster.md)

