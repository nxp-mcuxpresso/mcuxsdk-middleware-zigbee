# Setting the Extended PAN ID for the network

The 64-bit Extended PAN ID \(EPID\) for the network is obtained as follows:

-   A pre-configured value may be set in the advanced device parameter *APS Use Extended PAN ID*in the ZPS Configuration Editor \(see [Section 13.4.4](setting_advanced_device_parameters.md)\).
-   If the pre-set value is zero, the Coordinator uses its own IEEE/MAC address as the EPID.

**Note:** The application might override the EPID value set by the ZPS Configuration Editor by calling **zps\_eAplAibSetApsUseExtendedPanId\(\)** before calling **zps\_eAplZdoStartStack\(\)**.

**Parent topic:**[Starting the Coordinator](../topics/starting_the_coordinator.md)

