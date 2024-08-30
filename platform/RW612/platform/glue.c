/*!
 * \file glue.c
 * \brief Glue file for undefined symbols. Used as a intermediate step in compiling ZR for K32W1480 platform
 *
 * Copyright 2024 NXP
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */



#include "fsl_common.h"

/* PWRM Part */
#include "pwrm.h"

PUBLIC PWRM_teStatus PWRM_vInit(PWRM_tePowerMode ePowerMode)
{
    /* NOT IMPLEMENTED */
    return 0;
}

PUBLIC void PWRM_vManagePower(void)
{
    /* NOT IMPLEMENTED */
    return;
}

PUBLIC PWRM_teStatus PWRM_vWakeUpIO(uint32_t io_mask)
{
    /* NOT IMPLEMENTED */
    return 0;
}

PUBLIC PWRM_teStatus PWRM_vWakeUpConfig(uint32_t pwrm_config)
{
    /* NOT IMPLEMENTED */
    return 0;
}

PUBLIC void PWRM_vForceRamRetention(uint32_t u32RetainBitmap)
{
    /* NOT IMPLEMENTED */
    return;
}

PUBLIC void PWRM_vForceRadioRetention(bool_t bRetain)
{
    /* NOT IMPLEMENTED */
    return;
}

/* OSA Interrupt restricted */
#include "fsl_os_abstraction.h"

void OSA_InterruptEnableRestricted(uint32_t *pu32OldIntLevel)
{
   /* Disable interrupts for duration of this function */
   OSA_DisableIRQGlobal();

   /* Store old priority level */
   *pu32OldIntLevel = __get_BASEPRI();

   /* Update priority level, but only if it is a more restrictive value */
   __set_BASEPRI_MAX(((3U << (8U - __NVIC_PRIO_BITS)) & 0xffU));

   /* Restore interrupts */
   OSA_EnableIRQGlobal();
}

void OSA_InterruptEnableRestore(uint32_t *pu32OldIntLevel)
{
   // write value direct into register ARM to ARM, no translations required
   __set_BASEPRI(*pu32OldIntLevel);
}


WEAK void __assertion_failed(char *failedExpr)
{
    assert(0);
}

WEAK void _exit(int __status)
{
    while (1) {}
}

WEAK void panic(uint32_t id, uint32_t location, uint32_t extra1, uint32_t extra2)
{
}

void RESET_SystemReset()
{
    NVIC_SystemReset();
}


#include "MiniMac.h"
uint8 u8MiniMac_RunTimeOptions;
tsMiniMacPib sMiniMacPib;

void vMiniMac_PurgeAssocResp(tsExtAddr *psSearchAddr, bool_t bCallCallback)
{
}

uint32 zps_eSocMacSetTxBuffers (uint8 u8MaxTxBuffers)
{
    return 0;
}

void zps_vSocMac_InterruptHandler(void)
{
    return;
}

void ZPS_vNwkGenerateLeaveCmd(uint32_t a, void *b, uint16_t c)
{
    return;
}

void vAppApiSaveMacSettings(void)
{
    return;
}

/* ZPS_vMacHandleMcpsVsReqRsp(), AtGp_bSendGPDFS(), app_atgp_cmds.c */
void *pvAppApiGetMacHandle(void)
{
    /* No MAC handle */
    return NULL;
}