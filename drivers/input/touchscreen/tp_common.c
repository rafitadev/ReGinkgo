#include <linux/compiler.h>
#include <linux/input/tp_common.h>

bool capacitive_keys_enabled;
struct kobject *touchpanel_kobj;

static struct tp_common_ops *tp_capacitive_keys_ops;
static struct tp_common_ops *tp_double_tap_ops;
static struct tp_common_ops *tp_reversed_keys_ops;

static ssize_t tp_common_proxy_show(struct tp_common_ops *ops,
				    struct kobject *kobj,
				    struct kobj_attribute *attr,
				    char *buf)
{
	if (!ops || !ops->show)
		return -ENODEV;
	return ops->show(kobj, attr, buf);
}

static ssize_t tp_common_proxy_store(struct tp_common_ops *ops,
				     struct kobject *kobj,
				     struct kobj_attribute *attr,
				     const char *buf,
				     size_t count)
{
	if (!ops || !ops->store)
		return -ENODEV;
	return ops->store(kobj, attr, buf, count);
}

static ssize_t capacitive_keys_show(struct kobject *kobj,
				    struct kobj_attribute *attr,
				    char *buf)
{
	return tp_common_proxy_show(READ_ONCE(tp_capacitive_keys_ops), kobj, attr,
				     buf);
}

static ssize_t capacitive_keys_store(struct kobject *kobj,
				     struct kobj_attribute *attr,
				     const char *buf,
				     size_t count)
{
	return tp_common_proxy_store(READ_ONCE(tp_capacitive_keys_ops), kobj, attr,
				      buf, count);
}

static ssize_t double_tap_show(struct kobject *kobj,
			       struct kobj_attribute *attr,
			       char *buf)
{
	return tp_common_proxy_show(READ_ONCE(tp_double_tap_ops), kobj, attr, buf);
}

static ssize_t double_tap_store(struct kobject *kobj,
				struct kobj_attribute *attr,
				const char *buf,
				size_t count)
{
	return tp_common_proxy_store(READ_ONCE(tp_double_tap_ops), kobj, attr, buf,
				      count);
}

static ssize_t reversed_keys_show(struct kobject *kobj,
				  struct kobj_attribute *attr,
				  char *buf)
{
	return tp_common_proxy_show(READ_ONCE(tp_reversed_keys_ops), kobj, attr,
				     buf);
}

static ssize_t reversed_keys_store(struct kobject *kobj,
				   struct kobj_attribute *attr,
				   const char *buf,
				   size_t count)
{
	return tp_common_proxy_store(READ_ONCE(tp_reversed_keys_ops), kobj, attr,
				      buf, count);
}

static struct kobj_attribute capacitive_keys_attr =
	__ATTR(capacitive_keys, (S_IWUSR | S_IRUGO), capacitive_keys_show,
	       capacitive_keys_store);

static struct kobj_attribute double_tap_attr =
	__ATTR(double_tap, (S_IWUSR | S_IRUGO), double_tap_show, double_tap_store);

static struct kobj_attribute reversed_keys_attr =
	__ATTR(reversed_keys, (S_IWUSR | S_IRUGO), reversed_keys_show,
	       reversed_keys_store);

int tp_common_set_capacitive_keys_ops(struct tp_common_ops *ops)
{
	WRITE_ONCE(tp_capacitive_keys_ops, ops);
	return 0;
}

int tp_common_set_double_tap_ops(struct tp_common_ops *ops)
{
	WRITE_ONCE(tp_double_tap_ops, ops);
	return 0;
}

int tp_common_set_reversed_keys_ops(struct tp_common_ops *ops)
{
	WRITE_ONCE(tp_reversed_keys_ops, ops);
	return 0;
}

static int __init tp_common_init(void)
{
	int ret;

	touchpanel_kobj = kobject_create_and_add("touchpanel", NULL);
	if (!touchpanel_kobj)
		return -ENOMEM;

	ret = sysfs_create_file(touchpanel_kobj, &capacitive_keys_attr.attr);
	if (ret)
		return ret;

	ret = sysfs_create_file(touchpanel_kobj, &double_tap_attr.attr);
	if (ret)
		return ret;

	ret = sysfs_create_file(touchpanel_kobj, &reversed_keys_attr.attr);
	if (ret)
		return ret;

	return 0;
}

core_initcall(tp_common_init);
