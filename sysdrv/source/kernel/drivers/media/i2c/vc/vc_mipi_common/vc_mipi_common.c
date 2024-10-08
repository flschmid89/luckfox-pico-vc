/*************************************************
 *
 * Copyright Vision Components 2024
 *
 * vc_rom_table.h
 *
 * Author: Michael Steinel
 *
 *************************************************/
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

#include "vc_mipi_common.h"


int vc_mipi_common_read_sen_reg_content(struct i2c_client *client, struct vc_rom_table *rom_table,  struct vc_sen_reg_content *content)
{
	int  tgt, byteNr;
	u8 * valOut = NULL;
	u16  addr;
	u32  reg;
	enum vc_rom_table_sreg_names  eTgt;

	tgt = 0;
	while(1)
	{
		switch(tgt++)
		{
			case  0:  eTgt = MODEL_ID_HIGH;    byteNr=1;  valOut=(u8*)&content->modelId;    break;
			case  1:  eTgt = MODEL_ID_LOW;     byteNr=0;  valOut=(u8*)&content->modelId;    break;
			case  2:  eTgt = CHIP_REV;         byteNr=0;  valOut=(u8*)&content->chipRev;    break;
			case  3:  eTgt = IDLE;             byteNr=0;  valOut=(u8*)&content->stateIdle;  break;
			case  4:  eTgt = H_START_HIGH;     byteNr=1;  valOut=(u8*)&content->hStart;     break;
			case  5:  eTgt = H_START_LOW;      byteNr=0;  valOut=(u8*)&content->hStart;     break;
			case  6:  eTgt = V_START_HIGH;     byteNr=1;  valOut=(u8*)&content->vStart;     break;
			case  7:  eTgt = V_START_LOW;      byteNr=0;  valOut=(u8*)&content->vStart;     break;
			case  8:  eTgt = H_SIZE_HIGH;      byteNr=1;  valOut=(u8*)&content->hSize;      break;
			case  9:  eTgt = H_SIZE_LOW;       byteNr=0;  valOut=(u8*)&content->hSize;      break;
			case 10:  eTgt = V_SIZE_HIGH;      byteNr=1;  valOut=(u8*)&content->vSize;      break;
			case 11:  eTgt = V_SIZE_LOW;       byteNr=0;  valOut=(u8*)&content->vSize;      break;
			case 12:  eTgt = H_OUTPUT_HIGH;    byteNr=1;  valOut=(u8*)&content->hOutSize;   break;
			case 13:  eTgt = H_OUTPUT_LOW;     byteNr=0;  valOut=(u8*)&content->hOutSize;   break;
			case 14:  eTgt = V_OUTPUT_HIGH;    byteNr=1;  valOut=(u8*)&content->vOutSize;   break;
			case 15:  eTgt = V_OUTPUT_LOW;     byteNr=0;  valOut=(u8*)&content->vOutSize;   break;
			case 16:  eTgt = EXPOSURE_HIGH;    byteNr=2;  valOut=(u8*)&content->exposure;   break;
			case 17:  eTgt = EXPOSURE_MIDDLE;  byteNr=1;  valOut=(u8*)&content->exposure;   break;
			case 18:  eTgt = EXPOSURE_LOW;     byteNr=0;  valOut=(u8*)&content->exposure;   break;
			case 19:  eTgt = GAIN_HIGH;        byteNr=1;  valOut=(u8*)&content->gain;       break;
			case 20:  eTgt = GAIN_LOW;         byteNr=0;  valOut=(u8*)&content->gain;       break;
			case 21:  eTgt = RESERVED1;        byteNr=0;  valOut=(u8*)&content->RESERVED1;  break;
			case 22:  eTgt = RESERVED2;        byteNr=0;  valOut=(u8*)&content->RESERVED2;  break;
			case 23:  eTgt = RESERVED3;        byteNr=0;  valOut=(u8*)&content->RESERVED3;  break;
			case 24:  eTgt = RESERVED4;        byteNr=0;  valOut=(u8*)&content->RESERVED4;  break;
			case 25:  eTgt = RESERVED5;        byteNr=0;  valOut=(u8*)&content->RESERVED5;  break;
			case 26:  eTgt = RESERVED6;        byteNr=0;  valOut=(u8*)&content->RESERVED6;  break;
			case 27:  eTgt = RESERVED7;        byteNr=0;  valOut=(u8*)&content->RESERVED7;  break;
			default: goto readout_complete;
		}

		addr = sen_reg_rom_table(rom_table, eTgt);

		reg  = vc_mipi_common_reg_read(client, addr);
		if(reg < 0)
		{
			return -EIO;
		}

		dev_dbg(&client->dev, "%s@(0x%04x): %d", str_vc_rom_table_sreg_names(eTgt), addr, reg);

		/* expects diddle endian */
		valOut[byteNr] = (u8)reg;
	}
readout_complete:

	dev_dbg(&client->dev, "  modelId:%8u\n", content->modelId);
	dev_dbg(&client->dev, "  chipRev:%8u\n", content->chipRev);
	dev_dbg(&client->dev, "stateIdle:%8u\n", content->stateIdle);
	dev_dbg(&client->dev, "   hStart:%8u\n", content->hStart);
	dev_dbg(&client->dev, "   vStart:%8u\n", content->vStart);
	dev_dbg(&client->dev, "    hSize:%8u\n", content->hSize);
	dev_dbg(&client->dev, "    vSize:%8u\n", content->vSize);
	dev_info(&client->dev, " hOutSize:%8u\n", content->hOutSize);
	dev_info(&client->dev, " vOutSize:%8u\n", content->vOutSize);
	dev_dbg(&client->dev, " exposure:%8u\n", content->exposure);
	dev_dbg(&client->dev, "     gain:%8u\n", content->gain);
	dev_dbg(&client->dev, "RESERVED1:%8u\n", content->RESERVED1);
	dev_dbg(&client->dev, "RESERVED2:%8u\n", content->RESERVED2);
	dev_dbg(&client->dev, "RESERVED3:%8u\n", content->RESERVED3);
	dev_dbg(&client->dev, "RESERVED4:%8u\n", content->RESERVED4);
	dev_dbg(&client->dev, "RESERVED5:%8u\n", content->RESERVED5);
	dev_dbg(&client->dev, "RESERVED6:%8u\n", content->RESERVED6);
	dev_dbg(&client->dev, "RESERVED7:%8u\n", content->RESERVED7);

	return 0;
}
EXPORT_SYMBOL( vc_mipi_common_read_sen_reg_content );


