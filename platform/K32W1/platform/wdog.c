/*
* Copyright 2023 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <fsl_wdog32.h>
#include <fsl_cmc.h>
#include <dbg.h>
#include <fsl_os_abstraction.h>
#include <zb_platform.h>

#ifndef WDOG_TIMEOUT_PERIOD
#define WDOG_TIMEOUT_PERIOD             (6)     /* seconds */
#endif

#ifndef WDOG_RESETS_DEVICE
#define WDOG_RESETS_DEVICE              (1)
#endif

static int (*wdog_int_pr_fp)(void *);
static int (*wdog_int_ep_fp)(void *);
static int (*wdog_reset_fp)(void *);

static void ExceptionUnwindStack(uint32_t * pt)
{
    extern void *__StackTop;
    PRINTF("\r\n stack dump:\r\n");
    while ((uint32)pt < (uint32)&__StackTop )
    {
        PRINTF("0x%x  0x%x \r\n",pt, *pt);
        pt++;
        zbPlatWdogKick();
    }
}

static int zbWdogIntDefaultPrologue(void *p)
{
    (void)p;

    ExceptionUnwindStack((uint32_t *) __get_MSP());
#if defined(WDOG_RESETS_DEVICE) && (WDOG_RESETS_DEVICE == 1)
    DBG_vPrintf(TRUE, "APP: Watchdog RESETS device !\n");
#else
    DBG_vPrintf(TRUE, "APP: Watchdog halted device !\n");
#endif /* defined(WDOG_RESETS_DEVICE) && (WDOG_RESETS_DEVICE == 1) */

    return 0;
}

void WDOG0_IRQHandler(void)
{
    WDOG0->CS |= WDOG_CS_FLG_MASK;

    MRCC->MRCC_WDOG0 = 0;   /* Kill clock to WDOG0 */

    if (wdog_int_pr_fp != NULL)
    {
        /* If the user registered its own WDOG handler, execute it */
        wdog_int_pr_fp(NULL);
    }
    else
    {
        /*
         * Otherwise, execute the default one which dumps stack &
         * resets/halts the CPU
        */
        zbWdogIntDefaultPrologue(NULL);
    }

    /*
     * We may have additional processing that's required by the user in its app,
     * especially if the WDOG INT is shared with other interrupts i.e. BOD.
     * So allow here to do some more processing. Of course, if the WDOG triggers
     * a reset or an infinite loop above,  then this will never get executed.
     *
     */
    if (wdog_int_ep_fp != NULL)
    {
        wdog_int_ep_fp(NULL);
    }

#if defined(WDOG_RESETS_DEVICE) && (WDOG_RESETS_DEVICE == 1)
    MRCC->MRCC_WDOG0 = 1;   /* Restore clock => the RST signal will propagate */
#else
    while(1);
#endif
    SDK_ISR_EXIT_BARRIER;
}

void zbPlatWdogIntRegisterEpilogue(int (*fp)(void *))
{
    if (fp != NULL)
    {
        wdog_int_ep_fp = fp;
    }
}

void zbPlatWdogIntRegisterPrologue(int (*fp)(void *))
{
    if (fp != NULL)
    {
        wdog_int_pr_fp = fp;
    }
}

void zbPlatWdogRegisterResetCheckCallback(int (*fp)(void *))
{
    if (fp != NULL)
    {
        wdog_reset_fp = fp;
    }
}

void zbPlatWdogKick(void)
{
    OSA_InterruptDisable();
    /* Don't access IP regs if clock is off => bus fault */
    if (MRCC->MRCC_WDOG0)
    {
        WDOG32_Refresh(WDOG0);
    }
    OSA_InterruptEnable();
}

void zbPlatWdogInit(void)
{
    static wdog32_config_t config;

    /*
     * NOTE: After the system boot up, WDOG32 is disabled. We must wait for at
     *       least 2.5 periods of WDOG32 clock to reconfigure.
     *       The assumption here is that the initialization of the WDOG32 is done
     *       late enough in the boot flow that we don't need to worry about it.
     *       Otherwise, a delay might be required.
     */

    /*
     * config.enableWdog32 = true;
     * config.clockSource = kWDOG32_ClockSource1;
     * config.prescaler = kWDOG32_ClockPrescalerDivide1;
     * config.testMode = kWDOG32_TestModeDisabled;
     * config.enableUpdate = true;
     * config.enableInterrupt = false;
     * config.enableWindowMode = false;
     * config.windowValue = 0U;
     * config.timeoutValue = 0xFFFFU;
     */
    WDOG32_GetDefaultConfig(&config);

    config.testMode = kWDOG32_UserModeEnabled;
    config.enableInterrupt = true;

    config.clockSource  = kWDOG32_ClockSource1; /* 32kHz */
    config.prescaler    = kWDOG32_ClockPrescalerDivide256; /* 125 Hz */
    config.timeoutValue = 125 * WDOG_TIMEOUT_PERIOD;

    /* Enable clock before accessing IP registers */
    MRCC->MRCC_WDOG0 = 1;

    WDOG32_Init(WDOG0, &config);
    EnableIRQ(WDOG0_IRQn);

}

void zbPlatWdogDeInit(void)
{
    WDOG32_Unlock(WDOG0);

    /* Clear int flag if set */
    WDOG32_ClearStatusFlags(WDOG0, kWDOG32_InterruptFlag);

    /* Disable interrupts */
    WDOG32_DisableInterrupts(WDOG0, kWDOG32_InterruptEnable);

    /* Deinit WDOG */
    WDOG32_Deinit(WDOG0);

    /* Disable clock */
    MRCC->MRCC_WDOG0 = 0;

    DisableIRQ(WDOG0_IRQn);
}

void zbPlatWdogResetCheckSource(void)
{
    if ((CMC_GetSystemResetStatus(CMC0) & kCMC_Watchdog0Reset))
    {
        zbPlatWdogDeInit();
        if (wdog_reset_fp != NULL)
        {
            wdog_reset_fp(NULL);
        }
    }
}
