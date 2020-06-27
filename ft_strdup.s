BITS 64
DEFAULT REL

%include "libasm.inc"
%include "platform.inc"

SECTION .text
GLOBAL  LINKER_PREFIX(ft_strdup)
EXTERN  LINKER_PREFIX(ft_strlen), LINKER_PREFIX(ft_memcpy), LINKER_PREFIX(malloc)

; Parametrs accepting by (64 C Call Convention)
; $RDI - source string address

; returns allocated string address ($RAX)
LINKER_PREFIX(ft_strdup):
    stack_push_8
    push    r12
    push    rbx

    ; saving source address
    mov     rbx, rdi

    ; $rdi already have an string address, so we call strlen
    call    LINKER_PREFIX(ft_strlen)
    ; saving string length
    mov     r12, rax
    
    ; prepare parametr for malloc(3) call
    mov     rdi, r12
    add     rdi, 1
    call    LINKER_PREFIX(malloc)

    ; jump to the end if malloc(3) fails
    test    rax, rax
    jz      .epilogue

    ; preparing parametrs and call memcpy
    mov     rdi, rax
    mov     rsi, rbx
    mov     rdx, r12
    call    LINKER_PREFIX(ft_memcpy)

    ; set null-byte to the end of the string
    mov     BYTE [rax + r12], 0x0

.epilogue:
    pop     rbx
    pop     r12
    stack_pull_8
    ret
