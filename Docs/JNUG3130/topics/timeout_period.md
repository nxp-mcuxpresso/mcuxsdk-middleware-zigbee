# Timeout period

The timeout period is specific to an individual child and is set on the End Device using the function **zps\_bAplAfSetEndDeviceTimeout\(\)**. This period is communicated to the parent via an End Device Timeout Request when the End Device joins \(or re-joins\) the network. The timeout is applied by the Router to the Neighbor table entry for the End Device. The arrival of a keep-alive packet from the End Device will result in the timeout being re-started from the beginning. If the timeout is allowed to expire \(without a keep-alive packet\), the Router will delete the relevant child entry from the Neighbor table.

-   Note 1: The Router initially sets the timeout for all End Device children to the default value defined in the NIB, which is 256 minutes in the NXP software. The timeout will remain at this value unless changed by the End Device, as described above.

-   Note 2: After receiving the End Device Timeout Request, the parent will send an End Device Timeout Response to the End Device, indicating the outcome of the request. If the request has been successful, the End Device can subsequently send keep-alive packets


**Parent topic:**[End device aging](../topics/end_device_aging.md)

