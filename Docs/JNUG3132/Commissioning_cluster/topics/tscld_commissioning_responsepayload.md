# tsCLD\_Commissioning\_ResponsePayload

The following structure contains the payload of the responses to the following commands: Save Start-up Parameters, Restore Start-up Parameters and Reset Start-up Parameters.

```
typedef struct
{
    zenum8                  u8Status;
} tsCLD_Commissioning_ResponsePayload; 

```

where `u8Status` contains one of the ZCL command status codes listed and described in [Section 7.1.4](../../ZCL_enums_codes/topics/command_status_tezcl_commandstatus.md#id_6d04a321-4eed-4358-989a-b7a0c5505832).

**Parent topic:**[Structures](../../Commissioning_cluster/topics/structures.md)

