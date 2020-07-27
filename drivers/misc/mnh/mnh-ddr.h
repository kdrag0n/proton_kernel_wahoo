/*
*
* MNH DDR Driver
* Copyright (c) 2016-2017, Intel Corporation.
*
* This program is free software; you can redistribute it and/or modify it
* under the terms and conditions of the GNU General Public License,
* version 2, as published by the Free Software Foundation.
*
* This program is distributed in the hope it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
* more details.
*
*/
#ifndef __MNH_DDR_H__
#define __MNH_DDR_H__

#include <linux/types.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/gpio/consumer.h>
#include <linux/platform_device.h>

#define MNH_DDR_NUM_CTL_REG	(558 + 1)
#define MNH_DDR_NUM_PHY_REG	(1100 + 1)
#define MNH_DDR_NUM_PI_REG	(191 + 1)

#define MNH_DDR_NUM_FSPS (4)
#define MNH_DDR_NUM_BASES (3)

/* arbitrary but sufficient size for phy deltas */
#define MNH_DDR_PHY_SET_SIZE 32
/* need reg index for setA/B */
#define MNH_DDR_PHY_SET_ELEMS 2
struct mnh_ddr_reg_config {
	u32 fsps[MNH_DDR_NUM_FSPS];
	u32 ctl[MNH_DDR_NUM_CTL_REG];
	u32 pi[MNH_DDR_NUM_PI_REG];
	u32 phy[MNH_DDR_NUM_PHY_REG];
	u32 phy_setA[MNH_DDR_PHY_SET_SIZE][MNH_DDR_PHY_SET_ELEMS];
	u32 phy_setB[MNH_DDR_PHY_SET_SIZE][MNH_DDR_PHY_SET_ELEMS];
};

struct mnh_ddr_internal_state {
	u32 ctl_base;
	u32 ctl[MNH_DDR_NUM_CTL_REG];
	u32 pi_base;
	u32 pi[MNH_DDR_NUM_PI_REG];
	u32 phy_base;
	u32 phy[MNH_DDR_NUM_FSPS][MNH_DDR_NUM_PHY_REG];
	u32 fsps[MNH_DDR_NUM_FSPS];
	u32 suspend_fsp;
	u32 tref[MNH_DDR_NUM_FSPS];
};

enum mnh_ddr_bist_type {
	MOVI1_3N = 0,
	LIMITED_MOVI1_3N,
};

struct mnh_ddr_data {
	struct platform_device *pdev;
	struct mnh_ddr_internal_state _state;
};

int mnh_ddr_platform_init(struct platform_device *pdev,
			  struct mnh_ddr_data *data);
int mnh_ddr_po_init(struct mnh_ddr_data *data, struct gpio_desc *iso_n);
int mnh_ddr_resume(struct mnh_ddr_data *data, struct gpio_desc *iso_n);
int mnh_ddr_suspend(struct mnh_ddr_data *data, struct gpio_desc *iso_n);
int mnh_ddr_clr_int_status(struct device *dev);
u64 mnh_ddr_int_status(struct device *dev);
u32 mnh_ddr_mbist(struct mnh_ddr_data *data, enum mnh_ddr_bist_type bist_type);

#endif /* __MNH_DDR_H__ */
