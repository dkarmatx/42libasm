BITS 64
DEFAULT REL

%include "platform.inc"

SECTION .text
GLOBAL  LINKER_PREFIX(ft_read)
EXTERN LIBC_ERR_FUNC

LINKER_PREFIX(ft_read):
    push    rbx

    ; sys_read number
    mov     rax, SYS_READ
    ; rdi already have an fd
    ; rsi already have an buffer address
    ; rdx already have an buffer size
    syscall

    SYSCALL_ERROR_HANDLER LIBC_ERR_FUNC

    pop     rbx
    ret