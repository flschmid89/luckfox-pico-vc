/*
 * Driver for Vision Components GmbH VC MIPI MODULES_0 Sensor modules
 *
 * Copyright (C) 2024, Michael Steinel <steinel@vision-components.com>
 *
 * based on
 *
 * IMX219 driver, Guennadi Liakhovetski <g.liakhovetski@gmx.de>
 *
 * Copyright (C) 2014, Andrew Chew <achew@nvidia.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/version.h>
#include <linux/clk.h>
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
#include <media/v4l2-event.h>
#include <media/v4l2-fwnode.h>
#include <media/v4l2-subdev.h>
#include <media/v4l2-image-sizes.h>
#include <media/v4l2-mediabus.h>
#include <asm/div64.h>

// TEMPORARY PLATFORM DEFINES
//#define PLATFORM_QCOM 
//#define LC_IMX296_TEST 1

/* VC Sensor Mode - default 10-Bit Streaming */
static int sensor_mode = -1; /* value <0 means: unset */
module_param(sensor_mode, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(sensor_mode, "VC Sensor Mode: IMX327,412: 0=10bit_stream; IMX290,412: 0=10bit_stream, 1=10bit_4lanes; IMX296,297: 0=10bit_stream 1=10bit_ext_trig 2=mode0+binning 3=mode1+binning");

#include "../vc_mipi_common/vc_mipi_common.h"
#include "vc_mipi_modules_0.h"

#ifdef PLATFORM_QCOM
#warning "######## BUILDING FOR QCOM_PLATFORM ########"
#endif

#define sen_reg(priv, addr) (*((u16 *)(&priv->rom_table.regs[(addr)*2])))

#if LINUX_VERSION_CODE < KERNEL_VERSION(5,15,0)
#else
#define v4l2_subdev_pad_config  v4l2_subdev_state
#endif


#ifndef LC_IMX296_TEST
#define LC_IMX296_TEST 0// or 0, depending on your needs
#endif
/* V4L2 subdev video operations */

static int imx_flip(struct imx *priv)
{
	struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
	int ret = 0;
	switch(priv->model)
	{
		case IMX273_MODEL_MONOCHROME:
		case IMX273_MODEL_COLOR:
			ret = vc_mipi_common_reg_write(client, 0x020e,
					( priv->hflip ? 2 : 0 ) |
					( priv->vflip ? 1 : 0 ) );
			break;
		case IMX296_MODEL_MONOCHROME_S:
		case IMX296_MODEL_COLOR_S:
		case IMX296_MODEL_MONOCHROME:
		case IMX296_MODEL_COLOR:
		case IMX296_MODEL_COLOR_R:
			ret = vc_mipi_common_reg_write(client, 0x300e,
					( priv->hflip ? 2 : 0 ) |
					( priv->vflip ? 1 : 0 ) );
			break;

		default:
			/* do nothing for models which are not implemented yet */
			break;
	}

	return ret;
}

static int imx_s_stream(struct v4l2_subdev *sd, int enable)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct imx *priv = to_imx(client);
	int ret=0;

	/*
	 * ! CAUTION !
	 * for correct trigger timing the trigger counter is zeroed here!
	 * */
	ret = vc_mipi_common_reg_write(priv->rom, 0x0108, 0);

	if (!enable)
	{
		switch(priv->model)
		{
			case OV7251_MODEL_MONOCHROME:
			case OV7251_MODEL_COLOR:
			case OV9281_MODEL_MONOCHROME:
			case OV9281_MODEL_COLOR:
			case IMX178_MODEL_MONOCHROME:
			case IMX178_MODEL_COLOR:
			case IMX183_MODEL_MONOCHROME:
			case IMX183_MODEL_COLOR:
			case IMX226_MODEL_MONOCHROME:
			case IMX226_MODEL_COLOR:
			case IMX250_MODEL_MONOCHROME:
			case IMX250_MODEL_COLOR:
			case IMX252_MODEL_MONOCHROME:
			case IMX252_MODEL_COLOR:
			case IMX264_MODEL_MONOCHROME:
			case IMX264_MODEL_COLOR:
			case IMX265_MODEL_MONOCHROME:
			case IMX265_MODEL_COLOR:
			case IMX273_MODEL_MONOCHROME:
			case IMX273_MODEL_COLOR:
			case IMX290_MODEL_MONOCHROME:
			case IMX290_MODEL_COLOR:
			case IMX296_MODEL_MONOCHROME_S:
			case IMX296_MODEL_COLOR_S:
			case IMX296_MODEL_MONOCHROME:
			case IMX296_MODEL_COLOR:
			case IMX296_MODEL_COLOR_R:
			case IMX297_MODEL_MONOCHROME:
			case IMX297_MODEL_COLOR:
			case IMX327_MODEL_MONOCHROME:
			case IMX327_MODEL_COLOR:
			case IMX335_MODEL_MONOCHROME:
			case IMX335_MODEL_COLOR:
			case IMX392_MODEL_MONOCHROME:
			case IMX392_MODEL_COLOR:
			case IMX462_MODEL_MONOCHROME:
			case IMX462_MODEL_COLOR:
			case IMX565_MODEL_MONOCHROME:
			case IMX565_MODEL_COLOR:
			case IMX566_MODEL_MONOCHROME:
			case IMX566_MODEL_COLOR:
			case IMX568_MODEL_MONOCHROME:
			case IMX568_MODEL_COLOR:
			case IMX900_MODEL_MONOCHROME:
			case IMX900_MODEL_COLOR:
			case IMX585_MODEL_MONOCHROME:
			case IMX585_MODEL_COLOR:
#if 1
				ret = vc_mipi_common_trigmode_write(priv->rom, 0, 0, 0, 0, 0, &priv->tpf, &priv->rom_table); /* disable external trigger counter */
				if (ret)
					dev_err(&client->dev, "Error %d disabling trigger counter\n", ret);
				ret = vc_mipi_common_reg_write_table(client, priv->trait->stop);
				if (ret < 0)
					dev_err(&client->dev, "STOP Error %d setting registers\n", ret);
				return ret;
				break;
#endif
			case IMX412_MODEL_MONOCHROME:
			case IMX412_MODEL_COLOR:
			case IMX415_MODEL_MONOCHROME:
			case IMX415_MODEL_COLOR:

				/* reinit sensor */
				dev_dbg(&client->dev, "REINIT: sensor\n");

				ret = vc_mipi_common_reg_write_table(client, priv->trait->stop);
				if (ret < 0)
					dev_err(&client->dev, "REINIT: Error %d setting registers\n", ret);

				usleep_range(1000,2000);

				ret = vc_mipi_common_rom_init(client, priv->rom, -1);
				if (ret)
					return ret;

				ret = vc_mipi_common_rom_init(client, priv->rom, priv->cur_mode->sensor_mode);
				if (ret)
					return ret;

				ret = vc_mipi_common_trigmode_write(priv->rom, 0, 0, 0, 0, 0, &priv->tpf, &priv->rom_table); /* disable external trigger counter */
				if (ret)
					dev_err(&client->dev, "REINIT: Error %d disabling trigger counter\n", ret);

				ret = v4l2_ctrl_handler_setup(&priv->ctrl_handler);
				if (ret < 0)
					dev_err(&client->dev, "REINIT: Error %d setting controls\n", ret);

				dev_dbg(&client->dev, "REINIT: sensor Done!\n");
				return ret;

				break;
			default:
				return -EINVAL;
		}
	}


	ret = vc_mipi_common_reg_write_table(client, priv->cur_mode->reg_list);
	if (ret)
		return ret;

	/* Handle h/v flip */
	ret = imx_flip(priv);
	if (ret)
		return ret;

	/* Handle crop */
	switch(priv->model)
	{
		case IMX296_MODEL_MONOCHROME_S:
		case IMX296_MODEL_COLOR_S:
	
			if(priv->cur_mode->sensor_mode < (IMX296_S_SENSOR_MODE_MAX/2))
			{
			dev_info(&client->dev, "IMX296S: [sensormode] %d \n",priv->cur_mode->sensor_mode);
			// half value for sensor registers!
			if(sen_reg(priv, H_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_START_LOW  ), (priv->crop_rect.left/2) & 0xff);
			if(sen_reg(priv, H_START_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_START_HIGH ), (priv->crop_rect.left/2) >> 8);
			if(sen_reg(priv, H_OUTPUT_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_OUTPUT_LOW ), (priv->crop_rect.width/2) & 0xff);
			if(sen_reg(priv, H_OUTPUT_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_OUTPUT_HIGH), (priv->crop_rect.width/2) >> 8);
			// use value for sensor registers!
			if(sen_reg(priv, V_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_START_LOW  ), (priv->crop_rect.top) & 0xff);
			if(sen_reg(priv, V_START_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_START_HIGH ), (priv->crop_rect.top) >> 8);
			if(sen_reg(priv, V_OUTPUT_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_OUTPUT_LOW ), (priv->crop_rect.height) & 0xff);
			if(sen_reg(priv, V_OUTPUT_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_OUTPUT_HIGH), (priv->crop_rect.height) >> 8);
#ifdef PLATFORM_QCOM
			ret |= vc_mipi_common_reg_write(client, 0x4182 , (priv->crop_rect.height) & 0xff);
			ret |= vc_mipi_common_reg_write(client, 0x4183 , (priv->crop_rect.height) >> 8);
#endif
			}
			else
			{
			dev_info(&client->dev, "IMX296S: [SENSORMODE] %d\n",priv->cur_mode->sensor_mode);
			// use value for sensor registers!
			if(sen_reg(priv, H_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_START_LOW  ), (priv->crop_rect.left) & 0xff);
			if(sen_reg(priv, H_START_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_START_HIGH ), (priv->crop_rect.left) >> 8);
			if(sen_reg(priv, H_OUTPUT_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_OUTPUT_LOW ), (priv->crop_rect.width) & 0xff);
			if(sen_reg(priv, H_OUTPUT_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_OUTPUT_HIGH), (priv->crop_rect.width) >> 8);
			// half value for sensor registers!
			if(sen_reg(priv, V_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_START_LOW  ), (priv->crop_rect.top/2) & 0xff);
			if(sen_reg(priv, V_START_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_START_HIGH ), (priv->crop_rect.top/2) >> 8);
			if(sen_reg(priv, V_OUTPUT_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_OUTPUT_LOW ), (priv->crop_rect.height/2) & 0xff);
			if(sen_reg(priv, V_OUTPUT_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_OUTPUT_HIGH), (priv->crop_rect.height/2) >> 8);
#ifdef PLATFORM_QCOM
			ret |= vc_mipi_common_reg_write(client, 0x4182 , (priv->crop_rect.height/2) & 0xff);
			ret |= vc_mipi_common_reg_write(client, 0x4183 , (priv->crop_rect.height/2) >> 8);
#endif
			}
			break;
		case IMX335_MODEL_MONOCHROME:
		case IMX335_MODEL_COLOR:
			if(sen_reg(priv, H_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_START_LOW  ), (priv->crop_rect.left) & 0xff);
			if(sen_reg(priv, H_START_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_START_HIGH ), (priv->crop_rect.left) >> 8);
			if(sen_reg(priv, V_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_START_LOW  ), (priv->crop_rect.top) & 0xff);
			if(sen_reg(priv, V_START_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_START_HIGH ), (priv->crop_rect.top) >> 8);
			if(sen_reg(priv, H_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_START_LOW  ), (priv->crop_rect.left+76)   & 0xff);
			if(sen_reg(priv, V_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_START_LOW  ), (priv->crop_rect.top+176)    & 0xff);
			//FALLSTHROUGH
			        // Intentional fall-through
        /* fall through */
		case IMX415_MODEL_MONOCHROME:
		case IMX415_MODEL_COLOR:
			if(sen_reg(priv, H_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_START_LOW  ), (priv->crop_rect.left) & 0xff);
			if(sen_reg(priv, H_START_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_START_HIGH ), (priv->crop_rect.left) >> 8);
			if(sen_reg(priv, V_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_START_LOW  ), (priv->crop_rect.top) & 0xff);
			if(sen_reg(priv, V_START_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_START_HIGH ), (priv->crop_rect.top) >> 8);
			// double value for sensor registers!
			if(sen_reg(priv, V_OUTPUT_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_OUTPUT_LOW ), (priv->crop_rect.height*2) & 0xff);
			if(sen_reg(priv, V_OUTPUT_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_OUTPUT_HIGH), (priv->crop_rect.height*2) >> 8);
			break;
		default:
			if(sen_reg(priv, H_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_START_LOW  ), (priv->crop_rect.left) & 0xff);
			if(sen_reg(priv, H_START_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_START_HIGH ), (priv->crop_rect.left) >> 8);
			if(sen_reg(priv, V_START_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_START_LOW  ), (priv->crop_rect.top) & 0xff);
			if(sen_reg(priv, V_START_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_START_HIGH ), (priv->crop_rect.top) >> 8);
			if(sen_reg(priv, V_OUTPUT_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_OUTPUT_LOW ), priv->crop_rect.height & 0xff);
			if(sen_reg(priv, V_OUTPUT_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_OUTPUT_HIGH), priv->crop_rect.height >> 8);
			if(sen_reg(priv, H_OUTPUT_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_OUTPUT_LOW ), (priv->crop_rect.width) & 0xff);
			if(sen_reg(priv, H_OUTPUT_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, H_OUTPUT_HIGH), (priv->crop_rect.width) >> 8);

	}

	switch(priv->model)
	{
		case IMX178_MODEL_MONOCHROME:
		case IMX178_MODEL_COLOR:
		case IMX183_MODEL_MONOCHROME:
		case IMX183_MODEL_COLOR:
		case IMX226_MODEL_MONOCHROME:
		case IMX226_MODEL_COLOR:
		case IMX250_MODEL_MONOCHROME:
		case IMX250_MODEL_COLOR:
		case IMX252_MODEL_MONOCHROME:
		case IMX252_MODEL_COLOR:
		case IMX264_MODEL_MONOCHROME:
		case IMX264_MODEL_COLOR:
		case IMX265_MODEL_MONOCHROME:
		case IMX265_MODEL_COLOR:
		case IMX392_MODEL_MONOCHROME:
		case IMX392_MODEL_COLOR:
		case IMX585_MODEL_MONOCHROME:
		case IMX585_MODEL_COLOR:
			break;
		case OV7251_MODEL_MONOCHROME:
		case OV7251_MODEL_COLOR:
			break;
		case OV9281_MODEL_MONOCHROME:
		case OV9281_MODEL_COLOR:
			if(priv->cur_mode->sensor_ext_trig)
			{
				// OV9281 uses this setting for external triggering only
				ret |= vc_mipi_common_reg_write_table(client, priv->trait->stop);

				if (!ret)
				{
					ret |= vc_mipi_common_trigmode_write(priv->rom,
							priv->cur_mode->sensor_ext_trig,
							priv->exposure_time,
							priv->io_config,
							priv->enable_extrig,
							priv->sen_clk,
							&priv->tpf, &priv->rom_table);
					/*
					 * ! CAUTION !
					 * for correct trigger timing the trigger is NOW enabled after DMA start!
					 * */
					return (ret | vc_mipi_common_reg_write(priv->rom, 0x0108, priv->enable_extrig));
				}
				else
					dev_err(&client->dev, "OV9281 - ERROR !!! - unable to set sensor trigmode\n");
			}
			break;
#ifdef PLATFORM_QCOM
		case IMX296_MODEL_MONOCHROME:
		case IMX296_MODEL_COLOR:
		case IMX296_MODEL_COLOR_R:
		case IMX297_MODEL_MONOCHROME:
		case IMX297_MODEL_COLOR:
			ret |= vc_mipi_common_reg_write(client, 0x4182 , priv->crop_rect.height & 0xff);
			ret |= vc_mipi_common_reg_write(client, 0x4183 , priv->crop_rect.height >> 8);
			break;

#endif
		case IMX296_MODEL_MONOCHROME_S:
		case IMX296_MODEL_COLOR_S:
			// half value for sensor registers!
			if(priv->cur_mode->sensor_mode >= (IMX296_S_SENSOR_MODE_MAX/2))
			{
			if(sen_reg(priv, V_SIZE_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_SIZE_LOW   ), (priv->crop_rect.height/2) & 0xff);
			if(sen_reg(priv, V_SIZE_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_SIZE_HIGH  ), (priv->crop_rect.height/2) >> 8);
			break;
			}
			//FALLTHROUGH
		default:
			if(sen_reg(priv, V_SIZE_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_SIZE_LOW   ), priv->crop_rect.height & 0xff);
			if(sen_reg(priv, V_SIZE_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, V_SIZE_HIGH  ), priv->crop_rect.height >> 8);
	}
	if (ret)
		return ret;

	ret = vc_mipi_common_trigmode_write(priv->rom, priv->cur_mode->sensor_ext_trig, priv->exposure_time, priv->io_config, priv->enable_extrig, priv->sen_clk, &priv->tpf, &priv->rom_table);
	if (ret)
		return ret;

	ret = vc_mipi_common_reg_write_table(client, priv->trait->start);
	/*
	 * ! CAUTION !
	 * for correct trigger timing the trigger is NOW enabled after DMA start!
	 * */
	return (ret | vc_mipi_common_reg_write(priv->rom, 0x0108, priv->enable_extrig));
}

