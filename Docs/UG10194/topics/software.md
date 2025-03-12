# Software

To use the ZigBee examples, install the following software:

-   MCUXpresso Integrated Design Environment \(IDE\)
-   K32W1/MCXW71/MCXW72 ZigBee 3.0 Software Development Kit \(SDK\)
-   Python 3 and lxml module
-   SPSDK version 1.11.0 and crccheck module

    **Note:** Both SPSDK version 1.11.0 and crccheck modules are required to generate OTA images using the NXP ZB OTA tool \(`nxpzbota.py`\).


The MCUXpresso software and installation instructions are described in [Getting Started with the K32W148 Development Platform](https://www.nxp.com/document/guide/getting-started-with-the-k32w148-development-platform:GS-K32W148EVK).

Support for Zigbee packet sniffing is provided by using the `Sniffer_1000000baud_8N1_NoFlowControl` sniffer binary available in the `tools/sniffer` K32W061 SDK. The binary must be flashed on a K32W0 board using either of the following two methods:

-   Using the *Getting Started with MCUXpresso SDK for K32W061* \(document [MCUXSDKK32W061GSUG](https://www.nxp.com/doc/MCUXSDKK32W061GSUG)\). For more information, see the section "Building and Flashing the Application". In this case, the user must also install the K32W061 SDK.
-   Using the firmware loader from NXP Test Tool.

Also, ensure to install the following tools:

-   Kinetis Protocol Analyzer Adapter 2.0.3.1 or newer and Wireshark
-   J-Link software, which can be downloaded from [J-Link / J-Trace Downloads](https://www.segger.com/downloads/jlink)

The wireless microcontroller-specific resources and documentation are available via the [MCUXpresso](https://mcuxpresso.nxp.com/en/welcome) to authorized users.

**Parent topic:**[Development environment](../topics/development_environment.md)

