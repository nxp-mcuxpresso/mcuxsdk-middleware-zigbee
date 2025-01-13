/*
* Copyright 2016-2020,2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "app_coordinator.h"
#include "app_common.h"
#include "app_zigbee.h"
#include "ZQueue.h"
#include "fsl_shell.h"
#include "app_shell.h"
#include "app_shell_utils.h"

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
static shell_status_t SHELL_ZigbeeFactoryReset(shell_handle_t shellHandle, int32_t argc, char **argv);
static shell_status_t SHELL_ZigbeeGetNetworkStatus(shell_handle_t shellHandle, int32_t argc, char **argv);
static shell_status_t SHELL_ZigbeeGetNetworkInfo(shell_handle_t shellHandle, int32_t argc, char **argv);
static shell_status_t SHELL_ZigbeeCreateNetwork(shell_handle_t shellHandle, int32_t argc, char **argv);
static shell_status_t SHELL_ZigbeeFindInitiator(shell_handle_t shellHandle, int32_t argc, char **argv);
static shell_status_t SHELL_ZigbeeToggle(shell_handle_t shellHandle, int32_t argc, char **argv);

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
SHELL_COMMAND_DEFINE(zigbee_factoryreset,
                     "\r\n\"zigbee_factoryreset\": Resets the device to its factory state\r\n",
                     SHELL_ZigbeeFactoryReset,
                     0);
SHELL_COMMAND_DEFINE(zigbee_get_network_status,
                     "\r\n\"zigbee_get_network_status\": Returns the network status NETWORK_CREATED or NETWORK_NOT_CREATED\r\n",
                     SHELL_ZigbeeGetNetworkStatus,
                     0);
SHELL_COMMAND_DEFINE(zigbee_get_network_info,
                     "\r\n\"zigbee_get_network_info\": Returns the network info, Network Info would be serialized in the TLV format if created or NETWORK_NOT_CREATED (if the network is not formed)\r\n",
                     SHELL_ZigbeeGetNetworkInfo,
                     SHELL_IGNORE_PARAMETER_COUNT);
SHELL_COMMAND_DEFINE(zigbee_create_network,
                     "\r\n\"zigbee_create_network\": Allows to create a zigbee network, NETWORK_ALREADY_CREATED will be retured if the network is already formed\r\n",
                     SHELL_ZigbeeCreateNetwork,
                     0);
SHELL_COMMAND_DEFINE(zigbee_find,
                     "\r\n\"zigbee_find\": Start Find & Bind as an initiator, make sure to trigger Find & Bind on a TARGET device\r\n",
                     SHELL_ZigbeeFindInitiator,
                     0);
SHELL_COMMAND_DEFINE(zigbee_toggle,
                     "\r\n\"zigbee_toggle\": Sends on\\off toggle command to bound devices\r\n",
                     SHELL_ZigbeeToggle,
                     0);

static SHELL_HANDLE_DEFINE(s_shellHandle);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
extern serial_handle_t g_serialHandle;

/****************************************************************************/
/***        Public functions                                              ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: APP_ShellInit
 *
 * DESCRIPTION:
 * Init Zigbee Shell and registers its related commands
 *
 * RETURNS:
 * 0 if success, negative values in case of failure
 *
 ****************************************************************************/
int APP_ShellInit(void)
{
    int ret = 0;

    do
    {
        if (SHELL_Init(s_shellHandle, (serial_handle_t)g_serialHandle, "WU>> ") != kStatus_SHELL_Success)
        {
            ret = -1;
            break;
        }
        if(SHELL_RegisterCommand(s_shellHandle, SHELL_COMMAND(zigbee_factoryreset)) != kStatus_SHELL_Success)
        {
            ret = -2;
            break;
        }
        if(SHELL_RegisterCommand(s_shellHandle, SHELL_COMMAND(zigbee_get_network_status)) != kStatus_SHELL_Success)
        {
            ret = -3;
            break;
        }
        if(SHELL_RegisterCommand(s_shellHandle, SHELL_COMMAND(zigbee_get_network_info)) != kStatus_SHELL_Success)
        {
            ret = -4;
            break;
        }
        if(SHELL_RegisterCommand(s_shellHandle, SHELL_COMMAND(zigbee_create_network)) != kStatus_SHELL_Success)
        {
            ret = -5;
            break;
        }
        if(SHELL_RegisterCommand(s_shellHandle, SHELL_COMMAND(zigbee_find)) != kStatus_SHELL_Success)
        {
            ret = -6;
            break;
        }
        if(SHELL_RegisterCommand(s_shellHandle, SHELL_COMMAND(zigbee_toggle)) != kStatus_SHELL_Success)
        {
            ret = -7;
            break;
        }
    } while (false);

    return ret;
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
static shell_status_t SHELL_ZigbeeFactoryReset(shell_handle_t shellHandle, int32_t argc, char **argv)
{
    APP_tsEvent sButtonEvent;

    sButtonEvent.eType = APP_E_EVENT_POR_FACTORY_RESET;
    if(!ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent))
    {
        SHELL_Printf(s_shellHandle, "FACTORY_RESET_FAILURE\n");
    }

    return kStatus_SHELL_Success;
}

