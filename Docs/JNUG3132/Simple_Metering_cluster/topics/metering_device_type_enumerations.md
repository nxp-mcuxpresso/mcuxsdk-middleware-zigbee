# ‘Metering Device Type’ Enumerations

The following enumerations are used to set the `eMeteringDeviceType` element in the Simple Metering cluster structure `tsSE_SimpleMetering`.

```
typedef enum PACK
{
    E_CLD_SM_MDT_ELECTRIC                = 0x00,
    E_CLD_SM_MDT_GAS,
    E_CLD_SM_MDT_WATER,
    E_CLD_SM_MDT_THERMAL,                /* Deprecated */
    E_CLD_SM_MDT_PRESSURE,
    E_CLD_SM_MDT_HEAT,
    E_CLD_SM_MDT_COOLING,
    E_CLD_SM_MDT_GAS_MIRRORED            = 0x80,
    E_CLD_SM_MDT_WATER_MIRRORED,
    E_CLD_SM_MDT_THERMAL_MIRRORED,
    E_CLD_SM_MDT_PRESSURE_MIRRORED,
    E_CLD_SM_MDT_HEAT_MIRRORED,
    E_CLD_SM_MDT_COOLING_MIRRORED,
} teCLD_SM_MeteringDeviceType;

```

The above enumerations are detailed in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_SM\_MDT\_ELECTRIC|Electric Meter|
|E\_CLD\_SM\_MDT\_GAS|Gas Meter|
|E\_CLD\_SM\_MDT\_WATER|Water Meter|
|E\_CLD\_SM\_MDT\_THERMAL|Thermal Meter \(deprecated\)|
|E\_CLD\_SM\_MDT\_PRESSURE|Pressure Meter|
|E\_CLD\_SM\_MDT\_HEAT|Heat Meter|
|E\_CLD\_SM\_MDT\_COOLING|Cooling Meter|
|E\_CLD\_SM\_MDT\_GAS\_MIRRORED|Mirrored Gas Meter|
|E\_CLD\_SM\_MDT\_WATER\_MIRRORED|Mirrored Water Meter|
|E\_CLD\_SM\_MDT\_THERMAL\_MIRRORED|Mirrored Thermal Meter \(deprecated\)|
|E\_CLD\_SM\_MDT\_PRESSURE\_MIRRORED|Mirrored Pressure Meter|
|E\_CLD\_SM\_MDT\_HEAT\_MIRRORED|Mirrored Heat Meter|
|E\_CLD\_SM\_MDT\_COOLING\_MIRRORED|Mirrored Cooling Meter|

**Parent topic:**[Enumerations](../../Simple_Metering_cluster/topics/enumerations.md)

