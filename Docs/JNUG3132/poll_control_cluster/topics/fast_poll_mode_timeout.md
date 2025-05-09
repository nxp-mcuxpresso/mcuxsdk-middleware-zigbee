# Fast Poll Mode Timeout

In the Check-in response from a client, the payload \(see [Section 20.9.2](tscld_pollcontrol_checkinresponsepayload.md#id_00a9d130-1180-415c-8ef5-bfe98d6ea45f)\) may contain an optional timeout value which, if used, specifies the length of time that the device should remain in fast poll mode \(this timeout value will be used instead of the one specified through the ‘fast poll timeout’ attribute\). If the response payload specifies an out-of-range timeout value, the server will send a ZCL default response with status INVALID\_VALUE to the client \(see [Section 20.4.3.2](invalid_check-in_responses.md#id_ec1aba0e-7b6b-475c-a0b0-d1a1ea3d5b52)\). In the case of multiple clients \(controllers\) that have specified different timeout values, the server will use the largest timeout value received.

**Parent topic:**[Operation](../../poll_control_cluster/topics/operation.md)

