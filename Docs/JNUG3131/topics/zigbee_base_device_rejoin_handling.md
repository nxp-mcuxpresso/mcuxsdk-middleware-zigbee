# ZigBee base device rejoin handling

For a Router or End Device, there are instances in which the ZigBee PRO stack initiates a network rejoin attempt and include:

-   A Router or End Device which receives a ‘leave with rejoin’ request.

-   An End Device which polls its parent for data but fails to receive a response.


The ZigBee Base Device handles the stack events that result from this rejoin attempt:

-   If the stack event ZPS\_EVENT\_NWK\_FAILED\_TO\_JOIN is received to indicate an unsuccessful rejoin, the ZigBee Base Device makes a series of rejoin attempts as described for the case "If the node was in a network" in [Section 2.1](initialising_and_starting_the_zigbee_base_device.md#ID_003D1578-4268-42FD-808B-6A97FD6F2CB6). If a rejoin attempt is successful, the event BDB\_EVENT\_REJOIN\_SUCCESS is generated to notify the application. If all rejoins are unsuccessful, the event BDB\_EVENT\_REJOIN\_FAILURE is generated unless unsecured joins are enabled, in which case a join through Network Steering is attempted.

-   If the stack event ZPS\_EVENT\_NWK\_JOINED\_AS\_ROUTER or ZPS\_EVENT\_NWK\_JOINED\_AS\_END\_DEVICE is received to indicate a successful rejoin, the event BDB\_EVENT\_REJOIN\_SUCCESS is generated to notify the application.


**Parent topic:**[ZigBee Base Device](../topics/zigbee_base_device.md)

