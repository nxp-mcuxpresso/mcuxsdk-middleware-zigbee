/*!
 * \file zb_cmsis_nvic_virtual.h
 * \brief Header file used to redefine some NVIC CMSIS macros. This file is included by core_<core>.h from CMSIS if
 *        CMSIS_NVIC_VIRTUAL and CMSIS_NVIC_VIRTUAL_HEADER_FILE are defined accordingly.
 *
 * Copyright 2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _ZB_CMSIS_NVIC_VIRTUAL_H_
#define _ZB_CMSIS_NVIC_VIRTUAL_H_

#include "fwk_platform_coex.h"

#define NVIC_SetPriorityGrouping    __NVIC_SetPriorityGrouping
#define NVIC_GetPriorityGrouping    __NVIC_GetPriorityGrouping
#define NVIC_EnableIRQ              __NVIC_EnableIRQ
#define NVIC_GetEnableIRQ           __NVIC_GetEnableIRQ
#define NVIC_DisableIRQ             __NVIC_DisableIRQ
#define NVIC_GetPendingIRQ          __NVIC_GetPendingIRQ
#define NVIC_SetPendingIRQ          __NVIC_SetPendingIRQ
#define NVIC_ClearPendingIRQ        __NVIC_ClearPendingIRQ
#define NVIC_GetActive              __NVIC_GetActive
#define NVIC_SetPriority            __NVIC_SetPriority
#define NVIC_GetPriority            __NVIC_GetPriority
#define NVIC_SystemReset()          do \
                                    { \
                                        PLATFORM_TerminateControllers(conn802_15_4_c); \
                                        __NVIC_SystemReset(); \
                                    } while(0);

#endif /* _ZB_CMSIS_NVIC_VIRTUAL_H_ */