# Initializing and starting the ZigBee Base Device

Initialize the ZigBee Base Device in the application code using the function **BDB\_vInit\(\)**. Call this function after initializing the ZigBee PRO stack and after restoring the ZigBee Base Device attribute *bbdbNodeIsOnANetwork* from persistent storage.

**Note:**

1.  **BDB\_vInit\(\)** internally calls the function **BDB\_vSetKeys\(\)**, which loads into memory the pre-configured link key from the file **bdb\_link\_keys.c**. Network security and the pre-configured link keys are described in [Section 2.3](network_security.md#ID_4C903549-A2A4-4958-A885-54D50242FB72).
2.  The ZigBee Base Device requires a number of internal software times, the number defined by the macro BDB\_ZTIMER\_STORAGE. Therefore, when the application calls **ZTIMER\_eInit\(\)** to initialize the required software timers and allocate storage \(array elements\) for them, it must add BDB\_ZTIMER\_STORAGE timers for use by the ZigBee Base Device. This function must be called before **BDB\_vInit\(\)**. Software timers and their associated functions are described in the *ZigBee 3.0 Stack User Guide \(JNUG3130\)*.

The ZigBee Base Device is started by calling the function **BDB\_vStart\(\)**. This function may or may not perform an action. It depends on the node type and whether the node was previously a member of a network. In both cases, the function finally invokes the callback function **APP\_vBdbCallback\(\)** with a suitable event.

## If the node was not on a network: 

For a Router node that supports Touchlink commissioning \(see [Touchlink](touchlink.md#ID_62E3E2EA-3A9B-4306-A0DF-FDC8854BF9C3)\), the function selects a radio channel for the node from the set of primary channels for Touchlink specified in the BDBC\_TL\_PRIMARY\_CHANNEL\_SET bitmap \(see [Touchlink constants](touchlink_constants.md#ID_8D19687E-2F2E-4D4A-90E1-04CAD3E0AB1F)\). Either the first channel of the specified set selects or, if the macro RAND\_CHANNEL is set to TRUE \(in the file **bdb\_options.h**\), a channel selects from the set at random.

For the Coordinator and other Router and End Device nodes, no action is taken. The application must then form a network \(Coordinator or Router\). Alternatively, it can join the node to a network using one of the commissioning methods described in [Network commissioning](network_commissioning.md#ID_A7F09B49-B037-402A-9BDF-6AF4E110535A) \(End Device or Router\).

In the above cases, the function generates a `BDB_EVENT_INIT_SUCCESS` event.

## If the node was on a network: 

For Coordinator and Router nodes, no action is taken and the function generates a `BDB_EVENT_INIT_SUCCESS`event.

For an End Device node, the function attempts to rejoin the node to the network. It performs a series of rejoin cycles, where each cycle comprises the following three rejoin attempts:

1. First attempt with the previously used network parameters \(without network discovery\)

2. Second attempt with network discovery on the set of primary channels specified in the *u32bdbPrimaryChannelSet* bitmap \(attribute\)

3. Third attempt with network discovery on the set of secondary channels specified in the *u32bdbSecondaryChannelSet* bitmap \(attribute\)

The channel bitmaps are ZigBee Base Device attributes, described in [Section 2.5.1](attributes.md#ID_B7F86901-30A4-44E5-8C11-E17BF8CEBC8F).

The above rejoin cycle performs up to a maximum of BDBC\_IMP\_MAX\_REJOIN\_CYCLES times, which is an implementation-specific ZigBee Base Device constant \(see [Section 2.5.2](constants.md#ID_CB648524-D2DB-4870-A0F0-C766A7E87AA0)\).

If a rejoin attempt is successful, the function generates the event BDB\_EVENT\_REJOIN\_SUCCESS.

If all the rejoin attempts are unsuccessful, the function generates the event BDB\_EVENT\_REJOIN\_FAILURE unless unsecured joins are enabled through the APS attribute *apsUseInsecureJoin*, in which case the function attempts a join through Network Steering \(described in [Network steering](network_steering.md#ID_DB53F959-3956-49EA-844E-D27462676BEB)\). The nature of the join depends on the value of the Extended PAN ID \(EPID\) set in the APS attribute *ApsUseExtendedPanid*:

-   For a non-zero EPID, the node attempts to join the network with this EPID.

-   For a zero EPID, the function attempts to join any available network.


This join is attempted with an automatic call to the function**BDB\_eNsStartNwkSteering\(\)**.

**Parent topic:**[ZigBee Base Device](../topics/zigbee_base_device.md)