static int imx_g_frame_interval(struct v4l2_subdev *sd,
				   struct v4l2_subdev_frame_interval *ival)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct imx *priv = to_imx(client);

	ival->interval.numerator = priv->tpf.numerator;
	ival->interval.denominator = priv->tpf.denominator;

	dev_info(&client->dev, "GET Frame interval: %u/%u s = %d us\n",
		ival->interval.numerator, ival->interval.denominator,
		ival->interval.numerator*1000 / (ival->interval.denominator/1000));

	return 0;
}

static int imx_set_frame_length(struct imx *priv, u32 val, u32 vmax_min)
{
	struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
        int err=-EPERM;
        u32 frame_length;
	u32 base;
	u32 of;
	u32 height = priv->crop_rect.height;

	switch(priv->model)
	{
		case IMX178_MODEL_MONOCHROME:
		case IMX178_MODEL_COLOR:
		case IMX183_MODEL_MONOCHROME:
		case IMX183_MODEL_COLOR:
		case IMX226_MODEL_MONOCHROME:
		case IMX226_MODEL_COLOR:
			base = 0x7000;
			of = 0x04;
			break;
		case IMX250_MODEL_MONOCHROME:
		case IMX250_MODEL_COLOR:
		case IMX252_MODEL_MONOCHROME:
		case IMX252_MODEL_COLOR:
		case IMX264_MODEL_MONOCHROME:
		case IMX264_MODEL_COLOR:
		case IMX265_MODEL_MONOCHROME:
		case IMX265_MODEL_COLOR:
#ifndef PLATFORM_QCOM
		case IMX273_MODEL_MONOCHROME:
		case IMX273_MODEL_COLOR:
#endif
		case IMX392_MODEL_MONOCHROME:
		case IMX392_MODEL_COLOR:
			base = 0x0200;
			of = 0x10;
			break;
		case IMX335_MODEL_MONOCHROME:
		case IMX335_MODEL_COLOR:
			base = 0x3000;
			of = 0x30;
			break;
		case IMX565_MODEL_MONOCHROME:
		case IMX565_MODEL_COLOR:
		case IMX566_MODEL_MONOCHROME:
		case IMX566_MODEL_COLOR:
		case IMX568_MODEL_MONOCHROME:
		case IMX568_MODEL_COLOR:
		case IMX900_MODEL_MONOCHROME:
		case IMX900_MODEL_COLOR:
			base = 0x3000;
			of = 0xd4;
			break;
		case IMX585_MODEL_MONOCHROME:
		case IMX585_MODEL_COLOR:
			base = 0x3000;
			of = 0x28;
			break;
		case IMX296_MODEL_MONOCHROME_S:
		case IMX296_MODEL_COLOR_S:
			// half height for registers
			height = height / 2;
			// FALLTHROUGH
		default:
		//test	goto fail;
			base = 0x3000;
			of = 0x10;
	}

        dev_dbg(&client->dev, "%s : input length = %d\n",
                __func__, val);

        frame_length = (u32)val;

	// Fix Frame Lenght when too small
	if ( frame_length < height + vmax_min) {
		frame_length = height + vmax_min;

		dev_warn(&client->dev, "%s : FIXED frame length = %d TO %d\n",
				__func__, val, frame_length);
	}

	frame_length = frame_length & 0x07fffe; // multiple of 2

	err = vc_mipi_common_write_mbreg(client, (u16)(base+of+0), frame_length & 0x07ffff, 3);
        if (err)
                goto fail;

        dev_dbg(&client->dev, "%s frame_length = %d\n", __func__, frame_length);

	{
		int reg;
		int vmax=0;
		// VMAX
		reg = vc_mipi_common_read_mbreg(client, (u16)(base+of+0), &vmax, 3);
		dev_dbg(&client->dev, "frame_len vmax: %08x \n",vmax);
		dev_info(&client->dev, "frame_len vmax: %d \n",vmax);

	}
        return 0;

fail:
        dev_err(&client->dev, "%s error = %d\n", __func__, err);
        return err;
}

static int imx_s_frame_interval(struct v4l2_subdev *sd,
				   struct v4l2_subdev_frame_interval *ival)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct imx *priv = to_imx(client);
	struct v4l2_fract *tpf = &ival->interval;
	int ret;
	u32 div;
	u32 div_max;

	u32 height = priv->cur_mode->height;

	switch (priv->model)
	{
		case IMX296_MODEL_MONOCHROME_S:
		case IMX296_MODEL_COLOR_S:
			// half height for registers
			if(priv->cur_mode->sensor_mode >= (IMX296_S_SENSOR_MODE_MAX/2))
			    height = height / 2;
		break;

		default:
		break;
	}

	div_max = priv->trait->supported_modes[priv->cur_mode->sensor_mode].max_fps;

	div_max *= ((height*1000)/height)/1000;

	if(div_max == 0) div_max=1;

	dev_info(&client->dev, "INITSET Frame interval: %u/%u s = %d us div_max = %d\n",
			tpf->numerator, tpf->denominator,
			tpf->numerator*1000 / (tpf->denominator/1000),
			div_max);

	if (tpf->numerator == 0 || tpf->denominator == 0)
		div = 1;  /* Reset to full rate */
	else
		div = (tpf->numerator * div_max) / tpf->denominator;

	if (div == 0)
		div = 1;
	else if (div > div_max)
		div = div_max;

	dev_info(&client->dev, "imx_s_frame_interval div=%d\n",div);

	tpf->numerator = (div * tpf->denominator) / div_max;
	tpf->denominator = div_max;

	/*
	 * VMAX = 1/frame_rate x senclk / (SHS+1) / HMAX
	 * frame_length (i.e. VMAX) = (frame_interval) x senclk /(SHS+1) / HMAX
	 */

	priv->frame_len = (height*1000*div)/1000; // in 1H units

	dev_info(&client->dev, "imx_s_frame_interval frame_len=%d\n",priv->frame_len);

	priv->tpf.numerator   = div    *1;
	priv->tpf.denominator = div_max*1;

	priv->work_mode.max_fps = div_max;

	*tpf = priv->tpf;

	ret = v4l2_ctrl_handler_setup(&priv->ctrl_handler);
	if (ret < 0)
		dev_err(&client->dev, "SET Frame interval : Error %d setting controls\n", ret);

	dev_info(&client->dev, "SET Frame interval: %u/%u s = %d us\n",
			tpf->numerator, tpf->denominator,
			tpf->numerator*1000 / (tpf->denominator/1000));
	return ret;
}

/* V4L2 subdev core operations */
static int imx_s_power(struct v4l2_subdev *sd, int on)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct imx *priv = to_imx(client);

	mutex_lock(&priv->mutex);

	if (on)    {
		dev_dbg(&client->dev, "imx power on\n");
		//clk_prepare_enable(priv->clk);
	} else if (!on) {
		dev_dbg(&client->dev, "imx power off\n");
		//clk_disable_unprepare(priv->clk);
	}

	mutex_unlock(&priv->mutex);

	return 0;
}

