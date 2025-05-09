# Execution Commands from Client to Server

An ‘execution’ command can be sent from the client to request that an operation is performed on the appliance \(server\) - the request is sent in an ‘Execution of Command’ message. The application on the client can send this message by calling the function **eCLD\_ACExecutionOfCommandSend\(\)**.

The possible operations depend on the target appliance but the following operations are available to be specified in the message payload \(described in [Section 45.9.2](tscld_ac_executionofcommandpayload.md#id_dd9eab9f-773f-4836-aa62-b17497b01b1b)\):

-   Start appliance cycle

-   Stop appliance cycle

-   Pause appliance cycle

-   Start superfreezing cycle

-   Stop superfreezing cycle

-   Start supercooling cycle

-   Stop supercooling cycle

-   Disable gas

-   Enable gas


In the start and stop commands, the start-time and end-time can be specified. The commands are fully detailed in the British Standards document BS EN 50523.

The application on the server \(appliance\) will be notified of the received command by an E\_CLD\_APPLIANCE\_CONTROL\_CMD\_EXECUTION\_OF\_COMMAND event \(Appliance Control events are described in [Section 45.5](appliance_control_events.md#id_cce61421-45c7-4b54-b2ab-fc056f1d6dfa)\). The required command is specified in the payload of the message, which is contained in the above event. The application must then perform the requested command \(if possible\).

**Parent topic:**[Sending commands](../../appliance_control_cluster/topics/sending_commands.md)

