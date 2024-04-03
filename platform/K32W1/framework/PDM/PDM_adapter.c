/*
* Copyright 2023 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <string.h>
#include "PDM.h"
#include "NVM_Interface.h"
#include "fsl_os_abstraction.h"


#undef ASSERT_CONCAT_
#undef ASSERT_CONCAT
#undef STATIC_ASSERT

#define ASSERT_CONCAT_(a, b) a##b
#define ASSERT_CONCAT(a, b) ASSERT_CONCAT_(a, b)
#define STATIC_ASSERT(e) enum { ASSERT_CONCAT(assert_line_, __LINE__) = 1/(!!(e)) };


struct ram_buff_hdr
{
    uint16_t max_len;
    uint16_t *len;
};

struct ram_buff_descriptor
{
    struct ram_buff_hdr hdr;
    uint8_t *data;
};

struct data_hdr
{
    uint16_t len;
    uint16_t key;
} __attribute__ ((packed));


#define RBD_HDR_SIZE sizeof(struct data_hdr)

#ifndef PDM_DATA_ID
#define PDM_DATA_ID 0xf000
#endif

#ifndef PDM_BUFFER_SIZE
#define PDM_BUFFER_SIZE 1024
#endif

STATIC_ASSERT(PDM_BUFFER_SIZE > RBD_HDR_SIZE)

/* storage for RAM buffer. Set to all zeros */
static uint8_t pdm_buff[PDM_BUFFER_SIZE + sizeof(uint16_t)] __attribute__ ((aligned(4))) = {0};

NVM_RegisterDataSet(pdm_buff, 1, sizeof(pdm_buff), PDM_DATA_ID, gNVM_MirroredInRam_c);

/* RAM buffer is the front end for NVM.
   Current length `hdr.len` is at the begging of the storage area. */
static struct ram_buff_descriptor rb;


/* Search for id and fix inconsistencies */
static bool_t rb_search_and_fix(uint16_t size, uint8_t *b, bool_t valid_id, uint16_t id, uint16_t *l, uint16_t *p)
{
    bool_t ret = FALSE;
    uint32_t pos = 0;
    struct data_hdr tmp;

    if (!size || !b)
    {
        return FALSE;
    }

    while ((pos + RBD_HDR_SIZE) < size)
    {
        memcpy(&tmp, &b[pos], RBD_HDR_SIZE);

        if ((pos + tmp.len + RBD_HDR_SIZE) > size)
        {
            /* fix invalid entry */
            tmp.len = size - pos - RBD_HDR_SIZE;

            memcpy(&b[pos], &tmp, RBD_HDR_SIZE);
        }

        if (valid_id && (id == tmp.key))
        {
            if (l)
            {
                *l = tmp.len;
            }

            ret = TRUE;
            break;
        }

        pos += tmp.len + RBD_HDR_SIZE;
    }

    if (p)
    {
        *p = (uint16_t)pos;
    }

    return ret;
}

/* Remove entry of size 'len' from 'pos' and fix inconsistencies.
   'len' and 'pos' must be obtained by calling rb_search_and_fix() */
static void rb_delete(struct ram_buff_descriptor *rb, uint32_t pos, uint16_t len)
{
    if (!rb)
    {
        return;
    }

    if (*rb->hdr.len == 0)
    {
        return;
    }

    if ((pos + len + RBD_HDR_SIZE) >= *rb->hdr.len)
    {
        /* remove last entry */
        *rb->hdr.len = pos;
    }
    else
    {
        memmove(&rb->data[pos], &rb->data[pos + len + RBD_HDR_SIZE], *rb->hdr.len - pos - len - RBD_HDR_SIZE);

        /* update current length */
        *rb->hdr.len -= (len + RBD_HDR_SIZE);
    }
}


