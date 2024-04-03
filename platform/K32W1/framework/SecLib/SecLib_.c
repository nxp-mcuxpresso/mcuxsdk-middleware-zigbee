/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2022 NXP
* All rights reserved.
*
* \file
*
* This is the source file for the security module.
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */


/*! *********************************************************************************
*************************************************************************************
* Include
*************************************************************************************
********************************************************************************** */

#include "FunctionLib.h"
#include "SecLib.h"

#define Lo8(x) ((uint8_t) ((x) & 0xFF))

#define INITIALISE_NONCE_TOP_BYTE(NONCE); \
            NONCE[14] = 0;
#define UPDATE_NONCE_COUNTER(NONCE,VALUE); \
            NONCE[15] = Lo8(VALUE);


/* Used by ZigBee stack adaptation */
enum
{
    MAX_PACKET    =   127,    // largest packet size
    A_DATA        =   0x40,   // the Adata bit in the flags
    M_SHIFT       =   3,      // how much to shift the 3-bit M field
    L_SHIFT       =   0,      // how much to shift the 3-bit L field
    L_SIZE        =   2       // size of the l(m) length field (in octets)
};
static tsReg128 sKey;
bool_t g_bLegacyHwBugEmulation;



/****************************************************************************
 *
 * NAME:       bACI_WriteKey
 */
/**
 * This function setups the key in the AES.
 *
 * @ingroup
 *
 * @param psKeyData               tsReg128 key split over 4 words (16 bytes)
 *
 * @note
 *
 ****************************************************************************/
bool_t bACI_WriteKey(tsReg128 *psKeyData)
{
    /* For kw41, LTC_AES_EncryptEcb api directly needs key data instead
    * of JN where key is set first. */
    FLib_MemCpy(&sKey, psKeyData, sizeof(tsReg128));
    return TRUE;
}

/****************************************************************************
 *
 * NAME:       vACI_OptimisedCcmStar
 */
/**
 * This function performs CCM* AES encryption/decryption with checksum
 * generation/verification. Assumes input buffers are aligned and nonce has a
 * free byte at the start for the flags field
 *
 * @ingroup
 *
 * @param bEncrypt               TRUE to encrypt, FALSE to decrypt
 * @param u8M                    Required number of checksum bytes
 * @param u8alength              Length of authentication data, in bytes
 * @param u8mlength              Length of input data, in bytes
 * @param puNonce                Pre-allocated pointer to a structure
 *                               containing 128-bit Nonce data
 * @param pau8authenticationData Pre-allocated pointer to byte array of
 *                               authentication data
 * @param pau8Data               Pre-allocated pointer to byte array of input
 *                               and output data
 * @param pau8checksumData       Pre-allocated pointer to byte array of
 *                               checksum data
 * @param pbChecksumVerify       Pre-allocated pointer to boolean which in CCM
 *                               decode mode stores the result of the checksum
 *                               verification operation
 *
 * @note
 *
 ****************************************************************************/
