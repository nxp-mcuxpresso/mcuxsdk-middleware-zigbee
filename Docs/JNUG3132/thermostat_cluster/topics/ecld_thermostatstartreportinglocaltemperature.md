# eCLD\_ThermostatStartReportingLocalTemperature

```
teZCL_Status eCLD_ThermostatStartReportingLocalTemperature(
    uint8 u8SourceEndPointId,
    uint8 u8DstEndPointId,
    uint64 u64DstAddr,
    uint16 u16MinReportInterval,
    uint16 u16MaxReportInterval,
    int16 i16ReportableChange);

```

## Description 

This function can be used on a Thermostat cluster server to start automatic reporting of the measured local temperature to a cluster client. The change to be reported can be configured through this function. Reports is sent regularly \(but not periodically\), within the specified maximum and minimum time-intervals between consecutive reports.

## Parameters 

-   *u8SourceEndPointId*        Number of the local endpoint on which the Thermostat cluster server resides
-   *u8DstEndPointId*        Number of the endpoint to which reports are to be sent on the destination node
-   *u64DstAddr*                IEEE/MAC address of destination node
-   *u16MinReportInterval*                Minimum time-interval, in seconds, between reports
-   *u16MaxReportInterval*                Maximum time-interval, in seconds, between reports
-   *i16ReportableChange*                Specifies the change to be reported

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND

**Parent topic:**[Functions](../../thermostat_cluster/topics/functions.md)

