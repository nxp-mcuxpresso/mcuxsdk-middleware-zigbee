
# 1. General description

<p>The purpose of this demo is to demonstrate the capabilities of the K32W1480 SoC when used as a Zigbee NCP together with a Zigbee Coordinator application running on the iMX8 (or x86) platform under Linux. </p>

<p>The demo showcases how to connect a Zigbee End Device to the network formed by the Zigbee Coordinator and toggle the RGB LED available on the device. </p>

<p>A step-by-step guide to the hardware and software configurations are provided, as well as the steps needed to be executed in order to get the boards up and running.</p>

# 2. Building

Create a directoty `out` under the `build_linux` directory and issue the following commands:

>$ cd out ; cmake .. -DMACHINE=imx8 
>-- The C compiler identification is GNU 9.4.0 
>
>-- The CXX compiler identification is GNU 9.4.0 
>
>-- Detecting C compiler ABI info 
>
>-- Detecting C compiler ABI info - done 
>
>-- Check for working C compiler: /usr/bin/cc - skipped 
>
>-- Detecting C compile features 
>
>-- Detecting C compile features - done 
>
>-- Detecting CXX compiler ABI info 
>
>-- Detecting CXX compiler ABI info - done 
>
>-- Check for working CXX compiler: /usr/bin/c++ - skipped 
>
>-- Detecting CXX compile features 
>
>-- Detecting CXX compile features - done 
>
>CMake Warning at CMakeLists.txt:5 (message): 
>
>  Cross-compiling for imx8 
>
> 
>
> 
>
>CMake Warning at CMakeLists.txt:37 (message): 
>
>  Using ZB root path ../../../ 
>
> 
>
> 
>
>-- Configuring done 
>
>-- Generating done 
>
>-- Build files have been written to/home/zb-linux-coord/zigbee/examples/zigbee_coordinator/build_linux/out 
>
>[b06830_local@fsr-ub1864-125 out]$ make 
>
>[  1%] Building C object CMakeFiles/zb_coord_linux.dir/home/zb-linux-coord/zigbee/examples/zigbee_coordinator/zigbee/examples/zigbee_coordinator/src/app_coordinator.c.o 
>
>… 
>
>[ 98%] Building C object CMakeFiles/zb_coord_linux.dir/home/zb-linux-coord/zigbee/examples/zigbee_coordinator/zigbee/ZCL/Clusters/OTA/Source/OTA.c.o 
>
>[100%] Linking C executable zb_coord_linux 
>
>[100%] Built target zb_coord_linux 
>

# 3. Required Hardware

* 1 x iMX8M-EVK board running Linux - Host 

* 1 x K32W148-EVK board – Zigbee NCP 

* 1 x K32W061 DK6 board - Zigbee End Device 

# 4. Running the application

## 4.1. Starting the coordinator

Make sure that the iMX8 board is connected to the K32W148 Zigbee NCP board, as in the picture below. The two boards are connected through a micro USB cable, between the MCU-Link connected on the K32W148 board (marked as such on the silk screen), and the OTG connector on the iMX8 board.

The Linux Zigbee Coordinator allows the user to specify the serial port on which the K32W1480 board is connected. Usually on the iMX8 board, this is /dev/ttyACM0, and this is used in the example below.

>root@ubuntu:~ ./zb_coord_linux /dev/ttyACM0 
>
>[0] MAIN
>
>APP\_vLedInitialise
>
>[2] ZQ: Initialised a queue: Handle=00b10bf0 Length=30 ItemSize=12
>
>[2] ZQ: Initialised a queue: Handle=00b10bb0 Length=30 ItemSize=4
>
>[2] ZQ: Initialised a queue: Handle=00b10bc8 Length=35 ItemSize=4
>
>[2] ZQ: Initialised a queue: Handle=00b110e4 Length=3 ItemSize=64
> 
>[2] u16SizeOfRecord = 1620 u16numberOfBuffers = 7
>
>[2] Allocated 7 buffers in poll
>
>UART\_vInit
>UART\_vRtsStartFlow
>
>[2] ZQ: Initialised a queue: Handle=00b09cc0 Length=20 ItemSize=4
>
>[2] ZQ: Initialised a queue: Handle=00b09ce8 Length=38 ItemSize=4
>
>[2] serial Link initialised
>
>OTA\_ClientInit - not implemented
>
>OTA\_PullImageChunk - not implemented
>
>[2]  
>eOTA\_NewImageLoaded status = 1
>
>APP\_vSetLed 0 0
>
>APP\_vSetLed 1 0
>
>zps\_psAplAibGetAib
>
>ZPS\_bUseInstallCode - SL
>
>ZPS\_psAplDefaultTCAPSLinkKey - SL
>
>ZPS\_psAplDefaultDistributedAPSLinkKey - SL
>
>ZPS\_psAplDefaultDistributedAPSLinkKey - SL
>
>ZPS\_psAplDefaultGlobalAPSLinkKey - SL
>
>ZPS\_psAplDefaultGlobalAPSLinkKey - SL
>
>zps\_eAplZdoGetDeviceType - hardwired coord
>
>[2] Recovered Application State 0 On Network 0
>
>zps\_eAplZdoGetDeviceType - hardwired coord
>
>[3] New max process gap 1
>
## 4.2. Forming the network

