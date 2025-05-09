# tsZCL\_ReportAttributeMirror

This structure contains information relating to a report attribute command:

```
typedef struct
{
    uint8                       u8DestinationEndPoint;
    uint16                      u16ClusterId;
    uint64                      u64RemoteIeeeAddress;
    teZCL_ReportAttributeStatus eStatus;
}tsZCL_ReportAttributeMirror;

```

where:

-   `u8DestinationEndPoint` is the number of target endpoint for the attribute report \(this is the endpoint on which the mirror for the device resides\)

-   `u16ClusterId` is the ID of the cluster for which information is to be mirrored

-   `u64RemoteIeeeAddress` is the IEEE/MAC address of the target device for the attribute report \(which contains the mirror for the device\)

-   `eStatus` indicates the status of the attribute report \(see [Section 7.1.5](../../ZCL_enums_codes/topics/report_attribute_status_tezcl_reportattributestatu.md#id_44dccc85-b6c0-4f34-a7c2-ea58ce81b1e0)\)


**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

