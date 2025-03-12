# OTA upgrade operation
This section describes the OTA upgrade operation for K32W148-EVK, FRDM-MCXW71, or MCX-W72-EVK boards.
For information about the over-the-air upgrade process for RW612 platforms, refer to the section, [Zigbee Over The Air Upgrade (OTA) for RW612 platforms](https://bitbucket.sw.nxp.com/projects/CONNINT/repos/zigbee_public/browse/platform/RW612/docs/README.md#over-the-air-upgrade-ota).<br>

To add an image to the coordinator, the OTA images must be programmed. To program the OTA images, perform the following steps:

1.  Use the J-Link utility.
2.  Download `J-Link` from [J-Link / J-Trace Downloads](https://www.segger.com/downloads/jlink).
3.  Plug the K32W148-EVK, FRDM-MCXW71, or the MCX-W72-EVK board to the USB port \(no need to keep the **SW4** button pressed while doing this step\).
4.  Create a `commands_script` file with the following content \(change the application name as necessary\):

    ```
    Reset
    Halt
    LoadBin <OTA_ADDRESS> 0x7A000
    Reset
    Go
    Quit
    ```

    Where `OTA_ADDRESS` value:

    -   for K32W1/FRDM-MCXW71 OTA\_ADDRESS = 0x7A000
    -   for MCX-W72-EVK OTA\_ADDRESS = 0xFA000
    **Note:** If J-Link fails to recognize the `.ota` file, rename it to `.bin` and retry.

5.  Copy the application and `commands_script` in the same folder where the J-Link executable is placed.
6.  Run the following code:

    ```
    JLink.exe/JLinkExe (linux) -<DEVICE_NAME> -if SWD -speed 4000 -autoconnect 1 -CommanderScript commands_script
    ```

    Where `DEVICE_NAME` can be:

    -   K32W1480 for K32W1
    -   MCXW716 for MCXW71
    -   MCXW727C\_CORE0 for MCXW72

When adding an image to a non-factory new coordinator, care must be taken not to use the Erase command to erase the flash.

Any devices with OTA clients in the network periodically send match descriptor requests to find an OTA server. Once a server responds, it then sends an IEEE address request to confirm the address details. The clients then periodically send OTA Image Requests to determine whether the server is hosting an image for that client device. In response to the Image Request, the server returns details of the image that it currently hosts: Manufacturer code, Image tag, and Version number. The client checks these credentials and decides whether it requires this image. If it does not, it queries the server again at the next query interval. If the client does require the image, it starts to issue Block Requests to the server to get the new image. Once all blocks of the new image have been requested and received, the new image is verified. The older image is invalidated, the device reboots, and runs the new image. The client resumes periodically querying the server for new images.

The End Device, which is RX Off, is allowed to enter Sleep mode. It stays awake for 5 seconds and then sleeps for 1 second when not performing "Finding and Binding".

**Parent topic:**[ZigBee over-the-air upgrade](../topics/zigbee_over-the-air_ota_upgrade.md)

