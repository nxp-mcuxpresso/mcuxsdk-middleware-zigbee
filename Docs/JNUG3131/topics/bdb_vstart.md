# BDB_vStart

```
void BDB_vStart(void);

```

## Description 

This function starts the ZigBee Base Device \(ZBD\) and must be called after **BDB\_vInit\(\)** and just before the application enters the main loop \(for example: **APP\_vMainLoop\(\)**\).

Depending on the node type and whether the node was previously a member of a network, the function may or may not perform an action. In either case, the function invokes the callback function **APP\_vBdbCallback\(\)** with a suitable event.

-   If the node was not in a network:

    -   For a Router node that supports Touchlink commissioning, the function selects a radio channel for the node from the set of primary channels defined for Touchlink.

    -   For other Router, Coordinator, and End Device nodes, no action is taken and the application then must join the node to a network.

        -   In the above cases, the function generates the event BDB\_EVENT\_INIT\_SUCCESS.
-   If the node was in a network:

    -   For Coordinator and Router nodes, no action is taken by the function and the event BDB\_EVENT\_INIT\_SUCCESS is generated.

    -   For an End Device node, a series of rejoin attempts are performed. If a rejoin attempt is successful, the event BDB\_EVENT\_REJOIN\_SUCCESS is generated. If all rejoins are unsuccessful, the event BDB\_EVENT\_REJOIN\_FAILURE is generated unless unsecured joins are enabled, in which case a join through Network Steering is attempted.


The above actions are described in more detail in [Section 2.1](initialising_and_starting_the_zigbee_base_device.md#ID_003D1578-4268-42FD-808B-6A97FD6F2CB6).

## Parameters 

-   None

## Returns

-   None

**Parent topic:**[Functions](../topics/functions.md)

