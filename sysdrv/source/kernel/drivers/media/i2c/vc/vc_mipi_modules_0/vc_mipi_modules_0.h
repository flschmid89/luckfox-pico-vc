#ifndef __VC_MIPI_MODULES_0__H__
#define __VC_MIPI_MODULES_0__H__

/* IMX290 MCLK:54MHz  1920x1080  60fps  MIPI LANES 2 */
static const struct vc_mipi_sen_reg imx290_init_tab_1920_1080_60fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* IMX290 MCLK:54MHz  1920x1080  120fps  MIPI LANES 4 */
static const struct vc_mipi_sen_reg imx290_init_tab_1920_1080_120fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* MCLK:25MHz  1440x1080  60fps   MIPI LANE1 */
static const struct vc_mipi_sen_reg imx296_init_tab_1440_1080_60fps[] = {
	{0x30af               , 0x08},// Fix Output position of FE code when using Fast trigger
	{VC_MIPI_REG_TABLE_END, 0x00}
};
/* MCLK:25MHz  720x540   120fps   MIPI LANE1 */
static const struct vc_mipi_sen_reg imx297_init_tab_720_540_120fps[] = {
	{0x30af               , 0x08},// Fix Output position of FE code when using Fast trigger
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* IMX327 MCLK:54MHz  1920x1080  60fps  MIPI LANES 2 */
static const struct vc_mipi_sen_reg imx327_init_tab_1920_1080_60fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* IMX327 MCLK:54MHz  1920x1080 120fps  MIPI LANES 4 */
static const struct vc_mipi_sen_reg imx327_init_tab_1920_1080_120fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* IMX335 MCLK:54MHz  1920x1080  60fps  MIPI LANES 2 */
static const struct vc_mipi_sen_reg imx335_init_tab_2560_1964_60fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* IMX335 MCLK:54MHz  1920x1080 120fps  MIPI LANES 4 */
static const struct vc_mipi_sen_reg imx335_init_tab_2560_1964_120fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg imx412_init_tab[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* MCLK:25MHz  640x480  100fps   MIPI LANE1 */
static const struct vc_mipi_sen_reg ov7251_init_tab_640_480_100fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* MCLK:25MHz  1280x800  120fps   MIPI LANE2 */
static const struct vc_mipi_sen_reg ov9281_init_tab_1280_800_120fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/*TODO MCLK:74.25MHz  3072x2048  10fps   MIPI LANE2 */
static const struct vc_mipi_sen_reg imx178_init_tab_3104_2076_120fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/*TODO MCLK:25MHz  5440x3648  10fps   MIPI LANE2 */
static const struct vc_mipi_sen_reg imx183_init_tab_5440_3648_120fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* MCLK:25MHz  1440x1080  60fps   MIPI LANE1 */
static const struct vc_mipi_sen_reg imx273_init_tab_1440_1080_60fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* MCLK:74.25MHz  1440x1080  200fps   MIPI LANE4 */
static const struct vc_mipi_sen_reg imx273_init_tab_1440_1080_200fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* MCLK:74.25MHz  720x540  580fps   MIPI LANE4 */
static const struct vc_mipi_sen_reg imx273_init_tab_720_540_200fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/*TODO MCLK:25MHz  3840x3048  20fps   MIPI LANE2 */
static const struct vc_mipi_sen_reg imx226_init_tab_3840_3048_20fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/*TODO MCLK:25MHz  2048x1536  20fps   MIPI LANE2 */
static const struct vc_mipi_sen_reg imx252_init_tab_2048_1536_20fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* MCLK:74.25MHz  2432x2048  65fps   MIPI LANE2 */
static const struct vc_mipi_sen_reg imx250_init_tab_2432_2048_65fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* MCLK:74.25MHz  2432x2048  35fps   MIPI LANE2 */
static const struct vc_mipi_sen_reg imx264_init_tab_2432_2048_35fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/*TODO MCLK:25MHz  2048x1536  20fps   MIPI LANE2 */
static const struct vc_mipi_sen_reg imx265_init_tab_2048_1536_20fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/*TODO MCLK:25MHz  2048x1536  20fps   MIPI LANE2 */
static const struct vc_mipi_sen_reg imx392_init_tab_1920_1200_20fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* IMX415 MCLK:54MHz  3840x2192  60fps  MIPI LANES 4 and 32fps MIPI LANES 2 */
static const struct vc_mipi_sen_reg imx415_init_tab[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* IMX568 MCLK:54MHz  2448x2048  79fps  MIPI LANES 4 */
static const struct vc_mipi_sen_reg imx568_init_tab_2448_2048_79fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* IMX565 MCLK:54MHz  4128x3008  ??fps  MIPI LANES 4 */
static const struct vc_mipi_sen_reg imx565_init_tab_4128_3008_79fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* IMX566 MCLK:54MHz  2856x2840  ??fps  MIPI LANES 4 */
static const struct vc_mipi_sen_reg imx566_init_tab_2848_2840_79fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

/* IMX900 MCLK:54MHz  2048x1536  TODO XXfps  MIPI LANES 4 */
static const struct vc_mipi_sen_reg imx900_init_tab_2448_2048_79fps[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_290_327[] = {
	{0x3000, 0x00},		/* mode select streaming on */
	{0x3002, 0x00},		/* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_290_327[] = {
	{0x3002, 0x01},		/* mode select streaming off */
	{0x3000, 0x01},		/* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_296_297[] = {
	{0x3000, 0x00},        /* mode select streaming on */
	{0x300A, 0x00},        /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_296_297[] = {
	{0x300A, 0x01},        /* mode select streaming off */
	{0x3000, 0x01},        /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_412[] = {
	{0x100, 0x01},          /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_412[] = {
	{0x100, 0x00},          /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_415[] = {
	{0x3000, 0x00},		/* mode select streaming on */
	{0x3002, 0x00},		/* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_415[] = {
	{0x3002, 0x01},		/* mode select streaming off */
	{0x3000, 0x01},		/* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_ov7251[] = {
	{0x0100, 0x01},         /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_ov7251[] = {
	{0x0100, 0x00},         /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_ov9281[] = {
	{0x0100, 0x01},         /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_ov9281[] = {
	{0x0100, 0x00},         /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_imx178[] = {
	{0x7000, 0x01},         /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_imx178[] = {
	{0x7000, 0x00},         /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_imx183[] = {
	{0x7000, 0x01},         /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_imx183[] = {
	{0x7000, 0x00},         /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_imx226[] = {
	{0x7000, 0x01},         /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_imx226[] = {
	{0x7000, 0x00},         /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

#ifdef PLATFORM_QCOM
static const struct vc_mipi_sen_reg start_273[] = {
	{0x3000, 0x00},        /* mode select streaming on */
	{0x300A, 0x00},        /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_273[] = {
	{0x300A, 0x01},        /* mode select streaming off */
	{0x3000, 0x01},        /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};
#else
static const struct vc_mipi_sen_reg start_273[] = {
	{0x7000, 0x01},         /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_273[] = {
	{0x7000, 0x00},         /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};
#endif

static const struct vc_mipi_sen_reg start_imx252[] = {
	{0x7000, 0x01},         /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_imx252[] = {
	{0x7000, 0x00},         /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_imx250[] = {
	{0x7000, 0x01},         /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_imx250[] = {
	{0x7000, 0x00},         /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_imx264[] = {
	{0x7000, 0x01},         /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_imx264[] = {
	{0x7000, 0x00},         /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_imx392[] = {
	{0x7000, 0x01},         /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_imx392[] = {
	{0x7000, 0x00},         /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg start_568[] = {
	{0x3000, 0x00},        /* mode select streaming on */
	{0x3010, 0x00},        /* mode select streaming on */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_568[] = {
	{0x3010, 0x01},        /* mode select streaming off */
	{0x3000, 0x01},        /* mode select streaming off */
	{VC_MIPI_REG_TABLE_END, 0x00}
};

struct imx_mode {
	u32 sensor_mode;
	u32 sensor_depth;
	u32 sensor_ext_trig;
	u32 width;
	u32 height;
	u32 max_fps;
	const struct vc_mipi_sen_reg *reg_list;
};

struct imx_trait {
	u32 exposure_min;
	u32 exposure_max;
	u32 exposure_default;
	u32 gain_digital_min;
	u32 gain_digital_max;
	u32 gain_digital_default;
	u32 sensor_mode_max;
	const struct imx_mode        *supported_modes;
	const struct vc_mipi_sen_reg *start;
	const struct vc_mipi_sen_reg *stop;
};


struct imx_dtentry {
	u32 sensor_mode;
	u32 data_lanes;
	u32 io_config;
	s64 linkfreq;
	u32 enable_extrig;
	u32 sen_clk;
};
#define NULL_imx_dtentry { 0,0,0,0,0 }





#define IMX290_SENSOR_MODE_MAX (2)
static const struct imx_mode supported_modes_290[IMX290_SENSOR_MODE_MAX] = {
	{
		.sensor_mode     = 0, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 1920,
		.height          = 1080,
		.max_fps         = 60,
		.reg_list        = imx290_init_tab_1920_1080_60fps,
	},
	{
		.sensor_mode     = 1, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 1920,
		.height          = 1080,
		.max_fps         = 120,
		.reg_list        = imx290_init_tab_1920_1080_120fps,
	},
};

static const struct imx_trait  imx_trait_290 = {
		.exposure_min         = 29,
		.exposure_max         = 7602176,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 240,
		.gain_digital_default = 0,
		.sensor_mode_max      = IMX290_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_290,
		.start                = start_290_327,
		.stop                 = stop_290_327,
};




#define IMX296_SENSOR_MODE_MAX (4)
static const struct imx_mode supported_modes_296[IMX296_SENSOR_MODE_MAX] = {
	{
		.sensor_mode     = 0, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 1440,
		.height          = 1080,
		.max_fps         = 60,
		.reg_list        = imx296_init_tab_1440_1080_60fps,
	},
	{
		.sensor_mode     = 1, /* must be equivalent to array index! */
		.sensor_ext_trig = 1,
		.sensor_depth    = 10,
		.width           = 1440,
		.height          = 1080,
		.max_fps         = 60,
		.reg_list        = imx296_init_tab_1440_1080_60fps,
	},
	{
		.sensor_mode     = 2, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 720,
		.height          = 540,
		.max_fps         = 120,
		.reg_list        = imx297_init_tab_720_540_120fps,
	},
	{
		.sensor_mode     = 3, /* must be equivalent to array index! */
		.sensor_ext_trig = 1,
		.sensor_depth    = 10,
		.width           = 720,
		.height          = 540,
		.max_fps         = 120,
		.reg_list        = imx297_init_tab_720_540_120fps,
	},
};

static const struct imx_trait  imx_trait_296 = {
		.exposure_min         = 29,
		.exposure_max         = 15110711,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 480,
		.gain_digital_default = 200,
		.sensor_mode_max      = IMX296_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_296,
		.start                = start_296_297,
		.stop                 = stop_296_297,
};

#define IMX296_S_SENSOR_MODE_MAX (8)
static const struct imx_mode supported_modes_296s[IMX296_S_SENSOR_MODE_MAX] = {
	{
		.sensor_mode     = 0, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 2880,
		.height          = 1080,
		.max_fps         = 60,
		.reg_list        = imx296_init_tab_1440_1080_60fps,
	},
	{
		.sensor_mode     = 1, /* must be equivalent to array index! */
		.sensor_ext_trig = 1,
		.sensor_depth    = 10,
		.width           = 2880,
		.height          = 1080,
		.max_fps         = 60,
		.reg_list        = imx296_init_tab_1440_1080_60fps,
	},
	{
		.sensor_mode     = 2, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 1440,
		.height          = 540,
		.max_fps         = 120,
		.reg_list        = imx297_init_tab_720_540_120fps,
	},
	{
		.sensor_mode     = 3, /* must be equivalent to array index! */
		.sensor_ext_trig = 1,
		.sensor_depth    = 10,
		.width           = 1440,
		.height          = 540,
		.max_fps         = 120,
		.reg_list        = imx297_init_tab_720_540_120fps,
	},
	{
		.sensor_mode     = 4, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 1440,
		.height          = 2160,
		.max_fps         = 60,
		.reg_list        = imx296_init_tab_1440_1080_60fps,
	},
	{
		.sensor_mode     = 5, /* must be equivalent to array index! */
		.sensor_ext_trig = 1,
		.sensor_depth    = 10,
		.width           = 1440,
		.height          = 2160,
		.max_fps         = 60,
		.reg_list        = imx296_init_tab_1440_1080_60fps,
	},
	{
		.sensor_mode     = 6, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 720,
		.height          = 1080,
		.max_fps         = 120,
		.reg_list        = imx297_init_tab_720_540_120fps,
	},
	{
		.sensor_mode     = 7, /* must be equivalent to array index! */
		.sensor_ext_trig = 1,
		.sensor_depth    = 10,
		.width           = 720,
		.height          = 1080,
		.max_fps         = 120,
		.reg_list        = imx297_init_tab_720_540_120fps,
	},
};

static const struct imx_trait  imx_trait_296s = {
		.exposure_min         = 29,
		.exposure_max         = 15110711,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 480,
		.gain_digital_default = 200,
		.sensor_mode_max      = IMX296_S_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_296s,
		.start                = start_296_297,
		.stop                 = stop_296_297,
};

#define IMX296_R_SENSOR_MODE_MAX (2)
static const struct imx_mode supported_modes_296r[IMX296_R_SENSOR_MODE_MAX] = {
	{
		.sensor_mode     = 0, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = (1440*3),
		.height          = 1080,
		.max_fps         = 60,
		.reg_list        = imx296_init_tab_1440_1080_60fps,
	},
	{
		.sensor_mode     = 1, /* must be equivalent to array index! */
		.sensor_ext_trig = 1,
		.sensor_depth    = 10,
		.width           = (1440*3),
		.height          = 1080,
		.max_fps         = 60,
		.reg_list        = imx296_init_tab_1440_1080_60fps,
	},
};

static const struct imx_trait  imx_trait_296r = {
		.exposure_min         = 29,
		.exposure_max         = 15110711,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 480,
		.gain_digital_default = 200,
		.sensor_mode_max      = IMX296_R_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_296r,
		.start                = start_296_297,
		.stop                 = stop_296_297,
};

#define IMX297_SENSOR_MODE_MAX (4)
static const struct imx_mode supported_modes_297[IMX297_SENSOR_MODE_MAX] = {
	{
                .sensor_mode     = 0, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = 720,
                .height          = 540,
                .max_fps         = 120,
                .reg_list        = imx297_init_tab_720_540_120fps,
	},
	{
                .sensor_mode     = 1, /* must be equivalent to array index! */
                .sensor_ext_trig = 1,
                .sensor_depth    = 10,
                .width           = 720,
                .height          = 540,
                .max_fps         = 120,
                .reg_list        = imx297_init_tab_720_540_120fps,
	},
	{
                .sensor_mode     = 2, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = 720,
                .height          = 540,
                .max_fps         = 120,
                .reg_list        = imx297_init_tab_720_540_120fps,
	},
	{
                .sensor_mode     = 3, /* must be equivalent to array index! */
                .sensor_ext_trig = 1,
                .sensor_depth    = 10,
                .width           = 720,
                .height          = 540,
                .max_fps         = 120,
                .reg_list        = imx297_init_tab_720_540_120fps,
	},
};

static const struct imx_trait  imx_trait_297 = {
		.exposure_min         = 29,
		.exposure_max         = 15110711,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 480,
		.gain_digital_default = 200,
		.sensor_mode_max      = IMX297_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_297,
		.start                = start_296_297,
		.stop                 = stop_296_297,
};



#define IMX327_SENSOR_MODE_MAX (2)
static const struct imx_mode supported_modes_327[IMX327_SENSOR_MODE_MAX] = {
	{
                .sensor_mode     = 0, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = 1920,
                .height          = 1080,
                .max_fps         = 60,
                .reg_list        = imx327_init_tab_1920_1080_60fps,
	},
	{
		.sensor_mode     = 1, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 1920,
		.height          = 1080,
		.max_fps         = 120,
                .reg_list        = imx327_init_tab_1920_1080_120fps,
	},
};

static const struct imx_trait  imx_trait_327 = {
		.exposure_min         = 29,
		.exposure_max         = 7602176,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 240,
		.gain_digital_default = 0,
		.sensor_mode_max      = IMX327_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_327,
		.start                = start_290_327,
		.stop                 = stop_290_327,
};

#define IMX462_SENSOR_MODE_MAX (2)
static const struct imx_mode supported_modes_462[IMX462_SENSOR_MODE_MAX] = {
	{
                .sensor_mode     = 0, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = 1920,
                .height          = 1080,
                .max_fps         = 60,
                .reg_list        = imx327_init_tab_1920_1080_60fps,
	},
	{
		.sensor_mode     = 1, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 1920,
		.height          = 1080,
		.max_fps         = 120,
                .reg_list        = imx327_init_tab_1920_1080_120fps,
	},
};

static const struct imx_trait  imx_trait_462 = {
		.exposure_min         = 29,
		.exposure_max         = 7602176,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 240,
		.gain_digital_default = 0,
		.sensor_mode_max      = IMX462_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_462,
		.start                = start_290_327,
		.stop                 = stop_290_327,
};

#define IMX335_SENSOR_MODE_MAX (16)
static const struct imx_mode supported_modes_335[IMX335_SENSOR_MODE_MAX] = {
	{
                .sensor_mode     = 0, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = 2560,
                .height          = 1964,
                .max_fps         = 60,
                .reg_list        = imx335_init_tab_2560_1964_60fps,
	},
	{
		.sensor_mode     = 1, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 2560,
		.height          = 1964,
		.max_fps         = 120,
                .reg_list        = imx335_init_tab_2560_1964_120fps,
	},
	{
                .sensor_mode     = 2, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 12,
                .width           = 2560,
                .height          = 1964,
                .max_fps         = 60,
                .reg_list        = imx335_init_tab_2560_1964_60fps,
	},
	{
		.sensor_mode     = 3, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 12,
		.width           = 2560,
		.height          = 1964,
		.max_fps         = 120,
                .reg_list        = imx335_init_tab_2560_1964_120fps,
	},
	{
                .sensor_mode     = 4, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = 2560,
                .height          = 1964,
                .max_fps         = 120,
                .reg_list        = imx335_init_tab_2560_1964_60fps,
	},
	{
		.sensor_mode     = 5, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 10,
		.width           = 2560,
		.height          = 1964,
		.max_fps         = 240,
                .reg_list        = imx335_init_tab_2560_1964_120fps,
	},
	{
                .sensor_mode     = 6, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 12,
                .width           = 2560,
                .height          = 1964,
                .max_fps         = 120,
                .reg_list        = imx335_init_tab_2560_1964_60fps,
	},
	{
		.sensor_mode     = 7, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 12,
		.width           = 2560,
		.height          = 1964,
		.max_fps         = 240,
                .reg_list        = imx335_init_tab_2560_1964_120fps,
	},
	{
                .sensor_mode     = 8, /* must be equivalent to array index! */
                .sensor_ext_trig = 3,
                .sensor_depth    = 10,
                .width           = 2560,
                .height          = 1964,
                .max_fps         = 60,
                .reg_list        = imx335_init_tab_2560_1964_60fps,
	},
	{
		.sensor_mode     = 9, /* must be equivalent to array index! */
		.sensor_ext_trig = 3,
		.sensor_depth    = 10,
		.width           = 2560,
		.height          = 1964,
		.max_fps         = 120,
                .reg_list        = imx335_init_tab_2560_1964_120fps,
	},
	{
                .sensor_mode     = 10, /* must be equivalent to array index! */
                .sensor_ext_trig = 3,
                .sensor_depth    = 12,
                .width           = 2560,
                .height          = 1964,
                .max_fps         = 60,
                .reg_list        = imx335_init_tab_2560_1964_60fps,
	},
	{
		.sensor_mode     = 11, /* must be equivalent to array index! */
		.sensor_ext_trig = 3,
		.sensor_depth    = 12,
		.width           = 2560,
		.height          = 1964,
		.max_fps         = 120,
                .reg_list        = imx335_init_tab_2560_1964_120fps,
	},
	{
                .sensor_mode     = 12, /* must be equivalent to array index! */
                .sensor_ext_trig = 3,
                .sensor_depth    = 10,
                .width           = 2560,
                .height          = 1964,
                .max_fps         = 120,
                .reg_list        = imx335_init_tab_2560_1964_60fps,
	},
	{
		.sensor_mode     = 13, /* must be equivalent to array index! */
		.sensor_ext_trig = 3,
		.sensor_depth    = 10,
		.width           = 2560,
		.height          = 1964,
		.max_fps         = 240,
                .reg_list        = imx335_init_tab_2560_1964_120fps,
	},
	{
                .sensor_mode     = 14, /* must be equivalent to array index! */
                .sensor_ext_trig = 3,
                .sensor_depth    = 12,
                .width           = 2560,
                .height          = 1964,
                .max_fps         = 120,
                .reg_list        = imx335_init_tab_2560_1964_60fps,
	},
	{
		.sensor_mode     = 15, /* must be equivalent to array index! */
		.sensor_ext_trig = 3,
		.sensor_depth    = 12,
		.width           = 2560,
		.height          = 1964,
		.max_fps         = 240,
                .reg_list        = imx335_init_tab_2560_1964_120fps,
	},
};

static const struct imx_trait  imx_trait_335 = {
		.exposure_min         = 29,
		.exposure_max         = 7602176,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 240,
		.gain_digital_default = 0,
		.sensor_mode_max      = IMX335_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_335,
		.start                = start_290_327,
		.stop                 = stop_290_327,
};


#define IMX412_SENSOR_MODE_MAX (4)
static const struct imx_mode supported_modes_412[IMX412_SENSOR_MODE_MAX] = {
	{
                .sensor_mode     = 0, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = (4056-8),
                .height          = 3040,
                .max_fps         = 20,
                .reg_list        = imx412_init_tab,
	},
	{
                .sensor_mode     = 1, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = (4056-8),
                .height          = 3040,
                .max_fps         = 40,
                .reg_list        = imx412_init_tab,
	},
	{
                .sensor_mode     = 2, /* must be equivalent to array index! */
                .sensor_ext_trig = 1,
                .sensor_depth    = 10,
                .width           = (4056-8),
                .height          = 3040,
                .max_fps         = 20,
                .reg_list        = imx412_init_tab,
	},
	{
                .sensor_mode     = 3, /* must be equivalent to array index! */
                .sensor_ext_trig = 1,
                .sensor_depth    = 10,
                .width           = (4056-8),
                .height          = 3040,
                .max_fps         = 40,
                .reg_list        = imx412_init_tab,
	},
};

static const struct imx_trait  imx_trait_412 = {
		.exposure_min         = 22,
		.exposure_max         = 92693,
		.exposure_default     = 10000,
		.gain_digital_min     = 0x100,
		.gain_digital_max     = 0xFFF,
		.gain_digital_default = 0x100,
		.sensor_mode_max      = IMX412_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_412,
		.start                = start_412,
		.stop                 = stop_412,
};

#define IMX415_SENSOR_MODE_MAX (2)
static const struct imx_mode supported_modes_415[IMX415_SENSOR_MODE_MAX] = {
	{
                .sensor_mode     = 0, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = 3840,
                .height          = 2192,
                .max_fps         = 32,
                .reg_list        = imx415_init_tab,
	},
	{
                .sensor_mode     = 1, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = 3840,
                .height          = 2192,
                .max_fps         = 60,
                .reg_list        = imx415_init_tab,
	},
};

static const struct imx_trait  imx_trait_415 = {
		.exposure_min         = 32,
		.exposure_max         = 2097152,
		.exposure_default     = 10000,
		.gain_digital_min     = 0x000,
		.gain_digital_max     = 0x0F0,
		.gain_digital_default = 0x000,
		.sensor_mode_max      = IMX415_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_415,
		.start                = start_415,
		.stop                 = stop_415,
};

#define IMX585_SENSOR_MODE_MAX (2)
static const struct imx_mode supported_modes_585[IMX585_SENSOR_MODE_MAX] = {
	{
                .sensor_mode     = 0, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = 3856,
                .height          = 2180,
                .max_fps         = 32,
                .reg_list        = imx415_init_tab,
	},
	{
                .sensor_mode     = 1, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 10,
                .width           = 3856,
                .height          = 2180,
                .max_fps         = 60,
                .reg_list        = imx415_init_tab,
	},
};

static const struct imx_trait  imx_trait_585 = {
		.exposure_min         = 32,
		.exposure_max         = 2097152,
		.exposure_default     = 10000,
		.gain_digital_min     = 0x000,
		.gain_digital_max     = 0x0F0,
		.gain_digital_default = 0x000,
		.sensor_mode_max      = IMX585_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_585,
		.start                = start_415,
		.stop                 = stop_415,
};

#define OV7251_SENSOR_MODE_MAX (4)
static const struct imx_mode supported_modes_7251[OV7251_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 640,
		.height = 480,
		.max_fps = 100,
		.reg_list = ov7251_init_tab_640_480_100fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 640,
		.height = 480,
		.max_fps = 100,
		.reg_list = ov7251_init_tab_640_480_100fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 640,
		.height = 480,
		.max_fps = 100,
		.reg_list = ov7251_init_tab_640_480_100fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 640,
		.height = 480,
		.max_fps = 100,
		.reg_list = ov7251_init_tab_640_480_100fps,
	},
};

static const struct imx_trait  imx_trait_7251 = {
		.exposure_min         = 9,
		.exposure_max         = 7965,
		.exposure_default     = 1000,
		.gain_digital_min     = 0x00,
		.gain_digital_max     = 0xFE,
		.gain_digital_default = 0x10,
		.sensor_mode_max      = OV7251_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_7251,
		.start                = start_ov7251,
		.stop                 = stop_ov7251,
};

#define OV9281_SENSOR_MODE_MAX (4)
static const struct imx_mode supported_modes_9281[OV9281_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 1280,
		.height = 800,
		.max_fps = 120,
		.reg_list = ov9281_init_tab_1280_800_120fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 1280,
		.height = 800,
		.max_fps = 120,
		.reg_list = ov9281_init_tab_1280_800_120fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 1280,
		.height = 800,
		.max_fps = 120,
		.reg_list = ov9281_init_tab_1280_800_120fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 1280,
		.height = 800,
		.max_fps = 120,
		.reg_list = ov9281_init_tab_1280_800_120fps,
	},
};

static const struct imx_trait  imx_trait_9281 = {
		.exposure_min         = 9,
		.exposure_max         = 7962,
		.exposure_default     = 1001,
		.gain_digital_min     = 0x00,
		.gain_digital_max     = 0xFE,
		.gain_digital_default = 0x10,
		.sensor_mode_max      = OV9281_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_9281,
		.start                = start_ov9281,
		.stop                 = stop_ov9281,
};

#define IMX178_SENSOR_MODE_MAX (16)
static const struct imx_mode supported_modes_178[IMX178_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 3104,
		.height = 2076,
		.max_fps = 60,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 3104,
		.height = 2076,
		.max_fps = 60,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 3104,
		.height = 2076,
		.max_fps = 50,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 0,
		.sensor_depth = 14,
		.width = 3104,
		.height = 2076,
		.max_fps = 30,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 3104,
		.height = 2076,
		.max_fps = 60,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 3104,
		.height = 2076,
		.max_fps = 60,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 6,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 3104,
		.height = 2076,
		.max_fps = 50,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 7,
		.sensor_ext_trig = 1,
		.sensor_depth = 14,
		.width = 3104,
		.height = 2076,
		.max_fps = 30,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 8,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 3104,
		.height = 2076,
		.max_fps = 60,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 9,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 3104,
		.height = 2076,
		.max_fps = 60,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 10,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 3104,
		.height = 2076,
		.max_fps = 50,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 11,
		.sensor_ext_trig = 0,
		.sensor_depth = 14,
		.width = 3104,
		.height = 2076,
		.max_fps = 30,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 12,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 3104,
		.height = 2076,
		.max_fps = 60,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 13,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 3104,
		.height = 2076,
		.max_fps = 60,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 14,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 3104,
		.height = 2076,
		.max_fps = 50,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
	{
		.sensor_mode = 15,
		.sensor_ext_trig = 1,
		.sensor_depth = 14,
		.width = 3104,
		.height = 2076,
		.max_fps = 30,
		.reg_list = imx178_init_tab_3104_2076_120fps,
	},
};

static const struct imx_trait  imx_trait_178 = {
		.exposure_min         = 56,
		.exposure_max         = 10000000,
		.exposure_default     = 10000,
		.gain_digital_min     = 0x00,
		.gain_digital_max     = 0x1E0,
		.gain_digital_default = 0x10,
		.sensor_mode_max      = IMX178_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_178,
		.start                = start_imx178,
		.stop                 = stop_imx178,
};

#define IMX183_SENSOR_MODE_MAX (12)
static const struct imx_mode supported_modes_183[IMX183_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
	{
		.sensor_mode = 6,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
	{
		.sensor_mode = 7,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
	{
		.sensor_mode = 8,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
	{
		.sensor_mode = 9,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
	{
		.sensor_mode = 10,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
	{
		.sensor_mode = 11,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 5440,
		.height = 3648,
		.max_fps = 13,
		.reg_list = imx183_init_tab_5440_3648_120fps,
	},
};

static const struct imx_trait  imx_trait_183 = {
		.exposure_min         = 20,
		.exposure_max         = 10000000,
		.exposure_default     = 10000,
		.gain_digital_min     = 0x00,
		.gain_digital_max     = 0x7A5,
		.gain_digital_default = 0x10,
		.sensor_mode_max      = IMX183_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_183,
		.start                = start_imx183,
		.stop                 = stop_imx183,
};
 

#ifdef PLATFORM_QCOM
#define IMX273_SENSOR_MODE_MAX (4)
static const struct imx_mode supported_modes_273[IMX273_SENSOR_MODE_MAX] = {
	{
		.sensor_mode     = 0, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 8,
		.width           = 1440,
		.height          = 1080,
		.max_fps         = 257,
		.reg_list        = imx273_init_tab_1440_1080_60fps,
	},
	{
		.sensor_mode     = 1, /* must be equivalent to array index! */
		.sensor_ext_trig = 1,
		.sensor_depth    = 8,
		.width           = 1440,
		.height          = 1080,
		.max_fps         = 257,
		.reg_list        = imx273_init_tab_1440_1080_60fps,
	},
	{
		.sensor_mode     = 2, /* must be equivalent to array index! */
		.sensor_ext_trig = 0,
		.sensor_depth    = 8,
		.width           = 720,
		.height          = 540,
		.max_fps         = 514,
		.reg_list        = imx297_init_tab_720_540_120fps,
	},
	{
		.sensor_mode     = 3, /* must be equivalent to array index! */
		.sensor_ext_trig = 1,
		.sensor_depth    = 8,
		.width           = 720,
		.height          = 540,
		.max_fps         = 514,
		.reg_list        = imx297_init_tab_720_540_120fps,
	},
};
#else
#define IMX273_SENSOR_MODE_MAX (24)
static const struct imx_mode supported_modes_273[IMX273_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 6,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 7,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 8,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 9,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 10,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 11,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 1440,
		.height = 1080,
		.max_fps = 200,
		.reg_list = imx273_init_tab_1440_1080_200fps,
	},
	{
		.sensor_mode = 12,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 720,
		.height = 540,
		.max_fps = 500,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
	{
		.sensor_mode = 13,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 720,
		.height = 540,
		.max_fps = 400,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
	{
		.sensor_mode = 14,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 720,
		.height = 540,
		.max_fps = 300,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
	{
		.sensor_mode = 15,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 720,
		.height = 540,
		.max_fps = 500,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
	{
		.sensor_mode = 16,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 720,
		.height = 540,
		.max_fps = 400,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
	{
		.sensor_mode = 17,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 720,
		.height = 540,
		.max_fps = 300,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
	{
		.sensor_mode = 18,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 720,
		.height = 540,
		.max_fps = 500,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
	{
		.sensor_mode = 19,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 720,
		.height = 540,
		.max_fps = 400,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
	{
		.sensor_mode = 20,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 720,
		.height = 540,
		.max_fps = 300,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
	{
		.sensor_mode = 21,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 720,
		.height = 540,
		.max_fps = 500,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
	{
		.sensor_mode = 22,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 720,
		.height = 540,
		.max_fps = 400,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
	{
		.sensor_mode = 23,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 720,
		.height = 540,
		.max_fps = 300,
		.reg_list = imx273_init_tab_720_540_200fps,
	},
};
#endif
static const struct imx_trait  imx_trait_273 = {
		.exposure_min         = 29,
		.exposure_max         = 15110711,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 480,
		.gain_digital_default = 200,
		.sensor_mode_max      = IMX273_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_273,
		.start                = start_273,
		.stop                 = stop_273,
};

#define IMX226_SENSOR_MODE_MAX (12)
static const struct imx_mode supported_modes_226[IMX226_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
	{
		.sensor_mode = 6,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
	{
		.sensor_mode = 7,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
	{
		.sensor_mode = 8,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
	{
		.sensor_mode = 9,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
	{
		.sensor_mode = 10,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
	{
		.sensor_mode = 11,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 3840,
		.height = 3048,
		.max_fps = 20,
		.reg_list = imx226_init_tab_3840_3048_20fps,
	},
};

static const struct imx_trait  imx_trait_226 = {
		.exposure_min         = 20,
		.exposure_max         = 10000000,
		.exposure_default     = 10000,
		.gain_digital_min     = 0x00,
		.gain_digital_max     = 0x7A5,
		.gain_digital_default = 0x10,
		.sensor_mode_max      = IMX226_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_226,
		.start                = start_imx226,
		.stop                 = stop_imx226,
};

#define IMX252_SENSOR_MODE_MAX (12)
static const struct imx_mode supported_modes_252[IMX252_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 6,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 7,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 8,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 9,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 10,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 11,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx252_init_tab_2048_1536_20fps,
	},
};

static const struct imx_trait  imx_trait_252 = {
		.exposure_min         = 20,
		.exposure_max         = 10000000,
		.exposure_default     = 10000,
		.gain_digital_min     = 0x00,
		.gain_digital_max     = 0x7A5,
		.gain_digital_default = 0x10,
		.sensor_mode_max      = IMX252_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_252,
		.start                = start_imx252,
		.stop                 = stop_imx252,
};

#define IMX250_SENSOR_MODE_MAX (12)
static const struct imx_mode supported_modes_250[IMX250_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
	{
		.sensor_mode = 6,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
	{
		.sensor_mode = 7,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
	{
		.sensor_mode = 8,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
	{
		.sensor_mode = 9,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
	{
		.sensor_mode = 10,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
	{
		.sensor_mode = 11,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 2432,
		.height = 2048,
		.max_fps = 65,
		.reg_list = imx250_init_tab_2432_2048_65fps,
	},
};

static const struct imx_trait  imx_trait_250 = {
		.exposure_min         = 70,
		.exposure_max         = 10000000,
		.exposure_default     = 10000,
		.gain_digital_min     = 0x00,
		.gain_digital_max     = 0x7A5,
		.gain_digital_default = 0x10,
		.sensor_mode_max      = IMX250_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_250,
		.start                = start_imx250,
		.stop                 = stop_imx250,
};

#define IMX264_SENSOR_MODE_MAX (6)
static const struct imx_mode supported_modes_264[IMX264_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 2432,
		.height = 2048,
		.max_fps = 35,
		.reg_list = imx264_init_tab_2432_2048_35fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 2432,
		.height = 2048,
		.max_fps = 35,
		.reg_list = imx264_init_tab_2432_2048_35fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 2432,
		.height = 2048,
		.max_fps = 35,
		.reg_list = imx264_init_tab_2432_2048_35fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 2432,
		.height = 2048,
		.max_fps = 35,
		.reg_list = imx264_init_tab_2432_2048_35fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 2432,
		.height = 2048,
		.max_fps = 35,
		.reg_list = imx264_init_tab_2432_2048_35fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 2432,
		.height = 2048,
		.max_fps = 35,
		.reg_list = imx264_init_tab_2432_2048_35fps,
	},
};

static const struct imx_trait  imx_trait_264 = {
		.exposure_min         = 20,
		.exposure_max         = 10000000,
		.exposure_default     = 10000,
		.gain_digital_min     = 0x00,
		.gain_digital_max     = 0x7A5,
		.gain_digital_default = 0x10,
		.sensor_mode_max      = IMX264_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_264,
		.start                = start_imx264,
		.stop                 = stop_imx264,
};

#define IMX265_SENSOR_MODE_MAX (6)
static const struct imx_mode supported_modes_265[IMX265_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx265_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx265_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx265_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx265_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx265_init_tab_2048_1536_20fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 2048,
		.height = 1536,
		.max_fps = 20,
		.reg_list = imx265_init_tab_2048_1536_20fps,
	},
};

static const struct imx_trait  imx_trait_265 = {
		.exposure_min         = 20,
		.exposure_max         = 10000000,
		.exposure_default     = 10000,
		.gain_digital_min     = 0x00,
		.gain_digital_max     = 0x7A5,
		.gain_digital_default = 0x10,
		.sensor_mode_max      = IMX265_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_265,
		.start                = start_imx252,
		.stop                 = stop_imx252,
};

#define IMX392_SENSOR_MODE_MAX (12)
static const struct imx_mode supported_modes_392[IMX392_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
	{
		.sensor_mode = 6,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
	{
		.sensor_mode = 7,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
	{
		.sensor_mode = 8,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
	{
		.sensor_mode = 9,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
	{
		.sensor_mode = 10,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
	{
		.sensor_mode = 11,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 1920,
		.height = 1200,
		.max_fps = 20,
		.reg_list = imx392_init_tab_1920_1200_20fps,
	},
};

static const struct imx_trait  imx_trait_392 = {
		.exposure_min         = 20,
		.exposure_max         = 10000000,
		.exposure_default     = 10000,
		.gain_digital_min     = 0x00,
		.gain_digital_max     = 0x7A5,
		.gain_digital_default = 0x10,
		.sensor_mode_max      = IMX392_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_392,
		.start                = start_imx392,
		.stop                 = stop_imx392,
};


#define IMX568_SENSOR_MODE_MAX (12)
static const struct imx_mode supported_modes_568[IMX568_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 50,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 50,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 50,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 50,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 50,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 50,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 6,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 100,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 7,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 100,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 8,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 100,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 9,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 100,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 10,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 100,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 11,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = (2448-16),
		.height = 2048,
		.max_fps = 100,
		.reg_list = imx568_init_tab_2448_2048_79fps,
	},
};

static const struct imx_trait  imx_trait_568 = {
		.exposure_min         = 15,
		.exposure_max         = 15110711,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 480,
		.gain_digital_default = 200,
		.sensor_mode_max      = IMX568_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_568,
		.start                = start_568,
		.stop                 = stop_568,
};

#define IMX565_SENSOR_MODE_MAX (12)
static const struct imx_mode supported_modes_565[IMX565_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = (4128),
		.height = 3008,
		.max_fps = 50,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = (4128),
		.height = 3008,
		.max_fps = 50,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = (4128),
		.height = 3008,
		.max_fps = 50,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = (4128),
		.height = 3008,
		.max_fps = 50,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = (4128),
		.height = 3008,
		.max_fps = 50,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = (4128),
		.height = 3008,
		.max_fps = 50,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
	{
		.sensor_mode = 6,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = (4128),
		.height = 3008,
		.max_fps = 100,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
	{
		.sensor_mode = 7,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = (4128),
		.height = 3008,
		.max_fps = 100,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
	{
		.sensor_mode = 8,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = (4128),
		.height = 3008,
		.max_fps = 100,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
	{
		.sensor_mode = 9,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = (4128),
		.height = 3008,
		.max_fps = 100,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
	{
		.sensor_mode = 10,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = (4128),
		.height = 3008,
		.max_fps = 100,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
	{
		.sensor_mode = 11,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = (4128),
		.height = 3008,
		.max_fps = 100,
		.reg_list = imx565_init_tab_4128_3008_79fps,
	},
};

static const struct imx_trait  imx_trait_565 = {
		.exposure_min         = 15,
		.exposure_max         = 15110711,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 480,
		.gain_digital_default = 200,
		.sensor_mode_max      = IMX565_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_565,
		.start                = start_568, // same as 568
		.stop                 = stop_568,  // same as 568
};

#define IMX566_SENSOR_MODE_MAX (12)
static const struct imx_mode supported_modes_566[IMX566_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = (2848),
		.height = 2840,
		.max_fps = 50,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = (2848),
		.height = 2840,
		.max_fps = 50,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = (2848),
		.height = 2840,
		.max_fps = 50,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = (2848),
		.height = 2840,
		.max_fps = 50,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = (2848),
		.height = 2840,
		.max_fps = 50,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = (2848),
		.height = 2840,
		.max_fps = 50,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
	{
		.sensor_mode = 6,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = (2848),
		.height = 2840,
		.max_fps = 100,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
	{
		.sensor_mode = 7,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = (2848),
		.height = 2840,
		.max_fps = 100,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
	{
		.sensor_mode = 8,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = (2848),
		.height = 2840,
		.max_fps = 100,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
	{
		.sensor_mode = 9,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = (2848),
		.height = 2840,
		.max_fps = 100,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
	{
		.sensor_mode = 10,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = (2848),
		.height = 2840,
		.max_fps = 100,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
	{
		.sensor_mode = 11,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = (2848),
		.height = 2840,
		.max_fps = 100,
		.reg_list = imx566_init_tab_2848_2840_79fps,
	},
};

static const struct imx_trait  imx_trait_566 = {
		.exposure_min         = 15,
		.exposure_max         = 15110711,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 480,
		.gain_digital_default = 200,
		.sensor_mode_max      = IMX566_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_566,
		.start                = start_568, // same as 568
		.stop                 = stop_568,  // same as 568
};

#define IMX900_SENSOR_MODE_MAX (12)
static const struct imx_mode supported_modes_900[IMX900_SENSOR_MODE_MAX] = {
	{
		.sensor_mode = 0,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 2048,
		.height = 1536,
		.max_fps = 50,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 1,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 2048,
		.height = 1536,
		.max_fps = 50,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 2,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 2048,
		.height = 1536,
		.max_fps = 50,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 3,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 2048,
		.height = 1536,
		.max_fps = 50,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 4,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 2048,
		.height = 1536,
		.max_fps = 50,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 5,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 2048,
		.height = 1536,
		.max_fps = 50,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 6,
		.sensor_ext_trig = 0,
		.sensor_depth = 8,
		.width = 2048,
		.height = 1536,
		.max_fps = 100,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 7,
		.sensor_ext_trig = 0,
		.sensor_depth = 10,
		.width = 2048,
		.height = 1536,
		.max_fps = 100,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 8,
		.sensor_ext_trig = 0,
		.sensor_depth = 12,
		.width = 2048,
		.height = 1536,
		.max_fps = 100,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 9,
		.sensor_ext_trig = 1,
		.sensor_depth = 8,
		.width = 2048,
		.height = 1536,
		.max_fps = 100,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 10,
		.sensor_ext_trig = 1,
		.sensor_depth = 10,
		.width = 2048,
		.height = 1536,
		.max_fps = 100,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
	{
		.sensor_mode = 11,
		.sensor_ext_trig = 1,
		.sensor_depth = 12,
		.width = 2048,
		.height = 1536,
		.max_fps = 100,
		.reg_list = imx900_init_tab_2448_2048_79fps,
	},
};

static const struct imx_trait  imx_trait_900 = {
		.exposure_min         = 15,
		.exposure_max         = 15110711,
		.exposure_default     = 10000,
		.gain_digital_min     = 0,
		.gain_digital_max     = 480,
		.gain_digital_default = 200,
		.sensor_mode_max      = IMX900_SENSOR_MODE_MAX,
		.supported_modes      = supported_modes_900,
		.start                = start_568,
		.stop                 = stop_568,
};

static const struct vc_mipi_sen_reg start_unknown[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

static const struct vc_mipi_sen_reg stop_unknown[] = {
	{VC_MIPI_REG_TABLE_END, 0x00}
};

#define UNKNOWN_SENSOR_MODE_MAX (1)
static const struct imx_mode supported_modes_unknown[UNKNOWN_SENSOR_MODE_MAX] = {
	{
                .sensor_mode     = 0, /* must be equivalent to array index! */
                .sensor_ext_trig = 0,
                .sensor_depth    = 0,
                .width           = 0,
                .height          = 0,
                .max_fps         = 0,
                .reg_list        = NULL,
	},
};
static const struct imx_trait  imx_trait_unknown = {
		.exposure_min         = 0,
		.exposure_max         = 0,
		.exposure_default     = 0,
		.gain_digital_min     = 0,
		.gain_digital_max     = 0,
		.gain_digital_default = 0,
		.sensor_mode_max      = 0,
		.supported_modes      = supported_modes_unknown,
		.start                = start_unknown,
		.stop                 = stop_unknown,
};




enum imx_model {
	IMX290_MODEL_MONOCHROME,
	IMX290_MODEL_COLOR,
	IMX296_MODEL_MONOCHROME,
	IMX296_MODEL_COLOR,
	IMX297_MODEL_MONOCHROME,
	IMX297_MODEL_COLOR,
	IMX327_MODEL_MONOCHROME,
	IMX327_MODEL_COLOR,
	IMX412_MODEL_MONOCHROME,
	IMX412_MODEL_COLOR,
	OV9281_MODEL_MONOCHROME,
	OV9281_MODEL_COLOR,
	IMX183_MODEL_MONOCHROME,
	IMX183_MODEL_COLOR,
	IMX273_MODEL_MONOCHROME,
	IMX273_MODEL_COLOR,
	IMX226_MODEL_MONOCHROME,
	IMX226_MODEL_COLOR,
	IMX415_MODEL_MONOCHROME,
	IMX415_MODEL_COLOR,
	IMX252_MODEL_MONOCHROME,
	IMX252_MODEL_COLOR,
	OV7251_MODEL_MONOCHROME,
	OV7251_MODEL_COLOR,
	IMX250_MODEL_MONOCHROME,
	IMX250_MODEL_COLOR,
	IMX392_MODEL_MONOCHROME,
	IMX392_MODEL_COLOR,
	IMX178_MODEL_MONOCHROME,
	IMX178_MODEL_COLOR,
	IMX264_MODEL_MONOCHROME,
	IMX264_MODEL_COLOR,
	IMX335_MODEL_MONOCHROME,
	IMX335_MODEL_COLOR,
	IMX265_MODEL_MONOCHROME,
	IMX265_MODEL_COLOR,
	IMX462_MODEL_MONOCHROME,
	IMX462_MODEL_COLOR,
	IMX568_MODEL_MONOCHROME,
	IMX568_MODEL_COLOR,
	IMX565_MODEL_MONOCHROME,
	IMX565_MODEL_COLOR,
	IMX566_MODEL_MONOCHROME,
	IMX566_MODEL_COLOR,
	IMX296_MODEL_MONOCHROME_S,
	IMX296_MODEL_COLOR_S,
	IMX296_MODEL_COLOR_R,
	IMX900_MODEL_MONOCHROME,
	IMX900_MODEL_COLOR,
	IMX585_MODEL_MONOCHROME,
	IMX585_MODEL_COLOR,
	IMX_MODEL_UNKNOWN,
};

#define  str_imx_model(model) \
             (IMX290_MODEL_MONOCHROME == (model))?("IMX290, monochrome")\
            :(IMX290_MODEL_COLOR      == (model))?("IMX290, color     ")\
            :(IMX296_MODEL_MONOCHROME == (model))?("IMX296, monochrome")\
            :(IMX296_MODEL_COLOR      == (model))?("IMX296, color     ")\
            :(IMX297_MODEL_MONOCHROME == (model))?("IMX297, monochrome")\
            :(IMX297_MODEL_COLOR      == (model))?("IMX297, color     ")\
            :(IMX327_MODEL_MONOCHROME == (model))?("IMX327, monochrome")\
            :(IMX327_MODEL_COLOR      == (model))?("IMX327, color     ")\
            :(IMX412_MODEL_MONOCHROME == (model))?("IMX412, monochrome")\
            :(IMX412_MODEL_COLOR      == (model))?("IMX412, color     ")\
            :(OV9281_MODEL_MONOCHROME == (model))?("OV9281, monochrome")\
            :(OV9281_MODEL_COLOR      == (model))?("OV9281, color     ")\
            :(IMX183_MODEL_MONOCHROME == (model))?("IMX183, monochrome")\
            :(IMX183_MODEL_COLOR      == (model))?("IMX183, color     ")\
            :(IMX273_MODEL_MONOCHROME == (model))?("IMX273, monochrome")\
            :(IMX273_MODEL_COLOR      == (model))?("IMX273, color     ")\
            :(IMX226_MODEL_MONOCHROME == (model))?("IMX226, monochrome")\
            :(IMX226_MODEL_COLOR      == (model))?("IMX226, color     ")\
            :(IMX415_MODEL_MONOCHROME == (model))?("IMX415, monochrome")\
            :(IMX415_MODEL_COLOR      == (model))?("IMX415, color     ")\
            :(IMX252_MODEL_MONOCHROME == (model))?("IMX252, monochrome")\
            :(IMX252_MODEL_COLOR      == (model))?("IMX252, color     ")\
            :(OV7251_MODEL_MONOCHROME == (model))?("OV7251, monochrome")\
            :(OV7251_MODEL_COLOR      == (model))?("OV7251, color     ")\
            :(IMX250_MODEL_MONOCHROME == (model))?("IMX250, monochrome")\
            :(IMX250_MODEL_COLOR      == (model))?("IMX250, color     ")\
            :(IMX392_MODEL_MONOCHROME == (model))?("IMX392, monochrome")\
            :(IMX392_MODEL_COLOR      == (model))?("IMX392, color     ")\
            :(IMX178_MODEL_MONOCHROME == (model))?("IMX178, monochrome")\
            :(IMX178_MODEL_COLOR      == (model))?("IMX178, color     ")\
            :(IMX264_MODEL_MONOCHROME == (model))?("IMX264, monochrome")\
            :(IMX264_MODEL_COLOR      == (model))?("IMX264, color     ")\
            :(IMX335_MODEL_MONOCHROME == (model))?("IMX335, monochrome")\
            :(IMX335_MODEL_COLOR      == (model))?("IMX335, color     ")\
            :(IMX265_MODEL_MONOCHROME == (model))?("IMX265, monochrome")\
            :(IMX265_MODEL_COLOR      == (model))?("IMX265, color     ")\
            :(IMX462_MODEL_MONOCHROME == (model))?("IMX462, monochrome")\
            :(IMX462_MODEL_COLOR      == (model))?("IMX462, color     ")\
            :(IMX568_MODEL_MONOCHROME == (model))?("IMX568, monochrome")\
            :(IMX568_MODEL_COLOR      == (model))?("IMX568, color     ")\
            :(IMX565_MODEL_MONOCHROME == (model))?("IMX565, monochrome")\
            :(IMX565_MODEL_COLOR      == (model))?("IMX565, color     ")\
            :(IMX566_MODEL_MONOCHROME == (model))?("IMX566, monochrome")\
            :(IMX566_MODEL_COLOR      == (model))?("IMX566, color     ")\
            :(IMX296_MODEL_MONOCHROME_S == (model))?("IMX296, monochrome stereo")\
            :(IMX296_MODEL_COLOR_S      == (model))?("IMX296, color stereo     ")\
            :(IMX296_MODEL_COLOR_R      == (model))?("IMX296, color R ")\
            :(IMX900_MODEL_MONOCHROME == (model))?("IMX900, monochrome")\
            :(IMX900_MODEL_COLOR      == (model))?("IMX900, color     ")\
            :(IMX585_MODEL_MONOCHROME == (model))?("IMX585, monochrome")\
            :(IMX585_MODEL_COLOR      == (model))?("IMX585, color     ")\
            :("UNKNOWN")


#define  imx_model_by_mod_id(mod_id, color, stereo) \
             (0x290 == (mod_id))?((color)?(IMX290_MODEL_COLOR):(IMX290_MODEL_MONOCHROME))\
            :(0x296 == (mod_id))?((stereo)?((color)?(IMX296_MODEL_COLOR_S):(IMX296_MODEL_MONOCHROME_S))\
		       :((color)?((color==2)?IMX296_MODEL_COLOR_R:IMX296_MODEL_COLOR):(IMX296_MODEL_MONOCHROME)))\
            :(0x297 == (mod_id))?((color)?(IMX297_MODEL_COLOR):(IMX297_MODEL_MONOCHROME))\
            :(0x327 == (mod_id))?((color)?(IMX327_MODEL_COLOR):(IMX327_MODEL_MONOCHROME))\
            :(0x412 == (mod_id))?((color)?(IMX412_MODEL_COLOR):(IMX412_MODEL_MONOCHROME))\
            :(0x9281 == (mod_id))?((color)?(OV9281_MODEL_COLOR):(OV9281_MODEL_MONOCHROME))\
            :(0x183 == (mod_id))?((color)?(IMX183_MODEL_COLOR):(IMX183_MODEL_MONOCHROME))\
            :(0x273 == (mod_id))?((color)?(IMX273_MODEL_COLOR):(IMX273_MODEL_MONOCHROME))\
            :(0x226 == (mod_id))?((color)?(IMX226_MODEL_COLOR):(IMX226_MODEL_MONOCHROME))\
            :(0x415 == (mod_id))?((color)?(IMX415_MODEL_COLOR):(IMX415_MODEL_MONOCHROME))\
            :(0x252 == (mod_id))?((color)?(IMX252_MODEL_COLOR):(IMX252_MODEL_MONOCHROME))\
            :(0x7251 == (mod_id))?((color)?(OV7251_MODEL_COLOR):(OV7251_MODEL_MONOCHROME))\
            :(0x250 == (mod_id))?((color)?(IMX250_MODEL_COLOR):(IMX250_MODEL_MONOCHROME))\
            :(0x392 == (mod_id))?((color)?(IMX392_MODEL_COLOR):(IMX392_MODEL_MONOCHROME))\
            :(0x178 == (mod_id))?((color)?(IMX178_MODEL_COLOR):(IMX178_MODEL_MONOCHROME))\
            :(0x264 == (mod_id))?((color)?(IMX264_MODEL_COLOR):(IMX264_MODEL_MONOCHROME))\
            :(0x335 == (mod_id))?((color)?(IMX335_MODEL_COLOR):(IMX335_MODEL_MONOCHROME))\
            :(0x265 == (mod_id))?((color)?(IMX265_MODEL_COLOR):(IMX265_MODEL_MONOCHROME))\
            :(0x462 == (mod_id))?((color)?(IMX462_MODEL_COLOR):(IMX462_MODEL_MONOCHROME))\
            :(0x568 == (mod_id))?((color)?(IMX568_MODEL_COLOR):(IMX568_MODEL_MONOCHROME))\
            :(0x567 == (mod_id))?((color)?(IMX568_MODEL_COLOR):(IMX568_MODEL_MONOCHROME))\
            :(0x565 == (mod_id))?((color)?(IMX565_MODEL_COLOR):(IMX565_MODEL_MONOCHROME))\
            :(0x566 == (mod_id))?((color)?(IMX566_MODEL_COLOR):(IMX566_MODEL_MONOCHROME))\
            :(0x900 == (mod_id))?((color)?(IMX900_MODEL_COLOR):(IMX900_MODEL_MONOCHROME))\
            :(0x585 == (mod_id))?((color)?(IMX585_MODEL_COLOR):(IMX585_MODEL_MONOCHROME))\
            :(IMX_MODEL_UNKNOWN)

#define  imx_trait_by_model(model) (\
             (IMX290_MODEL_MONOCHROME == (model))?(&imx_trait_290)\
            :(IMX290_MODEL_COLOR      == (model))?(&imx_trait_290)\
            :(IMX296_MODEL_MONOCHROME == (model))?(&imx_trait_296)\
            :(IMX296_MODEL_COLOR      == (model))?(&imx_trait_296)\
            :(IMX297_MODEL_MONOCHROME == (model))?(&imx_trait_297)\
            :(IMX297_MODEL_COLOR      == (model))?(&imx_trait_297)\
            :(IMX327_MODEL_MONOCHROME == (model))?(&imx_trait_327)\
            :(IMX327_MODEL_COLOR      == (model))?(&imx_trait_327)\
            :(IMX412_MODEL_MONOCHROME == (model))?(&imx_trait_412)\
            :(IMX412_MODEL_COLOR      == (model))?(&imx_trait_412)\
            :(OV9281_MODEL_MONOCHROME == (model))?(&imx_trait_9281)\
            :(OV9281_MODEL_COLOR      == (model))?(&imx_trait_9281)\
            :(IMX183_MODEL_MONOCHROME == (model))?(&imx_trait_183)\
            :(IMX183_MODEL_COLOR      == (model))?(&imx_trait_183)\
            :(IMX273_MODEL_MONOCHROME == (model))?(&imx_trait_273)\
            :(IMX273_MODEL_COLOR      == (model))?(&imx_trait_273)\
            :(IMX226_MODEL_MONOCHROME == (model))?(&imx_trait_226)\
            :(IMX226_MODEL_COLOR      == (model))?(&imx_trait_226)\
            :(IMX415_MODEL_MONOCHROME == (model))?(&imx_trait_415)\
            :(IMX415_MODEL_COLOR      == (model))?(&imx_trait_415)\
            :(IMX252_MODEL_MONOCHROME == (model))?(&imx_trait_252)\
            :(IMX252_MODEL_COLOR      == (model))?(&imx_trait_252)\
            :(OV7251_MODEL_MONOCHROME == (model))?(&imx_trait_7251)\
            :(OV7251_MODEL_COLOR      == (model))?(&imx_trait_7251)\
            :(IMX250_MODEL_MONOCHROME == (model))?(&imx_trait_250)\
            :(IMX250_MODEL_COLOR      == (model))?(&imx_trait_250)\
            :(IMX392_MODEL_MONOCHROME == (model))?(&imx_trait_392)\
            :(IMX392_MODEL_COLOR      == (model))?(&imx_trait_392)\
            :(IMX178_MODEL_MONOCHROME == (model))?(&imx_trait_178)\
            :(IMX178_MODEL_COLOR      == (model))?(&imx_trait_178)\
            :(IMX264_MODEL_MONOCHROME == (model))?(&imx_trait_264)\
            :(IMX264_MODEL_COLOR      == (model))?(&imx_trait_264)\
            :(IMX335_MODEL_MONOCHROME == (model))?(&imx_trait_335)\
            :(IMX335_MODEL_COLOR      == (model))?(&imx_trait_335)\
            :(IMX265_MODEL_MONOCHROME == (model))?(&imx_trait_265)\
            :(IMX265_MODEL_COLOR      == (model))?(&imx_trait_265)\
            :(IMX462_MODEL_MONOCHROME == (model))?(&imx_trait_462)\
            :(IMX462_MODEL_COLOR      == (model))?(&imx_trait_462)\
            :(IMX568_MODEL_MONOCHROME == (model))?(&imx_trait_568)\
            :(IMX568_MODEL_COLOR      == (model))?(&imx_trait_568)\
            :(IMX565_MODEL_MONOCHROME == (model))?(&imx_trait_565)\
            :(IMX565_MODEL_COLOR      == (model))?(&imx_trait_565)\
            :(IMX566_MODEL_MONOCHROME == (model))?(&imx_trait_566)\
            :(IMX566_MODEL_COLOR      == (model))?(&imx_trait_566)\
            :(IMX296_MODEL_MONOCHROME_S == (model))?(&imx_trait_296s)\
            :(IMX296_MODEL_COLOR_S    == (model))?(&imx_trait_296s)\
            :(IMX296_MODEL_COLOR_R    == (model))?(&imx_trait_296r)\
            :(IMX900_MODEL_MONOCHROME == (model))?(&imx_trait_900)\
            :(IMX900_MODEL_COLOR      == (model))?(&imx_trait_900)\
            :(IMX585_MODEL_MONOCHROME == (model))?(&imx_trait_585)\
            :(IMX585_MODEL_COLOR      == (model))?(&imx_trait_585)\
            :(&imx_trait_unknown)\
	    )

#define  mbus_pixelcode_by_model_depth8(model) (\
             (OV9281_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(OV9281_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX183_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX183_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX226_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX226_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SGBRG8_1X8)\
            :(IMX252_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX252_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(OV7251_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(OV7251_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX250_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX250_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX273_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8)\
            :(IMX273_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX392_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX392_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX178_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX178_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX264_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX264_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX265_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX265_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX462_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX462_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX568_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX568_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX565_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX565_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX566_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX566_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(IMX900_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y8_1X8    )\
            :(IMX900_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB8_1X8)\
            :(-1)\
	    )
#define  mbus_pixelcode_by_model_depth10(model) (\
             (IMX290_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX290_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX296_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX296_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX297_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX297_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX327_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX327_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX412_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX412_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(OV9281_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(OV9281_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX183_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX183_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX226_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX226_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SGBRG10_1X10)\
            :(IMX415_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX415_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SGBRG10_1X10)\
            :(IMX252_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX252_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(OV7251_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(OV7251_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX250_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX250_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX273_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10)\
            :(IMX273_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX392_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX392_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX178_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX178_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX264_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX264_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX335_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX335_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX265_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX265_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX462_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX462_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX568_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX568_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX565_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX565_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX566_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX566_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX296_MODEL_MONOCHROME_S == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX296_MODEL_COLOR_S      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX296_MODEL_COLOR_R      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX900_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX900_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(IMX585_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y10_1X10    )\
            :(IMX585_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB10_1X10)\
            :(-1)\
	    )
#define  mbus_pixelcode_by_model_depth12(model) (\
             (IMX178_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX178_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX183_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX183_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX226_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX226_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SGBRG12_1X12)\
            :(IMX252_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX252_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX250_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX250_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX273_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12)\
            :(IMX273_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX392_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX392_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX264_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX264_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX335_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX335_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX265_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX265_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX568_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX568_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX565_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX565_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX566_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX566_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(IMX900_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX900_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(-1)\
	    )
#define  mbus_pixelcode_by_model_depth14(model) (\
             (IMX178_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y14_1X14    )\
            :(IMX178_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB14_1X14)\
            :(IMX900_MODEL_MONOCHROME == (model))?(MEDIA_BUS_FMT_Y12_1X12    )\
            :(IMX900_MODEL_COLOR      == (model))?(MEDIA_BUS_FMT_SRGGB12_1X12)\
            :(-1)\
	    )


struct imx {
        struct media_pad              pad;
        //struct clk                  *clk;

        struct device                *dev;
        struct regulator             *io_regulator;
        struct regulator             *core_regulator;
        struct regulator             *analog_regulator;
        struct gpio_desc             *enable_gpio;
        struct gpio_desc             *rst_gpio;
        struct v4l2_ctrl             *ctrl_pixelrate;

        struct v4l2_subdev            subdev;
        struct v4l2_ctrl_handler      ctrl_handler;
        struct v4l2_rect              crop_rect;
        struct v4l2_mbus_framefmt     format;
        struct v4l2_ctrl             *ctrl_linkfreq;

        int                           hflip;
        int                           vflip;
        u16                           analog_gain;
        u16                           digital_gain;
        u32                           exposure_time;
        const struct imx_mode        *cur_mode;
        s64                           cur_linkfreq; /* copy of rom_table entry, since type s64 is needed */
        s64                           cur_pixelrate;
        u8                           *cur_datalanes;/* pointer to rom_table entry for convenience        */
        s32                           cur_pixelcode;
        const struct imx_trait       *trait;
        struct i2c_client            *rom;
        struct vc_rom_table           rom_table;
        u32                           io_config;
        u32                           enable_extrig;
        u32                           sen_clk;

        struct mutex                  mutex;
        enum imx_model                model;
        int                           color;
        struct vc_sen_reg_content     content;
        struct v4l2_fract             tpf;
        u32                           frame_len;
        struct imx_mode               work_mode;
        int                           stereo;
        struct v4l2_ctrl              *hblank;
        struct v4l2_ctrl              *vblank;
};




static inline struct imx *  to_imx(const struct i2c_client *client)
{
	return container_of(i2c_get_clientdata(client), struct imx, subdev);
}

#endif //__VC_MIPI_MODULES_0__H__
