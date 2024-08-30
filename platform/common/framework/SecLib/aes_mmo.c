/*! *********************************************************************************
* Copyright 2023-2024 NXP
* All rights reserved.
*
* \file
*
* This is the source file for the security module.
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#include "SecLib.h"
#include "FunctionLib.h"


/****************************************************************************
 * \brief Perform an MMO Block Update on the hash
 *        H[j] = E(H[j-1], M[j]) ^ M[j]
 *        where E(K,x) = AES-128 block cipher, K=key, x=text
 *
 * \param [in] psMMO   MMO object
 * \param [in] puBlock Block to hash
 *
 ****************************************************************************/
void AESSW_vMMOBlockUpdate(AESSW_Block_u *puHash,
                           AESSW_Block_u *puBlock);

/****************************************************************************
 * \brief  Perform the final update on the MMO, running text through it
 *         H[0] = 0; H[j] = E(H[j-1], M[j]) ^ M[j] for j=1..t
 *         E(K,x) = AES-128 block cipher, K=key, x=text
 *
 * \param [in] psMMO     MMO object
 * \param [in] pu8Data   Text to run through
 * \param [in] iDataLen  Length of text to run through
 * \param [in] iFinalLen Final length of buffer
 *
 ****************************************************************************/
void AESSW_vMMOFinalUpdate(AESSW_Block_u *puHash,
                           uint8_t *pu8Data,
                           int iDataLen,
                           int iFinalLen);

/****************************************************************************
 * \brief  Perform the HMAC-MMO Keyed Hash Function for Message Authentication
 *         Specified in B.1.4 in ZigBee specification (053474r17)
 *
 * \param [in]  pu8Data  Pointer to data stream
 * \param [in]  iDataLen Length of data stream
 * \param [in]  puKey    Key
 * \param [out] puHash   Output hash
 *
 ****************************************************************************/
void AESSW_vHMAC_MMO(uint8_t *pu8Data,
                     int iDataLen,
                     AESSW_Block_u *puKeyData,
                     AESSW_Block_u *puHash);


/****************************************************************************
 *
 * NAME:       AESSW_vHMAC_MMO
 */
/**
 * Perform the HMAC-MMO Keyed Hash Function for Message Authentication
 * Specified in B.1.4 in ZigBee specification (053474r17)
 *
 * @ingroup grp_aes_sw
 *
 * @param pu8Data  Pointer to data stream
 * @param iDataLen Length of data stream
 * @param puKey    Key
 * @param puHash   Output hash
 *
 * @return
 *
 * @note
 *
 ****************************************************************************/
void AESSW_vHMAC_MMO(uint8_t *pu8Data,
                int iDataLen,
                AESSW_Block_u *puKeyData,
                AESSW_Block_u *puHash)
{
    AESSW_Block_u uHash;    /* Temporary hash result */
    AESSW_Block_u uKeyIPad; /* Inner padding - key XORd with ipad */
    AESSW_Block_u uKeyOPad; /* Outer padding - key XORd with opad */
    int i;

    /*
     * the HMAC_MMO transform looks like:
     *
     * MMO(K XOR opad, MMO(K XOR ipad, data))
     *
     * where K is a 16 octet key
     * ipad is the octet 0x36 repeated 16 times
     * opad is the octet 0x5c repeated 16 times
     * and data is the data being protected
     */

    /* Start out by storing key in pads */
    uKeyIPad = uKeyOPad = *puKeyData;

    /* XOR key with ipad and opad values */
    for (i = 0; i < 4; i++)
    {
        uKeyIPad.au32[i] ^= 0x36363636;
        uKeyOPad.au32[i] ^= 0x5c5c5c5c;
    }

    /* Perform inner MMO */
    FLib_MemSet(puHash->au8, 0, AES_BLOCK_SIZE); /* Clear hash to zero */
    AESSW_vMMOBlockUpdate(puHash, &uKeyIPad); /* Key ^ iPad */
    AESSW_vMMOFinalUpdate(puHash, pu8Data, iDataLen+AES_BLOCK_SIZE, iDataLen); /* Data to protect */

    /* Hash passed by reference now contains intermediate result */

    /*
     * Perform outer MMO by "hashing the hash".
     * Need to use temporary hash for result before writing back to hash passed by ref.
     */
    FLib_MemSet(uHash.au8, 0, AES_BLOCK_SIZE); /* Clear temp hash to zero */
    AESSW_vMMOBlockUpdate(&uHash, &uKeyOPad); /* Key ^ oPad */
    AESSW_vMMOFinalUpdate(&uHash, puHash->au8, AES_BLOCK_SIZE*2, AES_BLOCK_SIZE); /* Result from inner MMO */

    /* Return result of outer MMO */
    *puHash = uHash;
}



#ifdef DBG_MMO
extern void vMainDumpBuf(char *pcDescr, unsigned char *pucBuf, unsigned long ulLen);
#endif

/***********************/
/**** MMO FUNCTIONS ****/
/***********************/

/* H[0] = 0; H[j] = E(H[j-1], M[j]) ^ M[j] for j=1..t */
/* E(K,x) = AES-128 block cipher, K=key, x=text */

