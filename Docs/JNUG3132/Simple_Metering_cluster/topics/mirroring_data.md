# Mirroring Data

Once a mirror for a Metering Device has been set up, as described in [Section 42.5.1](configuring_mirroring_on_esp.md#id_56382dc2-f3cb-45d7-b933-601ecbbcede8) and [Section 42.5.2](configuring_mirroring_on_metering_devices.md#id_d9bbf7f7-4ef8-4c32-9fd8-a21e6fe6bcdc), the mirror can be populated and refreshed with data in two ways:

-   The ESP application can submit a ‘read attributes’ request to the Metering Device \(when it is not asleep\), as described in [Section 2.3.2](../../ZCL_fundamentals/topics/reading_attributes.md#id_cc7e89d1-915c-4667-9cd9-85905a6d06ae).

-   The Metering Device can send metering data as unsolicited attribute reports to the mirror at any time \(for example, before entering sleep mode\). This method is described further below.


The Metering Device application sends unsolicited attribute reports for the Simple Metering cluster to the mirror using the function **eZCL\_ReportAllAttributes\(\)**, described in [Section 5.2](../../Core_functions/topics/attribute_access_functions.md#id_4affd45c-30c4-4380-b0e4-54535096b0ee).

On receiving this data, the event E\_ZCL\_CBET\_ATTRIBUTE\_REPORT\_MIRROR is generated on the ESP, causing the callback function on the ESP to be invoked. The callback function must then check that the data has come from a valid source \(a Metering Device which has a mirror on the ESP\) by calling the function **eSM\_IsMirrorSourceAddressValid\(\)**. According to the outcome of this check, the function updates the event status:

```
sZCL_CallBackEvent.uMessage.sReportAttributeMirror.eStatus

```

-   If `eStatus` is set to E\_ZCL\_ATTR\_REPORT\_OK, the reported attribute values \(metering data\) are automatically stored on the relevant mirror endpoint and an E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTE event is generated for each attribute reported.

-   If `eStatus` is set to anything else, a ZCL default response is automatically sent back to the reporting device to indicate that mirroring is not authorised for this device \(E\_ZCL\_CMDS\_NOT\_AUTHORIZED\).


## Maintaining the Mirrored eMeteringDeviceType Attribute 

When a mirror is created on the ESP, the Simple Metering cluster attribute `eMeteringDeviceType` in the mirror will be set to the appropriate value for the Metering Device to be mirrored \(e.g. E\_CLD\_SM\_MDT\_GAS\). However, in order to distinguish the mirror cluster on the ESP from the original cluster on the Metering Device, the ESP application must replace this value in the mirror with the equivalent ‘\_MIRRORED’ value \(e.g. E\_CLD\_SM\_MDT\_GAS\_MIRRORED\). In fact, this replacement must be performed every time the ESP receives a new set of attribute values from the Metering Device \(by either of the two methods described above\), since this attribute value in the mirror will be over-written each time and must subsequently be corrected.

**Parent topic:**[Mirroring Metering Data](../../Simple_Metering_cluster/topics/mirroring_metering_data.md)

