LR3 SEGMENT
	ASSUME CS:LR3, DS:LR3, SS: NOTHING, ES:NOTHING
	org 100h
	START:
		jmp BEGIN
	;данные
	STR_AVAIBLE_MEMORY db 13, 10, "Avaible memory: $"
	STR_BYTES db " bytes$"
	STR_EXTENDED_MEMORY db 13, 10, "Extended memory: $"
	STR_KBYTE db " kbytes$"
	STR_ENDL db 13, 10, "$"
	STR_MCB_NUM db 13, 10, "MCB number $"
	STR_OWNER db 13, 10, "Owner: $"
	STR_O1 db " free$";
	STR_O2 db " OS XMS UMB$";
	STR_O3 db " driver's top memory$";
	STR_O4 db " MS DOS$";
	STR_O5 db " control block 386MAX UMB$";
	STR_O6 db " blocked 386MAX$";
	STR_O7 db " 386MAX UMB$";
	STR_AREA_SIZE db 13, 10, "Area size: $"
	STR_ERROR_OF_FREEDOM db 13, 10, "Error, memory wasn't free$"
	STR_SUCCES_OF_FREEDOM db 13, 10, "Memory was free successfuly$"
	STR_ERROR_OF_ALLOCATE db 13, 10, "Error, memory wasn't allocate$"
	STR_SUCCES_OF_ALLOCATE db 13, 10, "Memory was allocate successfuly$"
	;______________________________________________
	;код
	WRITE PROC
		push AX
		mov AH, 9h
		int 21h
		pop AX
		ret
	WRITE ENDP
	;______________________________________________
	WRITE_DEC_WORD PROC
		push AX
		push CX
		push DX
		push BX
	
		mov BX, 10
		xor CX, CX
	GETTING_NUMS:
		div BX
		push DX
		xor DX, DX
		inc CX
		cmp AX, 0h
		jnz GETTING_NUMS
		
		
	WRITING:
		pop DX
		or DL, 30h
		mov AH, 02h
		int 21h
		loop WRITING
	
		pop BX
		pop DX
		pop CX
		pop AX
		ret
	WRITE_DEC_WORD ENDP
	;______________________________________________
	AVAIBLE_MEMORY PROC
		push AX
		push BX
		push DX
		
		mov DX, offset STR_AVAIBLE_MEMORY
		call WRITE
		mov AH, 4Ah
		mov BX, 0FFFFh
		int 21h
		mov AX, BX
		mov BX, 10h
		mul BX
		call WRITE_DEC_WORD
		mov DX, offset STR_BYTES
		call WRITE
		
		pop DX
		pop BX
		pop AX
		ret
	AVAIBLE_MEMORY ENDP
	;______________________________________________
	EXTENDED_MEMORY PROC
		push AX
		push BX
		push DX
	
		mov DX, offset STR_EXTENDED_MEMORY
		call WRITE
		mov AL, 30h
		out 70h, AL
		in AL, 71h
		mov BL, AL
		mov AL, 31h
		out 70h, AL
		in AL, 71h
		mov BH, AL
		mov AX, BX
		xor DX, DX
		call WRITE_DEC_WORD
		mov DX, offset STR_KBYTE
		call WRITE
		
		pop DX
		pop BX
		pop AX
		ret
	EXTENDED_MEMORY ENDP
	;______________________________________________
	GET_MCB PROC
		push AX
		push BX
		push CX
		push DX
		push ES
		push SI
	
		mov AH, 52h
		int 21h
		mov AX, ES:[BX-2]
		mov ES, AX
		xor CX, CX
	ANOTHER_MCB:
		inc CX
		mov DX, offset STR_ENDL
		call WRITE
		mov DX, offset STR_MCB_NUM
		push CX
		call WRITE
		mov AX, CX
		xor DX, DX
		call WRITE_DEC_WORD
		mov DX, offset STR_OWNER
		call WRITE
		xor AX, AX
		mov AL, ES:[0h]
		push AX
		mov AX, ES:[1h]
		
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
		call WRITE_HEX_WORD
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
		call WRITE
	
	AFTER_SWITCH:	
		mov DX, offset STR_AREA_SIZE
		call WRITE
		mov AX, ES:[3h]
		mov BX, 10h
		mul BX
		call WRITE_DEC_WORD
		mov DX, offset STR_BYTES
		call WRITE
		mov CX, 8
		xor SI, SI
		mov DX, offset STR_ENDL
		call WRITE
	PRINT_LAST_BYTES:
		mov DL, ES:[SI + 8h]
		mov AH, 02h
		int 21h
		inc SI
		loop PRINT_LAST_BYTES
		
		mov AX, ES:[3h]
		mov BX, ES
		add BX, AX
		inc BX
		mov ES, BX
		pop AX
		pop CX
		cmp AL, 5Ah
		je END_PROC
		mov DX, offset STR_ENDL
		call WRITE
		jmp ANOTHER_MCB
	
	END_PROC:
		pop SI
		pop ES
		pop DX
		pop CX
		pop BX
		pop AX
		ret
	GET_MCB ENDP
	;______________________________________________
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
	FREE_MEMORY PROC
		push AX
		push BX
		push DX
		
		mov BX, offset STACK_END
		add BX, 10Fh
		shr BX, 4
		mov AH, 4Ah
		int 21h
		jnc SUCCES
		mov DX, offset STR_ERROR_OF_FREEDOM
		call WRITE
		jmp RETURN
		
	SUCCES:
		mov DX, offset STR_SUCCES_OF_FREEDOM
		call WRITE
		
	RETURN:
		pop DX
		pop BX
		pop AX
		ret
	FREE_MEMORY ENDP
;______________________________________________
	ALLOCATE_MEMORY PROC
		push AX
		push BX
		push DX
	
		mov BX, 1000h
		mov AH, 48h
		int 21h
		jnc ALLOCATE_SUCCES
		mov DX, offset STR_ERROR_OF_ALLOCATE
		call WRITE
		jmp ALLOCATE_RETURN
		
	ALLOCATE_SUCCES:
		mov DX, offset STR_SUCCES_OF_ALLOCATE
		call WRITE
	
	ALLOCATE_RETURN:
		pop DX
		pop BX
		pop AX
		ret
	ALLOCATE_MEMORY ENDP
;______________________________________________
	BEGIN:
		call AVAIBLE_MEMORY
		call ALLOCATE_MEMORY
		call FREE_MEMORY
		call EXTENDED_MEMORY
		call GET_MCB
		
		;TO DOS
		xor AL, AL
		mov AH, 4Ch
		int 21h
		
	STACK_FOR_FREEDOM:
		DW 128 dup(0)
	STACK_END:
LR3 ENDS
END START