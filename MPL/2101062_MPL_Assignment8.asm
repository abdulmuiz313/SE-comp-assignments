;Problem Statement:Write x86/64 to find the largest of given Byte/Word/Dword
;/64bit numbers.
;-------------------------.data section------------------------------
section .data
    msg db 10,"Program to find largest number in array"
    msg_len equ $-msg
    lnum db 10,"Largest number in array is :"
    lnum_len equ $-lnum
    array db 11h,55h,33h,22h,44h
    section .bss
    arrcnt resb 1
    char_ans resb 3
    %macro screen_io 4
        mov rax, %1
        mov rdi, %2
        mov rsi, %3
        mov rdx, %4
        syscall
    %endmacro  

;------------------------.text section -----------------------------
section .text
    global _start
_start: 
    screen_io 1,1,msg,msg_len
    mov byte[arrcnt],05
    mov rsi, array
    mov al, 0
    lp: cmp al,[rsi]
    Jg skip
    Xchg al,[rsi]
    skip: inc rsi
    dec byte[arrcnt]
    Jnz lp
    ; Display al ; al contains largest number
      
    jmp display_proc
    mov rax,60
    mov rdi,00
    syscall

;--------------display procedure-----------------
display_proc:
	mov rbp,char_ans
	mov rcx,2

up3:
	mov rbx,rax
	rol bl,04
	mov dl,bl

	and dl,0Fh
	
	cmp dl,09h
	
	jbe nxt

	add dl,07h
nxt:

	add dl,30h
    mov [rbp],dl
	
	inc rbp
	dec rcx
	jnz up3
    
    screen_io 1,1,lnum,lnum_len
	screen_io 1,1,char_ans,03
	;scall 1,1,m3,l3
ret

;Name:Abdulmuiz Shaikh
;Roll No.:2101062
;Division:SE (A)
;------------------------------OUTPUT---------------------------------
;Program to find largest number in array
;Largest number in array is :55
