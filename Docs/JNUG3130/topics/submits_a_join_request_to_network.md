# Submits a join request to network

Once the device identifies a network to join, a request to join the network must be submitted. If a non-zero pre-configured EPID has been set \(see above\), this join request is submitted automatically, otherwise the function **zps\_eAplZdoJoinNetwork\(\)** must be called to submit the request. The outcome of this request is reported in one of the following stack events on the requesting device:

-   zps\_EVENT\_NWK\_JOINED\_AS\_ROUTER \(if joined as Router\)
-   zps\_EVENT\_NWK\_JOINED\_AS\_ENDDEVICE \(if joined as End Device\)
-   zps\_EVENT\_NWK\_FAILED\_TO\_JOIN \(if failed to join\)

In the case of success, the above stack event contains the 16-bit network address that the network has allocated to the local device. In addition, the event zps\_EVENT\_NWK\_NEW\_NODE\_HAS\_JOINED is generated on the parent.

If the case of failure, the device can attempt another join by calling **zps\_eAplZdoJoinNetwork\(\)** with a different result reported in the zps\_EVENT\_NWK\_DISCOVERY\_COMPLETE event.

**Parent topic:**[Starting Routers and End Devices](../topics/starting_routers_and_end_devices.md)

