// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2019-2020, The Linux Foundation. All rights reserved.
<<<<<<< HEAD
 * Copyright (C) 2020 XiaoMi, Inc.
=======
>>>>>>> 3f4b63dc87b8c14c92d2dfd7912cebf038ddf404
 */

#include <linux/kernel.h>
#include <asm/mach/map.h>
#include <asm/mach/arch.h>
#include "board-dt.h"

static const char *trinket_dt_match[] __initconst = {
	"qcom,bengal",
	"qcom,bengal-iot",
	NULL
};

static void __init trinket_init(void)
{
	board_dt_populate(NULL);
}

DT_MACHINE_START(BENGAL,
	"Qualcomm Technologies, Inc. BENGAL (Flattened Device Tree)")
	.init_machine		= trinket_init,
	.dt_compat		= trinket_dt_match,
MACHINE_END
