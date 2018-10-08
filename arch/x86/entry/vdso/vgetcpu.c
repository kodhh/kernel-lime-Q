/*
 * Copyright 2006 Andi Kleen, SUSE Labs.
 * Subject to the GNU Public License, v.2
 *
 * Fast user context implementation of getcpu()
 */

#include <linux/kernel.h>
#include <linux/getcpu.h>
#include <linux/time.h>
#include <asm/vgtod.h>

notrace long
__vdso_getcpu(unsigned *cpu, unsigned *node, struct getcpu_cache *unused)
{
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	unsigned int p;

	p = __getcpu();

	if (cpu)
		*cpu = p & VGETCPU_CPU_MASK;
	if (node)
		*node = p >> 12;
=======
	vdso_read_cpunode(cpu, node);
>>>>>>> 0eb9ee107449... UPSTREAM: x86/segments: Introduce the 'CPUNODE' naming to better document the segment limit CPU/node NR trick
=======
	vdso_read_cpu_node(cpu, node);
>>>>>>> bd3bc4995a72... UPSTREAM: x86/vdso: Introduce helper functions for CPU and node number
=======
	vdso_read_cpunode(cpu, node);
>>>>>>> 0eb9ee107449... UPSTREAM: x86/segments: Introduce the 'CPUNODE' naming to better document the segment limit CPU/node NR trick
	return 0;
}

long getcpu(unsigned *cpu, unsigned *node, struct getcpu_cache *tcache)
	__attribute__((weak, alias("__vdso_getcpu")));