/****************************************************************************
 *
 * NAME:       AESSW_vMMOBlockUpdate
 */
/**
 * Perform an MMO Block Update on the hash
 * H[j] = E(H[j-1], M[j]) ^ M[j]
 * where E(K,x) = AES-128 block cipher, K=key, x=text
 *
 * @ingroup grp_aes_sw
 *
 * @param psMMO   MMO object
 * @param puBlock Block to hash
 *
 * @return
 *
 * @note
 *
 ****************************************************************************/
void AESSW_vMMOBlockUpdate(AESSW_Block_u *puHash,
                      AESSW_Block_u *puBlock)
{
    int i;
    AESSW_Block_u uOut;

#ifdef DBG_MMO
    vMainDumpBuf("block", puBlock->au8, AES_BLOCK_SIZE);
    vMainDumpBuf("hash before", puHash->au8, AES_BLOCK_SIZE);
#endif

    /* Block cipher using Hash as key */
    AES_128_Encrypt((uint8_t*)puBlock, (uint8_t*)puHash, (uint8_t*)&uOut);

    /* Prepare next hash as (result XOR block) */
    for (i = 0; i < AES_BLOCK_SIZE/4; i++)
    {
        uOut.au32[i] ^= puBlock->au32[i];
        puHash->au32[i] = uOut.au32[i];
    }

#ifdef DBG_MMO
    vMainDumpBuf("hash after", puHash->au8, AES_BLOCK_SIZE);
#endif
}

/****************************************************************************
 *
 * NAME:       AESSW_vMMOFinalUpdate
 */
/**
 * Perform the final update on the MMO, running text through it
 * H[0] = 0; H[j] = E(H[j-1], M[j]) ^ M[j] for j=1..t
 * E(K,x) = AES-128 block cipher, K=key, x=text
 *
 * @ingroup grp_aes_sw
 *
 * @param psMMO     MMO object
 * @param pu8Data   Text to run through
 * @param iDataLen  Length of text to run through
 * @param iFinalLen Final length of buffer
 *
 * @return
 *
 * @note
 *
 ****************************************************************************/
void AESSW_vMMOFinalUpdate(AESSW_Block_u *puHash,
                      uint8_t *pu8Data,
                      int iDataLen,
                      int iFinalLen)
{
    uint8_t *pu8Buf;
    int iPad;
    int iCount;
    int iAdjust;
    int iLen = iFinalLen;
    uint32_t u32DataLen;
    AESSW_Block_u uBuf;

    /* Do complete blocks */
    while (iLen >= AES_BLOCK_SIZE)
    {
        FLib_MemCpy(uBuf.au8, pu8Data, AES_BLOCK_SIZE);
        AESSW_vMMOBlockUpdate(puHash, &uBuf);
        pu8Data += AES_BLOCK_SIZE;
        iLen -= AES_BLOCK_SIZE;
    }

    /* At this point, length remaining can be 15 to 0 */
    pu8Buf = uBuf.au8;
    if (iLen > 0)
    {
        FLib_MemCpy(pu8Buf, pu8Data, iLen);
        pu8Buf += iLen;
    }
    *pu8Buf++ = 0x80;

    /*
     * Now we can start to put padding in.
     * New MMO (>= 8192 bytes): Need space for 6 octets for bitlength field (32 bits plus extra 0x0000)
     * Original MMO (< 8192 bytes): Need space for 2 octets for bitlength field (16 bits)
     * Calculate adjustment needed based on bitlength field space requirements
     */
    iAdjust = (iDataLen >= 8192) ? (AES_BLOCK_SIZE - 6) : (AES_BLOCK_SIZE - 2);
    iPad = iAdjust - 1 - iLen; /* Take off another 1 as 0x80 already gone in */
    if (iPad < 0)
    {
        /* Can't finish off on this block - pad the rest if any, transform and move on */
        iCount = iPad + (AES_BLOCK_SIZE - iAdjust);
        while (iCount-- > 0)
        {
            *pu8Buf++ = 0x00;
        }

        AESSW_vMMOBlockUpdate(puHash, &uBuf);

        /* Reset padding and buffer pointer for final block */
        pu8Buf = uBuf.au8;
        iPad = iAdjust;
    }

    /* Finish off block with length */
    if (iPad > 0)
    {
        FLib_MemSet(pu8Buf, 0, iPad);
        pu8Buf += iPad;
    }
    u32DataLen = (uint32_t)iDataLen << 3; /* in bits so x8 */
    if (iAdjust == (AES_BLOCK_SIZE - 6))
    {
        *pu8Buf++ = (uint8_t)((u32DataLen >> 24) & 0xff);
        *pu8Buf++ = (uint8_t)((u32DataLen >> 16) & 0xff);
    }
    *pu8Buf++ = (uint8_t)((u32DataLen >> 8) & 0xff);
    *pu8Buf++ = (uint8_t)(u32DataLen & 0xff);
    if (iAdjust == (AES_BLOCK_SIZE - 6))
    {
        *pu8Buf++ = 0;
        *pu8Buf++ = 0;
    }

    AESSW_vMMOBlockUpdate(puHash, &uBuf);
}
