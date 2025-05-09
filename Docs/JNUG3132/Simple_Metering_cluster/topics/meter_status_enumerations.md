# ‘Meter Status’ Enumerations

Enumerations for the `u8MeterStatus` element in the Simple Metering cluster structure `tsSE_SimpleMetering` are provided as \#defines.

The following enumerated masks can be used to set the meter status:

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_SM\_METER\_STATUS\_CHECK\_METER\_MASK|Non-fatal problem detected on meter|
|E\_CLD\_SM\_METER\_STATUS\_LOW\_BATTERY\_MASK|Battery level is low|
|E\_CLD\_SM\_METER\_STATUS\_TAMPER\_DETECT\_MASK|Detected tampering with device|
|E\_CLD\_SM\_METER\_STATUS\_POWER\_FAILURE\_MASK|Indicates power failure on device|
|E\_CLD\_SM\_METER\_STATUS\_POWER\_QUALITY\_MASK|Power anomaly detected|
|E\_CLD\_SM\_METER\_STATUS\_LEAK\_DETECT\_MASK|Detected leak \(e.g. of gas or water\)|
|E\_CLD\_SM\_METER\_STATUS\_SERVICE\_DISCONNECT\_OPEN\_MASK|Service to premises disconnected|

**Parent topic:**[Enumerations](../../Simple_Metering_cluster/topics/enumerations.md)

