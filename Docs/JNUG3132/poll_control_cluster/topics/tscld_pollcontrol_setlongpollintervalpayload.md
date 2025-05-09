# tsCLD\_PollControl\_SetLongPollIntervalPayload

This structure contains the payload of a ‘Set Long Poll Interval’ command, which is sent from the client to the server to request a new ‘long poll interval’ for use in normal poll mode.

```
typedef struct
{
 zuint32  u32NewLongPollInterval;
}tsCLD_PollControl_SetLongPollIntervalPayload;

```

where `u32NewLongPollInterval` is the required value of the ‘long poll interval’, in quarter-seconds, in the range 4 to 7208960. This value is used to over-write the corresponding cluster attribute if the specified value is within the valid range for the attribute \(including greater than or equal to the optional user-defined minimum, if set\).

To use the ‘Set Long Poll Interval’ command, it must be enabled in the compile-time options, as described in [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed).

**Parent topic:**[Structures](../../poll_control_cluster/topics/structures.md)

