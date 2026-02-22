// SPDX-License-Identifier: GPL-2.0-only

#ifndef _LINUX_MI_DETECT_H
#define _LINUX_MI_DETECT_H

#include <linux/types.h>
#include <linux/jump_label.h>

#ifdef CONFIG_MI_DETECT

void mi_detect_init(void);
const char *mi_get_current_device(void);
bool mi_is_ginkgo(void);
bool mi_is_laurel(void);

extern struct static_key_false mi_ginkgo_key;
extern struct static_key_false mi_laurel_key;

#else

static inline void mi_detect_init(void) { }

static inline const char *mi_get_current_device(void)
{
#if IS_ENABLED(CONFIG_MACH_XIAOMI_C3J)
	return "ginkgo";
#elif IS_ENABLED(CONFIG_MACH_XIAOMI_F9S)
	return "laurel_sprout";
#else
	return "unknown";
#endif
}

static inline bool mi_is_ginkgo(void)
{
#if IS_ENABLED(CONFIG_MACH_XIAOMI_C3J)
	return true;
#else
	return false;
#endif
}

static inline bool mi_is_laurel(void)
{
#if IS_ENABLED(CONFIG_MACH_XIAOMI_F9S)
	return true;
#else
	return false;
#endif
}

#endif /* CONFIG_MI_DETECT */

#endif /* _LINUX_MI_DETECT_H */
