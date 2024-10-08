#ifndef __VC_MIPI_COMMON__H__
#define __VC_MIPI_COMMON__H__

#include "../vc_mipi_common_platform.h"

#define VC_ROM_REG_OFFSET      (0x1000)
#define VC_MIPI_REG_TABLE_END  (0xffff)


#define VC_ROM_TABLE_NR_MODES_MAX  (256)
#define VC_ROM_TABLE_SIZE_MAX      (sizeof(struct vc_rom_size_hw))

struct vc_rom_size_hw {

	char   magic[12];
	char   manuf[32];
	u16    manuf_id;
	char   sen_manuf[8];
	char   sen_type[16];
	u16    mod_id;
	u16    mod_rev;
	char   regs[56];
	u16    nr_modes;         /*  256   modes */
	u16    bytes_per_mode;   /*   16   bytes */
	char   modes[4096];
};

enum vc_rom_table_mode_format {
	vc_rom_table_mode_format_unknown,
	vc_rom_table_mode_format_mipi,
};

struct vc_rom_table_mode_mipi
{
	u32    data_rate;
	u8     data_lanes;
	u8     format;
	u8     type;
};

union vc_rom_table_mode {
	struct vc_rom_table_mode_mipi *format_mipi;
};

struct vc_rom_table {

	char   magic[12];
	char   manuf[32];
	u16    manuf_id;
	char   sen_manuf[8];
	char   sen_type[16];
	u16    mod_id;
	u16    mod_rev;
	char   regs[56];
	u16    nr_modes;         /*  256   modes */
	u16    bytes_per_mode;   /*   16   bytes */
	char   modes[4096];
	enum vc_rom_table_mode_format  mode_format;
	union  vc_rom_table_mode mode[VC_ROM_TABLE_NR_MODES_MAX]; /* points to  modes */
};



struct vc_sen_reg_content {
	u16    modelId;
	u8     chipRev;
	u8     stateIdle;
	u16    hStart;      /* minimum horizontal position   for current sensor mode */
	u16    vStart;      /* minimum vertical   position   for current sensor mode */
	u16    hSize;       /* horizontal sensor resoultion  for current sensor mode */
	u16    vSize;       /* vertical   sensor resoultion  for current sensor mode */
	u16    hOutSize;    /* horizontal sensor resoultion  for the MIPI interface  */
	u16    vOutSize;    /* vertical   sensor resoultion  for the MIPI interface  */
	u32    exposure;    /* exposure time in us */
	u16    gain;        /* gain in 10*db */
	u8     RESERVED1;
	u8     RESERVED2;
	u8     RESERVED3;
	u8     RESERVED4;
	u8     RESERVED5;
	u8     RESERVED6;
	u8     RESERVED7;
};

enum vc_rom_table_sreg_names {
	MODEL_ID_HIGH = 0,
	MODEL_ID_LOW,
	CHIP_REV,
	IDLE,
	H_START_HIGH,
	H_START_LOW,
	V_START_HIGH,
	V_START_LOW,
	H_SIZE_HIGH,
	H_SIZE_LOW,
	V_SIZE_HIGH,
	V_SIZE_LOW,
	H_OUTPUT_HIGH,
	H_OUTPUT_LOW,
	V_OUTPUT_HIGH,
	V_OUTPUT_LOW,
	EXPOSURE_HIGH,
	EXPOSURE_MIDDLE,
	EXPOSURE_LOW,
	GAIN_HIGH,
	GAIN_LOW,
	RESERVED1,
	RESERVED2,
	RESERVED3,
	RESERVED4,
	RESERVED5,
	RESERVED6,
	RESERVED7,
};

