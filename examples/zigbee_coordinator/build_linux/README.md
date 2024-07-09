
# 1. General description

<p>The purpose of this demo is to demonstrate the capabilities of the K32W1480 SoC when used as a Zigbee NCP together with a Zigbee Coordinator application running on the iMX8 (or x86) platform under Linux. </p>

<p>The demo showcases how to connect a Zigbee End Device to the network formed by the Zigbee Coordinator and toggle the RGB LED available on the device. </p>

<p>A step-by-step guide to the hardware and software configurations are provided, as well as the steps needed to be executed in order to get the boards up and running.</p>

# 2. Required Hardware

* 1 x iMX8M-EVK board running Linux - Host 

* 1 x K32W148-EVK board – Zigbee NCP 

* 1 x K32W061 DK6 board - Zigbee End Device 

## 2.1. iMX8 board configuration 

Ensure that SW801 on the IMX8 EVK board is configured for SD card boot.
For more information see the following starting guide for IMX8M EVK board: https://www.nxp.com/document/guide/getting-started-with-the-i-mx-8m-plus-evk:GS-iMX-8M-Plus-EVK

## 2.2. K32W1480 board configuration (Zigbee NCP)

<p>For the detailed board configuration, see the “Getting Started with MCUXpresso SDK for K32W148-EVK.pdf” guide, part of the K32W148 SDK </p>
<p>Ensure that the debug firmware on the board is J-Link. If this is not the case, follow the steps in chapter 7 of the aforementioned document to update the firmware accordingly</p>
The board should be updated with the binary image `k32w148evk1_zigbee_coprocessor_bm.axf`, image which contains the Zigbee NCP and is provided as a Zigbee application part of the K32W148 SDK
<p>This board is connected to the iMX8M board using a standard micro USB cable that’s also used for power delivery to the board</p>

## 2.3. K32W061 board configuration (ZED RX ON)

<p>For the detailed board configuration see the “Getting Started with MCUXpresso SDK for K32W061.pdf” guide, part of the K32W061 SDK</p>

# 3. Building

<p>The building process has small differences depending on the host (iMX8 or x86) on which the Zigbee Coordinator application is running on. For the x86 platform it allows 
for user configurable options in terms of MCUXPRESSO SDK package and Mbedtls package. The Mbedtls package is required for the encryption/decryption capabilities needed to 
obtain a secured Serial Link.</p>

## 3.1. iMX8 platform 

Create a directory `out` under the `build_linux` directory and issue the cmake command with the `MACHINE=imx8` option. The mbedtls package is preinstalled in the provided 
Board Support Package (BSP).

The user has the option to cross-compile the Coordinator application under x86 Linux distribution. The toolchain to be used should be provided through the `ARMGCC_DIR` 
environment variable.

```
>$ cd out ; cmake .. -DMACHINE=imx8 
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Using Zigbee root path /home/zb-linux-coord/zigbee/
-- Using preinstalled MbedTLS package
CMake Warning at CMakeLists.txt:277 (message):
  Compiling for x86


-- Configuring done
-- Generating done
-- Build files have been written to: /home/zb-linux-coord/zigbee/examples/zigbee_coordinator/build_linux/out 
```
Issue the command `make` to execute the newly generated Makefile.

```
>[b06830_local@fsr-ub1864-125 out]$ make 

[  0%] Building C object CMakeFiles/pdum_static.dir/home/zb-linux-coord/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum.c.o
[  1%] Building C object CCMakeFiles/pdum_static.dir/home/zb-linux-coord/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum_apl.c.o
[  2%] Building C object CMakeFiles/pdum_static.dir/home/zb-linux-coord/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum_dbg.c.o
[  3%] Building C object CMakeFiles/pdum_static.dir/home/zb-linux-coord/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum_nwk.c.o
[  4%] Linking C static library pdum/lib/libpdum.a
[  4%] Built target pdum_static
[  5%] Building C object CMakeFiles/zb_coord_linux.dir/home/zb-linux-coord/zigbee/examples/zigbee_coordinator/zigbee/examples/zigbee_coordinator/src/linux/pdum_gen_glue.c.o
[  6%] Building C object CMakeFiles/zb_coord_linux.dir/home/zb-linux-coord/zigbee/examples/zigbee_coordinator/zigbee/examples/zigbee_coordinator/src/app_coordinator_ncp.c.o
. . .
[ 99%] Building C object CMakeFiles/zb_coord_linux.dir/home/zb-linux-coord/zigbee/examples/zigbee_coordinator/zigbee/ZCL/Clusters/OTA/Source/OTA.c.o
[100%] Linking C executable zb_coord_linux
[100%] Built target zb_coord_linux
```

