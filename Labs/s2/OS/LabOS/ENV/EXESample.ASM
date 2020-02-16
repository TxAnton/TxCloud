STACKSG SEGMENT  PARA STACK 'Stack'
        DW       32 DUP(?)
STACKSG	ENDS



	
DATASG  SEGMENT  PARA 'Data'				;SEG DATA
s1 db 'PS			FF',0DH,0AH,'$'
s2 db 'PC/XT		FE,FB',0DH,0AH,'$'
s3 db 'AT			FC',0DH,0AH,'$'
s4 db 'PS2-30		FA',0DH,0AH,'$'
s5 db 'PS2-50-60	FC',0DH,0AH,'$'
s6 db 'PS2-300		F8',0DH,0AH,'$'
s7 db 'PCjr			FD',0DH,0AH,'$'
s8 db 'PC Convertible F9',0DH,0AH,'$'
s9 db 'XZ',0DH,0AH,'$'
OS_VER db '00.00',0DH,0AH,'$'
NEW_LINE db 0DH,0AH,'$'

STRING DB 'Some text       ',0DH,0AH,'$'
DATASG	ENDS								;ENDS DATA

CODE      SEGMENT   						;SEG CODE
;	ASSUME CS:TESTPC, DS:TESTPC, ES:NOTHING, SS:NOTHING
;	ORG 100H
	ASSUME  DS:DataSG, CS:Code
;procedures
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
;breaks AX,CX,BX
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
	ret
PRINT_AS_HEX ENDP
;----------------------------------------
BYTE_TO_DEC PROC near
	push CX
	push DX
	xor AH,AH
	xor DX,DX
	mov CX,10
loop_bd:
	div CX
	or DL,30h
	mov [SI],DL
	dec SI
	xor DX,DX
	cmp AX,10
	jae loop_bd
	cmp AL,00h
	je end_l
	or AL,30h
	mov [SI],AL
end_l:
	pop DX
	pop CX
	ret
BYTE_TO_DEC ENDP

;----------------------------------------

;-----------------
Main      PROC  FAR

	mov  ax, DATASG                        ;ds setup
	mov  ds, ax  

	mov ax,0F000h
	mov es,ax
	mov ax,es:[0FFFEh]
;	mov ax,2Ah
	xor dx,dx
CASE:
	cmp al,0FFh
	jne LS2
	mov DX,offset s2
;	jmp ENDIF
LS2:
	cmp al,0FEh
	jne SLS2
	mov DX,offset s2
SLS2:
	cmp al,0FBh
	jne LS3
	mov DX,offset s2
LS3:
	cmp al,0FCh
	jne LS4
	mov DX,offset s3;s5
LS4:
	cmp al,0FAh
	jne LS6
	mov DX,offset s4
LS6:
	cmp al,0F8h
	jne LS7
	mov DX,offset s6
LS7:
	cmp al,0FDh
	jne LS8
	mov DX,offset s7
LS8:
	cmp al,0F9h
	jne LS9
	mov DX,offset s8
LS9:
	cmp DX,0
	jnz END_CASE
	mov DX,offset s9
	mov AH,09h
	int 21h
	call PRINT_AS_HEX
END_CASE:
	
	cmp DX,0
	je VER
	mov AH,09h
	int 21h
	
VER:

	mov AH, 30h
	int 21h
	mov BH,AH
	mov si, offset OS_VER
	inc si
	call BYTE_TO_DEC
	
	add si,3
	xor AH,AH
	mov AL,BH
	call BYTE_TO_DEC
	
	mov DX,offset OS_VER
	mov AH,09h
	int 21h

	mov AH, 30h
	int 21h

	mov AL,BH; OEM
	call PRINT_AS_HEX
	
	mov DX,offset NEW_LINE
	mov AH,09h
	int 21h
	
	mov AL,BL; Serial
	call PRINT_AS_HEX
	mov AL,CH
	call PRINT_AS_HEX
	mov AL,CL
	call PRINT_AS_HEX
	
EXIT:
	xor AL,AL
	mov AH,4Ch
	int 21h
Main      ENDP
CODE      ENDS
END Main	
	