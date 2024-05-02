/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "aessw_ccm.h"


/****************************************************************************
 *
 * NAME:       vSwipeEndian
 */
/**
 * Reverses 1282bit data between AESSW_Block_u and tsReg128
 *
 *
 * @param puBlock  128 bit data of type AESSW_Block_u
 *
 * @param psReg  128 bit data of type  tsReg128
 *
 * @param bBlockToReg  direction of converesion
 *                      1 = AESSW_Block_u to tsReg128
 *                      0 = tsReg128 to AESSW_Block_u
 *
 * @return
 *
 * @note
 *
 ****************************************************************************/
PUBLIC void vSwipeEndian(AESSW_Block_u *puBlock, tsReg128 *psReg, bool_t bBlockToReg)
{
    /* NOT IMPLEMENTED */
    return;
}

/****************************************************************************
 *
 * NAME: ZPS_eEnterCriticalSection
 *
 * DESCRIPTION:  Provides protection from function re-entrancy and interrupt
 *               pre-emption.
 *               
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC uint8 ZPS_eEnterCriticalSection(void* hMutex, uint32* psIntStore)
{
    /* NOT IMPLEMENTED */
    return 0;
}

/****************************************************************************
 *
 * NAME: ZPS_eExitCriticalSection
 *
 * DESCRIPTION:  Allows interrupt pre-emption and function re-entrancy.
 *               
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC uint8 ZPS_eExitCriticalSection(void* hMutex , uint32* psIntStore)
{
    /* NOT IMPLEMENTED */
    return 0;
}


