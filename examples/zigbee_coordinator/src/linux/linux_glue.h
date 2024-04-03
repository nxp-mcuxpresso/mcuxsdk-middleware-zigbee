/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier:    BSD-3-Clause
 */

#ifndef __LINUX_GLUE_H__
#define __LINUX_GLUE_H__
#include <pdum_apl.h>
#include <signal.h>

#include "zps_apl_aib.h"
#include "pdum_gen.h"

#define JENNIC_CHIP_FAMILY_JN518x

#ifndef APDU_PAYLOAD_SIZE
#define APDU_PAYLOAD_SIZE    1600U
#endif

#define FSL_OSA_TIME_RANGE          (0xFFFFFFFF)

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void vSleep(uint32 u32ms);
PUBLIC void APP_vNcpHostReset();

PUBLIC bool eSL_SearchExtendedPanId(uint64 u64ExtPanId, uint16 u16PanId);

void SecLib_Init();

void ZTIMER_vTask(void);

void vSwipeEndian(AESSW_Block_u *puBlock, tsReg128 *psReg, bool_t bBlockToReg);

#endif /*  __LINUX_GLUE_H__ */
