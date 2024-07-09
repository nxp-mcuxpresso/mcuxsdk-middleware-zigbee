# Table of Content

- [Table of Content](#table-of-content)
- [Useful documents](#useful-documents)
- [Building NXP Zigbee examples with CMake](#building-nxp-zigbee-examples-with-cmake)
  - [Python requirements](#python-requirements)
  - [Windows long paths limitation](#windows-long-paths-limitation)
  - [Building](#building)
    - [Configuring CMake project using presets](#configuring-cmake-project-using-presets)
    - [Building CMake project](#building-cmake-project)
  - [Current examples supported](#current-examples-supported)
- [Configure, Build, Debug NXP Zigbee examples with VS Code](#configure-build-debug-nxp-zigbee-examples-with-vs-code)
- [Using NXP Zigbee CMake interface to create an application](#using-nxp-zigbee-cmake-interface-to-create-an-application)
  - [NXP Zigbee configuration flags](#nxp-zigbee-configuration-flags)

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

NXP Zigbee examples come with [CMakePresets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html) support.
Each available preset corresponds to a variant configuration of the application. Presets makes it easier for users to
build a supported configuration of the application. Also, CMakePresets are fully supported and integrated with the
[VS Code CMake Tools extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools),
see [here](https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/cmake-presets.md) for more details on how to use it with presets.

To get the list of available configuration presets, run the following command (adapt the path accordingly):
```bash
cmake -S./examples/zigbee_coordinator --list-presets
```

>Note: the -S option specifies the source folder, this allows to run cmake from any folder, but the command can be
>simplified when you are already in the source folder of the example:
>```bash
>cd ./examples/zigbee_coordinator
> cmake --list-presets
>```

You should get an output similar to:
```bash
Available configure presets:

  "coordinator-rdrw612bga"     - Zigbee Coordinator RD-RW612-BGA
  "coordinator-r23-rdrw612bga" - Zigbee Coordinator R23 RD-RW612-BGA
  "coordinator-frdmrw612"      - Zigbee Coordinator FRDM-RW612
  "coordinator-r23-frdmrw612"  - Zigbee Coordinator R23 FRDM-RW612bash
```

### Configuring CMake project using presets

To configure the project with a specific preset, run the following command (adapt the path and preset name accordingly):
```bash
cmake -S./examples/zigbee_coordinator --preset coordinator-rw612
```
This will create a binary folder `build/` at the root of the Zigbee repository.

>Note: NXP Zigbee examples are configured with Ninja Multi-Config generator,
>this means multiple configurations will be configured at once: `Debug`, `MinSizeRel`, `Release` and `RelWithDebInfo`.

### Building CMake project

Once the project is configured, it can be built with a simple command:
```bash
cmake --build build/
```
This command will build the default build profile. Usually, `Debug` and `MinSizeRel` configurations are built at the same time.

To build a specific configuration, run the following command:
```bash
cmake --build build/ --config <config>
```

Once the build is complete, The binaries will be located in `build/<configuration>/bin`.

## Current examples supported

You'll find below the list of NXP Zigbee examples supported with CMake.

| Name | Source folder | Description |
| - | - | - |
| `zigbee_coordinator` | `examples/zigbee_coordinator` | See [README](./examples/zigbee_coordinator/README.md) |
| `zigbee_router` | `examples/zigbee_router` | See [README](./examples/zigbee_router/README.md) |
| `zigbee_ed_rx_on` | `examples/zigbee_ed_rx_on` | See [README](./examples/zigbee_ed_rx_on/README.md) |

# Configure, Build, Debug NXP Zigbee examples with VS Code

NXP provides a generic, easy and close to native VS Code integration to configure, build and debug NXP Zigbee examples.
Refer to the [NXP VS Code guide](Docs/vscode/vscode.md) for a detailed guide.

# Using NXP Zigbee CMake interface to create an application

The NXP Zigbee repository provides a CMake interface which can be used to build a Zigbee application on top of it.
This interface provides a configuration file which allows to use `find_package` in a CMake list file to find and pull
the NXP Zigbee stack into the project.

As an example, here is a very simple top level CMake list file which creates a Zigbee application:
```cmake
find_package(NxpZb REQUIRED HINTS $ENV{NXP_ZB_BASE})
project(my_zb_app VERSION 1.0.0)

target_sources(zb_app PRIVATE
    my_main.c
)
```
In the above example, `find_package(NxpZb REQUIRED HINTS $ENV{NXP_ZB_BASE})` is used to search and find the NXP Zigbee repo, based on the `NXP_ZB_BASE` environment variable. This variable must be set to the path to the root of this repo before configuring the project.

During this configuration, the NXP Zigbee build system will create an executable target `zb_app` which is the main executable representing the application. The application developer can add any properties to this target, such as sources, include directories, compile definitions, link options and so on. You may use the "extensions" functions provided in `cmake/extensions.cmake` to provide project-wide properties.

Furthermore, when configuring the NXP Zigbee project, a "catch-all" interface target is created, and called `zb_interface`. This interface target is used to share project-wide properties between the different targets of the project.

## NXP Zigbee configuration flags

The NXP Zigbee CMake interface comes with several configuration flags which allows to select a platform to build for, and to enable/disable stack features. See below for the available configuration flags.

| Parameter | Description | Supported values | Default value |
| - | - | - | - |
| `CONFIG_ZB_PLATFORM` | Select the platform to build for. This parameter is mandatory to build the NXP Zigbee stack. | `RW612` | `empty` |
| `CONFIG_ZB_BDB` | Adds BDB sources to the application target | `boolean` | `ON` |
| `CONFIG_ZB_ZCL` | Adds ZCL sources to the application target | `boolean` | `ON` |
| `CONFIG_ZB_R23` | Enables R23 features. Cannot be used alongside `CONFIG_ZB_LEGACY` | `boolean` | `OFF` |
| `CONFIG_ZB_LEGACY` | Enables legacy support. Cannot be used alongside `CONFIG_ZB_R23` | `boolean` | `OFF` |
| `CONFIG_ZB_WWAH` | Enables WWAH support. | `boolean` | `OFF` |
| `CONFIG_ZB_USE_FREERTOS` | Enable FreeRTOS support. | `boolean` | `ON` |
| `CONFIG_ZB_FREERTOS_CONFIG` | Path to the FreeRTOSConfig.h file to use in the build. This parameter is mandatory when `CONFIG_ZB_USE_FREERTOS` is enabled, but the platform might define a default path. | `NA` | `empty` |
| `CONFIG_ZB_DEVICE_TYPE` | Select the device role between Coordinator\Router (ZCR) and End Device (ZED) | `ZCR` `ZED` | `ZCR` |
| `CONFIG_ZB_CONSOLE_INTERFACE` | Select the HW interface used for the serial console, usually an UART. Platforms might not provide the same level of support from one to another. | `UART` | `UART` |
| `CONFIG_ZB_SINGLE_CHANNEL` | If set, the device will force use a single channel instead of automatically choosing one. | `empty` `channel number` | `empty` |

The default values are set by the file `cmake/defaults.cmake` at configuration time, but the application can provide its own default configuration. This can be done by creating a file called `app_config.cmake` in the same folder of the top level CMake list file. If the file exists, it will be included during the configuration step.

When generating the CMake project, the configuration will be displayed, similarly to the following output:
```bash
-- ********************************
-- *** NXP Zigbee configuration ***
-- CONFIG_ZB_BDB=ON
-- CONFIG_ZB_CONSOLE_INTERFACE=UART
-- CONFIG_ZB_DEVICE_TYPE=ZCR
-- CONFIG_ZB_FREERTOS_CONFIG=/path/to/mcux-sdk/middleware/wireless/zigbee/examples/zigbee_coordinator/src/freertos/FreeRTOSConfig.h
-- CONFIG_ZB_LEGACY=OFF
-- CONFIG_ZB_PLATFORM=RW612
-- CONFIG_ZB_R23=OFF
-- CONFIG_ZB_SINGLE_CHANNEL=
-- CONFIG_ZB_TRACE_APP=ON
-- CONFIG_ZB_TRACE_ZCL=ON
-- CONFIG_ZB_USE_FREERTOS=ON
-- CONFIG_ZB_WWAH=OFF
-- CONFIG_ZB_ZCL=ON
-- ********************************
```
