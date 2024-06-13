/*!
 * \file timer.c
 * \brief ZB platform abstraction implementation for timer module
 *
 * Copyright 2024 NXP
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>

#include "zb_platform.h"
#include "fwk_platform.h"

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

uint32_t zbPlatGetTime(void)
{
    /* PLATFORM_GetTimeStamp() returns usec */
    return (uint32_t)(PLATFORM_GetTimeStamp() / 1000U);
}