>[38956] Form 
>
>[38956] APP-EVT: Event 6, NodeState=0 
>
>zps_eAplZdoGetDeviceType - hardwired coord 
>
>[38960] New max process gap 4 
>
>[38965] Pkt Type 0034 Set New Max Response Time 3 
>
>[38969] Pkt Type 0021 Set New Max Response Time 4 
>
>zps_eAplZdoGetDeviceType - hardwired coord 
>
>[38969] BDB: Forming Centralized Nwk  
>
>[38983] Pkt Type 0024 Set New Max Response Time 14 
>
>[38983] APP-EVT: Request Nwk Formation 00 
>
>[39515] Nwk formation took 546 MS 
>
>[39515] WARNING: Nwk event 8024 Received 13 bytes Handled 2 bytes 
>
>[39515] BDB: APP_vGenCallback [0 4]  
>
>ZPS_vSetTCLockDownOverride 
>
>[39515] APP-BDB: NwkFormation Success  
>
>APP_vSetLed 1 1 
>
>[39515] APP-ZDO: Network started Channel = 13 
>

## 4.3. Steer the network

>[168745] Steer 
>
>[168745] APP-EVT: Event 4, NodeState=4 
>
>[168757] APP-BDB: NwkSteering Success 
>
>[168757] APP-EVT: Request Nwk Steering 00 
>
>[169612] BDB: APP_vGenCallback [0 9]  
>
>[169612] APP-ZDO: New Node f7a2 Has Joined 
>
>[169872] BDB: APP_vGenCallback [0 1]  
>
><font color="red">[169872] APP-ZDO: Data Indication Status 00 from f7a2 Src Ep 0 Dst Ep 0 Profile 0000 Cluster 0013 </font>
>
>[169910] BDB: APP_vGenCallback [0 14]  
>
>[169910] APP-ZDO: Discovery Confirm 
>
>[170350]  
>
>EVT: Unhandled Event 
>
>[171082]  
>
>EVT: Unhandled Event 
>
>[174313]  
>
>EVT: Unhandled Event 
>
>OTA_PullImageChunk - not implemented 
>
The red-line above signals that an Zigbee End Device has successfully joined the network and is ready to be controlled. 

## 4.4. Find and Bind

<p>Since the Zigbee End Device in this demo is behaving as a light bulb, we need to bind its On/Off cluster (server) to the Zigbee Coordinator On/Off cluster (client) in order to receive reports and be able to toggle it. This is done based on the BDB Find & Bind procedure, where the Zigbee Coordinator is the initiator and the Zigbee End Device is the target. For the first step we’ll use the “find” command, while the “bind” is going to be automatically done by the Zigbee Coordinator, since the On/Off cluster is the cluster of interest. </p>

<p>To kick off the F&B procedure, the user needs to enter the “find” command (case insensitive) into the Zigbee Coordinator console and the corresponding output: </p>

>[187966] Find 
>
>[187966] APP-EVT: Event 5, NodeState=4 
>
>[187984] Pkt Type 0007 Set New Max Response Time 17 
>
>[187984] APP-EVT: Find and Bind initiate 00 
>
>[188125] - for identify cluster 
>
>[188125]  
>
>CallBackBDB[188125] BDB ZCL Event 8 
>
>[188216] Identifying stopped 
>
>[188374]  
>
>EVT: Unhandled Event 
>
>[188392] BDB: APP_vGenCallback [0 1]  
>
>[188395] APP-BDB: F&B Simple Desc response From f7a2 Profle 0104 Device 0100 Ep 1 Version 1 
>
>[188399] APP-BDB: Check For Binding Cluster 0006 
>
>[188414] APP-BDB: Bind Created for cluster 0006 
>
>[188420] Remote Bind Dst addr f7a2, Ieee Dst Addr b1d48a734e2b758c Ieee Src 00158d00031f14c8 
>
>[188433] Sending a remote bind request Status =0 
>
>[188436] APP-BDB: Bind Created for target EndPt 1 
>
>[188448] APP-ZDO: Data Indication Status 00 from f7a2 Src Ep 0 Dst Ep 0 Profile 0000 Cluster 8004 
>
>[188612] 
>

## 4.5. Toggle commands

<p>The Zigbee End Device is sending periodic reports regarding the state of the light (on/off), as well as reports when there’s a change request state from the initiator. In order to change the state of the light, the user needs to enter the command “toggle” (case insensitive) in the Zigbee Coordinator console, as per the example below: </p>
 

>[220466] APP-BDB: No Identify Query Response 
>
>[223206] ZCL Attribute Report: Cluster 0006 Attribute 0000 Value 0 
>
>[231466] APP-BDB: No Identify Query Response Stopping F&B 
>
><font color=red>[239792] Toggle </font>
>
>[239792] APP-EVT: Event 3, NodeState=4 
>
>[239792] APP-EVT: Send Toggle Cmd 
>
><font color=blue>[240650] ZCL Attribute Report: Cluster 0006 Attribute 0000 Value 1 </font>
>
>OTA_PullImageChunk - not implemented 
>
>OTA_PullImageChunk - not implemented 
>
>[348304] ZCL Attribute Report: Cluster 0006 Attribute 0000 Value 1 
>
>OTA_PullImageChunk - not implemented 
>
>[410764] ZCL Attribute Report: Cluster 0006 Attribute 0000 Value 1 

