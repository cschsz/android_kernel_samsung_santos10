/* arch/x86/platform/intel-mid/sec_libs/sec_common.h
 *
 * Copyright (C) 2010-2013 Samsung Electronics Co, Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __SEC_COMMON_H__
#define __SEC_COMMON_H__

#define REBOOTMODE_NORMAL		(1 << 0)
#define REBOOTMODE_RECOVERY		(1 << 1)
#define REBOOTMODE_FOTA			(1 << 2)
#ifdef CONFIG_SAMSUNG_KERNEL_DEBUG
#define REBOOTMODE_KERNEL_PANIC		(1 << 3)
#endif /* CONFIG_SAMSUNG_KERNEL_DEBUG */
#define REBOOTMODE_SHUTDOWN		(1 << 4)
#define REBOOTMODE_DOWNLOAD		(1 << 5)
#ifdef CONFIG_SAMSUNG_KERNEL_DEBUG
#define REBOOTMODE_USER_PANIC		(1 << 6)
#define REBOOTMODE_CP_CRASH		(1 << 9)
#define REBOOTMODE_FORCED_UPLOAD	(1 << 10)
#endif /* CONFIG_SAMSUNG_KERNEL_DEBUG */

/* REBOOT_MODE */
#define REBOOT_MODE_PREFIX		0x12345670
#define REBOOT_MODE_NONE		0
#define REBOOT_MODE_DOWNLOAD		1
#define REBOOT_MODE_UPLOAD		2
#define REBOOT_MODE_CHARGING		3
#define REBOOT_MODE_RECOVERY		4
#define REBOOT_MODE_FOTA		5
#define REBOOT_MODE_FOTA_BL		6
#define REBOOT_MODE_SECURE		7
#define REBOOT_MODE_NORMAL		8

#define REBOOT_SET_PREFIX		0xabc00000
#define REBOOT_SET_DEBUG		0x000d0000
#define REBOOT_SET_SWSEL		0x000e0000
#define REBOOT_SET_SUD			0x000f0000

int sec_common_init_early(void);
int sec_common_init(void);
int sec_common_init_post(void);
int sec_common_reboot_call(unsigned long code, void *cmd);
int sec_common_init_ifwi_sysfs(void);
int camera_class_init(void);

extern struct class *sec_class;

extern struct class *camera_class;

extern char *sec_board_name;
extern unsigned int sec_board_id;
extern unsigned int sec_board_rev;
extern unsigned char sec_ifwi_version;

extern u32 sec_bootmode;
extern char sec_androidboot_mode[16];

#endif /* __SEC_COMMON_H__ */
