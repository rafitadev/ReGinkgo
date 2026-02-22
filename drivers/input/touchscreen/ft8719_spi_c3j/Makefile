# Makefile for the focaltech touchscreen drivers.

ccflags-y += -include $(srctree)/drivers/input/touchscreen/ft8719_spi_c3j/focaltech_namespace.h
subdir-ccflags-y += -include $(srctree)/drivers/input/touchscreen/ft8719_spi_c3j/focaltech_namespace.h


obj-$(CONFIG_TOUCHSCREEN_FTS_C3J)	+=  focaltech_core.o
obj-$(CONFIG_TOUCHSCREEN_FTS_C3J)	+=  focaltech_ex_fun.o
obj-$(CONFIG_TOUCHSCREEN_FTS_C3J)	+=  focaltech_ex_mode.o
obj-$(CONFIG_TOUCHSCREEN_FTS_C3J)	+=  focaltech_gesture.o
obj-$(CONFIG_TOUCHSCREEN_FTS_C3J)	+=  focaltech_esdcheck.o
obj-$(CONFIG_TOUCHSCREEN_FTS_C3J)   +=  focaltech_point_report_check.o


obj-$(CONFIG_TOUCHSCREEN_FTS_C3J)   +=  focaltech_spi.o
obj-$(CONFIG_TOUCHSCREEN_FTS_C3J)	+=  focaltech_flash.o

obj-$(CONFIG_TOUCHSCREEN_FTS_C3J)	+=  focaltech_test/

