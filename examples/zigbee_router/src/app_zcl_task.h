/*
* Copyright 2019 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/****************************************************************************/
/* Description.                                                             */
/* If you do not need this file to be parsed by doxygen then delete @file   */
/****************************************************************************/

/** @file
 * Add brief description here.
 * Add more detailed description here
 */

/****************************************************************************/
/* Description End                                                          */
/****************************************************************************/

#ifndef APP_ZCL_TASK_H_
#define APP_ZCL_TASK_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/

#include "zcl.h"
#include "base_device.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
void APP_ZCL_vInitialise(void);
void APP_ZCL_vSetIdentifyTime(uint16 u16Time);
void APP_cbTimerZclTick(void *pvParam);
void APP_ZCL_vTask(void);
void APP_ZCL_vEventHandler(ZPS_tsAfEvent *psStackEvent);
#ifdef CLD_IDENTIFY_10HZ_TICK
    void vIdEffectTick(uint8_t u8Endpoint);
#endif
#ifdef NCP_HOST
PUBLIC ZPS_teStatus APP_eZbModuleInitialise(void);
#endif
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

extern tsZHA_BaseDevice sBaseDevice;

#endif /* APP_ZCL_TASK_H_ */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
