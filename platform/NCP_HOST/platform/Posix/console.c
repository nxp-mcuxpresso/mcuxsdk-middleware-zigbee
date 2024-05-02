/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <assert.h>

#include "app_console.h"
#include "zb_platform.h"
#include "dbg.h"

bool zbPlatConsoleInit(void)
{
    struct termios term;

    /* Obtain terminal attributes */
    if (tcgetattr(STDIN_FILENO, &term))
    {
        DBG_vPrintf(TRACE_CONSOLE, "Failed to retrieve terminal attributes\r\n");
        return false;
    }

    /* Disable character echo and canonical input processing */
    term.c_lflag &= ~(ECHO | ICANON);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &term))
    {
        DBG_vPrintf(TRACE_CONSOLE, "Failed to set terminal attributes\r\n");
        return false;
    }

    return true;
}

bool zbPlatConsoleReceiveChar(uint8_t *pu8Data)
{
    bool bRet = FALSE;
    int iRet;
    fd_set rd;

    struct timeval tv;
    int err;

    FD_ZERO(&rd);
    FD_SET(STDIN_FILENO, &rd);

    tv.tv_sec  = 0;
    tv.tv_usec = 100;
    err = select(1, &rd, NULL, NULL, &tv);
    if ((err != 0) && (err != -1))
    {
        iRet = read(STDIN_FILENO, pu8Data, 1);
        bRet = TRUE;
        assert(iRet > 0);
        err = select(1, &rd, NULL, NULL, &tv);
    }

    return bRet;
}
