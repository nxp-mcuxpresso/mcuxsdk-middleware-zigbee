# Description

This function requests an update of network parameters related to radio communication. The request can specify any of the following:

-   update the radio channel mask \(for scans\) and the 16-bit network address of the network manager \(node nominated to manage radio-band operation of network\)
-   change the radio channel used
-   scan radio channels and report the results

The request can be broadcast or unicast to nodes with radio receivers that are configured to remain on during idle periods.

The request is represented by the structure below \(further detailed in [Section](zps_tsaplzdpmgmtnwkupdatereq.md)[9.2.2.41](zps_tsaplzdpmgmtnwkupdatereq.md)\).

`typedef struct {`

`uint32 u32ScanChannels;`

`uint8 u8ScanDuration;`

`uint8 u8ScanCount;`

`uint8 u8NwkUpdateId;`

`uint16 u16NwkManagerAddr;`

`} ZPS_tsAplZdpMgmtNwkUpdateReq;`

The specific action to be taken as a result of this request is indicated through the element `u8ScanDuration`, as described in the table below.

|`**u8ScanDuration**` |**Action**|
|--------------------|----------|
|0x00-0x05|Perform radio channel scan on the set of channels specified through `u32ScanChannels`. The time, in seconds, spent scanning each channel is determined by the value of `u8ScanDuration`and the number of scans is equal to the value of `u8ScanCount`. Valid for unicasts only.|
|0x06-0xFD|Reserved|
|0xFE|Change radio channel to single channel specified through `u32ScanChannels`and set the network man- ager address to that specified through `u16NwkManag- erAddr`. Valid for broadcasts only.|
|0xFF|Update the stored radio channel mask with that specified through `u32ScanChannels`\(but do not scan\).<br>Valid for broadcasts only.|

The remote node replies with a Mgmt\_NWK\_Update\_notify notification, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpMgmtNwkUpdateNotify`\(detailed in [Section 9.2.3.41](zps_tsaplzdpmgmtnwkupdatenotify.md)\).

**Parent topic:**[ZPS\_eAplZdpMgmtNwkUpdateRequest](../topics/zps_eaplzdpmgmtnwkupdaterequest.md)

