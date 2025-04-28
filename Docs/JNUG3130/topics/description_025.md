# Description

This function can be used on a Router or End Device to configure the **IEEE 802.15.4 MAC** capabilities in the Node descriptor. The MAC capabilities are specified in an 8-bit bitmap, detailed in the table below.

**MAC capabilities bitmap**

|**Bits**|**Description**|
|--------|---------------|
|0|Coordinator capability:<br> 1: Node able to act as Coordinator<br> 0: Node not able to act as Coordinator|
|1|Device type:<br> 1: Full-Function Device \(FFD\)<br> 0: Reduced-Function Device \(RFD\)<br> An FFD can act as any node type while an RFD cannot act as the network Coordinator.|
|2|Power source:<br> 1: Node is mains-powered<br> 0: Node is not mains-powered|
|3|Receiver on when idle:<br> 1: Receiver enabled during idle periods<br> 0: Receiver disabled during idle periods to conserve power|
|4-5|Reserved|
|6|Security capability:<br> 1: High security<br> 0: Standard security|
|7|Allocate address:<br> 1: Network address should be allocated to node<br> 0: Network address need not be allocated to node|

**Parent topic:**[ZPS\_vAplAfSetMacCapability](../topics/zps_vaplafsetmaccapability.md)

