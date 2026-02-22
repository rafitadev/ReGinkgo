// SPDX-License-Identifier: GPL-2.0-only
/*
 * mi_detect.c - Xiaomi device runtime detection (unification helper)
 *
 * Copyright (C) 2023-2025 Flopster101
 *
 * This driver provides a simple runtime mechanism to detect the current device
 * (ginkgo or laurel_sprout) at boot, for use in unified kernel builds. It is
 * modeled after sec_detect and is intended to be used by device-specific
 * workarounds and feature guards. For device-specific builds, the helpers are
 * stubbed to return the correct value at compile time.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/mi_detect.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/jump_label.h>

enum mi_device_type {
	MI_DEVICE_UNKNOWN = 0,
	MI_DEVICE_GINKGO,
	MI_DEVICE_LAUREL,
};

static enum mi_device_type mi_device = MI_DEVICE_UNKNOWN;

DEFINE_STATIC_KEY_FALSE(mi_ginkgo_key);
DEFINE_STATIC_KEY_FALSE(mi_laurel_key);
EXPORT_SYMBOL_GPL(mi_ginkgo_key);
EXPORT_SYMBOL_GPL(mi_laurel_key);

const char *mi_get_current_device(void)
{
	switch (mi_device) {
	case MI_DEVICE_GINKGO:
		return "ginkgo";
	case MI_DEVICE_LAUREL:
		return "laurel_sprout";
	default:
		return "unknown";
	}
}
EXPORT_SYMBOL_GPL(mi_get_current_device);

bool mi_is_ginkgo(void)
{
	if (static_branch_unlikely(&mi_ginkgo_key))
		return true;
	return mi_device == MI_DEVICE_GINKGO;
}
EXPORT_SYMBOL_GPL(mi_is_ginkgo);

bool mi_is_laurel(void)
{
	if (static_branch_unlikely(&mi_laurel_key))
		return true;
	return mi_device == MI_DEVICE_LAUREL;
}
EXPORT_SYMBOL_GPL(mi_is_laurel);

void mi_detect_init(void)
{
	struct device_node *root;
	const char *model = NULL;

	mi_device = MI_DEVICE_UNKNOWN;
	root = of_find_node_by_path("/");
	if (root) {
		if (of_property_read_string(root, "model", &model))
			of_property_read_string(root, "compatible", &model);
		if (model) {
			if (strstr(model, "IDP"))
				mi_device = MI_DEVICE_GINKGO;
			else if (strstr(model, "QRD"))
				mi_device = MI_DEVICE_LAUREL;
		}
		of_node_put(root);
	}

	if (mi_device == MI_DEVICE_GINKGO)
		static_branch_enable(&mi_ginkgo_key);
	else if (mi_device == MI_DEVICE_LAUREL)
		static_branch_enable(&mi_laurel_key);

	pr_info("mi_detect: Detected device: %s\n", mi_get_current_device());
}
EXPORT_SYMBOL_GPL(mi_detect_init);

#ifdef CONFIG_MI_DETECT_SYSFS
static const char *mi_get_device_model(void)
{
	if (mi_is_ginkgo())
		return "Redmi Note 8/8T";
	if (mi_is_laurel())
		return "Xiaomi Mi A3";
	return "Unknown";
}

static ssize_t device_name_show(struct kobject *kobj,
			     struct kobj_attribute *attr, char *buf)
{
	return scnprintf(buf, PAGE_SIZE, "%s\n", mi_get_current_device());
}

static ssize_t device_model_show(struct kobject *kobj,
			      struct kobj_attribute *attr, char *buf)
{
	return scnprintf(buf, PAGE_SIZE, "%s\n", mi_get_device_model());
}

static struct kobj_attribute device_name_attr =
	__ATTR(device_name, 0444, device_name_show, NULL);
static struct kobj_attribute device_model_attr =
	__ATTR(device_model, 0444, device_model_show, NULL);

static struct attribute *attrs[] = {
	&device_name_attr.attr,
	&device_model_attr.attr,
	NULL,
};

static struct attribute_group attr_group = {
	.attrs = attrs,
};

static struct kobject *device_kobj;
#endif

static int __init mi_detect_initcall(void)
{
	mi_detect_init();

#ifdef CONFIG_MI_DETECT_SYSFS
	device_kobj = kobject_create_and_add("mi_detect", kernel_kobj);
	if (device_kobj)
		sysfs_create_group(device_kobj, &attr_group);
#endif

	return 0;
}
pure_initcall(mi_detect_initcall);

static void __exit mi_detect_exit(void)
{
#ifdef CONFIG_MI_DETECT_SYSFS
	kobject_put(device_kobj);
#endif
}
module_exit(mi_detect_exit);

MODULE_AUTHOR("Flopster101");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Detects the Xiaomi device currently running this kernel.");
