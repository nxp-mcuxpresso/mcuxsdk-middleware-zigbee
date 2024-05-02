/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier:    BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sched.h>

#include "dbg.h"
#include "linux_glue.h"

const uint8_t gUseRtos_c = 1;

#include <sys/select.h>
#include <assert.h>

void SecLib_Init()
{
    fprintf(stderr, "%s\n", __func__);
}

void vMMAC_SetTxPowerMode(bool_t mode)
{
    fprintf(stderr,"%s\n", __func__);
}

uint16 u16Read16Nbo(uint8 *pu8Payload)
{
    uint16 u16Ret;
    u16Ret = *pu8Payload++;
    u16Ret |= (*pu8Payload << 8);
    return u16Ret;
}

/*******************************************/
PUBLIC void vSleep(uint32 u32ms)
{
#if 0
    struct timespec ts;
    ts.tv_sec = u32ms / 1000ul;            // whole seconds
    ts.tv_nsec = (u32ms % 1000000ul) * 1000000;  // remainder, in nanoseconds
    nanosleep(&ts, NULL);
#else
    usleep(u32ms * 1000);
    sched_yield();
#endif
}

PUBLIC void APP_vNcpHostReset()
{
    kill(getpid(), SIGHUP);
}
void restartUARTRegs()
{
    fprintf(stderr, "%s - not doing anything\r\n", __func__);
    //close(ncp_fd);
    //open(ncp_fd)

}

/** AES related stuff, should be replaced by crypto services */
void AESSW_vMMOBlockUpdate(AESSW_Block_u *puHash,
                           AESSW_Block_u *puBlock)
{
    fprintf(stderr, "%s - not implemented\r\n", __func__);
}

void vSwipeEndian(AESSW_Block_u *puBlock, tsReg128 *psReg, bool_t bBlockToReg)
{
    fprintf(stderr, "%s - not implemented\r\n", __func__);
}
void AESSW_vMMOFinalUpdate(AESSW_Block_u *puHash,
                           uint8_t *pu8Data,
                           int iDataLen,
                           int iFinalLen)
{
    fprintf(stderr, "%s - not implemented\r\n", __func__);
}
