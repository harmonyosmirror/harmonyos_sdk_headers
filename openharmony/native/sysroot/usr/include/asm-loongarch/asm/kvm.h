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
#ifndef __LINUX_KVM_LOONGARCH_H
#define __LINUX_KVM_LOONGARCH_H
#include <linux/types.h>
#include <stdint.h>
#define __KVM_HAVE_GUEST_DEBUG
#define KVM_GUESTDBG_USE_SW_BP 0x00010000
#define KVM_GUESTDBG_USE_HW_BP 0x00020000
#define KVM_DATA_HW_BREAKPOINT_NUM 8
#define KVM_INST_HW_BREAKPOINT_NUM 8
#define __KVM_HAVE_READONLY_MEM
#define KVM_COALESCED_MMIO_PAGE_OFFSET 1
struct kvm_regs {
  __u64 gpr[32];
  __u64 pc;
};
struct kvm_cpucfg {
  __u32 cpucfg[64];
};
struct kvm_fpu {
  __u32 fcsr;
  __u32 none;
  __u64 fcc;
  struct kvm_fpureg {
    __u64 val64[4];
  } fpr[32];
};
#define KVM_REG_LOONGARCH_GP (KVM_REG_LOONGARCH | 0x00000ULL)
#define KVM_REG_LOONGARCH_CSR (KVM_REG_LOONGARCH | 0x10000ULL)
#define KVM_REG_LOONGARCH_KVM (KVM_REG_LOONGARCH | 0x20000ULL)
#define KVM_REG_LOONGARCH_FPU (KVM_REG_LOONGARCH | 0x30000ULL)
#define KVM_REG_LOONGARCH_MASK (KVM_REG_LOONGARCH | 0x30000ULL)
#define KVM_CSR_IDX_MASK (0x10000 - 1)
#define KVM_REG_LOONGARCH_COUNTER (KVM_REG_LOONGARCH_KVM | KVM_REG_SIZE_U64 | 3)
#define KVM_REG_LOONGARCH_VCPU_RESET (KVM_REG_LOONGARCH_KVM | KVM_REG_SIZE_U64 | 4)
#define __KVM_HAVE_IRQ_LINE
struct kvm_debug_exit_arch {
  __u64 era;
  __u32 fwps;
  __u32 mwps;
  __u32 exception;
};
struct hw_breakpoint {
  __u64 addr;
  __u64 mask;
  __u32 asid;
  __u32 ctrl;
};
struct kvm_guest_debug_arch {
  struct hw_breakpoint data_breakpoint[KVM_DATA_HW_BREAKPOINT_NUM];
  struct hw_breakpoint inst_breakpoint[KVM_INST_HW_BREAKPOINT_NUM];
  int inst_bp_nums, data_bp_nums;
};
struct kvm_sync_regs {
};
struct kvm_sregs {
};
struct kvm_iocsr_entry {
  __u32 addr;
  __u32 pad;
  __u64 data;
};
struct kvm_csr_entry {
  __u32 index;
  __u32 reserved;
  __u64 data;
};
struct kvm_msrs {
  __u32 ncsrs;
  __u32 pad;
  struct kvm_csr_entry entries[0];
};
struct kvm_loongarch_interrupt {
  __u32 cpu;
  __u32 irq;
};
#define KVM_IRQCHIP_LS7A_IOAPIC 0x0
#define KVM_IRQCHIP_LS3A_GIPI 0x1
#define KVM_IRQCHIP_LS3A_HT_IRQ 0x2
#define KVM_IRQCHIP_LS3A_ROUTE 0x3
#define KVM_IRQCHIP_LS3A_EXTIRQ 0x4
#define KVM_IRQCHIP_LS3A_IPMASK 0x5
#define KVM_NR_IRQCHIPS 1
#define KVM_IRQCHIP_NUM_PINS 64
#define KVM_MAX_CORES 256
#define KVM_EXTIOI_IRQS (256)
#define KVM_EXTIOI_IRQS_BITMAP_SIZE (KVM_EXTIOI_IRQS / 8)
#define KVM_EXTIOI_IRQS_IPMAP_SIZE (KVM_EXTIOI_IRQS / 32)
#define KVM_EXTIOI_IRQS_PER_GROUP 32
#define KVM_EXTIOI_IRQS_COREMAP_SIZE (KVM_EXTIOI_IRQS)
#define KVM_EXTIOI_IRQS_NODETYPE_SIZE 16
struct ls7a_ioapic_state {
  __u64 int_id;
  __u64 int_mask;
  __u64 htmsi_en;
  __u64 intedge;
  __u64 intclr;
  __u64 auto_crtl0;
  __u64 auto_crtl1;
  __u8 route_entry[64];
  __u8 htmsi_vector[64];
  __u64 intisr_chip0;
  __u64 intisr_chip1;
  __u64 last_intirr;
  __u64 intirr;
  __u64 intisr;
  __u64 int_polarity;
};
struct loongarch_gipi_single {
  __u32 status;
  __u32 en;
  __u32 set;
  __u32 clear;
  __u64 buf[4];
};
struct loongarch_gipiState {
  struct loongarch_gipi_single core[KVM_MAX_CORES];
};
struct kvm_loongarch_ls3a_extirq_state {
  union ext_en_r {
    uint64_t reg_u64[KVM_EXTIOI_IRQS_BITMAP_SIZE / 8];
    uint32_t reg_u32[KVM_EXTIOI_IRQS_BITMAP_SIZE / 4];
    uint8_t reg_u8[KVM_EXTIOI_IRQS_BITMAP_SIZE];
  } ext_en_r;
  union bounce_r {
    uint64_t reg_u64[KVM_EXTIOI_IRQS_BITMAP_SIZE / 8];
    uint32_t reg_u32[KVM_EXTIOI_IRQS_BITMAP_SIZE / 4];
    uint8_t reg_u8[KVM_EXTIOI_IRQS_BITMAP_SIZE];
  } bounce_r;
  union ext_isr_r {
    uint64_t reg_u64[KVM_EXTIOI_IRQS_BITMAP_SIZE / 8];
    uint32_t reg_u32[KVM_EXTIOI_IRQS_BITMAP_SIZE / 4];
    uint8_t reg_u8[KVM_EXTIOI_IRQS_BITMAP_SIZE];
  } ext_isr_r;
  union ext_core_isr_r {
    uint64_t reg_u64[KVM_MAX_CORES][KVM_EXTIOI_IRQS_BITMAP_SIZE / 8];
    uint32_t reg_u32[KVM_MAX_CORES][KVM_EXTIOI_IRQS_BITMAP_SIZE / 4];
    uint8_t reg_u8[KVM_MAX_CORES][KVM_EXTIOI_IRQS_BITMAP_SIZE];
  } ext_core_isr_r;
  union ip_map_r {
    uint64_t reg_u64;
    uint32_t reg_u32[KVM_EXTIOI_IRQS_IPMAP_SIZE / 4];
    uint8_t reg_u8[KVM_EXTIOI_IRQS_IPMAP_SIZE];
  } ip_map_r;
  union core_map_r {
    uint64_t reg_u64[KVM_EXTIOI_IRQS_COREMAP_SIZE / 8];
    uint32_t reg_u32[KVM_EXTIOI_IRQS_COREMAP_SIZE / 4];
    uint8_t reg_u8[KVM_EXTIOI_IRQS_COREMAP_SIZE];
  } core_map_r;
  union node_type_r {
    uint64_t reg_u64[KVM_EXTIOI_IRQS_NODETYPE_SIZE / 4];
    uint32_t reg_u32[KVM_EXTIOI_IRQS_NODETYPE_SIZE / 2];
    uint16_t reg_u16[KVM_EXTIOI_IRQS_NODETYPE_SIZE];
    uint8_t reg_u8[KVM_EXTIOI_IRQS_NODETYPE_SIZE * 2];
  } node_type_r;
};
struct loongarch_kvm_irqchip {
  __u16 chip_id;
  __u16 len;
  __u16 vcpu_id;
  __u16 reserved;
  char data[0];
};
#endif
