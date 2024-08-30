/*!
 * Copyright 2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * \file rw61x_cpu2.c
 * \brief Holds an array holding the ble/15.4 combo firmware for CPU2
 *
 */

#include <stdint.h>

__attribute__ ((__section__(".fw_cpu2_combo"), used))
const uint8_t fw_cpu2_combo[] = {
    #include <rw61x_combo_fw.bin.inc>
};