int vc_mipi_common_rom_table_read(struct i2c_client *client, struct i2c_client **rom, struct vc_rom_table *rom_table, int *color, int *stereo)
{
	int addr, max_addr, reg, i;

	*rom = vc_mipi_common_rom_probe(client->adapter, VC_ROM_I2C_ADDRESS);
	if (NULL==*rom )
	{
		dev_err(&client->dev, "Error !!! VC_SEN_FPGA not found !!!\n");
		return -EIO;
	}

	// read ROM table to RAM
	max_addr = VC_ROM_TABLE_SIZE_MAX;

	for (addr=0; addr < max_addr ; addr++)
	{
		reg = vc_mipi_common_reg_read(*rom, addr+VC_ROM_REG_OFFSET);
		if(reg < 0)
		{
			i2c_unregister_device(*rom);
			return -EIO;
		}

		*((char *)(rom_table)+addr) = (char)reg;

		dev_dbg(&(*rom)->dev, "addr=0x%04x reg=0x%02x\n",addr+VC_ROM_REG_OFFSET,reg);

		/* read only as much modes bytes as there are in that very rom */
		if(&rom_table->magic[0] + addr == &rom_table->modes[0])
		{
			max_addr = 1 + addr + rom_table->bytes_per_mode * rom_table->nr_modes;
			max_addr = max_addr < VC_ROM_TABLE_SIZE_MAX ? max_addr : VC_ROM_TABLE_SIZE_MAX;
			dev_info(&(*rom)->dev, "addr=0x%04x max_addr=0x%04x\n",addr,max_addr);
		}
	}

	// print ROM entries
	dev_info(&(*rom)->dev, "VC_SEN_FPGA found!\n");

	dev_info(&(*rom)->dev, "[ MAGIC  ] [ %s ]\n",
			rom_table->magic);

	dev_info(&(*rom)->dev, "[ MANUF. ] [ %s ] [ MID=0x%04x ]\n",
			rom_table->manuf,
			rom_table->manuf_id);

	dev_info(&(*rom)->dev, "[ SENSOR ] [ %s %s ]\n",
			rom_table->sen_manuf,
			rom_table->sen_type);

	dev_info(&(*rom)->dev, "[ MODULE ] [ ID=0x%04x ] [ REV=0x%04x ]\n",
			rom_table->mod_id,
			rom_table->mod_rev);

	dev_info(&(*rom)->dev, "[ MODES  ] [ NR=0x%04x ] [ BPM=0x%04x ]\n",
			rom_table->nr_modes,
			rom_table->bytes_per_mode);

	if(rom_table->sen_type)
	{
		u32 len = strnlen(rom_table->sen_type,16);
		if(len > 0 && len < 17)
		{
			if( *(rom_table->sen_type+len-1) == 'C' )
			{
				dev_info(&(*rom)->dev, "[ COLOR  ] [ YES ]\n");
				dev_info(&(*rom)->dev, "[ STEREO ] [ NO  ]\n");
				*color  = 1;
				*stereo = 0;
			}
			else if( *(rom_table->sen_type+len-1) == 'Q' )
			{
				dev_info(&(*rom)->dev, "[ COLOR  ] [ YES ]\n");
				dev_info(&(*rom)->dev, "[ STEREO ] [ YES ]\n");
				*color  = 1;
				*stereo = 1;

			}
			else if( *(rom_table->sen_type+len-1) == 'S' )
			{
				dev_info(&(*rom)->dev, "[ COLOR  ] [ NO  ]\n");
				dev_info(&(*rom)->dev, "[ STEREO ] [ YES ]\n");

				*color  = 0;
				*stereo = 1;

			}
			else if( *(rom_table->sen_type+len-1) == 'R' )
			{
				dev_info(&(*rom)->dev, "[ COLOR  ] [ RGB ]\n");
				dev_info(&(*rom)->dev, "[ STEREO ] [ NO  ]\n");

				*color  = 2;
				*stereo = 0;

			}
			else
			{
				dev_info(&(*rom)->dev, "[ COLOR  ] [ NO  ]\n");
				dev_info(&(*rom)->dev, "[ STEREO ] [ NO  ]\n");

				*color  = 0;
				*stereo = 0;
			}
		}//TODO else
	}

	for (addr=0; addr <= sizeof(rom_table->regs); addr+=2)
	{
		dev_dbg(&(*rom)->dev, "VC_SEN_REG[%u]=0x%04x\n", addr/2, sen_reg_rom_table(rom_table, addr/2));
	}


	dev_dbg(&(*rom)->dev, "VC_SEN_REG mode number: %u, bytes per mode: %u\n", rom_table->nr_modes, rom_table->bytes_per_mode);

	rom_table->mode_format = vc_rom_table_mode_format_mipi;
	for (i=0, addr=0; i < rom_table->nr_modes; i++, addr+=rom_table->bytes_per_mode)
	{
		rom_table->mode[i].format_mipi = (struct vc_rom_table_mode_mipi *)(((char*)rom_table->modes) + addr);

		dev_info(&(*rom)->dev, "[ MODE %u ]   format: %s, type: %s, data lanes: %u, lane data rate: %10u bps\n",
				i,
				str_mipi_format(rom_table->mode[i].format_mipi->format),
				str_mipi_trigger_type(rom_table->mode[i].format_mipi->type),
				rom_table->mode[i].format_mipi->data_lanes,
				rom_table->mode[i].format_mipi->data_rate);
	}

	return 0;
}
EXPORT_SYMBOL( vc_mipi_common_rom_table_read );