## 3.2. x86 platform 

The Zigbee Coordinator demo application was compiled and verified on a x86 Linux distribution (Ubuntu 22.04.2 LTS). The CMakeFile of the application determines as a prebuild step
if the application was provided as part of a MCUXPRESSO SDK package or as standalone Zigbee module. Depending on the SDK package existence, the Mbedtls can be used either from within the SDK package, as a preinstalled package or it can be obtained from official git repository (version 2.28.0). 

### Environment Setup

For the x86 platform, the user can provide a MCUXPRESSO SDK path and a method to obtain the Mbedtls package through environment variables:
-   `export NXP_SDK_BASE=/home/mcu-sdk-2.0/` - example on how to provide MCUXPRESSO SDK path
-   `export MBEDTLS_ORIGIN=SDK` - Mbedtls package is obtained from MCUXPRESSO SDK 
-   `export MBEDTLS_ORIGIN=GIT` - Mbedtls package is retrieved from git official repository
-   `export MBEDTLS_ORIGIN=SYSTEM` - Mbedtls package is used as a preinstalled package

### MCUXPRESSO SDK package

Create a directory `out` under the `build_linux` directory and issue the cmake command. The output will showcase the MCUXPRESSO SDK location and the mbedtls usage from within the SDK package.

```
>$ cd out ; cmake ..
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found MCUXPRESSO SDK internal
-- Using SDK root path /home/mcu-sdk-2.0
-- Using Zigbee root path /home/mcu-sdk-2.0/middleware/wireless/zigbee
-- Using mbedtls from SDK
-- Build mbedtls from SDK source code
CMake Warning at CMakeLists.txt:277 (message):
  Compiling for x86


-- Configuring done
-- Generating done
-- Build files have been written to: /home/mcu-sdk-2.0/middleware/wireless/zigbee/examples/zigbee_coordinator/build_linux/out 
```

Issue the command `make` to execute the newly generated Makefile.

```
>[b06830_local@fsr-ub1864-125 out]$ make 

[  1%] Building C object CMakeFiles/pdum_static.dir/home/mcu-sdk-2.0/middleware/wireless/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum.c.o
[  1%] Building C object CMakeFiles/pdum_static.dir/home/mcu-sdk-2.0/middleware/wireless/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum_apl.c.o
[  2%] Building C object CMakeFiles/pdum_static.dir/home/mcu-sdk-2.0/middleware/wireless/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum_dbg.c.o
[  2%] Building C object CMakeFiles/pdum_static.dir/home/mcu-sdk-2.0/middleware/wireless/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum_nwk.c.o
[  3%] Linking C static library pdum/lib/libpdum.a
[  3%] Built target pdum_static
[  3%] Building C object mbedtls/library/CMakeFiles/ncp-host-mbedcrypto.dir/aes.c.o
. . .
[ 99%] Building C object CMakeFiles/zb_coord_linux.dir/home/mcu-sdk-2.0/middleware/wireless/zigbee//examples/zigbee_coordinator/zigbee/ZCL/Clusters/OTA/Source/OTA.c.o
[100%] Linking C executable zb_coord_linux
[100%] Built target zb_coord_linux
```

### Standalone Zigbee module

The Zigbee coordinator application can be obtained and compiled as a standalone application, without the presence of a MCUXPRESSO SDK. The mbedtls package is required as a
preinstalled package or can be configured through user environment variables `export MBEDTLS_ORIGIN=GIT` to be obtained from official repository.

Create a directory `out` under the `build_linux` directory and issue the cmake command. 

```
>$ cd out ; cmake ..
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Using Zigbee root path /home/zb-linux-coord/zigbee/
-- Using mbedtls from GIT
-- Clone mbedtls repository
-- Found Python3: /usr/bin/python3.10 (found version "3.10.12") found components: Interpreter
-- Performing Test C_COMPILER_SUPPORTS_WFORMAT_SIGNEDNESS
-- Performing Test C_COMPILER_SUPPORTS_WFORMAT_SIGNEDNESS - Success
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE


-- Configuring done
-- Generating done
-- Build files have been written to: /home/zb-linux-coord/zigbee/examples/zigbee_coordinator/build_linux/out 
```

