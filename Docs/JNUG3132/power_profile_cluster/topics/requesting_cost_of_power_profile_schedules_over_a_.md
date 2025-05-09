# Requesting Cost of Power Profile Schedules Over a Day \(by Server\)

The server application can use the **eCLD\_PPGetOverallSchedulePriceSend\(\)** function to send a Get Overall Schedule Price Request to the client, in order to obtain the overall cost of all the power profiles that will be executed over the next 24 hours.

The client can only return the requested information if price-related information about the relevant power profiles is held on the client device. If this is the case, an E\_CLD\_PP\_CMD\_GET\_OVERALL\_SCHEDULE\_PRICE event is generated on the client, with the `bIsInfoAvailable` field set to TRUE in the event structure `tsCLD_PPCallBackMessage`. Otherwise, the client will generate a ZCL default response with status NOT\_FOUND.

On receiving a Get Overall Schedule Price Response on the server, the event E\_CLD\_PP\_CMD\_GET\_OVERALL\_SCHEDULE\_PRICE\_RSP is generated, containing the requested price information \(if available\).

**Parent topic:**[Communicating Price Information](../../power_profile_cluster/topics/communicating_price_information.md)

