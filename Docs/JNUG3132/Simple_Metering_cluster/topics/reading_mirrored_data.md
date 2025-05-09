# Reading Mirrored Data

A ZigBee device such as an IPD may need to obtain data from a mirror on the ESP, particularly when the mirrored Metering Device is sleeping. The data is requested by means of the standard ‘read attributes’ method, described in [Section 2.3.2](../../ZCL_fundamentals/topics/reading_attributes.md#id_cc7e89d1-915c-4667-9cd9-85905a6d06ae) - that is, by calling the ZCL function **eZCL\_SendReadAttributesRequest\(\)** on the requesting device.

If an attempt is made to read an attribute that currently has no value in the mirror, the resulting E\_ZCL\_CBET\_READ\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE event will contain the attribute status E\_ZCL\_CMDS\_UNSUPPORTED\_ATTRIBUTE.

**Parent topic:**[Mirroring Metering Data](../../Simple_Metering_cluster/topics/mirroring_metering_data.md)

