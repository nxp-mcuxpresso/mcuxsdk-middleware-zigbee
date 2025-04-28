# ZPS\_tsAfNwkRouteDiscoveryConfEvent

This structure is used in the ZPS\_EVENT\_NWK\_ROUTE\_DISCOVERY\_CONFIRM event, which confirms that a route discovery has been performed.

The `ZPS_tsAfNwkRouteDiscoveryConfEvent`structure is detailed below.

```
typedef struct {
    uint16 u16DstAddress;
    uint8 u8Status;
    uint8 u8NwkStatus;
} ZPS_tsAfNwkRouteDiscoveryConfEvent;
```

where:

-   `u16DstAddress`is the destination address for which the route discovery confirm event was generated.
-   `u8Status`is one of the status codes from the MAC layer, detailed in [Section](mac_codes.md)[11.2.4](mac_codes.md).
-   `u8NwkStatus`is one of the status codes from the NWK layer, detailed in [Section 11.2.3](nwk_codes.md).

**Parent topic:**[Event structures](../topics/event_structures.md)

