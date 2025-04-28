# Appendix D: storing applications in device flash memory

During start-up, the device bootloader \(provided in internal ROM\) searches for a valid application image in internal Flash memory. If it is present, then the device boots directly from Flash memory. If no image is found, the bootloader drops into In System Programming \(ISP\) mode.