static int imx_exposure_290_327(struct imx *priv)
{
	struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
	int ret;
	u32 exposure = 0;
	unsigned int lf = priv->cur_mode->sensor_mode ? 2 : 1;

	// handle ext_trig mode
	if (priv->cur_mode->sensor_ext_trig)
		return vc_mipi_common_trigmode_write(priv->rom,
				priv->cur_mode->sensor_ext_trig,
				priv->exposure_time,
				priv->io_config,
				priv->enable_extrig,
				priv->sen_clk,
				&priv->tpf, &priv->rom_table);

	if (priv->exposure_time < 29)
		priv->exposure_time = 29;

	if (priv->exposure_time > 7767184)
		priv->exposure_time = 7767184;

	if (priv->exposure_time < 38716)
	{
		// range 1..1123
		exposure = (1124 * 20000 -  (u32)(priv->exposure_time) * 29 * 20 * lf) / 20000;
		dev_info(&client->dev, "SHS = %d \n",exposure);

		ret  = vc_mipi_common_reg_write(client, 0x301A, 0x00);
		ret |= vc_mipi_common_reg_write(client, 0x3019, 0x04);
		ret |= vc_mipi_common_reg_write(client, 0x3018, 0x65);

		ret |= vc_mipi_common_reg_write(client, 0x3022, (exposure >> 16) & 0x01);
		ret |= vc_mipi_common_reg_write(client, 0x3021, (exposure >>  8) & 0xff);
		ret |= vc_mipi_common_reg_write(client, 0x3020,  exposure        & 0xff);
	}
	else // range 1123..
	{
		exposure = ( 1 * 20000 + (u32)(priv->exposure_time) * 29 * 20 * lf ) / 20000;

		dev_info(&client->dev, "VMAX = %d \n",exposure);

		ret  = vc_mipi_common_reg_write(client, 0x3022, 0x00);
		ret |= vc_mipi_common_reg_write(client, 0x3021, 0x00);
		ret |= vc_mipi_common_reg_write(client, 0x3020, 0x01);

		ret |= vc_mipi_common_reg_write(client, 0x301A, (exposure >> 16) & 0x01);
		ret |= vc_mipi_common_reg_write(client, 0x3019, (exposure >>  8) & 0xff);
		ret |= vc_mipi_common_reg_write(client, 0x3018,  exposure        & 0xff);

	}

	return ret;
}
#define imx_exposure_290(priv)    imx_exposure_290_327(priv)
#define imx_exposure_327(priv)    imx_exposure_290_327(priv)

static int imx_exposure_462(struct imx *priv)
{
	struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
	int ret;
	u32 exposure = 0;
	unsigned int lf = 1;

	// handle ext_trig mode
	if (priv->cur_mode->sensor_ext_trig)
		return vc_mipi_common_trigmode_write(priv->rom,
				priv->cur_mode->sensor_ext_trig,
				priv->exposure_time,
				priv->io_config,
				priv->enable_extrig,
				priv->sen_clk,
				&priv->tpf, &priv->rom_table);

	if (priv->exposure_time < 66)
		priv->exposure_time = 66;

	if (priv->exposure_time > 7767184)
		priv->exposure_time = 7767184;

	if ((( 1 * 20000 + (u32)(priv->exposure_time) * 66 * 20 * lf ) / 20000) > 1123 )
	{

		// range 1123..
		exposure = ( 1 * 20000 + (u32)(priv->exposure_time) * 66 * 20 * lf ) / 20000;

		dev_info(&client->dev, "VMAX = %d \n",exposure);

		ret  = vc_mipi_common_reg_write(client, 0x3022, 0x00);
		ret |= vc_mipi_common_reg_write(client, 0x3021, 0x00);
		ret |= vc_mipi_common_reg_write(client, 0x3020, 0x01);

		ret |= vc_mipi_common_reg_write(client, 0x301A, (exposure >> 16) & 0x01);
		ret |= vc_mipi_common_reg_write(client, 0x3019, (exposure >>  8) & 0xff);
		ret |= vc_mipi_common_reg_write(client, 0x3018,  exposure        & 0xff);

	}
	else
	{
		// range 1..1123
		exposure = (1124 * 20000 -  (u32)(priv->exposure_time) * 66 * 20 * lf) / 20000;

		if ((exposure > 0) && (exposure < 1025))
		{
			dev_info(&client->dev, "SHS = %d \n",exposure);

			ret  = vc_mipi_common_reg_write(client, 0x301A, 0x00);
			ret |= vc_mipi_common_reg_write(client, 0x3019, 0x04);
			ret |= vc_mipi_common_reg_write(client, 0x3018, 0x65);

			ret |= vc_mipi_common_reg_write(client, 0x3022, (exposure >> 16) & 0x01);
			ret |= vc_mipi_common_reg_write(client, 0x3021, (exposure >>  8) & 0xff);
			ret |= vc_mipi_common_reg_write(client, 0x3020,  exposure        & 0xff);
		}
		else // invalid
		{
			dev_warn(&client->dev, "imx462 exposure FAILED\n");
			dev_warn(&client->dev, "EXPOSURE = %d \n",exposure);
			ret=-1;
		}
	}

	return ret;
}

static int imx_exposure_412(struct imx *priv)
{
	struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
	int ret=0;
	u32 exposure = 0;

	// alpha=1932/5792
	// N={1,5792}
	// tline=16129.2119 ns -> 16us
	// exposure_time=(N+alpha)*tline
	// N=(exposure_time/tline)-alpha
	// EXP_MIN=(1+alpha)*tline=21509.34885 ns -> 22us
	// EXP_MAX=(5792+alpha)*tline=93425775.44 ns -> 93426us
	//

	// handle ext_trig mode
	if (priv->cur_mode->sensor_ext_trig)
		return vc_mipi_common_trigmode_write(priv->rom,
				priv->cur_mode->sensor_ext_trig,
				priv->exposure_time,
				priv->io_config,
				priv->enable_extrig,
				priv->sen_clk,
				&priv->tpf, &priv->rom_table);

	if (priv->exposure_time < 22)
		priv->exposure_time = 22;
	if (priv->exposure_time > 92693)
		priv->exposure_time = 92693;

	if (priv->exposure_time < 92694)
	{
		exposure = ( ((u32)(priv->exposure_time) * 20000 / 16) - (1932 * 20000 / 5792) ) / 20000;
		dev_info(&client->dev, "EXP = %d \n",exposure);

		ret |= vc_mipi_common_reg_write(client, 0x0202, (exposure >>  8) & 0xff);
		ret |= vc_mipi_common_reg_write(client, 0x0203,  exposure        & 0xff);
	}

	return ret;
}

static int imx_exposure_415(struct imx *priv)
{
	struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
	int ret=0;
	u32 exposure = 0;
	unsigned int lf = priv->cur_mode->sensor_mode ? 8 : 14;

	// offset=1,79 us -> 0us
	// SRH0={8,2192-4}
	// VMAX=2250
	// 1H= 7.63885 us ->  8us (4 lanes)
	// 1H=14.44444 us -> 14us (2 lanes)
	// exposure_time= (2192 - SRH0)*1H + offset
	// SRH0 = 2250 - (exposure_time - offset)/1H
	// EXP_MIN=(2250-2246)*7.63885us+1.79us=32.3454us -> 32 us -> (4*8=32))
	// EXP_MAX=(2250-8)*7.63885us+1.79us=17173,9248us -> 17174 us -> ((2250-8)*8=17936)


	if (priv->exposure_time < 4*lf)
		priv->exposure_time = 4*lf;
	if (priv->exposure_time > 2097152)
		priv->exposure_time = 2097152;

	if (priv->exposure_time <= (2250-8)*4*lf)
	{
		exposure = ( 2250 - ( (u32)(priv->exposure_time) * 20000) / (4 * lf * 20000) );
		dev_info(&client->dev, "EXP = %d \n",exposure);

		ret |= vc_mipi_common_reg_write(client, 0x3052, (exposure >> 16) & 0x07);
		ret |= vc_mipi_common_reg_write(client, 0x3051, (exposure >>  8) & 0xff);
		ret |= vc_mipi_common_reg_write(client, 0x3050,  exposure        & 0xff);
		
		ret |= vc_mipi_common_reg_write(client, 0x3026, 0x00  );
		ret |= vc_mipi_common_reg_write(client, 0x3025, 0x08  );
		ret |= vc_mipi_common_reg_write(client, 0x3024, 0xca );
	}
	else
	{
		exposure = 9 + ( ( (u32)(priv->exposure_time) / (lf*4) ) );
		dev_info(&client->dev, "VMAX = %d \n",exposure);

		ret |= vc_mipi_common_reg_write(client, 0x3052, 0x00);
		ret |= vc_mipi_common_reg_write(client, 0x3051, 0x00);
		ret |= vc_mipi_common_reg_write(client, 0x3050, 0x08);

		ret |= vc_mipi_common_reg_write(client, 0x3026, (exposure >> 16) & 0x07);
		ret |= vc_mipi_common_reg_write(client, 0x3025, (exposure >>  8) & 0xff);
		ret |= vc_mipi_common_reg_write(client, 0x3024,  exposure        & 0xff);
	}

	return ret;
}

static int imx_exposure_9281(struct imx *priv)
{
	struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
	int ret=0;
	u32 exposure = 0;
	u32 flash = 0;
	u32 flash_mod = 0;
	u32 exp_time = 0;
	u32 exp_time_mod = 0;

	// handle ext_trig mode
	if (priv->cur_mode->sensor_ext_trig)
		vc_mipi_common_trigmode_write(priv->rom,
				priv->cur_mode->sensor_ext_trig,
				priv->exposure_time,
				priv->io_config,
				priv->enable_extrig,
				priv->sen_clk,
				&priv->tpf, &priv->rom_table);

	//
	// 9100 ns <==> 16
	//

#define OV9281_DIGITAL_EXPOSURE_MIN ((((   1 * 9100 )+9099) / 9100) << 4)
#define OV9281_DIGITAL_EXPOSURE_MAX (((( 876 * 9100 )+9099) / 9100) << 4)

	flash    = (((u32)(((priv->exposure_time)*1000)+9099)/(9100))); // calculate in ns
	flash_mod= (((u32)(((priv->exposure_time)*1000)+9099)%(9100))); // calculate in ns
	if(flash_mod < 4050) flash = flash - 1;

	exposure = ((flash) << 4); // calculate in ns - 4 bit shift

	dev_info(&client->dev, "EXPOSURE = %d \n",exposure);

	if (exposure < OV9281_DIGITAL_EXPOSURE_MIN)
		exposure = OV9281_DIGITAL_EXPOSURE_MIN;

	if (exposure > OV9281_DIGITAL_EXPOSURE_MAX)
		exposure = OV9281_DIGITAL_EXPOSURE_MAX;

	exp_time     = (((exposure >> 4)*9100)+999) / 1000 ;
	exp_time_mod = (((exposure >> 4)*9100)+999) % 1000 ;
	if(exp_time_mod < 500) exp_time = exp_time - 1;

	priv->exposure_time = exp_time ;

	dev_info(&client->dev, "REAL EXPOSURE_TIME = %d \n",priv->exposure_time);

	ret  = vc_mipi_common_reg_write(client, 0x3500, (exposure >> 16) & 0x0f);
	ret |= vc_mipi_common_reg_write(client, 0x3501, (exposure >>  8) & 0xff);
	ret |= vc_mipi_common_reg_write(client, 0x3502,  exposure        & 0xff);

	dev_info(&client->dev, "FLASH = %d MOD=%d\n",flash,flash_mod);

	/* flash duration for flashout signal*/
	ret |= vc_mipi_common_reg_write(client, 0x3926, (flash >> 16) & 0x0f);
	ret |= vc_mipi_common_reg_write(client, 0x3927, (flash >>  8) & 0xff);
	ret |= vc_mipi_common_reg_write(client, 0x3928,  flash        & 0xff);

	/* flash offset for flashout signal , not necessary for >= Rev3 of sensor module */
	ret |= vc_mipi_common_reg_write(client, 0x3922, 0);
	ret |= vc_mipi_common_reg_write(client, 0x3923, 0);
	ret |= vc_mipi_common_reg_write(client, 0x3924, 0);

	/* Email von Loic am 27.01.2023
	 * Das löst das Problem der Verschiebung des Flash-Signals
	 * UND der manchmal falschen Flash-Dauer im unteren Bereich.
	 * Bitte keine Fragen, ich habe nach dem Application Note experimentiert
	 * und die Funktion der Register ist nicht bei allen beschrieben :) */
	ret |= vc_mipi_common_reg_write(client, 0x3920, 0xff);
	ret |= vc_mipi_common_reg_write(client, 0x392b, 0x00);
	ret |= vc_mipi_common_reg_write(client, 0x392c, 0x00);
	ret |= vc_mipi_common_reg_write(client, 0x392d, 0x02);
	ret |= vc_mipi_common_reg_write(client, 0x392e, 0xd8);
	ret |= vc_mipi_common_reg_write(client, 0x392f, 0x48);
	 /* Alle 6 Register oben sind notwendig in dieser Kombination. */

	return ret;
}

