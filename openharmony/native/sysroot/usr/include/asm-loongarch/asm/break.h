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
#ifndef __UAPI_ASM_BREAK_H
#define __UAPI_ASM_BREAK_H
#define BRK_DEFAULT 0
#define BRK_BUG 1
#define BRK_KDB 2
#define BRK_MATHEMU 3
#define BRK_USERBP 4
#define BRK_SSTEPBP 5
#define BRK_OVERFLOW 6
#define BRK_DIVZERO 7
#define BRK_RANGE 8
#define BRK_MULOVFL 9
#define BRK_KPROBE_BP 10
#define BRK_KPROBE_SSTEPBP 11
#define BRK_UPROBE_BP 12
#define BRK_UPROBE_XOLBP 13
#endif
