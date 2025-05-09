# Cluster structure and attributes

The structure definition for the Electrical Measurement cluster \(server\) is:

```
typedef struct
{
#ifdef ELECTRICAL_MEASUREMENT_SERVER
zbmap32 u32MeasurementType;
#ifdef CLD_ELECTMEAS_ATTR_AC_FREQUENCY
zuint16 u16ACFrequency;
#endif
#ifdef CLD_ELECTMEAS_ATTR_RMS_VOLTAGE
zuint16 u16RMSVoltage;
#endif
#ifdef CLD_ELECTMEAS_ATTR_RMS_CURRENT
zuint16 u16RMSCurrent;
#endif
#ifdef CLD_ELECTMEAS_ATTR_ACTIVE_POWER
zint16 i16ActivePower;
#endif
#ifdef CLD_ELECTMEAS_ATTR_REACTIVE_POWER
zint16 i16ReactivePower;
#endif
#ifdef CLD_ELECTMEAS_ATTR_APPARENT_POWER
zuint16 u16ApparentPower;
#endif
#ifdef CLD_ELECTMEAS_ATTR_POWER_FACTOR
zint8 i8PowerFactor;
#endif
#ifdef CLD_ELECTMEAS_ATTR_AC_VOLTAGE_MULTIPLIER
zuint16 u16ACVoltageMultiplier;
#endif
#ifdef CLD_ELECTMEAS_ATTR_AC_VOLTAGE_DIVISOR
zuint16 u16ACVoltageDivisor;
#endif
#ifdef CLD_ELECTMEAS_ATTR_AC_CURRENT_MULTIPLIER
zuint16 u16ACCurrentMultiplier;
#endif
#ifdef CLD_ELECTMEAS_ATTR_AC_CURRENT_DIVISOR
zuint16 u16ACCurentDivisor;
#endif
#ifdef CLD_ELECTMEAS_ATTR_AC_POWER_MULTIPLIER
zuint16 u16ACPowerMultiplier;
#endif
#ifdef CLD_ELECTMEAS_ATTR_AC_POWER_DIVISOR
zuint16 u16ACPowerDivisor;
#endif
#ifdef CLD_ELECTMEAS_ATTR_MAN_SPEC_APPARENT_POWER
zuint32 u32ManSpecificApparentPower;
#endif
#ifdef CLD_ELECTMEAS_ATTR_MAN_SPEC_NON_ACTIVE_POWER
zuint32 u32NonActivePower;
#endif
#ifdef CLD_ELECTMEAS_ATTR_MAN_SPEC_FNDMTL_REACTIVE_POWER
zint32 i32FundamentalReactivePower;
#endif
#ifdef CLD_ELECTMEAS_ATTR_MAN_SPEC_FNDMTL_APPARENT_POWER
zuint32 u32FundamentalApparentPower;
#endif
#ifdef CLD_ELECTMEAS_ATTR_MAN_SPEC_FNDMTL_POWER_FACTOR
zuint16 u16FundamentalPowerFactor;
#endif
#ifdef CLD_ELECTMEAS_ATTR_MAN_SPEC_NON_FNDMTL_APPARENT_POWER
zuint32 u32NonFundamentalApparentPower;
#endif
#ifdef CLD_ELECTMEAS_ATTR_MAN_SPEC_TOTAL_HARMONIC_DISTORTION
zuint32 u32TotalHarmonicDistortion;
#endif
#ifdef CLD_ELECTMEAS_ATTR_MAN_SPEC_VBIAS
zuint32 u32VBias;
#endif
#ifdef CLD_ELECTMEAS_ATTR_MAN_SPEC_DIVISOR
zuint16 u16ManSpecDivisor;
#endif
#endif
zuint16 u16ClusterRevision;
}tsCLD_ElectricalMeasurement;
```

where:

## ‘Basic Information’ Attribute Set 


`u32MeasurementType` is a mandatory attribute which is a bitmap indicating the types of electrical measurement that can be performed by the deivice on which the cluster server resides.
The bitmap is detailed below(a bit is set to ‘1’ if the corresponding measurement type is supported, or to ‘0’ otherwise):


|**Bits**|**Measurement Type**|
|--------|--------------------|
|0|Active measurement \(AC\)|
|1|Reactive measurement \(AC\)|
|2|Apparent measurement \(AC\)|
|3|Phase A measurement|
|4|Phase B measurement|
|5|Phase C measurement|
|6|DC measurement|
|7|Harmonics measurement|
|8|Power quality measurement|
|9-31|Reserved|

## ‘AC \(Non-phase Specific\) Measurements’ Attribute Set 

- u16ACFrequency is an optional attribute containing the most recent measurement of the AC frequency, in Hertz(Hz).
The special value 0xFFFF is used to indicate that the frequency cannot be measured.


## ‘AC \(Single Phase or Phase A\) Measurements’ Attribute Set 