static int imx_exposure_imx(struct imx *priv,
	       	s32 expMin0,
	       	s32 expMin1,
	       	s32 expMax,
	       	s32 nrLines,
	       	s32 tOffset,
	       	s32 h1Period,
	       	s32 vMax,
	       	u32 shs_min,
	       	u32 vmax_min)
{
	struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
	int ret = 0;
	u32 exposure = 0;
	u32 shs;
	u16 regaddr;
	u32 base, offv, offh;
	u32 height = priv->crop_rect.height;

	switch(priv->model)
	{
#ifndef PLATFORM_QCOM
		case IMX273_MODEL_MONOCHROME:
		case IMX273_MODEL_COLOR:
			base = 0x0200;
			offv = 0x0010;
			offh = 0x0002;
			break;
#endif
		case IMX178_MODEL_MONOCHROME:
		case IMX178_MODEL_COLOR:
		case IMX183_MODEL_MONOCHROME:
		case IMX183_MODEL_COLOR:
		case IMX226_MODEL_MONOCHROME:
		case IMX226_MODEL_COLOR:
			base = 0x7000;
			offv = 0x0004;
			offh = 0x0002;
			break;

		case IMX250_MODEL_MONOCHROME:
		case IMX250_MODEL_COLOR:
		case IMX252_MODEL_MONOCHROME:
		case IMX252_MODEL_COLOR:
		case IMX264_MODEL_MONOCHROME:
		case IMX264_MODEL_COLOR:
		case IMX265_MODEL_MONOCHROME: //TODO
		case IMX265_MODEL_COLOR:
		case IMX392_MODEL_MONOCHROME:
		case IMX392_MODEL_COLOR:
			base = 0x0200;
			offv = 0x0010;
			offh = 0x0014;
			break;

		case IMX296_MODEL_MONOCHROME_S:
		case IMX296_MODEL_COLOR_S:
			// half height for registers
			if(priv->cur_mode->sensor_mode >= (IMX296_S_SENSOR_MODE_MAX/2))
			height = height / 2;
			// FALLTHROUGH
		case IMX296_MODEL_MONOCHROME:
		case IMX296_MODEL_COLOR:
		case IMX296_MODEL_COLOR_R:
			base = 0x3000;
			offv = 0x0010;
			offh = 0x0014;
			break;

		case IMX335_MODEL_MONOCHROME:
		case IMX335_MODEL_COLOR:
			base = 0x3000;
			offv = 0x0030;
			offh = 0x0034;
			break;

		case IMX565_MODEL_MONOCHROME:
		case IMX565_MODEL_COLOR:
		case IMX566_MODEL_MONOCHROME:
		case IMX566_MODEL_COLOR:
		case IMX568_MODEL_MONOCHROME:
		case IMX568_MODEL_COLOR:
		case IMX900_MODEL_MONOCHROME:
		case IMX900_MODEL_COLOR:
			base = 0x3000;
			offv = 0x00d4;
			offh = 0x00d8;
			break;

		case IMX585_MODEL_MONOCHROME: 
		case IMX585_MODEL_COLOR:
			base = 0x3000;
			offv = 0x0028;
			offh = 0x002c;
			break;

		default:
			base = 0x3000;
			offv = 0x0010;
			offh = 0x0002;
	}

#if 1
	{
		int reg;
		static int hmax=0;
		static int vmax=0;
		static int h1=0;
		// VMAX
		//if(vmax == 0)
		{
			vmax=0;
			reg = vc_mipi_common_read_mbreg(client, (u16)(base+offv), &vmax, 3);
			dev_dbg(&client->dev, "vmax = %08x \n",vmax);
			dev_dbg(&client->dev, "vmax = %d \n",vmax);
		}
		if(vmax)
			vMax = vmax; // TEST
		dev_info(&client->dev, "vmax (HW) = %d \n",vmax);
		if(priv->frame_len)
			vMax = priv->frame_len; //recall frame length if not zero
		dev_info(&client->dev, "vMax = %d \n",vMax);
#if 1
		// HMAX
		//if (hmax == 0)
		{
			reg = vc_mipi_common_read_mbreg(client, (u16)(base+offh), &hmax, 2);
			dev_dbg(&client->dev, "hmax = %08x \n",hmax);
			dev_dbg(&client->dev, "hmax = %d \n",hmax);
		}
		if(hmax)
		{
			h1 = (1000000*hmax)/priv->sen_clk; // TEST in us
			h1Period=h1*16384;
		}
		dev_info(&client->dev, "hmax (HW) = %d \n",hmax);
		dev_info(&client->dev, "h1 = %d \n",h1);
#endif

	}
#endif

	if (priv->exposure_time < expMin0)
		priv->exposure_time = expMin0;

	if (priv->exposure_time > expMax)
		priv->exposure_time = expMax;

	// exposure time in 1H units
	exposure = ((u32)(priv->exposure_time) * 16384 - tOffset)/h1Period;
	//if (vMax - shs_min  < exposure)
	//	vMax = exposure + shs_min;

	dev_info(&client->dev, "1H units= %d vMax= %d exp_time= %d us\n",exposure,vMax,priv->exposure_time);

	if (vMax > height+vmax_min)
			vMax = height+vmax_min;

	//if(vMax < priv->frame_len) // if computed vmax is to small for current frame_len
	//	vMax= priv->frame_len;
	
	dev_info(&client->dev, "1H units= %d vMax= %d exp_time= %d us\n",exposure,vMax,priv->exposure_time);

	//if (exposure + vMax <= height+vmax_min && (vMax > exposure))
	//if ((exposure <= height+vmax_min) && (vMax > exposure))
	if ((exposure <= vMax))
	{
		// shs = (NumberOfLines - exp_time / 1Hperiod + toffset / 1Hperiod )
		// shs = (nrLines  -  ((u32)(priv->exposure_time) * 16384 - tOffset)/h1Period);
		shs = (vMax  -  ((u32)(priv->exposure_time) * 16384 - tOffset)/h1Period);
		if(shs < shs_min)
			shs = shs_min;

	}
	else
	{
		// exposure = shs_min + ((u64)(priv->exposure_time) * 16384 - tOffset)/h1Period;
		u64 divresult;
		u32 divisor ,remainder;

		divresult = ((u64)priv->exposure_time * 16384) - tOffset;
		divisor   = h1Period;
		remainder = (u32)(do_div(divresult,divisor)); // caution: division result value at dividend!

		vMax = shs_min + ((u32)divresult);
		shs  = shs_min;

	}

	dev_info(&client->dev, "SHS = %d vMax= %d exp_time= %d us\n",shs,vMax,priv->exposure_time);

	ret = imx_set_frame_length(priv, vMax, vmax_min); // hw  be written here
	if(ret) 
		goto err_out;

	if((regaddr=sen_reg(priv, EXPOSURE_LOW)) && (sen_reg(priv, EXPOSURE_MIDDLE)) && (sen_reg(priv, EXPOSURE_HIGH)))
	{
		ret = vc_mipi_common_write_mbreg(client, regaddr, shs & 0x07ffff, 3);
	dev_info(&client->dev, "SHS 24bit\n");
	}
	else if((regaddr=sen_reg(priv, EXPOSURE_LOW)) && (sen_reg(priv, EXPOSURE_MIDDLE)))
	{
		ret = vc_mipi_common_write_mbreg(client, regaddr, shs & 0xffff, 2);
	dev_info(&client->dev, "SHS 16bit\n");
	}
	
	// handle ext_trig mode
	if (priv->cur_mode->sensor_ext_trig)
		ret = vc_mipi_common_trigmode_write(priv->rom,
				priv->cur_mode->sensor_ext_trig,
				priv->exposure_time,
				priv->io_config,
				priv->enable_extrig,
				priv->sen_clk,
				&priv->tpf, &priv->rom_table);


err_out:
	return ret;
}

//
// IMX178
// 1H period 7.973us
// NumberOfLines=2048
//
#define H1PERIOD_178 130630 // (U32)(7.973 * 16384.0)
#define NRLINES_178  (2048)
#define TOFFSET_178  4588   // (U32)(0.28 * 16384.0)
#define VMAX_178     2145
#define EXPOSURE_TIME_MIN_178  20
#define EXPOSURE_TIME_MIN2_178 74480
#define EXPOSURE_TIME_MAX_178  10000000
#define SHS_MIN_178 9
#define VMAX_MIN_178 50

#define imx_exposure_178(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_178, EXPOSURE_TIME_MIN2_178, EXPOSURE_TIME_MAX_178, NRLINES_178 ,TOFFSET_178, H1PERIOD_178, VMAX_178, SHS_MIN_178, VMAX_MIN_178)

//
// IMX183
// 1H period 20.00us
// NumberOfLines=3648
//
#define H1PERIOD_183 327680 // (U32)(20.000 * 16384.0)
#define NRLINES_183  (3648)
#define TOFFSET_183  47563  // (U32)(2.903 * 16384.0)
#define VMAX_183     3648
#define EXPOSURE_TIME_MIN_183  20
#define EXPOSURE_TIME_MIN2_183 74480
#define EXPOSURE_TIME_MAX_183  10000000
#define SHS_MIN_183 5
#define VMAX_MIN_183 80

#define imx_exposure_183(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_183, EXPOSURE_TIME_MIN2_183, EXPOSURE_TIME_MAX_183, NRLINES_183 ,TOFFSET_183, H1PERIOD_183, VMAX_183, SHS_MIN_183, VMAX_MIN_183)

//
// IMX226
// 1H period 20.00us
// NumberOfLines=3079
//
#define H1PERIOD_226 327680 // (U32)(20.000 * 16384.0)
#define NRLINES_226  (3079)
#define TOFFSET_226  47563  // (U32)(2.903 * 16384.0)
#define VMAX_226     3079
#define EXPOSURE_TIME_MIN_226  20
#define EXPOSURE_TIME_MIN2_226 74480
#define EXPOSURE_TIME_MAX_226  10000000
#define SHS_MIN_226 5
#define VMAX_MIN_226 3079

#define imx_exposure_226(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_226, EXPOSURE_TIME_MIN2_226, EXPOSURE_TIME_MAX_226, NRLINES_226 ,TOFFSET_226, H1PERIOD_226, VMAX_226, SHS_MIN_226, VMAX_MIN_226)

//
// IMX250
// IMX252
// IMX264
// IMX265
// 1H period 4.7138us -> 5us
// NumberOfLines=2094
//
#define H1PERIOD_250 (327680/4) // (U32)(5.000 * 16384.0)
#define NRLINES_250  (2094)
#define TOFFSET_250  224952  // (U32)(13.73 * 16384.0)
#define VMAX_250     2094
#define EXPOSURE_TIME_MIN_250  70
#define EXPOSURE_TIME_MIN2_250 74480
#define EXPOSURE_TIME_MAX_250  10000000
#define SHS_MIN_250 10
#define VMAX_MIN_250 46

#define imx_exposure_250(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_250, EXPOSURE_TIME_MIN2_250, EXPOSURE_TIME_MAX_250, NRLINES_250 ,TOFFSET_250, H1PERIOD_250, VMAX_250, SHS_MIN_250, VMAX_MIN_250)

#define imx_exposure_252(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_250, EXPOSURE_TIME_MIN2_250, EXPOSURE_TIME_MAX_250, NRLINES_250 ,TOFFSET_250, H1PERIOD_250, VMAX_250, SHS_MIN_250, VMAX_MIN_250)

#define imx_exposure_264(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_250, EXPOSURE_TIME_MIN2_250, EXPOSURE_TIME_MAX_250, NRLINES_250 ,TOFFSET_250, H1PERIOD_250, VMAX_250, SHS_MIN_250, VMAX_MIN_250)

#define imx_exposure_265(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_250, EXPOSURE_TIME_MIN2_250, EXPOSURE_TIME_MAX_250, NRLINES_250 ,TOFFSET_250, H1PERIOD_250, VMAX_250, SHS_MIN_250, VMAX_MIN_250)

//
// IMX566
// 1H period 10.13us
// NumberOfLines=2840
//
#define H1PERIOD_566 (165970)   // (U32)( 10.13 * 16384.0)
#define NRLINES_566  (2992)
#define TOFFSET_566  40468      // (U32)( 2.47  * 16384.0)
#define VMAX_566     2992
#define EXPOSURE_TIME_MIN_566  10
#define EXPOSURE_TIME_MIN2_566 ((2992-30)*(H1PERIOD_566/16384))
#define EXPOSURE_TIME_MAX_566  1511071
#define SHS_MIN_566 30
#define VMAX_MIN_566 (150)

#define imx_exposure_566(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_566, EXPOSURE_TIME_MIN2_566, EXPOSURE_TIME_MAX_566, NRLINES_566 ,TOFFSET_566, H1PERIOD_566, VMAX_566, SHS_MIN_566, VMAX_MIN_566)

