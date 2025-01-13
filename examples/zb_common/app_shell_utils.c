/*
* Copyright 2016-2020,2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <string.h>
#include <assert.h>
#include "app_shell_utils.h"

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
static int8_t SHELL_CopyCharTableToByteBuffer(const char *pCharTable, uint8_t charTableLen, uint8_t *pResult);
static int8_t SHELL_ExtractHexValueFromChar(char ch, uint8_t *pResult);

/****************************************************************************/
/***        Public functions                                              ***/
/****************************************************************************/
bool_t SHELL_read_device_info(const char* arg, struct dev_info* info)
{
    uint32_t idx = 0;
    structTLV_t tmp_tlv;

    if (strlen(arg) != (TLV_HEADER_SIZE + TLV_DEV_INFO_SIZE) * 2)
        return FALSE;

    if (SHELL_CopyCharTableToByteBuffer(arg, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag != E_TLV_TAG_DEVICE_INFO_PAYLOAD || tmp_tlv.len != TLV_DEV_INFO_SIZE)
        return FALSE;

    /* addr */
    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag != E_TLV_TAG_NODE_ADDR || tmp_tlv.len != DEV_ADDR_SIZE)
        return FALSE;

    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, tmp_tlv.len * 2, (uint8_t *)&info->addr))
            return FALSE;

    /* install code */
    idx += tmp_tlv.len * 2;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag != E_TLV_TAG_INST_CODE || tmp_tlv.len != DEV_INSTCODE_SIZE)
        return FALSE;

    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, tmp_tlv.len * 2, (uint8_t *)&info->instCode))
            return FALSE;

    /* CRC */
    idx += tmp_tlv.len * 2;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag != E_TLV_TAG_CRC || tmp_tlv.len != DEV_CRC_SIZE)
        return FALSE;

    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, tmp_tlv.len * 2, (uint8_t *)&info->crc))
            return FALSE;

    return TRUE;
}

bool_t SHELL_read_oob_info(const char* arg, struct oob_info_enc* oob, bool_t* enc)
{
    uint32_t idx = 0;
    structTLV_t tmp_tlv;

    if ((strlen(arg) != (TLV_HEADER_SIZE + TLV_OOB_INFO_ENC_SIZE) * 2) &&
        (strlen(arg) != (TLV_HEADER_SIZE + TLV_OOB_INFO_SIZE) * 2))
        return FALSE;

    if (SHELL_CopyCharTableToByteBuffer(arg, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag == E_TLV_TAG_ENCRYPTED_NETWORK_INFO_PAYLOAD && tmp_tlv.len == TLV_OOB_INFO_ENC_SIZE)
        *enc = TRUE;
    else if (tmp_tlv.tag == E_TLV_TAG_UNENCRYPTED_NETWORK_INFO_PAYLOAD && tmp_tlv.len == TLV_OOB_INFO_SIZE)
        *enc = FALSE;
    else
        return FALSE;

    /* key */
    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag != E_TLV_TAG_NETWORK_KEY || tmp_tlv.len != OOB_KEY_SIZE)
        return FALSE;

    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, tmp_tlv.len * 2, (uint8_t *)&oob->info.key))
            return FALSE;

    /* addr */
    idx += tmp_tlv.len * 2;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag != E_TLV_TAG_TRUST_CENTER_ADDR || tmp_tlv.len != OOB_ADDR_SIZE)
        return FALSE;

    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, tmp_tlv.len * 2, (uint8_t *)&oob->info.tcAddress))
            return FALSE;

    /* panId */
    idx += tmp_tlv.len * 2;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag != E_TLV_TAG_EXT_PAN_ID || tmp_tlv.len != OOB_PI_SIZE)
        return FALSE;

    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, tmp_tlv.len * 2, (uint8_t *)&oob->info.panId))
            return FALSE;

    /* shortPanId */
    idx += tmp_tlv.len * 2;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag != E_TLV_TAG_PAN_ID || tmp_tlv.len != OOB_SPI_SIZE)
        return FALSE;

    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, tmp_tlv.len * 2, (uint8_t *)&oob->info.shortPanId))
            return FALSE;

    /* activeKeySeq */
    idx += tmp_tlv.len * 2;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag != E_TLV_TAG_ACTIVE_SQ_NB || tmp_tlv.len != OOB_SQ_SIZE)
        return FALSE;

    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, tmp_tlv.len * 2, (uint8_t *)&oob->info.activeKeySeq))
            return FALSE;

    /* channel */
    idx += tmp_tlv.len * 2;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag != E_TLV_TAG_CHANNEL || tmp_tlv.len != OOB_CH_SIZE)
        return FALSE;

    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, tmp_tlv.len * 2, (uint8_t *)&oob->info.channel))
            return FALSE;

    if (*enc == FALSE)
        return TRUE;

    /* MIC */
    idx += tmp_tlv.len * 2;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, 4, (uint8_t *)&tmp_tlv))
        return FALSE;

    if (tmp_tlv.tag != E_TLV_TAG_MIC || tmp_tlv.len != OOB_MIC_SIZE)
        return FALSE;

    idx += 4;
    if (SHELL_CopyCharTableToByteBuffer(arg + idx, tmp_tlv.len * 2, (uint8_t *)&oob->mic))
            return FALSE;

    return TRUE;
}

