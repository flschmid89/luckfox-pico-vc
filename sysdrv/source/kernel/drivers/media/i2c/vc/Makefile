
SENSOR_DRIVER      := vc_mipi_common_bcm2835
SENSOR_DRIVER      += vc_mipi_common
SENSOR_DRIVER      += vc_mipi_modules_0


obj-$(CONFIG_VIDEO_VC_DRIVER) += $(foreach sencommon,$(SENSOR_DRIVER),$(sencommon)/$(sencommon).o)