int vc_mipi_common_rom_init(struct i2c_client *client, struct i2c_client *rom, int _sensor_mode)
{
	static int try=1;
	int addr,reg,data;

	addr = 0x0100; // reset
	data =      2; // powerdown sensor
	reg = vc_mipi_common_reg_write(rom, addr, data);
	if(reg)
		return -EIO;

	if(_sensor_mode < 0)
	{
		mdelay(200); // wait 200ms

		addr = 0x0101; // status
		reg = vc_mipi_common_reg_read(rom, addr);
		dev_info(&rom->dev, "VC_SEN_MODE=%d PowerOFF STATUS=0x%02x\n",_sensor_mode,reg);
		return 0;
	}

	addr = 0x0102; // mode
	data = _sensor_mode; // default 10-bit streaming
	reg = vc_mipi_common_reg_write(rom, addr, data);
	if(reg)
		return -EIO;

	addr = 0x0100; // reset
	data =      0; // powerup sensor
	reg = vc_mipi_common_reg_write(rom, addr, data);
	if(reg)
		return -EIO;

	while(1)
	{
		mdelay(200); // wait 200ms

		addr = 0x0101; // status
		reg = vc_mipi_common_reg_read(rom, addr);

		if(reg & 0x80)
			break;

		if(try++ >  4)
		{
			dev_err(&rom->dev, "!!! ERROR !!! setting VC_SEN_MODE=%d STATUS=0x%02x try=%d\n",_sensor_mode,reg,try);
			return -EIO;
		}

	}

	dev_info(&rom->dev, "VC_SEN_MODE=%d PowerOn STATUS=0x%02x try=%d\n",_sensor_mode,reg,try);

	try=1; // reset try counter

	return 0;
}
EXPORT_SYMBOL( vc_mipi_common_rom_init );

