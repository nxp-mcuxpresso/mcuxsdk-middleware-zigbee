# JCU APIs

The Core Utilities \(JCU\) provide an easy-to-use interface to simplify the programming of a range of non-network-specific operations. These utilities/modules each have a C function API, which allows a module to be used from a user application. The JCU is supplied in the ZigBee 3.0 SDK.

The JCU modules are outlined below:

-   **Non-Volatile Memory Manager \(NVM\):** This module handles the storage of context and application data in Non-Volatile Memory \(NVM\), and the retrieval of this data. It provides a mechanism by which the device can resume operation without loss of continuity following a power loss.
-   **Low-Power:** This module manages the transitions of the device into and out of low-power modes, such as sleep mode.
-   **Protocol Data Unit Manager \(PDUM\):** This module is concerned with managing memory, as well as inserting data into messages to be transmitted and extracting data from messages that have been received.

**Note:** The JCU modules are fully described in the *DK6 Core Utilities User Guide \(JNUG3133\)*.

**Parent topic:**[Software overview](../topics/software_overview.md)

