# Description

This function can be used to register a user-defined callback function on the Trust Centre, where this callback function allows the application to react to a notification from another network node - for example, to decide whether to permit a node to join that may or may not be known to the Trust Centre application.

The prototype of the user-defined callback function is:
```
bool bTransportKeyDecider (uint16 u16ShortAddress,
                            uint64 u64DeviceAddress,
                            uint64 u64ParentAddress,
                            uint8 u8Status,
                            uint16 u16Interface);

```
where:

-   *u16ShortAddr* is the network address of the relevant node.
-   *u64DeviceAddress* is the IEEE/MAC address of the relevant node.
-   *u64ParentAddress* is the IEEE/MAC address of the parent that sent the notification.
-   *u8Status* is the nature of the notification:
    -   0: Secure rejoin
    -   1: Unsecure join \(association\)
    -   2: Leave
    -   3: Unsecure rejoin
    -   4: Leave with a rejoin

-   *u16Interface* is the MAC interface this join has happened on. If it is 2.4 G only the value is always 0. If it is a MultiMAC device 2.4 G interface, it will return value 0 and sub Gig will return value 1.

To disallow the notified action \(for example, a join\), the callback function should return FALSE.

If the callback function is not registered or returns TRUE, the Trust Centre will allow the notified action. In the case of a join, the Trust Centre will send the network key in a ‘transport key’ command to the node, either:

-   encrypted with the node’s pre-configured link key, if this key is known to the Trust Centre, or
-   encrypted with the Trust Centre’s default pre-configured link key otherwise \(in this case, the joining node will only be able to decrypt the ‘transport key’ command and complete the join if it also has the Trust Centre’s default pre-configured link key\)

Registration of this callback function may be useful in controlling rejoins. A node can initially join a network using its pre-configured link key \(which is also known by the Trust Centre\), but this key may subsequently be replaced on the Trust Centre by an application link key \(shared only by the node and the Trust Centre\). If the node later leaves the network and loses its context data \(including the application link key\), it may attempt to rejoin the network using its pre-configured link key again. The callback function can allow the application to decide whether to permit such a rejoin. If the rejoin is to be allowed, the callback function must replace the stored application link key with the pre-configured link key on the Trust Centre before returning TRUE.

**Parent topic:**[ZPS\_vTCSetCallback](../topics/zps_vtcsetcallback.md)

