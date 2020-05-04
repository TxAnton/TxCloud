CODE SEGMENT
	assume CS:CODE, DS:DATA, SS:STACKK, ES:NOTHING
	
	INTERRUPT PROC FAR
		jmp INTERRUPT_START
		STR_COUNTER db 'Interrupt number 0000'
		INTERRUPT_ID dw 0804h
		SAVE_AX dw 0
		SAVE_SS dw 0
		SAVE_SP dw 0
		KEEP_IP dw 0
		KEEP_CS dw 0
		PSP_SEGMENT DW 0
		INTERRUPTION_STACK dw 128 dup(0);Свой стек для обработчика
		
	INTERRUPT_START:	
		mov SAVE_AX, AX
		mov SAVE_SP, SP
		mov SAVE_SS, SS
		mov AX, SEG INTERRUPTION_STACK
		mov SS, AX
		mov AX, offset INTERRUPTION_STACK
		add AX, 256
		mov SP, AX
		push BX
		push CX
		push DX
		push SI
		push DS
		push BP
		push ES
		mov AX, SEG STR_COUNTER
		mov DS, AX
		
		mov AH, 03h
		mov BH, 00h
		int 10h
		push DX;Сохранение позиции курсора для восстановления в будущем
		mov AH, 02h
		mov BH, 00h
		mov DX, 1820h;18 строка, 20 столбец для курсора
		int 10h
		mov AX, SEG STR_COUNTER
		push DS
		mov DS, AX
		mov SI, offset STR_COUNTER
		add SI, 20
		mov CX, 4
	INT_CYCLE:;Увеличение счетчика
		mov AH, [SI]
		inc AH
		mov [SI], AH
		cmp AH, ':'
		jne INT_END_CYCLE
		mov AH, '0'
		mov [SI], AH
		dec SI
		loop INT_CYCLE		
	INT_END_CYCLE:
		pop DS
		
		push ES
		push BP
		mov AX, SEG STR_COUNTER
		mov ES, AX
		mov BP, offset STR_COUNTER
		mov AH, 13h
		mov AL, 1h
		mov BL, 5h
		mov CX, 21
		mov BH, 0
		int 10h
		pop BP
		pop ES
		
		pop DX
		mov AH, 02h;Восстановление курсора
		mov BH, 0h
		int 10h
		
		pop ES
		pop BP
		pop DS
		pop SI
		pop DX
		pop CX
		pop BX
		mov SP, SAVE_SP
		mov AX, SAVE_SS
		mov SS, AX
		mov AX, SAVE_AX
		mov AL, 20h
		out 20h, AL
		IRET
		ret
	INTERRUPT ENDP
END_OF_INTERRUPT:
;____________________________________________________________
	CHECK_INTERRUPT PROC
		push AX
		push BX
		push SI
		
		mov AH, 35h
		mov AL, 1Ch;Номер прерывания
		int 21h
		mov  SI, offset INTERRUPT_ID
		sub SI, offset INTERRUPT
		mov AX, ES:[BX + SI]
		cmp	AX, 0804h
		jne CHECK_INTERRUPT_END
		mov INTERRUPT_LOADED, 1
		
	CHECK_INTERRUPT_END:
		pop SI
		pop BX
		pop AX
		ret
	CHECK_INTERRUPT ENDP
;____________________________________________________________
	WRITE  	PROC	NEAR
       	PUSH AX
       	MOV	AH, 09H
        INT	21H
		POP AX 
		RET
	WRITE  	ENDP
;____________________________________________________________
	LOAD_INTERRUPT PROC
		push AX
		push BX
		push CX
		push DX
		push DS
		push ES
		
		mov AH, 35h
		mov AL, 1Ch
		int 21h
		mov KEEP_CS, ES
		mov KEEP_IP, BX
		push DS
		mov DX, offset INTERRUPT
		mov AX, SEG INTERRUPT	
		mov DS, AX
		mov AH, 25h
		mov AL, 1Ch
		int 21h
		pop DS
		mov DX, offset END_OF_INTERRUPT
		add DX, 10Fh
		mov CL, 4h
		shr DX, CL
		inc DX
		xor AX, AX
		mov AH, 31h
		int 21h
		
		pop ES
		pop DS
		pop DX
		pop CX
		pop BX
		pop AX
		ret
	LOAD_INTERRUPT ENDP
;____________________________________________________________
	CHECK_PARAM PROC
		push AX
		push ES
		
		mov AX, PSP_SEGMENT
		mov ES, AX
		cmp byte ptr ES:[82h], '/'
		jne CHECK_PARAM_END
		cmp byte ptr ES:[83h], 'u'
		jne CHECK_PARAM_END
		cmp byte ptr ES:[84h], 'n'
		jne CHECK_PARAM_END
		mov UN_PARAM, 1
		
	CHECK_PARAM_END:
		pop ES
		pop AX
		ret
	CHECK_PARAM ENDP
;____________________________________________________________
	UNLOAD_INTERRUPTION PROC
		CLI
		push AX
		push BX
		push DX
		push DS
		push ES
		push SI
		
		mov AH, 35h
		mov AL, 1Ch
		int 21h
		mov SI, offset KEEP_IP
		sub SI, offset INTERRUPT
		mov DX, ES:[BX + SI];Смещение
		mov AX, ES:[BX + SI + 2];Сегмент
		push DS
		mov DS, AX
		mov AH, 25h
		mov AL, 1Ch
		int 21h
		pop DS
		mov AX, ES:[BX + SI + 4]
		mov ES, AX
		push ES
		mov AX, ES:[2Ch]
		mov ES, AX
		mov AH, 49h
		int 21h
		pop ES
		mov AH, 49h
		int 21h
		
		pop SI
		pop ES
		pop DS
		pop DX
		pop BX
		pop AX
		STI
		ret
	UNLOAD_INTERRUPTION ENDP
;____________________________________________________________
	MAIN PROC
		push DS
		xor AX, AX
		push AX
		mov AX, DATA
		mov DS, AX
		mov PSP_SEGMENT, ES
		
		call CHECK_INTERRUPT
		call CHECK_PARAM
		cmp UN_PARAM, 1
		je MAIN_UNLOAD
		mov AL, INTERRUPT_LOADED
		cmp AL, 1
		jne MAIN_LOAD
		mov DX, offset STR_INTERRUPT_EXIST
		call WRITE
		jmp MAIN_END
	MAIN_LOAD:
		call LOAD_INTERRUPT
		jmp MAIN_END
	MAIN_UNLOAD:
		cmp INTERRUPT_LOADED, 1
		jne NOT_EXIST
		call UNLOAD_INTERRUPTION
		jmp MAIN_END
	NOT_EXIST:
		mov DX, offset STR_NOT_EXIST
		call WRITE
	MAIN_END:
		xor AL, AL
		mov AH, 4Ch
		int 21h
	MAIN ENDP
;____________________________________________________________
CODE ENDS

STACKK SEGMENT STACK
	dw 128 dup(0)
STACKK ENDS


DATA SEGMENT
	INTERRUPT_LOADED db 0
	UN_PARAM db 0
	STR_INTERRUPT_EXIST db 'Interrupt already exist$'
	STR_NOT_EXIST db 'Interrupt does not exist$'
DATA ENDS
END MAIN