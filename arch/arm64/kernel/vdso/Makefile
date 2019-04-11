# SPDX-License-Identifier: GPL-2.0
#
# Building a vDSO image for AArch64.
#
# Author: Will Deacon <will.deacon@arm.com>
# Heavily based on the vDSO Makefiles for other archs.
#

obj-vdso := gettimeofday.o note.o sigreturn.o

# Build rules
targets := $(obj-vdso) vdso.so vdso.so.dbg
obj-vdso := $(addprefix $(obj)/, $(obj-vdso))

ldflags-y := -shared -nostdlib -soname=linux-vdso.so.1 \
		$(call ld-option, --hash-style=sysv) -n -T
ccflags-y += $(DISABLE_LTO)

<<<<<<< HEAD
=======
CFLAGS_REMOVE_vgettimeofday.o += $(CC_FLAGS_SCS)

ccflags-y := -fno-common -fno-builtin -fno-stack-protector
ccflags-y += -DDISABLE_BRANCH_PROFILING

VDSO_LDFLAGS := -Bsymbolic

CFLAGS_REMOVE_vgettimeofday.o = $(CC_FLAGS_FTRACE) -Os
KBUILD_CFLAGS			+= $(DISABLE_LTO)
KASAN_SANITIZE			:= n
UBSAN_SANITIZE			:= n
OBJECT_FILES_NON_STANDARD	:= y
KCOV_INSTRUMENT			:= n

ifeq ($(c-gettimeofday-y),)
CFLAGS_vgettimeofday.o = -O2 -mcmodel=tiny
else
CFLAGS_vgettimeofday.o = -O2 -mcmodel=tiny -include $(c-gettimeofday-y)
endif

# Clang versions less than 8 do not support -mcmodel=tiny
ifeq ($(CONFIG_CC_IS_CLANG), y)
  ifeq ($(shell test $(CONFIG_CLANG_VERSION) -lt 80000; echo $$?),0)
    CFLAGS_REMOVE_vgettimeofday.o += -mcmodel=tiny
  endif
endif

>>>>>>> d98e9848ac37... UPSTREAM: arm64: vdso: Fix compilation with clang older than 8
# Disable gcov profiling for VDSO code
GCOV_PROFILE := n

obj-y += vdso.o
extra-y += vdso.lds
CPPFLAGS_vdso.lds += -P -C -U$(ARCH)

# Force dependency (incbin is bad)
$(obj)/vdso.o : $(obj)/vdso.so

# Link rule for the .so file, .lds has to be first
$(obj)/vdso.so.dbg: $(src)/vdso.lds $(obj-vdso)
<<<<<<< HEAD
	$(call if_changed,vdsold)
=======
	$(call if_changed,ld)
>>>>>>> 293424ec2787... BACKPORT: arm64: vdso: use $(LD) instead of $(CC) to link VDSO

# Strip rule for the .so file
$(obj)/%.so: OBJCOPYFLAGS := -S
$(obj)/%.so: $(obj)/%.so.dbg FORCE
	$(call if_changed,objcopy)

# Generate VDSO offsets using helper script
gen-vdsosym := $(srctree)/$(src)/gen_vdso_offsets.sh
quiet_cmd_vdsosym = VDSOSYM $@
define cmd_vdsosym
	$(NM) $< | $(gen-vdsosym) | LC_ALL=C sort > $@
endef

include/generated/vdso-offsets.h: $(obj)/vdso.so.dbg FORCE
	$(call if_changed,vdsosym)

# Assembly rules for the .S files
$(obj-vdso): %.o: %.S FORCE
	$(call if_changed_dep,vdsoas)

# Actual build commands
<<<<<<< HEAD
quiet_cmd_vdsold = VDSOL   $@
      cmd_vdsold = $(CC) $(c_flags) -Wl,-n -Wl,-T $^ -o $@
=======
>>>>>>> 293424ec2787... BACKPORT: arm64: vdso: use $(LD) instead of $(CC) to link VDSO
quiet_cmd_vdsoas = VDSOA   $@
      cmd_vdsoas = $(CC) $(a_flags) -c -o $@ $<

# Install commands for the unstripped file
quiet_cmd_vdso_install = INSTALL $@
      cmd_vdso_install = cp $(obj)/$@.dbg $(MODLIB)/vdso/$@

vdso.so: $(obj)/vdso.so.dbg
	@mkdir -p $(MODLIB)/vdso
	$(call cmd,vdso_install)

vdso_install: vdso.so