//
// IMX568
// 1H period 9.0505us
// NumberOfLines=2206
//
#define H1PERIOD_568 (148283)   // (U32)(9.0505 * 16384.0)
#define NRLINES_568  (2206)
#define TOFFSET_568  40468      // (U32)( 2.47  * 16384.0)
#define VMAX_568     2206
#define EXPOSURE_TIME_MIN_568  15
#define EXPOSURE_TIME_MIN2_568 ((2206-42)*(H1PERIOD_568/16384))
#define EXPOSURE_TIME_MAX_568  1511071
#define SHS_MIN_568 42
#define VMAX_MIN_568 (150)

#define imx_exposure_568(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_568, EXPOSURE_TIME_MIN2_568, EXPOSURE_TIME_MAX_568, NRLINES_568 ,TOFFSET_568, H1PERIOD_568, VMAX_568, SHS_MIN_568, VMAX_MIN_568)

//
// IMX585
// 1H period 14.81481us - hmax=1100 - 10bit
// NumberOfLines=2250
//
#define H1PERIOD_585 (242726)   // (U32)(14.81481 * 16384.0)
#define NRLINES_585  (2250)
#define TOFFSET_585  0          // (U32)(     0 * 16384.0)
#define VMAX_585     NRLINES_585
#define VMAX_MIN_585 (58)
#define SHS_MIN_585  8
#define EXPOSURE_TIME_MIN_585  40
#define EXPOSURE_TIME_MIN2_585 ((VMAX_585 - SHS_MIN_585)*(H1PERIOD_585/16384))
#define EXPOSURE_TIME_MAX_585  2000000

#define imx_exposure_585(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_585, EXPOSURE_TIME_MIN2_585, EXPOSURE_TIME_MAX_585, NRLINES_585 ,TOFFSET_585, H1PERIOD_585, VMAX_585, SHS_MIN_585, VMAX_MIN_585)

//
// IMX900 74.25 Mhz 54 Mhz
// 1H period 7.59596 s
// NumberOfLines=1816
//
#define H1PERIOD_900 (124452)   // (U32)(9.0505 * 16384.0) // mode 0 460
#define NRLINES_900  (1816)
#define TOFFSET_900  25395      // (U32)( 1.55  * 16384.0)
#define VMAX_900     1816
#define EXPOSURE_TIME_MIN_900  15
#define EXPOSURE_TIME_MIN2_900 ((1816-99)*(H1PERIOD_900/16384))
#define EXPOSURE_TIME_MAX_900  1511071
#define SHS_MIN_900 99
#define VMAX_MIN_900 (280)

#define imx_exposure_900(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_900, EXPOSURE_TIME_MIN2_900, EXPOSURE_TIME_MAX_900, NRLINES_900 ,TOFFSET_900, H1PERIOD_900, VMAX_900, SHS_MIN_900, VMAX_MIN_900)

//
// IMX392
// 1H period 3.9595us -> 4us
// NumberOfLines=1250
//
#define H1PERIOD_392 (327680*2/10) // (U32)(4 * 16384.0)
#define NRLINES_392  (1250)
#define TOFFSET_392  224952  // (U32)(13.73 * 16384.0)
#define VMAX_392     1250
#define EXPOSURE_TIME_MIN_392  70
#define EXPOSURE_TIME_MIN2_392 74480
#define EXPOSURE_TIME_MAX_392  10000000
#define SHS_MIN_392 8
#define VMAX_MIN_392 35

#define imx_exposure_392(priv) imx_exposure_imx(priv, EXPOSURE_TIME_MIN_392, EXPOSURE_TIME_MIN2_392, EXPOSURE_TIME_MAX_392, NRLINES_392 ,TOFFSET_392, H1PERIOD_392, VMAX_392, SHS_MIN_392, VMAX_MIN_392)

//
// IMX273
// 1H period 3.91 us = 4 us ???
// NumberOfLines=1130
//
#define H1PERIOD_273 (4 * 16384) // (U32)(1H * 16384.0)
#define NRLINES_273  (1130)
#define TOFFSET_273  (14 * 16384) // (U32)(13.73 * 16384.0)
#define VMAX_273     1130
////#define EXPOSURE_TIME_MIN_273  (4 * 14)    // ???  (U32)( 1H * (14))
////#define EXPOSURE_TIME_MIN2_273 (4 * 1116 / 3) // ??? (U32)( 1H * (1130-14))
//#define EXPOSURE_TIME_MAX_273  (2446485) // ??? (4 * 1048562) // (U32)((1H * (2^20-14))
#define EXPOSURE_TIME_MIN_273  (4 * 14)      // (U32)( 1H * (14))
#define EXPOSURE_TIME_MIN2_273 (4 * 1116)    // (U32)( 1H * (1130-14))
#define EXPOSURE_TIME_MAX_273  (4 * 1048562) // (U32)((1H * (2^20-14))
#define SHS_MIN_273 15
#define VMAX_MIN_273 50

#define imx_exposure_273(priv)    imx_exposure_imx(priv, EXPOSURE_TIME_MIN_273, EXPOSURE_TIME_MIN2_273, EXPOSURE_TIME_MAX_273, NRLINES_273 ,TOFFSET_273, H1PERIOD_273, VMAX_273, SHS_MIN_273, VMAX_MIN_273)

//
// IMX296
// 1H period 14.815us
// NumberOfLines=1118
//
#define H1PERIOD_296 242726 // (U32)(14.815 * 16384.0)
#define NRLINES_296  (1118)
#define TOFFSET_296  233636 // (U32)(14.260 * 16384.0)
#define VMAX_296     1118
#define EXPOSURE_TIME_MIN_296  29
#define EXPOSURE_TIME_MIN2_296 16504
#define EXPOSURE_TIME_MAX_296  15534389
#define SHS_MIN_296 5
#define VMAX_MIN_296 50

#define imx_exposure_296(priv)    imx_exposure_imx(priv, EXPOSURE_TIME_MIN_296, EXPOSURE_TIME_MIN2_296, EXPOSURE_TIME_MAX_296, NRLINES_296 ,TOFFSET_296, H1PERIOD_296, VMAX_296, SHS_MIN_296, VMAX_MIN_296)

//
// IMX297
// 1H period 14.411us
// NumberOfLines=574
//
#define H1PERIOD_297 236106 // (U32)(14.411 * 16384.0)
#define NRLINES_297  (574)
#define TOFFSET_297  233636 // (U32)(14.260 * 16384.0)
#define VMAX_297    574
#define EXPOSURE_TIME_MIN_297  29
#define EXPOSURE_TIME_MIN2_297 8359
#define EXPOSURE_TIME_MAX_297  15110711
#define SHS_MIN_297 5
#define VMAX_MIN_297 50

#define imx_exposure_297(priv)    imx_exposure_imx(priv, EXPOSURE_TIME_MIN_297, EXPOSURE_TIME_MIN2_297, EXPOSURE_TIME_MAX_297, NRLINES_297 ,TOFFSET_297, H1PERIOD_297, VMAX_297, SHS_MIN_297, VMAX_MIN_297)

//
// IMX335
// clk 74.25Mhz
// HMAX 820
// 1H period 11.043us
// NumberOfLines=4500
//
#define H1PERIOD_335 180941 // (U32)(11.043 * 16384.0)
#define NRLINES_335  (4500)
#define TOFFSET_335   0     // (U32)(     0 * 16384.0)
#define VMAX_335      4500
#define EXPOSURE_TIME_MIN_335  11
#define EXPOSURE_TIME_MIN2_335 49682
#define EXPOSURE_TIME_MAX_335  905551
#define SHS_MIN_335 9
#define VMAX_MIN_335 ((4500+96)/2) // =2298

#define imx_exposure_335(priv)    imx_exposure_imx(priv, EXPOSURE_TIME_MIN_335, EXPOSURE_TIME_MIN2_335, EXPOSURE_TIME_MAX_335, NRLINES_335 ,TOFFSET_335, H1PERIOD_335, VMAX_335, SHS_MIN_335, VMAX_MIN_335)

static int imx_gain(struct imx *priv)
{
	struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
	int ret = 0;

	switch(priv->model)
	{

		case OV7251_MODEL_MONOCHROME:
		case OV7251_MODEL_COLOR:
			ret = vc_mipi_common_reg_write(client, 0x3504,  0x03);
			if(sen_reg(priv, GAIN_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, GAIN_HIGH) ,
						priv->digital_gain       & 0xfe);
			break;
		case OV9281_MODEL_MONOCHROME:
		case OV9281_MODEL_COLOR:
			ret = vc_mipi_common_reg_write(client, 0x3507,  0x03);
			if(sen_reg(priv, GAIN_HIGH))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, GAIN_HIGH) ,
						priv->digital_gain       & 0xfe);
			break;
		default:
			if(sen_reg(priv, GAIN_HIGH))
				ret  = vc_mipi_common_reg_write(client, sen_reg(priv, GAIN_HIGH),
					(priv->digital_gain >> 8) & 0xff);
			if(sen_reg(priv, GAIN_LOW))
				ret |= vc_mipi_common_reg_write(client, sen_reg(priv, GAIN_LOW) ,
				      	priv->digital_gain       & 0xff);
	}
	return ret;
}


static int imx_s_ctrl(struct v4l2_ctrl *ctrl)
{
	struct imx *priv =
		container_of(ctrl->handler, struct imx, ctrl_handler);
	//struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
	//u8  reg  = 0;
	int ret  = 0;
	u16 gain = 0;

	mutex_lock(&priv->mutex);

	switch (ctrl->id) 
	{
		case V4L2_CID_HBLANK:
		case V4L2_CID_VBLANK:
			mutex_unlock(&priv->mutex);
			return ret;

		case V4L2_CID_HFLIP:

			priv->hflip = ctrl->val;

			mutex_unlock(&priv->mutex);
			return ret;

		case V4L2_CID_VFLIP:

			priv->vflip = ctrl->val;

			mutex_unlock(&priv->mutex);
			return ret;

		case V4L2_CID_ANALOGUE_GAIN:
		case V4L2_CID_GAIN:

			/*
			 * hal transfer (gain * 10)  to kernel
			 */

			gain = ctrl->val;

			if (gain < priv->trait->gain_digital_min)
				gain = priv->trait->gain_digital_min;
			if (gain > priv->trait->gain_digital_max)
				gain = priv->trait->gain_digital_max;

			priv->digital_gain = gain;

			ret = imx_gain(priv);

			mutex_unlock(&priv->mutex);
			return ret;

		case V4L2_CID_EXPOSURE:

			priv->exposure_time = ctrl->val;

			switch(priv->model)
			{
				case IMX273_MODEL_MONOCHROME:
				case IMX273_MODEL_COLOR:
					ret = imx_exposure_273(priv);
					break;
				case IMX565_MODEL_MONOCHROME:
				case IMX565_MODEL_COLOR:
				case IMX566_MODEL_MONOCHROME:
				case IMX566_MODEL_COLOR:
					ret = imx_exposure_566(priv);
					break;
				case IMX568_MODEL_MONOCHROME:
				case IMX568_MODEL_COLOR:
					ret = imx_exposure_568(priv);
					break;
				case IMX900_MODEL_MONOCHROME:
				case IMX900_MODEL_COLOR:
					ret = imx_exposure_900(priv);
					break;
				case IMX296_MODEL_MONOCHROME_S:
				case IMX296_MODEL_COLOR_S:
				case IMX296_MODEL_MONOCHROME:
				case IMX296_MODEL_COLOR:
				case IMX296_MODEL_COLOR_R:
					ret = imx_exposure_296(priv);
					break;
				case IMX297_MODEL_MONOCHROME:
				case IMX297_MODEL_COLOR:
					ret = imx_exposure_297(priv);
					break;
				case IMX290_MODEL_MONOCHROME:
				case IMX290_MODEL_COLOR:
				case IMX327_MODEL_MONOCHROME:
				case IMX327_MODEL_COLOR:
					ret = imx_exposure_290_327(priv);
					break;
				case IMX462_MODEL_MONOCHROME:
				case IMX462_MODEL_COLOR:
					ret = imx_exposure_462(priv);
					break;
				case IMX335_MODEL_MONOCHROME:
				case IMX335_MODEL_COLOR:
					ret = imx_exposure_335(priv);
					break;
				case IMX412_MODEL_MONOCHROME:
				case IMX412_MODEL_COLOR:
					ret = imx_exposure_412(priv);
					break;
				case IMX415_MODEL_MONOCHROME:
				case IMX415_MODEL_COLOR:
					ret = imx_exposure_415(priv);
					break;
				case OV9281_MODEL_MONOCHROME:
				case OV9281_MODEL_COLOR:
					ret = imx_exposure_9281(priv);
					break;
				case IMX178_MODEL_MONOCHROME:
				case IMX178_MODEL_COLOR:
					ret = imx_exposure_178(priv);
					break;
				case IMX183_MODEL_MONOCHROME:
				case IMX183_MODEL_COLOR:
					ret = imx_exposure_183(priv);
					break;
				case IMX226_MODEL_MONOCHROME:
				case IMX226_MODEL_COLOR:
					ret = imx_exposure_226(priv);
					break;
				case IMX250_MODEL_MONOCHROME:
				case IMX250_MODEL_COLOR:
					ret = imx_exposure_250(priv);
					break;
				case IMX252_MODEL_MONOCHROME:
				case IMX252_MODEL_COLOR:
					ret = imx_exposure_252(priv);
					break;
				case IMX264_MODEL_MONOCHROME:
				case IMX264_MODEL_COLOR:
					ret = imx_exposure_264(priv);
					break;
				case IMX265_MODEL_MONOCHROME:
				case IMX265_MODEL_COLOR:
					ret = imx_exposure_265(priv);
					break;
				case IMX585_MODEL_MONOCHROME:
				case IMX585_MODEL_COLOR:
					ret = imx_exposure_585(priv);
					break;
				case IMX392_MODEL_MONOCHROME:
				case IMX392_MODEL_COLOR:
					ret = imx_exposure_392(priv);
					break;
				case OV7251_MODEL_MONOCHROME:
				case OV7251_MODEL_COLOR:
					ret = imx_exposure_9281(priv);
					break;
				default:
					ret = -EINVAL;
			}

			ctrl->val = priv->exposure_time;

			mutex_unlock(&priv->mutex);
			return ret;

		default:
			mutex_unlock(&priv->mutex);
			return -EINVAL;
	}

#if 0
	/* If enabled, apply settings immediately */
	if(sen_reg(priv, IDLE))
		reg = vc_mipi_common_reg_read(client, sen_reg(priv, IDLE));
	if ((reg & 0x1f) == 0x01)
		imx_s_stream(&priv->subdev, 1);
#endif
	mutex_unlock(&priv->mutex);

	return 0;
}