void SHELL_ConvertDevInfoToTLV(const struct dev_info* dev_info, uint8_t* dev_info_tlv, uint8_t dev_info_tlv_size)
{
    uint8_t index = 0;
    assert(dev_info);
    assert(dev_info_tlv);
    assert((TLV_DEV_INFO_SIZE + TLV_HEADER_SIZE) == dev_info_tlv_size);

    dev_info_tlv[index++] = E_TLV_TAG_DEVICE_INFO_PAYLOAD;
    dev_info_tlv[index++] = TLV_DEV_INFO_SIZE;

    dev_info_tlv[index++] = E_TLV_TAG_NODE_ADDR;
    dev_info_tlv[index++] = DEV_ADDR_SIZE;
    memcpy(dev_info_tlv + index, (uint8_t *)&dev_info->addr, DEV_ADDR_SIZE);
    index +=  DEV_ADDR_SIZE;

    dev_info_tlv[index++] = E_TLV_TAG_INST_CODE;
    dev_info_tlv[index++] = DEV_INSTCODE_SIZE;
    memcpy(dev_info_tlv + index, (uint8_t *)&dev_info->instCode, DEV_INSTCODE_SIZE);
    index +=  DEV_INSTCODE_SIZE;

    dev_info_tlv[index++] = E_TLV_TAG_CRC;
    dev_info_tlv[index++] = DEV_CRC_SIZE;
    memcpy(dev_info_tlv + index, (uint8_t *)&dev_info->crc, DEV_CRC_SIZE);
}

