#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/notifier.h>
#include <linux/kernel.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/timekeeping.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>

static dev_t dev;
static struct cdev c_dev;
static struct class *cl;

static ssize_t skeleton_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
    struct timespec64 ts;
    char ts_buf[32];
    int len;

    ktime_get_real_ts64(&ts);
    len = snprintf(ts_buf, sizeof(ts_buf), "%lld.%09lld\n", (long long)ts.tv_sec, (long long)ts.tv_nsec);

    if (*ppos >= len)
        return 0;
    if (*ppos + count > len)
        count = len - *ppos;

    if (copy_to_user(buf, ts_buf + *ppos, count))
        return -EFAULT;

    *ppos += count;
    return count;
}

static const struct file_operations skeleton_fops = {
    .owner = THIS_MODULE,
    .read = skeleton_read,
};
/*
   //add something like this in your board device tree
   skeleton@ff {
	compatible = "sd,skeleton";
	reg = <0xff 0x1000>;
   };
*/

static int skeleton_probe(struct platform_device *pdev)
{
    int ret;
    struct device *tdev = &pdev->dev;
    struct device_node *np = tdev->of_node;

    const char *my_arg2;

    printk(KERN_ALERT "%s successful TEST.\n", __func__);

     /* Read string property */
    if (of_property_read_string(np, "my-arg2", &my_arg2)) {
        dev_err(tdev, "Failed to read my-arg2\n");
        return -EINVAL;
    }
    dev_info(tdev, "my-arg2: %s\n", my_arg2);

    ret = alloc_chrdev_region(&dev, 0, 1, "skeleton");
    if (ret < 0) {
        printk(KERN_ALERT "Failed to allocate character device region\n");
        return ret;
    }

    cdev_init(&c_dev, &skeleton_fops);
    ret = cdev_add(&c_dev, dev, 1);
    if (ret < 0) {
        printk(KERN_ALERT "Failed to add character device\n");
        unregister_chrdev_region(dev, 1);
        return ret;
    }

    cl = class_create(THIS_MODULE, "skeleton");
    if (IS_ERR(cl)) {
        printk(KERN_ALERT "Failed to create class\n");
        cdev_del(&c_dev);
        unregister_chrdev_region(dev, 1);
        return PTR_ERR(cl);
    }

    if (IS_ERR(device_create(cl, NULL, dev, NULL, "skeleton"))) {
        printk(KERN_ALERT "Failed to create device\n");
        class_destroy(cl);
        cdev_del(&c_dev);
        unregister_chrdev_region(dev, 1);
        return PTR_ERR(cl);
    }

    return 0;
}

static int skeleton_remove(struct platform_device *pdev)
{
    printk(KERN_ALERT "%s successful.\n", __func__);

    device_destroy(cl, dev);
    class_destroy(cl);
    cdev_del(&c_dev);
    unregister_chrdev_region(dev, 1);

    return 0;
}

static const struct of_device_id of_id_table[] = {
    { .compatible = "sd,skeleton", },
    { /* sentinel */ }
};

MODULE_DEVICE_TABLE(of, of_id_table);


static struct platform_driver skeleton_driver = {
    .driver = {
        .name = "skeleton",
        .owner = THIS_MODULE,
        .of_match_table = of_id_table,
    },
    .probe = skeleton_probe,
    .remove = skeleton_remove,
};
module_platform_driver(skeleton_driver);

MODULE_VERSION("0.0.1");
MODULE_DESCRIPTION("Skeleton driver for testing purposes.");
MODULE_AUTHOR("Florian Schmid");
MODULE_LICENSE("GPL v2");