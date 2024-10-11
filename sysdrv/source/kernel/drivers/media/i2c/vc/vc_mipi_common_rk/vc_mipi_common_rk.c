/*************************************************
 *
 * Copyright Vision Components 2024
 *
 * vc_mipi_common_rk.h
 *
 * Author: Florian Schmid
 *
 *************************************************/
#include <linux/version.h>
//#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of_graph.h>
#include <linux/slab.h>
#include <linux/videodev2.h>
#include <linux/gpio/consumer.h>
#include <linux/regulator/consumer.h>
#include <media/v4l2-ctrls.h>
#include <media/v4l2-device.h>
#include <media/v4l2-fwnode.h>
#include <media/v4l2-image-sizes.h>
#include <media/v4l2-mediabus.h>

#include "vc_mipi_common_rk.h"

int vc_mipi_common_rk_platform_init(struct i2c_client *client, struct regulator **io_regulator, struct regulator **core_regulator, struct regulator **analog_regulator, struct gpio_desc **rst_gpio)
{
	return 0;
}
EXPORT_SYMBOL( vc_mipi_common_rk_platform_init );


struct i2c_client * vc_mipi_common_rk_rom_probe(struct i2c_adapter *adapter, u8 addr)
{
	struct i2c_board_info info = {
		I2C_BOARD_INFO("i2c", addr),
	};
	unsigned short addr_list[2] = { addr, I2C_CLIENT_END };
#if LINUX_VERSION_CODE < KERNEL_VERSION(5,5,0)
	return i2c_new_probed_device(adapter, &info, addr_list, NULL);
#else
	{
		struct i2c_client *client;
		client = i2c_new_scanned_device(adapter, &info, addr_list, NULL);
		return IS_ERR(client) ? NULL : client;
	}
#endif
}
EXPORT_SYMBOL( vc_mipi_common_rk_rom_probe );


int vc_mipi_common_rk_reg_write(struct i2c_client *client, const u16 addr, const u8 data)
{
	struct i2c_adapter *adap = client->adapter;
	struct i2c_msg msg;
	u8 tx[3];
	int ret;

	msg.addr = client->addr;
	msg.buf = tx;
	msg.len = 3;
	msg.flags = 0;
	tx[0] = addr >> 8;
	tx[1] = addr & 0xff;
	tx[2] = data;
	ret = i2c_transfer(adap, &msg, 1);
	mdelay(2);

	dev_dbg(&client->dev, "W [%04x] = %02x to   %x r = %d\n",
				addr, data, client->addr, ret);
	return ret == 1 ? 0 : -EIO;
}
EXPORT_SYMBOL( vc_mipi_common_rk_reg_write );


int vc_mipi_common_rk_reg_read(struct i2c_client *client, const u16 addr)
{
	u8 buf[2] = {addr >> 8, addr & 0xff};
	int ret;
	struct i2c_msg msgs[] = {
		{
			.addr  = client->addr,
			.flags = 0,
			.len   = 2,
			.buf   = buf,
		}, {
			.addr  = client->addr,
			.flags = I2C_M_RD,
			.len   = 1,
			.buf   = buf,
		},
	};

	ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));

	dev_dbg(&client->dev, "R [%04x] = %02x from %x r = %d\n",
				addr, buf[0], client->addr, ret);
	if (ret < 0) {
		dev_warn(&client->dev, "Reading register %x from %x failed\n",
				addr, client->addr);
		return ret;
	}

	return buf[0];
}
EXPORT_SYMBOL( vc_mipi_common_rk_reg_read );





static int __init  vc_mipi_common_rk_init(void)
{
	//printk("called %s()", __FUNCTION__);
	pr_info("%s (%s) init\n",
			THIS_MODULE->name,
			THIS_MODULE->version);
	return 0;
}

static void __exit  vc_mipi_common_rk_exit(void)
{
	//printk("called %s()", __FUNCTION__);
	pr_info("%s (%s) exit\n",
			THIS_MODULE->name,
			THIS_MODULE->version);
}

module_init(vc_mipi_common_rk_init);
module_exit(vc_mipi_common_rk_exit);

MODULE_VERSION("0.2.8");
MODULE_DESCRIPTION("Vision Components GmbH - VC MIPI Common RK driver");
MODULE_AUTHOR("Florian Schmid, Vision Components GmbH <mipi-tech@vision-components.com>");
MODULE_LICENSE("GPL v2");
