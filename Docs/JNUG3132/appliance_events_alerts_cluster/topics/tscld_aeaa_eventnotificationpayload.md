# tsCLD\_AEAA\_EventNotificationPayload

This structure contains the payload for an ‘Event Notification’ message.

```
typedef struct
{
   zuint8           u8EventHeader;
   zuint8           u8EventIdentification;
} tsCLD_AEAA_EventNotificationPayload;

```

where:

-   `u8EventHeader` is reserved and set to 0

-   `u8EventIdentification` is the identifier of the event being notified:

    -   0x01: End of operational cycle reached

    -   0x02: Reserved

    -   0x03: Reserved

    -   0x04: Target temperature reached

    -   0x05: End of cooking process reached

    -   0x06: Switching off

    -   0xF7: Wrong data

        -   \(Values 0x00 to 0x3F are standardised, 0x40 to 0x7F are non-standardised, and 0x80 to 0xFF except 0xF7 are proprietary\)

**Parent topic:**[Structures](../../appliance_events_alerts_cluster/topics/structures.md)

