// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * MIPS64 and compat userspace implementations of gettimeofday()
 * and similar.
 *
 * Copyright (C) 2015 Imagination Technologies
 * Copyright (C) 2018 ARM Limited
 *
 */
#include <linux/time.h>
#include <linux/types.h>

#if _MIPS_SIM != _MIPS_SIM_ABI64
int __vdso_clock_gettime(clockid_t clock,
			 struct old_timespec32 *ts)
{
	return __cvdso_clock_gettime32(clock, ts);
}

int __vdso_gettimeofday(struct __kernel_old_timeval *tv,
			struct timezone *tz)
{
	return __cvdso_gettimeofday(tv, tz);
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 23dea1cf7ed3... UPSTREAM: mips: Add clock_getres entry point
int __vdso_clock_getres(clockid_t clock_id,
			struct old_timespec32 *res)
{
	return __cvdso_clock_getres_time32(clock_id, res);
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 9abf17e726e1... UPSTREAM: mips: Add clock_gettime64 entry point
int __vdso_clock_gettime64(clockid_t clock,
			   struct __kernel_timespec *ts)
{
	return __cvdso_clock_gettime(clock, ts);
}

<<<<<<< HEAD
=======
>>>>>>> 6b7f832e465d... BACKPORT: mips: Add support for generic vDSO
=======
>>>>>>> 23dea1cf7ed3... UPSTREAM: mips: Add clock_getres entry point
=======
>>>>>>> 9abf17e726e1... UPSTREAM: mips: Add clock_gettime64 entry point
#else

int __vdso_clock_gettime(clockid_t clock,
			 struct __kernel_timespec *ts)
{
	return __cvdso_clock_gettime(clock, ts);
}

int __vdso_gettimeofday(struct __kernel_old_timeval *tv,
			struct timezone *tz)
{
	return __cvdso_gettimeofday(tv, tz);
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 23dea1cf7ed3... UPSTREAM: mips: Add clock_getres entry point
int __vdso_clock_getres(clockid_t clock_id,
			struct __kernel_timespec *res)
{
	return __cvdso_clock_getres(clock_id, res);
}

<<<<<<< HEAD
=======
>>>>>>> 6b7f832e465d... BACKPORT: mips: Add support for generic vDSO
=======
>>>>>>> 23dea1cf7ed3... UPSTREAM: mips: Add clock_getres entry point
#endif
