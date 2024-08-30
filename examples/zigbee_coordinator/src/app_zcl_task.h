/*
* Copyright 2019, 2023 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/


#ifndef APP_ZCL_TASK_H_
#define APP_ZCL_TASK_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/

#include "EmbeddedTypes.h"
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
void APP_ZCL_vSetIdentifyTime(uint16_t u16Time);
void APP_cbTimerZclTick(void *pvParam);
void APP_ZCL_vTask(void);
void APP_ZCL_vEventHandler(ZPS_tsAfEvent *psStackEvent);
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
