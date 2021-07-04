;Problem Statement:Write an X86/64 ALP to accept a string and display its length.
;-------------------------.data section------------------------------
section .data
    msg1 db "Enter a string", 0ah
    msg1_len equ $-msg1
    
    msg2 db "Length of string is :", 0ah
    msg2_len equ $-msg2

;-------------------------.bss section------------------------------    
section .bss
str1 resb 20
dnumbuff resb 2 

%macro display 2
    mov rax, 1
    mov rdi, 1
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

%macro accept 2
    mov rax, 0
    mov rdi, 0
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

;------------------------.text section -----------------------------
section .text
    global _start

_start:
    display msg1,msg1_len
    accept str1, 20
    dec rax
    mov bl,al
    
    display msg2,msg2_len
    
    call dispproc
    mov rax,60
    mov rdi,0 
    syscall  
   
dispproc:
    mov rsi,dnumbuff
    mov cl,02 ;counter 
    
up: rol bl,4
    mov dl,bl
    and dl,0fh
    add dl,30h
    cmp dl,39h
    jbe skip ;jump below if not equal
    add dl,07
    
skip:
    mov [rsi],dl
    inc rsi 
    dec cl 
    jnz up
    
display dnumbuff,2
ret 
;------------------------------------------------------------------
;Name:Abdulmuiz Shaikh
;Roll No.:2101062
;Division:SE (A)
;------------------------INPUT:-------------------------------------
;Welcome
;------------------------OUTPUT:------------------------------------
;Enter a string
;Length of string is :
;07
