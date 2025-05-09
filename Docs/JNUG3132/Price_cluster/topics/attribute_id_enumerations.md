# ‘Attribute ID’ Enumerations

The following structure contains the enumerations used to identify the attributes of the Price cluster.

**Note:** Only the Tier Label attributes are currently used. The remaining attributes are reserved for future use \(for Block mode\).

```
typedef enum PACK
{
/*Price Cluster Attribute Tier Price Label Set Attr Ids (D.4.2.2.1)*/
    E_CLD_P_ATTR_TIER_1_PRICE_LABEL = 0x0000,
    E_CLD_P_ATTR_TIER_2_PRICE_LABEL,
    ...
    ...
    E_CLD_P_ATTR_TIER_15_PRICE_LABEL,
/*Price Cluster Attribute Block Threshold Set Attr IDs (D.4.2.2.2)*/
    E_CLD_P_ATTR_BLOCK1_THRESHOLD = 0x0100,
    E_CLD_P_ATTR_BLOCK2_THRESHOLD,
    ...
    ...
    E_CLD_P_ATTR_BLOCK15_THRESHOLD,
/*Price Cluster Attribute Block Period Set Attr IDs (D.4.2.2.3)*/
    E_CLD_P_ATTR_START_OF_BLOCK_PERIOD = 0x0200,
    E_CLD_P_ATTR_BLOCK_PERIOD_DURATION,
    E_CLD_P_ATTR_THRESHOLD_MULTIPLIER,
    E_CLD_P_ATTR_THRESHOLD_DIVISOR,
/*Price Cluster Attribute Commodity Set Attr IDs (D.4.2.2.4)*/
    E_CLD_P_ATTR_COMMODITY_TYPE = 0x0300,
    E_CLD_P_ATTR_STANDING_CHARGE,
    E_CLD_P_ATTR_CONVERSION_FACTOR,
    E_CLD_P_ATTR_CONVERSION_FACTOR_TRAILING_DIGIT,
    E_CLD_P_ATTR_CALORIFIC_VALUE,
    E_CLD_P_ATTR_CALORIFIC_VALUE_UNIT,
    E_CLD_P_ATTR_CALORIFIC_VALUE_TRAILING_DIGIT,
/* Price Cluster Attribute Block Price Information Set Attr IDs (D.4.2.2.5)*/
    E_CLD_P_ATTR_NOTIER_BLOCK1_PRICE = 0x0400,
    E_CLD_P_ATTR_NOTIER_BLOCK2_PRICE,
    ...
    ...
    E_CLD_P_ATTR_NOTIER_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER1_BLOCK1_PRICE = 0x0410,
    ...
    E_CLD_P_ATTR_TIER1_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER2_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER2_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER3_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER3_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER4_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER4_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER5_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER5_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER6_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER6_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER7_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER7_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER8_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER8_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER9_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER9_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER10_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER10_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER11_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER11_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER12_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER12_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER13_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER13_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER14_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER14_BLOCK16_PRICE,
    E_CLD_P_ATTR_TIER15_BLOCK1_PRICE,
    ...
    E_CLD_P_ATTR_TIER15_BLOCK16_PRICE
/* Price Cluster Billing Period Information Set Attr IDs */
    E_CLD_P_ATTR_START_OF_BILLING_PERIOD = 0x700,
    E_CLD_P_ATTR_BILLING_PERIOD_DURATION
} teCLD_SM_PriceAttributeID;

```

**Parent topic:**[Enumerations](../../Price_cluster/topics/enumerations.md)