Note that the attributes `u16RMSVoltage`, `u16RMSCurrent` and `i16ActivePower` must be enabled in conjunction with the corresponding multiplier/divisor pair in the ‘AC Formatting’ attribute set.


- u16RMSVoltage is an optional attribute containing the most recent measurement of the Root Mean Square (RMS) voltage, in Volts.
The special value 0xFFFF is used to indicate that the RMS voltage cannot be measured.
Note that the ‘AC Formatting’ attributes u16ACVoltageMultiplier and u16ACVoltageDivisor must be implemented with this attribute.
- u16RMSCurrent is an optional attribute containing the most recent measurement of the Root Mean Square (RMS) current, in Amps. The special value 0xFFFF is used to indicate that the RMS current cannot be measured. Note that the ‘AC Formatting’ attributes u16ACCurrentMultiplier and u16ACCurrentDivisor must be implemented with this attribute.
- i16ActivePower is an optional attribute containing the present single-phase or Phase-A demand for active power, in Watts (W). A positive value represents active power delivered to the premises and a negative value represents active power received from the premises. Note that the ‘AC Formatting’ attributes u16ACPowerMultiplier and u16ACPowerDivisor must be implemented with this attribute.
- i16ReactivePower is an optional attribute containing the present single-phase or Phase-A demand for reactive power, in Volts-Amps-reactive (VAr). A positive value represents reactive power delivered to the premises and a negative value represents reactive power received from the premises.
- u16ApparentPower is an optional attribute containing the present single-phase or Phase-A demand for apparent power, in Volts-Amps (VA). This value is the positive square-root of i16ActivePower squared plus i16ReactivePower squared.
- i8PowerFactor is an optional attribute containing the single-phase or 
Phase-A power factor ratio represented as a multiple of 0.01(e.g. the attribute value 0x0C represents a ratio of 0.12).


## ‘AC Formatting’ Attribute Set 

The following attributes come in multiplier/divisor pairs, where each pair corresponds to an attribute of the ‘AC \(Single Phase or Phase A\) Measurements’ attribute set and must only be enabled if the corresponding attribute is enabled.


- u16ACVoltageMultiplier is an optional attribute containing the multiplication factor to be applied to the value of the u16RMSVoltage attribute (above). This multiplication factor must be used in conjunction with the u16ACVoltageDivisor division factor. The value 0x0000 is not valid.
- u16ACVoltageDivisor is an optional attribute containing the division factor to be applied to the value of the u16RMSVoltage attribute (above). This division factor must be used in conjunction with the u16ACVoltageMultiplier multiplication factor. The value 0x0000 is not valid. 
- u16ACCurrentMultiplier is an optional attribute containing the multiplication factor to be applied to the value of the u16RMSCurrent attribute (above). This multiplication factor must be used in conjunction with the u16ACCurrentDivisor division factor. The value 0x0000 is not valid.
- u16ACCurrentDivisor is an optional attribute containing the division factor to be applied to the value of the u16RMSCurrent attribute (above). This division factor must be used in conjunction with the u16ACCurrentMultiplier multiplication factor. The value 0x0000 is not valid.
- u16ACPowerMultiplier is an optional attribute containing the multiplication factor to be applied to the value of the i16ActivePower attribute (above). This multiplication factor must be used in conjunction with the u16ACPowerDivisor division factor. The value 0x0000 is not valid.
- u16ACPowerDivisor is an optional attribute containing the division factor to be applied to the value of the i16ActivePower attribute (above). This division factor must be used in conjunction with the u16ACPowerMultiplier multiplication factor. The value 0x0000 is not valid.


## Manufacturer-specific Attributes 


- u32ManSpecificApparentPower is an optional manufacturer-defined attribute containing the demand for apparent power.
- u32NonActivePower is an optional manufacturer-defined attribute containing the demand for non-active power.
- i32FundamentalReactivePower is an optional manufacturer-defined attribute containing the demand for fundamental reactive power.
- u32FundamentalApparentPower is an optional manufacturer-defined attribute containing the demand for fundamental apparent power.
- u16FundamentalPowerFactor is an optional manufacturer-defined attribute representing the power factor of a fundamental power system
u32NonFundamentalApparentPower is an optional manufacturer-defined attribute representing the power factor of a non-fundamental (harmonic) power system.
- u32TotalHarmonicDistortion is an optional manufacturer-defined attribute representing the total harmonic distortion present in the delivered power signal.
- u32VBias is an optional manufacturer-defined attribute representing the bias voltage.
- u16ManSpecDivisor is an optional manufacturer-defined attribute representing a power divisor.


## Global Attributes 

- u16ClusterRevision is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attributeis also described in [Section2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Parent topic:**[Electrical Measurement Cluster](../../electrical_measurement_cluster/topics/electrical_measurement_cluster.md)

