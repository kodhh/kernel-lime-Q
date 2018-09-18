/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_X86_VGTOD_H
#define _ASM_X86_VGTOD_H

#include <linux/compiler.h>
#include <asm/clocksource.h>
#include <vdso/datapage.h>
#include <vdso/helpers.h>

#ifdef BUILD_VDSO32_64
typedef u64 gtod_long_t;
#else
typedef unsigned long gtod_long_t;
#endif

extern int vclocks_used;
static inline bool vclock_was_used(int vclock)
{
	return READ_ONCE(vclocks_used) & (1 << vclock);
}

<<<<<<< HEAD
static inline unsigned gtod_read_begin(const struct vsyscall_gtod_data *s)
{
	unsigned ret;

repeat:
	ret = READ_ONCE(s->seq);
	if (unlikely(ret & 1)) {
		cpu_relax();
		goto repeat;
	}
	smp_rmb();
	return ret;
}

static inline int gtod_read_retry(const struct vsyscall_gtod_data *s,
					unsigned start)
{
	smp_rmb();
	return unlikely(s->seq != start);
}

static inline void gtod_write_begin(struct vsyscall_gtod_data *s)
{
	++s->seq;
	smp_wmb();
}

static inline void gtod_write_end(struct vsyscall_gtod_data *s)
{
	smp_wmb();
	++s->seq;
}

<<<<<<< HEAD
#ifdef CONFIG_X86_64

#define VGETCPU_CPU_MASK 0xfff

static inline unsigned int __getcpu(void)
{
	unsigned int p;

	/*
	 * Load CPU (and node) number from GDT.  LSL is faster than RDTSCP
	 * and works on all CPUs.  This is volatile so that it orders
	 * correctly with respect to barrier() and to keep GCC from cleverly
	 * hoisting it out of the calling function.
	 *
	 * If RDPID is available, use it.
	 */
	alternative_io ("lsl %[seg],%[p]",
			".byte 0xf3,0x0f,0xc7,0xf8", /* RDPID %eax/rax */
			X86_FEATURE_RDPID,
			[p] "=a" (p), [seg] "r" (__CPU_NUMBER_SEG));

	return p;
}

#endif /* CONFIG_X86_64 */

=======
>>>>>>> 5ddd47793d66... BACKPORT: x86/vdso: Switch to generic vDSO implementation
=======
>>>>>>> bd3bc4995a72... UPSTREAM: x86/vdso: Introduce helper functions for CPU and node number
#endif /* _ASM_X86_VGTOD_H */
