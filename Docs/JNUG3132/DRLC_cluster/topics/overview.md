# Overview

The DRLC cluster is required in ZigBee devices as indicated in the table below.

||**Server-side**|**Client-side**|
|---|---------------|---------------|
|**Mandatory in...**|ESP|PCT|
||Load Control Device|
|**Optional in...**||IPD|
||Smart Appliance|

The ESP acts as the DRLC cluster server, since it is the device which receives Load Control Events \(LCEs\) from the utility company via the backhaul network. Other devices act as clients and receive the LCEs forwarded by the ESP:

-   An IPD would normally display a list of LCEs to allow the consumer to manually modify consumption.

-   A Load Control Device, PCT or Smart Appliance would participate in an LCE by automatically adjusting the consumption of the device.


Devices that participate in an LCE must report their participation back to the ESP. Participation may result in the consumer receiving a credit on their utility bill.

**Note:** In the current NXP implementation, the DRLC cluster client is contained within an IPD only. This illustrates how to incorporate the DRLC cluster in other devices which need to participate in LCEs.

The LCEs contain a time-stamp. Therefore, devices which support the DRLC cluster client and which participate in LCEs must implement the Time cluster and maintain a real-time clock.

The DRLC cluster is enabled by defining CLD\_DRLC in the **zcl\_options.h** file. Further compile-time options for the DRLC cluster are detailed in [Section 41.12](compile-time_options.md#id_d99a7a68-c962-4f54-ab8a-35b360dbb023).

**Parent topic:**[Demand-Response and Load Control Cluster](../../DRLC_cluster/topics/demand-response_and_load_control_cluster.md)

