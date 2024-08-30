/*!
 * \file wdog.c
 * \brief ZB platform abstraction implementation for watchdog module
 *
 * Copyright 2024 NXP
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <zb_platform.h>

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void zbPlatWdogIntRegisterEpilogue(int (*fp)(void *))
{
    /* NOT IMPLEMENTED */
}

void zbPlatWdogIntRegisterPrologue(int (*fp)(void *))
{
    /* NOT IMPLEMENTED */
}

void zbPlatWdogRegisterResetCheckCallback(int (*fp)(void *))
{
    /* NOT IMPLEMENTED */
}

void zbPlatWdogKick(void)
{
    /* NOT IMPLEMENTED */
}

void zbPlatWdogInit(void)
{
    /* NOT IMPLEMENTED */
}

void zbPlatWdogDeInit(void)
{
    /* NOT IMPLEMENTED */
}

void zbPlatWdogResetCheckSource(void)
{
    /* NOT IMPLEMENTED */
}
