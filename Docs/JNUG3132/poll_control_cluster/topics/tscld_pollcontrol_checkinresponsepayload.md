# tsCLD\_PollControl\_CheckinResponsePayload

This structure contains the payload of a ‘Check-in Response’, which is sent from the client to the server in reply to a ‘Check-in’ command from the server.

```
typedef struct
{
  zbool   bStartFastPolling;
  zuint16  u16FastPollTimeout;
}tsCLD_PollControl_CheckinResponsePayload;

```

where:

-   `bStartFastPolling` is a boolean indicating whether or not the End Device is required to enter fast poll mode:

    -   TRUE: Enter fast poll mode

    -   FALSE: Continue in normal poll mode

-   `u16FastPollTimeout` is an optional fast poll mode timeout, in quarter-seconds, in the range 1 to 65535 - that is, the period of time for which the End Device should remain in fast poll mode \(if this mode is requested through `bStartFastPolling`\). Zero is a special value which indicates that the value of the ‘fast poll timeout’ attribute should be used instead \(see [Section 20.2](cluster_structure_and_attributes.md#id_0088cff5-1178-477d-9e66-701a47ef6f9c)\). If a non-zero value is specified then this value over-rides the ‘fast poll timeout’ attribute \(but does not over-write it\).


**Parent topic:**[Structures](../../poll_control_cluster/topics/structures.md)

