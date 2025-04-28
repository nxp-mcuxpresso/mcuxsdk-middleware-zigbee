# ZDP codes

The ZDP codes are carried in request and response messages.

**ZDP codes**

|**Name**|**Value**|**Description**|
|---|---|--|
|ZPS\_APL\_ZDP\_E\_INV\_REQUESTTYPE|0x80|The supplied request type was invalid.|
|ZPS\_APL\_ZDP\_E\_DEVICE\_NOT\_FOUND|0x81|The requested device did not exist on a device following a child descriptor request to a parent.|
|ZPS\_APL\_ZDP\_E\_INVALID\_EP|0x82|The supplied endpoint was equal to 0x00 or between 0xF1 and 0xFF.|
|ZPS\_APL\_ZDP\_E\_NOT\_ACTIVE|0x83|The requested endpoint is not described by a Simple descriptor.|
|ZPS\_APL\_ZDP\_E\_NOT\_SUPPORTED|0x84|The requested optional feature is not supported on the target device.|
|ZPS\_APL\_ZDP\_E\_TIMEOUT|0x85|A timeout has occurred with the requested operation.|
|ZPS\_APL\_ZDP\_E\_NO\_MATCH|0x86|The End Device bind request was unsuccessful due to a failure to match any suitable clusters.|
|ZPS\_APL\_ZDP\_E\_NO\_ENTRY|0x88|The unbind request was unsuccessful due to the Co- ordinator or source device not having an entry in its binding table to unbind.|
|ZPS\_APL\_ZDP\_E\_NO\_DESCRIPTOR|0x89|A child descriptor was not available following a discovery request to a parent.|
|ZPS\_APL\_ZDP\_E\_INSUFFICIENT\_SPACE|0x8A|The device does not have storage space to support the requested operation.|
|ZPS\_APL\_ZDP\_E\_NOT\_PERMITTED|0x8B|The device is not in the proper state to support the requested operation.|
|ZPS\_APL\_ZDP\_E\_TABLE\_FULL|0x8C|The device does not have table space to support the operation.|
|ZPS\_APL\_ZDP\_E\_NOT\_AUTHORIZED|0x8D|The permissions configuration table on the target indicates that the request is not authorized from this device.|

**Parent topic:**[Return/Status Codes](../topics/return_status_codes.md)

