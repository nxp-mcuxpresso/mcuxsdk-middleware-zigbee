# Keep-alive packets

A keep-alive packet can be sent from the End Device using the function **zps\_eAplAfSendKeepAlive\(\)**. It is recommended that this function is called at least three times within the timeout period defined for the End Device, in order to prevent the child from being accidentally removed from the network due to missed keep-alive packets at the parent.

A keep-alive packet can be either of the following types:

-   **MAC Data Poll:** In this case, the parent may send pending data back to the End Device. The arrival of this data at the End Device will be indicated by a zps\_EVENT\_AF\_DATA\_INDICATION event \(as described in [Section 6.5.2](receiving_data.md)\).
-   **End Device Timeout Request**: This packet type simply has the effect of re- starting the timeout for the End Device on the parent, which will return an End Device Timeout Response to the End Device, indicating the outcome of the request.

The keep-alive packet type to be used is determined by the Router parent and is configured in the NIB on the parent - in the NXP software, a Router is configured to accept either packet type, by default. This information is communicated to the End Device in the initial End Device Timeout Response that is sent to the End Device on joining the network. The **zps\_eAplAfSendKeepAlive\(\)** function will then automatically send the appropriate keep-alive packet type - where either packet type is accepted by the parent, the function sends a Data Poll packet.

**Parent topic:**[End device aging](../topics/end_device_aging.md)

