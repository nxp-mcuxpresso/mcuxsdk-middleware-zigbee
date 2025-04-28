# NWK codes

The NWK codes come from the NWK layer of the stack and may be returned by any ZigBee PRO API function with a non-void return.

**NWK codes**

|**Name**|**Value**|**Description**|
|--|--|--|
|ZPS\_NWK\_ENUM\_SUCCESS|0x00|Success|
|ZPS\_NWK\_ENUM\_INVALID\_PARAMETER|0xC1|An invalid or out-of-range parameter has been passed|
|ZPS\_NWK\_ENUM\_INVALID\_REQUEST|0xC2|Request cannot be processed|
|ZPS\_NWK\_ENUM\_NOT\_PERMITTED|0xC3|NLME-JOIN.request not permitted|
|ZPS\_NWK\_ENUM\_STARTUP\_FAILURE|0xC4|NLME-NETWORK-FORMATION.request failed|
|ZPS\_NWK\_ENUM\_ALREADY\_PRESENT|0xC5|NLME-DIRECT-JOIN.request failure - device already present|
|ZPS\_NWK\_ENUM\_SYNC\_FAILURE|0xC6|NLME-SYNC.request has failed|
|ZPS\_NWK\_ENUM\_NEIGHBOR\_TABLE\_FULL|0xC7|NLME-DIRECT-JOIN.request failure - no space in Router table|
|ZPS\_NWK\_ENUM\_UNKNOWN\_DEVICE|0xC8|NLME-LEAVE.request failure - device not in Neighbor table|
|ZPS\_NWK\_ENUM\_UNSUPPORTED\_ATTRIBUTE|0xC9|NLME-GET/SET.request unknown attribute identifier|
|ZPS\_NWK\_ENUM\_NO\_NETWORKS|0xCA|NLME-JOIN.request detected no networks|
|ZPS\_NWK\_ENUM\_RESERVED\_1|0xCB|Reserved|
|ZPS\_NWK\_ENUM\_MAX\_FRM\_CTR|0xCC|Security processing has failed on outgoing frame due to maximum frame counter|
|ZPS\_NWK\_ENUM\_NO\_KEY|0xCD|Security processing has failed on outgoing frame due to no key|
|ZPS\_NWK\_ENUM\_BAD\_CCM\_OUTPUT|0xCE|Security processing has failed on outgoing frame due CCM|
|ZPS\_NWK\_ENUM\_NO\_ROUTING\_CAPACITY|0xCF|Attempt at route discovery has failed due to lack of table space|
|ZPS\_NWK\_ENUM\_ROUTE\_DISCOVERY\_FAILED|0xD0|Attempt at route discovery has failed due to any reason except lack of table space|
|ZPS\_NWK\_ENUM\_ROUTE\_ERROR|0xD1|NLDE-DATA.request has failed due to routing failure on sending device|
|ZPS\_NWK\_ENUM\_BT\_TABLE\_FULL|0xD2|Broadcast or broadcast-mode multicast has failed as there is no room in BTT|
|ZPS\_NWK\_ENUM\_FRAME\_NOT\_BUFFERED|0xD3|Unicast mode multi-cast frame was discarded pending route discovery|
|ZPS\_NWK\_ENUM\_FRAME\_IS\_BUFFERED|0xD4|Unicast frame does not have a route available but it is buffered for automatic resend.|

**Parent topic:**[Return/Status Codes](../topics/return_status_codes.md)