static int imx_enum_mbus_code(struct v4l2_subdev *sd,
		struct v4l2_subdev_pad_config *cfg,
		struct v4l2_subdev_mbus_code_enum *code)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct imx *priv = to_imx(client);

	if (code->index !=0)
		return -EINVAL;

	code->code = priv->cur_pixelcode;

	return 0;
}

static int imx_enum_frame_size(struct v4l2_subdev *subdev,
		struct v4l2_subdev_pad_config *cfg,
		struct v4l2_subdev_frame_size_enum *fse)
{
	struct i2c_client *client = v4l2_get_subdevdata(subdev);
	struct imx *priv = to_imx(client);

	if (fse->index >= priv->trait->sensor_mode_max)
		return -EINVAL;

	if (fse->code != priv->cur_pixelcode)
		return -EINVAL;

	fse->min_width  = priv->trait->supported_modes[fse->index].width;
	fse->max_width  = fse->min_width;
	fse->min_height = priv->trait->supported_modes[fse->index].height;
	fse->max_height = fse->min_height;

	return 0;
}

static int imx_enum_frame_interval(struct v4l2_subdev *subdev,
		struct v4l2_subdev_pad_config *cfg,
		struct v4l2_subdev_frame_interval_enum *fie)
{
	struct i2c_client *client = v4l2_get_subdevdata(subdev);
	struct imx *priv = to_imx(client);

	if (fie->index >= priv->trait->sensor_mode_max)
		return -EINVAL;

	if (fie->code != priv->cur_pixelcode)
		return -EINVAL;

	fie->width    = priv->trait->supported_modes[fie->index].width;
	fie->height   = priv->trait->supported_modes[fie->index].height;
	fie->interval.numerator   = priv->tpf.numerator;
	fie->interval.denominator = priv->tpf.denominator;
	//	priv->trait->supported_modes[fie->index].max_fps;

	return 0;
}


static int imx_set_fmt(struct v4l2_subdev *sd,
		struct v4l2_subdev_pad_config *cfg,
		struct v4l2_subdev_format *fmt)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct imx *priv = to_imx(client);
	const struct imx_mode *mode = priv->cur_mode;

	priv->crop_rect.left = 0;
	priv->crop_rect.top = 0;

#ifdef PLATFORM_QCOM
#if 0	
//
//TODO check and adjust pixelrate
//
	if (fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE)
	{
		int ret;
		ret = v4l2_ctrl_s_ctrl_int64(priv->ctrl_pixelrate,
				(width*height*fps*depth)) ;
		if (ret < 0)
		{

			dev_err(&client->dev, "could NOT set pixel_clock=%d ret=%d\n",priv->ctrl_pixelrate->val,ret);
			return ret;
		}
		ret = v4l2_ctrl_s_ctrl(priv->ctrl_linkfreq,
					     0);

		if (ret < 0)
		{

			dev_err(&client->dev, "could NOT set link_freq=%d ret=%d\n",priv->ctrl_linkfreq->val,ret);
			return ret;
		}
	}
#endif
#endif
	fmt->format.code       = priv->cur_pixelcode;
	fmt->format.width      = mode->width;
	fmt->format.height     = mode->height;
	fmt->format.field      = V4L2_FIELD_NONE;
	fmt->format.colorspace = V4L2_COLORSPACE_SRGB;

	/* reset crop window */
	if (priv->crop_rect.left < 0)
		priv->crop_rect.left = 0;
	if (priv->crop_rect.top < 0)
		priv->crop_rect.top = 0;
	priv->crop_rect.width = mode->width;
	priv->crop_rect.height = mode->height;

	priv->cur_mode = mode;

	return 0;
}

static int imx_get_fmt(struct v4l2_subdev *sd,
		struct v4l2_subdev_pad_config *cfg,
		struct v4l2_subdev_format *fmt)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct imx *priv = to_imx(client);
	const struct imx_mode *mode = priv->cur_mode;


	fmt->format.width      = mode->width;
	fmt->format.height     = mode->height;
	fmt->format.code       = priv->cur_pixelcode;
	fmt->format.field      = V4L2_FIELD_NONE;
	fmt->format.colorspace = V4L2_COLORSPACE_SRGB;
	priv->format           = fmt->format;

	return 0;
}

static struct v4l2_mbus_framefmt * __imx_get_pad_format(struct imx *imx, struct v4l2_subdev_pad_config *cfg,
		unsigned int pad, enum v4l2_subdev_format_whence which)
{
	switch (which) {
		case V4L2_SUBDEV_FORMAT_TRY:
			return v4l2_subdev_get_try_format(&imx->subdev, cfg, pad);
		case V4L2_SUBDEV_FORMAT_ACTIVE:
			return &imx->format;
		default:
			return NULL;
	}
}

static struct v4l2_rect * __imx_get_pad_crop(struct imx *imx, struct v4l2_subdev_pad_config *cfg,
		unsigned int pad, enum v4l2_subdev_format_whence which)
{
	switch (which) {
		case V4L2_SUBDEV_FORMAT_TRY:
			return v4l2_subdev_get_try_crop(&imx->subdev, cfg, pad);
		case V4L2_SUBDEV_FORMAT_ACTIVE:
			return &imx->crop_rect;
		default:
			return NULL;
	}
}

static int imx_get_selection(struct v4l2_subdev *subdev,
		struct v4l2_subdev_pad_config *cfg,
		struct v4l2_subdev_selection *sel)
{
	struct i2c_client *client = v4l2_get_subdevdata(subdev);
	struct imx *imx = to_imx(client);

	if (sel->target == V4L2_SEL_TGT_CROP_DEFAULT)
	sel->r = *__imx_get_pad_crop(imx, cfg, sel->pad, sel->which);
		return 0;

	if (sel->target == V4L2_SEL_TGT_CROP_BOUNDS)
	sel->r = *__imx_get_pad_crop(imx, cfg, sel->pad, sel->which);
		return 0;

	if (sel->target != V4L2_SEL_TGT_CROP)
		return -EINVAL;

	sel->r = *__imx_get_pad_crop(imx, cfg, sel->pad, sel->which);
	return 0;
}

static int imx_set_selection(struct v4l2_subdev *subdev,
		struct v4l2_subdev_pad_config *cfg,
		struct v4l2_subdev_selection *sel)
{
	struct i2c_client *client = v4l2_get_subdevdata(subdev);
	struct imx *priv = to_imx(client);
	struct v4l2_mbus_framefmt *__format;
	struct v4l2_rect *__crop;
	struct v4l2_rect rect;

//	dev_info(&client->dev, "set_selection: pad=%u target=%u s\n",
//		sel->pad, sel->target);

//	if (sel->pad != 0)
//		return -EINVAL;
	if (sel->target == V4L2_SEL_TGT_CROP_DEFAULT)
		return 0;

	if (sel->target == V4L2_SEL_TGT_CROP_BOUNDS)
		return 0;

	if (sel->target != V4L2_SEL_TGT_CROP)
		return -EINVAL;

	/* Clamp the crop rectangle boundaries and align them to a multiple of 2
	 * pixels.
	 */

	rect.left   = clamp(                ALIGN(sel->r.left,   2), (s32)priv->content.hStart,    (s32)priv->content.hOutSize - 1);
	rect.top    = clamp(                ALIGN(sel->r.top,    2), (s32)priv->content.vStart,    (s32)priv->content.vOutSize - 1);
	rect.width  = clamp_t(unsigned int, ALIGN(sel->r.width,  2),                         1,     priv->content.hOutSize - rect.left);
	rect.height = clamp_t(unsigned int, ALIGN(sel->r.height, 2),                         1,     priv->content.vOutSize - rect.top );

	rect.width  = min_t(unsigned int, rect.width,  priv->content.hOutSize - rect.left);
	rect.height = min_t(unsigned int, rect.height, priv->content.vOutSize - rect.top);

	__crop = __imx_get_pad_crop(priv, cfg, sel->pad, sel->which);

	if (rect.width != __crop->width || rect.height != __crop->height) {
		/* Reset the output image size if the crop rectangle size has
		 * been modified.
		 */
		__format = __imx_get_pad_format(priv, cfg, sel->pad,
				sel->which);
		__format->width = rect.width;
		__format->height = rect.height;
	}

	*__crop = rect;
	sel->r = rect;

	return 0;
}

/* Various V4L2 operations tables */
static struct v4l2_subdev_video_ops imx_subdev_video_ops = {
	.s_stream = imx_s_stream,
	.s_frame_interval = imx_s_frame_interval,
	.g_frame_interval = imx_g_frame_interval,

};

static struct v4l2_subdev_core_ops imx_subdev_core_ops = {
	.s_power = imx_s_power,
#if LC_IMX296_TEST // enable for TEST IMX296 with libcamera
	.subscribe_event = v4l2_ctrl_subdev_subscribe_event,
	.unsubscribe_event = v4l2_event_subdev_unsubscribe,
#endif
};

static const struct v4l2_subdev_pad_ops imx_subdev_pad_ops = {
	.enum_mbus_code = imx_enum_mbus_code,
	.enum_frame_size = imx_enum_frame_size,
	.enum_frame_interval = imx_enum_frame_interval,
	.set_fmt = imx_set_fmt,
	.get_fmt = imx_get_fmt,
	.get_selection = imx_get_selection,
	.set_selection = imx_set_selection,
};

static struct v4l2_subdev_ops imx_subdev_ops = {
	.core = &imx_subdev_core_ops,
	.video = &imx_subdev_video_ops,
	.pad = &imx_subdev_pad_ops,
};

static const struct v4l2_ctrl_ops imx_ctrl_ops = {
	.s_ctrl = imx_s_ctrl,
};

