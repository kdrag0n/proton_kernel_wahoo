ifeq ($(CONFIG_BUILD_ARM64_DT_OVERLAY),y)
dtbo-$(CONFIG_BOARD_MUSKIE) += overlay-walleye-xd_xe_a.dtbo
else
dtb-$(CONFIG_BOARD_MUSKIE) += msm8998-htc-walleye-xd_xe_a.dtb
endif

always		:= $(dtb-y) $(dtbo-y)
subdir-y	:= $(dts-dirs)
clean-files	:= *.dtb *.dtbo
