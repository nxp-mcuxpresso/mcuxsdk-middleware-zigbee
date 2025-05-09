# Attribute Settings

The Simple Metering cluster contains both mandatory and optional attributes \(see [Section 42.2](simple_metering_cluster_structure_and_attributes.md#id_1c898ead-e5b8-46b9-9117-d5b84c56d269)\). The cluster structure is shown below with only the mandatory attributes \(which are enabled by default\):

```
typedef struct PACK
{
  zuint48                   u48CurrentSummationDelivered;
  zbmap8                    u8MeterStatus;
  teSE_UnitOfMeasure        eUnitOfMeasure;
  zbmap8                    u8SummationFormatting;
  teSE_MeteringDeviceType   eMeteringDeviceType;
} tsSE_SimpleMetering;

```

The mandatory attribute settings are outlined below.

## eMeteringDeviceType 

The element `eMeteringDeviceType` of the structure `tsSE_SimpleMetering` indicates the type of Metering Device in terms of the resource type which it measures: electricity, gas, water, heat, cooling or pressure. This attribute belongs to the cluster’s Formatting attribute set.

Enumerated values are provided for the full range of possible metering devices - for example, E\_CLD\_SM\_MDT\_GAS for a gas meter. Enumerated values are also provided for devices that mirror a Metering Device - for example, E\_CLD\_SM\_MDT\_GAS\_MIRRORED         for the mirroring device of a gas meter. All of these enumerations are defined in the structure `teCLD_SM_MeteringDeviceType`, detailed in [Section 42.10.6](metering_device_type_enumerations.md#id_67ec54ac-d1b7-4ffe-adc7-1ce5ec2e3c08).

## u8MeterStatus 

The element `u8MeterStatus` of the structure `tsSE_SimpleMetering` indicates the current status of the device by means of an 8-bit value. This attribute has its own attribute set, Meter Status.

The status value is a bitmap with the bit representations indicated in the table below:

|**Bit 7**|**Bit 6**|**Bit 5**|**Bit 4**|**Bit 3**|**Bit 2**|**Bit 1**|**Bit 0**|
|---------|---------|---------|---------|---------|---------|---------|---------|
|Reserved|Service

 Disconnect

 Open \*

|Leak Detect|Power Quality|Power

 Failure

|Tamper Detect|Battery Low|Check Meter|

\* Set to ‘1’ when service to this site has been disconnected

A bit is set \(to ‘1’\) to indicate the corresponding error or warning.

A number of macros are defined to reflect the above bit settings - for example, E\_CLD\_SM\_METER\_STATUS\_POWER\_FAILURE\_BIT         contains the state of the Power Failure bit \(Bit 3\). There are also macros for masking off the appropriate bit - these macros are detailed in [Section 42.10.2](meter_status_enumerations.md#id_e348bd95-336b-4f5c-bfdc-948d60dc84e5).

## eUnitOfMeasure 

The element `eUnitOfMeasure` of the structure `tsSE_SimpleMetering` indicates the unit of measure in which the relevant resource is metered, e.g. kiloWatt-hour for electricity. This attribute belongs to the cluster’s Formatting attribute set.

Enumerated values are provided for the possible units of measure - for example, E\_CLD\_SM\_UOM\_CUBIC\_METER for cubic metre \(of gas or water\). This example will also configure measurements to be expressed in binary/hex. However, enumerated values are also provided to configure measurements to be expressed in binary coded decimal - for example, E\_CLD\_SM\_UOM\_CUBIC\_METER\_BCD         configures measurements in cubic metres and expressed in binary coded decimal. All of these enumerations are defined in the structure `teCLD_SM_UnitOfMeasure`, detailed in [Section 42.10.3](unit_of_measure_enumerations.md#id_ee7f39b7-56bc-4008-b2e9-3e13449c50d0).

## u8SummationFormatting 

The element `u8SummationFormatting` of the structure `tsSE_SimpleMetering` is an 8-bit value indicating the position of the decimal point in the metered value \(see [u48CurrentSummationDelivered](#id_ae75b4a9-770d-4ece-8a7a-9f2926c8a3d2)\). This attribute belongs to the cluster’s Formatting attribute set.

This value contains bit fields, as follows:

-   **Bits 2-0:** 3-bit value indicating number of digits to right of point

-   **Bits 6-3:** 3-bit value indicating number of digits to left of point

-   **Bit 7:** Setting this bit \(to ‘1’\) suppresses leading zeros


A number of macros are defined to accommodate the above format information - these macros are detailed in [Section 42.10.4](summation_formatting_enumerations.md#id_0dd55d84-6982-431a-a9c9-f46539124377).

## u48CurrentSummationDelivered 

The element `u48CurrentSummationDelivered` of the structure `tsSE_SimpleMetering` is a 48-bit value representing the total quantity consumed, so far, of the metered resource \(e.g. electrical energy\). This attribute belongs to the Reading Information attribute set.

The attribute value is interpreted with the aid of the elements `eUnitOfMeasure` and `u8SummationFormatting`, which indicate the unit of measure and the position of the decimal point respectively.

**Parent topic:**[Simple Metering Cluster](../../Simple_Metering_cluster/topics/simple_metering_cluster.md)

