/*
* Copyright 2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "fsl_os_abstraction.h"
#include "app_zigbee.h"
#include "app_shell.h"
#include "app.h"
#include "dbg.h"

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
static void shell_init_task(void *argument);

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
static OSA_TASK_HANDLE_DEFINE(s_shellTaskHandle);
static OSA_TASK_DEFINE(shell_init_task, gMainThreadPriority_c, 1, gMainThreadStackSize_c, 0);

/****************************************************************************/
/***        Main Function                                                 ***/
/****************************************************************************/
int main(void)
{
    OSA_Init();

    BOARD_InitHardware();

    if (APP_InitZigbee() < 0)
    {
        assert(0);
    }

    /* Shell init task */
    if(OSA_TaskCreate((osa_task_handle_t)s_shellTaskHandle, OSA_TASK(shell_init_task), NULL) != KOSA_StatusSuccess)
    {
        assert(0);
    }

    /* Start scheduler*/
    OSA_Start();

    /*won't run here*/
    assert(0);
    return 0;
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
static void shell_init_task(void *argument)
{
    /* SHELL init performs blocking prints and this will hang the task
     * until a BLE peer device connects and receives the print.
     */
    if (APP_ShellInit() < 0)
    {
        DBG_vPrintf(TRUE, "SHELL init error \n");
        assert(0);
    }

    if (OSA_TaskDestroy(s_shellTaskHandle) != KOSA_StatusSuccess)
    {
        DBG_vPrintf(TRUE, "Failed to destroy shell task\n");
    }
}