void SHELL_ConvertOobInfoToTLV(const struct oob_info_enc* oob, uint8_t* oob_tlv, uint8_t oob_tlv_size, bool_t enc)
{
    uint8_t index = 0;

    assert(oob);
    assert(oob_tlv);
    assert((TLV_OOB_INFO_ENC_SIZE + TLV_HEADER_SIZE) == oob_tlv_size);

    if (enc)
    {
        oob_tlv[index++] = E_TLV_TAG_ENCRYPTED_NETWORK_INFO_PAYLOAD;
        oob_tlv[index++] = TLV_OOB_INFO_ENC_SIZE;
    }
    else
    {
        oob_tlv[index++] = E_TLV_TAG_UNENCRYPTED_NETWORK_INFO_PAYLOAD;
        oob_tlv[index++] = TLV_OOB_INFO_SIZE;
    }

    oob_tlv[index++] = E_TLV_TAG_NETWORK_KEY;
    oob_tlv[index++] = OOB_KEY_SIZE;
    memcpy(oob_tlv + index, (uint8_t *)&oob->info.key, OOB_KEY_SIZE);
    index += OOB_KEY_SIZE;

    oob_tlv[index++] = E_TLV_TAG_TRUST_CENTER_ADDR;
    oob_tlv[index++] = OOB_ADDR_SIZE;
    memcpy(oob_tlv + index, (uint8_t *)&oob->info.tcAddress, OOB_ADDR_SIZE);
    index += OOB_ADDR_SIZE;

    oob_tlv[index++] = E_TLV_TAG_EXT_PAN_ID;
    oob_tlv[index++] = OOB_PI_SIZE;
    memcpy(oob_tlv + index, (uint8_t *)&oob->info.panId, OOB_PI_SIZE);
    index += OOB_PI_SIZE;

    oob_tlv[index++] = E_TLV_TAG_PAN_ID;
    oob_tlv[index++] = OOB_SPI_SIZE;
    memcpy(oob_tlv + index, (uint8_t *)&oob->info.shortPanId, OOB_SPI_SIZE);
    index += OOB_SPI_SIZE;

    oob_tlv[index++] = E_TLV_TAG_ACTIVE_SQ_NB;
    oob_tlv[index++] = OOB_SQ_SIZE;
    memcpy(oob_tlv + index, (uint8_t *)&oob->info.activeKeySeq, OOB_SQ_SIZE);
    index += OOB_SQ_SIZE;

    oob_tlv[index++] = E_TLV_TAG_CHANNEL;
    oob_tlv[index++] = OOB_CH_SIZE;
    memcpy(oob_tlv + index, (uint8_t *)&oob->info.channel, OOB_CH_SIZE);
    index += OOB_CH_SIZE;

    if (enc)
    {
        oob_tlv[index++] = E_TLV_TAG_MIC;
        oob_tlv[index++] = OOB_MIC_SIZE;
        memcpy(oob_tlv + index, (uint8_t *)&oob->mic, OOB_MIC_SIZE);

    }
}

void SHELL_ConvertTlvToASCII(const uint8_t* info_tlv, uint8_t info_tlv_size, char* info_tlv_ascii, uint8_t info_tlv_ascii_size)
{
    uint8_t index = 0;
    assert(info_tlv);
    assert(info_tlv_ascii);
    assert(info_tlv_ascii_size > 2 * info_tlv_size);
    /* Convert Hex Array to ASCII*/
    while (index < info_tlv_size)
    {
        info_tlv_ascii[index*2] = HexToAscii(info_tlv[index] >> 4);
        info_tlv_ascii[index*2 + 1] = HexToAscii(info_tlv[index]);
        index++;
    }
    info_tlv_ascii[index*2] = '\0';
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
static int8_t SHELL_CopyCharTableToByteBuffer(const char *pCharTable, uint8_t charTableLen, uint8_t *pResult)
{
    int8_t status = 0;
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t value1 = 0;
    uint8_t value2 = 0;
    for (i=0; i<charTableLen; i+=2)
    {
        if (SHELL_ExtractHexValueFromChar(pCharTable[i], &value1) != 0)
        {
            status = -1;
            break;
        }
        if (SHELL_ExtractHexValueFromChar(pCharTable[i+1], &value2) != 0)
        {
            status = -1;
            break;
        }
        pResult[j++] = (value1<<4)|value2;
    }
    return status;
}

static int8_t SHELL_ExtractHexValueFromChar(char ch, uint8_t *pResult)
{
    int8_t status = 0;
    if (ch >= '0' && ch <= '9')
    {
        *pResult = ch - '0';
    }
    else if (ch >= 'a' && ch <= 'f')
    {
        *pResult = ch - 'a' + 0xa;
    }
    else if (ch >= 'A' && ch <= 'F')
    {
        *pResult = ch - 'A' + 0xa;
    }
    else
    {
        status = -1;
    }
    return status;
}
