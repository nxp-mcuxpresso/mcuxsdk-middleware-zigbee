# tsSM\_Error

This stucture contains the details of an error response \(from cluster server or client\). It is included in the structure `tsSM_CallBackMessage` when an E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND event is generated containing the command E\_CLD\_SM\_SERVER\_ERROR on a client or E\_CLD\_SM\_CLIENT\_ERROR on the server.

```
typedef struct
{
    uint8 u8Endpoint;
    uint8 u8Status;
}tsSM_Error;

```

where

-   `u8Endpoint` is the number of the endpoint from which the error is reported

-   `u8Status` is a value representing the nature of the error


**Parent topic:**[Structures](../../Simple_Metering_cluster/topics/structures.md)

