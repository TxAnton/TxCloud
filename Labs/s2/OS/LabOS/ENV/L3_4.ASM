TESTPC	SEGMENT
	ASSUME CS:TESTPC, DS:TESTPC, ES:NOTHING, SS:NOTHING
	ORG 100H
	
START:	JMP BEGIN
;data

STR_O1 db " free$";
STR_O2 db " OS XMS UMB$";
STR_O3 db " driver's top memory$";
STR_O4 db " MS DOS$";
STR_O5 db " control block 386MAX UMB$";
STR_O6 db " blocked 386MAX$";
STR_O7 db " 386MAX UMB$";
STR_AV_MEM db " Avaible memory: $";
STR_EX_MEM db " Extended memory: $";
STR_MCB db " MCB $"
STR_OWNER db " Owner $"
STR_SIZE db " Size $"
STR_FREE_SUCCESS db "Mem freed$";
STR_FREE_FAIL db "Mem not freed$";

ALLOC_SUCCESS db "Mem allocated$";
ALLOC_FAIL db "Mem not allocated$";

NEW_LINE db 0DH,0AH,'$'




STRING DB 'Some text       ',0DH,0AH,'$'
;procedures

PRINT PROC
		push AX
		mov AH, 9h
		int 21h
		pop AX
		ret
PRINT ENDP

DIGIT_TO_CHAR PROC near
;AL
	and al,0Fh
	cmp al,09h
	jle BLW
	add al,'A'
	sub al, 0Ah
	jmp DTC_CONT
BLW:
	add al,'0'
DTC_CONT:
	ret
DIGIT_TO_CHAR ENDP
;----------------------------------------
PRINT_AS_HEX proc near
;AL - number
;;breaks AX,CX,BX
	push ax
	push bx
	push cx
	push dx
	;mov bx,dx
	mov ch,al
	mov cl,4
	shr al,cl
	call DIGIT_TO_CHAR
	mov dl,al
	mov ah,02h
	int 21h
	mov al,ch
	call DIGIT_TO_CHAR
	mov dl,al
	mov ah,02h
	int 21h
	;mov dx,bx
	pop dx
	pop cx
	pop bx
	pop ax
	
	
	
	ret
PRINT_AS_HEX ENDP

PRINT_WORD proc near
;AX - word
	xchg AL,AH
	call PRINT_AS_HEX
	xchg AL,AH
	call PRINT_AS_HEX
	ret

PRINT_WORD ENDP

LN PROC
	push AX
	push DX
	mov DX, offset NEW_LINE
	mov AH, 9h
	int 21h
	pop DX
	pop AX
	ret
LN ENDP

;-----------------
BEGIN:	

;Avalible mem
	mov DX, offset STR_AV_MEM
	call PRINT
	
	mov AH, 4Ah
	mov BX, 0FFFFh
	int 21h;
	shl BX, 4
	mov AX, BX
	call PRINT_WORD	
	call LN
;Alloc mem
	mov BX, 1000h
	mov AH, 48h
	int 21h
	jnc ALLOCATE_SUCCESS
	mov DX, offset ALLOC_FAIL
	call PRINT
	call LN
	jmp ALLOCATE_DONE

ALLOCATE_SUCCESS:
	mov DX, offset ALLOC_SUCCESS
	call PRINT
	call LN

ALLOCATE_DONE:

;Free mem 
	xor AX,AX
	mov BX, offset STACK_BUF_END
	add BX, 10Fh
	shr BX, 4
	;sub BX,500
	mov AH, 4Ah
	int 21h
	jnc SUCCESS
	mov DX, offset STR_FREE_FAIL
	call PRINT
	call LN
	jmp FREE_END

SUCCESS:
	mov DX, offset STR_FREE_SUCCESS
	call PRINT
	call LN
FREE_END:
	xor AX,AX

;Extended mem
	mov DX, offset STR_EX_MEM
	call PRINT
	mov AL, 30h
	out 70h, AL
	in AL, 71h
	mov BL, AL
	mov AL, 31h
	out 70h, AL
	in AL, 71h
	mov BH, AL
	mov AX, BX
	call PRINT_WORD	
	call LN
	call LN
;MCB's
	mov AH, 52h
	int 21h
	mov AX, ES:[BX-2]
	mov ES, AX
	xor CX, CX
NEXT:
	inc CX
	mov AX,CX
	mov DX, offset STR_MCB
	call PRINT
	call PRINT_WORD
	call LN
	push CX
	
	xor AX, AX
	mov AL, ES:[0h]
	push AX
	mov AX, ES:[1h]

	mov DX, offset STR_OWNER
	call PRINT

	cmp AX, 0h
	je AREA_FREE
	cmp AX, 6h
	je AREA_DRIVER
	cmp AX, 7h
	je AREA_TOP
	cmp AX, 8h
	je AREA_DOS
	cmp AX, 0FFFAh
	je AREA_BLOCK
	cmp AX, 0FFFDh
	je AREA_BLOCKED
	cmp AX, 0FFFEh
	je AREA_LAST
	
	
	xor DX, DX
	call PRINT_WORD
	call LN
	jmp AFTER_SWITCH


AREA_FREE:
	mov DX, offset STR_O1
	jmp END_OF_SWITCH
AREA_DRIVER:
	mov DX, offset STR_O2
	jmp END_OF_SWITCH
AREA_TOP:
	mov DX, offset STR_O3
	jmp END_OF_SWITCH
AREA_DOS:
	mov DX, offset STR_O4
	jmp END_OF_SWITCH
AREA_BLOCK:
	mov DX, offset STR_O5
	jmp END_OF_SWITCH
AREA_BLOCKED:
	mov DX, offset STR_O6
	jmp END_OF_SWITCH
AREA_LAST:
	mov DX, offset STR_O7
END_OF_SWITCH:
	push AX
	mov AH, 9h
	int 21h
	pop AX
	;call LN
	call LN

AFTER_SWITCH:	
;size
	mov DX, offset STR_SIZE
	call PRINT
	
	mov AX, ES:[3h]
	mov BX, 10h
	mul BX	
	call PRINT_WORD
	call LN
	
	mov CX, 8
	xor SI, SI
	;call LN
PRINT_LAST_BYTES:
	mov DL, ES:[SI + 8h]
	mov AH, 02h
	int 21h
	inc SI
	loop PRINT_LAST_BYTES
	call LN

	mov AX, ES:[3h]
	mov BX, ES
	add BX, AX
	inc BX
	mov ES, BX
	pop AX
	pop CX
	cmp AL, 5Ah
	je END_PROC
	call LN
	jmp NEXT
END_PROC:
	
	
EXIT:
	xor AL,AL
	mov AH,4Ch
	int 21h
	
	STACK_BUF:
		DW 128 dup(0)
	STACK_BUF_END:
	
TESTPC ENDS
END START
	