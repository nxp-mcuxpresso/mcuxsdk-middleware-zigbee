# ‘Device Class’ Enumerations

The device classes that are used in load control are enumerated in the `teSE_DRLCDeviceClassFieldBitmap` structure below:

```
typedef enum
{
   E_SE_DRLC_HVAC_COMPRESSOR_OR_FURNACE_BIT = 0x00,
   E_SE_DRLC_STRIP_BASEBOARD_HEATERS_BIT,
   E_SE_DRLC_WATER_HEATER_BIT,
   E_SE_DRLC_POOL_PUMP_SPA_JACUZZI_BIT,
   E_SE_DRLC_SMART_APPLIANCES_BIT,
   E_SE_DRLC_IRRIGATION_PUMP_BIT,
   E_SE_DRLC_MANAGED_COMMERCIAL_AND_INDUSTRIAL_LOADS_BIT,
   E_SE_DRLC_SIMPLE_MISC_LOADS_BIT,
   E_SE_DRLC_EXTERIOR_LIGHTING_BIT,
   E_SE_DRLC_INTERIOR_LIGHTING_BIT,
   E_SE_DRLC_ELECTRIC_VEHICLE_BIT,
   E_SE_DRLC_GENERATION_SYSTEMS_BIT,
   E_SE_DRLC_DEVICE_CLASS_FIRST_RESERVED_BIT
} teSE_DRLCDeviceClassFieldBitmap;

```

The device class enumerations are listed and described in the table below.

|**Device Class Enumeration**|**Description**|
|----------------------------|---------------|
|E\_SE\_DRLC\_HVAC\_COMPRESSOR\_OR\_FURNACE\_BIT|HVAC compressor or furnace|
|E\_SE\_DRLC\_STRIP\_BASEBOARD\_HEATERS\_BIT|Strip/baseboard heater|
|E\_SE\_DRLC\_WATER\_HEATER\_BIT|Water heater|
|E\_SE\_DRLC\_POOL\_PUMP\_SPA\_JACUZZI\_BIT|Pool/spa/jacuzzi pump|
|E\_SE\_DRLC\_SMART\_APPLIANCES\_BIT|Smart appliance|
|E\_SE\_DRLC\_IRRIGATION\_PUMP\_BIT|Irrigation pump|
|E\_SE\_DRLC\_MANAGED\_COMMERCIAL\_AND\_INDUSTRIAL\_LOADS\_BIT|Managed Commercial &amp; Industrial \(C&amp;I\)|
|E\_SE\_DRLC\_SIMPLE\_MISC\_LOADS\_BIT|Simple miscellaneous \(residential on/off\)|
|E\_SE\_DRLC\_EXTERIOR\_LIGHTING\_BIT|Exterior lighting|
|E\_SE\_DRLC\_INTERIOR\_LIGHTING\_BIT|Interior lighting|
|E\_SE\_DRLC\_ELECTRIC\_VEHICLE\_BIT|Electric vehicle|
|E\_SE\_DRLC\_GENERATION\_SYSTEMS\_BIT|Generation systems|
|E\_SE\_DRLC\_DEVICE\_CLASS\_FIRST\_RESERVED\_BIT|Reserved|

**Parent topic:**[Enumerations](../../DRLC_cluster/topics/enumerations.md)

