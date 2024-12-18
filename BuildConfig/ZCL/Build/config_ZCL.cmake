# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# Needed external symbols (provided by app config cmake file)
# ZIGBEE_BASE_DIR                                 - Path to Zigbee repo
# CONFIG_ZB_ZCL_CLUSTER_MEASUREMENT_AND_SENSING   - Default value Off
# CONFIG_ZB_ZCL_CLUSTER_LIGHTING                  - Default value off
# CONFIG_ZB_ZCL_CLUSTER_HVAC                      - Default value off
# CONFIG_ZB_ZCL_CLUSTER_CLOSURE                   - Default value off
# CONFIG_ZB_ZCL_CLUSTER_SECURITY_AND_SAFETY       - Default value off
# CONFIG_ZB_ZCL_CLUSTER_SMART_ENERGY              - Default value off
# CONFIG_ZB_ZCL_CLUSTER_OTA                       - Default value off
# CONFIG_ZB_ZCL_CLUSTER_COMMISSIONING             - Default value off
# CONFIG_ZB_ZCL_CLUSTER_APPLIANCE_MANAGEMENT      - Default value off
# CONFIG_ZB_ZCL_CLUSTER_GREENPOWER                - Default value off

# Always include ZCIF
mcux_add_source(
    BASE_PATH ${NXP_ZB_BASE}
    SOURCES ZCIF/Source/*.*
)
mcux_add_include(
    BASE_PATH ${NXP_ZB_BASE}
    INCLUDES ZCIF/Include
             ZCIF/Source
)

# Always include Cluster General & ZHA Generic for basic, so no compile time option
mcux_add_source(
    BASE_PATH ${NXP_ZB_BASE}
    SOURCES ZCL/Clusters/General/Source/*.*
            ZCL/Devices/ZHA/Generic/Source/*.*
)
mcux_add_include(
    BASE_PATH ${NXP_ZB_BASE}
    INCLUDES ZCL/Clusters/General/Include
             ZCL/Clusters/General/Source
             ZCL/Devices/ZHA/Generic/Include
)
mcux_add_macro(ZCL_CLUSTER_GENERAL)

# Feature Specific Includes and Sources
if (CONFIG_ZB_ZCL_CLUSTER_MEASUREMENT_AND_SENSING)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES ZCL/Clusters/MeasurementAndSensing/Source/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES ZCL/Clusters/MeasurementAndSensing/Include/
    )
    mcux_add_macro(ZCL_CLUSTER_MEASUREMENT_AND_SENSING)
endif()

if (CONFIG_ZB_ZCL_CLUSTER_LIGHTING)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES ZCL/Clusters/Lighting/Source/*.*
                ZCL/Devices/ZLO/Source/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES ZCL/Clusters/Lighting/Include/
                 ZCL/Devices/ZLO/Include
    )
    mcux_add_macro(ZCL_CLUSTER_LIGHTING)
endif()

if (CONFIG_ZB_ZCL_CLUSTER_HVAC)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES ZCL/Clusters/HVAC/Source/*.*
                ZCL/Devices/ZHA/HVAC/Source/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES ZCL/Clusters/HVAC/Include/
                 ZCL/Devices/ZHA/HVAC/Include
    )
    mcux_add_macro(ZCL_CLUSTER_HVAC)
endif()

if (CONFIG_ZB_ZCL_CLUSTER_CLOSURE)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES ZCL/Clusters/Closures/Source/*.*
                ZCL/Devices/ZHA/Closures/Source/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES ZCL/Clusters/Closures/Include/
                 ZCL/Devices/ZHA/Closures/Include
    )
    mcux_add_macro(ZCL_CLUSTER_CLOSURE)
endif()

if (CONFIG_ZB_ZCL_CLUSTER_SECURITY_AND_SAFETY)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES ZCL/Clusters/SecurityAndSafety/Source/*.*
                ZCL/Devices/ZHA/SecurityAndSafety/Source/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES ZCL/Clusters/SecurityAndSafety/Include/
                 ZCL/Devices/ZHA/SecurityAndSafety/Include
    )
    mcux_add_macro(ZCL_CLUSTER_SECURITY_AND_SAFETY)
endif()

if (CONFIG_ZB_ZCL_CLUSTER_SMART_ENERGY)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES ZCL/Clusters/SmartEnergy/Source/*.*
                ZCL/Devices/ZHA/SmartEnergy/Source/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES ZCL/Clusters/SmartEnergy/Include/
                 ZCL/Devices/ZHA/SmartEnergy/Include
    )
    mcux_add_macro(ZCL_CLUSTER_SMART_ENERGY)
endif()

if (CONFIG_ZB_ZCL_CLUSTER_OTA)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES ZCL/Clusters/OTA/Source/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES ZCL/Clusters/OTA/Include/
    )
    mcux_add_macro(OTA_NO_CERTIFICATE)
endif()

if (CONFIG_ZB_ZCL_CLUSTER_COMMISSIONING)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES ZCL/Clusters/Commissioning/Source/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES ZCL/Clusters/Commissioning/Include/
    )
    mcux_add_macro(ZCL_CLUSTER_COMMISSIONING)
else()
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES ZCL/Clusters/Commissioning/Include/
    )
endif()

if (CONFIG_ZB_ZCL_CLUSTER_APPLIANCE_MANAGEMENT)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES ZCL/Clusters/ApplianceManagement/Source/*.*
                ZCL/Devices/ZHA/ApplianceManagement/Source/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES ZCL/Clusters/ApplianceManagement/Include/
                 ZCL/Devices/ZHA/ApplianceManagement/Include
    )
    mcux_add_macro(ZCL_CLUSTER_APPLIANCE_MANAGEMENT)
endif()

if (CONFIG_ZB_ZCL_CLUSTER_GREENPOWER)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES ZCL/Clusters/GreenPower/Source/*.*
                ZCL/Devices/ZGP/Source/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES ZCL/Clusters/GreenPower/Include/
                 ZCL/Clusters/GreenPower/Source/
                 ZCL/Devices/ZGP/Include
    )
    mcux_add_macro(CLD_GREENPOWER)
endif()

# Add include paths as clusters are not independent for now
mcux_add_include(
    BASE_PATH ${NXP_ZB_BASE}
    INCLUDES ZCL/Clusters/MeasurementAndSensing/Include/
             ZCL/Clusters/Lighting/Include/
             ZCL/Clusters/HVAC/Include/
             ZCL/Clusters/Closures/Include/
             ZCL/Clusters/SecurityAndSafety/Include/
             ZCL/Clusters/SmartEnergy/Include/
             ZCL/Clusters/OTA/Include/
             ZCL/Clusters/Commissioning/Include/
             ZCL/Clusters/ApplianceManagement/Include/
             ZCL/Clusters/GreenPower/Include/
)

mcux_add_configuration(CC "-DZPS_APL_OPT_SINGLE_INSTANCE")
mcux_add_configuration(CC "-DOTA_NO_CERTIFICATE")
mcux_add_configuration(CC "-DPLME_SAP")


