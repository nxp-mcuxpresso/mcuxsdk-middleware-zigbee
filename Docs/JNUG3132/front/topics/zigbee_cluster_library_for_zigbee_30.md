# Preface

## Introduction 

This manual describes the NXP implementation of the ZigBee Cluster Library \(ZCL\) for the ZigBee 3.0 standard. The manual describes the clusters from the ZCL that may be used in ZigBee 3.0 applications developed using an NXP ZigBee 3.0 Software Developer’s Kit \(SDK\).

## Prerequisites 

This manual assumes that you are already familiar with the concepts of ZigBee devices, clusters, and attributes. These are described in the ZigBee 3.0 Stack User Guide \(JNUG3130\), available from the NXP web site \(see “[Support Resources](#5)”\).

## Chip Compatibility 

The ZCL software described in this manual can be used on the NXP K32W041, K32W061, K32W1, MCXW71, MCXW72, RW612, and JN518x family of wireless microcontrollers. The NXP hardware platforms K32W148-EVK, FRDM-MCXW71, FRDM-MCXW72, MCX-W71-EVK, MCX-W72-EVK, FRDM-RW612, and RD-RW612-BGA are supported.

## Organization 

-   [Part I: Fundamentals](../../divider1/topics/part_i__fundamentals.md#id_55825c1d-9404-46ec-834e-c0b9f2edcd92) comprises four chapters:

    -   [Chapter 1](../../ZCL_intro/topics/zigbee_cluster_library_zcl.md#id_1acfe708-4b23-4227-9d28-8027b581780e) introduces the ZigBee Cluster Library \(ZCL\)

    -   [Chapter 2](../../ZCL_fundamentals/topics/zcl_fundamentals_and_features.md#id_2253a406-f703-4b1e-aac7-c22eb99f7ef2) describes some essential concepts for the ZCL, including read/write access to cluster attributes and the associated read/write functions

    -   [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee) describes the event handling framework of the ZCL, including the supplied event handling function

    -   [Chapter 4](../../ZCL_error_handling/topics/error_handling.md#id_f3337b17-3511-4a3c-930f-6e5c5a4b0ee6) describes the error handling provision of the ZCL, including the supplied error handling function

-   [Part II: Common Resources](../../divider2/topics/part_ii__common_resources.md#id_983ba107-e22b-4603-a236-585bc0009e76) comprises three chapters:

    -   [Chapter 5](../../Core_functions/topics/zcl_functions.md#id_47f7b1d5-4bf3-42d3-a301-46f756224a9b) details the general functions of the ZCL

    -   [Chapter 6](../../ZCL_structures/topics/zcl_structures.md#id_3021582b-e1f5-4cef-983a-56914625fec8) details the general structures used by the ZCL

    -   [Chapter 7](../../ZCL_enums_codes/topics/enumerations_and_status_codes.md#id_3aca14c7-db3e-486a-a708-96e2cfd2a8e7) details the general enumerations used by the ZCL

-   [Part III: General Clusters](../../divider3/topics/part_iii__general_clusters.md#id_76b12229-9cb5-4754-9bc6-40cdd4319e58) comprises fifteen chapters:

    -   [Chapter 8](../../Basic_cluster/topics/basic_cluster.md#id_607c1094-a342-4552-95ff-4f0eb2fb78c2) details the **Basic** cluster

    -   [Chapter 9](../../Power_Configuration_cluster/topics/power_configuration_cluster.md#id_55965dfd-7aa3-46fb-99ed-fedfeec0f9a2) details the **Power Configuration** cluster

    -   [Chapter 10](../../Device_Temp_Configuration_cluster/topics/device_temperature_configuration_cluster.md#id_d5871e15-4d16-42aa-b996-a753a1e075bb) details the **Device Temperature Configuration** cluster

    -   [Chapter 11](../../Identify_cluster/topics/identify_cluster.md#id_8d39ccb7-5ec3-439b-af2c-8b6105768b6d) details the **Identify** cluster

    -   [Chapter 12](../../Groups_cluster/topics/groups_cluster.md#id_b6af3456-b2dc-4439-8085-c09909bffbe2) details the **Groups** cluster

    -   [Chapter 13](../../Scenes_cluster/topics/scenes_cluster.md#id_6e49ba6c-88c2-4dbb-a986-2965b3fc17f7) details the **Scenes** cluster

    -   [Chapter 14](../../OnOff_cluster/topics/onoff_cluster.md#id_95380f68-4a55-4dd0-814d-ba1e49f7f592) details the **On/Off** cluster

    -   [Chapter 15](../../OnOff_Switch_Config_cluster/topics/onoff_switch_configuration_cluster.md#id_cb71d38c-0367-4f03-9a82-8a92202ae39d) details the **On/Off Switch Configuration** cluster

    -   [Chapter 16](../../Level_Control_cluster/topics/level_control_cluster.md#id_492efae6-d88d-4203-be53-0039b6fe8f2d) details the **Level Control** cluster

    -   [Chapter 17](../../Alarms_cluster/topics/alarms_cluster.md#id_709bda96-0108-4916-8d58-eab1f23dd3b0) details the **Alarms** cluster

    -   [Chapter 18](../../Time_cluster/topics/time_cluster_and_zcl_time.md#id_4d63ad38-ffbb-4bd9-a794-b4e7b3ba2d67) details the **Time** cluster, as well as the use of ZCL time

    -   [Chapter 19](../../Binary_Input_Basic_cluster/topics/binary_input_basic_cluster.md#id_3c6faea1-c00e-4b85-b298-53fb836b3df2) details the **Input and Output** clusters

    -   [Chapter 20](../../poll_control_cluster/topics/poll_control_cluster.md#id_df60ef89-7db8-4ee3-8585-efa4cbd3f0cc) details the **Poll Control** cluster

    -   [Chapter 21](../../power_profile_cluster/topics/power_profile_cluster.md#id_c10ea2ad-2bfe-4216-bcaa-7e0a4bf42864) details the **Power Profile** cluster

    -   [Chapter 22](../../Diagnostics_cluster/topics/diagnostics_cluster.md#id_a1a99033-70dd-400b-8749-bc4db774b38b) details the **Diagnostics** cluster

-   [Part IV: Measurement and Sensing Clusters](../../divider4/topics/part_iv__measurement_and_sensing_clusters.md#id_7058be3f-7787-4665-a15f-f1328b6468c4) comprises eight chapters:

    -   [Chapter 23](../../Illuminance_Measurement_cluster/topics/illuminance_measurement_cluster.md#id_23d80ff4-b719-417c-a0b7-1deda4fccd23) details the **Illuminance Measurement** cluster

    -   [Chapter 24](../../Illuminance_Level_Sensing_cluster/topics/illuminance_level_sensing_cluster.md#id_cc86a2b6-4b7b-4b9f-9ae6-2eea90d8395c) details the **Illuminance Level Sensing** cluster

    -   [Chapter 25](../../Temp_Measurement_cluster/topics/temperature_measurement_cluster.md#id_8ec2ebb1-d509-4d90-9b6b-39b86e2ea079) details the **Temperature Measurement** cluster

    -   [Chapter 26](../../pressure_measurement_cluster/topics/pressure_measurement_cluster.md#id_05e9c48c-8b3a-4fee-b387-dcf0af68767e) details the **Pressure Measurement** cluster

    -   [Chapter 27](../../flow_measurement_cluster/topics/flow_measurement_cluster.md#id_683eceab-8458-4fb9-8b0d-3b2c964dea68) details the **Flow Measurement** cluster

    -   [Chapter 28](../../Rel_Hum_Measurement_cluster/topics/relative_humidity_measurement_cluster.md#id_ffba8e89-b182-4189-8ef2-6cec8f1315f6) details the **Relative Humidity Measurement** cluster

    -   [Chapter 29](../../Occupancy_Sensing_cluster/topics/occupancy_sensing_cluster.md#id_3430306a-a092-4cca-9480-aef30e937d88) details the **Occupancy Sensing** cluster

    -   [Chapter 30](../../electrical_measurement_cluster/topics/electrical_measurement_cluster.md#id_a3ab2726-c85a-4d96-a8e1-3827b51a38c4) details the **Electrical Measurement** cluster

-   [Part V: Lighting Clusters](../../divider5/topics/part_v__lighting_clusters.md#id_dcc05b92-ef77-4d96-bac1-c5e708f381e6) comprises two chapters:

    -   [Chapter 31](../../Colour_Control_cluster/topics/colour_control_cluster.md#id_058f8405-367f-45f1-8eb4-5c7cccdee478) details the **Colour Control** cluster

    -   [Chapter 32](../../Ballast_Configuration_cluster/topics/ballast_configuration_cluster.md#id_97edc9fe-eee1-453a-8e0c-e26f900c1cb1) details the **Ballast Configuration** cluster

-   [Part VI: HVAC Clusters](../../divider6/topics/part_vi__hvac_clusters.md#id_3c5984ff-4d35-4a2e-a694-4a49d5683915) comprises three chapters:

    -   [Chapter 33](../../thermostat_cluster/topics/thermostat_cluster.md#id_ca0f6547-0403-46f7-b017-6b9a2e305885) details the **Thermostat** cluster

    -   [Chapter 34](../../Fan_Control_cluster/topics/fan_control_cluster.md#id_17c1a2df-697a-4f2f-bf93-7d465b2750d8) details the **Fan Control** cluster

    -   [Chapter 35](../../thermostat_UI_config_cluster/topics/thermostat_ui_configuration_cluster.md#id_fa143627-3a1a-4b8e-a36d-950ba77356a5) details the **Thermostat UI Configuration** cluster

-   [Part VII: Closure Clusters](../../divider7/topics/part_vii__closure_clusters.md#id_fd653b0a-40c3-4121-ac7b-96ec11e56503) comprises one chapter:

    -   [Chapter 36](../../door_lock_cluster/topics/door_lock_cluster.md#id_8f644d6d-b496-4393-ad05-3cad57aea286) details the **Door Lock** cluster

-   [Part VIII: Security and Safety Clusters](../../divider8/topics/part_viii__security_and_safety_clusters.md#id_0d276e51-2dd9-4efe-ac8c-77c0ffe75337) comprises three chapters:

    -   [Chapter 37](../../IAS_Zone_cluster/topics/ias_zone_cluster.md#id_30650f2c-f180-4bfc-8ca7-fa06fea094a6) details the **IAS Zone** cluster

    -   [Chapter 38](../../IAS_ACE_cluster/topics/ias_ancillary_control_equipment_cluster.md#id_a070c778-2295-40d2-9cd0-63acf7769c7b) details the **IAS ACE \(Ancillary Control Equipment\)** cluster

    -   [Chapter 39](../../IAS_WD_cluster/topics/ias_warning_device_cluster.md#id_455a8d41-4035-4fc9-b979-3d0c86863f97) details the **IAS WD \(Warning Device\)** cluster

-   [Part IX: Smart Energy Clusters](../../divider9/topics/part_ix__smart_energy_clusters.md#id_024dea63-b718-48c6-8c58-2c6971f68fda) comprises three chapters:

    -   [Chapter 40](../../Price_cluster/topics/price_cluster.md#id_57243bce-7094-499e-9e23-81660106e938) details the **Price**cluster

    -   [Chapter 41](../../DRLC_cluster/topics/demand-response_and_load_control_cluster.md#id_ffd5c332-0ec2-4631-ab01-93f70c7d9a08) details the **Demand-Response and Load Control**cluster

    -   [Chapter 42](../../Simple_Metering_cluster/topics/simple_metering_cluster.md#id_c6f40f83-67ff-49df-96fc-d44d497bc241) details the **Simple Metering** cluster

-   [Part X: Commissioning Clusters](../../divider10/topics/part_x__commissioning_clusters.md#id_6ffe52ff-1376-4e97-aeae-af6c9bce8eae) comprises two chapters:

    -   [Chapter 43](../../Commissioning_cluster/topics/commissioning_cluster.md#id_977af181-972e-4a47-ba80-6dea9cee8b86) details the **Commissioning** cluster

    -   [Chapter 44](../../touchlink_cluster/topics/touchlink_commissioning_cluster.md#id_00599527-d471-4995-8164-3e10eb467bb6) details the **Touchlink Commissioning** cluster

-   [Part XI: Appliances Clusters](../../divider11/topics/part_xi__appliances_clusters.md#id_2d45847d-6dac-4c62-8b25-68f4bdfae853) comprises four chapters:

    -   [Chapter 45](../../appliance_control_cluster/topics/appliance_control_cluster.md#id_de2e147c-a77e-440d-a30d-837ca20be885) details the **Appliance Control** cluster

    -   [Chapter 46](../../appliance_identification_cluster/topics/appliance_identification_cluster.md#id_737c20ee-5404-4881-b6c3-96c9beed2ab0) details the **Appliance Identification** cluster

    -   [Chapter 47](../../appliance_events_alerts_cluster/topics/appliance_events_and_alerts_cluster.md#id_ae2c3d72-955f-41d0-af32-989413bbda86) details the **Appliance Events and Alerts** cluster

    -   [Chapter 48](../../appliance_statistics_cluster/topics/appliance_statistics_cluster.md#id_92cb2bef-0b84-43c3-a448-b14026a3aa7d) details the **Appliance Statistics** cluster

-   [Part XII: Over-The-Air Upgrade](../../divider12/topics/part_xii__over-the-air_upgrade.md#id_3d60cbbe-d866-41ca-92dc-6079a7981991) comprises one chapter:

    -   [Chapter 49](../../OTA_upgrade_cluster/topics/ota_upgrade_cluster.md#id_dffd70c3-497c-496f-af07-56b128d01249) details the **OTA \(Over-the-Air\) Upgrade** cluster

-   [Part XIII: Appendices](../../divider13/topics/part_xiii__appendices.md#id_cc628cb7-8d23-44cd-a220-06a0b1e770e6) comprises the nine appendixes listed below:

    -   [Appendix A: Mutex Callbacks](../../appendix/topics/mutex_callbacks.md)

    -   [Appendix B: Attribute Reporting](../../appendix/topics/attribute_reporting.md)

    -   [Appendix C: Extended Attribute Discovery](../../appendix/topics/extended_attribute_discovery.md)

    -   [Appendix D: Custom Endpoints](../../appendix/topics/custom_endpoints.md)

    -   [Appendix E: Manufacturer-specific Attributes and Commands](../../appendix/topics/manufacturer-specific_attributes_and_commands.md)

    -   [Appendix F: OTA Extension for Dual-processor Nodes](../../appendix/topics/ota_extension_for_dual-processor_nodes.md)
    -   [Appendix G: Glossary](../../appendix/topics/glossary.md)

        These cover topics that include mutex callbacks, attribute reporting, attribute discovery, custom endpoints, manufacturer-specific attributes and commands. The storage of OTA upgrade applications in internal or external flash memory, OTA upgrade of nodes comprising two processors, example code fragments, and a glossary of terms are also included.


## Conventions 

-   Files, folders, functions and parameter types are represented in **bold** type.
-   Function parameters are represented in *italics* type.
-   Code fragments are represented in the `Courier New typeface`.
-   This is a Tip. It indicates useful or practical information.

**Note:** This is a Note. It highlights important additional information.

CAUTION:

This is a Caution. It warns of situations that may result in equipment malfunction or damage.

## Acronyms 

|S.No|Acronym|Description|
|:---:|-------|:----------|
|1|ACE|Ancillary Control Equipment|
|2|API| Application Programming Interface|
|3|APDU|Application Protocol Data Unit|
|4|CIE|Control and Indicating Equipment|
|5|DRLC| Demand-Response and Load Control|
|6|HVAC | Heating, Ventilation and Air-Conditioning|
|7|IAS|Intruder Alarm System|
|8|OTA|Over The Air|
|9|SE| Smart Energy|
|10|UI|User Interface|
|11|UTC|Co-ordinated Universal Time|
|12|WD|Warning Device|
|13|ZCL  |ZigBee Cluster Library|

## Related Documents

Refer to the following documents for further information:

-   JNUG3130 ZigBee 3.0 Stack User Guide
-   JNUG3131 ZigBee Devices User Guide
-   Connectivity Framework Reference Manual
-   075123 rev 7 ZigBee Cluster Library Specification \[from ZigBee Alliance\]
-   095264 ZigBee Over-the-air Upgrading Cluster \[from ZigBee Alliance\]

## Support Resources 

To access online support resources such as SDKs, Application Notes and User Guides, visit the Wireless Connectivity page of the NXP web site:

-   [www.nxp.com/products/wireless-connectivity](http://www.nxp.com/products/wireless-connectivity)

All NXP resources referred to in this manual can be found at the above address, unless otherwise stated.

