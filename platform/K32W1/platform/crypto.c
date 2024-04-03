/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <assert.h>
#include "RNG_Interface.h"
#include "zb_platform.h"
#if !defined(FWK_RNG_DEPRECATED_API)
/*
 * This is a placeholder that allows libs linking against
 * different version of the RNG APUI (deprecated and modern)
 * to be linked together.
 * Ideally, this would go away once we have all the libs/apps
 * on the new RNG version
 */
void RNG_GetRandomNo(uint32_t *pRandomNo) __attribute__((weak));
#endif

uint8_t zbPlatCryptoRandomInit(void)
{
    return RNG_Init();
}

uint32_t zbPlatCryptoRandomGet(uint32_t u32Min, uint32_t u32Max)
{
    uint32_t n = 0;
    int16_t num = 0;

#if defined(FWK_RNG_DEPRECATED_API)
    RNG_SetPseudoRandomNoSeed(NULL);
    num = RNG_GetPseudoRandomNo((uint8_t *)&n, sizeof(n), NULL);
#else
    num = RNG_GetPseudoRandomData((uint8_t *)&n, sizeof(n), NULL);
#endif
    assert(num == sizeof(n));
    (void)num;

    return n % (u32Max - u32Min) + u32Min;
}

uint32_t zbPlatCryptoRandom256Get(void)
{
    return zbPlatCryptoRandomGet(0, 0xFF);
}

#if !defined(FWK_RNG_DEPRECATED_API)
WEAK void RNG_GetRandomNo(uint32_t *pRandomNo)
{
    assert(pRandomNo);

    *pRandomNo = zbPlatCryptoRandomGet(0, UINT32_MAX);
}
#endif
