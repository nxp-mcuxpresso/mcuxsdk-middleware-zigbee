# End Device

Each End Device entry contains a name and a number of associated parameters, mainly related to the APS and NWK layers of the ZigBee PRO stack. The child entries for an End Device include the following:

-   Endpoint entries, one for each endpoint on the End Device, with each endpoint having child entries specifying the input and output clusters used \(note that each input cluster must be paired with an APDU\).
-   PDU Manager, with child entries specifying the APDUs used.
-   Channel Mask, specifying the 2.4-GHz band channels to scan when attempting to join a network.
-   Node Descriptor for the End Device.
-   Node Power Descriptor for the End Device.

**Parent topic:**[Overview of ZPS Configuration Editor Interface](../topics/overview_of_zps_configuration_editor_interface.md)