int vc_mipi_common_trigmode_write(struct i2c_client *rom, u32 sensor_ext_trig, u32 exposure_time, u32 io_config, u32 enable_extrig, u32 sen_clk, struct v4l2_fract *tpf, struct vc_rom_table *rom_table)
{
	int ret;
	int addr;
	int data;
	u64 exposure;
	u64 retrigger;
	u64 frame_time;

	frame_time = ((tpf->numerator*1000000)/tpf->denominator); // tpf in microseconds -> retrigger needs us

	if ( rom_table->mod_id == 0x0296 ) // handle IMX296
		frame_time += 666;

	if ( rom_table->mod_id == 0x0183 && frame_time < 966 ) // handle IMX183
		frame_time = 966;

	if (frame_time == 0) frame_time = exposure_time;

	addr = 0x0103; // io configuration
	data = io_config;
	ret = vc_mipi_common_reg_write(rom, addr, data);

	if(sensor_ext_trig)
	{
		exposure  = (exposure_time  * (sen_clk/1000000)); // sen_clk default=54Mhz imx183=72Mhz
		retrigger = (frame_time     * (sen_clk/1000000)); // sen_clk default=54Mhz imx183=72Mhz
		if (retrigger < exposure)
			retrigger = exposure;
		printk("ext_trig exposure=%lld exposure_time=%d\n",exposure,exposure_time);
		printk("ext_trig retrigger=%lld frame_time=%lld\n",retrigger,frame_time);
#if 0
		/* ! CAUTION !
		 * for correct timing this register setting
		 * is now done after DMA start in vc_mipi_module_0 imx_s_stream()
		 * */
		addr = 0x0108; // ext trig enable
		// data =      1; // external trigger enable
		// data =      2; // external static trigger variable shutter enable
		// data =      4; // TEST external self trigger enable
		data = enable_extrig; // external trigger enable
		ret |= vc_mipi_common_reg_write(rom, addr, data);
#endif
		addr = 0x0109; // shutter lsb
		data = exposure & 0xff;
		ret |= vc_mipi_common_reg_write(rom, addr, data);

		addr = 0x010a;
		data = (exposure >> 8) & 0xff;
		ret |= vc_mipi_common_reg_write(rom, addr, data);

		addr = 0x010b;
		data = (exposure >> 16) & 0xff;
		ret |= vc_mipi_common_reg_write(rom, addr, data);

		addr = 0x010c; // shutter msb
		data = (exposure >> 24) & 0xff;
		ret |= vc_mipi_common_reg_write(rom, addr, data);

#if 1
		addr = 0x010d; // retrigger lsb
		data = retrigger & 0xff;
		ret |= vc_mipi_common_reg_write(rom, addr, data);

		addr = 0x010e;
		data = (retrigger >> 8) & 0xff;
		ret |= vc_mipi_common_reg_write(rom, addr, data);

		addr = 0x010f;
		data = (retrigger >> 16) & 0xff;
		ret |= vc_mipi_common_reg_write(rom, addr, data);

		addr = 0x0110; // retrigger msb
		data = (retrigger >> 24) & 0xff;
		ret |= vc_mipi_common_reg_write(rom, addr, data);
#endif

	}

	return ret;
}
EXPORT_SYMBOL( vc_mipi_common_trigmode_write );


int vc_mipi_common_reg_write_table(struct i2c_client *client, const struct vc_mipi_sen_reg table[])
{
	const struct vc_mipi_sen_reg *reg;
	int ret;

	for (reg = table; reg->addr != VC_MIPI_REG_TABLE_END; reg++) {
		ret = vc_mipi_common_reg_write(client, reg->addr, reg->val);
		if (ret < 0)
			return ret;
	}

	return 0;
}
EXPORT_SYMBOL( vc_mipi_common_reg_write_table );


/**
 * Read a multibyte register.
 *
 * @client: Pointer to i2c device structure
 * @addr: Address of the LSB register.  Other registers must be
 *        consecutive, least-to-most significant.
 * @val: Pointer to store the register value (cpu endianness)
 * @nbytes: Number of bytes to read (range: [1..3]).
 *          Other bytes are set to 0.
 *
 * Return: 0 on success, errors otherwise
 */