static int imx_video_probe(struct i2c_client *client, struct imx *priv)
{
	u16 model_id, check_id, check_id2=-1, check_id3=-1;
	u32 lot_id=0;
	u16 chip_id=0;
	int ret=0;

	/* Check and show model, lot, and chip ID. */
	if(sen_reg(priv, MODEL_ID_HIGH))
		ret = vc_mipi_common_reg_read(client, sen_reg(priv, MODEL_ID_HIGH));
	if (ret < 0) {
		dev_err(&client->dev, "Failure to read Model ID (high byte)\n");
		goto done;
	}
	model_id = (ret << 8) & 0xff00;

	if(sen_reg(priv, MODEL_ID_LOW))
		ret = vc_mipi_common_reg_read(client, sen_reg(priv, MODEL_ID_LOW));
	if (ret < 0) {
		dev_err(&client->dev, "Failure to read Model ID (low byte)\n");
		goto done;
	}
	model_id |= ret & 0x00ff;


	switch(priv->model)
	{
		case IMX290_MODEL_MONOCHROME:
		case IMX290_MODEL_COLOR:
		case IMX327_MODEL_MONOCHROME:
		case IMX327_MODEL_COLOR:
		case IMX462_MODEL_MONOCHROME:
		case IMX462_MODEL_COLOR:
			check_id = 0x07D0;
			break;
		case IMX335_MODEL_MONOCHROME:
		case IMX335_MODEL_COLOR:
			check_id = 0x0518;
			//ROM has already doubled vOutsize
			priv->content.vOutSize = priv->content.vOutSize / 2;
			dev_info(&client->dev, "FIX /2 vOutSize:%8u\n", priv->content.vOutSize);
			break;
		case IMX273_MODEL_MONOCHROME:
		case IMX273_MODEL_COLOR:
#ifndef PLATFORM_QCOM
			check_id = 0x0273;
			break;
#endif
		case IMX296_MODEL_MONOCHROME_S:
		case IMX296_MODEL_COLOR_S:
			//ROM has halfed vOutsize
			if(priv->cur_mode->sensor_mode >= (IMX296_S_SENSOR_MODE_MAX/2))
			{
			  priv->content.vOutSize = priv->content.vOutSize * 2;
			  dev_info(&client->dev, "FIX *2 vOutSize:%8u\n", priv->content.vOutSize);
			}
			else //ROM has halfed hOutsize
			{
			  priv->content.hOutSize = priv->content.hOutSize * 2;
			  dev_info(&client->dev, "FIX *2 hOutSize:%8u\n", priv->content.hOutSize);
			}
			        // Intentional fall-through
        /* fall through */
		case IMX296_MODEL_MONOCHROME:
		case IMX297_MODEL_MONOCHROME:
		case IMX296_MODEL_COLOR:
		case IMX296_MODEL_COLOR_R:
		case IMX297_MODEL_COLOR:
			check_id = 0x0494;
			break;
		case IMX412_MODEL_MONOCHROME:
		case IMX412_MODEL_COLOR:
			check_id = 0x0577;
			break;
		case IMX415_MODEL_MONOCHROME:
			check_id = 0x0514;
			check_id2 = 0x0;
			//ROM has already doubled vOutsize
			priv->content.vOutSize = priv->content.vOutSize / 2;
			dev_info(&client->dev, "FIX /2 vOutSize:%8u\n", priv->content.vOutSize);
			break;
		case IMX415_MODEL_COLOR:
			check_id = 0x4514;
			check_id2 = 0x0;
			//ROM has already doubled vOutsize
			priv->content.vOutSize = priv->content.vOutSize / 2;
			dev_info(&client->dev, "FIX /2 vOutSize:%8u\n", priv->content.vOutSize);
			break;
		case OV9281_MODEL_MONOCHROME:
		case OV9281_MODEL_COLOR:
			check_id = 0x9281;
			break;
		case IMX178_MODEL_MONOCHROME:
		case IMX178_MODEL_COLOR:
			check_id = 0x0178;
			break;
		case IMX183_MODEL_MONOCHROME:
		case IMX183_MODEL_COLOR:
			check_id = 0x0183;
			break;
		case IMX226_MODEL_MONOCHROME:
		case IMX226_MODEL_COLOR:
			check_id = 0x0226;
			break;
		case IMX252_MODEL_MONOCHROME:
		case IMX252_MODEL_COLOR:
			check_id = 0x0252;
			break;
		case OV7251_MODEL_MONOCHROME:
		case OV7251_MODEL_COLOR:
			check_id = 0x7750;
			break;
		case IMX250_MODEL_MONOCHROME:
		case IMX250_MODEL_COLOR:
			check_id = 0x0250;
			break;
		case IMX392_MODEL_MONOCHROME:
		case IMX392_MODEL_COLOR:
			check_id = 0x0392;
			break;
		case IMX264_MODEL_MONOCHROME:
		case IMX264_MODEL_COLOR:
			check_id = 0x0264;
			break;
		case IMX265_MODEL_MONOCHROME:
		case IMX265_MODEL_COLOR:
			check_id = 0x0265;
			break;
		case IMX565_MODEL_MONOCHROME:
			check_id = 0xc6af; // IMX565
			break;
		case IMX565_MODEL_COLOR:
			check_id = 0x46af; // IMX565C
			break;
		case IMX566_MODEL_MONOCHROME:
			check_id = 0xc6cf; // IMX566
			break;
		case IMX566_MODEL_COLOR:
			check_id = 0x46cf; // IMX566C
			break;
		case IMX568_MODEL_MONOCHROME:
			check_id  = 0xc6ef; // IMX567
			check_id2 = 0xc70c; // IMX568
			break;
		case IMX568_MODEL_COLOR:
			check_id  = 0x46ef; // IMX567C
			check_id2 = 0x470c; // IMX568C
			break;
		case IMX900_MODEL_MONOCHROME:
			check_id  = 0xf080; // IMX900
			break;
		case IMX900_MODEL_COLOR:
			check_id  = 0x7080; // IMX900C 
			break;
		case IMX585_MODEL_MONOCHROME:
			check_id  = 0x0000; // IMX585
			break;
		case IMX585_MODEL_COLOR:
			check_id  = 0x0000; // IMX585C
			break;
		default:
			return -EINVAL;
	}

	if ( ! ((model_id == check_id) || (model_id == check_id2) || (model_id == check_id3)) ) {

		dev_err(&client->dev, "Model ID: %x not supported!\n",
				model_id);
		ret = -ENODEV;
		goto done;
	}


	if( sen_reg(priv, CHIP_REV) ) // chip_id register not always availabale
	{
		ret = vc_mipi_common_reg_read(client, sen_reg(priv, CHIP_REV));
		if (ret < 0) {
			dev_err(&client->dev, "Failure to read Chip ID (low byte)\n");
			goto done;
		}
		chip_id = ret;
	}

	dev_info(&client->dev,
			"Model ID 0x%04x, Lot ID 0x%06x, Chip ID 0x%04x\n",
			model_id, lot_id, chip_id);
done:
	return ret;
}

static int imx_ctrls_init(struct v4l2_subdev *sd)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct imx *priv = to_imx(client);
        struct v4l2_fwnode_device_properties props;
        unsigned int hblank;
        int ret;
		(void)hblank; //TODO Suppress unused variable warning

        ret = v4l2_fwnode_device_parse(&client->dev, &props);
        if (ret < 0)
                return ret;

	v4l2_ctrl_handler_init(&priv->ctrl_handler, 10);

	v4l2_ctrl_new_std(&priv->ctrl_handler, &imx_ctrl_ops,
			V4L2_CID_HFLIP, 0, 1, 1, 0);

	v4l2_ctrl_new_std(&priv->ctrl_handler, &imx_ctrl_ops,
			V4L2_CID_VFLIP, 0, 1, 1, 0);

	v4l2_ctrl_new_std(&priv->ctrl_handler, &imx_ctrl_ops,
			V4L2_CID_ANALOGUE_GAIN,
			priv->trait->gain_digital_min,
			priv->trait->gain_digital_max, 1,
			priv->trait->gain_digital_default);

	v4l2_ctrl_new_std(&priv->ctrl_handler, &imx_ctrl_ops,
			V4L2_CID_GAIN,
			priv->trait->gain_digital_min,
			priv->trait->gain_digital_max, 1,
			priv->trait->gain_digital_default);

#if LC_IMX296_TEST // enable for TEST IMX296 with libcamera
#define IMX296_PIXEL_ARRAY_WIDTH			1456
#define IMX296_PIXEL_ARRAY_HEIGHT			1088
#ifdef IMX296_PIXEL_ARRAY_WIDTH
	/*
         * Horizontal blanking is controlled through the HMAX register, which
         * contains a line length in INCK clock units. The INCK frequency is
         * fixed to 74.25 MHz. The HMAX value is currently fixed to 1100,
         * convert it to a number of pixels based on the nominal pixel rate.
         */
        hblank = 1100 * 1188000000ULL / 10 / 74250000
               - IMX296_PIXEL_ARRAY_WIDTH;
        priv->hblank = v4l2_ctrl_new_std(&priv->ctrl_handler, &imx_ctrl_ops,
                                           V4L2_CID_HBLANK, hblank, hblank, 1,
                                           hblank);
        if (priv->hblank)
                priv->hblank->flags |= V4L2_CTRL_FLAG_READ_ONLY;

        priv->vblank = v4l2_ctrl_new_std(&priv->ctrl_handler, &imx_ctrl_ops,
                                           V4L2_CID_VBLANK, 30,
                                           1048575 - IMX296_PIXEL_ARRAY_HEIGHT,
                                           1, 30);
#endif
#endif

	v4l2_ctrl_new_std(&priv->ctrl_handler, &imx_ctrl_ops,
			V4L2_CID_EXPOSURE,
			priv->trait->exposure_min,
			priv->trait->exposure_max, 1,
			priv->trait->exposure_default);

#if 1
	{
		u64 divresult;
		u32 divisor ,remainder;
		divresult = priv->cur_linkfreq * 2 * *(priv->cur_datalanes);
		divisor   = priv->cur_mode->sensor_depth;
		remainder = (u32)(do_div(divresult,divisor)); // caution: division result value at dividend!

		priv->ctrl_pixelrate = v4l2_ctrl_new_std(&priv->ctrl_handler, &imx_ctrl_ops,
				V4L2_CID_PIXEL_RATE,
				1,
				(priv->cur_linkfreq/2),
				1,
				(divresult/2)) ;


		priv->cur_pixelrate=divresult;

		priv->ctrl_linkfreq = v4l2_ctrl_new_int_menu(&priv->ctrl_handler, &imx_ctrl_ops,
				V4L2_CID_LINK_FREQ,
				0,
				0, &priv->cur_linkfreq); // currently only index 0

		if (priv->ctrl_linkfreq)
			priv->ctrl_linkfreq->flags |= V4L2_CTRL_FLAG_READ_ONLY;
	}
#endif

	v4l2_ctrl_new_fwnode_properties(&priv->ctrl_handler, &imx_ctrl_ops,
                                        &props);

	priv->subdev.ctrl_handler = &priv->ctrl_handler;
	if (priv->ctrl_handler.error) {
		dev_err(&client->dev, "Error %d adding controls\n",
				priv->ctrl_handler.error);
		ret = priv->ctrl_handler.error;
		goto error;
	}

	ret = v4l2_ctrl_handler_setup(&priv->ctrl_handler);
	if (ret < 0) {
		dev_err(&client->dev, "Error %d setting default controls\n",
				ret);
		goto error;
	}

	return 0;
error:
	v4l2_ctrl_handler_free(&priv->ctrl_handler);
	return ret;
}


static int imx_devicetree_read(struct i2c_client *client, struct imx_dtentry *dtentry)
{
	struct device_node *endpoint;
	struct device_node *node;
	const __be32 *prop; // property is defined as big endian integer
	int len;            // property len is sizeof(u32)

	/*
	 * read config-io and sensor_mode property
	 */

	node = (&client->dev)->of_node;

	if (!node) {
		dev_err(&client->dev, "device node not found\n");
		return -EINVAL;
	}

	prop = of_get_property(node, "io-config", &len);   // read property from device node

	if(prop && len == sizeof(u32)) {
		dtentry->io_config = be32_to_cpu(prop[0]);
		dev_info(&client->dev, "read property io-config = %d\n",dtentry->io_config);
	}

	prop = of_get_property(node, "external-trigger-mode-overwrite", &len); // read property from device node

	if(prop && len == sizeof(u32)) {
		dtentry->enable_extrig = be32_to_cpu(prop[0]); // set ext trig source to pin=1 or selftriggered=4 
		dev_info(&client->dev, "read property external-trigger-mode-overwrite = %d\n",dtentry->enable_extrig);
	}
	else
	{

		prop = of_get_property(node, "external-trigger-mode", &len); // read property from device node

		if(prop && len == sizeof(u32)) {
			dtentry->enable_extrig = be32_to_cpu(prop[0]); // set ext trig source to pin=1 or selftriggered=4 
			dev_info(&client->dev, "read property external-trigger-mode = %d\n",dtentry->enable_extrig);
		}
		else
			dtentry->enable_extrig = 1; // set ext trig source to pin=1 as fallback
	}

	prop = of_get_property(node, "sensor-mode", &len);   // read property from device node

	if(prop && len == sizeof(u32)) {
		dtentry->sensor_mode = be32_to_cpu(prop[0]); // read property sensor_mode
		dev_info(&client->dev, "read property sensor-mode = %d\n", dtentry->sensor_mode);
	}

	node = of_get_child_by_name((&client->dev)->of_node, "camera-clk");
	if (!node) {
		dev_err(&client->dev, "child 'camera-clk' in DT not found\n");
	}
	else
	{

		prop = of_get_property(node, "clock-frequency", &len);   // read property from device node

		if(prop && len == sizeof(u32)) {
			dtentry->sen_clk = be32_to_cpu(prop[0]); // set sensor oscillator clock in HZ normal=54Mhz IMX183=72Mhz
			dev_info(&client->dev, "read property clock-frequency = %d\n",dtentry->sen_clk);
		}
		of_node_put(node);
	}

	/*
	 * read data-lanes and link-frequencies property
	 */

	endpoint = of_graph_get_next_endpoint((&client->dev)->of_node, NULL);
	if (!endpoint) {
		dev_err(&client->dev, "endpoint node not found\n");
		return -EINVAL;
	}

	dtentry->data_lanes = fwnode_property_read_u32_array(of_fwnode_handle(endpoint), "data-lanes", NULL, 0);
	if(dtentry->data_lanes) // number of entries in data-lanes property
		dev_info(&client->dev, "read property data-lanes = %d\n",dtentry->data_lanes);

	len = fwnode_property_read_u64_array(of_fwnode_handle(endpoint), "link-frequencies", &(dtentry->linkfreq), 1);
	if(!len) // first link-frequency in property array found
		dev_info(&client->dev, "read property link-frequencies[0] = %lld\n",dtentry->linkfreq);

	return 0;
}



