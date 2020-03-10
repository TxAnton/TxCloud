LAB2 SEGMENT
	ASSUME  CS:LAB2, DS:LAB2, ES:NOTHING, SS:NOTHING
	ORG 100H
START: JMP BEGIN
LOCKED_MEMORY_STR db 13, 10, "Locked memory addres is $"
ENVIRONMENT db 13, 10, "Enviroment addres is $"
TAIL db 13, 10, "Command line tail: $"
NO_TAIL db "there is no command line tail$"
ENVIRONMENT_CONTENT db 13, 10, "Enviroment content:", 13, 10, '$'
ENTER_SYMB db 13, 10, '$'
PATH_STR db 13, 10, "Path is $"
;____________________________________________________
GET_LOCKED_MEMORY PROC
	push AX
	push DX
	
	mov DX, offset LOCKED_MEMORY_STR
	call WRITE
	mov AX, DS:[02h]
	call WRITE_HEX_WORD
	
	pop DX
	pop AX
	ret
GET_LOCKED_MEMORY ENDP
;____________________________________________________
WRITE PROC
	push AX
	mov AH, 9h
	int 21h
	pop AX
	ret
WRITE ENDP
;____________________________________________________
WRITE_HEX_WORD PROC
	push AX
	
	push AX
	mov AL, AH
	call WRITE_HEX_BYTE
	pop AX
	call WRITE_HEX_BYTE
	
	pop AX
	ret
WRITE_HEX_WORD ENDP
;____________________________________________________
WRITE_HEX_BYTE PROC
	push AX
	push BX
	push DX
	
	mov AH, 0
	mov BL, 16
	div BL
	mov DX, AX
	mov AH, 02h
	cmp DL, 0Ah
	jl PRINT
	add DL, 7
PRINT:
	add DL, '0'
	int 21h;
	
	mov DL, DH
	cmp DL, 0Ah
	jl PRINT2
	add DL, 7
PRINT2:
	add DL, '0'
	int 21h;
	
	pop DX
	pop BX
	pop AX
	ret
WRITE_HEX_BYTE ENDP
;____________________________________________________
GET_ENVIRONMENT PROC
	push AX
	push DX
	
	mov DX, offset ENVIRONMENT
	call WRITE
	mov AX, DS:[2Ch]
	call WRITE_HEX_WORD
	
	pop DX
	pop AX
	ret
GET_ENVIRONMENT ENDP
;____________________________________________________
GET_TAIL PROC
	push AX
	push CX
	push DX
	push SI
	
	mov DX, offset TAIL
	call WRITE
	xor CX, CX
	mov CL, DS:[80h]
	cmp CL, 0
	jne REWRITING_TAIL
	mov DX, offset NO_TAIL
	call WRITE
	jmp END_OF_PROC_TAIL
REWRITING_TAIL:
	xor SI, SI
	xor AX, AX
CYCLE:
	mov AL, DS:[81h + SI]
	call WRITE_SYMB_BYTE
	inc SI
	loop CYCLE
	
END_OF_PROC_TAIL:
	pop SI
	pop DX
	pop CX
	pop AX
	ret
GET_TAIL ENDP
;____________________________________________________
WRITE_SYMB_BYTE PROC
	push AX
	push DX
	
	xor DX, DX
	mov DL, AL
	mov AH, 02h
	int 21h
	
	pop DX
	pop AX
	ret
WRITE_SYMB_BYTE ENDP
;____________________________________________________
GET_ENVIRONMENT_CONTENT PROC
	push AX
	push BX
	push DX
	push ES
	push SI
	
	mov DX, offset ENVIRONMENT_CONTENT
	call WRITE
	xor SI, SI
	mov BX, 2Ch
	mov ES, [BX]
READING_STR:
	cmp BYTE PTR ES:[SI], 0h
	je NEW_LINE
	mov AL, ES:[SI]
	call WRITE_SYMB_BYTE
	jmp CHECK_END
NEW_LINE:
	mov DX, offset ENTER_SYMB
	call WRITE
CHECK_END:
	inc SI
	cmp WORD PTR ES:[SI], 0001h
	je PATH
	jmp READING_STR
PATH:
	mov DX, offset PATH_STR
	call WRITE
	add SI, 2
CYCLE_PATH:
	cmp BYTE PTR ES:[SI], 00h
	je END_OF_PROC_CONTENT
	mov AL, ES:[SI]
	call WRITE_SYMB_BYTE
	inc SI
	jmp CYCLE_PATH
	
END_OF_PROC_CONTENT:
	pop SI
	pop ES
	pop DX
	pop BX
	pop AX
	ret
GET_ENVIRONMENT_CONTENT ENDP
;____________________________________________________
BEGIN:
	call GET_LOCKED_MEMORY
	call GET_ENVIRONMENT
	call GET_TAIL
	call GET_ENVIRONMENT_CONTENT
	
	;TO DOS
	xor AL, AL
	mov AH, 4Ch
	int 21h
LAB2 ENDS
END START