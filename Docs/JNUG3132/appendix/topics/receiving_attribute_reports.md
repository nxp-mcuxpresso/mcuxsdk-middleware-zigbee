# Appendix B.5: Receiving attribute reports

In order to receive and parse attribute reports from the cluster server, a client must have attribute reporting enabled in its compile-time options \(see [Appendix B.3.1](compile-time_options.md#id_84f10234-23ce-42f7-a567-f5415e76352a)\).

When an attribute report is received from the server, events are generated and the ZCL software performs the following steps:

1. For each attribute in the attribute report, the ZCL generates an E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTE message for the endpoint callback function, which may or may not take action on this message.

2. On completion of the parsing of the attribute response, the ZCL generates a single E\_ZCL\_CBET\_REPORT\_ATTRIBUTES message for the endpoint callback function, which may or may not take action on this message.

Note that:

-   The E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTE event has the same fields as the E\_ZCL\_CBET\_READ\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE event. In the `uMessage` field of the `tsZCL_CallBackEvent` structure \(see [Section 6.2](../../ZCL_structures/topics/event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1)\) for these events, the same structure is used, which is of the type `tsZCL_IndividualAttributesResponse`.         However, the `eAttributeStatus` field is not updated for an attribute report \(only for a ‘read attributes’ response\).

-   The E\_ZCL\_CBET\_REPORT\_ATTRIBUTES event has the same fields as the E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE event.


**Parent topic:**[Appendix B: Attribute reporting](../../appendix/topics/attribute_reporting.md)

