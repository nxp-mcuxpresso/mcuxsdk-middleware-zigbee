/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _MCU_SDK_ADAPTER_H_
#define _MCU_SDK_ADAPTER_H_

/*
 * This is required because of a limitation of the MCUX SDK Kconfig
 * system that for CONFIG_ variables that are assigned the value 'n'
 * no corresponding #define is emitted.
 */

#ifndef CONFIG_ZB_COORD_TRACE_APP
#define CONFIG_ZB_COORD_TRACE_APP 0
#endif

#ifndef CONFIG_ZB_ED_RXOFF_TRACE_APP
#define CONFIG_ZB_ED_RXOFF_TRACE_APP 0
#endif

#ifndef CONFIG_ZB_ED_RXON_TRACE_APP
#define CONFIG_ZB_ED_RXON_TRACE_APP 0
#endif

#ifndef CONFIG_ZB_ROUTER_TRACE_APP
#define CONFIG_ZB_ROUTER_TRACE_APP 0
#endif

#ifndef CONFIG_ZB_COPROCESSOR_TRACE_APP
#define CONFIG_ZB_COPROCESSOR_TRACE_APP 0
#endif

#ifndef CONFIG_ZB_COORD_TRACE_ZCL
#define CONFIG_ZB_COORD_TRACE_ZCL 0
#endif

#ifndef CONFIG_ZB_ED_RXOFF_TRACE_ZCL
#define CONFIG_ZB_ED_RXOFF_TRACE_ZCL 0
#endif

#ifndef CONFIG_ZB_ED_RXON_TRACE_ZCL
#define CONFIG_ZB_ED_RXON_TRACE_ZCL 0
#endif

#ifndef CONFIG_ZB_ROUTER_TRACE_ZCL
#define CONFIG_ZB_ROUTER_TRACE_ZCL 0
#endif

#endif /* _MCU_SDK_ADAPTER_H_ */
