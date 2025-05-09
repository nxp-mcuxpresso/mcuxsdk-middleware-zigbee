# Device Start-up

The ‘current’ set of Start-up Parameter values on a cluster server are those used in the start-up procedure, which can be remotely initiated from a cluster client using the function **eCLD\_CommissioningCommandRestartDeviceSend\(\)**. This function sends a Restart Device command to the remote device hosting the cluster server. This command provides a number of options concerning the timing of the restart:

-   **Without delay:** The start-up procedure is invoked as soon as the command is received. This option requires both the delay and jitter to be specified as zero.

-   **With delay:**The start-up procedure is invoked after a specified delay \(in seconds\). If no delay is required, the delay period must be specified as zero.

-   **With delay and jitter:** The start-up procedure is invoked after a specified delay \(in seconds\) with a random jitter period added. It is necessary to indicate a maximum jitter period but the actual period will be randomly generated. If no jitter is required, the maximum jitter period must be specified as zero.


**Note:** If only jitter is required, the delay period must be specified as zero and the maximum jitter period must be non-zero.

In all of the above cases, it is possible to configure the start-up procedure to begin either without any further delay or at a ‘convenient’ moment \(when there are no pending actions that should be completed before the restart\).

The above options are configured in the command payload \(see [Section 43.9.2](tscld_commissioning_restartdevicepayload.md#id_1df93820-8802-4516-b816-5ad7a67552ec)\).

The cluster server will send a Restart Device Response to the requesting client before invoking the start-up procedure or starting the countdown \(for the delay\).

**Parent topic:**[Commissioning Commands](../../Commissioning_cluster/topics/commissioning_commands.md)

