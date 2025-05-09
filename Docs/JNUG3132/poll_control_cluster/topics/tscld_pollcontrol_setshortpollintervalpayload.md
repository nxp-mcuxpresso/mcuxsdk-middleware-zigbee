# tsCLD\_PollControl\_SetShortPollIntervalPayload

This structure contains the payload of a ‘Set Short Poll Interval’ command, which is sent from the client to the server to request a new ‘short poll interval’ for use in fast poll mode.

```
typedef struct
{
 zuint16  u16NewShortPollInterval;
}tsCLD_PollControl_SetShortPollIntervalPayload;

```

where `u16NewShortPollInterval` is the required value of the ‘short poll interval’, in quarter-seconds, in the range 1 to 65535. This value is used to over-write the corresponding cluster attribute if the specified value is within the valid range for the attribute \(including greater than or equal to the optional user-defined minimum, if set\).

To use the ‘Set Short Poll Interval’ command, it must be enabled in the compile-time options, as described in [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed).

**Parent topic:**[Structures](../../poll_control_cluster/topics/structures.md)

