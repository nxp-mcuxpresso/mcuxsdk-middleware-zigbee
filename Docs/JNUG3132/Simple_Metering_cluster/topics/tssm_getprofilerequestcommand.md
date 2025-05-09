# tsSM\_GetProfileRequestCommand

This stucture contains the details of a ‘Get Profile’ request \(from a cluster client\). It is included in the structure `tsSM_CallBackMessage` when an E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND event containing the command E\_CLD\_SM\_GET\_PROFILE is generated on the cluster server.

```
typedef struct
{
    teSM_IntervalChannel eIntervalChannel;
    uint8 u8NumberOfPeriods;
    uint8 u8SourceEndPoint;
    uint8 u8DestinationEndPoint;
    uint32 u32EndTime;
    tsZCL_Address sSourceAddress;
}tsSM_GetProfileRequestCommand;

```

where:

-   `eIntervalChannel` is a value indicating the required consumption data:

    -   E\_CLD\_SM\_CONSUMPTION\_RECEIVED - units from customer

    -   E\_CLD\_SM\_CONSUMPTION\_DELIVERED - units to customer

-   `u8NumberOfPeriods` is the number of consumption intervals for which data is being requested

-   `u8SourceEndPoint` is the number of the source endpoint of the request on the client

-   `u8DestinationEndPoint` is the number of the destination endpoint of the request on the server

-   `u32EndTime` is the end-time for which consumption data is being requested - the most recent consumption data will be reported which has an end-time equal to or earlier than this end-time \(a zero value will result in the most recent consumption data\)

-   `sSourceAddress` is a structure containing the source address of the request - that is, the address of the requesting client \(the structure is described in [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\)


**Parent topic:**[Structures](../../Simple_Metering_cluster/topics/structures.md)

