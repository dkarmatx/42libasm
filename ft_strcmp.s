BITS 64
DEFAULT REL

%include "libasm.inc"
%include "platform.inc"

SECTION .text
GLOBAL  LINKER_PREFIX(ft_strcmp)
EXTERN  LINKER_PREFIX(ft_memcmp), LINKER_PREFIX(ft_strlen)

; Parametrs accepting by (64 C Call Convention)
; $RDI - m1 address
; $RSI - m2 address

; $AL - return difference
LINKER_PREFIX(ft_strcmp):
    stack_push_8
    push    r12
    push    r13
    push    r14
    push    r15

    ; saving s1 and s2 
    mov     r14, rdi
    mov     r15, rsi

    ; get length of s1
    call    LINKER_PREFIX(ft_strlen)
    mov     r12, rax

    ; get lenght of s2
    mov     rdi, r15
    call    LINKER_PREFIX(ft_strlen)
    mov     r13, rax

    ; choose minimal of lenghts of s1 and s2
.if:
    test    r12, r13
    jle     .r12_lower
.r13_lower:
    mov     rdx, r13
    jmp     .end_if
.r12_lower:
    mov     rdx, r12
.end_if:

    ; increment lenght for null-byte
    inc     rdx
    mov     rdi, r14
    mov     rsi, r15
    call    LINKER_PREFIX(ft_memcmp)

    ; rax already has result, so we return it
    pop     r15
    pop     r14
    pop     r13
    pop     r12
    stack_pull_8
    ret
