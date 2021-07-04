;Problem Statement:Write an X86/64 ALP to count no. of positive and negative no. from the array.
;-------------------------.data section------------------------------
section .data

	
	arr dd -11111111H, 22222222H,-33333333H, -44444444H,55555555H
	arr_size equ 5
	
	msg db	10,"The number of Positive elements in 32-bit array:",0ah
	msg_len equ $-msg
	
	msg1 db 10,10,"The number of Negative elements in 32-bit array:",0ah
	msg1_len equ $-msg1
	
;-------------------------.bss section------------------------------
section .bss

	pcnt resq 01
	ncnt resq 01
	dnumbuff resb 02
	
	%macro display 2
		mov rax,01
		mov rdi,01
		mov rsi,%1
		mov rdx,%2
		syscall
	%endmacro
	
;------------------------.text section -----------------------------

section .text

global _start

_start:
	mov esi, arr
	mov ecx,5	;Arraay counter i.e.5
	mov ebx,0	; counter for +ve nos
	mov edx,0	; counter for -ve nos

next_num:
	mov eax,[esi]	; take no. in RAX
	rcl eax,1	; rotate left 1 bit to check for sign bit
	jc negative	

positive:
	inc ebx		; no carry, so no. is +ve
	jmp next 
	
negative:
	inc edx 	; carry, so no. is -ve

next:
	add esi,4	; 32 bit nos i.e. 4 bytes
	loop next_num

	mov [pcnt], ebx	; store positive count
	mov [ncnt], edx	; store negative count

	display msg, msg_len
	mov ebx,[pcnt]	; load value of p_count in rax
	call dispproc 	

	display msg1, msg1_len
	mov ebx,[ncnt]	; load value of n_count in rax
	call dispproc		

	

exit:
	mov rax,60		
	mov rbx,00
	syscall

;------------------------procedures useds -----------------------------
dispproc:
	mov edi,dnumbuff	;point edi to buffer
	mov ecx,02		;load number of digits to display

dispup1:
	rol bl,4	;rotate number left by four bits
	mov dl,bl	;move lower byte in dl
	and dl,0fh	;mask upper digit of byte in dl
	add dl,30h	;add 30h to calculate ASCII code
	cmp dl,39h	;compare with 39h
	jbe dispskip1	;if less than 39h skip adding 07 more
	add dl,07h	;else add 07

dispskip1:
	mov [edi],dl	;store ASCII code in buffer
	inc edi		;point to next byte
	loop dispup1	;decrement the count of digits to display
			;if not zero jump to repeat
	
	display dnumbuff,2
	ret
	
;Name:Abdulmuiz Shaikh
;Roll No.:2101062
;Division:SE (A)
;------------------------OUTPUT:------------------------------------
;
;The number of Positive elements in 32-bit array:
;02

;The number of Negative elements in 32-bit array:
;03
;