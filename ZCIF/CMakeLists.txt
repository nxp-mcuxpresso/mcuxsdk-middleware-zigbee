# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcif)
    mcux_add_source(
        SOURCES Source/dlist.c
                Source/zcl_attribute.c
                Source/zcl_buffer.c
                Source/zcl_clusterCommand.c
                Source/zcl_command.c
                Source/zcl_common.c
                Source/zcl_common.h
                Source/zcl_configureReportingCommandHandle.c
                Source/zcl_configureReportingCommandSend.c
                Source/zcl_configureReportingResponseHandle.c
                Source/zcl_CustomCommandReceive.c
                Source/zcl_CustomCommandSend.c

                Source/zcl_defaultResponse.c
                Source/zcl_discoverAttributesExtendedRequestHandle.c
                Source/zcl_discoverAttributesExtendedRequestSend.c
                Source/zcl_discoverAttributesExtendedResponseHandle.c
                Source/zcl_discoverAttributesRequestHandle.c
                Source/zcl_discoverAttributesRequestSend.c
                Source/zcl_discoverAttributesResponseHandle.c
                Source/zcl_discoverCommandsRequestHandle.c
                Source/zcl_discoverCommandsRequestSend.c
                Source/zcl_discoverCommandsResponseHandle.c
                Source/zcl_event.c
                Source/zcl_heap.c
                Source/zcl_internal.h
                Source/zcl_library_options.c
                Source/zcl_PDUbufferReadWrite.c
                Source/zcl_PDUbufferReadWriteString.c
                Source/zcl_readAttributesRequestHandle.c
                Source/zcl_readAttributesRequestSend.c
                Source/zcl_readAttributesResponseHandle.c
                Source/zcl_readReportingConfigurationCommandHandle.c
                Source/zcl_readReportingConfigurationCommandSend.c
                Source/zcl_readReportingConfigurationResponseHandle.c
                Source/zcl_reportManager.c
                Source/zcl_reportMaths.c
                Source/zcl_reportScheduler.c
                Source/zcl_reportStringHandling.c
                Source/zcl_reportStructure.c
                Source/zcl_search.c
                Source/zcl_timer.c
                Source/zcl_transmit.c
                Source/zcl_WriteAttributesRequestHandle.c
                Source/zcl_WriteAttributesRequestSend.c
                Source/zcl_WriteAttributesResponseHandle.c
                Source/zcl.c
                Include/zcl.h
                Include/dlist.h
                Include/zcl_customcommand.h
                Include/zcl_heap.h
                Include/zcl_internal_library_options.h
    )
    mcux_add_include(
        INCLUDES Include
                 Source
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcif_hf)
    mcux_add_include(
        INCLUDES Include
    )
endif()

