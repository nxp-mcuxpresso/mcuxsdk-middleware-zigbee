# Resetting Alarms \(from Client\)

A client application can remotely request one alarm or all alarms to be reset:

-   The function **eCLD\_AlarmsCommandResetAlarmCommandSend\(\)** can be used to request an individual alarm to be reset. A Reset Alarm command is sent to the cluster server. On arriving at the destination device, the command causes an E\_CLD\_ALARMS\_CMD\_RESET\_ALARM event to be generated.

-   The function **eCLD\_AlarmsCommandResetAllAlarmsCommandSend\(\)** can be used to request all alarms to be reset. A Reset All Alarms command is sent to the cluster server. On arriving at the destination device, the command causes an E\_CLD\_ALARMS\_CMD\_RESET\_ALL\_ALARMS event to be generated.


On the generation of the above events on the cluster server, the server application can remove the relevant entry or entries from the local Alarms table as described in [Section 17.4.2](#id_8ec8f3f3-1ef3-45d3-b405-f330603d1f5a).

**Note:** The client application can also request that all the entries in an Alarms table are removed by calling **eCLD\_AlarmsCommandResetAlarmLogCommandSend\(\)**. In this case, the entries are automatically deleted by the ZCL on the server.

**Parent topic:**[Alarm Operations](../../Alarms_cluster/topics/alarm_operations.md)

