/*
* Copyright 2025 NXP
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
#include "app_shell.h"
#include "app_shell_utils.h"


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
static void SHELL_ZigbeeGetNetworkInfo(int32_t argc, char *argv);
static void SHELL_ZigbeeCreateNetwork(void);
static void SHELL_ZigbeeFindInitiator(void);
static void SHELL_ZigbeeToggle(void);
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
    else if (0 == strincmp((char*)cmd, "zigbee_get_network_info", strlen("zigbee_get_network_info")))
    {
        if (len == strlen("zigbee_get_network_info"))
        {
            /* command has no arguments */
            SHELL_ZigbeeGetNetworkInfo(0, NULL);
        }
        else
        {
            /* skip command name and extra space in order to obtain install code */
            char *argv = (char *)cmd + strlen("zigbee_get_network_info") + 1;
            SHELL_ZigbeeGetNetworkInfo(1, argv);
        }
    }
    else if (0 == strincmp((char*)cmd, "zigbee_create_network", strlen("zigbee_create_network")))
    {
        SHELL_ZigbeeCreateNetwork();
    }
    else if (0 == strincmp((char*)cmd, "zigbee_find", strlen("zigbee_find")))
    {
        SHELL_ZigbeeFindInitiator();
    }
    else if (0 == strincmp((char*)cmd, "zigbee_toggle", strlen("zigbee_toggle")))
    {
        SHELL_ZigbeeToggle();
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
        SHELL_PRINTF("NETWORK_CREATED\n");
    }
    else
    {
        SHELL_PRINTF("NETWORK_NOT_CREATED\n");
    }
    SHELL_PRINTF("DONE\n");
}

static void SHELL_ZigbeeGetNetworkInfo(int32_t argc, char *argv)
{
    bool_t valid = TRUE;
    bool_t enc = FALSE;
    struct dev_info dev_info;
    struct oob_info_enc oob_info;
    uint8_t oob_info_tlv[TLV_HEADER_SIZE + TLV_OOB_INFO_ENC_SIZE]; // General header + oob Info and its partial headers
    char oob_info_tlv_ascii[(TLV_HEADER_SIZE + TLV_OOB_INFO_ENC_SIZE) * 2 + 1] = {}; // To Convert a 0x00-0xFF number to ascii '00'-'FF'

    switch (argc)
    {
        case 1:
            enc = TRUE;
            valid = SHELL_read_device_info(argv, &dev_info);
            break;
        case 0:
            break;
        default:
            SHELL_PRINTF("WRONG_ARG\n");
            SHELL_PRINTF("DONE\n");
            return;
    }

    if (valid)
    {
        APP_ZigbeeMutexLock();
        valid = APP_GetOOBInfo(enc ? &dev_info : NULL, &oob_info);
        APP_ZigbeeMutexUnlock();
    }
    if (valid)
    {
        APP_PrintZigbeeNwkKey();

        SHELL_ConvertOobInfoToTLV(&oob_info, oob_info_tlv, sizeof(oob_info_tlv), enc);
        if (enc)
        {
            SHELL_ConvertTlvToASCII(oob_info_tlv, sizeof(oob_info_tlv), oob_info_tlv_ascii, sizeof(oob_info_tlv_ascii));
        }
        else
        {
            SHELL_ConvertTlvToASCII(oob_info_tlv, sizeof(oob_info_tlv) - (OOB_MIC_SIZE + TLV_HEADER_SIZE), oob_info_tlv_ascii, sizeof(oob_info_tlv_ascii));
        }
        SHELL_PRINTF(oob_info_tlv_ascii);
        SHELL_PRINTF("\n");
    }
    else
    {
        SHELL_PRINTF("NO OOB INFO\n");
    }
    SHELL_PRINTF("DONE\n");
}

static void SHELL_ZigbeeCreateNetwork(void)
{
    APP_tsEvent sButtonEvent;
    if (FALSE == sBDB.sAttrib.bbdbNodeIsOnANetwork)
    {
        sButtonEvent.eType = APP_E_EVENT_SERIAL_FORM_NETWORK;
        APP_ZigbeeMutexLock();
        if(!ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent))
        {
            SHELL_PRINTF("NETWORK_CREATION_FAILURE\n");
        }
        APP_ZigbeeMutexUnlock();
    }
    else
    {
        SHELL_PRINTF("NETWORK_ALREADY_CREATED\n");
    }
    SHELL_PRINTF("DONE\n");
}

static void SHELL_ZigbeeFindInitiator(void)
{
    APP_tsEvent sButtonEvent;
    if (sBDB.sAttrib.bbdbNodeIsOnANetwork)
    {
        sButtonEvent.eType = APP_E_EVENT_SERIAL_FIND_BIND_START;
        APP_ZigbeeMutexLock();
        if(!ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent))
        {
            SHELL_PRINTF("FIND_&_BIND_FAILURE\n");
        }
        APP_ZigbeeMutexUnlock();
    }
    else
    {
        SHELL_PRINTF("NETWORK_NOT_CREATED\n");
    }
    SHELL_PRINTF("DONE\n");
}

static void SHELL_ZigbeeToggle(void)
{
    APP_tsEvent sButtonEvent;
    if (sBDB.sAttrib.bbdbNodeIsOnANetwork)
    {
        sButtonEvent.eType = APP_E_EVENT_SERIAL_TOGGLE;
        APP_ZigbeeMutexLock();
        if(!ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent))
        {
            SHELL_PRINTF("TOGGLE_FAILURE\n");
        }
        APP_ZigbeeMutexUnlock();
    }
    else
    {
        SHELL_PRINTF("NETWORK_NOT_CREATED\n");
    }
    SHELL_PRINTF("DONE\n");
}

static void SHELL_ZigbeePrintHelp(void)
{
    SHELL_PRINTF("zigbee_get_network_status\t");
    SHELL_PRINTF("Returns the network status NETWORK_CREATED or NETWORK_NOT_CREATED\n\n");

    SHELL_PRINTF("zigbee_get_network_info\t\t");
    SHELL_PRINTF("Returns the network info, Network Info would be serialized in the TLV format if created or NETWORK_NOT_CREATED (if the network is not formed)\n\n");

    SHELL_PRINTF("zigbee_create_network\t\t");
    SHELL_PRINTF("Allows to create a zigbee network, NETWORK_ALREADY_CREATED will be returned if the network is already formed\n\n");

    SHELL_PRINTF("zigbee_find\t\t");
    SHELL_PRINTF("Start Find & Bind as an initiator, make sure to trigger Find & Bind on a TARGET device\n\n");

    SHELL_PRINTF("zigbee_toggle\t\t");
    SHELL_PRINTF("Sends on\\off toggle command to bound devices\n\n");

    SHELL_PRINTF("zigbee_factoryreset\t\t");
    SHELL_PRINTF("Resets the device to its factory state\n\n");
}
