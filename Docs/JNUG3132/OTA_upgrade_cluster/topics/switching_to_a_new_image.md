# Switching to a new image

After an image is programmed into flash and validated as a correct image to switch to, the following steps should then be performed. These are already done as part of the OTA cluster. However, for custom applications not using the OTA cluster, it would be a requirement to switch and run a new image.

```
    /* Offset in bytes into flash for the new image. In this example, new image is at 288K boundary*/
   u32Offset = 0x48000; 
    /* Set the active image location */
    psector_SetEscoreImageData(u32Offset, 0);
    /* Disable any interrupts during the switching of the images */
    __disable_irq();
    /* Remap the vector table to point to the ROM instead of the application */
    SYSCON->MEMORYREMAP &= ~(SYSCON_MEMORYREMAP_MAP_MASK << SYSCON_MEMORYREMAP_MAP_SHIFT);
    /* Prevent entering into Low Power Mode when we reset */
    PMC->CTRL &= ~(PMC_CTRL_LPMODE_MASK << PMC_CTRL_LPMODE_SHIFT);
    /* Initiate reset */
    NVIC_SystemReset();

```

**Parent topic:**[OTA Configuration for Internal Flash](../../OTA_upgrade_cluster/topics/ota_configuration_for_internal_flash.md)

