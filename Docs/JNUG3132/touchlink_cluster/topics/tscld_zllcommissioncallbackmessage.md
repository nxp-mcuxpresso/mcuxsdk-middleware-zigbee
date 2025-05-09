# tsCLD\_ZllCommissionCallBackMessage

This structure contains the command ID and payload for a received Touchlink command.

```
typedef struct
{
    uint8   u8CommandId;
    union
    {
        tsCLD_ZllCommission_ScanReqCommandPayload                   
                                    *psScanReqPayload;
        tsCLD_ZllCommission_ScanRspCommandPayload                   
                                    *psScanRspPayload;
        tsCLD_ZllCommission_IdentifyReqCommandPayload               
                                    *psIdentifyReqPayload;
        tsCLD_ZllCommission_DeviceInfoReqCommandPayload             
                                    *psDeviceInfoReqPayload;
        tsCLD_ZllCommission_DeviceInfoRspCommandPayload             
                                    *psDeviceInfoRspPayload;
        tsCLD_ZllCommission_FactoryResetReqCommandPayload           
                                    *psFactoryResetPayload;
        tsCLD_ZllCommission_NetworkStartReqCommandPayload           
                                    *psNwkStartReqPayload;
        tsCLD_ZllCommission_NetworkStartRspCommandPayload           
                                    *psNwkStartRspPayload;
        tsCLD_ZllCommission_NetworkJoinRouterReqCommandPayload      
                                    *psNwkJoinRouterReqPayload;
        tsCLD_ZllCommission_NetworkJoinRouterRspCommandPayload      
                                    *psNwkJoinRouterRspPayload;
        tsCLD_ZllCommission_NetworkJoinEndDeviceReqCommandPayload   
                                    *psNwkJoinEndDeviceReqPayload;
        tsCLD_ZllCommission_NetworkJoinEndDeviceRspCommandPayload   
                                    *psNwkJoinEndDeviceRspPayload;
        tsCLD_ZllCommission_NetworkUpdateReqCommandPayload          
                                    *psNwkUpdateReqPayload;
    } uMessage;
} tsCLD_ZllCommissionCallBackMessage;

```

where:

-   `u8CommandId` is the command ID - enumerations are provided, as detailed in [Section 44.6.1](touchlink_command_events.md#id_9ffb3bb1-010d-459b-8d49-cea000a973b1).

-   `uMessage` contains the payload of the command, where the structure used depends on the command ID \(the structures are detailed in the sections below\).


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

