/*!
 * \file crypto.c
 * \brief ZB platform abstraction implementation for crypto module
 *
 * Copyright 2023-2024 NXP
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <assert.h>
#include "SecLib.h"
#include "RNG_Interface.h"
#include "aessw_ccm.h"
#include "zb_platform.h"

void RNG_GetRandomNo(uint32_t *pRandomNo) __attribute__((weak));

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void zbPlatCryptoInit(void)
{
    SecLib_Init();
}

void zbPlatCryptoDeInit(void)
{
    SecLib_DeInit();
}

uint8_t zbPlatCryptoRandomInit(void)
{
    return RNG_Init();
}

uint32_t zbPlatCryptoRandomGet(uint32_t u32Min, uint32_t u32Max)
{
    uint32_t n = 0;
    int16_t num = 0;

    num = RNG_GetPseudoRandomData((uint8_t *)&n, sizeof(n), NULL);
    assert(num == sizeof(n));
    (void)num;

    return n % (u32Max - u32Min) + u32Min;
}

uint32_t zbPlatCryptoRandom256Get(void)
{
    return zbPlatCryptoRandomGet(0, 0xFF);
}

WEAK void RNG_GetRandomNo(uint32_t *pRandomNo)
{
    assert(pRandomNo);

    *pRandomNo = zbPlatCryptoRandomGet(0, UINT32_MAX);
}

int16_t zbPlatRngGetPseudoRandom(uint8_t* pOut, uint8_t outBytes, uint8_t* pSeed)
{
    return RNG_GetPseudoRandomData(pOut, outBytes, pSeed);
}

void zbPlatCryptoAesHmacMmo(uint8_t *pu8Data, int iDataLen, void *key, void *hash)
{
    return AESSW_vHMAC_MMO(pu8Data, iDataLen, (AESSW_Block_u *)key, (AESSW_Block_u *)hash);
}

void zbPlatCryptoAesMmoBlockUpdate(void *hash, void *block)
{
    return AESSW_vMMOBlockUpdate((AESSW_Block_u *)hash, (AESSW_Block_u *)block);
}

void zbPlatCryptoAesMmoFinalUpdate(void *hash, uint8_t *pu8Data, int iDataLen, int iFinalLen)
{
    return AESSW_vMMOFinalUpdate((AESSW_Block_u *)hash, pu8Data, iDataLen, iFinalLen);
}

bool_t zbPlatCryptoAesSetKey(CRYPTO_tsReg128 *psKeyData)
{
    return bACI_WriteKey((tsReg128 *)psKeyData);
}

void zbPlatCryptoAes128EcbEncrypt(const uint8_t* pu8Input, uint32_t u32InputLen,
        const uint8_t* pu8Key, uint8_t* pu8Output)
{
    return AES_128_ECB_Encrypt(pu8Input, u32InputLen, pu8Key, pu8Output);
}

void zbPlatCryptoAes128EcbDecrypt(const uint8_t* pu8Input, const uint8_t* pu8Key, uint8_t* pu8Output)
{
    return AES_128_Decrypt(pu8Input, pu8Key, pu8Output);
}

void zbPlatCryptoAesCcmStar(bool_t bEncrypt, uint8_t u8M, uint8_t  u8AuthLen,
        uint8_t u8InputLen, CRYPTO_tsAesBlock *puNonce, uint8_t *pu8AuthData,
        uint8_t *pu8Input, uint8_t *pu8ChecksumData, bool_t *pbChecksumVerify)
{
    return vACI_OptimisedCcmStar(bEncrypt, u8M, u8AuthLen, u8InputLen, (tuAES_Block *)puNonce,
            pu8AuthData, pu8Input, pu8ChecksumData, pbChecksumVerify);
}

bool_t zbPlatCryptoEcdhGenerateKeys(CRYPTO_ecdhPublicKey_t *psPublicKey,
                                    CRYPTO_ecdhPrivateKey_t *psSecretKey,
                                    const uint8_t* pu8BasePointG)
{
#ifdef CRYPTO_ECDH_P256
    if (gSecSuccess_c == ECDH_P256_GenerateKeys((ecdhPublicKey_t *)psPublicKey,
        (ecdhPrivateKey_t *)psSecretKey))
    {
        return TRUE;
    }
#elif defined(CRYPTO_ECDH_CURVE25519)
#endif
    return FALSE;
}

bool_t zbPlatCryptoEcdhComputeDhKey(CRYPTO_ecdhPrivateKey_t *psSecretKey,
                                    CRYPTO_ecdhPublicKey_t *psPeerPublicKey,
                                    CRYPTO_ecdhDhKey_t *psOutEcdhKey,
                                    const uint8_t* pu8BasePointG)
{
#ifdef CRYPTO_ECDH_P256
    if (gSecSuccess_c == ECDH_P256_ComputeDhKey((ecdhPrivateKey_t *)psSecretKey,
        (ecdhPublicKey_t *)psPeerPublicKey, (ecdhDhKey_t *)psOutEcdhKey))
    {
        return TRUE;
    }
#elif defined(CRYPTO_ECDH_CURVE25519)
#endif
    return FALSE;
}

fpZbRngPrng_t zbPlatRngGetPrngFunc(void)
{
    return (fpZbRngPrng_t)RNG_GetPrngFunc();
}

void* zbPlatRngGetPrngContext(void)
{
    return RNG_GetPrngContext();
}
