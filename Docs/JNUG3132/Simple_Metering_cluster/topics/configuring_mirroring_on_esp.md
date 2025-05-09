# Configuring Mirroring on ESP

The ESP normally acts as the mirroring server, containing a unique mirror endpoint for each \(mirrored\) Metering Device. Configuration of the mirroring server is carried out both within the application that runs on the device and as compile-time options - refer to [Section 42.12](compile-time_options.md#id_25334628-dcfd-426f-af0c-8d34a10f08a1) for the relevant compile-time options.

On the ESP, mirroring can be enabled in the application code when the device is registered using the function **eSE\_RegisterEspMeterEndPoint\(\)** or **eSE\_RegisterEspEndPoint\(\)**. These functions require specification of the first endpoint that is to be used for mirroring. Starting at this endpoint, consecutive endpoints to be used for mirrors are reserved, up to the maximum number of mirrors defined by the compile-time option `CLD_SM_NUMBER_OF_MIRRORS`. For example, if 5 is specified as the first mirror endpoint and up to 4 mirrors can be used then endpoints 5, 6, 7 and 8 are reserved for mirrors. Note that mirroring is disabled by setting the start endpoint to 0.

**Note:** The endpoints reserved for mirroring must also be included in the configuration diagram in the ZPS Configuration Editor. However, they must not be enabled since they are enabled when mirrors are created on them.

The `tsSE_Mirror`         structures in the ESP device structure `tsSE_EspMeterDevice` contain the IEEE addresses of the Metering Devices being mirrored on the ESP \(these IEEE addresses are automatically initialised to zero\). The ESP application must save an array of these IEEE addresses to non-volatile memory using the NVM module - this will allow the mirrored Metering Devices to be identified by the mirroring server following a reset of the ESP.

The ESP must allocate mirror endpoints to Metering Devices in response to requests from the Metering Devices \(refer to [Section 42.5.2](configuring_mirroring_on_metering_devices.md#id_d9bbf7f7-4ef8-4c32-9fd8-a21e6fe6bcdc) for details of requesting a mirror\), as described below:

1. On receiving a mirror request on the ESP, the ZCL automatically allocates the next available mirror endpoint to the Metering Device \(the IEEE address of the Metering Device is automatically written to the `tsSE_Mirror`         structure which corresponds to the allocated mirror endpoint\).

2. The event E\_CLD\_SM\_CLIENT\_RECEIVED\_COMMAND containing the command E\_CLD\_SM\_REQUEST\_MIRROR is then generated on the ESP, causing the callback function on the ESP to be invoked.

3. The callback function must check whether all mirror endpoints have now been exhausted, in order to update the relevant status on the ESP. To do this, the function **eSM\_GetFreeMirrorEndPoint\(\)** must be called to obtain the number of the next free mirror endpoint. If the value 0xFFFF is returned, this means that no more mirror endpoints are available \(for subsequent requests\) and the attribute `u8PhysicalEnvironment` of the Basic cluster must be set to zero \(to indicate to other Metering Devices that no more mirrors are available on the ESP\). This step is illustrated in the code fragment below.

```
eSM_GetFreeMirrorEndPoint (&u16FoundEP);
if (u16FoundEP == 0xFFFF)
{
           psSE_EspMeterDevice->sBasicCluster.u8PhysicalEnvironment = 0x00;
}
else
{
           psSE_EspMeterDevice->sBasicCluster.u8PhysicalEnvironment = 0x01;
}

```

4. The callback function must copy the IEEE addresses from the `tsSE_Mirror`         structures \(which are automatically kept up-to-date\) to the application’s array of IEEE addresses for mirrored devices, and this array should be re-saved in non-volatile memory using the NVM module. This step is illustrated below in the code fragment under "[Writing and Preserving Array of IEEE Addresses](#id_1fd8cd4d-cf13-4c2b-a3ef-7cb535ea8dba)".

5. A response is automatically sent to the requesting Metering Device, where this response contains the number of the assigned endpoint.

The ESP is then ready to receive metering data from the remote Metering Device, as described in [Section 42.5.3](mirroring_data.md#id_5c81e91a-7d4a-4e82-8247-d180d955c57a).

## Writing and Preserving Array of IEEE Addresses 

The ESP application must maintain an array of the IEEE addresses of the mirrored Metering Devices and keep a copy of this array in NVM. The array can be updated from the `tsSE_Mirror`         structures for the mirror endpoints and saved to NVM as illustrated in the code fragment below:

```
case E_UPDATE_EVENT_REQUEST_MIRROR:
case E_UPDATE_EVENT_REMOVE_MIRROR:
{
  uint8 u8LoopCntr;
  for (u8LoopCntr =0; u8LoopCntr < CLD_SM_NUMBER_OF_MIRRORS; u8LoopCntr++)
      {
        sMirrorState.u64ExtAddr[u8LoopCntr] =  
                     sMeter.sSE_Mirrors[u8LoopCntr].u64SourceAddress;
      }
      sMirrorState.bNetworkUp = TRUE;
     NvSaveOnIdle(&sMirrorState, TRUE);
}
break;

```

## Recreating Mirrors Following an ESP Reset 

If the ESP is reset, the mirrors that have been created on the device are lost. However, if the IEEE addresses \(of the mirrored Metering Devices\) associated with the mirror endpoints have been preserved in NVM, this data can be read by the ESP application following the reset and the mirrors recreated. Given the relevant endpoint number and IEEE address, a mirror can be recreated using the function **eSM\_CreateMirror\(\)**.

**Note:** A matching function **eSM\_RemoveMirror\(\)**also exists to allow the application to remove a mirror.

**Parent topic:**[Mirroring Metering Data](../../Simple_Metering_cluster/topics/mirroring_metering_data.md)

