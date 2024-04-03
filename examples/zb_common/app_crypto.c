/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include "zb_platform.h"
#include "app_crypto.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: CRYPTO_u8RandomInit
 *
 * DESCRIPTION:
 * Initialize the random number generator unit
 *
 * PARAMETERS:      Name            RW  Usage
 *
 * RETURNS:
 * status of initialization
 *
 ****************************************************************************/
uint8_t CRYPTO_u8RandomInit(void)
{
    return zbPlatCryptoRandomInit();
}

/****************************************************************************
 *
 * NAME: CRYPTO_u32RandomGet
 *
 * DESCRIPTION:
 * Returns a 32-bit statistically random generated number, between the
 * specified mininum and maximum values
 *
 * PARAMETERS:      Name            RW  Usage
 *                  u32Min           	minimum value
 *                  u32Max				maximum value
 *
 * RETURNS:
 * random generated number
 *
 ****************************************************************************/
uint32_t CRYPTO_u32RandomGet(uint32_t u32Min, uint32_t u32Max)
{
    return zbPlatCryptoRandomGet(u32Min, u32Max);
}

/****************************************************************************
 *
 * NAME: CRYPTO_u32Random256Get
 *
 * DESCRIPTION:
 * Returns a 32-bit statistically random generated number
 *
 * PARAMETERS:      Name            RW  Usage
 *
 * RETURNS:
 * random generated number
 *
 ****************************************************************************/
uint32_t CRYPTO_u32Random256Get(void)
{
    return zbPlatCryptoRandom256Get();
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/