static int imx_get_model_and_mode(struct i2c_client *client, struct imx_dtentry *dtentry, struct vc_rom_table *rom_table, int color, enum imx_model *model, const struct imx_trait **trait, const struct imx_mode **cur_mode, s32 *cur_pixelcode, s64 *cur_linkfreq, u8 **cur_datalanes, int stereo)
{
	*model = imx_model_by_mod_id(rom_table->mod_id, color, stereo);

	if(IMX_MODEL_UNKNOWN == *model)
	{
		dev_err(&client->dev, "VC Sensor model: Unknown Sensor Module ID %d\n", rom_table->mod_id);
		return -EINVAL;
	}
	dev_info(&client->dev, "VC Sensor model: %s (%d)\n", str_imx_model(*model), *model);


	*trait =  imx_trait_by_model(*model);

	if(NULL == *trait)
	{
		dev_err(&client->dev, "VC Sensor device-tree:  No traits of sensor model %s (%d)\n", str_imx_model(*model), *model);
		return -EINVAL;
	}


	if((dtentry->sensor_mode >= (rom_table->nr_modes)) ||
		(dtentry->sensor_mode >= (*trait)->sensor_mode_max) ||
		(dtentry->sensor_mode < 0))
	{
		dev_err(&client->dev, "VC Sensor device-tree:  sensor-mode %d must be smaller than %d and non-negative\n", dtentry->sensor_mode, (*trait)->sensor_mode_max);
		return -EINVAL;
	}


	*cur_mode = &((*trait)->supported_modes[dtentry->sensor_mode]);


	rom_table->mode_format = vc_rom_table_mode_format_mipi;


	*cur_linkfreq = rom_table->mode[dtentry->sensor_mode].format_mipi->data_rate;

	/* workaround for bad programmed modules */
	if(0==*cur_linkfreq)
		*cur_linkfreq = dtentry->linkfreq;

	if(*cur_linkfreq != dtentry->linkfreq)
	{
		dev_err(&client->dev, "VC Sensor device-tree:  Link frequency of rom table %lld differs from device tree %lld entry\n",
				*cur_linkfreq, dtentry->linkfreq);
#ifdef PLATFORM_QCOM
		//TODO add device-tree entry for QCOM
#else
		return -EINVAL;
#endif
	}


	switch((*cur_mode)->sensor_depth)
	{
		case  8:   *cur_pixelcode = mbus_pixelcode_by_model_depth8(*model);   break;
		case 10:   *cur_pixelcode = mbus_pixelcode_by_model_depth10(*model);  break;
		case 12:   *cur_pixelcode = mbus_pixelcode_by_model_depth12(*model);  break;
		case 14:   *cur_pixelcode = mbus_pixelcode_by_model_depth14(*model);  break;
		default: return -EINVAL;
	}
	if(*cur_pixelcode < 0)
	{
		dev_err(&client->dev, "VC Sensor device-tree:  Unknown MBus Pixel Code for sensor model %s (%d), bit depth %d\n", str_imx_model(*model), *model, (*cur_mode)->sensor_depth);
		return -EINVAL;
	}


	/* check consistence */
	*cur_datalanes = &(rom_table->mode[dtentry->sensor_mode].format_mipi->data_lanes);

	/* workaround for bad programmed modules */
	if(0==*(*cur_datalanes))
		*(*cur_datalanes) = dtentry->data_lanes;

	if (*model == IMX296_MODEL_COLOR_R)
		*(*cur_datalanes) = dtentry->data_lanes;

	if(*(*cur_datalanes) != dtentry->data_lanes)
	{
		dev_err(&client->dev, "VC Sensor device-tree:  Number of data-lanes must be %d for sensor-mode %d\n", *(*cur_datalanes), dtentry->sensor_mode);
		return -EINVAL;
	}


	dev_info(&client->dev, "VC Sensor device-tree has configured %d data-lanes! [ sensor_mode = %d ]\n", dtentry->data_lanes, dtentry->sensor_mode);


	return 0;
}



#if LINUX_VERSION_CODE < KERNEL_VERSION(6,3,0)
static int imx_probe(struct i2c_client *client,
		const struct i2c_device_id *did)
#else
static int imx_probe(struct i2c_client *client)
#endif
{
	int    ret;
	struct imx_dtentry dtentry = NULL_imx_dtentry;
	struct imx         *priv;

	struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);

	dev_info(&client->dev,"%s (%s) probe\n",
			THIS_MODULE->name,
			THIS_MODULE->version);

#ifdef PLATFORM_QCOM
	// QCOM camera i2c bus does not support SMBUS
#else
	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
		dev_warn(&adapter->dev,
				"I2C-Adapter doesn't support I2C_FUNC_SMBUS_BYTE\n");
		return -EIO;
	}
#endif

	priv = devm_kzalloc(&client->dev, sizeof(struct imx), GFP_KERNEL);

	if (!priv)
		return -ENOMEM;

	mutex_init(&priv->mutex);

	/*
	 * init platform
	 */

	if( (ret = vc_mipi_common_platform_init(client, &priv->io_regulator, &priv->core_regulator, &priv->analog_regulator, &priv->rst_gpio)) )
		goto err_out;

	/*
	 * read ROM table information
	 */

	if( (ret = vc_mipi_common_rom_table_read(client, &priv->rom, &priv->rom_table, &priv->color, &priv->stereo)) )
		goto err_out;

	/*
	 * parse device-tree
	 */

	if( (ret = imx_devicetree_read(client, &dtentry)) )
		goto err_out;

	priv->sen_clk = dtentry.sen_clk;

	priv->enable_extrig   = dtentry.enable_extrig;

	priv->io_config       = dtentry.io_config;

	/*
	 * overwrite device-tree sensor_mode if applied to module
	 */
	if( sensor_mode >= 0)
	{
		dtentry.sensor_mode = sensor_mode;
	}

	// HACK for RGB TODO add dt-property
	if( priv->color == 1 && priv->rom_table.mod_id == 0x296 && dtentry.data_lanes == 4 ) {
		*priv->cur_datalanes = 4;
		priv->color = 2;
		dev_info(&client->dev,"RGB initialized\n");
	}

	if( (ret = imx_get_model_and_mode(client, &dtentry, &priv->rom_table, priv->color, &priv->model, &priv->trait,
		&priv->cur_mode, &priv->cur_pixelcode, &priv->cur_linkfreq, &priv->cur_datalanes, priv->stereo)) )
		goto err_out;

	if( (ret = vc_mipi_common_rom_init(client, priv->rom, priv->cur_mode->sensor_mode)) )
		goto err_out;

	if( (ret = vc_mipi_common_read_sen_reg_content(client, &priv->rom_table, &priv->content)) )
		goto err_out;

	/*
	 * keep a modifyable copy of the sensor_mode to work with
	 */
	priv->work_mode = *(priv->cur_mode );
	priv->cur_mode  = &(priv->work_mode);

	/*
	 * init crop
	 */

	priv->crop_rect.left = 0;
	priv->crop_rect.top = 0;
	priv->crop_rect.width = priv->cur_mode->width;
	priv->crop_rect.height = priv->cur_mode->height;

	ret = imx_video_probe(client, priv);
	if (ret < 0)
	{
		ret = -EIO;
		goto err_out;
	}

	// frame_interval
	priv->tpf.numerator = 1000;
	priv->tpf.denominator = priv->cur_mode->max_fps*1000;

	v4l2_i2c_subdev_init(&priv->subdev, client, &imx_subdev_ops);
	ret = imx_ctrls_init(&priv->subdev);
	if (ret < 0)
		goto err_out;

#if LC_IMX296_TEST // enable for TEST IMX296 with libcamera
	priv->subdev.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE | V4L2_SUBDEV_FL_HAS_EVENTS;
#else
	priv->subdev.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
#endif
	priv->pad.flags = MEDIA_PAD_FL_SOURCE;

	priv->subdev.entity.function = MEDIA_ENT_F_CAM_SENSOR;
	ret = media_entity_pads_init(&priv->subdev.entity, 1, &priv->pad);
	if (ret < 0)
		goto err_out;

#if LC_IMX296_TEST // enable for TEST IMX296 with libcamera
	ret = v4l2_async_register_subdev_sensor(&priv->subdev);
#else
	ret = v4l2_async_register_subdev(&priv->subdev);
#endif

err_out:
	if (ret < 0)
	{
		if(priv->rom)
		{
			vc_mipi_common_rom_init(client, priv->rom, -1);
			i2c_unregister_device(priv->rom);
		}
		return ret;
	}
	return ret;
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(6,0,0)
static int imx_remove(struct i2c_client *client)
#else
static void imx_remove(struct i2c_client *client)
#endif
{
	struct imx *priv = to_imx(client);

	if(priv->rom)
	{
		vc_mipi_common_rom_init(client, priv->rom, -1);
		i2c_unregister_device(priv->rom);
	}
	v4l2_async_unregister_subdev(&priv->subdev);
	media_entity_cleanup(&priv->subdev.entity);
	v4l2_ctrl_handler_free(&priv->ctrl_handler);

	dev_info(&client->dev,"%s (%s) remove\n",
			THIS_MODULE->name,
			THIS_MODULE->version);

#if LINUX_VERSION_CODE < KERNEL_VERSION(6,0,0)
	return 0;
#endif
}

static const struct i2c_device_id imx_id[] = {
	{"vc_mipi_modules_0", 0},
	{}
};

static const struct of_device_id imx_of_match[] = {
	{ .compatible = "vc,vc_mipi_modules" },
	{ .compatible = "sony,vc_mipi_imx183" },
	{ .compatible = "sony,vc_mipi_imx226" },
	{ .compatible = "sony,vc_mipi_imx252" },
	{ .compatible = "sony,vc_mipi_imx273" },
	{ .compatible = "sony,vc_mipi_imx290" },
#ifdef PLATFORM_QCOM
	//TODO adjust name in device-tree
	{ .compatible = "sony,imx273" },
	{ .compatible = "sony,imx296" },
#endif
	{ .compatible = "sony,vc_mipi_imx296" },
	{ .compatible = "sony,vc_mipi_imx297" },
	{ .compatible = "sony,vc_mipi_imx327c" },
	{ .compatible = "sony,vc_mipi_imx412" },
	{ .compatible = "sony,vc_mipi_imx415" },
	{ .compatible = "omnivision,vc_mipi_ov9281" },
	{ /* sentinel */ },
};
MODULE_DEVICE_TABLE(of, imx_of_match);

MODULE_DEVICE_TABLE(i2c, imx_id);
static struct i2c_driver imx_i2c_driver = {
	.driver = {
		.of_match_table = of_match_ptr(imx_of_match),
		.name = "vc_mipi_modules_0",
	},
	.probe = imx_probe,
	.remove = imx_remove,
	.id_table = imx_id,
};

module_i2c_driver(imx_i2c_driver);
MODULE_VERSION("0.2.8");
MODULE_DESCRIPTION("Vision Components GmbH - VC MIPI IMX driver");
MODULE_AUTHOR("Michael Steinel, Vision Components GmbH <mipi-tech@vision-components.com>");
MODULE_LICENSE("GPL v2");
