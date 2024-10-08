#ifndef __VC_MIPI_COMMON_BCM2835__H__
#define __VC_MIPI_COMMON_BCM2835__H__


#define  vc_mipi_common_platform_init  vc_mipi_common_bcm2835_platform_init
#define  vc_mipi_common_rom_probe  vc_mipi_common_bcm2835_rom_probe
#define  vc_mipi_common_reg_write  vc_mipi_common_bcm2835_reg_write
#define  vc_mipi_common_reg_read   vc_mipi_common_bcm2835_reg_read


#define VC_ROM_I2C_ADDRESS     (0x10  )

extern  int vc_mipi_common_bcm2835_platform_init(struct i2c_client *client, struct regulator **io_regulator, struct regulator **core_regulator, struct regulator **analog_regulator, struct gpio_desc **rst_gpio);
extern  struct i2c_client * vc_mipi_common_bcm2835_rom_probe(struct i2c_adapter *adapter, u8 addr);
extern  int vc_mipi_common_bcm2835_reg_write(struct i2c_client *client, const u16 addr, const u8 data);
extern  int vc_mipi_common_bcm2835_reg_read(struct i2c_client *client, const u16 addr);


#endif // __VC_MIPI_COMMON_BCM2835__H__
