# ZPS\_tsInterPanAddress

This structure is used to specify the destination for an inter-PAN transmission. The `ZPS_tsInterPanAddress`structure is detailed below.

```
typedef struct
{
    enum {
        ZPS_E_AM_INTERPAN_GROUP = 0x01,
        ZPS_E_AM_INTERPAN_SHORT,
        ZPS_E_AM_INTERPAN_IEEE
    }eMode;
    uint16 u16PanId;
    ZPS_tuAddress uAddress;
} ZPS_tsInterPanAddress;
```

where:

-   `eMode`is used to specify the type of destination address that will be used in the field `uAddress`below. One of the following enumerations must be specified:
    -   `ZPS_E_AM_INTERPAN_GROUP` indicates that a 16-bit group address will be used to specify multiple target nodes in the destination network \(the group address must be valid in the destination network\)
    -   `ZPS_E_AM_INTERPAN_SHORT` indicates that a 16-bit network/short address will be used to specify a single target node or a broadcast to all nodes in the destination network
    -   `ZPS_E_AM_INTERPAN_IEEE` indicates that a 64-bit IEEE/MAC address will be used to specify a single target node in the destination network
-   `u16PanId`is the PAN ID of the destination network - a value 0xFFFF can be used to specify a broadcast to all reachable ZigBee PRO networks
-   `uAddress`is the address of the target node\(s\) in the destination network \(the address type must be as specified above in the `eMode`field\) - a value of 0xFFFF can be used to specify a broadcast to all nodes in the destination network\(s\).

**Parent topic:**[Other structures](../topics/other_structures.md)

