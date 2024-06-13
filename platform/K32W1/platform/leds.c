/*
* Copyright 2023 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <stdint.h>
#include <stdbool.h>
#include "board.h"
#include "board_comp.h"
#include "pin_mux.h"
#include "fsl_component_led.h"

/* Number of leds on K32W1480-EVK board */
#define BOARD_LEDS_NUM (2)

static uint8_t app_num_leds;
static uint8_t app_state_leds;
static void initRgbLed(void);
static void initMonochromeLed(void);

static uint32_t monochrome_gpio_handle[((HAL_GPIO_HANDLE_SIZE + sizeof(uint32_t) - 1U) / sizeof(uint32_t))];
static hal_gpio_pin_config_t monochrome_pin_config =
{
	.direction = kHAL_GpioDirectionOut,
	.level = BOARD_MONOCHROME_GPIO_PIN_DEFAULT_STATE,
	.port = BOARD_MONOCHROME_GPIO_PORT_INSTANCE,
	.pin = BOARD_MONOCHROME_GPIO_PIN,
};

static uint32_t rgb_gpio_handles[3][((HAL_GPIO_HANDLE_SIZE + sizeof(uint32_t) - 1U) / sizeof(uint32_t))];
static hal_gpio_pin_config_t rgb_pin_config[3] =
{
	{
		.direction = kHAL_GpioDirectionOut,
		.level = BOARD_RGB_RED_GPIO_PIN_DEFAULT_STATE,
		.port  = BOARD_RGB_RED_GPIO_PORT_INSTANCE,
		.pin   = BOARD_RGB_RED_GPIO_PIN,
	},
	{
		.direction = kHAL_GpioDirectionOut,
		.level = BOARD_RGB_GREEN_GPIO_PIN_DEFAULT_STATE,
		.port  = BOARD_RGB_GREEN_GPIO_PORT_INSTANCE,
		.pin   = BOARD_RGB_GREEN_GPIO_PIN,
	},
	{
		.direction = kHAL_GpioDirectionOut,
		.level = BOARD_RGB_BLUE_GPIO_PIN_DEFAULT_STATE,
		.port  = BOARD_RGB_BLUE_GPIO_PORT_INSTANCE,
		.pin   = BOARD_RGB_BLUE_GPIO_PIN,
	}
};

static void deinitRgbLed(void)
{
	uint8_t i = 0;
	for (;i < 3; i++)
	{
		HAL_GpioDeinit(rgb_gpio_handles[i]);
	}
}

static void deinitMonochromeLed(void)
{
	HAL_GpioDeinit(monochrome_gpio_handle);
}

static void initRgbLed(void)
{
    uint8_t i = 0;

	/* RGB Led BOARD pins */
    BOARD_InitPinLED2();
    BOARD_InitPinLED3();
    BOARD_InitPinLED4();

    for (;i < 3; i++)
    {
    	HAL_GpioInit(rgb_gpio_handles[i], &rgb_pin_config[i]);
        HAL_GpioSetOutput(rgb_gpio_handles[0], rgb_pin_config[i].level);
    }
}

static void initMonochromeLed(void)
{
    BOARD_InitPinLED1();
	HAL_GpioInit(monochrome_gpio_handle, &monochrome_pin_config);
    HAL_GpioSetOutput(monochrome_gpio_handle, monochrome_pin_config.level);
}

static void deinitLeds(void)
{
	if (app_num_leds == 0)
	{
		return;
	}

	deinitRgbLed();

	if (app_num_leds > 1)
	{
		deinitMonochromeLed();
	}

	app_num_leds = 0;
}

bool zbPlatLedInit(uint8_t num_leds)
{
    if (num_leds == 0 || num_leds > BOARD_LEDS_NUM)
    {
        return false;
    }

    /* Deinit Leds to avoid double init conflicts */
    deinitLeds();

    app_num_leds = num_leds;
    app_state_leds = 0;

    /* Always enable at least one LED */
    initRgbLed();

    /* Init LED2(Monochrome) if needed */
    if (app_num_leds > 1)
    {
        initMonochromeLed();
    }

    return true;
}

void zbPlatLedSetState(uint8_t led, uint8_t state)
{
    if (app_num_leds == 0 || led > app_num_leds)
    {
        return;
    }

    /* Clear state led and save new state */
    app_state_leds &= ~(1 << led);
    app_state_leds |= ((state ? 1 : 0) << led);

    switch(led) {
		case 0: /* RGB LED */
		    for (uint8_t i = 0; i < 3; i++)
		    {
		        HAL_GpioSetOutput(rgb_gpio_handles[i], (state != 0) ?
		        		(1 - (uint8_t)rgb_pin_config[i].level):
		        		rgb_pin_config[i].level);
		    }
			break;
		case 1: /* Monochrome LED */
	        HAL_GpioSetOutput(monochrome_gpio_handle, (state != 0) ?
	        		(1 - (uint8_t)monochrome_pin_config.level):
					monochrome_pin_config.level);
		default:
			break;
    }
}

uint8_t zbPlatLedGetStates(void)
{
	if (app_num_leds == 0)
	{
		return 0;
	}

	return app_state_leds;
}
