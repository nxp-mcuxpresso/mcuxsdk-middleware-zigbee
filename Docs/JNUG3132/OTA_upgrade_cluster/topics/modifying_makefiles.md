# Modifying Makefiles

In the makefiles for all applications \(for server and all clients\), replace the following lines:

```
$(OBJCOPY) -j .version -j .bir -j .flashheader -j .vsr_table 
-j .vsr_handlers  -j .rodata -j .text -j .data -j .bss -j .heap 
-j .stack -S -O binary $< $@

```

with:

```
        $(OBJCOPY) -j .version -j .bir -j .flashheader -j .vsr_table 
-j .vsr_handlers -j .ro_mac_address -j .ro_ota_header  -j .rodata 
-j .text -j .data -j .bss -j .heap -j .stack -S -O binary $< $@

```

**Parent topic:**[Build Process](../../OTA_upgrade_cluster/topics/build_process.md)

