/*!
 * Copyright 2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * \file app_freertos_hooks.c
 * \brief Collection of FreeRTOS hooks implementation
 *
 */

#if defined(FSL_RTOS_FREE_RTOS) || defined(SDK_OS_FREE_RTOS)

#include "FreeRTOS.h"
#include "task.h"

#if defined(configUSE_IDLE_HOOK) && (configUSE_IDLE_HOOK == 1)
void vApplicationIdleHook(void)
{

}
#endif

#if defined(configCHECK_FOR_STACK_OVERFLOW) && (configCHECK_FOR_STACK_OVERFLOW > 0)
void vApplicationStackOverflowHook(TaskHandle_t xTask, char * pcTaskName)
{

}
#endif

#if defined(configUSE_TICK_HOOK) && (configUSE_TICK_HOOK == 1)
void vApplicationTickHook(void)
{

}
#endif

#if defined(configUSE_MALLOC_FAILED_HOOK) && (configUSE_MALLOC_FAILED_HOOK == 1)
void vApplicationMallocFailedHook(void)
{

}
#endif

#endif /* FSL_RTOS_FREE_RTOS || SDK_OS_FREE_RTOS */