Issue the command `make` to execute the newly generated Makefile.

```
>[b06830_local@fsr-ub1864-125 out]$ make 

[  0%] Building C object CMakeFiles/pdum_static.dir/home/zb-linux-coord/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum.c.o
[  1%] Building C object CCMakeFiles/pdum_static.dir/home/zb-linux-coord/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum_apl.c.o
[  2%] Building C object CMakeFiles/pdum_static.dir/home/zb-linux-coord/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum_dbg.c.o
[  3%] Building C object CMakeFiles/pdum_static.dir/home/zb-linux-coord/zigbee/platform/NCP_HOST/framework/PDUM/Source/pdum_nwk.c.o
[  4%] Linking C static library pdum/lib/libpdum.a
[  4%] Built target pdum_static
[  5%] Building C object CMakeFiles/zb_coord_linux.dir/home/zb-linux-coord/zigbee/examples/zigbee_coordinator/zigbee/examples/zigbee_coordinator/src/linux/pdum_gen_glue.c.o
[  6%] Building C object CMakeFiles/zb_coord_linux.dir/home/zb-linux-coord/zigbee/examples/zigbee_coordinator/zigbee/examples/zigbee_coordinator/src/app_coordinator_ncp.c.o
. . .
[ 99%] Building C object CMakeFiles/zb_coord_linux.dir/home/zb-linux-coord/zigbee/examples/zigbee_coordinator/zigbee/ZCL/Clusters/OTA/Source/OTA.c.o
[100%] Linking C executable zb_coord_linux
[100%] Built target zb_coord_linux
```

# 4. Running the application

## 4.1. Starting the coordinator

Make sure that the iMX8 board is connected to the K32W148 Zigbee NCP board, as in the picture below. The two boards are connected through a micro USB cable, between the MCU-Link connected on the K32W148 board (marked as such on the silk screen), and the OTG connector on the iMX8 board.

The Linux Zigbee Coordinator allows the user to specify the serial port on which the K32W1480 board is connected. Usually on the iMX8 board, this is /dev/ttyACM0, and this is used in the example below.

```
>root@ubuntu:~ ./zb_coord_linux /dev/ttyACM0 
[0] Created NCP Host Task with pid 653686
[0] MAIN
[0] ZQ: Initialised a queue: Handle=565ec8c4 Length=30 ItemSize=96
[0] ZQ: Initialised a queue: Handle=565ece50 Length=30 ItemSize=4
[0] ZQ: Initialised a queue: Handle=565ece68 Length=35 ItemSize=4
[0] ZQ: Initialised a queue: Handle=565ece38 Length=3 ItemSize=48
[0] ZQ: Initialised a queue: Handle=565f3700 Length=20 ItemSize=4
[0] ZQ: Initialised a queue: Handle=565f3728 Length=38 ItemSize=4
[0] serial Link initialised
[0]
eOTA_NewImageLoaded status = 1
[2] New max process gap 1
[2] Pkt Type 0010 Set New Max Response Time 2
[212] New max process gap 210
[226] Pkt Type 0012 Set New Max Response Time 13
zps_eAplZdoGetDeviceType - hardwired coord
[1178] Recovered Application State 0 On Network 0
zps_eAplZdoGetDeviceType - hardwired coord
>
```

## 4.2. Forming the network

```
[3259] Form
[3259] APP-EVT: Event 8, NodeState=0
zps_eAplZdoGetDeviceType - hardwired coord
zps_eAplZdoGetDeviceType - hardwired coord
[3267] BDB: Forming Centralized Nwk
[3285] Pkt Type 0024 Set New Max Response Time 18
[3285] APP-EVT: Request Nwk Formation 00
[3805] Nwk formation took 538 MS
[3805] BDB: APP_vGenCallback [0 4]
ZPS_vSetTCLockDownOverride
[3805] APP-BDB: NwkFormation Success
[3805] APP-ZDO: Network started Channel = 13
```

## 4.3. Steer the network

```
[5879] Steer
[5879] APP-EVT: Event 6, NodeState=10
[5888] APP-BDB: NwkSteering Success
[5888] APP-EVT: Request Nwk Steering 00
[6765] BDB: APP_vGenCallback [0 9]
[6765] APP-ZDO: New Node 0be0 Has Joined
[7024] BDB: APP_vGenCallback [0 1]
[7024] APP-ZDO: Data Indication Status 00 from 0be0 Src Ep 0 Dst Ep 0 Profile 0000 Cluster 0013
[7101] BDB: APP_vGenCallback [0 14]
[7101] APP-ZDO: Discovery Confirm
```