int vc_mipi_common_read_mbreg(struct i2c_client *client, u16 addr, u32 *val, size_t nbytes)
{
	int err=-1;
	u32 byte;
	u32 tmp_val=0;

	if(nbytes > 3 || nbytes == 0)
		goto  error;

	        //dev_info(&client->dev, "1 addr=%08x byte=%02x tmp_val=0x%08x %u\n",addr,byte,tmp_val,tmp_val);
	for (byte = 0 ; byte < nbytes ; byte++) {
	        //dev_info(&client->dev, "2 addr=%08x byte=%02x tmp_val=0x%08x %u\n",addr,byte,tmp_val,tmp_val);
		err = vc_mipi_common_reg_read(client, addr+byte);
		if (err < 0)
			goto  error;

		tmp_val |= (err & 0xff) << (byte*8);
	        //dev_info(&client->dev, "3 err=0x%08x addr=%08x byte=%02x tmp_val=0x%08x %u\n",err,addr,byte,tmp_val,tmp_val);
	}

	*val = tmp_val;
error:
	//dev_info(&client->dev, "*val=0x%08x %u\n",*val,*val);
	return err;
}

EXPORT_SYMBOL( vc_mipi_common_read_mbreg );

/**
 * Write a multibyte register.
 *
 * @client: Pointer to i2c device structure
 * @addr: Address of the LSB register.  Other registers must be
 *        consecutive, least-to-most significant.
 * @val: Value to be written to the register (cpu endianness)
 * @nbytes: Number of bytes to write (range: [1..3])
 */
int vc_mipi_common_write_mbreg(struct i2c_client *client, u16 addr, u32 val, size_t nbytes)
{
	int err=-1;
	u32 byte;
	u32 reg_val;

	if(nbytes > 3 || nbytes == 0)
		goto  error;

	for (byte = 0 ; byte < nbytes ; byte++) {
		reg_val = (val >> (byte*8)) & 0xff;
		err = vc_mipi_common_reg_write(client, addr+byte, reg_val);
		//dev_info(&client->dev, "err=%i addr=0x%08x reg_val=0x%08x %u\n",
		//		err,
		//		addr+byte,
		//		reg_val,
		//		reg_val);
		if (err < 0)
			goto error;
	}
error:
	return err;
}

EXPORT_SYMBOL( vc_mipi_common_write_mbreg );


#if 1
	static int __init  vc_mipi_common_init(void)
	{
		//printk("called %s()", __FUNCTION__);
		pr_info("%s (%s) init\n",
                        THIS_MODULE->name,
                        THIS_MODULE->version);

		return 0;
	}

	static void __exit  vc_mipi_common_exit(void)
	{
		//printk("called %s()", __FUNCTION__);
		pr_info("%s (%s) exit\n",
                        THIS_MODULE->name,
                        THIS_MODULE->version);
	}

	module_init(vc_mipi_common_init);
	module_exit(vc_mipi_common_exit);
#else

	static int vc_mipi_common_probe(struct i2c_client *client, const struct i2c_device_id *did)
	{
		printk("called %s()", __FUNCTION__);
		return 0;
	}

	static int vc_mipi_common_remove(struct i2c_client *client)
	{
		printk("called %s()", __FUNCTION__);
	}

	static const struct i2c_device_id vc_mipi_common_id[] = {
		{"vc_mipi_common_id", 0},
		{}
	};
	MODULE_DEVICE_TABLE(i2c, vc_mipi_common_id);

	static const struct of_device_id vc_mipi_common_match_table[] = {
		{ .compatible = "" },
		{ /* sentinel */ },
	};
	MODULE_DEVICE_TABLE(of, vc_mipi_common_match_table);


	static struct i2c_driver vc_mipi_common_i2c_driver = {
		.driver = {
			.of_match_table = of_match_ptr(vc_mipi_common_match_table),
			.name = "vc_mipi_common",
		},
		.probe = vc_mipi_common_probe,
		.remove = vc_mipi_common_remove,
		.id_table = vc_mipi_common_id,
	};

	module_i2c_driver(vc_mipi_common_i2c_driver);
#endif


MODULE_VERSION("0.2.8");
MODULE_DESCRIPTION("Vision Components GmbH - VC MIPI Common driver");
MODULE_AUTHOR("Michael Steinel, Vision Components GmbH <mipi-tech@vision-components.com>");
MODULE_LICENSE("GPL v2");

