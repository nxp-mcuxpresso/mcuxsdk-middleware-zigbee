# Table of Content

- [Table of Content](#table-of-content)
- [Useful documents](#useful-documents)
- [Building NXP Zigbee examples with CMake](#building-nxp-zigbee-examples-with-cmake)
  - [Python requirements](#python-requirements)
  - [Windows long paths limitation](#windows-long-paths-limitation)
  - [Building](#building)
  - [Current examples supported](#current-examples-supported)

# Useful documents

- [Zigbee Base Device Behavior Specification](https://zigbeealliance.org/wp-content/uploads/2019/12/docs-13-0402-13-00zi-Base-Device-Behavior-Specification-2-1.pdf)
- [JN-UG-3130-Zigbee3-Stack.pdf](./Docs/JN-UG-3130-Zigbee3-Stack.pdf): Provides information related to the ZigBee 3.0 wireless networking protocol and its associated stack for implementation on NXP microcontrollers.
- [JN-UG-3131-ZigBee3-Devices](./Docs/JN-UG-3131-ZigBee3-Devices.pdf): Introduces and provides details of the ZigBee Base Devices.
- [JN-UG-3132-ZigBee3-Cluster-Library](./Docs/JN-UG-3132-ZigBee3-Cluster-Library.pdf): It describes the NXP implementation of the ZigBee Cluster Library (ZCL) for the ZigBee 3.0 standard.
- [JN-UG-3133-Core-Utilities](./Docs/JN-UG-3133-Core-Utilities.pdf): Describes the device Core Utilities (JCU) that is used in wireless network applications for the NXP device-based microcontrollers.
- [JN-UG-3134-Zigbee3-Green-Power](./Docs/JN-UG-3134-Zigbee3-Green-Power.pdf): Describes the use of the NXP implementation of the Green Power feature for ZigBee 3.0 applications.

# Building NXP Zigbee examples with CMake

Prerequisites:
- CMake (version >=3.24)
- Ninja (version >=1.12)
- ARM GCC Toolchain
- Python3 (version >=3.6)
- [MCUXPresso GitHub SDK](https://github.com/nxp-mcuxpresso/mcux-sdk/tree/main)

## Python requirements

Python is used to run the ZPSConfig and PDUMConfig tools, and requires the extra modules.
To avoid conflicts with your global Python install, we recommend using a virtual environment. You can either use the one
used with your MCUXPresso SDK install, or create a specific one:
```bash
python3 -m venv .venv
```

Then, make sure to activate your environment:
```bash
source .venv/bin/activate
```

Once the virtual environment is activated, you can install the required modules with `pip`:
```bash
pip install -r requirements.txt
```

## Windows long paths limitation

CMake can generate long paths name, and depending on where your MCUX SDK is located, the build might not work correctly
on Windows. For this reason, it is recommended to enable long paths support, Microsoft documented the procedure
[here](https://learn.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation?tabs=registry). We also
recommend to place your MCUXPresso SDK in the root of your disk, like `C:\`, to reduce the paths length as much as possible.

Currently, a Linux environment is preferred over Windows due to these limitations. WSL, Virtual Machine or native Linux
environment can be used.

## Building

The NXP Zigbee CMake build system is meant to be used with the MCUXPresso GitHub SDK. To setup the SDK, follow the
[instructions](https://github.com/nxp-mcuxpresso/mcux-sdk/tree/main?tab=readme-ov-file#overview) provided by the SDK
directly. Once the SDK is setup, the NXP Zigbee repository will be located at `<path to mcux sdk>/middleware/wireless/zigbee`
and you will be able to build the CMake based examples. To know which revision of the MCUXPresso SDK is supported by
the target platform, check the platform specific README.md located at `platform/<platform name>/docs/README.md`.

To build a zigee example, we use `west build`, like the following:
```bash
west build -b <board> -p auto <path to the application>
```

As an example, to build the coordinator application of frdmrw612 board:
```bash
west build -b frdmrw612 -p auto <sdk root>/examples/src/wireless_examples/zigbee/coordinator/freertos
```

## Current examples supported

You'll find below the list of NXP Zigbee examples supported with CMake.

All these examples are located with the other SDK examples, in `<sdk_root>/examples/src`.

| Name | Source folder | Description | Supported boards |
| - | - | - | - |
| `coordinator` | `<sdk_root>/examples/src/wireless_examples/zigbee/coordinator/<os>` | See [README](./examples/zigbee_coordinator/README.md) | `frdmrw612` `rdrw612bga` `frdmmcxw71` `frdmmcxw72` |
| `router` | `<sdk_root>/examples/src/wireless_examples/zigbee/router/<os>` | See [README](./examples/zigbee_router/README.md) | `frdmrw612` `rdrw612bga` `frdmmcxw71` `frdmmcxw72` |
| `ed_rx_on` | `<sdk_root>/examples/src/wireless_examples/zigbee/ed_rx_on/<os>` | See [README](./examples/zigbee_ed_rx_on/README.md) | `frdmrw612` `rdrw612bga` `frdmmcxw71` `frdmmcxw72` |
| `ed_rx_off` | `<sdk_root>/examples/src/wireless_examples/zigbee/ed_rx_off/<os>` | - | `frdmmcxw71` `frdmmcxw72` |

>Note: frdmrw612 and rdrw612bga boards only supports FreeRTOS, not baremetal.