The APP-ZDO Data Indication message signals that an Zigbee End Device has successfully joined the network and is ready to be controlled. 

## 4.4. Find and Bind

Since the Zigbee End Device in this demo is behaving as a light bulb, we need to bind its On/Off cluster (server) to the Zigbee Coordinator On/Off cluster (client) in order to receive reports and be able to toggle it. This is done based on the BDB Find & Bind procedure, where the Zigbee Coordinator is the initiator and the Zigbee End Device is the target. For the first step we’ll use the `find` command, while the `bind` is going to be automatically done by the Zigbee Coordinator, since the On/Off cluster is the cluster of interest.

To kick off the F&B procedure, the user needs to enter the `find` command (case insensitive) into the Zigbee Coordinator console and the corresponding output:

```
>[187966] Find
>[187966] APP-EVT: Event 7, NodeState=10
>[187984] APP-EVT: Find and Bind initiate 00
>[188125] - for identify cluster
>[188125]
>CallBackBDB[188125] BDB ZCL Event 8
>[188216] Pkt Type 0052 Set New Max Response Time 23
>[188392] BDB: APP_vGenCallback [0 1]
>[188395] APP-BDB: F&B Simple Desc response From 0be0 Profle 0104 Device 0100 Ep 1 Version 1
>[188399] APP-BDB: Check For Binding Cluster 0006
>[188399] Pkt Type 8074 Took 111
>[188399] Pkt Type 8074 Set New Max Response Time 111
>[188414] APP-BDB: Bind Created for cluster 0006
>[188420] Remote Bind Dst addr 0be0, Ieee Dst Addr b1d48a734e2b758c Ieee Src 00158d00031f14c8
>[188433] Sending a remote bind request Status =0
>[188436] APP-BDB: Bind Created for target EndPt 1
>[188448] APP-ZDO: Data Indication Status 00 from 0be0 Src Ep 0 Dst Ep 0 Profile 0000 Cluster 8004
>[188612]
>
```

## 4.5. Toggle commands

The Zigbee End Device is sending periodic reports regarding the state of the light (on/off), as well as reports when there’s a change request state from the initiator. In order to change the state of the light, the user needs to enter the command `toggle` (case insensitive) in the Zigbee Coordinator console, as per the example below: 
 
```
>[239792] Toggle
>[239792] APP-EVT: Event 5, NodeState=10
>[239792] APP-EVT: Send Toggle Cmd 
>[239792] ZCL Attribute Report: Cluster 0006 Attribute 0000 Value 1
```

## 4.6. ZigBee Over-The-Air (OTA) upgrade

<p>Over-The-Air (OTA) Upgrade is the method by which a new firmware image is transferred to a device that is already installed and
running as part of a ZigBee network. Support for the OTA Upgrade cluster as a Server has been included for the Coordinator device.</p>

To add an image to the coordinator, the OTA images must be placed in the `out` directory and must obey the following convention: begin OTA image name with `OTA_Image` and use
a `.bin` file format. For example: OTA_Image_k32w061dk6_zigbee_ed_rx_on_bmClient_UpgradeImagewithOTAHeaderV2_Enc.bin

<p>Example output for a successful OTA transfer:<p>

```
[19539] Pkt Type 0002 Set New Max Response Time 23
[22830] Pkt Type 0002 Set New Max Response Time 29
[145090] Pkt Type 0002 Set New Max Response Time 33
[421207] Pkt Type 0002 Set New Max Response Time 49
[607037] Nwk status Ind addr 0be0 Status 11
[607037] BDB: APP_vGenCallback [0 13]
[607037] APP-ZDO: Network status Indication 11 addr 0be0
Upgrade End Req received from 0be0 status 0...
[1014587] BDB: APP_vGenCallback [0 9]
[1014587] APP-ZDO: New Node 0be0 Has Joined
[1014753] BDB: APP_vGenCallback [0 1]
[1014753] APP-ZDO: Data Indication Status 00 from 0be0 Src Ep 0 Dst Ep 0 Profile 0000 Cluster 0013
[1014841] BDB: APP_vGenCallback [0 14]
[1014841] APP-ZDO: Discovery Confirm
```