static shell_status_t SHELL_ZigbeeGetNetworkStatus(shell_handle_t shellHandle, int32_t argc, char **argv)
{
    if (sBDB.sAttrib.bbdbNodeIsOnANetwork)
    {
        SHELL_Printf(s_shellHandle, "NETWORK_CREATED\n");
    }
    else
    {
        SHELL_Printf(s_shellHandle, "NETWORK_NOT_CREATED\n");
    }
    SHELL_Printf(s_shellHandle, "DONE\n");

    return kStatus_SHELL_Success;
}

static shell_status_t SHELL_ZigbeeGetNetworkInfo(shell_handle_t shellHandle, int32_t argc, char **argv)
{
    bool_t valid = TRUE;
    bool_t enc = FALSE;
    struct dev_info dev_info;
    struct oob_info_enc oob_info;
    uint8_t oob_info_tlv[TLV_HEADER_SIZE + TLV_OOB_INFO_ENC_SIZE]; // General header + oob Info and its partial headers
    char oob_info_tlv_ascii[(TLV_HEADER_SIZE + TLV_OOB_INFO_ENC_SIZE) * 2 + 1] = {}; // To Convert a 0x00-0xFF number to ascii '00'-'FF'

    switch (argc)
    {
        case 2:
            enc = TRUE;
            valid = SHELL_read_device_info(argv[1], &dev_info);
            break;
        case 1:
            break;
        default:
            valid = FALSE;
            SHELL_Printf(s_shellHandle, "WRONG_ARG\n");
    }

    if (valid)
    {
        valid = APP_GetOOBInfo(enc ? &dev_info : NULL, &oob_info);
    }
    if (valid)
    {
        SHELL_ConvertOobInfoToTLV(&oob_info, oob_info_tlv, sizeof(oob_info_tlv), enc);
        if (enc)
        {
            SHELL_ConvertTlvToASCII(oob_info_tlv, sizeof(oob_info_tlv), oob_info_tlv_ascii, sizeof(oob_info_tlv_ascii));
        }
        else
        {
            SHELL_ConvertTlvToASCII(oob_info_tlv, sizeof(oob_info_tlv) - (OOB_MIC_SIZE + TLV_HEADER_SIZE), oob_info_tlv_ascii, sizeof(oob_info_tlv_ascii));
        }
        SHELL_Write(s_shellHandle, oob_info_tlv_ascii, strlen(oob_info_tlv_ascii));
        SHELL_Printf(s_shellHandle, "\n");
    }
    else
    {
        SHELL_Printf(s_shellHandle, "NO OOB INFO\n");
    }
    SHELL_Printf(s_shellHandle, "DONE\n");

    return kStatus_SHELL_Success;
}

static shell_status_t SHELL_ZigbeeCreateNetwork(shell_handle_t shellHandle, int32_t argc, char **argv)
{
    APP_tsEvent sButtonEvent;
    if (FALSE == sBDB.sAttrib.bbdbNodeIsOnANetwork)
    {
        sButtonEvent.eType = APP_E_EVENT_SERIAL_FORM_NETWORK;
        if(!ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent))
        {
            SHELL_Printf(s_shellHandle, "NETWORK_CREATION_FAILURE\n");
        }
    }
    else
    {
        SHELL_Printf(s_shellHandle, "NETWORK_ALREADY_CREATED\n");
    }
    SHELL_Printf(s_shellHandle, "DONE\n");
    return kStatus_SHELL_Success;
}

static shell_status_t SHELL_ZigbeeFindInitiator(shell_handle_t shellHandle, int32_t argc, char **argv)
{
    APP_tsEvent sButtonEvent;
    if (sBDB.sAttrib.bbdbNodeIsOnANetwork)
    {
        sButtonEvent.eType = APP_E_EVENT_SERIAL_FIND_BIND_START;
        if(!ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent))
        {
            SHELL_Printf(s_shellHandle, "FIND_&_BIND_FAILURE\n");
        }
    }
    else
    {
        SHELL_Printf(s_shellHandle, "NETWORK_NOT_CREATED\n");
    }
    SHELL_Printf(s_shellHandle, "DONE\n");
    return kStatus_SHELL_Success;
}

static shell_status_t SHELL_ZigbeeToggle(shell_handle_t shellHandle, int32_t argc, char **argv)
{
    APP_tsEvent sButtonEvent;
    if (sBDB.sAttrib.bbdbNodeIsOnANetwork)
    {
        sButtonEvent.eType = APP_E_EVENT_SERIAL_TOGGLE;
        if(!ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent))
        {
            SHELL_Printf(s_shellHandle, "TOGGLE_FAILURE\n");
        }
    }
    else
    {
        SHELL_Printf(s_shellHandle, "NETWORK_NOT_CREATED\n");
    }
    SHELL_Printf(s_shellHandle, "DONE\n");
    return kStatus_SHELL_Success;
}
