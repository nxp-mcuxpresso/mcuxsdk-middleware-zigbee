# Raising an Alarm

An alarm is raised when an alarm condition occurs on a cluster on the same endpoint as the Alarms cluster server - for example, when a cluster attribute falls below a lower threshold. The Alarms cluster server should then send an Alarm notification to any remote Alarms cluster clients that might be interested in the alarm. The server application can send this notification and add an entry to the Alarms table by calling the **eCLD\_AlarmsSignalAlarm\(\)** function. On arriving at a destination device, the notification causes an E\_CLD\_ALARMS\_CMD\_ALARM event to be generated to notify the client application.

**Parent topic:**[Alarm Operations](../../Alarms_cluster/topics/alarm_operations.md)

