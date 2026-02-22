/*
 * Copyright (c) 2017, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef _MSM_DRM_NOTIFY_H_
#define _MSM_DRM_NOTIFY_H_

#include <linux/notifier.h>

/* A hardware display blank change occurred */
#define MSM_DRM_EVENT_BLANK			0x01
/* A hardware display blank early change occurred */
#define MSM_DRM_EARLY_EVENT_BLANK		0x02

/* Legacy aliases used by some vendor drivers */
#ifndef DRM_EARLY_EVENT_BLANK
#define DRM_EARLY_EVENT_BLANK		0x01
#endif
#ifndef DRM_EVENT_BLANK
#define DRM_EVENT_BLANK			0x02
#endif

enum {
	/* panel: power on */
	MSM_DRM_BLANK_UNBLANK,
	MSM_DRM_BLANK_LP1,
	MSM_DRM_BLANK_LP2,
	MSM_DRM_BLANK_STANDBY,
	MSM_DRM_BLANK_SUSPEND,
	/* panel: power off */
	MSM_DRM_BLANK_POWERDOWN,
};

#ifndef DRM_BLANK_UNBLANK
#define DRM_BLANK_UNBLANK		0
#define DRM_BLANK_LP1			1
#define DRM_BLANK_LP2			2
#define DRM_BLANK_STANDBY		3
#define DRM_BLANK_SUSPEND		4
#define DRM_BLANK_POWERDOWN		5
#endif

enum msm_drm_display_id {
	/* primary display */
	MSM_DRM_PRIMARY_DISPLAY,
	/* external display */
	MSM_DRM_EXTERNAL_DISPLAY,
	MSM_DRM_DISPLAY_MAX
};

struct msm_drm_notifier {
	enum msm_drm_display_id id;
	void *data;
};

struct drm_notify_data {
	bool is_primary;
	void *data;
};

int msm_drm_register_client(struct notifier_block *nb);
int msm_drm_unregister_client(struct notifier_block *nb);
int msm_drm_notifier_call_chain(unsigned long val, void *v);
void msm_drm_notifier_enable(bool val);
int drm_register_client(struct notifier_block *nb);
int drm_unregister_client(struct notifier_block *nb);
int drm_notifier_call_chain(unsigned long val, void *v);

#endif
