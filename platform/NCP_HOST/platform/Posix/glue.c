/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Glue file for undefined symbols
 * Used as a intermediate step in compiling ZR for K32W1480 NCP platform
 */
#include "pwrm.h"

/* PWRM Part */
PUBLIC PWRM_teStatus PWRM_eStartActivity(void)
{
    /* NOT IMPLEMENTED */
    return PWRM_E_OK;
}

PUBLIC PWRM_teStatus PWRM_eFinishActivity(void)
{
    /* NOT IMPLEMENTED */
    return PWRM_E_OK;
}

/* OSA Interrupt restricted */
void RESET_SystemReset()
{
    /* NOT IMPLEMENTED */
    return;
}

/* Board Part */
void BOARD_InitHardware(void)
{
    /* NOT IMPLEMENTED */
    return;
}

void BOARD_SetClockForPowerMode(void)
{
    /* NOT IMPLEMENTED */
    return;
}

/* Board Part */
void MEM_Init()
{
    /* NOT IMPLEMENTED */
    return;
}
