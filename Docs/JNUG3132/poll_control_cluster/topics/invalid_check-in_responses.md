# Invalid Check-in Responses

The server may receive Check-in responses which cannot result in fast poll mode. In these cases, the server sends a ZCL default response indicating the relevant error status \(which is not ZCL\_SUCCESS\) back to the originating client. The following circumstances will lead to such a default response:

-   The Check-in response is from an unbound client. In this case, the Default Response will contain the status ACTION\_DENIED.

-   The Check-in response is from a bound client but requests an invalid fast poll timeout value \(see [Section 20.4.3.1](fast_poll_mode_timeout.md#id_fd89a922-c29c-4e0c-b19f-a06ab219cc5a)\). In this case, the default response will contain the status INVALID\_VALUE.

-   The Check-in response is from a bound client but arrives after the timeout period of the original Check-in command. In this case, the default response will contain the status TIMEOUT.


**Parent topic:**[Operation](../../poll_control_cluster/topics/operation.md)

