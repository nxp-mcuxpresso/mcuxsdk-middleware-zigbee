# Extended error codes

If extended error handling is implemented \(see [Section 6.7](return_codes_and_extended_error_handling.md)\), it provides more detail about the error that led to any one of the following function return codes:

-   APS codes 0xA3, 0xA6, and 0xAD \(see [Section 11.2.2](aps_codes.md)\).
-   NWK code 0xC2 \(see [Section 11.2.3](nwk_codes.md)\).

The extended error codes, which elaborate on the above codes are provided in the `ZPS_teExtendedStatus`enumerations.

**Extended error codes**

|**Name**|**Value**|**Description**|
|--|--|--|
|ZPS\_XS\_OK|0x00|Success|
|ZPS\_XS\_E\_FATAL|0x01|Fatal error - retrying will cause the error again|
|ZPS\_XS\_E\_LOOPBACK\_BAD\_ENDPOINT|0x02|Endpoint is not valid for loopback \(fatal error\)|
|ZPS\_XS\_E\_SIMPLE\_DESCRIPTOR\_NO\_ OUTPUT\_CLUSTER|0x03|No output cluster in the Simple descriptor for this endpoint/cluster \(fatal error\)|
|ZPS\_XS\_E\_FRAG\_NEEDS\_ACK|0x04|Fragmented data requests must be sent with APS ack \(fatal error\)|
|ZPS\_XS\_E\_COMMAND\_MANAGER\_BAD\_ PARAMETER|0x05|Bad parameter has been passed to the command manager \(fatal error\)|
|ZPS\_XS\_E\_INVALID\_ADDRESS|0x06|Address parameter is out-of-range \(fatal error\). For example, broadcast address when calling unicast function|
|ZPS\_XS\_E\_INVALID\_TX\_ACK\_FOR\_LOCAL\_EP|0x07|TX ACK bit has been set when attempting to post to a local endpoint \(fatal error\)|
|ZPS\_XS\_E\_RESOURCE|0x08|Resource error/shortage - retrying may succeed|
|ZPS\_XS\_E\_NO\_FREE\_NPDU|0x80|No free NPDUs \(resource error\) - the number of NPDUs is set in the "`Number of NPDUs`" property of the "`PDU Manager`" section of the ZPS Configuration Editor|
|ZPS\_XS\_E\_NO\_FREE\_APDU|0x81|No free APDUs \(resource error\) - the number of APDUs is set in the "Instances" property of the appropriate "`APDU`" child of the "`PDU Manager`" section of the ZPS Configuration Editor.|
|ZPS\_XS\_E\_NO\_FREE\_SIM\_DATA\_REQ|0x82|No free simultaneous data request handles \(resource error\) - the number of handles is set in the "Maximum Number of Simultaneous Data Requests" field of the "APS layer configuration" section of the ZPS Configuration Editor|
|ZPS\_XS\_E\_NO\_FREE\_APS\_ACK|0x83|No free APS acknowledgment handles \(resource error\) - the number of handles is set in the "Maximum Number of Simultaneous Data Requests with Acks" field of the "APS layer con- figuration" section of the ZPS Configuration Editor|
|ZPS\_XS\_E\_NO\_FREE\_FRAG\_RECORD|0x84|No free fragment record handles \(resource error\)- the number of handles is set in the "Maximum Number of Transmitted Simultaneous Fragmented Messages" field of the "APS layer configuration" section of the ZPS Configuration Editor|
|ZPS\_XS\_E\_NO\_FREE\_MCPS\_REQ|0x85|No free MCPS request descriptors \(resource error\) - there are 8 MCPS request descriptors and these are only ever likely to be exhausted under a very heavy network load or when trying to transmit too many frames too close together|
|ZPS\_XS\_E\_NO\_FREE\_LOOPBACK|0x86|Loopback send is currently busy \(resource error\)- there can be only one loopback request at a time|
|ZPS\_XS\_E\_NO\_FREE\_EXTENDED\_ADDR|0x87|No free entries in the extended address table \(resource error\) - this table is configured in the ZPS Configuration Editor|
|ZPS\_XS\_E\_SIMPLE\_DESCRIPTOR\_NOT\_ FOUND|0x88|Simple descriptor does not exist for this endpoint/ cluster|
|ZPS\_XS\_E\_BAD\_PARAM\_APSDE\_REQ\_RSP|0x89|Bad parameter has been found while processing an APSDE request or response|
|ZPS\_XS\_E\_NO\_RT\_ENTRY|0x8a|No routing table entries free|
|ZPS\_XS\_E\_NO\_BTR|0x8b|No Broadcast transaction table entries free|
|ZPS\_XS\_E\_FRAME\_COUNTER\_ERROR|0xC0|Decryption failed due to frame counter of received frame not greater than stored frame counter.|
|ZPS\_XS\_E\_CCM\_INVALID\_ERROR|0xC1|Decryption failed due to invalid CCM data.|
|ZPS\_XS\_E\_UNKNOWN\_SRC\_ADDR|0xC2|Decryption failed due to unknown source address in the received frame.|
|ZPS\_XS\_E\_NO\_KEY\_DESCRIPTOR|0xC3|Decryption failed due to missing the matching key descriptor.|
|ZPS\_XS\_E\_NULL\_KEYDESCR|0xC4|Decryption failed due to `NULL` key descriptor.|
|ZPS\_XS\_E\_PDUM\_ERROR|0xC5|Decryption failed due to PDUM packet clone failure.|
|ZPS\_XS\_E\_NULL\_EXT\_ADDR|0xC6|Encryption failed due to missing the Extended Address.|
|ZPS\_XS\_E\_ENCRYPT\_NULL\_DESCR|0xC7|Encryption failed due to `NULL` key descriptor.|
|ZPS\_XS\_E\_ENCRYPT\_FRAME\_COUNTER\_FAIL|0xC8|Encryption failed due to frame counter of outgoing frame being invalid.|
|ZPS\_XS\_E\_ENCRYPT\_DEFAULT|0xC9|Encryption failed due to internal error.|
|ZPS\_XS\_E\_FRAME\_COUNTER\_EXPIRED|0xCA|Decryption failed due to frame counter expiration of the received frame.|

**Parent topic:**[Return/Status Codes](../topics/return_status_codes.md)

