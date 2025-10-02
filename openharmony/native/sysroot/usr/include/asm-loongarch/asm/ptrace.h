/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _ASM_PTRACE_H
#define _ASM_PTRACE_H
#include <linux/types.h>
#include <stdint.h>
#define GPR_BASE 0
#define GPR_NUM 32
#define GPR_END (GPR_BASE + GPR_NUM - 1)
#define ARG0 (GPR_END + 1)
#define PC (GPR_END + 2)
#define BADVADDR (GPR_END + 3)
#define NUM_FPU_REGS 32
struct user_pt_regs {
  unsigned long regs[32];
  unsigned long orig_a0;
  unsigned long csr_era;
  unsigned long csr_badv;
  unsigned long reserved[10];
} __attribute__((aligned(8)));
struct user_fp_state {
  uint64_t fpr[32];
  uint64_t fcc;
  uint32_t fcsr;
};
struct user_lsx_state {
  uint64_t vregs[32 * 2];
};
struct user_lasx_state {
  uint64_t vregs[32 * 4];
};
#define PTRACE_SYSEMU 0x1f
#define PTRACE_SYSEMU_SINGLESTEP 0x20
#endif
