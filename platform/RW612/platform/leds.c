
/*!
 * \file leds.c
 * \brief ZB platform abstraction implementation for leds module
 *
 * Copyright 2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "board_comp.h"

#if (defined(BOARD_RGB_LED_COUNT) && (BOARD_RGB_LED_COUNT > 0)) \
    && (defined(gAppLedCnt_c) && (gAppLedCnt_c > 0))
#include "fsl_component_led.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static uint8_t app_state_leds = 0U;

#if (defined(BOARD_RGB_LED_COUNT) && (BOARD_RGB_LED_COUNT > 0)) \
    && (defined(gAppLedCnt_c) && (gAppLedCnt_c > 0))
static LED_HANDLE_DEFINE(ledHandle);
#endif

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

bool zbPlatLedInit(uint8_t num_leds)
{
    (void)num_leds;

#if (defined(BOARD_RGB_LED_COUNT) && (BOARD_RGB_LED_COUNT > 0)) \
    && (defined(gAppLedCnt_c) && (gAppLedCnt_c > 0))
    BOARD_InitRgbLed(ledHandle);
    LED_SetColor(ledHandle, LED_MAKE_COLOR(0, 0, 0));
    LED_TurnOnOff(ledHandle, 1);
#endif

    return true;
}

void zbPlatLedSetState(uint8_t led, uint8_t state)
{
    /* Clear state led and save new state */
    app_state_leds &= ~(1 << led);
    app_state_leds |= ((state ? 1 : 0) << led);

#if (defined(BOARD_RGB_LED_COUNT) && (BOARD_RGB_LED_COUNT > 0)) \
    && (defined(gAppLedCnt_c) && (gAppLedCnt_c > 0))
    bool red = ((app_state_leds & 1) != 0);
    bool green = ((app_state_leds & (1 << 1)) != 0);
    bool blue = ((app_state_leds & (1 << 2)) != 0);

    /* Update the RGB color depending on the LED states
     * Note: GPIO logic is inverted, so we set to 0 to switch on the LED */
    LED_SetColor(ledHandle, LED_MAKE_COLOR(red ? 0 : 255, green ? 0 : 255, blue ? 0 : 255));
    LED_TurnOnOff(ledHandle, 1);
#endif
}

uint8_t zbPlatLedGetStates(void)
{
    return app_state_leds;
}
