BITS 64
DEFAULT REL

%include "platform.inc"

SECTION .text
GLOBAL  LINKER_PREFIX(ft_write)
EXTERN LIBC_ERR_FUNC

LINKER_PREFIX(ft_write):
    push    rbx

    ; sys_write number
    mov     rax, SYS_WRITE
    ; rdi already have an fd
    ; rsi already have an buffer address
    ; rdx already have an size
    syscall

    SYSCALL_ERROR_HANDLER LIBC_ERR_FUNC

    pop     rbx
    ret