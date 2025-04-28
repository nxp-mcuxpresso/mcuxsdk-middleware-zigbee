# Node descriptor

The Node descriptor contains information on the capabilities of the node, including:

-   Type \(End Device, Router or Coordinator\)
-   Frequency band in use \(868 MHz, 902 MHz or 2400 MHz\)
-   IEEE 802.15.4 MAC capabilities - that is, whether:
    -   the device can be a PAN Coordinator
    -   the node implements a Full-Function or Reduced-Function IEEE 802.15.4 device
    -   the device is mains powered
    -   the device is capable of using MAC security
    -   the receiver stays on during idle periods
-   Manufacturer code
-   Stack compliance revision \(of the ZigBee PRO Core specification to which the stack complies - prior to Revision 22/ZigBee2017, these bits were reserved and set to zero\)
-   Maximum buffer size \(the largest data packet that can be sent by an application in one operation\)

**Parent topic:**[Descriptors](../topics/descriptors.md)

