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
#ifndef _ASM_SWAB_H
#define _ASM_SWAB_H


#include <linux/types.h>

#define __SWAB_64_THRU_32__

static __inline__  __u16 __arch_swab16(__u16 x)
{
	__asm__(
	"	revb.2h	%0, %1			\n"
	: "=r" (x)
	: "r" (x));

	return x;
}
#define __arch_swab16 __arch_swab16

static __inline__  __u32 __arch_swab32(__u32 x)
{
	__asm__(
	"	revb.2h	%0, %1			\n"
	"	rotri.w	%0, %0, 16		\n"
	: "=r" (x)
	: "r" (x));

	return x;
}
#define __arch_swab32 __arch_swab32

#ifdef __loongarch64
static __inline__  __u64 __arch_swab64(__u64 x)
{
	__asm__(
	"	revb.4h	%0, %1			\n"
	"	revh.d	%0, %0			\n"
	: "=r" (x)
	: "r" (x));

	return x;
}
#define __arch_swab64 __arch_swab64
#endif /* __loongarch64 */
#endif /* _ASM_SWAB_H */
