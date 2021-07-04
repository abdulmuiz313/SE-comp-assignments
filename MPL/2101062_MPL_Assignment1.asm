;Problem Statement:Write an X86/64 ALP to accept  five 64 digit Hexadecimal no from user
;and store them in an array and display the accepted numbers
;-------------------------.data section------------------------------
section .data
msg db "Enter 5 64-bits hex no.:", 0ah
msg_len equ $-msg

msg1 db "accepted numbers are:", 0ah  ;
msg1_len equ $-msg1

count db 05
;-------------------------.bss section------------------------------
section .bss
array resb 15

;------------------------.text section -----------------------------
section .text
global _start

_start:
    ;displaying msg 1 
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msg_len
    syscall

    ;accepting five 16digit hexadecimal no. as input
    mov rbx, 00
    up: mov rax , 0
    mov rdi, 0
    mov rsi, array
    add rsi, rbx
    mov rdx, 17  ;here we write 17 because 16 digit no. and one enter button space.
    syscall
    add rbx,17 ;same here 
    dec byte[count]
    jnz up

    ;displaying all five 16digit hexadecimal no.
    mov rax, 1
    mov rdi, 1
    mov rsi, msg1
    mov rdx, msg1_len
    syscall

    mov byte[count], 05
    mov rbx,00
    up1: mov rax , 1
    mov rdi,1
    mov rsi, array
    add rsi,rbx
    mov rdx,17
    syscall
    add rbx,17
    dec byte[count]
    jnz up1
;call for exit
mov rax, 60
mov rdi, 0
syscall

;Name:Abdulmuiz Shaikh
;Roll No.:2101062
;Division:SE (A)
;--------------------OUTPUT----------------
;Enter 5 64-bits hex no.:
;accepted numbers are:
;1234567898a65432
;9234567898765499
;5234567898765436
;9234567898765488
;1234567898765477