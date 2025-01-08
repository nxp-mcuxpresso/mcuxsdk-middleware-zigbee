/*!
 * \file PDM_adapter_settings.c
 * \brief PDM abstraction implementation over SettingsNVS
 *
 * Copyright 2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "PDM.h"
#include "settings.h"
#include "nvs_port.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#ifndef PDM_SETTINGS_KEY
#define PDM_SETTINGS_KEY "zb"
#endif

#ifndef PDM_SETTINGS_PERSISTENT_KEY
#define PDM_SETTINGS_PERSISTENT_KEY "zb_p"
#endif

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

typedef struct {
    void* destination;
    size_t destinationSize;
    size_t readSize;
    PDM_teStatus result;
} read_request_t;

typedef struct {
    PDM_teStatus result;
} delete_subtree_request_t;

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static int make_full_key(char fullKey[SETTINGS_MAX_NAME_LEN + 1], const uint16_t id)
{
    /* ExtAddr is reserved in a subtree which is persistent even after a factory reset */
    if (id == PDM_ID_ZPSMAC_EXTADDR)
    {
        snprintf(fullKey, SETTINGS_MAX_NAME_LEN + 1, PDM_SETTINGS_PERSISTENT_KEY "/%04x", id);
    }
    else
    {
        snprintf(fullKey, SETTINGS_MAX_NAME_LEN + 1, PDM_SETTINGS_KEY "/%04x", id);
    }

    return 0;
}

static int load_entry_callback(const char *key, size_t len, settings_read_cb read_cb, void *cb_arg, void *param)
{
    ssize_t bytesRead;
    int ret;
    read_request_t *request = (read_request_t*)param;

    do
    {
        // If requested key X, process just node X and ignore all its descendants: X/*
        if ((key != NULL) && (*key != '\0'))
        {
            ret = 0;
            break;
        }

        bytesRead = read_cb(cb_arg, request->destination, request->destinationSize);
        request->readSize = bytesRead > 0 ? bytesRead : 0;

        if (len > request->destinationSize)
        {
            request->result = PDM_E_STATUS_INVLD_PARAM;
        }
        else
        {
            request->result = bytesRead > 0 ? PDM_E_STATUS_OK : PDM_E_STATUS_INTERNAL_ERROR;
        }

        /* return 1 to stop processing further keys */
        ret = 1;
    } while (false);

    return ret;
}

static int delete_subtree_callback(const char *key, size_t len, settings_read_cb read_cb, void *cb_arg, void *param)
{
    char fullKey[SETTINGS_MAX_NAME_LEN + 1];
    int result;
    delete_subtree_request_t* request = (delete_subtree_request_t*)param;

    /* per design, key string shall not be null */
    assert(key != NULL);

    /* per design, param shall not be null */
    assert(param != NULL);

    snprintf(fullKey, sizeof(fullKey), PDM_SETTINGS_KEY "/%s", key);
    result = settings_delete(fullKey);

    /* return first error, but continue removing remaining keys anyway */
    if ((result != 0) && (request->result == PDM_E_STATUS_OK))
    {
        request->result = PDM_E_STATUS_INTERNAL_ERROR;
    }

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

PDM_teStatus PDM_eInitialise(uint16_t segment, uint8_t cnt, PDM_tpfvSystemEventCallback f)
{
    PDM_teStatus ret = PDM_E_STATUS_INTERNAL_ERROR;
    const struct flash_area* fa;

    (void)segment;
    (void)cnt;
    (void)f;

    do
    {
        if (flash_area_open(SETTINGS_PARTITION, &fa) != 0)
        {
            break;
        }

        if (flash_init(fa->fa_dev) != 0)
        {
            break;
        }

        if (settings_subsys_init() != 0)
        {
            break;
        }

        ret = PDM_E_STATUS_OK;
    } while (false);

    return ret;
}

PDM_teStatus PDM_eReadDataFromRecord(uint16_t id, void *data, uint16_t len, uint16_t *cnt)
{
    char key_name[SETTINGS_MAX_NAME_LEN + 1];
    PDM_teStatus ret;
    read_request_t request;

    do
    {
        if (!data || !len || !cnt)
        {
            ret = PDM_E_STATUS_INVLD_PARAM;
            break;
        }

        request.destination = data;
        request.destinationSize = len;
        request.readSize = 0;
        request.result = PDM_E_STATUS_OK;

        make_full_key(key_name, id);
        settings_load_subtree_direct(key_name, load_entry_callback, &request);
        *cnt = request.readSize;
        ret = request.result;
    } while (false);

    return ret;
}

PDM_teStatus PDM_eSaveRecordData(uint16_t id, void *data, uint16_t len)
{
    PDM_teStatus ret;
    char key_name[SETTINGS_MAX_NAME_LEN + 1];

    do
    {
        if (!data || !len)
        {
            ret = PDM_E_STATUS_INVLD_PARAM;
            break;
        }

        make_full_key(key_name, id);
        if (settings_save_one(key_name, data, len) != 0)
        {
            ret = PDM_E_STATUS_NOT_SAVED;
            break;
        }

        ret = PDM_E_STATUS_OK;
    } while (false);

    return ret;
}

void PDM_vDeleteDataRecord(uint16_t id)
{
    char key_name[SETTINGS_MAX_NAME_LEN + 1];

    make_full_key(key_name, id);
    settings_delete(key_name);
}

void PDM_vDeleteAllDataRecords(void)
{
    delete_subtree_request_t request = { .result = 0 };

    settings_load_subtree_direct(PDM_SETTINGS_KEY, delete_subtree_callback, &request);
}

bool_t PDM_bDoesDataExist(uint16_t id, uint16_t *len)
{
    bool_t ret = true;
    uint8_t data[SETTINGS_MAX_VAL_LEN];
    uint16_t bytesRead;

    PDM_eReadDataFromRecord(id, data, SETTINGS_MAX_VAL_LEN, &bytesRead);

    if (bytesRead == 0U)
    {
        ret = false;
    }
    *len = (uint16_t)bytesRead;

    return ret;
}
