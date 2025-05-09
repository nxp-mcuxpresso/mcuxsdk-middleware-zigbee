# Custom Data Structure

The IAS ACE cluster requires extra storage space to be allocated to be used by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
    tsZCL_ReceiveEventAddress        sReceiveEventAddress;
    tsZCL_CallBackEvent              sCustomCallBackEvent;
    tsCLD_IASACECallBackMessage      sCallBackMessage;
#if (defined CLD_IASACE) && (defined IASACE_SERVER)
    tsCLD_IASACE_PanelParameter             
                                     sCLD_IASACE_PanelParameter;
    tsCLD_IASACE_ZoneParameter              
           asCLD_IASACE_ZoneParameter[CLD_IASACE_ZONE_TABLE_SIZE];
    tsCLD_IASACE_ZoneTable                  
           asCLD_IASACE_ZoneTable[CLD_IASACE_ZONE_TABLE_SIZE];
#endif
} tsCLD_IASACECustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../IAS_ACE_cluster/topics/structures.md)

