/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdlib.h>

#include "zb_platform.h"
#include "dbg.h"

uint8_t zbPlatCryptoRandomInit(void)
{
    /* NOT IMPLEMENTED */
    return 0;
}

uint32_t zbPlatCryptoRandomGet(uint32_t u32Min, uint32_t u32Max)
{
    FILE *file  = NULL;
    int entropy = 0, n = 0;

    if (u32Min >= u32Max)
    {
        DBG_vPrintf(TRUE, "Invalid input parameters\n");
        return 0;
    }

    file = fopen("/dev/urandom", "rb");
    if (file == NULL)
    {
        DBG_vPrintf(TRUE, "Fail to open /dev/urandom\n");
        return 0;
    }

    if (fread(&entropy, 1, sizeof(entropy), file) != sizeof(entropy))
    {
        DBG_vPrintf(TRUE, "Fail to obtain entropy from /dev/urandom\n");
        fclose(file);
        return 0;
    }

    /* Seed and generate random number */
    srand(entropy);
    n = rand();

    fclose(file);
    return n % (u32Max - u32Min) + u32Min;
}

uint32_t zbPlatCryptoRandom256Get(void)
{
    zbPlatCryptoRandomGet(0, 256);
}
