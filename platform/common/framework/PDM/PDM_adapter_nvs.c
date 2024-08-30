/*!
 * \file PDM_adapter_nvs.c
 * \brief PDM abstraction implementation over NVS filesystem
 *
 * Copyright 2024 NXP
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "PDM.h"
#include "nvs.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#if defined(gAppNvsInternalFlash_c) && (gAppNvsInternalFlash_c > 0)
#define NVS_AREA_ID NVS_INTFLASH_AREA_ID
#elif defined(gAppNvsExternalFlash_c) && (gAppNvsExternalFlash_c > 0)
#define NVS_AREA_ID NVS_EXTFLASH_AREA_ID
#else
#error "PDM NVS: area must be defined"
#endif

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

struct nvs_context
{
    struct nvs_fs            fs;
    const struct flash_area *fa;
    struct flash_pages_info  info;
    const struct device *    dev;
};

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

struct nvs_context  nvs_context;

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

PDM_teStatus PDM_eInitialise(uint16_t segment, uint8_t cnt, PDM_tpfvSystemEventCallback f)
{
    PDM_teStatus ret = PDM_E_STATUS_INTERNAL_ERROR;

    (void)segment;
    (void)cnt;
    (void)f;

    do
    {
        if(flash_area_open(NVS_AREA_ID, &nvs_context.fa) != 0)
        {
            break;
        }

        nvs_context.dev       = flash_area_get_device(nvs_context.fa);
        nvs_context.fs.offset = nvs_context.fa->fa_off;

        if(flash_get_page_info_by_offs(nvs_context.dev, nvs_context.fs.offset, &nvs_context.info) != 0)
        {
            break;
        }

        nvs_context.fs.sector_size  = nvs_context.info.size * 4;
        nvs_context.fs.sector_count = nvs_context.fa->fa_size / nvs_context.fs.sector_size;
        nvs_context.fs.flash_device = nvs_context.dev;

        if(flash_init(nvs_context.dev) != 0)
        {
            break;
        }

        if(nvs_mount(&nvs_context.fs) != 0)
        {
            break;
        }

        ret = PDM_E_STATUS_OK;
    } while (false);

    return ret;
}

PDM_teStatus PDM_eReadDataFromRecord(uint16_t id, void *data, uint16_t len, uint16_t *cnt)
{
    PDM_teStatus ret = PDM_E_STATUS_INVLD_PARAM;
    ssize_t bytesRead;

    do
    {
        if (!data || !len || !cnt)
        {
            break;
        }

        bytesRead = nvs_read(&nvs_context.fs, id, data, len);
        if(bytesRead < 0)
        {
            *cnt = 0;
            break;
        }
        else
        {
            *cnt = bytesRead;
        }

        ret = PDM_E_STATUS_OK;
    } while (false);

    return ret;
}

PDM_teStatus PDM_eSaveRecordData(uint16_t id, void *data, uint16_t len)
{
    PDM_teStatus ret = PDM_E_STATUS_INTERNAL_ERROR;

    do
    {
        if (!data || !len)
        {
            ret = PDM_E_STATUS_INVLD_PARAM;
            break;
        }

        if(nvs_write(&nvs_context.fs, id, data, len) < 0)
        {
            break;
        }

        ret = PDM_E_STATUS_OK;
    } while (false);

    return ret;
}

void PDM_vDeleteDataRecord(uint16_t id)
{
    (void)nvs_delete(&nvs_context.fs, id);
}

void PDM_vDeleteAllDataRecords(void)
{
    uint16_t len = 0U;
    uint8_t eui64_address[8];
    bool extaddrExists = false;

    /* If the Extended Address is stored in PDM, we need to keep it, even after deleting all PDM records */
    if (PDM_bDoesDataExist(PDM_ID_ZPSMAC_EXTADDR, &len) == true)
    {
        if(len == 8U)
        {
            extaddrExists = true;
            (void)PDM_eReadDataFromRecord(PDM_ID_ZPSMAC_EXTADDR, eui64_address, len, &len);
        }
    }

    (void)nvs_clear(&nvs_context.fs);

    /* After an nvs_clear, the file system needs to be mounted again */
    if(nvs_mount(&nvs_context.fs) != 0)
    {
        assert(0);
    }

    if(extaddrExists == true)
    {
        (void)PDM_eSaveRecordData(PDM_ID_ZPSMAC_EXTADDR, eui64_address, 8U);
    }
}

bool_t PDM_bDoesDataExist(uint16_t id, uint16_t *len)
{
    bool_t ret = true;
    ssize_t bytesRead;

    do
    {
        bytesRead = nvs_file_stat(&nvs_context.fs, id);
        if(bytesRead == -ENOENT)
        {
            ret = false;
            *len = 0U;
            break;
        }

        *len = (uint16_t)bytesRead;
    } while (false);

    return ret;
}
