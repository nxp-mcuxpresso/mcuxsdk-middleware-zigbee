# Overview

Support for the OTA upgrade cluster as a client has been included for the Router and End Device.

**Note:** By default, all the devices only support encrypted OTA.

The internal flash memory is used to store the upgraded image by default.

The table below shows that the initial client binaries to be programmed into the K32W1, MCXW71, and MCXW72 devices are version 1 files.


**Version 1 files**
| Hardware platform | Binary files                                                                                                                                                                                                                                                                   |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| K32W148-EVK board | •  `k32w148evk_zigbee_router_bm_v1.axf`<br>•  `k32w148evk_zigbee_ed_rx_on_bm_v1.axf`<br>•  `k32w148evk_zigbee_ed_rx_off_bm_v1.axf`<br>•  `k32w148evk_zigbee_router_freertos_v1.axf`<br>•  `k32w148evk_zigbee_ed_rx_on_freertos_v1.axf`<br>•  `k32w148evk_zigbee_ed_rx_off_freertos_v1.axf` |
| FRDM-MCXW71 board | •  `frdmmcxw71_zigbee_router_bm_v1.axf`<br>•  `frdmmcxw71_zigbee_ed_rx_on_bm_v1.axf`<br>•  `frdmmcxw71_zigbee_ed_rx_off_bm_v1.axf`<br>•  `frdmmcxw71_zigbee_router_freertos_v1.axf`<br>•  `frdmmcxw71_zigbee_ed_rx_on_freertos_v1.axf`<br>•   `frdmmcxw71_zigbee_ed_rx_off_freertos_v1.axf`                                                   |
| MCX-W72-EVK board | •  `mcxw72evk_zigbee_router_freertos_v1.axf`<br>•  `mcxw72evk_zigbee_ed_rx_on_freertos_v1.axf`<br>•  `mcxw72evk_zigbee_ed_rx_off_freertos_v1.axf`
                                                                                                                                                                                                                     
The table below shows that the OTA images are the `V2/V3.ota` files.

**V2/V3 OTA files**
| Hardware platform | OTA files                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| ----------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| K32W148-EVK board | •  `k32w148evk_zigbee_router_bm_v2.ota`<br>•  `k32w148evk_zigbee_router_bm_v3.ota`<br>•  `k32w148evk_zigbee_ed_rx_on_bm_v2.ota`<br>•  `k32w148evk_zigbee_ed_rx_on_bm_v3.ota`<br>•  `k32w148evk_zigbee_ed_rx_off_bm_v2.ota`<br>•  `k32w148evk_zigbee_ed_rx_off_bm_v3.ota`<br>•  `k32w148evk_zigbee_router_freertos_v2.ota`<br>•  `k32w148evk_zigbee_router_freertos_v3.ota`<br>•  `k32w148evk_zigbee_ed_rx_on_freertos_v2.ota`<br>•  `k32w148evk_zigbee_ed_rx_on_freertos_v3.ota`<br>•  `k32w148evk_zigbee_ed_rx_off_freertos_v2.ota`<br>•  `k32w148evk_zigbee_ed_rx_off_freertos_v3.ota`|
| FRDM-MCXW71 board | •  `frdmmcxw71_zigbee_router_bm_v2.ota`<br>•  `frdmmcxw71_zigbee_router_bm_v3.ota`<br>•  `frdmmcxw71_zigbee_ed_rx_on_bm_v2.ota`<br>•  `frdmmcxw71_zigbee_ed_rx_on_bm_v3.ota`<br>•  `frdmmcxw71_zigbee_ed_rx_off_bm_v2.ota`<br>•  `frdmmcxw71_zigbee_ed_rx_off_bm_v3.ota`<br>•  `frdmmcxw71_zigbee_router_freertos_v2.ota`<br>•  `frdmmcxw71_zigbee_router_freertos_v3.ota`<br>•  `frdmmcxw71_zigbee_ed_rx_on_freertos_v2.ota`<br>•  `frdmmcxw71_zigbee_ed_rx_on_freertos_v3.ota`<br>•  `frdmmcxw71_zigbee_ed_rx_off_freertos_v2.ota`<br>•  `frdmmcxw71_zigbee_ed_rx_off_freertos_v3.ota` |
| MCX-W72-EVK board | •  `mcxw72evk_zigbee_router_freertos_v2.ota`<br>•  `mcxw72evk_zigbee_router_freertos_v3.ota`<br>•  `mcxw72evk_zigbee_ed_rx_on_freertos_v2.ota`<br>•  `mcxw72evk_zigbee_ed_rx_on_freertos_v3.ota`<br>•  `mcxw72evk_zigbee_ed_rx_off_freertos_v2.ota`<br>•  `mcxw72evk_zigbee_ed_rx_off_freertos_v3.ota`                                                                                                                                                                                                                                                                       |
**Parent topic:**[ZigBee over-the-air upgrade](../topics/zigbee_over-the-air_ota_upgrade.md)

