# Binding endpoints

An endpoint on the local node can be bound to one or more endpoints on remote nodes using the following functions:

-   <strong>zps\_eAplZdoBind\(\)</strong> creates a one-to-one binding to a single remote endpoint.
-   <strong>zps\_eAplZdoBindGroup\(\)</strong> creates a one-to-many binding for which the destination endpoints are specified via a group address \(refer to [Section 5.3](managing_group_addresses.md)\).

The function <strong>zps\_eAplZdpEndDeviceBindRequest\(\)</strong> is also provided, which allows an endpoint on one End Device to be bound to an endpoint on another End Device via the Coordinator. This function must be called on both End Devices, where the function call would typically be triggered by a user action such as pressing a button on the node. The function submits an End\_Device\_Bind\_req request to the Coordinator, which replies with an End\_Device\_Bind\_rsp response. The stack will then automatically update the Binding tables on the End Devices \(as the result of bind requests from the Coordinator\), and these updates will be indicated by a zps\_EVENT\_ZDO\_BIND event on each of the End Devices.

**Parent topic:**[Binding](../topics/binding_001.md)

