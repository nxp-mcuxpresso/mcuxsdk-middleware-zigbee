# ‘Unit of Measure’ Enumerations

The following enumerations are used to set the `teSE_UnitOfMeasure` element in the Simple Metering cluster structure `tsSE_SimpleMetering`. Separate sets of enumerations are provided for binary and BCD \(Binary Coded Decimal\) representations.

```
typedef enum PACK
{
    /* Binary values */
    E_CLD_SM_UOM_KILO_WATTS                = 0x00,
    E_CLD_SM_UOM_CUBIC_METER,
    E_CLD_SM_UOM_CUBIC_FEET,
    E_CLD_SM_UOM_100_CUBIC_FEET,           /* ccf & ccf/h */
    E_CLD_SM_UOM_US_GALLON,                /* USG & USG/h */
    E_CLD_SM_UOM_IMPERIAL_GALLON,          /* IMPG & IMPG/h */
    E_CLD_SM_UOM_BTU,                      /* BTU & BTU/h */
    E_CLD_SM_UOM_LITERS,                   /* Liters & Liters/h */
    E_CLD_SM_UOM_KPA_GAUGE,
    E_CLD_SM_UOM_KPA_ABSOLUTE,
    /* BCD values */
    E_CLD_SM_UOM_KILO_WATTS_BCD            = 0x80,
    E_CLD_SM_UOM_CUBIC_METER_BCD,
    E_CLD_SM_UOM_CUBIC_FEET_BCD,
    E_CLD_SM_UOM_100_CUBIC_FEET_BCD,       /* ccf & ccf/h */
    E_CLD_SM_UOM_US_GALLON_BCD,            /* USG & USG/h */
    E_CLD_SM_UOM_IMPERIAL_GALLON_BCD,      /* IMPG & IMPG/h */
    E_CLD_SM_UOM_BTU_BCD,                  /* BTU & BTU/h */
    E_CLD_SM_UOM_LITERS_BCD,               /* Liters & Liters/h */
    E_CLD_SM_UOM_KPA_GAUGE_BCD,
    E_CLD_SM_UOM_KPA_ABSOLUTE_BCD
} teCLD_SM_UnitOfMeasure;

```

The above enumerations are detailed in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
||**Instantaneous**|**Summation**|
|**Binary Values**|
|E\_CLD\_SM\_UOM\_KILO\_WATTS|kW \(kiloWatts\)|kWh \(kiloWatt-hours\)|
|E\_CLD\_SM\_UOM\_CUBIC\_METER|m3/h \(cubic metres per hour\)|m3 \(cubic metres\)|
|E\_CLD\_SM\_UOM\_CUBIC\_FEET|ft3/h \(cubic feet per hour\)|ft3 \(cubic feet\)|
|E\_CLD\_SM\_UOM\_100\_CUBIC\_FEET|ccf/h \(100 cubic feet per hour\)|ccf \(100 cubic feet\)|
|E\_CLD\_SM\_UOM\_US\_GALLON|US gl/h \(US Gallons per hour\)|US gl \(US Gallons\)|
|E\_CLD\_SM\_UOM\_IMPERIAL\_GALLON|Imperial gl/h \(Imperial Gallons per hour\)|Imperial gl \(Imperial Gallons\)|
|E\_CLD\_SM\_UOM\_BTU|BTU/h \(British Thermal Units per hour\)|BTU \(British Thermal Units\)|
|E\_CLD\_SM\_UOM\_LITERS|l/h \(litres per hour\)|l \(litres\)|
|E\_CLD\_SM\_UOM\_KPA\_GAUGE|kPA \(kiloPascal\) gauge|-|
|E\_CLD\_SM\_UOM\_KPA\_ABSOLUTE|kPA \(kiloPascal\) absolute|-|
|**BCD Values**|
|E\_CLD\_SM\_UOM\_KILO\_WATTS\_BCD|kW \(kiloWatts\)|kWh \(kiloWatt-hours\)|
|E\_CLD\_SM\_UOM\_CUBIC\_METER\_BCD|m3/h \(cubic metres per hour\)|m3 \(cubic metres\)|
|E\_CLD\_SM\_UOM\_CUBIC\_FEET\_BCD|ft3/h \(cubic feet per hour\)|ft3 \(cubic feet\)|
|E\_CLD\_SM\_UOM\_100\_CUBIC\_FEET\_BCD|ccf/h \(100 cubic feet per hour\)|ccf \(100 cubic feet\)|
|E\_CLD\_SM\_UOM\_US\_GALLON\_BCD|US gl/h \(US Gallons per hour\)|US gl \(US Gallons\)|
|E\_CLD\_SM\_UOM\_IMPERIAL\_GALLON\_BCD|Imperial gl/h \(Imperial Gallons per hour\)|Imperial gl \(Imperial Gallons\)|
|E\_CLD\_SM\_UOM\_BTU\_BCD|BTU/h \(British Thermal Units per hour\)|BTU \(British Thermal Units\)|
|E\_CLD\_SM\_UOM\_LITERS\_BCD|l/h \(litres per hour\)|l \(litres\)|
|E\_CLD\_SM\_UOM\_KPA\_GAUGE\_BCD|kPA \(kiloPascal\) gauge|-|
|E\_CLD\_SM\_UOM\_KPA\_ABSOLUTE\_BCD|kPA \(kiloPascal\) absolute|-|

**Parent topic:**[Enumerations](../../Simple_Metering_cluster/topics/enumerations.md)

