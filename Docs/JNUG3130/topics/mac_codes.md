# MAC codes

The MAC codes come from the IEEE 802.15.4 MAC layer of the stack. The MAC codes may be returned by any ZigBee PRO API function with a non-void return. The codes are also described in the *IEEE 802.15.4 Stack User Guide \(JN-UG-3024\)*.

**MAC codes**

|**Name**|**Value**|**Description**|
|--|--|--|
|MAC\_ENUM\_SUCCESS|0x00|Success|
|MAC\_ENUM\_BEACON\_LOSS|0xE0|Beacon loss after synchronization request|
|MAC\_ENUM\_CHANNEL\_ACCESS\_FAILURE|0xE1|CSMA/CA channel access failure|
|MAC\_ENUM\_DENIED|0xE2|GTS request denied|
|MAC\_ENUM\_DISABLE\_TRX\_FAILURE|0xE3|Could not disable transmit or receive|
|MAC\_ENUM\_FAILED\_SECURITY\_CHECK|0xE4|Incoming frame failed security check|
|MAC\_ENUM\_FRAME\_TOO\_LONG|0xE5|Frame too long, after security processing, to be sent|
|MAC\_ENUM\_INVALID\_GTS|0xE6|GTS transmission failed|
|MAC\_ENUM\_INVALID\_HANDLE|0xE7|Purge request failed to find entry in queue|
|MAC\_ENUM\_INVALID\_PARAMETER|0xE8|Out-of-range parameter in function|
|MAC\_ENUM\_NO\_ACK|0xE9|No acknowledgment received when expected|
|MAC\_ENUM\_NO\_BEACON|0xEA|Scan failed to find any beacons|
|MAC\_ENUM\_NO\_DATA|0xEB|No response data after a data request|
|MAC\_ENUM\_NO\_SHORT\_ADDRESS|0xEC|No allocated network \(short\) address for operation|
|MAC\_ENUM\_OUT\_OF\_CAP|0xED|Receiver-enable request could not be executed, as CAP finished|
|MAC\_ENUM\_PAN\_ID\_CONFLICT|0xEE|PAN ID conflict has been detected|
|MAC\_ENUM\_REALIGNMENT|0xEF|Coordinator realignment has been received|
|MAC\_ENUM\_TRANSACTION\_EXPIRED|0xF0|Pending transaction has expired and data discarded|
|MAC\_ENUM\_TRANSACTION\_OVERFLOW|0xF1|No capacity to store transaction|
|MAC\_ENUM\_TX\_ACTIVE|0xF2|Receiver-enable request could not be executed, as in transmit state|
|MAC\_ENUM\_UNAVAILABLE\_KEY|0xF3|Appropriate key is not available in ACL|
|MAC\_ENUM\_UNSUPPORTED\_ATTRIBUTE|0xF4|PIB Set/Get on unsupported attribute|

**Parent topic:**[Return/Status Codes](../topics/return_status_codes.md)

