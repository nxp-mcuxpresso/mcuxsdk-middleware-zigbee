/*
* Copyright 2016-2020,2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "app_router_node.h"
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
static shell_status_t SHELL_ZigbeeGetDeviceInfo(shell_handle_t shellHandle, int32_t argc, char **argv);
static shell_status_t SHELL_ZigbeeSetNetworkInfo(shell_handle_t shellHandle, int32_t argc, char **argv);

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
SHELL_COMMAND_DEFINE(zigbee_factoryreset,
                     "\r\n\"zigbee_factoryreset\": Resets the device to its factory state\r\n",
                     SHELL_ZigbeeFactoryReset,
                     0);
SHELL_COMMAND_DEFINE(zigbee_get_network_status,
                     "\r\n\"zigbee_get_network_status\": Returns the network status CONNECTED or NOT_CONNECTED\r\n",
                     SHELL_ZigbeeGetNetworkStatus,
                     0);
SHELL_COMMAND_DEFINE(zigbee_get_device_info,
                     "\r\n\"zigbee_get_device_info\": Returns the device info (extended address, installation code, CRC), that would be serialized in the TLV format\r\n",
                     SHELL_ZigbeeGetDeviceInfo,
                     0);
SHELL_COMMAND_DEFINE(zigbee_set_network_info,
                     "\r\n\"zigbee_set_network_info\": Set the network information, the device will automatically try to join the network at the end of the download\r\n",
                     SHELL_ZigbeeSetNetworkInfo,
                     1);

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
        if(SHELL_RegisterCommand(s_shellHandle, SHELL_COMMAND(zigbee_get_device_info)) != kStatus_SHELL_Success)
        {
            ret = -4;
            break;
        }
        if(SHELL_RegisterCommand(s_shellHandle, SHELL_COMMAND(zigbee_set_network_info)) != kStatus_SHELL_Success)
        {
            ret = -5;
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
        SHELL_Printf(s_shellHandle, "CONNECTED\n");
    }
    else
    {
        SHELL_Printf(s_shellHandle, "NOT_CONNECTED\n");
    }
    SHELL_Printf(s_shellHandle, "DONE\n");

    return kStatus_SHELL_Success;
}

static shell_status_t SHELL_ZigbeeGetDeviceInfo(shell_handle_t shellHandle, int32_t argc, char **argv)
{
    struct dev_info info;
    uint8_t dev_info_tlv[TLV_HEADER_SIZE + TLV_DEV_INFO_SIZE]; // General header + Dev Info and its partial headers
    char dev_info_tlv_ascii[(TLV_HEADER_SIZE + TLV_DEV_INFO_SIZE) * 2 + 1] = {}; // To Convert a 0x00-0xFF number to ascii '00'-'FF'

    APP_GetDeviceInfo(&info);

    SHELL_ConvertDevInfoToTLV(&info, dev_info_tlv, sizeof(dev_info_tlv));
    SHELL_ConvertTlvToASCII(dev_info_tlv, sizeof(dev_info_tlv), dev_info_tlv_ascii, sizeof(dev_info_tlv_ascii));

    SHELL_Write(s_shellHandle, dev_info_tlv_ascii, strlen(dev_info_tlv_ascii));
    SHELL_Printf(s_shellHandle, "\nDONE\n");

    return kStatus_SHELL_Success;
}

static shell_status_t SHELL_ZigbeeSetNetworkInfo(shell_handle_t shellHandle, int32_t argc, char **argv)
{
    bool_t valid = TRUE;
    bool_t enc = FALSE;
    struct oob_info_enc oob_info;

    if (argc != 2)
    {
        valid = FALSE;
        SHELL_Printf(s_shellHandle, "WRONG_ARG\n");
    }

    if (valid)
    {
        valid = SHELL_read_oob_info(argv[1], &oob_info, &enc);
    }
    if (valid)
    {
        APP_ZigbeeMutexLock();
        valid = APP_SetOOBInfo(&oob_info, enc);
        APP_ZigbeeMutexUnlock();
    }
    if (valid)
    {
        SHELL_Printf(s_shellHandle, "OK\n");
    }
    else
    {
        SHELL_Printf(s_shellHandle, "INVALID OOB INFO\n");
    }
    SHELL_Printf(s_shellHandle, "DONE\n");
    return kStatus_SHELL_Success;
}
