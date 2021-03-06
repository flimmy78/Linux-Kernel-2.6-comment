/* 
 * Copyright (C) 2002 Jeff Dike (jdike@karaya.com)
 * Licensed under the GPL
 */

#ifndef __SYSDEP_I386_PTRACE_USER_H__
#define __SYSDEP_I386_PTRACE_USER_H__

#include <asm/ptrace.h>

#define PT_OFFSET(r) ((r) * sizeof(long))

#define PT_SYSCALL_NR(regs) ((regs)[ORIG_EAX])
#define PT_SYSCALL_NR_OFFSET PT_OFFSET(ORIG_EAX)

#define PT_SYSCALL_ARG1_OFFSET PT_OFFSET(EBX)
#define PT_SYSCALL_ARG2_OFFSET PT_OFFSET(ECX)
#define PT_SYSCALL_ARG3_OFFSET PT_OFFSET(EDX)
#define PT_SYSCALL_ARG4_OFFSET PT_OFFSET(ESI)
#define PT_SYSCALL_ARG5_OFFSET PT_OFFSET(EDI)

#define PT_SYSCALL_RET_OFFSET PT_OFFSET(EAX)

#define PT_IP_OFFSET PT_OFFSET(EIP)
#define PT_IP(regs) ((regs)[EIP])
#define PT_SP(regs) ((regs)[UESP])

#ifndef FRAME_SIZE
#define FRAME_SIZE (17)
#endif
#define FRAME_SIZE_OFFSET (FRAME_SIZE * sizeof(unsigned long))

#define FP_FRAME_SIZE (27)
#define FPX_FRAME_SIZE (128)

#define MAX_REG_OFFSET (FRAME_SIZE_OFFSET)
#define MAX_REG_NR (FRAME_SIZE)

#ifdef PTRACE_GETREGS
#define UM_HAVE_GETREGS
#endif

#ifdef PTRACE_SETREGS
#define UM_HAVE_SETREGS
#endif

#ifdef PTRACE_GETFPREGS
#define UM_HAVE_GETFPREGS
#endif

#ifdef PTRACE_SETFPREGS
#define UM_HAVE_SETFPREGS
#endif

#ifdef PTRACE_GETFPXREGS
#define UM_HAVE_GETFPXREGS
#endif

#ifdef PTRACE_SETFPXREGS
#define UM_HAVE_SETFPXREGS
#endif

extern void update_debugregs(int seq);

#endif
