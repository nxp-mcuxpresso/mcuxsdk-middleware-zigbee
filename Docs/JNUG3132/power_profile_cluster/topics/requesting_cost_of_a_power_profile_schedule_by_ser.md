# Requesting Cost of a Power Profile Schedule \(by Server\)

The server application can use the function **eCLD\_PPGetPowerProfilePriceSend\(\)** to send a Get Power Profile Price Request to the client, in order to request the cost of executing the schedule of a particular power profile.

The client can only return the requested information if price-related information about the power profile is held on the client device. If this is the case, an E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE event is generated on the client, with the `bIsInfoAvailable` field set to TRUE in the event structure `tsCLD_PPCallBackMessage` and the client sends a Get Power Profile Price Response back to the server. Otherwise, the client sends a ZCL default response with status NOT\_FOUND.

On receiving a Get Power Profile Price Response on the server, the event E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE\_RSP is generated, containing the requested price information \(if available\).

Alternatively, the server application can use the function **eCLD\_PPGetPowerProfilePriceExtendedSend\(\)** to send a Get Power Profile Price Extended Request to a cluster client, in order to request specific cost information about a power profile supported by the server. The cost of executing a power profile can be requested with either scheduled energy phases or contiguous energy phases \(no gaps between them\). This request is handled by the client as described above for an ordinary Get Power Profile Price Request. However, the response results in an E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE\_EXTENDED\_RSP event on the server, containing the requested price information \(if available\).

**Parent topic:**[Communicating Price Information](../../power_profile_cluster/topics/communicating_price_information.md)

