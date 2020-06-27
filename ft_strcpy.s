BITS 64
DEFAULT REL

%include "libasm.inc"
%include "platform.inc"

SECTION .text
GLOBAL  LINKER_PREFIX(ft_strcpy)
EXTERN  LINKER_PREFIX(ft_strlen), LINKER_PREFIX(ft_memcpy)

; Parametrs accepting by (64 C Call Convention)
; $RDI - dst address
; $RSI - src address

; returns destination address ($RAX)
LINKER_PREFIX(ft_strcpy):
    stack_push_8
    push    r12
    push    rbx

    ; saving dst
    mov     rbx, rdi
    ; saving src
    mov     r12, rsi

    ; set str address for strlen
    mov     rdi, r12
    call    LINKER_PREFIX(ft_strlen)

    ; set size for memcpy from return of strlen
    mov     rdx, rax
    ; set dst for memcpy
    mov     rdi, rbx
    ; set src for memcpy
    mov     rsi, r12
    call    LINKER_PREFIX(ft_memcpy)

    ; set null-byte to the end of destination string
    mov     BYTE [rax + rdx], 0x0

    ; $rax already have destionation address after ft_memcpy
    pop     r12
    pop     rbx
    stack_pull_8
    ret
