/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SEC_LIB_H
#define SEC_LIB_H

#include "EmbeddedTypes.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define AES_128_BLOCK_SIZE 16u /* [bytes] */
#define AES_BLOCK_SIZE 16u /* [bytes] */
#define AESSW_BLK_SIZE (AES_BLOCK_SIZE)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/* Security block definition */
typedef union
{
    uint8_t    au8[AES_BLOCK_SIZE];
    uint32_t   au32[AES_BLOCK_SIZE / 4];
} tuAES_Block;

/* For backwards compatibility */
typedef tuAES_Block AESSW_Block_u;

typedef struct
{
    uint32_t u32register0;
    uint32_t u32register1;
    uint32_t u32register2;
    uint32_t u32register3;
} tsReg128;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

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
 * \brief This function setups the key in the AES.
 *
 * \param [in] psKeyData               tsReg128 key split over 4 words (16 bytes)
 *
 ****************************************************************************/
bool_t bACI_WriteKey(tsReg128 *psKeyData);

/****************************************************************************
 * \brief  This function performs CCM* AES encryption/decryption with checksum
 *         generation/verification. Assumes input buffers are aligned and nonce has a
 *         free byte at the start for the flags field
 *
 * \param [in] bEncrypt               TRUE to encrypt, FALSE to decrypt
 * \param [in] u8M                    Required number of checksum bytes
 * \param [in] u8alength              Length of authentication data, in bytes
 * \param [in] u8mlength              Length of input data, in bytes
 * \param [in] puNonce                Pre-allocated pointer to a structure
 *                                    containing 128-bit Nonce data
 * \param [in] pau8authenticationData Pre-allocated pointer to byte array of
 *                                    authentication data
 * \param [in] pau8Data               Pre-allocated pointer to byte array of input
 *                                    and output data
 * \param [in] pau8checksumData       Pre-allocated pointer to byte array of
 *                                    checksum data
 * \param [in] pbChecksumVerify       Pre-allocated pointer to boolean which in CCM
 *                                    decode mode stores the result of the checksum
 *                                    verification operation
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
                           bool_t        *pbChecksumVerify);


#endif /* SEC_LIB_H */