#define  str_vc_rom_table_sreg_names(t) \
              (MODEL_ID_HIGH    == (t))?("(High Byte)                Model-Id")\
             :(MODEL_ID_LOW     == (t))?("(Low  Byte)                Model-Id")\
             :(CHIP_REV         == (t))?("                      Chip Revision")\
             :(IDLE             == (t))?("                        Idle Status")\
             :(H_START_HIGH     == (t))?("(High Byte) Horizontal Sensor Start")\
             :(H_START_LOW      == (t))?("(Low  Byte) Horizontal Sensor Start")\
             :(V_START_HIGH     == (t))?("(High Byte)   Vertical Sensor Start")\
             :(V_START_LOW      == (t))?("(Low  Byte)   Vertical Sensor Start")\
             :(H_SIZE_HIGH      == (t))?("(High Byte) Horizontal Sensor  Size")\
             :(H_SIZE_LOW       == (t))?("(Low  Byte) Horizontal Sensor  Size")\
             :(V_SIZE_HIGH      == (t))?("(High Byte)   Vertical Sensor  Size")\
             :(V_SIZE_LOW       == (t))?("(Low  Byte)   Vertical Sensor  Size")\
             :(H_OUTPUT_HIGH    == (t))?("(High Byte) Horizontal Output  Size")\
             :(H_OUTPUT_LOW     == (t))?("(Low  Byte) Horizontal Output  Size")\
             :(V_OUTPUT_HIGH    == (t))?("(High Byte)   Vertical Output  Size")\
             :(V_OUTPUT_LOW     == (t))?("(Low  Byte)   Vertical Output  Size")\
             :(EXPOSURE_HIGH    == (t))?("(High Byte)          Exposure Value")\
             :(EXPOSURE_MIDDLE  == (t))?("(Mid. Byte)          Exposure Value")\
             :(EXPOSURE_LOW     == (t))?("(Low  Byte)          Exposure Value")\
             :(GAIN_HIGH        == (t))?("(High Byte)              Gain Value")\
             :(GAIN_LOW         == (t))?("(Low  Byte)              Gain Value")\
             :(RESERVED1        == (t))?("                        (Reserved1)")\
             :(RESERVED2        == (t))?("                        (Reserved2)")\
             :(RESERVED3        == (t))?("                        (Reserved3)")\
             :(RESERVED4        == (t))?("                        (Reserved4)")\
             :(RESERVED5        == (t))?("                        (Reserved5)")\
             :(RESERVED6        == (t))?("                        (Reserved6)")\
             :(RESERVED7        == (t))?("                        (Reserved7)")\
            :("UNKNOWN")

#define  str_mipi_format(t) \
              (0x2a    == (t))?("RAW  8 Bit")\
             :(0x2b    == (t))?("RAW 10 Bit")\
             :(0x2c    == (t))?("RAW 12 Bit")\
             :(0x2d    == (t))?("RAW 14 Bit")\
            :("UNKNOWN")

#define  str_mipi_trigger_type(t) \
              (1    == (t))?("IntTrig")\
             :(2    == (t))?("ExtTrig")\
             :(3    == (t))?("SlaveTrig")\
            :("UNKNOWN")

struct vc_mipi_sen_reg {
	u16 addr;
	u8  val;
};




extern  int vc_mipi_common_reg_write_table(struct i2c_client *client, const struct vc_mipi_sen_reg table[]);
extern  int vc_mipi_common_read_sen_reg_content(struct i2c_client *client, struct vc_rom_table *rom_table,  struct vc_sen_reg_content *content);
extern  int vc_mipi_common_rom_table_read(struct i2c_client *client, struct i2c_client **rom, struct vc_rom_table *rom_table, int *color, int *stereo);
extern  int vc_mipi_common_rom_init(struct i2c_client *client, struct i2c_client *rom, int _sensor_mode);
extern  int vc_mipi_common_trigmode_write(struct i2c_client *rom, u32 sensor_ext_trig, u32 exposure_time, u32 io_config, u32 enable_extrig, u32 sen_clk, struct v4l2_fract *tpf, struct vc_rom_table *rom_table);
extern  int vc_mipi_common_read_mbreg(struct i2c_client *client, u16 addr, u32 *val, size_t nbytes);
extern  int vc_mipi_common_write_mbreg(struct i2c_client *client, u16 addr, u32 val, size_t nbytes);

#define sen_reg_rom_table(rom_table, addr) (*((u16 *)(&rom_table->regs[(addr)*2])))




#endif // __VC_MIPI_COMMON__H__
