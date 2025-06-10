/*
* Copyright 2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/


/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "fsl_os_abstraction.h"
#include "app.h"
#include "app_conn.h"
#include "zigbee_config.h"
#include "app_router_node.h"
#include "fwk_platform.h"
#include "app_zigbee.h"

#if defined(gAppUseSensors_d) && (gAppUseSensors_d > 0)
#include "sensors.h"
#endif

#if defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 0)
/* board_comp.h only required for above services   */
#include "board_comp.h"
#endif

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
void APP_InitZigbee(void);

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
extern void vAppMain(void);

/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/
int main(void)
{
    OSA_Init();

    BOARD_InitHardware();

    /* Initialize Timers for Application */
    (void)PLATFORM_InitTimerManager();

#if defined(gAppUseSensors_d) && (gAppUseSensors_d > 0)
    /* for battery/temperature  measurement */
    SENSORS_Init();

    /* Trig the ADC on the battery voltage during initialization for BLE battery service profile
      SENSORS_RefreshBatteryLevel() shall be called at second step to get the updated value*/
    SENSORS_TriggerBatteryMeasurement();
#endif

#if (defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 0))
    /* init application serial manager*/
    BOARD_InitSerialManager((serial_handle_t)gSerMgrIf);
#endif

#if defined(gAppUseSensors_d) && (gAppUseSensors_d > 0)
    /* Measure battery voltage during initialization for BLE battery service profile */
    (void)SENSORS_RefreshBatteryLevel();
#endif

#if defined(gAppLowpowerEnabled_d) && (gAppLowpowerEnabled_d > 0)
    APP_ServiceInitLowpower();
#endif

    (void)APP_InitBle();
    (void)APP_InitZigbee();

    /* Example of baremetal loop if user doesn't want to use OSA API */
#if (FSL_OSA_BM_TIMER_CONFIG != FSL_OSA_BM_TIMER_NONE)
    extern void OSA_TimeInit(void);
    OSA_TimeInit();
#endif

    BluetoothLEHost_AppInit();

    while(TRUE)
    {
        OSA_ProcessTasks();
        BluetoothLEHost_HandleMessages();
        /* Before executing WFI, need to execute some connectivity background tasks
            (usually done in Idle thread) such as NVM save in Idle, etc.. */
        BluetoothLEHost_ProcessIdleTask();

        /* place event handler code here... */
        APP_vRunZigbee();
        ZTIMER_vTask();
        APP_taskRouter();

        OSA_DisableIRQGlobal();

        /* Check if some connectivity tasks have turned to ready state from interrupts or
              if messages are to be processed in Application process */
        if (( OSA_TaskShouldYield() == FALSE ) &&
            ( BluetoothLEHost_IsMessagePending() == FALSE ) &&
            (BluetoothLEHost_IsConnectivityTaskToProcess() == FALSE))
        {
            __WFI();
        }

        OSA_EnableIRQGlobal();
    }

    /* Won't run here */
    assert(0);
    return 0;
}

/****************************************************************************
 *
 * NAME: APP_InitZigbee
 *
 * DESCRIPTION:
 * Init Zigbee
 *
 * RETURNS:
 * 0 if success, negative values in case of failure
 *
 ****************************************************************************/
void APP_InitZigbee(void)
{

#if IS_MCXW_SERIES
    PLATFORM_SwitchToOsc32k();
#endif

    CRYPTO_Init();
    CRYPTO_u8RandomInit();
    MEM_Init();

#if IS_MCXW_SERIES
#if defined(USE_NBU) && (USE_NBU == 1)
    PLATFORM_InitNbu();
    PLATFORM_InitMulticore();
    PLATFORM_FwkSrvInit();
    PLATFORM_SendChipRevision();
    PLATFORM_LoadHwParams();
#endif
#endif

    vAppMain();
}

/*! *********************************************************************************
 * @}
 ********************************************************************************** */
