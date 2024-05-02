/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __PORTMACRO_LINUX_H__
#define __PORTMACRO_LINUX_H__

#define AES0 NULL
#define AES_SetKey(x, y, z);
#define AES_EncryptEcb(x, y, z, t);

PUBLIC uint8 ZPS_eEnterCriticalSection(void* hMutex, uint32* psIntStore);
PUBLIC uint8 ZPS_eExitCriticalSection(void* hMutex, uint32* psIntStore);
PUBLIC void vSwipeEndian(AESSW_Block_u *puBlock, tsReg128 *psReg, bool_t bBlockToReg);


#endif /* __PORTMACRO_LINU_H__ */
