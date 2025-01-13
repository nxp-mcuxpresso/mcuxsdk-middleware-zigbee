/*
* Copyright 2016-2020,2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef APP_SHELL_UTILS_H_
#define APP_SHELL_UTILS_H_

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "app_common.h"

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef enum
{
    E_TLV_TAG_UNENCRYPTED_NETWORK_INFO_PAYLOAD  = 0xa0,
    E_TLV_TAG_ENCRYPTED_NETWORK_INFO_PAYLOAD    = 0xa1,
    E_TLV_TAG_DEVICE_INFO_PAYLOAD               = 0xa2,

    E_TLV_TAG_NODE_ADDR                         = 0xc0,
    E_TLV_TAG_INST_CODE                         = 0xc1,
    E_TLV_TAG_CRC                               = 0xc2,

    E_TLV_TAG_NETWORK_KEY                       = 0xf0,
    E_TLV_TAG_TRUST_CENTER_ADDR                 = 0xf1,
    E_TLV_TAG_EXT_PAN_ID                        = 0xf2,
    E_TLV_TAG_PAN_ID                            = 0xf3,
    E_TLV_TAG_ACTIVE_SQ_NB                      = 0xf4,
    E_TLV_TAG_CHANNEL                           = 0xf5,
    E_TLV_TAG_MIC                               = 0xf6,
} TLV_Tag;

typedef struct 
{
    uint8_t tag;
    uint8_t len;
    uint8_t *pData;
} structTLV_t;

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define TLV_TAG_SIZE sizeof(((structTLV_t *)0)->tag)
#define TLV_LEN_SIZE sizeof(((structTLV_t *)0)->len)
#define TLV_HEADER_SIZE (TLV_TAG_SIZE + TLV_LEN_SIZE)

#define DEV_ADDR_SIZE sizeof(((struct dev_info *)0)->addr)
#define DEV_INSTCODE_SIZE sizeof(((struct dev_info *)0)->instCode)
#define DEV_CRC_SIZE sizeof(((struct dev_info *)0)->crc)

#define DEV_INFO_SIZE sizeof(struct dev_info)
#define TLV_DEV_INFO_SIZE (DEV_INFO_SIZE + 3 * TLV_HEADER_SIZE)

#define OOB_KEY_SIZE sizeof(((struct oob_info *)0)->key)
#define OOB_ADDR_SIZE sizeof(((struct oob_info *)0)->tcAddress)
#define OOB_PI_SIZE sizeof(((struct oob_info *)0)->panId)
#define OOB_SPI_SIZE sizeof(((struct oob_info *)0)->shortPanId)
#define OOB_SQ_SIZE sizeof(((struct oob_info *)0)->activeKeySeq)
#define OOB_CH_SIZE sizeof(((struct oob_info *)0)->channel)
#define OOB_MIC_SIZE sizeof(((struct oob_info_enc *)0)->mic)

#define OOB_INFO_SIZE sizeof(struct oob_info)
#define TLV_OOB_INFO_SIZE (OOB_INFO_SIZE + 6 * TLV_HEADER_SIZE)

#define OOB_INFO_ENC_SIZE sizeof(struct oob_info_enc)
#define TLV_OOB_INFO_ENC_SIZE (OOB_INFO_ENC_SIZE + 7 * TLV_HEADER_SIZE)

/* Converts a 0x00-0x0F number to ascii '0'-'F' */
#define HexToAscii(hex) (uint8_t)( ((hex) & 0x0F) + ((((hex) & 0x0F) <= 9) ? '0' : ('A'-10)) )

/****************************************************************************/
/***        Public functions                                              ***/
/****************************************************************************/
bool_t SHELL_read_device_info(const char* arg, struct dev_info* info);
bool_t SHELL_read_oob_info(const char* arg, struct oob_info_enc* oob, bool_t* enc);
void SHELL_ConvertDevInfoToTLV(const struct dev_info* dev_info, uint8_t* dev_info_tlv, uint8_t dev_info_tlv_size);
void SHELL_ConvertOobInfoToTLV(const struct oob_info_enc* oob, uint8_t* oob_tlv, uint8_t oob_tlv_size, bool_t enc);
void SHELL_ConvertTlvToASCII(const uint8_t* info_tlv, uint8_t info_tlv_size, char* info_tlv_ascii, uint8_t info_tlv_ascii_size);

#endif /*APP_SHELL_UTILS_H_*/
