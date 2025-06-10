/*
* Copyright 2025 NXP
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
#include "app_shell.h"
#include "app_shell_utils.h"
#include "bdb_api.h"


/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
extern uint32_t Serial_CustomSendData(uint8_t *pData, uint32_t size);
#define SHELL_PRINTF(a) {\
                        const char *pStr; \
                        pStr=a;\
                        Serial_CustomSendData((uint8_t *)pStr, strlen(pStr));\
                      }

#define strincmp strncasecmp

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
static void SHELL_ZigbeeFactoryReset(void);
static void SHELL_ZigbeeGetNetworkStatus(void);
static void SHELL_ZigbeeGetDeviceInfo(void);
static void SHELL_ZigbeeSetNetworkInfo(int32_t argc, char *argv);
static void SHELL_ZigbeePrintHelp(void);


/****************************************************************************/
/***        Public functions                                              ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: SHELL_ZigbeeProcessCommand
 *
 * DESCRIPTION:
 * Process received Zigbee Shell command
 *
 * PARAMETERS: Name        RW  Usage
 *             cmd             Received command
 *             len             Received command length
 *
 * RETURNS: none
 *
 ****************************************************************************/
void SHELL_ZigbeeProcessCommand(uint8_t *cmd, uint8_t len)
{
    if (0 == strincmp((char*)cmd, "zigbee_factoryreset", strlen("zigbee_factoryreset")))
    {
        SHELL_ZigbeeFactoryReset();
    }
    else if (0 == strincmp((char*)cmd, "zigbee_get_network_status", strlen("zigbee_get_network_status")))
    {
        SHELL_ZigbeeGetNetworkStatus();
    }
    else if (0 == strincmp((char*)cmd, "zigbee_get_device_info", strlen("zigbee_get_device_info")))
    {
        SHELL_ZigbeeGetDeviceInfo();
    }
    else if (0 == strincmp((char*)cmd, "zigbee_set_network_info", strlen("zigbee_set_network_info")))
    {
        if (len == strlen("zigbee_set_network_info"))
        {
            SHELL_PRINTF("MISSING COMMAND ARGUMENT\n");
        }
        else
        {
            /* skip command name and extra space in order to obtain network info */
            char *argv = (char *)cmd + strlen("zigbee_set_network_info") + 1;
            SHELL_ZigbeeSetNetworkInfo(1, argv);
        }
    }
    else if (0 == strincmp((char*)cmd, "help", strlen("help")))
    {
        SHELL_ZigbeePrintHelp();
    }
    else
    {
        SHELL_PRINTF("UNKNOWN COMMAND\n");
    }
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
static void SHELL_ZigbeeFactoryReset(void)
{
    SHELL_PRINTF("DONE\n");
    APP_ZigbeeProcessBleEvent((void *) e15_4FactoryResetEvent);
}

static void SHELL_ZigbeeGetNetworkStatus(void)
{
    if (sBDB.sAttrib.bbdbNodeIsOnANetwork)
    {
        SHELL_PRINTF("CONNECTED\n");
    }
    else
    {
        SHELL_PRINTF("NOT_CONNECTED\n");
    }
    SHELL_PRINTF("DONE\n");
}

static void SHELL_ZigbeeGetDeviceInfo(void)
{
    struct dev_info info;
    uint8_t dev_info_tlv[TLV_HEADER_SIZE + TLV_DEV_INFO_SIZE]; // General header + Dev Info and its partial headers
    char dev_info_tlv_ascii[(TLV_HEADER_SIZE + TLV_DEV_INFO_SIZE) * 2 + 1] = {}; // To Convert a 0x00-0xFF number to ascii '00'-'FF'

    APP_GetDeviceInfo(&info);

    SHELL_ConvertDevInfoToTLV(&info, dev_info_tlv, sizeof(dev_info_tlv));
    SHELL_ConvertTlvToASCII(dev_info_tlv, sizeof(dev_info_tlv), dev_info_tlv_ascii, sizeof(dev_info_tlv_ascii));

    SHELL_PRINTF(dev_info_tlv_ascii);
    SHELL_PRINTF("\nDONE\n");
}

static void SHELL_ZigbeeSetNetworkInfo(int32_t argc, char *argv)
{
    bool_t valid = TRUE;
    bool_t enc = FALSE;
    struct oob_info_enc oob_info;

    if (argc != 1)
    {
        valid = FALSE;
        SHELL_PRINTF("WRONG_ARG\n");
        SHELL_PRINTF("DONE\n");
        return;
    }

    if (valid)
    {
        valid = SHELL_read_oob_info(argv, &oob_info, &enc);
    }
    if (valid)
    {
        APP_ZigbeeMutexLock();
        valid = APP_SetOOBInfo(&oob_info, enc);
        APP_ZigbeeMutexUnlock();
    }
    if (valid)
    {
        APP_PrintZigbeeNwkKey();
        SHELL_PRINTF("OK\n");
    }
    else
    {
        SHELL_PRINTF("INVALID OOB INFO\n");
    }
    SHELL_PRINTF("DONE\n");
}

static void SHELL_ZigbeePrintHelp(void)
{
    SHELL_PRINTF("zigbee_get_network_status\t");
    SHELL_PRINTF("Returns the network status CONNECTED or NOT_CONNECTED\n\n");

    SHELL_PRINTF("zigbee_set_network_info\t\t");
    SHELL_PRINTF("Set the network information, the device will automatically try to join the network at the end of the download\n\n");

    SHELL_PRINTF("zigbee_get_device_info\t\t");
    SHELL_PRINTF("Returns the device info (extended address, installation code, CRC), that would be serialized in the TLV format\n\n");

    SHELL_PRINTF("zigbee_factoryreset\t\t");
    SHELL_PRINTF("Resets the device to its factory state\n\n");
}