PDM_teStatus PDM_eInitialise(uint16_t segment, uint8_t cnt, PDM_tpfvSystemEventCallback f)
{
    (void)segment;
    (void)cnt;
    (void)f;

    /* read from flash into storage area */
    NvModuleInit();
    NvRestoreDataSet(pdm_buff, TRUE);

    /* set up RAM buffer */
    rb.hdr.max_len = PDM_BUFFER_SIZE;

    /* current length is at the begging of the storage area  */
    rb.hdr.len = (uint16_t *)pdm_buff;

    /* set up the storage area. */
    rb.data = &pdm_buff[sizeof(uint16_t)];

    if (*rb.hdr.len > rb.hdr.max_len)
    {
        *rb.hdr.len = rb.hdr.max_len;
    }

    /* data check */
    rb_search_and_fix(*rb.hdr.len, rb.data, FALSE, 0, NULL, rb.hdr.len);

    /* save back to flash */
    NvSyncSave(rb.hdr.len, TRUE);

    return PDM_E_STATUS_OK;
}

PDM_teStatus PDM_eReadDataFromRecord(uint16_t id, void *data, uint16_t len, uint16_t *cnt)
{
    PDM_teStatus ret = PDM_E_STATUS_INVLD_PARAM;
    uint16_t tmp_len;

    if (!data || !len || !cnt)
    {
        return PDM_E_STATUS_INVLD_PARAM;
    }

    OSA_InterruptDisable();

    if (rb_search_and_fix(*rb.hdr.len, rb.data, TRUE, id, &tmp_len, cnt))
    {
        ret = PDM_E_STATUS_OK;

        /* adjust data length */
        if (tmp_len > len)
        {
            tmp_len = len;
        }

        /* copy the data */
        memcpy(data, &rb.data[*cnt + RBD_HDR_SIZE], tmp_len);

        /* set length */
        *cnt = tmp_len;
    }

    OSA_InterruptEnable();
    return ret;
}

PDM_teStatus PDM_eSaveRecordData(uint16_t id, void *data, uint16_t len)
{
    PDM_teStatus ret = PDM_E_STATUS_PDM_FULL;
    struct data_hdr tmp __attribute__ ((aligned(4)));
    uint16_t pos, tmp_len;

    if (!data || !len)
    {
        return PDM_E_STATUS_INVLD_PARAM;
    }

    OSA_InterruptDisable();

    if (rb_search_and_fix(*rb.hdr.len, rb.data, TRUE, id, &tmp_len, &pos))
    {
        if (len == tmp_len)
        {
            ret = PDM_E_STATUS_OK;

            /* replace current data */
            memcpy(&rb.data[pos + RBD_HDR_SIZE], data, len);
        }
        else
        {
            /* delete current data. Add it later */
            rb_delete(&rb, pos, tmp_len);

            /* id isn't in RAM buffer */
            tmp_len = 0;
        }
    }
    else
    {
        /* id isn't in RAM buffer */
        tmp_len = 0;
    }

    if (!tmp_len)
    {
        if (*rb.hdr.len + len + RBD_HDR_SIZE <= rb.hdr.max_len)
        {
            ret = PDM_E_STATUS_OK;

            /* add it at the end */
            tmp.key = id;
            tmp.len = len;

            memcpy(&rb.data[*rb.hdr.len], &tmp, RBD_HDR_SIZE);
            memcpy(&rb.data[*rb.hdr.len + RBD_HDR_SIZE], data, len);

            *rb.hdr.len += len + RBD_HDR_SIZE;
        }
    }

    /* save to flash */
    NvSyncSave(rb.hdr.len, TRUE);

    OSA_InterruptEnable();
    return ret;
}

void PDM_vDeleteDataRecord(uint16_t id)
{
    uint16_t len, pos;

    OSA_InterruptDisable();

    if (rb_search_and_fix(*rb.hdr.len, rb.data, TRUE, id, &len, &pos))
    {
        /* delete current data */
        rb_delete(&rb, pos, len);
    }

    /* save to flash */
    NvSyncSave(rb.hdr.len, TRUE);

    OSA_InterruptEnable();
    return;
}

void PDM_vDeleteAllDataRecords()
{
    OSA_InterruptDisable();

    /* can't delete from NVM. Set zero length */
    *rb.hdr.len = 0;

    /* save to flash */
    NvSyncSave(rb.hdr.len, TRUE);

    OSA_InterruptEnable();
    return;
}

bool_t PDM_bDoesDataExist(uint16_t id, uint16_t *len)
{
    bool_t ret;

    OSA_InterruptDisable();

    ret = rb_search_and_fix(*rb.hdr.len, rb.data, TRUE, id, len, NULL);

    OSA_InterruptEnable();
    return ret;
}
