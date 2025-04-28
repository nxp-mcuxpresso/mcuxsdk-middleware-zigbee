# APS codes

The APS codes relate to sending/receiving messages.

**APS codes**
|**Name**|**Value**|**Description**|
|--|--|--|
|ZPS\_APL\_APS\_E\_ASDU\_TOO\_LONG|0xA0|A transmit request failed since the ASDU is too large and fragmentation is not supported.|
|ZPS\_APL\_APS\_E\_DEFRAG\_DEFERRED|0xA1|A received fragmented frame could not be defragmented at the current time.|
|ZPS\_APL\_APS\_E\_DEFRAG\_UNSUPPORTED|0xA2|A received fragmented frame could not be defragmented since the device does not support fragmentation.|
|ZPS\_APL\_APS\_E\_ILLEGAL\_REQUEST|0xA3|A parameter value was out of range.|
|ZPS\_APL\_APS\_E\_INVALID\_BINDING|0xA4|An APSME-UNBIND.request failed due to the requested binding link not existing in the binding table.|
|ZPS\_APL\_APS\_E\_INVALID\_GROUP|0xA5|An APSME-REMOVE-GROUP.request has been issued with a group identifier that does not appear in the group table.|
|ZPS\_APL\_APS\_E\_INVALID\_PARAMETER|0xA6|A parameter value was invalid or out of range.|
|ZPS\_APL\_APS\_E\_NO\_ACK|0xA7|An APSDE-DATA.request requesting acknowledged transmission failed due to no acknowledgment being received.|
|ZPS\_APL\_APS\_E\_NO\_BOUND\_DEVICE|0xA8|An APSDE-DATA.request with a destination addressing mode set to 0x00 failed due to there being no devices bound to this device.|
|ZPS\_APL\_APS\_E\_NO\_SHORT\_ADDRESS|0xA9|An APSDE-DATA.request with a destination addressing mode set to 0x03 failed due to no corresponding short address found in the address map table.|
|ZPS\_APL\_APS\_E\_NOT\_SUPPORTED|0xAA|An APSDE-DATA.request with a destination addressing mode set to 0x00 failed due to a binding table not being supported on the device.|
|ZPS\_APL\_APS\_E\_SECURED\_LINK\_KEY|0xAB|An ASDU was received that was secured using a link key.|
|ZPS\_APL\_APS\_E\_SECURED\_NWK\_KEY|0xAC|An ASDU was received that was secured using a network key.|
|ZPS\_APL\_APS\_E\_SECURITY\_FAIL|0xAD|An APSDE-DATA.request requesting security has resulted in an error during the corresponding security processing.|
|ZPS\_APL\_APS\_E\_TABLE\_FULL|0xAE|An APSME-BIND.request or APSME.ADDGROUP.request issued when the binding or group tables, respectively, were full.|
|ZPS\_APL\_APS\_E\_UNSECURED|0xAF|An ASDU was received without any security.|
|ZPS\_APL\_APS\_E\_UNSUPPORTED\_ATTRIBUTE|0xB0|An APSME-GET.request or APSMESET. request has been issued with an unknown attribute identifier.|

**Parent topic:**[Return/Status Codes](../topics/return_status_codes.md)

