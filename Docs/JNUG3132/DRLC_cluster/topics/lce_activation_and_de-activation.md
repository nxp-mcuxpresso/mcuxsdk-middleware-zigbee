# LCE Activation and De-activation

On receiving a new LCE from the DRLC cluster server, a cluster client first checks the device class and enrollment group specified within the LCE. If they do not match those of the local device \(see DRLC attributes in [Section 41.2](drlc_cluster_structure_and_attributes.md#id_7bc64896-4d9e-47c4-87c2-0bc3e3957607)\), the LCE is discarded.

**Note:** A DRLC cluster client can opt out of an individual LCE using the **eSE\_DRLCSetEventUserOption\(\)** function.

Generally, a valid LCE received from the cluster server is automatically added to the ‘Scheduled’ list on the client - the E\_SE\_DRLC\_EVENT\_COMMAND callback event containing the command SE\_DRLC\_LOAD\_CONTROL\_EVENT is generated on the client to indicate that this has been done. However, if the LCE has a ‘start-time of now’, it is added directly to the ‘Active’ list, provided that the start-time is not randomized \(see below\).

If a new LCE is successfully added to the Scheduled \(or Active\) list, the client sends a Report Event Status message to the server to confirm acceptance of the LCE.

When the start-time of an LCE in the ‘Scheduled’ list is reached, the LCE is automatically moved to the ‘Active’ list. The E\_SE\_DRLC\_EVENT\_ACTIVE callback event is generated on the client to indicate that this has been done, allowing the application to make the required load adjustment. However, if a randomized start-time is enabled \(in the LCE\), the move to the ‘Active’ list is delayed by a random time interval that is no greater than the maximum defined by the cluster attribute `u8StartRandomizeMinutes` \(see [Section 41.2](drlc_cluster_structure_and_attributes.md#id_7bc64896-4d9e-47c4-87c2-0bc3e3957607)\).

When the duration of the active LCE has expired, the LCE is automatically moved to the ‘De-allocated’ list - the E\_SE\_DRLC\_EVENT\_EXPIRED callback event is generated on the client to indicate that this has been done, allowing the application to restore the load to the previous level. However, if a randomized end-time is enabled \(in the LCE\), the move to the ‘Deallocated’ list is delayed by a random time interval that is no greater than the maximum defined by the cluster attribute `u8StopRandomizeMinutes` \(see [Section 41.2](drlc_cluster_structure_and_attributes.md#id_7bc64896-4d9e-47c4-87c2-0bc3e3957607)\).

**Note:** The above randomize attributes of the DRLC cluster also allow LCE start-time and end-time randomization to be disabled for all LCEs on the local device. If this is the case, randomization settings within the LCE itself are ignored.

**Parent topic:**[LCE Handling on Clients](../../DRLC_cluster/topics/lce_handling_on_clients.md)

