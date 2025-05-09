# Configuration

When initialized, the Poll Control cluster adopts the attribute values that are pre-set in the `tsCLD_PollControl` structure \(see [Section 20.2](cluster_structure_and_attributes.md#id_0088cff5-1178-477d-9e66-701a47ef6f9c)\). For the optional attributes, values can be set in the file **zcl\_options.h** \(see [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed)\).

The mandatory attributes \(and related optional attributes\) are as follows:

-   **Long Poll Interval \(**`**u32LongPollInterval**`**\)**: This is the polling period used in normal poll mode, expressed in quarter-seconds, with a default value of 20 \(5 seconds\). The attribute has a valid range of 4 to 7208960 but a user-defined minimum value for this attribute can be set via the optional ‘long poll interval maximum’ attribute \(`u32LongPollIntervalMin`\). This limit can be used to ensure that the interval is not inadvertently set \(for example, by another device\) to a low value which quickly drains the energy resources of the End Device node. Alternatively, minimum and maximum values can be specified through the compile-time options \(see [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed)\).

-   **Short Poll Interval \(**`**u16ShortPollInterval**`**\)**: This is the polling period used in fast poll mode, expressed in quarter-seconds, with a default value of 2 \(0.5 seconds\). The attribute has a valid range of 1 to 65535. User-defined minimum and maximum values for this attribute can be specified through the compile-time options \(see [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed)\).

-   **Fast Poll Timeout \(**`**u16FastPollTimeout**`**\)**: This is the time-interval for which the server should normally stay in fast poll mode \(unless over-ridden by a client command\), expressed in quarter-seconds, with a default value of 40 \(10 seconds\). It is recommended that this timeout is greater than 7.68 seconds. The valid range of values is 1 to 65535 but a user-defined maximum value for this attribute can be set via the optional ‘fast poll timeout maximum’ attribute \(`u16FastPollTimeoutMax`\). This limit can be used to ensure that the interval is not inadvertently set \(for example, by another device\) to a high value which quickly drains the energy resources of the End Device node. Alternatively, minimum and maximum values can be specified through the compile-time options \(see [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed)\).

-   **Check-in Interval \(**`**u32CheckinInterval**`**\)**: This is the period between the server’s checks of whether a client requires the poll mode to be changed, expressed in quarter-seconds, with a default value of 14400 \(1 hour\). It should be greater than the ‘long poll interval’ \(see above\). Zero is a special value indicating that the Poll Control cluster server is disabled. Otherwise, the valid range of values is 1 to 7208960 but a user-defined minimum value for this attribute can be set via the optional ‘check-in interval minimum’ attribute \(`u32CheckinIntervalMin`\). This limit can be used to ensure that the interval is not inadvertently set to a low value which quickly drains the energy resources of the End Device node. Alternatively, minimum and maximum values can be specified through the compile-time options \(see [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed)\).


The Poll Control cluster server can also be configured by the server application at run-time by writing to the relevant attribute\(s\) using the **eCLD\_PollControlSetAttribute\(\)** function \(which must be called separately for each attribute to be modified\). If used, this function must be called after the cluster has been initialized \(see [Section 20.4.1](initialisation.md#id_6fb4f920-aea8-42a8-bc62-c78e38da024e)\).

Changes to certain attributes can also be initiated remotely from the cluster client \(controller\) using the following functions:

-   **eCLD\_PollControlSetLongPollIntervalSend\(\)**: The client application can use this function to submit a request to set the ‘long poll interval’ attribute on the server to a specified value. This function causes a ‘Set Long Poll Interval’ command to be sent to the relevant End Device. If the new value is acceptable, the cluster server automatically updates the attribute.

-   **eCLD\_PollControlSetShortPollIntervalSend\(\)**: The client application can use this function to submit a request to set the ‘short poll interval’ attribute on the server to a specified value. This function causes a ‘Set Short Poll Interval’ command to be sent to the relevant End Device. If the new value is acceptable, the cluster server automatically updates the attribute.


In both of the above cases, a response is only sent back to the client if the new value is not acceptable, in which case a ZCL ‘default response’ is sent indicating an invalid value.

Use of the above two functions requires the corresponding commands to be enabled in the compile-time options, as described in [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed).

**Note:** Changes to attribute values initiated by either the server application or client application takes effect immediately. So, for example, if the End Device is operating in fast poll mode when the ‘short poll interval’ is modified, the polling period is immediately re-timed to the new value. If the modified attribute is not related to the currently operating poll mode, the change is implemented the next time the relevant poll mode is started.

Before the first scheduled ‘check-in’ \(after one hour, by default\), the End Device application should set up bindings between the local endpoint on which the cluster resides and the relevant endpoint on each remote controller node with which the End Device operates. These bindings are used while sending the ‘Check-in’ commands.

**Parent topic:**[Poll Control Operations](../../poll_control_cluster/topics/poll_control_operations.md)

