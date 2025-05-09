# Appendix E.2: Adding Manufacturer-specific Commands

To add a manufacturer-specific command to a cluster:

1. Ensure that a manufacturer ID code has been specified, as described in [Appendix E.1](adding_manufacturer-specific_attributes.md#id_fb922ac1-c20d-4b83-a453-528cc2b96268).

2. In the **zcl\_options.h** file, define a Command ID for the new command \(you must not use a value already used by another command\) - for example, to add a command with an ID of 0x20 to the Basic cluster, the relevant line is: 

    ```
    #define E_CLD_BASIC_CMD_MANU_SPEC 0x20

    ```

3. In your application code, introduce a handling routine for the new command into the command handler function that is registered when the cluster instance is created - for example, in the case of the Basic cluster, this handler function is **eCLD\_BasicCommandHandler\(\)**, which is registered when the function **eCLD\_BasicCreateBasic\(\)** is called. Do this as follows:

    a\) Define a handler routine specifically for the new command - for example, in the case of the Basic cluster, this function may be **eCLD\_BasicHandleManuSpecCommand\(\)** and has the prototype:
    
    ```teZCL_Status eCLD_BasicHandleManuSpecCommand(
        ZPS_tsAfEvent            *pZPSevent,
        tsZCL_EndPointDefinition *psEndPointDefinition,
        tsZCL_ClusterInstance    *psClusterInstance);
    ```

    b\) Add the Command ID and the above command-specific handler function into the registered command handler function - for example, in the case of the Basic cluster, the code for **eCLD\_BasicCommandHandler\(\)** would be modified as shown in the fragment below:

        PUBLIC teZCL_Status eCLD_BasicCommandHandler(
        ZPS_tsAfEvent *pZPSevent,
        tsZCL_EndPointDefinition *psEndPointDefinition,
        tsZCL_ClusterInstance *psClusterInstance)
    {...
        // SERVER
    switch(u8CommandIdentifier)
    {
    case(E_CLD_BASIC_CMD_RESET_TO_FACTORY_DEFAULTS):
    {
    eCLD_BasicHandleResetToFactoryDefaultsCommand(pZPSevent, psEndPointDefinition, psClusterInstance);
    break;
    }
    case(E_CLD_BASIC_CMD_MANU_SPEC):
    eCLD_BasicHandleManuSpecCommand(pZPSevent, psEndPointDefinition, psClusterInstance);
    break;
    default:
    {
    // unlock
    eZCL_ReleaseMutex(psEndPointDefinition);
    return(E_ZCL_FAIL);
    break;
    }
    }
    ...
}
 ```
    

4. Add a command payload structure for the new command into the source (**.c**) file for the cluster - for example:

```
typedef struct
{
    uint8  u8PayloadField1;    
    uint16 u16PayloadField2;
    uint16 u16PayloadField3;
    uint32 u32PayloadField4;    
}tsMS_ManuSpecCommand;

```

5. Add a function for sending the command to a remote node into the header (**.h**) and source (**.c**) files for the cluster - for example, in the case of the Basic cluster, the function might be:

```
PUBLIC teZCL_Status eCLD_BasicCommandManuSpecSend(
                    uint8 u8SourceEndpoint,
                    uint8 u8DestinationEndpoint,
                    tsZCL_Address *psDestinationAddress,
                    tsMS_ManuSpecCommand *psManuSpecPayload,
              uint8 *pu8TransactionSequenceNumber)
{
        teZCL_Status eZCL_Status;
      tsZCL_TxPayloadItem asPayloadDefinition[] = 
      {  
        {1, E_ZCL_UINT8,  &psManuSpecPayload->u8PayloadField1},
        {1, E_ZCL_UINT16, &psManuSpecPayload->u16PayloadField2},
        {1, E_ZCL_UINT16, &psManuSpecPayload->u16PayloadField3},
        {1, E_ZCL_UINT32, &psManuSpecPayload->u32PayloadField4}
      };
      eZCL_Status = eZCL_CustomCommandSend(u8SourceEndpoint,
                  u8DestinationEndpoint, 
                  psDestinationAddress, 
                  GENERAL_CLUSTER_ID_BASIC,               
                  TRUE, 
                  E_CLD_BASIC_CMD_MANU_SPEC, 
                  pu8TransactionSequenceNumber,
                  asPayloadDefinition, 
                  TRUE, 
                  HA_MANUFACTURER_CODE,
                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem));
    return eZCL_Status;
}

```

**Parent topic:**[Appendix E: Manufacturer-specific attributes and commands](../../appendix/topics/manufacturer-specific_attributes_and_commands.md)

