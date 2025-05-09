# Compile-time Options

This section describes the compile-time options that may be configured in the **zcl\_options.h** file of an application that uses the Poll Control cluster.

To enable the Poll Control cluster in the code to be built, it is necessary to add the following line to the file:

```
#define CLD_POLL_CONTROL

```

In addition, to enable the cluster as a client or server, it is also necessary to add one of the following lines to the same file:

```
#define POLL_CONTROL_SERVER
#define POLL_CONTROL_CLIENT

```

The following options can also be configured at compile-time in the **zcl\_options.h** file.

## Optional Server Attributes 

To enable and assign a value \(`t` quarter-seconds\) to the optional Check-in Interval Minimum \(`u32CheckinIntervalMin`\) attribute, add the line:

```
#define CLD_POLL_CONTROL_ATTR_CHECKIN_INTERVAL_MIN t

```

To enable and assign a value \(`t` quarter-seconds\) to the optional Long Poll Interval Minimum \(`u32LongPollIntervalMin`\) attribute, add the line:

```
#define CLD_POLL_CONTROL_ATTR_LONG_POLL_INTERVAL_MIN t

```

To enable and assign a value \(`t` quarter-seconds\) to the optional Fast Poll Timeout Maximum \(`u16FastPollTimeoutMax`\) attribute, add the line:

```
#define CLD_POLL_CONTROL_ATTR_FAST_POLL_TIMEOUT_MAX t

```

**Note:** For further information on the above optional server attributes, refer to [Section 20.2](cluster_structure_and_attributes.md#id_0088cff5-1178-477d-9e66-701a47ef6f9c).

## Global Attributes 

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_POLL_CONTROL_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

## Set Valid Range for ‘Check-in Interval’ 

To set the maximum possible ‘check-in interval’ \(to `t` quarter-seconds\), add the line:

```
#define CLD_POLL_CONTROL_CHECKIN_INTERVAL_MAX t

```

The default value is 7208960.

To set the minimum possible ‘check-in interval’ \(to `t` quarter-seconds\), add the line:

```
#define CLD_POLL_CONTROL_CHECKIN_INTERVAL_MIN t

```

The default value is 0.

This minimum value is only applied if the Check-in Interval Minimum attribute \(`u32CheckinIntervalMin`\) is not enabled.

## Set Valid Range for ‘Fast Poll Timeout’ 

To set the maximum possible ‘fast poll timeout’ \(to `t` quarter-seconds\), add the line:

```
#define CLD_POLL_CONTROL_FAST_POLL_TIMEOUT_MAX t

```

The default value is 65535.

To set the minimum possible ‘fast poll timeout’ \(to `t` quarter-seconds\), add the line:

```
#define CLD_POLL_CONTROL_FAST_POLL_TIMEOUT_MIN t

```

The default value is 1.

This maximum value is only applied if the Fast Poll Timeout Maximum attribute \(`u16FastPollTimeoutMax`\) is not enabled.

## Set Valid Range for ‘Long Poll Interval’ 

To set the maximum possible ‘long poll interval’ \(to `t` quarter-seconds\), add the line:

```
#define CLD_POLL_CONTROL_LONG_POLL_INTERVAL_MAX t

```

The default value is 7208960.

To set the minimum possible ‘long poll interval’ \(to `t` quarter-seconds\), add the line:

```
#define CLD_POLL_CONTROL_LONG_POLL_INTERVAL_MIN t

```

The default value is 4.

This minimum value is only applied if the Long Poll Interval Minimum attribute \(`u32LongPollIntervalMin`\) is not enabled.

## Set Valid Range for ‘Short Poll Interval’ 

To set the maximum possible ‘short poll interval’ \(to `t` quarter-seconds\), add the line:

```
#define CLD_POLL_CONTROL_SHORT_POLL_INTERVAL_MAX t

```

The default value is 65535.

To set the minimum possible ‘short poll interval’ \(to `t` quarter-seconds\), add the line:

```
#define CLD_POLL_CONTROL_SHORT_POLL_INTERVAL_MIN t

```

The default value is 1.

## Optional Commands 

To enable the optional ‘Set Long Poll Interval’ command, add the line:

```
#define CLD_POLL_CONTROL_CMD_SET_LONG_POLL_INTERVAL        

```

To enable the optional ‘Set Short Poll Interval’ command, add the line:

```
#define CLD_POLL_CONTROL_CMD_SET_SHORT_POLL_INTERVAL 
```

## Maximum Number of Clients 

To set the maximum number of clients for a server to `n`, add the line:

```
#define CLD_POLL_CONTROL_NUMBER_OF_MULTIPLE_CLIENTS n

```

This is the maximum number of clients from which the server can handle Check-in Responses. It should be equal to the capacity \(number of entries\) of the binding table created on the server device to accommodate bindings to client devices \(where this size is set in a ZigBee network parameter using the ZPS Configuration Editor\).

## Disable APS Acknowledgments for Bound Transmissions 

To disable APS acknowledgments for bound transmissions from this cluster, add the line:

```
#define CLD_POLL_CONTROL_BOUND_TX_WITH_APS_ACK_DISABLED

```

**Parent topic:**[Poll Control Cluster](../../poll_control_cluster/topics/poll_control_cluster.md)

