;Problem Statement:Write x86/64 to perform multiplication of two 8-bit 
;hexadecimal numbers.Use seccessive addition and add and shift method.
;-------------------------.data section------------------------------
section .data

welmsg  db 10, '*****Multiplication using****',10
	db 10,' 1. Successive addition',10
	db 10, '2. Shift & add method',10
	db 10, '3.exit',10
	db 10, 'Enter your choice',10
welmsg_len equ $-welmsg

nummsg db 10,'Enter two digits of Number::'
nummsg_len equ $-nummsg

resmsg db 10,'Multiplication of elements::'
resmsg_len equ $-resmsg

blankmsg db 10,'',10
blank_len equ $-blankmsg

;-------------------------.bss section------------------------------

section .bss

	numascii resb 03
	num1 resb 02
	num2 resb 02
	result resd 01
	dispbuff resb 04
    choice resb 1 
%macro display 2
	mov rax,01
	mov rdi,01
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro accept 2
	mov rax,00
	mov rdi,00
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

;------------------------.text section -----------------------------
section .text
global _start
_start:

	
	display nummsg,nummsg_len
	accept numascii,3
	call packnum
	mov byte[num1],bl

	display nummsg,nummsg_len
	accept numascii,3
	call packnum
	mov byte[num2],bl
    
menu: display welmsg, welmsg_len
    accept choice,2 
    
    cmp byte [choice],'1'
	je add_proc
    
	cmp byte [choice],'2'
	je shift_proc
	
	cmp byte [choice],'3'
	
	je exit

add_proc:mov ecx,00
	mov eax,00	
	mov cx,[num2]
     	mov edx,00h            ;Temporary Addition
	mov eax,[num1]
        

addup:	add edx,eax
	loop addup
	
	mov [result],edx

	display resmsg,resmsg_len
	mov ebx,[result]

	call disp16_proc

	display blankmsg,blank_len
    jmp menu
    
    
shift_proc:
	mov eax,00
	mov ecx,00
	mov ebx,00
	mov edx,0
	mov dword[result],00	
	mov al,[num1]

	mov cl,0
	
	mov edx,08h

	addup1:
		rcr al,01
		jnc next1
		mov bl,[num2]
		shl bx,cl
		add [result],bx
		
	next1: 	inc cl
	       	dec edx    
		jnz addup1

	display resmsg,resmsg_len
	mov ebx,[result]
	call disp16_proc

display blankmsg,blank_len  
jmp menu
exit:	mov rax,60
	mov rbx,00
	syscall

;**********Packnum Procedure**********************
packnum:
	mov bl,0
	mov ecx,02
	mov esi,numascii
    up1:rol bl,04
	mov al,[esi]
	cmp al,39h
	jbe skip1
	sub al,07h
 skip1: sub al,30h
	add bl,al
	inc esi
	loop up1
	ret
;**********Display Procedure**********************
disp16_proc:
	mov ecx,4
	mov edi,dispbuff
dup1:  
    rol bx,4
	mov al,bl
	and al,0fh
	cmp al,09
    jbe dskip
	add al,07h
dskip: 
    add al,30h
    mov [edi],al
    inc edi
    loop dup1
    display dispbuff,4
    ret
;Name:Abdulmuiz Shaikh
;Roll No.:2101062
;Division:SE (A)
;------------------------------OUTPUT---------------------------------
;Enter two digits of Number::
;Enter two digits of Number::
;*****Multiplication using****

; 1. Successive addition

;2. Shift & add method

;3.exit

;Enter your choice

;Multiplication of elements::0130


;*****Multiplication using****

; 1. Successive addition

;2. Shift & add method

;3.exit

;Enter your choice

;Multiplication of elements::0130


;*****Multiplication using****

; 1. Successive addition

;2. Shift & add method

;3.exit

;Enter your choice