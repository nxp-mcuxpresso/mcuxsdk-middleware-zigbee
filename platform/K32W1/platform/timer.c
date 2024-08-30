/*
* Copyright 2023-2024 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#include <stdint.h>
#include <stdbool.h>
#include "zb_platform.h"
#include "board.h"
#include "app.h"
#include "fsl_os_abstraction.h"
#include "fsl_component_timer_manager.h"

#if (FSL_OSA_BM_TIMER_CONFIG == FSL_OSA_BM_TIMER_NONE) && \
    (!defined(TM_ENABLE_TIME_STAMP) || TM_ENABLE_TIME_STAMP == 0)
#error "Either enable SysTick as a timebase for the OSA BM or enable timestamp support"
#endif

uint32_t zbPlatGetTime(void)
{
#if (FSL_OSA_BM_TIMER_CONFIG != FSL_OSA_BM_TIMER_NONE)
    return OSA_TimeGetMsec();
#else
    return (uint32_t)(TM_GetTimestamp() / 1000U); /* TM_GetTimestamp() returns usec */
#endif
}
