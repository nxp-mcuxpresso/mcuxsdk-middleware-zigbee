# Timeout on the ‘On’ Command

On receiving an 'On' command, a timeout is applied such that the 'on' state is maintained for a specified duration before automatically switching to the 'off' state. This timeout is defined using the optional attributes `u16OnConfigurableDuration`and `eDurationUnitOfMeasurement`. The timeout duration in seconds is given by:

`u16OnConfigurableDuration` \* 10^\(power from `eDurationUnitOfMeasurement`\)

The attribute `u16OnConfigurableDuration` can be set locally or remotely, while the attribute `eDurationUnitOfMeasurement` must be set locally. A maximum timeout duration can be defined locally via the optional attribute `u16MaxDuration`, which puts an upper limit on the value of `u16OnConfigurableDuration`.

The attribute `u16OnConfigurableDuration` can be set remotely using the **eZCL\_SendWriteAttributesRequest\(\)** function. On receiving this write request, the local ZCL checks that the requested duration is within the permissible range \(see [Section 2.3.3.1](../../ZCL_fundamentals/topics/writing_to_attributes_of_a_remote_cluster.md#id_a5f67377-e001-4080-a5ab-ee4676a2daa5)\) - if the request exceeds the maximum permitted value, the timeout duration is clipped to this maximum.

For full details of the above attributes, refer to [Section 14.2](onoff_cluster_structure_and_attribute.md#id_dca0fc79-dce1-4ecf-b5f1-c7f9aae241ae).

When an ‘On’ command is received, an E\_ZCL\_CBET\_CLUSTER\_CUSTOM event is generated. The application is responsible for implementing the timeout described above, if it is enabled. First, the application must check the attributes `u16OnConfigurableDuration` and `eDurationUnitOfMeasurement` to make sure they have valid values. If so, the application must start a timer to implement the timeout for the duration defined by these attributes. On expiration of the timer, the application must switch from the ‘on’ state to the ‘off’ state by \(locally\) writing to the `bOnOff` attribute.

**Parent topic:**[Switching On and Off](../../OnOff_cluster/topics/switching_on_and_off.md)