void vACI_OptimisedCcmStar(bool_t         bEncrypt,
                           uint8_t        u8M,
                           uint8_t        u8alength,
                           uint8_t        u8mlength,
                           tuAES_Block   *puNonce,
                           uint8_t       *pau8authenticationData,
                           uint8_t       *pau8Data,
                           uint8_t       *pau8checksumData,
                           bool_t        *pbChecksumVerify)
{
    uint32_t u32BlockCnt;
    int i,j;
    tuAES_Block uOut;
    tuAES_Block uCalculatedMic;
    tuAES_Block uRxedMic;
    uint8_t *pu8Out;
    uint8_t *pu8In;

    /* Bounds checking on u8M:
     * 1. To ensure that it will never overflow the MIC storage arrays, for
     *    MISRA C compliance
     * 2. To limit u8M to even values. According to the generic CCM*
     *    definition in IEEE802.15.4-2006, valid values are 0, 4, 6, 8, 10,
     *    12, 14 or 16 but we let 2 through as well. This does mean that the M
     *    field of the Flags field in the Nonce has the same value for a u8M
     *    of 0 or 2, but in practice this form of the Flags field is only used
     *    when u8M is non-0 anyway */
    if (u8M > 16U)
    {
        u8M = 16U;
    }
    else
    {
        /* Round down to even value by zeroing bit 0 */
        u8M &= 0xfeU;
    }

    /**************************************************/
    /* If we are Decrypting - then do this first      */
    /**************************************************/
    if (bEncrypt == FALSE)
    {
        /* Decrypt the data */
        pu8Out = pau8Data;

        /* Add in CTR Flags */
        puNonce->au8[0] =(uint8_t)((L_SIZE - 1) << L_SHIFT);
        INITIALISE_NONCE_TOP_BYTE(puNonce->au8);

        u32BlockCnt = 0;
        for (i = 0; i < u8mlength; i++)
        {
            j = i & 0xf;
            if (j == 0)
            {
                /* generate new keystream block */
                /* Start block counter at 1 for PDU; A[0] is for Mic */
                u32BlockCnt++;
                UPDATE_NONCE_COUNTER(puNonce->au8, u32BlockCnt);

                /* Encrypt the Counter */
                (void)AES_128_ECB_Encrypt(
                         (uint8_t*)puNonce,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
            }

            /* XOR in the keystream and copy into both output buffer and temp buffer */
            *pu8Out ^= uOut.au8[j];
            pu8Out++;
        }

        /* Decrypt the Received MIC */
        if (u8M > 0)
        {
            /* MIC encryption uses block counter = 0 */
            puNonce->au8[14] = 0;
            puNonce->au8[15] = 0;
            (void)AES_128_ECB_Encrypt(
                         (uint8_t*)puNonce,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
            /* Store the MIC for Comparison later */
            pu8Out = uRxedMic.au8;
            pu8In = pau8checksumData;
            for (i = 0; i < u8M; i++)
            {
                *pu8Out = *pu8In ^ uOut.au8[i];
                pu8Out++;
                pu8In++;
            }
        }
    }
    /********************************************/
    /* If we are calculating the MIC, do it now */
    /********************************************/
    if (u8M > 0) /* Only even values are possible, enforced at the start of
                  * the function, so > 0 also implies >= 2, hence there is no
                  * possibility of underflow of the (u8M - 2) calculation
                  * below */
    {
        /* Add in CBC-MAC Flags */
        puNonce->au8[0] =(uint8_t)(  ((u8alength > 0) ? A_DATA : 0)
                                 + (((u8M - 2) / 2) << M_SHIFT)
                                 + ((L_SIZE - 1) << L_SHIFT)
                                );

        /* Add in l(m). The octet order is clearly specified in CCM* as */
        /* 'most-significant-octet first order' */
        puNonce->au8[14] = 0; /* Was: Lo8(u8mlength >> 8); */
        puNonce->au8[15] = Lo8(u8mlength);

        /* Generate the first AES block for CBC-MAC */
        (void)AES_128_ECB_Encrypt(
                         (uint8_t*)puNonce,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
        /* Initialise input counter */
        j = 0;

        /* Encode L(a) at the header if necessary */
        if (u8alength > 0)
        {
            /* Removed XOR with top byte of u8alength, as will always be 0.
             * Was: uOut.au8[j++] ^= Lo8(u8alength >> 8);
             * Now: j++; */
            j++;
            uOut.au8[j++] ^= Lo8(u8alength);
        }

        /* Generate further codes for the MIC in place */
        for (i = 0; i < u8alength; i++)
        {
            /* Perform the CBC XOR */
            uOut.au8[j] ^= pau8authenticationData[i];
            j++;

            /* Full Block, or hit pad boundary */
            if ((j == AES_BLOCK_SIZE) || (i == (u8alength - 1)))
            {
                /* Following is to emulate the hardware bug in the JN5148. The
                   hardware prepended the pair of length bytes in hardware,
                   and although it took in 16 bytes at a time (appended with
                   zeroes as necessary for the last stripe) it only used 14 of
                   them at that time (to complete a 16 byte stripe) and held
                   back 2 bytes for the next stripe. But if the final stripe
                   only consisted of one or both of the held back bytes, there
                   wasn't another stripe coming in from the higher layer and
                   the hardware appended 14 bytes from the previous stripe
                   rather than add zeroes itself. So we emulate this by XORing
                   in those bytes again */
                if (g_bLegacyHwBugEmulation && (j < 3))
                {
                    uint8_t *pu8Data;

                    /* Bug only happens for u8alength of (15 + 16.x) or
                       (16 + 16.x); we aren't bothering with the case where
                       u8alength is 0. In both cases we need to XOR back in
                       the 14 bytes from just before the one or two in this
                       stripe. So if u8alength is 15, there is 1 byte in this
                       stripe and we want bytes 0-13. For u8alength of 16,
                       there are 2 bytes in this stripe and we still want
                       bytes 0-13. Similarly for u8alength of 31 or 32, 47 or
                       48, etc. */
                    pu8Data = &pau8authenticationData[(u8alength - 15) & 0xfe];

                    /* XOR data from previous stripe */
                    for (j = 2; j < AES_BLOCK_SIZE; j++)
                    {
                        uOut.au8[j] ^= *pu8Data;
                        pu8Data++;
                    }
                }
                /* Encrypt the CBC-MAC block, in place */
                (void)AES_128_ECB_Encrypt(
                         (uint8_t*)&uOut,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
                /* the block is now empty */
                j = 0;
            }
        }

        for (i = 0; i < u8mlength; i++)
        {
            /* Perform the CBC XOR */
            uOut.au8[j] ^= pau8Data[i];
            j++;

            /* Full Block, or hit pad boundary */
            if ((j == AES_BLOCK_SIZE) || (i == (u8mlength - 1)))
            {
                /* Encrypt the CBC-MAC block, in place */
               (void)AES_128_ECB_Encrypt(
                         (uint8_t*)&uOut,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
                /* the block is now empty */
                j = 0;
            }
        }

        /* Save the MIC */
        FLib_MemCpy(uCalculatedMic.au8, uOut.au8, u8M);
    }

    /**************************************************/
    /* If we are Encrypting */
    /**************************************************/
    if (bEncrypt)
    {
        /* Encrypt the data */
        pu8Out = pau8Data;

        /* Add in CTR Flags */
        puNonce->au8[0] =(uint8_t)((L_SIZE - 1) << L_SHIFT);
        INITIALISE_NONCE_TOP_BYTE(puNonce->au8);

        u32BlockCnt = 0;
        for (i = 0; i < u8mlength; i++)
        {
            j = i & 0xf;
            if (j == 0)
            {
                /* generate new keystream block */
                /* Start block counter at 1 for PDU; A[0] is for Mic */
                u32BlockCnt++;
                UPDATE_NONCE_COUNTER(puNonce->au8, u32BlockCnt);

                /* Encrypt the Counter */
                (void)AES_128_ECB_Encrypt(
                         (uint8_t*)puNonce,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
            }
            /* XOR in the keystream and copy to output buffer */
            *pu8Out ^= uOut.au8[j];
            pu8Out++;
        }

        /* MIC encryption uses block counter = 0 */
        puNonce->au8[14] = 0;
        puNonce->au8[15] = 0;

        /*---- truncate, encrypt, and append MIC to packet */
        if (u8M > 0)
        {
            /* Encrypt the Counter */
           (void)AES_128_ECB_Encrypt(
                         (uint8_t*)puNonce,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
            /* Append the encrypted MIC */
            pu8Out = pau8checksumData;
            pu8In = uCalculatedMic.au8;
            for (i = 0; i < u8M; i++)
            {
                *pu8Out = *pu8In ^ uOut.au8[i];
                pu8Out++;
                pu8In++;
            }
        }
    }
    else
    {
        /* Compare the Received MIC with Calculated MIC */
        if (FLib_MemCmp(uCalculatedMic.au8, uRxedMic.au8, u8M))
        {
            *pbChecksumVerify = TRUE;
        }
        else
        {
            *pbChecksumVerify = FALSE;
        }
    }
}
